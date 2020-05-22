#include "step2.cc"

void testStep2(){ //TString inputFile, TString outputFile){

  TString inputFile="root://cmseos.fnal.gov//store/user/bburgsta/FWLJMET102X_1lep2016Dnn_trainMVA_step1hadds/TprimeTprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_1_hadd.root";
  TString outputFile="test.root";

  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");

  step2 t(inputFile,outputFile);
  t.Loop("ljmet","ljmet");
}
