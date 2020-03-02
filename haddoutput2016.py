import os,sys,datetime,time, subprocess, math
from ROOT import *
execfile("/uscms_data/d3/jmanagan/EOSSafeUtils.py")

start_time = time.time()

#IO directories must be full paths

input  = sys.argv[1]
output = sys.argv[2]

inDir='/store/user/escharni/FWLJMET102X_1lep2016Dnn_trainMVA_step1/'
outDir='/store/user/escharni/FWLJMET102X_1lep2016Dnn_trainMVA_step1hadds/'


os.system('eos root://cmseos.fnal.gov/ mkdir -p '+outDir)

dirList = [
    '/TprimeTprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8',
    '/TprimeTprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8',
    '/TprimeTprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8',
    '/BprimeBprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8',
    '/BprimeBprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8',
    '/BprimeBprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8',
    '/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
    '/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
    '/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
    '/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
    '/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
    '/TTJets_SingleLeptFromT_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
    '/TTJets_SingleLeptFromTbar_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',    
]

for sample in dirList:
    outList = ['none']
    #if 'Tprime' in sample: outList = ['BWBW','TZBW','THBW','TZTH','TZTZ','THTH']
    #elif 'Bprime' in sample: outList = ['TWTW','BZTW','BHTW','BZBH','BZBZ','BHBH']
    #elif 'TTTo' in sample: outList = ['Mtt0to700','Mtt700to1000','Mtt1000toInf']

    for outlabel in outList:

        outsample = sample+'_'+outlabel
        if outlabel == 'none': outsample = sample

        rootfiles = EOSlist_root_files(inDir+'/'+outsample)

        print "------------ hadding Sample:",outsample,"---------------"
        print 'N root files in',outsample,'=',len(rootfiles)


        nFilesPerHadd = 900
        onefile = ' root://cmseos.fnal.gov/'+inDir+'/'+outsample+'/'+rootfiles[-1]
        manyfiles = nFilesPerHadd*onefile
        lengthcheck = len('hadd -f root://cmseos.fnal.gov/'+outDir+'/'+outsample+'_hadd.root '+manyfiles)
        if lengthcheck > 126000.:
            toolong = lengthcheck - 126000.
            num2remove = math.ceil(toolong/len(onefile))
            nFilesPerHadd = int(nFilesPerHadd - num2remove)
            print 'Length estimate reduced from',lengthcheck,'by',toolong,'via removing',num2remove,'files for nFilesPerHadd of',nFilesPerHadd

        if len(rootfiles) < nFilesPerHadd:
            haddcommand = 'hadd -f root://cmseos.fnal.gov/'+outDir+'/'+outsample+'_hadd.root '
            for file in rootfiles:
                haddcommand+=' root://cmseos.fnal.gov/'+inDir+'/'+outsample+'/'+file
            print 'Length of hadd command =',len(haddcommand)
            subprocess.call(haddcommand,shell=True)

            if bool(EOSisfile(outDir+'/'+outsample+'_hadd.root')) != True:
                print haddcommand
        else:
            for i in range(int(math.ceil(len(rootfiles)/float(nFilesPerHadd)))):
                haddcommand = 'hadd -f root://cmseos.fnal.gov/'+outDir+'/'+outsample+'_'+str(i+1)+'_hadd.root '

                begin=i*nFilesPerHadd
                end=begin+nFilesPerHadd
                if end > len(rootfiles): end=len(rootfiles)
                print 'begin:',begin,'end:',end

                for j in range(begin,end):
                    haddcommand+=' root://cmseos.fnal.gov/'+inDir+'/'+outsample+'/'+rootfiles[j]
                print 'Length of hadd command =',len(haddcommand)
                subprocess.call(haddcommand,shell=True)

                if bool(EOSisfile(outDir+'/'+outsample+'_'+str(i+1)+'_hadd.root')) != True:
                    print haddcommand

print("--- %s minutes ---" % (round(time.time() - start_time, 2)/60))



