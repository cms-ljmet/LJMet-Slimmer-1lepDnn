
# coding: utf-8


from ROOT import TTree, TH1D, TFile
from root_numpy import tree2array
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from sklearn import svm, metrics, preprocessing
from plot_confusion_matrix import plot_confusion_matrix
import copy, time, os, sys, math

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

start_time = time.time()
if len(sys.argv) == 1:
   print 'taking defaults....'
   outdir = 'Train3J_BBMar2020'
   arch = '3x10'
   vararray = 1
   maxtest = 15000
   #maxpersample = 60000
   testnum = 0
else:
   outdir = sys.argv[1]
   arch = sys.argv[2]
   vararray = int(sys.argv[3])
   maxtest = int(sys.argv[4])
   #maxpersample = int(sys.argv[5])
   #testnum = int(sys.argv[6])
   testnum = int(sys.argv[5])
outdir = outdir + '/'
if testnum == 1:
   ofile = open("BB_output.txt","a+")
   ofile.write('\ntestnum, # of TTToSemiLep Events, # of Bprime 1.0 Events, # of Bprime 1.8 Events, #of WJets events, # of TTToSemiLep testing events, # of Bprime1.0 testing events, # of Bprime 1.8 testing events, # of WJets Testing Events, Training ttbar, Training Bprime 1.0, Training Bprime 1.8, Training WJets, Testing ttbar, Testing Bprime 1.0, Testing Bprime1.8, Testing WJets, Testing Score (Accuracy), Precision, Recall, F-Score'+'\n')
else:
   time.sleep(2)
   ofile = open("BB_output.txt","a+")
   ofile.write('\n')
ofile.write(str(testnum)+", ")

Bprime = 1.0
Bprime2 = 1.8
test1100 = False #use if Bprime = 1800
WithBprimeVars = False


#outStr = '_M'+str(Bprime).replace('.','p')+'_'+str(arch)+'_'+ str(millify(int(maxpersample))) + 'train3J_' + str(millify(maxtest)) +'test_vars'+str(vararray)+'_Test'+str(testnum)
outStr = '_M'+str(Bprime).replace('.','p')+'_'+str(arch)+'_train3J_' + str(millify(maxtest)) +'test_vars'+str(vararray)+'_Test'+str(testnum)

print 'Outstr:',outStr,'Outdir:',outdir


if not os.path.exists(outdir): os.system('mkdir '+outdir)

if vararray == 1:
   vars = ['corr_met_MultiLepCalc', 'AK4HTpMETpLepPt', 'AK4HT', 'NJets_JetSubCalc', 'NJetsAK8_JetSubCalc', 'jetPt_1', 'jetPt_2', 'jetPt_3', 'dnnJ_1', 'dnnJ_2', 'dnnJ_3']#'minDR_lepAK8', 
elif vararray == 2:
   vars = ['corr_met_MultiLepCalc', 'AK4HTpMETpLepPt', 'AK4HT', 'NJets_JetSubCalc', 'NJetsAK8_JetSubCalc', 'nH_DeepAK8', 'nT_DeepAK8', 'jetPt_1', 'jetPt_2', 'jetPt_3', 'sdMass_2', 'sdMass_3', 'dnnJ_1', 'dnnJ_2', 'dnnJ_3']#'minDR_lepAK8', 
elif vararray == 3:
   vars = ['corr_met_MultiLepCalc', 'AK4HTpMETpLepPt', 'AK4HT', 'NJets_JetSubCalc', 'NJetsAK8_JetSubCalc', 'minDR_leadAK8otherAK8', 'nH_DeepAK8', 'nT_DeepAK8', 'jetPt_1', 'jetPt_2', 'jetPt_3', 'sdMass_1', 'sdMass_2', 'sdMass_3', 'dnnLargest_2', 'dnnLargest_3', 'dnnJ_1', 'dnnJ_2', 'dnnJ_3']#'minDR_lepAK8', 
elif vararray == 4:
   vars = ['corr_met_MultiLepCalc', 'AK4HTpMETpLepPt', 'AK4HT', 'NJets_JetSubCalc', 'NJetsAK8_JetSubCalc', 'minDR_leadAK8otherAK8', 'nH_DeepAK8', 'nT_DeepAK8', 'jetPt_1', 'jetPt_2', 'jetPt_3', 'sdMass_1', 'sdMass_2', 'sdMass_3', 'dnnLargest_2', 'dnnLargest_3', 'dnnJ_1', 'dnnJ_2', 'dnnJ_3']#'minDR_lepAK8',  Bprime2_DeepAK8_Pt and Bprime2_DeepAK8_Mass removed 
elif vararray == 5:
   vars = ['corr_met_MultiLepCalc', 'AK4HTpMETpLepPt', 'AK4HT', 'NJets_JetSubCalc', 'NJetsAK8_JetSubCalc', 'minDR_leadAK8otherAK8', 'nH_DeepAK8', 'nT_DeepAK8', 'jetPt_1', 'jetPt_2', 'jetPt_3', 'sdMass_1', 'sdMass_2', 'sdMass_3', 'dnnLargest_1', 'dnnLargest_2', 'dnnLargest_3', 'dnnJ_1', 'dnnJ_2', 'dnnJ_3', 'dnnH_2', 'dnnH_3', 'dnnT_1']#'minDR_lepAK8', 
elif vararray == 6:
   vars = ['corr_met_MultiLepCalc', 'AK4HTpMETpLepPt', 'AK4HT', 'NJets_JetSubCalc', 'NJetsAK8_JetSubCalc', 'minDR_leadAK8otherAK8', 'nH_DeepAK8', 'nT_DeepAK8', 'nW_DeepAK8', 'jetPt_1', 'jetPt_2', 'jetPt_3', 'sdMass_1', 'sdMass_2', 'sdMass_3', 'tau21_3', 'dnnLargest_1', 'dnnLargest_2', 'dnnLargest_3', 'dnnJ_1', 'dnnJ_2', 'dnnJ_3', 'dnnH_1', 'dnnH_2', 'dnnH_3', 'dnnT_1', 'dnnT_2']#'minDR_lepAK8', 
else:
   ######################
   ## assign default vars array
   ######################
   vars = ['corr_met_MultiLepCalc']


arrayTTToSemiLepT = []
arrayTTToSemiLepTb = []
arrayBprime    = []
arrayBprime2   = []
arrayWJets400    = []
arrayWJets600    = []
arrayWJets800    = []
arrayWJets1200    = []
arrayWJets2500    = []

testTTToSemiLepT = []
testTTToSemiLepTb = []
testBprime      = []
testBprime2   = []
testWJets400    = []
testWJets600    = []
testWJets800    = []
testWJets1200    = []
testWJets2500    = []


## Open ROOT files
print 'Opening files...'
eosdir = "root://cmseos.fnal.gov//store/user/bburgsta/training_20200326/"

#sel = "Bprime2_DeepAK8_Mass < 0"
sel = "isValidBBDecayMode_DeepAK8 == 0 && Bprime2_DeepAK8_Mass < 0 && NJetsAK8_JetSubCalc > 2"
treeVars = vars
print 'getting trees...','Making training arrays...','Making testing arrays...'

seltest = "isValidBBDecayMode_DeepAK8 == 0 && Bprime2_DeepAK8_Mass >= 0"

for i in range(1,7):
   fileTTToSemiLepT  = TFile.Open(eosdir + "TTJets_SingleLeptFromT_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_"+ str(i)+"_hadd.root", "READ")
   treeTTToSemiLepT  = fileTTToSemiLepT.Get("ljmet")
   if i == 1:
      arrayTTToSemiLepT = tree2array(treeTTToSemiLepT, treeVars, sel)
      testTTToSemiLepT  = tree2array(treeTTToSemiLepT, treeVars, seltest)
   else:
      arrayTTToSemiLepT = np.concatenate([arrayTTToSemiLepT,tree2array(treeTTToSemiLepT, treeVars, sel)])
      testTTToSemiLepT  = np.concatenate([testTTToSemiLepT,tree2array(treeTTToSemiLepT, treeVars, seltest)])

for i in range(1,3):
   fileTTToSemiLepTb = TFile.Open(eosdir + "TTJets_SingleLeptFromTbar_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_"+ str(i)+"_hadd.root", "READ")
   treeTTToSemiLepTb = fileTTToSemiLepTb.Get("ljmet")
   if i == 1:
      arrayTTToSemiLepTb = tree2array(treeTTToSemiLepTb, treeVars, sel)
      testTTToSemiLepTb  = tree2array(treeTTToSemiLepTb, treeVars, seltest)
   else:
      arrayTTToSemiLepTb = np.concatenate([arrayTTToSemiLepTb,tree2array(treeTTToSemiLepTb, treeVars, sel)])
      testTTToSemiLepTb  = np.concatenate([testTTToSemiLepTb,tree2array(treeTTToSemiLepTb, treeVars, seltest)])

for i in range(1,5):
   fileBprime  = TFile.Open(eosdir + "BprimeBprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_"+ str(i)+"_hadd.root", "READ")
   fileBprime2 = TFile.Open(eosdir + "BprimeBprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8_"+ str(i)+"_hadd.root", "READ")
   if Bprime == 1.8:
      temp = fileBprime
      fileBprime = fileBprime2
      fileBprime2 = temp
   treeBprime = fileBprime.Get("ljmet")
   treeBprime2 = fileBprime2.Get("ljmet")
   if i == 1:
      arrayBprime= tree2array(treeBprime, treeVars, sel)
      testBprime= tree2array(treeBprime, treeVars, seltest)
      arrayBprime2= tree2array(treeBprime2, treeVars, sel)
      testBprime2= tree2array(treeBprime2, treeVars, seltest)
   else:
      arrayBprime= np.concatenate([arrayBprime,tree2array(treeBprime, treeVars, sel)])
      testBprime= np.concatenate([testBprime,tree2array(treeBprime, treeVars, seltest)])
      arrayBprime2= np.concatenate([arrayBprime2,tree2array(treeBprime2, treeVars, sel)])
      testBprime2= np.concatenate([testBprime2,tree2array(treeBprime2, treeVars, seltest)])


fileWJets400   = TFile.Open(eosdir + "WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_hadd.root", "READ")
treeWJets400   = fileWJets400.Get("ljmet")
arrayWJets400  = tree2array(treeWJets400, treeVars, sel)
testWJets400   = tree2array(treeWJets400, treeVars, seltest)

for i in range(1,3):
   fileWJets600    = TFile.Open(eosdir + "WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_"+ str(i)+"_hadd.root", "READ")
   treeWJets600    = fileWJets600.Get("ljmet")

   fileWJets800    = TFile.Open(eosdir + "WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_"+ str(i)+"_hadd.root", "READ")
   treeWJets800    = fileWJets800.Get("ljmet")

   fileWJets1200   = TFile.Open(eosdir + "WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_"+ str(i)+"_hadd.root", "READ")
   treeWJets1200   = fileWJets1200.Get("ljmet")
   if i ==1:
      arrayWJets600= tree2array(treeWJets600, treeVars, sel)
      testWJets600= tree2array(treeWJets600, treeVars, seltest)
      arrayWJets800= tree2array(treeWJets800, treeVars, sel)
      testWJets800= tree2array(treeWJets800, treeVars, seltest)
      arrayWJets1200= tree2array(treeWJets1200, treeVars, sel)
      testWJets1200= tree2array(treeWJets1200, treeVars, seltest)
   else:
      arrayWJets600= np.concatenate([arrayWJets600,tree2array(treeWJets600, treeVars, sel)])
      testWJets600= np.concatenate([testWJets600,tree2array(treeWJets600, treeVars, seltest)])
      arrayWJets800= np.concatenate([arrayWJets800,tree2array(treeWJets800, treeVars, sel)])
      testWJets800= np.concatenate([testWJets800,tree2array(treeWJets800, treeVars, seltest)])
      arrayWJets1200= np.concatenate([arrayWJets1200,tree2array(treeWJets1200, treeVars, sel)])
      testWJets1200= np.concatenate([testWJets1200,tree2array(treeWJets1200, treeVars, seltest)])



fileWJets2500  = TFile.Open(eosdir + "WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_hadd.root", "READ")
treeWJets2500  = fileWJets2500.Get("ljmet")
arrayWJets2500= tree2array(treeWJets2500, treeVars, sel)
testWJets2500= tree2array(treeWJets2500, treeVars, seltest)

#print testWJets800
#print "N 400",len(testWJets400),"max multiplier",len(testWJets400)/1256.89
#print "N 600",len(testWJets600),"max multiplier",len(testWJets600)/309.66
#print "N 800",len(testWJets800),"max multiplier",len(testWJets800)/141.36
#print "N 1200",len(testWJets1200),"max multiplier",len(testWJets1200)/34.15
#print "N 2500",len(testWJets2500),"max multiplier",len(testWJets2500)

print 'Weighting WJets...'
multiplier = 250000./1743.  ## where numerator is the total we want (400 and 600 don't have enough, but 800/1200/2500 do)
multipliertest = 90. ## based on number of 600 sample
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

np.random.shuffle(arrayWJets400)
np.random.shuffle(arrayWJets600)
np.random.shuffle(arrayWJets800)
np.random.shuffle(arrayWJets1200)
np.random.shuffle(arrayWJets2500)
np.random.shuffle(testWJets400)
np.random.shuffle(testWJets600)
np.random.shuffle(testWJets800)
np.random.shuffle(testWJets1200)
np.random.shuffle(testWJets2500)

arrayWJets = np.concatenate([arrayWJets400[:max400],arrayWJets600[:max600],arrayWJets800[:max800],arrayWJets1200[:max1200],arrayWJets2500[:max2500]])
testWJets = np.concatenate([testWJets400[:maxtest400],testWJets600[:maxtest600],testWJets800[:maxtest800],testWJets1200[:maxtest1200],testWJets2500[:maxtest2500]])
arrayTTToSemiLep = np.concatenate([arrayTTToSemiLepT,arrayTTToSemiLepTb])
testTTToSemiLep = np.concatenate([testTTToSemiLepT,testTTToSemiLepTb])

np.random.shuffle(arrayTTToSemiLep)
np.random.shuffle(testTTToSemiLep)

ofile.write(str(len(arrayTTToSemiLep)) + ", " + str(len(arrayBprime)) + ", " +str(len(arrayBprime2)) + ", " +str(len(arrayWJets)) + ", " +str(len(testTTToSemiLep)) + ", " +str(len(testBprime)) + ", " +str(len(testBprime2)) + ", " +str(len(testWJets)) + ", ")

print "-------Before Concatenate---------"
print "number of TTToSemiLep events: ", len(arrayTTToSemiLep)
print "number of Bprime " + str(Bprime) + " events: ", len(arrayBprime)
print "number of WJets events: ", len(arrayWJets)
print "number of TTToSemiLep testing events: ", len(testTTToSemiLep)
print "number of Bprime " + str(Bprime) + " testing events: ", len(testBprime)
print "number of Bprime " + str(Bprime2) + " testing events: ", len(testBprime2)
print "number of WJets testing events: ", len(testWJets)

maxpersample = int(round(1,2*min(len(arrayTTToSemiLep) + len(testTTToSemiLep[maxtest:]), len(arrayBprime) + len(testBprime[maxtest:]))))
print 'MAX TRAINING = ',maxpersample

arrayBprime = np.concatenate([testBprime[maxtest:],arrayBprime]) #put the better events first
arrayBprime2 = np.concatenate([testBprime2[maxtest:],arrayBprime2])
arrayTTToSemiLep = np.concatenate([testTTToSemiLep[maxtest:],arrayTTToSemiLep])

#trainboost = 22000
#arrayTTToSemiLep = np.concatenate([testTTToSemiLep[maxtest:],arrayTTToSemiLep[:trainboost]])

testBprime = testBprime[:maxtest]
testBprime2 = testBprime2[:maxtest]
testWJets = testWJets[:maxtest]
testTTToSemiLep = testTTToSemiLep[:maxtest]

print "-------After Concatenate-------"
print "number of TTToSemiLep events: ", len(arrayTTToSemiLep)
print "number of Bprime " + str(Bprime) + " events: ", len(arrayBprime)
print "number of Bprime " + str(Bprime2) + " events: ", len(arrayBprime2)
print "number of WJets events: ", len(arrayWJets)
print "number of TTToSemiLep testing events: ", len(testTTToSemiLep)
print "number of Bprime " + str(Bprime) + " testing events: ", len(testBprime)
print "number of Bprime " + str(Bprime2) + " testing events: ", len(testBprime2)
print "number of WJets testing events: ", len(testWJets)

arrayBprime = arrayBprime[:maxpersample]
arrayBprime2 = arrayBprime2[:maxpersample]
arrayWJets = arrayWJets[:maxpersample]
arrayTTToSemiLep = arrayTTToSemiLep[:maxpersample]

np.random.shuffle(arrayTTToSemiLep)
np.random.shuffle(arrayBprime)
np.random.shuffle(arrayBprime2)
np.random.shuffle(arrayWJets)
np.random.shuffle(testTTToSemiLep)
np.random.shuffle(testWJets)
np.random.shuffle(testBprime)
np.random.shuffle(testBprime2)

print 'Training ttbar',len(arrayTTToSemiLep)
print 'Training Bprime',len(arrayBprime)
print 'Training WJets',len(arrayWJets)
print 'Testing ttbar',len(testTTToSemiLep)
print 'Testing Bprime',len(testBprime)
print 'Testing WJets',len(testWJets)

ofile.write(str(len(arrayTTToSemiLep)) + ", " + str(len(arrayBprime)) + ", " +str(len(arrayBprime2)) + ", " +str(len(arrayWJets)) + ", " +str(len(testTTToSemiLep)) + ", " +str(len(testBprime)) + ", " +str(len(testBprime2)) + ", " +str(len(testWJets)) + ", ")

## build arrays where each
## entry is a list of all training variables
newArrayTTToSemiLep = []
newArrayBprime = []
newArrayWJets = []
newTestTTToSemiLep = []
newTestBprime = []
newTestBprime2 = []
newTestWJets = []

for entry in arrayTTToSemiLep:
    a = list(entry)
    newArrayTTToSemiLep.append(a)
for entry in arrayBprime:
    a = list(entry)
    newArrayBprime.append(a)
for entry in arrayWJets:
    a = list(entry)
    newArrayWJets.append(a)
for entry in testTTToSemiLep:
    a = list(entry)
    newTestTTToSemiLep.append(a)
for entry in testBprime:
    a = list(entry)
    newTestBprime.append(a)
for entry in testBprime2:
    a = list(entry)
    newTestBprime2.append(a)
for entry in testWJets:
    a = list(entry)
    newTestWJets.append(a)
arrayTTToSemiLep = copy.copy(newArrayTTToSemiLep)
arrayBprime = copy.copy(newArrayBprime)
arrayWJets = copy.copy(newArrayWJets)
testTTToSemiLep = copy.copy(newTestTTToSemiLep)
testBprime = copy.copy(newTestBprime)
testBprime2 = copy.copy(newTestBprime2)
testWJets = copy.copy(newTestWJets)


## Transpose these arrays to get arrays for plotting
## Each entry is one variable for all the events
numPerSample = min(len(arrayTTToSemiLep),len(arrayBprime),len(arrayBprime2),len(arrayWJets))

histsTTToSemiLep = np.array(arrayTTToSemiLep[:numPerSample]).T
histsBprime = np.array(arrayBprime[:numPerSample]).T
histsBprime2 = np.array(arrayBprime2[:numPerSample]).T
histsWJets = np.array(arrayWJets[:numPerSample]).T

## Plot the input variables and save files

for index, hist in enumerate(histsWJets):
   plt.figure()
   plt.hist(hist, bins=50, color='g', label=r'$\mathrm{W+jets}$', histtype='step', normed=True)
   plt.hist(histsBprime[index], bins=50, color='y', label=r'$\mathrm{B\overline{B}\,('+str(Bprime)+'\,TeV)}$', histtype='step', normed=True)
   #plt.hist(histsBprime2[index], bins=50, color='c', label=r'$\mathrm{B\overline{B}\,('+str(Bprime2)+'\,TeV)}$', histtype='step', normed=True)
   plt.hist(histsTTToSemiLep[index], bins=50, color='r', label=r'$\mathrm{t\bar{t}}$', histtype='step', normed=True)
   plt.title('CMS Simulation',loc='left',size=18)
   plt.title('Work in progress',loc='right',size=14,style='italic')
   plt.ylabel('Events per bin',horizontalalignment='right',y=1.0,size=14)
   plt.xlabel(vars[index],horizontalalignment='right',x=1.0,size=14)
   plt.legend(loc='best',fontsize=14)
   if not WithBprimeVars: plt.savefig(outdir+'plots_'+str(vars[index])+outStr)
   if WithBprimeVars: plt.savefig(outdir+'plots_'+str(vars[index])+outStr)
   plt.close()


## Make arrays of "train" and "target" data with samples mixed randomly
## trainData is the data itself, targetData are the correct labels 
print "Randomizing"
import random

trainData = []
targetData = []
testData = []
testLabel = []
nEvents = len(newArrayTTToSemiLep) + len(newArrayBprime) + len(newArrayWJets)
print 'Labeling training data',nEvents
while nEvents > 0:
    rng = random.randint(0,2)
    if (rng == 0 and len(newArrayWJets) > 0):
        trainData.append(newArrayWJets.pop())
        targetData.append(0)
        nEvents = nEvents -1
    if (rng == 1 and len(newArrayTTToSemiLep) > 0):
        trainData.append(newArrayTTToSemiLep.pop())
        targetData.append(1)
        nEvents = nEvents - 1
    if (rng == 2 and len(newArrayBprime) > 0):
        trainData.append(newArrayBprime.pop())
        targetData.append(2)
        nEvents = nEvents - 1

#print 'Train Data:'
#print trainData[0]
#print trainData[1]
#print 'Train Labels:'
#print targetData[:10]

# from sklearn.feature_selection import SelectKBest, f_classif
# trainData_12 = SelectKBest(f_classif, k=12).fit_transform(trainData, targetData)
# print 'Train Data 12:'
# print trainData_12[0]
# print trainData_12[1]

# trainData_16 = SelectKBest(f_classif, k=16).fit_transform(trainData, targetData)
# print 'Train Data 16:'
# print trainData_16[0]
# print trainData_16[1]

# trainData_20 = SelectKBest(f_classif, k=20).fit_transform(trainData, targetData)
# print 'Train Data 20:'
# print trainData_20[0]
# print trainData_20[1]

# trainData_24 = SelectKBest(f_classif, k=24).fit_transform(trainData, targetData)
# print 'Train Data 24:'
# print trainData_24[0]
# print trainData_24[1]

# trainData_28 = SelectKBest(f_classif, k=28).fit_transform(trainData, targetData)
# print 'Train Data 28:'
# print trainData_28[0]
# print trainData_28[1]


nEventsTest = len(newTestTTToSemiLep) + len(newTestBprime) + len(newTestWJets)
if test1100: nEventsTest = len(newTestTTToSemiLep) + len(newTestBprime2) + len(newTestWJets)
print 'Labeling testing data',nEventsTest
while nEventsTest > 0:
    rng = random.randint(0,2)
    if (rng == 0 and len(newTestWJets) > 0):
        testData.append(newTestWJets.pop())
        testLabel.append(0)
        nEventsTest = nEventsTest -1
    if (rng == 1 and len(newTestTTToSemiLep) > 0):
        testData.append(newTestTTToSemiLep.pop())
        testLabel.append(1)
        nEventsTest = nEventsTest - 1
    if (rng == 2):
        if not test1100 and len(newTestBprime) > 0:
            testData.append(newTestBprime.pop())
            testLabel.append(2)
            nEventsTest = nEventsTest - 1
        if test1100 and len(newTestBprime2) > 0:
            testData.append(newTestBprime2.pop())
            testLabel.append(2)
            nEventsTest = nEventsTest - 1

#print 'Test Data:'
#print testData[:10]
#print 'Test Labels:'
#print testLabel[:10]

## Standardize the dataset by scaling all the variables
## to a normal distribution (google the StandardScaler for more)
print 'Building the scaler'
scaler = preprocessing.StandardScaler().fit(trainData)
print 'Transforming...'
trainData = scaler.transform(trainData)
testData = scaler.transform(testData)
arrayWJets = scaler.transform(arrayWJets)
arrayTTToSemiLep = scaler.transform(arrayTTToSemiLep)
arrayBprime = scaler.transform(arrayBprime)
testBprime2 = scaler.transform(testBprime2)
testBprime = scaler.transform(testBprime)
testTTToSemiLep = scaler.transform(testTTToSemiLep)
testWJets = scaler.transform(testWJets)

#print 'Train Data scaled:'
#print trainData[:10]
#print 'Train Labels scaled:'
#print targetData[:10]

#numTrain = trainboost*3
#print 'NumTrain',numTrain
#print 'Training length',len(trainData[:numTrain])

## import the neural networks we will use
from sklearn import neural_network
from sklearn.linear_model import SGDClassifier
from sklearn import tree

## build a multi-layer perceptron with 3 hidden layers of 40 nodes each with the 
## rectified-linear unit activation function. Do all the work in the mlp.fit command
print 'Training...'
mlp = neural_network.MLPClassifier(hidden_layer_sizes=arch2tuple(arch), verbose=True, activation='relu',early_stopping=True)
#mlp.fit(trainData[:numTrain], targetData[:numTrain])
mlp.fit(trainData, targetData)

## options for getting the validation loss too... metrics.log_loss? warm_start + max_iter = 1? somehow tell it which validation sample to use?
losscurve = mlp.loss_curve_
plt.figure()
plt.xlabel('iterations')
plt.ylabel('training loss')
plt.plot(losscurve)
plt.savefig(outdir+'trainloss'+outStr+'.png')
plt.close()

testscore = mlp.validation_scores_
plt.figure()
plt.xlabel('iterations')
plt.ylabel('validation score')
plt.plot(testscore)
plt.savefig(outdir+'valscore'+outStr+'.png')
plt.close()

## Plot a confusion matrix
cm = metrics.confusion_matrix(mlp.predict(testData), testLabel)
plt.figure()
targetNames = [r'$\mathrm{W+jets}$',r'$\mathrm{t\bar{t}}$',r'$\mathrm{B\overline{B}}$']
plot_confusion_matrix(cm.T, targetNames, normalize=True)
if WithBprimeVars: plt.savefig(outdir+'confusion'+outStr+'.png')
if not WithBprimeVars: plt.savefig(outdir+'confusion'+outStr+'.png')
#plt.show()

## Print the overall score from the non-training events
print 'Test data score =',mlp.score(testData, testLabel)
print 'Train data score =',mlp.score(trainData, targetData)

ofile.write(str(mlp.score(testData, testLabel)) + ", ")


## Predict the scores for non-training events
probsWJets = mlp.predict_proba(testWJets)
probsTTToSemiLep = mlp.predict_proba(testTTToSemiLep)
probsBprime = mlp.predict_proba(testBprime)
probsBprime2 = mlp.predict_proba(testBprime2)
probs = [probsWJets, probsTTToSemiLep, probsBprime]
if test1100: probs = [probsWJets, probsTTToSemiLep, probsBprime2]

## Plot the scores
plt.close()
plt.figure()
plt.xlabel('Predicted W boson score',horizontalalignment='right',x=1.0,size=14)
plt.ylabel('Events per bin',horizontalalignment='right',y=1.0,size=14)
plt.title('CMS Simulation',loc='left',size=18)
plt.title('Work in progress',loc='right',size=14,style='italic')
plt.ylim([0.01,10.**4])
plt.hist(probsWJets.T[0], bins=20, range=(0,1), label=r'$\mathrm{W+jets}$', color='g', histtype='step',normed=True, log=True)
plt.hist(probsTTToSemiLep.T[0], bins=20, range=(0,1), label=r'$\mathrm{t\bar{t}}$', color='y', histtype='step',normed=True, log=True)
plt.hist(probsBprime.T[0], bins=20, range=(0,1), label=r'$\mathrm{B\overline{B}\,('+str(Bprime)+'\,TeV)}$', color='m', histtype='step',normed=True, log=True)
plt.hist(probsBprime2.T[0], bins=20, range=(0,1), label=r'$\mathrm{B\overline{B}\,('+str(Bprime2)+'\,TeV)}$', color='c', histtype='step',normed=True, log=True)
plt.legend(loc='best')
#plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc=3, ncol=6, mode="expand", borderaxespad=0.)
plt.savefig(outdir+'score_WJet'+outStr+'.png')
#plt.show()

plt.close()
plt.figure()
plt.xlabel('Predicted top quark score',horizontalalignment='right',x=1.0,size=14)
plt.ylabel('Events per bin',horizontalalignment='right',y=1.0,size=14)
plt.title('CMS Simulation',loc='left',size=18)
plt.title('Work in progress',loc='right',size=14,style='italic')
plt.ylim([0.01,10.**4])
plt.hist(probsWJets.T[1], bins=20, range=(0,1), label=r'$\mathrm{W+jets}$', color='g', histtype='step',normed=True, log=True)
plt.hist(probsTTToSemiLep.T[1], bins=20, range=(0,1), label=r'$\mathrm{t\bar{t}}$', color='y', histtype='step',normed=True, log=True)
plt.hist(probsBprime.T[1], bins=20, range=(0,1), label=r'$\mathrm{B\overline{B}\,('+str(Bprime)+'\,TeV)}$', color='m', histtype='step',normed=True, log=True)
plt.hist(probsBprime2.T[1], bins=20, range=(0,1), label=r'$\mathrm{B\overline{B}\,('+str(Bprime2)+'\,TeV)}$', color='c', histtype='step',normed=True, log=True)
plt.legend(loc='best')
#plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc=3, ncol=6, mode="expand", borderaxespad=0.)
plt.savefig(outdir+'score_TTToSemiLep'+outStr+'.png')
#plt.show()

plt.close()
plt.figure()
plt.xlabel('Predicted B quark score',horizontalalignment='right',x=1.0,size=14)
plt.ylabel('Events per bin',horizontalalignment='right',y=1.0,size=14)
plt.title('CMS Simulation',loc='left',size=18)
plt.title('Work in progress',loc='right',size=14,style='italic')
plt.ylim([0.01,10.**4])
plt.hist(probsWJets.T[2], bins=20, range=(0,1), label=r'$\mathrm{W+jets}$', color='g', histtype='step',normed=True, log=True)
plt.hist(probsTTToSemiLep.T[2], bins=20, range=(0,1), label=r'$\mathrm{t\bar{t}}$', color='y', histtype='step',normed=True, log=True)
plt.hist(probsBprime.T[2], bins=20, range=(0,1), label=r'$\mathrm{B\overline{B}\,('+str(Bprime)+'\,TeV)}$', color='m', histtype='step',normed=True, log=True)
plt.hist(probsBprime2.T[2], bins=20, range=(0,1), label=r'$\mathrm{B\overline{B}\,('+str(Bprime2)+'\,TeV)}$', color='c', histtype='step',normed=True, log=True)
plt.legend(loc='best')
#plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc=3, ncol=6, mode="expand", borderaxespad=0.)
plt.savefig(outdir+'score_Bprime'+outStr+'.png')
#plt.show()



## Binarize scores as needed

# probsWJets_Bprime = copy.copy(probsWJets)
# probsTTToSemiLep_Bprime = copy.copy(probsTTToSemiLep)
# probsBprime_WJets = copy.copy(probsBprime)
# probsBprime_TTToSemiLep = copy.copy(probBprime)
# for entry in probsBprime_WJets:
#     #print entry
#     entry[0] = entry[0] / (entry[0]+entry[2])
#     entry[1] = 0.0
#     entry[2] = entry[2] / (entry[0]+entry[2])
# for entry in probsBprime_TTToSemiLep:
#     #print entry
#     entry[0] = 0.0
#     entry[1] = entry[1] / (entry[1]+entry[2])
#     entry[2] = entry[2] / (entry[1]+entry[2])
# for entry in probsWJets_Bprime:
#     #print entry
#     entry[0] = entry[0] / (entry[0]+entry[2])
#     entry[1] = 0.0
#     entry[2] = entry[2] / (entry[0]+entry[2])
# for entry in probsTTToSemiLep_Bprime:
#     #print entry
#     entry[0] = 0.0
#     entry[1] = entry[1] / (entry[1]+entry[2])
#     entry[2] = entry[2] / (entry[1]+entry[2])


## Plot ROC curves
#truthWJets = np.array([0]*len(arrayWJets[numPerSample:]))
truthWJets = np.array([0]*len(testWJets))
truthTTToSemiLep = np.array([1]*len(testTTToSemiLep))
truthBprime = np.array([2]*len(testBprime))
truthBprime2 = np.array([2]*len(testBprime2))
truth = [truthWJets, truthTTToSemiLep, truthBprime]
if test1100: truth = [truthWJets, truthTTToSemiLep, truthBprime2]
#probsBackground_bin = [probsWJets_Bprime, probsTTToSemiLep_Bprime]
#probs_bin = [probsBprime_WJets, probsBprime_TTToSemiLep]

sig_label = 2
bkg_label = 0

from sklearn.metrics import roc_curve
rocCurves = {}
rocCurves_bin = {}
for bkg_label in [0, 1]:
    rocCurves[bkg_label] = roc_curve(np.concatenate([truth[bkg_label],truth[sig_label]]), np.concatenate([probs[bkg_label].T[sig_label],probs[sig_label].T[sig_label]]), pos_label=sig_label)
rocCurves[2] = roc_curve(np.concatenate([truth[0],truth[1],truth[2]]), np.concatenate([probs[0].T[2],probs[1].T[2],probs[2].T[2]]), pos_label=2)


plt.close()
plt.figure()
plt.semilogy(rocCurves[0][1], rocCurves[0][0], color='g', label='B quark vs W boson')
plt.semilogy(rocCurves[1][1], rocCurves[1][0], color='r', label='B quark vs t quark')
plt.semilogy(rocCurves[2][1], rocCurves[2][0], color='c', label='B quark vs both')
plt.xlim([0.0,1.0])
plt.ylim([0.00001,1.0])
plt.title('CMS Simulation',loc='left',size=18)
plt.title('Work in progress',loc='right',size=14,style='italic')
plt.ylabel('Background Efficiency',horizontalalignment='right',size=14)
plt.xlabel('Signal Efficiency',horizontalalignment='right',size=14)
plt.legend(loc='best')
#plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc=3, ncol=4, mode="expand", borderaxespad=0.)
plt.savefig(outdir+'roc'+outStr+'.png')
#plt.show()

## save the output of the network
np.savez(outdir+'Arrays'+outStr,trainData=trainData, targetData=targetData, testData=testData, testLabel=testLabel, testWJets=testWJets, testTTToSemilep=testTTToSemiLep, testBprime=testBprime, testBprime2=testBprime2)
from sklearn.externals import joblib
joblib.dump(mlp, outdir+'Dnn_mlp_3bin'+outStr+'.pkl')
joblib.dump(scaler, outdir+'Dnn_scaler_3bin'+outStr+'.pkl')

classRep = open('ClassificationReportsBB.txt', 'a+')

from sklearn.metrics import classification_report, f1_score, recall_score, precision_score,accuracy_score
cRep = classification_report(testLabel,mlp.predict(testData),target_names=['Wjets', 'tbar', 'TTbar'], digits = 6)
print cRep
classRep.write('\n================================\n     Test #:' + str(testnum) +'\n================================\n' + cRep)
classRep.close()
prec = precision_score(testLabel, mlp.predict(testData), average='weighted')
recall = recall_score(testLabel, mlp.predict(testData), average='weighted')
fscore = f1_score(testLabel, mlp.predict(testData), average='weighted')


ofile.write(str(prec) + ', ' + str(recall) + ', ' + str(fscore)+ '\n')
ofile.close()


print 'Done'
print("--- %s minutes ---" % (round(time.time() - start_time, 2)/60))

