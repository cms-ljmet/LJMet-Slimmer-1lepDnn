import os,shutil,datetime,time
import getpass
from ROOT import *
execfile("/uscms_data/d3/jmanagan/EOSSafeUtils.py")

start_time = time.time()

#IO directories must be full paths

finalStateYear = 'singleLep2018' # or 2018
relbase = '/uscms_data/d3/cholz/CMSSW_10_2_10/'
tarfile = '/uscms_data/d3/cholz/slimmerdnn.tar'
inputDir='/eos/uscms/store/user/lpcljm/FWLJMET102X_1lep2018_Oct2019/' # or 2018
outputDir='/eos/uscms/store/user/cholz/FWLJMET102X_1lep2018_Mar2020_step1/' # or 2018
condorDir='/uscms_data/d3/cholz/FWLJMET102X_1lep2018_Mar2020_step1/' # or 2018

runDir=os.getcwd()
inDir=inputDir[10:]
outDir=outputDir[10:]

print 'Making tar:'
if os.path.exists(tarfile): print '*********** tar already exists! I ASSUME YOU WANT TO MAKE A NEW ONE! *************'

os.chdir(relbase)
# YOU NEED TO EXCLUDE ANYTHING ELSE THAT MIGHT LIVE IN THE SAME CMSSW RELEASE, MY LIST IS SUPER LONG
print 'tar --exclude="src/.git" --exclude="tmp/" --exclude="src/PhysicsTools" --exclude="src/FWLJMET" --exclude="src/RecoEgamma" --exclude="src/RecoMET" --exclude="src/TopTagger" --exclude="src/RecoJets" --exclude=".SCRAM" --exclude="src/singleLepAnalyzer" --exclude="src/tptp_2017" --exclude="src/tptp_2018" --exclude="src/LJMet-Slimmer-1lepDnn/*.root" --exclude="src/LJMet-Slimmer-1lepDnn/*.png" --exclude="src/LJMet-Slimmer-1lepDnn/*.log" --exclude="src/LJMet-Slimmer-1lepDnn/*/*.root" --exclude="src/LJMet-Slimmer-1lepDnn/.git" -zcf '+tarfile+' ./*'
os.system('tar --exclude="src/.git" --exclude="tmp/" --exclude="src/PhysicsTools" --exclude="src/FWLJMET" --exclude="src/RecoEgamma" --exclude="src/RecoMET" --exclude="src/TopTagger" --exclude="src/RecoJets" --exclude=".SCRAM" --exclude="src/singleLepAnalyzer" --exclude="src/tptp_2017" --exclude="src/tptp_2018" --exclude="src/LJMet-Slimmer-1lepDnn/*.root" --exclude="src/LJMet-Slimmer-1lepDnn/*.png" --exclude="src/LJMet-Slimmer-1lepDnn/*.log" --exclude="src/LJMet-Slimmer-1lepDnn/*/*.root" --exclude="src/LJMet-Slimmer-1lepDnn/.git" -zcf '+tarfile+' ./*')
os.chdir(runDir)

print 'Starting submission'
count=0

dirList = [
    'BprimeBprime_M-1000_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    'BprimeBprime_M-1100_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'BprimeBprime_M-1200_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'BprimeBprime_M-1300_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'BprimeBprime_M-1400_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'BprimeBprime_M-1500_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'BprimeBprime_M-1600_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'BprimeBprime_M-1700_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'BprimeBprime_M-1800_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'BprimeBprime_M-900_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'DYJetsToLL_M-50_HT-1200to2500_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8',
    #'DYJetsToLL_M-50_HT-2500toInf_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8',
    #'DYJetsToLL_M-50_HT-400to600_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8',
    #'DYJetsToLL_M-50_HT-600to800_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8',
    #'DYJetsToLL_M-50_HT-800to1200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8',
    #'QCD_HT1000to1500_TuneCP5_13TeV-madgraphMLM-pythia8',
    #'QCD_HT1500to2000_TuneCP5_13TeV-madgraphMLM-pythia8',
    #'QCD_HT2000toInf_TuneCP5_13TeV-madgraphMLM-pythia8',
    #'QCD_HT300to500_TuneCP5_13TeV-madgraphMLM-pythia8',
    #'QCD_HT500to700_TuneCP5_13TeV-madgraphMLM-pythia8',
    #'QCD_HT700to1000_TuneCP5_13TeV-madgraphMLM-pythia8',
    #'ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-madgraph-pythia8',
    #'ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8',
    #'ST_t-channel_top_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8',
    #'ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8',
    #'ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8',
    #'EGamma',
    #'SingleMuon',
    #'TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8',
    #'TTToHadronic_TuneCP5_13TeV-powheg-pythia8',
    #'TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8',
    #'TTWJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8',
    #'TTZToLLNuNu_M-10_TuneCP5_13TeV-amcatnlo-pythia8',
    #'TTZToLL_M-1to10_TuneCP5_13TeV-amcatnlo-pythia8',
    #'TT_Mtt-1000toInf_TuneCP5_13TeV-powheg-pythia8',
    #'TT_Mtt-700to1000_TuneCP5_PSweights_13TeV-powheg-pythia8',
    #'TprimeTprime_M-1000_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'TprimeTprime_M-1100_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'TprimeTprime_M-1200_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'TprimeTprime_M-1300_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'TprimeTprime_M-1400_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'TprimeTprime_M-1500_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'TprimeTprime_M-1600_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'TprimeTprime_M-1700_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'TprimeTprime_M-1800_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'TprimeTprime_M-900_TuneCP5_PSweights_13TeV-madgraph-pythia8',
    #'WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8',
    #'WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8',
    #'WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8',
    #'WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8',
    #'WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8',
    #'WW_TuneCP5_PSweights_13TeV-pythia8',
    #'WZ_TuneCP5_PSweights_13TeV-pythia8',
    #'ZZ_TuneCP5_13TeV-pythia8',
    #'ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8',
    #'ttHTobb_M125_TuneCP5_13TeV-powheg-pythia8',
]

for sample in dirList:
    print "------------ Sample:",sample,"---------------"
    outList = ['none']
    if 'Tprime' in sample: outList = ['BWBW','TZBW','THBW','TZTH','TZTZ','THTH']
    elif 'Bprime' in sample: outList = ['TWTW','BZTW','BHTW','BZBH','BZBZ','BHBH']
    elif 'TTTo' in sample: outList = ['Mtt0to700','Mtt700to1000','Mtt1000toInf']

    isData = False
    if 'SingleMuon' in sample or 'SingleElectron' in sample or 'EGamma' in sample: isData = True

    for outlabel in outList:
        tmpcount = 0

        outsample = sample+'_'+outlabel
        if outlabel == 'none': outsample = sample

        os.system('eos root://cmseos.fnal.gov/ mkdir -p '+outDir+outsample)
        os.system('mkdir -p '+condorDir+outsample)

        runlist = EOSlistdir(inputDir+'/'+sample+'/'+finalStateYear+'/')
        print "Running",len(runlist),"crab directories"

        runcounter = 0
        for run in runlist:
            runcounter += 1
            numlist = EOSlistdir(inputDir+'/'+sample+'/'+finalStateYear+'/'+run+'/')
            
            for num in numlist:
                numpath = inputDir+'/'+sample+'/'+finalStateYear+'/'+run+'/'+num
                pathsuffix = numpath.split('/')[-3:]
                pathsuffix = '/'.join(pathsuffix)

                rootfiles = EOSlist_root_files(numpath)            
                basefilename = (rootfiles[0].split('.')[0]).split('_')[:-1]
                basefilename = '_'.join(basefilename)
                print "Running path:",pathsuffix,"\tBase filenames:",basefilename

                for i in range(0,len(rootfiles),20):
                    count+=1
                    tmpcount += 1

                    #if tmpcount > 1: continue

                    segment1 = (rootfiles[i].split('.')[0]).split('_')[-1] ## 1-1, 78
                    segment2 = (rootfiles[i].split('.')[0]).split('_')[-2] ## SingleElectronRun2017C

                    if isData:    # need unique IDs across eras
                        idlist = segment2[-1]+segment1+' '
                        for j in range(i+1,i+20):
                            if j >= len(rootfiles): continue
                            idparts = (rootfiles[j].split('.')[0]).split('_')[-2:]
                            idlist += idparts[0][-1]+idparts[1]+' '
                    elif 'ext' in segment2:     # WON'T WORK in FWLJMET 052219, but ok since no samples need it
                        idlist = segment2[-4:]+segment1+' '
                        for j in range(i+1,i+20):
                            if j >= len(rootfiles): continue
                            idparts = (rootfiles[j].split('.')[0]).split('_')[-2:]
                            idlist += idparts[0][-4:]+idparts[1]+' '
                    else:
                        idlist = segment1+' '
                        for j in range(i+1,i+20):
                            if j >= len(rootfiles): continue
                            idlist += (rootfiles[j].split('.')[0]).split('_')[-1]+' '
                        
                    idlist = idlist.strip()
                    print "Running IDs",idlist
                
                    dict={'RUNDIR':runDir, 'SAMPLE':sample, 'INPATHSUFFIX':pathsuffix, 'INPUTDIR':inDir, 'FILENAME':basefilename, 'OUTFILENAME':outsample, 'OUTPUTDIR':outDir, 'LIST':idlist, 'ID':tmpcount, 'TARBALL':tarfile}
                    jdfName=condorDir+'/%(OUTFILENAME)s/%(OUTFILENAME)s_%(ID)s.job'%dict
                    print jdfName
                    jdf=open(jdfName,'w')
                    jdf.write(
                        """use_x509userproxy = true
universe = vanilla
Executable = %(RUNDIR)s/makeStep1Dnn.sh
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Transfer_Input_Files = %(TARBALL)s
Output = %(OUTFILENAME)s_%(ID)s.out
Error = %(OUTFILENAME)s_%(ID)s.err
Log = %(OUTFILENAME)s_%(ID)s.log
Notification = Never
Arguments = "%(FILENAME)s %(OUTFILENAME)s %(INPUTDIR)s/%(SAMPLE)s/%(INPATHSUFFIX)s %(OUTPUTDIR)s/%(OUTFILENAME)s '%(LIST)s'"

Queue 1"""%dict)
                    jdf.close()
                    os.chdir('%s/%s'%(condorDir,outsample))
                    os.system('condor_submit %(OUTFILENAME)s_%(ID)s.job'%dict)
                    os.system('sleep 0.5')                                
                    os.chdir('%s'%(runDir))
                    print count, "jobs submitted!!!"
        
print("--- %s minutes ---" % (round(time.time() - start_time, 2)/60))
