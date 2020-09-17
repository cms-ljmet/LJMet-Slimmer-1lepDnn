#include "step2.cc"
#include <vector>
<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> ce2542b0dfe71b9bb8bf62be7ffd9c6fef3d5ca4

using namespace std;

void makeStep2(TString macroDir, TString inputFile, TString outputFile, bool runShifts){

  gROOT->SetMacroPath(macroDir);

  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");

  TString incl("-I");
  incl+=macroDir;
  gSystem->AddIncludePath(incl);

  step2 t(inputFile,outputFile);
  bool isData = (inputFile.Contains("Single") || inputFile.Contains("EGamma"));
<<<<<<< HEAD
  std::cout << "Data/MC decision: isData = " << isData << std::endl;
 
  if(isData or not runShifts) t.Loop("ljmet","ljmet");
  else{
    //t.saveHistograms();
=======
 
  if(isData or not runShifts) t.Loop("ljmet","ljmet");
  else{
    t.saveHistograms();
>>>>>>> ce2542b0dfe71b9bb8bf62be7ffd9c6fef3d5ca4
    vector<TString> shifts = {"ljmet","ljmet_JECup","ljmet_JECdown","ljmet_JERup","ljmet_JERdown","ljmet_BTAGup","ljmet_BTAGdown","ljmet_LTAGup","ljmet_LTAGdown"};
    for(size_t i = 0; i < shifts.size(); i++){
      cout << "\nRunning shift " << shifts[i] << endl;
      t.Loop(shifts[i],shifts[i]);
    }
  }
}
