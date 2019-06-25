
void testStep1Dnn(TString macroDir, TString inputFile, TString outputFile){

  gSystem->Load("/uscms_data/d3/jmanagan/CMSSW_10_2_10/lib/slc6_amd64_gcc630/liblwtnnlwtnn.so");
  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");

  gROOT->SetMacroPath(macroDir);
  TString incl("-I");
  incl+=macroDir;
  gSystem->AddIncludePath(incl);

  gROOT->ProcessLine(".x makeStep1Dnn.C(\""+inputFile+"\",\""+outputFile+"\",\"$PWD\")");

}
