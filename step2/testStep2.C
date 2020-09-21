#include "step2.cc"

void testStep2(){ //TString inputFile, TString outputFile){

  TString inputFile="root://cmseos.fnal.gov//store/user/cholz/FWLJMET102X_1lep2016Dnn_06092020_step1hadds/TprimeTprime_M-900_TuneCUETP8M1_13TeV-madgraph-pythia8_TZTZ_4_hadd.root";
  TString outputFile="test.root";

  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");

  step2 t(inputFile,outputFile);
  t.Loop("ljmet","ljmet");
}
