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

  std::vector<float> probjratio = {0.93502437536,1.16050105933,1.17907897781,1.19761779496,1.1605174677,1.21086755205,1.18172403861,1.17633653298,1.13539922593,1.1638942794,1.20042923129,1.15940403571,1.12754788226,1.12667308666,1.10719523961,1.12582949499,1.10189585351,1.12541409448,1.18383437813,1.1479992218,1.06086063339,1.17383559034,1.13233112262,1.1143887346,1.14445348826,1.14160659701,1.12601268962,1.1184326496,1.088199043,1.10070675891,1.13485746114,1.12776426817,1.12182946261,1.14623005575,1.11298486273,1.10253114396,1.13760859761,1.09899545364,1.10552205758,1.09028053261,1.08116624002,1.05868392915,1.03946854035,1.01164251299,0.950746433825,0.877552238296,0.816278871402,0.765795138198,0.815139345621,0.993521986454};

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
