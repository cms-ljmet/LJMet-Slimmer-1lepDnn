## Python version of runDnnTraing with no manual button pushing 
## corresponds to command < python -u DnnTraining.py outdir arch vararray maxtest testnum >

import os, sys, itertools

whichsig = sys.argv[1] ## TT or BB

setupFile = 'MVAsetup_2017'+whichsig+'.py'
fileToTrain = 'MVAtrainer_'+whichsig+'.py'
outdir = 'MVAtraining_Jan2021_2017'          ## Doesn't change
vararray = 0 				     ## LOTS AND LOTS
testnum = 0 				     ## increment by one

## List of possible variables for the MVA
varList = ['dnnJ_1','dnnJ_2','jetPt_1','jetPt_3','sdMass_1','sdMass_3','tau21_3','AK4HT','t_pt','t_mass','t_dRWb','AK4HTpMETpLepPt','corr_met_MultiLepCalc','NJets_JetSubCalc', 'NJetsDeepFlavwithSF_JetSubCalc','NJetsAK8_JetSubCalc','minDR_leadAK8otherAK8'] 
#'jetPt_2','sdMass_2','dnnJ_3', removed for bad data/bkg agreement  #'tau21_1','tau21_2', removed since not used before

## Make a big list of lists of different lengths and combinations
combos = []
for size in range(7,len(varList)):
   thissize = list(itertools.combinations(varList,size))
   for item in thissize:
      ## Some sanity checks for vars we know for sure we want to include
      if 'dnnJ_1' not in item: continue
      if 'dnnJ_2' not in item: continue
      if 'AK4HT' not in item: continue
      if 'corr_met_MultiLepCalc' not in item and 'AK4HTpMETpLepPt' not in item: continue
      if 'NJetsDeepFlavwithSF_JetSubCalc' not in item and 'NJets_JetSubCalc' not in item: continue
      if 't_mass' not in item and 't_pt' not in item: continue
      if 't_drWb' not in item and 'minDR_leadAK8otherAK8' not in item: continue
      combos.append(item)
combos.append(varList)

print 'Setting up!'
os.system('python -u '+setupFile+' '+outdir)
os.system('sleep 2')

print 'Looping over vars...'
for vararray in range(0,len(combos)):

        print '---------------- Test: '+ str(testnum) + '\t Var: ' + str(vararray) + '\t Output: ' + outdir + '---------------------------'
        os.system('python -u '+fileToTrain+' '+outdir+' '+str(vararray)+' '+str(testnum)+' 2017')
        testnum = testnum + 1
