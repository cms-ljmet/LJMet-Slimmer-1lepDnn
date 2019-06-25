void runStep1Dnn(TString macroDir, TString inputFile, TString outputFile, TString outputDir){

  gSystem->Load("liblwtnnlwtnn.so");
  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");

  gROOT->SetMacroPath(macroDir);
  TString incl("-I");
  incl+=macroDir;
  gSystem->AddIncludePath(incl);

  gROOT->ProcessLine(".x makeStep1Dnn.C(\""+inputFile+"\",\""+outputFile+"\",\""+outputDir+"\")");

}
