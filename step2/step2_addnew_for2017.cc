#define step2_cxx
#include "step2.h"
#include <fstream>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <TH2.h>
#include <TF1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TRandom.h>
#include <TRandom3.h>
#include <sstream>
#include <string>
#include <vector>
#include <TLorentzVector.h>
#include <math.h>
using namespace std;

//outputTree->Branch("maxProb_JetSubCalc_PtOrdered",&maxProb_JetSubCalc_PtOrdered);
//outputTree->Branch("AK4HT",&AK4HT,"AK4HT/F");



void step2::Loop(TString inTreeName, TString outTreeName) 
{
  inputTree = (TTree*)inputFile->Get(inTreeName);
  if (inputTree == 0) return;
  if(inputTree->GetEntries() == 0){
    std::cout << "WARNING! Found 0 events in the tree!!!" << std::endl;
    return;
  }

  Init(inputTree);
   
  inputTree->SetBranchStatus("*",1);

  // Makes a copy of the branches with status 1
  outputFile->cd();
  if(isMC && inTreeName == "ljmet"){
    TH1D* numhist = (TH1D*)inputFile->Get("NumTrueHist");
    TH1D* wgthist = (TH1D*)inputFile->Get("weightHist");
    numhist->Write();
    wgthist->Write();
  }
  TTree *outputTree = inputTree->CloneTree(0);

  float dnnJweight, dnnJweight3;
  outputTree->Branch("dnnJweight",&dnnJweight,"dnnJweight/F");
  outputTree->Branch("dnnJweight3",&dnnJweight3,"dnnJweight3/F");
  
  int npassed_all = 0;

  std::vector<float> probjratio = {0.895978610288,1.16525315136,1.20747298989,1.19353489843,1.18540312118,1.18632840174,1.15826557542,1.17909153199,1.1741450779,1.17470932221,1.14152086917,1.2197336202,1.18811047751,1.15225187135,1.21357371137,1.16520406009,1.12996415871,1.1508927419,1.1186715293,1.15234318754,1.08876462251,1.10323576449,1.13570005709,1.1341834586,1.10422957542,1.23227254201,1.12565168224,1.14096049038,1.10447652923,1.13157946119,1.16375808236,1.14940833335,1.15607472711,1.18015479664,1.13812756764,1.1298478968,1.16623846496,1.16324157939,1.14357869922,1.16791151985,1.11825314392,1.12994111158,1.11389184899,1.04621473695,1.01500221633,0.925724410351,0.819028856086,0.731851041888,0.680752586579,0.72002981445};

  Long64_t nentries = inputTree->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = inputTree->GetEntry(jentry);   nbytes += nb;
    if (Cut(ientry) != 1) continue; 
    
    //      if (ientry > 5000) continue;
    
    if(jentry % 10000 ==0) std::cout<<"Completed "<<jentry<<" out of "<<nentries<<" events"<<std::endl;
    
    if( MCPastTrigger < 1 || DataPastTrigger < 1 ) continue;
    
    dnnJweight = 1;
    dnnJweight3 = 1;
    if (NJetsAK8_JetSubCalc > 0) dnnJweight *= probjratio.at(floor(dnn_J_DeepAK8Calc_PtOrdered->at(0)/0.02));
    if (NJetsAK8_JetSubCalc > 1) dnnJweight *= probjratio.at(floor(dnn_J_DeepAK8Calc_PtOrdered->at(1)/0.02));
    if (NJetsAK8_JetSubCalc > 2) dnnJweight3 = dnnJweight*probjratio.at(floor(dnn_J_DeepAK8Calc_PtOrdered->at(2)/0.02));

    npassed_all++;
    outputTree->Fill(); 
  }
  std::cout<<"NPassed ALL = " << npassed_all << "/"<<nentries<<std::endl;
  std::cout << "DONE" << std::endl;
  outputTree->Write();
 
}
