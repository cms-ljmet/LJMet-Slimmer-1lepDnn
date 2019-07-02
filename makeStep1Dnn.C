#include "step1.cc"
#include <vector>

using namespace std;

void makeStep1Dnn(TString inputFile, TString outputFile, TString outputDir){

  step1 t(inputFile,outputFile,outputDir);

  bool isData = (inputFile.Contains("Single") || inputFile.Contains("EGamma"));

  if(isData) t.Loop("ljmet","ljmet");
  else{
    t.saveHistograms();
    vector<TString> shifts = {"ljmet","ljmet_JECup","ljmet_JECdown","ljmet_JERup","ljmet_JERdown","ljmet_BTAGup","ljmet_BTAGdown","ljmet_LTAGup","ljmet_LTAGdown"};
    for(size_t i = 0; i < shifts.size(); i++){
      if(shifts[i].Contains("BTAGup")) {isBUp = true; isBDn = false; isLUp = false; isLDn = false; isNominal = false;}
      else if(shifts[i].Contains("BTAGdown")) {isBUp = false; isBDn = true; isLUp = false; isLDn = false; isNominal = false;}
      else if(shifts[i].Contains("LTAGup")) {isBUp = false; isBDn = true; isLUp = true; isLDn = false; isNominal = false;}
      else if(shifts[i].Contains("LTAGdown")) {isBUp = false; isBDn = true; isLUp = false; isLDn = true; isNominal = false;}
      else {isBUp = false; isBDn = false; isLUp = false; isLDn = false; isNominal = true;}
      cout << "\nRunning shift " << shifts[i] << ", (Bup,Bdn,Lup,Ldn,None) = (" << isBUp << "," << isBDn << "," << isLUp << "," << isLDn << "," << isNominal << ")" << endl;

      if(shifts[i].Contains("BTAG") || shifts[i].Contains("LTAG")) t.Loop(shifts[0],shifts[i]);
      else t.Loop(shifts[i],shifts[i]);
    }
  }
}
