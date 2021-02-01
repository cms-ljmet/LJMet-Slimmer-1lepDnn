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

#include "lwtnn/lwtnn/interface/parse_json.hh"
#include "lwtnn/lwtnn/interface/LightweightNeuralNetwork.hh"

using namespace std;

//outputTree->Branch("maxProb_JetSubCalc_PtOrdered",&maxProb_JetSubCalc_PtOrdered);
//outputTree->Branch("AK4HT",&AK4HT,"AK4HT/F");

// ----------------------------------------------------------------------------
// DNN stuff
// ----------------------------------------------------------------------------

std::string dnnFileTT = "vlq_mlp_3x10_10var_Jan21_2016TT.json";
std::ifstream input_cfgTT( dnnFileTT );
lwt::JSONConfig cfgTT = lwt::parse_json(input_cfgTT);
lwt::LightweightNeuralNetwork* lwtnnTT = new lwt::LightweightNeuralNetwork(cfgTT.inputs, cfgTT.layers, cfgTT.outputs);

std::string dnnFileBB = "vlq_mlp_3x10_11var_Jan21_2016BB.json";
std::ifstream input_cfgBB( dnnFileBB );
lwt::JSONConfig cfgBB = lwt::parse_json(input_cfgBB);
lwt::LightweightNeuralNetwork* lwtnnBB = new lwt::LightweightNeuralNetwork(cfgBB.inputs, cfgBB.layers, cfgBB.outputs);

std::map<std::string,double> myMapTT;
std::map<std::string,double> varMapTT;
std::map<std::string,double> myMapBB;
std::map<std::string,double> varMapBB;

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

  float dnnNew_ttbar;
  float dnnNew_WJets;
  float dnnNew_Tprime;
  float dnnNew_ttbarBB;
  float dnnNew_WJetsBB;
  float dnnNew_Bprime;
  outputTree->Branch("dnnNew_ttbar",&dnnNew_ttbar,"dnnNew_ttbar/F");
  outputTree->Branch("dnnNew_WJets",&dnnNew_WJets,"dnnNew_WJets/F");
  outputTree->Branch("dnnNew_Tprime",&dnnNew_Tprime,"dnnNew_Tprime/F"); 
  outputTree->Branch("dnnNew_ttbarBB",&dnnNew_ttbarBB,"dnnNew_ttbarBB/F");
  outputTree->Branch("dnnNew_WJetsBB",&dnnNew_WJetsBB,"dnnNew_WJetsBB/F");
  outputTree->Branch("dnnNew_Bprime",&dnnNew_Bprime,"dnnNew_Bprime/F");
 
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

    // ----------------------------------------------------------------------------
    // Evaluate the VLQ / ttbar / WJets DNN
    // ----------------------------------------------------------------------------
      
    myMapTT = {
      {"Wjets",  -999},
      {"ttbar",  -999},
      {"Tprime",-999},
    };

    varMapTT = {
      {"dnnJ_1", -999},
      {"dnnJ_2", -999},
      {"dnnJ_3", -999},
      {"AK4HT", -999},
      {"t_mass",-999},
      {"t_dRWb",-999},
      {"AK4HTpMETpLepPt", -999},
      {"NJets_JetSubCalc", -999},
      {"NJetsDeepFlavwithSF_JetSubCalc", -999},
      {"minDR_leadAK8otherAK8", -999},
    };

    myMapBB = {
      {"Wjets",  -999},
      {"ttbar",  -999},
      {"Bprime",-999},
    };

    varMapBB = {
      {"dnnJ_1", -999},
      {"dnnJ_2", -999},
      {"dnnJ_3", -999},
      {"sdMass_1", -999},
      {"AK4HT", -999},
      {"t_mass",-999},
      {"t_dRWb",-999},
      {"AK4HTpMETpLepPt", -999},
      {"NJets_JetSubCalc", -999},
      {"NJetsDeepFlavwithSF_JetSubCalc", -999},
      {"minDR_leadAK8otherAK8", -999},
    };

    dnnNew_WJets = -1;
    dnnNew_ttbar = -1;
    dnnNew_Tprime = -1;
    dnnNew_WJetsBB = -1;
    dnnNew_ttbarBB = -1;
    dnnNew_Bprime = -1;

    float sdMass_1;
    float dnnJ_1, dnnJ_2, dnnJ_3;
      
    sdMass_1 = theJetAK8SoftDropCorr_JetSubCalc_PtOrdered->at(0);      
    dnnJ_1 = dnn_J_DeepAK8Calc_PtOrdered->at(0);
    dnnJ_2 = dnn_J_DeepAK8Calc_PtOrdered->at(1);
    dnnJ_3 = dnn_J_DeepAK8Calc_PtOrdered->at(2);
      
    varMapTT = {
      {"dnnJ_1", dnnJ_1},
      {"dnnJ_2", dnnJ_2},
      {"dnnJ_3", dnnJ_3},
      {"AK4HT", AK4HT},
      {"t_mass", t_mass},
      {"t_dRWb", t_dRWb},
      {"AK4HTpMETpLepPt", AK4HTpMETpLepPt},
      {"NJets_JetSubCalc", NJets_JetSubCalc},
      {"NJetsDeepFlavwithSF_JetSubCalc", NJetsDeepFlavwithSF_JetSubCalc},
      {"minDR_leadAK8otherAK8", minDR_leadAK8otherAK8},
    };
    
    varMapBB = {
      {"dnnJ_1", dnnJ_1},
      {"dnnJ_2", dnnJ_2},
      {"dnnJ_3", dnnJ_3},
      {"sdMass_1", sdMass_1},
      {"AK4HT", AK4HT},
      {"t_mass", t_mass},
      {"t_dRWb", t_dRWb},
      {"AK4HTpMETpLepPt", AK4HTpMETpLepPt},
      {"NJets_JetSubCalc", NJets_JetSubCalc},
      {"NJetsDeepFlavwithSF_JetSubCalc", NJetsDeepFlavwithSF_JetSubCalc},
      {"minDR_leadAK8otherAK8", minDR_leadAK8otherAK8},
    };
    
    myMapTT = lwtnnTT->compute(varMapTT);      
    myMapBB = lwtnnBB->compute(varMapBB);      
    
    dnnNew_WJets = myMapTT["Wjets"];
    dnnNew_ttbar = myMapTT["ttbar"];
    dnnNew_Tprime = myMapTT["Tprime"];
    dnnNew_WJetsBB = myMapBB["Wjets"];
    dnnNew_ttbarBB = myMapBB["ttbar"];
    dnnNew_Bprime = myMapBB["Bprime"];
    
    npassed_all++;
    outputTree->Fill(); 
  }
  std::cout<<"NPassed ALL = " << npassed_all << "/"<<nentries<<std::endl;
  std::cout << "DONE" << std::endl;
  outputTree->Write();
  
}
