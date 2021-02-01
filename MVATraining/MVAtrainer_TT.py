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

## Read in the arguments
start_time = time.time()
arch = '3x10'
maxtest = 15000
outdir = sys.argv[1]
vararray = int(sys.argv[2])
testnum = int(sys.argv[3])
year = str(sys.argv[4])
if year == 'all': maxtest = 30000

## Set up the logs
outdir = outdir + '/'
if testnum == 1:
   ofile = open(outdir+"TT_output_Jan21_"+year+".txt","a+")
   ofile.write('\ntest, vararray, Testing Score (Accuracy), tt-as-TT, TT-as-TT, Precision, Recall, F-Score \n')
else:
   time.sleep(2)
   ofile = open(outdir+"TT_output_Jan21_"+year+".txt","a+")
   ofile.write('\n')
ofile.write(str(testnum)+", ")
ofile.write(str(vararray)+", ")

## Set which signal we will use
Tprime = 1.0
Tprime2 = 1.8
test1100 = False #use if Tprime = 1800

## Make new directory and set a label for all files
outStr = '_'+year+'TT_'+str(arch)+'_' + str(millify(maxtest)) +'test_vars'+str(vararray)+'_Test'+str(testnum)
print 'Outstr:',outStr,'Outdir:',outdir
if not os.path.exists(outdir): os.system('mkdir '+outdir)

## List of possible variables for the MVA, default is 2017
varList = ['dnnJ_1','dnnJ_2','jetPt_1','jetPt_3','sdMass_1','sdMass_3','tau21_3','AK4HT','t_pt','t_mass','t_dRWb','AK4HTpMETpLepPt','corr_met_MultiLepCalc','NJets_JetSubCalc', 'NJetsDeepFlavwithSF_JetSubCalc','NJetsAK8_JetSubCalc','minDR_leadAK8otherAK8'] 
#'jetPt_2','sdMass_2','dnnJ_3', removed for bad data/bkg agreement  #'tau21_1','tau21_2', removed since not used before

if year == '2016':
   varList = ['dnnJ_1','dnnJ_2','dnnJ_3','jetPt_1','jetPt_3','sdMass_1','tau21_3','AK4HT','t_pt','t_mass','t_dRWb','AK4HTpMETpLepPt','corr_met_MultiLepCalc','NJets_JetSubCalc', 'NJetsDeepFlavwithSF_JetSubCalc','NJetsAK8_JetSubCalc','minDR_leadAK8otherAK8'] 
   #'jetPt_2','sdMass_2','sdMass_3', removed for bad data/bkg agreement  #'tau21_1','tau21_2', removed since not used before
elif year == '2018':
   varList = ['dnnJ_1','dnnJ_2','dnnJ_3','jetPt_1','jetPt_3','sdMass_3','tau21_3','AK4HT','t_pt','t_mass','t_dRWb','AK4HTpMETpLepPt','corr_met_MultiLepCalc','NJets_JetSubCalc', 'NJetsDeepFlavwithSF_JetSubCalc','NJetsAK8_JetSubCalc','minDR_leadAK8otherAK8'] 
   #'jetPt_2','sdMass_2','sdMass_1', removed for bad data/bkg agreement  #'tau21_1','tau21_2', removed since not used before
elif year == 'all':
   varList = ['dnnJ_1','dnnJ_2','jetPt_1','jetPt_3','sdMass_1','sdMass_3','tau21_3','AK4HT','t_pt','t_mass','t_dRWb','AK4HTpMETpLepPt','corr_met_MultiLepCalc','NJets_JetSubCalc', 'NJetsDeepFlavwithSF_JetSubCalc','NJetsAK8_JetSubCalc','minDR_leadAK8otherAK8'] 

## Make a big list of lists of different lengths and combinations
combos = []
for size in range(7,len(varList)):
   thissize = list(itertools.combinations(varList,size))
   for item in thissize:
      ## Some sanity checks for vars we know for sure we want to include
      if 'dnnJ_1' not in item: continue
      if 'dnnJ_2' not in item and 'dnnJ_3' not in item: continue
      if 'AK4HT' not in item: continue
      if 'corr_met_MultiLepCalc' not in item and 'AK4HTpMETpLepPt' not in item: continue
      if 'NJetsDeepFlavwithSF_JetSubCalc' not in item and 'NJets_JetSubCalc' not in item: continue
      if 't_mass' not in item and 't_pt' not in item: continue
      if 't_drWb' not in item and 'minDR_leadAK8otherAK8' not in item: continue
      if year == 'all':
         if 'minDR_leadAK8otherAK8' not in item: continue
         if 'dnnJ_2' not in item: continue
         if 'NJetsDeepFlavwithSF_JetSubCalc' not in item: continue
         if 'AK4HTpMETpLepPt' not in item: continue
      combos.append(item)
combos.append(varList)

## Choose our particular variable list for this test
vars = list(combos[vararray])
print 'Vars =',vars

indexKill = range(0,len(varList))
for item in vars:
   indexKill.remove(varList.index(item))

inStr = '_'+year+'TT_'+str(arch)+'_' + str(millify(maxtest)) +'test'
allmystuff = np.load(outdir+'Arrays'+inStr+'.npz')

trainData = (allmystuff['trainData']).tolist()
trainLabel = (allmystuff['trainLabel']).tolist()
testData = (allmystuff['testData']).tolist()
testLabel = (allmystuff['testLabel']).tolist()
testWJets = (allmystuff['testWJets']).tolist()
testTTToSemiLep = (allmystuff['testTTToSemilep']).tolist()
testTprime = (allmystuff['testTprime']).tolist()
testTprime2 = (allmystuff['testTprime2']).tolist()

## Get rid of the variables we aren't using this time
for i in range(0,len(trainData)):
   for j in sorted(indexKill, reverse = True):
      del trainData[i][j]
for i in range(0,len(testData)):
   for j in sorted(indexKill, reverse = True):
      del testData[i][j]
for i in range(0,len(testWJets)):
   for j in sorted(indexKill, reverse = True):
      del testWJets[i][j]
      del testTprime[i][j]
      del testTprime2[i][j]
      del testTTToSemiLep[i][j]

## Standardize the dataset by scaling all the variables                                                                                                            
## to a normal distribution (google the StandardScaler for more)                                                                                                   
print 'Building the scaler...'
scaler = preprocessing.StandardScaler().fit(trainData)
print 'Transforming...'
trainData = scaler.transform(trainData)
testData = scaler.transform(testData)
testTprime2 = scaler.transform(testTprime2)
testTprime = scaler.transform(testTprime)
testTTToSemiLep = scaler.transform(testTTToSemiLep)
testWJets = scaler.transform(testWJets)

## Print the same sample of 3 events after the scaling procedure                                                                                                   
# print 'Train Data scaled:'                                                                                                                                       
# print trainData[:3]                                                                                                                                              
# print 'Train Label scaled:'                                                                                                                                      
# print trainLabel[:3] 

## build a multi-layer perceptron with 3 hidden layers of 40 nodes each with the 
## rectified-linear unit activation function. Do all the work in the mlp.fit command
print 'Training...'
mlp = neural_network.MLPClassifier(hidden_layer_sizes=arch2tuple(arch), activation='relu',early_stopping=True)
mlp.fit(trainData, trainLabel)

## Print the overall score from the non-training events and save it to the log
print 'Test data score =',mlp.score(testData, testLabel)
print 'Train data score =',mlp.score(trainData, trainLabel)
ofile.write(str(round(mlp.score(testData, testLabel),5)) + ", ")

## Plot a confusion matrix
cm = metrics.confusion_matrix(mlp.predict(testData), testLabel)
plt.figure()
targetNames = [r'$\mathrm{W+jets}$',r'$\mathrm{t\bar{t}}$',r'$\mathrm{T\overline{T}}$']
plot_confusion_matrix(cm.T, targetNames, normalize=True)

cm = (cm.T).astype('float') / (cm.T).sum(axis=1)[:, np.newaxis]

ofile.write(str(round(cm[1][2],5)) + ", " + str(round(cm[2][2],5)) + ", ")

threshold = 0.78
if year == 'all': threshold = 0.83
if mlp.score(testData,testLabel) > threshold:

   plt.savefig(outdir+'confusion'+outStr+'.png')

   ## Draw training sample loss curve
   losscurve = mlp.loss_curve_
   plt.figure()
   plt.xlabel('iterations')
   plt.ylabel('training loss')
   plt.plot(losscurve)
   plt.savefig(outdir+'trainloss'+outStr+'.png')
   plt.close()
   
   ## Draw validation sample (10% of the training data) score
   testscore = mlp.validation_scores_
   plt.figure()
   plt.xlabel('iterations')
   plt.ylabel('validation score')
   plt.plot(testscore)
   plt.savefig(outdir+'valscore'+outStr+'.png')
   plt.close()
   
   ## Predict the scores for non-training events
   probsWJets = mlp.predict_proba(testWJets)
   probsTTToSemiLep = mlp.predict_proba(testTTToSemiLep)
   probsTprime = mlp.predict_proba(testTprime)
   probsTprime2 = mlp.predict_proba(testTprime2)
   probs = [probsWJets, probsTTToSemiLep, probsTprime]
   if test1100: probs = [probsWJets, probsTTToSemiLep, probsTprime2]

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
   plt.hist(probsTprime.T[0], bins=20, range=(0,1), label=r'$\mathrm{T\overline{T}\,('+str(Tprime)+'\,TeV)}$', color='m', histtype='step',normed=True, log=True)
   plt.hist(probsTprime2.T[0], bins=20, range=(0,1), label=r'$\mathrm{T\overline{T}\,('+str(Tprime2)+'\,TeV)}$', color='c', histtype='step',normed=True, log=True)
   plt.legend(loc='best')
   plt.savefig(outdir+'score_WJet'+outStr+'.png')
   
   plt.close()
   plt.figure()
   plt.xlabel('Predicted top quark score',horizontalalignment='right',x=1.0,size=14)
   plt.ylabel('Events per bin',horizontalalignment='right',y=1.0,size=14)
   plt.title('CMS Simulation',loc='left',size=18)
   plt.title('Work in progress',loc='right',size=14,style='italic')
   plt.ylim([0.01,10.**4])
   plt.hist(probsWJets.T[1], bins=20, range=(0,1), label=r'$\mathrm{W+jets}$', color='g', histtype='step',normed=True, log=True)
   plt.hist(probsTTToSemiLep.T[1], bins=20, range=(0,1), label=r'$\mathrm{t\bar{t}}$', color='y', histtype='step',normed=True, log=True)
   plt.hist(probsTprime.T[1], bins=20, range=(0,1), label=r'$\mathrm{T\overline{T}\,('+str(Tprime)+'\,TeV)}$', color='m', histtype='step',normed=True, log=True)
   plt.hist(probsTprime2.T[1], bins=20, range=(0,1), label=r'$\mathrm{T\overline{T}\,('+str(Tprime2)+'\,TeV)}$', color='c', histtype='step',normed=True, log=True)
   plt.legend(loc='best')
   plt.savefig(outdir+'score_TTToSemiLep'+outStr+'.png')
   
   plt.close()
   plt.figure()
   plt.xlabel('Predicted T quark score',horizontalalignment='right',x=1.0,size=14)
   plt.ylabel('Events per bin',horizontalalignment='right',y=1.0,size=14)
   plt.title('CMS Simulation',loc='left',size=18)
   plt.title('Work in progress',loc='right',size=14,style='italic')
   plt.ylim([0.01,10.**4])
   plt.hist(probsWJets.T[2], bins=20, range=(0,1), label=r'$\mathrm{W+jets}$', color='g', histtype='step',normed=True, log=True)
   plt.hist(probsTTToSemiLep.T[2], bins=20, range=(0,1), label=r'$\mathrm{t\bar{t}}$', color='y', histtype='step',normed=True, log=True)
   plt.hist(probsTprime.T[2], bins=20, range=(0,1), label=r'$\mathrm{T\overline{T}\,('+str(Tprime)+'\,TeV)}$', color='m', histtype='step',normed=True, log=True)
   plt.hist(probsTprime2.T[2], bins=20, range=(0,1), label=r'$\mathrm{T\overline{T}\,('+str(Tprime2)+'\,TeV)}$', color='c', histtype='step',normed=True, log=True)
   plt.legend(loc='best')
   plt.savefig(outdir+'score_Tprime'+outStr+'.png')

   ## Print important things to files and the screen
   classRep = open('ClassificationReportsTT.txt', 'a+')
   cRep = classification_report(testLabel,mlp.predict(testData),target_names=['Wjets', 'ttbar', 'TTbar'], digits = 6)
   classRep.write('\n================================\n     Test #:' + str(testnum) +'\n================================\n' + cRep)
   classRep.close()

prec = precision_score(testLabel, mlp.predict(testData), average='weighted')
recall = recall_score(testLabel, mlp.predict(testData), average='weighted')
fscore = f1_score(testLabel, mlp.predict(testData), average='weighted')
   
## save the output of the network
joblib.dump(mlp, outdir+'Dnn_mlp_3bin'+outStr+'.pkl')
joblib.dump(scaler, outdir+'Dnn_scaler_3bin'+outStr+'.pkl')

ofile.write(str(round(prec,5)) + ', ' + str(round(recall,5)) + ', ' + str(round(fscore,5))+ '\n')
ofile.close()

print 'Done'
print("--- %s minutes ---" % (round(time.time() - start_time, 2)/60))

