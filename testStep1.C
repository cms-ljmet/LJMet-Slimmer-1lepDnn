#include "step1.cc"

void testStep1(){
  
  TString inputFile="root://cmseos.fnal.gov//store/user/lpcljm/2016/LJMet_1lepTT_070516/nominal/SingleMuon_PRB2/SingleMuon_PRB2_60.root";
  
  TString outputFile="test.root";
  
  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");
  
  step1 t(inputFile,outputFile);
  t.Loop();
}


