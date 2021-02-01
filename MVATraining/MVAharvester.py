import os,sys,csv,itertools

logfile = sys.argv[1]
year = sys.argv[2]

sig = 'TT'
if 'BB' in logfile: sig = 'BB'

trainings = []
with open(logfile, mode='r') as csv_file:
    for i in range(0,3):
        ## Skip however many lines you need so that the first line has the labels
        csv_file.next()

    csv_reader = csv.DictReader(csv_file)    
    line_count = 0
    for row in csv_reader:
        if sig == 'TT':
            trainings.append(dict(row))
        else:
            ## If there is junk at the top of your file AFTER the labels you can skip lines...
            #if line_count > 622: 
            trainings.append(dict(row))
        line_count += 1

print 'Found',len(trainings),'trainings'
print trainings[0]
print trainings[1]
print trainings[2]

#Lines look like this:
#{' Testing Score (Accuracy)': ' 0.77941', ' F-Score ': ' 0.77613', ' vararray': ' 8', ' Recall': ' 0.77941', ' Precision': ' 0.77685', 'test': '8', ' TT-as-TT': ' 0.86543', ' tt-as-TT': ' 0.18887'}

## List of possible variables for the MVA -- default is 2017
varList = ['dnnJ_1','dnnJ_2','jetPt_1','jetPt_3','sdMass_1','sdMass_3','tau21_3','AK4HT','t_pt','t_mass','t_dRWb','AK4HTpMETpLepPt','corr_met_MultiLepCalc','NJets_JetSubCalc', 'NJetsDeepFlavwithSF_JetSubCalc','NJetsAK8_JetSubCalc','minDR_leadAK8otherAK8'] 
if year == '2016':
   varList = ['dnnJ_1','dnnJ_2','dnnJ_3','jetPt_1','jetPt_3','sdMass_1','tau21_3','AK4HT','t_pt','t_mass','t_dRWb','AK4HTpMETpLepPt','corr_met_MultiLepCalc','NJets_JetSubCalc', 'NJetsDeepFlavwithSF_JetSubCalc','NJetsAK8_JetSubCalc','minDR_leadAK8otherAK8'] 
elif year == '2018':
   varList = ['dnnJ_1','dnnJ_2','dnnJ_3','jetPt_1','jetPt_3','sdMass_3','tau21_3','AK4HT','t_pt','t_mass','t_dRWb','AK4HTpMETpLepPt','corr_met_MultiLepCalc','NJets_JetSubCalc', 'NJetsDeepFlavwithSF_JetSubCalc','NJetsAK8_JetSubCalc','minDR_leadAK8otherAK8'] 
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
        combos.append(item)
combos.append(varList)

if year == 'all':
    ## Make a big list of lists of different lengths and combinations
    combos = []
    for size in range(10,len(varList)):
        thissize = list(itertools.combinations(varList,size))
        for item in thissize:
            ## Some sanity checks for vars we know for sure we want to include
            if 'dnnJ_1' not in item: continue
            if 'dnnJ_2' not in item: continue
            if 'AK4HT' not in item: continue
            if 'AK4HTpMETpLepPt' not in item: continue
            if 'NJetsDeepFlavwithSF_JetSubCalc' not in item: continue
            if 'NJets_JetSubCalc' not in item: continue
            if 't_mass' not in item and 't_pt' not in item: continue
            if 'minDR_leadAK8otherAK8' not in item: continue
            combos.append(item)
    combos.append(varList)

print 'I expect',len(combos),'tests'

maxFscore = max(trainings, key=lambda x:float(x[' F-Score ']))
maxAcc = max(trainings, key=lambda x:float(x[' Recall']))
if sig == 'TT':
    minMistag = min(trainings, key=lambda x:float(x[' tt-as-TT']))
    maxSignal = max(trainings, key=lambda x:float(x[' TT-as-TT']))
else:
    minMistag = min(trainings, key=lambda x:float(x[' tt-as-BB']))
    maxSignal = max(trainings, key=lambda x:float(x[' BB-as-BB']))

print 'Max Fscore:',maxFscore
print '\t vars:',combos[int(maxFscore[' vararray'])]
#print 'Max Accuracy:',maxAcc
#print 'Min mistag:',minMistag
#print 'Max SigEff:',maxSignal

minvars = 999
mintt = 1.0
closescores = 0
maxFwithoutJ3 = 0
lowNhighFtraining = maxFscore
lowMisHighFtraining = maxFscore
highFnoJ3training = maxFscore

mistagKey = ' tt-as-TT'
if sig == 'BB': 
    mistagKey = ' tt-as-BB'

for training in trainings:
    if 'dnnJ_3' not in combos[int(training[' vararray'])] and float(training[' F-Score ']) > maxFwithoutJ3:
        maxFwithoutJ3 = float(training[' F-Score '])
        highFnoJ3training = training

    if abs(float(training[' F-Score ']) - float(maxFscore[' F-Score '])) < 0.005:        
        closescores += 1
        Nvars = len(combos[int(training[' vararray'])])
        tt = float(training[mistagKey])

        if tt < mintt:
            #print 'LOWERING mistagging to',tt
            mintt = tt
            lowMisHighFtraining = training            

        if Nvars < minvars: 
            #print 'LOWERING nvars to',Nvars
            minvars = Nvars
            lowNhighFtraining = training
        if Nvars == minvars and float(training[mistagKey]) < float(lowNhighFtraining[mistagKey]):
            #print 'SAME nvars, LOWERING ttbar mistagging!'
            lowNhighFtraining = training
        
print
print 'Got close scores:',closescores
print 'Lowest number of variables nearby:',lowNhighFtraining
print '\t vars =',combos[int(lowNhighFtraining[' vararray'])]
print 'Lowest mistagging nearby:',lowMisHighFtraining
print '\t vars =',combos[int(lowMisHighFtraining[' vararray'])]
print
print 'Highest F-Score without dnnJ_3:',highFnoJ3training
print '\t vars =',combos[int(highFnoJ3training[' vararray'])]
