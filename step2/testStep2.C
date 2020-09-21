#include "step2.cc"

void testStep2(){ //TString inputFile, TString outputFile){

  //TString inputFile="tptp1800_step2.root";
  //TString outputFile="test1800.root";
  TString inputFile="root://cmseos.fnal.gov//store/user/cholz/FWLJMET102X_1lep2018Dnn_Mar2020_step1hadds/TprimeTprime_M-1200_TuneCP5_PSweights_13TeV-madgraph-pythia8_BWBW_hadd.root";

  TString outputFile="test.root";


  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");

  step2 t(inputFile,outputFile);
  t.Loop("ljmet","ljmet");
}
