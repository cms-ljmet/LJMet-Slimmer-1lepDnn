#include "step2.cc"

void testStep2(){ //TString inputFile, TString outputFile){

<<<<<<< HEAD
  TString inputFile="root://cmseos.fnal.gov//store/user/cholz/FWLJMET102X_1lep2018Dnn_Mar2020_step1hadds/TprimeTprime_M-1200_TuneCP5_PSweights_13TeV-madgraph-pythia8_BWBW_hadd.root";
=======
  TString inputFile="root://cmseos.fnal.gov//store/user/bburgsta/FWLJMET102X_1lep2016Dnn_trainMVA_step1hadds/TprimeTprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_1_hadd.root";
>>>>>>> 1babca7ec385b9e8e043c203dc3d45674911bd17
  TString outputFile="test.root";

  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");

  step2 t(inputFile,outputFile);
  t.Loop("ljmet","ljmet");
}
