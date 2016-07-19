import os,shutil,datetime,time
import getpass
from ROOT import *
execfile("/uscms_data/d3/jmanagan/EOSSafeUtils.py")

start_time = time.time()

shift = sys.argv[1]

#IO directories must be full paths

relbase = '/uscms_data/d3/jmanagan/CMSSW_7_4_14/'
inputDir='/eos/uscms/store/user/lpcljm/2016/LJMet_1lepTT_070516/'+shift+'/'
outputDir='/eos/uscms/store/user/lpcljm/2016/LJMet_1lepTT_071016_step1/'+shift+'/'
condorDir='/uscms_data/d3/jmanagan/LJMet_1lepTT_071016_step1/'+shift+'/'

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
    #'TprimeTprime_M-700_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'TprimeTprime_M-800_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'TprimeTprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'TprimeTprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'TprimeTprime_M-1100_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'TprimeTprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'TprimeTprime_M-1300_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'TprimeTprime_M-1400_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'TprimeTprime_M-1500_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'TprimeTprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'TprimeTprime_M-1700_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'TprimeTprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8',
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
Transfer_Input_Files = %(RUNDIR)s/makeStep1.C, %(RUNDIR)s/%(POST)s/step1.cc, %(RUNDIR)s/%(POST)s/step1.h, %(RUNDIR)s/%(POST)s/step1_cc.d, %(RUNDIR)s/%(POST)s/step1_cc.so
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

#, %(RUNDIR)s/csc2015_Dec01.txt, %(RUNDIR)s/ecalscn1043093_Dec01.txt

signalList = [
    #'BprimeBprime_M-700_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'BprimeBprime_M-800_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'BprimeBprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'BprimeBprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'BprimeBprime_M-1100_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'BprimeBprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'BprimeBprime_M-1300_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'BprimeBprime_M-1400_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'BprimeBprime_M-1500_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'BprimeBprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'BprimeBprime_M-1700_TuneCUETP8M1_13TeV-madgraph-pythia8',
    'BprimeBprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8',
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
Transfer_Input_Files = %(RUNDIR)s/makeStep1.C, %(RUNDIR)s/%(POST)s/step1.cc, %(RUNDIR)s/%(POST)s/step1.h, %(RUNDIR)s/%(POST)s/step1_cc.d, %(RUNDIR)s/%(POST)s/step1_cc.so
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

#, %(RUNDIR)s/csc2015_Dec01.txt, %(RUNDIR)s/ecalscn1043093_Dec01.txt

dirList = [
    #'TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8',
    #'WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
    'TT_TuneCUETP8M1_13TeV-powheg-pythia8',
    #'TT_Mtt-1000toInf_TuneCUETP8M1_13TeV-powheg-pythia8',
    #'TT_Mtt-700to1000_TuneCUETP8M1_13TeV-powheg-pythia8',
    'WW_TuneCUETP8M1_13TeV-pythia8',						      
    'WZ_TuneCUETP8M1_13TeV-pythia8',						      
    'ZZ_TuneCUETP8M1_13TeV-pythia8',						      
    'DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8',			      
    'ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1',		      
    'ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1',		      
    'ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1',		      
    'ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1',		      
    'ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1',		      
    'TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8',		      
    'TTWJetsToQQ_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8',			      
    'TTZToQQ_TuneCUETP8M1_13TeV-amcatnlo-pythia8',					      
    'TTZToLLNuNu_M-10_TuneCUETP8M1_13TeV-amcatnlo-pythia8',			      
  
    #'QCD_HT100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',			      
    #'QCD_HT200to300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',			      
    'QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',			      
    'QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',			      
    'QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',			      
    'QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',			      
    'QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',			      
    'QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',              	      
  
    'WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
    'WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',    
    'WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
    'WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
    'WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
    'WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
    'WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
    
    ]

if shift == 'nominal':
    # These don't need to be run for shifted directories
    #dirList.append('ST_tW_top_5f_scaleup_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1')
    #dirList.append('ST_tW_top_5f_scaledown_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1')	      
    #dirList.append('ST_tW_antitop_5f_scaleup_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1')	      
    #dirList.append('ST_tW_antitop_5f_scaledown_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1')      
    dirList.append('TT_TuneCUETP8M1_13TeV-powheg-scaledown-pythia8')
    dirList.append('TT_TuneCUETP8M1_13TeV-powheg-scaleup-pythia8')
    dirList.append('SingleElectron_PRB1')
    dirList.append('SingleMuon_PRB1')
    dirList.append('SingleElectron_PRB2')
    dirList.append('SingleMuon_PRB2')
    dirList.append('SingleElectron_PRC')
    dirList.append('SingleMuon_PRC')

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
Transfer_Input_Files = %(RUNDIR)s/makeStep1.C, %(RUNDIR)s/%(POST)s/step1.cc, %(RUNDIR)s/%(POST)s/step1.h, %(RUNDIR)s/%(POST)s/step1_cc.d, %(RUNDIR)s/%(POST)s/step1_cc.so
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

#, %(RUNDIR)s/csc2015_Dec01.txt, %(RUNDIR)s/ecalscn1043093_Dec01.txt
''' # not needed yet in 80X, waiting for high mass samples to finish
sample = 'TT_TuneCUETP8M1_13TeV-powheg-pythia8'
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
'''
print("--- %s minutes ---" % (round(time.time() - start_time, 2)/60))



