#include "BTagCalibForLJMet.cpp"
#include "step1.cc"


void testStep1(){
  
  TString inputFile="root://cmseos.fnal.gov//store/user/lpcljm/CHiggs/LJMet80X_1lep_040317/nominal/ChargedHiggs_HplusTB_HplusToTB_M-500_13TeV_amcatnlo_pythia8/ChargedHiggs_HplusTB_HplusToTB_M-500_13TeV_amcatnlo_pythia8_1.root";
  //  TString inputFile="root://cmseos.fnal.gov//store/user/lpcljm/2016/LJMet80X_1lep_041917/nominal/SingleElectron_RRBCDEFGH/SingleElectron_RRBCDEFGH_1.root";
  //  TString inputFile="../LJMet/Com/condor_TTinclusive/testmc.root";
  //  TString inputFile="root://cmseos.fnal.gov//store/user/lpcljm/2016/LJMet80X_1lep_031317/nominal/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_1.root";
  //  TString inputFile="root://cmseos.fnal.gov//store/user/lpcljm/2016/LJMet80X_1lep_041917/nominal/TT_TuneCUETP8M2T4_v1_13TeV-powheg-pythia8/TT_TuneCUETP8M2T4_v1_13TeV-powheg-pythia8_1.root";
  //TString inputFile="root://cmseos.fnal.gov//store/user/lpcljm/CHiggs/LHCP2017/LJMet80X_1lep_022517/nominal/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8_1.root";
  
  TString outputFile="test.root";

  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");
  
  step1 t(inputFile,outputFile);
  t.Loop();
}




