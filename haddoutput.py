import os,sys,datetime,time
from ROOT import *
execfile("/uscms_data/d2/abarker/area2/CMSSW_7_4_14/src/LJMet/Com/condor_2lep_120715/EOSSafeUtils.py")

start_time = time.time()

#IO directories must be full paths
input  = sys.argv[1]
output = sys.argv[2]
shift = sys.argv[3]

inputDir='/eos/uscms/store/user/lpcljm/'+input+'/'+shift
outputDir='/eos/uscms/store/user/lpcljm/'+output+'/'+shift

inDir=inputDir[10:]
outDir=outputDir[10:]

os.system('eos root://cmseos.fnal.gov/ mkdir -p '+outDir)

signalList = [
    'TprimeTprime_M-700_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'TprimeTprime_M-800_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'TprimeTprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'TprimeTprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'TprimeTprime_M-1100_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'TprimeTprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'TprimeTprime_M-1300_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'TprimeTprime_M-1400_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'TprimeTprime_M-1500_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'TprimeTprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'TprimeTprime_M-1700_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'TprimeTprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    ]

signalOutList = ['BWBW','TZBW','THBW','TZTH','TZTZ','THTH']

for sample in signalList:
    for outlabel in signalOutList:

        rootfiles = EOSlist_root_files(inputDir+'/'+sample+'_'+outlabel)
#        print 'N root files in',sample,'=',len(rootfiles)
        haddcommand = 'hadd root://cmseos.fnal.gov/'+outDir+'/'+sample+'_'+outlabel+'_hadd.root '

        print '##########'*15
        print 'HADDING:', sample,'_',outlabel
        print '##########'*15

        for file in rootfiles:
           
            haddcommand+=' root://cmseos.fnal.gov/'+inDir+'/'+sample+'_'+outlabel+'/'+file

        os.system(haddcommand)
#        print haddcommand


signalList = [
    'BprimeBprime_M-700_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'BprimeBprime_M-800_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'BprimeBprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'BprimeBprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'BprimeBprime_M-1100_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'BprimeBprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'BprimeBprime_M-1300_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'BprimeBprime_M-1400_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'BprimeBprime_M-1500_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'BprimeBprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'BprimeBprime_M-1700_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    'BprimeBprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns',
    ]

signalOutList = ['TWTW','BZTW','BHTW','BZBH','BZBZ','BHBH']

for sample in signalList:
    for outlabel in signalOutList:

        rootfiles = EOSlist_root_files(inputDir+'/'+sample+'_'+outlabel)
#        print 'N root files in',sample,'=',len(rootfiles)
        haddcommand = 'hadd root://cmseos.fnal.gov/'+outDir+'/'+sample+'_'+outlabel+'_hadd.root '

        print '##########'*15
        print 'HADDING:', sample,'_',outlabel
        print '##########'*15

        for file in rootfiles:
           
            haddcommand+=' root://cmseos.fnal.gov/'+inDir+'/'+sample+'_'+outlabel+'/'+file

        os.system(haddcommand)
#        print haddcommand


dirList = [
#    'TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',
#    'WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',
    'TT_TuneCUETP8M1_13TeV-powheg-pythia8_highstats_25ns',
    'TT_Mtt-1000toInf_TuneCUETP8M1_13TeV-powheg-pythia8_25ns',
    'TT_Mtt-700to1000_TuneCUETP8M1_13TeV-powheg-pythia8_25ns',
    'WW_TuneCUETP8M1_13TeV-pythia8_25ns',						      
    'WZ_TuneCUETP8M1_13TeV-pythia8_25ns',						      
    'ZZ_TuneCUETP8M1_13TeV-pythia8_25ns',						      
    'DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_25ns',			      
    'ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1_25ns',		      
    'ST_t-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1_25ns',		      
    'ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_25ns',		      
    'ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_25ns',		      
    'TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8_25ns',		      
    'TTWJetsToQQ_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8_25ns',			      
    'TTZToQQ_TuneCUETP8M1_13TeV-amcatnlo-pythia8_25ns',					      
    'TTZToLLNuNu_M-10_TuneCUETP8M1_13TeV-amcatnlo-pythia8_25ns',			      
   
    'QCD_HT100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',			      
    'QCD_HT200to300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',			      
    'QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',			      
    'QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',			      
    'QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',			      
    'QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',			      
    'QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',			      
    'QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',              	      
  
    'WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',
    'WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',
    'WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',
    'WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',
    'WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',
    'WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',
    'WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',    
    ]

if shift == 'nominal':
    # These don't need to be run for shifted directories
    dirList.append('ST_tW_top_5f_scaleup_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_25ns')
    dirList.append('ST_tW_top_5f_scaledown_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_25ns')	      
    dirList.append('ST_tW_antitop_5f_scaleup_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_25ns')	      
    dirList.append('ST_tW_antitop_5f_scaledown_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_25ns')      
    dirList.append('TT_TuneCUETP8M1_13TeV-powheg-scaledown-pythia8_25ns')
    dirList.append('TT_TuneCUETP8M1_13TeV-powheg-scaleup-pythia8_25ns')
    dirList.append('SingleElectron_RRC')
    dirList.append('SingleMuon_RRC')
    dirList.append('SingleElectron_RRD')
    dirList.append('SingleMuon_RRD')
    dirList.append('SingleElectron_PRD_xrd')
    dirList.append('SingleMuon_PRD_xrd')

for sample in dirList:

    rootfiles = EOSlist_root_files(inputDir+'/'+sample)
#    print 'N root files in',sample,'=',len(rootfiles)
    haddcommand = 'hadd root://cmseos.fnal.gov/'+outDir+'/'+sample+'_hadd.root '

    print '##########'*15
    print 'HADDING:', sample
    print '##########'*15

    nFilesPerHadd = 1000

    if len(rootfiles) < nFilesPerHadd:
        haddcommand = 'hadd root://cmseos.fnal.gov/'+outDir+'/'+sample+'_hadd.root '
        for file in rootfiles:
            haddcommand+=' root://cmseos.fnal.gov/'+inDir+'/'+sample+'/'+file
        os.system(haddcommand)
    else:
        for i in range(int(len(rootfiles)/nFilesPerHadd)):
            haddcommand = 'hadd root://cmseos.fnal.gov/'+outDir+'/'+sample+'_'+str(i+1)+'_hadd.root '
            begin=i*nFilesPerHadd
            end=begin+nFilesPerHadd
            if len(rootfiles) - end < nFilesPerHadd: end=len(rootfiles)
            for j in range(begin,end):
                haddcommand+=' root://cmseos.fnal.gov/'+inDir+'/'+sample+'/'+rootfiles[j]
            os.system(haddcommand)
            #        print haddcommand

sample = 'TT_TuneCUETP8M1_13TeV-powheg-pythia8_highstats_25ns'
TTOutList = ['Mtt0to700','Mtt700to1000','Mtt1000toInf']

for outlabel in TTOutList:

    rootfiles = EOSlist_root_files(inputDir+'/'+sample+'_'+outlabel)
#    print 'N root files in',sample,'=',len(rootfiles)
    haddcommand = 'hadd root://cmseos.fnal.gov/'+outDir+'/'+sample+'_'+outlabel+'_hadd.root '
    
    print '##########'*15
    print 'HADDING:', sample,'_',outlabel
    print '##########'*15

    for file in rootfiles:

        haddcommand+=' root://cmseos.fnal.gov/'+inDir+'/'+sample+'_'+outlabel+'/'+file

    os.system(haddcommand)

print("--- %s minutes ---" % (round(time.time() - start_time, 2)/60))



