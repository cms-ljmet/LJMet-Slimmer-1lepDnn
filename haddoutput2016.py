import os,sys,datetime,time, subprocess, math
from ROOT import *
execfile("/uscms_data/d3/jmanagan/EOSSafeUtils.py")

start_time = time.time()

#IO directories must be full paths
#input  = sys.argv[1]
#output = sys.argv[2]

inDir='/store/user/bburgsta/FWLJMET102X_1lep2016Dnn_042720_step1'
outDir='/store/user/bburgsta/FWLJMET102X_1lep2016Dnn_042720_step1hadds/'
scratchDir='/uscmst1b_scratch/lpc1/3DayLifetime/bburgsta/'

if not os.path.exists(scratchDir): os.system('mkdir '+scratchDir)
os.system('eos root://cmseos.fnal.gov/ mkdir -p '+outDir)

dirList = [
#'TprimeTprime_M-1400_TuneCUETP8M1_13TeV-madgraph-pythia8_BWBW',
#'TprimeTprime_M-1400_TuneCUETP8M1_13TeV-madgraph-pythia8_THBW',
#'TprimeTprime_M-1400_TuneCUETP8M1_13TeV-madgraph-pythia8_THTH',
#'TprimeTprime_M-1400_TuneCUETP8M1_13TeV-madgraph-pythia8_TZBW',
#'TprimeTprime_M-1400_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTH',
#'TprimeTprime_M-1400_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTZ',
#'TprimeTprime_M-1500_TuneCUETP8M1_13TeV-madgraph-pythia8_BWBW',
#'TprimeTprime_M-1500_TuneCUETP8M1_13TeV-madgraph-pythia8_THBW',
#'TprimeTprime_M-1500_TuneCUETP8M1_13TeV-madgraph-pythia8_THTH',
#'TprimeTprime_M-1500_TuneCUETP8M1_13TeV-madgraph-pythia8_TZBW',
#'TprimeTprime_M-1500_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTH',
#'TprimeTprime_M-1500_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTZ',

#'TprimeTprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8_BWBW',
#'TprimeTprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8_THBW',
#'TprimeTprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8_THTH',
#'TprimeTprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8_TZBW',
#'TprimeTprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTH',
#'TprimeTprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTZ',
#'TprimeTprime_M-1700_TuneCUETP8M1_13TeV-madgraph-pythia8_BWBW',
#'TprimeTprime_M-1700_TuneCUETP8M1_13TeV-madgraph-pythia8_THBW',
#'TprimeTprime_M-1700_TuneCUETP8M1_13TeV-madgraph-pythia8_THTH',
#'TprimeTprime_M-1700_TuneCUETP8M1_13TeV-madgraph-pythia8_TZBW',
#'TprimeTprime_M-1700_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTH',
#'TprimeTprime_M-1700_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTZ',
#'TprimeTprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8_BWBW',
#'TprimeTprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8_THBW',
#'TprimeTprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8_THTH',
#'TprimeTprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8_TZBW',
#'TprimeTprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTH',
#'TprimeTprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTZ',
#'TprimeTprime_M-700_TuneCUETP8M1_13TeV-madgraph-pythia8_BWBW',
#'TprimeTprime_M-700_TuneCUETP8M1_13TeV-madgraph-pythia8_THBW',
#'TprimeTprime_M-700_TuneCUETP8M1_13TeV-madgraph-pythia8_THTH',
#'TprimeTprime_M-700_TuneCUETP8M1_13TeV-madgraph-pythia8_TZBW',
#'TprimeTprime_M-700_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTH',
#'TprimeTprime_M-700_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTZ',

#'TprimeTprime_M-800_TuneCUETP8M1_13TeV-madgraph-pythia8_BWBW',
#'TprimeTprime_M-800_TuneCUETP8M1_13TeV-madgraph-pythia8_THBW',
#'TprimeTprime_M-800_TuneCUETP8M1_13TeV-madgraph-pythia8_THTH',
#'TprimeTprime_M-800_TuneCUETP8M1_13TeV-madgraph-pythia8_TZBW',
#'TprimeTprime_M-800_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTH',
#'TprimeTprime_M-800_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTZ',

#'TprimeTprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8_BWBW',
#'TprimeTprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8_THBW',
#'TprimeTprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8_THTH',
#'TprimeTprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8_TZBW',
#'TprimeTprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTH',
#'TprimeTprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTZ',
#'WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
#'WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
#'WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
#'WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
#'WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
'WW_TuneCUETP8M1_13TeV-pythia8',
#'WZ_TuneCUETP8M1_13TeV-pythia8',
#'ZZ_TuneCUETP8M1_13TeV-pythia8',
#'ttHToNonbb_M125_TuneCUETP8M2_ttHtranche3_13TeV-powheg-pythia8',
#'ttHTobb_M125_13TeV_powheg_pythia8',
#'BprimeBprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_BHBH',
#'BprimeBprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_BHTW',
#'BprimeBprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBH',
#'BprimeBprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBZ',
#'BprimeBprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_BZTW',
#'BprimeBprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_TWTW',
#'BprimeBprime_M-1100_TuneCUETP8M1_13TeV-madgraph-pythia8_BHBH',
#'BprimeBprime_M-1100_TuneCUETP8M1_13TeV-madgraph-pythia8_BHTW',
#'BprimeBprime_M-1100_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBH',
#'BprimeBprime_M-1100_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBZ',
#'BprimeBprime_M-1100_TuneCUETP8M1_13TeV-madgraph-pythia8_BZTW',
#'BprimeBprime_M-1100_TuneCUETP8M1_13TeV-madgraph-pythia8_TWTW',
#'BprimeBprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_BHBH',
#'BprimeBprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_BHTW',
#'BprimeBprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBH',
#'BprimeBprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBZ',
#'BprimeBprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_BZTW',
#'BprimeBprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_TWTW',
#'BprimeBprime_M-1300_TuneCUETP8M1_13TeV-madgraph-pythia8_BHBH',
#'BprimeBprime_M-1300_TuneCUETP8M1_13TeV-madgraph-pythia8_BHTW',
#'BprimeBprime_M-1300_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBH',
#'BprimeBprime_M-1300_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBZ',
#'BprimeBprime_M-1300_TuneCUETP8M1_13TeV-madgraph-pythia8_BZTW',
#'BprimeBprime_M-1300_TuneCUETP8M1_13TeV-madgraph-pythia8_TWTW',
#'BprimeBprime_M-1400_TuneCUETP8M1_13TeV-madgraph-pythia8_BHBH',
#'BprimeBprime_M-1400_TuneCUETP8M1_13TeV-madgraph-pythia8_BHTW',
#'BprimeBprime_M-1400_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBH',
#'BprimeBprime_M-1400_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBZ',
#'BprimeBprime_M-1400_TuneCUETP8M1_13TeV-madgraph-pythia8_BZTW',
#'BprimeBprime_M-1400_TuneCUETP8M1_13TeV-madgraph-pythia8_TWTW',
#'BprimeBprime_M-1500_TuneCUETP8M1_13TeV-madgraph-pythia8_BHBH',
#'BprimeBprime_M-1500_TuneCUETP8M1_13TeV-madgraph-pythia8_BHTW',
#'BprimeBprime_M-1500_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBH',
#'BprimeBprime_M-1500_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBZ',
#'BprimeBprime_M-1500_TuneCUETP8M1_13TeV-madgraph-pythia8_BZTW',
#'BprimeBprime_M-1500_TuneCUETP8M1_13TeV-madgraph-pythia8_TWTW',
#'BprimeBprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8_BHBH',
#'BprimeBprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8_BHTW',
#'BprimeBprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBH',
#'BprimeBprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBZ',
#'BprimeBprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8_BZTW',
#'BprimeBprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8_TWTW',
#'BprimeBprime_M-1700_TuneCUETP8M1_13TeV-madgraph-pythia8_BHBH',
#'BprimeBprime_M-1700_TuneCUETP8M1_13TeV-madgraph-pythia8_BHTW',
#'BprimeBprime_M-1700_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBH',
#'BprimeBprime_M-1700_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBZ',
#'BprimeBprime_M-1700_TuneCUETP8M1_13TeV-madgraph-pythia8_BZTW',
#'BprimeBprime_M-1700_TuneCUETP8M1_13TeV-madgraph-pythia8_TWTW',
#'BprimeBprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8_BHBH',
#'BprimeBprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8_BHTW',
#'BprimeBprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBH',
#'BprimeBprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBZ',
#'BprimeBprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8_BZTW',
#'BprimeBprime_M-1800_TuneCUETP8M1_13TeV-madgraph-pythia8_TWTW',
#'BprimeBprime_M-700_TuneCUETP8M1_13TeV-madgraph-pythia8_BHBH',
#'BprimeBprime_M-700_TuneCUETP8M1_13TeV-madgraph-pythia8_BHTW',
#'BprimeBprime_M-700_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBH',
#'BprimeBprime_M-700_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBZ',
#'BprimeBprime_M-700_TuneCUETP8M1_13TeV-madgraph-pythia8_BZTW',
#'BprimeBprime_M-700_TuneCUETP8M1_13TeV-madgraph-pythia8_TWTW',
#'BprimeBprime_M-800_TuneCUETP8M1_13TeV-madgraph-pythia8_BHBH',
#'BprimeBprime_M-800_TuneCUETP8M1_13TeV-madgraph-pythia8_BHTW',
#'BprimeBprime_M-800_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBH',
#'BprimeBprime_M-800_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBZ',
#'BprimeBprime_M-800_TuneCUETP8M1_13TeV-madgraph-pythia8_BZTW',
#'BprimeBprime_M-800_TuneCUETP8M1_13TeV-madgraph-pythia8_TWTW',
#'BprimeBprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8_BHBH',
#'BprimeBprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8_BHTW',
#'BprimeBprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBH',
#'BprimeBprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8_BZBZ',
#'BprimeBprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8_BZTW',
#'BprimeBprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8_TWTW',
#'DYJetsToLL_M-50_HT-1200to2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
#'DYJetsToLL_M-50_HT-2500toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
#'DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
#'DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
#'DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',

#'QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
#'QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
#'QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
#'QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
#'QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
#'QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',

#'ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8',
#'ST_t-channel_antitop_4f_inclusiveDecays_13TeV_PSweights-powhegV2-madspin',
#'ST_t-channel_top_4f_inclusiveDecays_13TeV_PSweights-powhegV2-madspin',
#'ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M2T4',
#'ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M2T4',
'SingleElectron',
'SingleMuon',
#'TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8',
#'TTZToLLNuNu_M-10_TuneCUETP8M1_13TeV-amcatnlo-pythia8',
#'TTZToLL_M-1to10_TuneCUETP8M1_13TeV-madgraphMLM-pythia8',
#'TT_Mtt-1000toInf_TuneCUETP8M2T4_13TeV-powheg-pythia8',
#'TT_Mtt-700to1000_TuneCUETP8M2T4_13TeV-powheg-pythia8',
#'TT_TuneCUETP8M2T4_13TeV-powheg-pythia8_Mtt0to700',
#'TT_TuneCUETP8M2T4_13TeV-powheg-pythia8_Mtt1000toInf',
#'TT_TuneCUETP8M2T4_13TeV-powheg-pythia8_Mtt700to1000',
#'TT_TuneCUETP8M2T4_PSweights_13TeV-powheg-pythia8_Mtt0to700',
#'TT_TuneCUETP8M2T4_PSweights_13TeV-powheg-pythia8_Mtt1000toInf',
#'TT_TuneCUETP8M2T4_PSweights_13TeV-powheg-pythia8_Mtt700to1000',
#'TprimeTprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_BWBW',
#'TprimeTprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_THBW',
#'TprimeTprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_THTH',
#'TprimeTprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_TZBW',
#'TprimeTprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTH',
#'TprimeTprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTZ',
#'TprimeTprime_M-1100_TuneCUETP8M1_13TeV-madgraph-pythia8_BWBW',
#'TprimeTprime_M-1100_TuneCUETP8M1_13TeV-madgraph-pythia8_THBW',
#'TprimeTprime_M-1100_TuneCUETP8M1_13TeV-madgraph-pythia8_THTH',
#'TprimeTprime_M-1100_TuneCUETP8M1_13TeV-madgraph-pythia8_TZBW',
#'TprimeTprime_M-1100_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTH',
#'TprimeTprime_M-1100_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTZ',
#'TprimeTprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_BWBW',
#'TprimeTprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_THBW',
#'TprimeTprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_THTH',
#'TprimeTprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_TZBW',
#'TprimeTprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTH',
#'TprimeTprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTZ',
#'TprimeTprime_M-1300_TuneCUETP8M1_13TeV-madgraph-pythia8_BWBW',
#'TprimeTprime_M-1300_TuneCUETP8M1_13TeV-madgraph-pythia8_THBW',
#'TprimeTprime_M-1300_TuneCUETP8M1_13TeV-madgraph-pythia8_THTH',
#'TprimeTprime_M-1300_TuneCUETP8M1_13TeV-madgraph-pythia8_TZBW',
#'TprimeTprime_M-1300_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTH',
#'TprimeTprime_M-1300_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTZ',

]
'''    '/TprimeTprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8',
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
	 '/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8',
''' 


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
            haddcommand = 'hadd -f '+scratchDir+'/'+outsample+'_hadd.root '
            for file in rootfiles:
                haddcommand+=' root://cmseos.fnal.gov/'+inDir+'/'+outsample+'/'+file
            print 'Length of hadd command =',len(haddcommand)
            subprocess.call(haddcommand,shell=True)
            
            xrdcpcommand = 'xrdcp '+scratchDir+'/'+outsample+'_hadd.root root://cmseos.fnal.gov/'+outDir+'/'+outsample+'_hadd.root'
            subprocess.call(xrdcpcommand,shell=True)

            if bool(EOSisfile(outDir+'/'+outsample+'_hadd.root')) != True:
                print haddcommand                
        else:
            for i in range(int(math.ceil(len(rootfiles)/float(nFilesPerHadd)))):
                haddcommand = 'hadd -f '+scratchDir+'/'+outsample+'_'+str(i+1)+'_hadd.root '

                begin=i*nFilesPerHadd
                end=begin+nFilesPerHadd
                if end > len(rootfiles): end=len(rootfiles)
                print 'begin:',begin,'end:',end

                for j in range(begin,end):
                    haddcommand+=' root://cmseos.fnal.gov/'+inDir+'/'+outsample+'/'+rootfiles[j]
                print 'Length of hadd command =',len(haddcommand)
                subprocess.call(haddcommand,shell=True)

                xrdcpcommand = 'xrdcp '+scratchDir+'/'+outsample+'_'+str(i+1)+'_hadd.root root://cmseos.fnal.gov/'+outDir+'/'+outsample+'_'+str(i+1)+'_hadd.root'
                subprocess.call(xrdcpcommand,shell=True)

                if bool(EOSisfile(outDir+'/'+outsample+'_'+str(i+1)+'_hadd.root')) != True:
                    print haddcommand

print("--- %s minutes ---" % (round(time.time() - start_time, 2)/60))



