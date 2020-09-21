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
  
  int npassed_all = 0;

  Long64_t nentries = inputTree->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = inputTree->GetEntry(jentry);   nbytes += nb;
    if (Cut(ientry) != 1) continue; 
    
    //      if (ientry > 5000) continue;
    
    if(jentry % 10000 ==0) std::cout<<"Completed "<<jentry<<" out of "<<nentries<<" events"<<std::endl;
    
    if( MCPastTrigger < 1 || DataPastTrigger < 1 || NJetsAK8_JetSubCalc < 3 || corr_met_MultiLepCalc < 50. || leptonPt_MultiLepCalc < 55) continue;

    npassed_all++;
    outputTree->Fill(); 
  }
  std::cout<<"NPassed ALL = " << npassed_all << "/"<<nentries<<std::endl;
  std::cout << "DONE" << std::endl;
  outputTree->Write();
 
}
