#define step1_cxx
#include "step1.h"
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

using namespace std;

// ----------------------------------------------------------------------------
// Define functions
// ----------------------------------------------------------------------------

bool comparepair( const std::pair<double,int> a, const std::pair<double,int> b) { return a.first > b.first; }

TRandom3 Rand;

const double MTOP  = 173.5;
const double MW    = 80.4; 



// ----------------------------------------------------------------------------
// MAIN EVENT LOOP
// ----------------------------------------------------------------------------

void step1::Loop() 
{
  
  // ----------------------------------------------------------------------------
  // Turn on input tree branches
  // ----------------------------------------------------------------------------

   if (inputTree == 0) return;
   
   inputTree->SetBranchStatus("*",0);

   //Event info

   inputTree->SetBranchStatus("event_CommonCalc",1);
   inputTree->SetBranchStatus("run_CommonCalc",1);
   inputTree->SetBranchStatus("lumi_CommonCalc",1);
   inputTree->SetBranchStatus("nPV_singleLepCalc",1);
   inputTree->SetBranchStatus("nTrueInteractions_singleLepCalc",1);
   inputTree->SetBranchStatus("MCWeight_singleLepCalc",1);

   inputTree->SetBranchStatus("isTHBW_TpTpCalc",1);
   inputTree->SetBranchStatus("isTHTH_TpTpCalc",1);
   inputTree->SetBranchStatus("isBWBW_TpTpCalc",1);
   inputTree->SetBranchStatus("isTZBW_TpTpCalc",1);
   inputTree->SetBranchStatus("isTZTH_TpTpCalc",1);
   inputTree->SetBranchStatus("isTZTZ_TpTpCalc",1);
   inputTree->SetBranchStatus("isBHTW_TpTpCalc",1);
   inputTree->SetBranchStatus("isBHBH_TpTpCalc",1);
   inputTree->SetBranchStatus("isTWTW_TpTpCalc",1);
   inputTree->SetBranchStatus("isBZTW_TpTpCalc",1);
   inputTree->SetBranchStatus("isBZBH_TpTpCalc",1);
   inputTree->SetBranchStatus("isBZBZ_TpTpCalc",1);
   inputTree->SetBranchStatus("tPrimePt_TpTpCalc",1);
   inputTree->SetBranchStatus("NLeptonDecays_TpTpCalc",1);
   
   //triggers
   inputTree->SetBranchStatus("vsSelMCTriggersEl_singleLepCalc",1);
   inputTree->SetBranchStatus("viSelMCTriggersEl_singleLepCalc",1);
   inputTree->SetBranchStatus("vsSelMCTriggersMu_singleLepCalc",1);
   inputTree->SetBranchStatus("viSelMCTriggersMu_singleLepCalc",1);
   inputTree->SetBranchStatus("vsSelTriggersEl_singleLepCalc",1);
   inputTree->SetBranchStatus("viSelTriggersEl_singleLepCalc",1);
   inputTree->SetBranchStatus("vsSelTriggersMu_singleLepCalc",1);
   inputTree->SetBranchStatus("viSelTriggersMu_singleLepCalc",1);
   
   //electrons **** ADD MORE/NEW ID BRANCHES *****
   inputTree->SetBranchStatus("elPt_singleLepCalc",1);
   inputTree->SetBranchStatus("elEta_singleLepCalc",1);
   inputTree->SetBranchStatus("elPhi_singleLepCalc",1);
   inputTree->SetBranchStatus("elEnergy_singleLepCalc",1);
   inputTree->SetBranchStatus("elMVAValue_singleLepCalc",1);
   inputTree->SetBranchStatus("elMiniIso_singleLepCalc",1);
   inputTree->SetBranchStatus("elIsTightBarrel_singleLepCalc",1);
   inputTree->SetBranchStatus("elIsMediumBarrel_singleLepCalc",1);
   inputTree->SetBranchStatus("elIsLooseBarrel_singleLepCalc",1);
   inputTree->SetBranchStatus("elIsVetoBarrel_singleLepCalc",1);
   inputTree->SetBranchStatus("elIsTIghtEndCap_singleLepCalc",1);
   inputTree->SetBranchStatus("elIsMediumEndCap_singleLepCalc",1);
   inputTree->SetBranchStatus("elIsLooseEndCap_singleLepCalc",1);
   inputTree->SetBranchStatus("elIsVetoEndCap_singleLepCalc",1);

   
   //muons  **** ADD MORE/NEW ID BRANCHES *****
   inputTree->SetBranchStatus("muPt_singleLepCalc",1);
   inputTree->SetBranchStatus("muEta_singleLepCalc",1);
   inputTree->SetBranchStatus("muPhi_singleLepCalc",1);
   inputTree->SetBranchStatus("muEnergy_singleLepCalc",1);
   inputTree->SetBranchStatus("muMiniIso_singleLepCalc",1);
   inputTree->SetBranchStatus("muIsTight_singleLepCalc",1);
   inputTree->SetBranchStatus("muIsMedium_singleLepCalc",1);
   inputTree->SetBranchStatus("muIsMediumPrompt_singleLepCalc",1);
   inputTree->SetBranchStatus("muIsLoose_singleLepCalc",1);

   //missing et
   inputTree->SetBranchStatus("corr_met_singleLepCalc",1);
   inputTree->SetBranchStatus("corr_met_phi_singleLepCalc",1);

   //boosted truth
   inputTree->SetBranchStatus("HadronicVHtPt_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtEta_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtPhi_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtEnergy_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtID_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD0Pt_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD0Eta_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD0Phi_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD0E_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD1Pt_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD1Eta_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD1Phi_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD1E_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD2Pt_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD2Eta_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD2Phi_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD2E_JetSubCalc",1);

   //jets *** CHECK ALL THESE NAMES, ADD BEST, ADD DeepAK8, Add DoubleB discrim, ADD DeepCSV from singleLepCalc ****
   //JetSubCalc
   inputTree->SetBranchStatus("theJetHFlav_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetPFlav_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetPt_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetEta_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetPhi_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetEnergy_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetCSVb_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetCSVbb_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8DoubleB_JetSubCalc",1);
   //inputTree->SetBranchStatus("theJetCSVc_JetSubCalc",1);
   //inputTree->SetBranchStatus("theJetCSVudsg_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Pt_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Eta_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Phi_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Mass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Energy_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau1_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau2_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau3_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8CHSTau1_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8CHSTau2_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8CHSTau3_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8CHSPrunedMass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8CHSSoftDropMass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDropRaw_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDropCorr_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDrop_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc",1);
   /* inputTree->SetBranchStatus("theJetAK8SDSubjetPt_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetEta_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetCSVb_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetCSVbb_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetCSVc_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetCSVudsg_JetSubCalc",1);*/
   inputTree->SetBranchStatus("theJetAK8SDSubjetHFlav_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetIndex_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetSize_JetSubCalc",1);

   //BEST
   /*inputTree->SetBranchStatus("AK8JetPt_BestCalc",1);
   inputTree->SetBranchStatus("AK8JetEta_BestCalc",1);
   inputTree->SetBranchStatus("AK8JetPhi_BestCalc",1);
   inputTree->SetBranchStatus("AK8JetEnergy_BestCalc",1);
   inputTree->SetBranchStatus("AK8JetCSV_BestCalc",1);
   inputTree->SetBranchStatus("dnn_QCD_BestCalc",1);
   inputTree->SetBranchStatus("dnn_Top_BestCalc",1);
   inputTree->SetBranchStatus("dnn_Higgs_BestCalc",1);
   inputTree->SetBranchStatus("dnn_Z_BestCalc",1);
   inputTree->SetBranchStatus("dnn_W_BestCalc",1);*/
   inputTree->SetBranchStatus("dnn_largest_BestCalc",1);
   /*inputTree->SetBranchStatus("bDisc_BestCalc",1);
   inputTree->SetBranchStatus("bDisc1_BestCalc",1);
   inputTree->SetBranchStatus("bDisc2_BestCalc",1);
   inputTree->SetBranchStatus("et_BestCalc",1);
   inputTree->SetBranchStatus("eta_BestCalc",1);
   inputTree->SetBranchStatus("mass_BestCalc",1);
   inputTree->SetBranchStatus("SDmass_BestCalc",1);
   inputTree->SetBranchStatus("tau32_BestCalc",1);
   inputTree->SetBranchStatus("tau21_BestCalc",1);
   inputTree->SetBranchStatus("q_BestCalc",1);
   inputTree->SetBranchStatus("m1234_jet_BestCalc",1);
   inputTree->SetBranchStatus("m12_jet_BestCalc",1);
   inputTree->SetBranchStatus("m23_jet_BestCalc",1);
   inputTree->SetBranchStatus("m13_jet_BestCalc",1);
   inputTree->SetBranchStatus("m1234top_BestCalc",1);
   inputTree->SetBranchStatus("m12top_BestCalc",1);
   inputTree->SetBranchStatus("m23top_BestCalc",1);
   inputTree->SetBranchStatus("m13top_BestCalc",1);
   inputTree->SetBranchStatus("m1234W_BestCalc",1);
   inputTree->SetBranchStatus("m12W_BestCalc",1);
   inputTree->SetBranchStatus("m23W_BestCalc",1);
   inputTree->SetBranchStatus("m13W_BestCalc",1);
   inputTree->SetBranchStatus("m1234Z_BestCalc",1);
   inputTree->SetBranchStatus("m12Z_BestCalc",1);
   inputTree->SetBranchStatus("m23Z_BestCalc",1);
   inputTree->SetBranchStatus("m13Z_BestCalc",1);
   inputTree->SetBranchStatus("m1234H_BestCalc",1);
   inputTree->SetBranchStatus("m12H_BestCalc",1);
   inputTree->SetBranchStatus("m23H_BestCalc",1);
   inputTree->SetBranchStatus("m13H_BestCalc",1);
   inputTree->SetBranchStatus("pzOverp_top_BestCalc",1);
   inputTree->SetBranchStatus("pzOverp_W_BestCalc",1);
   inputTree->SetBranchStatus("pzOverp_Z_BestCalc",1);
   inputTree->SetBranchStatus("pzOverp_H_BestCalc",1);
   inputTree->SetBranchStatus("pzOverp_jet_BestCalc",1);
   inputTree->SetBranchStatus("Njets_top_BestCalc",1);
   inputTree->SetBranchStatus("Njets_W_BestCalc",1);
   inputTree->SetBranchStatus("Njets_Z_BestCalc",1);
   inputTree->SetBranchStatus("Njets_H_BestCalc",1);
   inputTree->SetBranchStatus("Njets_jet_BestCalc",1);
   inputTree->SetBranchStatus("Njets_orig_BestCalc",1);*/



   //DeepAK8
   /*inputTree->SetBranchStatus("dnn_B_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_J_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_W_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_Z_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_H_DeepAK8Calc",1);*/
   inputTree->SetBranchStatus("dnn_largest_DeepAK8Calc",1);
   inputTree->SetBranchStatus("decorr_largest_DeepAK8Calc",1);
   /*inputTree->SetBranchStatus("dnn_T_DeepAK8Calc",1);
   inputTree->SetBranchStatus("decorr_B_DeepAK8Calc",1);
   inputTree->SetBranchStatus("decorr_J_DeepAK8Calc",1);
   inputTree->SetBranchStatus("decorr_W_DeepAK8Calc",1);
   inputTree->SetBranchStatus("decorr_Z_DeepAK8Calc",1);
   inputTree->SetBranchStatus("decorr_H_DeepAK8Calc",1);
   inputTree->SetBranchStatus("decorr_T_DeepAK8Calc",1);*/

   //JetSubCalc
   inputTree->SetBranchStatus("maxProb_JetSubCalc",1);

   //adding DeepCSV from singleLepCalc
   //inputTree->SetBranchStatus("AK8JetDeepCSVb_singleLepCalc",1);
   //inputTree->SetBranchStatus("AK8JetDeepCSVbb_singleLepCalc",1);
   //   inputTree->SetBranchStatus("AK8JetDeepCSVc_singleLepCalc",1);
   //inputTree->SetBranchStatus("AK8JetDeepCSVudsg_singleLepCalc",1);
   
   //top
   inputTree->SetBranchStatus("ttbarMass_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topEnergy_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topEta_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topMass_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topPhi_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topPt_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topID_TTbarMassCalc",1);
   inputTree->SetBranchStatus("isTT_TTbarMassCalc",1);
   inputTree->SetBranchStatus("isTau_singleLepCalc",1);

  // ----------------------------------------------------------------------------
  // Create output tree and define branches
  // ----------------------------------------------------------------------------
   
   // OUTPUT FILE
   outputFile->cd();
   TTree *outputTree = new TTree("ljmet","ljmet");



   // ***** EVERY NEW BRANCH NEEDS A LINE HERE ****
   outputTree->Branch("event_CommonCalc",&event_CommonCalc,"event_CommonCalc/L");
   outputTree->Branch("run_CommonCalc",&run_CommonCalc,"run_CommonCalc/I");
   outputTree->Branch("lumi_CommonCalc",&lumi_CommonCalc,"lumi_CommonCalc/I");
   outputTree->Branch("nPV_singleLepCalc",&nPV_singleLepCalc,"nPV_singleLepCalc/I");
   outputTree->Branch("nTrueInteractions_singleLepCalc",&nTrueInteractions_singleLepCalc,"nTrueInteractions_singleLepCalc/I");
   outputTree->Branch("isElectron",&isElectron,"isElectron/I");
   outputTree->Branch("isMuon",&isMuon,"isMuon/I");
   outputTree->Branch("MCPastTrigger",&MCPastTrigger,"MCPastTrigger/I");
   outputTree->Branch("DataPastTrigger",&DataPastTrigger,"DataPastTrigger/I");
   outputTree->Branch("isTHBW_TpTpCalc",&isTHBW_TpTpCalc,"isTHBW_TpTpCalc/O");
   outputTree->Branch("isTHTH_TpTpCalc",&isTHTH_TpTpCalc,"isTHTH_TpTpCalc/O");
   outputTree->Branch("isBWBW_TpTpCalc",&isBWBW_TpTpCalc,"isBWBW_TpTpCalc/O");
   outputTree->Branch("isTZBW_TpTpCalc",&isTZBW_TpTpCalc,"isTZBW_TpTpCalc/O");
   outputTree->Branch("isTZTH_TpTpCalc",&isTZTH_TpTpCalc,"isTZTH_TpTpCalc/O");
   outputTree->Branch("isTZTZ_TpTpCalc",&isTZTZ_TpTpCalc,"isTZTZ_TpTpCalc/O");
   outputTree->Branch("isBHTW_TpTpCalc",&isBHTW_TpTpCalc,"isBHTW_TpTpCalc/O");
   outputTree->Branch("isBHBH_TpTpCalc",&isBHBH_TpTpCalc,"isBHBH_TpTpCalc/O");
   outputTree->Branch("isTWTW_TpTpCalc",&isTWTW_TpTpCalc,"isTWTW_TpTpCalc/O");
   outputTree->Branch("isBZTW_TpTpCalc",&isBZTW_TpTpCalc,"isBZTW_TpTpCalc/O");
   outputTree->Branch("isBZBH_TpTpCalc",&isBZBH_TpTpCalc,"isBZBH_TpTpCalc/O");
   outputTree->Branch("isBZBZ_TpTpCalc",&isBZBZ_TpTpCalc,"isBZBZ_TpTpCalc/O");
   outputTree->Branch("tPrimePt_TpTpCalc",&tPrimePt_TpTpCalc,"tPrimePt_TpTpCalc/O");
   outputTree->Branch("NLeptonDecays_TpTpCalc",&NLeptonDecays_TpTpCalc,"NLeptonDecays_TpTpCalc/I");
   outputTree->Branch("MCWeight_singleLepCalc",&MCWeight_singleLepCalc,"MCWeight_singleLepCalc/D");
   outputTree->Branch("renormWeights",&renormWeights);
   outputTree->Branch("pdfWeights",&pdfWeights);
   outputTree->Branch("pileupWeight",&pileupWeight,"pileupWeight/F");
   outputTree->Branch("HTSF_Pol",&HTSF_Pol,"HTSF_Pol/F");
   outputTree->Branch("ttbarMass_TTbarMassCalc",&ttbarMass_TTbarMassCalc,"ttbarMass_TTbarMassCalc/D");
   outputTree->Branch("isTT_TTbarMassCalc",&isTT_TTbarMassCalc,"isTT_TTbarMassCalc/I");
   outputTree->Branch("isTau_singleLepCalc",&isTau_singleLepCalc,"isTau_singleLepCalc/O");
   outputTree->Branch("corr_met_singleLepCalc",&corr_met_singleLepCalc,"corr_met_singleLepCalc/D");
   outputTree->Branch("corr_met_phi_singleLepCalc",&corr_met_phi_singleLepCalc,"corr_met_phi_singleLepCalc/D");
   outputTree->Branch("leptonPt_singleLepCalc",&leptonPt_singleLepCalc,"leptonPt_singleLepCalc/F");
   outputTree->Branch("leptonEta_singleLepCalc",&leptonEta_singleLepCalc,"leptonEta_singleLepCalc/F");
   outputTree->Branch("leptonPhi_singleLepCalc",&leptonPhi_singleLepCalc,"leptonPhi_singleLepCalc/F");
   outputTree->Branch("leptonEnergy_singleLepCalc",&leptonEnergy_singleLepCalc,"leptonEnergy_singleLepCalc/F");
   outputTree->Branch("leptonMVAValue_singleLepCalc",&leptonMVAValue_singleLepCalc,"leptonMVAValue_singleLepCalc/F");
   outputTree->Branch("leptonMiniIso_singleLepCalc",&leptonMiniIso_singleLepCalc,"leptonMiniIso_singleLepCalc/F");
   outputTree->Branch("theJetPt_JetSubCalc_PtOrdered",&theJetPt_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetEta_JetSubCalc_PtOrdered",&theJetEta_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetPhi_JetSubCalc_PtOrdered",&theJetPhi_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetEnergy_JetSubCalc_PtOrdered",&theJetEnergy_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetCSVb_JetSubCalc_PtOrdered",&theJetCSVb_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetCSVbb_JetSubCalc_PtOrdered",&theJetCSVbb_JetSubCalc_PtOrdered);
   //outputTree->Branch("theJetCSVc_JetSubCalc_PtOrdered",&theJetCSVc_JetSubCalc_PtOrdered);
   //outputTree->Branch("theJetCSVudsg_JetSubCalc_PtOrdered",&theJetCSVudsg_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetHFlav_JetSubCalc_PtOrdered",&theJetHFlav_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetPFlav_JetSubCalc_PtOrdered",&theJetPFlav_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetBTag_JetSubCalc_PtOrdered",&theJetBTag_JetSubCalc_PtOrdered);
   outputTree->Branch("HadronicVHtID_JetSubCalc",&HadronicVHtID_JetSubCalc);
   outputTree->Branch("HadronicVHtPt_JetSubCalc",&HadronicVHtPt_JetSubCalc);
   outputTree->Branch("HadronicVHtEta_JetSubCalc",&HadronicVHtEta_JetSubCalc);
   outputTree->Branch("HadronicVHtPhi_JetSubCalc",&HadronicVHtPhi_JetSubCalc);
   outputTree->Branch("HadronicVHtEnergy_JetSubCalc",&HadronicVHtEnergy_JetSubCalc);
   outputTree->Branch("theJetAK8Pt_JetSubCalc_PtOrdered",&theJetAK8Pt_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Eta_JetSubCalc_PtOrdered",&theJetAK8Eta_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Phi_JetSubCalc_PtOrdered",&theJetAK8Phi_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Mass_JetSubCalc_PtOrdered",&theJetAK8Mass_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Energy_JetSubCalc_PtOrdered",&theJetAK8Energy_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered",&theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered",&theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SoftDropRaw_JetSubCalc_PtOrdered",&theJetAK8SoftDropRaw_PtOrdered);
   outputTree->Branch("theJetAK8SoftDropCorr_JetSubCalc_PtOrdered",&theJetAK8SoftDropCorr_PtOrdered);
   outputTree->Branch("theJetAK8oubleB_JetSubCalc_PtOrdered",&theJetAK8DoubleB_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SoftDrop_PtOrdered",&theJetAK8SoftDrop_PtOrdered);
   outputTree->Branch("theJetAK8SDSubjetNCSVM_PtOrdered",&theJetAK8SDSubjetNCSVM_PtOrdered);
   outputTree->Branch("theJetAK8NjettinessTau1_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau1_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8NjettinessTau2_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau2_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8NjettinessTau3_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau3_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSTau1_JetSubCalc_PtOrdered",&theJetAK8CHSTau1_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSTau2_JetSubCalc_PtOrdered",&theJetAK8CHSTau2_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSTau3_JetSubCalc_PtOrdered",&theJetAK8CHSTau3_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Wmatch_JetSubCalc_PtOrdered",&theJetAK8Wmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Tmatch_JetSubCalc_PtOrdered",&theJetAK8Tmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Zmatch_JetSubCalc_PtOrdered",&theJetAK8Zmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Hmatch_JetSubCalc_PtOrdered",&theJetAK8Hmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8MatchedPt_JetSubCalc_PtOrdered",&theJetAK8MatchedPt_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered",&theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SDSubjetSize_JetSubCalc_PtOrdered",&theJetAK8SDSubjetSize_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SDSubjetIndex_JetSubCalc",&theJetAK8SDSubjetIndex_JetSubCalc);
   outputTree->Branch("theJetAK8SDSubjetSize_JetSubCalc",&theJetAK8SDSubjetSize_JetSubCalc);
   outputTree->Branch("theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered",&theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered);
   outputTree->Branch("maxProb_JetSubCalc_PtOrdered",&maxProb_JetSubCalc_PtOrdered);
   outputTree->Branch("dnn_largest_BestCalc_PtOrdered",&dnn_largest_BestCalc_PtOrdered);
   outputTree->Branch("dnn_largest_DeepAK8Calc_PtOrdered",&dnn_largest_DeepAK8Calc_PtOrdered);
   outputTree->Branch("decorr_largest_DeepAK8Calc_PtOrdered",&decorr_largest_DeepAK8Calc_PtOrdered);
   outputTree->Branch("BJetLeadPt",&BJetLeadPt,"BJetLeadPt/F");
   outputTree->Branch("WJetLeadPt",&WJetLeadPt,"WJetLeadPt/F");
   outputTree->Branch("TJetLeadPt",&TJetLeadPt,"TJetLeadPt/F");
   outputTree->Branch("AK4HTpMETpLepPt",&AK4HTpMETpLepPt,"AK4HTpMETpLepPt/F");
   outputTree->Branch("AK4HT",&AK4HT,"AK4HT/F");
   outputTree->Branch("NJets_JetSubCalc",&NJets_JetSubCalc,"NJets_JetSubCalc/I");
   outputTree->Branch("NJetsAK8_JetSubCalc",&NJetsAK8_JetSubCalc,"NJetsAK8_JetSubCalc/I");
   outputTree->Branch("NJetsCSV_JetSubCalc",&NJetsCSV_JetSubCalc,"NJetsCSV_JetSubCalc/I");
   outputTree->Branch("NJetsCSVnotH_JetSubCalc",&NJetsCSVnotH_JetSubCalc,"NJetsCSVnotH_JetSubCalc/I");
   outputTree->Branch("NJetsCSVnotPH_JetSubCalc",&NJetsCSVnotPH_JetSubCalc,"NJetsCSVnotPH_JetSubCalc/I");
   outputTree->Branch("NJetsH1btagged",&NJetsH1btagged,"NJetsH1btagged/I");
   outputTree->Branch("NJetsH2btagged",&NJetsH2btagged,"NJetsH2btagged/I");
   outputTree->Branch("NPuppiH1btagged",&NPuppiH1btagged,"NPuppiH1btagged/I");
   outputTree->Branch("NPuppiH2btagged",&NPuppiH2btagged,"NPuppiH2btagged/I");
   outputTree->Branch("topPt",&topPt,"topPt/F");
   outputTree->Branch("topPtGen",&topPtGen,"topPtGen/F");
   outputTree->Branch("topMass",&topMass,"topMass/F");
   outputTree->Branch("minMleppBjet",&minMleppBjet,"minMleppBjet/F");
   outputTree->Branch("minMleppJet",&minMleppJet,"mixnMleppJet/F");
   outputTree->Branch("genTopPt",&genTopPt,"genTopPt/F");
   outputTree->Branch("genAntiTopPt",&genAntiTopPt,"genAntiTopPt/F");
   outputTree->Branch("topPtWeight13TeV",&topPtWeight13TeV,"topPtWeight13TeV/F");
   outputTree->Branch("NJetsWtagged_0p6",&NJetsWtagged_0p6,"NJetsWtagged_0p6/I");
   outputTree->Branch("NPuppiWtagged_0p55",&NPuppiWtagged_0p55,"NPuppiWtagged_0p55/I");
   outputTree->Branch("NJetsWtagged_0p6_notTtagged",&NJetsWtagged_0p6_notTtagged,"NJetsWtagged_0p6_notTtagged/I");
   outputTree->Branch("NJetsTtagged_0p81",&NJetsTtagged_0p81,"NJetsTtagged_0p81/I");
   outputTree->Branch("minDR_leadAK8otherAK8",&minDR_leadAK8otherAK8,"minDR_leadAK8otherAK8/F");
   outputTree->Branch("minDR_lepAK8",&minDR_lepAK8,"minDR_lepAK8/F");
   outputTree->Branch("minDR_lepJet",&minDR_lepJet,"minDR_lepJet/F");
   outputTree->Branch("ptRel_lepJet",&ptRel_lepJet,"ptRel_lepJet/F");
   outputTree->Branch("MT_lepMet",&MT_lepMet,"MT_lepMet/F");
   outputTree->Branch("deltaR_lepJets",&deltaR_lepJets);
   outputTree->Branch("deltaR_lepBJets",&deltaR_lepBJets);
   outputTree->Branch("deltaR_lepAK8s",&deltaR_lepAK8s);
   outputTree->Branch("muIsLoose_singleLepCalc",&muIsLoose_singleLepCalc);
   outputTree->Branch("muIsMedium_singleLepCalc",&muIsMedium_singleLepCalc);
   outputTree->Branch("muIsMediumPrompt_singleLepCalc",&muIsMediumPrompt_singleLepCalc);
   outputTree->Branch("muIsTight_singleLepCalc",&muIsTight_singleLepCalc);
   outputTree->Branch("AK8JetPt_BestCalc",&AK8JetPt_BestCalc);
   outputTree->Branch("AK8JetEta_BestCalc",&AK8JetEta_BestCalc);
   outputTree->Branch("AK8JetPhi_BestCalc",&AK8JetPhi_BestCalc);
   outputTree->Branch("AK8JetEnergy_BestCalc",&AK8JetEnergy_BestCalc);
   outputTree->Branch("AK8JetCSV_BestCalc",&AK8JetCSV_BestCalc);
   outputTree->Branch("dnn_QCD_BestCalc",&dnn_QCD_BestCalc);
   outputTree->Branch("dnn_Top_BestCalc",&dnn_Top_BestCalc);
   outputTree->Branch("dnn_Higgs_BestCalc",&dnn_Higgs_BestCalc);
   outputTree->Branch("dnn_Z_BestCalc",&dnn_Z_BestCalc);
   outputTree->Branch("dnn_W_BestCalc",&dnn_W_BestCalc);
   outputTree->Branch("maxProb_JetSubCalc",&maxProb_JetSubCalc);
   outputTree->Branch("dnn_largest_BestCalc",&dnn_largest_BestCalc);
   outputTree->Branch("bDisc_BestCalc",&bDisc_BestCalc);
   outputTree->Branch("bDisc1_BestCalc",&bDisc1_BestCalc);
   outputTree->Branch("bDisc2_BestCalc",&bDisc2_BestCalc);
   outputTree->Branch("et_BestCalc",&et_BestCalc);
   outputTree->Branch("eta_BestCalc",&eta_BestCalc);
   outputTree->Branch("mass_BestCalc",&mass_BestCalc);
   outputTree->Branch("SDmass_BestCalc",&SDmass_BestCalc);
   outputTree->Branch("tau32_BestCalc",&tau32_BestCalc);
   outputTree->Branch("tau21_BestCalc",&tau21_BestCalc);
   outputTree->Branch("q_BestCalc",&q_BestCalc);
   outputTree->Branch("m1234_jet_BestCalc",&m1234_jet_BestCalc);
   outputTree->Branch("m12_jet_BestCalc",&m12_jet_BestCalc);
   outputTree->Branch("m23_jet_BestCalc",&m23_jet_BestCalc);
   outputTree->Branch("m13_jet_BestCalc",&m13_jet_BestCalc);
   outputTree->Branch("m1234top_BestCalc",&m1234top_BestCalc);
   outputTree->Branch("m12top_BestCalc",&m12top_BestCalc);
   outputTree->Branch("m23top_BestCalc",&m23top_BestCalc);
   outputTree->Branch("m13top_BestCalc",&m13top_BestCalc);
   outputTree->Branch("m1234W_BestCalc",&m1234W_BestCalc);
   outputTree->Branch("m12W_BestCalc",&m12W_BestCalc);
   outputTree->Branch("m23W_BestCalc",&m23W_BestCalc);
   outputTree->Branch("m13W_BestCalc",&m13W_BestCalc);
   outputTree->Branch("m1234Z_BestCalc",&m1234Z_BestCalc);
   outputTree->Branch("m12Z_BestCalc",&m12Z_BestCalc);
   outputTree->Branch("m23Z_BestCalc",&m23Z_BestCalc);
   outputTree->Branch("m13Z_BestCalc",&m13Z_BestCalc);
   outputTree->Branch("m1234H_BestCalc",&m1234H_BestCalc);
   outputTree->Branch("m12H_BestCalc",&m12H_BestCalc);
   outputTree->Branch("m23H_BestCalc",&m23H_BestCalc);
   outputTree->Branch("m13H_BestCalc",&m13H_BestCalc);
   outputTree->Branch("pzOverp_top_BestCalc",&pzOverp_top_BestCalc);
   outputTree->Branch("pzOverp_W_BestCalc",&pzOverp_W_BestCalc);
   outputTree->Branch("pzOverp_Z_BestCalc",&pzOverp_Z_BestCalc);
   outputTree->Branch("pzOverp_H_BestCalc",&pzOverp_H_BestCalc);
   outputTree->Branch("pzOverp_jet_BestCalc",&pzOverp_jet_BestCalc);
   outputTree->Branch("Njets_top_BestCalc",&Njets_top_BestCalc);
   outputTree->Branch("Njets_W_BestCalc",&Njets_W_BestCalc);
   outputTree->Branch("Njets_Z_BestCalc",&Njets_Z_BestCalc);
   outputTree->Branch("Njets_H_BestCalc",&Njets_H_BestCalc);
   outputTree->Branch("Njets_jet_BestCalc",&Njets_jet_BestCalc);
   outputTree->Branch("Njets_orig_BestCalc",&Njets_orig_BestCalc);
   outputTree->Branch("dnn_B_DeepAK8Calc",&dnn_B_DeepAK8Calc);
   outputTree->Branch("dnn_J_DeepAK8Calc",&dnn_J_DeepAK8Calc);
   outputTree->Branch("dnn_W_DeepAK8Calc",&dnn_W_DeepAK8Calc);
   outputTree->Branch("dnn_Z_DeepAK8Calc",&dnn_Z_DeepAK8Calc);
   outputTree->Branch("dnn_H_DeepAK8Calc",&dnn_H_DeepAK8Calc);
   outputTree->Branch("dnn_T_DeepAK8Calc",&dnn_T_DeepAK8Calc);
   outputTree->Branch("dnn_largest_DeepAK8Calc",&dnn_T_DeepAK8Calc);
   outputTree->Branch("decorr_largest_DeepAK8Calc",&decorr_T_DeepAK8Calc);
   outputTree->Branch("decorr_B_DeepAK8Calc",&decorr_B_DeepAK8Calc);
   outputTree->Branch("decorr_J_DeepAK8Calc",&decorr_J_DeepAK8Calc);
   outputTree->Branch("decorr_W_DeepAK8Calc",&decorr_W_DeepAK8Calc);
   outputTree->Branch("decorr_Z_DeepAK8Calc",&decorr_Z_DeepAK8Calc);
   outputTree->Branch("decorr_H_DeepAK8Calc",&decorr_H_DeepAK8Calc);
   outputTree->Branch("decorr_T_DeepAK8Calc",&decorr_T_DeepAK8Calc);
   //outputTree->Branch("AK8JetDeepCSVb_singleLepCalc",&AK8JetDeepCSVb_singleLepCalc);
   //outputTree->Branch("AK8JetDeepCSVbb_singleLepCalc",&AK8JetDeepCSVbb_singleLepCalc);
   //outputTree->Branch("AK8JetDeepCSVc_singleLepCalc",&AK8JetDeepCSVc_singleLepCalc);
   //outputTree->Branch("AK8JetDeepCSVudsg_singleLepCalc",&AK8JetDeepCSVudsg_singleLepCalc);
   outputTree->Branch("theJetAK8SDSubjetHFlav_JetSubCalc",&theJetAK8SDSubjetHFlav_JetSubCalc);
   outputTree->Branch("elIsTightBarrel_singleLepCalc",&elIsTightBarrel_singleLepCalc,"elIsTightBarrel_singleLepCalc/F");
   outputTree->Branch("elIsMediumBarrel_singleLepCalc",&elIsTightBarrel_singleLepCalc,"elIsMediumBarrel_singleLepCalc/F");
   outputTree->Branch("elIsLooseBarrel_singleLepCalc",&elIsTightBarrel_singleLepCalc,"elIsLooseBarrel_singleLepCalc/F");
   outputTree->Branch("elIsVetoBarrel_singleLepCalc",&elIsTightBarrel_singleLepCalc,"elIsVetoBarrel_singleLepCalc/F");
   outputTree->Branch("elIsTightEndCap_singleLepCalc",&elIsTightBarrel_singleLepCalc,"elIsTightEndCap_singleLepCalc/F");
   outputTree->Branch("elIsMediumEndCap_singleLepCalc",&elIsTightBarrel_singleLepCalc,"elIsMediumEndCap_singleLepCalc/F");
   outputTree->Branch("elIsLooseEndCap_singleLepCalc",&elIsTightBarrel_singleLepCalc,"elIsLooseEndCap_singleLepCalc/F");
   outputTree->Branch("elIsVetoEndCap_singleLepCalc",&elIsTightBarrel_singleLepCalc,"elIsVetoEndCap_singleLepCalc/F");

   outputTree->Branch("theJetAK8Truth_JetSubCalc_PtOrdered",&theJetAK8Truth_JetSubCalc_PtOrdered);

   outputTree->Branch("Tprime1_BEST_Mass",&Tprime1_BEST_Mass);
   outputTree->Branch("Tprime2_BEST_Mass",&Tprime2_BEST_Mass);
   outputTree->Branch("Tprime1_BEST_Pt",&Tprime1_BEST_Pt);
   outputTree->Branch("Tprime2_BEST_Pt",&Tprime2_BEST_Pt);
   outputTree->Branch("Tprime1_BEST_Eta",&Tprime1_BEST_Eta);
   outputTree->Branch("Tprime2_BEST_Eta",&Tprime2_BEST_Eta);
   outputTree->Branch("Tprime1_BEST_Phi",&Tprime1_BEST_Phi);
   outputTree->Branch("Tprime2_BEST_Phi",&Tprime2_BEST_Phi);
   outputTree->Branch("TprimeAvg_BEST_Mass",&TprimeAvg_BEST_Mass);

   outputTree->Branch("Tprime1_DeepAK8_Mass",&Tprime1_DeepAK8_Mass);
   outputTree->Branch("Tprime2_DeepAK8_Mass",&Tprime2_DeepAK8_Mass);
   outputTree->Branch("Tprime1_DeepAK8_Pt",&Tprime1_DeepAK8_Pt);
   outputTree->Branch("Tprime2_DeepAK8_Pt",&Tprime2_DeepAK8_Pt);
   outputTree->Branch("Tprime1_DeepAK8_Eta",&Tprime1_DeepAK8_Eta);
   outputTree->Branch("Tprime2_DeepAK8_Eta",&Tprime2_DeepAK8_Eta);
   outputTree->Branch("Tprime1_DeepAK8_Phi",&Tprime1_DeepAK8_Phi);
   outputTree->Branch("Tprime2_DeepAK8_Phi",&Tprime2_DeepAK8_Phi);
   outputTree->Branch("TprimeAvg_DeepAK8_Mass",&TprimeAvg_DeepAK8_Mass);

   outputTree->Branch("Tprime1_DeepAK8_decorr_Mass",&Tprime1_DeepAK8_decorr_Mass);
   outputTree->Branch("Tprime2_DeepAK8_decorr_Mass",&Tprime2_DeepAK8_decorr_Mass);
   outputTree->Branch("Tprime1_DeepAK8_decorr_Pt",&Tprime1_DeepAK8_decorr_Pt);
   outputTree->Branch("Tprime2_DeepAK8_decorr_Pt",&Tprime2_DeepAK8_decorr_Pt);
   outputTree->Branch("Tprime1_DeepAK8_decorr_Eta",&Tprime1_DeepAK8_decorr_Eta);
   outputTree->Branch("Tprime2_DeepAK8_decorr_Eta",&Tprime2_DeepAK8_decorr_Eta);
   outputTree->Branch("Tprime1_DeepAK8_decorr_Phi",&Tprime1_DeepAK8_decorr_Phi);
   outputTree->Branch("Tprime2_DeepAK8_decorr_Phi",&Tprime2_DeepAK8_decorr_Phi);
   outputTree->Branch("TprimeAvg_DeepAK8_decorr_Mass",&TprimeAvg_DeepAK8_decorr_Mass);

   outputTree->Branch("isValidVLQDecayMode_BEST",&validDecay_BEST);
   outputTree->Branch("isValidVLQDecayMode_DeepAK8",&validDecay_DeepAK8);
   outputTree->Branch("isValidVLQDecayMode_DeepAK8_decorr",&validDecay_DeepAK8_decorr);

   outputTree->Branch("highPtAK8Jet1_SoftDropCorrectedMass",&highPtAK8Jet1_SoftDropCorrectedMass);
   outputTree->Branch("highPtAK8Jet2_SoftDropCorrectedMass",&highPtAK8Jet2_SoftDropCorrectedMass);
   outputTree->Branch("highPtAK8Jet3_SoftDropCorrectedMass",&highPtAK8Jet3_SoftDropCorrectedMass);

   outputTree->Branch("W_mass",&W_mass);

   // ******* HERE's an example histogram definition that could go in the file ********
   // ******* TH1D *name = new TH1D("name","title;x-axis title;y-axis title",nbins,xmin,xmax)

   // Tprime tagging denominator histogram
   TH1D *THBWeff_den = new TH1D("THBWeff_den",";T VLQ pT [GeV];N(THBW VLQ's from Tagging Algorithm) / N(true hadronic THBW VLQ's)", 50, 200, 2000); THBWeff_den->Sumw2();
   TH1D *THTHeff_den = new TH1D("THTHeff_den",";T VLQ pT [GeV];N(THTH VLQ's from Tagging Algorithm) / N(true hadronic THTH VLQ's)", 50, 200, 2000); THTHeff_den->Sumw2();
   TH1D *THTZeff_den = new TH1D("THTZeff_den",";T VLQ pT [GeV];N(THTZ VLQ's from Tagging Algorithm) / N(true hadronic THTZ VLQ's)", 50, 200, 2000); THTZeff_den->Sumw2();
   TH1D *TZBWeff_den = new TH1D("TZBWeff_den",";T VLQ pT [GeV];N(TZBW VLQ's from Tagging Algorithm) / N(true hadronic TZBW VLQ's)", 50, 200, 2000); TZBWeff_den->Sumw2();
   TH1D *TZTZeff_den = new TH1D("TZTZeff_den",";T VLQ pT [GeV];N(TZTZ VLQ's from Tagging Algorithm) / N(true hadronic TZTZ VLQ's)", 50, 200, 2000); TZTZeff_den->Sumw2();
   TH1D *BWBWeff_den = new TH1D("BWBWeff_den",";T VLQ pT [GeV];N(BWBW VLQ's from Tagging Algorithm) / N(true hadronic BWBW VLQ's)", 50, 200, 2000); BWBWeff_den->Sumw2();
   TH1D *BWTZeff_den = new TH1D("BWTZeff_den",";T VLQ pT [GeV];N(BWTZ VLQ's from Tagging Algorithm) / N(true hadronic BWTZ VLQ's)", 50, 200, 2000); BWTZeff_den->Sumw2();
   TH1D *BWTHeff_den = new TH1D("BWTHeff_den",";T VLQ pT [GeV];N(BWTH VLQ's from Tagging Algorithm) / N(true hadronic BWTH VLQ's)", 50, 200, 2000); BWTHeff_den->Sumw2();

   // Tprime mistagging denominator histogram
   TH1D *THBWeff_mistag_den = new TH1D("THBWeff_mistag_den",";T VLQ pT [GeV];N(THBW VLQ's from Tagging Algorithm) / N(true hadronic THBW VLQ's)", 50, 200, 2000); THBWeff_mistag_den->Sumw2();
   TH1D *THTHeff_mistag_den = new TH1D("THTHeff_mistag_den",";T VLQ pT [GeV];N(THTH VLQ's from Tagging Algorithm) / N(true hadronic THTH VLQ's)", 50, 200, 2000); THTHeff_mistag_den->Sumw2();
   TH1D *THTZeff_mistag_den = new TH1D("THTZeff_mistag_den",";T VLQ pT [GeV];N(THTZ VLQ's from Tagging Algorithm) / N(true hadronic THTZ VLQ's)", 50, 200, 2000); THTZeff_mistag_den->Sumw2();
   TH1D *TZBWeff_mistag_den = new TH1D("TZBWeff_mistag_den",";T VLQ pT [GeV];N(TZBW VLQ's from Tagging Algorithm) / N(true hadronic TZBW VLQ's)", 50, 200, 2000); TZBWeff_mistag_den->Sumw2();
   TH1D *TZTZeff_mistag_den = new TH1D("TZTZeff_mistag_den",";T VLQ pT [GeV];N(TZTZ VLQ's from Tagging Algorithm) / N(true hadronic TZTZ VLQ's)", 50, 200, 2000); TZTZeff_mistag_den->Sumw2();
   TH1D *BWBWeff_mistag_den = new TH1D("BWBWeff_mistag_den",";T VLQ pT [GeV];N(BWBW VLQ's from Tagging Algorithm) / N(true hadronic BWBW VLQ's)", 50, 200, 2000); BWBWeff_mistag_den->Sumw2();
   TH1D *BWTZeff_mistag_den = new TH1D("BWTZeff_mistag_den",";T VLQ pT [GeV];N(BWTZ VLQ's from Tagging Algorithm) / N(true hadronic BWTZ VLQ's)", 50, 200, 2000); BWTZeff_mistag_den->Sumw2();
   TH1D *BWTHeff_mistag_den = new TH1D("BWTHeff_mistag_den",";T VLQ pT [GeV];N(BWTH VLQ's from Tagging Algorithm) / N(true hadronic BWTH VLQ's)", 50, 200, 2000); BWTHeff_mistag_den->Sumw2();

   // Tagging Efficiency denominator histograms
   TH1D *Weff_den = new TH1D("Weff_den",";W boson pT [GeV];N(W from Tagging Algorithm) / N(true hadronic W)", 50, 200, 2000); Weff_den->Sumw2(); 
   TH1D *Zeff_den = new TH1D("Zeff_den",";Z boson pT [GeV];N(Z from Tagging Algorithm) / N(true hadronic Z)", 50, 200, 2000); Zeff_den->Sumw2(); 
   TH1D *Heff_den = new TH1D("Heff_den",";H boson pT [GeV];N(H from Tagging Algorithm) / N(true hadronic H)", 50, 200, 2000); Heff_den->Sumw2(); 
   TH1D *Teff_den = new TH1D("Teff_den",";T boson pT [GeV];N(T from Tagging Algorithm) / N(true hadronic T)", 50, 200, 2000); Teff_den->Sumw2(); 
   TH1D *Beff_den = new TH1D("Beff_den",";B boson pT [GeV];N(B from Tagging Algorithm) / N(true hadronic B)", 50, 200, 2000); Beff_den->Sumw2(); 
   TH1D *Jeff_den = new TH1D("Jeff_den",";J boson pT [GeV];N(J from Tagging Algorithm) / N(true hadronic J)", 50, 200, 2000); Jeff_den->Sumw2(); 

   // Mistagging efficiency denominator histograms
   TH1D *Weff_mistag_den = new TH1D("Weff_mistag_den",";W boson pT [GeV];N(W from Tagging Algorithm) / N(true hadronic W)", 50, 200, 2000); Weff_mistag_den->Sumw2();
   TH1D *Zeff_mistag_den = new TH1D("Zeff_mistag_den",";Z boson pT [GeV];N(Z from Tagging Algorithm) / N(true hadronic Z)", 50, 200, 2000); Zeff_mistag_den->Sumw2();
   TH1D *Heff_mistag_den = new TH1D("Heff_mistag_den",";H boson pT [GeV];N(H from Tagging Algorithm) / N(true hadronic H)", 50, 200, 2000); Heff_mistag_den->Sumw2();
   TH1D *Teff_mistag_den = new TH1D("Teff_mistag_den",";T boson pT [GeV];N(T from Tagging Algorithm) / N(true hadronic T)", 50, 200, 2000); Teff_mistag_den->Sumw2();
   TH1D *Beff_mistag_den = new TH1D("Beff_mistag_den",";B boson pT [GeV];N(B from Tagging Algorithm) / N(true hadronic B)", 50, 200, 2000); Beff_mistag_den->Sumw2();
   TH1D *Jeff_mistag_den = new TH1D("Jeff_mistag_den",";J boson pT [GeV];N(J from Tagging Algorithm) / N(true hadronic J)", 50, 200, 2000); Jeff_mistag_den->Sumw2();

   // Tprime agging efficiency numerator histgram
   TH1D *THBWeff_BEST_num = new TH1D("THBWeff_BEST_num",";THBW VLQ pT [GeV];N(THBW VLQ's from BEST) / N(true hadronic THBW VLQ's)", 50, 200, 2000); THBWeff_BEST_num->Sumw2();
   TH1D *THTHeff_BEST_num = new TH1D("THTHeff_BEST_num",";THTH VLQ pT [GeV];N(THTH VLQ's from BEST) / N(true hadronic THTH VLQ's)", 50, 200, 2000); THTHeff_BEST_num->Sumw2();
   TH1D *THTZeff_BEST_num = new TH1D("THTZeff_BEST_num",";THTZ VLQ pT [GeV];N(THTZ VLQ's from BEST) / N(true hadronic THTZ VLQ's)", 50, 200, 2000); THTZeff_BEST_num->Sumw2();
   TH1D *TZBWeff_BEST_num = new TH1D("TZBWeff_BEST_num",";TZBW VLQ pT [GeV];N(TZBW VLQ's from BEST) / N(true hadronic TZBW VLQ's)", 50, 200, 2000); TZBWeff_BEST_num->Sumw2();
   TH1D *TZTZeff_BEST_num = new TH1D("TZTZeff_BEST_num",";TZTZ VLQ pT [GeV];N(TZTZ VLQ's from BEST) / N(true hadronic TZTZ VLQ's)", 50, 200, 2000); TZTZeff_BEST_num->Sumw2();
   TH1D *BWBWeff_BEST_num = new TH1D("BWBWeff_BEST_num",";BWBW VLQ pT [GeV];N(BWBW VLQ's from BEST) / N(true hadronic BWBW VLQ's)", 50, 200, 2000); BWBWeff_BEST_num->Sumw2();
   TH1D *BWTZeff_BEST_num = new TH1D("BWTZeff_BEST_num",";BWTZ VLQ pT [GeV];N(BWTZ VLQ's from BEST) / N(true hadronic BWTZ VLQ's)", 50, 200, 2000); BWTZeff_BEST_num->Sumw2();
   TH1D *BWTHeff_BEST_num = new TH1D("BWTHeff_BEST_num",";BWTH VLQ pT [GeV];N(BWTH VLQ's from BEST) / N(true hadronic BWTH VLQ's)", 50, 200, 2000); BWTHeff_BEST_num->Sumw2();

   TH1D *THBWeff_DeepAK8_num = new TH1D("THBWeff_DeepAK8_num",";THBW VLQ pT [GeV];N(THBW VLQ's from DeepAK8) / N(true hadronic THBW VLQ's)", 50, 200, 2000); THBWeff_DeepAK8_num->Sumw2();
   TH1D *THTHeff_DeepAK8_num = new TH1D("THTHeff_DeepAK8_num",";THTH VLQ pT [GeV];N(THTH VLQ's from DeepAK8) / N(true hadronic THTH VLQ's)", 50, 200, 2000); THTHeff_DeepAK8_num->Sumw2();
   TH1D *THTZeff_DeepAK8_num = new TH1D("THTZeff_DeepAK8_num",";THTZ VLQ pT [GeV];N(THTZ VLQ's from DeepAK8) / N(true hadronic THTZ VLQ's)", 50, 200, 2000); THTZeff_DeepAK8_num->Sumw2();
   TH1D *TZBWeff_DeepAK8_num = new TH1D("TZBWeff_DeepAK8_num",";TZBW VLQ pT [GeV];N(TZBW VLQ's from DeepAK8) / N(true hadronic TZBW VLQ's)", 50, 200, 2000); TZBWeff_DeepAK8_num->Sumw2();
   TH1D *TZTZeff_DeepAK8_num = new TH1D("TZTZeff_DeepAK8_num",";TZTZ VLQ pT [GeV];N(TZTZ VLQ's from DeepAK8) / N(true hadronic TZTZ VLQ's)", 50, 200, 2000); TZTZeff_DeepAK8_num->Sumw2();
   TH1D *BWBWeff_DeepAK8_num = new TH1D("BWBWeff_DeepAK8_num",";BWBW VLQ pT [GeV];N(BWBW VLQ's from DeepAK8) / N(true hadronic BWBW VLQ's)", 50, 200, 2000); BWBWeff_DeepAK8_num->Sumw2();
   TH1D *BWTZeff_DeepAK8_num = new TH1D("BWTZeff_DeepAK8_num",";BWTZ VLQ pT [GeV];N(BWTZ VLQ's from DeepAK8) / N(true hadronic BWTZ VLQ's)", 50, 200, 2000); BWTZeff_DeepAK8_num->Sumw2();
   TH1D *BWTHeff_DeepAK8_num = new TH1D("BWTHeff_DeepAK8_num",";BWTH VLQ pT [GeV];N(BWTH VLQ's from DeepAK8) / N(true hadronic BWTH VLQ's)", 50, 200, 2000); BWTHeff_DeepAK8_num->Sumw2();

   TH1D *THBWeff_DeepAK8_decorr_num = new TH1D("THBWeff_DeepAK8_decorr_num",";THBW VLQ pT [GeV];N(THBW VLQ's from DeepAK8_decorr) / N(true hadronic THBW VLQ's)", 50, 200, 2000); THBWeff_DeepAK8_decorr_num->Sumw2();
   TH1D *THTHeff_DeepAK8_decorr_num = new TH1D("THTHeff_DeepAK8_decorr_num",";THTH VLQ pT [GeV];N(THTH VLQ's from DeepAK8_decorr) / N(true hadronic THTH VLQ's)", 50, 200, 2000); THTHeff_DeepAK8_decorr_num->Sumw2();
   TH1D *THTZeff_DeepAK8_decorr_num = new TH1D("THTZeff_DeepAK8_decorr_num",";THTZ VLQ pT [GeV];N(THTZ VLQ's from DeepAK8_decorr) / N(true hadronic THTZ VLQ's)", 50, 200, 2000); THTZeff_DeepAK8_decorr_num->Sumw2();
   TH1D *TZBWeff_DeepAK8_decorr_num = new TH1D("TZBWeff_DeepAK8_decorr_num",";TZBW VLQ pT [GeV];N(TZBW VLQ's from DeepAK8_decorr) / N(true hadronic TZBW VLQ's)", 50, 200, 2000); TZBWeff_DeepAK8_decorr_num->Sumw2();
   TH1D *TZTZeff_DeepAK8_decorr_num = new TH1D("TZTZeff_DeepAK8_decorr_num",";TZTZ VLQ pT [GeV];N(TZTZ VLQ's from DeepAK8_decorr) / N(true hadronic TZTZ VLQ's)", 50, 200, 2000); TZTZeff_DeepAK8_decorr_num->Sumw2();
   TH1D *BWBWeff_DeepAK8_decorr_num = new TH1D("BWBWeff_DeepAK8_decorr_num",";BWBW VLQ pT [GeV];N(BWBW VLQ's from DeepAK8_decorr) / N(true hadronic BWBW VLQ's)", 50, 200, 2000); BWBWeff_DeepAK8_decorr_num->Sumw2();
   TH1D *BWTZeff_DeepAK8_decorr_num = new TH1D("BWTZeff_DeepAK8_decorr_num",";BWTZ VLQ pT [GeV];N(BWTZ VLQ's from DeepAK8_decorr) / N(true hadronic BWTZ VLQ's)", 50, 200, 2000); BWTZeff_DeepAK8_decorr_num->Sumw2();
   TH1D *BWTHeff_DeepAK8_decorr_num = new TH1D("BWTHeff_DeepAK8_decorr_num",";BWTH VLQ pT [GeV];N(BWTH VLQ's from DeepAK8_decorr) / N(true hadronic BWTH VLQ's)", 50, 200, 2000); BWTHeff_DeepAK8_decorr_num->Sumw2();

   // Tagging efficiency numerator histograms
   TH1D *Weff_BEST_num = new TH1D("Weff_BEST_num",";W boson pT [GeV];N(W from BEST) / N(true hadronic W)", 50, 200, 2000); Weff_BEST_num->Sumw2(); 
   TH1D *Zeff_BEST_num = new TH1D("Zeff_BEST_num",";Z boson pT [GeV];N(Z from BEST) / N(true hadronic Z)", 50, 200, 2000); Zeff_BEST_num->Sumw2();
   TH1D *Heff_BEST_num = new TH1D("Heff_BEST_num",";H boson pT [GeV];N(H from BEST) / N(true hadronic H)", 50, 200, 2000); Heff_BEST_num->Sumw2();
   TH1D *Teff_BEST_num = new TH1D("Teff_BEST_num",";T boson pT [GeV];N(T from BEST) / N(true hadronic T)", 50, 200, 2000); Teff_BEST_num->Sumw2();
   TH1D *Beff_BEST_num = new TH1D("Beff_BEST_num",";B boson pT [GeV];N(B from BEST) / N(true hadronic B)", 50, 200, 2000); Beff_BEST_num->Sumw2();
   TH1D *Jeff_BEST_num = new TH1D("Jeff_BEST_num",";J boson pT [GeV];N(J from BEST) / N(true hadronic J)", 50, 200, 2000); Jeff_BEST_num->Sumw2();

   TH1D *Weff_DeepAK8_decorr_num = new TH1D("Weff_DeepAK8_decorr_num",";W boson pT [GeV];N(W from DeepAK8_decorr) / N(true hadronic W)", 50, 200, 2000); Weff_DeepAK8_decorr_num->Sumw2();
   TH1D *Zeff_DeepAK8_decorr_num = new TH1D("Zeff_DeepAK8_decorr_num",";Z boson pT [GeV];N(Z from DeepAK8_decorr) / N(true hadronic Z)", 50, 200, 2000); Zeff_DeepAK8_decorr_num->Sumw2();
   TH1D *Heff_DeepAK8_decorr_num = new TH1D("Heff_DeepAK8_decorr_num",";H boson pT [GeV];N(H from DeepAK8_decorr) / N(true hadronic H)", 50, 200, 2000); Heff_DeepAK8_decorr_num->Sumw2();
   TH1D *Teff_DeepAK8_decorr_num = new TH1D("Teff_DeepAK8_decorr_num",";T boson pT [GeV];N(T from DeepAK8_decorr) / N(true hadronic T)", 50, 200, 2000); Teff_DeepAK8_decorr_num->Sumw2();
   TH1D *Beff_DeepAK8_decorr_num = new TH1D("Beff_DeepAK8_decorr_num",";B boson pT [GeV];N(B from DeepAK8_decorr) / N(true hadronic B)", 50, 200, 2000); Beff_DeepAK8_decorr_num->Sumw2();
   TH1D *Jeff_DeepAK8_decorr_num = new TH1D("Jeff_DeepAK8_decorr_num",";J boson pT [GeV];N(J from DeepAK8_decorr) / N(true hadronic J)", 50, 200, 2000); Jeff_DeepAK8_decorr_num->Sumw2();

   TH1D *Weff_DeepAK8_num = new TH1D("Weff_DeepAK8_num",";W boson pT [GeV];N(W from DeepAK8) / N(true hadronic W)", 50, 200, 2000); Weff_DeepAK8_num->Sumw2();
   TH1D *Zeff_DeepAK8_num = new TH1D("Zeff_DeepAK8_num",";Z boson pT [GeV];N(Z from DeepAK8) / N(true hadronic Z)", 50, 200, 2000); Zeff_DeepAK8_num->Sumw2();
   TH1D *Heff_DeepAK8_num = new TH1D("Heff_DeepAK8_num",";H boson pT [GeV];N(H from DeepAK8) / N(true hadronic H)", 50, 200, 2000); Heff_DeepAK8_num->Sumw2();
   TH1D *Teff_DeepAK8_num = new TH1D("Teff_DeepAK8_num",";T boson pT [GeV];N(T from DeepAK8) / N(true hadronic T)", 50, 200, 2000); Teff_DeepAK8_num->Sumw2();
   TH1D *Beff_DeepAK8_num = new TH1D("Beff_DeepAK8_num",";B boson pT [GeV];N(B from DeepAK8) / N(true hadronic B)", 50, 200, 2000); Beff_DeepAK8_num->Sumw2();
   TH1D *Jeff_DeepAK8_num = new TH1D("Jeff_DeepAK8_num",";J boson pT [GeV];N(J from DeepAK8) / N(true hadronic J)", 50, 200, 2000); Jeff_DeepAK8_num->Sumw2();

   TH1D *WZeff_JetSub_num = new TH1D("WZeff_JetSub_num",";W and Z boson pT [GeV];N(W and Z from JetSub) / N(true hadronic W and Z)", 50, 200, 2000); WZeff_JetSub_num->Sumw2();
   TH1D *Heff_JetSub_num = new TH1D("Heff_JetSub_num",";H boson pT [GeV];N(H from JetSub) / N(true hadronic H)", 50, 200, 2000); Heff_JetSub_num->Sumw2();
   TH1D *Teff_JetSub_num = new TH1D("Teff_JetSub_num",";T boson pT [GeV];N(T from JetSub) / N(true hadronic T)", 50, 200, 2000); Teff_JetSub_num->Sumw2();
   TH1D *Beff_JetSub_num = new TH1D("Beff_JetSub_num",";B boson pT [GeV];N(B from JetSub) / N(true hadronic B)", 50, 200, 2000); Beff_JetSub_num->Sumw2();
   TH1D *Jeff_JetSub_num = new TH1D("Jeff_JetSub_num",";J boson pT [GeV];N(J from JetSub) / N(true hadronic J)", 50, 200, 2000); Jeff_JetSub_num->Sumw2();

   // Tprime agging efficiency numerator histgram
   TH1D *THBWeff_mistag_BEST_num = new TH1D("THBWeff_mistag_BEST_num",";THBW VLQ pT [GeV];N(THBW VLQ's from BEST) / N(true hadronic THBW VLQ's)", 50, 200, 2000); THBWeff_mistag_BEST_num->Sumw2();
   TH1D *THTHeff_mistag_BEST_num = new TH1D("THTHeff_mistag_BEST_num",";THTH VLQ pT [GeV];N(THTH VLQ's from BEST) / N(true hadronic THTH VLQ's)", 50, 200, 2000); THTHeff_mistag_BEST_num->Sumw2();
   TH1D *THTZeff_mistag_BEST_num = new TH1D("THTZeff_mistag_BEST_num",";THTZ VLQ pT [GeV];N(THTZ VLQ's from BEST) / N(true hadronic THTZ VLQ's)", 50, 200, 2000); THTZeff_mistag_BEST_num->Sumw2();
   TH1D *TZBWeff_mistag_BEST_num = new TH1D("TZBWeff_mistag_BEST_num",";TZBW VLQ pT [GeV];N(TZBW VLQ's from BEST) / N(true hadronic TZBW VLQ's)", 50, 200, 2000); TZBWeff_mistag_BEST_num->Sumw2();
   TH1D *TZTZeff_mistag_BEST_num = new TH1D("TZTZeff_mistag_BEST_num",";TZTZ VLQ pT [GeV];N(TZTZ VLQ's from BEST) / N(true hadronic TZTZ VLQ's)", 50, 200, 2000); TZTZeff_mistag_BEST_num->Sumw2();
   TH1D *BWBWeff_mistag_BEST_num = new TH1D("BWBWeff_mistag_BEST_num",";BWBW VLQ pT [GeV];N(BWBW VLQ's from BEST) / N(true hadronic BWBW VLQ's)", 50, 200, 2000); BWBWeff_mistag_BEST_num->Sumw2();
   TH1D *BWTZeff_mistag_BEST_num = new TH1D("BWTZeff_mistag_BEST_num",";BWTZ VLQ pT [GeV];N(BWTZ VLQ's from BEST) / N(true hadronic BWTZ VLQ's)", 50, 200, 2000); BWTZeff_mistag_BEST_num->Sumw2();
   TH1D *BWTHeff_mistag_BEST_num = new TH1D("BWTHeff_mistag_BEST_num",";BWTH VLQ pT [GeV];N(BWTH VLQ's from BEST) / N(true hadronic BWTH VLQ's)", 50, 200, 2000); BWTHeff_mistag_BEST_num->Sumw2();

   TH1D *THBWeff_mistag_DeepAK8_num = new TH1D("THBWeff_mistag_DeepAK8_num",";THBW VLQ pT [GeV];N(THBW VLQ's from DeepAK8) / N(true hadronic THBW VLQ's)", 50, 200, 2000); THBWeff_mistag_DeepAK8_num->Sumw2();
   TH1D *THTHeff_mistag_DeepAK8_num = new TH1D("THTHeff_mistag_DeepAK8_num",";THTH VLQ pT [GeV];N(THTH VLQ's from DeepAK8) / N(true hadronic THTH VLQ's)", 50, 200, 2000); THTHeff_mistag_DeepAK8_num->Sumw2();
   TH1D *THTZeff_mistag_DeepAK8_num = new TH1D("THTZeff_mistag_DeepAK8_num",";THTZ VLQ pT [GeV];N(THTZ VLQ's from DeepAK8) / N(true hadronic THTZ VLQ's)", 50, 200, 2000); THTZeff_mistag_DeepAK8_num->Sumw2();
   TH1D *TZBWeff_mistag_DeepAK8_num = new TH1D("TZBWeff_mistag_DeepAK8_num",";TZBW VLQ pT [GeV];N(TZBW VLQ's from DeepAK8) / N(true hadronic TZBW VLQ's)", 50, 200, 2000); TZBWeff_mistag_DeepAK8_num->Sumw2();
   TH1D *TZTZeff_mistag_DeepAK8_num = new TH1D("TZTZeff_mistag_DeepAK8_num",";TZTZ VLQ pT [GeV];N(TZTZ VLQ's from DeepAK8) / N(true hadronic TZTZ VLQ's)", 50, 200, 2000); TZTZeff_mistag_DeepAK8_num->Sumw2();
   TH1D *BWBWeff_mistag_DeepAK8_num = new TH1D("BWBWeff_mistag_DeepAK8_num",";BWBW VLQ pT [GeV];N(BWBW VLQ's from DeepAK8) / N(true hadronic BWBW VLQ's)", 50, 200, 2000); BWBWeff_mistag_DeepAK8_num->Sumw2();
   TH1D *BWTZeff_mistag_DeepAK8_num = new TH1D("BWTZeff_mistag_DeepAK8_num",";BWTZ VLQ pT [GeV];N(BWTZ VLQ's from DeepAK8) / N(true hadronic BWTZ VLQ's)", 50, 200, 2000); BWTZeff_mistag_DeepAK8_num->Sumw2();
   TH1D *BWTHeff_mistag_DeepAK8_num = new TH1D("BWTHeff_mistag_DeepAK8_num",";BWTH VLQ pT [GeV];N(BWTH VLQ's from DeepAK8) / N(true hadronic BWTH VLQ's)", 50, 200, 2000); BWTHeff_mistag_DeepAK8_num->Sumw2();

   TH1D *THBWeff_mistag_DeepAK8_decorr_num = new TH1D("THBWeff_mistag_DeepAK8_decorr_num",";THBW VLQ pT [GeV];N(THBW VLQ's from DeepAK8_decorr) / N(true hadronic THBW VLQ's)", 50, 200, 2000); THBWeff_mistag_DeepAK8_decorr_num->Sumw2();
   TH1D *THTHeff_mistag_DeepAK8_decorr_num = new TH1D("THTHeff_mistag_DeepAK8_decorr_num",";THTH VLQ pT [GeV];N(THTH VLQ's from DeepAK8_decorr) / N(true hadronic THTH VLQ's)", 50, 200, 2000); THTHeff_mistag_DeepAK8_decorr_num->Sumw2();
   TH1D *THTZeff_mistag_DeepAK8_decorr_num = new TH1D("THTZeff_mistag_DeepAK8_decorr_num",";THTZ VLQ pT [GeV];N(THTZ VLQ's from DeepAK8_decorr) / N(true hadronic THTZ VLQ's)", 50, 200, 2000); THTZeff_mistag_DeepAK8_decorr_num->Sumw2();
   TH1D *TZBWeff_mistag_DeepAK8_decorr_num = new TH1D("TZBWeff_mistag_DeepAK8_decorr_num",";TZBW VLQ pT [GeV];N(TZBW VLQ's from DeepAK8_decorr) / N(true hadronic TZBW VLQ's)", 50, 200, 2000); TZBWeff_mistag_DeepAK8_decorr_num->Sumw2();
   TH1D *TZTZeff_mistag_DeepAK8_decorr_num = new TH1D("TZTZeff_mistag_DeepAK8_decorr_num",";TZTZ VLQ pT [GeV];N(TZTZ VLQ's from DeepAK8_decorr) / N(true hadronic TZTZ VLQ's)", 50, 200, 2000); TZTZeff_mistag_DeepAK8_decorr_num->Sumw2();
   TH1D *BWBWeff_mistag_DeepAK8_decorr_num = new TH1D("BWBWeff_mistag_DeepAK8_decorr_num",";BWBW VLQ pT [GeV];N(BWBW VLQ's from DeepAK8_decorr) / N(true hadronic BWBW VLQ's)", 50, 200, 2000); BWBWeff_mistag_DeepAK8_decorr_num->Sumw2();
   TH1D *BWTZeff_mistag_DeepAK8_decorr_num = new TH1D("BWTZeff_mistag_DeepAK8_decorr_num",";BWTZ VLQ pT [GeV];N(BWTZ VLQ's from DeepAK8_decorr) / N(true hadronic BWTZ VLQ's)", 50, 200, 2000); BWTZeff_mistag_DeepAK8_decorr_num->Sumw2();
   TH1D *BWTHeff_mistag_DeepAK8_decorr_num = new TH1D("BWTHeff_mistag_DeepAK8_decorr_num",";BWTH VLQ pT [GeV];N(BWTH VLQ's from DeepAK8_decorr) / N(true hadronic BWTH VLQ's)", 50, 200, 2000); BWTHeff_mistag_DeepAK8_decorr_num->Sumw2();

   // Mistagging efficiency numerator histograms
   TH1D *Weff_mistag_BEST_num = new TH1D("Weff_mistag_BEST_num",";W boson pT [GeV];N(W from BEST) / N(true hadronic W)", 50, 200, 2000); Weff_mistag_BEST_num->Sumw2(); 
   TH1D *Zeff_mistag_BEST_num = new TH1D("Zeff_mistag_BEST_num",";Z boson pT [GeV];N(Z from BEST) / N(true hadronic Z)", 50, 200, 2000); Zeff_mistag_BEST_num->Sumw2();
   TH1D *Heff_mistag_BEST_num = new TH1D("Heff_mistag_BEST_num",";H boson pT [GeV];N(H from BEST) / N(true hadronic H)", 50, 200, 2000); Heff_mistag_BEST_num->Sumw2();
   TH1D *Teff_mistag_BEST_num = new TH1D("Teff_mistag_BEST_num",";T boson pT [GeV];N(T from BEST) / N(true hadronic T)", 50, 200, 2000); Teff_mistag_BEST_num->Sumw2();
   TH1D *Beff_mistag_BEST_num = new TH1D("Beff_mistag_BEST_num",";B boson pT [GeV];N(B from BEST) / N(true hadronic B)", 50, 200, 2000); Beff_mistag_BEST_num->Sumw2();
   TH1D *Jeff_mistag_BEST_num = new TH1D("Jeff_mistag_BEST_num",";J boson pT [GeV];N(J from BEST) / N(true hadronic J)", 50, 200, 2000); Jeff_mistag_BEST_num->Sumw2();

   TH1D *Weff_mistag_DeepAK8_decorr_num = new TH1D("Weff_mistag_DeepAK8_decorr_num",";W boson pT [GeV];N(W from DeepAK8_decorr) / N(true hadronic W)", 50, 200, 2000); Weff_mistag_DeepAK8_decorr_num->Sumw2();
   TH1D *Zeff_mistag_DeepAK8_decorr_num = new TH1D("Zeff_mistag_DeepAK8_decorr_num",";Z boson pT [GeV];N(Z from DeepAK8_decorr) / N(true hadronic Z)", 50, 200, 2000); Zeff_mistag_DeepAK8_decorr_num->Sumw2();
   TH1D *Heff_mistag_DeepAK8_decorr_num = new TH1D("Heff_mistag_DeepAK8_decorr_num",";H boson pT [GeV];N(H from DeepAK8_decorr) / N(true hadronic H)", 50, 200, 2000); Heff_mistag_DeepAK8_decorr_num->Sumw2();
   TH1D *Teff_mistag_DeepAK8_decorr_num = new TH1D("Teff_mistag_DeepAK8_decorr_num",";T boson pT [GeV];N(T from DeepAK8_decorr) / N(true hadronic T)", 50, 200, 2000); Teff_mistag_DeepAK8_decorr_num->Sumw2();
   TH1D *Beff_mistag_DeepAK8_decorr_num = new TH1D("Beff_mistag_DeepAK8_decorr_num",";B boson pT [GeV];N(B from DeepAK8_decorr) / N(true hadronic B)", 50, 200, 2000); Beff_mistag_DeepAK8_decorr_num->Sumw2();
   TH1D *Jeff_mistag_DeepAK8_decorr_num = new TH1D("Jeff_mistag_DeepAK8_decorr_num",";J boson pT [GeV];N(J from DeepAK8_decorr) / N(true hadronic J)", 50, 200, 2000); Jeff_mistag_DeepAK8_decorr_num->Sumw2();

   TH1D *Weff_mistag_DeepAK8_num = new TH1D("Weff_mistag_DeepAK8_num",";W boson pT [GeV];N(W from DeepAK8) / N(true hadronic W)", 50, 200, 2000); Weff_mistag_DeepAK8_num->Sumw2();
   TH1D *Zeff_mistag_DeepAK8_num = new TH1D("Zeff_mistag_DeepAK8_num",";Z boson pT [GeV];N(Z from DeepAK8) / N(true hadronic Z)", 50, 200, 2000); Zeff_mistag_DeepAK8_num->Sumw2();
   TH1D *Heff_mistag_DeepAK8_num = new TH1D("Heff_mistag_DeepAK8_num",";H boson pT [GeV];N(H from DeepAK8) / N(true hadronic H)", 50, 200, 2000); Heff_mistag_DeepAK8_num->Sumw2();
   TH1D *Teff_mistag_DeepAK8_num = new TH1D("Teff_mistag_DeepAK8_num",";T boson pT [GeV];N(T from DeepAK8) / N(true hadronic T)", 50, 200, 2000); Teff_mistag_DeepAK8_num->Sumw2();
   TH1D *Beff_mistag_DeepAK8_num = new TH1D("Beff_mistag_DeepAK8_num",";B boson pT [GeV];N(B from DeepAK8) / N(true hadronic B)", 50, 200, 2000); Beff_mistag_DeepAK8_num->Sumw2();
   TH1D *Jeff_mistag_DeepAK8_num = new TH1D("Jeff_mistag_DeepAK8_num",";J boson pT [GeV];N(J from DeepAK8) / N(true hadronic J)", 50, 200, 2000); Jeff_mistag_DeepAK8_num->Sumw2();

   TH1D *WZeff_mistag_JetSub_num = new TH1D("WZeff_mistag_JetSub_num",";W and Z boson pT [GeV];N(W and Z from JetSub) / N(true hadronic W and Z)", 50, 200, 2000); WZeff_mistag_JetSub_num->Sumw2();
   TH1D *Heff_mistag_JetSub_num = new TH1D("Heff_mistag_JetSub_num",";H boson pT [GeV];N(H from JetSub) / N(true hadronic H)", 50, 200, 2000); Heff_mistag_JetSub_num->Sumw2();
   TH1D *Teff_mistag_JetSub_num = new TH1D("Teff_mistag_JetSub_num",";T boson pT [GeV];N(T from JetSub) / N(true hadronic T)", 50, 200, 2000); Teff_mistag_JetSub_num->Sumw2();
   TH1D *Beff_mistag_JetSub_num = new TH1D("Beff_mistag_JetSub_num",";B boson pT [GeV];N(B from JetSub) / N(true hadronic B)", 50, 200, 2000); Beff_mistag_JetSub_num->Sumw2();
   TH1D *Jeff_mistag_JetSub_num = new TH1D("Jeff_mistag_JetSub_num",";J boson pT [GeV];N(J from JetSub) / N(true hadronic J)", 50, 200, 2000); Jeff_mistag_JetSub_num->Sumw2();

   //Tprime2 Mass Histograms
   TH1D *Tprime2_BEST_Mass_hist = new TH1D("Tprime2_BEST_Mass_hist",";Number of entries;Tprime2 mass [GeV]",50,800,2000); Tprime2_BEST_Mass_hist->Sumw2();
   TH1D *Tprime2_DeepAK8_Mass_hist = new TH1D("Tprime2_DeepAK8_Mass_hist",";Number of entries;Tprime2 mass [GeV]",50,800,2000); Tprime2_DeepAK8_Mass_hist->Sumw2();
   TH1D *Tprime2_DeepAK8_decorr_Mass_hist = new TH1D("Tprime2_DeepAK8_decorr_Mass_hist",";Number of entries;Tprime2 mass [GeV]",50,800,2000); Tprime2_DeepAK8_decorr_Mass_hist->Sumw2();
   TH1D *Tprime2_JetSub_Mass_hist = new TH1D("Tprime2_JetSub_Mass_hist",";Number of entries;Tprime2 mass [GeV]",50,800,2000); Tprime2_JetSub_Mass_hist->Sumw2();

   TH2D *confusion_num_BEST = new TH2D("confusion_num_BEST","",6,0,6,6,0,6);
   TH2D *confusion_num_DeepAK8 = new TH2D("confusion_num_DeepAK8","",6,0,6,6,0,6);
   TH2D *confusion_num_DeepAK8_decorr = new TH2D("confusion_num_DeepAK8_decorr","",6,0,6,6,0,6);
   TH2D *confusion_num_JetSub = new TH2D("confusion_num_JetSub","",6,0,6,6,0,6);
   TH2D *confusion_den = new TH2D("confusion_den","",6,0,6,6,0,6);

  // ----------------------------------------------------------------------------
  // Define and initialize objects / cuts / efficiencies
  // ----------------------------------------------------------------------------



   // basic cuts
   float metCut=0;
   int   njetsCut=0;
   float JetLeadPtCut=0;
   float JetSubLeadPtCut=0;
   float lepPtCut=0;
   float elEtaCut=2.5;
   float muEtaCut=2.4;
   float jetEtaCut=2.4;
   float ak8EtaCut=2.4;
   float jetPtCut=30;

   // counters
   int npass_ThreeJets    = 0;
   int npass_trigger      = 0;
   int npass_mu500        = 0;
   int npass_met          = 0;
   int npass_njets        = 0;
   int npass_nHjets       = 0;
   int npass_JetLeadPt    = 0;
   int npass_JetSubLeadPt = 0;
   int npass_lepPt        = 0;
   int npass_ElEta        = 0;
   int npass_MuEta        = 0;
   int npass_all          = 0;
   int Nelectrons         = 0;
   int Nmuons             = 0;

   // Lorentz vectors
   TLorentzVector jet_lv;
   TLorentzVector bjet_lv;
   TLorentzVector wjet1_lv;
   TLorentzVector tjet1_lv;
   TLorentzVector lepton_lv;
   TLorentzVector ak8_lv;
   

   // Pileup distributions -- ReReco Data vs Moriond17MC
   double pileup_central[75] = {3.603e-01, 9.378e-01, 1.201e+00, 9.651e-01, 1.112e+00, 1.162e+00, 7.847e-01, 4.960e-01, 7.422e-01, 8.839e-01, 9.662e-01, 1.071e+00, 1.124e+00, 1.175e+00, 1.203e+00, 1.208e+00, 1.200e+00, 1.182e+00, 1.144e+00, 1.096e+00, 1.065e+00, 1.051e+00, 1.052e+00, 1.051e+00, 1.050e+00, 1.057e+00, 1.072e+00, 1.083e+00, 1.095e+00, 1.108e+00, 1.094e+00, 1.084e+00, 1.042e+00, 9.850e-01, 9.095e-01, 8.196e-01, 7.159e-01, 6.107e-01, 5.032e-01, 4.052e-01, 3.092e-01, 2.285e-01, 1.636e-01, 1.133e-01, 7.738e-02, 5.090e-02, 3.180e-02, 2.013e-02, 1.226e-02, 7.425e-03, 4.389e-03, 2.614e-03, 1.572e-03, 9.679e-04, 7.333e-04, 6.786e-04, 7.342e-04, 9.346e-04, 1.346e-03, 1.888e-03, 3.248e-03, 3.966e-03, 4.872e-03, 5.119e-03, 5.452e-03, 5.338e-03, 5.112e-03, 4.397e-03, 4.023e-03, 3.359e-03, 2.987e-03, 2.770e-03, 2.278e-03, 1.982e-03, 1.765e-03};

   // Polynominals for WJets HT scaling
   TF1 *poly2 = new TF1("poly2","max([6],[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x + [5]*x*x*x*x*x)",100,5000);
   poly2->SetParameter(0,    0.998174);  
   poly2->SetParameter(1, 8.40861e-05); 
   poly2->SetParameter(2,-6.63274e-07);
   poly2->SetParameter(3, 4.09272e-10); 
   poly2->SetParameter(4,-9.50233e-14); 
   poly2->SetParameter(5, 7.59648e-18); 
   poly2->SetParameter(6,0.402806);
   
   TF1 *poly2U = new TF1("poly2U","max([6],[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x + [5]*x*x*x*x*x)",100,5000);
   poly2U->SetParameter(0,    0.998164);  
   poly2U->SetParameter(1, 8.51652e-05); 
   poly2U->SetParameter(2,-6.62919e-07);
   poly2U->SetParameter(3,  4.1205e-10); 
   poly2U->SetParameter(4,-9.57795e-14); 
   poly2U->SetParameter(5, 7.67371e-18); 
   poly2U->SetParameter(6,0.454456);
   
   TF1 *poly2D = new TF1("poly2D","max([6],[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x + [5]*x*x*x*x*x)",100,5000);
   poly2D->SetParameter(0,    0.998183);  
   poly2D->SetParameter(1, 8.30069e-05); 
   poly2D->SetParameter(2,-6.63629e-07);
   poly2D->SetParameter(3, 4.06495e-10); 
   poly2D->SetParameter(4,-9.42671e-14); 
   poly2D->SetParameter(5, 7.51924e-18); 
   poly2D->SetParameter(6,0.351156);

   
  // ----------------------------------------------------------------------------
  // RUN THE EVENT LOOP
  // ----------------------------------------------------------------------------

   cout << "RUN CONFIG: isMC = " << isMC << endl;
   cout << "isSig = " << isSig << ", SigMass = " << SigMass << endl;
   cout << "For W's: isTT = " << isTT << ", isSTt = " << isSTt << ", isSTtW = " << isSTtW << endl;
   cout << "Fot jets & PDF: isTOP = " << isTOP << ", isMadgraphBkg = " << isMadgraphBkg << endl;
   
   Long64_t nentries = inputTree->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = inputTree->GetEntry(jentry);   nbytes += nb;
      if (Cut(ientry) != 1) continue;
      
      //      if (ientry > 5000) continue;
      
      if(jentry % 1000 ==0) std::cout<<"Completed "<<jentry<<" out of "<<nentries<<" events"<<std::endl;

      // ----------------------------------------------------------------------------
      // Filter input file by mass or decay
      // ----------------------------------------------------------------------------



      if(isTTincMtt0to700 && ttbarMass_TTbarMassCalc >= 700.) continue;
      if(isTTincMtt0to1000 && ttbarMass_TTbarMassCalc >= 1000.) continue;
      if(isTTincMtt700to1000 && (ttbarMass_TTbarMassCalc < 700. || ttbarMass_TTbarMassCalc >= 1000.)) continue;
      if(isTTincMtt1000toInf && ttbarMass_TTbarMassCalc < 1000.) continue;
      if(outBWBW && !isBWBW_TpTpCalc) continue;
      if(outTZBW && !isTZBW_TpTpCalc) continue;
      if(outTHBW && !isTHBW_TpTpCalc) continue;
      if(outTZTH && !isTZTH_TpTpCalc) continue;
      if(outTZTZ && !isTZTZ_TpTpCalc) continue;
      if(outTHTH && !isTHTH_TpTpCalc) continue;
      if(outTWTW && !isTWTW_TpTpCalc) continue;
      if(outBZTW && !isBZTW_TpTpCalc) continue;
      if(outBHTW && !isBHTW_TpTpCalc) continue;
      if(outBZBH && !isBZBH_TpTpCalc) continue;
      if(outBZBZ && !isBZBZ_TpTpCalc) continue;
      if(outBHBH && !isBHBH_TpTpCalc) continue;

      // ----------------------------------------------------------------------------
      // Assign as electron or muon event
      // ----------------------------------------------------------------------------
      // **** If we had saveLooseLeps == True in TTsinglelep_MC_cfg.py then this needs work!
      // **** Choose an electron and muon ID for "tight" and find events with only 1 tight el or mu by that definition
      isElectron = 0;
      isMuon = 0;
      if(elPt_singleLepCalc->size()==0 && muPt_singleLepCalc->size()==0){std::cout << "got no leptons, something wrong" << std::endl; continue;}
      if(elPt_singleLepCalc->size()>0 && muPt_singleLepCalc->size()>0) std::cout << "got el and mu, something wrong" << std::endl;
      if(elPt_singleLepCalc->size()>1 || muPt_singleLepCalc->size()>1) std::cout << "got more than one el or mu, something wrong" << std::endl;
      if(elPt_singleLepCalc->size()>0 && muPt_singleLepCalc->size()==0) {isElectron = 1; isMuon = 0;}
      if(elPt_singleLepCalc->size()==0 && muPt_singleLepCalc->size()>0) {isElectron = 0; isMuon = 1;}
      if(isElectron==0 && isMuon==0){std::cout << "got no leptons, something wrong" << std::endl; continue;}

      if(isSM && isElectron == 1) continue;
      if(isSE && isMuon == 1) continue;

      double leppt = 0;
      double lepeta = 0;
      if(isElectron){leppt = elPt_singleLepCalc->at(0); lepeta = elEta_singleLepCalc->at(0);}
      if(isMuon){leppt = muPt_singleLepCalc->at(0); lepeta = muEta_singleLepCalc->at(0);}

      // ----------------------------------------------------------------------------
      // Pileup weight calculation
      // ----------------------------------------------------------------------------

      pileupWeight = 1.0;
	
      if(nTrueInteractions_singleLepCalc > 74) nTrueInteractions_singleLepCalc = 74;
      pileupWeight = pileup_central[nTrueInteractions_singleLepCalc];

      // ----------------------------------------------------------------------------
      // Assign Lepton scale factor or efficiency weights, save trigger pass/fail
      // ----------------------------------------------------------------------------

      DataPastTrigger = 0;
      MCPastTrigger = 0;

      // *** SAM, put some if the WPTight triggers in these strings, check other names, same below in Data section
      if(isMC){ //MC triggers check
	if(isElectron){
	  std::string string_a = "Ele15_IsoVVVL_PFHT450";
	  std::string string_b = "Ele15_IsoVVVL_PFHT450_PFMET50";
	  std::string string_c = "Ele50_IsoVVVL_PFHT450";
	  std::string string_d = "Ele15_IsoVVVL_PFHT600";
	  std::string string_ORa = "Ele35_WPTight_Gsf";
	  std::string string_ORb = "Ele38_WPTight_Gsf";
	  for(unsigned int itrig=0; itrig < vsSelMCTriggersEl_singleLepCalc->size(); itrig++){
	    if(vsSelMCTriggersEl_singleLepCalc->at(itrig).find(string_a) != std::string::npos && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersEl_singleLepCalc->at(itrig).find(string_b) != std::string::npos && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
            if(vsSelMCTriggersEl_singleLepCalc->at(itrig).find(string_c) != std::string::npos && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
            if(vsSelMCTriggersEl_singleLepCalc->at(itrig).find(string_d) != std::string::npos && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersEl_singleLepCalc->at(itrig).find(string_ORa) != std::string::npos && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersEl_singleLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	  }
	}
	if(isMuon){
	  // ***** SAM, check these names, same below in Data section
	  std::string string_a = "Mu15_IsoVVVL_PFHT450";
	  std::string string_b = "Mu15_IsoVVVL_PFHT450_PFMET50";
	  std::string string_c = "Mu15_IsoVVVL_PFHT450_CaloBTagCSV_4p5";
	  std::string string_d = "Mu50_IsoVVVL_PFHT450";
	  std::string string_e = "Mu15_IsoVVVL_PFHT600";
	  std::string string_ORb = "Mu50";
	  std::string string_ORc = "TkMu55";
	  for(unsigned int itrig=0; itrig < vsSelMCTriggersMu_singleLepCalc->size(); itrig++){
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_a) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_b) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
            if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_c) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
            if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_d) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
            if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_e) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_ORc) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	  }
	}
	DataPastTrigger = 1;
      }
      else{ //Data triggers check
	if(isElectron){
	  std::string string_a = "Ele15_IsoVVVL_PFHT450";
	  std::string string_b = "Ele15_IsoVVVL_PFHT450_PFMET50";
	  std::string string_c = "Ele50_IsoVVVL_PFHT450";
	  std::string string_d = "Ele15_IsoVVVL_PFHT600";
	  std::string string_ORa = "Ele35_WPTight_Gsf";
	  std::string string_ORb = "Ele38_WPTight_Gsf";
	  for(unsigned int itrig=0; itrig < vsSelTriggersEl_singleLepCalc->size(); itrig++){
	    if(vsSelTriggersEl_singleLepCalc->at(itrig).find(string_a) != std::string::npos && viSelTriggersEl_singleLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig).find(string_b) != std::string::npos && viSelTriggersEl_singleLepCalc->at(itrig) > 0) DataPastTrigger = 1;
            if(vsSelTriggersEl_singleLepCalc->at(itrig).find(string_c) != std::string::npos && viSelTriggersEl_singleLepCalc->at(itrig) > 0) DataPastTrigger = 1;
            if(vsSelTriggersEl_singleLepCalc->at(itrig).find(string_d) != std::string::npos && viSelTriggersEl_singleLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig).find(string_ORa) != std::string::npos && viSelTriggersEl_singleLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelTriggersEl_singleLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	  }
	}



	if(isMuon){
	  std::string string_a = "Mu15_IsoVVVL_PFHT450";
	  std::string string_b = "Mu15_IsoVVVL_PFHT450_PFMET50";
	  std::string string_c = "Mu15_IsoVVVL_PFHT450_CaloBTagCSV_4p5";
	  std::string string_d = "Mu50_IsoVVVL_PFHT450";
	  std::string string_e = "Mu15_IsoVVVL_PFHT600";
	  std::string string_ORb = "Mu50";
	  std::string string_ORc = "TkMu55";
	  for(unsigned int itrig=0; itrig < vsSelTriggersMu_singleLepCalc->size(); itrig++){
	    if(vsSelTriggersMu_singleLepCalc->at(itrig).find(string_a) != std::string::npos && viSelTriggersMu_singleLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig).find(string_b) != std::string::npos && viSelTriggersMu_singleLepCalc->at(itrig) > 0) DataPastTrigger = 1;
            if(vsSelTriggersMu_singleLepCalc->at(itrig).find(string_c) != std::string::npos && viSelTriggersMu_singleLepCalc->at(itrig) > 0) DataPastTrigger = 1;
            if(vsSelTriggersMu_singleLepCalc->at(itrig).find(string_d) != std::string::npos && viSelTriggersMu_singleLepCalc->at(itrig) > 0) DataPastTrigger = 1;
            if(vsSelTriggersMu_singleLepCalc->at(itrig).find(string_e) != std::string::npos && viSelTriggersMu_singleLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelTriggersMu_singleLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig).find(string_ORc) != std::string::npos && viSelTriggersMu_singleLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	  }
	}
	MCPastTrigger = 1;
      }
      
      if(DataPastTrigger) npass_trigger+=1;

      // ----------------------------------------------------------------------------
      // Generator-level HT correction
      // ----------------------------------------------------------------------------      

      HTSF_Pol = 1;

      if(isMadgraphBkg){
	// Piece-wise splice with a flat line. Uncertainty from upper/lower error bar fits
	HTSF_Pol = poly2->Eval(HTfromHEPUEP_singleLepCalc);
      }

      // ----------------------------------------------------------------------------
      // Loop over AK4 jets for calculations and pt ordering pair
      // ----------------------------------------------------------------------------

      NJets_JetSubCalc = 0;
      AK4HT = 0;
      vector<pair<double,int>> jetptindpair;

      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc->size(); ijet++){

	// ----------------------------------------------------------------------------
	// Basic cuts
	// ----------------------------------------------------------------------------

	if(theJetPt_JetSubCalc->at(ijet) < jetPtCut || fabs(theJetEta_JetSubCalc->at(ijet)) > jetEtaCut) continue;

	if(isMC){
	  // ----------------------------------------------------------------------------
	  // Counts and pt ordering pair
	  // ----------------------------------------------------------------------------

	  jetptindpair.push_back(std::make_pair(theJetPt_JetSubCalc->at(ijet),ijet));
	  NJets_JetSubCalc+=1;
	  AK4HT+=theJetPt_JetSubCalc->at(ijet);
	  
	}else{
	  jetptindpair.push_back(std::make_pair(theJetPt_JetSubCalc->at(ijet),ijet));
	  NJets_JetSubCalc+=1;
	  AK4HT+=theJetPt_JetSubCalc->at(ijet);
	}
      }
	
      // ----------------------------------------------------------------------------
      // Apply pt ordering to AK4 vectors
      // ----------------------------------------------------------------------------
      //****** ANY OTHER NEW JET VECTOR (DeepCSV?) to order by pT go here



      std::sort(jetptindpair.begin(), jetptindpair.end(), comparepair);
      theJetPt_JetSubCalc_PtOrdered.clear();
      theJetEta_JetSubCalc_PtOrdered.clear();
      theJetPhi_JetSubCalc_PtOrdered.clear();
      theJetEnergy_JetSubCalc_PtOrdered.clear();
      theJetCSVb_JetSubCalc_PtOrdered.clear();
      theJetCSVbb_JetSubCalc_PtOrdered.clear();
      //theJetCSVc_JetSubCalc_PtOrdered.clear();
      //theJetCSVudsg_JetSubCalc_PtOrdered.clear();
      theJetHFlav_JetSubCalc_PtOrdered.clear();
      theJetPFlav_JetSubCalc_PtOrdered.clear();
      theJetBTag_JetSubCalc_PtOrdered.clear();
      for(unsigned int ijet=0; ijet < jetptindpair.size(); ijet++){
      	theJetPt_JetSubCalc_PtOrdered.push_back(theJetPt_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetEta_JetSubCalc_PtOrdered.push_back(theJetEta_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetPhi_JetSubCalc_PtOrdered.push_back(theJetPhi_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetEnergy_JetSubCalc_PtOrdered.push_back(theJetEnergy_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetCSVb_JetSubCalc_PtOrdered.push_back(theJetCSVb_JetSubCalc->at(jetptindpair[ijet].second));
	theJetCSVbb_JetSubCalc_PtOrdered.push_back(theJetCSVbb_JetSubCalc->at(jetptindpair[ijet].second));
	//theJetCSVc_JetSubCalc_PtOrdered.push_back(theJetCSVc_JetSubCalc->at(jetptindpair[ijet].second));
	//theJetCSVudsg_JetSubCalc_PtOrdered.push_back(theJetCSVudsg_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetHFlav_JetSubCalc_PtOrdered.push_back(theJetHFlav_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetPFlav_JetSubCalc_PtOrdered.push_back(theJetPFlav_JetSubCalc->at(jetptindpair[ijet].second));
	theJetBTag_JetSubCalc_PtOrdered.push_back(theJetBTag_JetSubCalc->at(jetptindpair[ijet].second));
      }



      // ----------------------------------------------------------------------------
      // Apply kinematic cuts
      // ----------------------------------------------------------------------------
	                
      int isPastNJetsCut = 0;
      if(NJets_JetSubCalc >= njetsCut){npass_njets+=1;isPastNJetsCut=1;}
      
      int isPastJetLeadPtCut = 0;
      if(theJetPt_JetSubCalc_PtOrdered.size() > 0 && theJetPt_JetSubCalc_PtOrdered[0] > JetLeadPtCut){npass_JetLeadPt+=1;isPastJetLeadPtCut=1;}
      
      int isPastJetSubLeadPtCut = 0;
      if(theJetPt_JetSubCalc_PtOrdered.size() > 1 && theJetPt_JetSubCalc_PtOrdered[1] > JetSubLeadPtCut){npass_JetSubLeadPt+=1;isPastJetSubLeadPtCut=1;}
      
      int isPastMETcut = 0;
      if(corr_met_singleLepCalc > metCut){npass_met+=1;isPastMETcut=1;}

      int isPastLepPtCut = 0;
      if(leppt > lepPtCut){npass_lepPt+=1;isPastLepPtCut=1;}
      
      int isPastElEtaCut = 0;
      int isPastMuEtaCut = 0;
      if(isElectron && fabs(lepeta) < elEtaCut){npass_ElEta+=1;isPastElEtaCut=1;}
      if(isMuon && fabs(lepeta) < muEtaCut){npass_MuEta+=1;isPastMuEtaCut=1;}
      if(isElectron){Nelectrons+=1;}
      if(isMuon){Nmuons+=1;}
      
      AK4HTpMETpLepPt = 0;
      AK4HTpMETpLepPt = AK4HT + corr_met_singleLepCalc + leppt;



      // ----------------------------------------------------------------------------
      // Loop over AK8 jets for calculations and pt ordering pair
      // ----------------------------------------------------------------------------

      NJetsAK8_JetSubCalc = 0;
      vector<pair<double,int>> jetak8ptindpair;      
      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc->size(); ijet++){
	
        // ----------------------------------------------------------------------------                                  
        // Basic cuts                                                                                                    
        // ----------------------------------------------------------------------------                                  
	
        if(fabs(theJetAK8Eta_JetSubCalc->at(ijet)) > ak8EtaCut) continue;
        if(theJetAK8NjettinessTau1_JetSubCalc->at(ijet)==0) continue;
        if(theJetAK8NjettinessTau2_JetSubCalc->at(ijet)==0) continue;
        if(theJetAK8CHSTau1_JetSubCalc->at(ijet)==0) continue;
        if(theJetAK8CHSTau2_JetSubCalc->at(ijet)==0) continue;

        // ----------------------------------------------------------------------------                                  
        // Counter and pt ordering pair                                                                                  
        // ----------------------------------------------------------------------------                                  
	
        NJetsAK8_JetSubCalc += 1;
        jetak8ptindpair.push_back(std::make_pair(theJetAK8Pt_JetSubCalc->at(ijet),ijet));
	
      }



      // ----------------------------------------------------------------------------
      // Skip failing events
      // ----------------------------------------------------------------------------


      if(!(isPastMETcut && isPastNJetsCut && isPastJetLeadPtCut && isPastLepPtCut && (isPastElEtaCut || isPastMuEtaCut) && isPastJetSubLeadPtCut)) continue;
      npass_all+=1;

      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /////////////// ONLY ON SELECTED EVENTS ////////////////////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////      

      // ----------------------------------------------------------------------------
      // Combine lepton variables into one set
      // ----------------------------------------------------------------------------

      // ******** MAYBE NEED SOME OTHERS?
      if(isElectron){
	leptonPt_singleLepCalc = leppt;
	leptonEta_singleLepCalc = lepeta;
	leptonPhi_singleLepCalc = elPhi_singleLepCalc->at(0);
	leptonEnergy_singleLepCalc = elEnergy_singleLepCalc->at(0);
	leptonMiniIso_singleLepCalc = elMiniIso_singleLepCalc->at(0);
	leptonMVAValue_singleLepCalc = elMVAValue_singleLepCalc->at(0);
      }
      if(isMuon){
	leptonPt_singleLepCalc = leppt;
	leptonEta_singleLepCalc = lepeta;
	leptonPhi_singleLepCalc = muPhi_singleLepCalc->at(0);
	leptonEnergy_singleLepCalc = muEnergy_singleLepCalc->at(0);
	leptonMiniIso_singleLepCalc = muMiniIso_singleLepCalc->at(0);
	leptonMVAValue_singleLepCalc = -99.9;
      }

      // ----------------------------------------------------------------------------
      // Apply pt ordering to AK8 vectors 
      // ----------------------------------------------------------------------------



      // **** LOTS MORE TO ORDER PROBABLY. OR MAYBE WE DON'T NEED TO ORDER AT ALL.....
      //Pt ordering for AK8
      std::sort(jetak8ptindpair.begin(), jetak8ptindpair.end(), comparepair);

      maxProb_JetSubCalc_PtOrdered.clear();
      dnn_largest_BestCalc_PtOrdered.clear();
      dnn_largest_DeepAK8Calc_PtOrdered.clear();
      decorr_largest_DeepAK8Calc_PtOrdered.clear();
      theJetAK8DoubleB_JetSubCalc_PtOrdered.clear();
      theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.clear();
      theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered.clear();
      theJetAK8SDSubjetSize_JetSubCalc_PtOrdered.clear();
      theJetAK8Pt_JetSubCalc_PtOrdered.clear();
      theJetAK8Eta_JetSubCalc_PtOrdered.clear();
      theJetAK8Phi_JetSubCalc_PtOrdered.clear();
      theJetAK8Energy_JetSubCalc_PtOrdered.clear();
      theJetAK8Mass_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered.clear();
      theJetAK8SoftDropRaw_PtOrdered.clear();
      theJetAK8SoftDropCorr_PtOrdered.clear();
      theJetAK8SoftDrop_PtOrdered.clear();
      theJetAK8SDSubjetNCSVM_PtOrdered.clear();
      theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.clear();
      theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.clear();
      theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSTau1_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSTau2_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSTau3_JetSubCalc_PtOrdered.clear();
      for(unsigned int ijet=0; ijet < jetak8ptindpair.size(); ijet++){
	maxProb_JetSubCalc_PtOrdered.push_back(dnn_largest_BestCalc->at(jetak8ptindpair[ijet].second));
      	dnn_largest_BestCalc_PtOrdered.push_back(dnn_largest_BestCalc->at(jetak8ptindpair[ijet].second));
      	dnn_largest_DeepAK8Calc_PtOrdered.push_back(dnn_largest_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
      	decorr_largest_DeepAK8Calc_PtOrdered.push_back(decorr_largest_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
      	theJetAK8DoubleB_JetSubCalc_PtOrdered.push_back(theJetAK8DoubleB_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetIndex_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetIndex_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SDSubjetSize_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetSize_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Pt_JetSubCalc_PtOrdered.push_back(theJetAK8Pt_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Eta_JetSubCalc_PtOrdered.push_back(theJetAK8Eta_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Phi_JetSubCalc_PtOrdered.push_back(theJetAK8Phi_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Energy_JetSubCalc_PtOrdered.push_back(theJetAK8Energy_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Mass_JetSubCalc_PtOrdered.push_back(theJetAK8Mass_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered.push_back(theJetAK8CHSPrunedMass_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered.push_back(theJetAK8CHSSoftDropMass_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDropRaw_PtOrdered.push_back(theJetAK8SoftDropRaw_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDropCorr_PtOrdered.push_back(theJetAK8SoftDropCorr_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SoftDrop_PtOrdered.push_back(theJetAK8SoftDrop_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SDSubjetNCSVM_PtOrdered.push_back(theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau1_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau2_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau3_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8CHSTau1_JetSubCalc_PtOrdered.push_back(theJetAK8CHSTau1_JetSubCalc->at(jetak8ptindpair[ijet].second));      	
	theJetAK8CHSTau2_JetSubCalc_PtOrdered.push_back(theJetAK8CHSTau2_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8CHSTau3_JetSubCalc_PtOrdered.push_back(theJetAK8CHSTau3_JetSubCalc->at(jetak8ptindpair[ijet].second));
      }
      
      // ----------------------------------------------------------------------------
      // AK8 Jet - lepton associations, Top and W taggging
      // ----------------------------------------------------------------------------

      NJetsWtagged_0p6 = 0;
      NPuppiWtagged_0p55 = 0;
      NJetsWtagged_0p6_notTtagged = 0;
      NJetsTtagged_0p81 = 0;
      deltaR_lepAK8s.clear();
      minDR_lepAK8 = 1000;
      minDR_leadAK8otherAK8 = 1000;
      if(theJetAK8Pt_JetSubCalc_PtOrdered.size() < 1) minDR_lepAK8 = -99.0;      
      if(theJetAK8Pt_JetSubCalc_PtOrdered.size() < 2) minDR_leadAK8otherAK8 = -99.0;
      WJetLeadPt = -99.0;
      TJetLeadPt = -99.0;

      theJetAK8Wmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8Hmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8Zmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8Tmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8MatchedPt_JetSubCalc_PtOrdered.clear();
      theJetAK8Truth_JetSubCalc_PtOrdered.clear();

      wjet1_lv.SetPtEtaPhiM(0,0,0,0);
      tjet1_lv.SetPtEtaPhiM(0,0,0,0);
      ak8_lv.SetPtEtaPhiM(0,0,0,0);
      TLorentzVector leadak8;
      leadak8.SetPtEtaPhiM(0,0,0,0);

      for(int i = 0; i < 8; i++){
	NJetsWtagged_0p6_shifts.push_back(0);
	NPuppiWtagged_0p55_shifts.push_back(0);
	NJetsWtagged_0p6_notTtagged_shifts.push_back(0);
	NJetsTtagged_0p81_shifts.push_back(0);
	WJetLeadPt_shifts.push_back(-99.0);
	TJetLeadPt_shifts.push_back(-99.0);
      }

      NJetsH1btagged = 0;
      NJetsH2btagged = 0;
      NPuppiH1btagged = 0;
      NPuppiH2btagged = 0;
      TLorentzVector tempTLV;
      std::vector<TLorentzVector> HtagTLVs;
      std::vector<TLorentzVector> PHtagTLVs;
      
      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc_PtOrdered.size(); ijet++){

	// ----------------------------------------------------------------------------
	// AK8 - lepton and AK8 -- AK8 associations
	// ----------------------------------------------------------------------------
	
	ak8_lv.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),theJetAK8Energy_JetSubCalc_PtOrdered.at(ijet));
	if(ijet == 0) leadak8 = ak8_lv;
	deltaR_lepAK8s.push_back(lepton_lv.DeltaR(ak8_lv));
	if(lepton_lv.DeltaR(ak8_lv) < minDR_lepAK8) minDR_lepAK8 = lepton_lv.DeltaR(ak8_lv);
	if(ijet > 0){
	  float tempdr = leadak8.DeltaR(ak8_lv);
	  if(tempdr < minDR_leadAK8otherAK8){
	    minDR_leadAK8otherAK8 = tempdr;
	  }
	}



	// ----------------------------------------------------------------------------
	// W & top tagging on MC
	// ----------------------------------------------------------------------------
	
	float tau21 = theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.at(ijet)/theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.at(ijet);
	float tau32 = theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.at(ijet)/theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.at(ijet);


	// ------------------------------------------------------------------------------------------------------------------
	// MC Calculation first
	// ------------------------------------------------------------------------------------------------------------------

	if(isMC){
	  
	  // ------------------------------------------------------------------------------------------------------------------
	  // TRUTH MATCHING
	  // ------------------------------------------------------------------------------------------------------------------
	  float minDR = 1000;
	  float matchedPt= -99;
	  int matchedID = 0;
	  bool isWmatched = false;
	  bool isHmatched = false;
	  bool isZmatched = false;
	  bool isTmatched = false;
	  bool isJmatched = false;
	  bool isBmatched = false;
	  TLorentzVector trueW,d1,d2,d3;

	  for(unsigned int iW = 0; iW < HadronicVHtPt_JetSubCalc->size(); iW++){
	    trueW.SetPtEtaPhiE(HadronicVHtPt_JetSubCalc->at(iW),HadronicVHtEta_JetSubCalc->at(iW),HadronicVHtPhi_JetSubCalc->at(iW),HadronicVHtEnergy_JetSubCalc->at(iW));

	    if(ak8_lv.DeltaR(trueW) < minDR){
	      minDR = ak8_lv.DeltaR(trueW);
	      matchedPt = HadronicVHtPt_JetSubCalc->at(iW);
	      matchedID = abs(HadronicVHtID_JetSubCalc->at(iW));	      
	      d1.SetPtEtaPhiE(HadronicVHtD0Pt_JetSubCalc->at(iW),HadronicVHtD0Eta_JetSubCalc->at(iW),HadronicVHtD0Phi_JetSubCalc->at(iW),HadronicVHtD0E_JetSubCalc->at(iW));
	      d2.SetPtEtaPhiE(HadronicVHtD1Pt_JetSubCalc->at(iW),HadronicVHtD1Eta_JetSubCalc->at(iW),HadronicVHtD1Phi_JetSubCalc->at(iW),HadronicVHtD1E_JetSubCalc->at(iW));
	      d3.SetPtEtaPhiE(HadronicVHtD2Pt_JetSubCalc->at(iW),HadronicVHtD2Eta_JetSubCalc->at(iW),HadronicVHtD2Phi_JetSubCalc->at(iW),HadronicVHtD2E_JetSubCalc->at(iW));
	    }
   	  }	 
	  
	  bool WallDsInJet = false;
	  bool TallDsInJet = false;
	  if(matchedID != 6 && ak8_lv.DeltaR(d1) < 0.8 && ak8_lv.DeltaR(d2) < 0.8) WallDsInJet = true;
	  if(matchedID == 6 && ak8_lv.DeltaR(d1) < 0.8 && ak8_lv.DeltaR(d2) < 0.8 && ak8_lv.DeltaR(d3) < 0.8) TallDsInJet = true;
	  if(minDR < 0.8 && matchedID == 24 && WallDsInJet) isWmatched = true;
	  if(minDR < 0.8 && matchedID == 25 && WallDsInJet) isHmatched = true;
	  if(minDR < 0.8 && matchedID == 23 && WallDsInJet) isZmatched = true;
	  if(minDR < 0.8 && matchedID == 6 && TallDsInJet) isTmatched = true;

	  theJetAK8Wmatch_JetSubCalc_PtOrdered.push_back(isWmatched);
	  theJetAK8Hmatch_JetSubCalc_PtOrdered.push_back(isHmatched);
	  theJetAK8Zmatch_JetSubCalc_PtOrdered.push_back(isZmatched);
	  theJetAK8Tmatch_JetSubCalc_PtOrdered.push_back(isTmatched);
	  if(isWmatched || isZmatched || isHmatched || isTmatched) theJetAK8MatchedPt_JetSubCalc_PtOrdered.push_back(matchedPt);
	  else theJetAK8MatchedPt_JetSubCalc_PtOrdered.push_back(-99.0);

	  if (not isWmatched && not isZmatched && not isTmatched && not isHmatched) {
	    int firstsub = theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered.at(ijet);
	    int nsubs = theJetAK8SDSubjetSize_JetSubCalc_PtOrdered.at(ijet);
	    for(int isub = firstsub; isub < firstsub + nsubs; isub++){
	      if( theJetAK8SDSubjetHFlav_JetSubCalc->at(isub) == 5 ) isBmatched = true;
	    }
	    if ( not isBmatched ) isJmatched = true;
	  }

	  if(isJmatched) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(0);
	  if(isTmatched) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(1);
	  if(isHmatched) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(2);
	  if(isZmatched) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(3);
	  if(isWmatched) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(4);
	  if(isBmatched) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(5);

	  // ------------------------------------------------------------------------------------------------------------------
	  // FILLING HISTOGRAMS
	  // ------------------------------------------------------------------------------------------------------------------

	  if (isBmatched) {
	    confusion_den->Fill(0.0,0.0);
	    confusion_den->Fill(1.0,0.0);
	    confusion_den->Fill(2.0,0.0);
	    confusion_den->Fill(3.0,0.0);
	    confusion_den->Fill(4.0,0.0);
	    confusion_den->Fill(5.0,0.0); }
	  else if (isTmatched) {
	    confusion_den->Fill(0.0,1.0);
	    confusion_den->Fill(1.0,1.0);
	    confusion_den->Fill(2.0,1.0);
	    confusion_den->Fill(3.0,1.0);
	    confusion_den->Fill(4.0,1.0);
	    confusion_den->Fill(5.0,1.0); }
	  else if (isHmatched) {
	    confusion_den->Fill(0.0,2.0);
	    confusion_den->Fill(1.0,2.0);
	    confusion_den->Fill(2.0,2.0);
	    confusion_den->Fill(3.0,2.0);
	    confusion_den->Fill(4.0,2.0);
	    confusion_den->Fill(5.0,2.0); }
	  else if (isZmatched) {
	    confusion_den->Fill(0.0,3.0);
	    confusion_den->Fill(1.0,3.0);
	    confusion_den->Fill(2.0,3.0);
	    confusion_den->Fill(3.0,3.0);
	    confusion_den->Fill(4.0,3.0);
	    confusion_den->Fill(5.0,3.0); }
	  else if (isWmatched) {
	    confusion_den->Fill(0.0,4.0);
	    confusion_den->Fill(1.0,4.0);
	    confusion_den->Fill(2.0,4.0);
	    confusion_den->Fill(3.0,4.0);
	    confusion_den->Fill(4.0,4.0);
	    confusion_den->Fill(5.0,4.0); }
	  else {
	    confusion_den->Fill(0.0,5.0);
	    confusion_den->Fill(1.0,5.0);
	    confusion_den->Fill(2.0,5.0);
	    confusion_den->Fill(3.0,5.0);
	    confusion_den->Fill(4.0,5.0);
	    confusion_den->Fill(5.0,5.0); }

	  // 0 = J, 1 = T, 2 = H, 3 = Z, 4 = W, 5 = B
	  // BEST confusion matrix
	  if (dnn_largest_BestCalc_PtOrdered.at(ijet) == 0) { // J
	    if (isBmatched) confusion_num_BEST->Fill(0.0,0.0);
	    else if (isTmatched) confusion_num_BEST->Fill(0.0,1);
	    else if (isHmatched) confusion_num_BEST->Fill(0.0,2);
	    else if (isZmatched) confusion_num_BEST->Fill(0.0,3);
	    else if (isWmatched) confusion_num_BEST->Fill(0.0,4.0);
	    else confusion_num_BEST->Fill(0.0,5); }
	  else if (dnn_largest_BestCalc_PtOrdered.at(ijet) == 4) { // W
	    if (isBmatched) confusion_num_BEST->Fill(1,0.0);
	    else if (isTmatched) confusion_num_BEST->Fill(1,1);
	    else if (isHmatched) confusion_num_BEST->Fill(1,2);
	    else if (isZmatched) confusion_num_BEST->Fill(1,3);
	    else if (isWmatched) confusion_num_BEST->Fill(1,4.0);
	    else confusion_num_BEST->Fill(1,5); }
	  else if (dnn_largest_BestCalc_PtOrdered.at(ijet) == 3) { // Z
	    if (isBmatched) confusion_num_BEST->Fill(2,0.0);
	    else if (isTmatched) confusion_num_BEST->Fill(2,1);
	    else if (isHmatched) confusion_num_BEST->Fill(2,2);
	    else if (isZmatched) confusion_num_BEST->Fill(2,3);
	    else if (isWmatched) confusion_num_BEST->Fill(2,4);
	    else confusion_num_BEST->Fill(2,5); }
	  else if (dnn_largest_BestCalc_PtOrdered.at(ijet) == 2) { // H
	    if (isBmatched) confusion_num_BEST->Fill(3,0.0);
	    else if (isTmatched) confusion_num_BEST->Fill(3,1);
	    else if (isHmatched) confusion_num_BEST->Fill(3,2);
	    else if (isZmatched) confusion_num_BEST->Fill(3,3);
	    else if (isWmatched) confusion_num_BEST->Fill(3,4);
	    else confusion_num_BEST->Fill(3,5); }
	  else if (dnn_largest_BestCalc_PtOrdered.at(ijet) == 1) { // T
	    if (isBmatched) confusion_num_BEST->Fill(4,0.0);
	    else if (isTmatched) confusion_num_BEST->Fill(4,1);
	    else if (isHmatched) confusion_num_BEST->Fill(4,2);
	    else if (isZmatched) confusion_num_BEST->Fill(4,3);
	    else if (isWmatched) confusion_num_BEST->Fill(4,4);
	    else confusion_num_BEST->Fill(4,5); }
	  else {                                                  // B
	    if (isBmatched) confusion_num_BEST->Fill(5,0.0);
	    else if (isTmatched) confusion_num_BEST->Fill(5,1);
	    else if (isHmatched) confusion_num_BEST->Fill(5,2);
	    else if (isZmatched) confusion_num_BEST->Fill(5,3);
	    else if (isWmatched) confusion_num_BEST->Fill(5,4);
	    else confusion_num_BEST->Fill(5,5); }
	  
	  // DeepAK8 confusion matrix
	  if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 0.0) { // J
	    if (isBmatched) confusion_num_DeepAK8->Fill(0.0,0.0);
	    else if (isTmatched) confusion_num_DeepAK8->Fill(0.0,1);
	    else if (isHmatched) confusion_num_DeepAK8->Fill(0.0,2);
	    else if (isZmatched) confusion_num_DeepAK8->Fill(0.0,3);
	    else if (isWmatched) confusion_num_DeepAK8->Fill(0.0,4);
	    else confusion_num_DeepAK8->Fill(0.0,5); }
	  else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 4) { // W
	    if (isBmatched) confusion_num_DeepAK8->Fill(1,0.0);
	    else if (isTmatched) confusion_num_DeepAK8->Fill(1,1);
	    else if (isHmatched) confusion_num_DeepAK8->Fill(1,2);
	    else if (isZmatched) confusion_num_DeepAK8->Fill(1,3);
	    else if (isWmatched) confusion_num_DeepAK8->Fill(1,4);
	    else confusion_num_DeepAK8->Fill(1,5); }
	  else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 3) { //Z
	    if (isBmatched) confusion_num_DeepAK8->Fill(2,0.0);
	    else if (isTmatched) confusion_num_DeepAK8->Fill(2,1);
	    else if (isHmatched) confusion_num_DeepAK8->Fill(2,2);
	    else if (isZmatched) confusion_num_DeepAK8->Fill(2,3);
	    else if (isWmatched) confusion_num_DeepAK8->Fill(2,4);
	    else confusion_num_DeepAK8->Fill(2,5); }
	  else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 2) { //H
	    if (isBmatched) confusion_num_DeepAK8->Fill(3,0.0);
	    else if (isTmatched) confusion_num_DeepAK8->Fill(3,1);
	    else if (isHmatched) confusion_num_DeepAK8->Fill(3,2);
	    else if (isZmatched) confusion_num_DeepAK8->Fill(3,3);
	    else if (isWmatched) confusion_num_DeepAK8->Fill(3,4);
	    else confusion_num_DeepAK8->Fill(3,5); }
	  else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 1) { // T
	    if (isBmatched) confusion_num_DeepAK8->Fill(4,0.0);
	    else if (isTmatched) confusion_num_DeepAK8->Fill(4,1);
	    else if (isHmatched) confusion_num_DeepAK8->Fill(4,2);
	    else if (isZmatched) confusion_num_DeepAK8->Fill(4,3);
	    else if (isWmatched) confusion_num_DeepAK8->Fill(4,4);
	    else confusion_num_DeepAK8->Fill(4,5); }
	  else {                                                      // B
	    if (isBmatched) confusion_num_DeepAK8->Fill(5,0.0);
	    else if (isTmatched) confusion_num_DeepAK8->Fill(5,1);
	    else if (isHmatched) confusion_num_DeepAK8->Fill(5,2);
	    else if (isZmatched) confusion_num_DeepAK8->Fill(5,3);
	    else if (isWmatched) confusion_num_DeepAK8->Fill(5,4);
	    else confusion_num_DeepAK8->Fill(5,5); }
	  
	  // DeepAK8_decorr confusion matrix
	  if (decorr_largest_DeepAK8Calc_PtOrdered.at(ijet) == 0.0) { // J
	    if (isBmatched) confusion_num_DeepAK8_decorr->Fill(0.0,0.0);
	    else if (isTmatched) confusion_num_DeepAK8_decorr->Fill(0.0,1);
	    else if (isHmatched) confusion_num_DeepAK8_decorr->Fill(0.0,2);
	    else if (isZmatched) confusion_num_DeepAK8_decorr->Fill(0.0,3);
	    else if (isWmatched) confusion_num_DeepAK8_decorr->Fill(0.0,4);
	    else confusion_num_DeepAK8_decorr->Fill(0.0,5); }
	  else if (decorr_largest_DeepAK8Calc_PtOrdered.at(ijet) == 4) { // W
	    if (isBmatched) confusion_num_DeepAK8_decorr->Fill(1,0.0);
	    else if (isTmatched) confusion_num_DeepAK8_decorr->Fill(1,1);
	    else if (isHmatched) confusion_num_DeepAK8_decorr->Fill(1,2);
	    else if (isZmatched) confusion_num_DeepAK8_decorr->Fill(1,3);
	    else if (isWmatched) confusion_num_DeepAK8_decorr->Fill(1,4);
	    else confusion_num_DeepAK8_decorr->Fill(1,5); }
	  else if (decorr_largest_DeepAK8Calc_PtOrdered.at(ijet) == 3) { // Z
	    if (isBmatched) confusion_num_DeepAK8_decorr->Fill(2,0.0);
	    else if (isTmatched) confusion_num_DeepAK8_decorr->Fill(2,1);
	    else if (isHmatched) confusion_num_DeepAK8_decorr->Fill(2,2);
	    else if (isZmatched) confusion_num_DeepAK8_decorr->Fill(2,3);
	    else if (isWmatched) confusion_num_DeepAK8_decorr->Fill(2,4);
	    else confusion_num_DeepAK8_decorr->Fill(2,5); }
	  else if (decorr_largest_DeepAK8Calc_PtOrdered.at(ijet) == 2) { // H
	    if (isBmatched) confusion_num_DeepAK8_decorr->Fill(3,0.0);
	    else if (isTmatched) confusion_num_DeepAK8_decorr->Fill(3,1);
	    else if (isHmatched) confusion_num_DeepAK8_decorr->Fill(3,2);
	    else if (isZmatched) confusion_num_DeepAK8_decorr->Fill(3,3);
	    else if (isWmatched) confusion_num_DeepAK8_decorr->Fill(3,4);
	    else confusion_num_DeepAK8_decorr->Fill(3,5); }
	  else if (decorr_largest_DeepAK8Calc_PtOrdered.at(ijet) == 1) { // T
	    if (isBmatched) confusion_num_DeepAK8_decorr->Fill(4,0.0);
	    else if (isTmatched) confusion_num_DeepAK8_decorr->Fill(4,1);
	    else if (isHmatched) confusion_num_DeepAK8_decorr->Fill(4,2);
	    else if (isZmatched) confusion_num_DeepAK8_decorr->Fill(4,3);
	    else if (isWmatched) confusion_num_DeepAK8_decorr->Fill(4,4);
	    else confusion_num_DeepAK8_decorr->Fill(4,5); }
	  else {                                                          // B
	    if (isBmatched) confusion_num_DeepAK8_decorr->Fill(5,0.0);
	    else if (isTmatched) confusion_num_DeepAK8_decorr->Fill(5,1);
	    else if (isHmatched) confusion_num_DeepAK8_decorr->Fill(5,2);
	    else if (isZmatched) confusion_num_DeepAK8_decorr->Fill(5,3);
	    else if (isWmatched) confusion_num_DeepAK8_decorr->Fill(5,4);
	    else confusion_num_DeepAK8_decorr->Fill(5,5); }

	  //JetSub confusion matrix
	  if (theJetAK8SoftDropCorr_PtOrdered.at(ijet) < 105 && theJetAK8SoftDropCorr_PtOrdered.at(ijet) > 65 && tau21 < 0.55) { // W or Z
	    if (isBmatched) {
	      confusion_num_JetSub->Fill(1,0.0);
	      confusion_num_JetSub->Fill(2,0.0); }
	    else if (isTmatched) {
	      confusion_num_JetSub->Fill(1,1);
	      confusion_num_JetSub->Fill(2,1); }
	    else if (isHmatched) {
	      confusion_num_JetSub->Fill(1,2);
	      confusion_num_JetSub->Fill(2,2); }
	    else if (isZmatched) {
	      confusion_num_JetSub->Fill(1,3);
	      confusion_num_JetSub->Fill(2,3); }
	    else if (isWmatched) { 
	      confusion_num_JetSub->Fill(1,4);
	      confusion_num_JetSub->Fill(2,4); }
	    else {
	      confusion_num_JetSub->Fill(1,5);
	      confusion_num_JetSub->Fill(2,5); } }
	  else if (theJetAK8SoftDropCorr_PtOrdered.at(ijet) < 135 && theJetAK8SoftDropCorr_PtOrdered.at(ijet) > 105 && theJetAK8DoubleB_JetSubCalc_PtOrdered.at(ijet) > 0.6) { //H
	    if (isBmatched) confusion_num_JetSub->Fill(3,0);
	    else if (isTmatched) confusion_num_JetSub->Fill(3,1);
	    else if (isHmatched) confusion_num_JetSub->Fill(3,2);
	    else if (isZmatched) confusion_num_JetSub->Fill(3,3);
	    else if (isWmatched) confusion_num_JetSub->Fill(3,4);
	    else confusion_num_JetSub->Fill(3,5); } 
	  else if (theJetAK8SoftDropCorr_PtOrdered.at(ijet) > 105 && theJetAK8SoftDropCorr_PtOrdered.at(ijet) < 210 && tau32 < 0.65) { // T
	    if (isBmatched) confusion_num_JetSub->Fill(4,0);
	    else if (isTmatched) confusion_num_JetSub->Fill(4,1);
	    else if (isHmatched) confusion_num_JetSub->Fill(4,2);
	    else if (isZmatched) confusion_num_JetSub->Fill(4,3);
	    else if (isWmatched) confusion_num_JetSub->Fill(4,4);
	    else confusion_num_JetSub->Fill(4,5); }
	  else {                                                  // B
	    if (theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.at(ijet) > 0) {
	      if (isBmatched) confusion_num_JetSub->Fill(5,0);
	      else if (isTmatched) confusion_num_JetSub->Fill(5,1);
	      else if (isHmatched) confusion_num_JetSub->Fill(5,2);
	      else if (isZmatched) confusion_num_JetSub->Fill(5,3);
	      else if (isWmatched) confusion_num_JetSub->Fill(5,4);
	      else confusion_num_JetSub->Fill(5,5); }
	    if (theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.at(ijet) == 0) { // J
	      if (isBmatched) confusion_num_JetSub->Fill(0.0,0.0);
	      else if (isTmatched) confusion_num_JetSub->Fill(0.0,1.0);
	      else if (isHmatched) confusion_num_JetSub->Fill(0.0,2.0);
	      else if (isZmatched) confusion_num_JetSub->Fill(0.0,3.0);
	      else if (isWmatched) confusion_num_JetSub->Fill(0.0,4.0);
	      else confusion_num_JetSub->Fill(0.0,5.0); } }

	  // ***** EXAMPLE of filling denominators
	  if(isWmatched && matchedPt > 200) Weff_den->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
          else Weff_mistag_den->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
          if(isZmatched && matchedPt > 200) Zeff_den->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
          else Zeff_mistag_den->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
          if(isHmatched && matchedPt > 300) Heff_den->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
          else Heff_mistag_den->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
          if(isTmatched && matchedPt > 400) Teff_den->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
          else Teff_mistag_den->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));



          if(isBmatched) Beff_den->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
          else Beff_mistag_den->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
          if(isJmatched) Jeff_den->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
          else Jeff_mistag_den->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));


	
	  // Filling Numerators
	  if (dnn_largest_BestCalc_PtOrdered.at(ijet) == 4) {
	    if (isWmatched && matchedPt > 200) Weff_BEST_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Weff_mistag_BEST_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	  if (dnn_largest_BestCalc_PtOrdered.at(ijet) == 3) { 
	    if (isZmatched && matchedPt > 200) Zeff_BEST_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Zeff_mistag_BEST_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	  if (dnn_largest_BestCalc_PtOrdered.at(ijet) == 1) { 
	    if (isTmatched && matchedPt > 400) Teff_BEST_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Teff_mistag_BEST_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	  if (dnn_largest_BestCalc_PtOrdered.at(ijet) == 2) { 
	    if (isHmatched && matchedPt > 300) Heff_BEST_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Heff_mistag_BEST_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	  if (dnn_largest_BestCalc_PtOrdered.at(ijet) == 5) {
	    if (isBmatched) Beff_BEST_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Beff_mistag_BEST_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	  if (dnn_largest_BestCalc_PtOrdered.at(ijet) == 0) {
	    if (isJmatched) Jeff_BEST_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Jeff_mistag_BEST_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }


	  
	  if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 4) {
	    if (isWmatched && matchedPt > 200) Weff_DeepAK8_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Weff_mistag_DeepAK8_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	  if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 3) {
	    if (isZmatched && matchedPt > 200) Zeff_DeepAK8_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Zeff_mistag_DeepAK8_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	  if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 1) {
	    if (isTmatched && matchedPt > 400) Teff_DeepAK8_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Teff_mistag_DeepAK8_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	  if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 2) {
	    if (isHmatched && matchedPt > 300) Heff_DeepAK8_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Heff_mistag_DeepAK8_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	  if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 5) {
	    if (isBmatched) Beff_DeepAK8_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Beff_mistag_DeepAK8_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	  if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 0) {
	    if (isJmatched) Jeff_DeepAK8_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Jeff_mistag_DeepAK8_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }


	  
	  if (decorr_largest_DeepAK8Calc_PtOrdered.at(ijet) == 4) {
	    if (isWmatched && matchedPt > 200) Weff_DeepAK8_decorr_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Weff_mistag_DeepAK8_decorr_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	  if (decorr_largest_DeepAK8Calc_PtOrdered.at(ijet) == 3) {
	    if (isZmatched && matchedPt > 200) Zeff_DeepAK8_decorr_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Zeff_mistag_DeepAK8_decorr_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	  if (decorr_largest_DeepAK8Calc_PtOrdered.at(ijet) == 1) {
	    if (isTmatched && matchedPt > 400) Teff_DeepAK8_decorr_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Teff_mistag_DeepAK8_decorr_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	  if (decorr_largest_DeepAK8Calc_PtOrdered.at(ijet) == 2) {
	    if (isHmatched && matchedPt > 300) Heff_DeepAK8_decorr_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));	
	    else Heff_mistag_DeepAK8_decorr_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	  if (decorr_largest_DeepAK8Calc_PtOrdered.at(ijet) == 5) {
	    if (isBmatched) Beff_DeepAK8_decorr_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Beff_mistag_DeepAK8_decorr_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	  if (decorr_largest_DeepAK8Calc_PtOrdered.at(ijet) == 0) {
	    if (isJmatched) Jeff_DeepAK8_decorr_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Jeff_mistag_DeepAK8_decorr_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }



	  bool mark = true;
	  if (theJetAK8SoftDropCorr_PtOrdered.at(ijet) < 105 && theJetAK8SoftDropCorr_PtOrdered.at(ijet) > 65 && tau21 < 0.55) {
	    if ( (isWmatched || isZmatched) && matchedPt > 200) WZeff_JetSub_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else WZeff_mistag_JetSub_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    mark = false; }
	  if (theJetAK8SoftDropCorr_PtOrdered.at(ijet) < 135 && theJetAK8SoftDropCorr_PtOrdered.at(ijet) > 105 && theJetAK8DoubleB_JetSubCalc_PtOrdered.at(ijet) > 0.6) {
	    if (isHmatched && matchedPt > 300) Heff_JetSub_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Heff_mistag_JetSub_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    mark = false; }
	  if (theJetAK8SoftDropCorr_PtOrdered.at(ijet) > 105 && theJetAK8SoftDropCorr_PtOrdered.at(ijet) < 210 && tau32 < 0.65) {
	    if (isTmatched && matchedPt > 400) Teff_JetSub_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    else Teff_mistag_JetSub_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    mark = false; }
	  if (mark) { 
	    if (theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.at(ijet) > 0) {
	      if (isBmatched) Beff_JetSub_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	      else Beff_mistag_JetSub_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	    if (theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.at(ijet) == 0) {
	      if (isJmatched) Jeff_JetSub_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	      else Jeff_mistag_JetSub_num->Fill(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)); }
	  }



      

	  // // ------------------------------------------------------------------------------------------------------------------
	  // // TOP TAGGING
	  // // ------------------------------------------------------------------------------------------------------------------
	  // float topTau81SF = 1.0;
	  // double topTau81Eff = 1.0;
	    
	  // // Set the initial tagged/untagged state
	  // bool isTtagged = (massSD > 105) && (massSD < 220) && (tau32 < 0.81) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);
	  // if(isTtagged) NJetsTtagged_0p81 += 1;
	  
	  // // ------------------------------------------------------------------------------------------------------------------
	  // // Variable for top tagged jets
	  // // ------------------------------------------------------------------------------------------------------------------
	  
	  // if(isTtagged){
	  //   TJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet);
	  // }


	  // // ------------------------------------------------------------------------------------------------------------------
	  // // W TAGGING
	  // // ------------------------------------------------------------------------------------------------------------------
	  
	  // // Set the initial tagged/untagged state
	  // bool isWtagged = (mass > 65) && (mass < 105) && (tau21 < 0.6) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
	  // bool isPWtagged = (massPSD > 65) && (massPSD < 105) && (Ptau21 < 0.55) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
	  
	  // // Now increase the tag count in the right variable	  
	  // if(isWtagged){ 
	  //   NJetsWtagged_0p6 += 1;
	  //   NJetsWtagged_0p6_notTtagged += int(isWtagged)-int(isTtagged);
	  // }

	  // if(isPWtagged) NPuppiWtagged_0p55 += 1;	  
	    
	  // // ------------------------------------------------------------------------------------------------------------------
	  // // Variables for W tagged jets
	  // // ------------------------------------------------------------------------------------------------------------------
	  
	  // if(isWtagged){
	  //   if(NJetsWtagged_0p6 == 1){
	  //     WJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet);
	  //   }
	  // }
	}
	 
	// ------------------------------------------------------------------------------------------------------------------
	// DATA Calculation second
	// ------------------------------------------------------------------------------------------------------------------
	// else{
	  
	//   theJetAK8Wmatch_JetSubCalc_PtOrdered.push_back(0);
	//   theJetAK8Hmatch_JetSubCalc_PtOrdered.push_back(0);
	//   theJetAK8Zmatch_JetSubCalc_PtOrdered.push_back(0);
	//   theJetAK8Tmatch_JetSubCalc_PtOrdered.push_back(0);
	  
	//   bool isTtagged = (massSD > 105) && (massSD < 220) && (tau32 < 0.81) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);
	  
	//   NJetsTtagged_0p81 += isTtagged;
	//   if(NJetsTtagged_0p81 == 1){
	//     TJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet);
	//     tjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
	// 			  theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),massSD);
	//     deltaRlepTjet = tjet1_lv.DeltaR(lepton_lv);
	//     deltaPhilepTjet = tjet1_lv.DeltaPhi(lepton_lv);
	//   }
	  
	//   bool isWtagged = (mass > 65) && (mass < 105) && (tau21 < 0.6) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
	//   bool isPWtagged = (massPSD > 65) && (massPSD < 105) && (Ptau21 < 0.55) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
	  
	//   NJetsWtagged_0p6 += isWtagged;
	//   NPuppiWtagged_0p55 += isPWtagged;
	//   if(isWtagged){NJetsWtagged_0p6_notTtagged += isWtagged-isTtagged;}
	//   if(NJetsWtagged_0p6 == 1){
	//     WJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet);
	//   }
	// }

        // ----------------------------------------------------------------------------                                  
        // Count Higgs tags                                                                                              
        // ----------------------------------------------------------------------------                                  
	
	// Not needed right now since we are using the scale-factor applied counters
        // int firstsub = theJetAK8SDSubjetIndex_JetSubCalc->at(ijet);
        // int nsubs = theJetAK8SDSubjetSize_JetSubCalc->at(ijet);
        // int NsubCSVM = 0;
        // for(int isub = firstsub; isub < firstsub + nsubs; isub++){
        //   if(theJetAK8SDSubjetCSV_JetSubCalc->at(isub) > 0.8484) NsubCSVM += 1;
        //   if(isub != firstsub && theJetAK8SDSubjetPt_JetSubCalc->at(isub) == theJetAK8SDSubjetPt_JetSubCalc->at(firstsub)) cout << "subjets have matching pT, something's wrong" << endl;
        // }
	// Now options are pruning+CHS or softdrop+PUPPI
        // double sdmass = theJetAK8PrunedMassWtagUncerts_JetSubCalc_PtOrdered.at(ijet);
        // double pt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet);
	// tempTLV.SetPtEtaPhiE(pt,theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),theJetAK8Energy_JetSubCalc_PtOrdered.at(ijet));
        // if(pt > 300 && sdmass > 60 && sdmass < 160){
        //   if(theJetAK8SDSubjetNCSVM_PtOrdered.at(ijet) >= 1) HtagTLVs.push_back(tempTLV);
        //   if(theJetAK8SDSubjetNCSVM_PtOrdered.at(ijet) == 1) NJetsH1btagged += 1;                                  
        //   if(theJetAK8SDSubjetNCSVM_PtOrdered.at(ijet) > 1) NJetsH2btagged += 1;                                   
	// }
	
	// double puppisdmass = theJetAK8SoftDrop_PtOrdered.at(ijet); //corrmass + Rand.Gaus(0,puppisdres*sqrt(pow(puppisdsf,2) - 1.0));
        // if(pt > 300 && puppisdmass > 60 && puppisdmass < 160){
        //   if(theJetAK8SDSubjetNCSVM_PtOrdered.at(ijet) >= 1) PHtagTLVs.push_back(tempTLV);
        //   if(theJetAK8SDSubjetNCSVM_PtOrdered.at(ijet) == 1) NPuppiH1btagged += 1;                                  
        //   if(theJetAK8SDSubjetNCSVM_PtOrdered.at(ijet) > 1) NPuppiH2btagged += 1;                                   
	// }
      }

      if(theJetAK8Pt_JetSubCalc_PtOrdered.size() < 3) continue;

      // ----------------------------------------------------------------------------
      // Lepton 4-vectors, calculate MT and electron trigger presel value
      // ----------------------------------------------------------------------------

      // Set lepton 4-vectors
      double lepM;
      double lepphi;
     if (isMuon){ 
	lepM = 0.105658367;
	lepphi = muPhi_singleLepCalc->at(0);
	lepton_lv.SetPtEtaPhiM(muPt_singleLepCalc->at(0),muEta_singleLepCalc->at(0),muPhi_singleLepCalc->at(0),lepM);
      }
      else{
	lepM = 0.00051099891;
	lepphi = elPhi_singleLepCalc->at(0);
	lepton_lv.SetPtEtaPhiM(elPt_singleLepCalc->at(0),elEta_singleLepCalc->at(0),elPhi_singleLepCalc->at(0),lepM);
      }      MT_lepMet = sqrt(2*leppt*corr_met_singleLepCalc*(1 - cos(lepphi - corr_met_phi_singleLepCalc)));

      // ----------------------------------------------------------------------------
      // 8TeV Top pT reweighting
      // ----------------------------------------------------------------------------

      genTopPt = -999;
      genAntiTopPt = -999;
      topPtWeight13TeV = 1.0;

      for(unsigned int ijet=0; ijet < topPt_TTbarMassCalc->size(); ijet++){
	if(genTopPt < 0 && topID_TTbarMassCalc->at(ijet) == 6) genTopPt = topPt_TTbarMassCalc->at(ijet);
	if(genAntiTopPt < 0 && topID_TTbarMassCalc->at(ijet) == -6) genAntiTopPt = topPt_TTbarMassCalc->at(ijet);
      }

      if(genTopPt > 0 && genAntiTopPt > 0){
	// Updated info from the TWiki CMS/TopSystematics#pt_top_Reweighting, NOTE goes to at least pT = 750
        float SFtop13TeV = TMath::Exp(0.0615-0.0005*genTopPt);
        float SFantitop13TeV = TMath::Exp(0.0615-0.0005*genAntiTopPt);
        topPtWeight13TeV = TMath::Sqrt(SFtop13TeV*SFantitop13TeV);
      }
      
      // ----------------------------------------------------------------------------
      // W --> l nu with mass constraint
      // ----------------------------------------------------------------------------

      double metpx = corr_met_singleLepCalc*cos(corr_met_phi_singleLepCalc);
      double metpy = corr_met_singleLepCalc*sin(corr_met_phi_singleLepCalc);
      double metpt = corr_met_singleLepCalc;

      double Dtmp = (MW*MW)-(lepM*lepM)+2*((lepton_lv.Px())*(metpx)+(lepton_lv.Py())*(metpy));
      double Atmp = 4.0*((lepton_lv.Energy())*(lepton_lv.Energy())-(lepton_lv.Pz())*(lepton_lv.Pz()));
      double Btmp = -4.0*Dtmp*(lepton_lv.Pz());
      double Ctmp = 4.0*(lepton_lv.Energy())*(lepton_lv.Energy())*(metpt)*(metpt)-Dtmp*Dtmp;
      
      double nuPz_1;
      double nuPz_2;
      
      double DETtmp = Btmp*Btmp-4.0*Atmp*Ctmp;

      TLorentzVector Wlv_1, Wlv_2, Wlv, lvTop, lvXTF;
      if(DETtmp >= 0) {
	nuPz_1 = (-Btmp+TMath::Sqrt(DETtmp))/(2.0*Atmp);
	nuPz_2 = (-Btmp-TMath::Sqrt(DETtmp))/(2.0*Atmp);
	TLorentzVector Nulv_1(metpx,metpy,nuPz_1,TMath::Sqrt((metpt)*(metpt)+(nuPz_1)*(nuPz_1)));
	TLorentzVector Nulv_2(metpx,metpy,nuPz_2,TMath::Sqrt((metpt)*(metpt)+(nuPz_2)*(nuPz_2)));
	Wlv_1 = Nulv_1+lepton_lv;
	Wlv_2 = Nulv_2+lepton_lv;
      }
      if(DETtmp < 0) {
	nuPz_1 = (-Btmp)/(2.0*Atmp);
	nuPz_2 = (-Btmp)/(2.0*Atmp);
	double alpha = (lepton_lv.Px())*(metpx)/(metpt)+(lepton_lv.Py())*(metpy)/(metpt);
	double Delta = (MW*MW)-(lepM*lepM);
	Atmp = 4.0*((lepton_lv.Pz())*(lepton_lv.Pz())-(lepton_lv.Energy())*(lepton_lv.Energy())+(alpha*alpha));
	Btmp = 4.0*alpha*Delta;
	Ctmp = Delta*Delta;
	DETtmp = Btmp*Btmp-4.0*Atmp*Ctmp;
	double pTnu_1 = (-Btmp+TMath::Sqrt(DETtmp))/(2.0*Atmp);
	double pTnu_2 = (-Btmp-TMath::Sqrt(DETtmp))/(2.0*Atmp);
	TLorentzVector Nulv_1(metpx*(pTnu_1)/(metpt),metpy*(pTnu_1)/(metpt),nuPz_1,TMath::Sqrt((pTnu_1)*(pTnu_1)+(nuPz_1)*(nuPz_1)));
	TLorentzVector Nulv_2(metpx*(pTnu_2)/(metpt),metpy*(pTnu_2)/(metpt),nuPz_2,TMath::Sqrt((pTnu_2)*(pTnu_2)+(nuPz_2)*(nuPz_2)));
	Wlv_1 = Nulv_1+lepton_lv;
	Wlv_2 = Nulv_2+lepton_lv;
	if (fabs(Wlv_1.M()-MW) < fabs(Wlv_2.M()-MW)) Wlv_2 = Wlv_1;
	else Wlv_1 = Wlv_2;
      }
      
      if (fabs(Wlv_1.M()-MW) < fabs(Wlv_2.M()-MW)) Wlv = Wlv_1;
      else Wlv = Wlv_2;
 

      W_mass = Wlv.M();

      // ----------------------------------------------------------------------------
      // top --> W b --> l nu b using W from above
      // ----------------------------------------------------------------------------
      /*
      double dMTOP = 1e8;
      unsigned int topIndex = 0;
      bool firstW = true;
      double MTop_1, MTop_2;
      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc_PtOrdered.size(); ijet++){
	if(theJetBTag_JetSubCalc_PtOrdered.at(topIndex) == 0){ continue;}
	jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(ijet),theJetEta_JetSubCalc_PtOrdered.at(ijet),theJetPhi_JetSubCalc_PtOrdered.at(ijet),theJetEnergy_JetSubCalc_PtOrdered.at(ijet));
	MTop_1 = (jet_lv + Wlv_1).M();
	MTop_2 = (jet_lv + Wlv_2).M();
	if(fabs(MTop_1 - MTOP) < dMTOP) {
	  if(fabs(MTop_1 - MTOP) < fabs(MTop_2 - MTOP)) {
	    firstW = true;
	    topIndex = ijet;
	    dMTOP = fabs(MTop_1 - MTOP);
	  }
	  else {
	    firstW = false;
	    topIndex = ijet;
	    dMTOP = fabs(MTop_2 - MTOP);
	  }
	}
	else if(fabs(MTop_2 - MTOP) < dMTOP) {
	  firstW = false;
	  topIndex = ijet;
	  dMTOP = fabs(MTop_2 - MTOP);
	}
	isHadronicTprime = true;
      }
      isLeptonicTprime = not isHadronicTprime;
      if(firstW) {Wlv = Wlv_1;}
      else{Wlv = Wlv_2;}

      jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(topIndex),theJetEta_JetSubCalc_PtOrdered.at(topIndex),theJetPhi_JetSubCalc_PtOrdered.at(topIndex),theJetEnergy_JetSubCalc_PtOrdered.at(topIndex));
      lvTop = jet_lv + Wlv; //Top LV
      top_lv = lvTop;
      
      topPt = lvTop.Pt();
      topMass = lvTop.M();
      topPtGen = genTopPt;
      if(fabs(lvTop.Pt() - genTopPt) > fabs(lvTop.Pt() - genAntiTopPt)) topPtGen = genAntiTopPt;
      */



      // ----------------------------------------------------------------------------
      // T' decay
      // ----------------------------------------------------------------------------                                                                                                           
      float deltaR = 999;
      int bIndex = 999;
      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc_PtOrdered.size(); ijet++){
	TLorentzVector jet_lv;
	jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(ijet),theJetEta_JetSubCalc_PtOrdered.at(ijet),theJetPhi_JetSubCalc_PtOrdered.at(ijet),theJetEnergy_JetSubCalc_PtOrdered.at(ijet));
	float tempdr = jet_lv.DeltaR(Wlv);
	if(tempdr < deltaR) {deltaR = tempdr; bIndex = ijet;}
      }
      
      TLorentzVector top_lv;
      TLorentzVector W_lv;
      bool isLeptonicTprime = false;
      bool isHadronicTprime = false;
      if(deltaR < .8/* and theJetBTag_JetSubCalc_PtOrdered.at(bIndex) == 1*/){
	TLorentzVector bottom_lv;
	bottom_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(bIndex),theJetEta_JetSubCalc_PtOrdered.at(bIndex),theJetPhi_JetSubCalc_PtOrdered.at(bIndex),theJetEnergy_JetSubCalc_PtOrdered.at(bIndex));
	top_lv = bottom_lv + Wlv;
	isHadronicTprime = true;
      } else {
	isLeptonicTprime = true;
      }
      
      std::vector<pair<TLorentzVector,int>> jets_lv;
      int ijet = 0;
      while(jets_lv.size() < 3){
	TLorentzVector jet;
	jet.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),theJetAK8Energy_JetSubCalc_PtOrdered.at(ijet));
	if(jet.DeltaR(Wlv) > .8 and jet.DeltaR(top_lv) > .8 and isHadronicTprime) jets_lv.push_back(std::make_pair(jet,ijet));
	if(jet.DeltaR(Wlv) > .8 and isLeptonicTprime) jets_lv.push_back(std::make_pair(jet,ijet));
	ijet++;
	if(ijet == theJetAK8Pt_JetSubCalc_PtOrdered.size()) break;
      }

      if(jets_lv.size() != 3) continue;
      npass_ThreeJets = npass_ThreeJets + 1;

      highPtAK8Jet1_SoftDropCorrectedMass = theJetAK8SoftDropCorr_PtOrdered.at(jets_lv.at(0).second);
      highPtAK8Jet2_SoftDropCorrectedMass = theJetAK8SoftDropCorr_PtOrdered.at(jets_lv.at(1).second);
      highPtAK8Jet3_SoftDropCorrectedMass = theJetAK8SoftDropCorr_PtOrdered.at(jets_lv.at(2).second);
      
      Tprime1_BEST_Mass = 0;
      Tprime2_BEST_Mass = 0;
      Tprime1_BEST_Pt = 0;
      Tprime2_BEST_Pt = 0;
      Tprime1_BEST_Eta = 0;
      Tprime2_BEST_Eta = 0;
      Tprime1_BEST_Phi = 0;
      Tprime2_BEST_Phi = 0;
      TprimeAvg_BEST_Mass = 0;
      
      Tprime1_DeepAK8_Mass = 0;
      Tprime2_DeepAK8_Mass = 0;
      Tprime1_DeepAK8_Pt = 0;
      Tprime2_DeepAK8_Pt = 0;
      Tprime1_DeepAK8_Eta = 0;
      Tprime2_DeepAK8_Eta = 0;
      Tprime1_DeepAK8_Phi = 0;
      Tprime2_DeepAK8_Phi = 0;
      TprimeAvg_DeepAK8_Mass = 0;
      
      Tprime1_DeepAK8_decorr_Mass = 0;
      Tprime2_DeepAK8_decorr_Mass = 0;
      Tprime1_DeepAK8_decorr_Pt = 0;
      Tprime2_DeepAK8_decorr_Pt = 0;
      Tprime1_DeepAK8_decorr_Eta = 0;
      Tprime2_DeepAK8_decorr_Eta = 0;
      Tprime1_DeepAK8_decorr_Phi = 0;
      Tprime2_DeepAK8_decorr_Phi = 0;
      TprimeAvg_DeepAK8_decorr_Mass = 0;

      //BEST SECTION
      int jet1_BEST = dnn_largest_BestCalc_PtOrdered.at(jets_lv.at(0).second);
      int jet2_BEST = dnn_largest_BestCalc_PtOrdered.at(jets_lv.at(1).second);
      int jet3_BEST = dnn_largest_BestCalc_PtOrdered.at(jets_lv.at(2).second);
      std::vector <pair<int,int>> decayJets_BEST;
      decayJets_BEST.push_back(std::make_pair(jet1_BEST,0));
      decayJets_BEST.push_back(std::make_pair(jet2_BEST,1));
      decayJets_BEST.push_back(std::make_pair(jet3_BEST,2));
      std::sort(decayJets_BEST.begin(),decayJets_BEST.end());
      TLorentzVector Tprime1_BEST_lv;
      TLorentzVector Tprime2_BEST_lv;
      // Start t --> b W decays
      validDecay_BEST = false;
      if(isHadronicTprime and decayJets_BEST.at(0).first==2 && decayJets_BEST.at(1).first==4 && decayJets_BEST.at(2).first==5){ // TTbar --> tH and bW
	validDecay_BEST = true;
	Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(0).second).first;
	Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(1).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	if(isSig){
	  if(isTHBW_TpTpCalc) {THBWeff_BEST_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { THBWeff_mistag_BEST_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isHadronicTprime and decayJets_BEST.at(0).first==1 && decayJets_BEST.at(1).first==2 && decayJets_BEST.at(2).first==2){ // TTbar --> tH and tH
	validDecay_BEST = true;
	float massDiff1=(top_lv+jets_lv.at(decayJets_BEST.at(1).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first).M();
	float massDiff2=(top_lv+jets_lv.at(decayJets_BEST.at(2).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first).M();
	if(massDiff1 < massDiff2) {
	  Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(1).second).first; 
	  Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	} else {
	  Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(2).second).first;
	  Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first;
	}
	if(isSig){
	  if(isTHTH_TpTpCalc) {THTHeff_BEST_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { THTHeff_mistag_BEST_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isHadronicTprime and decayJets_BEST.at(0).first==1 && decayJets_BEST.at(1).first==2 && decayJets_BEST.at(2).first==3){ // TTbar --> tH and tZ
	validDecay_BEST = true;
	float massDiff1=(top_lv+jets_lv.at(decayJets_BEST.at(1).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first).M();
	float massDiff2=(top_lv+jets_lv.at(decayJets_BEST.at(2).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first).M();
	if(massDiff1 < massDiff2) {
	  Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(1).second).first; 
	  Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	} else {
	  Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(2).second).first;
	  Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first;
	}
	if(isSig){
	  if(isTZTH_TpTpCalc) {THTZeff_BEST_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { THTZeff_mistag_BEST_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isHadronicTprime and decayJets_BEST.at(0).first==3 && decayJets_BEST.at(1).first==4 && decayJets_BEST.at(2).first==5){ // TTbar --> tZ and bW
	Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(0).second).first;
	Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(1).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	if(isSig){
	  if(isTZBW_TpTpCalc) {TZBWeff_BEST_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { TZBWeff_mistag_BEST_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isHadronicTprime and decayJets_BEST.at(0).first==1 && decayJets_BEST.at(1).first==3 && decayJets_BEST.at(2).first==3){ // TTbar --> tZ tZ
	validDecay_BEST = true;
	float massDiff1=(top_lv+jets_lv.at(decayJets_BEST.at(1).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first).M();
	float massDiff2=(top_lv+jets_lv.at(decayJets_BEST.at(2).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first).M();
	if(massDiff1 < massDiff2) {
	  Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(1).second).first; 
	  Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	} else {
	  Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(2).second).first;
	  Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first;
	} 
	if(isSig){
	  if(isTZTZ_TpTpCalc) {TZTZeff_BEST_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else {TZTZeff_mistag_BEST_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
	// Start T' --> b W decays
      }
      if(isLeptonicTprime and decayJets_BEST.at(0).first==4 && decayJets_BEST.at(1).first==5 && decayJets_BEST.at(2).first==5){
	validDecay_BEST = true;
	float massDiff1=(Wlv+jets_lv.at(decayJets_BEST.at(1).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first).M();
	float massDiff2=(Wlv+jets_lv.at(decayJets_BEST.at(2).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first).M();
	if(massDiff1 < massDiff2) {
	  Tprime1_BEST_lv = Wlv+jets_lv.at(decayJets_BEST.at(1).second).first;
	  Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	} else {
	  Tprime1_BEST_lv = Wlv+jets_lv.at(decayJets_BEST.at(2).second).first;
	  Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first;
	}
	if(isSig){
	  if(isBWBW_TpTpCalc){BWBWeff_BEST_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { BWBWeff_mistag_BEST_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isLeptonicTprime and decayJets_BEST.at(0).first==1 && decayJets_BEST.at(1).first==3 && decayJets_BEST.at(2).first==5){
	validDecay_BEST = true;
	Tprime1_BEST_lv = Wlv+jets_lv.at(decayJets_BEST.at(2).second).first;
	Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first;
	if(isSig){
	  if(isTZBW_TpTpCalc){BWTZeff_BEST_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  }  else { BWTZeff_mistag_BEST_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isLeptonicTprime and decayJets_BEST.at(0).first==1 && decayJets_BEST.at(1).first==2 && decayJets_BEST.at(2).first==5){
	validDecay_BEST = true;	    
	Tprime1_BEST_lv = Wlv+jets_lv.at(decayJets_BEST.at(2).second).first;
	Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first;
	if(isSig){
	  if(isTHBW_TpTpCalc){BWTHeff_BEST_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  }  else { BWTHeff_mistag_BEST_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(!validDecay_BEST) {
	//if(isHadronicTprime) cout << "1 " << jet1_BEST << " " << jet2_BEST << " " << jet3_BEST << endl;
	//if(isLeptonicTprime) cout << "4 " << jet1_BEST << " " << jet2_BEST << " " << jet3_BEST << endl;
	if(isHadronicTprime){
	  float massDiff1=(top_lv+jets_lv.at(decayJets_BEST.at(0).second).first).M()-(jets_lv.at(decayJets_BEST.at(1).second).first+jets_lv.at(decayJets_BEST.at(2).second).first).M();
	  float massDiff2=(top_lv+jets_lv.at(decayJets_BEST.at(1).second).first).M()-(jets_lv.at(decayJets_BEST.at(2).second).first+jets_lv.at(decayJets_BEST.at(0).second).first).M();
	  float massDiff3=(top_lv+jets_lv.at(decayJets_BEST.at(2).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first).M();
	  if(massDiff1 < massDiff2 and massDiff1 < massDiff3){
	    Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(0).second).first;
	    Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(1).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	  } else if(massDiff2 < massDiff1 and massDiff2 < massDiff3){
	    Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(1).second).first;
	    Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	  } else {
	    Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(2).second).first;
	    Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first;
	  }
	}
	if(isLeptonicTprime){
	  float massDiff1=(Wlv+jets_lv.at(decayJets_BEST.at(0).second).first).M()-(jets_lv.at(decayJets_BEST.at(1).second).first+jets_lv.at(decayJets_BEST.at(2).second).first).M();
	  float massDiff2=(Wlv+jets_lv.at(decayJets_BEST.at(1).second).first).M()-(jets_lv.at(decayJets_BEST.at(2).second).first+jets_lv.at(decayJets_BEST.at(0).second).first).M();
	  float massDiff3=(Wlv+jets_lv.at(decayJets_BEST.at(2).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first).M();
	  if(massDiff1 < massDiff2 and massDiff1 < massDiff3){
	    Tprime1_BEST_lv = Wlv+jets_lv.at(decayJets_BEST.at(0).second).first;
	    Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(1).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	  } else if(massDiff2 < massDiff1 and massDiff2 < massDiff3){
	    Tprime1_BEST_lv = Wlv+jets_lv.at(decayJets_BEST.at(1).second).first;
	    Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	  } else {
	    Tprime1_BEST_lv = Wlv+jets_lv.at(decayJets_BEST.at(2).second).first;
	    Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first;
	  }
	}
      }

      if(Tprime1_BEST_lv.M() != 0){
	Tprime1_BEST_Mass = Tprime1_BEST_lv.M();
	Tprime2_BEST_Mass = Tprime2_BEST_lv.M(); Tprime2_BEST_Mass_hist->Fill(Tprime2_BEST_Mass);
	Tprime1_BEST_Pt = Tprime1_BEST_lv.Pt();
	Tprime2_BEST_Pt = Tprime2_BEST_lv.Pt();
	Tprime1_BEST_Eta = Tprime1_BEST_lv.Eta();
	Tprime2_BEST_Eta = Tprime2_BEST_lv.Eta();
	Tprime1_BEST_Phi = Tprime1_BEST_lv.Phi();
	Tprime2_BEST_Phi = Tprime2_BEST_lv.Phi();
	TprimeAvg_BEST_Mass =  (Tprime1_BEST_lv.M()+Tprime2_BEST_lv.M() ) / 2;
      }
      // DeepAK8 Section
      int jet1_DeepAK8 = dnn_largest_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second);
      int jet2_DeepAK8 = dnn_largest_DeepAK8Calc_PtOrdered.at(jets_lv.at(1).second);
      int jet3_DeepAK8 = dnn_largest_DeepAK8Calc_PtOrdered.at(jets_lv.at(2).second);
      std::vector <pair<int,int>> decayJets_DeepAK8;
      decayJets_DeepAK8.push_back(std::make_pair(jet1_DeepAK8,0));
      decayJets_DeepAK8.push_back(std::make_pair(jet2_DeepAK8,1));
      decayJets_DeepAK8.push_back(std::make_pair(jet3_DeepAK8,2));
      std::sort(decayJets_DeepAK8.begin(),decayJets_DeepAK8.end());
      TLorentzVector Tprime1_DeepAK8_lv;
      TLorentzVector Tprime2_DeepAK8_lv;
      // Start t --> b W decays
      validDecay_DeepAK8 = false;
      if(isHadronicTprime and decayJets_DeepAK8.at(0).first==2 && decayJets_DeepAK8.at(1).first==4 && decayJets_DeepAK8.at(2).first==5){ // TTbar --> tH and bW
	validDecay_DeepAK8 = true;
	Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	if(isSig){
	  if(isTHBW_TpTpCalc){THBWeff_DeepAK8_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { THBWeff_mistag_DeepAK8_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isHadronicTprime and decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==2 && decayJets_DeepAK8.at(2).first==2){ // TTbar --> tH and tH
	validDecay_DeepAK8 = true;
	float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();
	float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M();
	if(massDiff1 < massDiff2) {
	  Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; 
	  Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	} else {
	  Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	  Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	}
	if(isSig){
	  if(isTHTH_TpTpCalc) {THTHeff_DeepAK8_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { THTHeff_mistag_DeepAK8_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isHadronicTprime and decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==2 && decayJets_DeepAK8.at(2).first==3){ // TTbar --> tH and tZ
	validDecay_DeepAK8 = true;
	float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();
	float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M();
	if(massDiff1 < massDiff2) {
	  Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; 
	  Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	} else {
	  Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	  Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	}
	if(isSig){
	  if(isTZTH_TpTpCalc) {THTZeff_DeepAK8_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { THTZeff_mistag_DeepAK8_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isHadronicTprime and decayJets_DeepAK8.at(0).first==3 && decayJets_DeepAK8.at(1).first==4 && decayJets_DeepAK8.at(2).first==5){ // TTbar --> tZ and bW
	Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	if(isSig){
	  if(isTZBW_TpTpCalc){TZBWeff_DeepAK8_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { TZBWeff_mistag_DeepAK8_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isHadronicTprime and decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==3 && decayJets_DeepAK8.at(2).first==3){ // TTbar --> tZ tZ
	validDecay_DeepAK8 = true;
	float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();
	float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M();
	if(massDiff1 < massDiff2) {
	  Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; 
	  Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	} else {
	  Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	  Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	}
	if(isSig){
	  if(isTZTZ_TpTpCalc){TZTZeff_DeepAK8_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { TZTZeff_mistag_DeepAK8_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      // Start T' --> b W decays
      if(isLeptonicTprime and decayJets_DeepAK8.at(0).first==4 && decayJets_DeepAK8.at(1).first==5 && decayJets_DeepAK8.at(2).first==5){
	validDecay_DeepAK8 = true;
	float massDiff1=(Wlv+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();
	float massDiff2=(Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M();
	if(massDiff1 < massDiff2) {
	  Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	  Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	} else {
	  Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	  Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	}
	if(isSig){
	  if(isBWBW_TpTpCalc){BWBWeff_DeepAK8_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { BWBWeff_mistag_DeepAK8_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isLeptonicTprime and decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==3 && decayJets_DeepAK8.at(2).first==5){
	validDecay_DeepAK8 = true;
	Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	if(isSig){
	  if(isTZBW_TpTpCalc){BWTZeff_DeepAK8_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { BWTZeff_mistag_DeepAK8_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isLeptonicTprime and decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==2 && decayJets_DeepAK8.at(2).first==5){
	validDecay_DeepAK8 = true;	    
	Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	if(isSig){
	  if(isTHBW_TpTpCalc){BWTHeff_DeepAK8_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { BWTHeff_mistag_DeepAK8_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(!validDecay_DeepAK8) {
	//if(isHadronicTprime) cout << "1 " << jet1_DeepAK8 << " " << jet2_DeepAK8 << " " << jet3_DeepAK8 << endl;
	//if(isLeptonicTprime) cout << "4 " << jet1_DeepAK8 << " " << jet2_DeepAK8 << " " << jet3_DeepAK8 << endl;
	if(isHadronicTprime){
	  float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();
	  float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(2).second).first+jets_lv.at(decayJets_DeepAK8.at(0).second).first).M();
	  float massDiff3=(top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M();
	  if(massDiff1 < massDiff2 and massDiff1 < massDiff3){
	    Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	  } else if(massDiff2 < massDiff1 and massDiff2 < massDiff3){
	    Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	  } else {
	    Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	  }
	}
	if(isLeptonicTprime){
	  float massDiff1=(Wlv+jets_lv.at(decayJets_DeepAK8.at(0).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();
	  float massDiff2=(Wlv+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(2).second).first+jets_lv.at(decayJets_DeepAK8.at(0).second).first).M();
	  float massDiff3=(Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M();
	  if(massDiff1 < massDiff2 and massDiff1 < massDiff3){
	    Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	  } else if(massDiff2 < massDiff1 and massDiff2 < massDiff3){
	    Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	  } else {
	    Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	  }
	}
      }

      if(Tprime1_DeepAK8_lv.M() != 0){
	Tprime1_DeepAK8_Mass = Tprime1_DeepAK8_lv.M();
	Tprime2_DeepAK8_Mass = Tprime2_DeepAK8_lv.M(); Tprime2_DeepAK8_Mass_hist->Fill(Tprime2_DeepAK8_Mass);
	Tprime1_DeepAK8_Pt = Tprime1_DeepAK8_lv.Pt();
	Tprime2_DeepAK8_Pt = Tprime2_DeepAK8_lv.Pt();
	Tprime1_DeepAK8_Eta = Tprime1_DeepAK8_lv.Eta();
	Tprime2_DeepAK8_Eta = Tprime2_DeepAK8_lv.Eta();
	Tprime1_DeepAK8_Phi = Tprime1_DeepAK8_lv.Phi();
	Tprime2_DeepAK8_Phi = Tprime2_DeepAK8_lv.Phi();
	TprimeAvg_DeepAK8_Mass =  (Tprime1_DeepAK8_lv.M()+Tprime2_DeepAK8_lv.M() ) / 2;
      }
      // DeepAK8_decorr Section
      int jet1_DeepAK8_decorr = decorr_largest_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second);
      int jet2_DeepAK8_decorr = decorr_largest_DeepAK8Calc_PtOrdered.at(jets_lv.at(1).second);
      int jet3_DeepAK8_decorr = decorr_largest_DeepAK8Calc_PtOrdered.at(jets_lv.at(2).second);
      std::vector <pair<int,int>> decayJets_DeepAK8_decorr;
      decayJets_DeepAK8_decorr.push_back(std::make_pair(jet1_DeepAK8_decorr,0));
      decayJets_DeepAK8_decorr.push_back(std::make_pair(jet2_DeepAK8_decorr,1));
      decayJets_DeepAK8_decorr.push_back(std::make_pair(jet3_DeepAK8_decorr,2));
      std::sort(decayJets_DeepAK8_decorr.begin(),decayJets_DeepAK8_decorr.end());
      TLorentzVector Tprime1_DeepAK8_decorr_lv;
      TLorentzVector Tprime2_DeepAK8_decorr_lv;
      // Start t --> b W decays
      validDecay_DeepAK8_decorr = false;
      if(isHadronicTprime and decayJets_DeepAK8_decorr.at(0).first==2 && decayJets_DeepAK8_decorr.at(1).first==4 && decayJets_DeepAK8_decorr.at(2).first==5){ // TTbar --> tH and bW
	validDecay_DeepAK8_decorr = true;
	Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first;
	Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	if(isSig){
	  if(isTHBW_TpTpCalc){THBWeff_DeepAK8_decorr_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { THBWeff_mistag_DeepAK8_decorr_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isHadronicTprime and decayJets_DeepAK8_decorr.at(0).first==1 && decayJets_DeepAK8_decorr.at(1).first==2 && decayJets_DeepAK8_decorr.at(2).first==2){ // TTbar --> tH and tH
	validDecay_DeepAK8_decorr = true;
	float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M();
	float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M();
	if(massDiff1 < massDiff2) {
	  Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first; 
	  Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	} else {
	  Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	  Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	}
	if(isSig){
	  if(isTHTH_TpTpCalc){THTHeff_DeepAK8_decorr_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { THTHeff_mistag_DeepAK8_decorr_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isHadronicTprime and decayJets_DeepAK8_decorr.at(0).first==1 && decayJets_DeepAK8_decorr.at(1).first==2 && decayJets_DeepAK8_decorr.at(2).first==3){ // TTbar --> tH and tZ
	validDecay_DeepAK8_decorr = true;
	float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M();
	float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M();
	if(massDiff1 < massDiff2) {
	  Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first; 
	  Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	} else {
	  Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	  Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	}
	if(isSig){
	  if(isTZTH_TpTpCalc){THTZeff_DeepAK8_decorr_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { THTZeff_mistag_DeepAK8_decorr_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isHadronicTprime and decayJets_DeepAK8_decorr.at(0).first==3 && decayJets_DeepAK8_decorr.at(1).first==4 && decayJets_DeepAK8_decorr.at(2).first==5){ // TTbar --> tZ and bW
	Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first;
	Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	if(isSig){
	  if(isTZBW_TpTpCalc){TZBWeff_DeepAK8_decorr_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { TZBWeff_mistag_DeepAK8_decorr_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isHadronicTprime and decayJets_DeepAK8_decorr.at(0).first==1 && decayJets_DeepAK8_decorr.at(1).first==3 && decayJets_DeepAK8_decorr.at(2).first==3){ // TTbar --> tZ tZ
	validDecay_DeepAK8_decorr = true;
	float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M();
	float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M();
	if(massDiff1 < massDiff2) {
	  Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first; 
	  Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	} else {
	  Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	  Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	}
	if(isSig){
	  if(isTZTZ_TpTpCalc){TZTZeff_DeepAK8_decorr_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { TZTZeff_mistag_DeepAK8_decorr_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      // Start T' --> b W decays	  
      if(isLeptonicTprime and decayJets_DeepAK8_decorr.at(0).first==4 && decayJets_DeepAK8_decorr.at(1).first==5 && decayJets_DeepAK8_decorr.at(2).first==5){
	validDecay_DeepAK8_decorr = true;
	float massDiff1=(Wlv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M();
	float massDiff2=(Wlv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M();
	if(massDiff1 < massDiff2) {
	  Tprime1_DeepAK8_decorr_lv = Wlv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	  Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	} else {
	  Tprime1_DeepAK8_decorr_lv = Wlv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	  Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	}
	if(isSig){
	  if(isBWBW_TpTpCalc){BWBWeff_DeepAK8_decorr_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { BWBWeff_mistag_DeepAK8_decorr_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isLeptonicTprime and decayJets_DeepAK8_decorr.at(0).first==1 && decayJets_DeepAK8_decorr.at(1).first==3 && decayJets_DeepAK8_decorr.at(2).first==5){
	validDecay_DeepAK8_decorr = true;
	Tprime1_DeepAK8_decorr_lv = Wlv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	if(isSig){
	  if(isTZBW_TpTpCalc){BWTZeff_DeepAK8_decorr_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { BWTZeff_mistag_DeepAK8_decorr_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(isLeptonicTprime and decayJets_DeepAK8_decorr.at(0).first==1 && decayJets_DeepAK8_decorr.at(1).first==2 && decayJets_DeepAK8_decorr.at(2).first==5){
	validDecay_DeepAK8_decorr = true;	    
	Tprime1_DeepAK8_decorr_lv = Wlv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	if(isSig){
	  if(isTHBW_TpTpCalc){BWTHeff_DeepAK8_decorr_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	  } else { BWTHeff_mistag_DeepAK8_decorr_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);}}
      }
      if(!validDecay_DeepAK8_decorr) {
	//if(isHadronicTprime) cout << "1 " << jet1_DeepAK8_decorr << " " << jet2_DeepAK8_decorr << " " << jet3_DeepAK8_decorr << endl;
	//if(isLeptonicTprime) cout << "4 " << jet1_DeepAK8_decorr << " " << jet2_DeepAK8_decorr << " " << jet3_DeepAK8_decorr << endl;
	if(isHadronicTprime){
	  float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M();
	  float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first).M();
	  float massDiff3=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M();
	  if(massDiff1 < massDiff2 and massDiff1 < massDiff3){
	    Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first;
	    Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	  } else if(massDiff2 < massDiff1 and massDiff2 < massDiff3){
	    Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	    Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	  } else {
	    Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	    Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	  }
	}
	if(isLeptonicTprime){
	  float massDiff1=(Wlv+jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M();
	  float massDiff2=(Wlv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first).M();
	  float massDiff3=(Wlv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M();
	  if(massDiff1 < massDiff2 and massDiff1 < massDiff3){
	    Tprime1_DeepAK8_decorr_lv = Wlv+jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first;
	    Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	  } else if(massDiff2 < massDiff1 and massDiff2 < massDiff3){
	    Tprime1_DeepAK8_decorr_lv = Wlv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	    Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	  } else {
	    Tprime1_DeepAK8_decorr_lv = Wlv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	    Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	  }
	}
      }

      if(Tprime1_DeepAK8_decorr_lv.M() != 0){
	Tprime1_DeepAK8_decorr_Mass = Tprime1_DeepAK8_decorr_lv.M();
	Tprime2_DeepAK8_decorr_Mass = Tprime2_DeepAK8_decorr_lv.M(); Tprime2_DeepAK8_decorr_Mass_hist->Fill(Tprime2_DeepAK8_decorr_Mass);
	Tprime1_DeepAK8_decorr_Pt = Tprime1_DeepAK8_decorr_lv.Pt();
	Tprime2_DeepAK8_decorr_Pt = Tprime2_DeepAK8_decorr_lv.Pt();
	Tprime1_DeepAK8_decorr_Eta = Tprime1_DeepAK8_decorr_lv.Eta();
	Tprime2_DeepAK8_decorr_Eta = Tprime2_DeepAK8_decorr_lv.Eta();
	Tprime1_DeepAK8_decorr_Phi = Tprime1_DeepAK8_decorr_lv.Phi();
	Tprime2_DeepAK8_decorr_Phi = Tprime2_DeepAK8_decorr_lv.Phi();
	TprimeAvg_DeepAK8_decorr_Mass =  (Tprime1_DeepAK8_decorr_lv.M()+Tprime2_DeepAK8_decorr_lv.M() ) / 2;
      }
      /*
      // Jetsub Section
      int jet1_JetSub = maxProb_JetSubCalc_PtOrdered.at(jets_lv.at(0).second);
      int jet2_JetSub = maxProb_JetSubCalc_PtOrdered.at(jets_lv.at(1).second);
      int jet3_JetSub = maxProb_JetSubCalc_PtOrdered.at(jets_lv.at(2).second);
      std::vector <pair<int,int>> decayJets_JetSub;
      decayJets_JetSub.push_back(std::make_pair(jet1_JetSub,0));
      decayJets_JetSub.push_back(std::make_pair(jet2_JetSub,1));
      decayJets_JetSub.push_back(std::make_pair(jet3_JetSub,2));
      std::sort(decayJets_JetSub.begin(),decayJets_JetSub.end());
      TLorentzVector Tprime1_JetSub_lv;
      TLorentzVector Tprime2_JetSub_lv;
      // Start t --> b W decays
      validDecay_JetSub = true;
      if(isHadronicTprime and decayJets_JetSub.at(0).first==2 && decayJets_JetSub.at(1).first==4 && decayJets_JetSub.at(2).first==5){ // TTbar --> tH and bW
      Tprime1_JetSub_lv = top_lv+jets_lv.at(decayJets_JetSub.at(0).second).first;
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(1).second).first+jets_lv.at(decayJets_JetSub.at(2).second).first;
      THBWeff_JetSub_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
      } else if(isHadronicTprime and decayJets_JetSub.at(0).first==1 && decayJets_JetSub.at(1).first==2 && decayJets_JetSub.at(2).first==2){ // TTbar --> tH and tH
      float massDiff1=(top_lv+jets_lv.at(decayJets_JetSub.at(1).second).first).M()-(jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(2).second).first).M();
      float massDiff2=(top_lv+jets_lv.at(decayJets_JetSub.at(2).second).first).M()-(jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(1).second).first).M();
      if(massDiff1 < massDiff2) {
      Tprime1_JetSub_lv = top_lv+jets_lv.at(decayJets_JetSub.at(1).second).first; 
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(2).second).first;
      } else {
      Tprime1_JetSub_lv = top_lv+jets_lv.at(decayJets_JetSub.at(2).second).first;
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(1).second).first;
      }
      THTHeff_JetSub_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
      } else if(isHadronicTprime and decayJets_JetSub.at(0).first==1 && decayJets_JetSub.at(1).first==2 && decayJets_JetSub.at(2).first==3){ // TTbar --> tH and tZ
      float massDiff1=(top_lv+jets_lv.at(decayJets_JetSub.at(1).second).first).M()-(jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(2).second).first).M();
      float massDiff2=(top_lv+jets_lv.at(decayJets_JetSub.at(2).second).first).M()-(jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(1).second).first).M();
      if(massDiff1 < massDiff2) {
      Tprime1_JetSub_lv = top_lv+jets_lv.at(decayJets_JetSub.at(1).second).first; 
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(2).second).first;
      } else {
      Tprime1_JetSub_lv = top_lv+jets_lv.at(decayJets_JetSub.at(2).second).first;
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(1).second).first;
      }
      THTZeff_JetSub_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
      } else if(isHadronicTprime and decayJets_JetSub.at(0).first==3 && decayJets_JetSub.at(1).first==4 && decayJets_JetSub.at(2).first==5){ // TTbar --> tZ and bW
      Tprime1_JetSub_lv = top_lv+jets_lv.at(decayJets_JetSub.at(0).second).first;
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(1).second).first+jets_lv.at(decayJets_JetSub.at(2).second).first;
      TZBWeff_JetSub_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
      } else if(isHadronicTprime and decayJets_JetSub.at(0).first==1 && decayJets_JetSub.at(1).first==3 && decayJets_JetSub.at(2).first==3){ // TTbar --> tZ tZ
      float massDiff1=(top_lv+jets_lv.at(decayJets_JetSub.at(1).second).first).M()-(jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(2).second).first).M();
      float massDiff2=(top_lv+jets_lv.at(decayJets_JetSub.at(2).second).first).M()-(jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(1).second).first).M();
      if(massDiff1 < massDiff2) {
      Tprime1_JetSub_lv = top_lv+jets_lv.at(decayJets_JetSub.at(1).second).first; 
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(2).second).first;
      } else {
      Tprime1_JetSub_lv = top_lv+jets_lv.at(decayJets_JetSub.at(2).second).first;
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(1).second).first;
      } 
      TZTZeff_JetSub_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
      // Start T' --> b W decays
      } else if(isLeptonicTprime and decayJets_JetSub.at(0).first==4 && decayJets_JetSub.at(1).first==5 && decayJets_JetSub.at(2).first==5){
      float massDiff1=(Wlv+jets_lv.at(decayJets_JetSub.at(1).second).first).M()-(jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(2).second).first).M();
      float massDiff2=(Wlv+jets_lv.at(decayJets_JetSub.at(2).second).first).M()-(jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(1).second).first).M();
      if(massDiff1 < massDiff2) {
      Tprime1_JetSub_lv = Wlv+jets_lv.at(decayJets_JetSub.at(1).second).first;
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(2).second).first;
      } else {
      Tprime1_JetSub_lv = Wlv+jets_lv.at(decayJets_JetSub.at(2).second).first;
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(1).second).first;
      }
      BWBWeff_JetSub_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
      } else if(isLeptonicTprime and decayJets_JetSub.at(0).first==1 && decayJets_JetSub.at(1).first==3 && decayJets_JetSub.at(2).first==5){
      Tprime1_JetSub_lv = Wlv+jets_lv.at(decayJets_JetSub.at(2).second).first;
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(1).second).first;
      BWTZeff_JetSub_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
      } else if(isLeptonicTprime and decayJets_JetSub.at(0).first==1 && decayJets_JetSub.at(1).first==2 && decayJets_JetSub.at(2).first==5){
      Tprime1_JetSub_lv = Wlv+jets_lv.at(decayJets_JetSub.at(2).second).first;
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(1).second).first;
      BWTHeff_JetSub_num->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
      } else {
      validDecay_JetSub = false;
      //if(isHadronicTprime) cout << "1 " << jet1_JetSub << " " << jet2_JetSub << " " << jet3_JetSub << endl;
      //if(isLeptonicTprime) cout << "4 " << jet1_JetSub << " " << jet2_JetSub << " " << jet3_JetSub << endl;
      if(isHadronicTprime){
      float massDiff1=(top_lv+jets_lv.at(decayJets_JetSub.at(0).second).first).M()-(jets_lv.at(decayJets_JetSub.at(1).second).first+jets_lv.at(decayJets_JetSub.at(2).second).first).M();
      float massDiff2=(top_lv+jets_lv.at(decayJets_JetSub.at(1).second).first).M()-(jets_lv.at(decayJets_JetSub.at(2).second).first+jets_lv.at(decayJets_JetSub.at(0).second).first).M();
      float massDiff3=(top_lv+jets_lv.at(decayJets_JetSub.at(2).second).first).M()-(jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(1).second).first).M();
      if(massDiff1 < massDiff2 and massDiff1 < massDiff3){
      Tprime1_JetSub_lv = top_lv+jets_lv.at(decayJets_JetSub.at(0).second).first;
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(1).second).first+jets_lv.at(decayJets_JetSub.at(2).second).first;
      } else if(massDiff2 < massDiff1 and massDiff2 < massDiff3){
      Tprime1_JetSub_lv = top_lv+jets_lv.at(decayJets_JetSub.at(1).second).first;
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(2).second).first;
      } else {
      Tprime1_JetSub_lv = top_lv+jets_lv.at(decayJets_JetSub.at(2).second).first;
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(1).second).first;
      }
      }
      if(isLeptonicTprime){
      float massDiff1=(Wlv+jets_lv.at(decayJets_JetSub.at(0).second).first).M()-(jets_lv.at(decayJets_JetSub.at(1).second).first+jets_lv.at(decayJets_JetSub.at(2).second).first).M();
      float massDiff2=(Wlv+jets_lv.at(decayJets_JetSub.at(1).second).first).M()-(jets_lv.at(decayJets_JetSub.at(2).second).first+jets_lv.at(decayJets_JetSub.at(0).second).first).M();
      float massDiff3=(Wlv+jets_lv.at(decayJets_JetSub.at(2).second).first).M()-(jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(1).second).first).M();
      if(massDiff1 < massDiff2 and massDiff1 < massDiff3){
      Tprime1_JetSub_lv = Wlv+jets_lv.at(decayJets_JetSub.at(0).second).first;
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(1).second).first+jets_lv.at(decayJets_JetSub.at(2).second).first;
      } else if(massDiff2 < massDiff1 and massDiff2 < massDiff3){
      Tprime1_JetSub_lv = Wlv+jets_lv.at(decayJets_JetSub.at(1).second).first;
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(2).second).first;
      } else {
      Tprime1_JetSub_lv = Wlv+jets_lv.at(decayJets_JetSub.at(2).second).first;
      Tprime2_JetSub_lv = jets_lv.at(decayJets_JetSub.at(0).second).first+jets_lv.at(decayJets_JetSub.at(1).second).first;
      }
      }
      }

      if(Tprime1_JetSub_lv.M() != 0){
      Tprime1_JetSub_Mass = Tprime1_JetSub_lv.M();
      Tprime2_JetSub_Mass = Tprime2_JetSub_lv.M(); Tprime2_JetSub_Mass_hist->Fill(Tprime2_JetSub_Mass);
      Tprime1_JetSub_Pt = Tprime1_JetSub_lv.Pt();
      Tprime2_JetSub_Pt = Tprime2_JetSub_lv.Pt();
      Tprime1_JetSub_Eta = Tprime1_JetSub_lv.Eta();
      Tprime2_JetSub_Eta = Tprime2_JetSub_lv.Eta();
      Tprime1_JetSub_Phi = Tprime1_JetSub_lv.Phi();
      Tprime2_JetSub_Phi = Tprime2_JetSub_lv.Phi();
      TprimeAvg_JetSub_Mass =  (Tprime1_DeepAK8_decorr_lv.M()+Tprime2_DeepAK8_lv.M() ) / 2;
      }
      */
      // Filling denominator histograms
      if(isSig){
	if(isTHBW_TpTpCalc) THBWeff_den->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	else THBWeff_mistag_den->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	if(isTHTH_TpTpCalc) THTHeff_den->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	else THTHeff_mistag_den->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	if(isTZTH_TpTpCalc) THTZeff_den->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	else THTZeff_mistag_den->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	if(isTZBW_TpTpCalc) TZBWeff_den->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	else TZBWeff_mistag_den->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	if(isTZTZ_TpTpCalc) TZTZeff_den->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	else TZTZeff_mistag_den->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	if(isBWBW_TpTpCalc) BWBWeff_den->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	else BWBWeff_mistag_den->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	if(isTZBW_TpTpCalc) BWTZeff_den->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	else BWTZeff_mistag_den->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	if(isTHBW_TpTpCalc) BWTHeff_den->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
	else BWTHeff_mistag_den->Fill(tPrimePt_TpTpCalc->at(0)/2 + tPrimePt_TpTpCalc->at(1)/2);
      }


      // ----------------------------------------------------------------------------
      // AK4 Jet - lepton associations
      // ----------------------------------------------------------------------------

      NJetsCSV_JetSubCalc = 0;
      NJetsCSVwithSF_JetSubCalc = 0;
      NJetsCSVnotH_JetSubCalc = 0;
      NJetsCSVnotPH_JetSubCalc = 0;
      BJetLeadPt = -99;
      minMleppBjet = 1e8;
      minMleppJet = 1e8;
      minDR_lepJet = 1e8;
      ptRel_lepJet = -99;
      deltaR_lepJets.clear();
      deltaR_lepBJets.clear();



      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc_PtOrdered.size(); ijet++){
        jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(ijet),theJetEta_JetSubCalc_PtOrdered.at(ijet),theJetPhi_JetSubCalc_PtOrdered.at(ijet),theJetEnergy_JetSubCalc_PtOrdered.at(ijet));
	if((lepton_lv + jet_lv).M() < minMleppJet) {
	  minMleppJet = fabs((lepton_lv + jet_lv).M());
	  deltaRlepJetInMinMljet = jet_lv.DeltaR(lepton_lv);
	  deltaPhilepJetInMinMljet = jet_lv.DeltaPhi(lepton_lv);
	}

	deltaR_lepJets.push_back(lepton_lv.DeltaR(jet_lv));

        // FOR NOW DON'T USE THE SCALE FACTORS               **** NEED TO CHANGE TO DEEPCSV probb + probbb > 0.4941                          
	if(theJetCSVb_JetSubCalc_PtOrdered.at(ijet) + theJetCSVbb_JetSubCalc_PtOrdered.at(ijet) > 0.4941){
          NJetsCSV_JetSubCalc += 1;
        }
	// OK, we're back to using SFs
	if(theJetBTag_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsCSVwithSF_JetSubCalc += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt) BJetLeadPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet) {
            minMleppBjet = fabs( (lepton_lv + jet_lv).M() );
          }

	  bool Hoverlap = false;
	  for(unsigned int iH = 0; iH < HtagTLVs.size(); iH++){
	    if(jet_lv.DeltaR(HtagTLVs.at(iH)) < 0.8) Hoverlap = true;
	  }
	  if(!Hoverlap) NJetsCSVnotH_JetSubCalc += 1;

	  Hoverlap = false;
	  for(unsigned int iH = 0; iH < PHtagTLVs.size(); iH++){
	    if(jet_lv.DeltaR(PHtagTLVs.at(iH)) < 0.8) Hoverlap = true;
	  }
	  if(!Hoverlap) NJetsCSVnotPH_JetSubCalc += 1;

	}

 	if(deltaR_lepJets[ijet] < minDR_lepJet) {
	  minDR_lepJet = deltaR_lepJets[ijet];
	  ptRel_lepJet = lepton_lv.P()*(jet_lv.Vect().Cross(lepton_lv.Vect()).Mag()/jet_lv.P()/lepton_lv.P());
	}
      }

      // ----------------------------------------------------------------------------
      // DONE!! Write the tree
      // ----------------------------------------------------------------------------
      
      outputTree->Fill();
   }
   std::cout<<"Npassed_ThreeJets      = "<<npass_ThreeJets<<" / "<<nentries<<std::endl;
   std::cout<<"Nelectrons             = "<<Nelectrons<<" / "<<nentries<<std::endl;
   std::cout<<"Nmuons                 = "<<Nmuons<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_Mu500          = "<<npass_mu500<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_Trigger(DATA)  = "<<npass_trigger<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_MET            = "<<npass_met<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_nJets          = "<<npass_njets<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_JetLeadPt      = "<<npass_JetLeadPt<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_JetSubLeadPt   = "<<npass_JetSubLeadPt<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_lepPt          = "<<npass_lepPt<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_ElEta          = "<<npass_ElEta<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_MuEta          = "<<npass_MuEta<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_ALL            = "<<npass_all<<" / "<<nentries<<std::endl;



   //***** EXAMPLE OF WRITING HISTOGRAMS TO THE FILE
   // Tprime Tagging Efficiency denominator Histograms
   THBWeff_den->Write();
   THTHeff_den->Write();
   THTZeff_den->Write();
   TZBWeff_den->Write();
   TZTZeff_den->Write();
   BWBWeff_den->Write();
   BWTZeff_den->Write();
   BWTHeff_den->Write();

   // Tprime Mistagging Efficiency denominator Histograms
   THBWeff_mistag_den->Write();
   THTHeff_mistag_den->Write();
   THTZeff_mistag_den->Write();
   TZBWeff_mistag_den->Write();
   TZTZeff_mistag_den->Write();
   BWBWeff_mistag_den->Write();
   BWTZeff_mistag_den->Write();
   BWTHeff_mistag_den->Write();

   // Tagging efficiency denominator histograms
   Weff_den->Write();
   Zeff_den->Write();
   Heff_den->Write();
   Teff_den->Write();
   Beff_den->Write();
   Jeff_den->Write();
   
   // Mistagging efficiency denominator histograms
   Weff_mistag_den->Write();
   Zeff_mistag_den->Write();
   Heff_mistag_den->Write();
   Teff_mistag_den->Write();
   Beff_mistag_den->Write();
   Jeff_mistag_den->Write();

   // Tprime Tagging Efficiency numerator histograms
   THBWeff_BEST_num->Write();
   THTHeff_BEST_num->Write();
   THTZeff_BEST_num->Write();
   TZBWeff_BEST_num->Write();
   TZTZeff_BEST_num->Write();
   BWBWeff_BEST_num->Write();
   BWTZeff_BEST_num->Write();
   BWTHeff_BEST_num->Write();

   THBWeff_DeepAK8_num->Write();
   THTHeff_DeepAK8_num->Write();
   THTZeff_DeepAK8_num->Write();
   TZBWeff_DeepAK8_num->Write();
   TZTZeff_DeepAK8_num->Write();
   BWBWeff_DeepAK8_num->Write();
   BWTZeff_DeepAK8_num->Write();
   BWTHeff_DeepAK8_num->Write();

   THBWeff_DeepAK8_decorr_num->Write();
   THTHeff_DeepAK8_decorr_num->Write();
   THTZeff_DeepAK8_decorr_num->Write();
   TZBWeff_DeepAK8_decorr_num->Write();
   TZTZeff_DeepAK8_decorr_num->Write();
   BWBWeff_DeepAK8_decorr_num->Write();
   BWTZeff_DeepAK8_decorr_num->Write();
   BWTHeff_DeepAK8_decorr_num->Write();

   // Tprime Tagging Efficiency numerator histograms
   THBWeff_mistag_BEST_num->Write();
   THTHeff_mistag_BEST_num->Write();
   THTZeff_mistag_BEST_num->Write();
   TZBWeff_mistag_BEST_num->Write();
   TZTZeff_mistag_BEST_num->Write();
   BWBWeff_mistag_BEST_num->Write();
   BWTZeff_mistag_BEST_num->Write();
   BWTHeff_mistag_BEST_num->Write();
   
   THBWeff_mistag_DeepAK8_num->Write();
   THTHeff_mistag_DeepAK8_num->Write();
   THTZeff_mistag_DeepAK8_num->Write();
   TZBWeff_mistag_DeepAK8_num->Write();
   TZTZeff_mistag_DeepAK8_num->Write();
   BWBWeff_mistag_DeepAK8_num->Write();
   BWTZeff_mistag_DeepAK8_num->Write();
   BWTHeff_mistag_DeepAK8_num->Write();

   THBWeff_mistag_DeepAK8_decorr_num->Write();
   THTHeff_mistag_DeepAK8_decorr_num->Write();
   THTZeff_mistag_DeepAK8_decorr_num->Write();
   TZBWeff_mistag_DeepAK8_decorr_num->Write();
   TZTZeff_mistag_DeepAK8_decorr_num->Write();
   BWBWeff_mistag_DeepAK8_decorr_num->Write();
   BWTZeff_mistag_DeepAK8_decorr_num->Write();
   BWTHeff_mistag_DeepAK8_decorr_num->Write();
   
   // Tagging efficiency numerator histograms
   Weff_BEST_num->Write();
   Zeff_BEST_num->Write();
   Heff_BEST_num->Write();
   Teff_BEST_num->Write();
   Beff_BEST_num->Write();
   Jeff_BEST_num->Write();

   Weff_DeepAK8_num->Write();
   Zeff_DeepAK8_num->Write();
   Heff_DeepAK8_num->Write();
   Teff_DeepAK8_num->Write();
   Beff_DeepAK8_num->Write();
   Jeff_DeepAK8_num->Write();

   Weff_DeepAK8_decorr_num->Write();
   Zeff_DeepAK8_decorr_num->Write();
   Heff_DeepAK8_decorr_num->Write();
   Teff_DeepAK8_decorr_num->Write();
   Beff_DeepAK8_decorr_num->Write();
   Jeff_DeepAK8_decorr_num->Write();

   WZeff_JetSub_num->Write();
   Heff_JetSub_num->Write();
   Teff_JetSub_num->Write();
   Beff_JetSub_num->Write();
   Jeff_JetSub_num->Write();



   // Mistgging efficiency numerator histograms                                                                                                                                                    
   Weff_mistag_BEST_num->Write();
   Zeff_mistag_BEST_num->Write();
   Heff_mistag_BEST_num->Write();
   Teff_mistag_BEST_num->Write();
   Beff_mistag_BEST_num->Write();
   Jeff_mistag_BEST_num->Write();

   Weff_mistag_DeepAK8_num->Write();
   Zeff_mistag_DeepAK8_num->Write();
   Heff_mistag_DeepAK8_num->Write();
   Teff_mistag_DeepAK8_num->Write();
   Beff_mistag_DeepAK8_num->Write();
   Jeff_mistag_DeepAK8_num->Write();

   Weff_mistag_DeepAK8_decorr_num->Write();
   Zeff_mistag_DeepAK8_decorr_num->Write();
   Heff_mistag_DeepAK8_decorr_num->Write();
   Teff_mistag_DeepAK8_decorr_num->Write();
   Beff_mistag_DeepAK8_decorr_num->Write();
   Jeff_mistag_DeepAK8_decorr_num->Write();

   WZeff_mistag_JetSub_num->Write();
   Heff_mistag_JetSub_num->Write();
   Teff_mistag_JetSub_num->Write();
   Beff_mistag_JetSub_num->Write();
   Jeff_mistag_JetSub_num->Write();

   Tprime2_BEST_Mass_hist->Write();
   Tprime2_DeepAK8_Mass_hist->Write();
   Tprime2_DeepAK8_decorr_Mass_hist->Write();
   //Tprime2_JetSub_Mass_hist->Write();

   confusion_den->Write();
   confusion_num_BEST->Write();
   confusion_num_DeepAK8->Write();
   confusion_num_DeepAK8_decorr->Write();
   confusion_num_JetSub->Write();

   outputTree->Write();

}
