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
#include <TH3.h>

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
   inputTree->SetBranchStatus("LHEweightids_singleLepCalc",1);
   inputTree->SetBranchStatus("LHEweights_singleLepCalc",1);
   inputTree->SetBranchStatus("HTfromHEPUEP_singleLepCalc",1);

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
   inputTree->SetBranchStatus("AK8JetCSV_BestCalc",1);*/
   inputTree->SetBranchStatus("dnn_QCD_BestCalc",1);
   inputTree->SetBranchStatus("dnn_Top_BestCalc",1);
   inputTree->SetBranchStatus("dnn_Higgs_BestCalc",1);
   inputTree->SetBranchStatus("dnn_Z_BestCalc",1);
   inputTree->SetBranchStatus("dnn_W_BestCalc",1);
   inputTree->SetBranchStatus("dnn_B_BestCalc",1);
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
   inputTree->SetBranchStatus("dnn_B_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_J_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_W_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_Z_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_H_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_largest_DeepAK8Calc",1);
   inputTree->SetBranchStatus("decorr_largest_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_T_DeepAK8Calc",1);
   inputTree->SetBranchStatus("decorr_B_DeepAK8Calc",1);
   inputTree->SetBranchStatus("decorr_J_DeepAK8Calc",1);
   inputTree->SetBranchStatus("decorr_W_DeepAK8Calc",1);
   inputTree->SetBranchStatus("decorr_Z_DeepAK8Calc",1);
   inputTree->SetBranchStatus("decorr_H_DeepAK8Calc",1);
   inputTree->SetBranchStatus("decorr_T_DeepAK8Calc",1);

   //JetSubCalc
   inputTree->SetBranchStatus("maxProb_JetSubCalc",1);

   //adding DeepCSV from singleLepCalc
   //inputTree->SetBranchStatus("AK8JetDeepCSVb_singleLepCalc",1);
   //inputTree->SetBranchStatus("AK8JetDeepCSVbb_singleLepCalc",1);
   //   inputTree->SetBranchStatus("AK8JetDeepCSVc_singleLepCalc",1);
   //inputTree->SetBranchStatus("AK8JetDeepCSVudsg_singleLepCalc",1);
   
   //top
   inputTree->SetBranchStatus("ttbarMass_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topMass_TTbarMassCalc",1);

   inputTree->SetBranchStatus("allTopsEnergy_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsEta_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsPhi_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsPt_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsID_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsStatus_TTbarMassCalc",1);
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
   outputTree->Branch("pileupWeightUp",&pileupWeightUp,"pileupWeightUp/F");
   outputTree->Branch("pileupWeightDown",&pileupWeightDown,"pileupWeightDown/F");
   outputTree->Branch("HTSF_Pol",&HTSF_Pol,"HTSF_Pol/F");
   outputTree->Branch("HTSF_PolUp",&HTSF_PolUp,"HTSF_PolUp/F");
   outputTree->Branch("HTSF_PolDn",&HTSF_PolDn,"HTSF_PolDn/F");
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
   outputTree->Branch("NJetsCSVwithSF_JetSubCalc",&NJetsCSVwithSF_JetSubCalc,"NJetsCSVwithSF_JetSubCalc/I");
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
   outputTree->Branch("dnn_B_BestCalc",&dnn_B_BestCalc);
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
   outputTree->Branch("dnn_largest_DeepAK8Calc",&dnn_largest_DeepAK8Calc);
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

   outputTree->Branch("probSum_BEST_decay",&probSum_BEST_decay);
   outputTree->Branch("probSum_DeepAK8_decay",&probSum_DeepAK8_decay);
   outputTree->Branch("probSum_DeepAK8_decorr_decay",&probSum_DeepAK8_decorr_decay);
   outputTree->Branch("probSum_BEST_all",&probSum_BEST_all);
   outputTree->Branch("probSum_DeepAK8_all",&probSum_DeepAK8_all);
   outputTree->Branch("probSum_DeepAK8_decorr_all",&probSum_DeepAK8_decorr_all);
   outputTree->Branch("probSum_BEST_four",&probSum_BEST_four);
   outputTree->Branch("probSum_DeepAK8_four",&probSum_DeepAK8_four);
   outputTree->Branch("probSum_DeepAK8_decorr_four",&probSum_DeepAK8_decorr_four);
   outputTree->Branch("nB_BEST",&nB_BEST);
   outputTree->Branch("nH_BEST",&nH_BEST);
   outputTree->Branch("nJ_BEST",&nJ_BEST);
   outputTree->Branch("nT_BEST",&nT_BEST);
   outputTree->Branch("nW_BEST",&nW_BEST);
   outputTree->Branch("nZ_BEST",&nZ_BEST);
   outputTree->Branch("nB_DeepAK8",&nB_DeepAK8);
   outputTree->Branch("nH_DeepAK8",&nH_DeepAK8);
   outputTree->Branch("nJ_DeepAK8",&nJ_DeepAK8);
   outputTree->Branch("nT_DeepAK8",&nT_DeepAK8);
   outputTree->Branch("nW_DeepAK8",&nW_DeepAK8);
   outputTree->Branch("nZ_DeepAK8",&nZ_DeepAK8);
   outputTree->Branch("nB_DeepAK8_decorr",&nB_DeepAK8_decorr);
   outputTree->Branch("nH_DeepAK8_decorr",&nH_DeepAK8_decorr);
   outputTree->Branch("nJ_DeepAK8_decorr",&nJ_DeepAK8_decorr);
   outputTree->Branch("nT_DeepAK8_decorr",&nT_DeepAK8_decorr);
   outputTree->Branch("nW_DeepAK8_decorr",&nW_DeepAK8_decorr);
   outputTree->Branch("nZ_DeepAK8_decorr",&nZ_DeepAK8_decorr);
   outputTree->Branch("theJetAK8Truth_JetSubCalc_PtOrdered",&theJetAK8Truth_JetSubCalc_PtOrdered);
   outputTree->Branch("deltaR_leptonicparticle_AK8_PtOrdered",&deltaR_leptonicparticle_AK8_PtOrdered);
   outputTree->Branch("Tprime1_BEST_Mass",&Tprime1_BEST_Mass);
   outputTree->Branch("Tprime2_BEST_Mass",&Tprime2_BEST_Mass);
   outputTree->Branch("Tprime1_BEST_Pt",&Tprime1_BEST_Pt);
   outputTree->Branch("Tprime2_BEST_Pt",&Tprime2_BEST_Pt);
   outputTree->Branch("Tprime1_BEST_Eta",&Tprime1_BEST_Eta);
   outputTree->Branch("Tprime2_BEST_Eta",&Tprime2_BEST_Eta);
   outputTree->Branch("Tprime1_BEST_Phi",&Tprime1_BEST_Phi);
   outputTree->Branch("Tprime2_BEST_Phi",&Tprime2_BEST_Phi);
   outputTree->Branch("Tprime1_BEST_deltaR",&Tprime1_BEST_deltaR);
   outputTree->Branch("Tprime2_BEST_deltaR",&Tprime2_BEST_deltaR);
   outputTree->Branch("TprimeAvg_BEST_Mass",&TprimeAvg_BEST_Mass);
   outputTree->Branch("Tprime1_DeepAK8_Mass",&Tprime1_DeepAK8_Mass);
   outputTree->Branch("Tprime2_DeepAK8_Mass",&Tprime2_DeepAK8_Mass);
   outputTree->Branch("Tprime1_DeepAK8_Pt",&Tprime1_DeepAK8_Pt);
   outputTree->Branch("Tprime2_DeepAK8_Pt",&Tprime2_DeepAK8_Pt);
   outputTree->Branch("Tprime1_DeepAK8_Eta",&Tprime1_DeepAK8_Eta);
   outputTree->Branch("Tprime2_DeepAK8_Eta",&Tprime2_DeepAK8_Eta);
   outputTree->Branch("Tprime1_DeepAK8_Phi",&Tprime1_DeepAK8_Phi);
   outputTree->Branch("Tprime2_DeepAK8_Phi",&Tprime2_DeepAK8_Phi);
   outputTree->Branch("Tprime1_DeepAK8_deltaR",&Tprime1_DeepAK8_deltaR);
   outputTree->Branch("Tprime2_DeepAK8_deltaR",&Tprime2_DeepAK8_deltaR);
   outputTree->Branch("TprimeAvg_DeepAK8_Mass",&TprimeAvg_DeepAK8_Mass);
   outputTree->Branch("Tprime1_DeepAK8_decorr_Mass",&Tprime1_DeepAK8_decorr_Mass);
   outputTree->Branch("Tprime2_DeepAK8_decorr_Mass",&Tprime2_DeepAK8_decorr_Mass);
   outputTree->Branch("Tprime1_DeepAK8_decorr_Pt",&Tprime1_DeepAK8_decorr_Pt);
   outputTree->Branch("Tprime2_DeepAK8_decorr_Pt",&Tprime2_DeepAK8_decorr_Pt);
   outputTree->Branch("Tprime1_DeepAK8_decorr_Eta",&Tprime1_DeepAK8_decorr_Eta);
   outputTree->Branch("Tprime2_DeepAK8_decorr_Eta",&Tprime2_DeepAK8_decorr_Eta);
   outputTree->Branch("Tprime1_DeepAK8_decorr_Phi",&Tprime1_DeepAK8_decorr_Phi);
   outputTree->Branch("Tprime2_DeepAK8_decorr_Phi",&Tprime2_DeepAK8_decorr_Phi);
   outputTree->Branch("Tprime1_DeepAK8_decorr_deltaR",&Tprime1_DeepAK8_decorr_deltaR);
   outputTree->Branch("Tprime2_DeepAK8_decorr_deltaR",&Tprime2_DeepAK8_decorr_deltaR);
   outputTree->Branch("TprimeAvg_DeepAK8_decorr_Mass",&TprimeAvg_DeepAK8_decorr_Mass);
   outputTree->Branch("isValidVLQDecayMode_BEST",&validDecay_BEST);
   outputTree->Branch("isValidVLQDecayMode_DeepAK8",&validDecay_DeepAK8);
   outputTree->Branch("isValidVLQDecayMode_DeepAK8_decorr",&validDecay_DeepAK8_decorr);
   outputTree->Branch("taggedBWBW_BEST",&taggedBWBW_BEST);
   outputTree->Branch("taggedTHBW_BEST",&taggedTHBW_BEST);
   outputTree->Branch("taggedTHTH_BEST",&taggedTHTH_BEST);
   outputTree->Branch("taggedTZBW_BEST",&taggedTZBW_BEST);
   outputTree->Branch("taggedTZTH_BEST",&taggedTZTH_BEST);
   outputTree->Branch("taggedTZTZ_BEST",&taggedTZTZ_BEST);
   outputTree->Branch("taggedBWBW_DeepAK8",&taggedBWBW_DeepAK8);
   outputTree->Branch("taggedTHBW_DeepAK8",&taggedTHBW_DeepAK8);
   outputTree->Branch("taggedTHTH_DeepAK8",&taggedTHTH_DeepAK8);
   outputTree->Branch("taggedTZBW_DeepAK8",&taggedTZBW_DeepAK8);
   outputTree->Branch("taggedTZTH_DeepAK8",&taggedTZTH_DeepAK8);
   outputTree->Branch("taggedTZTZ_DeepAK8",&taggedTZTZ_DeepAK8);
   outputTree->Branch("taggedBWBW_DeepAK8_decorr",&taggedBWBW_DeepAK8_decorr);
   outputTree->Branch("taggedTHBW_DeepAK8_decorr",&taggedTHBW_DeepAK8_decorr);
   outputTree->Branch("taggedTHTH_DeepAK8_decorr",&taggedTHTH_DeepAK8_decorr);
   outputTree->Branch("taggedTZBW_DeepAK8_decorr",&taggedTZBW_DeepAK8_decorr);
   outputTree->Branch("taggedTZTH_DeepAK8_decorr",&taggedTZTH_DeepAK8_decorr);
   outputTree->Branch("taggedTZTZ_DeepAK8_decorr",&taggedTZTZ_DeepAK8_decorr);
   outputTree->Branch("highPtAK8Jet1_SoftDropCorrectedMass",&highPtAK8Jet1_SoftDropCorrectedMass);
   outputTree->Branch("highPtAK8Jet2_SoftDropCorrectedMass",&highPtAK8Jet2_SoftDropCorrectedMass);
   outputTree->Branch("highPtAK8Jet3_SoftDropCorrectedMass",&highPtAK8Jet3_SoftDropCorrectedMass);
   outputTree->Branch("W_mass",&W_mass);
   outputTree->Branch("t_mass",&t_mass);
   outputTree->Branch("EGammaGsfSF",&EGammaGsfSF,"EGammaGsfSF/F");
   outputTree->Branch("lepIdSF",&lepIdSF,"lepIdSF/F");
   outputTree->Branch("taggedXXXX_BEST",&taggedXXXX_BEST);
   outputTree->Branch("taggedXXXX_DeepAK8",&taggedXXXX_DeepAK8);
   outputTree->Branch("taggedXXXX_DeepAK8_decorr",&taggedXXXX_DeepAK8_decorr);
   outputTree->Branch("isLeptonic_t",&isLeptonic_t);
   outputTree->Branch("isLeptonic_W",&isLeptonic_W);
   outputTree->Branch("leptonicTprimeJetIDs_BEST",&leptonicTprimeJetIDs_BEST);
   outputTree->Branch("leptonicTprimeJetIDs_DeepAK8",&leptonicTprimeJetIDs_DeepAK8);
   outputTree->Branch("leptonicTprimeJetIDs_DeepAK8_decorr",&leptonicTprimeJetIDs_DeepAK8_decorr);
   outputTree->Branch("hadronicTprimeJetIDs_BEST",&hadronicTprimeJetIDs_BEST);
   outputTree->Branch("hadronicTprimeJetIDs_DeepAK8",&hadronicTprimeJetIDs_DeepAK8);
   outputTree->Branch("hadronicTprimeJetIDs_DeepAK8_decorr",&hadronicTprimeJetIDs_DeepAK8_decorr);

   // ----------------------------------------------------------------------------
   // Defining the 6 histograms for 3D probability plots
   // ----------------------------------------------------------------------------
   // TH3D *jProb_BEST = new TH3D("jProb_BEST","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *tProb_BEST = new TH3D("tProb_BEST","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *HProb_BEST = new TH3D("HProb_BEST","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *WProb_BEST = new TH3D("WProb_BEST","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *ZProb_BEST = new TH3D("ZProb_BEST","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *bProb_BEST = new TH3D("bProb_BEST","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *jProb_DeepAK8 = new TH3D("jProb_DeepAK8","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *tProb_DeepAK8 = new TH3D("tProb_DeepAK8","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *HProb_DeepAK8 = new TH3D("HProb_DeepAK8","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *WProb_DeepAK8 = new TH3D("WProb_DeepAK8","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *ZProb_DeepAK8 = new TH3D("ZProb_DeepAK8","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *bProb_DeepAK8 = new TH3D("bProb_DeepAK8","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *jProb_DeepAK8_decorr = new TH3D("jProb_DeepAK8_decorr","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *tProb_DeepAK8_decorr = new TH3D("tProb_DeepAK8_decorr","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *HProb_DeepAK8_decorr = new TH3D("HProb_DeepAK8_decorr","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *WProb_DeepAK8_decorr = new TH3D("WProb_DeepAK8_decorr","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *ZProb_DeepAK8_decorr = new TH3D("ZProb_DeepAK8_decorr","",200,-1,1,200,-1,1,200,-1,1);
   // TH3D *bProb_DeepAK8_decorr = new TH3D("bProb_DeepAK8_decorr","",200,-1,1,200,-1,1,200,-1,1);

   // TH2D *tProb_DeepAK8_ = new TH2D("tProb_DeepAK8_","",200,-1,1,200,-1,1);
   // TH2D *HProb_DeepAK8_ = new TH2D("HProb_DeepAK8_","",200,-1,1,200,-1,1);
   // TH2D *WProb_DeepAK8_ = new TH2D("WProb_DeepAK8_","",200,-1,1,200,-1,1);
   // TH2D *ZProb_DeepAK8_ = new TH2D("ZProb_DeepAK8_","",200,-1,1,200,-1,1);
   // TH2D *bProb_DeepAK8_ = new TH2D("bProb_DeepAK8_","",200,-1,1,200,-1,1);
  // ----------------------------------------------------------------------------
  // Define and initialize objects / cuts / efficiencies
  // ----------------------------------------------------------------------------



   // basic cuts
   float metCut=50;
   int   htCut=450;
   int   nAK8jetsCut=0;
   float JetLeadPtCut=0;
   float JetSubLeadPtCut=0;
   float lepPtCut=50;
   float elEtaCut=2.5;
   float muEtaCut=2.4;
   float jetEtaCut=2.4;
   float ak8EtaCut=2.4;
   float jetPtCut=30;

   // counters
   int n_vectorSizeMismatch = 0;

   int n_jetstotal        = 0;
   int n_jetsnearlep      = 0;
   int n_jetspassed       = 0;
   int npass_ThreeJets    = 0;
   int npass_trigger      = 0;
   int npass_mu500        = 0;
   int npass_met          = 0;
   int npass_ht           = 0;
   int npass_nAK8jets     = 0;
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
   

   // Pileup distributions -- 31Mar2018 Data vs RunIIFall17MC
   std::vector<std::vector<float>> pileupweight;
   std::vector<std::vector<float>> pileupweightUp;
   std::vector<std::vector<float>> pileupweightDn;
   pileupweight = {
     {2.627E-04, 2.950E-02, 3.845E-02, 6.129E-02, 7.067E-02, 1.038E-01, 1.276E-01, 1.488E-01, 1.050E-01, 3.197E-01, 4.811E-01, 6.165E-01, 6.699E-01, 7.030E-01, 7.332E-01, 7.987E-01, 8.958E-01, 9.917E-01, 1.083E+00, 1.145E+00, 1.204E+00, 1.252E+00, 1.292E+00, 1.325E+00, 1.342E+00, 1.346E+00, 1.351E+00, 1.358E+00, 1.368E+00, 1.355E+00, 1.323E+00, 1.260E+00, 1.197E+00, 1.133E+00, 1.057E+00, 9.937E-01, 9.487E-01, 9.072E-01, 8.591E-01, 8.169E-01, 8.251E-01, 8.610E-01, 9.336E-01, 1.047E+00, 1.193E+00, 1.356E+00, 1.538E+00, 1.612E+00, 1.625E+00, 1.577E+00, 1.402E+00, 1.210E+00, 1.006E+00, 7.882E-01, 5.993E-01, 4.287E-01, 3.047E-01, 2.107E-01, 1.456E-01, 1.024E-01, 7.315E-02, 5.335E-02, 4.065E-02, 3.040E-02, 2.403E-02, 1.784E-02, 1.262E-02, 1.095E-02, 9.353E-03, 8.596E-03, 7.320E-03, 6.155E-03, 6.241E-03, 4.710E-03, 3.440E-03, 2.819E-03, 2.363E-03, 1.809E-03, 1.251E-03, 4.036E-04},
     {3.544E-04, 3.998E-02, 4.526E-02, 7.801E-02, 9.146E-02, 1.097E-01, 1.527E-01, 2.427E-01, 1.278E-01, 4.256E-01, 5.532E-01, 6.663E-01, 6.732E-01, 7.100E-01, 7.715E-01, 8.042E-01, 9.015E-01, 9.917E-01, 1.066E+00, 1.131E+00, 1.189E+00, 1.253E+00, 1.282E+00, 1.315E+00, 1.325E+00, 1.339E+00, 1.339E+00, 1.339E+00, 1.362E+00, 1.336E+00, 1.297E+00, 1.239E+00, 1.190E+00, 1.117E+00, 1.039E+00, 9.847E-01, 9.359E-01, 8.988E-01, 8.460E-01, 8.122E-01, 8.128E-01, 8.503E-01, 9.144E-01, 1.020E+00, 1.173E+00, 1.348E+00, 1.525E+00, 1.596E+00, 1.638E+00, 1.565E+00, 1.346E+00, 1.213E+00, 9.796E-01, 7.891E-01, 5.957E-01, 4.270E-01, 3.022E-01, 2.079E-01, 1.453E-01, 1.013E-01, 7.242E-02, 5.264E-02, 4.040E-02, 3.102E-02, 2.399E-02, 1.754E-02, 1.216E-02, 1.027E-02, 9.501E-03, 8.830E-03, 7.677E-03, 5.254E-03, 6.172E-03, 5.941E-03, 3.630E-03, 4.188E-03, 2.190E-03, 1.532E-03, 1.240E-03, 5.375E-04},
     {1.749E-01, 4.172E+00, 3.462E+00, 2.677E+00, 1.657E+00, 1.475E+00, 1.255E+00, 1.247E+00, 6.000E-01, 1.423E+00, 1.498E+00, 1.492E+00, 1.325E+00, 1.164E+00, 1.082E+00, 1.052E+00, 1.083E+00, 1.127E+00, 1.163E+00, 1.191E+00, 1.212E+00, 1.241E+00, 1.255E+00, 1.270E+00, 1.274E+00, 1.273E+00, 1.272E+00, 1.268E+00, 1.278E+00, 1.250E+00, 1.223E+00, 1.171E+00, 1.111E+00, 1.036E+00, 9.706E-01, 9.104E-01, 8.681E-01, 8.332E-01, 7.862E-01, 7.510E-01, 7.602E-01, 7.926E-01, 8.584E-01, 9.577E-01, 1.096E+00, 1.256E+00, 1.416E+00, 1.494E+00, 1.526E+00, 1.468E+00, 1.336E+00, 1.152E+00, 9.528E-01, 7.484E-01, 5.701E-01, 4.122E-01, 2.880E-01, 1.984E-01, 1.374E-01, 9.694E-02, 6.917E-02, 5.072E-02, 3.857E-02, 2.990E-02, 2.407E-02, 1.711E-02, 1.255E-02, 1.081E-02, 9.624E-03, 8.906E-03, 8.153E-03, 8.132E-03, 7.845E-03, 7.748E-03, 6.232E-03, 5.267E-03, 5.608E-03, 6.070E-03, 6.121E-03, 6.164E-03},
     {1.672E-01, 4.002E+00, 3.617E+00, 2.548E+00, 1.509E+00, 1.493E+00, 1.296E+00, 1.240E+00, 6.044E-01, 1.455E+00, 1.498E+00, 1.488E+00, 1.340E+00, 1.174E+00, 1.086E+00, 1.052E+00, 1.083E+00, 1.128E+00, 1.168E+00, 1.181E+00, 1.205E+00, 1.236E+00, 1.259E+00, 1.272E+00, 1.271E+00, 1.272E+00, 1.271E+00, 1.267E+00, 1.278E+00, 1.251E+00, 1.219E+00, 1.164E+00, 1.109E+00, 1.038E+00, 9.689E-01, 9.156E-01, 8.645E-01, 8.359E-01, 7.875E-01, 7.518E-01, 7.621E-01, 7.939E-01, 8.594E-01, 9.634E-01, 1.096E+00, 1.255E+00, 1.424E+00, 1.511E+00, 1.535E+00, 1.457E+00, 1.342E+00, 1.153E+00, 9.464E-01, 7.538E-01, 5.673E-01, 4.094E-01, 2.882E-01, 1.995E-01, 1.377E-01, 9.630E-02, 6.899E-02, 5.090E-02, 3.856E-02, 2.996E-02, 2.428E-02, 1.692E-02, 1.250E-02, 1.081E-02, 9.817E-03, 8.680E-03, 8.324E-03, 8.295E-03, 7.672E-03, 7.872E-03, 6.039E-03, 5.129E-03, 5.624E-03, 5.494E-03, 6.660E-03, 5.473E-03},
     {2.758E-04, 2.979E-02, 4.481E-02, 7.384E-02, 6.863E-02, 1.116E-01, 1.301E-01, 1.552E-01, 1.058E-01, 3.333E-01, 5.015E-01, 6.410E-01, 6.712E-01, 7.089E-01, 7.387E-01, 8.027E-01, 9.054E-01, 9.982E-01, 1.086E+00, 1.149E+00, 1.200E+00, 1.257E+00, 1.302E+00, 1.324E+00, 1.342E+00, 1.344E+00, 1.353E+00, 1.352E+00, 1.366E+00, 1.349E+00, 1.320E+00, 1.250E+00, 1.194E+00, 1.130E+00, 1.055E+00, 9.941E-01, 9.461E-01, 9.058E-01, 8.535E-01, 8.164E-01, 8.234E-01, 8.614E-01, 9.270E-01, 1.046E+00, 1.190E+00, 1.357E+00, 1.530E+00, 1.580E+00, 1.623E+00, 1.552E+00, 1.396E+00, 1.203E+00, 9.963E-01, 7.804E-01, 5.990E-01, 4.260E-01, 3.034E-01, 2.091E-01, 1.455E-01, 1.023E-01, 7.260E-02, 5.320E-02, 4.007E-02, 3.055E-02, 2.303E-02, 1.753E-02, 1.254E-02, 1.085E-02, 8.972E-03, 8.785E-03, 7.276E-03, 6.235E-03, 5.168E-03, 6.401E-03, 3.540E-03, 3.876E-03, 2.529E-03, 1.391E-03, 1.006E-03, 5.000E-04},
     {2.494E-04, 3.158E-02, 3.862E-02, 5.765E-02, 7.191E-02, 1.117E-01, 1.001E-01, 1.299E-01, 1.084E-01, 3.222E-01, 4.813E-01, 6.202E-01, 6.505E-01, 7.113E-01, 7.297E-01, 7.877E-01, 9.025E-01, 1.013E+00, 1.094E+00, 1.148E+00, 1.211E+00, 1.252E+00, 1.304E+00, 1.336E+00, 1.347E+00, 1.356E+00, 1.354E+00, 1.365E+00, 1.369E+00, 1.351E+00, 1.328E+00, 1.258E+00, 1.202E+00, 1.130E+00, 1.059E+00, 9.882E-01, 9.494E-01, 9.124E-01, 8.601E-01, 8.192E-01, 8.230E-01, 8.637E-01, 9.387E-01, 1.048E+00, 1.188E+00, 1.354E+00, 1.540E+00, 1.616E+00, 1.634E+00, 1.572E+00, 1.388E+00, 1.224E+00, 1.001E+00, 7.875E-01, 5.981E-01, 4.347E-01, 3.054E-01, 2.086E-01, 1.461E-01, 1.012E-01, 7.329E-02, 5.338E-02, 4.046E-02, 3.013E-02, 2.390E-02, 1.758E-02, 1.241E-02, 1.099E-02, 9.904E-03, 8.385E-03, 7.029E-03, 5.092E-03, 5.896E-03, 4.427E-03, 3.156E-03, 3.957E-03, 2.318E-03, 2.368E-03, 1.121E-03, 5.284E-04},
     {2.960E-04, 4.661E-02, 5.142E-02, 7.836E-02, 7.650E-02, 1.158E-01, 1.384E-01, 1.598E-01, 1.298E-01, 4.088E-01, 5.108E-01, 6.759E-01, 7.111E-01, 7.069E-01, 7.569E-01, 8.221E-01, 9.024E-01, 9.951E-01, 1.083E+00, 1.143E+00, 1.196E+00, 1.243E+00, 1.290E+00, 1.319E+00, 1.335E+00, 1.333E+00, 1.349E+00, 1.351E+00, 1.349E+00, 1.339E+00, 1.312E+00, 1.253E+00, 1.187E+00, 1.126E+00, 1.046E+00, 9.803E-01, 9.405E-01, 9.074E-01, 8.515E-01, 8.155E-01, 8.172E-01, 8.621E-01, 9.268E-01, 1.040E+00, 1.184E+00, 1.351E+00, 1.528E+00, 1.601E+00, 1.645E+00, 1.555E+00, 1.395E+00, 1.202E+00, 1.009E+00, 7.834E-01, 5.907E-01, 4.264E-01, 3.005E-01, 2.080E-01, 1.442E-01, 1.016E-01, 7.377E-02, 5.274E-02, 4.028E-02, 2.943E-02, 2.345E-02, 1.733E-02, 1.304E-02, 1.089E-02, 9.218E-03, 8.375E-03, 7.196E-03, 4.961E-03, 5.212E-03, 4.817E-03, 2.602E-03, 3.627E-03, 2.491E-03, 2.361E-03, 6.611E-04, 6.415E-04},
     {2.894E-04, 4.360E-02, 5.014E-02, 6.912E-02, 8.141E-02, 1.445E-01, 1.405E-01, 1.480E-01, 1.039E-01, 3.417E-01, 4.570E-01, 6.214E-01, 6.927E-01, 6.701E-01, 6.820E-01, 8.060E-01, 8.304E-01, 9.961E-01, 1.076E+00, 1.131E+00, 1.193E+00, 1.219E+00, 1.294E+00, 1.326E+00, 1.323E+00, 1.350E+00, 1.362E+00, 1.348E+00, 1.360E+00, 1.339E+00, 1.311E+00, 1.262E+00, 1.185E+00, 1.131E+00, 1.058E+00, 1.002E+00, 9.544E-01, 9.065E-01, 8.609E-01, 8.214E-01, 8.346E-01, 8.601E-01, 9.398E-01, 1.059E+00, 1.200E+00, 1.364E+00, 1.510E+00, 1.641E+00, 1.590E+00, 1.542E+00, 1.397E+00, 1.237E+00, 1.003E+00, 8.001E-01, 5.921E-01, 4.271E-01, 3.083E-01, 2.139E-01, 1.458E-01, 1.017E-01, 7.216E-02, 5.370E-02, 4.107E-02, 3.045E-02, 2.474E-02, 1.765E-02, 1.298E-02, 1.070E-02, 9.453E-03, 9.417E-03, 7.668E-03, 4.481E-03, 3.087E-03, 6.682E-03, 3.068E-03, 1.882E-03, 1.948E-03, 5.821E-03, 1.565E-03, 3.780E-04},
     {1.800E-01, 3.572E+00, 3.238E+00, 2.501E+00, 1.587E+00, 1.524E+00, 1.259E+00, 1.234E+00, 6.249E-01, 1.469E+00, 1.489E+00, 1.493E+00, 1.332E+00, 1.168E+00, 1.077E+00, 1.050E+00, 1.085E+00, 1.129E+00, 1.164E+00, 1.190E+00, 1.213E+00, 1.238E+00, 1.258E+00, 1.270E+00, 1.275E+00, 1.274E+00, 1.272E+00, 1.267E+00, 1.276E+00, 1.252E+00, 1.223E+00, 1.169E+00, 1.110E+00, 1.035E+00, 9.696E-01, 9.107E-01, 8.679E-01, 8.329E-01, 7.873E-01, 7.513E-01, 7.580E-01, 7.947E-01, 8.584E-01, 9.582E-01, 1.093E+00, 1.255E+00, 1.420E+00, 1.496E+00, 1.525E+00, 1.468E+00, 1.336E+00, 1.156E+00, 9.496E-01, 7.491E-01, 5.688E-01, 4.106E-01, 2.897E-01, 1.987E-01, 1.380E-01, 9.650E-02, 6.927E-02, 5.094E-02, 3.836E-02, 2.994E-02, 2.412E-02, 1.694E-02, 1.244E-02, 1.079E-02, 9.658E-03, 8.864E-03, 8.303E-03, 8.066E-03, 7.846E-03, 7.957E-03, 6.113E-03, 5.381E-03, 5.472E-03, 5.358E-03, 5.970E-03, 6.237E-03},
     {2.605E-04, 2.631E-02, 3.681E-02, 4.785E-02, 7.677E-02, 1.316E-01, 9.301E-02, 1.018E-01, 1.079E-01, 4.031E-01, 4.383E-01, 6.138E-01, 6.870E-01, 7.113E-01, 7.262E-01, 8.072E-01, 8.834E-01, 9.917E-01, 1.070E+00, 1.134E+00, 1.185E+00, 1.256E+00, 1.307E+00, 1.338E+00, 1.329E+00, 1.353E+00, 1.370E+00, 1.381E+00, 1.371E+00, 1.359E+00, 1.336E+00, 1.252E+00, 1.208E+00, 1.133E+00, 1.066E+00, 9.925E-01, 9.398E-01, 9.187E-01, 8.526E-01, 8.198E-01, 8.374E-01, 8.628E-01, 9.381E-01, 1.055E+00, 1.208E+00, 1.350E+00, 1.567E+00, 1.627E+00, 1.624E+00, 1.558E+00, 1.401E+00, 1.214E+00, 1.002E+00, 7.880E-01, 5.921E-01, 4.393E-01, 3.076E-01, 2.087E-01, 1.429E-01, 1.036E-01, 7.355E-02, 5.130E-02, 3.955E-02, 3.146E-02, 2.366E-02, 1.726E-02, 1.258E-02, 1.092E-02, 1.015E-02, 9.365E-03, 6.013E-03, 3.590E-03, 4.496E-03, 4.837E-03, 6.140E-03, 4.341E-03, 1.343E-03, 4.228E-03, 5.226E-04, 7.545E-04},
     {2.607E-04, 2.222E-02, 4.369E-02, 5.655E-02, 7.639E-02, 9.580E-02, 1.022E-01, 1.921E-01, 1.312E-01, 3.306E-01, 5.204E-01, 6.816E-01, 6.607E-01, 6.635E-01, 7.260E-01, 7.893E-01, 9.209E-01, 1.004E+00, 1.098E+00, 1.158E+00, 1.206E+00, 1.268E+00, 1.289E+00, 1.328E+00, 1.341E+00, 1.340E+00, 1.358E+00, 1.349E+00, 1.383E+00, 1.356E+00, 1.331E+00, 1.242E+00, 1.211E+00, 1.133E+00, 1.049E+00, 9.995E-01, 9.512E-01, 9.076E-01, 8.579E-01, 8.202E-01, 8.377E-01, 8.753E-01, 9.439E-01, 1.041E+00, 1.193E+00, 1.341E+00, 1.525E+00, 1.574E+00, 1.593E+00, 1.569E+00, 1.366E+00, 1.206E+00, 1.021E+00, 7.956E-01, 6.034E-01, 4.278E-01, 3.102E-01, 2.086E-01, 1.461E-01, 1.031E-01, 7.383E-02, 5.028E-02, 4.112E-02, 3.090E-02, 2.154E-02, 1.732E-02, 1.306E-02, 1.068E-02, 9.153E-03, 8.133E-03, 6.713E-03, 5.319E-03, 3.989E-03, 8.444E-03, 1.941E-03, 4.946E-03, 2.976E-03, 3.784E-03, 5.910E-04, 2.521E-04},
     {1.780E-01, 5.124E+00, 3.340E+00, 2.752E+00, 1.532E+00, 1.502E+00, 1.283E+00, 1.247E+00, 6.408E-01, 1.423E+00, 1.493E+00, 1.501E+00, 1.316E+00, 1.161E+00, 1.081E+00, 1.048E+00, 1.081E+00, 1.129E+00, 1.170E+00, 1.190E+00, 1.214E+00, 1.239E+00, 1.258E+00, 1.269E+00, 1.274E+00, 1.270E+00, 1.265E+00, 1.265E+00, 1.274E+00, 1.253E+00, 1.220E+00, 1.173E+00, 1.111E+00, 1.039E+00, 9.675E-01, 9.125E-01, 8.687E-01, 8.348E-01, 7.882E-01, 7.476E-01, 7.592E-01, 7.946E-01, 8.570E-01, 9.614E-01, 1.095E+00, 1.257E+00, 1.418E+00, 1.502E+00, 1.533E+00, 1.460E+00, 1.343E+00, 1.154E+00, 9.496E-01, 7.457E-01, 5.701E-01, 4.112E-01, 2.882E-01, 1.982E-01, 1.382E-01, 9.659E-02, 6.902E-02, 5.065E-02, 3.841E-02, 3.010E-02, 2.401E-02, 1.713E-02, 1.250E-02, 1.079E-02, 9.623E-03, 8.901E-03, 8.297E-03, 8.180E-03, 7.698E-03, 7.869E-03, 6.500E-03, 5.429E-03, 5.453E-03, 5.933E-03, 5.511E-03, 5.550E-03},
     {1.829E-01, 3.581E+00, 3.653E+00, 2.510E+00, 1.605E+00, 1.528E+00, 1.253E+00, 1.264E+00, 6.156E-01, 1.469E+00, 1.500E+00, 1.473E+00, 1.340E+00, 1.166E+00, 1.074E+00, 1.057E+00, 1.075E+00, 1.127E+00, 1.169E+00, 1.188E+00, 1.212E+00, 1.238E+00, 1.260E+00, 1.272E+00, 1.272E+00, 1.272E+00, 1.270E+00, 1.266E+00, 1.275E+00, 1.250E+00, 1.224E+00, 1.167E+00, 1.110E+00, 1.039E+00, 9.682E-01, 9.119E-01, 8.667E-01, 8.359E-01, 7.903E-01, 7.499E-01, 7.578E-01, 7.936E-01, 8.595E-01, 9.557E-01, 1.098E+00, 1.254E+00, 1.419E+00, 1.500E+00, 1.529E+00, 1.462E+00, 1.339E+00, 1.152E+00, 9.470E-01, 7.516E-01, 5.683E-01, 4.100E-01, 2.894E-01, 1.993E-01, 1.372E-01, 9.685E-02, 6.914E-02, 5.076E-02, 3.851E-02, 2.990E-02, 2.414E-02, 1.714E-02, 1.249E-02, 1.084E-02, 9.637E-03, 8.826E-03, 8.251E-03, 7.945E-03, 7.913E-03, 7.839E-03, 6.205E-03, 5.395E-03, 5.376E-03, 5.855E-03, 5.805E-03, 5.727E-03},
     {2.326E-04, 2.787E-02, 3.339E-02, 5.035E-02, 6.247E-02, 9.966E-02, 1.074E-01, 1.442E-01, 1.041E-01, 3.121E-01, 4.634E-01, 6.124E-01, 6.707E-01, 6.990E-01, 7.462E-01, 8.168E-01, 9.110E-01, 1.022E+00, 1.100E+00, 1.156E+00, 1.212E+00, 1.261E+00, 1.307E+00, 1.336E+00, 1.353E+00, 1.354E+00, 1.353E+00, 1.360E+00, 1.376E+00, 1.354E+00, 1.326E+00, 1.264E+00, 1.198E+00, 1.132E+00, 1.062E+00, 9.996E-01, 9.498E-01, 9.122E-01, 8.609E-01, 8.217E-01, 8.276E-01, 8.657E-01, 9.451E-01, 1.048E+00, 1.196E+00, 1.360E+00, 1.538E+00, 1.600E+00, 1.634E+00, 1.581E+00, 1.403E+00, 1.211E+00, 9.999E-01, 7.865E-01, 5.984E-01, 4.296E-01, 3.034E-01, 2.107E-01, 1.463E-01, 1.024E-01, 7.337E-02, 5.378E-02, 4.052E-02, 3.077E-02, 2.339E-02, 1.753E-02, 1.269E-02, 1.092E-02, 9.353E-03, 9.002E-03, 7.919E-03, 4.869E-03, 6.104E-03, 4.942E-03, 3.426E-03, 2.660E-03, 2.304E-03, 2.039E-03, 1.059E-03, 5.481E-04},
     {2.328E-04, 3.090E-02, 4.163E-02, 4.817E-02, 5.984E-02, 9.593E-02, 1.055E-01, 1.605E-01, 1.151E-01, 3.110E-01, 4.780E-01, 6.027E-01, 6.617E-01, 6.884E-01, 7.227E-01, 7.992E-01, 8.973E-01, 1.001E+00, 1.085E+00, 1.149E+00, 1.217E+00, 1.260E+00, 1.303E+00, 1.342E+00, 1.352E+00, 1.359E+00, 1.367E+00, 1.366E+00, 1.386E+00, 1.359E+00, 1.335E+00, 1.267E+00, 1.203E+00, 1.130E+00, 1.060E+00, 9.983E-01, 9.556E-01, 9.185E-01, 8.634E-01, 8.242E-01, 8.302E-01, 8.673E-01, 9.375E-01, 1.051E+00, 1.194E+00, 1.359E+00, 1.540E+00, 1.593E+00, 1.626E+00, 1.570E+00, 1.398E+00, 1.220E+00, 9.918E-01, 7.834E-01, 5.988E-01, 4.256E-01, 3.069E-01, 2.102E-01, 1.467E-01, 1.022E-01, 7.271E-02, 5.372E-02, 4.035E-02, 3.002E-02, 2.315E-02, 1.791E-02, 1.267E-02, 1.052E-02, 9.544E-03, 8.520E-03, 8.017E-03, 6.324E-03, 6.082E-03, 5.663E-03, 2.850E-03, 3.110E-03, 2.375E-03, 1.463E-03, 1.312E-03, 4.850E-04},
     {2.564E-04, 3.837E-02, 3.059E-02, 5.322E-02, 6.786E-02, 9.388E-02, 1.256E-01, 1.484E-01, 1.033E-01, 3.382E-01, 4.688E-01, 6.103E-01, 6.883E-01, 6.948E-01, 7.502E-01, 8.297E-01, 9.089E-01, 9.969E-01, 1.095E+00, 1.143E+00, 1.203E+00, 1.262E+00, 1.306E+00, 1.333E+00, 1.348E+00, 1.344E+00, 1.349E+00, 1.360E+00, 1.371E+00, 1.356E+00, 1.326E+00, 1.267E+00, 1.197E+00, 1.129E+00, 1.052E+00, 9.949E-01, 9.485E-01, 9.147E-01, 8.563E-01, 8.183E-01, 8.310E-01, 8.650E-01, 9.384E-01, 1.046E+00, 1.197E+00, 1.363E+00, 1.533E+00, 1.615E+00, 1.624E+00, 1.580E+00, 1.390E+00, 1.200E+00, 1.008E+00, 7.782E-01, 5.965E-01, 4.190E-01, 3.025E-01, 2.105E-01, 1.457E-01, 1.019E-01, 7.269E-02, 5.390E-02, 4.059E-02, 3.069E-02, 2.300E-02, 1.719E-02, 1.252E-02, 1.121E-02, 9.765E-03, 7.860E-03, 8.231E-03, 5.744E-03, 4.478E-03, 5.989E-03, 2.354E-03, 2.470E-03, 1.666E-03, 2.406E-03, 1.619E-03, 3.990E-04},
     {3.098E-04, 2.532E-02, 7.010E-02, 5.975E-02, 5.345E-02, 7.526E-02, 8.972E-02, 1.506E-01, 1.019E-01, 4.177E-01, 4.905E-01, 6.736E-01, 7.624E-01, 7.185E-01, 8.202E-01, 7.980E-01, 8.954E-01, 1.013E+00, 1.087E+00, 1.149E+00, 1.210E+00, 1.250E+00, 1.304E+00, 1.345E+00, 1.342E+00, 1.349E+00, 1.356E+00, 1.341E+00, 1.364E+00, 1.326E+00, 1.323E+00, 1.231E+00, 1.202E+00, 1.088E+00, 1.043E+00, 9.859E-01, 9.468E-01, 9.123E-01, 8.560E-01, 8.090E-01, 8.177E-01, 8.259E-01, 9.266E-01, 1.030E+00, 1.172E+00, 1.328E+00, 1.537E+00, 1.607E+00, 1.641E+00, 1.598E+00, 1.403E+00, 1.203E+00, 1.024E+00, 7.923E-01, 5.926E-01, 4.400E-01, 3.034E-01, 2.112E-01, 1.464E-01, 1.046E-01, 7.418E-02, 5.522E-02, 3.982E-02, 2.936E-02, 2.511E-02, 1.870E-02, 1.296E-02, 9.903E-03, 9.423E-03, 9.231E-03, 6.472E-03, 7.884E-03, 4.329E-03, 2.418E-03, 3.861E-03, 2.891E-03, 5.423E-04, 6.677E-03, 4.057E-04, 3.023E-04},
     {4.708E-04, 1.701E+00, -1.578E+00, 9.121E-01, 7.486E-01, 5.589E-01, 6.530E-01, 7.658E-01, 3.456E-01, 8.560E-01, 7.973E-01, 8.156E-01, 7.265E-01, 7.858E-01, 1.014E+00, 1.050E+00, 1.065E+00, 1.061E+00, 1.177E+00, 1.207E+00, 1.204E+00, 1.295E+00, 1.282E+00, 1.308E+00, 1.332E+00, 1.341E+00, 1.295E+00, 1.213E+00, 1.124E+00, 1.338E+00, 1.282E+00, 1.244E+00, 9.802E-01, 1.026E+00, 1.055E+00, 9.854E-01, 9.301E-01, 8.898E-01, 7.931E-01, 7.788E-01, 7.278E-01, 8.297E-01, 9.476E-01, 1.002E+00, 1.184E+00, 1.341E+00, 1.580E+00, 1.553E+00, 1.629E+00, 1.606E+00, 1.476E+00, 1.237E+00, 9.413E-01, 7.969E-01, 5.947E-01, 4.415E-01, 3.248E-01, 2.170E-01, 1.507E-01, 1.046E-01, 6.915E-02, 5.408E-02, 1.983E-02, 3.311E-02, 2.035E-02, 1.957E-02, 1.242E-02, 1.083E-02, 8.955E-03, 6.824E-03, 8.855E-03, 8.707E-03, 6.040E-03, 1.291E-02, 7.450E-03, 4.775E-03, 5.259E-03, 4.108E-03, 5.489E-03, 5.481E-03},
     {2.406E-04, 3.385E-02, 3.578E-02, 5.432E-02, 6.220E-02, 9.562E-02, 1.249E-01, 1.405E-01, 1.066E-01, 3.192E-01, 4.762E-01, 6.200E-01, 6.800E-01, 7.151E-01, 7.432E-01, 7.980E-01, 8.981E-01, 1.007E+00, 1.090E+00, 1.145E+00, 1.208E+00, 1.252E+00, 1.304E+00, 1.329E+00, 1.345E+00, 1.349E+00, 1.354E+00, 1.362E+00, 1.372E+00, 1.359E+00, 1.325E+00, 1.259E+00, 1.200E+00, 1.133E+00, 1.059E+00, 9.963E-01, 9.505E-01, 9.115E-01, 8.607E-01, 8.247E-01, 8.266E-01, 8.668E-01, 9.347E-01, 1.045E+00, 1.196E+00, 1.369E+00, 1.551E+00, 1.602E+00, 1.626E+00, 1.571E+00, 1.409E+00, 1.217E+00, 1.005E+00, 7.886E-01, 6.010E-01, 4.290E-01, 3.019E-01, 2.112E-01, 1.465E-01, 1.022E-01, 7.362E-02, 5.391E-02, 4.057E-02, 3.021E-02, 2.415E-02, 1.752E-02, 1.257E-02, 1.084E-02, 9.528E-03, 8.775E-03, 7.496E-03, 5.919E-03, 5.381E-03, 5.185E-03, 4.161E-03, 3.090E-03, 1.867E-03, 1.701E-03, 9.188E-04, 5.315E-04},
     {2.315E-01, 3.072E+00, 2.850E+00, 2.379E+00, 1.814E+00, 1.427E+00, 1.502E+00, 1.198E+00, 6.637E-01, 1.478E+00, 1.465E+00, 1.593E+00, 1.334E+00, 1.162E+00, 1.089E+00, 1.052E+00, 1.074E+00, 1.133E+00, 1.161E+00, 1.196E+00, 1.212E+00, 1.235E+00, 1.260E+00, 1.276E+00, 1.285E+00, 1.278E+00, 1.270E+00, 1.259E+00, 1.272E+00, 1.265E+00, 1.203E+00, 1.151E+00, 1.119E+00, 1.035E+00, 9.633E-01, 9.135E-01, 8.644E-01, 8.412E-01, 7.865E-01, 7.494E-01, 7.635E-01, 7.874E-01, 8.475E-01, 9.577E-01, 1.104E+00, 1.274E+00, 1.419E+00, 1.490E+00, 1.524E+00, 1.496E+00, 1.342E+00, 1.169E+00, 9.458E-01, 7.514E-01, 5.769E-01, 4.126E-01, 2.925E-01, 2.000E-01, 1.368E-01, 9.616E-02, 6.762E-02, 5.076E-02, 3.781E-02, 2.879E-02, 2.332E-02, 1.717E-02, 1.265E-02, 1.079E-02, 9.486E-03, 9.464E-03, 8.739E-03, 8.339E-03, 8.351E-03, 7.462E-03, 7.104E-03, 5.085E-03, 4.805E-03, 6.677E-03, 5.575E-03, 5.164E-03},
     {2.174E-01, 2.227E+00, 2.479E+00, 2.328E+00, 1.704E+00, 1.940E+00, 1.549E+00, 1.289E+00, 5.517E-01, 1.441E+00, 1.490E+00, 1.434E+00, 1.362E+00, 1.171E+00, 1.073E+00, 1.050E+00, 1.080E+00, 1.120E+00, 1.159E+00, 1.167E+00, 1.210E+00, 1.239E+00, 1.259E+00, 1.290E+00, 1.269E+00, 1.256E+00, 1.265E+00, 1.263E+00, 1.287E+00, 1.244E+00, 1.225E+00, 1.178E+00, 1.111E+00, 1.037E+00, 9.787E-01, 9.073E-01, 8.541E-01, 8.298E-01, 7.933E-01, 7.530E-01, 7.696E-01, 7.966E-01, 8.582E-01, 9.675E-01, 1.092E+00, 1.266E+00, 1.416E+00, 1.513E+00, 1.557E+00, 1.461E+00, 1.341E+00, 1.135E+00, 9.446E-01, 7.411E-01, 5.572E-01, 4.133E-01, 2.920E-01, 1.992E-01, 1.383E-01, 9.723E-02, 6.830E-02, 5.173E-02, 3.840E-02, 3.008E-02, 2.393E-02, 1.743E-02, 1.259E-02, 1.057E-02, 9.381E-03, 8.891E-03, 8.430E-03, 7.669E-03, 8.314E-03, 8.597E-03, 6.436E-03, 6.161E-03, 5.354E-03, 5.808E-03, 7.759E-03, 4.967E-03},
     {1.572E-01, 2.823E+00, 3.055E+00, 2.295E+00, 1.478E+00, 1.373E+00, 1.264E+00, 1.132E+00, 6.411E-01, 1.457E+00, 1.430E+00, 1.465E+00, 1.362E+00, 1.154E+00, 1.093E+00, 1.051E+00, 1.061E+00, 1.118E+00, 1.178E+00, 1.191E+00, 1.207E+00, 1.267E+00, 1.251E+00, 1.274E+00, 1.267E+00, 1.288E+00, 1.274E+00, 1.276E+00, 1.269E+00, 1.253E+00, 1.226E+00, 1.163E+00, 1.108E+00, 1.031E+00, 9.792E-01, 9.190E-01, 8.577E-01, 8.364E-01, 7.998E-01, 7.505E-01, 7.587E-01, 7.996E-01, 8.608E-01, 9.585E-01, 1.094E+00, 1.239E+00, 1.403E+00, 1.476E+00, 1.520E+00, 1.470E+00, 1.327E+00, 1.124E+00, 9.653E-01, 7.601E-01, 5.713E-01, 4.137E-01, 2.874E-01, 1.990E-01, 1.410E-01, 9.522E-02, 6.876E-02, 4.921E-02, 3.726E-02, 2.983E-02, 2.373E-02, 1.658E-02, 1.257E-02, 1.075E-02, 9.609E-03, 8.271E-03, 8.340E-03, 8.770E-03, 7.378E-03, 7.303E-03, 5.912E-03, 5.315E-03, 7.372E-03, 6.092E-03, 5.033E-03, 5.305E-03},
     {2.160E-01, 2.263E+00, 1.119E+01, 2.336E+00, 1.736E+00, 1.510E+00, 1.077E+00, 1.176E+00, 7.053E-01, 1.423E+00, 1.569E+00, 1.440E+00, 1.375E+00, 1.159E+00, 1.075E+00, 1.069E+00, 1.062E+00, 1.133E+00, 1.158E+00, 1.204E+00, 1.216E+00, 1.240E+00, 1.263E+00, 1.282E+00, 1.286E+00, 1.287E+00, 1.260E+00, 1.280E+00, 1.266E+00, 1.247E+00, 1.234E+00, 1.178E+00, 1.121E+00, 1.030E+00, 9.682E-01, 9.054E-01, 8.685E-01, 8.296E-01, 7.917E-01, 7.498E-01, 7.487E-01, 7.899E-01, 8.571E-01, 9.687E-01, 1.098E+00, 1.254E+00, 1.410E+00, 1.492E+00, 1.542E+00, 1.455E+00, 1.350E+00, 1.139E+00, 9.516E-01, 7.482E-01, 5.658E-01, 4.106E-01, 2.926E-01, 1.957E-01, 1.395E-01, 9.392E-02, 6.780E-02, 5.034E-02, 3.757E-02, 3.000E-02, 2.382E-02, 1.738E-02, 1.216E-02, 1.105E-02, 9.388E-03, 8.357E-03, 8.885E-03, 8.099E-03, 7.050E-03, 6.724E-03, 6.228E-03, 4.828E-03, 5.222E-03, 5.245E-03, 7.617E-03, 7.289E-03},
     {2.423E-01, 4.315E+00, 2.464E+00, 2.864E+00, 1.174E+00, 1.485E+00, 1.268E+00, 1.222E+00, 5.845E-01, 1.453E+00, 1.426E+00, 1.488E+00, 1.321E+00, 1.167E+00, 1.076E+00, 1.052E+00, 1.066E+00, 1.122E+00, 1.151E+00, 1.206E+00, 1.209E+00, 1.239E+00, 1.250E+00, 1.286E+00, 1.282E+00, 1.269E+00, 1.251E+00, 1.263E+00, 1.273E+00, 1.269E+00, 1.204E+00, 1.178E+00, 1.108E+00, 1.043E+00, 9.572E-01, 9.212E-01, 8.694E-01, 8.428E-01, 7.893E-01, 7.578E-01, 7.580E-01, 7.940E-01, 8.664E-01, 9.559E-01, 1.096E+00, 1.248E+00, 1.412E+00, 1.500E+00, 1.509E+00, 1.463E+00, 1.369E+00, 1.149E+00, 9.606E-01, 7.550E-01, 5.693E-01, 4.126E-01, 2.883E-01, 1.976E-01, 1.379E-01, 9.559E-02, 6.876E-02, 5.059E-02, 3.842E-02, 3.008E-02, 2.387E-02, 1.667E-02, 1.304E-02, 1.021E-02, 1.031E-02, 8.361E-03, 8.001E-03, 8.146E-03, 7.446E-03, 8.348E-03, 5.815E-03, 4.387E-03, 4.728E-03, 6.252E-03, 4.515E-03, 5.561E-03},
{1.617E-01, 4.064E+00, 2.742E+00, 2.266E+00, 1.559E+00, 1.377E+00, 1.402E+00, 1.178E+00, 6.902E-01, 1.501E+00, 1.659E+00, 1.587E+00, 1.368E+00, 1.170E+00, 1.114E+00, 1.061E+00, 1.092E+00, 1.130E+00, 1.172E+00, 1.207E+00, 1.183E+00, 1.234E+00, 1.261E+00, 1.254E+00, 1.287E+00, 1.263E+00, 1.272E+00, 1.246E+00, 1.266E+00, 1.262E+00, 1.218E+00, 1.166E+00, 1.121E+00, 1.039E+00, 9.762E-01, 8.993E-01, 8.753E-01, 8.349E-01, 7.893E-01, 7.575E-01, 7.539E-01, 7.984E-01, 8.531E-01, 9.740E-01, 1.119E+00, 1.251E+00, 1.404E+00, 1.488E+00, 1.556E+00, 1.446E+00, 1.355E+00, 1.132E+00, 9.286E-01, 7.537E-01, 5.683E-01, 4.106E-01, 2.881E-01, 1.966E-01, 1.355E-01, 9.763E-02, 6.776E-02, 5.132E-02, 3.890E-02, 2.995E-02, 2.371E-02, 1.746E-02, 1.324E-02, 1.051E-02, 9.834E-03, 8.969E-03, 7.766E-03, 7.762E-03, 8.075E-03, 9.524E-03, 8.243E-03, 5.045E-03, 5.098E-03, 4.711E-03, 4.371E-03, 6.547E-03},
     {3.073E-01, 2.023E+00, 2.628E+00, 2.467E+00, 1.432E+00, 1.146E+00, 1.139E+00, 1.750E+00, 5.444E-01, 1.307E+00, 1.464E+00, 1.483E+00, 1.358E+00, 1.188E+00, 1.069E+00, 1.036E+00, 1.110E+00, 1.127E+00, 1.156E+00, 1.209E+00, 1.195E+00, 1.237E+00, 1.262E+00, 1.289E+00, 1.287E+00, 1.264E+00, 1.262E+00, 1.249E+00, 1.281E+00, 1.250E+00, 1.228E+00, 1.186E+00, 1.097E+00, 1.033E+00, 9.705E-01, 9.052E-01, 8.553E-01, 8.536E-01, 7.986E-01, 7.560E-01, 7.652E-01, 8.156E-01, 8.463E-01, 9.698E-01, 1.088E+00, 1.243E+00, 1.417E+00, 1.469E+00, 1.544E+00, 1.439E+00, 1.331E+00, 1.134E+00, 9.276E-01, 7.655E-01, 5.659E-01, 4.075E-01, 2.903E-01, 1.991E-01, 1.353E-01, 9.565E-02, 6.819E-02, 5.082E-02, 3.936E-02, 2.947E-02, 2.426E-02, 1.780E-02, 1.251E-02, 1.031E-02, 1.034E-02, 9.703E-03, 8.115E-03, 7.457E-03, 6.907E-03, 6.714E-03, 5.733E-03, 7.032E-03, 5.893E-03, 4.560E-03, 7.615E-03, 4.148E-03},
     {1.575E-01, 2.376E+00, 5.511E+00, 4.140E+00, 2.222E+00, 1.022E+00, 1.414E+00, 1.012E+00, 5.570E-01, 1.627E+00, 1.349E+00, 1.507E+00, 1.347E+00, 1.251E+00, 1.103E+00, 1.054E+00, 1.092E+00, 1.122E+00, 1.182E+00, 1.167E+00, 1.212E+00, 1.234E+00, 1.264E+00, 1.287E+00, 1.260E+00, 1.284E+00, 1.277E+00, 1.250E+00, 1.300E+00, 1.262E+00, 1.246E+00, 1.159E+00, 1.099E+00, 1.041E+00, 9.627E-01, 9.212E-01, 8.749E-01, 8.307E-01, 7.929E-01, 7.360E-01, 7.686E-01, 7.892E-01, 8.466E-01, 9.500E-01, 1.047E+00, 1.288E+00, 1.426E+00, 1.505E+00, 1.517E+00, 1.455E+00, 1.287E+00, 1.121E+00, 9.316E-01, 7.538E-01, 5.805E-01, 4.069E-01, 2.963E-01, 1.982E-01, 1.402E-01, 9.389E-02, 6.983E-02, 5.031E-02, 3.893E-02, 3.000E-02, 2.573E-02, 1.678E-02, 1.244E-02, 1.088E-02, 9.356E-03, 8.698E-03, 8.022E-03, 6.875E-03, 1.100E-02, 9.955E-03, 7.337E-03, 4.677E-03, 6.427E-03, 6.148E-03, 8.214E-03, 3.827E-03},
     {1.870E-01, 4.744E+00, 3.217E+00, 2.383E+00, 1.802E+00, 1.486E+00, 1.329E+00, 1.205E+00, 6.102E-01, 1.495E+00, 1.516E+00, 1.478E+00, 1.319E+00, 1.164E+00, 1.076E+00, 1.050E+00, 1.080E+00, 1.130E+00, 1.165E+00, 1.189E+00, 1.212E+00, 1.236E+00, 1.258E+00, 1.271E+00, 1.271E+00, 1.272E+00, 1.272E+00, 1.268E+00, 1.277E+00, 1.253E+00, 1.221E+00, 1.169E+00, 1.109E+00, 1.039E+00, 9.688E-01, 9.133E-01, 8.658E-01, 8.371E-01, 7.900E-01, 7.512E-01, 7.587E-01, 7.925E-01, 8.574E-01, 9.586E-01, 1.093E+00, 1.257E+00, 1.420E+00, 1.493E+00, 1.527E+00, 1.462E+00, 1.338E+00, 1.155E+00, 9.495E-01, 7.493E-01, 5.703E-01, 4.107E-01, 2.901E-01, 1.994E-01, 1.376E-01, 9.651E-02, 6.895E-02, 5.073E-02, 3.841E-02, 2.999E-02, 2.412E-02, 1.701E-02, 1.244E-02, 1.072E-02, 9.630E-03, 8.829E-03, 8.312E-03, 8.101E-03, 7.724E-03, 7.905E-03, 6.299E-03, 5.287E-03, 5.476E-03, 5.776E-03, 5.866E-03, 6.320E-03},
     {1.913E-01, 4.255E+00, 3.444E+00, 2.481E+00, 1.640E+00, 1.531E+00, 1.288E+00, 1.270E+00, 5.997E-01, 1.442E+00, 1.477E+00, 1.476E+00, 1.330E+00, 1.169E+00, 1.083E+00, 1.051E+00, 1.078E+00, 1.126E+00, 1.166E+00, 1.188E+00, 1.211E+00, 1.238E+00, 1.256E+00, 1.271E+00, 1.273E+00, 1.274E+00, 1.271E+00, 1.267E+00, 1.274E+00, 1.254E+00, 1.220E+00, 1.167E+00, 1.113E+00, 1.037E+00, 9.688E-01, 9.129E-01, 8.681E-01, 8.336E-01, 7.865E-01, 7.516E-01, 7.576E-01, 7.948E-01, 8.593E-01, 9.561E-01, 1.097E+00, 1.258E+00, 1.421E+00, 1.492E+00, 1.534E+00, 1.461E+00, 1.341E+00, 1.156E+00, 9.519E-01, 7.507E-01, 5.693E-01, 4.101E-01, 2.896E-01, 1.981E-01, 1.374E-01, 9.658E-02, 6.937E-02, 5.074E-02, 3.867E-02, 2.989E-02, 2.413E-02, 1.713E-02, 1.250E-02, 1.076E-02, 9.502E-03, 8.767E-03, 8.258E-03, 8.063E-03, 7.855E-03, 7.777E-03, 6.306E-03, 5.442E-03, 5.528E-03, 5.516E-03, 6.168E-03, 5.712E-03},
     {1.898E-01, 4.165E+00, 3.239E+00, 2.648E+00, 1.610E+00, 1.494E+00, 1.289E+00, 1.238E+00, 6.235E-01, 1.438E+00, 1.486E+00, 1.484E+00, 1.339E+00, 1.165E+00, 1.076E+00, 1.050E+00, 1.080E+00, 1.129E+00, 1.168E+00, 1.188E+00, 1.213E+00, 1.239E+00, 1.262E+00, 1.272E+00, 1.272E+00, 1.269E+00, 1.273E+00, 1.266E+00, 1.276E+00, 1.250E+00, 1.221E+00, 1.171E+00, 1.110E+00, 1.038E+00, 9.687E-01, 9.137E-01, 8.687E-01, 8.352E-01, 7.870E-01, 7.480E-01, 7.602E-01, 7.922E-01, 8.591E-01, 9.607E-01, 1.091E+00, 1.255E+00, 1.415E+00, 1.496E+00, 1.528E+00, 1.460E+00, 1.339E+00, 1.154E+00, 9.493E-01, 7.497E-01, 5.703E-01, 4.105E-01, 2.896E-01, 1.985E-01, 1.373E-01, 9.672E-02, 6.940E-02, 5.067E-02, 3.834E-02, 3.009E-02, 2.403E-02, 1.718E-02, 1.255E-02, 1.087E-02, 9.529E-03, 8.865E-03, 8.370E-03, 7.970E-03, 7.921E-03, 7.850E-03, 6.155E-03, 5.393E-03, 5.518E-03, 5.859E-03, 5.714E-03, 6.418E-03},
     {1.897E-01, 3.957E+00, 3.856E+00, 2.684E+00, 1.643E+00, 1.480E+00, 1.304E+00, 1.284E+00, 6.124E-01, 1.434E+00, 1.497E+00, 1.483E+00, 1.326E+00, 1.166E+00, 1.080E+00, 1.051E+00, 1.074E+00, 1.126E+00, 1.163E+00, 1.187E+00, 1.212E+00, 1.238E+00, 1.260E+00, 1.268E+00, 1.274E+00, 1.274E+00, 1.270E+00, 1.269E+00, 1.277E+00, 1.252E+00, 1.224E+00, 1.171E+00, 1.110E+00, 1.038E+00, 9.698E-01, 9.114E-01, 8.652E-01, 8.348E-01, 7.895E-01, 7.498E-01, 7.574E-01, 7.921E-01, 8.594E-01, 9.566E-01, 1.096E+00, 1.260E+00, 1.419E+00, 1.496E+00, 1.534E+00, 1.465E+00, 1.340E+00, 1.157E+00, 9.516E-01, 7.506E-01, 5.693E-01, 4.110E-01, 2.894E-01, 1.974E-01, 1.380E-01, 9.660E-02, 6.948E-02, 5.088E-02, 3.837E-02, 2.965E-02, 2.417E-02, 1.699E-02, 1.248E-02, 1.080E-02, 9.539E-03, 8.775E-03, 8.265E-03, 8.058E-03, 7.837E-03, 7.898E-03, 6.202E-03, 5.428E-03, 5.554E-03, 5.352E-03, 5.705E-03, 6.037E-03},
     {1.899E-01, 3.543E+00, 3.519E+00, 2.642E+00, 1.581E+00, 1.495E+00, 1.296E+00, 1.289E+00, 6.150E-01, 1.486E+00, 1.474E+00, 1.479E+00, 1.324E+00, 1.167E+00, 1.074E+00, 1.054E+00, 1.080E+00, 1.133E+00, 1.165E+00, 1.186E+00, 1.215E+00, 1.238E+00, 1.261E+00, 1.271E+00, 1.273E+00, 1.274E+00, 1.268E+00, 1.265E+00, 1.274E+00, 1.253E+00, 1.223E+00, 1.171E+00, 1.109E+00, 1.036E+00, 9.682E-01, 9.106E-01, 8.671E-01, 8.343E-01, 7.894E-01, 7.523E-01, 7.561E-01, 7.949E-01, 8.588E-01, 9.588E-01, 1.095E+00, 1.253E+00, 1.420E+00, 1.494E+00, 1.534E+00, 1.461E+00, 1.336E+00, 1.154E+00, 9.528E-01, 7.531E-01, 5.697E-01, 4.117E-01, 2.903E-01, 1.985E-01, 1.375E-01, 9.617E-02, 6.911E-02, 5.078E-02, 3.842E-02, 2.983E-02, 2.402E-02, 1.707E-02, 1.242E-02, 1.086E-02, 9.659E-03, 8.759E-03, 8.298E-03, 8.003E-03, 7.673E-03, 7.920E-03, 6.423E-03, 5.314E-03, 5.516E-03, 5.349E-03, 5.832E-03, 5.663E-03},
   };

   pileupweightUp = {  // 66016 ub
     {2.627E-04, 2.950E-02, 3.845E-02, 6.129E-02, 7.067E-02, 1.038E-01, 1.276E-01, 1.488E-01, 1.050E-01, 3.197E-01, 4.811E-01, 6.165E-01, 6.699E-01, 7.030E-01, 7.332E-01, 7.987E-01, 8.958E-01, 9.917E-01, 1.083E+00, 1.145E+00, 1.204E+00, 1.252E+00, 1.292E+00, 1.325E+00, 1.342E+00, 1.346E+00, 1.351E+00, 1.358E+00, 1.368E+00, 1.355E+00, 1.323E+00, 1.260E+00, 1.197E+00, 1.133E+00, 1.057E+00, 9.937E-01, 9.487E-01, 9.072E-01, 8.591E-01, 8.169E-01, 8.251E-01, 8.610E-01, 9.336E-01, 1.047E+00, 1.193E+00, 1.356E+00, 1.538E+00, 1.612E+00, 1.625E+00, 1.577E+00, 1.402E+00, 1.210E+00, 1.006E+00, 7.882E-01, 5.993E-01, 4.287E-01, 3.047E-01, 2.107E-01, 1.456E-01, 1.024E-01, 7.315E-02, 5.335E-02, 4.065E-02, 3.040E-02, 2.403E-02, 1.784E-02, 1.262E-02, 1.095E-02, 9.353E-03, 8.596E-03, 7.320E-03, 6.155E-03, 6.241E-03, 4.710E-03, 3.440E-03, 2.819E-03, 2.363E-03, 1.809E-03, 1.251E-03, 4.036E-04},
     {3.544E-04, 3.998E-02, 4.526E-02, 7.801E-02, 9.146E-02, 1.097E-01, 1.527E-01, 2.427E-01, 1.278E-01, 4.256E-01, 5.532E-01, 6.663E-01, 6.732E-01, 7.100E-01, 7.715E-01, 8.042E-01, 9.015E-01, 9.917E-01, 1.066E+00, 1.131E+00, 1.189E+00, 1.253E+00, 1.282E+00, 1.315E+00, 1.325E+00, 1.339E+00, 1.339E+00, 1.339E+00, 1.362E+00, 1.336E+00, 1.297E+00, 1.239E+00, 1.190E+00, 1.117E+00, 1.039E+00, 9.847E-01, 9.359E-01, 8.988E-01, 8.460E-01, 8.122E-01, 8.128E-01, 8.503E-01, 9.144E-01, 1.020E+00, 1.173E+00, 1.348E+00, 1.525E+00, 1.596E+00, 1.638E+00, 1.565E+00, 1.346E+00, 1.213E+00, 9.796E-01, 7.891E-01, 5.957E-01, 4.270E-01, 3.022E-01, 2.079E-01, 1.453E-01, 1.013E-01, 7.242E-02, 5.264E-02, 4.040E-02, 3.102E-02, 2.399E-02, 1.754E-02, 1.216E-02, 1.027E-02, 9.501E-03, 8.830E-03, 7.677E-03, 5.254E-03, 6.172E-03, 5.941E-03, 3.630E-03, 4.188E-03, 2.190E-03, 1.532E-03, 1.240E-03, 5.375E-04},
     {1.749E-01, 4.172E+00, 3.462E+00, 2.677E+00, 1.657E+00, 1.475E+00, 1.255E+00, 1.247E+00, 6.000E-01, 1.423E+00, 1.498E+00, 1.492E+00, 1.325E+00, 1.164E+00, 1.082E+00, 1.052E+00, 1.083E+00, 1.127E+00, 1.163E+00, 1.191E+00, 1.212E+00, 1.241E+00, 1.255E+00, 1.270E+00, 1.274E+00, 1.273E+00, 1.272E+00, 1.268E+00, 1.278E+00, 1.250E+00, 1.223E+00, 1.171E+00, 1.111E+00, 1.036E+00, 9.706E-01, 9.104E-01, 8.681E-01, 8.332E-01, 7.862E-01, 7.510E-01, 7.602E-01, 7.926E-01, 8.584E-01, 9.577E-01, 1.096E+00, 1.256E+00, 1.416E+00, 1.494E+00, 1.526E+00, 1.468E+00, 1.336E+00, 1.152E+00, 9.528E-01, 7.484E-01, 5.701E-01, 4.122E-01, 2.880E-01, 1.984E-01, 1.374E-01, 9.694E-02, 6.917E-02, 5.072E-02, 3.857E-02, 2.990E-02, 2.407E-02, 1.711E-02, 1.255E-02, 1.081E-02, 9.624E-03, 8.906E-03, 8.153E-03, 8.132E-03, 7.845E-03, 7.748E-03, 6.232E-03, 5.267E-03, 5.608E-03, 6.070E-03, 6.121E-03, 6.164E-03},
     {1.672E-01, 4.002E+00, 3.617E+00, 2.548E+00, 1.509E+00, 1.493E+00, 1.296E+00, 1.240E+00, 6.044E-01, 1.455E+00, 1.498E+00, 1.488E+00, 1.340E+00, 1.174E+00, 1.086E+00, 1.052E+00, 1.083E+00, 1.128E+00, 1.168E+00, 1.181E+00, 1.205E+00, 1.236E+00, 1.259E+00, 1.272E+00, 1.271E+00, 1.272E+00, 1.271E+00, 1.267E+00, 1.278E+00, 1.251E+00, 1.219E+00, 1.164E+00, 1.109E+00, 1.038E+00, 9.689E-01, 9.156E-01, 8.645E-01, 8.359E-01, 7.875E-01, 7.518E-01, 7.621E-01, 7.939E-01, 8.594E-01, 9.634E-01, 1.096E+00, 1.255E+00, 1.424E+00, 1.511E+00, 1.535E+00, 1.457E+00, 1.342E+00, 1.153E+00, 9.464E-01, 7.538E-01, 5.673E-01, 4.094E-01, 2.882E-01, 1.995E-01, 1.377E-01, 9.630E-02, 6.899E-02, 5.090E-02, 3.856E-02, 2.996E-02, 2.428E-02, 1.692E-02, 1.250E-02, 1.081E-02, 9.817E-03, 8.680E-03, 8.324E-03, 8.295E-03, 7.672E-03, 7.872E-03, 6.039E-03, 5.129E-03, 5.624E-03, 5.494E-03, 6.660E-03, 5.473E-03},
     {2.758E-04, 2.979E-02, 4.481E-02, 7.384E-02, 6.863E-02, 1.116E-01, 1.301E-01, 1.552E-01, 1.058E-01, 3.333E-01, 5.015E-01, 6.410E-01, 6.712E-01, 7.089E-01, 7.387E-01, 8.027E-01, 9.054E-01, 9.982E-01, 1.086E+00, 1.149E+00, 1.200E+00, 1.257E+00, 1.302E+00, 1.324E+00, 1.342E+00, 1.344E+00, 1.353E+00, 1.352E+00, 1.366E+00, 1.349E+00, 1.320E+00, 1.250E+00, 1.194E+00, 1.130E+00, 1.055E+00, 9.941E-01, 9.461E-01, 9.058E-01, 8.535E-01, 8.164E-01, 8.234E-01, 8.614E-01, 9.270E-01, 1.046E+00, 1.190E+00, 1.357E+00, 1.530E+00, 1.580E+00, 1.623E+00, 1.552E+00, 1.396E+00, 1.203E+00, 9.963E-01, 7.804E-01, 5.990E-01, 4.260E-01, 3.034E-01, 2.091E-01, 1.455E-01, 1.023E-01, 7.260E-02, 5.320E-02, 4.007E-02, 3.055E-02, 2.303E-02, 1.753E-02, 1.254E-02, 1.085E-02, 8.972E-03, 8.785E-03, 7.276E-03, 6.235E-03, 5.168E-03, 6.401E-03, 3.540E-03, 3.876E-03, 2.529E-03, 1.391E-03, 1.006E-03, 5.000E-04},
     {2.494E-04, 3.158E-02, 3.862E-02, 5.765E-02, 7.191E-02, 1.117E-01, 1.001E-01, 1.299E-01, 1.084E-01, 3.222E-01, 4.813E-01, 6.202E-01, 6.505E-01, 7.113E-01, 7.297E-01, 7.877E-01, 9.025E-01, 1.013E+00, 1.094E+00, 1.148E+00, 1.211E+00, 1.252E+00, 1.304E+00, 1.336E+00, 1.347E+00, 1.356E+00, 1.354E+00, 1.365E+00, 1.369E+00, 1.351E+00, 1.328E+00, 1.258E+00, 1.202E+00, 1.130E+00, 1.059E+00, 9.882E-01, 9.494E-01, 9.124E-01, 8.601E-01, 8.192E-01, 8.230E-01, 8.637E-01, 9.387E-01, 1.048E+00, 1.188E+00, 1.354E+00, 1.540E+00, 1.616E+00, 1.634E+00, 1.572E+00, 1.388E+00, 1.224E+00, 1.001E+00, 7.875E-01, 5.981E-01, 4.347E-01, 3.054E-01, 2.086E-01, 1.461E-01, 1.012E-01, 7.329E-02, 5.338E-02, 4.046E-02, 3.013E-02, 2.390E-02, 1.758E-02, 1.241E-02, 1.099E-02, 9.904E-03, 8.385E-03, 7.029E-03, 5.092E-03, 5.896E-03, 4.427E-03, 3.156E-03, 3.957E-03, 2.318E-03, 2.368E-03, 1.121E-03, 5.284E-04},
     {2.960E-04, 4.661E-02, 5.142E-02, 7.836E-02, 7.650E-02, 1.158E-01, 1.384E-01, 1.598E-01, 1.298E-01, 4.088E-01, 5.108E-01, 6.759E-01, 7.111E-01, 7.069E-01, 7.569E-01, 8.221E-01, 9.024E-01, 9.951E-01, 1.083E+00, 1.143E+00, 1.196E+00, 1.243E+00, 1.290E+00, 1.319E+00, 1.335E+00, 1.333E+00, 1.349E+00, 1.351E+00, 1.349E+00, 1.339E+00, 1.312E+00, 1.253E+00, 1.187E+00, 1.126E+00, 1.046E+00, 9.803E-01, 9.405E-01, 9.074E-01, 8.515E-01, 8.155E-01, 8.172E-01, 8.621E-01, 9.268E-01, 1.040E+00, 1.184E+00, 1.351E+00, 1.528E+00, 1.601E+00, 1.645E+00, 1.555E+00, 1.395E+00, 1.202E+00, 1.009E+00, 7.834E-01, 5.907E-01, 4.264E-01, 3.005E-01, 2.080E-01, 1.442E-01, 1.016E-01, 7.377E-02, 5.274E-02, 4.028E-02, 2.943E-02, 2.345E-02, 1.733E-02, 1.304E-02, 1.089E-02, 9.218E-03, 8.375E-03, 7.196E-03, 4.961E-03, 5.212E-03, 4.817E-03, 2.602E-03, 3.627E-03, 2.491E-03, 2.361E-03, 6.611E-04, 6.415E-04},
     {2.894E-04, 4.360E-02, 5.014E-02, 6.912E-02, 8.141E-02, 1.445E-01, 1.405E-01, 1.480E-01, 1.039E-01, 3.417E-01, 4.570E-01, 6.214E-01, 6.927E-01, 6.701E-01, 6.820E-01, 8.060E-01, 8.304E-01, 9.961E-01, 1.076E+00, 1.131E+00, 1.193E+00, 1.219E+00, 1.294E+00, 1.326E+00, 1.323E+00, 1.350E+00, 1.362E+00, 1.348E+00, 1.360E+00, 1.339E+00, 1.311E+00, 1.262E+00, 1.185E+00, 1.131E+00, 1.058E+00, 1.002E+00, 9.544E-01, 9.065E-01, 8.609E-01, 8.214E-01, 8.346E-01, 8.601E-01, 9.398E-01, 1.059E+00, 1.200E+00, 1.364E+00, 1.510E+00, 1.641E+00, 1.590E+00, 1.542E+00, 1.397E+00, 1.237E+00, 1.003E+00, 8.001E-01, 5.921E-01, 4.271E-01, 3.083E-01, 2.139E-01, 1.458E-01, 1.017E-01, 7.216E-02, 5.370E-02, 4.107E-02, 3.045E-02, 2.474E-02, 1.765E-02, 1.298E-02, 1.070E-02, 9.453E-03, 9.417E-03, 7.668E-03, 4.481E-03, 3.087E-03, 6.682E-03, 3.068E-03, 1.882E-03, 1.948E-03, 5.821E-03, 1.565E-03, 3.780E-04},
     {1.800E-01, 3.572E+00, 3.238E+00, 2.501E+00, 1.587E+00, 1.524E+00, 1.259E+00, 1.234E+00, 6.249E-01, 1.469E+00, 1.489E+00, 1.493E+00, 1.332E+00, 1.168E+00, 1.077E+00, 1.050E+00, 1.085E+00, 1.129E+00, 1.164E+00, 1.190E+00, 1.213E+00, 1.238E+00, 1.258E+00, 1.270E+00, 1.275E+00, 1.274E+00, 1.272E+00, 1.267E+00, 1.276E+00, 1.252E+00, 1.223E+00, 1.169E+00, 1.110E+00, 1.035E+00, 9.696E-01, 9.107E-01, 8.679E-01, 8.329E-01, 7.873E-01, 7.513E-01, 7.580E-01, 7.947E-01, 8.584E-01, 9.582E-01, 1.093E+00, 1.255E+00, 1.420E+00, 1.496E+00, 1.525E+00, 1.468E+00, 1.336E+00, 1.156E+00, 9.496E-01, 7.491E-01, 5.688E-01, 4.106E-01, 2.897E-01, 1.987E-01, 1.380E-01, 9.650E-02, 6.927E-02, 5.094E-02, 3.836E-02, 2.994E-02, 2.412E-02, 1.694E-02, 1.244E-02, 1.079E-02, 9.658E-03, 8.864E-03, 8.303E-03, 8.066E-03, 7.846E-03, 7.957E-03, 6.113E-03, 5.381E-03, 5.472E-03, 5.358E-03, 5.970E-03, 6.237E-03},
     {2.605E-04, 2.631E-02, 3.681E-02, 4.785E-02, 7.677E-02, 1.316E-01, 9.301E-02, 1.018E-01, 1.079E-01, 4.031E-01, 4.383E-01, 6.138E-01, 6.870E-01, 7.113E-01, 7.262E-01, 8.072E-01, 8.834E-01, 9.917E-01, 1.070E+00, 1.134E+00, 1.185E+00, 1.256E+00, 1.307E+00, 1.338E+00, 1.329E+00, 1.353E+00, 1.370E+00, 1.381E+00, 1.371E+00, 1.359E+00, 1.336E+00, 1.252E+00, 1.208E+00, 1.133E+00, 1.066E+00, 9.925E-01, 9.398E-01, 9.187E-01, 8.526E-01, 8.198E-01, 8.374E-01, 8.628E-01, 9.381E-01, 1.055E+00, 1.208E+00, 1.350E+00, 1.567E+00, 1.627E+00, 1.624E+00, 1.558E+00, 1.401E+00, 1.214E+00, 1.002E+00, 7.880E-01, 5.921E-01, 4.393E-01, 3.076E-01, 2.087E-01, 1.429E-01, 1.036E-01, 7.355E-02, 5.130E-02, 3.955E-02, 3.146E-02, 2.366E-02, 1.726E-02, 1.258E-02, 1.092E-02, 1.015E-02, 9.365E-03, 6.013E-03, 3.590E-03, 4.496E-03, 4.837E-03, 6.140E-03, 4.341E-03, 1.343E-03, 4.228E-03, 5.226E-04, 7.545E-04},
     {2.607E-04, 2.222E-02, 4.369E-02, 5.655E-02, 7.639E-02, 9.580E-02, 1.022E-01, 1.921E-01, 1.312E-01, 3.306E-01, 5.204E-01, 6.816E-01, 6.607E-01, 6.635E-01, 7.260E-01, 7.893E-01, 9.209E-01, 1.004E+00, 1.098E+00, 1.158E+00, 1.206E+00, 1.268E+00, 1.289E+00, 1.328E+00, 1.341E+00, 1.340E+00, 1.358E+00, 1.349E+00, 1.383E+00, 1.356E+00, 1.331E+00, 1.242E+00, 1.211E+00, 1.133E+00, 1.049E+00, 9.995E-01, 9.512E-01, 9.076E-01, 8.579E-01, 8.202E-01, 8.377E-01, 8.753E-01, 9.439E-01, 1.041E+00, 1.193E+00, 1.341E+00, 1.525E+00, 1.574E+00, 1.593E+00, 1.569E+00, 1.366E+00, 1.206E+00, 1.021E+00, 7.956E-01, 6.034E-01, 4.278E-01, 3.102E-01, 2.086E-01, 1.461E-01, 1.031E-01, 7.383E-02, 5.028E-02, 4.112E-02, 3.090E-02, 2.154E-02, 1.732E-02, 1.306E-02, 1.068E-02, 9.153E-03, 8.133E-03, 6.713E-03, 5.319E-03, 3.989E-03, 8.444E-03, 1.941E-03, 4.946E-03, 2.976E-03, 3.784E-03, 5.910E-04, 2.521E-04},
     {1.780E-01, 5.124E+00, 3.340E+00, 2.752E+00, 1.532E+00, 1.502E+00, 1.283E+00, 1.247E+00, 6.408E-01, 1.423E+00, 1.493E+00, 1.501E+00, 1.316E+00, 1.161E+00, 1.081E+00, 1.048E+00, 1.081E+00, 1.129E+00, 1.170E+00, 1.190E+00, 1.214E+00, 1.239E+00, 1.258E+00, 1.269E+00, 1.274E+00, 1.270E+00, 1.265E+00, 1.265E+00, 1.274E+00, 1.253E+00, 1.220E+00, 1.173E+00, 1.111E+00, 1.039E+00, 9.675E-01, 9.125E-01, 8.687E-01, 8.348E-01, 7.882E-01, 7.476E-01, 7.592E-01, 7.946E-01, 8.570E-01, 9.614E-01, 1.095E+00, 1.257E+00, 1.418E+00, 1.502E+00, 1.533E+00, 1.460E+00, 1.343E+00, 1.154E+00, 9.496E-01, 7.457E-01, 5.701E-01, 4.112E-01, 2.882E-01, 1.982E-01, 1.382E-01, 9.659E-02, 6.902E-02, 5.065E-02, 3.841E-02, 3.010E-02, 2.401E-02, 1.713E-02, 1.250E-02, 1.079E-02, 9.623E-03, 8.901E-03, 8.297E-03, 8.180E-03, 7.698E-03, 7.869E-03, 6.500E-03, 5.429E-03, 5.453E-03, 5.933E-03, 5.511E-03, 5.550E-03},
     {1.829E-01, 3.581E+00, 3.653E+00, 2.510E+00, 1.605E+00, 1.528E+00, 1.253E+00, 1.264E+00, 6.156E-01, 1.469E+00, 1.500E+00, 1.473E+00, 1.340E+00, 1.166E+00, 1.074E+00, 1.057E+00, 1.075E+00, 1.127E+00, 1.169E+00, 1.188E+00, 1.212E+00, 1.238E+00, 1.260E+00, 1.272E+00, 1.272E+00, 1.272E+00, 1.270E+00, 1.266E+00, 1.275E+00, 1.250E+00, 1.224E+00, 1.167E+00, 1.110E+00, 1.039E+00, 9.682E-01, 9.119E-01, 8.667E-01, 8.359E-01, 7.903E-01, 7.499E-01, 7.578E-01, 7.936E-01, 8.595E-01, 9.557E-01, 1.098E+00, 1.254E+00, 1.419E+00, 1.500E+00, 1.529E+00, 1.462E+00, 1.339E+00, 1.152E+00, 9.470E-01, 7.516E-01, 5.683E-01, 4.100E-01, 2.894E-01, 1.993E-01, 1.372E-01, 9.685E-02, 6.914E-02, 5.076E-02, 3.851E-02, 2.990E-02, 2.414E-02, 1.714E-02, 1.249E-02, 1.084E-02, 9.637E-03, 8.826E-03, 8.251E-03, 7.945E-03, 7.913E-03, 7.839E-03, 6.205E-03, 5.395E-03, 5.376E-03, 5.855E-03, 5.805E-03, 5.727E-03},
     {2.326E-04, 2.787E-02, 3.339E-02, 5.035E-02, 6.247E-02, 9.966E-02, 1.074E-01, 1.442E-01, 1.041E-01, 3.121E-01, 4.634E-01, 6.124E-01, 6.707E-01, 6.990E-01, 7.462E-01, 8.168E-01, 9.110E-01, 1.022E+00, 1.100E+00, 1.156E+00, 1.212E+00, 1.261E+00, 1.307E+00, 1.336E+00, 1.353E+00, 1.354E+00, 1.353E+00, 1.360E+00, 1.376E+00, 1.354E+00, 1.326E+00, 1.264E+00, 1.198E+00, 1.132E+00, 1.062E+00, 9.996E-01, 9.498E-01, 9.122E-01, 8.609E-01, 8.217E-01, 8.276E-01, 8.657E-01, 9.451E-01, 1.048E+00, 1.196E+00, 1.360E+00, 1.538E+00, 1.600E+00, 1.634E+00, 1.581E+00, 1.403E+00, 1.211E+00, 9.999E-01, 7.865E-01, 5.984E-01, 4.296E-01, 3.034E-01, 2.107E-01, 1.463E-01, 1.024E-01, 7.337E-02, 5.378E-02, 4.052E-02, 3.077E-02, 2.339E-02, 1.753E-02, 1.269E-02, 1.092E-02, 9.353E-03, 9.002E-03, 7.919E-03, 4.869E-03, 6.104E-03, 4.942E-03, 3.426E-03, 2.660E-03, 2.304E-03, 2.039E-03, 1.059E-03, 5.481E-04},
     {2.328E-04, 3.090E-02, 4.163E-02, 4.817E-02, 5.984E-02, 9.593E-02, 1.055E-01, 1.605E-01, 1.151E-01, 3.110E-01, 4.780E-01, 6.027E-01, 6.617E-01, 6.884E-01, 7.227E-01, 7.992E-01, 8.973E-01, 1.001E+00, 1.085E+00, 1.149E+00, 1.217E+00, 1.260E+00, 1.303E+00, 1.342E+00, 1.352E+00, 1.359E+00, 1.367E+00, 1.366E+00, 1.386E+00, 1.359E+00, 1.335E+00, 1.267E+00, 1.203E+00, 1.130E+00, 1.060E+00, 9.983E-01, 9.556E-01, 9.185E-01, 8.634E-01, 8.242E-01, 8.302E-01, 8.673E-01, 9.375E-01, 1.051E+00, 1.194E+00, 1.359E+00, 1.540E+00, 1.593E+00, 1.626E+00, 1.570E+00, 1.398E+00, 1.220E+00, 9.918E-01, 7.834E-01, 5.988E-01, 4.256E-01, 3.069E-01, 2.102E-01, 1.467E-01, 1.022E-01, 7.271E-02, 5.372E-02, 4.035E-02, 3.002E-02, 2.315E-02, 1.791E-02, 1.267E-02, 1.052E-02, 9.544E-03, 8.520E-03, 8.017E-03, 6.324E-03, 6.082E-03, 5.663E-03, 2.850E-03, 3.110E-03, 2.375E-03, 1.463E-03, 1.312E-03, 4.850E-04},
     {2.564E-04, 3.837E-02, 3.059E-02, 5.322E-02, 6.786E-02, 9.388E-02, 1.256E-01, 1.484E-01, 1.033E-01, 3.382E-01, 4.688E-01, 6.103E-01, 6.883E-01, 6.948E-01, 7.502E-01, 8.297E-01, 9.089E-01, 9.969E-01, 1.095E+00, 1.143E+00, 1.203E+00, 1.262E+00, 1.306E+00, 1.333E+00, 1.348E+00, 1.344E+00, 1.349E+00, 1.360E+00, 1.371E+00, 1.356E+00, 1.326E+00, 1.267E+00, 1.197E+00, 1.129E+00, 1.052E+00, 9.949E-01, 9.485E-01, 9.147E-01, 8.563E-01, 8.183E-01, 8.310E-01, 8.650E-01, 9.384E-01, 1.046E+00, 1.197E+00, 1.363E+00, 1.533E+00, 1.615E+00, 1.624E+00, 1.580E+00, 1.390E+00, 1.200E+00, 1.008E+00, 7.782E-01, 5.965E-01, 4.190E-01, 3.025E-01, 2.105E-01, 1.457E-01, 1.019E-01, 7.269E-02, 5.390E-02, 4.059E-02, 3.069E-02, 2.300E-02, 1.719E-02, 1.252E-02, 1.121E-02, 9.765E-03, 7.860E-03, 8.231E-03, 5.744E-03, 4.478E-03, 5.989E-03, 2.354E-03, 2.470E-03, 1.666E-03, 2.406E-03, 1.619E-03, 3.990E-04},
     {3.098E-04, 2.532E-02, 7.010E-02, 5.975E-02, 5.345E-02, 7.526E-02, 8.972E-02, 1.506E-01, 1.019E-01, 4.177E-01, 4.905E-01, 6.736E-01, 7.624E-01, 7.185E-01, 8.202E-01, 7.980E-01, 8.954E-01, 1.013E+00, 1.087E+00, 1.149E+00, 1.210E+00, 1.250E+00, 1.304E+00, 1.345E+00, 1.342E+00, 1.349E+00, 1.356E+00, 1.341E+00, 1.364E+00, 1.326E+00, 1.323E+00, 1.231E+00, 1.202E+00, 1.088E+00, 1.043E+00, 9.859E-01, 9.468E-01, 9.123E-01, 8.560E-01, 8.090E-01, 8.177E-01, 8.259E-01, 9.266E-01, 1.030E+00, 1.172E+00, 1.328E+00, 1.537E+00, 1.607E+00, 1.641E+00, 1.598E+00, 1.403E+00, 1.203E+00, 1.024E+00, 7.923E-01, 5.926E-01, 4.400E-01, 3.034E-01, 2.112E-01, 1.464E-01, 1.046E-01, 7.418E-02, 5.522E-02, 3.982E-02, 2.936E-02, 2.511E-02, 1.870E-02, 1.296E-02, 9.903E-03, 9.423E-03, 9.231E-03, 6.472E-03, 7.884E-03, 4.329E-03, 2.418E-03, 3.861E-03, 2.891E-03, 5.423E-04, 6.677E-03, 4.057E-04, 3.023E-04},
     {4.708E-04, 1.701E+00, -1.578E+00, 9.121E-01, 7.486E-01, 5.589E-01, 6.530E-01, 7.658E-01, 3.456E-01, 8.560E-01, 7.973E-01, 8.156E-01, 7.265E-01, 7.858E-01, 1.014E+00, 1.050E+00, 1.065E+00, 1.061E+00, 1.177E+00, 1.207E+00, 1.204E+00, 1.295E+00, 1.282E+00, 1.308E+00, 1.332E+00, 1.341E+00, 1.295E+00, 1.213E+00, 1.124E+00, 1.338E+00, 1.282E+00, 1.244E+00, 9.802E-01, 1.026E+00, 1.055E+00, 9.854E-01, 9.301E-01, 8.898E-01, 7.931E-01, 7.788E-01, 7.278E-01, 8.297E-01, 9.476E-01, 1.002E+00, 1.184E+00, 1.341E+00, 1.580E+00, 1.553E+00, 1.629E+00, 1.606E+00, 1.476E+00, 1.237E+00, 9.413E-01, 7.969E-01, 5.947E-01, 4.415E-01, 3.248E-01, 2.170E-01, 1.507E-01, 1.046E-01, 6.915E-02, 5.408E-02, 1.983E-02, 3.311E-02, 2.035E-02, 1.957E-02, 1.242E-02, 1.083E-02, 8.955E-03, 6.824E-03, 8.855E-03, 8.707E-03, 6.040E-03, 1.291E-02, 7.450E-03, 4.775E-03, 5.259E-03, 4.108E-03, 5.489E-03, 5.481E-03},
     {2.406E-04, 3.385E-02, 3.578E-02, 5.432E-02, 6.220E-02, 9.562E-02, 1.249E-01, 1.405E-01, 1.066E-01, 3.192E-01, 4.762E-01, 6.200E-01, 6.800E-01, 7.151E-01, 7.432E-01, 7.980E-01, 8.981E-01, 1.007E+00, 1.090E+00, 1.145E+00, 1.208E+00, 1.252E+00, 1.304E+00, 1.329E+00, 1.345E+00, 1.349E+00, 1.354E+00, 1.362E+00, 1.372E+00, 1.359E+00, 1.325E+00, 1.259E+00, 1.200E+00, 1.133E+00, 1.059E+00, 9.963E-01, 9.505E-01, 9.115E-01, 8.607E-01, 8.247E-01, 8.266E-01, 8.668E-01, 9.347E-01, 1.045E+00, 1.196E+00, 1.369E+00, 1.551E+00, 1.602E+00, 1.626E+00, 1.571E+00, 1.409E+00, 1.217E+00, 1.005E+00, 7.886E-01, 6.010E-01, 4.290E-01, 3.019E-01, 2.112E-01, 1.465E-01, 1.022E-01, 7.362E-02, 5.391E-02, 4.057E-02, 3.021E-02, 2.415E-02, 1.752E-02, 1.257E-02, 1.084E-02, 9.528E-03, 8.775E-03, 7.496E-03, 5.919E-03, 5.381E-03, 5.185E-03, 4.161E-03, 3.090E-03, 1.867E-03, 1.701E-03, 9.188E-04, 5.315E-04},
     {2.315E-01, 3.072E+00, 2.850E+00, 2.379E+00, 1.814E+00, 1.427E+00, 1.502E+00, 1.198E+00, 6.637E-01, 1.478E+00, 1.465E+00, 1.593E+00, 1.334E+00, 1.162E+00, 1.089E+00, 1.052E+00, 1.074E+00, 1.133E+00, 1.161E+00, 1.196E+00, 1.212E+00, 1.235E+00, 1.260E+00, 1.276E+00, 1.285E+00, 1.278E+00, 1.270E+00, 1.259E+00, 1.272E+00, 1.265E+00, 1.203E+00, 1.151E+00, 1.119E+00, 1.035E+00, 9.633E-01, 9.135E-01, 8.644E-01, 8.412E-01, 7.865E-01, 7.494E-01, 7.635E-01, 7.874E-01, 8.475E-01, 9.577E-01, 1.104E+00, 1.274E+00, 1.419E+00, 1.490E+00, 1.524E+00, 1.496E+00, 1.342E+00, 1.169E+00, 9.458E-01, 7.514E-01, 5.769E-01, 4.126E-01, 2.925E-01, 2.000E-01, 1.368E-01, 9.616E-02, 6.762E-02, 5.076E-02, 3.781E-02, 2.879E-02, 2.332E-02, 1.717E-02, 1.265E-02, 1.079E-02, 9.486E-03, 9.464E-03, 8.739E-03, 8.339E-03, 8.351E-03, 7.462E-03, 7.104E-03, 5.085E-03, 4.805E-03, 6.677E-03, 5.575E-03, 5.164E-03},
     {2.174E-01, 2.227E+00, 2.479E+00, 2.328E+00, 1.704E+00, 1.940E+00, 1.549E+00, 1.289E+00, 5.517E-01, 1.441E+00, 1.490E+00, 1.434E+00, 1.362E+00, 1.171E+00, 1.073E+00, 1.050E+00, 1.080E+00, 1.120E+00, 1.159E+00, 1.167E+00, 1.210E+00, 1.239E+00, 1.259E+00, 1.290E+00, 1.269E+00, 1.256E+00, 1.265E+00, 1.263E+00, 1.287E+00, 1.244E+00, 1.225E+00, 1.178E+00, 1.111E+00, 1.037E+00, 9.787E-01, 9.073E-01, 8.541E-01, 8.298E-01, 7.933E-01, 7.530E-01, 7.696E-01, 7.966E-01, 8.582E-01, 9.675E-01, 1.092E+00, 1.266E+00, 1.416E+00, 1.513E+00, 1.557E+00, 1.461E+00, 1.341E+00, 1.135E+00, 9.446E-01, 7.411E-01, 5.572E-01, 4.133E-01, 2.920E-01, 1.992E-01, 1.383E-01, 9.723E-02, 6.830E-02, 5.173E-02, 3.840E-02, 3.008E-02, 2.393E-02, 1.743E-02, 1.259E-02, 1.057E-02, 9.381E-03, 8.891E-03, 8.430E-03, 7.669E-03, 8.314E-03, 8.597E-03, 6.436E-03, 6.161E-03, 5.354E-03, 5.808E-03, 7.759E-03, 4.967E-03},
     {1.572E-01, 2.823E+00, 3.055E+00, 2.295E+00, 1.478E+00, 1.373E+00, 1.264E+00, 1.132E+00, 6.411E-01, 1.457E+00, 1.430E+00, 1.465E+00, 1.362E+00, 1.154E+00, 1.093E+00, 1.051E+00, 1.061E+00, 1.118E+00, 1.178E+00, 1.191E+00, 1.207E+00, 1.267E+00, 1.251E+00, 1.274E+00, 1.267E+00, 1.288E+00, 1.274E+00, 1.276E+00, 1.269E+00, 1.253E+00, 1.226E+00, 1.163E+00, 1.108E+00, 1.031E+00, 9.792E-01, 9.190E-01, 8.577E-01, 8.364E-01, 7.998E-01, 7.505E-01, 7.587E-01, 7.996E-01, 8.608E-01, 9.585E-01, 1.094E+00, 1.239E+00, 1.403E+00, 1.476E+00, 1.520E+00, 1.470E+00, 1.327E+00, 1.124E+00, 9.653E-01, 7.601E-01, 5.713E-01, 4.137E-01, 2.874E-01, 1.990E-01, 1.410E-01, 9.522E-02, 6.876E-02, 4.921E-02, 3.726E-02, 2.983E-02, 2.373E-02, 1.658E-02, 1.257E-02, 1.075E-02, 9.609E-03, 8.271E-03, 8.340E-03, 8.770E-03, 7.378E-03, 7.303E-03, 5.912E-03, 5.315E-03, 7.372E-03, 6.092E-03, 5.033E-03, 5.305E-03},
     {2.160E-01, 2.263E+00, 1.119E+01, 2.336E+00, 1.736E+00, 1.510E+00, 1.077E+00, 1.176E+00, 7.053E-01, 1.423E+00, 1.569E+00, 1.440E+00, 1.375E+00, 1.159E+00, 1.075E+00, 1.069E+00, 1.062E+00, 1.133E+00, 1.158E+00, 1.204E+00, 1.216E+00, 1.240E+00, 1.263E+00, 1.282E+00, 1.286E+00, 1.287E+00, 1.260E+00, 1.280E+00, 1.266E+00, 1.247E+00, 1.234E+00, 1.178E+00, 1.121E+00, 1.030E+00, 9.682E-01, 9.054E-01, 8.685E-01, 8.296E-01, 7.917E-01, 7.498E-01, 7.487E-01, 7.899E-01, 8.571E-01, 9.687E-01, 1.098E+00, 1.254E+00, 1.410E+00, 1.492E+00, 1.542E+00, 1.455E+00, 1.350E+00, 1.139E+00, 9.516E-01, 7.482E-01, 5.658E-01, 4.106E-01, 2.926E-01, 1.957E-01, 1.395E-01, 9.392E-02, 6.780E-02, 5.034E-02, 3.757E-02, 3.000E-02, 2.382E-02, 1.738E-02, 1.216E-02, 1.105E-02, 9.388E-03, 8.357E-03, 8.885E-03, 8.099E-03, 7.050E-03, 6.724E-03, 6.228E-03, 4.828E-03, 5.222E-03, 5.245E-03, 7.617E-03, 7.289E-03},
     {2.423E-01, 4.315E+00, 2.464E+00, 2.864E+00, 1.174E+00, 1.485E+00, 1.268E+00, 1.222E+00, 5.845E-01, 1.453E+00, 1.426E+00, 1.488E+00, 1.321E+00, 1.167E+00, 1.076E+00, 1.052E+00, 1.066E+00, 1.122E+00, 1.151E+00, 1.206E+00, 1.209E+00, 1.239E+00, 1.250E+00, 1.286E+00, 1.282E+00, 1.269E+00, 1.251E+00, 1.263E+00, 1.273E+00, 1.269E+00, 1.204E+00, 1.178E+00, 1.108E+00, 1.043E+00, 9.572E-01, 9.212E-01, 8.694E-01, 8.428E-01, 7.893E-01, 7.578E-01, 7.580E-01, 7.940E-01, 8.664E-01, 9.559E-01, 1.096E+00, 1.248E+00, 1.412E+00, 1.500E+00, 1.509E+00, 1.463E+00, 1.369E+00, 1.149E+00, 9.606E-01, 7.550E-01, 5.693E-01, 4.126E-01, 2.883E-01, 1.976E-01, 1.379E-01, 9.559E-02, 6.876E-02, 5.059E-02, 3.842E-02, 3.008E-02, 2.387E-02, 1.667E-02, 1.304E-02, 1.021E-02, 1.031E-02, 8.361E-03, 8.001E-03, 8.146E-03, 7.446E-03, 8.348E-03, 5.815E-03, 4.387E-03, 4.728E-03, 6.252E-03, 4.515E-03, 5.561E-03},
     {1.617E-01, 4.064E+00, 2.742E+00, 2.266E+00, 1.559E+00, 1.377E+00, 1.402E+00, 1.178E+00, 6.902E-01, 1.501E+00, 1.659E+00, 1.587E+00, 1.368E+00, 1.170E+00, 1.114E+00, 1.061E+00, 1.092E+00, 1.130E+00, 1.172E+00, 1.207E+00, 1.183E+00, 1.234E+00, 1.261E+00, 1.254E+00, 1.287E+00, 1.263E+00, 1.272E+00, 1.246E+00, 1.266E+00, 1.262E+00, 1.218E+00, 1.166E+00, 1.121E+00, 1.039E+00, 9.762E-01, 8.993E-01, 8.753E-01, 8.349E-01, 7.893E-01, 7.575E-01, 7.539E-01, 7.984E-01, 8.531E-01, 9.740E-01, 1.119E+00, 1.251E+00, 1.404E+00, 1.488E+00, 1.556E+00, 1.446E+00, 1.355E+00, 1.132E+00, 9.286E-01, 7.537E-01, 5.683E-01, 4.106E-01, 2.881E-01, 1.966E-01, 1.355E-01, 9.763E-02, 6.776E-02, 5.132E-02, 3.890E-02, 2.995E-02, 2.371E-02, 1.746E-02, 1.324E-02, 1.051E-02, 9.834E-03, 8.969E-03, 7.766E-03, 7.762E-03, 8.075E-03, 9.524E-03, 8.243E-03, 5.045E-03, 5.098E-03, 4.711E-03, 4.371E-03, 6.547E-03},
     {3.073E-01, 2.023E+00, 2.628E+00, 2.467E+00, 1.432E+00, 1.146E+00, 1.139E+00, 1.750E+00, 5.444E-01, 1.307E+00, 1.464E+00, 1.483E+00, 1.358E+00, 1.188E+00, 1.069E+00, 1.036E+00, 1.110E+00, 1.127E+00, 1.156E+00, 1.209E+00, 1.195E+00, 1.237E+00, 1.262E+00, 1.289E+00, 1.287E+00, 1.264E+00, 1.262E+00, 1.249E+00, 1.281E+00, 1.250E+00, 1.228E+00, 1.186E+00, 1.097E+00, 1.033E+00, 9.705E-01, 9.052E-01, 8.553E-01, 8.536E-01, 7.986E-01, 7.560E-01, 7.652E-01, 8.156E-01, 8.463E-01, 9.698E-01, 1.088E+00, 1.243E+00, 1.417E+00, 1.469E+00, 1.544E+00, 1.439E+00, 1.331E+00, 1.134E+00, 9.276E-01, 7.655E-01, 5.659E-01, 4.075E-01, 2.903E-01, 1.991E-01, 1.353E-01, 9.565E-02, 6.819E-02, 5.082E-02, 3.936E-02, 2.947E-02, 2.426E-02, 1.780E-02, 1.251E-02, 1.031E-02, 1.034E-02, 9.703E-03, 8.115E-03, 7.457E-03, 6.907E-03, 6.714E-03, 5.733E-03, 7.032E-03, 5.893E-03, 4.560E-03, 7.615E-03, 4.148E-03},
     {1.575E-01, 2.376E+00, 5.511E+00, 4.140E+00, 2.222E+00, 1.022E+00, 1.414E+00, 1.012E+00, 5.570E-01, 1.627E+00, 1.349E+00, 1.507E+00, 1.347E+00, 1.251E+00, 1.103E+00, 1.054E+00, 1.092E+00, 1.122E+00, 1.182E+00, 1.167E+00, 1.212E+00, 1.234E+00, 1.264E+00, 1.287E+00, 1.260E+00, 1.284E+00, 1.277E+00, 1.250E+00, 1.300E+00, 1.262E+00, 1.246E+00, 1.159E+00, 1.099E+00, 1.041E+00, 9.627E-01, 9.212E-01, 8.749E-01, 8.307E-01, 7.929E-01, 7.360E-01, 7.686E-01, 7.892E-01, 8.466E-01, 9.500E-01, 1.047E+00, 1.288E+00, 1.426E+00, 1.505E+00, 1.517E+00, 1.455E+00, 1.287E+00, 1.121E+00, 9.316E-01, 7.538E-01, 5.805E-01, 4.069E-01, 2.963E-01, 1.982E-01, 1.402E-01, 9.389E-02, 6.983E-02, 5.031E-02, 3.893E-02, 3.000E-02, 2.573E-02, 1.678E-02, 1.244E-02, 1.088E-02, 9.356E-03, 8.698E-03, 8.022E-03, 6.875E-03, 1.100E-02, 9.955E-03, 7.337E-03, 4.677E-03, 6.427E-03, 6.148E-03, 8.214E-03, 3.827E-03},
     {1.870E-01, 4.744E+00, 3.217E+00, 2.383E+00, 1.802E+00, 1.486E+00, 1.329E+00, 1.205E+00, 6.102E-01, 1.495E+00, 1.516E+00, 1.478E+00, 1.319E+00, 1.164E+00, 1.076E+00, 1.050E+00, 1.080E+00, 1.130E+00, 1.165E+00, 1.189E+00, 1.212E+00, 1.236E+00, 1.258E+00, 1.271E+00, 1.271E+00, 1.272E+00, 1.272E+00, 1.268E+00, 1.277E+00, 1.253E+00, 1.221E+00, 1.169E+00, 1.109E+00, 1.039E+00, 9.688E-01, 9.133E-01, 8.658E-01, 8.371E-01, 7.900E-01, 7.512E-01, 7.587E-01, 7.925E-01, 8.574E-01, 9.586E-01, 1.093E+00, 1.257E+00, 1.420E+00, 1.493E+00, 1.527E+00, 1.462E+00, 1.338E+00, 1.155E+00, 9.495E-01, 7.493E-01, 5.703E-01, 4.107E-01, 2.901E-01, 1.994E-01, 1.376E-01, 9.651E-02, 6.895E-02, 5.073E-02, 3.841E-02, 2.999E-02, 2.412E-02, 1.701E-02, 1.244E-02, 1.072E-02, 9.630E-03, 8.829E-03, 8.312E-03, 8.101E-03, 7.724E-03, 7.905E-03, 6.299E-03, 5.287E-03, 5.476E-03, 5.776E-03, 5.866E-03, 6.320E-03},
     {1.913E-01, 4.255E+00, 3.444E+00, 2.481E+00, 1.640E+00, 1.531E+00, 1.288E+00, 1.270E+00, 5.997E-01, 1.442E+00, 1.477E+00, 1.476E+00, 1.330E+00, 1.169E+00, 1.083E+00, 1.051E+00, 1.078E+00, 1.126E+00, 1.166E+00, 1.188E+00, 1.211E+00, 1.238E+00, 1.256E+00, 1.271E+00, 1.273E+00, 1.274E+00, 1.271E+00, 1.267E+00, 1.274E+00, 1.254E+00, 1.220E+00, 1.167E+00, 1.113E+00, 1.037E+00, 9.688E-01, 9.129E-01, 8.681E-01, 8.336E-01, 7.865E-01, 7.516E-01, 7.576E-01, 7.948E-01, 8.593E-01, 9.561E-01, 1.097E+00, 1.258E+00, 1.421E+00, 1.492E+00, 1.534E+00, 1.461E+00, 1.341E+00, 1.156E+00, 9.519E-01, 7.507E-01, 5.693E-01, 4.101E-01, 2.896E-01, 1.981E-01, 1.374E-01, 9.658E-02, 6.937E-02, 5.074E-02, 3.867E-02, 2.989E-02, 2.413E-02, 1.713E-02, 1.250E-02, 1.076E-02, 9.502E-03, 8.767E-03, 8.258E-03, 8.063E-03, 7.855E-03, 7.777E-03, 6.306E-03, 5.442E-03, 5.528E-03, 5.516E-03, 6.168E-03, 5.712E-03},
     {1.898E-01, 4.165E+00, 3.239E+00, 2.648E+00, 1.610E+00, 1.494E+00, 1.289E+00, 1.238E+00, 6.235E-01, 1.438E+00, 1.486E+00, 1.484E+00, 1.339E+00, 1.165E+00, 1.076E+00, 1.050E+00, 1.080E+00, 1.129E+00, 1.168E+00, 1.188E+00, 1.213E+00, 1.239E+00, 1.262E+00, 1.272E+00, 1.272E+00, 1.269E+00, 1.273E+00, 1.266E+00, 1.276E+00, 1.250E+00, 1.221E+00, 1.171E+00, 1.110E+00, 1.038E+00, 9.687E-01, 9.137E-01, 8.687E-01, 8.352E-01, 7.870E-01, 7.480E-01, 7.602E-01, 7.922E-01, 8.591E-01, 9.607E-01, 1.091E+00, 1.255E+00, 1.415E+00, 1.496E+00, 1.528E+00, 1.460E+00, 1.339E+00, 1.154E+00, 9.493E-01, 7.497E-01, 5.703E-01, 4.105E-01, 2.896E-01, 1.985E-01, 1.373E-01, 9.672E-02, 6.940E-02, 5.067E-02, 3.834E-02, 3.009E-02, 2.403E-02, 1.718E-02, 1.255E-02, 1.087E-02, 9.529E-03, 8.865E-03, 8.370E-03, 7.970E-03, 7.921E-03, 7.850E-03, 6.155E-03, 5.393E-03, 5.518E-03, 5.859E-03, 5.714E-03, 6.418E-03},
     {1.897E-01, 3.957E+00, 3.856E+00, 2.684E+00, 1.643E+00, 1.480E+00, 1.304E+00, 1.284E+00, 6.124E-01, 1.434E+00, 1.497E+00, 1.483E+00, 1.326E+00, 1.166E+00, 1.080E+00, 1.051E+00, 1.074E+00, 1.126E+00, 1.163E+00, 1.187E+00, 1.212E+00, 1.238E+00, 1.260E+00, 1.268E+00, 1.274E+00, 1.274E+00, 1.270E+00, 1.269E+00, 1.277E+00, 1.252E+00, 1.224E+00, 1.171E+00, 1.110E+00, 1.038E+00, 9.698E-01, 9.114E-01, 8.652E-01, 8.348E-01, 7.895E-01, 7.498E-01, 7.574E-01, 7.921E-01, 8.594E-01, 9.566E-01, 1.096E+00, 1.260E+00, 1.419E+00, 1.496E+00, 1.534E+00, 1.465E+00, 1.340E+00, 1.157E+00, 9.516E-01, 7.506E-01, 5.693E-01, 4.110E-01, 2.894E-01, 1.974E-01, 1.380E-01, 9.660E-02, 6.948E-02, 5.088E-02, 3.837E-02, 2.965E-02, 2.417E-02, 1.699E-02, 1.248E-02, 1.080E-02, 9.539E-03, 8.775E-03, 8.265E-03, 8.058E-03, 7.837E-03, 7.898E-03, 6.202E-03, 5.428E-03, 5.554E-03, 5.352E-03, 5.705E-03, 6.037E-03},
     {1.899E-01, 3.543E+00, 3.519E+00, 2.642E+00, 1.581E+00, 1.495E+00, 1.296E+00, 1.289E+00, 6.150E-01, 1.486E+00, 1.474E+00, 1.479E+00, 1.324E+00, 1.167E+00, 1.074E+00, 1.054E+00, 1.080E+00, 1.133E+00, 1.165E+00, 1.186E+00, 1.215E+00, 1.238E+00, 1.261E+00, 1.271E+00, 1.273E+00, 1.274E+00, 1.268E+00, 1.265E+00, 1.274E+00, 1.253E+00, 1.223E+00, 1.171E+00, 1.109E+00, 1.036E+00, 9.682E-01, 9.106E-01, 8.671E-01, 8.343E-01, 7.894E-01, 7.523E-01, 7.561E-01, 7.949E-01, 8.588E-01, 9.588E-01, 1.095E+00, 1.253E+00, 1.420E+00, 1.494E+00, 1.534E+00, 1.461E+00, 1.336E+00, 1.154E+00, 9.528E-01, 7.531E-01, 5.697E-01, 4.117E-01, 2.903E-01, 1.985E-01, 1.375E-01, 9.617E-02, 6.911E-02, 5.078E-02, 3.842E-02, 2.983E-02, 2.402E-02, 1.707E-02, 1.242E-02, 1.086E-02, 9.659E-03, 8.759E-03, 8.298E-03, 8.003E-03, 7.673E-03, 7.920E-03, 6.423E-03, 5.314E-03, 5.516E-03, 5.349E-03, 5.832E-03, 5.663E-03},
   };
   
   pileupweightDn = { // this is 72383
     {2.627E-04, 2.950E-02, 3.845E-02, 6.129E-02, 7.067E-02, 1.038E-01, 1.276E-01, 1.488E-01, 1.050E-01, 3.197E-01, 4.811E-01, 6.165E-01, 6.699E-01, 7.030E-01, 7.332E-01, 7.987E-01, 8.958E-01, 9.917E-01, 1.083E+00, 1.145E+00, 1.204E+00, 1.252E+00, 1.292E+00, 1.325E+00, 1.342E+00, 1.346E+00, 1.351E+00, 1.358E+00, 1.368E+00, 1.355E+00, 1.323E+00, 1.260E+00, 1.197E+00, 1.133E+00, 1.057E+00, 9.937E-01, 9.487E-01, 9.072E-01, 8.591E-01, 8.169E-01, 8.251E-01, 8.610E-01, 9.336E-01, 1.047E+00, 1.193E+00, 1.356E+00, 1.538E+00, 1.612E+00, 1.625E+00, 1.577E+00, 1.402E+00, 1.210E+00, 1.006E+00, 7.882E-01, 5.993E-01, 4.287E-01, 3.047E-01, 2.107E-01, 1.456E-01, 1.024E-01, 7.315E-02, 5.335E-02, 4.065E-02, 3.040E-02, 2.403E-02, 1.784E-02, 1.262E-02, 1.095E-02, 9.353E-03, 8.596E-03, 7.320E-03, 6.155E-03, 6.241E-03, 4.710E-03, 3.440E-03, 2.819E-03, 2.363E-03, 1.809E-03, 1.251E-03, 4.036E-04},
     {3.544E-04, 3.998E-02, 4.526E-02, 7.801E-02, 9.146E-02, 1.097E-01, 1.527E-01, 2.427E-01, 1.278E-01, 4.256E-01, 5.532E-01, 6.663E-01, 6.732E-01, 7.100E-01, 7.715E-01, 8.042E-01, 9.015E-01, 9.917E-01, 1.066E+00, 1.131E+00, 1.189E+00, 1.253E+00, 1.282E+00, 1.315E+00, 1.325E+00, 1.339E+00, 1.339E+00, 1.339E+00, 1.362E+00, 1.336E+00, 1.297E+00, 1.239E+00, 1.190E+00, 1.117E+00, 1.039E+00, 9.847E-01, 9.359E-01, 8.988E-01, 8.460E-01, 8.122E-01, 8.128E-01, 8.503E-01, 9.144E-01, 1.020E+00, 1.173E+00, 1.348E+00, 1.525E+00, 1.596E+00, 1.638E+00, 1.565E+00, 1.346E+00, 1.213E+00, 9.796E-01, 7.891E-01, 5.957E-01, 4.270E-01, 3.022E-01, 2.079E-01, 1.453E-01, 1.013E-01, 7.242E-02, 5.264E-02, 4.040E-02, 3.102E-02, 2.399E-02, 1.754E-02, 1.216E-02, 1.027E-02, 9.501E-03, 8.830E-03, 7.677E-03, 5.254E-03, 6.172E-03, 5.941E-03, 3.630E-03, 4.188E-03, 2.190E-03, 1.532E-03, 1.240E-03, 5.375E-04},
     {1.749E-01, 4.172E+00, 3.462E+00, 2.677E+00, 1.657E+00, 1.475E+00, 1.255E+00, 1.247E+00, 6.000E-01, 1.423E+00, 1.498E+00, 1.492E+00, 1.325E+00, 1.164E+00, 1.082E+00, 1.052E+00, 1.083E+00, 1.127E+00, 1.163E+00, 1.191E+00, 1.212E+00, 1.241E+00, 1.255E+00, 1.270E+00, 1.274E+00, 1.273E+00, 1.272E+00, 1.268E+00, 1.278E+00, 1.250E+00, 1.223E+00, 1.171E+00, 1.111E+00, 1.036E+00, 9.706E-01, 9.104E-01, 8.681E-01, 8.332E-01, 7.862E-01, 7.510E-01, 7.602E-01, 7.926E-01, 8.584E-01, 9.577E-01, 1.096E+00, 1.256E+00, 1.416E+00, 1.494E+00, 1.526E+00, 1.468E+00, 1.336E+00, 1.152E+00, 9.528E-01, 7.484E-01, 5.701E-01, 4.122E-01, 2.880E-01, 1.984E-01, 1.374E-01, 9.694E-02, 6.917E-02, 5.072E-02, 3.857E-02, 2.990E-02, 2.407E-02, 1.711E-02, 1.255E-02, 1.081E-02, 9.624E-03, 8.906E-03, 8.153E-03, 8.132E-03, 7.845E-03, 7.748E-03, 6.232E-03, 5.267E-03, 5.608E-03, 6.070E-03, 6.121E-03, 6.164E-03},
     {1.672E-01, 4.002E+00, 3.617E+00, 2.548E+00, 1.509E+00, 1.493E+00, 1.296E+00, 1.240E+00, 6.044E-01, 1.455E+00, 1.498E+00, 1.488E+00, 1.340E+00, 1.174E+00, 1.086E+00, 1.052E+00, 1.083E+00, 1.128E+00, 1.168E+00, 1.181E+00, 1.205E+00, 1.236E+00, 1.259E+00, 1.272E+00, 1.271E+00, 1.272E+00, 1.271E+00, 1.267E+00, 1.278E+00, 1.251E+00, 1.219E+00, 1.164E+00, 1.109E+00, 1.038E+00, 9.689E-01, 9.156E-01, 8.645E-01, 8.359E-01, 7.875E-01, 7.518E-01, 7.621E-01, 7.939E-01, 8.594E-01, 9.634E-01, 1.096E+00, 1.255E+00, 1.424E+00, 1.511E+00, 1.535E+00, 1.457E+00, 1.342E+00, 1.153E+00, 9.464E-01, 7.538E-01, 5.673E-01, 4.094E-01, 2.882E-01, 1.995E-01, 1.377E-01, 9.630E-02, 6.899E-02, 5.090E-02, 3.856E-02, 2.996E-02, 2.428E-02, 1.692E-02, 1.250E-02, 1.081E-02, 9.817E-03, 8.680E-03, 8.324E-03, 8.295E-03, 7.672E-03, 7.872E-03, 6.039E-03, 5.129E-03, 5.624E-03, 5.494E-03, 6.660E-03, 5.473E-03},
     {2.758E-04, 2.979E-02, 4.481E-02, 7.384E-02, 6.863E-02, 1.116E-01, 1.301E-01, 1.552E-01, 1.058E-01, 3.333E-01, 5.015E-01, 6.410E-01, 6.712E-01, 7.089E-01, 7.387E-01, 8.027E-01, 9.054E-01, 9.982E-01, 1.086E+00, 1.149E+00, 1.200E+00, 1.257E+00, 1.302E+00, 1.324E+00, 1.342E+00, 1.344E+00, 1.353E+00, 1.352E+00, 1.366E+00, 1.349E+00, 1.320E+00, 1.250E+00, 1.194E+00, 1.130E+00, 1.055E+00, 9.941E-01, 9.461E-01, 9.058E-01, 8.535E-01, 8.164E-01, 8.234E-01, 8.614E-01, 9.270E-01, 1.046E+00, 1.190E+00, 1.357E+00, 1.530E+00, 1.580E+00, 1.623E+00, 1.552E+00, 1.396E+00, 1.203E+00, 9.963E-01, 7.804E-01, 5.990E-01, 4.260E-01, 3.034E-01, 2.091E-01, 1.455E-01, 1.023E-01, 7.260E-02, 5.320E-02, 4.007E-02, 3.055E-02, 2.303E-02, 1.753E-02, 1.254E-02, 1.085E-02, 8.972E-03, 8.785E-03, 7.276E-03, 6.235E-03, 5.168E-03, 6.401E-03, 3.540E-03, 3.876E-03, 2.529E-03, 1.391E-03, 1.006E-03, 5.000E-04},
     {2.494E-04, 3.158E-02, 3.862E-02, 5.765E-02, 7.191E-02, 1.117E-01, 1.001E-01, 1.299E-01, 1.084E-01, 3.222E-01, 4.813E-01, 6.202E-01, 6.505E-01, 7.113E-01, 7.297E-01, 7.877E-01, 9.025E-01, 1.013E+00, 1.094E+00, 1.148E+00, 1.211E+00, 1.252E+00, 1.304E+00, 1.336E+00, 1.347E+00, 1.356E+00, 1.354E+00, 1.365E+00, 1.369E+00, 1.351E+00, 1.328E+00, 1.258E+00, 1.202E+00, 1.130E+00, 1.059E+00, 9.882E-01, 9.494E-01, 9.124E-01, 8.601E-01, 8.192E-01, 8.230E-01, 8.637E-01, 9.387E-01, 1.048E+00, 1.188E+00, 1.354E+00, 1.540E+00, 1.616E+00, 1.634E+00, 1.572E+00, 1.388E+00, 1.224E+00, 1.001E+00, 7.875E-01, 5.981E-01, 4.347E-01, 3.054E-01, 2.086E-01, 1.461E-01, 1.012E-01, 7.329E-02, 5.338E-02, 4.046E-02, 3.013E-02, 2.390E-02, 1.758E-02, 1.241E-02, 1.099E-02, 9.904E-03, 8.385E-03, 7.029E-03, 5.092E-03, 5.896E-03, 4.427E-03, 3.156E-03, 3.957E-03, 2.318E-03, 2.368E-03, 1.121E-03, 5.284E-04},
     {2.960E-04, 4.661E-02, 5.142E-02, 7.836E-02, 7.650E-02, 1.158E-01, 1.384E-01, 1.598E-01, 1.298E-01, 4.088E-01, 5.108E-01, 6.759E-01, 7.111E-01, 7.069E-01, 7.569E-01, 8.221E-01, 9.024E-01, 9.951E-01, 1.083E+00, 1.143E+00, 1.196E+00, 1.243E+00, 1.290E+00, 1.319E+00, 1.335E+00, 1.333E+00, 1.349E+00, 1.351E+00, 1.349E+00, 1.339E+00, 1.312E+00, 1.253E+00, 1.187E+00, 1.126E+00, 1.046E+00, 9.803E-01, 9.405E-01, 9.074E-01, 8.515E-01, 8.155E-01, 8.172E-01, 8.621E-01, 9.268E-01, 1.040E+00, 1.184E+00, 1.351E+00, 1.528E+00, 1.601E+00, 1.645E+00, 1.555E+00, 1.395E+00, 1.202E+00, 1.009E+00, 7.834E-01, 5.907E-01, 4.264E-01, 3.005E-01, 2.080E-01, 1.442E-01, 1.016E-01, 7.377E-02, 5.274E-02, 4.028E-02, 2.943E-02, 2.345E-02, 1.733E-02, 1.304E-02, 1.089E-02, 9.218E-03, 8.375E-03, 7.196E-03, 4.961E-03, 5.212E-03, 4.817E-03, 2.602E-03, 3.627E-03, 2.491E-03, 2.361E-03, 6.611E-04, 6.415E-04},
     {2.894E-04, 4.360E-02, 5.014E-02, 6.912E-02, 8.141E-02, 1.445E-01, 1.405E-01, 1.480E-01, 1.039E-01, 3.417E-01, 4.570E-01, 6.214E-01, 6.927E-01, 6.701E-01, 6.820E-01, 8.060E-01, 8.304E-01, 9.961E-01, 1.076E+00, 1.131E+00, 1.193E+00, 1.219E+00, 1.294E+00, 1.326E+00, 1.323E+00, 1.350E+00, 1.362E+00, 1.348E+00, 1.360E+00, 1.339E+00, 1.311E+00, 1.262E+00, 1.185E+00, 1.131E+00, 1.058E+00, 1.002E+00, 9.544E-01, 9.065E-01, 8.609E-01, 8.214E-01, 8.346E-01, 8.601E-01, 9.398E-01, 1.059E+00, 1.200E+00, 1.364E+00, 1.510E+00, 1.641E+00, 1.590E+00, 1.542E+00, 1.397E+00, 1.237E+00, 1.003E+00, 8.001E-01, 5.921E-01, 4.271E-01, 3.083E-01, 2.139E-01, 1.458E-01, 1.017E-01, 7.216E-02, 5.370E-02, 4.107E-02, 3.045E-02, 2.474E-02, 1.765E-02, 1.298E-02, 1.070E-02, 9.453E-03, 9.417E-03, 7.668E-03, 4.481E-03, 3.087E-03, 6.682E-03, 3.068E-03, 1.882E-03, 1.948E-03, 5.821E-03, 1.565E-03, 3.780E-04},
     {1.800E-01, 3.572E+00, 3.238E+00, 2.501E+00, 1.587E+00, 1.524E+00, 1.259E+00, 1.234E+00, 6.249E-01, 1.469E+00, 1.489E+00, 1.493E+00, 1.332E+00, 1.168E+00, 1.077E+00, 1.050E+00, 1.085E+00, 1.129E+00, 1.164E+00, 1.190E+00, 1.213E+00, 1.238E+00, 1.258E+00, 1.270E+00, 1.275E+00, 1.274E+00, 1.272E+00, 1.267E+00, 1.276E+00, 1.252E+00, 1.223E+00, 1.169E+00, 1.110E+00, 1.035E+00, 9.696E-01, 9.107E-01, 8.679E-01, 8.329E-01, 7.873E-01, 7.513E-01, 7.580E-01, 7.947E-01, 8.584E-01, 9.582E-01, 1.093E+00, 1.255E+00, 1.420E+00, 1.496E+00, 1.525E+00, 1.468E+00, 1.336E+00, 1.156E+00, 9.496E-01, 7.491E-01, 5.688E-01, 4.106E-01, 2.897E-01, 1.987E-01, 1.380E-01, 9.650E-02, 6.927E-02, 5.094E-02, 3.836E-02, 2.994E-02, 2.412E-02, 1.694E-02, 1.244E-02, 1.079E-02, 9.658E-03, 8.864E-03, 8.303E-03, 8.066E-03, 7.846E-03, 7.957E-03, 6.113E-03, 5.381E-03, 5.472E-03, 5.358E-03, 5.970E-03, 6.237E-03},
     {2.605E-04, 2.631E-02, 3.681E-02, 4.785E-02, 7.677E-02, 1.316E-01, 9.301E-02, 1.018E-01, 1.079E-01, 4.031E-01, 4.383E-01, 6.138E-01, 6.870E-01, 7.113E-01, 7.262E-01, 8.072E-01, 8.834E-01, 9.917E-01, 1.070E+00, 1.134E+00, 1.185E+00, 1.256E+00, 1.307E+00, 1.338E+00, 1.329E+00, 1.353E+00, 1.370E+00, 1.381E+00, 1.371E+00, 1.359E+00, 1.336E+00, 1.252E+00, 1.208E+00, 1.133E+00, 1.066E+00, 9.925E-01, 9.398E-01, 9.187E-01, 8.526E-01, 8.198E-01, 8.374E-01, 8.628E-01, 9.381E-01, 1.055E+00, 1.208E+00, 1.350E+00, 1.567E+00, 1.627E+00, 1.624E+00, 1.558E+00, 1.401E+00, 1.214E+00, 1.002E+00, 7.880E-01, 5.921E-01, 4.393E-01, 3.076E-01, 2.087E-01, 1.429E-01, 1.036E-01, 7.355E-02, 5.130E-02, 3.955E-02, 3.146E-02, 2.366E-02, 1.726E-02, 1.258E-02, 1.092E-02, 1.015E-02, 9.365E-03, 6.013E-03, 3.590E-03, 4.496E-03, 4.837E-03, 6.140E-03, 4.341E-03, 1.343E-03, 4.228E-03, 5.226E-04, 7.545E-04},
     {2.607E-04, 2.222E-02, 4.369E-02, 5.655E-02, 7.639E-02, 9.580E-02, 1.022E-01, 1.921E-01, 1.312E-01, 3.306E-01, 5.204E-01, 6.816E-01, 6.607E-01, 6.635E-01, 7.260E-01, 7.893E-01, 9.209E-01, 1.004E+00, 1.098E+00, 1.158E+00, 1.206E+00, 1.268E+00, 1.289E+00, 1.328E+00, 1.341E+00, 1.340E+00, 1.358E+00, 1.349E+00, 1.383E+00, 1.356E+00, 1.331E+00, 1.242E+00, 1.211E+00, 1.133E+00, 1.049E+00, 9.995E-01, 9.512E-01, 9.076E-01, 8.579E-01, 8.202E-01, 8.377E-01, 8.753E-01, 9.439E-01, 1.041E+00, 1.193E+00, 1.341E+00, 1.525E+00, 1.574E+00, 1.593E+00, 1.569E+00, 1.366E+00, 1.206E+00, 1.021E+00, 7.956E-01, 6.034E-01, 4.278E-01, 3.102E-01, 2.086E-01, 1.461E-01, 1.031E-01, 7.383E-02, 5.028E-02, 4.112E-02, 3.090E-02, 2.154E-02, 1.732E-02, 1.306E-02, 1.068E-02, 9.153E-03, 8.133E-03, 6.713E-03, 5.319E-03, 3.989E-03, 8.444E-03, 1.941E-03, 4.946E-03, 2.976E-03, 3.784E-03, 5.910E-04, 2.521E-04},
     {1.780E-01, 5.124E+00, 3.340E+00, 2.752E+00, 1.532E+00, 1.502E+00, 1.283E+00, 1.247E+00, 6.408E-01, 1.423E+00, 1.493E+00, 1.501E+00, 1.316E+00, 1.161E+00, 1.081E+00, 1.048E+00, 1.081E+00, 1.129E+00, 1.170E+00, 1.190E+00, 1.214E+00, 1.239E+00, 1.258E+00, 1.269E+00, 1.274E+00, 1.270E+00, 1.265E+00, 1.265E+00, 1.274E+00, 1.253E+00, 1.220E+00, 1.173E+00, 1.111E+00, 1.039E+00, 9.675E-01, 9.125E-01, 8.687E-01, 8.348E-01, 7.882E-01, 7.476E-01, 7.592E-01, 7.946E-01, 8.570E-01, 9.614E-01, 1.095E+00, 1.257E+00, 1.418E+00, 1.502E+00, 1.533E+00, 1.460E+00, 1.343E+00, 1.154E+00, 9.496E-01, 7.457E-01, 5.701E-01, 4.112E-01, 2.882E-01, 1.982E-01, 1.382E-01, 9.659E-02, 6.902E-02, 5.065E-02, 3.841E-02, 3.010E-02, 2.401E-02, 1.713E-02, 1.250E-02, 1.079E-02, 9.623E-03, 8.901E-03, 8.297E-03, 8.180E-03, 7.698E-03, 7.869E-03, 6.500E-03, 5.429E-03, 5.453E-03, 5.933E-03, 5.511E-03, 5.550E-03},
     {1.829E-01, 3.581E+00, 3.653E+00, 2.510E+00, 1.605E+00, 1.528E+00, 1.253E+00, 1.264E+00, 6.156E-01, 1.469E+00, 1.500E+00, 1.473E+00, 1.340E+00, 1.166E+00, 1.074E+00, 1.057E+00, 1.075E+00, 1.127E+00, 1.169E+00, 1.188E+00, 1.212E+00, 1.238E+00, 1.260E+00, 1.272E+00, 1.272E+00, 1.272E+00, 1.270E+00, 1.266E+00, 1.275E+00, 1.250E+00, 1.224E+00, 1.167E+00, 1.110E+00, 1.039E+00, 9.682E-01, 9.119E-01, 8.667E-01, 8.359E-01, 7.903E-01, 7.499E-01, 7.578E-01, 7.936E-01, 8.595E-01, 9.557E-01, 1.098E+00, 1.254E+00, 1.419E+00, 1.500E+00, 1.529E+00, 1.462E+00, 1.339E+00, 1.152E+00, 9.470E-01, 7.516E-01, 5.683E-01, 4.100E-01, 2.894E-01, 1.993E-01, 1.372E-01, 9.685E-02, 6.914E-02, 5.076E-02, 3.851E-02, 2.990E-02, 2.414E-02, 1.714E-02, 1.249E-02, 1.084E-02, 9.637E-03, 8.826E-03, 8.251E-03, 7.945E-03, 7.913E-03, 7.839E-03, 6.205E-03, 5.395E-03, 5.376E-03, 5.855E-03, 5.805E-03, 5.727E-03},
     {2.326E-04, 2.787E-02, 3.339E-02, 5.035E-02, 6.247E-02, 9.966E-02, 1.074E-01, 1.442E-01, 1.041E-01, 3.121E-01, 4.634E-01, 6.124E-01, 6.707E-01, 6.990E-01, 7.462E-01, 8.168E-01, 9.110E-01, 1.022E+00, 1.100E+00, 1.156E+00, 1.212E+00, 1.261E+00, 1.307E+00, 1.336E+00, 1.353E+00, 1.354E+00, 1.353E+00, 1.360E+00, 1.376E+00, 1.354E+00, 1.326E+00, 1.264E+00, 1.198E+00, 1.132E+00, 1.062E+00, 9.996E-01, 9.498E-01, 9.122E-01, 8.609E-01, 8.217E-01, 8.276E-01, 8.657E-01, 9.451E-01, 1.048E+00, 1.196E+00, 1.360E+00, 1.538E+00, 1.600E+00, 1.634E+00, 1.581E+00, 1.403E+00, 1.211E+00, 9.999E-01, 7.865E-01, 5.984E-01, 4.296E-01, 3.034E-01, 2.107E-01, 1.463E-01, 1.024E-01, 7.337E-02, 5.378E-02, 4.052E-02, 3.077E-02, 2.339E-02, 1.753E-02, 1.269E-02, 1.092E-02, 9.353E-03, 9.002E-03, 7.919E-03, 4.869E-03, 6.104E-03, 4.942E-03, 3.426E-03, 2.660E-03, 2.304E-03, 2.039E-03, 1.059E-03, 5.481E-04},
     {2.328E-04, 3.090E-02, 4.163E-02, 4.817E-02, 5.984E-02, 9.593E-02, 1.055E-01, 1.605E-01, 1.151E-01, 3.110E-01, 4.780E-01, 6.027E-01, 6.617E-01, 6.884E-01, 7.227E-01, 7.992E-01, 8.973E-01, 1.001E+00, 1.085E+00, 1.149E+00, 1.217E+00, 1.260E+00, 1.303E+00, 1.342E+00, 1.352E+00, 1.359E+00, 1.367E+00, 1.366E+00, 1.386E+00, 1.359E+00, 1.335E+00, 1.267E+00, 1.203E+00, 1.130E+00, 1.060E+00, 9.983E-01, 9.556E-01, 9.185E-01, 8.634E-01, 8.242E-01, 8.302E-01, 8.673E-01, 9.375E-01, 1.051E+00, 1.194E+00, 1.359E+00, 1.540E+00, 1.593E+00, 1.626E+00, 1.570E+00, 1.398E+00, 1.220E+00, 9.918E-01, 7.834E-01, 5.988E-01, 4.256E-01, 3.069E-01, 2.102E-01, 1.467E-01, 1.022E-01, 7.271E-02, 5.372E-02, 4.035E-02, 3.002E-02, 2.315E-02, 1.791E-02, 1.267E-02, 1.052E-02, 9.544E-03, 8.520E-03, 8.017E-03, 6.324E-03, 6.082E-03, 5.663E-03, 2.850E-03, 3.110E-03, 2.375E-03, 1.463E-03, 1.312E-03, 4.850E-04},
     {2.564E-04, 3.837E-02, 3.059E-02, 5.322E-02, 6.786E-02, 9.388E-02, 1.256E-01, 1.484E-01, 1.033E-01, 3.382E-01, 4.688E-01, 6.103E-01, 6.883E-01, 6.948E-01, 7.502E-01, 8.297E-01, 9.089E-01, 9.969E-01, 1.095E+00, 1.143E+00, 1.203E+00, 1.262E+00, 1.306E+00, 1.333E+00, 1.348E+00, 1.344E+00, 1.349E+00, 1.360E+00, 1.371E+00, 1.356E+00, 1.326E+00, 1.267E+00, 1.197E+00, 1.129E+00, 1.052E+00, 9.949E-01, 9.485E-01, 9.147E-01, 8.563E-01, 8.183E-01, 8.310E-01, 8.650E-01, 9.384E-01, 1.046E+00, 1.197E+00, 1.363E+00, 1.533E+00, 1.615E+00, 1.624E+00, 1.580E+00, 1.390E+00, 1.200E+00, 1.008E+00, 7.782E-01, 5.965E-01, 4.190E-01, 3.025E-01, 2.105E-01, 1.457E-01, 1.019E-01, 7.269E-02, 5.390E-02, 4.059E-02, 3.069E-02, 2.300E-02, 1.719E-02, 1.252E-02, 1.121E-02, 9.765E-03, 7.860E-03, 8.231E-03, 5.744E-03, 4.478E-03, 5.989E-03, 2.354E-03, 2.470E-03, 1.666E-03, 2.406E-03, 1.619E-03, 3.990E-04},
     {3.098E-04, 2.532E-02, 7.010E-02, 5.975E-02, 5.345E-02, 7.526E-02, 8.972E-02, 1.506E-01, 1.019E-01, 4.177E-01, 4.905E-01, 6.736E-01, 7.624E-01, 7.185E-01, 8.202E-01, 7.980E-01, 8.954E-01, 1.013E+00, 1.087E+00, 1.149E+00, 1.210E+00, 1.250E+00, 1.304E+00, 1.345E+00, 1.342E+00, 1.349E+00, 1.356E+00, 1.341E+00, 1.364E+00, 1.326E+00, 1.323E+00, 1.231E+00, 1.202E+00, 1.088E+00, 1.043E+00, 9.859E-01, 9.468E-01, 9.123E-01, 8.560E-01, 8.090E-01, 8.177E-01, 8.259E-01, 9.266E-01, 1.030E+00, 1.172E+00, 1.328E+00, 1.537E+00, 1.607E+00, 1.641E+00, 1.598E+00, 1.403E+00, 1.203E+00, 1.024E+00, 7.923E-01, 5.926E-01, 4.400E-01, 3.034E-01, 2.112E-01, 1.464E-01, 1.046E-01, 7.418E-02, 5.522E-02, 3.982E-02, 2.936E-02, 2.511E-02, 1.870E-02, 1.296E-02, 9.903E-03, 9.423E-03, 9.231E-03, 6.472E-03, 7.884E-03, 4.329E-03, 2.418E-03, 3.861E-03, 2.891E-03, 5.423E-04, 6.677E-03, 4.057E-04, 3.023E-04},
     {4.708E-04, 1.701E+00, -1.578E+00, 9.121E-01, 7.486E-01, 5.589E-01, 6.530E-01, 7.658E-01, 3.456E-01, 8.560E-01, 7.973E-01, 8.156E-01, 7.265E-01, 7.858E-01, 1.014E+00, 1.050E+00, 1.065E+00, 1.061E+00, 1.177E+00, 1.207E+00, 1.204E+00, 1.295E+00, 1.282E+00, 1.308E+00, 1.332E+00, 1.341E+00, 1.295E+00, 1.213E+00, 1.124E+00, 1.338E+00, 1.282E+00, 1.244E+00, 9.802E-01, 1.026E+00, 1.055E+00, 9.854E-01, 9.301E-01, 8.898E-01, 7.931E-01, 7.788E-01, 7.278E-01, 8.297E-01, 9.476E-01, 1.002E+00, 1.184E+00, 1.341E+00, 1.580E+00, 1.553E+00, 1.629E+00, 1.606E+00, 1.476E+00, 1.237E+00, 9.413E-01, 7.969E-01, 5.947E-01, 4.415E-01, 3.248E-01, 2.170E-01, 1.507E-01, 1.046E-01, 6.915E-02, 5.408E-02, 1.983E-02, 3.311E-02, 2.035E-02, 1.957E-02, 1.242E-02, 1.083E-02, 8.955E-03, 6.824E-03, 8.855E-03, 8.707E-03, 6.040E-03, 1.291E-02, 7.450E-03, 4.775E-03, 5.259E-03, 4.108E-03, 5.489E-03, 5.481E-03},
     {2.406E-04, 3.385E-02, 3.578E-02, 5.432E-02, 6.220E-02, 9.562E-02, 1.249E-01, 1.405E-01, 1.066E-01, 3.192E-01, 4.762E-01, 6.200E-01, 6.800E-01, 7.151E-01, 7.432E-01, 7.980E-01, 8.981E-01, 1.007E+00, 1.090E+00, 1.145E+00, 1.208E+00, 1.252E+00, 1.304E+00, 1.329E+00, 1.345E+00, 1.349E+00, 1.354E+00, 1.362E+00, 1.372E+00, 1.359E+00, 1.325E+00, 1.259E+00, 1.200E+00, 1.133E+00, 1.059E+00, 9.963E-01, 9.505E-01, 9.115E-01, 8.607E-01, 8.247E-01, 8.266E-01, 8.668E-01, 9.347E-01, 1.045E+00, 1.196E+00, 1.369E+00, 1.551E+00, 1.602E+00, 1.626E+00, 1.571E+00, 1.409E+00, 1.217E+00, 1.005E+00, 7.886E-01, 6.010E-01, 4.290E-01, 3.019E-01, 2.112E-01, 1.465E-01, 1.022E-01, 7.362E-02, 5.391E-02, 4.057E-02, 3.021E-02, 2.415E-02, 1.752E-02, 1.257E-02, 1.084E-02, 9.528E-03, 8.775E-03, 7.496E-03, 5.919E-03, 5.381E-03, 5.185E-03, 4.161E-03, 3.090E-03, 1.867E-03, 1.701E-03, 9.188E-04, 5.315E-04},
     {2.315E-01, 3.072E+00, 2.850E+00, 2.379E+00, 1.814E+00, 1.427E+00, 1.502E+00, 1.198E+00, 6.637E-01, 1.478E+00, 1.465E+00, 1.593E+00, 1.334E+00, 1.162E+00, 1.089E+00, 1.052E+00, 1.074E+00, 1.133E+00, 1.161E+00, 1.196E+00, 1.212E+00, 1.235E+00, 1.260E+00, 1.276E+00, 1.285E+00, 1.278E+00, 1.270E+00, 1.259E+00, 1.272E+00, 1.265E+00, 1.203E+00, 1.151E+00, 1.119E+00, 1.035E+00, 9.633E-01, 9.135E-01, 8.644E-01, 8.412E-01, 7.865E-01, 7.494E-01, 7.635E-01, 7.874E-01, 8.475E-01, 9.577E-01, 1.104E+00, 1.274E+00, 1.419E+00, 1.490E+00, 1.524E+00, 1.496E+00, 1.342E+00, 1.169E+00, 9.458E-01, 7.514E-01, 5.769E-01, 4.126E-01, 2.925E-01, 2.000E-01, 1.368E-01, 9.616E-02, 6.762E-02, 5.076E-02, 3.781E-02, 2.879E-02, 2.332E-02, 1.717E-02, 1.265E-02, 1.079E-02, 9.486E-03, 9.464E-03, 8.739E-03, 8.339E-03, 8.351E-03, 7.462E-03, 7.104E-03, 5.085E-03, 4.805E-03, 6.677E-03, 5.575E-03, 5.164E-03},
     {2.174E-01, 2.227E+00, 2.479E+00, 2.328E+00, 1.704E+00, 1.940E+00, 1.549E+00, 1.289E+00, 5.517E-01, 1.441E+00, 1.490E+00, 1.434E+00, 1.362E+00, 1.171E+00, 1.073E+00, 1.050E+00, 1.080E+00, 1.120E+00, 1.159E+00, 1.167E+00, 1.210E+00, 1.239E+00, 1.259E+00, 1.290E+00, 1.269E+00, 1.256E+00, 1.265E+00, 1.263E+00, 1.287E+00, 1.244E+00, 1.225E+00, 1.178E+00, 1.111E+00, 1.037E+00, 9.787E-01, 9.073E-01, 8.541E-01, 8.298E-01, 7.933E-01, 7.530E-01, 7.696E-01, 7.966E-01, 8.582E-01, 9.675E-01, 1.092E+00, 1.266E+00, 1.416E+00, 1.513E+00, 1.557E+00, 1.461E+00, 1.341E+00, 1.135E+00, 9.446E-01, 7.411E-01, 5.572E-01, 4.133E-01, 2.920E-01, 1.992E-01, 1.383E-01, 9.723E-02, 6.830E-02, 5.173E-02, 3.840E-02, 3.008E-02, 2.393E-02, 1.743E-02, 1.259E-02, 1.057E-02, 9.381E-03, 8.891E-03, 8.430E-03, 7.669E-03, 8.314E-03, 8.597E-03, 6.436E-03, 6.161E-03, 5.354E-03, 5.808E-03, 7.759E-03, 4.967E-03},
     {1.572E-01, 2.823E+00, 3.055E+00, 2.295E+00, 1.478E+00, 1.373E+00, 1.264E+00, 1.132E+00, 6.411E-01, 1.457E+00, 1.430E+00, 1.465E+00, 1.362E+00, 1.154E+00, 1.093E+00, 1.051E+00, 1.061E+00, 1.118E+00, 1.178E+00, 1.191E+00, 1.207E+00, 1.267E+00, 1.251E+00, 1.274E+00, 1.267E+00, 1.288E+00, 1.274E+00, 1.276E+00, 1.269E+00, 1.253E+00, 1.226E+00, 1.163E+00, 1.108E+00, 1.031E+00, 9.792E-01, 9.190E-01, 8.577E-01, 8.364E-01, 7.998E-01, 7.505E-01, 7.587E-01, 7.996E-01, 8.608E-01, 9.585E-01, 1.094E+00, 1.239E+00, 1.403E+00, 1.476E+00, 1.520E+00, 1.470E+00, 1.327E+00, 1.124E+00, 9.653E-01, 7.601E-01, 5.713E-01, 4.137E-01, 2.874E-01, 1.990E-01, 1.410E-01, 9.522E-02, 6.876E-02, 4.921E-02, 3.726E-02, 2.983E-02, 2.373E-02, 1.658E-02, 1.257E-02, 1.075E-02, 9.609E-03, 8.271E-03, 8.340E-03, 8.770E-03, 7.378E-03, 7.303E-03, 5.912E-03, 5.315E-03, 7.372E-03, 6.092E-03, 5.033E-03, 5.305E-03},
     {2.160E-01, 2.263E+00, 1.119E+01, 2.336E+00, 1.736E+00, 1.510E+00, 1.077E+00, 1.176E+00, 7.053E-01, 1.423E+00, 1.569E+00, 1.440E+00, 1.375E+00, 1.159E+00, 1.075E+00, 1.069E+00, 1.062E+00, 1.133E+00, 1.158E+00, 1.204E+00, 1.216E+00, 1.240E+00, 1.263E+00, 1.282E+00, 1.286E+00, 1.287E+00, 1.260E+00, 1.280E+00, 1.266E+00, 1.247E+00, 1.234E+00, 1.178E+00, 1.121E+00, 1.030E+00, 9.682E-01, 9.054E-01, 8.685E-01, 8.296E-01, 7.917E-01, 7.498E-01, 7.487E-01, 7.899E-01, 8.571E-01, 9.687E-01, 1.098E+00, 1.254E+00, 1.410E+00, 1.492E+00, 1.542E+00, 1.455E+00, 1.350E+00, 1.139E+00, 9.516E-01, 7.482E-01, 5.658E-01, 4.106E-01, 2.926E-01, 1.957E-01, 1.395E-01, 9.392E-02, 6.780E-02, 5.034E-02, 3.757E-02, 3.000E-02, 2.382E-02, 1.738E-02, 1.216E-02, 1.105E-02, 9.388E-03, 8.357E-03, 8.885E-03, 8.099E-03, 7.050E-03, 6.724E-03, 6.228E-03, 4.828E-03, 5.222E-03, 5.245E-03, 7.617E-03, 7.289E-03},
     {2.423E-01, 4.315E+00, 2.464E+00, 2.864E+00, 1.174E+00, 1.485E+00, 1.268E+00, 1.222E+00, 5.845E-01, 1.453E+00, 1.426E+00, 1.488E+00, 1.321E+00, 1.167E+00, 1.076E+00, 1.052E+00, 1.066E+00, 1.122E+00, 1.151E+00, 1.206E+00, 1.209E+00, 1.239E+00, 1.250E+00, 1.286E+00, 1.282E+00, 1.269E+00, 1.251E+00, 1.263E+00, 1.273E+00, 1.269E+00, 1.204E+00, 1.178E+00, 1.108E+00, 1.043E+00, 9.572E-01, 9.212E-01, 8.694E-01, 8.428E-01, 7.893E-01, 7.578E-01, 7.580E-01, 7.940E-01, 8.664E-01, 9.559E-01, 1.096E+00, 1.248E+00, 1.412E+00, 1.500E+00, 1.509E+00, 1.463E+00, 1.369E+00, 1.149E+00, 9.606E-01, 7.550E-01, 5.693E-01, 4.126E-01, 2.883E-01, 1.976E-01, 1.379E-01, 9.559E-02, 6.876E-02, 5.059E-02, 3.842E-02, 3.008E-02, 2.387E-02, 1.667E-02, 1.304E-02, 1.021E-02, 1.031E-02, 8.361E-03, 8.001E-03, 8.146E-03, 7.446E-03, 8.348E-03, 5.815E-03, 4.387E-03, 4.728E-03, 6.252E-03, 4.515E-03, 5.561E-03},
     {1.617E-01, 4.064E+00, 2.742E+00, 2.266E+00, 1.559E+00, 1.377E+00, 1.402E+00, 1.178E+00, 6.902E-01, 1.501E+00, 1.659E+00, 1.587E+00, 1.368E+00, 1.170E+00, 1.114E+00, 1.061E+00, 1.092E+00, 1.130E+00, 1.172E+00, 1.207E+00, 1.183E+00, 1.234E+00, 1.261E+00, 1.254E+00, 1.287E+00, 1.263E+00, 1.272E+00, 1.246E+00, 1.266E+00, 1.262E+00, 1.218E+00, 1.166E+00, 1.121E+00, 1.039E+00, 9.762E-01, 8.993E-01, 8.753E-01, 8.349E-01, 7.893E-01, 7.575E-01, 7.539E-01, 7.984E-01, 8.531E-01, 9.740E-01, 1.119E+00, 1.251E+00, 1.404E+00, 1.488E+00, 1.556E+00, 1.446E+00, 1.355E+00, 1.132E+00, 9.286E-01, 7.537E-01, 5.683E-01, 4.106E-01, 2.881E-01, 1.966E-01, 1.355E-01, 9.763E-02, 6.776E-02, 5.132E-02, 3.890E-02, 2.995E-02, 2.371E-02, 1.746E-02, 1.324E-02, 1.051E-02, 9.834E-03, 8.969E-03, 7.766E-03, 7.762E-03, 8.075E-03, 9.524E-03, 8.243E-03, 5.045E-03, 5.098E-03, 4.711E-03, 4.371E-03, 6.547E-03},
     {3.073E-01, 2.023E+00, 2.628E+00, 2.467E+00, 1.432E+00, 1.146E+00, 1.139E+00, 1.750E+00, 5.444E-01, 1.307E+00, 1.464E+00, 1.483E+00, 1.358E+00, 1.188E+00, 1.069E+00, 1.036E+00, 1.110E+00, 1.127E+00, 1.156E+00, 1.209E+00, 1.195E+00, 1.237E+00, 1.262E+00, 1.289E+00, 1.287E+00, 1.264E+00, 1.262E+00, 1.249E+00, 1.281E+00, 1.250E+00, 1.228E+00, 1.186E+00, 1.097E+00, 1.033E+00, 9.705E-01, 9.052E-01, 8.553E-01, 8.536E-01, 7.986E-01, 7.560E-01, 7.652E-01, 8.156E-01, 8.463E-01, 9.698E-01, 1.088E+00, 1.243E+00, 1.417E+00, 1.469E+00, 1.544E+00, 1.439E+00, 1.331E+00, 1.134E+00, 9.276E-01, 7.655E-01, 5.659E-01, 4.075E-01, 2.903E-01, 1.991E-01, 1.353E-01, 9.565E-02, 6.819E-02, 5.082E-02, 3.936E-02, 2.947E-02, 2.426E-02, 1.780E-02, 1.251E-02, 1.031E-02, 1.034E-02, 9.703E-03, 8.115E-03, 7.457E-03, 6.907E-03, 6.714E-03, 5.733E-03, 7.032E-03, 5.893E-03, 4.560E-03, 7.615E-03, 4.148E-03},
     {1.575E-01, 2.376E+00, 5.511E+00, 4.140E+00, 2.222E+00, 1.022E+00, 1.414E+00, 1.012E+00, 5.570E-01, 1.627E+00, 1.349E+00, 1.507E+00, 1.347E+00, 1.251E+00, 1.103E+00, 1.054E+00, 1.092E+00, 1.122E+00, 1.182E+00, 1.167E+00, 1.212E+00, 1.234E+00, 1.264E+00, 1.287E+00, 1.260E+00, 1.284E+00, 1.277E+00, 1.250E+00, 1.300E+00, 1.262E+00, 1.246E+00, 1.159E+00, 1.099E+00, 1.041E+00, 9.627E-01, 9.212E-01, 8.749E-01, 8.307E-01, 7.929E-01, 7.360E-01, 7.686E-01, 7.892E-01, 8.466E-01, 9.500E-01, 1.047E+00, 1.288E+00, 1.426E+00, 1.505E+00, 1.517E+00, 1.455E+00, 1.287E+00, 1.121E+00, 9.316E-01, 7.538E-01, 5.805E-01, 4.069E-01, 2.963E-01, 1.982E-01, 1.402E-01, 9.389E-02, 6.983E-02, 5.031E-02, 3.893E-02, 3.000E-02, 2.573E-02, 1.678E-02, 1.244E-02, 1.088E-02, 9.356E-03, 8.698E-03, 8.022E-03, 6.875E-03, 1.100E-02, 9.955E-03, 7.337E-03, 4.677E-03, 6.427E-03, 6.148E-03, 8.214E-03, 3.827E-03},
     {1.870E-01, 4.744E+00, 3.217E+00, 2.383E+00, 1.802E+00, 1.486E+00, 1.329E+00, 1.205E+00, 6.102E-01, 1.495E+00, 1.516E+00, 1.478E+00, 1.319E+00, 1.164E+00, 1.076E+00, 1.050E+00, 1.080E+00, 1.130E+00, 1.165E+00, 1.189E+00, 1.212E+00, 1.236E+00, 1.258E+00, 1.271E+00, 1.271E+00, 1.272E+00, 1.272E+00, 1.268E+00, 1.277E+00, 1.253E+00, 1.221E+00, 1.169E+00, 1.109E+00, 1.039E+00, 9.688E-01, 9.133E-01, 8.658E-01, 8.371E-01, 7.900E-01, 7.512E-01, 7.587E-01, 7.925E-01, 8.574E-01, 9.586E-01, 1.093E+00, 1.257E+00, 1.420E+00, 1.493E+00, 1.527E+00, 1.462E+00, 1.338E+00, 1.155E+00, 9.495E-01, 7.493E-01, 5.703E-01, 4.107E-01, 2.901E-01, 1.994E-01, 1.376E-01, 9.651E-02, 6.895E-02, 5.073E-02, 3.841E-02, 2.999E-02, 2.412E-02, 1.701E-02, 1.244E-02, 1.072E-02, 9.630E-03, 8.829E-03, 8.312E-03, 8.101E-03, 7.724E-03, 7.905E-03, 6.299E-03, 5.287E-03, 5.476E-03, 5.776E-03, 5.866E-03, 6.320E-03},
     {1.913E-01, 4.255E+00, 3.444E+00, 2.481E+00, 1.640E+00, 1.531E+00, 1.288E+00, 1.270E+00, 5.997E-01, 1.442E+00, 1.477E+00, 1.476E+00, 1.330E+00, 1.169E+00, 1.083E+00, 1.051E+00, 1.078E+00, 1.126E+00, 1.166E+00, 1.188E+00, 1.211E+00, 1.238E+00, 1.256E+00, 1.271E+00, 1.273E+00, 1.274E+00, 1.271E+00, 1.267E+00, 1.274E+00, 1.254E+00, 1.220E+00, 1.167E+00, 1.113E+00, 1.037E+00, 9.688E-01, 9.129E-01, 8.681E-01, 8.336E-01, 7.865E-01, 7.516E-01, 7.576E-01, 7.948E-01, 8.593E-01, 9.561E-01, 1.097E+00, 1.258E+00, 1.421E+00, 1.492E+00, 1.534E+00, 1.461E+00, 1.341E+00, 1.156E+00, 9.519E-01, 7.507E-01, 5.693E-01, 4.101E-01, 2.896E-01, 1.981E-01, 1.374E-01, 9.658E-02, 6.937E-02, 5.074E-02, 3.867E-02, 2.989E-02, 2.413E-02, 1.713E-02, 1.250E-02, 1.076E-02, 9.502E-03, 8.767E-03, 8.258E-03, 8.063E-03, 7.855E-03, 7.777E-03, 6.306E-03, 5.442E-03, 5.528E-03, 5.516E-03, 6.168E-03, 5.712E-03},
     {1.898E-01, 4.165E+00, 3.239E+00, 2.648E+00, 1.610E+00, 1.494E+00, 1.289E+00, 1.238E+00, 6.235E-01, 1.438E+00, 1.486E+00, 1.484E+00, 1.339E+00, 1.165E+00, 1.076E+00, 1.050E+00, 1.080E+00, 1.129E+00, 1.168E+00, 1.188E+00, 1.213E+00, 1.239E+00, 1.262E+00, 1.272E+00, 1.272E+00, 1.269E+00, 1.273E+00, 1.266E+00, 1.276E+00, 1.250E+00, 1.221E+00, 1.171E+00, 1.110E+00, 1.038E+00, 9.687E-01, 9.137E-01, 8.687E-01, 8.352E-01, 7.870E-01, 7.480E-01, 7.602E-01, 7.922E-01, 8.591E-01, 9.607E-01, 1.091E+00, 1.255E+00, 1.415E+00, 1.496E+00, 1.528E+00, 1.460E+00, 1.339E+00, 1.154E+00, 9.493E-01, 7.497E-01, 5.703E-01, 4.105E-01, 2.896E-01, 1.985E-01, 1.373E-01, 9.672E-02, 6.940E-02, 5.067E-02, 3.834E-02, 3.009E-02, 2.403E-02, 1.718E-02, 1.255E-02, 1.087E-02, 9.529E-03, 8.865E-03, 8.370E-03, 7.970E-03, 7.921E-03, 7.850E-03, 6.155E-03, 5.393E-03, 5.518E-03, 5.859E-03, 5.714E-03, 6.418E-03},
     {1.897E-01, 3.957E+00, 3.856E+00, 2.684E+00, 1.643E+00, 1.480E+00, 1.304E+00, 1.284E+00, 6.124E-01, 1.434E+00, 1.497E+00, 1.483E+00, 1.326E+00, 1.166E+00, 1.080E+00, 1.051E+00, 1.074E+00, 1.126E+00, 1.163E+00, 1.187E+00, 1.212E+00, 1.238E+00, 1.260E+00, 1.268E+00, 1.274E+00, 1.274E+00, 1.270E+00, 1.269E+00, 1.277E+00, 1.252E+00, 1.224E+00, 1.171E+00, 1.110E+00, 1.038E+00, 9.698E-01, 9.114E-01, 8.652E-01, 8.348E-01, 7.895E-01, 7.498E-01, 7.574E-01, 7.921E-01, 8.594E-01, 9.566E-01, 1.096E+00, 1.260E+00, 1.419E+00, 1.496E+00, 1.534E+00, 1.465E+00, 1.340E+00, 1.157E+00, 9.516E-01, 7.506E-01, 5.693E-01, 4.110E-01, 2.894E-01, 1.974E-01, 1.380E-01, 9.660E-02, 6.948E-02, 5.088E-02, 3.837E-02, 2.965E-02, 2.417E-02, 1.699E-02, 1.248E-02, 1.080E-02, 9.539E-03, 8.775E-03, 8.265E-03, 8.058E-03, 7.837E-03, 7.898E-03, 6.202E-03, 5.428E-03, 5.554E-03, 5.352E-03, 5.705E-03, 6.037E-03},
     {1.899E-01, 3.543E+00, 3.519E+00, 2.642E+00, 1.581E+00, 1.495E+00, 1.296E+00, 1.289E+00, 6.150E-01, 1.486E+00, 1.474E+00, 1.479E+00, 1.324E+00, 1.167E+00, 1.074E+00, 1.054E+00, 1.080E+00, 1.133E+00, 1.165E+00, 1.186E+00, 1.215E+00, 1.238E+00, 1.261E+00, 1.271E+00, 1.273E+00, 1.274E+00, 1.268E+00, 1.265E+00, 1.274E+00, 1.253E+00, 1.223E+00, 1.171E+00, 1.109E+00, 1.036E+00, 9.682E-01, 9.106E-01, 8.671E-01, 8.343E-01, 7.894E-01, 7.523E-01, 7.561E-01, 7.949E-01, 8.588E-01, 9.588E-01, 1.095E+00, 1.253E+00, 1.420E+00, 1.494E+00, 1.534E+00, 1.461E+00, 1.336E+00, 1.154E+00, 9.528E-01, 7.531E-01, 5.697E-01, 4.117E-01, 2.903E-01, 1.985E-01, 1.375E-01, 9.617E-02, 6.911E-02, 5.078E-02, 3.842E-02, 2.983E-02, 2.402E-02, 1.707E-02, 1.242E-02, 1.086E-02, 9.659E-03, 8.759E-03, 8.298E-03, 8.003E-03, 7.673E-03, 7.920E-03, 6.423E-03, 5.314E-03, 5.516E-03, 5.349E-03, 5.832E-03, 5.663E-03},
   };


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
   cout << "Pileup index: " << pileupIndex << endl;
   
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
      // Check jet size alignment
      // ----------------------------------------------------------------------------

      unsigned int ak8ptsize = theJetAK8Pt_JetSubCalc->size();
      unsigned int bestsize = dnn_Higgs_BestCalc->size();
      unsigned int deepak8size = dnn_H_DeepAK8Calc->size();
      if(bestsize != ak8ptsize){
	std::cout << "Something's wrong! BEST has " << bestsize << " jets, expected " << ak8ptsize << std::endl;
	continue;
      }
      if(deepak8size != ak8ptsize){
	std::cout << "Something's wrong! DeepAK8 has " << bestsize << " jets, expected " << ak8ptsize << std::endl;
	continue;
      }

      // ----------------------------------------------------------------------------
      // Pileup weight calculation
      // ----------------------------------------------------------------------------

      pileupWeight = 1.0;
      pileupWeightUp = 1.0;
      pileupWeightDown = 1.0;
	
      if(isMC){
	if(nTrueInteractions_singleLepCalc > 79) nTrueInteractions_singleLepCalc = 79;
	if(nTrueInteractions_singleLepCalc < 0) nTrueInteractions_singleLepCalc = 0;
	if(pileupIndex < 1 || pileupIndex > 32){
	  std::cout << "I don't know this pileup sample, using TTToSemiLeptonic's" << std::endl;
	  pileupIndex = 14;
	}
	pileupWeight = pileupweight[pileupIndex-1][nTrueInteractions_singleLepCalc];
	pileupWeightUp = pileupweightUp[pileupIndex-1][nTrueInteractions_singleLepCalc];
	pileupWeightDown = pileupweightDn[pileupIndex-1][nTrueInteractions_singleLepCalc];
      }

      // ----------------------------------------------------------------------------
      // Assign Lepton scale factor or efficiency weights, save trigger pass/fail
      // ----------------------------------------------------------------------------

      DataPastTrigger = 0;
      MCPastTrigger = 0;
      EGammaGsfSF = 1.0;
      lepIdSF = 1.0;

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
	  // Gsf Tracking scale factor: http://fcouderc.web.cern.ch/fcouderc/EGamma/scaleFactors/Moriond17/approval/RECO/passingRECO/egammaEffi.txt_egammaPlots.pdf
	  if (leppt < 45) {
	    if (lepeta < -2.0) EGammaGsfSF = 0.977;
	    else if (lepeta < -1.566) EGammaGsfSF = 0.982;
	    else if (lepeta < -1.442) EGammaGsfSF = 0.948;
	    else if (lepeta < -1.0) EGammaGsfSF = 0.969;
	    else if (lepeta < -0.5) EGammaGsfSF = 0.977;
	    else if (lepeta < 0.5) EGammaGsfSF = 0.970;
	    else if (lepeta < 1.0) EGammaGsfSF = 0.972;
	    else if (lepeta < 1.442) EGammaGsfSF = 0.970;
	    else if (lepeta < 1.566) EGammaGsfSF = 0.958;
	    else EGammaGsfSF = 0.980; }
	  else if (leppt < 75) {
	    if (lepeta < -2.0) EGammaGsfSF = 0.984;
	    else if (lepeta < -1.566) EGammaGsfSF = 0.982;
	    else if (lepeta < -1.442) EGammaGsfSF = 0.971;
	    else if (lepeta < -1.0) EGammaGsfSF = 0.976;
	    else if (lepeta < 0.0) EGammaGsfSF = 0.980;
	    else if (lepeta < 0.5) EGammaGsfSF = 0.978;
	    else if (lepeta < 1.0) EGammaGsfSF = 0.979;
	    else if (lepeta < 1.442) EGammaGsfSF = 0.977;
	    else if (lepeta < 1.566) EGammaGsfSF = 0.964;
	    else if (lepeta < 2.0) EGammaGsfSF = 0.983;
	    else EGammaGsfSF = 0.984; }
	  else if (leppt < 100) {
	    if (lepeta < -1.566) EGammaGsfSF = 0.997;
	    else if (lepeta < -1.442) EGammaGsfSF = 1.003;
	    else if (lepeta < -1.0) EGammaGsfSF = 0.996;
	    else if (lepeta < 1.0) EGammaGsfSF = 0.992;
	    else if (lepeta < 1.442) EGammaGsfSF = 0.996;
	    else if (lepeta < 1.566) EGammaGsfSF = 1.003;
	    else EGammaGsfSF = 0.997; }
	  else {
	    if (lepeta < -1.566) EGammaGsfSF = 0.990;
	    else if (lepeta < -1.442) EGammaGsfSF = 1.010;
	    else if (lepeta < -1.0) EGammaGsfSF = 0.985;
	    else if (lepeta < -0.5) EGammaGsfSF = 0.988;
	    else if (lepeta < 0.5) EGammaGsfSF = 0.994;
	    else if (lepeta < 1.0) EGammaGsfSF = 0.988;
	    else if (lepeta < 1.442) EGammaGsfSF = 0.985;
	    else if (lepeta < 1.566) EGammaGsfSF = 1.010;
	    else EGammaGsfSF = 0.990; }

	  if (leppt < 20) {
	    if (lepeta < -2.0) lepIdSF = 0.900;
	    else if (lepeta < -1.566) lepIdSF = 0.950;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.973;
	    else if (lepeta < 0.0) lepIdSF = 0.989;
	    else if (lepeta < 0.8) lepIdSF = 0.991;
	    else if (lepeta < 1.442) lepIdSF = 0.995;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.972;
	    else lepIdSF = 0.885; }
	  else if (leppt < 35) {
	    if (lepeta < -2.0) lepIdSF = 0.891;
	    else if (lepeta < -1.566) lepIdSF = 0.908;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.934;
	    else if (lepeta < 0.0) lepIdSF = 0.958;
	    else if (lepeta < 0.8) lepIdSF = 0.961;
	    else if (lepeta < 1.442) lepIdSF = 0.943;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.913;
	    else lepIdSF = 0.884; }
	  else if (leppt < 50) {
	    if (lepeta < -2.0) lepIdSF = 0.916;
	    else if (lepeta < -1.566) lepIdSF = 0.934;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.944;
	    else if (lepeta < 0.0) lepIdSF = 0.958;
	    else if (lepeta < 0.8) lepIdSF = 0.959;
	    else if (lepeta < 1.442) lepIdSF = 0.948;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.937;
	    else lepIdSF = 0.912; }
	  else if (leppt < 100) {
	    if (lepeta < -2.0) lepIdSF = 0.921;
	    else if (lepeta < -1.566) lepIdSF = 0.941;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.947;
	    else if (lepeta < 0.0) lepIdSF = 0.962;
	    else if (lepeta < 0.8) lepIdSF = 0.960;
	    else if (lepeta < 1.442) lepIdSF = 0.951;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.949;
	    else lepIdSF = 0.918; }
	  else if (leppt < 200) {
	    if (lepeta < -2.0) lepIdSF = 0.965;
	    else if (lepeta < -1.566) lepIdSF = 0.970;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.972;
	    else if (lepeta < 0.0) lepIdSF = 0.981;
	    else if (lepeta < 0.8) lepIdSF = 0.979;
	    else if (lepeta < 1.442) lepIdSF = 0.973;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.984;
	    else lepIdSF = 0.971; }
	  else {
	    if (lepeta < -2.0) lepIdSF = 0.947;
	    else if (lepeta < -1.566) lepIdSF = 0.997;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.996;
	    else if (lepeta < 0.0) lepIdSF = 0.973;
	    else if (lepeta < 0.8) lepIdSF = 0.970;
	    else if (lepeta < 1.442) lepIdSF = 0.951;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.966;
	    else lepIdSF = 0.924; }
	}
	if(isMuon){
	  // ***** SAM, check these names, same below in Data section
	  std::string string_a = "Mu15_IsoVVVL_PFHT450";
	  std::string string_b = "Mu15_IsoVVVL_PFHT450_PFMET50";
	  std::string string_c = "Mu15_IsoVVVL_PFHT450_CaloBTagCSV_4p5";
	  std::string string_d = "Mu50_IsoVVVL_PFHT450";
	  std::string string_e = "Mu15_IsoVVVL_PFHT600";
	  std::string string_ORb = "Mu50";
	  std::string string_ORc = "TkMu50";
	  for(unsigned int itrig=0; itrig < vsSelMCTriggersMu_singleLepCalc->size(); itrig++){
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_a) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_b) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
            if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_c) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
            if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_d) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
            if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_e) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_ORc) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	  }
	  // Cut based tight id
	  if (fabs(lepeta) < 2.10 && fabs(lepeta) > 1.20) {
	    if (leppt < 25.0 && leppt > 20.0) lepIdSF = 0.9924252719877384;
	    else if (leppt < 60.0 && leppt > 50.0) lepIdSF = 0.9906364222943529;
	    else if (leppt < 30.0 && leppt > 25.0) lepIdSF = 0.9890884461284933;
	    else if (leppt < 120.0 && leppt > 60.0) lepIdSF = 0.9920464322143979;
	    else if (leppt < 40.0 && leppt > 30.0) lepIdSF = 0.9946469069883841;
	    else if (leppt < 50.0 && leppt > 40.0) lepIdSF = 0.9926528825155183; }
	  else if (fabs(lepeta) < 2.40 && leppt > 2.10) {
	    if (leppt < 25.0 && leppt > 20.0) lepIdSF = 0.9758095839531763;
	    else if (leppt < 60.0 && leppt > 50.0) lepIdSF = 0.9673568416097894;
	    else if (leppt < 30.0 && leppt > 25.0) lepIdSF = 0.9745153594179884;
	    else if (leppt < 120.0 && leppt > 60.0) lepIdSF = 0.9766311856731202;
	    else if (leppt < 40.0 && leppt > 30.0) lepIdSF = 0.9787410500158746;
	    else if (leppt < 50.0 && leppt > 40.0) lepIdSF = 0.978189122919501; }
	  else if (fabs(lepeta) < 1.20 && fabs(lepeta) > 0.90) {
	    if (leppt < 25.0 && leppt > 20.0) lepIdSF = 0.9927389275515244;
	    else if (leppt < 60.0 && leppt > 50.0) lepIdSF = 0.9839056384760008;
	    else if (leppt < 30.0 && leppt > 25.0) lepIdSF = 0.985063939762512;
	    else if (leppt < 120.0 && leppt > 60.0) lepIdSF = 0.984060403143468;
	    else if (leppt < 40.0 && leppt > 30.0) lepIdSF = 0.9865359464182247;
	    else if (leppt < 50.0 && leppt > 40.0) lepIdSF = 0.984913093101493; }
	  else if (fabs(lepeta) < 0.90 && fabs(lepeta) > 0.0) {
	    if (leppt < 25.0 && leppt > 20.0) lepIdSF = 0.9910777627756951;
	    else if (leppt < 60.0 && leppt > 50.0) lepIdSF = 0.9855545160334763;
	    else if (leppt < 30.0 && leppt > 25.0) lepIdSF = 0.987410468262084;
	    else if (leppt < 120.0 && leppt > 60.0) lepIdSF = 0.9898057377093389;
	    else if (leppt < 40.0 && leppt > 30.0) lepIdSF = 0.9907753279135898;
	    else if (leppt < 50.0 && leppt > 40.0) lepIdSF = 0.9892483588952047; }
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
	  std::string string_ORc = "TkMu50";
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
      
      if(isMC && MCPastTrigger) npass_trigger+=1;
      if(!isMC && DataPastTrigger) npass_trigger+=1;

      // ----------------------------------------------------------------------------
      // Generator-level HT correction
      // ----------------------------------------------------------------------------      

      HTSF_Pol = 1;
      HTSF_PolUp = 1;
      HTSF_PolDn = 1;

      if(isMadgraphBkg){
	// Piece-wise splice with a flat line. Uncertainty from upper/lower error bar fits
	HTSF_Pol = poly2->Eval(HTfromHEPUEP_singleLepCalc);
	HTSF_PolUp = poly2U->Eval(HTfromHEPUEP_singleLepCalc);
	HTSF_PolDn = poly2D->Eval(HTfromHEPUEP_singleLepCalc);
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


	// Add to total jets counter
	n_jetstotal++;

        // ----------------------------------------------------------------------------                                  
        // Counter and pt ordering pair                                                                                  
        // ----------------------------------------------------------------------------                                  
	
        NJetsAK8_JetSubCalc += 1;
        jetak8ptindpair.push_back(std::make_pair(theJetAK8Pt_JetSubCalc->at(ijet),ijet));
	
      }


      // ----------------------------------------------------------------------------
      // Apply kinematic cuts
      // ----------------------------------------------------------------------------
	                
      int isPastHTCut = 0;
      if(AK4HT >= htCut){npass_ht+=1;isPastHTCut=1;}

      int isPastNAK8JetsCut = 0;
      if(NJetsAK8_JetSubCalc >= nAK8jetsCut){npass_nAK8jets+=1;isPastNAK8JetsCut=1;}
      
      int isPastJetLeadPtCut = 1;
      //      if(theJetPt_JetSubCalc_PtOrdered.size() > 0 && theJetPt_JetSubCalc_PtOrdered[0] > JetLeadPtCut){npass_JetLeadPt+=1;isPastJetLeadPtCut=1;}
      
      int isPastJetSubLeadPtCut = 1;
      //      if(theJetPt_JetSubCalc_PtOrdered.size() > 1 && theJetPt_JetSubCalc_PtOrdered[1] > JetSubLeadPtCut){npass_JetSubLeadPt+=1;isPastJetSubLeadPtCut=1;}
      
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
      // Skip failing events
      // ----------------------------------------------------------------------------
            
      if(!(isPastMETcut && isPastHTCut && isPastNAK8JetsCut && isPastJetLeadPtCut && isPastLepPtCut && (isPastElEtaCut || isPastMuEtaCut) && isPastJetSubLeadPtCut)) continue;
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

      dnn_Higgs_BestCalc_PtOrdered.clear();
      dnn_Top_BestCalc_PtOrdered.clear();
      dnn_W_BestCalc_PtOrdered.clear();
      dnn_Z_BestCalc_PtOrdered.clear();
      dnn_B_BestCalc_PtOrdered.clear();
      dnn_QCD_BestCalc_PtOrdered.clear();
      dnn_J_DeepAK8Calc_PtOrdered.clear();
      dnn_T_DeepAK8Calc_PtOrdered.clear();
      dnn_H_DeepAK8Calc_PtOrdered.clear();
      dnn_W_DeepAK8Calc_PtOrdered.clear();
      dnn_Z_DeepAK8Calc_PtOrdered.clear();
      dnn_B_DeepAK8Calc_PtOrdered.clear();
      decorr_J_DeepAK8Calc_PtOrdered.clear();
      decorr_T_DeepAK8Calc_PtOrdered.clear();
      decorr_H_DeepAK8Calc_PtOrdered.clear();
      decorr_W_DeepAK8Calc_PtOrdered.clear();
      decorr_Z_DeepAK8Calc_PtOrdered.clear();
      decorr_B_DeepAK8Calc_PtOrdered.clear();

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
	dnn_Higgs_BestCalc_PtOrdered.push_back(dnn_Higgs_BestCalc->at(jetak8ptindpair[ijet].second));
	dnn_Top_BestCalc_PtOrdered.push_back(dnn_Top_BestCalc->at(jetak8ptindpair[ijet].second));
	dnn_W_BestCalc_PtOrdered.push_back(dnn_W_BestCalc->at(jetak8ptindpair[ijet].second));
	dnn_Z_BestCalc_PtOrdered.push_back(dnn_Z_BestCalc->at(jetak8ptindpair[ijet].second));
	dnn_B_BestCalc_PtOrdered.push_back(dnn_B_BestCalc->at(jetak8ptindpair[ijet].second));
	dnn_QCD_BestCalc_PtOrdered.push_back(dnn_QCD_BestCalc->at(jetak8ptindpair[ijet].second));
	dnn_J_DeepAK8Calc_PtOrdered.push_back(dnn_J_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	dnn_T_DeepAK8Calc_PtOrdered.push_back(dnn_T_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	dnn_H_DeepAK8Calc_PtOrdered.push_back(dnn_H_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	dnn_W_DeepAK8Calc_PtOrdered.push_back(dnn_W_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	dnn_Z_DeepAK8Calc_PtOrdered.push_back(dnn_Z_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	dnn_B_DeepAK8Calc_PtOrdered.push_back(dnn_B_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
        decorr_J_DeepAK8Calc_PtOrdered.push_back(decorr_J_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
        decorr_T_DeepAK8Calc_PtOrdered.push_back(decorr_T_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
        decorr_H_DeepAK8Calc_PtOrdered.push_back(decorr_H_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
        decorr_W_DeepAK8Calc_PtOrdered.push_back(decorr_W_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
        decorr_Z_DeepAK8Calc_PtOrdered.push_back(decorr_Z_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
        decorr_B_DeepAK8Calc_PtOrdered.push_back(decorr_B_DeepAK8Calc->at(jetak8ptindpair[ijet].second));

	maxProb_JetSubCalc_PtOrdered.push_back(maxProb_JetSubCalc->at(jetak8ptindpair[ijet].second));
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

      // Add probabilities
      probSum_BEST_all = 0;
      probSum_DeepAK8_all = 0;
      probSum_DeepAK8_decorr_all = 0;
      nB_BEST = 0;
      nH_BEST = 0;
      nJ_BEST = 0;
      nT_BEST = 0;
      nW_BEST = 0;
      nZ_BEST = 0;
      nB_DeepAK8 = 0;
      nH_DeepAK8 = 0;
      nJ_DeepAK8 = 0;
      nT_DeepAK8 = 0;
      nW_DeepAK8 = 0;
      nZ_DeepAK8 = 0;
      nB_DeepAK8_decorr = 0;
      nH_DeepAK8_decorr = 0;
      nJ_DeepAK8_decorr = 0;
      nT_DeepAK8_decorr = 0;
      nW_DeepAK8_decorr = 0;
      nZ_DeepAK8_decorr = 0;
      // 0 = J, 1 = T, 2 = H, 3 = Z, 4 = W, 5 = B
      for(unsigned int ijet=0; ijet < jetak8ptindpair.size(); ijet++){
        if (dnn_B_BestCalc_PtOrdered.at(ijet) < -900) dnn_B_BestCalc_PtOrdered.at(ijet) = 0;
        if (dnn_Higgs_BestCalc_PtOrdered.at(ijet) < -900) dnn_Higgs_BestCalc_PtOrdered.at(ijet) = 0;
        if (dnn_QCD_BestCalc_PtOrdered.at(ijet) < -900) dnn_QCD_BestCalc_PtOrdered.at(ijet) = 0;
        if (dnn_Top_BestCalc_PtOrdered.at(ijet) < -900) dnn_Top_BestCalc_PtOrdered.at(ijet) = 0;
        if (dnn_W_BestCalc_PtOrdered.at(ijet) < -900) dnn_W_BestCalc_PtOrdered.at(ijet) = 0;
        if (dnn_Z_BestCalc_PtOrdered.at(ijet) < -900) dnn_Z_BestCalc_PtOrdered.at(ijet) = 0;
        if (dnn_B_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_B_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (dnn_H_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_H_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (dnn_J_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_J_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (dnn_T_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_T_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (dnn_W_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_W_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (dnn_Z_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_Z_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (decorr_B_DeepAK8Calc_PtOrdered.at(ijet) < -900) decorr_B_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (decorr_H_DeepAK8Calc_PtOrdered.at(ijet) < -900) decorr_H_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (decorr_J_DeepAK8Calc_PtOrdered.at(ijet) < -900) decorr_J_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (decorr_T_DeepAK8Calc_PtOrdered.at(ijet) < -900) decorr_T_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (decorr_W_DeepAK8Calc_PtOrdered.at(ijet) < -900) decorr_W_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (decorr_Z_DeepAK8Calc_PtOrdered.at(ijet) < -900) decorr_Z_DeepAK8Calc_PtOrdered.at(ijet) = 0;

        probSum_BEST_all += dnn_B_BestCalc_PtOrdered.at(ijet) + 2*dnn_W_BestCalc_PtOrdered.at(ijet) + 2*dnn_Top_BestCalc_PtOrdered.at(ijet) + 3*dnn_Z_BestCalc_PtOrdered.at(ijet) + 4*dnn_Higgs_BestCalc_PtOrdered.at(ijet);
        probSum_DeepAK8_all += dnn_B_DeepAK8Calc_PtOrdered.at(ijet) + 2*dnn_W_DeepAK8Calc_PtOrdered.at(ijet) + 2*dnn_T_DeepAK8Calc_PtOrdered.at(ijet) + 3*dnn_Z_DeepAK8Calc_PtOrdered.at(ijet) + 4*dnn_H_DeepAK8Calc_PtOrdered.at(ijet);
        probSum_DeepAK8_decorr_all += decorr_B_DeepAK8Calc_PtOrdered.at(ijet) + 2*decorr_W_DeepAK8Calc_PtOrdered.at(ijet) + 2*decorr_T_DeepAK8Calc_PtOrdered.at(ijet) + 3*decorr_Z_DeepAK8Calc_PtOrdered.at(ijet) + 4*decorr_H_DeepAK8Calc_PtOrdered.at(ijet);

        if (dnn_largest_BestCalc_PtOrdered.at(ijet) == 1) nT_BEST += 1;
        else if (dnn_largest_BestCalc_PtOrdered.at(ijet) == 2) nH_BEST += 1;
        else if (dnn_largest_BestCalc_PtOrdered.at(ijet) == 3) nZ_BEST += 1;
        else if (dnn_largest_BestCalc_PtOrdered.at(ijet) == 4) nW_BEST += 1;
        else if (dnn_largest_BestCalc_PtOrdered.at(ijet) == 5) nB_BEST += 1;
        else nJ_BEST += 1;

        if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 1) nT_DeepAK8 += 1;
        else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 2) nH_DeepAK8 += 1;
        else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 3) nZ_DeepAK8 += 1;
        else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 4) nW_DeepAK8 += 1;
	//        else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 5) nB_DeepAK8 += 1;
	else if (theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.at(ijet) > 0) nB_DeepAK8 += 1;
        else nJ_DeepAK8 += 1;

        if (decorr_largest_DeepAK8Calc_PtOrdered.at(ijet) == 1) nT_DeepAK8_decorr += 1;
        else if (decorr_largest_DeepAK8Calc_PtOrdered.at(ijet) == 2) nH_DeepAK8_decorr += 1;
        else if (decorr_largest_DeepAK8Calc_PtOrdered.at(ijet) == 3) nZ_DeepAK8_decorr += 1;
        else if (decorr_largest_DeepAK8Calc_PtOrdered.at(ijet) == 4) nW_DeepAK8_decorr += 1;
        else if (decorr_largest_DeepAK8Calc_PtOrdered.at(ijet) == 5) nB_DeepAK8_decorr += 1;
        else nJ_DeepAK8_decorr += 1;
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
      deltaR_leptonicparticle_AK8_PtOrdered.clear();
      taggedXXXX_BEST.clear();
      taggedXXXX_DeepAK8.clear();
      taggedXXXX_DeepAK8_decorr.clear();

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

	  if (not (isWmatched && matchedPt > 200) && not (isZmatched && matchedPt > 200) && not (isTmatched && matchedPt > 400) && not (isHmatched && matchedPt > 300)) {
	    int firstsub = theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered.at(ijet);
	    int nsubs = theJetAK8SDSubjetSize_JetSubCalc_PtOrdered.at(ijet);
	    for(int isub = firstsub; isub < firstsub + nsubs; isub++){
	      if( theJetAK8SDSubjetHFlav_JetSubCalc->at(isub) == 5 ) isBmatched = true;
	    }
	    if ( not isBmatched ) isJmatched = true;
	  }

	  if(isJmatched) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(0);
	  if(isTmatched && matchedPt > 400) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(1);
	  if(isHmatched && matchedPt > 300) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(2);
	  if(isZmatched && matchedPt > 200) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(3);
	  if(isWmatched && matchedPt > 200) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(4);
	  if(isBmatched) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(5);

	  // ----------------------------------------------------------------------------
	  // Filling 3D probability histograms
	  // ----------------------------------------------------------------------------
	  double xBEST = dnn_Higgs_BestCalc_PtOrdered.at(ijet) - dnn_W_BestCalc_PtOrdered.at(ijet);
	  double yBEST = dnn_Top_BestCalc_PtOrdered.at(ijet) - dnn_Z_BestCalc_PtOrdered.at(ijet);
	  double zBEST = dnn_B_BestCalc_PtOrdered.at(ijet) - dnn_QCD_BestCalc_PtOrdered.at(ijet);
	  double xDeepAK8 = dnn_H_DeepAK8Calc_PtOrdered.at(ijet) - dnn_W_DeepAK8Calc_PtOrdered.at(ijet);
	  double yDeepAK8 = dnn_T_DeepAK8Calc_PtOrdered.at(ijet) - dnn_Z_DeepAK8Calc_PtOrdered.at(ijet);
	  double zDeepAK8 = dnn_B_DeepAK8Calc_PtOrdered.at(ijet) - dnn_J_DeepAK8Calc_PtOrdered.at(ijet);
	  double xDeepAK8_decorr = decorr_H_DeepAK8Calc_PtOrdered.at(ijet) - decorr_W_DeepAK8Calc_PtOrdered.at(ijet);
	  double yDeepAK8_decorr = decorr_T_DeepAK8Calc_PtOrdered.at(ijet) - decorr_Z_DeepAK8Calc_PtOrdered.at(ijet);
	  double zDeepAK8_decorr = decorr_B_DeepAK8Calc_PtOrdered.at(ijet) - decorr_J_DeepAK8Calc_PtOrdered.at(ijet);

	  int match = theJetAK8Truth_JetSubCalc_PtOrdered.at(ijet);
	  // if(match == 0) {jProb_BEST->Fill(xBEST,yBEST,zBEST); jProb_DeepAK8->Fill(xDeepAK8,yDeepAK8,zDeepAK8); jProb_DeepAK8_decorr->Fill(xDeepAK8_decorr,yDeepAK8_decorr,zDeepAK8_decorr);}
	  // if(match == 1) {tProb_BEST->Fill(xBEST,yBEST,zBEST); tProb_DeepAK8->Fill(xDeepAK8,yDeepAK8,zDeepAK8); tProb_DeepAK8_decorr->Fill(xDeepAK8_decorr,yDeepAK8_decorr,zDeepAK8_decorr);}
	  // if(match == 2) {HProb_BEST->Fill(xBEST,yBEST,zBEST); HProb_DeepAK8->Fill(xDeepAK8,yDeepAK8,zDeepAK8); HProb_DeepAK8_decorr->Fill(xDeepAK8_decorr,yDeepAK8_decorr,zDeepAK8_decorr);}
	  // if(match == 3) {ZProb_BEST->Fill(xBEST,yBEST,zBEST); ZProb_DeepAK8->Fill(xDeepAK8,yDeepAK8,zDeepAK8); ZProb_DeepAK8_decorr->Fill(xDeepAK8_decorr,yDeepAK8_decorr,zDeepAK8_decorr);}
	  // if(match == 4) {WProb_BEST->Fill(xBEST,yBEST,zBEST); WProb_DeepAK8->Fill(xDeepAK8,yDeepAK8,zDeepAK8); WProb_DeepAK8_decorr->Fill(xDeepAK8_decorr,yDeepAK8_decorr,zDeepAK8_decorr);}
	  // if(match == 5) {bProb_BEST->Fill(xBEST,yBEST,zBEST); bProb_DeepAK8->Fill(xDeepAK8,yDeepAK8,zDeepAK8); bProb_DeepAK8_decorr->Fill(xDeepAK8_decorr,yDeepAK8_decorr,zDeepAK8_decorr);}

	  // if(match == 1) {tProb_DeepAK8_->Fill(xDeepAK8,yDeepAK8);}
	  // if(match == 2) {HProb_DeepAK8_->Fill(xDeepAK8,yDeepAK8);}
	  // if(match == 3) {ZProb_DeepAK8_->Fill(xDeepAK8,yDeepAK8);}
	  // if(match == 4) {WProb_DeepAK8_->Fill(xDeepAK8,yDeepAK8);}
	  // if(match == 5) {bProb_DeepAK8_->Fill(xDeepAK8,yDeepAK8);}
	}
      }

      // ----------------------------------------------------------------------------
      // 13TeV Top pT reweighting -- TTbarMassCalc top vectors are the wrong tops....
      // ----------------------------------------------------------------------------
      
      genTopPt = -999;
      genAntiTopPt = -999;
      topPtWeight13TeV = 1.0;
      
      if(isTT){
	int top1index = -1;
	int top2index = -1;
	for(unsigned int itop=0; itop < allTopsStatus_TTbarMassCalc->size(); itop++){
	  //	  std::cout << "Status: " << allTopsStatus_TTbarMassCalc->at(itop) << ", Pt: " << allTopsPt_TTbarMassCalc->at(itop) << std::endl;
	  if(allTopsStatus_TTbarMassCalc->at(itop) != 62) continue;
	  if(top1index < 0){
	    top1index = itop;
	    continue;
	  }
	  if(top2index < 0){
	    top2index = itop;
	    continue;
	  }
	}

	float SFtop1 = TMath::Exp(0.0615-0.0005*allTopsPt_TTbarMassCalc->at(top1index));
	float SFtop2 = TMath::Exp(0.0615-0.0005*allTopsPt_TTbarMassCalc->at(top2index));
	topPtWeight13TeV = TMath::Sqrt(SFtop1*SFtop2);

	if(allTopsID_TTbarMassCalc->at(top1index) == 6){
	  genTopPt = allTopsPt_TTbarMassCalc->at(top1index);
	  genAntiTopPt = allTopsPt_TTbarMassCalc->at(top2index);
	}
	else{
	  genAntiTopPt = allTopsPt_TTbarMassCalc->at(top1index);
	  genTopPt = allTopsPt_TTbarMassCalc->at(top2index);
	}
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
 
      TLorentzVector W_lv;
      W_lv = Wlv;
      W_mass = W_lv.M();


      // ----------------------------------------------------------------------------
      // T' decay
      // ----------------------------------------------------------------------------                                                                                                           
      float deltaR = 999;
      int bIndex = 999;
      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc_PtOrdered.size(); ijet++){
	TLorentzVector jet_lv;
	jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(ijet),theJetEta_JetSubCalc_PtOrdered.at(ijet),theJetPhi_JetSubCalc_PtOrdered.at(ijet),theJetEnergy_JetSubCalc_PtOrdered.at(ijet));
	float tempdr = jet_lv.DeltaR(W_lv);
	if(tempdr < deltaR) {deltaR = tempdr; bIndex = ijet;}
      }
      
      TLorentzVector top_lv;
      t_mass = -999;
      bool isLeptonic_W = false;
      bool isLeptonic_t = false;
      if(deltaR < .8/* and theJetBTag_JetSubCalc_PtOrdered.at(bIndex) == 1*/){
	TLorentzVector bottom_lv;
	bottom_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(bIndex),theJetEta_JetSubCalc_PtOrdered.at(bIndex),theJetPhi_JetSubCalc_PtOrdered.at(bIndex),theJetEnergy_JetSubCalc_PtOrdered.at(bIndex));
	top_lv = bottom_lv + W_lv;
	t_mass = top_lv.M();
	isLeptonic_t = true;
      } else {
	isLeptonic_W = true;
      }

      // Fill the vector for deltaR from leptonic particle (W or t) from all AK8 Jets
      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc_PtOrdered.size(); ijet++){
	TLorentzVector jet_lv;
	jet_lv.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),theJetAK8Energy_JetSubCalc_PtOrdered.at(ijet));
	if(isLeptonic_W) deltaR_leptonicparticle_AK8_PtOrdered.push_back(jet_lv.DeltaR(W_lv));
	if(isLeptonic_t) deltaR_leptonicparticle_AK8_PtOrdered.push_back(jet_lv.DeltaR(top_lv));
      }

      // Get 3 high-pT jets that are not close to t/W (deltaR > .8)
      std::vector<pair<TLorentzVector,int>> jets_lv;
      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc_PtOrdered.size(); ijet++){      
	if(jets_lv.size() > 3) continue;

	TLorentzVector jet;
	jet.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),theJetAK8Energy_JetSubCalc_PtOrdered.at(ijet));
	if(jet.DeltaR(top_lv) > .8 and isLeptonic_t) jets_lv.push_back(std::make_pair(jet,ijet));
	if(jet.DeltaR(W_lv) > .8 and isLeptonic_W) jets_lv.push_back(std::make_pair(jet,ijet));
      }

      highPtAK8Jet1_SoftDropCorrectedMass = -999;
      highPtAK8Jet2_SoftDropCorrectedMass = -999;
      highPtAK8Jet3_SoftDropCorrectedMass = -999;

      leptonicTprimeJetIDs_BEST.clear();
      leptonicTprimeJetIDs_DeepAK8.clear();
      leptonicTprimeJetIDs_DeepAK8_decorr.clear();
      hadronicTprimeJetIDs_BEST.clear();
      hadronicTprimeJetIDs_DeepAK8.clear();
      hadronicTprimeJetIDs_DeepAK8_decorr.clear();
	
      Tprime1_BEST_Mass = -999;
      Tprime2_BEST_Mass = -999;
      Tprime1_BEST_Pt = -999;
      Tprime2_BEST_Pt = -999;
      Tprime1_BEST_Eta = -999;
      Tprime2_BEST_Eta = -999;
      Tprime1_BEST_Phi = -999;
      Tprime2_BEST_Phi = -999;
      Tprime1_BEST_deltaR = -999;
      Tprime2_BEST_deltaR = -999;
      TprimeAvg_BEST_Mass = -999;
      
      Tprime1_DeepAK8_Mass = -999;
      Tprime2_DeepAK8_Mass = -999;
      Tprime1_DeepAK8_Pt = -999;
      Tprime2_DeepAK8_Pt = -999;
      Tprime1_DeepAK8_Eta = -999;
      Tprime2_DeepAK8_Eta = -999;
      Tprime1_DeepAK8_Phi = -999;
      Tprime2_DeepAK8_Phi = -999;
      Tprime1_DeepAK8_deltaR = -999;
      Tprime2_DeepAK8_deltaR = -999;
      TprimeAvg_DeepAK8_Mass = -999;
      
      Tprime1_DeepAK8_decorr_Mass = -999;
      Tprime2_DeepAK8_decorr_Mass = -999;
      Tprime1_DeepAK8_decorr_Pt = -999;
      Tprime2_DeepAK8_decorr_Pt = -999;
      Tprime1_DeepAK8_decorr_Eta = -999;
      Tprime2_DeepAK8_decorr_Eta = -999;
      Tprime1_DeepAK8_decorr_Phi = -999;
      Tprime2_DeepAK8_decorr_Phi = -999;
      Tprime1_DeepAK8_decorr_deltaR = -999;
      Tprime2_DeepAK8_decorr_deltaR = -999;
      TprimeAvg_DeepAK8_decorr_Mass = -999;

      taggedBWBW_BEST = false;
      taggedTHBW_BEST = false;
      taggedTHTH_BEST = false;
      taggedTZBW_BEST = false;
      taggedTZTH_BEST = false;
      taggedTZTZ_BEST = false;
      taggedBWBW_DeepAK8 = false;
      taggedTHBW_DeepAK8 = false;
      taggedTHTH_DeepAK8 = false;
      taggedTZBW_DeepAK8 = false;
      taggedTZTH_DeepAK8 = false;
      taggedTZTZ_DeepAK8 = false;
      taggedBWBW_DeepAK8_decorr = false;
      taggedTHBW_DeepAK8_decorr = false;
      taggedTHTH_DeepAK8_decorr = false;
      taggedTZBW_DeepAK8_decorr = false;
      taggedTZTH_DeepAK8_decorr = false;
      taggedTZTZ_DeepAK8_decorr = false;

      validDecay_BEST = false;
      validDecay_DeepAK8 = false;
      validDecay_DeepAK8_decorr = false;

      probSum_BEST_decay = -999;
      probSum_DeepAK8_decay = -999;
      probSum_DeepAK8_decorr_decay = -999;
      probSum_BEST_four = -999;
      probSum_DeepAK8_four = -999;
      probSum_DeepAK8_decorr_four = -999;

      if(jets_lv.size() == 3){
	probSum_BEST_decay = 0;
	probSum_DeepAK8_decay = 0;
	probSum_DeepAK8_decorr_decay = 0;
	probSum_BEST_four = 0;
	probSum_DeepAK8_four = 0;
	probSum_DeepAK8_decorr_four = 0;
        for (unsigned int i = 0; i < jets_lv.size(); i++) {
          probSum_BEST_decay += dnn_B_BestCalc_PtOrdered.at(jets_lv.at(i).second) + 2*dnn_W_BestCalc_PtOrdered.at(jets_lv.at(0).second) + 3*dnn_Top_BestCalc_PtOrdered.at(jets_lv.at(0).second) + 4*dnn_Z_BestCalc_PtOrdered.at(jets_lv.at(0).second) + 5*dnn_Higgs_BestCalc_PtOrdered.at(jets_lv.at(0).second);
          probSum_DeepAK8_decay += dnn_B_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second) + 2*dnn_W_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second) + 3*dnn_T_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second) + 4*dnn_Z_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second) + 5*dnn_H_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second);
          probSum_DeepAK8_decorr_decay += decorr_B_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second) + 2*decorr_W_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second) + 3*decorr_T_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second) + 4*decorr_Z_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second) + 5*decorr_H_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second);
          probSum_BEST_four += dnn_W_BestCalc_PtOrdered.at(jets_lv.at(0).second) + dnn_Top_BestCalc_PtOrdered.at(jets_lv.at(0).second) + dnn_Z_BestCalc_PtOrdered.at(jets_lv.at(0).second) + dnn_Higgs_BestCalc_PtOrdered.at(jets_lv.at(0).second);
          probSum_DeepAK8_four += dnn_W_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second) + dnn_T_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second) + dnn_Z_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second) + dnn_H_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second);
          probSum_DeepAK8_decorr_four += decorr_W_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second) + decorr_T_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second) + decorr_Z_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second) + decorr_H_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second);
	}

	npass_ThreeJets = npass_ThreeJets + 1;
	
	if(isLeptonic_W) {leptonicTprimeJetIDs_BEST = {4,5}; leptonicTprimeJetIDs_DeepAK8 = {4,5}; leptonicTprimeJetIDs_DeepAK8_decorr = {4,5};}
	if(isLeptonic_t) {leptonicTprimeJetIDs_BEST.push_back(1); leptonicTprimeJetIDs_DeepAK8.push_back(1); leptonicTprimeJetIDs_DeepAK8_decorr.push_back(1);}

	highPtAK8Jet1_SoftDropCorrectedMass = theJetAK8SoftDropCorr_PtOrdered.at(jets_lv.at(0).second);
	highPtAK8Jet2_SoftDropCorrectedMass = theJetAK8SoftDropCorr_PtOrdered.at(jets_lv.at(1).second);
	highPtAK8Jet3_SoftDropCorrectedMass = theJetAK8SoftDropCorr_PtOrdered.at(jets_lv.at(2).second);

	//BEST SECTION
	int jet1_BEST = dnn_largest_BestCalc_PtOrdered.at(jets_lv.at(0).second);
	int jet2_BEST = dnn_largest_BestCalc_PtOrdered.at(jets_lv.at(1).second);
	int jet3_BEST = dnn_largest_BestCalc_PtOrdered.at(jets_lv.at(2).second);
	std::vector <pair<int,int>> decayJets_BEST;
	decayJets_BEST.push_back(std::make_pair(jet1_BEST,0));
	decayJets_BEST.push_back(std::make_pair(jet2_BEST,1));
	decayJets_BEST.push_back(std::make_pair(jet3_BEST,2));
	std::sort(decayJets_BEST.begin(),decayJets_BEST.end());
	if(isLeptonic_t) {taggedXXXX_BEST={1,decayJets_BEST.at(0).first,decayJets_BEST.at(1).first,decayJets_BEST.at(2).first};}
	if(isLeptonic_W) {taggedXXXX_BEST={4,decayJets_BEST.at(0).first,decayJets_BEST.at(1).first,decayJets_BEST.at(2).first};}
	std::sort(taggedXXXX_BEST.begin(),taggedXXXX_BEST.end());
	TLorentzVector Tprime1_BEST_lv;
	TLorentzVector Tprime2_BEST_lv;
	// Start t --> b W decays
	validDecay_BEST = false;
	if(isLeptonic_t and decayJets_BEST.at(0).first==2 && decayJets_BEST.at(1).first==4 && decayJets_BEST.at(2).first==5){ // TTbar --> tH and bW
	  validDecay_BEST = true;
	  taggedTHBW_BEST = true;
	  leptonicTprimeJetIDs_BEST.push_back(2);
	  hadronicTprimeJetIDs_BEST = {4,5};
	  Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(0).second).first;
	  Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(1).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	  Tprime1_BEST_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_BEST.at(0).second).first);
	  Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(1).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	}
	if(isLeptonic_t and decayJets_BEST.at(0).first==1 && decayJets_BEST.at(1).first==2 && decayJets_BEST.at(2).first==2){ // TTbar --> tH and tH
	  validDecay_BEST = true;
	  taggedTHTH_BEST = true;
	  leptonicTprimeJetIDs_BEST.push_back(2);
	  hadronicTprimeJetIDs_BEST = {1,2};
	  float massDiff1=(top_lv+jets_lv.at(decayJets_BEST.at(1).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first).M();
	  float massDiff2=(top_lv+jets_lv.at(decayJets_BEST.at(2).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first).M();
	  if(massDiff1 < massDiff2) {
	    Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(1).second).first; 
	    Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	    Tprime1_BEST_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_BEST.at(1).second).first);
	    Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(0).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	  } else {
	    Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(2).second).first;
	    Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first;
	    Tprime1_BEST_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	    Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(1).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(0).second).first);
	  }
	}
	if(isLeptonic_t and decayJets_BEST.at(0).first==1 && decayJets_BEST.at(1).first==2 && decayJets_BEST.at(2).first==3){ // TTbar --> tH and tZ
	  validDecay_BEST = true;
	  taggedTZTH_BEST = true;
	  float massDiff1=(top_lv+jets_lv.at(decayJets_BEST.at(1).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first).M();
	  float massDiff2=(top_lv+jets_lv.at(decayJets_BEST.at(2).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first).M();
	  if(massDiff1 < massDiff2) {
	    leptonicTprimeJetIDs_BEST.push_back(2);
	    hadronicTprimeJetIDs_BEST = {1,2};
	    Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(1).second).first; 
	    Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	    Tprime1_BEST_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_BEST.at(1).second).first);
	    Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(0).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	  } else {
	    leptonicTprimeJetIDs_BEST.push_back(3);
	    hadronicTprimeJetIDs_BEST = {1,2};
	    Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(2).second).first;
	    Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first;
	    Tprime1_BEST_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	    Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(1).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(0).second).first);
	  }
	}
	if(isLeptonic_t and decayJets_BEST.at(0).first==3 && decayJets_BEST.at(1).first==4 && decayJets_BEST.at(2).first==5){ // TTbar --> tZ and bW
	  validDecay_BEST = true;
	  taggedTZBW_BEST = true;
	  leptonicTprimeJetIDs_BEST.push_back(3);
	  hadronicTprimeJetIDs_BEST = {4,5};
	  Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(0).second).first;
	  Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(1).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	  Tprime1_BEST_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_BEST.at(0).second).first);
	  Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(1).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	}
	if(isLeptonic_t and decayJets_BEST.at(0).first==1 && decayJets_BEST.at(1).first==3 && decayJets_BEST.at(2).first==3){ // TTbar --> tZ tZ
	  validDecay_BEST = true;
	  taggedTZTZ_BEST = true;
	  leptonicTprimeJetIDs_BEST.push_back(3);
	  hadronicTprimeJetIDs_BEST = {1,3};
	  float massDiff1=(top_lv+jets_lv.at(decayJets_BEST.at(1).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first).M();
	  float massDiff2=(top_lv+jets_lv.at(decayJets_BEST.at(2).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first).M();
	  if(massDiff1 < massDiff2) {
	    Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(1).second).first; 
	    Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	    Tprime1_BEST_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_BEST.at(1).second).first);
	    Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(0).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	  } else {
	    Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(2).second).first;
	    Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first;
	    Tprime1_BEST_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	    Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(1).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(0).second).first);
	  } 
	  // Start T' --> b W decays
	}
	if(isLeptonic_W and decayJets_BEST.at(0).first==4 && decayJets_BEST.at(1).first==5 && decayJets_BEST.at(2).first==5){
	  validDecay_BEST = true;
	  taggedBWBW_BEST = true;
	  hadronicTprimeJetIDs_BEST = {4,5};
	  float massDiff1=(W_lv+jets_lv.at(decayJets_BEST.at(1).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first).M();
	  float massDiff2=(W_lv+jets_lv.at(decayJets_BEST.at(2).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first).M();
	  if(massDiff1 < massDiff2) {
	    Tprime1_BEST_lv = W_lv+jets_lv.at(decayJets_BEST.at(1).second).first;
	    Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	    Tprime1_BEST_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_BEST.at(1).second).first);
	    Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(0).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	  } else {
	    Tprime1_BEST_lv = W_lv+jets_lv.at(decayJets_BEST.at(2).second).first;
	    Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first;
	    Tprime1_BEST_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	    Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(0).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(1).second).first);
	  }
	}
	if(isLeptonic_W and decayJets_BEST.at(0).first==1 && decayJets_BEST.at(1).first==3 && decayJets_BEST.at(2).first==5){
	  validDecay_BEST = true;
	  taggedTZBW_BEST = true;
	  hadronicTprimeJetIDs_BEST = {1,3};
	  Tprime1_BEST_lv = W_lv+jets_lv.at(decayJets_BEST.at(2).second).first;
	  Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first;
	  Tprime1_BEST_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	  Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(0).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(1).second).first);
	}
	if(isLeptonic_W and decayJets_BEST.at(0).first==1 && decayJets_BEST.at(1).first==2 && decayJets_BEST.at(2).first==5){
	  validDecay_BEST = true;	    
	  taggedTHBW_BEST = true;
	  hadronicTprimeJetIDs_BEST = {1,2};
	  Tprime1_BEST_lv = W_lv+jets_lv.at(decayJets_BEST.at(2).second).first;
	  Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first;
	  Tprime1_BEST_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	  Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(0).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(1).second).first);
	}
	if(!validDecay_BEST) {
	  if(isLeptonic_t){
	    float massDiff1=(top_lv+jets_lv.at(decayJets_BEST.at(0).second).first).M()-(jets_lv.at(decayJets_BEST.at(1).second).first+jets_lv.at(decayJets_BEST.at(2).second).first).M();
	    float massDiff2=(top_lv+jets_lv.at(decayJets_BEST.at(1).second).first).M()-(jets_lv.at(decayJets_BEST.at(2).second).first+jets_lv.at(decayJets_BEST.at(0).second).first).M();
	    float massDiff3=(top_lv+jets_lv.at(decayJets_BEST.at(2).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first).M();
	    if(massDiff1 < massDiff2 and massDiff1 < massDiff3){
	      leptonicTprimeJetIDs_BEST.push_back(decayJets_BEST.at(0).first);
	      hadronicTprimeJetIDs_BEST = {decayJets_BEST.at(1).first, decayJets_BEST.at(2).first};
	      Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(0).second).first;
	      Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(1).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	      Tprime1_BEST_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_BEST.at(0).second).first);
	      Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(1).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	    } else if(massDiff2 < massDiff1 and massDiff2 < massDiff3){
	      leptonicTprimeJetIDs_BEST.push_back(decayJets_BEST.at(1).first);
	      hadronicTprimeJetIDs_BEST = {decayJets_BEST.at(0).first, decayJets_BEST.at(2).first};
	      Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(1).second).first;
	      Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	      Tprime1_BEST_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_BEST.at(1).second).first);
	      Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(0).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	    } else {
	      leptonicTprimeJetIDs_BEST.push_back(decayJets_BEST.at(2).first);
	      hadronicTprimeJetIDs_BEST = {decayJets_BEST.at(0).first, decayJets_BEST.at(1).first};
	      Tprime1_BEST_lv = top_lv+jets_lv.at(decayJets_BEST.at(2).second).first;
	      Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first;
	      Tprime1_BEST_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	      Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(1).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(0).second).first);
	    }
	  }
	  if(isLeptonic_W){
	    float massDiff1=(W_lv+jets_lv.at(decayJets_BEST.at(0).second).first).M()-(jets_lv.at(decayJets_BEST.at(1).second).first+jets_lv.at(decayJets_BEST.at(2).second).first).M();
	    float massDiff2=(W_lv+jets_lv.at(decayJets_BEST.at(1).second).first).M()-(jets_lv.at(decayJets_BEST.at(2).second).first+jets_lv.at(decayJets_BEST.at(0).second).first).M();
	    float massDiff3=(W_lv+jets_lv.at(decayJets_BEST.at(2).second).first).M()-(jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first).M();
	    if(massDiff1 < massDiff2 and massDiff1 < massDiff3){
	      hadronicTprimeJetIDs_BEST = {decayJets_BEST.at(1).first, decayJets_BEST.at(2).first};
	      Tprime1_BEST_lv = W_lv+jets_lv.at(decayJets_BEST.at(0).second).first;
	      Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(1).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	      Tprime1_BEST_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_BEST.at(0).second).first);
	      Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(1).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	    } else if(massDiff2 < massDiff1 and massDiff2 < massDiff3){
	      hadronicTprimeJetIDs_BEST = {decayJets_BEST.at(0).first, decayJets_BEST.at(2).first};
	      Tprime1_BEST_lv = W_lv+jets_lv.at(decayJets_BEST.at(1).second).first;
	      Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(2).second).first;
	      Tprime1_BEST_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_BEST.at(1).second).first);
	      Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(0).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	    } else {
	      hadronicTprimeJetIDs_BEST = {decayJets_BEST.at(0).first, decayJets_BEST.at(1).first};
	      Tprime1_BEST_lv = W_lv+jets_lv.at(decayJets_BEST.at(2).second).first;
	      Tprime2_BEST_lv = jets_lv.at(decayJets_BEST.at(0).second).first+jets_lv.at(decayJets_BEST.at(1).second).first;
	      Tprime1_BEST_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	      Tprime2_BEST_deltaR = jets_lv.at(decayJets_BEST.at(0).second).first.DeltaR(jets_lv.at(decayJets_BEST.at(2).second).first);
	    }
	  }
	}

	if(Tprime1_BEST_lv.M() != -999){
	  Tprime1_BEST_Mass = Tprime1_BEST_lv.M();
	  Tprime2_BEST_Mass = Tprime2_BEST_lv.M();
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
	
	if(jet1_DeepAK8 == 0 || jet1_DeepAK8== 5){
	  if(theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.at(jets_lv.at(0).second) > 0){
	    jet1_DeepAK8 = 5;
	  } else {
	    jet1_DeepAK8 = 0;
	  }
	}
	if(jet2_DeepAK8 == 0 || jet2_DeepAK8== 5){
	  if(theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.at(jets_lv.at(1).second) > 0){
	    jet2_DeepAK8 = 5;
	  } else {
	    jet2_DeepAK8 = 0;
	  }
	}
	if(jet3_DeepAK8 == 0 || jet3_DeepAK8== 5){
	  if(theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.at(jets_lv.at(2).second) > 0){
	    jet3_DeepAK8 = 5;
	  } else {
	    jet3_DeepAK8 = 0;
	  }
	}

	std::vector <pair<int,int>> decayJets_DeepAK8;
	decayJets_DeepAK8.push_back(std::make_pair(jet1_DeepAK8,0));
	decayJets_DeepAK8.push_back(std::make_pair(jet2_DeepAK8,1));
	decayJets_DeepAK8.push_back(std::make_pair(jet3_DeepAK8,2));
	std::sort(decayJets_DeepAK8.begin(),decayJets_DeepAK8.end());
	if(isLeptonic_t) {taggedXXXX_DeepAK8={1,decayJets_DeepAK8.at(0).first,decayJets_DeepAK8.at(1).first,decayJets_DeepAK8.at(2).first};}
	if(isLeptonic_W) {taggedXXXX_DeepAK8={4,decayJets_DeepAK8.at(0).first,decayJets_DeepAK8.at(1).first,decayJets_DeepAK8.at(2).first};}
	std::sort(taggedXXXX_DeepAK8.begin(),taggedXXXX_DeepAK8.end());
	TLorentzVector Tprime1_DeepAK8_lv;
	TLorentzVector Tprime2_DeepAK8_lv;
	// Start t --> b W decays
	validDecay_DeepAK8 = false;
	if(isLeptonic_t and decayJets_DeepAK8.at(0).first==2 && decayJets_DeepAK8.at(1).first==4 && decayJets_DeepAK8.at(2).first==5){ // TTbar --> tH and bW
	  validDecay_DeepAK8 = true;
	  taggedTHBW_DeepAK8 = true;
	  leptonicTprimeJetIDs_DeepAK8.push_back(2);
	  hadronicTprimeJetIDs_DeepAK8 = {4,5};
	  Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	  Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	  Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	  Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	}
	if(isLeptonic_t and decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==2 && decayJets_DeepAK8.at(2).first==2){ // TTbar --> tH and tH
	  validDecay_DeepAK8 = true;
	  taggedTHTH_DeepAK8 = true;
	  leptonicTprimeJetIDs_DeepAK8.push_back(2);
	  hadronicTprimeJetIDs_DeepAK8 = {1,2};
	  float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();
	  float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M();
	  if(massDiff1 < massDiff2) {
	    Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; 
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	    Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	  } else {
	    Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	    Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	  }
	}
	if(isLeptonic_t and decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==2 && decayJets_DeepAK8.at(2).first==3){ // TTbar --> tH and tZ
	  validDecay_DeepAK8 = true;
	  taggedTZTH_DeepAK8 = true;
	  float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();
	  float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M();
	  if(massDiff1 < massDiff2) {
	    leptonicTprimeJetIDs_DeepAK8.push_back(2);
	    hadronicTprimeJetIDs_DeepAK8 = {1,3};
	    Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; 
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	    Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	  } else {
	    leptonicTprimeJetIDs_DeepAK8.push_back(3);
	    hadronicTprimeJetIDs_DeepAK8 = {1,2};
	    Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	    Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	  }
	}
	if(isLeptonic_t and decayJets_DeepAK8.at(0).first==3 && decayJets_DeepAK8.at(1).first==4 && decayJets_DeepAK8.at(2).first==5){ // TTbar --> tZ and bW
	  validDecay_DeepAK8 = true;
	  taggedTZBW_DeepAK8 = true;
	  leptonicTprimeJetIDs_DeepAK8.push_back(3);
	  hadronicTprimeJetIDs_DeepAK8 = {4,5};
	  Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	  Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	  Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	  Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	}
	if(isLeptonic_t and decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==3 && decayJets_DeepAK8.at(2).first==3){ // TTbar --> tZ tZ
	  validDecay_DeepAK8 = true;
	  taggedTZTZ_DeepAK8 = true;
	  leptonicTprimeJetIDs_DeepAK8.push_back(3);
	  hadronicTprimeJetIDs_DeepAK8 = {1,3};
	  float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();
	  float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M();
	  if(massDiff1 < massDiff2) {
	    Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; 
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	    Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	  } else {
	    Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	    Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	  }
	}
	// Start T' --> b W decays
	if(isLeptonic_W and decayJets_DeepAK8.at(0).first==4 && decayJets_DeepAK8.at(1).first==5 && decayJets_DeepAK8.at(2).first==5){
	  validDecay_DeepAK8 = true;
	  taggedBWBW_DeepAK8 = true;
	  hadronicTprimeJetIDs_DeepAK8 = {4,5};
	  float massDiff1=(W_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();
	  float massDiff2=(W_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M();
	  if(massDiff1 < massDiff2) {
	    Tprime1_DeepAK8_lv = W_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime1_DeepAK8_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	    Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	  } else {
	    Tprime1_DeepAK8_lv = W_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	    Tprime1_DeepAK8_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	  }
	}
	if(isLeptonic_W and decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==3 && decayJets_DeepAK8.at(2).first==5){
	  validDecay_DeepAK8 = true;
	  taggedTZBW_DeepAK8 = true;
	  hadronicTprimeJetIDs_DeepAK8 = {1,3};
	  Tprime1_DeepAK8_lv = W_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	  Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	  Tprime1_DeepAK8_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	  Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	}
	if(isLeptonic_W and decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==2 && decayJets_DeepAK8.at(2).first==5){
	  validDecay_DeepAK8 = true;
	  taggedTHBW_DeepAK8 = true;
	  hadronicTprimeJetIDs_DeepAK8 = {1,2};
	  Tprime1_DeepAK8_lv = W_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	  Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	  Tprime1_DeepAK8_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	  Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	}
	if(!validDecay_DeepAK8) {
	  if(isLeptonic_t){
	    float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();
	    float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(2).second).first+jets_lv.at(decayJets_DeepAK8.at(0).second).first).M();
	    float massDiff3=(top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M();
	    if(massDiff1 < massDiff2 and massDiff1 < massDiff3){
	      leptonicTprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(0).first);
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(1).first, decayJets_DeepAK8.at(2).first};
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else if(massDiff2 < massDiff1 and massDiff2 < massDiff3){
	      leptonicTprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(1).first);
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(2).first};
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else {
	      leptonicTprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(2).first);
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(1).first};
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    }
	  }
	  if(isLeptonic_W){
	    float massDiff1=(W_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();
	    float massDiff2=(W_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(2).second).first+jets_lv.at(decayJets_DeepAK8.at(0).second).first).M();
	    float massDiff3=(W_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M();
	    if(massDiff1 < massDiff2 and massDiff1 < massDiff3){
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(1).first, decayJets_DeepAK8.at(2).first};
	      Tprime1_DeepAK8_lv = W_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else if(massDiff2 < massDiff1 and massDiff2 < massDiff3){
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(2).first};
	      Tprime1_DeepAK8_lv = W_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else {
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(1).first};
	      Tprime1_DeepAK8_lv = W_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime1_DeepAK8_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    }
	  }
	}

	if(Tprime1_DeepAK8_lv.M() != -999){
	  Tprime1_DeepAK8_Mass = Tprime1_DeepAK8_lv.M();
	  Tprime2_DeepAK8_Mass = Tprime2_DeepAK8_lv.M();
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
	if(isLeptonic_t) {taggedXXXX_DeepAK8_decorr={1,decayJets_DeepAK8_decorr.at(0).first,decayJets_DeepAK8_decorr.at(1).first,decayJets_DeepAK8_decorr.at(2).first};}
	if(isLeptonic_W) {taggedXXXX_DeepAK8_decorr={4,decayJets_DeepAK8_decorr.at(0).first,decayJets_DeepAK8_decorr.at(1).first,decayJets_DeepAK8_decorr.at(2).first};}
	std::sort(taggedXXXX_DeepAK8_decorr.begin(),taggedXXXX_DeepAK8_decorr.end());
	TLorentzVector Tprime1_DeepAK8_decorr_lv;
	TLorentzVector Tprime2_DeepAK8_decorr_lv;
	// Start t --> b W decays
	validDecay_DeepAK8_decorr = false;
	if(isLeptonic_t and decayJets_DeepAK8_decorr.at(0).first==2 && decayJets_DeepAK8_decorr.at(1).first==4 && decayJets_DeepAK8_decorr.at(2).first==5){ // TTbar --> tH and bW
	  validDecay_DeepAK8_decorr = true;
	  taggedTHBW_DeepAK8_decorr = true;
	  leptonicTprimeJetIDs_DeepAK8_decorr.push_back(2);
	  hadronicTprimeJetIDs_DeepAK8_decorr = {4,5};
	  Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first;
	  Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	  Tprime1_DeepAK8_decorr_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first);
	  Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	}
	if(isLeptonic_t and decayJets_DeepAK8_decorr.at(0).first==1 && decayJets_DeepAK8_decorr.at(1).first==2 && decayJets_DeepAK8_decorr.at(2).first==2){ // TTbar --> tH and tH
	  validDecay_DeepAK8_decorr = true;
	  taggedTHTH_DeepAK8_decorr = true;
	  leptonicTprimeJetIDs_DeepAK8_decorr.push_back(2);
	  hadronicTprimeJetIDs_DeepAK8_decorr = {1,2};
	  float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M();
	  float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M();
	  if(massDiff1 < massDiff2) {
	    Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first; 
	    Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	    Tprime1_DeepAK8_decorr_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first);
	    Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	  } else {
	    Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	    Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	    Tprime1_DeepAK8_decorr_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	    Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first);
	  }
	}
	if(isLeptonic_t and decayJets_DeepAK8_decorr.at(0).first==1 && decayJets_DeepAK8_decorr.at(1).first==2 && decayJets_DeepAK8_decorr.at(2).first==3){ // TTbar --> tH and tZ
	  validDecay_DeepAK8_decorr = true;
	  taggedTZTH_DeepAK8_decorr = true;
	  float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M();
	  float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M();
	  if(massDiff1 < massDiff2) {
	    leptonicTprimeJetIDs_DeepAK8_decorr.push_back(2);
	    hadronicTprimeJetIDs_DeepAK8_decorr = {1,3};
	    Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first; 
	    Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	    Tprime1_DeepAK8_decorr_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first);
	    Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	  } else {
	    leptonicTprimeJetIDs_DeepAK8_decorr.push_back(3);
	    hadronicTprimeJetIDs_DeepAK8_decorr = {1,2};
	    Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	    Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	    Tprime1_DeepAK8_decorr_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	    Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first);
	  }
	}
	if(isLeptonic_t and decayJets_DeepAK8_decorr.at(0).first==3 && decayJets_DeepAK8_decorr.at(1).first==4 && decayJets_DeepAK8_decorr.at(2).first==5){ // TTbar --> tZ and bW
	  validDecay_DeepAK8_decorr = true;
	  taggedTZBW_DeepAK8_decorr = true;
	  leptonicTprimeJetIDs_DeepAK8_decorr.push_back(3);
	  hadronicTprimeJetIDs_DeepAK8_decorr = {4,5};
	  Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first;
	  Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	  Tprime1_DeepAK8_decorr_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first);
	  Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	}
	if(isLeptonic_t and decayJets_DeepAK8_decorr.at(0).first==1 && decayJets_DeepAK8_decorr.at(1).first==3 && decayJets_DeepAK8_decorr.at(2).first==3){ // TTbar --> tZ tZ
	  validDecay_DeepAK8_decorr = true;
	  taggedTZTZ_DeepAK8_decorr = true;
	  leptonicTprimeJetIDs_DeepAK8_decorr.push_back(3);
	  hadronicTprimeJetIDs_DeepAK8_decorr = {1,3};
	  float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M();
	  float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M();
	  if(massDiff1 < massDiff2) {
	    Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first; 
	    Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	    Tprime1_DeepAK8_decorr_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first);
	    Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	  } else {
	    Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	    Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	    Tprime1_DeepAK8_decorr_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	    Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first);
	  }
	}
	// Start T' --> b W decays	  
	if(isLeptonic_W and decayJets_DeepAK8_decorr.at(0).first==4 && decayJets_DeepAK8_decorr.at(1).first==5 && decayJets_DeepAK8_decorr.at(2).first==5){
	  validDecay_DeepAK8_decorr = true;
	  taggedBWBW_DeepAK8_decorr = true;
	  hadronicTprimeJetIDs_DeepAK8_decorr = {4,5};
	  float massDiff1=(W_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M();
	  float massDiff2=(W_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M();
	  if(massDiff1 < massDiff2) {
	    Tprime1_DeepAK8_decorr_lv = W_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	    Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	    Tprime1_DeepAK8_decorr_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first);
	    Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	  } else {
	    Tprime1_DeepAK8_decorr_lv = W_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	    Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	    Tprime1_DeepAK8_decorr_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	    Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first);
	  }
	}
	if(isLeptonic_W and decayJets_DeepAK8_decorr.at(0).first==1 && decayJets_DeepAK8_decorr.at(1).first==3 && decayJets_DeepAK8_decorr.at(2).first==5){
	  validDecay_DeepAK8_decorr = true;
	  taggedTZBW_DeepAK8_decorr = true;
	  hadronicTprimeJetIDs_DeepAK8_decorr = {1,3};
	  Tprime1_DeepAK8_decorr_lv = W_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	  Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	  Tprime1_DeepAK8_decorr_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	  Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first);
	}
	if(isLeptonic_W and decayJets_DeepAK8_decorr.at(0).first==1 && decayJets_DeepAK8_decorr.at(1).first==2 && decayJets_DeepAK8_decorr.at(2).first==5){
	  validDecay_DeepAK8_decorr = true;
	  taggedTHBW_DeepAK8_decorr = true;
	  hadronicTprimeJetIDs_DeepAK8_decorr = {1,2};
	  Tprime1_DeepAK8_decorr_lv = W_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	  Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	  Tprime1_DeepAK8_decorr_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	  Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first);
	}
	if(!validDecay_DeepAK8_decorr) {
	  if(isLeptonic_t){
	    float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M();
	    float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first).M();
	    float massDiff3=(top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M();
	    if(massDiff1 < massDiff2 and massDiff1 < massDiff3){
	      leptonicTprimeJetIDs_DeepAK8_decorr.push_back(decayJets_DeepAK8_decorr.at(0).first);
	      hadronicTprimeJetIDs_DeepAK8_decorr = {decayJets_DeepAK8_decorr.at(1).first, decayJets_DeepAK8_decorr.at(2).first};
	      Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first;
	      Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	      Tprime1_DeepAK8_decorr_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first);
	      Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	    } else if(massDiff2 < massDiff1 and massDiff2 < massDiff3){
	      leptonicTprimeJetIDs_DeepAK8_decorr.push_back(decayJets_DeepAK8_decorr.at(1).first);
	      hadronicTprimeJetIDs_DeepAK8_decorr = {decayJets_DeepAK8_decorr.at(0).first, decayJets_DeepAK8_decorr.at(2).first};
	      Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	      Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	      Tprime1_DeepAK8_decorr_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first);
	      Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	    } else {
	      leptonicTprimeJetIDs_DeepAK8_decorr.push_back(decayJets_DeepAK8_decorr.at(2).first);
	      hadronicTprimeJetIDs_DeepAK8_decorr = {decayJets_DeepAK8_decorr.at(0).first, decayJets_DeepAK8_decorr.at(1).first};
	      Tprime1_DeepAK8_decorr_lv = top_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	      Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	      Tprime1_DeepAK8_decorr_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	      Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first);
	    }
	  }
	  if(isLeptonic_W){
	    float massDiff1=(W_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M();
	    float massDiff2=(W_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first).M();
	    float massDiff3=(W_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first).M();
	    if(massDiff1 < massDiff2 and massDiff1 < massDiff3){
	      hadronicTprimeJetIDs_DeepAK8_decorr = {decayJets_DeepAK8_decorr.at(1).first, decayJets_DeepAK8_decorr.at(2).first};
	      Tprime1_DeepAK8_decorr_lv = W_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first;
	      Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	      Tprime1_DeepAK8_decorr_deltaR = W_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first);
	      Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	    } else if(massDiff2 < massDiff1 and massDiff2 < massDiff3){
	      hadronicTprimeJetIDs_DeepAK8_decorr = {decayJets_DeepAK8_decorr.at(0).first, decayJets_DeepAK8_decorr.at(2).first};
	      Tprime1_DeepAK8_decorr_lv = W_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	      Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	      Tprime1_DeepAK8_decorr_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first);
	      Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	    } else {
	      hadronicTprimeJetIDs_DeepAK8_decorr = {decayJets_DeepAK8_decorr.at(0).first, decayJets_DeepAK8_decorr.at(1).first};
	      Tprime1_DeepAK8_decorr_lv = W_lv+jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first;
	      Tprime2_DeepAK8_decorr_lv = jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first+jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first;
	      Tprime1_DeepAK8_decorr_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(2).second).first);
	      Tprime2_DeepAK8_decorr_deltaR = jets_lv.at(decayJets_DeepAK8_decorr.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8_decorr.at(0).second).first);
	    }
	  }
	}

	if(Tprime1_DeepAK8_decorr_lv.M() != -999){
	  Tprime1_DeepAK8_decorr_Mass = Tprime1_DeepAK8_decorr_lv.M();
	  Tprime2_DeepAK8_decorr_Mass = Tprime2_DeepAK8_decorr_lv.M();
	  Tprime1_DeepAK8_decorr_Pt = Tprime1_DeepAK8_decorr_lv.Pt();
	  Tprime2_DeepAK8_decorr_Pt = Tprime2_DeepAK8_decorr_lv.Pt();
	  Tprime1_DeepAK8_decorr_Eta = Tprime1_DeepAK8_decorr_lv.Eta();
	  Tprime2_DeepAK8_decorr_Eta = Tprime2_DeepAK8_decorr_lv.Eta();
	  Tprime1_DeepAK8_decorr_Phi = Tprime1_DeepAK8_decorr_lv.Phi();
	  Tprime2_DeepAK8_decorr_Phi = Tprime2_DeepAK8_decorr_lv.Phi();
	  TprimeAvg_DeepAK8_decorr_Mass =  (Tprime1_DeepAK8_decorr_lv.M()+Tprime2_DeepAK8_decorr_lv.M() ) / 2;
	}
	std::sort(leptonicTprimeJetIDs_BEST.begin(),leptonicTprimeJetIDs_BEST.end());
	std::sort(leptonicTprimeJetIDs_DeepAK8.begin(),leptonicTprimeJetIDs_DeepAK8.end());
	std::sort(leptonicTprimeJetIDs_DeepAK8_decorr.begin(),leptonicTprimeJetIDs_DeepAK8_decorr.end());
	std::sort(hadronicTprimeJetIDs_BEST.begin(),hadronicTprimeJetIDs_BEST.end());
	std::sort(hadronicTprimeJetIDs_DeepAK8.begin(),hadronicTprimeJetIDs_DeepAK8.end());
	std::sort(hadronicTprimeJetIDs_DeepAK8_decorr.begin(),hadronicTprimeJetIDs_DeepAK8_decorr.end());
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
      // PDF and Matrix Element energy scale weights
      // ----------------------------------------------------------------------------

      std::vector<double> renorm;
      std::vector<double> pdf;
      renormWeights.clear();
      pdfWeights.clear();
      if(isSig){
	// SEEMS TO APPLY TO ALL B2G MG+PYTHIA SIGNALS. LEADING ORDER 4-FLAVOR PDF
	for(unsigned int i = 0; i < LHEweightids_singleLepCalc->size(); i++){
	  if(LHEweightids_singleLepCalc->at(i) > 1 && LHEweightids_singleLepCalc->at(i) < 10){
	    if(LHEweightids_singleLepCalc->at(i) == 6 || LHEweightids_singleLepCalc->at(i) == 8) continue;
	    renorm.push_back(LHEweights_singleLepCalc->at(i));
	    renormWeights.push_back(LHEweights_singleLepCalc->at(i));
	  }
	  if(LHEweightids_singleLepCalc->at(i) > 111 && LHEweightids_singleLepCalc->at(i) < 212){
	    pdf.push_back(LHEweights_singleLepCalc->at(i));	    
	    pdfWeights.push_back(LHEweights_singleLepCalc->at(i));	    
	  }
	}
      }
      else if(isMadgraphBkg){
	// SEEMS TO APPLY TO OTHER MG+PYTHIA BACKGROUNDS. LEADING ORDER 5-FLAVOR PDF
	for(unsigned int i = 0; i < LHEweightids_singleLepCalc->size(); i++){
	  if(LHEweightids_singleLepCalc->at(i) > 1 && LHEweightids_singleLepCalc->at(i) < 10){
	    if(LHEweightids_singleLepCalc->at(i) == 6 || LHEweightids_singleLepCalc->at(i) == 8) continue;
	    renorm.push_back(LHEweights_singleLepCalc->at(i));
	    renormWeights.push_back(LHEweights_singleLepCalc->at(i));
	  }
	  if(LHEweightids_singleLepCalc->at(i) > 10 && LHEweightids_singleLepCalc->at(i) < 111){
	    pdf.push_back(LHEweights_singleLepCalc->at(i));
	    pdfWeights.push_back(LHEweights_singleLepCalc->at(i));
	  }
	}
      }
      else{
	// SEEMS TO APPLY TO ALL POWHEG AND MC@NLO BACKGROUNDS. NLO PDFs
	for(unsigned int i = 0; i < LHEweightids_singleLepCalc->size(); i++){
	  if(LHEweightids_singleLepCalc->at(i) > 1001 && LHEweightids_singleLepCalc->at(i) < 1010){
	    if(LHEweightids_singleLepCalc->at(i) == 1006 || LHEweightids_singleLepCalc->at(i) == 1008) continue;
	    renorm.push_back(LHEweights_singleLepCalc->at(i));
	    renormWeights.push_back(LHEweights_singleLepCalc->at(i));
	  }
	  if(LHEweightids_singleLepCalc->at(i) > 2000 && LHEweightids_singleLepCalc->at(i) < 2101){
	    pdf.push_back(LHEweights_singleLepCalc->at(i));
	    pdfWeights.push_back(LHEweights_singleLepCalc->at(i));
	  }
	  if(LHEweightids_singleLepCalc->at(i) == 2101 || LHEweightids_singleLepCalc->at(i) == 2102){
	    alphaSWeights.push_back(LHEweights_singleLepCalc->at(i));
	  }
	}
      }

      if(renormWeights.size() == 0){
	if(isVV){
	  renormWeights.push_back(0.85);
	  renormWeights.push_back(1.15);
	  renormWeights.push_back(0.85);
	  renormWeights.push_back(0.85);
	  renormWeights.push_back(1.15);
	  renormWeights.push_back(1.15);
	}else if(isSTt || isSTtW){
	  renormWeights.push_back(0.84);
	  renormWeights.push_back(1.16);
	  renormWeights.push_back(0.84);
	  renormWeights.push_back(0.84);
	  renormWeights.push_back(1.16);
	  renormWeights.push_back(1.16);
	}else{
	  for(int irn = 0; irn < 6; irn++){
	    renormWeights.push_back(1.0);
	  }
	}
      }
      if(pdfWeights.size() == 0){
	for(int ipdf = 0; ipdf < 100; ipdf++){
	  pdfWeights.push_back(1.0);
	}
      }

      // ----------------------------------------------------------------------------
      // DONE!! Write the tree
      // ----------------------------------------------------------------------------
      
      outputTree->Fill();
   }
   std::cout<<"Nelectrons             = "<<Nelectrons<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_ElEta          = "<<npass_ElEta<<" / "<<nentries<<std::endl;
   std::cout<<"Nmuons                 = "<<Nmuons<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_MuEta          = "<<npass_MuEta<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_nAK8Jets       = "<<npass_nAK8jets<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_Trigger        = "<<npass_trigger<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_MET            = "<<npass_met<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_lepPt          = "<<npass_lepPt<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_HT             = "<<npass_ht<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_ALL            = "<<npass_all<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_ThreeJets      = "<<npass_ThreeJets<<" / "<<nentries<<std::endl;

   // jProb_BEST->Write();
   // tProb_BEST->Write();
   // HProb_BEST->Write();
   // WProb_BEST->Write();
   // ZProb_BEST->Write();
   // bProb_BEST->Write();
   // jProb_DeepAK8->Write();
   // tProb_DeepAK8->Write();
   // HProb_DeepAK8->Write();
   // WProb_DeepAK8->Write();
   // ZProb_DeepAK8->Write();
   // bProb_DeepAK8->Write();
   // jProb_DeepAK8_decorr->Write();
   // tProb_DeepAK8_decorr->Write();
   // HProb_DeepAK8_decorr->Write();
   // WProb_DeepAK8_decorr->Write();
   // ZProb_DeepAK8_decorr->Write();
   // bProb_DeepAK8_decorr->Write();

   // tProb_DeepAK8_->Write();
   // HProb_DeepAK8_->Write();
   // WProb_DeepAK8_->Write();
   // ZProb_DeepAK8_->Write();
   // bProb_DeepAK8_->Write();

   outputTree->Write();

}
