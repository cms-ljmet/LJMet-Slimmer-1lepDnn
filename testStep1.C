#include "step1.cc"

void makeSingleStep1(){
  
  TString inputFile="root://cmseos.fnal.gov//store/user/lpcljm/LJMet_1lepTT_022916/nominal//TprimeTprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns/TprimeTprime_M-1200_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns_1.root";
  
  TString outputFile="test.root";
  
  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");
  
  step1 t(inputFile,outputFile);
  t.Loop();
}


