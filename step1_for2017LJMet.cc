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
  
   TH1I *negweights = (TH1I*)inputFile->Get("histos/nevents");
   TH2D *TTconfusionD = new TH2D("TTconfusionD",";tagged decay;true decay",10,0,10,6,0,6);
   TH2D *TTconfusionN = new TH2D("TTconfusionN",";tagged decay;true decay",10,0,10,6,0,6);
   TH2D *BBconfusionD = new TH2D("BBconfusionD",";tagged decay;true decay",7,0,7,6,0,6);
   TH2D *BBconfusionN = new TH2D("BBconfusionN",";tagged decay;true decay",7,0,7,6,0,6);

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
   inputTree->SetBranchStatus("NewPDFweights_singleLepCalc",1);
   inputTree->SetBranchStatus("HTfromHEPUEP_singleLepCalc",1);
   inputTree->SetBranchStatus("L1NonPrefiringProb_CommonCalc",1);
   inputTree->SetBranchStatus("L1NonPrefiringProbUp_CommonCalc",1);
   inputTree->SetBranchStatus("L1NonPrefiringProbDown_CommonCalc",1);

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
   
   //electrons
   inputTree->SetBranchStatus("elPt_singleLepCalc",1);
   inputTree->SetBranchStatus("elEta_singleLepCalc",1);
   inputTree->SetBranchStatus("elPhi_singleLepCalc",1);
   inputTree->SetBranchStatus("elEnergy_singleLepCalc",1);
   inputTree->SetBranchStatus("elMVAValue_singleLepCalc",1);
   inputTree->SetBranchStatus("elMiniIso_singleLepCalc",1);
   
   //muons
   inputTree->SetBranchStatus("muPt_singleLepCalc",1);
   inputTree->SetBranchStatus("muEta_singleLepCalc",1);
   inputTree->SetBranchStatus("muPhi_singleLepCalc",1);
   inputTree->SetBranchStatus("muEnergy_singleLepCalc",1);
   inputTree->SetBranchStatus("muMiniIso_singleLepCalc",1);

   //missing et
   inputTree->SetBranchStatus("corr_met_singleLepCalc",1);
   inputTree->SetBranchStatus("corr_met_phi_singleLepCalc",1);
   inputTree->SetBranchStatus("corr_metmod_singleLepCalc",1);
   inputTree->SetBranchStatus("corr_metmod_phi_singleLepCalc",1);

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

   //JetSubCalc
   inputTree->SetBranchStatus("theJetHFlav_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetPFlav_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetPt_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetEta_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetPhi_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetEnergy_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetDeepCSVb_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetDeepCSVbb_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8DoubleB_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_bSFup_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_bSFdn_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_lSFup_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_lSFdn_JetSubCalc",1);
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
   inputTree->SetBranchStatus("theJetAK8SDSubjetNDeepCSVL_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetHFlav_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetIndex_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetSize_JetSubCalc",1);

   //DeepAK8
   inputTree->SetBranchStatus("dnn_B_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_C_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_J_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_W_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_Z_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_H_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_largest_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_T_DeepAK8Calc",1);

   //JetSubCalc
   inputTree->SetBranchStatus("maxProb_JetSubCalc",1);

   //top
   inputTree->SetBranchStatus("ttbarMass_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topMass_TTbarMassCalc",1);

   inputTree->SetBranchStatus("allTopsEnergy_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsEta_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsPhi_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsPt_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsID_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsStatus_TTbarMassCalc",1);
   inputTree->SetBranchStatus("isTau_singleLepCalc",1);

   // ----------------------------------------------------------------------------
   // Create output tree and define branches
   // ----------------------------------------------------------------------------
   
   // OUTPUT FILE
   outputFile->cd();
   TTree *outputTree = new TTree("ljmet","ljmet");

   // Common things
   outputTree->Branch("event_CommonCalc",&event_CommonCalc,"event_CommonCalc/L");
   outputTree->Branch("run_CommonCalc",&run_CommonCalc,"run_CommonCalc/I");
   outputTree->Branch("lumi_CommonCalc",&lumi_CommonCalc,"lumi_CommonCalc/I");
   outputTree->Branch("nPV_singleLepCalc",&nPV_singleLepCalc,"nPV_singleLepCalc/I");
   outputTree->Branch("nTrueInteractions_singleLepCalc",&nTrueInteractions_singleLepCalc,"nTrueInteractions_singleLepCalc/I");
   outputTree->Branch("isElectron",&isElectron,"isElectron/I");
   outputTree->Branch("isMuon",&isMuon,"isMuon/I");
   outputTree->Branch("MCPastTrigger",&MCPastTrigger,"MCPastTrigger/I");
   outputTree->Branch("DataPastTrigger",&DataPastTrigger,"DataPastTrigger/I");
   outputTree->Branch("L1NonPrefiringProb_CommonCalc",&L1NonPrefiringProb_CommonCalc,"L1NonPrefiringProb_CommonCalc/D");
   outputTree->Branch("L1NonPrefiringProbUp_CommonCalc",&L1NonPrefiringProbUp_CommonCalc,"L1NonPrefiringProbUp_CommonCalc/D");
   outputTree->Branch("L1NonPrefiringProbDown_CommonCalc",&L1NonPrefiringProbDown_CommonCalc,"L1NonPrefiringProbDown_CommonCalc/D");

   // Tprime generator
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

   // weights
   outputTree->Branch("renormWeights",&renormWeights);
   outputTree->Branch("pdfWeights",&pdfWeights);
   outputTree->Branch("pdfNewWeights",&pdfNewWeights);
   outputTree->Branch("pdfNewNominalWeight",&pdfNewNominalWeight,"pdfNewNominalWeight/F");
   outputTree->Branch("pileupWeight",&pileupWeight,"pileupWeight/F");
   outputTree->Branch("pileupWeightUp",&pileupWeightUp,"pileupWeightUp/F");
   outputTree->Branch("pileupWeightDown",&pileupWeightDown,"pileupWeightDown/F");
   outputTree->Branch("HTSF_Pol",&HTSF_Pol,"HTSF_Pol/F");
   outputTree->Branch("HTSF_PolUp",&HTSF_PolUp,"HTSF_PolUp/F");
   outputTree->Branch("HTSF_PolDn",&HTSF_PolDn,"HTSF_PolDn/F");
   outputTree->Branch("topPtWeight13TeV",&topPtWeight13TeV,"topPtWeight13TeV/F");
   outputTree->Branch("EGammaGsfSF",&EGammaGsfSF,"EGammaGsfSF/F");
   outputTree->Branch("lepIdSF",&lepIdSF,"lepIdSF/F");

   // ttbar generator
   outputTree->Branch("ttbarMass_TTbarMassCalc",&ttbarMass_TTbarMassCalc,"ttbarMass_TTbarMassCalc/D");
   outputTree->Branch("genTopPt",&genTopPt,"genTopPt/F");
   outputTree->Branch("genAntiTopPt",&genAntiTopPt,"genAntiTopPt/F");

   // leptons
   outputTree->Branch("isTau_singleLepCalc",&isTau_singleLepCalc,"isTau_singleLepCalc/O");
   outputTree->Branch("corr_met_singleLepCalc",&corr_met_singleLepCalc,"corr_met_singleLepCalc/D");
   outputTree->Branch("corr_met_phi_singleLepCalc",&corr_met_phi_singleLepCalc,"corr_met_phi_singleLepCalc/D");
   outputTree->Branch("corr_metmod_singleLepCalc",&corr_metmod_singleLepCalc,"corr_metmod_singleLepCalc/D");
   outputTree->Branch("corr_metmod_phi_singleLepCalc",&corr_metmod_phi_singleLepCalc,"corr_metmod_phi_singleLepCalc/D");
   outputTree->Branch("leptonPt_singleLepCalc",&leptonPt_singleLepCalc,"leptonPt_singleLepCalc/F");
   outputTree->Branch("leptonEta_singleLepCalc",&leptonEta_singleLepCalc,"leptonEta_singleLepCalc/F");
   outputTree->Branch("leptonPhi_singleLepCalc",&leptonPhi_singleLepCalc,"leptonPhi_singleLepCalc/F");
   outputTree->Branch("leptonEnergy_singleLepCalc",&leptonEnergy_singleLepCalc,"leptonEnergy_singleLepCalc/F");
   outputTree->Branch("leptonMVAValue_singleLepCalc",&leptonMVAValue_singleLepCalc,"leptonMVAValue_singleLepCalc/F");
   outputTree->Branch("leptonMiniIso_singleLepCalc",&leptonMiniIso_singleLepCalc,"leptonMiniIso_singleLepCalc/F");
   outputTree->Branch("MT_lepMet",&MT_lepMet,"MT_lepMet/F");
   outputTree->Branch("MT_lepMetmod",&MT_lepMetmod,"MT_lepMetmod/F");
   outputTree->Branch("minDPhi_MetJet",&minDPhi_MetJet,"minDPhi_MetJet/F");

   // AK4
   outputTree->Branch("theJetPt_JetSubCalc_PtOrdered",&theJetPt_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetEta_JetSubCalc_PtOrdered",&theJetEta_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetPhi_JetSubCalc_PtOrdered",&theJetPhi_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetEnergy_JetSubCalc_PtOrdered",&theJetEnergy_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetDeepCSVb_JetSubCalc_PtOrdered",&theJetDeepCSVb_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetDeepCSVbb_JetSubCalc_PtOrdered",&theJetDeepCSVbb_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetHFlav_JetSubCalc_PtOrdered",&theJetHFlav_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetPFlav_JetSubCalc_PtOrdered",&theJetPFlav_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetBTag_JetSubCalc_PtOrdered",&theJetBTag_JetSubCalc_PtOrdered);
   outputTree->Branch("AK4HTpMETpLepPt",&AK4HTpMETpLepPt,"AK4HTpMETpLepPt/F");
   outputTree->Branch("AK4HT",&AK4HT,"AK4HT/F");
   outputTree->Branch("NJets_JetSubCalc",&NJets_JetSubCalc,"NJets_JetSubCalc/I");
   outputTree->Branch("NJetsCSV_JetSubCalc",&NJetsCSV_JetSubCalc,"NJetsCSV_JetSubCalc/I");
   outputTree->Branch("NJetsCSVwithSF_JetSubCalc",&NJetsCSVwithSF_JetSubCalc,"NJetsCSVwithSF_JetSubCalc/I");
   outputTree->Branch("deltaR_lepMinMlb",&deltaR_lepMinMlb,"deltaR_lepMinMlb/F");
   outputTree->Branch("deltaR_lepMinMlj",&deltaR_lepMinMlj,"deltaR_lepMinMlj/F");
   outputTree->Branch("minMleppBjet",&minMleppBjet,"minMleppBjet/F");
   outputTree->Branch("minMleppJet",&minMleppJet,"mixnMleppJet/F");
   outputTree->Branch("minDR_lepJet",&minDR_lepJet,"minDR_lepJet/F");
   outputTree->Branch("ptRel_lepJet",&ptRel_lepJet,"ptRel_lepJet/F");
   outputTree->Branch("deltaR_lepJets",&deltaR_lepJets);
   outputTree->Branch("deltaR_lepBJets",&deltaR_lepBJets);

   // jet truth
   outputTree->Branch("HadronicVHtID_JetSubCalc",&HadronicVHtID_JetSubCalc);
   outputTree->Branch("HadronicVHtPt_JetSubCalc",&HadronicVHtPt_JetSubCalc);
   outputTree->Branch("HadronicVHtEta_JetSubCalc",&HadronicVHtEta_JetSubCalc);
   outputTree->Branch("HadronicVHtPhi_JetSubCalc",&HadronicVHtPhi_JetSubCalc);
   outputTree->Branch("HadronicVHtEnergy_JetSubCalc",&HadronicVHtEnergy_JetSubCalc);
   outputTree->Branch("theJetAK8Wmatch_JetSubCalc_PtOrdered",&theJetAK8Wmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Tmatch_JetSubCalc_PtOrdered",&theJetAK8Tmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Zmatch_JetSubCalc_PtOrdered",&theJetAK8Zmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Hmatch_JetSubCalc_PtOrdered",&theJetAK8Hmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8MatchedPt_JetSubCalc_PtOrdered",&theJetAK8MatchedPt_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Truth_JetSubCalc_PtOrdered",&theJetAK8Truth_JetSubCalc_PtOrdered);

   // AK8
   outputTree->Branch("NJetsAK8_JetSubCalc",&NJetsAK8_JetSubCalc,"NJetsAK8_JetSubCalc/I");
   outputTree->Branch("theJetAK8Pt_JetSubCalc_PtOrdered",&theJetAK8Pt_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Eta_JetSubCalc_PtOrdered",&theJetAK8Eta_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Phi_JetSubCalc_PtOrdered",&theJetAK8Phi_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Mass_JetSubCalc_PtOrdered",&theJetAK8Mass_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Energy_JetSubCalc_PtOrdered",&theJetAK8Energy_JetSubCalc_PtOrdered);
   outputTree->Branch("minDR_leadAK8otherAK8",&minDR_leadAK8otherAK8,"minDR_leadAK8otherAK8/F");
   outputTree->Branch("minDR_lepAK8",&minDR_lepAK8,"minDR_lepAK8/F");
   outputTree->Branch("ptRel_lepAK8",&ptRel_lepAK8,"ptRel_lepAK8/F");
   outputTree->Branch("deltaR_lepAK8s",&deltaR_lepAK8s);

   // mass + sub tagging 
   outputTree->Branch("maxProb_JetSubCalc_PtOrdered",&maxProb_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered",&theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered",&theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SoftDropRaw_JetSubCalc_PtOrdered",&theJetAK8SoftDropRaw_PtOrdered);
   outputTree->Branch("theJetAK8SoftDropCorr_JetSubCalc_PtOrdered",&theJetAK8SoftDropCorr_PtOrdered);
   outputTree->Branch("theJetAK8DoubleB_JetSubCalc_PtOrdered",&theJetAK8DoubleB_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SoftDrop_PtOrdered",&theJetAK8SoftDrop_PtOrdered);
   outputTree->Branch("theJetAK8NjettinessTau1_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau1_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8NjettinessTau2_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau2_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8NjettinessTau3_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau3_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSTau1_JetSubCalc_PtOrdered",&theJetAK8CHSTau1_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSTau2_JetSubCalc_PtOrdered",&theJetAK8CHSTau2_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSTau3_JetSubCalc_PtOrdered",&theJetAK8CHSTau3_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered",&theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SDSubjetSize_JetSubCalc_PtOrdered",&theJetAK8SDSubjetSize_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered",&theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered",&theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered);

   // DeepAK8 tagging
   outputTree->Branch("dnn_largest_DeepAK8Calc_PtOrdered",&dnn_largest_DeepAK8Calc_PtOrdered);
   outputTree->Branch("dnn_B_DeepAK8Calc_PtOrdered",&dnn_B_DeepAK8Calc_PtOrdered);
   outputTree->Branch("dnn_J_DeepAK8Calc_PtOrdered",&dnn_J_DeepAK8Calc_PtOrdered);
   outputTree->Branch("dnn_W_DeepAK8Calc_PtOrdered",&dnn_W_DeepAK8Calc_PtOrdered);
   outputTree->Branch("dnn_Z_DeepAK8Calc_PtOrdered",&dnn_Z_DeepAK8Calc_PtOrdered);
   outputTree->Branch("dnn_H_DeepAK8Calc_PtOrdered",&dnn_H_DeepAK8Calc_PtOrdered);
   outputTree->Branch("dnn_T_DeepAK8Calc_PtOrdered",&dnn_T_DeepAK8Calc_PtOrdered);
   outputTree->Branch("probSum_DeepAK8_decay",&probSum_DeepAK8_decay,"probSum_DeepAK8_decay/F");
   outputTree->Branch("probSum_DeepAK8_all",&probSum_DeepAK8_all,"probSum_DeepAK8_all/F");
   outputTree->Branch("probSum_DeepAK8_four",&probSum_DeepAK8_four,"probSum_DeepAK8_four/F");
   outputTree->Branch("nB_DeepAK8",&nB_DeepAK8,"nB_DeepAK8/I");
   outputTree->Branch("nH_DeepAK8",&nH_DeepAK8,"nH_DeepAK8/I");
   outputTree->Branch("nJ_DeepAK8",&nJ_DeepAK8,"nJ_DeepAK8/I");
   outputTree->Branch("nT_DeepAK8",&nT_DeepAK8,"nT_DeepAK8/I");
   outputTree->Branch("nW_DeepAK8",&nW_DeepAK8,"nW_DeepAK8/I");
   outputTree->Branch("nZ_DeepAK8",&nZ_DeepAK8,"nZ_DeepAK8/I");

   // VLQ reco   
   outputTree->Branch("W_mass",&W_mass,"W_mass/F");
   outputTree->Branch("W_pt",&W_pt,"W_pt/F");
   outputTree->Branch("W_dRLep",&W_dRLep,"W_dRLep/F");
   outputTree->Branch("t_mass",&t_mass,"t_mass/F");
   outputTree->Branch("t_pt",&t_pt,"t_pt/F");
   outputTree->Branch("t_dRWb",&t_dRWb,"t_dRWb/F");
   outputTree->Branch("deltaR_leptonicparticle_AK8_PtOrdered",&deltaR_leptonicparticle_AK8_PtOrdered);
   outputTree->Branch("isLeptonic_t",&isLeptonic_t,"isLeptonic_t/O");
   outputTree->Branch("isLeptonic_W",&isLeptonic_W,"isLeptonic_W/O");
   outputTree->Branch("Tprime1_DeepAK8_Mass",&Tprime1_DeepAK8_Mass,"Tprime1_DeepAK8_Mass/F");
   outputTree->Branch("Tprime2_DeepAK8_Mass",&Tprime2_DeepAK8_Mass,"Tprime2_DeepAK8_Mass/F");
   outputTree->Branch("Tprime1_DeepAK8_Pt",&Tprime1_DeepAK8_Pt,"Tprime1_DeepAK8_Pt/F");
   outputTree->Branch("Tprime2_DeepAK8_Pt",&Tprime2_DeepAK8_Pt,"Tprime2_DeepAK8_Pt/F");
   outputTree->Branch("Tprime1_DeepAK8_Eta",&Tprime1_DeepAK8_Eta,"Tprime1_DeepAK8_Eta/F");
   outputTree->Branch("Tprime2_DeepAK8_Eta",&Tprime2_DeepAK8_Eta,"Tprime2_DeepAK8_Eta/F");
   outputTree->Branch("Tprime1_DeepAK8_Phi",&Tprime1_DeepAK8_Phi,"Tprime1_DeepAK8_Phi/F");
   outputTree->Branch("Tprime2_DeepAK8_Phi",&Tprime2_DeepAK8_Phi,"Tprime2_DeepAK8_Phi/F");
   outputTree->Branch("Tprime1_DeepAK8_deltaR",&Tprime1_DeepAK8_deltaR,"Tprime1_DeepAK8_deltaR/F");
   outputTree->Branch("Tprime2_DeepAK8_deltaR",&Tprime2_DeepAK8_deltaR,"Tprime2_DeepAK8_deltaR/F");
   outputTree->Branch("isValidTTDecayMode_DeepAK8",&validTDecay_DeepAK8,"validTDecay_DeepAK8/O");
   outputTree->Branch("taggedBWBW_DeepAK8",&taggedBWBW_DeepAK8,"taggedBWBW_DeepAK8/O");
   outputTree->Branch("taggedTHBW_DeepAK8",&taggedTHBW_DeepAK8,"taggedTHBW_DeepAK8/O");
   outputTree->Branch("taggedTHTH_DeepAK8",&taggedTHTH_DeepAK8,"taggedTHTH_DeepAK8/O");
   outputTree->Branch("taggedTZBW_DeepAK8",&taggedTZBW_DeepAK8,"taggedTZBW_DeepAK8/O");
   outputTree->Branch("taggedTZTH_DeepAK8",&taggedTZTH_DeepAK8,"taggedTZTH_DeepAK8/O");
   outputTree->Branch("taggedTZTZ_DeepAK8",&taggedTZTZ_DeepAK8,"taggedTZTZ_DeepAK8/O");
   outputTree->Branch("highPtAK8Jet1_SoftDropCorrectedMass",&highPtAK8Jet1_SoftDropCorrectedMass,"highPtAK8Jet1_SoftDropCorrectedMass/F");
   outputTree->Branch("highPtAK8Jet2_SoftDropCorrectedMass",&highPtAK8Jet2_SoftDropCorrectedMass,"highPtAK8Jet2_SoftDropCorrectedMass/F");
   outputTree->Branch("highPtAK8Jet3_SoftDropCorrectedMass",&highPtAK8Jet3_SoftDropCorrectedMass,"highPtAK8Jet3_SoftDropCorrectedMass/F");
   outputTree->Branch("leptonicTprimeJetIDs_DeepAK8",&leptonicTprimeJetIDs_DeepAK8);
   outputTree->Branch("hadronicTprimeJetIDs_DeepAK8",&hadronicTprimeJetIDs_DeepAK8);

   outputTree->Branch("Bprime1_DeepAK8_Mass",&Bprime1_DeepAK8_Mass,"Bprime1_DeepAK8_Mass/F");
   outputTree->Branch("Bprime2_DeepAK8_Mass",&Bprime2_DeepAK8_Mass,"Bprime2_DeepAK8_Mass/F");
   outputTree->Branch("Bprime1_DeepAK8_Pt",&Bprime1_DeepAK8_Pt,"Bprime1_DeepAK8_Pt/F");
   outputTree->Branch("Bprime2_DeepAK8_Pt",&Bprime2_DeepAK8_Pt,"Bprime2_DeepAK8_Pt/F");
   outputTree->Branch("Bprime1_DeepAK8_Eta",&Bprime1_DeepAK8_Eta,"Bprime1_DeepAK8_Eta/F");
   outputTree->Branch("Bprime2_DeepAK8_Eta",&Bprime2_DeepAK8_Eta,"Bprime2_DeepAK8_Eta/F");
   outputTree->Branch("Bprime1_DeepAK8_Phi",&Bprime1_DeepAK8_Phi,"Bprime1_DeepAK8_Phi/F");
   outputTree->Branch("Bprime2_DeepAK8_Phi",&Bprime2_DeepAK8_Phi,"Bprime2_DeepAK8_Phi/F");
   outputTree->Branch("Bprime1_DeepAK8_deltaR",&Bprime1_DeepAK8_deltaR,"Bprime1_DeepAK8_deltaR/F");
   outputTree->Branch("Bprime2_DeepAK8_deltaR",&Bprime2_DeepAK8_deltaR,"Bprime2_DeepAK8_deltaR/F");
   outputTree->Branch("isValidBBDecayMode_DeepAK8",&validBDecay_DeepAK8,"validBDecay_DeepAK8/O");
   outputTree->Branch("taggedTWTW_DeepAK8",&taggedTWTW_DeepAK8,"taggedTWTW_DeepAK8/O");
   outputTree->Branch("taggedBHTW_DeepAK8",&taggedBHTW_DeepAK8,"taggedBZTW_DeepAK8/O");
   outputTree->Branch("taggedBZTW_DeepAK8",&taggedBZTW_DeepAK8,"taggedBHTW_DeepAK8/O");
   outputTree->Branch("leptonicBprimeJetIDs_DeepAK8",&leptonicBprimeJetIDs_DeepAK8);
   outputTree->Branch("hadronicBprimeJetIDs_DeepAK8",&hadronicBprimeJetIDs_DeepAK8);

   // ----------------------------------------------------------------------------
   // Define and initialize objects / cuts / efficiencies
   // ----------------------------------------------------------------------------

   // basic cuts
   float metCut=50;
   int   htCut=450;
   int   nAK8jetsCut=0;
   float lepPtCut=50;
   float elEtaCut=2.5;
   float muEtaCut=2.4;
   float jetEtaCut=2.4;
   float ak8EtaCut=2.4;
   float jetPtCut=30;
   float ak8PtCut=200;

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
   int npass_lepPt        = 0;
   int npass_ElEta        = 0;
   int npass_MuEta        = 0;
   int npass_all          = 0;
   int Nelectrons         = 0;
   int Nmuons             = 0;

   // Lorentz vectors
   TLorentzVector jet_lv;
   TLorentzVector lepton_lv;
   TLorentzVector ak8_lv;
   

   // Pileup distributions -- 31Mar2018 Data vs RunIIFall17MC
   std::vector<std::vector<float>> pileupweight;
   std::vector<std::vector<float>> pileupweightUp;
   std::vector<std::vector<float>> pileupweightDn;

   pileupweight = { // 69.2 mb
     { 2.835E-04, 4.399E-02, 4.817E-02, 6.416E-02, 6.566E-02, 1.137E-01, 1.327E-01, 1.748E-01, 1.153E-01, 3.682E-01, 4.893E-01, 6.327E-01, 6.937E-01, 7.157E-01, 7.351E-01, 8.159E-01, 8.876E-01, 1.006E+00, 1.086E+00, 1.145E+00, 1.208E+00, 1.252E+00, 1.295E+00, 1.326E+00, 1.329E+00, 1.351E+00, 1.349E+00, 1.354E+00, 1.364E+00, 1.348E+00, 1.321E+00, 1.261E+00, 1.191E+00, 1.125E+00, 1.056E+00, 9.903E-01, 9.451E-01, 9.121E-01, 8.587E-01, 8.164E-01, 8.142E-01, 8.557E-01, 9.305E-01, 1.044E+00, 1.188E+00, 1.347E+00, 1.527E+00, 1.576E+00, 1.627E+00, 1.561E+00, 1.363E+00, 1.222E+00, 1.004E+00, 7.747E-01, 5.955E-01, 4.290E-01, 3.002E-01, 2.099E-01, 1.454E-01, 1.015E-01, 7.117E-02, 5.287E-02, 4.043E-02, 3.071E-02, 2.376E-02, 1.749E-02, 1.254E-02, 1.029E-02, 1.006E-02, 8.396E-03, 7.763E-03, 5.241E-03, 6.290E-03, 5.725E-03, 2.761E-03, 2.530E-03, 1.811E-03, 1.530E-03, 6.849E-04, 3.797E-04}, // DYJetsMG.root
     { 3.544E-04, 3.998E-02, 4.526E-02, 7.801E-02, 9.146E-02, 1.097E-01, 1.527E-01, 2.427E-01, 1.278E-01, 4.256E-01, 5.532E-01, 6.663E-01, 6.732E-01, 7.100E-01, 7.715E-01, 8.042E-01, 9.015E-01, 9.917E-01, 1.066E+00, 1.131E+00, 1.189E+00, 1.253E+00, 1.282E+00, 1.315E+00, 1.325E+00, 1.339E+00, 1.339E+00, 1.339E+00, 1.362E+00, 1.336E+00, 1.297E+00, 1.239E+00, 1.190E+00, 1.117E+00, 1.039E+00, 9.847E-01, 9.359E-01, 8.988E-01, 8.460E-01, 8.122E-01, 8.128E-01, 8.503E-01, 9.144E-01, 1.020E+00, 1.173E+00, 1.348E+00, 1.525E+00, 1.596E+00, 1.638E+00, 1.565E+00, 1.346E+00, 1.213E+00, 9.796E-01, 7.891E-01, 5.957E-01, 4.270E-01, 3.022E-01, 2.079E-01, 1.453E-01, 1.013E-01, 7.242E-02, 5.264E-02, 4.040E-02, 3.102E-02, 2.399E-02, 1.754E-02, 1.216E-02, 1.027E-02, 9.501E-03, 8.830E-03, 7.677E-03, 5.254E-03, 6.172E-03, 5.941E-03, 3.630E-03, 4.188E-03, 2.190E-03, 1.532E-03, 1.240E-03, 5.375E-04}, // QCD1000.root
     { 1.749E-01, 4.172E+00, 3.462E+00, 2.677E+00, 1.657E+00, 1.475E+00, 1.255E+00, 1.247E+00, 6.000E-01, 1.423E+00, 1.498E+00, 1.492E+00, 1.325E+00, 1.164E+00, 1.082E+00, 1.052E+00, 1.083E+00, 1.127E+00, 1.163E+00, 1.191E+00, 1.212E+00, 1.241E+00, 1.255E+00, 1.270E+00, 1.274E+00, 1.273E+00, 1.272E+00, 1.268E+00, 1.278E+00, 1.250E+00, 1.223E+00, 1.171E+00, 1.111E+00, 1.036E+00, 9.706E-01, 9.104E-01, 8.681E-01, 8.332E-01, 7.862E-01, 7.510E-01, 7.602E-01, 7.926E-01, 8.584E-01, 9.577E-01, 1.096E+00, 1.256E+00, 1.416E+00, 1.494E+00, 1.526E+00, 1.468E+00, 1.336E+00, 1.152E+00, 9.528E-01, 7.484E-01, 5.701E-01, 4.122E-01, 2.880E-01, 1.984E-01, 1.374E-01, 9.694E-02, 6.917E-02, 5.072E-02, 3.857E-02, 2.990E-02, 2.407E-02, 1.711E-02, 1.255E-02, 1.081E-02, 9.624E-03, 8.906E-03, 8.153E-03, 8.132E-03, 7.845E-03, 7.748E-03, 6.232E-03, 5.267E-03, 5.608E-03, 6.070E-03, 6.121E-03, 6.164E-03}, // QCD1500.root
     { 1.672E-01, 4.002E+00, 3.617E+00, 2.548E+00, 1.509E+00, 1.493E+00, 1.296E+00, 1.240E+00, 6.044E-01, 1.455E+00, 1.498E+00, 1.488E+00, 1.340E+00, 1.174E+00, 1.086E+00, 1.052E+00, 1.083E+00, 1.128E+00, 1.168E+00, 1.181E+00, 1.205E+00, 1.236E+00, 1.259E+00, 1.272E+00, 1.271E+00, 1.272E+00, 1.271E+00, 1.267E+00, 1.278E+00, 1.251E+00, 1.219E+00, 1.164E+00, 1.109E+00, 1.038E+00, 9.689E-01, 9.156E-01, 8.645E-01, 8.359E-01, 7.875E-01, 7.518E-01, 7.621E-01, 7.939E-01, 8.594E-01, 9.634E-01, 1.096E+00, 1.255E+00, 1.424E+00, 1.511E+00, 1.535E+00, 1.457E+00, 1.342E+00, 1.153E+00, 9.464E-01, 7.538E-01, 5.673E-01, 4.094E-01, 2.882E-01, 1.995E-01, 1.377E-01, 9.630E-02, 6.899E-02, 5.090E-02, 3.856E-02, 2.996E-02, 2.428E-02, 1.692E-02, 1.250E-02, 1.081E-02, 9.817E-03, 8.680E-03, 8.324E-03, 8.295E-03, 7.672E-03, 7.872E-03, 6.039E-03, 5.129E-03, 5.624E-03, 5.494E-03, 6.660E-03, 5.473E-03}, // QCD2000.root
     { 2.758E-04, 2.979E-02, 4.481E-02, 7.384E-02, 6.863E-02, 1.116E-01, 1.301E-01, 1.552E-01, 1.058E-01, 3.333E-01, 5.015E-01, 6.410E-01, 6.712E-01, 7.089E-01, 7.387E-01, 8.027E-01, 9.054E-01, 9.982E-01, 1.086E+00, 1.149E+00, 1.200E+00, 1.257E+00, 1.302E+00, 1.324E+00, 1.342E+00, 1.344E+00, 1.353E+00, 1.352E+00, 1.366E+00, 1.349E+00, 1.320E+00, 1.250E+00, 1.194E+00, 1.130E+00, 1.055E+00, 9.941E-01, 9.461E-01, 9.058E-01, 8.535E-01, 8.164E-01, 8.234E-01, 8.614E-01, 9.270E-01, 1.046E+00, 1.190E+00, 1.357E+00, 1.530E+00, 1.580E+00, 1.623E+00, 1.552E+00, 1.396E+00, 1.203E+00, 9.963E-01, 7.804E-01, 5.990E-01, 4.260E-01, 3.034E-01, 2.091E-01, 1.455E-01, 1.023E-01, 7.260E-02, 5.320E-02, 4.007E-02, 3.055E-02, 2.303E-02, 1.753E-02, 1.254E-02, 1.085E-02, 8.972E-03, 8.785E-03, 7.276E-03, 6.235E-03, 5.168E-03, 6.401E-03, 3.540E-03, 3.876E-03, 2.529E-03, 1.391E-03, 1.006E-03, 5.000E-04}, // QCD300.root
     { 2.494E-04, 3.158E-02, 3.862E-02, 5.765E-02, 7.191E-02, 1.117E-01, 1.001E-01, 1.299E-01, 1.084E-01, 3.222E-01, 4.813E-01, 6.202E-01, 6.505E-01, 7.113E-01, 7.297E-01, 7.877E-01, 9.025E-01, 1.013E+00, 1.094E+00, 1.148E+00, 1.211E+00, 1.252E+00, 1.304E+00, 1.336E+00, 1.347E+00, 1.356E+00, 1.354E+00, 1.365E+00, 1.369E+00, 1.351E+00, 1.328E+00, 1.258E+00, 1.202E+00, 1.130E+00, 1.059E+00, 9.882E-01, 9.494E-01, 9.124E-01, 8.601E-01, 8.192E-01, 8.230E-01, 8.637E-01, 9.387E-01, 1.048E+00, 1.188E+00, 1.354E+00, 1.540E+00, 1.616E+00, 1.634E+00, 1.572E+00, 1.388E+00, 1.224E+00, 1.001E+00, 7.875E-01, 5.981E-01, 4.347E-01, 3.054E-01, 2.086E-01, 1.461E-01, 1.012E-01, 7.329E-02, 5.338E-02, 4.046E-02, 3.013E-02, 2.390E-02, 1.758E-02, 1.241E-02, 1.099E-02, 9.904E-03, 8.385E-03, 7.029E-03, 5.092E-03, 5.896E-03, 4.427E-03, 3.156E-03, 3.957E-03, 2.318E-03, 2.368E-03, 1.121E-03, 5.284E-04}, // QCD500.root
     { 2.960E-04, 4.661E-02, 5.142E-02, 7.836E-02, 7.650E-02, 1.158E-01, 1.384E-01, 1.598E-01, 1.298E-01, 4.088E-01, 5.108E-01, 6.759E-01, 7.111E-01, 7.069E-01, 7.569E-01, 8.221E-01, 9.024E-01, 9.951E-01, 1.083E+00, 1.143E+00, 1.196E+00, 1.243E+00, 1.290E+00, 1.319E+00, 1.335E+00, 1.333E+00, 1.349E+00, 1.351E+00, 1.349E+00, 1.339E+00, 1.312E+00, 1.253E+00, 1.187E+00, 1.126E+00, 1.046E+00, 9.803E-01, 9.405E-01, 9.074E-01, 8.515E-01, 8.155E-01, 8.172E-01, 8.621E-01, 9.268E-01, 1.040E+00, 1.184E+00, 1.351E+00, 1.528E+00, 1.601E+00, 1.645E+00, 1.555E+00, 1.395E+00, 1.202E+00, 1.009E+00, 7.834E-01, 5.907E-01, 4.264E-01, 3.005E-01, 2.080E-01, 1.442E-01, 1.016E-01, 7.377E-02, 5.274E-02, 4.028E-02, 2.943E-02, 2.345E-02, 1.733E-02, 1.304E-02, 1.089E-02, 9.218E-03, 8.375E-03, 7.196E-03, 4.961E-03, 5.212E-03, 4.817E-03, 2.602E-03, 3.627E-03, 2.491E-03, 2.361E-03, 6.611E-04, 6.415E-04}, // QCD700.root
     { 2.894E-04, 4.360E-02, 5.014E-02, 6.912E-02, 8.141E-02, 1.445E-01, 1.405E-01, 1.480E-01, 1.039E-01, 3.417E-01, 4.570E-01, 6.214E-01, 6.927E-01, 6.701E-01, 6.820E-01, 8.060E-01, 8.304E-01, 9.961E-01, 1.076E+00, 1.131E+00, 1.193E+00, 1.219E+00, 1.294E+00, 1.326E+00, 1.323E+00, 1.350E+00, 1.362E+00, 1.348E+00, 1.360E+00, 1.339E+00, 1.311E+00, 1.262E+00, 1.185E+00, 1.131E+00, 1.058E+00, 1.002E+00, 9.544E-01, 9.065E-01, 8.609E-01, 8.214E-01, 8.346E-01, 8.601E-01, 9.398E-01, 1.059E+00, 1.200E+00, 1.364E+00, 1.510E+00, 1.641E+00, 1.590E+00, 1.542E+00, 1.397E+00, 1.237E+00, 1.003E+00, 8.001E-01, 5.921E-01, 4.271E-01, 3.083E-01, 2.139E-01, 1.458E-01, 1.017E-01, 7.216E-02, 5.370E-02, 4.107E-02, 3.045E-02, 2.474E-02, 1.765E-02, 1.298E-02, 1.070E-02, 9.453E-03, 9.417E-03, 7.668E-03, 4.481E-03, 3.087E-03, 6.682E-03, 3.068E-03, 1.882E-03, 1.948E-03, 5.821E-03, 1.565E-03, 3.780E-04}, // STs.root
     { 1.800E-01, 3.572E+00, 3.238E+00, 2.501E+00, 1.587E+00, 1.524E+00, 1.259E+00, 1.234E+00, 6.249E-01, 1.469E+00, 1.489E+00, 1.493E+00, 1.332E+00, 1.168E+00, 1.077E+00, 1.050E+00, 1.085E+00, 1.129E+00, 1.164E+00, 1.190E+00, 1.213E+00, 1.238E+00, 1.258E+00, 1.270E+00, 1.275E+00, 1.274E+00, 1.272E+00, 1.267E+00, 1.276E+00, 1.252E+00, 1.223E+00, 1.169E+00, 1.110E+00, 1.035E+00, 9.696E-01, 9.107E-01, 8.679E-01, 8.329E-01, 7.873E-01, 7.513E-01, 7.580E-01, 7.947E-01, 8.584E-01, 9.582E-01, 1.093E+00, 1.255E+00, 1.420E+00, 1.496E+00, 1.525E+00, 1.468E+00, 1.336E+00, 1.156E+00, 9.496E-01, 7.491E-01, 5.688E-01, 4.106E-01, 2.897E-01, 1.987E-01, 1.380E-01, 9.650E-02, 6.927E-02, 5.094E-02, 3.836E-02, 2.994E-02, 2.412E-02, 1.694E-02, 1.244E-02, 1.079E-02, 9.658E-03, 8.864E-03, 8.303E-03, 8.066E-03, 7.846E-03, 7.957E-03, 6.113E-03, 5.381E-03, 5.472E-03, 5.358E-03, 5.970E-03, 6.237E-03}, // STt.root
     { 1.780E-01, 5.124E+00, 3.340E+00, 2.752E+00, 1.532E+00, 1.502E+00, 1.283E+00, 1.247E+00, 6.408E-01, 1.423E+00, 1.493E+00, 1.501E+00, 1.316E+00, 1.161E+00, 1.081E+00, 1.048E+00, 1.081E+00, 1.129E+00, 1.170E+00, 1.190E+00, 1.214E+00, 1.239E+00, 1.258E+00, 1.269E+00, 1.274E+00, 1.270E+00, 1.265E+00, 1.265E+00, 1.274E+00, 1.253E+00, 1.220E+00, 1.173E+00, 1.111E+00, 1.039E+00, 9.675E-01, 9.125E-01, 8.687E-01, 8.348E-01, 7.882E-01, 7.476E-01, 7.592E-01, 7.946E-01, 8.570E-01, 9.614E-01, 1.095E+00, 1.257E+00, 1.418E+00, 1.502E+00, 1.533E+00, 1.460E+00, 1.343E+00, 1.154E+00, 9.496E-01, 7.457E-01, 5.701E-01, 4.112E-01, 2.882E-01, 1.982E-01, 1.382E-01, 9.659E-02, 6.902E-02, 5.065E-02, 3.841E-02, 3.010E-02, 2.401E-02, 1.713E-02, 1.250E-02, 1.079E-02, 9.623E-03, 8.901E-03, 8.297E-03, 8.180E-03, 7.698E-03, 7.869E-03, 6.500E-03, 5.429E-03, 5.453E-03, 5.933E-03, 5.511E-03, 5.550E-03}, // STtb.root
     { 2.605E-04, 2.631E-02, 3.681E-02, 4.785E-02, 7.677E-02, 1.316E-01, 9.301E-02, 1.018E-01, 1.079E-01, 4.031E-01, 4.383E-01, 6.138E-01, 6.870E-01, 7.113E-01, 7.262E-01, 8.072E-01, 8.834E-01, 9.917E-01, 1.070E+00, 1.134E+00, 1.185E+00, 1.256E+00, 1.307E+00, 1.338E+00, 1.329E+00, 1.353E+00, 1.370E+00, 1.381E+00, 1.371E+00, 1.359E+00, 1.336E+00, 1.252E+00, 1.208E+00, 1.133E+00, 1.066E+00, 9.925E-01, 9.398E-01, 9.187E-01, 8.526E-01, 8.198E-01, 8.374E-01, 8.628E-01, 9.381E-01, 1.055E+00, 1.208E+00, 1.350E+00, 1.567E+00, 1.627E+00, 1.624E+00, 1.558E+00, 1.401E+00, 1.214E+00, 1.002E+00, 7.880E-01, 5.921E-01, 4.393E-01, 3.076E-01, 2.087E-01, 1.429E-01, 1.036E-01, 7.355E-02, 5.130E-02, 3.955E-02, 3.146E-02, 2.366E-02, 1.726E-02, 1.258E-02, 1.092E-02, 1.015E-02, 9.365E-03, 6.013E-03, 3.590E-03, 4.496E-03, 4.837E-03, 6.140E-03, 4.341E-03, 1.343E-03, 4.228E-03, 5.226E-04, 7.545E-04}, // STtWt.root
     { 2.607E-04, 2.222E-02, 4.369E-02, 5.655E-02, 7.639E-02, 9.580E-02, 1.022E-01, 1.921E-01, 1.312E-01, 3.306E-01, 5.204E-01, 6.816E-01, 6.607E-01, 6.635E-01, 7.260E-01, 7.893E-01, 9.209E-01, 1.004E+00, 1.098E+00, 1.158E+00, 1.206E+00, 1.268E+00, 1.289E+00, 1.328E+00, 1.341E+00, 1.340E+00, 1.358E+00, 1.349E+00, 1.383E+00, 1.356E+00, 1.331E+00, 1.242E+00, 1.211E+00, 1.133E+00, 1.049E+00, 9.995E-01, 9.512E-01, 9.076E-01, 8.579E-01, 8.202E-01, 8.377E-01, 8.753E-01, 9.439E-01, 1.041E+00, 1.193E+00, 1.341E+00, 1.525E+00, 1.574E+00, 1.593E+00, 1.569E+00, 1.366E+00, 1.206E+00, 1.021E+00, 7.956E-01, 6.034E-01, 4.278E-01, 3.102E-01, 2.086E-01, 1.461E-01, 1.031E-01, 7.383E-02, 5.028E-02, 4.112E-02, 3.090E-02, 2.154E-02, 1.732E-02, 1.306E-02, 1.068E-02, 9.153E-03, 8.133E-03, 6.713E-03, 5.319E-03, 3.989E-03, 8.444E-03, 1.941E-03, 4.946E-03, 2.976E-03, 3.784E-03, 5.910E-04, 2.521E-04}, // STtWtb.root
     { 2.406E-04, 3.385E-02, 3.578E-02, 5.432E-02, 6.220E-02, 9.562E-02, 1.249E-01, 1.405E-01, 1.066E-01, 3.192E-01, 4.762E-01, 6.200E-01, 6.800E-01, 7.151E-01, 7.432E-01, 7.980E-01, 8.981E-01, 1.007E+00, 1.090E+00, 1.145E+00, 1.208E+00, 1.252E+00, 1.304E+00, 1.329E+00, 1.345E+00, 1.349E+00, 1.354E+00, 1.362E+00, 1.372E+00, 1.359E+00, 1.325E+00, 1.259E+00, 1.200E+00, 1.133E+00, 1.059E+00, 9.963E-01, 9.505E-01, 9.115E-01, 8.607E-01, 8.247E-01, 8.266E-01, 8.668E-01, 9.347E-01, 1.045E+00, 1.196E+00, 1.369E+00, 1.551E+00, 1.602E+00, 1.626E+00, 1.571E+00, 1.409E+00, 1.217E+00, 1.005E+00, 7.886E-01, 6.010E-01, 4.290E-01, 3.019E-01, 2.112E-01, 1.465E-01, 1.022E-01, 7.362E-02, 5.391E-02, 4.057E-02, 3.021E-02, 2.415E-02, 1.752E-02, 1.257E-02, 1.084E-02, 9.528E-03, 8.775E-03, 7.496E-03, 5.919E-03, 5.381E-03, 5.185E-03, 4.161E-03, 3.090E-03, 1.867E-03, 1.701E-03, 9.188E-04, 5.315E-04}, // TThad.root
     { 2.326E-04, 2.787E-02, 3.339E-02, 5.035E-02, 6.247E-02, 9.966E-02, 1.074E-01, 1.442E-01, 1.041E-01, 3.121E-01, 4.634E-01, 6.124E-01, 6.707E-01, 6.990E-01, 7.462E-01, 8.168E-01, 9.110E-01, 1.022E+00, 1.100E+00, 1.156E+00, 1.212E+00, 1.261E+00, 1.307E+00, 1.336E+00, 1.353E+00, 1.354E+00, 1.353E+00, 1.360E+00, 1.376E+00, 1.354E+00, 1.326E+00, 1.264E+00, 1.198E+00, 1.132E+00, 1.062E+00, 9.996E-01, 9.498E-01, 9.122E-01, 8.609E-01, 8.217E-01, 8.276E-01, 8.657E-01, 9.451E-01, 1.048E+00, 1.196E+00, 1.360E+00, 1.538E+00, 1.600E+00, 1.634E+00, 1.581E+00, 1.403E+00, 1.211E+00, 9.999E-01, 7.865E-01, 5.984E-01, 4.296E-01, 3.034E-01, 2.107E-01, 1.463E-01, 1.024E-01, 7.337E-02, 5.378E-02, 4.052E-02, 3.077E-02, 2.339E-02, 1.753E-02, 1.269E-02, 1.092E-02, 9.353E-03, 9.002E-03, 7.919E-03, 4.869E-03, 6.104E-03, 4.942E-03, 3.426E-03, 2.660E-03, 2.304E-03, 2.039E-03, 1.059E-03, 5.481E-04}, // TT1L.root
     { 2.328E-04, 3.090E-02, 4.163E-02, 4.817E-02, 5.984E-02, 9.593E-02, 1.055E-01, 1.605E-01, 1.151E-01, 3.110E-01, 4.780E-01, 6.027E-01, 6.617E-01, 6.884E-01, 7.227E-01, 7.992E-01, 8.973E-01, 1.001E+00, 1.085E+00, 1.149E+00, 1.217E+00, 1.260E+00, 1.303E+00, 1.342E+00, 1.352E+00, 1.359E+00, 1.367E+00, 1.366E+00, 1.386E+00, 1.359E+00, 1.335E+00, 1.267E+00, 1.203E+00, 1.130E+00, 1.060E+00, 9.983E-01, 9.556E-01, 9.185E-01, 8.634E-01, 8.242E-01, 8.302E-01, 8.673E-01, 9.375E-01, 1.051E+00, 1.194E+00, 1.359E+00, 1.540E+00, 1.593E+00, 1.626E+00, 1.570E+00, 1.398E+00, 1.220E+00, 9.918E-01, 7.834E-01, 5.988E-01, 4.256E-01, 3.069E-01, 2.102E-01, 1.467E-01, 1.022E-01, 7.271E-02, 5.372E-02, 4.035E-02, 3.002E-02, 2.315E-02, 1.791E-02, 1.267E-02, 1.052E-02, 9.544E-03, 8.520E-03, 8.017E-03, 6.324E-03, 6.082E-03, 5.663E-03, 2.850E-03, 3.110E-03, 2.375E-03, 1.463E-03, 1.312E-03, 4.850E-04}, // TT2L.root
     { 1.829E-01, 3.581E+00, 3.653E+00, 2.510E+00, 1.605E+00, 1.528E+00, 1.253E+00, 1.264E+00, 6.156E-01, 1.469E+00, 1.500E+00, 1.473E+00, 1.340E+00, 1.166E+00, 1.074E+00, 1.057E+00, 1.075E+00, 1.127E+00, 1.169E+00, 1.188E+00, 1.212E+00, 1.238E+00, 1.260E+00, 1.272E+00, 1.272E+00, 1.272E+00, 1.270E+00, 1.266E+00, 1.275E+00, 1.250E+00, 1.224E+00, 1.167E+00, 1.110E+00, 1.039E+00, 9.682E-01, 9.119E-01, 8.667E-01, 8.359E-01, 7.903E-01, 7.499E-01, 7.578E-01, 7.936E-01, 8.595E-01, 9.557E-01, 1.098E+00, 1.254E+00, 1.419E+00, 1.500E+00, 1.529E+00, 1.462E+00, 1.339E+00, 1.152E+00, 9.470E-01, 7.516E-01, 5.683E-01, 4.100E-01, 2.894E-01, 1.993E-01, 1.372E-01, 9.685E-02, 6.914E-02, 5.076E-02, 3.851E-02, 2.990E-02, 2.414E-02, 1.714E-02, 1.249E-02, 1.084E-02, 9.637E-03, 8.826E-03, 8.251E-03, 7.945E-03, 7.913E-03, 7.839E-03, 6.205E-03, 5.395E-03, 5.376E-03, 5.855E-03, 5.805E-03, 5.727E-03}, // TTMtt1000.root
     { 2.564E-04, 3.837E-02, 3.059E-02, 5.322E-02, 6.786E-02, 9.388E-02, 1.256E-01, 1.484E-01, 1.033E-01, 3.382E-01, 4.688E-01, 6.103E-01, 6.883E-01, 6.948E-01, 7.502E-01, 8.297E-01, 9.089E-01, 9.969E-01, 1.095E+00, 1.143E+00, 1.203E+00, 1.262E+00, 1.306E+00, 1.333E+00, 1.348E+00, 1.344E+00, 1.349E+00, 1.360E+00, 1.371E+00, 1.356E+00, 1.326E+00, 1.267E+00, 1.197E+00, 1.129E+00, 1.052E+00, 9.949E-01, 9.485E-01, 9.147E-01, 8.563E-01, 8.183E-01, 8.310E-01, 8.650E-01, 9.384E-01, 1.046E+00, 1.197E+00, 1.363E+00, 1.533E+00, 1.615E+00, 1.624E+00, 1.580E+00, 1.390E+00, 1.200E+00, 1.008E+00, 7.782E-01, 5.965E-01, 4.190E-01, 3.025E-01, 2.105E-01, 1.457E-01, 1.019E-01, 7.269E-02, 5.390E-02, 4.059E-02, 3.069E-02, 2.300E-02, 1.719E-02, 1.252E-02, 1.121E-02, 9.765E-03, 7.860E-03, 8.231E-03, 5.744E-03, 4.478E-03, 5.989E-03, 2.354E-03, 2.470E-03, 1.666E-03, 2.406E-03, 1.619E-03, 3.990E-04}, // TTMtt700.root
     { 1.777E-01, 4.152E+00, 3.134E+00, 2.525E+00, 1.672E+00, 1.475E+00, 1.314E+00, 1.246E+00, 6.182E-01, 1.445E+00, 1.502E+00, 1.481E+00, 1.335E+00, 1.172E+00, 1.077E+00, 1.056E+00, 1.078E+00, 1.128E+00, 1.163E+00, 1.187E+00, 1.210E+00, 1.241E+00, 1.257E+00, 1.269E+00, 1.274E+00, 1.272E+00, 1.275E+00, 1.269E+00, 1.274E+00, 1.251E+00, 1.221E+00, 1.172E+00, 1.108E+00, 1.038E+00, 9.686E-01, 9.096E-01, 8.677E-01, 8.350E-01, 7.882E-01, 7.517E-01, 7.598E-01, 7.926E-01, 8.621E-01, 9.573E-01, 1.095E+00, 1.256E+00, 1.418E+00, 1.493E+00, 1.519E+00, 1.461E+00, 1.337E+00, 1.155E+00, 9.482E-01, 7.499E-01, 5.699E-01, 4.113E-01, 2.900E-01, 1.983E-01, 1.379E-01, 9.650E-02, 6.894E-02, 5.091E-02, 3.854E-02, 3.005E-02, 2.404E-02, 1.723E-02, 1.252E-02, 1.087E-02, 9.655E-03, 8.873E-03, 8.288E-03, 8.132E-03, 7.512E-03, 7.948E-03, 6.459E-03, 5.342E-03, 5.533E-03, 5.494E-03, 6.272E-03, 5.718E-03}, // ttW.root
     { 1.706E-01, 3.530E+00, 3.856E+00, 2.444E+00, 1.560E+00, 1.559E+00, 1.305E+00, 1.151E+00, 6.161E-01, 1.462E+00, 1.460E+00, 1.477E+00, 1.332E+00, 1.169E+00, 1.089E+00, 1.053E+00, 1.081E+00, 1.127E+00, 1.168E+00, 1.189E+00, 1.213E+00, 1.239E+00, 1.260E+00, 1.269E+00, 1.271E+00, 1.271E+00, 1.267E+00, 1.268E+00, 1.277E+00, 1.252E+00, 1.224E+00, 1.168E+00, 1.112E+00, 1.035E+00, 9.726E-01, 9.155E-01, 8.653E-01, 8.328E-01, 7.885E-01, 7.499E-01, 7.569E-01, 7.910E-01, 8.622E-01, 9.600E-01, 1.097E+00, 1.263E+00, 1.419E+00, 1.488E+00, 1.534E+00, 1.459E+00, 1.336E+00, 1.153E+00, 9.516E-01, 7.507E-01, 5.691E-01, 4.092E-01, 2.881E-01, 1.979E-01, 1.371E-01, 9.644E-02, 6.921E-02, 5.098E-02, 3.832E-02, 3.012E-02, 2.400E-02, 1.712E-02, 1.263E-02, 1.081E-02, 9.730E-03, 8.891E-03, 8.303E-03, 7.981E-03, 7.828E-03, 7.682E-03, 5.988E-03, 5.577E-03, 5.647E-03, 5.452E-03, 5.620E-03, 6.340E-03}, // ttZ.root
     { 2.629E-04, 3.050E-02, 3.890E-02, 6.312E-02, 7.966E-02, 8.978E-02, 1.220E-01, 1.564E-01, 1.403E-01, 3.331E-01, 4.831E-01, 7.230E-01, 6.684E-01, 6.902E-01, 7.569E-01, 8.120E-01, 9.160E-01, 9.935E-01, 1.107E+00, 1.147E+00, 1.205E+00, 1.275E+00, 1.308E+00, 1.340E+00, 1.357E+00, 1.334E+00, 1.338E+00, 1.374E+00, 1.364E+00, 1.327E+00, 1.328E+00, 1.268E+00, 1.172E+00, 1.140E+00, 1.057E+00, 1.000E+00, 9.372E-01, 9.072E-01, 8.622E-01, 8.166E-01, 8.278E-01, 8.347E-01, 9.259E-01, 1.027E+00, 1.198E+00, 1.365E+00, 1.532E+00, 1.601E+00, 1.664E+00, 1.586E+00, 1.423E+00, 1.201E+00, 9.999E-01, 8.071E-01, 5.876E-01, 4.368E-01, 3.066E-01, 2.078E-01, 1.453E-01, 1.008E-01, 7.283E-02, 5.322E-02, 4.061E-02, 3.022E-02, 2.276E-02, 1.655E-02, 1.240E-02, 1.027E-02, 8.813E-03, 8.502E-03, 7.074E-03, 3.975E-03, 4.932E-03, 3.915E-03, 5.159E-03, 3.200E-03, 3.571E-03, 1.294E-03, 5.620E-04, 2.589E-04}, // ttH.root
     { 2.287E-04, 2.292E-02, 3.389E-02, 5.589E-02, 7.345E-02, 9.506E-02, 1.567E-01, 1.679E-01, 1.027E-01, 3.358E-01, 5.043E-01, 5.718E-01, 7.089E-01, 7.301E-01, 7.766E-01, 8.208E-01, 9.466E-01, 1.003E+00, 1.090E+00, 1.158E+00, 1.203E+00, 1.254E+00, 1.304E+00, 1.321E+00, 1.364E+00, 1.320E+00, 1.336E+00, 1.364E+00, 1.384E+00, 1.363E+00, 1.327E+00, 1.235E+00, 1.180E+00, 1.133E+00, 1.038E+00, 9.921E-01, 9.512E-01, 8.981E-01, 8.557E-01, 8.188E-01, 8.226E-01, 8.653E-01, 9.360E-01, 1.043E+00, 1.196E+00, 1.390E+00, 1.552E+00, 1.611E+00, 1.653E+00, 1.593E+00, 1.397E+00, 1.211E+00, 1.016E+00, 8.021E-01, 5.913E-01, 4.259E-01, 3.059E-01, 2.099E-01, 1.442E-01, 1.030E-01, 7.447E-02, 5.361E-02, 3.887E-02, 3.212E-02, 2.586E-02, 1.842E-02, 1.320E-02, 1.090E-02, 9.167E-03, 9.412E-03, 7.134E-03, 6.695E-03, 8.357E-03, 8.256E-03, 6.384E-03, 3.223E-03, 5.739E-03, 5.987E-03, 5.793E-03, 5.615E-04}, // WW.root
     { 2.869E-04, 9.374E-03, 3.689E-02, 6.702E-02, 9.232E-02, 1.800E-01, 1.922E-01, 2.219E-01, 1.089E-01, 4.104E-01, 4.199E-01, 6.427E-01, 7.047E-01, 7.547E-01, 7.360E-01, 7.494E-01, 8.440E-01, 1.009E+00, 1.084E+00, 1.138E+00, 1.231E+00, 1.263E+00, 1.297E+00, 1.322E+00, 1.345E+00, 1.347E+00, 1.332E+00, 1.359E+00, 1.385E+00, 1.368E+00, 1.298E+00, 1.255E+00, 1.197E+00, 1.131E+00, 1.070E+00, 1.008E+00, 9.473E-01, 9.046E-01, 8.477E-01, 8.320E-01, 8.104E-01, 8.451E-01, 9.316E-01, 1.064E+00, 1.210E+00, 1.362E+00, 1.547E+00, 1.642E+00, 1.651E+00, 1.610E+00, 1.433E+00, 1.247E+00, 1.025E+00, 7.690E-01, 5.969E-01, 4.246E-01, 3.122E-01, 2.133E-01, 1.483E-01, 1.042E-01, 7.078E-02, 5.239E-02, 3.758E-02, 2.855E-02, 2.451E-02, 1.824E-02, 1.194E-02, 1.108E-02, 7.717E-03, 8.780E-03, 4.887E-03, 4.952E-03, 4.224E-03, 8.586E-03, 3.532E-03, 1.218E-03, 8.432E-04, 5.514E-03, 2.907E-04, 2.155E-04}, // WZ.root
     { 4.546E-04, 2.534E-02, 3.661E-02, 2.158E-01, 1.437E-01, 1.406E-01, 2.281E-01, 2.785E-01, 1.595E-01, 4.560E-01, 5.475E-01, 7.024E-01, 7.455E-01, 7.130E-01, 6.330E-01, 7.235E-01, 8.012E-01, 9.118E-01, 1.052E+00, 1.104E+00, 1.171E+00, 1.251E+00, 1.300E+00, 1.325E+00, 1.326E+00, 1.344E+00, 1.353E+00, 1.343E+00, 1.334E+00, 1.345E+00, 1.325E+00, 1.264E+00, 1.187E+00, 1.128E+00, 1.053E+00, 9.933E-01, 9.439E-01, 9.083E-01, 8.603E-01, 8.265E-01, 8.285E-01, 8.341E-01, 9.475E-01, 1.005E+00, 1.205E+00, 1.319E+00, 1.557E+00, 1.555E+00, 1.611E+00, 1.592E+00, 1.327E+00, 1.226E+00, 1.024E+00, 7.230E-01, 5.492E-01, 4.278E-01, 3.085E-01, 2.009E-01, 1.457E-01, 9.861E-02, 7.158E-02, 5.429E-02, 4.119E-02, 2.955E-02, 2.219E-02, 1.474E-02, 1.221E-02, 1.157E-02, 9.763E-03, 9.035E-03, 8.900E-03, 8.299E-03, 8.596E-03, 8.830E-03, 6.079E-03, 5.265E-03, 6.533E-03, 1.267E-03, 2.455E-03, 9.727E-05}, // ZZ.root
     { 1.737E-01, 1.055E+01, 4.352E+00, 2.942E+00, 1.548E+00, 1.589E+00, 1.295E+00, 1.292E+00, 6.233E-01, 1.440E+00, 1.506E+00, 1.584E+00, 1.330E+00, 1.196E+00, 1.075E+00, 1.060E+00, 1.067E+00, 1.127E+00, 1.156E+00, 1.184E+00, 1.208E+00, 1.230E+00, 1.244E+00, 1.289E+00, 1.282E+00, 1.267E+00, 1.274E+00, 1.255E+00, 1.291E+00, 1.243E+00, 1.215E+00, 1.156E+00, 1.104E+00, 1.046E+00, 9.638E-01, 9.099E-01, 8.666E-01, 8.356E-01, 7.955E-01, 7.521E-01, 7.623E-01, 7.873E-01, 8.549E-01, 9.447E-01, 1.093E+00, 1.253E+00, 1.434E+00, 1.507E+00, 1.528E+00, 1.446E+00, 1.327E+00, 1.148E+00, 9.370E-01, 7.509E-01, 5.741E-01, 4.201E-01, 2.926E-01, 1.973E-01, 1.392E-01, 9.638E-02, 7.009E-02, 5.182E-02, 3.903E-02, 3.123E-02, 2.462E-02, 1.788E-02, 1.248E-02, 1.042E-02, 9.927E-03, 9.133E-03, 8.077E-03, 8.021E-03, 7.964E-03, 7.882E-03, 6.734E-03, 5.201E-03, 5.570E-03, 6.242E-03, 4.751E-03, 5.440E-03}, // TpTp700.root
     { 1.875E-01, 4.242E+00, 2.624E+00, 2.240E+00, 1.587E+00, 1.455E+00, 1.372E+00, 1.061E+00, 5.604E-01, 1.342E+00, 1.505E+00, 1.511E+00, 1.339E+00, 1.188E+00, 1.120E+00, 1.043E+00, 1.090E+00, 1.126E+00, 1.159E+00, 1.179E+00, 1.210E+00, 1.231E+00, 1.259E+00, 1.265E+00, 1.280E+00, 1.279E+00, 1.280E+00, 1.261E+00, 1.269E+00, 1.263E+00, 1.216E+00, 1.158E+00, 1.117E+00, 1.042E+00, 9.759E-01, 9.145E-01, 8.574E-01, 8.281E-01, 7.890E-01, 7.517E-01, 7.487E-01, 7.954E-01, 8.684E-01, 9.680E-01, 1.090E+00, 1.249E+00, 1.407E+00, 1.487E+00, 1.537E+00, 1.485E+00, 1.334E+00, 1.161E+00, 9.685E-01, 7.463E-01, 5.761E-01, 4.040E-01, 2.921E-01, 1.990E-01, 1.370E-01, 9.548E-02, 6.825E-02, 5.148E-02, 3.840E-02, 3.014E-02, 2.454E-02, 1.696E-02, 1.267E-02, 1.055E-02, 9.746E-03, 8.898E-03, 8.372E-03, 8.391E-03, 7.481E-03, 7.044E-03, 5.584E-03, 5.658E-03, 4.883E-03, 4.657E-03, 4.368E-03, 5.942E-03}, // TpTp1000.root
     { 2.315E-01, 3.072E+00, 2.850E+00, 2.379E+00, 1.814E+00, 1.427E+00, 1.502E+00, 1.198E+00, 6.637E-01, 1.478E+00, 1.465E+00, 1.593E+00, 1.334E+00, 1.162E+00, 1.089E+00, 1.052E+00, 1.074E+00, 1.133E+00, 1.161E+00, 1.196E+00, 1.212E+00, 1.235E+00, 1.260E+00, 1.276E+00, 1.285E+00, 1.278E+00, 1.270E+00, 1.259E+00, 1.272E+00, 1.265E+00, 1.203E+00, 1.151E+00, 1.119E+00, 1.035E+00, 9.633E-01, 9.135E-01, 8.644E-01, 8.412E-01, 7.865E-01, 7.494E-01, 7.635E-01, 7.874E-01, 8.475E-01, 9.577E-01, 1.104E+00, 1.274E+00, 1.419E+00, 1.490E+00, 1.524E+00, 1.496E+00, 1.342E+00, 1.169E+00, 9.458E-01, 7.514E-01, 5.769E-01, 4.126E-01, 2.925E-01, 2.000E-01, 1.368E-01, 9.616E-02, 6.762E-02, 5.076E-02, 3.781E-02, 2.879E-02, 2.332E-02, 1.717E-02, 1.265E-02, 1.079E-02, 9.486E-03, 9.464E-03, 8.739E-03, 8.339E-03, 8.351E-03, 7.462E-03, 7.104E-03, 5.085E-03, 4.805E-03, 6.677E-03, 5.575E-03, 5.164E-03}, // TpTp1100.root
     { 2.174E-01, 2.227E+00, 2.479E+00, 2.328E+00, 1.704E+00, 1.940E+00, 1.549E+00, 1.289E+00, 5.517E-01, 1.441E+00, 1.490E+00, 1.434E+00, 1.362E+00, 1.171E+00, 1.073E+00, 1.050E+00, 1.080E+00, 1.120E+00, 1.159E+00, 1.167E+00, 1.210E+00, 1.239E+00, 1.259E+00, 1.290E+00, 1.269E+00, 1.256E+00, 1.265E+00, 1.263E+00, 1.287E+00, 1.244E+00, 1.225E+00, 1.178E+00, 1.111E+00, 1.037E+00, 9.787E-01, 9.073E-01, 8.541E-01, 8.298E-01, 7.933E-01, 7.530E-01, 7.696E-01, 7.966E-01, 8.582E-01, 9.675E-01, 1.092E+00, 1.266E+00, 1.416E+00, 1.513E+00, 1.557E+00, 1.461E+00, 1.341E+00, 1.135E+00, 9.446E-01, 7.411E-01, 5.572E-01, 4.133E-01, 2.920E-01, 1.992E-01, 1.383E-01, 9.723E-02, 6.830E-02, 5.173E-02, 3.840E-02, 3.008E-02, 2.393E-02, 1.743E-02, 1.259E-02, 1.057E-02, 9.381E-03, 8.891E-03, 8.430E-03, 7.669E-03, 8.314E-03, 8.597E-03, 6.436E-03, 6.161E-03, 5.354E-03, 5.808E-03, 7.759E-03, 4.967E-03}, // TpTp1200.root
     { 1.572E-01, 2.823E+00, 3.055E+00, 2.295E+00, 1.478E+00, 1.373E+00, 1.264E+00, 1.132E+00, 6.411E-01, 1.457E+00, 1.430E+00, 1.465E+00, 1.362E+00, 1.154E+00, 1.093E+00, 1.051E+00, 1.061E+00, 1.118E+00, 1.178E+00, 1.191E+00, 1.207E+00, 1.267E+00, 1.251E+00, 1.274E+00, 1.267E+00, 1.288E+00, 1.274E+00, 1.276E+00, 1.269E+00, 1.253E+00, 1.226E+00, 1.163E+00, 1.108E+00, 1.031E+00, 9.792E-01, 9.190E-01, 8.577E-01, 8.364E-01, 7.998E-01, 7.505E-01, 7.587E-01, 7.996E-01, 8.608E-01, 9.585E-01, 1.094E+00, 1.239E+00, 1.403E+00, 1.476E+00, 1.520E+00, 1.470E+00, 1.327E+00, 1.124E+00, 9.653E-01, 7.601E-01, 5.713E-01, 4.137E-01, 2.874E-01, 1.990E-01, 1.410E-01, 9.522E-02, 6.876E-02, 4.921E-02, 3.726E-02, 2.983E-02, 2.373E-02, 1.658E-02, 1.257E-02, 1.075E-02, 9.609E-03, 8.271E-03, 8.340E-03, 8.770E-03, 7.378E-03, 7.303E-03, 5.912E-03, 5.315E-03, 7.372E-03, 6.092E-03, 5.033E-03, 5.305E-03}, // TpTp1300.root
     { 2.160E-01, 2.263E+00, 1.119E+01, 2.336E+00, 1.736E+00, 1.510E+00, 1.077E+00, 1.176E+00, 7.053E-01, 1.423E+00, 1.569E+00, 1.440E+00, 1.375E+00, 1.159E+00, 1.075E+00, 1.069E+00, 1.062E+00, 1.133E+00, 1.158E+00, 1.204E+00, 1.216E+00, 1.240E+00, 1.263E+00, 1.282E+00, 1.286E+00, 1.287E+00, 1.260E+00, 1.280E+00, 1.266E+00, 1.247E+00, 1.234E+00, 1.178E+00, 1.121E+00, 1.030E+00, 9.682E-01, 9.054E-01, 8.685E-01, 8.296E-01, 7.917E-01, 7.498E-01, 7.487E-01, 7.899E-01, 8.571E-01, 9.687E-01, 1.098E+00, 1.254E+00, 1.410E+00, 1.492E+00, 1.542E+00, 1.455E+00, 1.350E+00, 1.139E+00, 9.516E-01, 7.482E-01, 5.658E-01, 4.106E-01, 2.926E-01, 1.957E-01, 1.395E-01, 9.392E-02, 6.780E-02, 5.034E-02, 3.757E-02, 3.000E-02, 2.382E-02, 1.738E-02, 1.216E-02, 1.105E-02, 9.388E-03, 8.357E-03, 8.885E-03, 8.099E-03, 7.050E-03, 6.724E-03, 6.228E-03, 4.828E-03, 5.222E-03, 5.245E-03, 7.617E-03, 7.289E-03}, // TpTp1400.root
     { 2.423E-01, 4.315E+00, 2.464E+00, 2.864E+00, 1.174E+00, 1.485E+00, 1.268E+00, 1.222E+00, 5.845E-01, 1.453E+00, 1.426E+00, 1.488E+00, 1.321E+00, 1.167E+00, 1.076E+00, 1.052E+00, 1.066E+00, 1.122E+00, 1.151E+00, 1.206E+00, 1.209E+00, 1.239E+00, 1.250E+00, 1.286E+00, 1.282E+00, 1.269E+00, 1.251E+00, 1.263E+00, 1.273E+00, 1.269E+00, 1.204E+00, 1.178E+00, 1.108E+00, 1.043E+00, 9.572E-01, 9.212E-01, 8.694E-01, 8.428E-01, 7.893E-01, 7.578E-01, 7.580E-01, 7.940E-01, 8.664E-01, 9.559E-01, 1.096E+00, 1.248E+00, 1.412E+00, 1.500E+00, 1.509E+00, 1.463E+00, 1.369E+00, 1.149E+00, 9.606E-01, 7.550E-01, 5.693E-01, 4.126E-01, 2.883E-01, 1.976E-01, 1.379E-01, 9.559E-02, 6.876E-02, 5.059E-02, 3.842E-02, 3.008E-02, 2.387E-02, 1.667E-02, 1.304E-02, 1.021E-02, 1.031E-02, 8.361E-03, 8.001E-03, 8.146E-03, 7.446E-03, 8.348E-03, 5.815E-03, 4.387E-03, 4.728E-03, 6.252E-03, 4.515E-03, 5.561E-03}, // TpTp1500.root
     { 1.617E-01, 4.064E+00, 2.742E+00, 2.266E+00, 1.559E+00, 1.377E+00, 1.402E+00, 1.178E+00, 6.902E-01, 1.501E+00, 1.659E+00, 1.587E+00, 1.368E+00, 1.170E+00, 1.114E+00, 1.061E+00, 1.092E+00, 1.130E+00, 1.172E+00, 1.207E+00, 1.183E+00, 1.234E+00, 1.261E+00, 1.254E+00, 1.287E+00, 1.263E+00, 1.272E+00, 1.246E+00, 1.266E+00, 1.262E+00, 1.218E+00, 1.166E+00, 1.121E+00, 1.039E+00, 9.762E-01, 8.993E-01, 8.753E-01, 8.349E-01, 7.893E-01, 7.575E-01, 7.539E-01, 7.984E-01, 8.531E-01, 9.740E-01, 1.119E+00, 1.251E+00, 1.404E+00, 1.488E+00, 1.556E+00, 1.446E+00, 1.355E+00, 1.132E+00, 9.286E-01, 7.537E-01, 5.683E-01, 4.106E-01, 2.881E-01, 1.966E-01, 1.355E-01, 9.763E-02, 6.776E-02, 5.132E-02, 3.890E-02, 2.995E-02, 2.371E-02, 1.746E-02, 1.324E-02, 1.051E-02, 9.834E-03, 8.969E-03, 7.766E-03, 7.762E-03, 8.075E-03, 9.524E-03, 8.243E-03, 5.045E-03, 5.098E-03, 4.711E-03, 4.371E-03, 6.547E-03}, // TpTp1600.root
     { 3.073E-01, 2.023E+00, 2.628E+00, 2.467E+00, 1.432E+00, 1.146E+00, 1.139E+00, 1.750E+00, 5.444E-01, 1.307E+00, 1.464E+00, 1.483E+00, 1.358E+00, 1.188E+00, 1.069E+00, 1.036E+00, 1.110E+00, 1.127E+00, 1.156E+00, 1.209E+00, 1.195E+00, 1.237E+00, 1.262E+00, 1.289E+00, 1.287E+00, 1.264E+00, 1.262E+00, 1.249E+00, 1.281E+00, 1.250E+00, 1.228E+00, 1.186E+00, 1.097E+00, 1.033E+00, 9.705E-01, 9.052E-01, 8.553E-01, 8.536E-01, 7.986E-01, 7.560E-01, 7.652E-01, 8.156E-01, 8.463E-01, 9.698E-01, 1.088E+00, 1.243E+00, 1.417E+00, 1.469E+00, 1.544E+00, 1.439E+00, 1.331E+00, 1.134E+00, 9.276E-01, 7.655E-01, 5.659E-01, 4.075E-01, 2.903E-01, 1.991E-01, 1.353E-01, 9.565E-02, 6.819E-02, 5.082E-02, 3.936E-02, 2.947E-02, 2.426E-02, 1.780E-02, 1.251E-02, 1.031E-02, 1.034E-02, 9.703E-03, 8.115E-03, 7.457E-03, 6.907E-03, 6.714E-03, 5.733E-03, 7.032E-03, 5.893E-03, 4.560E-03, 7.615E-03, 4.148E-03}, // TpTp1700.root
     { 1.575E-01, 2.376E+00, 5.511E+00, 4.140E+00, 2.222E+00, 1.022E+00, 1.414E+00, 1.012E+00, 5.570E-01, 1.627E+00, 1.349E+00, 1.507E+00, 1.347E+00, 1.251E+00, 1.103E+00, 1.054E+00, 1.092E+00, 1.122E+00, 1.182E+00, 1.167E+00, 1.212E+00, 1.234E+00, 1.264E+00, 1.287E+00, 1.260E+00, 1.284E+00, 1.277E+00, 1.250E+00, 1.300E+00, 1.262E+00, 1.246E+00, 1.159E+00, 1.099E+00, 1.041E+00, 9.627E-01, 9.212E-01, 8.749E-01, 8.307E-01, 7.929E-01, 7.360E-01, 7.686E-01, 7.892E-01, 8.466E-01, 9.500E-01, 1.047E+00, 1.288E+00, 1.426E+00, 1.505E+00, 1.517E+00, 1.455E+00, 1.287E+00, 1.121E+00, 9.316E-01, 7.538E-01, 5.805E-01, 4.069E-01, 2.963E-01, 1.982E-01, 1.402E-01, 9.389E-02, 6.983E-02, 5.031E-02, 3.893E-02, 3.000E-02, 2.573E-02, 1.678E-02, 1.244E-02, 1.088E-02, 9.356E-03, 8.698E-03, 8.022E-03, 6.875E-03, 1.100E-02, 9.955E-03, 7.337E-03, 4.677E-03, 6.427E-03, 6.148E-03, 8.214E-03, 3.827E-03}, // TpTp1800.root
     { 1.870E-01, 4.744E+00, 3.217E+00, 2.383E+00, 1.802E+00, 1.486E+00, 1.329E+00, 1.205E+00, 6.102E-01, 1.495E+00, 1.516E+00, 1.478E+00, 1.319E+00, 1.164E+00, 1.076E+00, 1.050E+00, 1.080E+00, 1.130E+00, 1.165E+00, 1.189E+00, 1.212E+00, 1.236E+00, 1.258E+00, 1.271E+00, 1.271E+00, 1.272E+00, 1.272E+00, 1.268E+00, 1.277E+00, 1.253E+00, 1.221E+00, 1.169E+00, 1.109E+00, 1.039E+00, 9.688E-01, 9.133E-01, 8.658E-01, 8.371E-01, 7.900E-01, 7.512E-01, 7.587E-01, 7.925E-01, 8.574E-01, 9.586E-01, 1.093E+00, 1.257E+00, 1.420E+00, 1.493E+00, 1.527E+00, 1.462E+00, 1.338E+00, 1.155E+00, 9.495E-01, 7.493E-01, 5.703E-01, 4.107E-01, 2.901E-01, 1.994E-01, 1.376E-01, 9.651E-02, 6.895E-02, 5.073E-02, 3.841E-02, 2.999E-02, 2.412E-02, 1.701E-02, 1.244E-02, 1.072E-02, 9.630E-03, 8.829E-03, 8.312E-03, 8.101E-03, 7.724E-03, 7.905E-03, 6.299E-03, 5.287E-03, 5.476E-03, 5.776E-03, 5.866E-03, 6.320E-03}, // WJ1200.root
     { 1.913E-01, 4.255E+00, 3.444E+00, 2.481E+00, 1.640E+00, 1.531E+00, 1.288E+00, 1.270E+00, 5.997E-01, 1.442E+00, 1.477E+00, 1.476E+00, 1.330E+00, 1.169E+00, 1.083E+00, 1.051E+00, 1.078E+00, 1.126E+00, 1.166E+00, 1.188E+00, 1.211E+00, 1.238E+00, 1.256E+00, 1.271E+00, 1.273E+00, 1.274E+00, 1.271E+00, 1.267E+00, 1.274E+00, 1.254E+00, 1.220E+00, 1.167E+00, 1.113E+00, 1.037E+00, 9.688E-01, 9.129E-01, 8.681E-01, 8.336E-01, 7.865E-01, 7.516E-01, 7.576E-01, 7.948E-01, 8.593E-01, 9.561E-01, 1.097E+00, 1.258E+00, 1.421E+00, 1.492E+00, 1.534E+00, 1.461E+00, 1.341E+00, 1.156E+00, 9.519E-01, 7.507E-01, 5.693E-01, 4.101E-01, 2.896E-01, 1.981E-01, 1.374E-01, 9.658E-02, 6.937E-02, 5.074E-02, 3.867E-02, 2.989E-02, 2.413E-02, 1.713E-02, 1.250E-02, 1.076E-02, 9.502E-03, 8.767E-03, 8.258E-03, 8.063E-03, 7.855E-03, 7.777E-03, 6.306E-03, 5.442E-03, 5.528E-03, 5.516E-03, 6.168E-03, 5.712E-03}, // WJ200.root
     { 1.898E-01, 4.165E+00, 3.239E+00, 2.648E+00, 1.610E+00, 1.494E+00, 1.289E+00, 1.238E+00, 6.235E-01, 1.438E+00, 1.486E+00, 1.484E+00, 1.339E+00, 1.165E+00, 1.076E+00, 1.050E+00, 1.080E+00, 1.129E+00, 1.168E+00, 1.188E+00, 1.213E+00, 1.239E+00, 1.262E+00, 1.272E+00, 1.272E+00, 1.269E+00, 1.273E+00, 1.266E+00, 1.276E+00, 1.250E+00, 1.221E+00, 1.171E+00, 1.110E+00, 1.038E+00, 9.687E-01, 9.137E-01, 8.687E-01, 8.352E-01, 7.870E-01, 7.480E-01, 7.602E-01, 7.922E-01, 8.591E-01, 9.607E-01, 1.091E+00, 1.255E+00, 1.415E+00, 1.496E+00, 1.528E+00, 1.460E+00, 1.339E+00, 1.154E+00, 9.493E-01, 7.497E-01, 5.703E-01, 4.105E-01, 2.896E-01, 1.985E-01, 1.373E-01, 9.672E-02, 6.940E-02, 5.067E-02, 3.834E-02, 3.009E-02, 2.403E-02, 1.718E-02, 1.255E-02, 1.087E-02, 9.529E-03, 8.865E-03, 8.370E-03, 7.970E-03, 7.921E-03, 7.850E-03, 6.155E-03, 5.393E-03, 5.518E-03, 5.859E-03, 5.714E-03, 6.418E-03}, // WJ2500.root
     { 1.897E-01, 3.957E+00, 3.856E+00, 2.684E+00, 1.643E+00, 1.480E+00, 1.304E+00, 1.284E+00, 6.124E-01, 1.434E+00, 1.497E+00, 1.483E+00, 1.326E+00, 1.166E+00, 1.080E+00, 1.051E+00, 1.074E+00, 1.126E+00, 1.163E+00, 1.187E+00, 1.212E+00, 1.238E+00, 1.260E+00, 1.268E+00, 1.274E+00, 1.274E+00, 1.270E+00, 1.269E+00, 1.277E+00, 1.252E+00, 1.224E+00, 1.171E+00, 1.110E+00, 1.038E+00, 9.698E-01, 9.114E-01, 8.652E-01, 8.348E-01, 7.895E-01, 7.498E-01, 7.574E-01, 7.921E-01, 8.594E-01, 9.566E-01, 1.096E+00, 1.260E+00, 1.419E+00, 1.496E+00, 1.534E+00, 1.465E+00, 1.340E+00, 1.157E+00, 9.516E-01, 7.506E-01, 5.693E-01, 4.110E-01, 2.894E-01, 1.974E-01, 1.380E-01, 9.660E-02, 6.948E-02, 5.088E-02, 3.837E-02, 2.965E-02, 2.417E-02, 1.699E-02, 1.248E-02, 1.080E-02, 9.539E-03, 8.775E-03, 8.265E-03, 8.058E-03, 7.837E-03, 7.898E-03, 6.202E-03, 5.428E-03, 5.554E-03, 5.352E-03, 5.705E-03, 6.037E-03}, // WJ400.root
     { 1.899E-01, 3.543E+00, 3.519E+00, 2.642E+00, 1.581E+00, 1.495E+00, 1.296E+00, 1.289E+00, 6.150E-01, 1.486E+00, 1.474E+00, 1.479E+00, 1.324E+00, 1.167E+00, 1.074E+00, 1.054E+00, 1.080E+00, 1.133E+00, 1.165E+00, 1.186E+00, 1.215E+00, 1.238E+00, 1.261E+00, 1.271E+00, 1.273E+00, 1.274E+00, 1.268E+00, 1.265E+00, 1.274E+00, 1.253E+00, 1.223E+00, 1.171E+00, 1.109E+00, 1.036E+00, 9.682E-01, 9.106E-01, 8.671E-01, 8.343E-01, 7.894E-01, 7.523E-01, 7.561E-01, 7.949E-01, 8.588E-01, 9.588E-01, 1.095E+00, 1.253E+00, 1.420E+00, 1.494E+00, 1.534E+00, 1.461E+00, 1.336E+00, 1.154E+00, 9.528E-01, 7.531E-01, 5.697E-01, 4.117E-01, 2.903E-01, 1.985E-01, 1.375E-01, 9.617E-02, 6.911E-02, 5.078E-02, 3.842E-02, 2.983E-02, 2.402E-02, 1.707E-02, 1.242E-02, 1.086E-02, 9.659E-03, 8.759E-03, 8.298E-03, 8.003E-03, 7.673E-03, 7.920E-03, 6.423E-03, 5.314E-03, 5.516E-03, 5.349E-03, 5.832E-03, 5.663E-03}, // WJ600.root
     { 1.711E-01, 3.600E+00, 3.097E+00, 2.605E+00, 1.589E+00, 1.439E+00, 1.297E+00, 1.250E+00, 6.091E-01, 1.445E+00, 1.499E+00, 1.471E+00, 1.332E+00, 1.165E+00, 1.075E+00, 1.055E+00, 1.080E+00, 1.127E+00, 1.166E+00, 1.190E+00, 1.212E+00, 1.240E+00, 1.261E+00, 1.271E+00, 1.275E+00, 1.275E+00, 1.271E+00, 1.265E+00, 1.274E+00, 1.250E+00, 1.222E+00, 1.170E+00, 1.106E+00, 1.038E+00, 9.693E-01, 9.130E-01, 8.674E-01, 8.346E-01, 7.890E-01, 7.505E-01, 7.591E-01, 7.919E-01, 8.587E-01, 9.597E-01, 1.092E+00, 1.260E+00, 1.417E+00, 1.489E+00, 1.528E+00, 1.462E+00, 1.335E+00, 1.156E+00, 9.473E-01, 7.489E-01, 5.693E-01, 4.120E-01, 2.903E-01, 1.985E-01, 1.383E-01, 9.635E-02, 6.923E-02, 5.101E-02, 3.853E-02, 2.984E-02, 2.410E-02, 1.704E-02, 1.249E-02, 1.076E-02, 9.659E-03, 8.827E-03, 8.296E-03, 7.973E-03, 7.932E-03, 8.048E-03, 6.384E-03, 5.142E-03, 5.646E-03, 5.484E-03, 5.501E-03, 6.078E-03} // WJ800.root
   };

   pileupweightDn = { // 69.2 - 4.6%
     { 2.964E-04, 4.867E-02, 6.284E-02, 6.202E-02, 7.567E-02, 1.268E-01, 1.384E-01, 1.958E-01, 1.665E-01, 5.472E-01, 7.142E-01, 8.790E-01, 9.067E-01, 9.409E-01, 9.795E-01, 1.100E+00, 1.176E+00, 1.276E+00, 1.326E+00, 1.354E+00, 1.388E+00, 1.403E+00, 1.429E+00, 1.453E+00, 1.453E+00, 1.467E+00, 1.443E+00, 1.421E+00, 1.400E+00, 1.354E+00, 1.299E+00, 1.213E+00, 1.120E+00, 1.035E+00, 9.561E-01, 8.881E-01, 8.437E-01, 8.165E-01, 7.802E-01, 7.657E-01, 8.014E-01, 8.916E-01, 1.022E+00, 1.185E+00, 1.355E+00, 1.493E+00, 1.596E+00, 1.514E+00, 1.409E+00, 1.203E+00, 9.275E-01, 7.324E-01, 5.311E-01, 3.636E-01, 2.499E-01, 1.626E-01, 1.038E-01, 6.701E-02, 4.331E-02, 2.848E-02, 1.901E-02, 1.358E-02, 1.009E-02, 7.522E-03, 5.775E-03, 4.256E-03, 3.079E-03, 2.558E-03, 2.538E-03, 2.145E-03, 1.999E-03, 1.352E-03, 1.613E-03, 1.450E-03, 6.862E-04, 6.135E-04, 4.263E-04, 3.482E-04, 1.501E-04, 7.989E-05}, // DYJetsMG.root
     { 3.706E-04, 4.424E-02, 5.904E-02, 7.542E-02, 1.054E-01, 1.223E-01, 1.593E-01, 2.719E-01, 1.845E-01, 6.325E-01, 8.076E-01, 9.257E-01, 8.799E-01, 9.334E-01, 1.028E+00, 1.084E+00, 1.194E+00, 1.258E+00, 1.301E+00, 1.338E+00, 1.365E+00, 1.405E+00, 1.415E+00, 1.441E+00, 1.449E+00, 1.453E+00, 1.433E+00, 1.406E+00, 1.398E+00, 1.342E+00, 1.275E+00, 1.192E+00, 1.118E+00, 1.028E+00, 9.414E-01, 8.831E-01, 8.355E-01, 8.046E-01, 7.687E-01, 7.617E-01, 7.999E-01, 8.860E-01, 1.004E+00, 1.158E+00, 1.337E+00, 1.494E+00, 1.594E+00, 1.533E+00, 1.419E+00, 1.206E+00, 9.159E-01, 7.274E-01, 5.183E-01, 3.703E-01, 2.500E-01, 1.618E-01, 1.045E-01, 6.636E-02, 4.327E-02, 2.843E-02, 1.935E-02, 1.352E-02, 1.008E-02, 7.599E-03, 5.830E-03, 4.268E-03, 2.985E-03, 2.556E-03, 2.398E-03, 2.256E-03, 1.977E-03, 1.355E-03, 1.583E-03, 1.505E-03, 9.021E-04, 1.016E-03, 5.155E-04, 3.486E-04, 2.718E-04, 1.131E-04}, // QCD1000.root
     { 1.829E-01, 4.616E+00, 4.516E+00, 2.588E+00, 1.910E+00, 1.645E+00, 1.309E+00, 1.397E+00, 8.664E-01, 2.115E+00, 2.187E+00, 2.072E+00, 1.732E+00, 1.530E+00, 1.441E+00, 1.418E+00, 1.435E+00, 1.431E+00, 1.420E+00, 1.409E+00, 1.393E+00, 1.391E+00, 1.385E+00, 1.392E+00, 1.393E+00, 1.382E+00, 1.362E+00, 1.330E+00, 1.311E+00, 1.256E+00, 1.202E+00, 1.126E+00, 1.045E+00, 9.534E-01, 8.791E-01, 8.165E-01, 7.750E-01, 7.459E-01, 7.143E-01, 7.043E-01, 7.482E-01, 8.259E-01, 9.425E-01, 1.087E+00, 1.250E+00, 1.392E+00, 1.480E+00, 1.435E+00, 1.321E+00, 1.131E+00, 9.092E-01, 6.908E-01, 5.041E-01, 3.512E-01, 2.393E-01, 1.562E-01, 9.963E-02, 6.334E-02, 4.093E-02, 2.721E-02, 1.848E-02, 1.303E-02, 9.626E-03, 7.324E-03, 5.850E-03, 4.162E-03, 3.080E-03, 2.689E-03, 2.429E-03, 2.276E-03, 2.099E-03, 2.097E-03, 2.012E-03, 1.962E-03, 1.549E-03, 1.277E-03, 1.320E-03, 1.382E-03, 1.342E-03, 1.297E-03}, // QCD1500.root
     { 1.749E-01, 4.427E+00, 4.718E+00, 2.463E+00, 1.739E+00, 1.665E+00, 1.352E+00, 1.389E+00, 8.727E-01, 2.163E+00, 2.187E+00, 2.068E+00, 1.751E+00, 1.544E+00, 1.446E+00, 1.419E+00, 1.435E+00, 1.431E+00, 1.426E+00, 1.398E+00, 1.384E+00, 1.386E+00, 1.390E+00, 1.394E+00, 1.389E+00, 1.381E+00, 1.360E+00, 1.329E+00, 1.312E+00, 1.256E+00, 1.198E+00, 1.119E+00, 1.042E+00, 9.549E-01, 8.777E-01, 8.212E-01, 7.718E-01, 7.483E-01, 7.155E-01, 7.050E-01, 7.501E-01, 8.273E-01, 9.436E-01, 1.094E+00, 1.250E+00, 1.391E+00, 1.488E+00, 1.452E+00, 1.329E+00, 1.123E+00, 9.133E-01, 6.914E-01, 5.007E-01, 3.537E-01, 2.381E-01, 1.551E-01, 9.969E-02, 6.369E-02, 4.099E-02, 2.703E-02, 1.843E-02, 1.307E-02, 9.621E-03, 7.340E-03, 5.899E-03, 4.117E-03, 3.069E-03, 2.690E-03, 2.478E-03, 2.218E-03, 2.144E-03, 2.139E-03, 1.968E-03, 1.994E-03, 1.501E-03, 1.244E-03, 1.324E-03, 1.251E-03, 1.460E-03, 1.152E-03}, // QCD2000.root
     { 2.884E-04, 3.296E-02, 5.845E-02, 7.139E-02, 7.909E-02, 1.244E-01, 1.357E-01, 1.738E-01, 1.527E-01, 4.953E-01, 7.321E-01, 8.905E-01, 8.773E-01, 9.319E-01, 9.842E-01, 1.082E+00, 1.199E+00, 1.267E+00, 1.325E+00, 1.359E+00, 1.379E+00, 1.410E+00, 1.437E+00, 1.451E+00, 1.467E+00, 1.459E+00, 1.448E+00, 1.419E+00, 1.402E+00, 1.355E+00, 1.298E+00, 1.203E+00, 1.122E+00, 1.040E+00, 9.555E-01, 8.915E-01, 8.447E-01, 8.109E-01, 7.754E-01, 7.657E-01, 8.104E-01, 8.976E-01, 1.018E+00, 1.188E+00, 1.357E+00, 1.504E+00, 1.599E+00, 1.517E+00, 1.405E+00, 1.195E+00, 9.501E-01, 7.210E-01, 5.271E-01, 3.662E-01, 2.514E-01, 1.614E-01, 1.050E-01, 6.677E-02, 4.332E-02, 2.872E-02, 1.940E-02, 1.367E-02, 9.998E-03, 7.483E-03, 5.596E-03, 4.265E-03, 3.077E-03, 2.698E-03, 2.264E-03, 2.245E-03, 1.874E-03, 1.608E-03, 1.325E-03, 1.621E-03, 8.798E-04, 9.400E-04, 5.954E-04, 3.166E-04, 2.206E-04, 1.052E-04}, // QCD300.root
     { 2.608E-04, 3.494E-02, 5.037E-02, 5.574E-02, 8.287E-02, 1.245E-01, 1.044E-01, 1.455E-01, 1.566E-01, 4.788E-01, 7.026E-01, 8.616E-01, 8.502E-01, 9.351E-01, 9.723E-01, 1.062E+00, 1.195E+00, 1.286E+00, 1.336E+00, 1.358E+00, 1.391E+00, 1.403E+00, 1.439E+00, 1.464E+00, 1.473E+00, 1.472E+00, 1.449E+00, 1.432E+00, 1.405E+00, 1.356E+00, 1.305E+00, 1.210E+00, 1.130E+00, 1.040E+00, 9.592E-01, 8.862E-01, 8.476E-01, 8.168E-01, 7.815E-01, 7.683E-01, 8.100E-01, 9.000E-01, 1.031E+00, 1.190E+00, 1.354E+00, 1.501E+00, 1.610E+00, 1.552E+00, 1.415E+00, 1.211E+00, 9.448E-01, 7.341E-01, 5.295E-01, 3.696E-01, 2.510E-01, 1.648E-01, 1.057E-01, 6.661E-02, 4.350E-02, 2.842E-02, 1.958E-02, 1.371E-02, 1.010E-02, 7.380E-03, 5.807E-03, 4.279E-03, 3.047E-03, 2.733E-03, 2.499E-03, 2.143E-03, 1.810E-03, 1.313E-03, 1.512E-03, 1.121E-03, 7.844E-04, 9.596E-04, 5.457E-04, 5.389E-04, 2.457E-04, 1.112E-04}, // QCD500.root
     { 3.096E-04, 5.157E-02, 6.708E-02, 7.576E-02, 8.816E-02, 1.292E-01, 1.443E-01, 1.790E-01, 1.875E-01, 6.075E-01, 7.457E-01, 9.389E-01, 9.295E-01, 9.294E-01, 1.008E+00, 1.108E+00, 1.195E+00, 1.263E+00, 1.322E+00, 1.352E+00, 1.374E+00, 1.393E+00, 1.424E+00, 1.445E+00, 1.460E+00, 1.448E+00, 1.443E+00, 1.418E+00, 1.385E+00, 1.344E+00, 1.290E+00, 1.206E+00, 1.116E+00, 1.036E+00, 9.476E-01, 8.792E-01, 8.396E-01, 8.122E-01, 7.737E-01, 7.648E-01, 8.043E-01, 8.983E-01, 1.018E+00, 1.180E+00, 1.350E+00, 1.497E+00, 1.597E+00, 1.538E+00, 1.425E+00, 1.198E+00, 9.490E-01, 7.206E-01, 5.338E-01, 3.676E-01, 2.479E-01, 1.616E-01, 1.040E-01, 6.641E-02, 4.295E-02, 2.850E-02, 1.971E-02, 1.355E-02, 1.005E-02, 7.210E-03, 5.699E-03, 4.217E-03, 3.202E-03, 2.709E-03, 2.326E-03, 2.140E-03, 1.853E-03, 1.279E-03, 1.337E-03, 1.220E-03, 6.467E-04, 8.795E-04, 5.865E-04, 5.374E-04, 1.449E-04, 1.350E-04}, // QCD700.root
     { 3.027E-04, 4.823E-02, 6.540E-02, 6.682E-02, 9.383E-02, 1.611E-01, 1.465E-01, 1.658E-01, 1.501E-01, 5.078E-01, 6.672E-01, 8.632E-01, 9.054E-01, 8.810E-01, 9.086E-01, 1.087E+00, 1.100E+00, 1.264E+00, 1.313E+00, 1.338E+00, 1.370E+00, 1.367E+00, 1.428E+00, 1.453E+00, 1.446E+00, 1.466E+00, 1.457E+00, 1.415E+00, 1.396E+00, 1.345E+00, 1.289E+00, 1.214E+00, 1.114E+00, 1.041E+00, 9.582E-01, 8.989E-01, 8.520E-01, 8.115E-01, 7.822E-01, 7.704E-01, 8.214E-01, 8.962E-01, 1.032E+00, 1.202E+00, 1.368E+00, 1.512E+00, 1.578E+00, 1.576E+00, 1.377E+00, 1.188E+00, 9.508E-01, 7.416E-01, 5.306E-01, 3.755E-01, 2.485E-01, 1.619E-01, 1.067E-01, 6.829E-02, 4.343E-02, 2.854E-02, 1.928E-02, 1.380E-02, 1.025E-02, 7.460E-03, 6.012E-03, 4.295E-03, 3.185E-03, 2.663E-03, 2.386E-03, 2.406E-03, 1.975E-03, 1.156E-03, 7.917E-04, 1.693E-03, 7.626E-04, 4.564E-04, 4.586E-04, 1.325E-03, 3.430E-04, 7.954E-05}, // STs.root
     { 1.882E-01, 3.952E+00, 4.224E+00, 2.418E+00, 1.829E+00, 1.699E+00, 1.314E+00, 1.382E+00, 9.023E-01, 2.183E+00, 2.173E+00, 2.075E+00, 1.741E+00, 1.535E+00, 1.435E+00, 1.416E+00, 1.437E+00, 1.432E+00, 1.421E+00, 1.408E+00, 1.394E+00, 1.389E+00, 1.388E+00, 1.392E+00, 1.394E+00, 1.383E+00, 1.361E+00, 1.329E+00, 1.310E+00, 1.258E+00, 1.202E+00, 1.125E+00, 1.043E+00, 9.528E-01, 8.783E-01, 8.167E-01, 7.748E-01, 7.456E-01, 7.154E-01, 7.046E-01, 7.461E-01, 8.281E-01, 9.425E-01, 1.088E+00, 1.246E+00, 1.391E+00, 1.484E+00, 1.437E+00, 1.320E+00, 1.131E+00, 9.091E-01, 6.931E-01, 5.024E-01, 3.515E-01, 2.387E-01, 1.556E-01, 1.002E-01, 6.345E-02, 4.110E-02, 2.708E-02, 1.851E-02, 1.309E-02, 9.572E-03, 7.335E-03, 5.861E-03, 4.121E-03, 3.055E-03, 2.684E-03, 2.437E-03, 2.265E-03, 2.138E-03, 2.080E-03, 2.012E-03, 2.015E-03, 1.519E-03, 1.305E-03, 1.288E-03, 1.220E-03, 1.309E-03, 1.312E-03}, // STt.root
     { 1.861E-01, 5.669E+00, 4.357E+00, 2.661E+00, 1.765E+00, 1.675E+00, 1.338E+00, 1.397E+00, 9.253E-01, 2.115E+00, 2.179E+00, 2.085E+00, 1.720E+00, 1.526E+00, 1.441E+00, 1.413E+00, 1.431E+00, 1.433E+00, 1.428E+00, 1.408E+00, 1.395E+00, 1.390E+00, 1.389E+00, 1.391E+00, 1.393E+00, 1.379E+00, 1.354E+00, 1.328E+00, 1.308E+00, 1.259E+00, 1.200E+00, 1.128E+00, 1.044E+00, 9.562E-01, 8.764E-01, 8.183E-01, 7.755E-01, 7.473E-01, 7.162E-01, 7.012E-01, 7.472E-01, 8.279E-01, 9.409E-01, 1.091E+00, 1.249E+00, 1.394E+00, 1.482E+00, 1.443E+00, 1.327E+00, 1.125E+00, 9.143E-01, 6.918E-01, 5.023E-01, 3.499E-01, 2.393E-01, 1.558E-01, 9.969E-02, 6.328E-02, 4.116E-02, 2.711E-02, 1.844E-02, 1.301E-02, 9.584E-03, 7.374E-03, 5.835E-03, 4.168E-03, 3.068E-03, 2.685E-03, 2.429E-03, 2.274E-03, 2.136E-03, 2.109E-03, 1.974E-03, 1.993E-03, 1.616E-03, 1.317E-03, 1.284E-03, 1.350E-03, 1.208E-03, 1.168E-03}, // STtb.root
     { 2.724E-04, 2.910E-02, 4.802E-02, 4.626E-02, 8.848E-02, 1.467E-01, 9.702E-02, 1.141E-01, 1.559E-01, 5.990E-01, 6.398E-01, 8.527E-01, 8.980E-01, 9.351E-01, 9.676E-01, 1.088E+00, 1.170E+00, 1.258E+00, 1.306E+00, 1.342E+00, 1.361E+00, 1.409E+00, 1.442E+00, 1.466E+00, 1.453E+00, 1.469E+00, 1.466E+00, 1.449E+00, 1.407E+00, 1.364E+00, 1.313E+00, 1.204E+00, 1.136E+00, 1.042E+00, 9.655E-01, 8.901E-01, 8.390E-01, 8.224E-01, 7.747E-01, 7.688E-01, 8.242E-01, 8.990E-01, 1.030E+00, 1.198E+00, 1.377E+00, 1.496E+00, 1.638E+00, 1.563E+00, 1.406E+00, 1.200E+00, 9.532E-01, 7.279E-01, 5.302E-01, 3.698E-01, 2.485E-01, 1.665E-01, 1.064E-01, 6.664E-02, 4.255E-02, 2.909E-02, 1.965E-02, 1.318E-02, 9.869E-03, 7.707E-03, 5.750E-03, 4.200E-03, 3.087E-03, 2.716E-03, 2.562E-03, 2.393E-03, 1.548E-03, 9.258E-04, 1.153E-03, 1.225E-03, 1.526E-03, 1.053E-03, 3.162E-04, 9.623E-04, 1.145E-04, 1.587E-04}, // STtWt.root
     { 2.726E-04, 2.459E-02, 5.699E-02, 5.467E-02, 8.803E-02, 1.068E-01, 1.066E-01, 2.151E-01, 1.894E-01, 4.913E-01, 7.596E-01, 9.469E-01, 8.635E-01, 8.723E-01, 9.673E-01, 1.064E+00, 1.220E+00, 1.275E+00, 1.340E+00, 1.370E+00, 1.386E+00, 1.422E+00, 1.423E+00, 1.455E+00, 1.466E+00, 1.455E+00, 1.453E+00, 1.416E+00, 1.420E+00, 1.361E+00, 1.309E+00, 1.195E+00, 1.139E+00, 1.043E+00, 9.499E-01, 8.964E-01, 8.492E-01, 8.125E-01, 7.795E-01, 7.692E-01, 8.244E-01, 9.120E-01, 1.036E+00, 1.182E+00, 1.360E+00, 1.486E+00, 1.594E+00, 1.512E+00, 1.380E+00, 1.209E+00, 9.299E-01, 7.231E-01, 5.403E-01, 3.734E-01, 2.532E-01, 1.621E-01, 1.073E-01, 6.661E-02, 4.350E-02, 2.895E-02, 1.973E-02, 1.292E-02, 1.026E-02, 7.570E-03, 5.235E-03, 4.214E-03, 3.207E-03, 2.655E-03, 2.310E-03, 2.078E-03, 1.729E-03, 1.372E-03, 1.023E-03, 2.139E-03, 4.824E-04, 1.200E-03, 7.006E-04, 8.612E-04, 1.296E-04, 5.305E-05}, // STtWtb.root
     { 2.516E-04, 3.745E-02, 4.667E-02, 5.252E-02, 7.168E-02, 1.066E-01, 1.302E-01, 1.573E-01, 1.540E-01, 4.744E-01, 6.952E-01, 8.614E-01, 8.888E-01, 9.401E-01, 9.903E-01, 1.076E+00, 1.190E+00, 1.277E+00, 1.331E+00, 1.355E+00, 1.387E+00, 1.404E+00, 1.439E+00, 1.457E+00, 1.471E+00, 1.465E+00, 1.449E+00, 1.430E+00, 1.409E+00, 1.364E+00, 1.303E+00, 1.211E+00, 1.128E+00, 1.043E+00, 9.595E-01, 8.935E-01, 8.486E-01, 8.159E-01, 7.820E-01, 7.734E-01, 8.135E-01, 9.032E-01, 1.026E+00, 1.186E+00, 1.363E+00, 1.517E+00, 1.621E+00, 1.539E+00, 1.408E+00, 1.210E+00, 9.588E-01, 7.298E-01, 5.315E-01, 3.701E-01, 2.522E-01, 1.626E-01, 1.045E-01, 6.743E-02, 4.363E-02, 2.869E-02, 1.967E-02, 1.385E-02, 1.012E-02, 7.401E-03, 5.868E-03, 4.263E-03, 3.086E-03, 2.695E-03, 2.405E-03, 2.242E-03, 1.930E-03, 1.526E-03, 1.380E-03, 1.313E-03, 1.034E-03, 7.494E-04, 4.397E-04, 3.871E-04, 2.014E-04, 1.118E-04}, // TThad.root
     { 2.433E-04, 3.083E-02, 4.356E-02, 4.868E-02, 7.199E-02, 1.111E-01, 1.120E-01, 1.615E-01, 1.504E-01, 4.638E-01, 6.765E-01, 8.507E-01, 8.766E-01, 9.189E-01, 9.942E-01, 1.101E+00, 1.207E+00, 1.297E+00, 1.343E+00, 1.368E+00, 1.393E+00, 1.414E+00, 1.443E+00, 1.464E+00, 1.479E+00, 1.470E+00, 1.448E+00, 1.427E+00, 1.412E+00, 1.360E+00, 1.304E+00, 1.216E+00, 1.126E+00, 1.042E+00, 9.624E-01, 8.965E-01, 8.479E-01, 8.166E-01, 7.822E-01, 7.706E-01, 8.146E-01, 9.020E-01, 1.038E+00, 1.189E+00, 1.364E+00, 1.507E+00, 1.608E+00, 1.537E+00, 1.415E+00, 1.218E+00, 9.548E-01, 7.261E-01, 5.290E-01, 3.691E-01, 2.511E-01, 1.628E-01, 1.050E-01, 6.726E-02, 4.356E-02, 2.873E-02, 1.960E-02, 1.382E-02, 1.011E-02, 7.537E-03, 5.685E-03, 4.266E-03, 3.114E-03, 2.716E-03, 2.361E-03, 2.300E-03, 2.039E-03, 1.256E-03, 1.565E-03, 1.252E-03, 8.515E-04, 6.450E-04, 5.424E-04, 4.641E-04, 2.322E-04, 1.153E-04}, // TT1L.root
     { 2.434E-04, 3.418E-02, 5.431E-02, 4.657E-02, 6.896E-02, 1.070E-01, 1.101E-01, 1.798E-01, 1.662E-01, 4.622E-01, 6.978E-01, 8.373E-01, 8.649E-01, 9.050E-01, 9.629E-01, 1.078E+00, 1.188E+00, 1.271E+00, 1.324E+00, 1.359E+00, 1.398E+00, 1.413E+00, 1.438E+00, 1.471E+00, 1.478E+00, 1.476E+00, 1.463E+00, 1.433E+00, 1.422E+00, 1.364E+00, 1.312E+00, 1.219E+00, 1.131E+00, 1.040E+00, 9.600E-01, 8.953E-01, 8.531E-01, 8.222E-01, 7.845E-01, 7.730E-01, 8.171E-01, 9.037E-01, 1.029E+00, 1.193E+00, 1.362E+00, 1.506E+00, 1.610E+00, 1.530E+00, 1.408E+00, 1.210E+00, 9.511E-01, 7.311E-01, 5.247E-01, 3.677E-01, 2.513E-01, 1.613E-01, 1.062E-01, 6.711E-02, 4.368E-02, 2.868E-02, 1.943E-02, 1.380E-02, 1.007E-02, 7.354E-03, 5.625E-03, 4.359E-03, 3.111E-03, 2.617E-03, 2.409E-03, 2.177E-03, 2.065E-03, 1.631E-03, 1.560E-03, 1.434E-03, 7.085E-04, 7.542E-04, 5.592E-04, 3.329E-04, 2.876E-04, 1.020E-04}, // TT2L.root
     { 1.912E-01, 3.962E+00, 4.766E+00, 2.427E+00, 1.849E+00, 1.704E+00, 1.307E+00, 1.416E+00, 8.888E-01, 2.183E+00, 2.190E+00, 2.046E+00, 1.751E+00, 1.533E+00, 1.431E+00, 1.425E+00, 1.424E+00, 1.431E+00, 1.427E+00, 1.405E+00, 1.392E+00, 1.389E+00, 1.391E+00, 1.394E+00, 1.391E+00, 1.381E+00, 1.359E+00, 1.329E+00, 1.309E+00, 1.255E+00, 1.204E+00, 1.123E+00, 1.044E+00, 9.567E-01, 8.770E-01, 8.179E-01, 7.737E-01, 7.483E-01, 7.181E-01, 7.033E-01, 7.458E-01, 8.269E-01, 9.437E-01, 1.085E+00, 1.252E+00, 1.390E+00, 1.483E+00, 1.440E+00, 1.324E+00, 1.126E+00, 9.113E-01, 6.907E-01, 5.010E-01, 3.527E-01, 2.385E-01, 1.554E-01, 1.001E-01, 6.362E-02, 4.087E-02, 2.718E-02, 1.847E-02, 1.304E-02, 9.610E-03, 7.325E-03, 5.866E-03, 4.170E-03, 3.067E-03, 2.695E-03, 2.432E-03, 2.255E-03, 2.125E-03, 2.049E-03, 2.029E-03, 1.986E-03, 1.542E-03, 1.308E-03, 1.266E-03, 1.333E-03, 1.273E-03, 1.205E-03}, // TTMtt1000.root
     { 2.682E-04, 4.244E-02, 3.991E-02, 5.145E-02, 7.820E-02, 1.047E-01, 1.310E-01, 1.663E-01, 1.492E-01, 5.026E-01, 6.844E-01, 8.478E-01, 8.997E-01, 9.133E-01, 9.995E-01, 1.119E+00, 1.204E+00, 1.265E+00, 1.336E+00, 1.352E+00, 1.382E+00, 1.415E+00, 1.441E+00, 1.461E+00, 1.473E+00, 1.459E+00, 1.443E+00, 1.427E+00, 1.408E+00, 1.362E+00, 1.304E+00, 1.219E+00, 1.126E+00, 1.039E+00, 9.529E-01, 8.922E-01, 8.467E-01, 8.188E-01, 7.780E-01, 7.674E-01, 8.178E-01, 9.013E-01, 1.030E+00, 1.187E+00, 1.364E+00, 1.510E+00, 1.602E+00, 1.551E+00, 1.406E+00, 1.217E+00, 9.459E-01, 7.194E-01, 5.331E-01, 3.652E-01, 2.503E-01, 1.588E-01, 1.046E-01, 6.720E-02, 4.339E-02, 2.861E-02, 1.942E-02, 1.385E-02, 1.013E-02, 7.519E-03, 5.590E-03, 4.182E-03, 3.074E-03, 2.788E-03, 2.464E-03, 2.008E-03, 2.120E-03, 1.481E-03, 1.149E-03, 1.517E-03, 5.850E-04, 5.990E-04, 3.923E-04, 5.477E-04, 3.548E-04, 8.395E-05}, // TTMtt700.root
     { 1.858E-01, 4.593E+00, 4.089E+00, 2.441E+00, 1.927E+00, 1.645E+00, 1.371E+00, 1.396E+00, 8.927E-01, 2.148E+00, 2.192E+00, 2.057E+00, 1.745E+00, 1.540E+00, 1.435E+00, 1.424E+00, 1.427E+00, 1.432E+00, 1.419E+00, 1.404E+00, 1.390E+00, 1.392E+00, 1.388E+00, 1.391E+00, 1.392E+00, 1.382E+00, 1.365E+00, 1.331E+00, 1.307E+00, 1.256E+00, 1.200E+00, 1.128E+00, 1.042E+00, 9.551E-01, 8.774E-01, 8.157E-01, 7.746E-01, 7.475E-01, 7.162E-01, 7.050E-01, 7.478E-01, 8.259E-01, 9.466E-01, 1.087E+00, 1.249E+00, 1.393E+00, 1.482E+00, 1.434E+00, 1.316E+00, 1.126E+00, 9.101E-01, 6.921E-01, 5.016E-01, 3.519E-01, 2.392E-01, 1.559E-01, 1.003E-01, 6.331E-02, 4.108E-02, 2.709E-02, 1.842E-02, 1.308E-02, 9.617E-03, 7.361E-03, 5.843E-03, 4.191E-03, 3.072E-03, 2.705E-03, 2.437E-03, 2.267E-03, 2.134E-03, 2.097E-03, 1.926E-03, 2.013E-03, 1.605E-03, 1.296E-03, 1.303E-03, 1.250E-03, 1.375E-03, 1.203E-03}, // ttW.root
     { 1.785E-01, 3.905E+00, 5.030E+00, 2.363E+00, 1.798E+00, 1.739E+00, 1.361E+00, 1.289E+00, 8.896E-01, 2.173E+00, 2.132E+00, 2.051E+00, 1.740E+00, 1.537E+00, 1.450E+00, 1.420E+00, 1.431E+00, 1.430E+00, 1.426E+00, 1.407E+00, 1.393E+00, 1.390E+00, 1.391E+00, 1.391E+00, 1.390E+00, 1.380E+00, 1.356E+00, 1.330E+00, 1.311E+00, 1.257E+00, 1.204E+00, 1.124E+00, 1.045E+00, 9.530E-01, 8.810E-01, 8.210E-01, 7.725E-01, 7.455E-01, 7.164E-01, 7.033E-01, 7.449E-01, 8.242E-01, 9.466E-01, 1.090E+00, 1.250E+00, 1.400E+00, 1.483E+00, 1.430E+00, 1.328E+00, 1.124E+00, 9.092E-01, 6.911E-01, 5.034E-01, 3.523E-01, 2.388E-01, 1.551E-01, 9.965E-02, 6.317E-02, 4.082E-02, 2.707E-02, 1.849E-02, 1.310E-02, 9.563E-03, 7.378E-03, 5.833E-03, 4.165E-03, 3.101E-03, 2.689E-03, 2.456E-03, 2.272E-03, 2.138E-03, 2.058E-03, 2.008E-03, 1.946E-03, 1.488E-03, 1.352E-03, 1.330E-03, 1.241E-03, 1.232E-03, 1.334E-03}, // ttZ.root
     { 2.749E-04, 3.375E-02, 5.075E-02, 6.102E-02, 9.180E-02, 1.001E-01, 1.272E-01, 1.752E-01, 2.026E-01, 4.950E-01, 7.052E-01, 1.004E+00, 8.737E-01, 9.073E-01, 1.008E+00, 1.095E+00, 1.213E+00, 1.261E+00, 1.351E+00, 1.357E+00, 1.385E+00, 1.429E+00, 1.444E+00, 1.468E+00, 1.483E+00, 1.449E+00, 1.432E+00, 1.442E+00, 1.400E+00, 1.332E+00, 1.306E+00, 1.220E+00, 1.101E+00, 1.050E+00, 9.572E-01, 8.969E-01, 8.367E-01, 8.121E-01, 7.834E-01, 7.659E-01, 8.147E-01, 8.697E-01, 1.017E+00, 1.166E+00, 1.366E+00, 1.513E+00, 1.601E+00, 1.538E+00, 1.441E+00, 1.222E+00, 9.685E-01, 7.203E-01, 5.290E-01, 3.788E-01, 2.466E-01, 1.655E-01, 1.061E-01, 6.635E-02, 4.327E-02, 2.828E-02, 1.946E-02, 1.367E-02, 1.013E-02, 7.404E-03, 5.530E-03, 4.026E-03, 3.044E-03, 2.555E-03, 2.224E-03, 2.172E-03, 1.822E-03, 1.025E-03, 1.265E-03, 9.916E-04, 1.282E-03, 7.759E-04, 8.409E-04, 2.946E-04, 1.232E-04, 5.447E-05}, // ttH.root
     { 2.392E-04, 2.535E-02, 4.420E-02, 5.403E-02, 8.465E-02, 1.060E-01, 1.635E-01, 1.881E-01, 1.482E-01, 4.991E-01, 7.362E-01, 7.943E-01, 9.265E-01, 9.598E-01, 1.035E+00, 1.107E+00, 1.254E+00, 1.273E+00, 1.330E+00, 1.370E+00, 1.382E+00, 1.406E+00, 1.439E+00, 1.448E+00, 1.491E+00, 1.433E+00, 1.430E+00, 1.431E+00, 1.421E+00, 1.368E+00, 1.305E+00, 1.188E+00, 1.110E+00, 1.043E+00, 9.399E-01, 8.897E-01, 8.492E-01, 8.039E-01, 7.775E-01, 7.679E-01, 8.096E-01, 9.016E-01, 1.028E+00, 1.184E+00, 1.363E+00, 1.541E+00, 1.622E+00, 1.547E+00, 1.431E+00, 1.227E+00, 9.506E-01, 7.261E-01, 5.374E-01, 3.764E-01, 2.482E-01, 1.614E-01, 1.058E-01, 6.703E-02, 4.294E-02, 2.892E-02, 1.990E-02, 1.377E-02, 9.700E-03, 7.869E-03, 6.284E-03, 4.481E-03, 3.240E-03, 2.711E-03, 2.313E-03, 2.405E-03, 1.837E-03, 1.727E-03, 2.143E-03, 2.091E-03, 1.587E-03, 7.816E-04, 1.351E-03, 1.363E-03, 1.270E-03, 1.181E-04}, // WW.root
     { 3.000E-04, 1.037E-02, 4.812E-02, 6.479E-02, 1.064E-01, 2.007E-01, 2.005E-01, 2.486E-01, 1.572E-01, 6.099E-01, 6.130E-01, 8.929E-01, 9.211E-01, 9.922E-01, 9.807E-01, 1.010E+00, 1.118E+00, 1.280E+00, 1.323E+00, 1.346E+00, 1.414E+00, 1.416E+00, 1.431E+00, 1.448E+00, 1.471E+00, 1.462E+00, 1.426E+00, 1.426E+00, 1.421E+00, 1.373E+00, 1.276E+00, 1.207E+00, 1.125E+00, 1.041E+00, 9.691E-01, 9.041E-01, 8.457E-01, 8.098E-01, 7.702E-01, 7.803E-01, 7.976E-01, 8.806E-01, 1.023E+00, 1.208E+00, 1.380E+00, 1.510E+00, 1.617E+00, 1.577E+00, 1.430E+00, 1.241E+00, 9.751E-01, 7.476E-01, 5.422E-01, 3.609E-01, 2.505E-01, 1.609E-01, 1.080E-01, 6.809E-02, 4.416E-02, 2.923E-02, 1.891E-02, 1.346E-02, 9.378E-03, 6.994E-03, 5.955E-03, 4.439E-03, 2.932E-03, 2.757E-03, 1.947E-03, 2.243E-03, 1.258E-03, 1.277E-03, 1.083E-03, 2.175E-03, 8.778E-04, 2.953E-04, 1.985E-04, 1.255E-03, 6.371E-05, 4.534E-05}, // WZ.root
     { 4.754E-04, 2.803E-02, 4.775E-02, 2.087E-01, 1.657E-01, 1.568E-01, 2.380E-01, 3.119E-01, 2.303E-01, 6.776E-01, 7.993E-01, 9.758E-01, 9.744E-01, 9.374E-01, 8.435E-01, 9.754E-01, 1.061E+00, 1.157E+00, 1.284E+00, 1.306E+00, 1.345E+00, 1.403E+00, 1.434E+00, 1.452E+00, 1.450E+00, 1.459E+00, 1.448E+00, 1.410E+00, 1.370E+00, 1.350E+00, 1.302E+00, 1.216E+00, 1.115E+00, 1.038E+00, 9.541E-01, 8.908E-01, 8.427E-01, 8.130E-01, 7.817E-01, 7.751E-01, 8.154E-01, 8.691E-01, 1.040E+00, 1.141E+00, 1.374E+00, 1.462E+00, 1.627E+00, 1.494E+00, 1.395E+00, 1.227E+00, 9.032E-01, 7.350E-01, 5.420E-01, 3.393E-01, 2.305E-01, 1.621E-01, 1.067E-01, 6.413E-02, 4.339E-02, 2.768E-02, 1.913E-02, 1.395E-02, 1.028E-02, 7.239E-03, 5.392E-03, 3.586E-03, 2.997E-03, 2.877E-03, 2.464E-03, 2.309E-03, 2.292E-03, 2.140E-03, 2.204E-03, 2.236E-03, 1.511E-03, 1.277E-03, 1.538E-03, 2.884E-04, 5.381E-04, 2.047E-05}, // ZZ.root
     { 1.817E-01, 1.168E+01, 5.677E+00, 2.844E+00, 1.784E+00, 1.772E+00, 1.351E+00, 1.447E+00, 9.000E-01, 2.140E+00, 2.198E+00, 2.200E+00, 1.738E+00, 1.572E+00, 1.432E+00, 1.429E+00, 1.414E+00, 1.430E+00, 1.412E+00, 1.401E+00, 1.388E+00, 1.380E+00, 1.373E+00, 1.413E+00, 1.402E+00, 1.376E+00, 1.364E+00, 1.317E+00, 1.325E+00, 1.249E+00, 1.194E+00, 1.112E+00, 1.038E+00, 9.623E-01, 8.730E-01, 8.160E-01, 7.736E-01, 7.480E-01, 7.227E-01, 7.053E-01, 7.502E-01, 8.203E-01, 9.387E-01, 1.072E+00, 1.246E+00, 1.388E+00, 1.498E+00, 1.448E+00, 1.323E+00, 1.114E+00, 9.031E-01, 6.882E-01, 4.957E-01, 3.524E-01, 2.410E-01, 1.592E-01, 1.012E-01, 6.300E-02, 4.145E-02, 2.705E-02, 1.873E-02, 1.331E-02, 9.740E-03, 7.650E-03, 5.982E-03, 4.350E-03, 3.063E-03, 2.591E-03, 2.505E-03, 2.334E-03, 2.080E-03, 2.069E-03, 2.043E-03, 1.996E-03, 1.674E-03, 1.261E-03, 1.311E-03, 1.421E-03, 1.042E-03, 1.145E-03}, // TpTp700.root
     { 1.961E-01, 4.693E+00, 3.423E+00, 2.165E+00, 1.829E+00, 1.623E+00, 1.431E+00, 1.188E+00, 8.092E-01, 1.995E+00, 2.197E+00, 2.099E+00, 1.750E+00, 1.561E+00, 1.492E+00, 1.407E+00, 1.444E+00, 1.429E+00, 1.414E+00, 1.395E+00, 1.390E+00, 1.380E+00, 1.389E+00, 1.387E+00, 1.399E+00, 1.389E+00, 1.370E+00, 1.323E+00, 1.303E+00, 1.268E+00, 1.196E+00, 1.114E+00, 1.050E+00, 9.590E-01, 8.840E-01, 8.201E-01, 7.654E-01, 7.413E-01, 7.169E-01, 7.049E-01, 7.369E-01, 8.288E-01, 9.535E-01, 1.099E+00, 1.243E+00, 1.384E+00, 1.470E+00, 1.429E+00, 1.331E+00, 1.144E+00, 9.079E-01, 6.958E-01, 5.124E-01, 3.503E-01, 2.418E-01, 1.531E-01, 1.011E-01, 6.354E-02, 4.080E-02, 2.680E-02, 1.823E-02, 1.322E-02, 9.581E-03, 7.384E-03, 5.964E-03, 4.126E-03, 3.110E-03, 2.624E-03, 2.460E-03, 2.274E-03, 2.156E-03, 2.164E-03, 1.919E-03, 1.784E-03, 1.388E-03, 1.372E-03, 1.150E-03, 1.060E-03, 9.575E-04, 1.250E-03}, // TpTp1000.root
     { 2.421E-01, 3.399E+00, 3.718E+00, 2.300E+00, 2.091E+00, 1.592E+00, 1.567E+00, 1.341E+00, 9.583E-01, 2.196E+00, 2.139E+00, 2.213E+00, 1.743E+00, 1.527E+00, 1.451E+00, 1.419E+00, 1.423E+00, 1.438E+00, 1.418E+00, 1.415E+00, 1.392E+00, 1.385E+00, 1.391E+00, 1.399E+00, 1.405E+00, 1.387E+00, 1.359E+00, 1.321E+00, 1.305E+00, 1.270E+00, 1.183E+00, 1.107E+00, 1.052E+00, 9.529E-01, 8.726E-01, 8.193E-01, 7.717E-01, 7.530E-01, 7.146E-01, 7.028E-01, 7.514E-01, 8.205E-01, 9.305E-01, 1.087E+00, 1.258E+00, 1.412E+00, 1.483E+00, 1.431E+00, 1.319E+00, 1.153E+00, 9.135E-01, 7.011E-01, 5.003E-01, 3.526E-01, 2.421E-01, 1.564E-01, 1.012E-01, 6.385E-02, 4.073E-02, 2.699E-02, 1.807E-02, 1.304E-02, 9.435E-03, 7.052E-03, 5.666E-03, 4.177E-03, 3.104E-03, 2.684E-03, 2.394E-03, 2.418E-03, 2.250E-03, 2.151E-03, 2.142E-03, 1.890E-03, 1.766E-03, 1.233E-03, 1.131E-03, 1.520E-03, 1.222E-03, 1.086E-03}, // TpTp1100.root
     { 2.274E-01, 2.464E+00, 3.234E+00, 2.251E+00, 1.963E+00, 2.163E+00, 1.615E+00, 1.444E+00, 7.966E-01, 2.141E+00, 2.176E+00, 1.993E+00, 1.780E+00, 1.540E+00, 1.430E+00, 1.415E+00, 1.431E+00, 1.421E+00, 1.415E+00, 1.381E+00, 1.390E+00, 1.389E+00, 1.390E+00, 1.414E+00, 1.387E+00, 1.364E+00, 1.354E+00, 1.325E+00, 1.321E+00, 1.250E+00, 1.205E+00, 1.133E+00, 1.045E+00, 9.548E-01, 8.865E-01, 8.137E-01, 7.625E-01, 7.428E-01, 7.208E-01, 7.062E-01, 7.575E-01, 8.301E-01, 9.422E-01, 1.098E+00, 1.245E+00, 1.404E+00, 1.480E+00, 1.453E+00, 1.348E+00, 1.126E+00, 9.126E-01, 6.806E-01, 4.997E-01, 3.478E-01, 2.339E-01, 1.566E-01, 1.010E-01, 6.358E-02, 4.118E-02, 2.729E-02, 1.825E-02, 1.329E-02, 9.582E-03, 7.369E-03, 5.816E-03, 4.242E-03, 3.090E-03, 2.630E-03, 2.368E-03, 2.272E-03, 2.171E-03, 1.978E-03, 2.132E-03, 2.177E-03, 1.600E-03, 1.494E-03, 1.260E-03, 1.322E-03, 1.701E-03, 1.045E-03}, // TpTp1200.root
     { 1.644E-01, 3.123E+00, 3.986E+00, 2.219E+00, 1.704E+00, 1.531E+00, 1.319E+00, 1.268E+00, 9.258E-01, 2.165E+00, 2.087E+00, 2.035E+00, 1.780E+00, 1.517E+00, 1.457E+00, 1.418E+00, 1.405E+00, 1.419E+00, 1.438E+00, 1.409E+00, 1.386E+00, 1.420E+00, 1.381E+00, 1.396E+00, 1.386E+00, 1.398E+00, 1.364E+00, 1.339E+00, 1.302E+00, 1.258E+00, 1.206E+00, 1.119E+00, 1.042E+00, 9.488E-01, 8.870E-01, 8.242E-01, 7.657E-01, 7.487E-01, 7.267E-01, 7.039E-01, 7.467E-01, 8.331E-01, 9.451E-01, 1.088E+00, 1.248E+00, 1.374E+00, 1.467E+00, 1.418E+00, 1.316E+00, 1.133E+00, 9.029E-01, 6.741E-01, 5.107E-01, 3.567E-01, 2.398E-01, 1.568E-01, 9.943E-02, 6.354E-02, 4.198E-02, 2.673E-02, 1.837E-02, 1.264E-02, 9.297E-03, 7.306E-03, 5.766E-03, 4.035E-03, 3.086E-03, 2.674E-03, 2.425E-03, 2.113E-03, 2.148E-03, 2.262E-03, 1.892E-03, 1.850E-03, 1.470E-03, 1.289E-03, 1.736E-03, 1.386E-03, 1.103E-03, 1.116E-03}, // TpTp1300.root
     { 2.259E-01, 2.503E+00, 1.460E+01, 2.258E+00, 2.001E+00, 1.683E+00, 1.123E+00, 1.317E+00, 1.018E+00, 2.115E+00, 2.290E+00, 2.001E+00, 1.798E+00, 1.523E+00, 1.432E+00, 1.442E+00, 1.406E+00, 1.438E+00, 1.414E+00, 1.425E+00, 1.396E+00, 1.390E+00, 1.394E+00, 1.405E+00, 1.406E+00, 1.398E+00, 1.349E+00, 1.343E+00, 1.299E+00, 1.252E+00, 1.214E+00, 1.133E+00, 1.054E+00, 9.478E-01, 8.770E-01, 8.120E-01, 7.754E-01, 7.426E-01, 7.193E-01, 7.032E-01, 7.369E-01, 8.230E-01, 9.410E-01, 1.100E+00, 1.252E+00, 1.390E+00, 1.473E+00, 1.433E+00, 1.335E+00, 1.121E+00, 9.185E-01, 6.828E-01, 5.034E-01, 3.511E-01, 2.375E-01, 1.556E-01, 1.012E-01, 6.249E-02, 4.154E-02, 2.636E-02, 1.811E-02, 1.293E-02, 9.374E-03, 7.349E-03, 5.789E-03, 4.230E-03, 2.986E-03, 2.748E-03, 2.369E-03, 2.135E-03, 2.288E-03, 2.089E-03, 1.808E-03, 1.703E-03, 1.548E-03, 1.171E-03, 1.230E-03, 1.194E-03, 1.670E-03, 1.534E-03}, // TpTp1400.root
     { 2.534E-01, 4.774E+00, 3.214E+00, 2.769E+00, 1.353E+00, 1.656E+00, 1.323E+00, 1.369E+00, 8.440E-01, 2.160E+00, 2.081E+00, 2.068E+00, 1.726E+00, 1.534E+00, 1.434E+00, 1.419E+00, 1.411E+00, 1.424E+00, 1.405E+00, 1.426E+00, 1.388E+00, 1.389E+00, 1.380E+00, 1.409E+00, 1.402E+00, 1.378E+00, 1.339E+00, 1.325E+00, 1.307E+00, 1.274E+00, 1.184E+00, 1.134E+00, 1.041E+00, 9.602E-01, 8.671E-01, 8.262E-01, 7.761E-01, 7.544E-01, 7.171E-01, 7.107E-01, 7.460E-01, 8.273E-01, 9.512E-01, 1.085E+00, 1.249E+00, 1.383E+00, 1.475E+00, 1.440E+00, 1.307E+00, 1.127E+00, 9.317E-01, 6.889E-01, 5.082E-01, 3.543E-01, 2.389E-01, 1.564E-01, 9.975E-02, 6.308E-02, 4.107E-02, 2.683E-02, 1.837E-02, 1.300E-02, 9.587E-03, 7.369E-03, 5.801E-03, 4.057E-03, 3.202E-03, 2.540E-03, 2.601E-03, 2.136E-03, 2.060E-03, 2.101E-03, 1.910E-03, 2.114E-03, 1.445E-03, 1.064E-03, 1.113E-03, 1.423E-03, 9.898E-04, 1.170E-03}, // TpTp1500.root
     { 1.691E-01, 4.496E+00, 3.577E+00, 2.191E+00, 1.797E+00, 1.535E+00, 1.462E+00, 1.319E+00, 9.965E-01, 2.230E+00, 2.421E+00, 2.204E+00, 1.788E+00, 1.538E+00, 1.485E+00, 1.431E+00, 1.447E+00, 1.434E+00, 1.431E+00, 1.428E+00, 1.359E+00, 1.384E+00, 1.392E+00, 1.374E+00, 1.407E+00, 1.371E+00, 1.361E+00, 1.308E+00, 1.299E+00, 1.267E+00, 1.197E+00, 1.122E+00, 1.053E+00, 9.560E-01, 8.843E-01, 8.065E-01, 7.815E-01, 7.474E-01, 7.171E-01, 7.104E-01, 7.420E-01, 8.319E-01, 9.367E-01, 1.106E+00, 1.275E+00, 1.387E+00, 1.467E+00, 1.429E+00, 1.347E+00, 1.114E+00, 9.222E-01, 6.787E-01, 4.913E-01, 3.537E-01, 2.385E-01, 1.556E-01, 9.965E-02, 6.276E-02, 4.035E-02, 2.740E-02, 1.810E-02, 1.318E-02, 9.708E-03, 7.336E-03, 5.762E-03, 4.249E-03, 3.249E-03, 2.613E-03, 2.482E-03, 2.292E-03, 2.000E-03, 2.002E-03, 2.071E-03, 2.412E-03, 2.049E-03, 1.224E-03, 1.200E-03, 1.072E-03, 9.581E-04, 1.377E-03}, // TpTp1600.root
     { 3.213E-01, 2.238E+00, 3.428E+00, 2.385E+00, 1.650E+00, 1.278E+00, 1.188E+00, 1.960E+00, 7.860E-01, 1.943E+00, 2.136E+00, 2.060E+00, 1.775E+00, 1.562E+00, 1.424E+00, 1.397E+00, 1.471E+00, 1.430E+00, 1.411E+00, 1.430E+00, 1.373E+00, 1.387E+00, 1.393E+00, 1.413E+00, 1.407E+00, 1.372E+00, 1.351E+00, 1.310E+00, 1.314E+00, 1.255E+00, 1.208E+00, 1.141E+00, 1.031E+00, 9.504E-01, 8.791E-01, 8.118E-01, 7.635E-01, 7.642E-01, 7.256E-01, 7.090E-01, 7.532E-01, 8.499E-01, 9.292E-01, 1.101E+00, 1.240E+00, 1.378E+00, 1.481E+00, 1.411E+00, 1.337E+00, 1.109E+00, 9.057E-01, 6.796E-01, 4.907E-01, 3.592E-01, 2.375E-01, 1.545E-01, 1.004E-01, 6.358E-02, 4.029E-02, 2.685E-02, 1.822E-02, 1.306E-02, 9.822E-03, 7.220E-03, 5.894E-03, 4.330E-03, 3.072E-03, 2.566E-03, 2.609E-03, 2.479E-03, 2.090E-03, 1.923E-03, 1.771E-03, 1.701E-03, 1.425E-03, 1.705E-03, 1.387E-03, 1.038E-03, 1.669E-03, 8.726E-04}, // TpTp1700.root
     { 1.647E-01, 2.629E+00, 7.189E+00, 4.002E+00, 2.561E+00, 1.140E+00, 1.475E+00, 1.133E+00, 8.043E-01, 2.417E+00, 1.969E+00, 2.093E+00, 1.760E+00, 1.645E+00, 1.470E+00, 1.421E+00, 1.446E+00, 1.424E+00, 1.443E+00, 1.381E+00, 1.392E+00, 1.383E+00, 1.395E+00, 1.410E+00, 1.378E+00, 1.394E+00, 1.367E+00, 1.311E+00, 1.335E+00, 1.267E+00, 1.225E+00, 1.115E+00, 1.033E+00, 9.579E-01, 8.720E-01, 8.262E-01, 7.811E-01, 7.436E-01, 7.204E-01, 6.902E-01, 7.564E-01, 8.223E-01, 9.296E-01, 1.078E+00, 1.194E+00, 1.428E+00, 1.491E+00, 1.445E+00, 1.314E+00, 1.121E+00, 8.760E-01, 6.718E-01, 4.929E-01, 3.538E-01, 2.436E-01, 1.542E-01, 1.025E-01, 6.329E-02, 4.176E-02, 2.635E-02, 1.866E-02, 1.292E-02, 9.715E-03, 7.350E-03, 6.253E-03, 4.082E-03, 3.054E-03, 2.707E-03, 2.361E-03, 2.222E-03, 2.066E-03, 1.773E-03, 2.820E-03, 2.522E-03, 1.824E-03, 1.134E-03, 1.513E-03, 1.399E-03, 1.800E-03, 8.053E-04}, // TpTp1800.root
     { 1.956E-01, 5.248E+00, 4.196E+00, 2.304E+00, 2.077E+00, 1.657E+00, 1.386E+00, 1.350E+00, 8.810E-01, 2.221E+00, 2.212E+00, 2.054E+00, 1.725E+00, 1.530E+00, 1.433E+00, 1.415E+00, 1.431E+00, 1.434E+00, 1.422E+00, 1.406E+00, 1.392E+00, 1.386E+00, 1.389E+00, 1.392E+00, 1.390E+00, 1.381E+00, 1.361E+00, 1.331E+00, 1.310E+00, 1.258E+00, 1.201E+00, 1.125E+00, 1.043E+00, 9.559E-01, 8.776E-01, 8.191E-01, 7.730E-01, 7.494E-01, 7.178E-01, 7.045E-01, 7.467E-01, 8.257E-01, 9.414E-01, 1.088E+00, 1.246E+00, 1.393E+00, 1.485E+00, 1.435E+00, 1.322E+00, 1.127E+00, 9.104E-01, 6.925E-01, 5.023E-01, 3.517E-01, 2.394E-01, 1.557E-01, 1.004E-01, 6.365E-02, 4.097E-02, 2.709E-02, 1.842E-02, 1.303E-02, 9.584E-03, 7.348E-03, 5.862E-03, 4.138E-03, 3.053E-03, 2.666E-03, 2.430E-03, 2.256E-03, 2.140E-03, 2.089E-03, 1.981E-03, 2.002E-03, 1.566E-03, 1.282E-03, 1.289E-03, 1.315E-03, 1.286E-03, 1.330E-03}, // WJ1200.root
     { 2.001E-01, 4.707E+00, 4.493E+00, 2.398E+00, 1.889E+00, 1.708E+00, 1.343E+00, 1.422E+00, 8.659E-01, 2.142E+00, 2.156E+00, 2.050E+00, 1.738E+00, 1.537E+00, 1.443E+00, 1.418E+00, 1.428E+00, 1.429E+00, 1.423E+00, 1.406E+00, 1.391E+00, 1.389E+00, 1.386E+00, 1.393E+00, 1.392E+00, 1.384E+00, 1.361E+00, 1.330E+00, 1.307E+00, 1.260E+00, 1.200E+00, 1.123E+00, 1.046E+00, 9.546E-01, 8.776E-01, 8.187E-01, 7.750E-01, 7.462E-01, 7.146E-01, 7.049E-01, 7.457E-01, 8.282E-01, 9.435E-01, 1.085E+00, 1.250E+00, 1.394E+00, 1.485E+00, 1.434E+00, 1.329E+00, 1.126E+00, 9.123E-01, 6.931E-01, 5.036E-01, 3.523E-01, 2.389E-01, 1.554E-01, 1.002E-01, 6.324E-02, 4.093E-02, 2.711E-02, 1.854E-02, 1.303E-02, 9.649E-03, 7.323E-03, 5.864E-03, 4.167E-03, 3.069E-03, 2.676E-03, 2.398E-03, 2.240E-03, 2.127E-03, 2.079E-03, 2.015E-03, 1.970E-03, 1.567E-03, 1.320E-03, 1.302E-03, 1.255E-03, 1.352E-03, 1.202E-03}, // WJ200.root
     { 1.985E-01, 4.608E+00, 4.225E+00, 2.560E+00, 1.855E+00, 1.666E+00, 1.344E+00, 1.387E+00, 9.003E-01, 2.137E+00, 2.169E+00, 2.061E+00, 1.750E+00, 1.531E+00, 1.433E+00, 1.415E+00, 1.431E+00, 1.433E+00, 1.426E+00, 1.405E+00, 1.394E+00, 1.389E+00, 1.393E+00, 1.393E+00, 1.391E+00, 1.378E+00, 1.363E+00, 1.328E+00, 1.309E+00, 1.256E+00, 1.201E+00, 1.127E+00, 1.043E+00, 9.551E-01, 8.775E-01, 8.195E-01, 7.756E-01, 7.476E-01, 7.150E-01, 7.015E-01, 7.482E-01, 8.255E-01, 9.433E-01, 1.091E+00, 1.243E+00, 1.391E+00, 1.479E+00, 1.437E+00, 1.323E+00, 1.125E+00, 9.113E-01, 6.918E-01, 5.022E-01, 3.519E-01, 2.394E-01, 1.556E-01, 1.002E-01, 6.339E-02, 4.089E-02, 2.715E-02, 1.854E-02, 1.302E-02, 9.568E-03, 7.373E-03, 5.841E-03, 4.182E-03, 3.080E-03, 2.704E-03, 2.405E-03, 2.265E-03, 2.155E-03, 2.055E-03, 2.031E-03, 1.988E-03, 1.530E-03, 1.308E-03, 1.299E-03, 1.334E-03, 1.253E-03, 1.350E-03}, // WJ2500.root
     { 1.984E-01, 4.378E+00, 5.029E+00, 2.594E+00, 1.893E+00, 1.651E+00, 1.360E+00, 1.439E+00, 8.843E-01, 2.131E+00, 2.186E+00, 2.060E+00, 1.733E+00, 1.533E+00, 1.439E+00, 1.418E+00, 1.423E+00, 1.429E+00, 1.420E+00, 1.404E+00, 1.392E+00, 1.388E+00, 1.391E+00, 1.390E+00, 1.393E+00, 1.383E+00, 1.360E+00, 1.332E+00, 1.311E+00, 1.257E+00, 1.203E+00, 1.127E+00, 1.043E+00, 9.549E-01, 8.785E-01, 8.174E-01, 7.724E-01, 7.473E-01, 7.174E-01, 7.032E-01, 7.454E-01, 8.254E-01, 9.436E-01, 1.086E+00, 1.250E+00, 1.396E+00, 1.484E+00, 1.437E+00, 1.328E+00, 1.129E+00, 9.116E-01, 6.936E-01, 5.034E-01, 3.523E-01, 2.389E-01, 1.558E-01, 1.001E-01, 6.302E-02, 4.109E-02, 2.711E-02, 1.856E-02, 1.307E-02, 9.576E-03, 7.264E-03, 5.873E-03, 4.135E-03, 3.064E-03, 2.687E-03, 2.407E-03, 2.242E-03, 2.128E-03, 2.078E-03, 2.010E-03, 2.000E-03, 1.542E-03, 1.316E-03, 1.308E-03, 1.218E-03, 1.251E-03, 1.270E-03}, // WJ400.root
     { 1.986E-01, 3.920E+00, 4.591E+00, 2.554E+00, 1.822E+00, 1.667E+00, 1.351E+00, 1.444E+00, 8.880E-01, 2.208E+00, 2.152E+00, 2.055E+00, 1.731E+00, 1.534E+00, 1.430E+00, 1.421E+00, 1.431E+00, 1.438E+00, 1.423E+00, 1.403E+00, 1.396E+00, 1.388E+00, 1.392E+00, 1.393E+00, 1.391E+00, 1.383E+00, 1.357E+00, 1.328E+00, 1.308E+00, 1.259E+00, 1.203E+00, 1.126E+00, 1.043E+00, 9.538E-01, 8.770E-01, 8.167E-01, 7.741E-01, 7.469E-01, 7.172E-01, 7.055E-01, 7.441E-01, 8.282E-01, 9.429E-01, 1.088E+00, 1.248E+00, 1.389E+00, 1.484E+00, 1.435E+00, 1.328E+00, 1.125E+00, 9.090E-01, 6.919E-01, 5.041E-01, 3.534E-01, 2.391E-01, 1.560E-01, 1.004E-01, 6.336E-02, 4.095E-02, 2.699E-02, 1.846E-02, 1.305E-02, 9.589E-03, 7.309E-03, 5.837E-03, 4.154E-03, 3.050E-03, 2.701E-03, 2.438E-03, 2.238E-03, 2.137E-03, 2.064E-03, 1.968E-03, 2.006E-03, 1.596E-03, 1.289E-03, 1.299E-03, 1.217E-03, 1.278E-03, 1.191E-03}, // WJ600.root
     { 1.790E-01, 3.982E+00, 4.040E+00, 2.518E+00, 1.831E+00, 1.604E+00, 1.353E+00, 1.400E+00, 8.796E-01, 2.147E+00, 2.188E+00, 2.043E+00, 1.741E+00, 1.531E+00, 1.432E+00, 1.422E+00, 1.431E+00, 1.430E+00, 1.423E+00, 1.408E+00, 1.392E+00, 1.390E+00, 1.391E+00, 1.393E+00, 1.394E+00, 1.384E+00, 1.360E+00, 1.327E+00, 1.308E+00, 1.255E+00, 1.202E+00, 1.126E+00, 1.040E+00, 9.558E-01, 8.780E-01, 8.188E-01, 7.744E-01, 7.471E-01, 7.169E-01, 7.038E-01, 7.471E-01, 8.252E-01, 9.428E-01, 1.089E+00, 1.246E+00, 1.397E+00, 1.481E+00, 1.430E+00, 1.323E+00, 1.127E+00, 9.084E-01, 6.930E-01, 5.012E-01, 3.515E-01, 2.389E-01, 1.561E-01, 1.004E-01, 6.339E-02, 4.117E-02, 2.704E-02, 1.850E-02, 1.310E-02, 9.615E-03, 7.310E-03, 5.857E-03, 4.148E-03, 3.066E-03, 2.676E-03, 2.438E-03, 2.255E-03, 2.136E-03, 2.056E-03, 2.034E-03, 2.039E-03, 1.587E-03, 1.247E-03, 1.329E-03, 1.248E-03, 1.206E-03, 1.279E-03} // WJ800.root
   };

   pileupweightUp = { // 69.2 + 4.6%
     { 2.746E-04, 3.800E-02, 3.945E-02, 6.450E-02, 5.656E-02, 1.007E-01, 1.282E-01, 1.600E-01, 9.290E-02, 2.390E-01, 3.489E-01, 4.406E-01, 5.268E-01, 5.542E-01, 5.641E-01, 6.175E-01, 6.675E-01, 7.750E-01, 8.711E-01, 9.498E-01, 1.031E+00, 1.097E+00, 1.160E+00, 1.206E+00, 1.218E+00, 1.241E+00, 1.244E+00, 1.264E+00, 1.296E+00, 1.306E+00, 1.305E+00, 1.271E+00, 1.224E+00, 1.180E+00, 1.130E+00, 1.079E+00, 1.043E+00, 1.014E+00, 9.572E-01, 9.059E-01, 8.888E-01, 9.052E-01, 9.405E-01, 1.001E+00, 1.086E+00, 1.194E+00, 1.345E+00, 1.420E+00, 1.540E+00, 1.589E+00, 1.520E+00, 1.511E+00, 1.388E+00, 1.202E+00, 1.037E+00, 8.357E-01, 6.502E-01, 5.015E-01, 3.800E-01, 2.872E-01, 2.160E-01, 1.706E-01, 1.374E-01, 1.090E-01, 8.734E-02, 6.595E-02, 4.809E-02, 3.973E-02, 3.881E-02, 3.216E-02, 2.939E-02, 1.958E-02, 2.321E-02, 2.095E-02, 1.007E-02, 9.249E-03, 6.678E-03, 5.725E-03, 2.615E-03, 1.486E-03}, // DYJetsMG.root
     { 3.433E-04, 3.454E-02, 3.707E-02, 7.843E-02, 7.878E-02, 9.718E-02, 1.476E-01, 2.221E-01, 1.030E-01, 2.762E-01, 3.946E-01, 4.640E-01, 5.113E-01, 5.498E-01, 5.919E-01, 6.086E-01, 6.780E-01, 7.641E-01, 8.550E-01, 9.381E-01, 1.015E+00, 1.099E+00, 1.149E+00, 1.196E+00, 1.214E+00, 1.229E+00, 1.235E+00, 1.251E+00, 1.294E+00, 1.295E+00, 1.282E+00, 1.249E+00, 1.222E+00, 1.172E+00, 1.113E+00, 1.073E+00, 1.033E+00, 9.993E-01, 9.431E-01, 9.012E-01, 8.873E-01, 8.995E-01, 9.242E-01, 9.785E-01, 1.072E+00, 1.194E+00, 1.344E+00, 1.437E+00, 1.551E+00, 1.594E+00, 1.501E+00, 1.501E+00, 1.355E+00, 1.225E+00, 1.037E+00, 8.318E-01, 6.545E-01, 4.967E-01, 3.796E-01, 2.866E-01, 2.198E-01, 1.698E-01, 1.373E-01, 1.101E-01, 8.817E-02, 6.614E-02, 4.662E-02, 3.968E-02, 3.667E-02, 3.382E-02, 2.906E-02, 1.962E-02, 2.278E-02, 2.174E-02, 1.324E-02, 1.531E-02, 8.076E-03, 5.732E-03, 4.735E-03, 2.103E-03}, // QCD1000.root
     { 1.694E-01, 3.604E+00, 2.835E+00, 2.691E+00, 1.428E+00, 1.307E+00, 1.213E+00, 1.141E+00, 4.834E-01, 9.236E-01, 1.068E+00, 1.039E+00, 1.006E+00, 9.011E-01, 8.298E-01, 7.959E-01, 8.148E-01, 8.686E-01, 9.329E-01, 9.882E-01, 1.035E+00, 1.088E+00, 1.124E+00, 1.155E+00, 1.167E+00, 1.168E+00, 1.174E+00, 1.183E+00, 1.213E+00, 1.211E+00, 1.209E+00, 1.180E+00, 1.142E+00, 1.087E+00, 1.039E+00, 9.923E-01, 9.580E-01, 9.264E-01, 8.764E-01, 8.333E-01, 8.299E-01, 8.384E-01, 8.677E-01, 9.186E-01, 1.002E+00, 1.113E+00, 1.247E+00, 1.345E+00, 1.444E+00, 1.494E+00, 1.490E+00, 1.425E+00, 1.318E+00, 1.161E+00, 9.929E-01, 8.030E-01, 6.238E-01, 4.741E-01, 3.591E-01, 2.743E-01, 2.100E-01, 1.636E-01, 1.311E-01, 1.061E-01, 8.847E-02, 6.451E-02, 4.810E-02, 4.175E-02, 3.714E-02, 3.411E-02, 3.086E-02, 3.037E-02, 2.895E-02, 2.835E-02, 2.272E-02, 1.925E-02, 2.068E-02, 2.272E-02, 2.337E-02, 2.412E-02}, // QCD1500.root
     { 1.620E-01, 3.457E+00, 2.962E+00, 2.561E+00, 1.300E+00, 1.323E+00, 1.252E+00, 1.134E+00, 4.869E-01, 9.444E-01, 1.069E+00, 1.036E+00, 1.017E+00, 9.092E-01, 8.329E-01, 7.962E-01, 8.147E-01, 8.688E-01, 9.369E-01, 9.801E-01, 1.029E+00, 1.083E+00, 1.129E+00, 1.157E+00, 1.164E+00, 1.168E+00, 1.172E+00, 1.182E+00, 1.214E+00, 1.212E+00, 1.205E+00, 1.173E+00, 1.139E+00, 1.088E+00, 1.038E+00, 9.980E-01, 9.540E-01, 9.294E-01, 8.779E-01, 8.341E-01, 8.319E-01, 8.399E-01, 8.686E-01, 9.241E-01, 1.002E+00, 1.112E+00, 1.254E+00, 1.361E+00, 1.453E+00, 1.484E+00, 1.496E+00, 1.426E+00, 1.309E+00, 1.170E+00, 9.880E-01, 7.975E-01, 6.242E-01, 4.768E-01, 3.597E-01, 2.725E-01, 2.094E-01, 1.642E-01, 1.310E-01, 1.064E-01, 8.922E-02, 6.381E-02, 4.794E-02, 4.177E-02, 3.789E-02, 3.325E-02, 3.151E-02, 3.098E-02, 2.831E-02, 2.880E-02, 2.202E-02, 1.875E-02, 2.074E-02, 2.056E-02, 2.543E-02, 2.142E-02}, // QCD2000.root
     { 2.672E-04, 2.574E-02, 3.670E-02, 7.423E-02, 5.911E-02, 9.888E-02, 1.257E-01, 1.420E-01, 8.521E-02, 2.163E-01, 3.577E-01, 4.463E-01, 5.098E-01, 5.489E-01, 5.668E-01, 6.074E-01, 6.810E-01, 7.691E-01, 8.707E-01, 9.530E-01, 1.025E+00, 1.102E+00, 1.167E+00, 1.204E+00, 1.229E+00, 1.234E+00, 1.249E+00, 1.262E+00, 1.298E+00, 1.307E+00, 1.305E+00, 1.260E+00, 1.227E+00, 1.185E+00, 1.130E+00, 1.084E+00, 1.044E+00, 1.007E+00, 9.514E-01, 9.059E-01, 8.988E-01, 9.113E-01, 9.370E-01, 1.004E+00, 1.088E+00, 1.202E+00, 1.348E+00, 1.423E+00, 1.536E+00, 1.580E+00, 1.557E+00, 1.488E+00, 1.378E+00, 1.211E+00, 1.043E+00, 8.298E-01, 6.572E-01, 4.998E-01, 3.801E-01, 2.896E-01, 2.204E-01, 1.717E-01, 1.362E-01, 1.084E-01, 8.464E-02, 6.609E-02, 4.806E-02, 4.190E-02, 3.462E-02, 3.365E-02, 2.754E-02, 2.329E-02, 1.907E-02, 2.342E-02, 1.291E-02, 1.417E-02, 9.327E-03, 5.206E-03, 3.842E-03, 1.956E-03}, // QCD300.root
     { 2.416E-04, 2.728E-02, 3.163E-02, 5.796E-02, 6.194E-02, 9.897E-02, 9.667E-02, 1.189E-01, 8.736E-02, 2.091E-01, 3.433E-01, 4.319E-01, 4.940E-01, 5.508E-01, 5.599E-01, 5.961E-01, 6.788E-01, 7.806E-01, 8.777E-01, 9.527E-01, 1.034E+00, 1.097E+00, 1.168E+00, 1.215E+00, 1.234E+00, 1.245E+00, 1.249E+00, 1.274E+00, 1.300E+00, 1.308E+00, 1.312E+00, 1.268E+00, 1.235E+00, 1.185E+00, 1.134E+00, 1.077E+00, 1.048E+00, 1.014E+00, 9.588E-01, 9.090E-01, 8.984E-01, 9.137E-01, 9.489E-01, 1.006E+00, 1.086E+00, 1.200E+00, 1.357E+00, 1.456E+00, 1.547E+00, 1.600E+00, 1.548E+00, 1.515E+00, 1.384E+00, 1.222E+00, 1.042E+00, 8.469E-01, 6.616E-01, 4.986E-01, 3.816E-01, 2.865E-01, 2.225E-01, 1.722E-01, 1.375E-01, 1.069E-01, 8.782E-02, 6.631E-02, 4.759E-02, 4.244E-02, 3.822E-02, 3.212E-02, 2.661E-02, 1.902E-02, 2.176E-02, 1.620E-02, 1.151E-02, 1.447E-02, 8.548E-03, 8.861E-03, 4.279E-03, 2.068E-03}, // QCD500.root
     { 2.868E-04, 4.027E-02, 4.212E-02, 7.878E-02, 6.589E-02, 1.026E-01, 1.337E-01, 1.462E-01, 1.046E-01, 2.653E-01, 3.643E-01, 4.706E-01, 5.401E-01, 5.474E-01, 5.807E-01, 6.221E-01, 6.787E-01, 7.667E-01, 8.683E-01, 9.483E-01, 1.021E+00, 1.090E+00, 1.156E+00, 1.199E+00, 1.223E+00, 1.224E+00, 1.244E+00, 1.262E+00, 1.281E+00, 1.297E+00, 1.297E+00, 1.263E+00, 1.220E+00, 1.181E+00, 1.120E+00, 1.069E+00, 1.038E+00, 1.009E+00, 9.492E-01, 9.048E-01, 8.920E-01, 9.120E-01, 9.368E-01, 9.971E-01, 1.083E+00, 1.197E+00, 1.346E+00, 1.442E+00, 1.558E+00, 1.583E+00, 1.555E+00, 1.487E+00, 1.395E+00, 1.216E+00, 1.029E+00, 8.306E-01, 6.510E-01, 4.971E-01, 3.768E-01, 2.874E-01, 2.239E-01, 1.702E-01, 1.369E-01, 1.045E-01, 8.620E-02, 6.536E-02, 5.000E-02, 4.206E-02, 3.557E-02, 3.208E-02, 2.724E-02, 1.853E-02, 1.923E-02, 1.762E-02, 9.488E-03, 1.326E-02, 9.188E-03, 8.836E-03, 2.524E-03, 2.510E-03}, // QCD700.root
     { 2.804E-04, 3.766E-02, 4.106E-02, 6.948E-02, 7.013E-02, 1.280E-01, 1.357E-01, 1.355E-01, 8.374E-02, 2.217E-01, 3.260E-01, 4.327E-01, 5.261E-01, 5.189E-01, 5.233E-01, 6.099E-01, 6.246E-01, 7.674E-01, 8.628E-01, 9.382E-01, 1.018E+00, 1.069E+00, 1.160E+00, 1.206E+00, 1.211E+00, 1.240E+00, 1.256E+00, 1.259E+00, 1.292E+00, 1.297E+00, 1.296E+00, 1.272E+00, 1.217E+00, 1.186E+00, 1.133E+00, 1.093E+00, 1.053E+00, 1.008E+00, 9.596E-01, 9.115E-01, 9.110E-01, 9.098E-01, 9.499E-01, 1.016E+00, 1.097E+00, 1.209E+00, 1.330E+00, 1.478E+00, 1.505E+00, 1.570E+00, 1.558E+00, 1.530E+00, 1.387E+00, 1.242E+00, 1.031E+00, 8.321E-01, 6.678E-01, 5.112E-01, 3.810E-01, 2.878E-01, 2.191E-01, 1.733E-01, 1.396E-01, 1.081E-01, 9.093E-02, 6.657E-02, 4.975E-02, 4.134E-02, 3.648E-02, 3.607E-02, 2.903E-02, 1.674E-02, 1.139E-02, 2.445E-02, 1.119E-02, 6.881E-03, 7.184E-03, 2.179E-02, 5.974E-03, 1.479E-03}, // STs.root
     { 1.744E-01, 3.086E+00, 2.652E+00, 2.514E+00, 1.367E+00, 1.350E+00, 1.217E+00, 1.129E+00, 5.035E-01, 9.533E-01, 1.062E+00, 1.040E+00, 1.012E+00, 9.044E-01, 8.261E-01, 7.949E-01, 8.160E-01, 8.697E-01, 9.335E-01, 9.872E-01, 1.036E+00, 1.086E+00, 1.127E+00, 1.155E+00, 1.168E+00, 1.169E+00, 1.173E+00, 1.183E+00, 1.212E+00, 1.213E+00, 1.209E+00, 1.178E+00, 1.140E+00, 1.086E+00, 1.038E+00, 9.926E-01, 9.578E-01, 9.260E-01, 8.777E-01, 8.336E-01, 8.275E-01, 8.407E-01, 8.676E-01, 9.191E-01, 9.994E-01, 1.112E+00, 1.251E+00, 1.348E+00, 1.443E+00, 1.495E+00, 1.489E+00, 1.430E+00, 1.313E+00, 1.162E+00, 9.906E-01, 7.999E-01, 6.275E-01, 4.749E-01, 3.606E-01, 2.731E-01, 2.103E-01, 1.643E-01, 1.304E-01, 1.063E-01, 8.864E-02, 6.386E-02, 4.771E-02, 4.167E-02, 3.727E-02, 3.395E-02, 3.143E-02, 3.013E-02, 2.895E-02, 2.911E-02, 2.229E-02, 1.967E-02, 2.018E-02, 2.005E-02, 2.279E-02, 2.441E-02}, // STt.root
     { 1.724E-01, 4.426E+00, 2.736E+00, 2.767E+00, 1.319E+00, 1.331E+00, 1.239E+00, 1.141E+00, 5.163E-01, 9.236E-01, 1.065E+00, 1.045E+00, 9.995E-01, 8.990E-01, 8.296E-01, 7.932E-01, 8.127E-01, 8.700E-01, 9.384E-01, 9.872E-01, 1.036E+00, 1.087E+00, 1.128E+00, 1.154E+00, 1.167E+00, 1.166E+00, 1.167E+00, 1.181E+00, 1.210E+00, 1.214E+00, 1.206E+00, 1.182E+00, 1.142E+00, 1.090E+00, 1.036E+00, 9.946E-01, 9.587E-01, 9.281E-01, 8.786E-01, 8.296E-01, 8.288E-01, 8.405E-01, 8.662E-01, 9.221E-01, 1.001E+00, 1.114E+00, 1.249E+00, 1.353E+00, 1.451E+00, 1.486E+00, 1.498E+00, 1.427E+00, 1.313E+00, 1.157E+00, 9.930E-01, 8.011E-01, 6.242E-01, 4.737E-01, 3.611E-01, 2.733E-01, 2.095E-01, 1.634E-01, 1.305E-01, 1.069E-01, 8.825E-02, 6.459E-02, 4.791E-02, 4.169E-02, 3.714E-02, 3.410E-02, 3.140E-02, 3.055E-02, 2.840E-02, 2.879E-02, 2.370E-02, 1.985E-02, 2.011E-02, 2.221E-02, 2.104E-02, 2.172E-02}, // STtb.root
     { 2.524E-04, 2.272E-02, 3.015E-02, 4.811E-02, 6.613E-02, 1.166E-01, 8.986E-02, 9.320E-02, 8.697E-02, 2.616E-01, 3.126E-01, 4.274E-01, 5.218E-01, 5.508E-01, 5.572E-01, 6.109E-01, 6.644E-01, 7.641E-01, 8.579E-01, 9.410E-01, 1.011E+00, 1.101E+00, 1.171E+00, 1.217E+00, 1.217E+00, 1.242E+00, 1.264E+00, 1.290E+00, 1.302E+00, 1.316E+00, 1.320E+00, 1.262E+00, 1.242E+00, 1.188E+00, 1.142E+00, 1.082E+00, 1.037E+00, 1.021E+00, 9.504E-01, 9.096E-01, 9.141E-01, 9.127E-01, 9.483E-01, 1.012E+00, 1.105E+00, 1.196E+00, 1.381E+00, 1.466E+00, 1.537E+00, 1.586E+00, 1.562E+00, 1.502E+00, 1.386E+00, 1.223E+00, 1.031E+00, 8.557E-01, 6.664E-01, 4.988E-01, 3.733E-01, 2.933E-01, 2.233E-01, 1.655E-01, 1.344E-01, 1.117E-01, 8.697E-02, 6.509E-02, 4.821E-02, 4.217E-02, 3.917E-02, 3.587E-02, 2.276E-02, 1.341E-02, 1.659E-02, 1.770E-02, 2.239E-02, 1.587E-02, 4.953E-03, 1.582E-02, 1.995E-03, 2.952E-03}, // STtWt.root
     { 2.525E-04, 1.920E-02, 3.578E-02, 5.685E-02, 6.580E-02, 8.489E-02, 9.872E-02, 1.758E-01, 1.057E-01, 2.146E-01, 3.711E-01, 4.746E-01, 5.018E-01, 5.138E-01, 5.571E-01, 5.973E-01, 6.926E-01, 7.738E-01, 8.806E-01, 9.605E-01, 1.030E+00, 1.112E+00, 1.155E+00, 1.208E+00, 1.228E+00, 1.230E+00, 1.253E+00, 1.260E+00, 1.313E+00, 1.313E+00, 1.316E+00, 1.252E+00, 1.244E+00, 1.189E+00, 1.123E+00, 1.089E+00, 1.050E+00, 1.009E+00, 9.563E-01, 9.101E-01, 9.144E-01, 9.259E-01, 9.541E-01, 9.984E-01, 1.090E+00, 1.188E+00, 1.343E+00, 1.418E+00, 1.508E+00, 1.597E+00, 1.524E+00, 1.492E+00, 1.412E+00, 1.235E+00, 1.051E+00, 8.334E-01, 6.719E-01, 4.986E-01, 3.816E-01, 2.919E-01, 2.241E-01, 1.622E-01, 1.398E-01, 1.097E-01, 7.918E-02, 6.530E-02, 5.009E-02, 4.123E-02, 3.532E-02, 3.115E-02, 2.541E-02, 1.987E-02, 1.472E-02, 3.089E-02, 7.077E-03, 1.808E-02, 1.098E-02, 1.416E-02, 2.256E-03, 9.865E-04}, // STtWtb.root
     { 2.331E-04, 2.924E-02, 2.930E-02, 5.461E-02, 5.358E-02, 8.473E-02, 1.206E-01, 1.285E-01, 8.591E-02, 2.072E-01, 3.396E-01, 4.317E-01, 5.165E-01, 5.538E-01, 5.703E-01, 6.039E-01, 6.755E-01, 7.756E-01, 8.745E-01, 9.504E-01, 1.031E+00, 1.098E+00, 1.169E+00, 1.209E+00, 1.232E+00, 1.238E+00, 1.249E+00, 1.272E+00, 1.303E+00, 1.316E+00, 1.310E+00, 1.269E+00, 1.233E+00, 1.188E+00, 1.134E+00, 1.086E+00, 1.049E+00, 1.013E+00, 9.595E-01, 9.150E-01, 9.024E-01, 9.170E-01, 9.448E-01, 1.002E+00, 1.093E+00, 1.213E+00, 1.367E+00, 1.443E+00, 1.539E+00, 1.599E+00, 1.571E+00, 1.506E+00, 1.389E+00, 1.224E+00, 1.047E+00, 8.358E-01, 6.540E-01, 5.047E-01, 3.828E-01, 2.893E-01, 2.235E-01, 1.739E-01, 1.379E-01, 1.072E-01, 8.874E-02, 6.606E-02, 4.820E-02, 4.185E-02, 3.677E-02, 3.361E-02, 2.837E-02, 2.211E-02, 1.986E-02, 1.897E-02, 1.517E-02, 1.130E-02, 6.888E-03, 6.366E-03, 3.508E-03, 2.080E-03}, // TThad.root
     { 2.254E-04, 2.407E-02, 2.735E-02, 5.062E-02, 5.381E-02, 8.831E-02, 1.038E-01, 1.319E-01, 8.389E-02, 2.025E-01, 3.305E-01, 4.264E-01, 5.094E-01, 5.412E-01, 5.726E-01, 6.181E-01, 6.852E-01, 7.875E-01, 8.823E-01, 9.591E-01, 1.035E+00, 1.106E+00, 1.172E+00, 1.215E+00, 1.239E+00, 1.243E+00, 1.248E+00, 1.270E+00, 1.306E+00, 1.312E+00, 1.311E+00, 1.274E+00, 1.231E+00, 1.188E+00, 1.138E+00, 1.090E+00, 1.048E+00, 1.014E+00, 9.596E-01, 9.117E-01, 9.035E-01, 9.157E-01, 9.553E-01, 1.005E+00, 1.094E+00, 1.205E+00, 1.355E+00, 1.441E+00, 1.547E+00, 1.610E+00, 1.564E+00, 1.498E+00, 1.383E+00, 1.221E+00, 1.042E+00, 8.369E-01, 6.572E-01, 5.034E-01, 3.822E-01, 2.897E-01, 2.227E-01, 1.735E-01, 1.377E-01, 1.092E-01, 8.597E-02, 6.611E-02, 4.864E-02, 4.217E-02, 3.610E-02, 3.448E-02, 2.998E-02, 1.819E-02, 2.252E-02, 1.808E-02, 1.249E-02, 9.724E-03, 8.496E-03, 7.632E-03, 4.044E-03, 2.145E-03}, // TT1L.root
     { 2.255E-04, 2.669E-02, 3.410E-02, 4.843E-02, 5.155E-02, 8.500E-02, 1.020E-01, 1.469E-01, 9.271E-02, 2.018E-01, 3.409E-01, 4.197E-01, 5.025E-01, 5.331E-01, 5.545E-01, 6.048E-01, 6.748E-01, 7.715E-01, 8.701E-01, 9.533E-01, 1.039E+00, 1.105E+00, 1.168E+00, 1.221E+00, 1.239E+00, 1.248E+00, 1.261E+00, 1.275E+00, 1.316E+00, 1.316E+00, 1.319E+00, 1.277E+00, 1.236E+00, 1.186E+00, 1.135E+00, 1.088E+00, 1.055E+00, 1.021E+00, 9.625E-01, 9.145E-01, 9.063E-01, 9.175E-01, 9.476E-01, 1.008E+00, 1.092E+00, 1.204E+00, 1.357E+00, 1.435E+00, 1.539E+00, 1.598E+00, 1.558E+00, 1.508E+00, 1.372E+00, 1.216E+00, 1.043E+00, 8.292E-01, 6.647E-01, 5.023E-01, 3.832E-01, 2.891E-01, 2.207E-01, 1.733E-01, 1.371E-01, 1.066E-01, 8.507E-02, 6.755E-02, 4.859E-02, 4.064E-02, 3.683E-02, 3.264E-02, 3.035E-02, 2.362E-02, 2.244E-02, 2.072E-02, 1.039E-02, 1.137E-02, 8.760E-03, 5.474E-03, 5.010E-03, 1.898E-03}, // TT2L.root
     { 1.772E-01, 3.094E+00, 2.992E+00, 2.524E+00, 1.382E+00, 1.354E+00, 1.211E+00, 1.157E+00, 4.959E-01, 9.533E-01, 1.070E+00, 1.026E+00, 1.017E+00, 9.031E-01, 8.242E-01, 7.996E-01, 8.086E-01, 8.686E-01, 9.374E-01, 9.855E-01, 1.035E+00, 1.086E+00, 1.129E+00, 1.157E+00, 1.165E+00, 1.168E+00, 1.172E+00, 1.182E+00, 1.211E+00, 1.211E+00, 1.210E+00, 1.176E+00, 1.141E+00, 1.090E+00, 1.037E+00, 9.940E-01, 9.564E-01, 9.293E-01, 8.809E-01, 8.321E-01, 8.272E-01, 8.395E-01, 8.688E-01, 9.167E-01, 1.004E+00, 1.111E+00, 1.250E+00, 1.351E+00, 1.447E+00, 1.488E+00, 1.493E+00, 1.425E+00, 1.310E+00, 1.166E+00, 9.898E-01, 7.988E-01, 6.268E-01, 4.762E-01, 3.586E-01, 2.741E-01, 2.099E-01, 1.638E-01, 1.309E-01, 1.061E-01, 8.872E-02, 6.462E-02, 4.790E-02, 4.185E-02, 3.719E-02, 3.381E-02, 3.123E-02, 2.968E-02, 2.920E-02, 2.868E-02, 2.262E-02, 1.972E-02, 1.983E-02, 2.191E-02, 2.216E-02, 2.241E-02}, // TTMtt1000.root
     { 2.484E-04, 3.314E-02, 2.505E-02, 5.351E-02, 5.845E-02, 8.319E-02, 1.214E-01, 1.358E-01, 8.326E-02, 2.195E-01, 3.344E-01, 4.249E-01, 5.228E-01, 5.380E-01, 5.756E-01, 6.279E-01, 6.836E-01, 7.680E-01, 8.780E-01, 9.480E-01, 1.027E+00, 1.106E+00, 1.170E+00, 1.213E+00, 1.235E+00, 1.234E+00, 1.244E+00, 1.270E+00, 1.302E+00, 1.314E+00, 1.311E+00, 1.277E+00, 1.230E+00, 1.185E+00, 1.127E+00, 1.084E+00, 1.047E+00, 1.017E+00, 9.545E-01, 9.079E-01, 9.071E-01, 9.150E-01, 9.486E-01, 1.003E+00, 1.094E+00, 1.208E+00, 1.351E+00, 1.455E+00, 1.537E+00, 1.608E+00, 1.550E+00, 1.484E+00, 1.394E+00, 1.208E+00, 1.039E+00, 8.163E-01, 6.552E-01, 5.030E-01, 3.807E-01, 2.884E-01, 2.207E-01, 1.739E-01, 1.380E-01, 1.090E-01, 8.454E-02, 6.481E-02, 4.800E-02, 4.329E-02, 3.769E-02, 3.011E-02, 3.116E-02, 2.145E-02, 1.653E-02, 2.191E-02, 8.582E-03, 9.030E-03, 6.145E-03, 9.005E-03, 6.180E-03, 1.561E-03}, // TTMtt700.root
     { 1.721E-01, 3.587E+00, 2.567E+00, 2.539E+00, 1.440E+00, 1.307E+00, 1.270E+00, 1.140E+00, 4.981E-01, 9.379E-01, 1.071E+00, 1.031E+00, 1.014E+00, 9.073E-01, 8.261E-01, 7.991E-01, 8.105E-01, 8.694E-01, 9.324E-01, 9.846E-01, 1.033E+00, 1.088E+00, 1.127E+00, 1.155E+00, 1.167E+00, 1.168E+00, 1.177E+00, 1.184E+00, 1.210E+00, 1.212E+00, 1.207E+00, 1.181E+00, 1.139E+00, 1.089E+00, 1.037E+00, 9.914E-01, 9.576E-01, 9.284E-01, 8.787E-01, 8.341E-01, 8.294E-01, 8.385E-01, 8.714E-01, 9.182E-01, 1.001E+00, 1.113E+00, 1.249E+00, 1.345E+00, 1.438E+00, 1.488E+00, 1.491E+00, 1.428E+00, 1.311E+00, 1.164E+00, 9.926E-01, 8.013E-01, 6.281E-01, 4.739E-01, 3.604E-01, 2.731E-01, 2.093E-01, 1.642E-01, 1.310E-01, 1.067E-01, 8.836E-02, 6.496E-02, 4.798E-02, 4.200E-02, 3.726E-02, 3.399E-02, 3.137E-02, 3.037E-02, 2.772E-02, 2.908E-02, 2.355E-02, 1.953E-02, 2.041E-02, 2.056E-02, 2.395E-02, 2.238E-02}, // ttW.root
     { 1.653E-01, 3.049E+00, 3.158E+00, 2.457E+00, 1.344E+00, 1.382E+00, 1.261E+00, 1.053E+00, 4.963E-01, 9.488E-01, 1.041E+00, 1.028E+00, 1.011E+00, 9.054E-01, 8.352E-01, 7.969E-01, 8.128E-01, 8.683E-01, 9.366E-01, 9.867E-01, 1.035E+00, 1.087E+00, 1.129E+00, 1.154E+00, 1.165E+00, 1.167E+00, 1.169E+00, 1.184E+00, 1.213E+00, 1.213E+00, 1.210E+00, 1.177E+00, 1.142E+00, 1.086E+00, 1.042E+00, 9.978E-01, 9.549E-01, 9.259E-01, 8.790E-01, 8.321E-01, 8.262E-01, 8.368E-01, 8.715E-01, 9.208E-01, 1.003E+00, 1.120E+00, 1.250E+00, 1.341E+00, 1.452E+00, 1.486E+00, 1.490E+00, 1.426E+00, 1.316E+00, 1.165E+00, 9.911E-01, 7.971E-01, 6.239E-01, 4.728E-01, 3.581E-01, 2.729E-01, 2.101E-01, 1.645E-01, 1.302E-01, 1.069E-01, 8.822E-02, 6.455E-02, 4.843E-02, 4.176E-02, 3.755E-02, 3.406E-02, 3.143E-02, 2.981E-02, 2.888E-02, 2.811E-02, 2.183E-02, 2.039E-02, 2.083E-02, 2.040E-02, 2.145E-02, 2.481E-02}, // ttZ.root
     { 2.547E-04, 2.635E-02, 3.186E-02, 6.346E-02, 6.862E-02, 7.956E-02, 1.178E-01, 1.431E-01, 1.130E-01, 2.162E-01, 3.445E-01, 5.035E-01, 5.077E-01, 5.344E-01, 5.807E-01, 6.145E-01, 6.889E-01, 7.654E-01, 8.876E-01, 9.516E-01, 1.029E+00, 1.118E+00, 1.172E+00, 1.219E+00, 1.243E+00, 1.225E+00, 1.235E+00, 1.283E+00, 1.295E+00, 1.285E+00, 1.313E+00, 1.278E+00, 1.204E+00, 1.196E+00, 1.132E+00, 1.090E+00, 1.034E+00, 1.009E+00, 9.611E-01, 9.061E-01, 9.037E-01, 8.830E-01, 9.359E-01, 9.849E-01, 1.096E+00, 1.210E+00, 1.349E+00, 1.442E+00, 1.575E+00, 1.614E+00, 1.587E+00, 1.486E+00, 1.383E+00, 1.252E+00, 1.023E+00, 8.509E-01, 6.642E-01, 4.966E-01, 3.796E-01, 2.852E-01, 2.211E-01, 1.717E-01, 1.380E-01, 1.073E-01, 8.364E-02, 6.239E-02, 4.754E-02, 3.967E-02, 3.401E-02, 3.257E-02, 2.678E-02, 1.485E-02, 1.820E-02, 1.432E-02, 1.881E-02, 1.170E-02, 1.317E-02, 4.844E-03, 2.146E-03, 1.013E-03}, // ttH.root
     { 2.216E-04, 1.980E-02, 2.775E-02, 5.618E-02, 6.327E-02, 8.423E-02, 1.514E-01, 1.537E-01, 8.270E-02, 2.179E-01, 3.597E-01, 3.981E-01, 5.384E-01, 5.653E-01, 5.959E-01, 6.212E-01, 7.120E-01, 7.728E-01, 8.739E-01, 9.605E-01, 1.027E+00, 1.100E+00, 1.168E+00, 1.202E+00, 1.249E+00, 1.211E+00, 1.233E+00, 1.273E+00, 1.314E+00, 1.320E+00, 1.312E+00, 1.245E+00, 1.213E+00, 1.188E+00, 1.111E+00, 1.081E+00, 1.050E+00, 9.985E-01, 9.539E-01, 9.085E-01, 8.980E-01, 9.153E-01, 9.461E-01, 1.000E+00, 1.093E+00, 1.232E+00, 1.367E+00, 1.451E+00, 1.565E+00, 1.621E+00, 1.557E+00, 1.498E+00, 1.405E+00, 1.245E+00, 1.030E+00, 8.297E-01, 6.626E-01, 5.017E-01, 3.767E-01, 2.916E-01, 2.260E-01, 1.730E-01, 1.321E-01, 1.140E-01, 9.504E-02, 6.945E-02, 5.060E-02, 4.209E-02, 3.538E-02, 3.605E-02, 2.700E-02, 2.501E-02, 3.084E-02, 3.021E-02, 2.328E-02, 1.178E-02, 2.117E-02, 2.241E-02, 2.212E-02, 2.197E-03}, // WW.root
     { 2.780E-04, 8.098E-03, 3.021E-02, 6.737E-02, 7.952E-02, 1.595E-01, 1.857E-01, 2.031E-01, 8.771E-02, 2.663E-01, 2.995E-01, 4.475E-01, 5.352E-01, 5.844E-01, 5.648E-01, 5.671E-01, 6.348E-01, 7.772E-01, 8.690E-01, 9.440E-01, 1.051E+00, 1.107E+00, 1.162E+00, 1.202E+00, 1.232E+00, 1.236E+00, 1.229E+00, 1.268E+00, 1.315E+00, 1.325E+00, 1.283E+00, 1.265E+00, 1.230E+00, 1.187E+00, 1.146E+00, 1.099E+00, 1.045E+00, 1.006E+00, 9.449E-01, 9.232E-01, 8.846E-01, 8.940E-01, 9.416E-01, 1.021E+00, 1.107E+00, 1.207E+00, 1.362E+00, 1.479E+00, 1.563E+00, 1.639E+00, 1.598E+00, 1.543E+00, 1.417E+00, 1.193E+00, 1.040E+00, 8.271E-01, 6.762E-01, 5.097E-01, 3.874E-01, 2.947E-01, 2.148E-01, 1.690E-01, 1.277E-01, 1.013E-01, 9.006E-02, 6.879E-02, 4.579E-02, 4.281E-02, 2.978E-02, 3.363E-02, 1.850E-02, 1.849E-02, 1.559E-02, 3.141E-02, 1.288E-02, 4.452E-03, 3.110E-03, 2.063E-02, 1.110E-03, 8.433E-04}, // WZ.root
     { 4.404E-04, 2.189E-02, 2.998E-02, 2.170E-01, 1.238E-01, 1.246E-01, 2.204E-01, 2.548E-01, 1.285E-01, 2.959E-01, 3.905E-01, 4.891E-01, 5.662E-01, 5.521E-01, 4.857E-01, 5.475E-01, 6.026E-01, 7.025E-01, 8.437E-01, 9.157E-01, 9.996E-01, 1.097E+00, 1.165E+00, 1.205E+00, 1.215E+00, 1.234E+00, 1.248E+00, 1.254E+00, 1.267E+00, 1.303E+00, 1.309E+00, 1.274E+00, 1.219E+00, 1.183E+00, 1.128E+00, 1.083E+00, 1.042E+00, 1.010E+00, 9.590E-01, 9.171E-01, 9.045E-01, 8.824E-01, 9.577E-01, 9.642E-01, 1.102E+00, 1.169E+00, 1.371E+00, 1.401E+00, 1.525E+00, 1.621E+00, 1.480E+00, 1.516E+00, 1.417E+00, 1.122E+00, 9.566E-01, 8.333E-01, 6.682E-01, 4.800E-01, 3.807E-01, 2.790E-01, 2.173E-01, 1.752E-01, 1.400E-01, 1.049E-01, 8.155E-02, 5.558E-02, 4.681E-02, 4.468E-02, 3.768E-02, 3.461E-02, 3.369E-02, 3.100E-02, 3.172E-02, 3.230E-02, 2.216E-02, 1.925E-02, 2.410E-02, 4.743E-03, 9.372E-03, 3.806E-04}, // ZZ.root
     { 1.683E-01, 9.118E+00, 3.564E+00, 2.958E+00, 1.334E+00, 1.408E+00, 1.251E+00, 1.182E+00, 5.021E-01, 9.346E-01, 1.074E+00, 1.103E+00, 1.010E+00, 9.259E-01, 8.248E-01, 8.020E-01, 8.028E-01, 8.682E-01, 9.274E-01, 9.827E-01, 1.032E+00, 1.079E+00, 1.115E+00, 1.173E+00, 1.175E+00, 1.164E+00, 1.176E+00, 1.172E+00, 1.226E+00, 1.204E+00, 1.201E+00, 1.165E+00, 1.134E+00, 1.097E+00, 1.032E+00, 9.918E-01, 9.563E-01, 9.290E-01, 8.867E-01, 8.345E-01, 8.321E-01, 8.328E-01, 8.642E-01, 9.061E-01, 9.994E-01, 1.110E+00, 1.263E+00, 1.358E+00, 1.446E+00, 1.472E+00, 1.480E+00, 1.420E+00, 1.296E+00, 1.165E+00, 9.999E-01, 8.184E-01, 6.337E-01, 4.715E-01, 3.637E-01, 2.727E-01, 2.128E-01, 1.672E-01, 1.327E-01, 1.109E-01, 9.047E-02, 6.741E-02, 4.784E-02, 4.023E-02, 3.831E-02, 3.498E-02, 3.057E-02, 2.996E-02, 2.939E-02, 2.884E-02, 2.456E-02, 1.901E-02, 2.054E-02, 2.336E-02, 1.814E-02, 2.129E-02}, // TpTp700.root
     { 1.816E-01, 3.665E+00, 2.149E+00, 2.252E+00, 1.367E+00, 1.290E+00, 1.325E+00, 9.709E-01, 4.515E-01, 8.712E-01, 1.073E+00, 1.052E+00, 1.017E+00, 9.196E-01, 8.591E-01, 7.895E-01, 8.197E-01, 8.676E-01, 9.293E-01, 9.786E-01, 1.033E+00, 1.079E+00, 1.128E+00, 1.151E+00, 1.172E+00, 1.174E+00, 1.181E+00, 1.177E+00, 1.206E+00, 1.224E+00, 1.202E+00, 1.167E+00, 1.148E+00, 1.093E+00, 1.045E+00, 9.968E-01, 9.462E-01, 9.207E-01, 8.796E-01, 8.340E-01, 8.173E-01, 8.414E-01, 8.778E-01, 9.285E-01, 9.967E-01, 1.107E+00, 1.239E+00, 1.340E+00, 1.455E+00, 1.512E+00, 1.488E+00, 1.436E+00, 1.339E+00, 1.158E+00, 1.003E+00, 7.870E-01, 6.327E-01, 4.756E-01, 3.580E-01, 2.702E-01, 2.072E-01, 1.661E-01, 1.305E-01, 1.070E-01, 9.020E-02, 6.394E-02, 4.857E-02, 4.074E-02, 3.761E-02, 3.408E-02, 3.169E-02, 3.134E-02, 2.761E-02, 2.577E-02, 2.036E-02, 2.069E-02, 1.801E-02, 1.743E-02, 1.668E-02, 2.325E-02}, // TpTp1000.root
     { 2.243E-01, 2.654E+00, 2.334E+00, 2.392E+00, 1.563E+00, 1.265E+00, 1.451E+00, 1.096E+00, 5.347E-01, 9.591E-01, 1.045E+00, 1.109E+00, 1.013E+00, 8.996E-01, 8.355E-01, 7.965E-01, 8.081E-01, 8.730E-01, 9.315E-01, 9.924E-01, 1.035E+00, 1.083E+00, 1.129E+00, 1.161E+00, 1.178E+00, 1.173E+00, 1.172E+00, 1.175E+00, 1.208E+00, 1.225E+00, 1.189E+00, 1.159E+00, 1.150E+00, 1.086E+00, 1.032E+00, 9.957E-01, 9.539E-01, 9.352E-01, 8.767E-01, 8.315E-01, 8.334E-01, 8.330E-01, 8.566E-01, 9.186E-01, 1.009E+00, 1.129E+00, 1.250E+00, 1.342E+00, 1.442E+00, 1.523E+00, 1.497E+00, 1.447E+00, 1.308E+00, 1.166E+00, 1.005E+00, 8.039E-01, 6.337E-01, 4.779E-01, 3.574E-01, 2.721E-01, 2.053E-01, 1.638E-01, 1.285E-01, 1.022E-01, 8.569E-02, 6.474E-02, 4.848E-02, 4.168E-02, 3.661E-02, 3.625E-02, 3.308E-02, 3.115E-02, 3.082E-02, 2.730E-02, 2.590E-02, 1.859E-02, 1.772E-02, 2.499E-02, 2.129E-02, 2.020E-02}, // TpTp1100.root
     { 2.106E-01, 1.924E+00, 2.030E+00, 2.340E+00, 1.468E+00, 1.719E+00, 1.496E+00, 1.179E+00, 4.445E-01, 9.348E-01, 1.063E+00, 9.988E-01, 1.034E+00, 9.068E-01, 8.234E-01, 7.943E-01, 8.123E-01, 8.627E-01, 9.299E-01, 9.686E-01, 1.033E+00, 1.086E+00, 1.129E+00, 1.173E+00, 1.162E+00, 1.153E+00, 1.167E+00, 1.179E+00, 1.222E+00, 1.205E+00, 1.211E+00, 1.187E+00, 1.142E+00, 1.088E+00, 1.048E+00, 9.889E-01, 9.426E-01, 9.226E-01, 8.844E-01, 8.355E-01, 8.402E-01, 8.427E-01, 8.674E-01, 9.280E-01, 9.988E-01, 1.122E+00, 1.247E+00, 1.363E+00, 1.474E+00, 1.488E+00, 1.495E+00, 1.404E+00, 1.306E+00, 1.150E+00, 9.705E-01, 8.050E-01, 6.325E-01, 4.759E-01, 3.613E-01, 2.751E-01, 2.073E-01, 1.669E-01, 1.305E-01, 1.068E-01, 8.796E-02, 6.574E-02, 4.827E-02, 4.084E-02, 3.620E-02, 3.406E-02, 3.191E-02, 2.864E-02, 3.068E-02, 3.145E-02, 2.347E-02, 2.252E-02, 1.975E-02, 2.174E-02, 2.962E-02, 1.943E-02}, // TpTp1200.root
     { 1.523E-01, 2.439E+00, 2.502E+00, 2.307E+00, 1.273E+00, 1.217E+00, 1.221E+00, 1.036E+00, 5.165E-01, 9.453E-01, 1.020E+00, 1.020E+00, 1.034E+00, 8.935E-01, 8.389E-01, 7.957E-01, 7.980E-01, 8.616E-01, 9.450E-01, 9.884E-01, 1.030E+00, 1.111E+00, 1.121E+00, 1.159E+00, 1.161E+00, 1.182E+00, 1.176E+00, 1.191E+00, 1.205E+00, 1.213E+00, 1.212E+00, 1.173E+00, 1.139E+00, 1.081E+00, 1.049E+00, 1.002E+00, 9.466E-01, 9.299E-01, 8.915E-01, 8.328E-01, 8.282E-01, 8.458E-01, 8.701E-01, 9.194E-01, 1.001E+00, 1.098E+00, 1.236E+00, 1.329E+00, 1.438E+00, 1.497E+00, 1.479E+00, 1.391E+00, 1.335E+00, 1.180E+00, 9.951E-01, 8.059E-01, 6.225E-01, 4.756E-01, 3.683E-01, 2.694E-01, 2.087E-01, 1.588E-01, 1.266E-01, 1.059E-01, 8.720E-02, 6.254E-02, 4.819E-02, 4.152E-02, 3.708E-02, 3.168E-02, 3.157E-02, 3.276E-02, 2.723E-02, 2.672E-02, 2.156E-02, 1.943E-02, 2.719E-02, 2.280E-02, 1.922E-02, 2.076E-02}, // TpTp1300.root
     { 2.093E-01, 1.955E+00, 9.168E+00, 2.349E+00, 1.495E+00, 1.338E+00, 1.040E+00, 1.076E+00, 5.682E-01, 9.235E-01, 1.119E+00, 1.003E+00, 1.045E+00, 8.971E-01, 8.249E-01, 8.091E-01, 7.984E-01, 8.729E-01, 9.288E-01, 9.994E-01, 1.038E+00, 1.087E+00, 1.132E+00, 1.166E+00, 1.178E+00, 1.182E+00, 1.163E+00, 1.195E+00, 1.202E+00, 1.208E+00, 1.220E+00, 1.187E+00, 1.152E+00, 1.080E+00, 1.037E+00, 9.869E-01, 9.585E-01, 9.223E-01, 8.825E-01, 8.320E-01, 8.173E-01, 8.356E-01, 8.663E-01, 9.292E-01, 1.004E+00, 1.112E+00, 1.242E+00, 1.344E+00, 1.459E+00, 1.481E+00, 1.505E+00, 1.409E+00, 1.316E+00, 1.161E+00, 9.854E-01, 7.999E-01, 6.339E-01, 4.678E-01, 3.645E-01, 2.658E-01, 2.058E-01, 1.624E-01, 1.277E-01, 1.065E-01, 8.755E-02, 6.555E-02, 4.663E-02, 4.267E-02, 3.623E-02, 3.201E-02, 3.363E-02, 3.025E-02, 2.602E-02, 2.460E-02, 2.271E-02, 1.765E-02, 1.926E-02, 1.963E-02, 2.908E-02, 2.852E-02}, // TpTp1400.root
     { 2.348E-01, 3.728E+00, 2.018E+00, 2.879E+00, 1.011E+00, 1.316E+00, 1.225E+00, 1.119E+00, 4.709E-01, 9.432E-01, 1.017E+00, 1.036E+00, 1.003E+00, 9.033E-01, 8.257E-01, 7.965E-01, 8.014E-01, 8.643E-01, 9.231E-01, 1.000E+00, 1.032E+00, 1.086E+00, 1.121E+00, 1.169E+00, 1.175E+00, 1.165E+00, 1.154E+00, 1.179E+00, 1.209E+00, 1.229E+00, 1.190E+00, 1.188E+00, 1.138E+00, 1.094E+00, 1.025E+00, 1.004E+00, 9.594E-01, 9.370E-01, 8.798E-01, 8.409E-01, 8.275E-01, 8.399E-01, 8.757E-01, 9.169E-01, 1.002E+00, 1.106E+00, 1.243E+00, 1.351E+00, 1.429E+00, 1.490E+00, 1.527E+00, 1.421E+00, 1.328E+00, 1.172E+00, 9.914E-01, 8.037E-01, 6.246E-01, 4.722E-01, 3.603E-01, 2.705E-01, 2.087E-01, 1.632E-01, 1.306E-01, 1.068E-01, 8.774E-02, 6.288E-02, 5.001E-02, 3.944E-02, 3.977E-02, 3.202E-02, 3.029E-02, 3.043E-02, 2.748E-02, 3.054E-02, 2.120E-02, 1.604E-02, 1.744E-02, 2.340E-02, 1.724E-02, 2.176E-02}, // TpTp1500.root
     { 1.566E-01, 3.511E+00, 2.246E+00, 2.278E+00, 1.343E+00, 1.220E+00, 1.354E+00, 1.078E+00, 5.560E-01, 9.739E-01, 1.183E+00, 1.105E+00, 1.039E+00, 9.057E-01, 8.551E-01, 8.030E-01, 8.216E-01, 8.706E-01, 9.400E-01, 1.002E+00, 1.009E+00, 1.082E+00, 1.130E+00, 1.141E+00, 1.179E+00, 1.159E+00, 1.173E+00, 1.163E+00, 1.202E+00, 1.222E+00, 1.204E+00, 1.175E+00, 1.151E+00, 1.090E+00, 1.046E+00, 9.802E-01, 9.660E-01, 9.283E-01, 8.798E-01, 8.405E-01, 8.230E-01, 8.446E-01, 8.623E-01, 9.343E-01, 1.023E+00, 1.109E+00, 1.236E+00, 1.340E+00, 1.473E+00, 1.473E+00, 1.511E+00, 1.400E+00, 1.284E+00, 1.170E+00, 9.897E-01, 7.999E-01, 6.240E-01, 4.698E-01, 3.540E-01, 2.763E-01, 2.057E-01, 1.656E-01, 1.322E-01, 1.063E-01, 8.714E-02, 6.585E-02, 5.075E-02, 4.058E-02, 3.795E-02, 3.435E-02, 2.940E-02, 2.899E-02, 2.980E-02, 3.485E-02, 3.006E-02, 1.845E-02, 1.880E-02, 1.763E-02, 1.669E-02, 2.562E-02}, // TpTp1600.root
     { 2.977E-01, 1.748E+00, 2.152E+00, 2.481E+00, 1.233E+00, 1.015E+00, 1.100E+00, 1.601E+00, 4.386E-01, 8.484E-01, 1.044E+00, 1.032E+00, 1.031E+00, 9.199E-01, 8.199E-01, 7.843E-01, 8.351E-01, 8.682E-01, 9.269E-01, 1.003E+00, 1.020E+00, 1.085E+00, 1.131E+00, 1.173E+00, 1.179E+00, 1.160E+00, 1.164E+00, 1.166E+00, 1.216E+00, 1.210E+00, 1.214E+00, 1.196E+00, 1.127E+00, 1.083E+00, 1.039E+00, 9.867E-01, 9.439E-01, 9.491E-01, 8.902E-01, 8.389E-01, 8.354E-01, 8.628E-01, 8.554E-01, 9.302E-01, 9.948E-01, 1.102E+00, 1.248E+00, 1.323E+00, 1.461E+00, 1.465E+00, 1.484E+00, 1.402E+00, 1.283E+00, 1.188E+00, 9.855E-01, 7.939E-01, 6.287E-01, 4.759E-01, 3.535E-01, 2.707E-01, 2.070E-01, 1.640E-01, 1.338E-01, 1.046E-01, 8.914E-02, 6.711E-02, 4.797E-02, 3.984E-02, 3.990E-02, 3.717E-02, 3.072E-02, 2.785E-02, 2.549E-02, 2.456E-02, 2.090E-02, 2.571E-02, 2.173E-02, 1.707E-02, 2.907E-02, 1.623E-02}, // TpTp1700.root
     { 1.526E-01, 2.053E+00, 4.513E+00, 4.162E+00, 1.914E+00, 9.058E-01, 1.366E+00, 9.259E-01, 4.488E-01, 1.056E+00, 9.620E-01, 1.049E+00, 1.023E+00, 9.690E-01, 8.464E-01, 7.974E-01, 8.210E-01, 8.648E-01, 9.480E-01, 9.687E-01, 1.034E+00, 1.082E+00, 1.133E+00, 1.170E+00, 1.155E+00, 1.179E+00, 1.178E+00, 1.167E+00, 1.235E+00, 1.222E+00, 1.232E+00, 1.168E+00, 1.129E+00, 1.092E+00, 1.031E+00, 1.004E+00, 9.656E-01, 9.236E-01, 8.838E-01, 8.166E-01, 8.390E-01, 8.349E-01, 8.558E-01, 9.112E-01, 9.572E-01, 1.142E+00, 1.256E+00, 1.355E+00, 1.436E+00, 1.481E+00, 1.435E+00, 1.386E+00, 1.288E+00, 1.170E+00, 1.011E+00, 7.926E-01, 6.417E-01, 4.737E-01, 3.663E-01, 2.657E-01, 2.120E-01, 1.623E-01, 1.323E-01, 1.065E-01, 9.456E-02, 6.326E-02, 4.770E-02, 4.204E-02, 3.611E-02, 3.331E-02, 3.037E-02, 2.568E-02, 4.057E-02, 3.642E-02, 2.675E-02, 1.710E-02, 2.370E-02, 2.301E-02, 3.136E-02, 1.498E-02}, // TpTp1800.root
     { 1.812E-01, 4.098E+00, 2.634E+00, 2.396E+00, 1.552E+00, 1.317E+00, 1.284E+00, 1.103E+00, 4.916E-01, 9.699E-01, 1.081E+00, 1.029E+00, 1.002E+00, 9.015E-01, 8.253E-01, 7.943E-01, 8.123E-01, 8.706E-01, 9.341E-01, 9.864E-01, 1.034E+00, 1.084E+00, 1.128E+00, 1.156E+00, 1.165E+00, 1.168E+00, 1.173E+00, 1.184E+00, 1.212E+00, 1.214E+00, 1.207E+00, 1.178E+00, 1.140E+00, 1.089E+00, 1.038E+00, 9.955E-01, 9.555E-01, 9.307E-01, 8.806E-01, 8.335E-01, 8.282E-01, 8.383E-01, 8.666E-01, 9.195E-01, 9.992E-01, 1.114E+00, 1.251E+00, 1.345E+00, 1.446E+00, 1.489E+00, 1.492E+00, 1.429E+00, 1.313E+00, 1.163E+00, 9.933E-01, 8.001E-01, 6.284E-01, 4.764E-01, 3.594E-01, 2.731E-01, 2.093E-01, 1.637E-01, 1.305E-01, 1.065E-01, 8.865E-02, 6.412E-02, 4.768E-02, 4.140E-02, 3.716E-02, 3.382E-02, 3.146E-02, 3.026E-02, 2.850E-02, 2.892E-02, 2.297E-02, 1.933E-02, 2.020E-02, 2.162E-02, 2.240E-02, 2.473E-02}, // WJ1200.root
     { 1.854E-01, 3.676E+00, 2.821E+00, 2.494E+00, 1.412E+00, 1.357E+00, 1.244E+00, 1.162E+00, 4.832E-01, 9.356E-01, 1.053E+00, 1.028E+00, 1.010E+00, 9.051E-01, 8.312E-01, 7.957E-01, 8.109E-01, 8.678E-01, 9.351E-01, 9.859E-01, 1.033E+00, 1.086E+00, 1.125E+00, 1.156E+00, 1.167E+00, 1.170E+00, 1.173E+00, 1.183E+00, 1.209E+00, 1.215E+00, 1.206E+00, 1.176E+00, 1.143E+00, 1.088E+00, 1.038E+00, 9.951E-01, 9.580E-01, 9.268E-01, 8.767E-01, 8.340E-01, 8.271E-01, 8.408E-01, 8.686E-01, 9.171E-01, 1.003E+00, 1.115E+00, 1.252E+00, 1.344E+00, 1.452E+00, 1.488E+00, 1.495E+00, 1.430E+00, 1.316E+00, 1.165E+00, 9.915E-01, 7.988E-01, 6.272E-01, 4.734E-01, 3.591E-01, 2.733E-01, 2.106E-01, 1.637E-01, 1.314E-01, 1.061E-01, 8.868E-02, 6.458E-02, 4.794E-02, 4.155E-02, 3.667E-02, 3.358E-02, 3.126E-02, 3.012E-02, 2.899E-02, 2.845E-02, 2.299E-02, 1.990E-02, 2.039E-02, 2.064E-02, 2.355E-02, 2.235E-02}, // WJ200.root
     { 1.839E-01, 3.598E+00, 2.653E+00, 2.662E+00, 1.387E+00, 1.324E+00, 1.245E+00, 1.133E+00, 5.023E-01, 9.332E-01, 1.060E+00, 1.033E+00, 1.017E+00, 9.017E-01, 8.255E-01, 7.944E-01, 8.123E-01, 8.701E-01, 9.369E-01, 9.856E-01, 1.036E+00, 1.086E+00, 1.131E+00, 1.157E+00, 1.166E+00, 1.165E+00, 1.175E+00, 1.182E+00, 1.211E+00, 1.211E+00, 1.207E+00, 1.180E+00, 1.140E+00, 1.089E+00, 1.037E+00, 9.960E-01, 9.587E-01, 9.286E-01, 8.773E-01, 8.299E-01, 8.298E-01, 8.380E-01, 8.684E-01, 9.215E-01, 9.972E-01, 1.113E+00, 1.247E+00, 1.347E+00, 1.447E+00, 1.486E+00, 1.493E+00, 1.427E+00, 1.313E+00, 1.164E+00, 9.933E-01, 7.997E-01, 6.274E-01, 4.745E-01, 3.587E-01, 2.737E-01, 2.107E-01, 1.635E-01, 1.303E-01, 1.068E-01, 8.833E-02, 6.480E-02, 4.810E-02, 4.198E-02, 3.677E-02, 3.396E-02, 3.168E-02, 2.977E-02, 2.923E-02, 2.872E-02, 2.244E-02, 1.972E-02, 2.035E-02, 2.193E-02, 2.182E-02, 2.511E-02}, // WJ2500.root
     { 1.838E-01, 3.418E+00, 3.158E+00, 2.698E+00, 1.415E+00, 1.312E+00, 1.260E+00, 1.175E+00, 4.934E-01, 9.305E-01, 1.068E+00, 1.033E+00, 1.007E+00, 9.027E-01, 8.285E-01, 7.956E-01, 8.078E-01, 8.673E-01, 9.330E-01, 9.846E-01, 1.034E+00, 1.086E+00, 1.130E+00, 1.154E+00, 1.167E+00, 1.169E+00, 1.172E+00, 1.185E+00, 1.213E+00, 1.213E+00, 1.210E+00, 1.181E+00, 1.140E+00, 1.088E+00, 1.039E+00, 9.934E-01, 9.549E-01, 9.281E-01, 8.801E-01, 8.320E-01, 8.268E-01, 8.380E-01, 8.687E-01, 9.175E-01, 1.002E+00, 1.117E+00, 1.250E+00, 1.347E+00, 1.452E+00, 1.492E+00, 1.494E+00, 1.431E+00, 1.316E+00, 1.165E+00, 9.914E-01, 8.006E-01, 6.269E-01, 4.717E-01, 3.605E-01, 2.734E-01, 2.109E-01, 1.642E-01, 1.304E-01, 1.053E-01, 8.881E-02, 6.408E-02, 4.785E-02, 4.172E-02, 3.681E-02, 3.361E-02, 3.129E-02, 3.010E-02, 2.892E-02, 2.889E-02, 2.262E-02, 1.984E-02, 2.049E-02, 2.003E-02, 2.178E-02, 2.362E-02}, // WJ400.root
     { 1.840E-01, 3.061E+00, 2.882E+00, 2.656E+00, 1.362E+00, 1.324E+00, 1.252E+00, 1.180E+00, 4.954E-01, 9.640E-01, 1.052E+00, 1.030E+00, 1.006E+00, 9.036E-01, 8.237E-01, 7.976E-01, 8.125E-01, 8.732E-01, 9.347E-01, 9.840E-01, 1.037E+00, 1.085E+00, 1.130E+00, 1.156E+00, 1.166E+00, 1.170E+00, 1.170E+00, 1.181E+00, 1.210E+00, 1.214E+00, 1.209E+00, 1.180E+00, 1.140E+00, 1.087E+00, 1.037E+00, 9.926E-01, 9.569E-01, 9.276E-01, 8.799E-01, 8.347E-01, 8.254E-01, 8.409E-01, 8.681E-01, 9.197E-01, 1.001E+00, 1.110E+00, 1.251E+00, 1.346E+00, 1.452E+00, 1.487E+00, 1.489E+00, 1.428E+00, 1.318E+00, 1.169E+00, 9.923E-01, 8.020E-01, 6.287E-01, 4.743E-01, 3.593E-01, 2.721E-01, 2.098E-01, 1.638E-01, 1.306E-01, 1.059E-01, 8.828E-02, 6.437E-02, 4.763E-02, 4.193E-02, 3.728E-02, 3.355E-02, 3.141E-02, 2.989E-02, 2.831E-02, 2.898E-02, 2.342E-02, 1.943E-02, 2.034E-02, 2.002E-02, 2.226E-02, 2.216E-02}, // WJ600.root
     { 1.658E-01, 3.110E+00, 2.537E+00, 2.618E+00, 1.368E+00, 1.275E+00, 1.253E+00, 1.144E+00, 4.908E-01, 9.375E-01, 1.069E+00, 1.024E+00, 1.012E+00, 9.021E-01, 8.249E-01, 7.980E-01, 8.126E-01, 8.685E-01, 9.351E-01, 9.875E-01, 1.034E+00, 1.087E+00, 1.130E+00, 1.156E+00, 1.168E+00, 1.170E+00, 1.173E+00, 1.181E+00, 1.210E+00, 1.211E+00, 1.208E+00, 1.179E+00, 1.137E+00, 1.089E+00, 1.038E+00, 9.952E-01, 9.573E-01, 9.280E-01, 8.795E-01, 8.327E-01, 8.286E-01, 8.378E-01, 8.680E-01, 9.205E-01, 9.989E-01, 1.117E+00, 1.249E+00, 1.341E+00, 1.446E+00, 1.489E+00, 1.488E+00, 1.430E+00, 1.310E+00, 1.162E+00, 9.915E-01, 8.026E-01, 6.287E-01, 4.745E-01, 3.612E-01, 2.726E-01, 2.102E-01, 1.646E-01, 1.310E-01, 1.059E-01, 8.859E-02, 6.427E-02, 4.789E-02, 4.155E-02, 3.728E-02, 3.381E-02, 3.140E-02, 2.978E-02, 2.927E-02, 2.945E-02, 2.328E-02, 1.880E-02, 2.082E-02, 2.053E-02, 2.100E-02, 2.378E-02} // WJ800.root
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
      
      //      if (ientry > 50) continue;
      
      if(jentry % 1000 ==0) std::cout<<"Completed "<<jentry<<" out of "<<nentries<<" events"<<std::endl;

      // ----------------------------------------------------------------------------
      // Filter input file by mass or decay
      // ----------------------------------------------------------------------------

      float confusionTruth = -1;
      
      if(isTTincMtt0to700 && ttbarMass_TTbarMassCalc >= 700.) continue;
      if(isTTincMtt0to1000 && ttbarMass_TTbarMassCalc >= 1000.) continue;
      if(isTTincMtt700to1000 && (ttbarMass_TTbarMassCalc < 700. || ttbarMass_TTbarMassCalc >= 1000.)) continue;
      if(isTTincMtt1000toInf && ttbarMass_TTbarMassCalc < 1000.) continue;
      if(outBWBW && !isBWBW_TpTpCalc) {confusionTruth = 0.5; continue;}
      if(outTZBW && !isTZBW_TpTpCalc) {confusionTruth = 1.5; continue;}
      if(outTHBW && !isTHBW_TpTpCalc) {confusionTruth = 2.5; continue;}
      if(outTZTH && !isTZTH_TpTpCalc) {confusionTruth = 3.5; continue;}
      if(outTZTZ && !isTZTZ_TpTpCalc) {confusionTruth = 4.5; continue;}
      if(outTHTH && !isTHTH_TpTpCalc) {confusionTruth = 5.5; continue;}
      if(outTWTW && !isTWTW_TpTpCalc) {confusionTruth = 6.5; continue;}
      if(outBZTW && !isBZTW_TpTpCalc) {confusionTruth = 7.5; continue;}
      if(outBHTW && !isBHTW_TpTpCalc) {confusionTruth = 8.5; continue;}
      if(outBZBH && !isBZBH_TpTpCalc) {confusionTruth = 9.5; continue;}
      if(outBZBZ && !isBZBZ_TpTpCalc) {confusionTruth = 10.5; continue;}
      if(outBHBH && !isBHBH_TpTpCalc) {confusionTruth = 11.5; continue;}

      if(isSig){
	if(confusionTruth < 6.0){
	  TTconfusionD->Fill(0.5,confusionTruth);
	  TTconfusionD->Fill(1.5,confusionTruth);
	  TTconfusionD->Fill(2.5,confusionTruth);
	  TTconfusionD->Fill(3.5,confusionTruth);
	  TTconfusionD->Fill(4.5,confusionTruth);
	  TTconfusionD->Fill(5.5,confusionTruth);
	  TTconfusionD->Fill(6.5,confusionTruth);
	  TTconfusionD->Fill(7.5,confusionTruth);
	  TTconfusionD->Fill(8.5,confusionTruth);
	  TTconfusionD->Fill(9.5,confusionTruth);
	}else{
	  BBconfusionD->Fill(0.5,confusionTruth-6.0);
	  BBconfusionD->Fill(1.5,confusionTruth-6.0);
	  BBconfusionD->Fill(2.5,confusionTruth-6.0);
	  BBconfusionD->Fill(3.5,confusionTruth-6.0);
	  BBconfusionD->Fill(4.5,confusionTruth-6.0);
	  BBconfusionD->Fill(5.5,confusionTruth-6.0);
	  BBconfusionD->Fill(6.5,confusionTruth-6.0);
	}
      }
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
      unsigned int deepak8size = dnn_H_DeepAK8Calc->size();
      if(deepak8size != ak8ptsize){
	std::cout << "Something's wrong! DeepAK8 has " << deepak8size << " jets, expected " << ak8ptsize << std::endl;
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
	if(pileupIndex < 1 || pileupIndex > 39){
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

          //Scale Factor 2: https://twiki.cern.ch/twiki/pub/CMS/EgammaIDRecipesRun2/2017_ElectronMVA90noiso_2D.pdf
	  if (leppt < 20) {
	    if (lepeta < -2.0) lepIdSF = 0.943;
	    else if (lepeta < -1.566) lepIdSF = 0.957;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 1.008;
	    else if (lepeta < 0.0) lepIdSF = 0.993;
	    else if (lepeta < 0.8) lepIdSF = 0.992;
	    else if (lepeta < 1.442) lepIdSF = 0.999;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.978;
	    else lepIdSF = 0.930; }
	  else if (leppt < 35) {
	    if (lepeta < -2.0) lepIdSF = 0.926;
	    else if (lepeta < -1.566) lepIdSF = 0.937;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.964;
	    else if (lepeta < 0.0) lepIdSF = 0.981;
	    else if (lepeta < 0.8) lepIdSF = 0.981;
	    else if (lepeta < 1.442) lepIdSF = 0.963;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.943;
	    else lepIdSF = 0.918; }
	  else if (leppt < 50) {
	    if (lepeta < -2.0) lepIdSF = 0.941;
	    else if (lepeta < -1.566) lepIdSF = 0.953;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.962;
	    else if (lepeta < 0.0) lepIdSF = 0.972;
	    else if (lepeta < 0.8) lepIdSF = 0.974;
	    else if (lepeta < 1.442) lepIdSF = 0.965;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.955;
	    else lepIdSF = 0.933; }
	  else if (leppt < 100) {
	    if (lepeta < -2.0) lepIdSF = 0.948;
	    else if (lepeta < -1.566) lepIdSF = 0.967;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.968;
	    else if (lepeta < 0.0) lepIdSF = 0.979;
	    else if (lepeta < 0.8) lepIdSF = 0.975;
	    else if (lepeta < 1.442) lepIdSF = 0.970;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.971;
	    else lepIdSF = 0.938; }
	  else if (leppt < 200) {
	    if (lepeta < -2.0) lepIdSF = 0.983;
	    else if (lepeta < -1.566) lepIdSF = 0.969;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.979;
	    else if (lepeta < 0.0) lepIdSF = 0.983;
	    else if (lepeta < 0.8) lepIdSF = 0.988;
	    else if (lepeta < 1.442) lepIdSF = 0.993;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.990;
	    else lepIdSF = 0.939; }
	  else {
	    if (lepeta < -2.0) lepIdSF = 0.922;
	    else if (lepeta < -1.566) lepIdSF = 0.985;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 1.007;
	    else if (lepeta < 0.0) lepIdSF = 0.993;
	    else if (lepeta < 0.8) lepIdSF = 0.959;
	    else if (lepeta < 1.442) lepIdSF = 1.013;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.949;
	    else lepIdSF = 1.057; }
	}
	if(isMuon){
	  std::string string_a = "Mu15_IsoVVVL_PFHT450";
	  std::string string_b = "Mu15_IsoVVVL_PFHT450_PFMET50";
	  std::string string_d = "Mu50_IsoVVVL_PFHT450";
	  std::string string_e = "Mu15_IsoVVVL_PFHT600";
	  std::string string_ORb = "Mu50";
	  std::string string_ORc = "TkMu50";
	  for(unsigned int itrig=0; itrig < vsSelMCTriggersMu_singleLepCalc->size(); itrig++){
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_a) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_b) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTrigger = 1;
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
	  std::string string_d = "Mu50_IsoVVVL_PFHT450";
	  std::string string_e = "Mu15_IsoVVVL_PFHT600";
	  std::string string_ORb = "Mu50";
	  std::string string_ORc = "TkMu50";
	  for(unsigned int itrig=0; itrig < vsSelTriggersMu_singleLepCalc->size(); itrig++){
	    if(vsSelTriggersMu_singleLepCalc->at(itrig).find(string_a) != std::string::npos && viSelTriggersMu_singleLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig).find(string_b) != std::string::npos && viSelTriggersMu_singleLepCalc->at(itrig) > 0) DataPastTrigger = 1;
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
      }

      MT_lepMet = sqrt(2*leppt*corr_met_singleLepCalc*(1 - cos(lepphi - corr_met_phi_singleLepCalc)));
      
      // ----------------------------------------------------------------------------
      // Loop over AK4 jets for calculations and pt ordering pair
      // ----------------------------------------------------------------------------

      NJets_JetSubCalc = 0;
      AK4HT = 0;
      int nskipped = 0;
      float deltaR1 = -1; float deltaR2 = -1;
      float ptRel1 = -1; float ptRel2 = -1;
      int ind1 = -1; int ind2 = -1;
      vector<pair<double,int>> jetptindpair;

      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc->size(); ijet++){

	// ----------------------------------------------------------------------------
	// Basic cuts   NEW NEW NEW NEW 2D cut right here
	// ----------------------------------------------------------------------------

	if(theJetPt_JetSubCalc->at(ijet) < jetPtCut || fabs(theJetEta_JetSubCalc->at(ijet)) > jetEtaCut) continue;
	
	jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc->at(ijet),theJetEta_JetSubCalc->at(ijet),theJetPhi_JetSubCalc->at(ijet),theJetEnergy_JetSubCalc->at(ijet));
	float deltaR = lepton_lv.DeltaR(jet_lv);
	float ptRel = lepton_lv.P()*(jet_lv.Vect().Cross(lepton_lv.Vect()).Mag()/jet_lv.P()/lepton_lv.P());
	if(deltaR < 0.4 && ptRel < 20){
	  nskipped += 1;
	  if(deltaR1 < 0){
	    deltaR1 = deltaR;
	    ptRel1 = ptRel;
	    ind1 = ijet;
	  }else{
	    if(deltaR2 < 0){
	      deltaR2 = deltaR;
	      ptRel2 = ptRel;
	      ind2 = ijet;
	    }else std::cout << "3rd close jet!" << std::endl;
	  }
	  continue; // not ONLY checking the closest jet, but should be impossible for 2 to be that close...
	}

	// ----------------------------------------------------------------------------
	// Counts and pt ordering pair
	// ----------------------------------------------------------------------------

	jetptindpair.push_back(std::make_pair(theJetPt_JetSubCalc->at(ijet),ijet));
	NJets_JetSubCalc+=1;
	AK4HT+=theJetPt_JetSubCalc->at(ijet);
      }

      if(nskipped > 1){
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "Weird thing! " << nskipped << " AK4s had DR < 0.4 && PtRel < 20!" << std::endl;
	std::cout << "dr1 = " << deltaR1 << ", dr2 = " << deltaR2 << std::endl;
	std::cout << "pt1 = " << ptRel1 << ", pt2 = " << ptRel2 << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
      }
	
      // ----------------------------------------------------------------------------
      // Loop over AK8 jets for calculations and pt ordering pair
      // ----------------------------------------------------------------------------

      NJetsAK8_JetSubCalc = 0;
      vector<pair<double,int>> jetak8ptindpair;      
      nskipped = 0;      
      deltaR1 = -1; deltaR2 = -1;
      ptRel1 = -1; ptRel2 = -1;
      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc->size(); ijet++){

        // ----------------------------------------------------------------------------                                  
        // Basic cuts    NEW NEW NEW NEW NEW 2D cut right here
        // ----------------------------------------------------------------------------                                  
	
        if(fabs(theJetAK8Eta_JetSubCalc->at(ijet)) > ak8EtaCut) continue;
        if(theJetAK8Pt_JetSubCalc->at(ijet) < ak8PtCut) continue;
        if(theJetAK8NjettinessTau1_JetSubCalc->at(ijet)==0) continue;
        if(theJetAK8NjettinessTau2_JetSubCalc->at(ijet)==0) continue;
	
	ak8_lv.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc->at(ijet),theJetAK8Eta_JetSubCalc->at(ijet),theJetAK8Phi_JetSubCalc->at(ijet),theJetAK8Energy_JetSubCalc->at(ijet));
	float deltaR = lepton_lv.DeltaR(ak8_lv);
	float ptRel = lepton_lv.P()*(ak8_lv.Vect().Cross(lepton_lv.Vect()).Mag()/ak8_lv.P()/lepton_lv.P());
	if(deltaR < 0.8 && ptRel < 20){
	  nskipped += 1;
	  if(deltaR1 < 0){
	    deltaR1 = deltaR;
	    ptRel1 = ptRel;
	  }else{
	    if(deltaR2 < 0){
	      deltaR2 = deltaR;
	      ptRel2 = ptRel;
	    }else std::cout << "3rd close jet!" << std::endl;
	  }
	  continue;   // not ONLY checking the closest jet, but should be impossible for 2 to be that close...
	}

        // ----------------------------------------------------------------------------                                  
        // Counters and pt ordering pair                                                                                  
        // ----------------------------------------------------------------------------                                  

	n_jetstotal++;	
        NJetsAK8_JetSubCalc += 1;
        jetak8ptindpair.push_back(std::make_pair(theJetAK8Pt_JetSubCalc->at(ijet),ijet));
	
        // ----------------------------------------------------------------------------                                  
        // Combine DeepAK8 C and B results
        // ----------------------------------------------------------------------------                                  

	if(dnn_largest_DeepAK8Calc->at(ijet) == 6) dnn_largest_DeepAK8Calc->at(ijet) = 5;

      }

      if(nskipped > 1){
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "Weird thing! " << nskipped << " AK8s had DR < 0.8 && PtRel < 20!" << std::endl;
	std::cout << "dr1 = " << deltaR1 << ", dr2 = " << deltaR2 << std::endl;
	std::cout << "pt1 = " << ptRel1 << ", pt2 = " << ptRel2 << std::endl; 
	std::cout << "------------------------------------------------------------" << std::endl;
     }

      // ----------------------------------------------------------------------------
      // Apply kinematic cuts
      // ----------------------------------------------------------------------------
	                
      int isPastHTCut = 0;
      if(AK4HT >= htCut){npass_ht+=1;isPastHTCut=1;}

      int isPastNAK8JetsCut = 0;
      if(NJetsAK8_JetSubCalc >= nAK8jetsCut){npass_nAK8jets+=1;isPastNAK8JetsCut=1;}
      
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
            
      if(!(isPastMETcut && isPastHTCut && isPastNAK8JetsCut && isPastLepPtCut && (isPastElEtaCut || isPastMuEtaCut))) continue;
      npass_all+=1;

      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /////////////// ONLY ON SELECTED EVENTS ////////////////////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////      
      
      // ----------------------------------------------------------------------------
      // Combine lepton variables into one set
      // ----------------------------------------------------------------------------

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
      // Apply pt ordering to AK4 vectors
      // ----------------------------------------------------------------------------

      std::sort(jetptindpair.begin(), jetptindpair.end(), comparepair);
      theJetPt_JetSubCalc_PtOrdered.clear();
      theJetEta_JetSubCalc_PtOrdered.clear();
      theJetPhi_JetSubCalc_PtOrdered.clear();
      theJetEnergy_JetSubCalc_PtOrdered.clear();
      theJetDeepCSVb_JetSubCalc_PtOrdered.clear();
      theJetDeepCSVbb_JetSubCalc_PtOrdered.clear();
      theJetHFlav_JetSubCalc_PtOrdered.clear();
      theJetPFlav_JetSubCalc_PtOrdered.clear();
      theJetBTag_JetSubCalc_PtOrdered.clear();
      theJetBTag_bSFup_JetSubCalc_PtOrdered.clear();
      theJetBTag_bSFdn_JetSubCalc_PtOrdered.clear();
      theJetBTag_lSFup_JetSubCalc_PtOrdered.clear();
      theJetBTag_lSFdn_JetSubCalc_PtOrdered.clear();
      for(unsigned int ijet=0; ijet < jetptindpair.size(); ijet++){
      	theJetPt_JetSubCalc_PtOrdered.push_back(theJetPt_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetEta_JetSubCalc_PtOrdered.push_back(theJetEta_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetPhi_JetSubCalc_PtOrdered.push_back(theJetPhi_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetEnergy_JetSubCalc_PtOrdered.push_back(theJetEnergy_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetDeepCSVb_JetSubCalc_PtOrdered.push_back(theJetDeepCSVb_JetSubCalc->at(jetptindpair[ijet].second));
	theJetDeepCSVbb_JetSubCalc_PtOrdered.push_back(theJetDeepCSVbb_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetHFlav_JetSubCalc_PtOrdered.push_back(theJetHFlav_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetPFlav_JetSubCalc_PtOrdered.push_back(theJetPFlav_JetSubCalc->at(jetptindpair[ijet].second));
	theJetBTag_JetSubCalc_PtOrdered.push_back(theJetBTag_JetSubCalc->at(jetptindpair[ijet].second));
	theJetBTag_bSFup_JetSubCalc_PtOrdered.push_back(theJetBTag_bSFup_JetSubCalc->at(jetptindpair[ijet].second));
	theJetBTag_bSFdn_JetSubCalc_PtOrdered.push_back(theJetBTag_bSFdn_JetSubCalc->at(jetptindpair[ijet].second));
	theJetBTag_lSFup_JetSubCalc_PtOrdered.push_back(theJetBTag_lSFup_JetSubCalc->at(jetptindpair[ijet].second));
	theJetBTag_lSFdn_JetSubCalc_PtOrdered.push_back(theJetBTag_lSFdn_JetSubCalc->at(jetptindpair[ijet].second));
      }

      // ----------------------------------------------------------------------------
      // AK4 Jet - lepton associations
      // ----------------------------------------------------------------------------
         
      int ind_MinMlb = -1;
      int ind_MinMlj = -1;
      BJetLeadPt = -99;
      minMleppBjet = 1e8;
      minMleppJet = 1e8;      
      minDPhi_MetJet = 1e8;
      minDR_lepJet = 1e8;
      ptRel_lepJet = -99;
      deltaR_lepJets.clear();
      deltaR_lepBJets.clear();
      deltaR_lepMinMlb = 1e8;
      deltaR_lepMinMlj = 1e8;
      NJetsCSV_JetSubCalc = 0;
      NJetsCSVwithSF_JetSubCalc = 0;
      TLorentzVector nu;
      nu.SetPtEtaPhiE(corr_met_singleLepCalc,0,corr_met_phi_singleLepCalc,corr_met_singleLepCalc);

      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc_PtOrdered.size(); ijet++){
        jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(ijet),theJetEta_JetSubCalc_PtOrdered.at(ijet),theJetPhi_JetSubCalc_PtOrdered.at(ijet),theJetEnergy_JetSubCalc_PtOrdered.at(ijet));
	if((lepton_lv + jet_lv).M() < minMleppJet) {
	  minMleppJet = fabs((lepton_lv + jet_lv).M());
	  deltaR_lepMinMlj = jet_lv.DeltaR(lepton_lv);
	  ind_MinMlj = ijet;
	}

	deltaR_lepJets.push_back(lepton_lv.DeltaR(jet_lv));

   	if(theJetDeepCSVb_JetSubCalc_PtOrdered.at(ijet) + theJetDeepCSVbb_JetSubCalc_PtOrdered.at(ijet) > 0.4941){
          NJetsCSV_JetSubCalc += 1;
        }

	if(isNominal && theJetBTag_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsCSVwithSF_JetSubCalc += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt) BJetLeadPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet) {
            minMleppBjet = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepMinMlb = jet_lv.DeltaR(lepton_lv);
	    ind_MinMlb = ijet;
          }
	}
	if(isBUp && theJetBTag_bSFup_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsCSVwithSF_JetSubCalc += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt) BJetLeadPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet) {
            minMleppBjet = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepMinMlb = jet_lv.DeltaR(lepton_lv);
	    ind_MinMlb = ijet;
          }
	}
	if(isBDn && theJetBTag_bSFdn_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsCSVwithSF_JetSubCalc += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt) BJetLeadPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet) {
            minMleppBjet = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepMinMlb = jet_lv.DeltaR(lepton_lv);
	    ind_MinMlb = ijet;
          }
	}
	if(isLUp && theJetBTag_lSFup_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsCSVwithSF_JetSubCalc += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt) BJetLeadPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet) {
            minMleppBjet = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepMinMlb = jet_lv.DeltaR(lepton_lv);
	    ind_MinMlb = ijet;
          }
	}
	if(isLDn && theJetBTag_lSFdn_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsCSVwithSF_JetSubCalc += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt) BJetLeadPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet) {
            minMleppBjet = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepMinMlb = jet_lv.DeltaR(lepton_lv);
	    ind_MinMlb = ijet;
          }
	}
	
	if(jet_lv.DeltaPhi(nu) < minDPhi_MetJet) minDPhi_MetJet = jet_lv.DeltaPhi(nu);	  

 	if(deltaR_lepJets[ijet] < minDR_lepJet) {
	  minDR_lepJet = deltaR_lepJets[ijet];
	  ptRel_lepJet = lepton_lv.P()*(jet_lv.Vect().Cross(lepton_lv.Vect()).Mag()/jet_lv.P()/lepton_lv.P());
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
      // Apply pt ordering to AK8 vectors 
      // ----------------------------------------------------------------------------

      //Pt ordering for AK8
      std::sort(jetak8ptindpair.begin(), jetak8ptindpair.end(), comparepair);

      dnn_J_DeepAK8Calc_PtOrdered.clear();
      dnn_T_DeepAK8Calc_PtOrdered.clear();
      dnn_H_DeepAK8Calc_PtOrdered.clear();
      dnn_W_DeepAK8Calc_PtOrdered.clear();
      dnn_Z_DeepAK8Calc_PtOrdered.clear();
      dnn_B_DeepAK8Calc_PtOrdered.clear();

      maxProb_JetSubCalc_PtOrdered.clear();
      dnn_largest_DeepAK8Calc_PtOrdered.clear();
      theJetAK8DoubleB_JetSubCalc_PtOrdered.clear();
      theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.clear();
      theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered.clear();
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
      theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.clear();
      theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.clear();
      theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSTau1_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSTau2_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSTau3_JetSubCalc_PtOrdered.clear();
      for(unsigned int ijet=0; ijet < jetak8ptindpair.size(); ijet++){
	dnn_J_DeepAK8Calc_PtOrdered.push_back(dnn_J_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	dnn_T_DeepAK8Calc_PtOrdered.push_back(dnn_T_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	dnn_H_DeepAK8Calc_PtOrdered.push_back(dnn_H_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	dnn_W_DeepAK8Calc_PtOrdered.push_back(dnn_W_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	dnn_Z_DeepAK8Calc_PtOrdered.push_back(dnn_Z_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	dnn_B_DeepAK8Calc_PtOrdered.push_back(dnn_B_DeepAK8Calc->at(jetak8ptindpair[ijet].second)+dnn_C_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	maxProb_JetSubCalc_PtOrdered.push_back(maxProb_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	dnn_largest_DeepAK8Calc_PtOrdered.push_back(dnn_largest_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
      	theJetAK8DoubleB_JetSubCalc_PtOrdered.push_back(theJetAK8DoubleB_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetIndex_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SDSubjetSize_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetSize_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetNDeepCSVL_JetSubCalc->at(jetak8ptindpair[ijet].second));
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
      	theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau1_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau2_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau3_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8CHSTau1_JetSubCalc_PtOrdered.push_back(theJetAK8CHSTau1_JetSubCalc->at(jetak8ptindpair[ijet].second));      	
	theJetAK8CHSTau2_JetSubCalc_PtOrdered.push_back(theJetAK8CHSTau2_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8CHSTau3_JetSubCalc_PtOrdered.push_back(theJetAK8CHSTau3_JetSubCalc->at(jetak8ptindpair[ijet].second));
      }

      // Add probabilities
      probSum_DeepAK8_all = 0;
      nB_DeepAK8 = 0;
      nH_DeepAK8 = 0;
      nJ_DeepAK8 = 0;
      nT_DeepAK8 = 0;
      nW_DeepAK8 = 0;
      nZ_DeepAK8 = 0;
      // 0 = J, 1 = T, 2 = H, 3 = Z, 4 = W, 5 = B
      for(unsigned int ijet=0; ijet < jetak8ptindpair.size(); ijet++){
        if (dnn_B_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_B_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (dnn_H_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_H_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (dnn_J_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_J_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (dnn_T_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_T_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (dnn_W_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_W_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (dnn_Z_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_Z_DeepAK8Calc_PtOrdered.at(ijet) = 0;

        probSum_DeepAK8_all += dnn_B_DeepAK8Calc_PtOrdered.at(ijet) + 2*dnn_W_DeepAK8Calc_PtOrdered.at(ijet) + 2*dnn_T_DeepAK8Calc_PtOrdered.at(ijet) + 3*dnn_Z_DeepAK8Calc_PtOrdered.at(ijet) + 4*dnn_H_DeepAK8Calc_PtOrdered.at(ijet);

        if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 1) nT_DeepAK8 += 1;
        else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 2) nH_DeepAK8 += 1;
        else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 3) nZ_DeepAK8 += 1;
        else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 4) nW_DeepAK8 += 1;
	else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 5) nB_DeepAK8 += 1;
	//	else if (theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered.at(ijet) > 0) nB_DeepAK8 += 1;
        else nJ_DeepAK8 += 1;
      }

      // ----------------------------------------------------------------------------
      // AK8 Jet - lepton associations and truth matching
      // ----------------------------------------------------------------------------

      deltaR_lepAK8s.clear();
      minDR_lepAK8 = 1000;
      minDR_leadAK8otherAK8 = 1000;
      ptRel_lepAK8 = -99;
      if(theJetAK8Pt_JetSubCalc_PtOrdered.size() < 1) minDR_lepAK8 = -99.0;      
      if(theJetAK8Pt_JetSubCalc_PtOrdered.size() < 2) minDR_leadAK8otherAK8 = -99.0;

      theJetAK8Wmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8Hmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8Zmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8Tmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8MatchedPt_JetSubCalc_PtOrdered.clear();
      theJetAK8Truth_JetSubCalc_PtOrdered.clear();

      ak8_lv.SetPtEtaPhiM(0,0,0,0);
      TLorentzVector leadak8;
      leadak8.SetPtEtaPhiM(0,0,0,0);

      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc_PtOrdered.size(); ijet++){

	// ----------------------------------------------------------------------------
	// AK8 - lepton and AK8 -- AK8 associations
	// ----------------------------------------------------------------------------
	
	ak8_lv.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),theJetAK8Energy_JetSubCalc_PtOrdered.at(ijet));
	if(ijet == 0) leadak8 = ak8_lv;

	deltaR_lepAK8s.push_back(lepton_lv.DeltaR(ak8_lv));
	if(lepton_lv.DeltaR(ak8_lv) < minDR_lepAK8){
	  minDR_lepAK8 = lepton_lv.DeltaR(ak8_lv);
	  ptRel_lepAK8 = lepton_lv.P()*(ak8_lv.Vect().Cross(lepton_lv.Vect()).Mag()/ak8_lv.P()/lepton_lv.P());
	}

	if(ijet > 0){
	  float tempdr = leadak8.DeltaR(ak8_lv);
	  if(tempdr < minDR_leadAK8otherAK8){
	    minDR_leadAK8otherAK8 = tempdr;
	  }
	}

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

	}
      }

      // ----------------------------------------------------------------------------
      // W --> l nu with mass constraint
      // ----------------------------------------------------------------------------

      double metpx = corr_met_singleLepCalc*cos(corr_met_phi_singleLepCalc);
      double metpy = corr_met_singleLepCalc*sin(corr_met_phi_singleLepCalc);
      double metpt = corr_met_singleLepCalc;
      TLorentzVector Wlv_1, Wlv_2, Wlv, Nulv_1, Nulv_2;
      double nuPz_1;
      double nuPz_2;
      
      double Dtmp = MW*MW - lepM*lepM + 2*(lepton_lv.Px()*metpx + lepton_lv.Py()*metpy);
      double Atmp = 4.0*(lepton_lv.Energy()*lepton_lv.Energy() - lepton_lv.Pz()*lepton_lv.Pz());
      double Btmp = -4.0*Dtmp*lepton_lv.Pz();
      double Ctmp = 4.0*lepton_lv.Energy()*lepton_lv.Energy()*metpt*metpt - Dtmp*Dtmp;
      
      double DETtmp = Btmp*Btmp-4.0*Atmp*Ctmp;

      if(DETtmp >= 0) {
      	nuPz_1 = (-Btmp+TMath::Sqrt(DETtmp))/(2.0*Atmp);
      	nuPz_2 = (-Btmp-TMath::Sqrt(DETtmp))/(2.0*Atmp);
      	Nulv_1.SetPxPyPzE(metpx,metpy,nuPz_1,TMath::Sqrt((metpt)*(metpt)+(nuPz_1)*(nuPz_1)));
      	Nulv_2.SetPxPyPzE(metpx,metpy,nuPz_2,TMath::Sqrt((metpt)*(metpt)+(nuPz_2)*(nuPz_2)));
      }else{
      	nuPz_1 = -Btmp/(2.0*Atmp);
      	nuPz_2 = -Btmp/(2.0*Atmp);
	// does another quad solution for pT and scales pT in result. Reduces M, pT, DR.
      	double alpha = lepton_lv.Px()*metpx/metpt + lepton_lv.Py()*metpy/metpt;
      	double Delta = MW*MW - lepM*lepM;
      	Atmp = 4.0*(lepton_lv.Pz()*lepton_lv.Pz() - lepton_lv.Energy()*lepton_lv.Energy() + alpha*alpha);
      	Btmp = 4.0*alpha*Delta;
      	Ctmp = Delta*Delta;
      	float DETtmp2 = Btmp*Btmp-4.0*Atmp*Ctmp;
      	double pTnu_1 = (-Btmp+TMath::Sqrt(DETtmp2))/(2.0*Atmp);
      	double pTnu_2 = (-Btmp-TMath::Sqrt(DETtmp2))/(2.0*Atmp);
      	Nulv_1.SetPxPyPzE(metpx*pTnu_1/metpt,metpy*pTnu_1/metpt,nuPz_1,TMath::Sqrt(pTnu_1*pTnu_1 + nuPz_1*nuPz_1));
      	Nulv_2.SetPxPyPzE(metpx*pTnu_2/metpt,metpy*pTnu_2/metpt,nuPz_2,TMath::Sqrt(pTnu_2*pTnu_2 + nuPz_2*nuPz_2));
      }
      Wlv_1 = Nulv_1+lepton_lv;
      Wlv_2 = Nulv_2+lepton_lv;
      
      if (fabs(Wlv_1.M()-MW) < fabs(Wlv_2.M()-MW)) Wlv = Wlv_1;
      else Wlv = Wlv_2;
 
      W_mass = Wlv.M();
      W_pt = Wlv.Pt();
      W_dRLep = Wlv.DeltaR(lepton_lv);

      // ----------------------------------------------------------------------------
      // VLQ decay
      // ----------------------------------------------------------------------------                                                                                                           
      // Find closest b-tagged AK4 to the W vector
      float deltaRbW = 999;
      int bIndex = 999;
      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc_PtOrdered.size(); ijet++){
	if(isNominal && theJetBTag_JetSubCalc_PtOrdered.at(ijet) == 0) continue;
	else if(isBUp && theJetBTag_bSFup_JetSubCalc_PtOrdered.at(ijet) == 0) continue;
	else if(isBDn && theJetBTag_bSFdn_JetSubCalc_PtOrdered.at(ijet) == 0) continue;
	else if(isLUp && theJetBTag_lSFup_JetSubCalc_PtOrdered.at(ijet) == 0) continue;
	else if(isLDn && theJetBTag_lSFdn_JetSubCalc_PtOrdered.at(ijet) == 0) continue;

	jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(ijet),theJetEta_JetSubCalc_PtOrdered.at(ijet),theJetPhi_JetSubCalc_PtOrdered.at(ijet),theJetEnergy_JetSubCalc_PtOrdered.at(ijet));
	if(jet_lv.DeltaR(Wlv) < deltaRbW){
	  deltaRbW = jet_lv.DeltaR(Wlv);
	  bIndex = ijet;
	}
      }

      // Form a leptonic top candidate if the b is close enough
      TLorentzVector top_lv;
      t_mass = -999;
      isLeptonic_W = false;
      isLeptonic_t = false;
      if(minMleppJet > 150){  // best combo of W vs t truth match with this
	//if(deltaRbW >= 0.8 && minMleppJet > 150){  // favors tops
	isLeptonic_W = true;
      }else{
	if(deltaRbW > 0.8) bIndex = ind_MinMlj; // use a close b unless it doesn't exist
	TLorentzVector bottom_lv;
	bottom_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(bIndex),theJetEta_JetSubCalc_PtOrdered.at(bIndex),theJetPhi_JetSubCalc_PtOrdered.at(bIndex),theJetEnergy_JetSubCalc_PtOrdered.at(bIndex));
	top_lv = bottom_lv + Wlv;
	t_mass = top_lv.M();
	t_pt = top_lv.Pt();
	t_dRWb = bottom_lv.DeltaR(Wlv);
	isLeptonic_t = true;
      } 

      // Fill the vector for deltaR from leptonic particle (W or t) from all AK8 Jets
      std::vector<pair<TLorentzVector,int>> jets_lv;
      deltaR_leptonicparticle_AK8_PtOrdered.clear();
      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc_PtOrdered.size(); ijet++){
	jet_lv.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),theJetAK8Energy_JetSubCalc_PtOrdered.at(ijet));
	if(isLeptonic_W) deltaR_leptonicparticle_AK8_PtOrdered.push_back(jet_lv.DeltaR(Wlv));
	if(isLeptonic_t) deltaR_leptonicparticle_AK8_PtOrdered.push_back(jet_lv.DeltaR(top_lv));

	// Get 3 highest-pT jets that are not close to t/W (deltaR > .8) and store AK8 index and 4-vector
	if(jets_lv.size() >= 3) continue;

	if(jet_lv.DeltaR(top_lv) > .8 and isLeptonic_t) jets_lv.push_back(std::make_pair(jet_lv,ijet));
	if(jet_lv.DeltaR(Wlv) > .8 and isLeptonic_W) jets_lv.push_back(std::make_pair(jet_lv,ijet));
      }

      highPtAK8Jet1_SoftDropCorrectedMass = -999;
      highPtAK8Jet2_SoftDropCorrectedMass = -999;
      highPtAK8Jet3_SoftDropCorrectedMass = -999;

      leptonicTprimeJetIDs_DeepAK8.clear();
      hadronicTprimeJetIDs_DeepAK8.clear();
      leptonicBprimeJetIDs_DeepAK8.clear();
      hadronicBprimeJetIDs_DeepAK8.clear();
	
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
      Bprime1_DeepAK8_Mass = -999;
      Bprime2_DeepAK8_Mass = -999;
      Bprime1_DeepAK8_Pt = -999;
      Bprime2_DeepAK8_Pt = -999;
      Bprime1_DeepAK8_Eta = -999;
      Bprime2_DeepAK8_Eta = -999;
      Bprime1_DeepAK8_Phi = -999;
      Bprime2_DeepAK8_Phi = -999;
      Bprime1_DeepAK8_deltaR = -999;
      Bprime2_DeepAK8_deltaR = -999;
      
      validTDecay_DeepAK8 = false;
      validBDecay_DeepAK8 = false;
      taggedBWBW_DeepAK8 = false;
      taggedTHBW_DeepAK8 = false;
      taggedTHTH_DeepAK8 = false;
      taggedTZBW_DeepAK8 = false;
      taggedTZTH_DeepAK8 = false;
      taggedTZTZ_DeepAK8 = false;      
      taggedTWTW_DeepAK8 = false;
      taggedBZTW_DeepAK8 = false;
      taggedBHTW_DeepAK8 = false;

      probSum_DeepAK8_decay = -999;
      probSum_DeepAK8_four = -999;

      // ----------------------------------------------------------------------------
      // VLQ Decay -- 3 AK8 jets away from leptonic particle
      // ----------------------------------------------------------------------------                                                                                                           
      if(jets_lv.size() > 3) std::cout << "Problem: > 3 AK8s for Tprime reco" << std::endl;
      if(jets_lv.size() == 3){

	npass_ThreeJets = npass_ThreeJets + 1;

	// Sums of tag probabilities
	probSum_DeepAK8_decay = 0;
	probSum_DeepAK8_four = 0;
        for (unsigned int i = 0; i < jets_lv.size(); i++) {
	  // "decay" weighted sum of probabilities including B
          probSum_DeepAK8_decay += dnn_B_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second) + 2*dnn_W_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second) + 3*dnn_T_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second) + 4*dnn_Z_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second) + 5*dnn_H_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second);

	  // "four" raw sum of heavy particle probabilities
          probSum_DeepAK8_four += dnn_W_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second) + dnn_T_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second) + dnn_Z_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second) + dnn_H_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second);
	}
	
	// First guess at leptonic T particles
	if(isLeptonic_W) leptonicTprimeJetIDs_DeepAK8.push_back(4);
	if(isLeptonic_t) leptonicTprimeJetIDs_DeepAK8.push_back(1);
	
	// Save masses of the 3 jets for plotting
	highPtAK8Jet1_SoftDropCorrectedMass = theJetAK8SoftDropCorr_PtOrdered.at(jets_lv.at(0).second);
	highPtAK8Jet2_SoftDropCorrectedMass = theJetAK8SoftDropCorr_PtOrdered.at(jets_lv.at(1).second);
	highPtAK8Jet3_SoftDropCorrectedMass = theJetAK8SoftDropCorr_PtOrdered.at(jets_lv.at(2).second);
	
	// ----------------------------------------------------------------------------
	// DeepAK8 SECTION -- TT
	// ----------------------------------------------------------------------------                                                                                                   

	// get the tags
	int jet1_DeepAK8 = dnn_largest_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second);
	int jet2_DeepAK8 = dnn_largest_DeepAK8Calc_PtOrdered.at(jets_lv.at(1).second);
	int jet3_DeepAK8 = dnn_largest_DeepAK8Calc_PtOrdered.at(jets_lv.at(2).second);

	// pair up the jet tag with the pT index 0,1,2 and sort by tag (orders J, T, H, Z, W, B)
	std::vector <pair<int,int>> decayJets_DeepAK8;
	decayJets_DeepAK8.push_back(std::make_pair(jet1_DeepAK8,0));
	decayJets_DeepAK8.push_back(std::make_pair(jet2_DeepAK8,1));
	decayJets_DeepAK8.push_back(std::make_pair(jet3_DeepAK8,2));
	std::sort(decayJets_DeepAK8.begin(),decayJets_DeepAK8.end());

	// Start forming 4 particle groups
	TLorentzVector Tprime1_DeepAK8_lv;
	TLorentzVector Tprime2_DeepAK8_lv;
	TLorentzVector Bprime1_DeepAK8_lv;
	TLorentzVector Bprime2_DeepAK8_lv;
	validBDecay_DeepAK8 = false;
	validTDecay_DeepAK8 = false;
	if(isLeptonic_t){

	  float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();
	  float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M();
	  float massDiff3=(top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();

	  if(decayJets_DeepAK8.at(0).first==2 && decayJets_DeepAK8.at(1).first==4 && decayJets_DeepAK8.at(2).first==5){ // TT -> tH bW, BB -> tW bH
	    validTDecay_DeepAK8 = true;
	    taggedTHBW_DeepAK8 = true;
	    leptonicTprimeJetIDs_DeepAK8.push_back(2); // assign the H with the leptonic top
	    hadronicTprimeJetIDs_DeepAK8 = {4,5};      // assign the b & W as hadronic
	    Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first; // decayJets.second gives the jets_lv index to get 4-vec
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);

	    validBDecay_DeepAK8 = true;
	    taggedBHTW_DeepAK8 = true;
	    leptonicBprimeJetIDs_DeepAK8.push_back(4); // assign the W with leptonic top
	    hadronicBprimeJetIDs_DeepAK8 = {2,5};      // assign bH hadronic
	    Bprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; // decayJets.second gives the jets_lv index to get 4-vec
	    Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Bprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	    Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);

	  }
	  else if(decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==2 && decayJets_DeepAK8.at(2).first==2){ // TTbar --> tH and tH
	    validTDecay_DeepAK8 = true;
	    taggedTHTH_DeepAK8 = true;
	    leptonicTprimeJetIDs_DeepAK8.push_back(2); // assign an H with leptonic top
	    hadronicTprimeJetIDs_DeepAK8 = {1,2};      // assign tH hadronic
	    // options (lepTop + H1) - (T0 + H2) OR (lepTop + H2) - (T0 + H1) checking smallest
	    if(massDiff1 < massDiff2) { // (lepTop + H1) wins
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; 
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // (lepTop + H2) wins
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    }
	  }
	  else if(decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==2 && decayJets_DeepAK8.at(2).first==3){ // TTbar --> tH and tZ
	    validTDecay_DeepAK8 = true;
	    taggedTZTH_DeepAK8 = true;
	    // options (lepTop + H1) - (T0 + Z2) OR (lepTop + Z2) - (T0 + H1)
	    if(massDiff1 < massDiff2) { // (lepTop + H1) wins
	      leptonicTprimeJetIDs_DeepAK8.push_back(2); // tH
	      hadronicTprimeJetIDs_DeepAK8 = {1,3}; // tZ
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; 
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // (lepTop + Z2) wins
	      leptonicTprimeJetIDs_DeepAK8.push_back(3);
	      hadronicTprimeJetIDs_DeepAK8 = {1,2};
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    }
	  }
	  else if(decayJets_DeepAK8.at(0).first==3 && decayJets_DeepAK8.at(1).first==4 && decayJets_DeepAK8.at(2).first==5){ // TT -> tZ bW, BB -> tW bZ
	    validTDecay_DeepAK8 = true;
	    taggedTZBW_DeepAK8 = true;
	    leptonicTprimeJetIDs_DeepAK8.push_back(3); // tZ
	    hadronicTprimeJetIDs_DeepAK8 = {4,5}; // bW
	    Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);

	    validBDecay_DeepAK8 = true;
	    taggedBZTW_DeepAK8 = true;
	    leptonicBprimeJetIDs_DeepAK8.push_back(4); // assign the W with the leptonic top
	    hadronicBprimeJetIDs_DeepAK8 = {3,5};      // assign the b & Z as hadronic
	    Bprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; // decayJets.second gives the jets_lv index to get 4-vec
	    Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Bprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	    Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	  }
	  else if(decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==3 && decayJets_DeepAK8.at(2).first==3){ // TTbar --> tZ tZ
	    validTDecay_DeepAK8 = true;
	    taggedTZTZ_DeepAK8 = true;
	    leptonicTprimeJetIDs_DeepAK8.push_back(3); // tZ
	    hadronicTprimeJetIDs_DeepAK8 = {1,3}; // tZ
	    // options (lepTop + Z1) - (T0 + Z2) OR (lepTop + Z2) - (T0 + Z1)
	    if(massDiff1 < massDiff2) { // (lepTop + Z1) wins
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; 
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // (lepTop + Z2) wins
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    } 
	  }
	  else if(decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==4 && decayJets_DeepAK8.at(2).first==4){ // BB/XX -> tW tW, jets t W W
	    validBDecay_DeepAK8 = true;
	    taggedTWTW_DeepAK8 = true;
	    leptonicBprimeJetIDs_DeepAK8.push_back(4); // tW
	    hadronicBprimeJetIDs_DeepAK8 = {1,4}; // tW
	    // options (lepTop + W1) - (T0 + W2) OR (lepTop + W2) - (T0 + W1)
	    if(massDiff1 < massDiff2) { // (lepTop + W1) wins
	      Bprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; 
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // (lepTop + W2) wins
	      Bprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Bprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	    }
	  }

	  if(!validTDecay_DeepAK8){ // Not a valid T decay combination
	    if(massDiff3 < massDiff1 and massDiff3 < massDiff2){  // lepTop + 0 is best
	      leptonicTprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(0).first);
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(1).first, decayJets_DeepAK8.at(2).first};
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else if(massDiff1 < massDiff2 and massDiff1 < massDiff3){ // lepTop + 1 is best 
	      leptonicTprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(1).first);
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(2).first};
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // lepTop + 2 is best
	      leptonicTprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(2).first);
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(1).first};
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    }
	  }
	  if(!validBDecay_DeepAK8){ // Not a valid B decay combination
	    if(massDiff3 < massDiff1 and massDiff3 < massDiff2){  // lepTop + 0 is best
	      leptonicBprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(0).first);
	      hadronicBprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(1).first, decayJets_DeepAK8.at(2).first};
	      Bprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else if(massDiff1 < massDiff2 and massDiff1 < massDiff3){ // lepTop + 1 is best 
	      leptonicBprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(1).first);
	      hadronicBprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(2).first};
	      Bprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // lepTop + 2 is best
	      leptonicBprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(2).first);
	      hadronicBprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(1).first};
	      Bprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Bprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    }
	  }
	}else{ // isLeptonic_W

	  float massDiff1=(Wlv+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();
	  float massDiff2=(Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M();
	  float massDiff3=(Wlv+jets_lv.at(decayJets_DeepAK8.at(0).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();

	  if(decayJets_DeepAK8.at(0).first==4 && decayJets_DeepAK8.at(1).first==5 && decayJets_DeepAK8.at(2).first==5){ // bW bW
	    validTDecay_DeepAK8 = true;
	    taggedBWBW_DeepAK8 = true;
	    leptonicTprimeJetIDs_DeepAK8.push_back(5); // bW
	    hadronicTprimeJetIDs_DeepAK8 = {4,5}; // bW
	    // options (lepW + b1) - (W0 + b2) OR (lepW + b2) - (W0 + b1)
	    if(massDiff1 < massDiff2) { // (lepW + b1) wins
	      Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // (lepW + b2) wins
	      Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	    }
	  }
	  else if(decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==3 && decayJets_DeepAK8.at(2).first==5){ // TT -> bW tZ, BB -> tW bZ
	    validTDecay_DeepAK8 = true;
	    taggedTZBW_DeepAK8 = true;
	    leptonicTprimeJetIDs_DeepAK8.push_back(5); // bW
	    hadronicTprimeJetIDs_DeepAK8 = {1,3}; // tZ
	    Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	    Tprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);

	    validBDecay_DeepAK8 = true;
	    taggedBZTW_DeepAK8 = true;
	    leptonicBprimeJetIDs_DeepAK8.push_back(4); // tW
	    hadronicBprimeJetIDs_DeepAK8 = {3,5}; // bZ
	    Bprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	    Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Bprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	  }
	  else if(decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==2 && decayJets_DeepAK8.at(2).first==5){ // TT -> bW tH, BB -> tW bH
	    validTDecay_DeepAK8 = true;	    
	    taggedTHBW_DeepAK8 = true;
	    leptonicTprimeJetIDs_DeepAK8.push_back(5); // bW
	    hadronicTprimeJetIDs_DeepAK8 = {1,2}; // tH
	    Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	    Tprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);

	    validBDecay_DeepAK8 = true;	    
	    taggedBHTW_DeepAK8 = true;
	    leptonicBprimeJetIDs_DeepAK8.push_back(4); // tW
	    hadronicBprimeJetIDs_DeepAK8 = {2,5}; // bH
	    Bprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	    Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Bprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(2).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	  }
	  else if(decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==1 && decayJets_DeepAK8.at(2).first==4){ // BB -> tW tW, jets t t W
	    validBDecay_DeepAK8 = true;
	    taggedTWTW_DeepAK8 = true;
	    leptonicBprimeJetIDs_DeepAK8.push_back(1); // tW
	    hadronicBprimeJetIDs_DeepAK8 = {1,4}; // tW
	    // options (lepW + t0) - (W2 + t1) OR (lepW + t1) - (W2 + t0)
	    if(massDiff3 < massDiff1) { // (lepW + t0) wins
	      Bprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // (lepW + t1) wins
	      Bprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    }
	  }
	  
	  if(!validTDecay_DeepAK8){ // not a valid grouping
	    if(massDiff3 < massDiff1 and massDiff3 < massDiff2){ // lepW + 0 wins
	      leptonicTprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(0).first);
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(1).first, decayJets_DeepAK8.at(2).first};
	      Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else if(massDiff1 < massDiff2 and massDiff1 < massDiff3){ // lepW + 1 wins
	      leptonicTprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(1).first);
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(2).first};
	      Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // lepW + 2 wins
	      leptonicTprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(2).first);
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(1).first};
	      Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    }
	  }
	  if(!validBDecay_DeepAK8){ // not a valid grouping
	    if(massDiff3 < massDiff1 and massDiff3 < massDiff2){ // lepW + 0 wins
	      leptonicBprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(0).first);
	      hadronicBprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(1).first, decayJets_DeepAK8.at(2).first};
	      Bprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else if(massDiff1 < massDiff2 and massDiff1 < massDiff3){ // lepW + 1 wins
	      leptonicBprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(1).first);
	      hadronicBprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(2).first};
	      Bprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // lepW + 2 wins
	      leptonicBprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(2).first);
	      hadronicBprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(1).first};
	      Bprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Bprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
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
	}
        if(Bprime1_DeepAK8_lv.M() != -999){
	  Bprime1_DeepAK8_Mass = Bprime1_DeepAK8_lv.M();
	  Bprime2_DeepAK8_Mass = Bprime2_DeepAK8_lv.M();
	  Bprime1_DeepAK8_Pt = Bprime1_DeepAK8_lv.Pt();
	  Bprime2_DeepAK8_Pt = Bprime2_DeepAK8_lv.Pt();
	  Bprime1_DeepAK8_Eta = Bprime1_DeepAK8_lv.Eta();
	  Bprime2_DeepAK8_Eta = Bprime2_DeepAK8_lv.Eta();
	  Bprime1_DeepAK8_Phi = Bprime1_DeepAK8_lv.Phi();
	  Bprime2_DeepAK8_Phi = Bprime2_DeepAK8_lv.Phi();
	}

	// Numerator of confusion matrix
	if(isSig){
	  if(confusionTruth < 6.0){
	    if(taggedBWBW_DeepAK8) TTconfusionN->Fill(0.5,confusionTruth);
	    else if(taggedTZBW_DeepAK8) TTconfusionN->Fill(1.5,confusionTruth);
	    else if(taggedTHBW_DeepAK8) TTconfusionN->Fill(2.5,confusionTruth);
	    else if(taggedTZTH_DeepAK8) TTconfusionN->Fill(3.5,confusionTruth);
	    else if(taggedTZTZ_DeepAK8) TTconfusionN->Fill(4.5,confusionTruth);
	    else if(taggedTHTH_DeepAK8) TTconfusionN->Fill(5.5,confusionTruth);
	    else{
	      if(hadronicTprimeJetIDs_DeepAK8.at(0) == 4 && hadronicTprimeJetIDs_DeepAK8.at(1) == 5) TTconfusionN->Fill(6.5,confusionTruth);
	      else if(hadronicTprimeJetIDs_DeepAK8.at(0) == 1 && hadronicTprimeJetIDs_DeepAK8.at(1) == 3) TTconfusionN->Fill(7.5,confusionTruth);
	      else if(hadronicTprimeJetIDs_DeepAK8.at(0) == 1 && hadronicTprimeJetIDs_DeepAK8.at(1) == 2) TTconfusionN->Fill(8.5,confusionTruth);
	      else TTconfusionN->Fill(9.5,confusionTruth);
	    }
	  }else{
	    if(taggedTWTW_DeepAK8) BBconfusionN->Fill(0.5,confusionTruth-6.0);
	    else if(taggedBZTW_DeepAK8) BBconfusionN->Fill(1.5,confusionTruth-6.0);
	    else if(taggedBHTW_DeepAK8) BBconfusionN->Fill(2.5,confusionTruth-6.0);
	    else{
	      if(hadronicBprimeJetIDs_DeepAK8.at(0) == 1 && hadronicBprimeJetIDs_DeepAK8.at(1) == 4) BBconfusionN->Fill(3.5,confusionTruth-6.0);
	      else if(hadronicBprimeJetIDs_DeepAK8.at(0) == 3 && hadronicBprimeJetIDs_DeepAK8.at(1) == 5) BBconfusionN->Fill(4.5,confusionTruth-6.0);
	      else if(hadronicBprimeJetIDs_DeepAK8.at(0) == 2 && hadronicBprimeJetIDs_DeepAK8.at(1) == 5) BBconfusionN->Fill(5.5,confusionTruth-6.0);
	      else BBconfusionN->Fill(6.5,confusionTruth-6.0);
	    }
	  }
	}
      }

      // ----------------------------------------------------------------------------
      // PDF and Matrix Element energy scale weights
      // ----------------------------------------------------------------------------

      std::vector<double> renorm;
      std::vector<double> pdf;
      renormWeights.clear();
      pdfWeights.clear();
      pdfNewWeights.clear();
      pdfNewNominalWeight = 1.0;
      if(isSig){
	pdfNewNominalWeight = NewPDFweights_singleLepCalc->at(0);
	// SEEMS TO APPLY TO ALL B2G MG+PYTHIA SIGNALS. NNLO 4-FLAVOR PDF
	for(unsigned int i = 0; i < LHEweightids_singleLepCalc->size(); i++){
	  if(i > 0 && i < 101) pdfNewWeights.push_back(NewPDFweights_singleLepCalc->at(i));
	  if(LHEweightids_singleLepCalc->at(i) > 1 && LHEweightids_singleLepCalc->at(i) < 10){
	    if(LHEweightids_singleLepCalc->at(i) == 6 || LHEweightids_singleLepCalc->at(i) == 8) continue;
	    renormWeights.push_back(LHEweights_singleLepCalc->at(i));
	  }
	  if(LHEweightids_singleLepCalc->at(i) > 474 && LHEweightids_singleLepCalc->at(i) < 575){
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
	  if(LHEweightids_singleLepCalc->at(i) == 111 || LHEweightids_singleLepCalc->at(i) == 112){
	    alphaSWeights.push_back(LHEweights_singleLepCalc->at(i));
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
   
   negweights->Write();
   if(isSig){
     TTconfusionD->Write();
     TTconfusionN->Write();
     BBconfusionD->Write();
     BBconfusionN->Write();
   }
   outputTree->Write();

}

// ----------------------------------------------------------------------------
// Tprime function
// ----------------------------------------------------------------------------



