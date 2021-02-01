#include "step2.cc"
#include <vector>

using namespace std;

void makeStep2Dnn(TString inputFile, TString outputFile){

  step2 t(inputFile,outputFile);

  bool isData = (inputFile.Contains("Single") || inputFile.Contains("EGamma"));

  if(isData) t.Loop("ljmet","ljmet");
  else{
    //t.saveHistograms();
    vector<TString> shifts = {"ljmet","ljmet_JECup","ljmet_JECdown","ljmet_JERup","ljmet_JERdown","ljmet_BTAGup","ljmet_BTAGdown","ljmet_LTAGup","ljmet_LTAGdown"};
    for(size_t i = 0; i < shifts.size(); i++){
      cout << "\nRunning shift " << shifts[i] << endl;

      if(shifts[i].Contains("BTAG") || shifts[i].Contains("LTAG")) t.Loop(shifts[0],shifts[i]);
      else t.Loop(shifts[i],shifts[i]);
    }
  }
}
