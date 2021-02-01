from ROOT import TTree, TH1D, TFile
from root_numpy import tree2array
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from sklearn import svm, metrics, preprocessing
from plot_confusion_matrix import plot_confusion_matrix
import copy, time, os, sys, math, random, itertools
from sklearn import neural_network
from sklearn.linear_model import SGDClassifier
from sklearn import tree
from sklearn.metrics import roc_curve
from sklearn.externals import joblib
from sklearn.metrics import classification_report, f1_score, recall_score, precision_score,accuracy_score


def millify(n):
   n = float(n)
   millnames = ['','k','M','G','T']
   millidx = max(0,min(len(millnames)-1,
                       int(math.floor(0 if n == 0 else math.log10(abs(n))/3))))

   return '{:.0f}{}'.format(n / 10**(3 * millidx), millnames[millidx])

def arch2tuple(n):
   layers, nodes = n.split('x',2)
   tup = (int(nodes),)
   out =()
   for x in range(int(layers)-1):
      out = out + tup
   return (out)

def resample_with_replacement(X_train, sample_weight):
   # normalize sample_weights if not already
   sample_weight = sample_weight / sample_weight.sum(dtype=np.float64)
   
   X_train_resampled = np.zeros((len(X_train), len(X_train[0])), dtype=np.float32)
   print '\t Resampling:'
   for i in range(len(X_train)):
      if i%10000 == 0: print '\t\t ...',i,'...'
      # draw a number from 0 to len(X_train)-1
      draw = np.random.choice(np.arange(len(X_train)), p=sample_weight)

      # place the X at the drawn number into the resampled X
      X_train_resampled[i] = X_train[draw]

   return X_train_resampled

## Read in the arguments
start_time = time.time()
outdir = sys.argv[1]
arch = '3x10'
maxtest = 15000
testnum = 0

## Set up the logs
outdir = outdir + '/'
if not os.path.exists(outdir): os.system('mkdir '+outdir)
ofile = open(outdir+"TT_output_Jan21_2018.txt","a+")
ofile.write('\narch, Original ttbar Training Events, Original TT 1.0 Training Events, Original WJets Training events, Original ttbar testing events, Original TT 1.0 testing events, Original TT 1.8 testing events, Original WJets Testing Events, Final Training ttbar, Final Training TT 1.0, Final Training WJets, Final Testing ttbar, Final Testing TT 1.0, Final Testing Tprime1.8, Final Testing WJets'+'\n')
ofile.write(arch+", ")

## Set which signal we will use
Tprime = 1.0
Tprime2 = 1.8
test1100 = False #use if Tprime = 1800
WithTprimeVars = False

## Make new directory and set a label for all files
outStr = '_2018TT_'+str(arch)+'_' + str(millify(maxtest)) +'test'
print 'Outstr:',outStr,'Outdir:',outdir

## List of possible variables for the MVA
vars = ['weight','dnnJ_1','dnnJ_2','dnnJ_3','jetPt_1','jetPt_3','sdMass_3','tau21_3','AK4HT','t_pt','t_mass','t_dRWb','AK4HTpMETpLepPt','corr_met_MultiLepCalc','NJets_JetSubCalc', 'NJetsDeepFlavwithSF_JetSubCalc','NJetsAK8_JetSubCalc','minDR_leadAK8otherAK8'] 
#'jetPt_2','sdMass_2','sdMass_1', removed for bad data/bkg agreement  #'tau21_1','tau21_2', removed since not used before

## Initialize/create Arrays to put things in
trainTTToSemiLepT = []
trainTTToSemiLepTb = []
trainTprime    = []
trainWJets400    = []
trainWJets600    = []
trainWJets800    = []
trainWJets1200    = []
trainWJets2500    = []

testTTToSemiLepT = []
testTTToSemiLepTb = []
testTprime      = []
testTprime2   = []
testWJets400    = []
testWJets600    = []
testWJets800    = []
testWJets1200    = []
testWJets2500    = []


## Open ROOT files
print 'Opening files...'
eosdir = "root://cmseos.fnal.gov//store/user/jmanagan/MVAtraining_2018_Jan2021/"

## Choosing valid events with appropriate characteristics and cutting the rest
seltrain = "isValidTTDecayMode_DeepAK8 == 0 && Tprime2_DeepAK8_Mass < 0 && NJetsAK8_JetSubCalc > 2"
seltest = "isValidTTDecayMode_DeepAK8 == 0 && Tprime2_DeepAK8_Mass >= 0"

treeVars = vars

## Getting values from trees for each parent particle and either keeping them in an array or adding them together

fileTTToSemiLepT  = TFile.Open(eosdir + "TTJets_SingleLeptFromT_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root", "READ")
treeTTToSemiLepT  = fileTTToSemiLepT.Get("ljmet")
trainTTToSemiLepT = tree2array(treeTTToSemiLepT, treeVars, seltrain)
testTTToSemiLepT  = tree2array(treeTTToSemiLepT, treeVars, seltest)

## Selection with Single Lept from TBar
fileTTToSemiLepTb = TFile.Open(eosdir + "TTJets_SingleLeptFromTbar_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root", "READ")
treeTTToSemiLepTb = fileTTToSemiLepTb.Get("ljmet")  
trainTTToSemiLepTb = tree2array(treeTTToSemiLepTb, treeVars, seltrain)
testTTToSemiLepTb  = tree2array(treeTTToSemiLepTb, treeVars, seltest)

## Selection with signals   
fileTprime  = TFile.Open(eosdir + "TprimeTprime_M-1000_TuneCP5_PSweights_13TeV-madgraph-pythia8_hadd.root", "READ")
fileTprime2 = TFile.Open(eosdir + "TprimeTprime_M-1800_TuneCP5_PSweights_13TeV-madgraph-pythia8_hadd.root", "READ")
if Tprime == 1.8:
   temp = fileTprime
   fileTprime = fileTprime2
   fileTprime2 = temp
treeTprime = fileTprime.Get("ljmet")
treeTprime2 = fileTprime2.Get("ljmet")
trainTprime= tree2array(treeTprime, treeVars, seltrain)
testTprime= tree2array(treeTprime, treeVars, seltest)
testTprime2= tree2array(treeTprime2, treeVars, seltest)

## Section with W Jets

fileWJets1200   = TFile.Open(eosdir + "WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root", "READ")
treeWJets1200   = fileWJets1200.Get("ljmet")
trainWJets1200= tree2array(treeWJets1200, treeVars, seltrain)
testWJets1200= tree2array(treeWJets1200, treeVars, seltest)

fileWJets2500    = TFile.Open(eosdir + "WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root", "READ")
treeWJets2500    = fileWJets2500.Get("ljmet")
trainWJets2500= tree2array(treeWJets2500, treeVars, seltrain)
testWJets2500= tree2array(treeWJets2500, treeVars, seltest)

fileWJets400    = TFile.Open(eosdir + "WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root", "READ")
treeWJets400    = fileWJets400.Get("ljmet")
trainWJets400= tree2array(treeWJets400, treeVars, seltrain)
testWJets400= tree2array(treeWJets400, treeVars, seltest)

fileWJets600  = TFile.Open(eosdir + "WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root", "READ")
treeWJets600  = fileWJets600.Get("ljmet")
trainWJets600= tree2array(treeWJets600, treeVars, seltrain)
testWJets600= tree2array(treeWJets600, treeVars, seltest)

fileWJets800  = TFile.Open(eosdir + "WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root", "READ")
treeWJets800  = fileWJets800.Get("ljmet")
trainWJets800= tree2array(treeWJets800, treeVars, seltrain)
testWJets800= tree2array(treeWJets800, treeVars, seltest)

## Use this print when changing the samples to new files!
# print "N 400",len(testWJets400),"max multiplier",len(testWJets400)/1256.89
# print "N 600",len(testWJets600),"max multiplier",len(testWJets600)/309.66
# print "N 800",len(testWJets800),"max multiplier",len(testWJets800)/141.36
# print "N 1200",len(testWJets1200),"max multiplier",len(testWJets1200)/34.15
# print "N 2500",len(testWJets2500),"max multiplier",len(testWJets2500)

## Get the WJets HT bins combined in (close to) the right ratios for smoothness
print 'Weighting WJets...'
multiplier = 550000./1743.  ## tweak numerator until original N training is large enough in print below
multipliertest = 40. ## less than printout from 600 sample above
max2500 = int(round(multiplier*1.))
max1200 = int(round(multiplier*34.15))
max800 = int(round(multiplier*141.36))
max600 = int(round(multiplier*309.66))
max400 = int(round(multiplier*1256.89))
maxtest2500 = int(round(multipliertest*1.))
maxtest1200 = int(round(multipliertest*34.15))
maxtest800 = int(round(multipliertest*141.36))
maxtest600 = int(round(multipliertest*309.66))
maxtest400 = int(round(multipliertest*1256.89))

## Shuffle, cuz why not...
np.random.shuffle(trainWJets400)
np.random.shuffle(trainWJets600)
np.random.shuffle(trainWJets800)
np.random.shuffle(trainWJets1200)
np.random.shuffle(trainWJets2500)
np.random.shuffle(testWJets400)
np.random.shuffle(testWJets600)
np.random.shuffle(testWJets800)
np.random.shuffle(testWJets1200)
np.random.shuffle(testWJets2500)

print "Concatenating, manipulating, shuffling..."
## Add them together as if they were one sample, then shuffle
trainWJets = np.concatenate([trainWJets400[:max400],trainWJets600[:max600],trainWJets800[:max800],trainWJets1200[:max1200],trainWJets2500[:max2500]])
testWJets = np.concatenate([testWJets400[:maxtest400],testWJets600[:maxtest600],testWJets800[:maxtest800],testWJets1200[:maxtest1200],testWJets2500[:maxtest2500]])
np.random.shuffle(trainWJets)
np.random.shuffle(testWJets)

## Also add together the two ttbar samples (no weights here, same probability to get 1-lep from top and antitop)
trainTTToSemiLep = np.concatenate([trainTTToSemiLepT,trainTTToSemiLepTb])
testTTToSemiLep = np.concatenate([testTTToSemiLepT,testTTToSemiLepTb])
np.random.shuffle(trainTTToSemiLep)
np.random.shuffle(testTTToSemiLep)

## Print initial information to the log file and the screen
ofile.write(str(len(trainTTToSemiLep)) + ", " + str(len(trainTprime)) + ", " +str(len(trainWJets)) + ", " +str(len(testTTToSemiLep)) + ", " +str(len(testTprime)) + ", " +str(len(testTprime2)) + ", " +str(len(testWJets)) + ", ")

## Use this pring when you've changed samples and need to check!
print "-------Before Concatenate---------"
print "number of TTToSemiLep training events: ", len(trainTTToSemiLep)
print "number of Tprime " + str(Tprime) + " training events: ", len(trainTprime)
print "number of WJets training events: ", len(trainWJets)
print "number of TTToSemiLep testing events: ", len(testTTToSemiLep)
print "number of Tprime " + str(Tprime) + " testing events: ", len(testTprime)
print "number of Tprime " + str(Tprime2) + " testing events: ", len(testTprime2)
print "number of WJets testing events: ", len(testWJets)

## "Testing" events are the most signal-like, so we want as many as possible
## in the training arrays for signal and ttbar
## This is allowed because we will not use 1000-GeV signal for analysis and because
## we have a special ttbar MC sample for this training
trainTprime = np.concatenate([testTprime[maxtest:],trainTprime]) #put the better events first
trainTTToSemiLep = np.concatenate([testTTToSemiLep[maxtest:],trainTTToSemiLep])

## Shorten the testing arrays to the chosen length
testTprime = testTprime[:maxtest]
testTprime2 = testTprime2[:maxtest]
testWJets = testWJets[:maxtest]
testTTToSemiLep = testTTToSemiLep[:maxtest]

## Print some info to the screen -- use when changing samples!
# print "-------After Concatenate-------"
# print "number of TTToSemiLep Training events: ", len(trainTTToSemiLep)
# print "number of Tprime " + str(Tprime) + " Training events: ", len(trainTprime)
# print "number of WJets Training events: ", len(trainWJets)
# print "number of TTToSemiLep testing events: ", len(testTTToSemiLep)
# print "number of Tprime " + str(Tprime) + " testing events: ", len(testTprime)
# print "number of Tprime " + str(Tprime2) + " testing events: ", len(testTprime2)
# print "number of WJets testing events: ", len(testWJets)

## Calculate the maximum number of allowed training events in each group
## We'll allow up to 10% imbalance between the samples.
maxpersample = int(round(1.1*min(len(trainTTToSemiLep), len(trainTprime), len(trainWJets)),0))
#print 'MAX TRAINING = ',maxpersample 

## Shorten the training arrays to the max allowed length
## These are not shuffled yet, so we will chop off fewer "good" testing events
trainTprime = trainTprime[:maxpersample]
trainWJets = trainWJets[:maxpersample]
trainTTToSemiLep = trainTTToSemiLep[:maxpersample]

## Now shuffle everything up!
np.random.shuffle(trainTTToSemiLep)
np.random.shuffle(trainTprime)
np.random.shuffle(trainWJets)
np.random.shuffle(testTTToSemiLep)
np.random.shuffle(testWJets)
np.random.shuffle(testTprime)
np.random.shuffle(testTprime2)

## Final size print to the screen -- use when changing samples!
print '-------- Final sizes ------'
print 'Training ttbar',len(trainTTToSemiLep)
print 'Training Tprime',len(trainTprime)
print 'Training WJets',len(trainWJets)
print 'Testing ttbar',len(testTTToSemiLep)
print 'Testing Tprime 1.0',len(testTprime)
print 'Testing Tprime 1.8',len(testTprime2)
print 'Testing WJets',len(testWJets)

ofile.write(str(len(trainTTToSemiLep)) + ", " + str(len(trainTprime)) + ", " +str(len(trainWJets)) + ", " +str(len(testTTToSemiLep)) + ", " +str(len(testTprime)) + ", " +str(len(testTprime2)) + ", " +str(len(testWJets)) + ", ")
ofile.close()

## build arrays where each entry is a list of all training variables
## and make a copy of them
newTrainTTToSemiLep = []
newTrainTprime = []
newTrainWJets = []
newTestTTToSemiLep = []
newTestTprime = []
newTestTprime2 = []
newTestWJets = []

for entry in trainTTToSemiLep:
    a = list(entry)
    newTrainTTToSemiLep.append(a)
for entry in trainTprime:
    a = list(entry)
    newTrainTprime.append(a)
for entry in trainWJets:
    a = list(entry)
    newTrainWJets.append(a)
for entry in testTTToSemiLep:
    a = list(entry)
    newTestTTToSemiLep.append(a)
for entry in testTprime:
    a = list(entry)
    newTestTprime.append(a)
for entry in testTprime2:
    a = list(entry)
    newTestTprime2.append(a)
for entry in testWJets:
    a = list(entry)
    newTestWJets.append(a)

## Resample the training data so that events with larger weights are more likely to be included
## We'll do this within each type of sample so that we don't break the equivalency
weightsTrainTTToSemiLep = np.array([sub[0] for sub in newTrainTTToSemiLep])
weightsTrainTprime = np.array([sub[0] for sub in newTrainTprime])
weightsTrainWJets = np.array([sub[0] for sub in newTrainWJets])
weightsTestTTToSemiLep = np.array([sub[0] for sub in newTestTTToSemiLep])
weightsTestTprime = np.array([sub[0] for sub in newTestTprime])
weightsTestTprime2 = np.array([sub[0] for sub in newTestTprime2])
weightsTestWJets = np.array([sub[0] for sub in newTestWJets])
newTrainTTToSemiLep = [sub[1:] for sub in newTrainTTToSemiLep] ## cut off 'weight' from the front
newTrainTprime = [sub[1:] for sub in newTrainTprime]
newTrainWJets = [sub[1:] for sub in newTrainWJets]
newTestTTToSemiLep = [sub[1:] for sub in newTestTTToSemiLep]
newTestTprime = [sub[1:] for sub in newTestTprime]
newTestTprime2 = [sub[1:] for sub in newTestTprime2]
newTestWJets = [sub[1:] for sub in newTestWJets]

RStrainTTToSemiLep = (resample_with_replacement(newTrainTTToSemiLep,weightsTrainTTToSemiLep)).tolist()
RStrainTprime = (resample_with_replacement(newTrainTprime,weightsTrainTprime)).tolist()
RStrainWJets = (resample_with_replacement(newTrainWJets,weightsTrainWJets)).tolist()
RStestTTToSemiLep = (resample_with_replacement(newTestTTToSemiLep,weightsTestTTToSemiLep)).tolist()
RStestTprime = (resample_with_replacement(newTestTprime,weightsTestTprime)).tolist()
RStestTprime2 = (resample_with_replacement(newTestTprime2,weightsTestTprime2)).tolist()
RStestWJets = (resample_with_replacement(newTestWJets,weightsTestWJets)).tolist()

## copy.copy means we can edit them separately, else they are magically linked...
## we will use the "new" versions for merging and save the copies for plots
trainTTToSemiLep = copy.copy(RStrainTTToSemiLep)
trainTprime = copy.copy(RStrainTprime)
trainWJets = copy.copy(RStrainWJets)
testTTToSemiLep = copy.copy(RStestTTToSemiLep)
testTprime = copy.copy(RStestTprime)
testTprime2 = copy.copy(RStestTprime2)
testWJets = copy.copy(RStestWJets)

## Transpose these arrays to get arrays for plotting
## Each entry is one variable for all the events
## We will make sure all samples are the same size for plots
numPerSample = min(len(trainTTToSemiLep),len(trainTprime),len(trainWJets))

histsTTToSemiLep = np.array(trainTTToSemiLep[:numPerSample]).T
histsTprime = np.array(trainTprime[:numPerSample]).T
#histsTprime2 = np.array(trainTprime2[:numPerSample]).T
histsWJets = np.array(trainWJets[:numPerSample]).T

## Plot the input variables and save files if we're on the longest variable list
print "Plotting input variables..."
for index, hist in enumerate(histsWJets):
   plt.figure()
   plt.hist(hist, bins=50, color='g', label=r'$\mathrm{W+jets}$', histtype='step', normed=True)
   plt.hist(histsTprime[index], bins=50, color='y', label=r'$\mathrm{T\overline{T}\,('+str(Tprime)+'\,TeV)}$', histtype='step', normed=True)
   #plt.hist(histsTprime2[index], bins=50, color='c', label=r'$\mathrm{T\overline{T}\,('+str(Tprime2)+'\,TeV)}$', histtype='step', normed=True)
   plt.hist(histsTTToSemiLep[index], bins=50, color='r', label=r'$\mathrm{t\bar{t}}$', histtype='step', normed=True)
   plt.title('CMS Simulation',loc='left',size=18)
   plt.title('Work in progress',loc='right',size=14,style='italic')
   plt.ylabel('Events per bin',horizontalalignment='right',y=1.0,size=14)
   plt.xlabel(vars[index],horizontalalignment='right',x=1.0,size=14)
   plt.legend(loc='best',fontsize=14)
   if not WithTprimeVars: plt.savefig(outdir+'plots_'+str(vars[index])+outStr)
   if WithTprimeVars: plt.savefig(outdir+'plots_'+str(vars[index])+outStr)
   plt.close()

## Make arrays of training data and labels with samples mixed randomly
print "Merging samples..."

trainData = []
trainLabel = []
weights = []
nEvents = len(RStrainTTToSemiLep) + len(RStrainTprime) + len(RStrainWJets)
## Get a random integer and pull from specific samples based on that integer
while nEvents > 0:
   rng = random.randint(0,2)
   if (rng == 0 and len(RStrainWJets) > 0):      
      trainData.append(RStrainWJets.pop())
      trainLabel.append(0)
      nEvents = nEvents -1
   if (rng == 1 and len(RStrainTTToSemiLep) > 0):
      trainData.append(RStrainTTToSemiLep.pop())
      trainLabel.append(1)
      nEvents = nEvents - 1
   if (rng == 2 and len(RStrainTprime) > 0):
      trainData.append(RStrainTprime.pop())
      trainLabel.append(2)
      nEvents = nEvents - 1

## Print a sample of 3 training events and labels 
# print 'Train Data:'
# print trainData[:3]
# print 'Train Label:'
# print trainLabel[:3]
# print 'Train Weight:'
# print trainWeight[:3]

#############################################
## Helpful stuff not used right now
#
#print 'Train Data:'
#print trainData[0]
#print trainData[1]
#print 'Train Label:'
#print trainLabel[:10]
#
##from sklearn.feature_selection import SelectKBest, f_classif
##trainData_12 = SelectKBest(f_classif, k=12).fit_transform(trainData, trainLabel)
#print 'Train Data 12:'
#print trainData_12[0]
#print trainData_12[1]
#
##trainData_16 = SelectKBest(f_classif, k=16).fit_transform(trainData, trainLabel)
#print 'Train Data 16:'
#print trainData_16[0]
#print trainData_16[1]
#
##trainData_20 = SelectKBest(f_classif, k=20).fit_transform(trainData, trainLabel)
#print 'Train Data 20:'
#print trainData_20[0]
#print trainData_20[1]
#
##trainData_24 = SelectKBest(f_classif, k=24).fit_transform(trainData, trainLabel)
#print 'Train Data 24:'
#print trainData_24[0]
#print trainData_24[1]

#trainData_28 = SelectKBest(f_classif, k=28).fit_transform(trainData, trainLabel)
#print 'Train Data 28:'
#print trainData_28[0]
#print trainData_28[1]
#
################################################


## Make arrays of testing data and labels with samples mixed randomly
nEventsTest = len(RStestTTToSemiLep) + len(RStestTprime) + len(RStestWJets)
if test1100: nEventsTest = len(RStestTTToSemiLep) + len(RStestTprime2) + len(RStestWJets)

testData = []
testLabel = []
testWeight = []
while nEventsTest > 0:
   rng = random.randint(0,2)
   if (rng == 0 and len(RStestWJets) > 0):
      testData.append(RStestWJets.pop())
      testLabel.append(0)
      nEventsTest = nEventsTest -1
   if (rng == 1 and len(RStestTTToSemiLep) > 0):
      testData.append(RStestTTToSemiLep.pop())
      testLabel.append(1)
      nEventsTest = nEventsTest - 1
   if (rng == 2):
      if not test1100 and len(RStestTprime) > 0:
         testData.append(RStestTprime.pop())
         testLabel.append(2)
         nEventsTest = nEventsTest - 1
      if test1100 and len(RStestTprime2) > 0:
         testData.append(RStestTprime2.pop())
         testLabel.append(2)
         nEventsTest = nEventsTest - 1


## save the output of the setup
np.savez(outdir+'Arrays'+outStr,trainData=trainData, trainLabel=trainLabel, testData=testData, testLabel=testLabel, testWJets=testWJets, testTTToSemilep=testTTToSemiLep, testTprime=testTprime, testTprime2=testTprime2) ## for the sake of space, we won't save this stuff right now. 

print 'Done'
print("--- %s minutes ---" % (round(time.time() - start_time, 2)/60))

