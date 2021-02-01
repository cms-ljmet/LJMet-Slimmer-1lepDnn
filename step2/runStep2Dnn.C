void runStep2Dnn(TString macroDir, TString inputFile, TString outputFile){

  gSystem->Load("../../lib/slc6_amd64_gcc700/liblwtnnlwtnn.so");
  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");

  gROOT->SetMacroPath(macroDir);
  TString incl("-I");
  incl+=macroDir;
  gSystem->AddIncludePath(incl);

  gROOT->ProcessLine(".x makeStep2Dnn.C(\""+inputFile+"\",\""+outputFile+"\")");

}
