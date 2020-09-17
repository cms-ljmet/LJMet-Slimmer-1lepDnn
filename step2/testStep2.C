#include "step2.cc"

void testStep2(){ //TString inputFile, TString outputFile){

<<<<<<< HEAD
  TString inputFile="root://cmseos.fnal.gov//store/user/cholz/FWLJMET102X_1lep2018Dnn_Mar2020_step1hadds/TprimeTprime_M-1200_TuneCP5_PSweights_13TeV-madgraph-pythia8_BWBW_hadd.root";
=======
  TString inputFile="root://cmseos.fnal.gov//store/user/bburgsta/FWLJMET102X_1lep2016Dnn_trainMVA_step1hadds/TprimeTprime_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8_1_hadd.root";
>>>>>>> ce2542b0dfe71b9bb8bf62be7ffd9c6fef3d5ca4
  TString outputFile="test.root";

  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");

  step2 t(inputFile,outputFile);
  t.Loop("ljmet","ljmet");
}
