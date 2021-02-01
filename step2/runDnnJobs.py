import os,sys,shutil,datetime,time
from ROOT import *

execfile("/uscms_data/d3/jmanagan/EOSSafeUtils.py")

start_time = time.time()

#IO directories must be full paths

url = 'root://cmseos.fnal.gov/' # input stored on FNAL LPC
relbase = '/uscms_data/d3/jmanagan/CMSSW_10_2_10/'
inputDir='/eos/uscms/store/user/jmanagan/FWLJMET102X_1lep2018Dnn_Jan2021_step2hadds'
outputDir='/eos/uscms/store/user/jmanagan/FWLJMET102X_1lep2018Dnn_Feb2021_step2hadds' ## if for MVA training, keep 'training' in name to trigger a setting in the .sh
condorDir='/uscms_data/d3/jmanagan/step2jobs18_addDnn/'
tarfile = '/uscms_data/d3/jmanagan/slimmerdnn.tar'

#drwxr-xr-+   1 jmanagan us_cms      214460747 Jan 27 12:57 FWLJMET102X_1lep2016Dnn_012621_step1hadds
#drwxr-xr-+   1 jmanagan us_cms    63680878213 Jan 19 11:49 FWLJMET102X_1lep2016Dnn_Jan2021_step2hadds
#drwxr-xr-+   1 jmanagan us_cms   596776760511 Jan  4 15:27 FWLJMET102X_1lep2017Dnn_Dec2020_step1hadds
#drwxr-xr-+   1 jmanagan us_cms    89434852878 Jan 15 16:32 FWLJMET102X_1lep2018Dnn_Jan2021_step2hadds

runDir=os.getcwd()

gROOT.ProcessLine('.x compileStep2.C')

cTime=datetime.datetime.now()
date='%i_%i_%i_%i_%i_%i'%(cTime.year,cTime.month,cTime.day,cTime.hour,cTime.minute,cTime.second)

inDir=inputDir[10:]
outDir=outputDir[10:]

print 'Making tar:'
if os.path.exists(tarfile): print '*********** tar already exists! I ASSUME YOU WANT TO MAKE A NEW ONE! *************'

os.chdir(relbase)
# YOU NEED TO EXCLUDE ANYTHING ELSE THAT MIGHT LIVE IN THE SAME CMSSW RELEASE, MY LIST IS SUPER LONG
print 'tar --exclude="src/.git" --exclude="tmp/" --exclude="src/PhysicsTools" --exclude="src/FWLJMET" --exclude="src/RecoEgamma" --exclude="src/RecoMET" --exclude="src/TopTagger" --exclude="src/RecoJets" --exclude=".SCRAM" --exclude="src/tptp_2016" --exclude="src/tptp_2016_badgithub" --exclude="src/tptp_2017" --exclude="src/tptp_2018" --exclude="src/singleLepAnalyzer" --exclude="src/LJMet-Slimmer-1lepDnn/*.root" --exclude="src/LJMet-Slimmer-1lepDnn/MVATraining" --exclude="src/LJMet-Slimmer-1lepDnn/*.log" --exclude="src/LJMet-Slimmer-1lepDnn/*.png" --exclude="src/LJMet-Slimmer-1lepDnn/*/*.root" --exclude="src/LJMet-Slimmer-1lepDnn/.git" -zcf '+tarfile+' ./*'
os.system('tar --exclude="src/.git" --exclude="tmp/" --exclude="src/PhysicsTools" --exclude="src/FWLJMET" --exclude="src/RecoEgamma" --exclude="src/RecoMET" --exclude="src/TopTagger" --exclude="src/RecoJets" --exclude=".SCRAM" --exclude="src/tptp_2016" --exclude="src/tptp_2016_badgithub" --exclude="src/tptp_2017" --exclude="src/tptp_2018" --exclude="src/singleLepAnalyzer" --exclude="src/LJMet-Slimmer-1lepDnn/*.root" --exclude="src/LJMet-Slimmer-1lepDnn/MVATraining" --exclude="src/LJMet-Slimmer-1lepDnn/*.log" --exclude="src/LJMet-Slimmer-1lepDnn/*.png" --exclude="src/LJMet-Slimmer-1lepDnn/*/*.root" --exclude="src/LJMet-Slimmer-1lepDnn/.git" -zcf '+tarfile+' ./*')
os.chdir(runDir)

print 'Starting submission'
count=0

doSplit = False # only needed if running on step1hadds with giant WJets files and not slimming...

rootfiles = EOSlist_root_files(inputDir)
os.system('eos root://cmseos.fnal.gov/ mkdir -p '+outDir)
os.system('mkdir -p '+condorDir)

for file in rootfiles:

    # can turn some files of/off, but right now don't need to.
    ## Do WJets, TprimeTprime AND BprimeBprime M-1000, M-1800
    #if 'M-1800' not in file and 'M-1000' not in file and 'WJetsToLNu_HT' not in file: continue 
    #if 'TTJets_Single' not in file: continue
    #if 'WJetsToLNu_HT-2500' not in file: continue
    #if 'SingleElectron' in file: continue

    if doSplit:
        root = TFile.Open('root://cmseos.fnal.gov/'+inDir+'/'+file)
        tree = root.Get("ljmet");
        entries = tree.GetEntries()

        rawname = file[:-5]
        print file
        print "rawname: ",rawname

        for index in range(0,10):
            jstart = int(index*entries/10.0)
            jstop = min(entries,int((index+1)*entries/10.0))
            
            count+=1
            dict={'RUNDIR':runDir, 'CONDORDIR':condorDir, 'INPUTDIR':inDir, 'FILENAME':rawname, 'CMSSWBASE':relbase, 'OUTPUTDIR':outDir, 'INDEX':index, 
                  'START':int(index*entries/10.0), 'STOP':min(entries,int((index+1)*entries/10.0)), 'TARBALL':tarfile, 'URL':url}
            jdfName=condorDir+'/%(FILENAME)s_%(INDEX)s.job'%dict
            print "jdfname: ",jdfName
            jdf=open(jdfName,'w')
            jdf.write(
                """use_x509userproxy = true
universe = vanilla
Executable = %(RUNDIR)s/makeStep2Dnn.sh
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Transfer_Input_Files = %(TARBALL)s
Output = %(FILENAME)s_%(INDEX)s.out
Error = %(FILENAME)s_%(INDEX)s.err
Log = %(FILENAME)s_%(INDEX)s.log
Notification = Never
Arguments = %(FILENAME)s.root %(FILENAME)s_%(INDEX)s.root %(INPUTDIR)s %(OUTPUTDIR)s %(URL)s

Queue 1"""%dict)
            jdf.close()
            os.chdir('%s/'%(condorDir))
            os.system('condor_submit %(FILENAME)s_%(INDEX)s.job'%dict)
            os.system('sleep 0.5')                                
            os.chdir('%s'%(runDir))
            print count, "jobs submitted!!!"
    
    else:
        rawname = file[:-5]
        print file
        print "rawname: ",rawname
        count+=1
        dict={'RUNDIR':runDir, 'CONDORDIR':condorDir, 'INPUTDIR':inDir, 'FILENAME':rawname, 'CMSSWBASE':relbase, 'OUTPUTDIR':outDir, 'TARBALL':tarfile, 'URL':url}
        jdfName=condorDir+'/%(FILENAME)s.job'%dict
        print "jdfname: ",jdfName
        jdf=open(jdfName,'w')
        jdf.write(
            """use_x509userproxy = true
universe = vanilla
Executable = %(RUNDIR)s/makeStep2Dnn.sh
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Transfer_Input_Files = %(TARBALL)s
Output = %(FILENAME)s.out
Error = %(FILENAME)s.err
Log = %(FILENAME)s.log
Notification = Never
Arguments = %(FILENAME)s.root %(FILENAME)s.root %(INPUTDIR)s %(OUTPUTDIR)s %(URL)s

Queue 1"""%dict)
        jdf.close()
        os.chdir('%s/'%(condorDir))
        os.system('condor_submit %(FILENAME)s.job'%dict)
        os.system('sleep 0.5')                                
        os.chdir('%s'%(runDir))
        print count, "jobs submitted!!!"


print("--- %s minutes ---" % (round(time.time() - start_time, 2)/60))





