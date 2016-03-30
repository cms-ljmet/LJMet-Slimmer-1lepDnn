import os,shutil,datetime,time
import getpass
from ROOT import *
execfile("/uscms_data/d2/abarker/area2/CMSSW_7_4_14/src/LJMet/Com/condor_2lep_120715/EOSSafeUtils.py")

start_time = time.time()

shift = sys.argv[1]

#IO directories must be full paths

relbase = '/uscms_data/d3/jmanagan/CMSSW_7_4_14/'
inputDir='/eos/uscms/store/user/lpcljm/LJMet_1lepTT_022916/'+shift+'/'
outputDir='/eos/uscms/store/user/lpcljm/LJMet_1lepTT_031516_step1/'+shift+'/'
condorDir='/uscms_data/d3/jmanagan/LJMet_1lepTT_031516_step1/'+shift+'/'

runDir=os.getcwd()
# Can change the file directory if needed
#if '' not in shift: runDirPost = ''
#else: runDirPost = shift+'Files'
runDirPost = ''
print 'Files from',runDirPost

gROOT.ProcessLine('.x compileStep1.C')

cTime=datetime.datetime.now()
date='%i_%i_%i_%i_%i_%i'%(cTime.year,cTime.month,cTime.day,cTime.hour,cTime.minute,cTime.second)

inDir=inputDir[10:]
outDir=outputDir[10:]

print 'Getting proxy'
proxyPath=os.popen('voms-proxy-info -path')
proxyPath=proxyPath.readline().strip()

print 'Starting submission'
count=0

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
    rootfiles = EOSlist_root_files(inputDir+sample)
    relPath = sample        
    for outlabel in signalOutList:
        os.system('eos root://cmseos.fnal.gov/ mkdir -p '+outDir+sample+'_'+outlabel)
        os.system('mkdir -p '+condorDir+sample+'_'+outlabel)

        for file in rootfiles:
            #        print file
            rawname = file[:-5]
            count+=1
            dict={'RUNDIR':runDir, 'POST':runDirPost, 'RELPATH':relPath, 'LABEL':outlabel, 'CONDORDIR':condorDir, 'INPUTDIR':inDir, 'FILENAME':rawname, 'PROXY':proxyPath, 'CMSSWBASE':relbase, 'OUTPUTDIR':outDir}
            jdfName=condorDir+'/%(RELPATH)s_%(LABEL)s/%(FILENAME)s_%(LABEL)s.job'%dict
            print jdfName
            jdf=open(jdfName,'w')
            jdf.write(
                """x509userproxy = %(PROXY)s
universe = vanilla
Executable = %(RUNDIR)s/makeStep1.sh
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Transfer_Input_Files = %(RUNDIR)s/makeStep1.C, %(RUNDIR)s/%(POST)s/step1.cc, %(RUNDIR)s/%(POST)s/step1.h, %(RUNDIR)s/%(POST)s/step1_cc.d, %(RUNDIR)s/%(POST)s/step1_cc.so, %(RUNDIR)s/csc2015_Dec01.txt, %(RUNDIR)s/ecalscn1043093_Dec01.txt
Output = %(FILENAME)s_%(LABEL)s.out
Error = %(FILENAME)s_%(LABEL)s.err
Log = %(FILENAME)s_%(LABEL)s.log
Notification = Never
Arguments = %(FILENAME)s.root %(FILENAME)s_%(LABEL)s.root %(INPUTDIR)s/%(RELPATH)s %(OUTPUTDIR)s/%(RELPATH)s_%(LABEL)s

Queue 1"""%dict)
            jdf.close()
            os.chdir('%s/%s_%s'%(condorDir,relPath,outlabel))
            os.system('condor_submit %(FILENAME)s_%(LABEL)s.job'%dict)
            os.system('sleep 0.5')                                
            os.chdir('%s'%(runDir))
            print count, "jobs submitted!!!"

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
    rootfiles = EOSlist_root_files(inputDir+sample)
    relPath = sample        
    for outlabel in signalOutList:
        os.system('eos root://cmseos.fnal.gov/ mkdir -p '+outDir+sample+'_'+outlabel)
        os.system('mkdir -p '+condorDir+sample+'_'+outlabel)

        for file in rootfiles:
            #        print file
            rawname = file[:-5]
            count+=1
            dict={'RUNDIR':runDir, 'POST':runDirPost, 'RELPATH':relPath, 'LABEL':outlabel, 'CONDORDIR':condorDir, 'INPUTDIR':inDir, 'FILENAME':rawname, 'PROXY':proxyPath, 'CMSSWBASE':relbase, 'OUTPUTDIR':outDir}
            jdfName=condorDir+'/%(RELPATH)s_%(LABEL)s/%(FILENAME)s_%(LABEL)s.job'%dict
            print jdfName
            jdf=open(jdfName,'w')
            jdf.write(
                """x509userproxy = %(PROXY)s
universe = vanilla
Executable = %(RUNDIR)s/makeStep1.sh
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Transfer_Input_Files = %(RUNDIR)s/makeStep1.C, %(RUNDIR)s/%(POST)s/step1.cc, %(RUNDIR)s/%(POST)s/step1.h, %(RUNDIR)s/%(POST)s/step1_cc.d, %(RUNDIR)s/%(POST)s/step1_cc.so, %(RUNDIR)s/csc2015_Dec01.txt, %(RUNDIR)s/ecalscn1043093_Dec01.txt
Output = %(FILENAME)s_%(LABEL)s.out
Error = %(FILENAME)s_%(LABEL)s.err
Log = %(FILENAME)s_%(LABEL)s.log
Notification = Never
Arguments = %(FILENAME)s.root %(FILENAME)s_%(LABEL)s.root %(INPUTDIR)s/%(RELPATH)s %(OUTPUTDIR)s/%(RELPATH)s_%(LABEL)s

Queue 1"""%dict)
            jdf.close()
            os.chdir('%s/%s_%s'%(condorDir,relPath,outlabel))
            os.system('condor_submit %(FILENAME)s_%(LABEL)s.job'%dict)
            os.system('sleep 0.5')                                
            os.chdir('%s'%(runDir))
            print count, "jobs submitted!!!"

dirList = [
    'TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_25ns',
    'WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',
    'TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_25ns',
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
    os.system('eos root://cmseos.fnal.gov/ mkdir -p '+outDir+sample)
    os.system('mkdir -p '+condorDir+sample)
    relPath = sample

    rootfiles = EOSlist_root_files(inputDir+sample)
    for file in rootfiles:
#        print file
        rawfile = file[:-5]
        count+=1
        dict={'RUNDIR':runDir, 'POST':runDirPost, 'RELPATH':relPath, 'CONDORDIR':condorDir, 'INPUTDIR':inDir, 'FILENAME':rawfile, 'PROXY':proxyPath, 'CMSSWBASE':relbase, 'OUTPUTDIR':outDir}
        jdfName=condorDir+'/%(RELPATH)s/%(FILENAME)s.job'%dict
        print jdfName
        jdf=open(jdfName,'w')
        jdf.write(
            """x509userproxy = %(PROXY)s
universe = vanilla
Executable = %(RUNDIR)s/makeStep1.sh
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Transfer_Input_Files = %(RUNDIR)s/makeStep1.C, %(RUNDIR)s/%(POST)s/step1.cc, %(RUNDIR)s/%(POST)s/step1.h, %(RUNDIR)s/%(POST)s/step1_cc.d, %(RUNDIR)s/%(POST)s/step1_cc.so, %(RUNDIR)s/csc2015_Dec01.txt, %(RUNDIR)s/ecalscn1043093_Dec01.txt
Output = %(FILENAME)s.out
Error = %(FILENAME)s.err
Log = %(FILENAME)s.log
Notification = Never
Arguments = %(FILENAME)s.root %(FILENAME)s.root %(INPUTDIR)s/%(RELPATH)s %(OUTPUTDIR)s/%(RELPATH)s

Queue 1"""%dict)
        jdf.close()
        os.chdir('%s/%s'%(condorDir,relPath))
        os.system('condor_submit %(FILENAME)s.job'%dict)
        os.system('sleep 0.5')                                
        os.chdir('%s'%(runDir))
        print count, "jobs submitted!!!"

sample = 'TT_TuneCUETP8M1_13TeV-powheg-pythia8_highstats_25ns'
TTOutList = ['Mtt0to700','Mtt700to1000','Mtt1000toInf']

rootfiles = EOSlist_root_files(inputDir+sample)
relPath = sample        
for outlabel in TTOutList:
    os.system('eos root://cmseos.fnal.gov/ mkdir -p '+outDir+sample+'_'+outlabel)
    os.system('mkdir -p '+condorDir+sample+'_'+outlabel)

    for file in rootfiles:
        #        print file
        rawname = file[:-5]
        count+=1
        dict={'RUNDIR':runDir, 'POST':runDirPost, 'RELPATH':relPath, 'LABEL':outlabel, 'CONDORDIR':condorDir, 'INPUTDIR':inDir, 'FILENAME':rawname, 'PROXY':proxyPath, 'CMSSWBASE':relbase, 'OUTPUTDIR':outDir}
        jdfName=condorDir+'/%(RELPATH)s_%(LABEL)s/%(FILENAME)s_%(LABEL)s.job'%dict
        print jdfName
        jdf=open(jdfName,'w')
        jdf.write(
            """x509userproxy = %(PROXY)s
universe = vanilla
Executable = %(RUNDIR)s/makeStep1.sh
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Transfer_Input_Files = %(RUNDIR)s/makeStep1.C, %(RUNDIR)s/%(POST)s/step1.cc, %(RUNDIR)s/%(POST)s/step1.h, %(RUNDIR)s/%(POST)s/step1_cc.d, %(RUNDIR)s/%(POST)s/step1_cc.so, %(RUNDIR)s/csc2015_Dec01.txt, %(RUNDIR)s/ecalscn1043093_Dec01.txt
Output = %(FILENAME)s_%(LABEL)s.out
Error = %(FILENAME)s_%(LABEL)s.err
Log = %(FILENAME)s_%(LABEL)s.log
Notification = Never
Arguments = %(FILENAME)s.root %(FILENAME)s_%(LABEL)s.root %(INPUTDIR)s/%(RELPATH)s %(OUTPUTDIR)s/%(RELPATH)s_%(LABEL)s

Queue 1"""%dict)
        jdf.close()
        os.chdir('%s/%s_%s'%(condorDir,relPath,outlabel))
        os.system('condor_submit %(FILENAME)s_%(LABEL)s.job'%dict)
        os.system('sleep 0.5')                                
        os.chdir('%s'%(runDir))
        print count, "jobs submitted!!!"

print("--- %s minutes ---" % (round(time.time() - start_time, 2)/60))



