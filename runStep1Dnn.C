void runStep1Dnn(TString macroDir, TString inputFile, TString outputFile, TString outputDir){

  gSystem->Load("../../lib/slc6_amd64_gcc700/liblwtnnlwtnn.so");
  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");

  gROOT->SetMacroPath(macroDir);
  TString incl("-I");
  incl+=macroDir;
  gSystem->AddIncludePath(incl);

  gROOT->ProcessLine(".x makeStep1Dnn.C(\""+inputFile+"\",\""+outputFile+"\",\""+outputDir+"\")");

}
