#include "step1.cc"

void testStep1(){
  
  TString inputFile="root://cmseos.fnal.gov//store/user/lpcljm/LJMet_1lepTT_042516/nominal/TT_TuneCUETP8M1_13TeV-powheg-pythia8/TT_TuneCUETP8M1_13TeV-powheg-pythia8_1.root";
  //  TString inputFile="root://cmseos.fnal.gov//store/user/lpcljm/LJMet_1lepTT_042516/nominal/TprimeTprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8/TprimeTprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_1.root";
  
  TString outputFile="test.root";
  
  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");
  
  step1 t(inputFile,outputFile);
  t.Loop();
}


