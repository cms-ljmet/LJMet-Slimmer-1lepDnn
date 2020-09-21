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
    //cout <<"=========== triggerSF before math: " << triggerSF << " ===========" << endl;
    triggerSF = 1.0;
    triggerSFUncert = 0.0;

    float leppt = leptonPt_MultiLepCalc;
    float lepeta = leptonEta_MultiLepCalc;
 
    if(isMC){ //MC triggers check
           if(isElectron){
//             cout << "trigger SF: " << triggerSF << endl;
             float runBCDEFG = 1.0;
             float runH = 1.0;
             float runBCDEFGunc = 0.0;
             float runHunc = 0.0;
             if (fabs(lepeta) < 0.8){
               if (leppt < 60) {runBCDEFG = 1.026; runBCDEFGunc = 0.018; runH = 1.007; runHunc = 0.035;}
               else if (leppt < 70) {runBCDEFG = 0.986; runBCDEFGunc = 0.018;  runH = 0.982; runHunc = 0.036;}
               else if (leppt < 100) {runBCDEFG = 1.009; runBCDEFGunc = 0.009;  runH = 0.972; runHunc = 0.020;}
               else if (leppt < 200) {runBCDEFG = 0.985; runBCDEFGunc = 0.008;  runH = 0.766; runHunc = 0.029;}
               else {runBCDEFG = 0.902; runBCDEFGunc = 0.026;  runH = 0.477; runHunc = 0.078;}
             }else if (fabs(lepeta) < 1.442){
               if (leppt < 60) {runBCDEFG = 1.026; runBCDEFGunc = 0.023;  runH = 1.029; runHunc = 0.045;}
               else if (leppt < 70) {runBCDEFG = 1.070; runBCDEFGunc = 0.020;  runH = 0.863; runHunc = 0.069;}
               else if (leppt < 100) {runBCDEFG = 1.039; runBCDEFGunc = 0.011;  runH = 1.007; runHunc = 0.027;}
               else if (leppt < 200) {runBCDEFG = 0.994; runBCDEFGunc = 0.011;  runH = 0.800; runHunc = 0.037;}
               else {runBCDEFG = 1.024; runBCDEFGunc = 0.004;  runH = 0.546; runHunc = 0.0132;}
             }else if (fabs(lepeta) < 1.566){
               if (leppt < 60) {runBCDEFG = 1.282; runBCDEFGunc = 0.044;  runH = 1.282; runHunc = 0.044;}
               else if (leppt < 70) {runBCDEFG = 1.205; runBCDEFGunc = 0.036;  runH = 0.603; runHunc = 0.247;}
               else if (leppt < 100) {runBCDEFG = 0.870; runBCDEFGunc = 0.097;  runH = 0.977; runHunc = 0.111;}
               else if (leppt < 200) {runBCDEFG = 1.035; runBCDEFGunc = 0.058;  runH = 0.894; runHunc = 0.142;}
               else {runBCDEFG = 1.048; runBCDEFGunc = 0.022;  runH = 0.524; runHunc = 0.262;}
             }else if (fabs(lepeta) < 2.0){
               if (leppt < 60) {runBCDEFG = 1.182; runBCDEFGunc = 0.044;  runH = 1.165; runHunc = 0.093;}
               else if (leppt < 70) {runBCDEFG = 1.231; runBCDEFGunc = 0.036;  runH = 1.185; runHunc = 0.090;}
               else if (leppt < 100) {runBCDEFG = 1.011; runBCDEFGunc = 0.038;  runH = 1.136; runHunc = 0.045;}
               else if (leppt < 200) {runBCDEFG = 1.061; runBCDEFGunc = 0.032;  runH = 0.921; runHunc = 0.081;}
               else {runBCDEFG = 0.894; runBCDEFGunc = 0.086;  runH = 0.572; runHunc = 0.286;}
             }else {
               if (leppt < 60) {runBCDEFG = 1.091; runBCDEFGunc = 0.056;  runH = 0.802; runHunc = 0.328;}
               else if (leppt < 70) {runBCDEFG = 0.950; runBCDEFGunc = 0.096;  runH = 1.188; runHunc = 0.020;}
               else if (leppt < 100) {runBCDEFG = 1.069; runBCDEFGunc = 0.031;  runH = 0.940; runHunc = 0.172;}
               else if (leppt < 200) {runBCDEFG = 1.079; runBCDEFGunc = 0.032;  runH = 0.793; runHunc = 0.134;}
               else {runBCDEFG = 1.110; runBCDEFGunc = 0.036;  runH = 1.0; runHunc = 0.0;}
             }
             float triggerSFUncertBCDEF = 29.957*runBCDEFGunc/36.814;
             float triggerSFUncertH = 8.857*runHunc/36.814;
             triggerSF = (27.957*runBCDEFG + 8.857*runH)/36.814;
             triggerSFUncert = sqrt(pow(triggerSFUncertBCDEF, 2) + pow(triggerSFUncertH, 2));
//             cout << "After math Electron triggerSF: " << triggerSF << endl;
           }
          if(isMuon){
//             cout << "Muon triggerSF: " << triggerSF << endl;
             float runBCDEFG = 1.0;
             float runH = 1.0;
             float runBCDEFGunc = 0.0;
             float runHunc = 0.0;
             if (fabs(lepeta) < 0.90){
               if (leppt < 60.0){
                 runBCDEFG = 1.011; runBCDEFGunc = 0.016;
                 runH = 1.022;  runHunc = 0.023;
               }
               else if (leppt < 70.0){
                 runBCDEFG = 1.007; runBCDEFGunc = 0.016;
                 runH = 1.019;  runHunc = 0.026;
               }
               else if (leppt < 100){
                 runBCDEFG = 0.976; runBCDEFGunc = 0.013;
                 runH = 0.992;  runHunc = 0.02;
               }
               else if (leppt < 200){
                 runBCDEFG = 0.953; runBCDEFGunc = 0.013;
                 runH = 0.968;  runHunc = 0.021;
               }
               else{
                 runBCDEFG = 0.945; runBCDEFGunc = 0.035;
                 runH = 0.933;  runHunc = 0.059;
               }
             }
             else if (fabs(lepeta) < 1.2){
               if (leppt < 60.0){
                 runBCDEFG = 0.981; runBCDEFGunc = 0.042;
                 runH = 1.032;  runHunc = 0.054;
               }
               else if (leppt < 70.0){
                 runBCDEFG = 1.046; runBCDEFGunc = 0.019;
                 runH = 1.064;  runHunc = 0.008;
               }
               else if (leppt < 100){
                 runBCDEFG = 0.999; runBCDEFGunc = 0.023;
                 runH = 0.967;  runHunc = 0.049;
               }
               else if (leppt < 200){
                 runBCDEFG = 0.977; runBCDEFGunc = 0.022;
                 runH = 1.006;  runHunc = 0.038;
               }
               else{
                 runBCDEFG = 0.943; runBCDEFGunc = 0.067;
                 runH = 1.042;  runHunc = 0.008;
               }
             }
             else if (fabs(lepeta) < 2.10){
               if (leppt < 60.0){
                 runBCDEFG = 1.041; runBCDEFGunc = 0.019;
                 runH = 1.046;  runHunc = 0.027;
               }
               else if (leppt < 70.0){
                 runBCDEFG = 1.064; runBCDEFGunc = 0.013;
                 runH = 1.032;  runHunc = 0.043;
               }
               else if (leppt < 100){
                 runBCDEFG = 1.018; runBCDEFGunc = 0.014;
                 runH = 1.012;  runHunc = 0.026;
               }
               else if (leppt < 200){
                 runBCDEFG = 1.013; runBCDEFGunc = 0.014;
                 runH = 0.969;  runHunc = 0.037;
               }
               else{
                 runBCDEFG = 0.980; runBCDEFGunc = 0.044;
                 runH = 0.883;  runHunc = 0.105;
                }
             }
             else{
               if (leppt < 60.0){
                 runBCDEFG = 0.966; runBCDEFGunc = 0.103;
                 runH = 1.074;  runHunc = 0.019;
               }
               else if (leppt < 70.0){
                 runBCDEFG = 1.092; runBCDEFGunc = 0.024;
                 runH = 1.092;  runHunc = 0.024;
               }
               else if (leppt < 100){
                 runBCDEFG = 1.063; runBCDEFGunc = 0.013;
                 runH = 1.063;  runHunc = 0.013;
               }
               else if (leppt < 200){
                 runBCDEFG = 0.968; runBCDEFGunc = 0.093;
                 runH = 1.0;  runHunc = 0.0;
               }
               else{
                 runBCDEFG = 1.0; runBCDEFGunc = 0.0;
                 runH = 1.0;  runHunc = 0.0;
               } 
             }
           float triggerSFUncertBCDEF = 29.957*runBCDEFGunc/36.814;
           float triggerSFUncertH = 8.857*runHunc/36.814;
           triggerSF = (27.957*runBCDEFG + 8.857*runH)/36.814;
           triggerSFUncert = sqrt(pow(triggerSFUncertBCDEF, 2) + pow(triggerSFUncertH, 2));
//           cout << "After math Muon trigger SF: " << triggerSF << endl;
           } 
    }
    npassed_all++;
    outputTree->Fill(); 
  }
  std::cout<<"NPassed ALL = " << npassed_all << "/"<<nentries<<std::endl;
  std::cout << "DONE" << std::endl;
  outputTree->Write();
 
}
