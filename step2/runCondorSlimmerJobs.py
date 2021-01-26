import os,sys,shutil,datetime,time
from ROOT import *

execfile("/uscms_data/d3/jmanagan/EOSSafeUtils.py")

start_time = time.time()

#IO directories must be full paths

relbase = '/uscms_data/d3/jmanagan/CMSSW_10_2_10/'
#inputDir='/eos/uscms/store/user/bluetke/FWLJMET102X_1lep2017_June2020_step1hadds_fromjson_BL/' ## your step1hadds
inputDir='/eos/uscms/store/user/jmoberg/FWLJMET102X_1lep2018Dnn_Jun2020_step1hadds' #bluetke/FWLJMET102X_1lep2017training_June2020_step1hadds' #bburgsta/FWLJMET102X_1lep2016Dnn_trainMVA_step1hadds' #
outputDir='/eos/uscms/store/user/jmanagan/MVAtraining_2018_Jan2021' ## if for MVA training, keep 'training' in name to trigger a setting in the .sh
condorDir='/uscms_data/d3/jmanagan/step2jobs2017/'

runDir=os.getcwd()

gROOT.ProcessLine('.x compileStep2.C')

cTime=datetime.datetime.now()
date='%i_%i_%i_%i_%i_%i'%(cTime.year,cTime.month,cTime.day,cTime.hour,cTime.minute,cTime.second)

inDir=inputDir[10:]
outDir=outputDir[10:]

print 'Starting submission'
count=0

doSplit = False # only needed if running on step1hadds with giant WJets files and not slimming...

rootfiles = EOSlist_root_files(inputDir)
#print "I am Looking in " 
#print inputDir
os.system('eos root://cmseos.fnal.gov/ mkdir -p '+outDir)
os.system('mkdir -p '+condorDir)
#print "I found these files"
#print rootfiles

for file in rootfiles:

    # can turn some files of/off, but right now don't need to.
    ## Do WJets, TprimeTprime AND BprimeBprime M-1000, M-1800
    #if 'M-1800' not in file and 'M-1000' not in file and 'WJetsToLNu_HT' not in file: continue 
    if 'TTJets_Single' not in file: continue
    #if 'WJetsToLNu_HT-2500' not in file: continue

    #if 'pythia8_hadd.root' in file and EOSpathExists(inDir+'/'+file.replace('pythia8_hadd.root','pythia8_1_hadd.root')): continue
    #if '700_hadd.root' in file and EOSpathExists(inDir+'/'+file.replace('700_hadd.root','700_1_hadd.root')): continue
    #if '1000_hadd.root' in file and EOSpathExists(inDir+'/'+file.replace('1000_hadd.root','1000_1_hadd.root')): continue
    #if 'Inf_hadd.root' in file and EOSpathExists(inDir+'/'+file.replace('Inf_hadd.root','Inf_1_hadd.root')): continue

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
                  'START':int(index*entries/10.0), 'STOP':min(entries,int((index+1)*entries/10.0))}
            jdfName=condorDir+'/%(FILENAME)s_%(INDEX)s.job'%dict
            print "jdfname: ",jdfName
            jdf=open(jdfName,'w')
            jdf.write(
                """use_x509userproxy = true
universe = vanilla
Executable = %(RUNDIR)s/makeStep2.sh
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Transfer_Input_Files = %(RUNDIR)s/makeStep2.C, %(RUNDIR)s/step2.cc, %(RUNDIR)s/step2.h
Output = %(FILENAME)s_%(INDEX)s.out
Error = %(FILENAME)s_%(INDEX)s.err
Log = %(FILENAME)s_%(INDEX)s.log
Notification = Never
Arguments = %(FILENAME)s.root %(FILENAME)s_%(INDEX)s.root %(INPUTDIR)s %(OUTPUTDIR)s %(START)s %(STOP)s

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
        dict={'RUNDIR':runDir, 'CONDORDIR':condorDir, 'INPUTDIR':inDir, 'FILENAME':rawname, 'CMSSWBASE':relbase, 'OUTPUTDIR':outDir}
        jdfName=condorDir+'/%(FILENAME)s.job'%dict
        print "jdfname: ",jdfName
        jdf=open(jdfName,'w')
        jdf.write(
            """use_x509userproxy = true
universe = vanilla
Executable = %(RUNDIR)s/makeStep2.sh
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Transfer_Input_Files = %(RUNDIR)s/makeStep2.C, %(RUNDIR)s/step2.cc, %(RUNDIR)s/step2.h
Output = %(FILENAME)s.out
Error = %(FILENAME)s.err
Log = %(FILENAME)s.log
Notification = Never
Arguments = %(FILENAME)s.root %(FILENAME)s.root %(INPUTDIR)s %(OUTPUTDIR)s 0 nentries

Queue 1"""%dict)
        jdf.close()
        os.chdir('%s/'%(condorDir))
        os.system('condor_submit %(FILENAME)s.job'%dict)
        os.system('sleep 0.5')                                
        os.chdir('%s'%(runDir))
        print count, "jobs submitted!!!"


print("--- %s minutes ---" % (round(time.time() - start_time, 2)/60))





