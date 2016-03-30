#define step1_cxx
#include "step1.h"
#include <fstream>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TRandom.h>
#include <TRandom3.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool comparepair( const std::pair<double,int> a, const std::pair<double,int> b) { return a.first > b.first; }

TRandom * gRandom = new TRandom3();

const double MTOP  = 173.5;
const double MW    = 80.4; 

void step1::Loop() 
{
//   In a ROOT session, you can do:
//      root> .L step1.C
//      root> step1 t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

   if (inputTree == 0) return;
   
   inputTree->SetBranchStatus("*",0);

   //Specify branches to keep
   
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
   inputTree->SetBranchStatus("elMiniIso_singleLepCalc",1);
   inputTree->SetBranchStatus("elRelIso_singleLepCalc",1);
   inputTree->SetBranchStatus("elDxy_singleLepCalc",1);
   inputTree->SetBranchStatus("elDZ_singleLepCalc",1);
   inputTree->SetBranchStatus("elCharge_singleLepCalc",1);
   
   //muons
   inputTree->SetBranchStatus("muPt_singleLepCalc",1);
   inputTree->SetBranchStatus("muEta_singleLepCalc",1);
   inputTree->SetBranchStatus("muPhi_singleLepCalc",1);
   inputTree->SetBranchStatus("muEnergy_singleLepCalc",1);
   inputTree->SetBranchStatus("muMiniIso_singleLepCalc",1);
   inputTree->SetBranchStatus("muRelIso_singleLepCalc",1);
   inputTree->SetBranchStatus("muDxy_singleLepCalc",1);
   inputTree->SetBranchStatus("muDz_singleLepCalc",1);
   inputTree->SetBranchStatus("muCharge_singleLepCalc",1);
   
   //missing et
   inputTree->SetBranchStatus("met_singleLepCalc",1);
   inputTree->SetBranchStatus("met_phi_singleLepCalc",1);
   inputTree->SetBranchStatus("corr_met_singleLepCalc",1);
   inputTree->SetBranchStatus("corr_met_phi_singleLepCalc",1);
   inputTree->SetBranchStatus("corr_metnohf_singleLepCalc",1);
   inputTree->SetBranchStatus("corr_metnohf_phi_singleLepCalc",1);

   // genParticles
   inputTree->SetBranchStatus("genPt_singleLepCalc",1);
   inputTree->SetBranchStatus("genEta_singleLepCalc",1);
   inputTree->SetBranchStatus("genPhi_singleLepCalc",1);
   inputTree->SetBranchStatus("genEnergy_singleLepCalc",1);
   inputTree->SetBranchStatus("genStatus_singleLepCalc",1);
   inputTree->SetBranchStatus("genJetPt_singleLepCalc",1);
   inputTree->SetBranchStatus("genJetEta_singleLepCalc",1);
   inputTree->SetBranchStatus("genJetPhi_singleLepCalc",1);
   inputTree->SetBranchStatus("genJetEnergy_singleLepCalc",1);
   
   //jets
   inputTree->SetBranchStatus("AK4JetFlav_singleLepCalc",1);
   inputTree->SetBranchStatus("theJetPt_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetEta_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetPhi_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetEnergy_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetCSV_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Pt_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Eta_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Phi_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Mass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Energy_JetSubCalc",1);
   inputTree->SetBranchStatus("WPt_JetSubCalc",1);
   inputTree->SetBranchStatus("WEta_JetSubCalc",1);
   inputTree->SetBranchStatus("WPhi_JetSubCalc",1);
   inputTree->SetBranchStatus("WEnergy_JetSubCalc",1);
   inputTree->SetBranchStatus("WdecayDR_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau1_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau2_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau3_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8PrunedMass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDropMass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8PrunedTau21Tag_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetNCSVMSF_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetPt_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetEta_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetPhi_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetMass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetCSV_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetBTag_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetIndex_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetSize_JetSubCalc",1);
   
   //top
   inputTree->SetBranchStatus("ttbarMass_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topEnergy_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topEta_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topMass_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topPhi_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topPt_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topID_TTbarMassCalc",1);
   
   //LHE weights
   inputTree->SetBranchStatus("LHEWeightids_singleLepCalc",1);
   inputTree->SetBranchStatus("LHEWeights_singleLepCalc",1);
   
   // OUTPUT FILE
   outputFile->cd();
   TTree *outputTree = new TTree("ljmet","ljmet");

   int NJetsWtagged_0p6;
   float leadWJetPtak8;
   float topPtWeightPast400;
   float topPtWeightHighPt;
   float leptonRelIso_singleLepCalc;
   float minDR_leadAK8otherAK8;
   float minDR_lepAK8;
   float deltaR_lepClosestJet;
   float PtRelLepClosestJet;
   float MT_lepMet;
   float JetSF_pTNbwflat;
   float JetSFup_pTNbwflat;
   float JetSFdn_pTNbwflat;
   float JetSFupwide_pTNbwflat;
   float JetSFdnwide_pTNbwflat;
   std::vector<float> leadWJetPtak8_shifts;
   std::vector<int> nWtags_shifts;
   std::vector<float> deltaRtopWjet_shifts;  
   std::vector<float> deltaPhitopWjet_shifts; 
   std::vector<float> deltaRlepWjet_shifts;  
   std::vector<float> deltaPhilepWjet_shifts; 
   std::vector<float> pdfWeights;
   std::vector<float> theJetAK8SoftDropMass_JetSubCalc_PtOrdered;
   std::vector<float> theJetAK8NjettinessTau3_JetSubCalc_PtOrdered;
   std::vector<float> theJetAK8MaxSubCSV_JetSubCalc_PtOrdered;
   std::vector<int> theJetBTagBuggy_JetSubCalc_PtOrdered;
   std::vector<int> theJetAK8Wmatch_JetSubCalc_PtOrdered;
   std::vector<int> NJetsWtagged_0p6_shifts;
   std::vector<float> deltaR_lepJets;
   std::vector<float> deltaR_lepBJets;
   std::vector<float> deltaR_lepAK8s;
   std::vector<float> deltaPhi_lepJets;
   std::vector<float> deltaPhi_lepBJets;
   std::vector<float> deltaPhi_lepAK8s;
   std::vector<float> mass_lepJets;
   std::vector<float> mass_lepBJets;
   std::vector<float> mass_lepAK8s;

   outputTree->Branch("theJetAK8Wmatch_JetSubCalc_PtOrdered",&theJetAK8Wmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("NJetsWtagged_0p6",&NJetsWtagged_0p6,"NJetsWtagged_0p6/I");
   outputTree->Branch("NJetsWtagged_0p6_shifts",&NJetsWtagged_0p6_shifts);
   outputTree->Branch("JetSF_pTNbwflat",&JetSF_pTNbwflat,"JetSF_pTNbwflat/F");
   outputTree->Branch("JetSFup_pTNbwflat",&JetSFup_pTNbwflat,"JetSFup_pTNbwflat/F");
   outputTree->Branch("JetSFdn_pTNbwflat",&JetSFdn_pTNbwflat,"JetSFdn_pTNbwflat/F");
   outputTree->Branch("JetSFupwide_pTNbwflat",&JetSFupwide_pTNbwflat,"JetSFupwide_pTNbwflat/F");
   outputTree->Branch("JetSFdnwide_pTNbwflat",&JetSFdnwide_pTNbwflat,"JetSFdnwide_pTNbwflat/F");
   outputTree->Branch("minDR_leadAK8otherAK8",&minDR_leadAK8otherAK8,"minDR_leadAK8otherAK8/F");
   outputTree->Branch("minDR_lepAK8",&minDR_lepAK8,"minDR_lepAK8/F");
   outputTree->Branch("MT_lepMet",&MT_lepMet,"MT_lepMet/F");
   outputTree->Branch("deltaR_lepJets",&deltaR_lepJets);
   outputTree->Branch("deltaR_lepBJets",&deltaR_lepBJets);
   outputTree->Branch("deltaR_lepAK8s",&deltaR_lepAK8s);
   outputTree->Branch("deltaPhi_lepJets",&deltaPhi_lepJets);
   outputTree->Branch("deltaPhi_lepBJets",&deltaPhi_lepBJets);
   outputTree->Branch("deltaPhi_lepAK8s",&deltaPhi_lepAK8s);
   outputTree->Branch("mass_lepJets",&mass_lepJets);
   outputTree->Branch("mass_lepBJets",&mass_lepBJets);
   outputTree->Branch("mass_lepAK8s",&mass_lepAK8s);
   outputTree->Branch("theJetBTagBuggy_JetSubCalc_PtOrdered",&theJetBTagBuggy_JetSubCalc_PtOrdered);
   outputTree->Branch("event_CommonCalc",&event_CommonCalc,"event_CommonCalc/I");
   outputTree->Branch("run_CommonCalc",&run_CommonCalc,"run_CommonCalc/I");
   outputTree->Branch("lumi_CommonCalc",&lumi_CommonCalc,"lumi_CommonCalc/I");
   outputTree->Branch("nPV_singleLepCalc",&nPV_singleLepCalc,"nPV_singleLepCalc/I");
   outputTree->Branch("nTrueInteractions_singleLepCalc",&nTrueInteractions_singleLepCalc,"nTrueInteractions_singleLepCalc/I");
   outputTree->Branch("MCWeight_singleLepCalc",&MCWeight_singleLepCalc,"MCWeight_singleLepCalc/D");
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
   outputTree->Branch("ttbarMass_TTbarMassCalc",&ttbarMass_TTbarMassCalc,"ttbarMass_TTbarMassCalc/D");
   outputTree->Branch("NLeptonDecays_TpTpCalc",&NLeptonDecays_TpTpCalc,"NLeptonDecays_TpTpCalc/I");
   outputTree->Branch("corr_met_singleLepCalc",&corr_met_singleLepCalc,"corr_met_singleLepCalc/D");
   outputTree->Branch("corr_met_phi_singleLepCalc",&corr_met_phi_singleLepCalc,"corr_met_phi_singleLepCalc/D");
   outputTree->Branch("isElectron",&isElectron,"isElectron/I");
   outputTree->Branch("isMuon",&isMuon,"isMuon/I");
   outputTree->Branch("MCPastTrigger",&MCPastTrigger,"MCPastTrigger/I");
   outputTree->Branch("MCPastTriggerAlt",&MCPastTriggerAlt,"MCPastTriggerAlt/I");
   outputTree->Branch("DataPastTrigger",&DataPastTrigger,"DataPastTrigger/I");
   outputTree->Branch("DataPastTriggerAlt",&DataPastTriggerAlt,"DataPastTriggerAlt/I");
   outputTree->Branch("leptonPt_singleLepCalc",&leptonPt_singleLepCalc,"leptonPt_singleLepCalc/F");
   outputTree->Branch("leptonEta_singleLepCalc",&leptonEta_singleLepCalc,"leptonEta_singleLepCalc/F");
   outputTree->Branch("leptonPhi_singleLepCalc",&leptonPhi_singleLepCalc,"leptonPhi_singleLepCalc/F");
   outputTree->Branch("leptonEnergy_singleLepCalc",&leptonEnergy_singleLepCalc,"leptonEnergy_singleLepCalc/F");
   outputTree->Branch("leptonMiniIso_singleLepCalc",&leptonMiniIso_singleLepCalc,"leptonMiniIso_singleLepCalc/F");
   outputTree->Branch("leptonRelIso_singleLepCalc",&leptonRelIso_singleLepCalc,"leptonRelIso_singleLepCalc/F");
   outputTree->Branch("leptonDxy_singleLepCalc",&leptonDxy_singleLepCalc,"leptonDxy_singleLepCalc/F");
   outputTree->Branch("leptonDz_singleLepCalc",&leptonDz_singleLepCalc,"leptonDz_singleLepCalc/F");
   outputTree->Branch("leptonCharge_singleLepCalc",&leptonCharge_singleLepCalc,"leptonCharge_singleLepCalc/I");
   outputTree->Branch("theJetPt_JetSubCalc_PtOrdered",&theJetPt_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetEta_JetSubCalc_PtOrdered",&theJetEta_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetPhi_JetSubCalc_PtOrdered",&theJetPhi_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetEnergy_JetSubCalc_PtOrdered",&theJetEnergy_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetBTag_JetSubCalc_PtOrdered",&theJetBTag_JetSubCalc_PtOrdered);
   outputTree->Branch("WPt_JetSubCalc",&WPt_JetSubCalc);
   outputTree->Branch("WEta_JetSubCalc",&WEta_JetSubCalc);
   outputTree->Branch("WPhi_JetSubCalc",&WPhi_JetSubCalc);
   outputTree->Branch("WEnergy_JetSubCalc",&WEnergy_JetSubCalc);
   outputTree->Branch("WdecayDR_JetSubCalc",&WdecayDR_JetSubCalc);
   outputTree->Branch("theJetAK8Pt_JetSubCalc_PtOrdered",&theJetAK8Pt_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Eta_JetSubCalc_PtOrdered",&theJetAK8Eta_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Phi_JetSubCalc_PtOrdered",&theJetAK8Phi_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Energy_JetSubCalc_PtOrdered",&theJetAK8Energy_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8PrunedMass_JetSubCalc_PtOrdered",&theJetAK8PrunedMass_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SoftDropMass_JetSubCalc_PtOrdered",&theJetAK8SoftDropMass_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8MaxSubCSV_JetSubCalc_PtOrdered",&theJetAK8MaxSubCSV_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8NjettinessTau1_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau1_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8NjettinessTau2_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau2_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8NjettinessTau3_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau3_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8PrunedMassJMRSmeared_JetSubCalc",&theJetAK8PrunedMassJMRSmeared_JetSubCalc);
   outputTree->Branch("theJetAK8PrunedMassJMRSmearedUp_JetSubCalc",&theJetAK8PrunedMassJMRSmearedUp_JetSubCalc);
   outputTree->Branch("theJetAK8PrunedMassJMRSmearedDn_JetSubCalc",&theJetAK8PrunedMassJMRSmearedDn_JetSubCalc);
   outputTree->Branch("genJetPt_singleLepCalc",&genJetPt_singleLepCalc);
   outputTree->Branch("genJetEta_singleLepCalc",&genJetEta_singleLepCalc);
   outputTree->Branch("genJetPhi_singleLepCalc",&genJetPhi_singleLepCalc);
   outputTree->Branch("genJetEnergy_singleLepCalc",&genJetEnergy_singleLepCalc);
   outputTree->Branch("renormWeights",&renormWeights);
   outputTree->Branch("pdfWeights",&pdfWeights);
   outputTree->Branch("BJetLeadPtWithSF_JetSubCalc",&BJetLeadPtWithSF_JetSubCalc,"BJetLeadPtWithSF_JetSubCalc/F");
   outputTree->Branch("WJetLeadPt",&leadWJetPtak8,"WJetLeadPt/F");
   outputTree->Branch("WJetLeadPt_shifts",&leadWJetPtak8_shifts);
   outputTree->Branch("AK4HTpMETpLepPt",&AK4HTpMETpLepPt,"AK4HTpMETpLepPt/F");
   outputTree->Branch("AK4HT",&AK4HT,"AK4HT/F");
   outputTree->Branch("pileupWeight",&pileupWeight,"pileupWeight/F");
   outputTree->Branch("pileupWeight72ub",&pileupWeight72ub,"pileupWeight72ub/F");
   outputTree->Branch("pileupWeightUp",&pileupWeightUp,"pileupWeightUp/F");
   outputTree->Branch("pileupWeightDown",&pileupWeightDown,"pileupWeightDown/F");
   outputTree->Branch("TrigEffAltWeight",&TrigEffAltWeight,"TrigEffAltWeight/F");
   outputTree->Branch("TrigEffWeight",&TrigEffWeight,"TrigEffWeight/F");
   outputTree->Branch("isoSF",&isoSF,"isoSF/F");
   outputTree->Branch("lepIdSF",&lepIdSF,"lepIdSF/F");
   outputTree->Branch("NJets_JetSubCalc",&NJets_JetSubCalc,"NJets_JetSubCalc/I");
   outputTree->Branch("NJetsAK8_JetSubCalc",&NJetsAK8_JetSubCalc,"NJetsAK8_JetSubCalc/I");
   outputTree->Branch("NJetsCSV_JetSubCalc",&NJetsCSV_JetSubCalc,"NJetsCSV_JetSubCalc/I");
   outputTree->Branch("NJetsCSVwithSF_JetSubCalc",&NJetsCSVwithSF_JetSubCalc,"NJetsCSVwithSF_JetSubCalc/I");
   outputTree->Branch("NJetsWtagged",&NJetsWtagged,"NJetsWtagged/I");
   outputTree->Branch("NJetsHtagged",&NJetsHtagged,"NJetsHtagged/I");
   outputTree->Branch("topPt",&topPt,"topPt/F");
   outputTree->Branch("topPtGen",&topPtGen,"topPtGen/F");
   outputTree->Branch("topMass",&topMass,"topMass/F");
   outputTree->Branch("minMleppBjet",&minMleppBjet,"minMleppBjet/F");
   outputTree->Branch("minMleppJet",&minMleppJet,"mixnMleppJet/F");
   outputTree->Branch("genTopPt",&genTopPt,"genTopPt/F");
   outputTree->Branch("genAntiTopPt",&genAntiTopPt,"genAntiTopPt/F");
   outputTree->Branch("topPtWeight",&topPtWeight,"topPtWeight/F");
   outputTree->Branch("topPtWeightPast400",&topPtWeightPast400,"topPtWeightPast400/F");
   outputTree->Branch("topPtWeightHighPt",&topPtWeightHighPt,"topPtWeightHighPt/F");
   outputTree->Branch("deltaRlepJetInMinMljet",&deltaRlepJetInMinMljet,"deltaRlepJetInMinMljet/F");
   outputTree->Branch("deltaRlepbJetInMinMlb",&deltaRlepbJetInMinMlb,"deltaRlepbJetInMinMlb/F");
   outputTree->Branch("deltaPhilepJetInMinMljet",&deltaPhilepJetInMinMljet,"deltaPhilepJetInMinMljet/F");
   outputTree->Branch("deltaPhilepbJetInMinMlb",&deltaPhilepbJetInMinMlb,"deltaPhilepbJetInMinMlb/F");
   outputTree->Branch("deltaRtopWjet",&deltaRtopWjet,"deltaRtopWjet/F");
   outputTree->Branch("deltaRlepWjet",&deltaRlepWjet,"deltaRlepWjet/F");
   outputTree->Branch("deltaPhitopWjet",&deltaPhitopWjet,"deltaPhitopWjet/F");
   outputTree->Branch("deltaPhilepWjet",&deltaPhilepWjet,"deltaPhilepWjet/F");
   outputTree->Branch("deltaRtopWjet_shifts",&deltaRtopWjet_shifts);
   outputTree->Branch("deltaRlepWjet_shifts",&deltaRlepWjet_shifts);
   outputTree->Branch("deltaPhitopWjet_shifts",&deltaPhitopWjet_shifts);
   outputTree->Branch("deltaPhilepWjet_shifts",&deltaPhilepWjet_shifts);
   outputTree->Branch("WJetTaggedPt",&WJetTaggedPt);
   outputTree->Branch("WJetTaggedMass",&WJetTaggedMass);
   outputTree->Branch("WJetTaggedPtJMRup",&WJetTaggedPtJMRup);
   outputTree->Branch("WJetTaggedMassJMRup",&WJetTaggedMassJMRup);
   outputTree->Branch("WJetTaggedPtJMRdn",&WJetTaggedPtJMRdn);
   outputTree->Branch("WJetTaggedMassJMRdn",&WJetTaggedMassJMRdn);
   outputTree->Branch("WJetTaggedPtJMSup",&WJetTaggedPtJMSup);
   outputTree->Branch("WJetTaggedMassJMSup",&WJetTaggedMassJMSup);
   outputTree->Branch("WJetTaggedPtJMSdn",&WJetTaggedPtJMSdn);
   outputTree->Branch("WJetTaggedMassJMSdn",&WJetTaggedMassJMSdn);
   outputTree->Branch("WJetTaggedPtTAUup",&WJetTaggedPtTAUup);
   outputTree->Branch("WJetTaggedMassTAUup",&WJetTaggedMassTAUup);
   outputTree->Branch("WJetTaggedPtTAUdn",&WJetTaggedPtTAUdn);
   outputTree->Branch("WJetTaggedMassTAUdn",&WJetTaggedMassTAUdn);
   outputTree->Branch("deltaR_lepJets",&deltaR_lepJets);
   outputTree->Branch("deltaR_lepClosestJet",&deltaR_lepClosestJet,"deltaR_lepClosestJet/F");
   outputTree->Branch("PtRelLepClosestJet",&PtRelLepClosestJet,"PtRelLepClosestJet/F");

   TLorentzVector jet_lv;
   TLorentzVector bjet_lv;
   TLorentzVector wjet1_lv;
   TLorentzVector lepton_lv;
   TLorentzVector ak8_lv;
   
   // basic cuts
   float metCut=40;
   int   njetsCut=2;
   float JetLeadPtCut=125;
   float JetSubLeadPtCut=75;
   float lepPtCut=40;
   float elEtaCut=2.1;
   float jetEtaCut=2.4;
   float jetPtCut=30;

   std::vector<float> ptRangeTpTp, ptRangeTTbar;
   float ptminTTbar[15] = {200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700, 750, 800, 900, 1200};
   for (int i=0;i<15;++i) ptRangeTTbar.push_back(ptminTTbar[i]);
   float ptminTpTp[17] = {200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700, 750, 800, 900, 1000, 1100, 1200};
   for (int i=0;i<17;++i) ptRangeTpTp.push_back(ptminTpTp[i]);

   float SignalEff[17] = {0.260129,0.317269,0.346859,0.374089,0.396727,0.418234,0.436933,0.453725,0.464151,0.479066,0.48227,0.503652,0.494932,0.503458,0.496269,0.462555,0.457404};
   float TTbarEff[15] = {0.415831,0.514135,0.49113,0.448312,0.407475,0.369593,0.346835,0.31726,0.312786,0.290524,0.29417,0.272038,0.277081,0.287097,0.273381};
      
   //read CSC bad event filter file
   vector <int> CSC_run;
   vector <int> CSC_ls;
   vector <int> CSC_event;
   cout << "Reading CSC file" << std::endl;
   ifstream infileCSCm( "csc2015_Dec01.txt" );
   while (infileCSCm)
   {
     string s;
     if (!getline( infileCSCm, s )) break;

     istringstream ss( s );
     vector <string> line;
     while (ss)
     {
       string s;
       if (!getline( ss, s, ':' )) break;
       line.push_back( s );
     }
     CSC_run.push_back( std::atoi(line[0].c_str()) );
     CSC_ls.push_back( std::atoi(line[1].c_str()) );
     CSC_event.push_back( std::atoi(line[2].c_str()) );
   }
   if (!infileCSCm.eof())
   {
     cerr << "Error while reading CSC filter file!\n";
   }
   cout << "Done reading CSC file, testing vector size" << std::endl;
   cout << "Nevents = " << CSC_run.size() << ", " << CSC_ls.size() << ", " << CSC_event.size() << std::endl;

   //read bad ECAL SC filter file
   vector <int> ECALSC_run;
   vector <int> ECALSC_ls;
   vector <int> ECALSC_event;
   cout << "Reading ECAL SCN file" << std::endl;
   ifstream infileCSCe( "ecalscn1043093_Dec01.txt" );
   while (infileCSCe)
   {
     string s;
     if (!getline( infileCSCe, s )) break;

     istringstream ss( s );
     vector <string> line;
     while (ss)
     {
       string s;
       if (!getline( ss, s, ':' )) break;
       line.push_back( s );
     }
     ECALSC_run.push_back( std::atoi(line[0].c_str()) );
     ECALSC_ls.push_back( std::atoi(line[1].c_str()) );
     ECALSC_event.push_back( std::atoi(line[2].c_str()) );
   }
   if (!infileCSCe.eof())
   {
     cerr << "Error while reading ECAL SCN filter file!\n";
   }
   cout << "Done reading ECAL SCN file, testing vector size" << std::endl;
   cout << "Nevents = " << ECALSC_run.size() << ", " << ECALSC_ls.size() << ", " << ECALSC_event.size() << std::endl;
   
   
   double puweight260627_72ub[60] = {1.048445e+02, 1.417593e+02, 8.807366e+01, 3.236995e+01, 1.683957e+01, 2.831305e+00, 1.423759e+00, 1.612828e+00, 2.306693e+00, 2.473619e+00, 2.514170e+00, 2.546666e+00, 2.333108e+00, 1.836848e+00, 1.221869e+00, 6.836922e-01, 3.275329e-01, 1.432766e-01, 6.667120e-02, 3.763312e-02, 2.341225e-02, 1.359301e-02, 6.804618e-03, 2.922054e-03, 1.130104e-03, 4.448707e-04, 2.080687e-04, 1.239100e-04, 8.786009e-05, 6.837745e-05, 5.143024e-05, 3.476586e-05, 1.906542e-05, 9.115409e-06, 3.556074e-06, 1.447242e-06, 5.171527e-07, 1.940254e-07, 6.513423e-08, 2.309190e-08, 7.790329e-09, 2.199365e-09, 6.795396e-10, 1.624286e-10, 4.931596e-11, 1.298753e-11, 7.930341e-12, 2.315454e-12, 1.497868e-11, 2.172998e-12, 9.012326e-14, 1.094585e-14, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00};
   double puweight260627_69ub[60] = {1.245238e+02, 1.562054e+02, 9.528614e+01, 3.645428e+01, 2.049345e+01, 3.843197e+00, 2.215886e+00, 2.747772e+00, 3.412640e+00, 3.156122e+00, 2.921218e+00, 2.709273e+00, 2.214740e+00, 1.509242e+00, 8.529270e-01, 4.047681e-01, 1.706805e-01, 7.408239e-02, 3.853898e-02, 2.208110e-02, 1.157933e-02, 5.111779e-03, 1.897273e-03, 6.326908e-04, 2.194698e-04, 9.396686e-05, 5.134064e-05, 3.356329e-05, 2.432826e-05, 1.843384e-05, 1.299881e-05, 8.002472e-06, 3.916437e-06, 1.648432e-06, 5.607770e-07, 1.975807e-07, 6.075239e-08, 1.950465e-08, 5.573450e-09, 1.673234e-09, 4.755563e-10, 1.125301e-10, 2.899281e-11, 5.749377e-12, 1.440875e-12, 3.115802e-13, 1.554955e-13, 3.630806e-14, 2.427227e-13, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00};
   double puweight260627_65ub[60] = {1.458817e+02, 1.724645e+02, 1.043786e+02, 4.182011e+01, 2.579572e+01, 5.495080e+00, 3.731141e+00, 4.618505e+00, 4.765473e+00, 3.872168e+00, 3.259346e+00, 2.705177e+00, 1.908453e+00, 1.092269e+00, 5.137612e-01, 2.085454e-01, 8.454498e-02, 4.109705e-02, 2.206794e-02, 1.053976e-02, 4.084606e-03, 1.298473e-03, 3.698050e-04, 1.135070e-04, 4.460047e-05, 2.240654e-05, 1.319444e-05, 8.644198e-06, 5.969210e-06, 4.142850e-06, 2.600931e-06, 1.398830e-06, 5.905424e-07, 2.124612e-07, 6.132579e-08, 1.821361e-08, 4.691640e-09, 1.254258e-09, 2.966644e-10, 7.328361e-11, 1.703655e-11, 3.277952e-12, 6.826269e-13, 1.087907e-13, 2.182661e-14, 3.753385e-15, 1.408114e-15, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00, 0.000000e+00};
   double puweight260627_72ub_central[60] = {1.088e+02, 1.446e+02, 8.940e+01, 3.287e+01, 1.730e+01, 2.948e+00, 1.504e+00, 1.727e+00, 2.433e+00, 2.557e+00, 2.567e+00, 2.573e+00, 2.328e+00, 1.803e+00, 1.176e+00, 6.448e-01, 3.032e-01, 1.315e-01, 6.179e-02, 3.525e-02, 2.165e-02, 1.219e-02, 5.878e-03, 2.434e-03, 9.180e-04, 3.608e-04, 1.720e-04, 1.043e-04, 7.446e-05, 5.795e-05, 4.336e-05, 2.903e-05, 1.572e-05, 7.404e-06, 2.842e-06, 1.137e-06, 3.988e-07, 1.468e-07, 4.833e-08, 1.679e-08, 5.547e-09, 1.533e-09, 4.632e-10, 1.082e-10, 3.210e-11, 8.253e-12, 4.917e-12, 1.400e-12, 8.834e-12, 1.222e-12, 5.321e-14, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00};

   int npass_trigger      = 0;
   int npass_met          = 0;
   int npass_njets        = 0;
   int npass_nHjets       = 0;
   int npass_JetLeadPt    = 0;
   int npass_JetSubLeadPt = 0;
   int npass_lepPt        = 0;
   int npass_ElEta        = 0;
   int npass_all          = 0;
   int Nelectrons         = 0;
   int Nmuons             = 0;

   cout << "RUN CONFIG: " << endl;
   cout << "isSig = " << isSig << ", isTOP = " << isTOP << ", isMC = " << isMC << endl;
   
   Long64_t nentries = inputTree->GetEntriesFast();

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if (Cut(ientry) != 1) continue;
      
      //      if (ientry > 5000) continue;
      
      if(jentry % 1000 ==0) std::cout<<"Completed "<<jentry<<" out of "<<nentries<<" events"<<std::endl;

      // Filter input file by mass or decay
      if(isTTincMtt0to700 && ttbarMass_TTbarMassCalc >= 700.) continue;
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

      //CSC filter (aka muon halo filter) NOTE: filtering data sets by running both SE and SM CSC filters!
      bool filterEvent = false;
      for(unsigned int i=0; i < CSC_run.size(); i++){
      	if(CSC_run[i]==run_CommonCalc && CSC_ls[i]==lumi_CommonCalc && CSC_event[i]==event_CommonCalc) filterEvent = true;
      }
      for(unsigned int i=0; i < ECALSC_run.size(); i++){
      	if(ECALSC_run[i]==run_CommonCalc && ECALSC_ls[i]==lumi_CommonCalc && ECALSC_event[i]==event_CommonCalc) filterEvent = true;
      }
      if(filterEvent) continue;
     	     
      if(elPt_singleLepCalc->size()==0 && muPt_singleLepCalc->size()==0) continue;
      
      int isE = 0;
      int isM = 0;
      if(elPt_singleLepCalc->size()>0 && muPt_singleLepCalc->size()>0) std::cout << "got el and mu, something wrong" << std::endl;
      if(elPt_singleLepCalc->size()>1 && muPt_singleLepCalc->size()>1) std::cout << "got more than one el or mu, something wrong" << std::endl;
      if(elPt_singleLepCalc->size()>0 && muPt_singleLepCalc->size()==0) { isE = 1; isM = 0;}
      if(elPt_singleLepCalc->size()==0 && muPt_singleLepCalc->size()>0) { isE = 0; isM = 1;}
      if(isE==0 && isM==0)	 continue;

      double puweight = puweight260627_69ub[nTrueInteractions_singleLepCalc];
      double puweightup = puweight260627_65ub[nTrueInteractions_singleLepCalc];
      double puweightdown = puweight260627_72ub[nTrueInteractions_singleLepCalc];
      double puweight72ub = puweight260627_72ub_central[nTrueInteractions_singleLepCalc];

      int   isPastTrig = 0;
      int   isPastTrigAlt = 0;
      int   isPastTrigMC = 0;
      int   isPastTrigMCAlt = 0;
      float TrigEffAlt = 1.0;
      float TrigEff = 1.0;
      float isosf = 1.0;
      float lepidsf = 1.0;

      double leppt, lepeta;
      if(isE){leppt = elPt_singleLepCalc->at(0); lepeta = elEta_singleLepCalc->at(0);}
      if(isM){leppt = muPt_singleLepCalc->at(0); lepeta = muEta_singleLepCalc->at(0);}

      if(isMC){ //MC triggers check
      	if(isE){
	  for(unsigned int itrig=0; itrig < vsSelMCTriggersEl_singleLepCalc->size(); itrig++){
	    if(vsSelMCTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele27_eta2p1_WP75_Gsf_v1" && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigMC = 1;
	    if(vsSelMCTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v1" && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigMCAlt = 1;
	  }

	  // Ele45_PFJet200_PFJet50
	  if(leppt <  45){
	    if(fabs(lepeta) < 0.8) TrigEffAltWeight = 0.344; // 
	    else if(fabs(lepeta) < 1.442) TrigEffAltWeight = 0.350;
	    else if(fabs(lepeta) < 1.566) TrigEffAltWeight = 0.932;
	    else if(fabs(lepeta) < 2.0) TrigEffAltWeight = 0.343;
	    else TrigEffAltWeight = 0.058;
	  }else if(leppt < 50){
	    if(fabs(lepeta) < 0.8) TrigEffAltWeight = 0.890; // 
	    else if(fabs(lepeta) < 1.442) TrigEffAltWeight = 0.830;
	    else if(fabs(lepeta) < 1.566) TrigEffAltWeight = 0.855;
	    else if(fabs(lepeta) < 2.0) TrigEffAltWeight = 0.677;
	    else TrigEffAltWeight = 0.461;
	  }else if(leppt < 60){
	    if(fabs(lepeta) < 0.8) TrigEffAltWeight = 0.990; // 
	    else if(fabs(lepeta) < 1.442) TrigEffAltWeight = 0.980;
	    else if(fabs(lepeta) < 1.566) TrigEffAltWeight = 1.006;
	    else if(fabs(lepeta) < 2.0) TrigEffAltWeight = 1.032;
	    else TrigEffAltWeight = 0.980;
	  }else if(leppt < 70){
	    if(fabs(lepeta) < 0.8) TrigEffAltWeight = 0.992; // 
	    else if(fabs(lepeta) < 1.442) TrigEffAltWeight = 1.011;
	    else if(fabs(lepeta) < 1.566) TrigEffAltWeight = 0.991;
	    else if(fabs(lepeta) < 2.0) TrigEffAltWeight = 1.084;
	    else TrigEffAltWeight = 1.023;
	  }else if(leppt < 90){
	    if(fabs(lepeta) < 0.8) TrigEffAltWeight = 0.994; // 
	    else if(fabs(lepeta) < 1.442) TrigEffAltWeight = 1.000; // non-convergent fit
	    else if(fabs(lepeta) < 1.566) TrigEffAltWeight = 1.120;
	    else if(fabs(lepeta) < 2.0) TrigEffAltWeight = 1.058;
	    else TrigEffAltWeight = 1.032;
	  }else if(leppt < 130){
	    if(fabs(lepeta) < 0.8) TrigEffAltWeight = 1.001; // 
	    else if(fabs(lepeta) < 1.442) TrigEffAltWeight = 1.012;
	    else if(fabs(lepeta) < 1.566) TrigEffAltWeight = 1.061;
	    else if(fabs(lepeta) < 2.0) TrigEffAltWeight = 1.034;
	    else TrigEffAltWeight = 1.025;
	  }else if(leppt < 180){
	    if(fabs(lepeta) < 0.8) TrigEffAltWeight = 0.997; // 
	    else if(fabs(lepeta) < 1.442) TrigEffAltWeight = 0.988;
	    else if(fabs(lepeta) < 1.566) TrigEffAltWeight = 0.943;
	    else if(fabs(lepeta) < 2.0) TrigEffAltWeight = 1.016;
	    else TrigEffAltWeight = 1.060;
	  }else if(leppt < 250){
	    if(fabs(lepeta) < 0.8) TrigEffAltWeight = 1.001; // 
	    else if(fabs(lepeta) < 1.442) TrigEffAltWeight = 1.001;
	    else if(fabs(lepeta) < 1.566) TrigEffAltWeight = 0.974;
	    else if(fabs(lepeta) < 2.0) TrigEffAltWeight = 1.044;
	    else TrigEffAltWeight = 1.034;
	  }else{ TrigEffAltWeight = 1.000;}

	  // Ele27_eta2p1
	  if(leppt <  45){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.968; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 1.018;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 1.012;
	    else TrigEffWeight = 0.955;
	  }else if(leppt < 50){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.974; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 1.023;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.998;
	    else TrigEffWeight = 0.952;
	  }else if(leppt < 60){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.980; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 1.010;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.986;
	    else TrigEffWeight = 0.937;
	  }else if(leppt < 70){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.969; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 1.026;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 1.032;
	    else TrigEffWeight = 0.946;
	  }else if(leppt < 90){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.979; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 1.012;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 1.081;
	    else TrigEffWeight = 0.914;
	  }else if(leppt < 130){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 1.006; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 1.017;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.970;
	    else TrigEffWeight = 0.936;
	  }else if(leppt < 180){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 1.014; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 1.055;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.980;
	    else TrigEffWeight = 0.898;
	  }else{
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 1.025; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 1.011;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.933;
	    else TrigEffWeight = 0.934;
	  }
	  	
	  //miniIso < 0.1 scale factors from https://indico.cern.ch/event/370512/contribution/1/attachments/1176496/1701148/2015_10_26_tnp.pdf
	  if(fabs(lepeta) < 1.442){
	    if(leppt > 10 && leppt < 20) isosf = 0.979; // +/-0.004 
	    else if(leppt < 30) isosf = 0.988; // +/-0.002
	    else if(leppt < 40) isosf = 0.995; // +/-0.022
	    else if(leppt < 50) isosf = 0.995; // +/-0.011
	    else if(leppt < 200) isosf = 0.995; // +/-0.000
	  }
	  else if(fabs(lepeta) < 1.566){
	    if(leppt > 10 && leppt < 20) isosf = 0.909; // +/-0.05 
	    else if(leppt < 30) isosf = 0.982; // +/-0.014
	    else if(leppt < 40) isosf = 1.001; // +/-0.006
	    else if(leppt < 50) isosf = 0.993; // +/-0.007
	    else if(leppt < 200) isosf = 0.988; // +/-0.014
	  }
	  else if(fabs(lepeta) < 2.5){
	    if(leppt > 10 && leppt < 20) isosf = 0.984; // +/-0.011
	    else if(leppt < 30) isosf = 0.997; // +/-0.002
	    else if(leppt < 40) isosf = 1.000; // +/-0.001
	    else if(leppt < 50) isosf = 1.019; // +/-0.002
	    else if(leppt < 200) isosf = 1.000; // +/-0.002
	  }
	  else isosf = 1.;
	  
	  //MVA-based ID scale factors (non-triggering) from Clint Richardson https://indico.cern.ch/event/459111/contribution/1/attachments/1180755/1709309/B2G_Meeting_11.03.2015.pdf
	  if(lepeta > -2.5 && lepeta < -1.6){
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9880;
	    else if(leppt < 50.) lepidsf= 0.9663; 
	    else if(leppt < 70.) lepidsf= 0.9884;
	    else if(leppt < 90.) lepidsf= 0.9762; 
	    else if(leppt < 130.) lepidsf= 0.9727; 
	    else if(leppt < 180.) lepidsf= 0.9978; 
	    else if(leppt < 250.) lepidsf= 0.9118;
	    else if(leppt < 1000.) lepidsf= 0.9205;
	  } 
	  else if(lepeta < -1.4){
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9788; 
	    else if(leppt < 50.) lepidsf= 0.9821; 
	    else if(leppt < 70.) lepidsf= 0.9567; 
	    else if(leppt < 90.) lepidsf= 0.9926; 
	    else if(leppt < 130.) lepidsf= 0.9889; 
	    else if(leppt < 180.) lepidsf= 1.0034; 
	    else if(leppt < 250.) lepidsf= 1.1316; 
	    else if(leppt < 1000.) lepidsf= 1.0000;
	  }
	  else if(lepeta < -0.8){
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9945;
	    else if(leppt < 50.) lepidsf= 0.9849; 
	    else if(leppt < 70.) lepidsf= 0.9944;
	    else if(leppt < 90.) lepidsf= 1.0008; 
	    else if(leppt < 130.) lepidsf= 1.0077; 
	    else if(leppt < 180.) lepidsf= 0.9915; 
	    else if(leppt < 250.) lepidsf= 0.9556; 
	    else if(leppt < 1000.) lepidsf= 0.9274;
	  } 
	  else if(lepeta < 0.0){
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9923; 
	    else if(leppt < 50.) lepidsf= 0.9794; 
	    else if(leppt < 70.) lepidsf= 0.9887; 
	    else if(leppt < 90.) lepidsf= 0.9742; 
	    else if(leppt < 130.) lepidsf= 0.9611; 
	    else if(leppt < 180.) lepidsf= 1.0176; 
	    else if(leppt < 250.) lepidsf= 0.9990; 
	    else if(leppt < 1000.) lepidsf= 0.9677;
	  } 
	  else if(lepeta < 0.8){
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9990; 
	    else if(leppt < 50.) lepidsf= 0.9808; 
	    else if(leppt < 70.) lepidsf= 0.9657; 
	    else if(leppt < 90.) lepidsf= 0.9963; 
	    else if(leppt < 130.) lepidsf= 0.9963; 
	    else if(leppt < 180.) lepidsf= 0.9725; 
	    else if(leppt < 250.) lepidsf= 0.9769; 
	    else if(leppt < 1000.) lepidsf= 0.9334;
	  } 
	  else if(lepeta < 1.4){
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9934; 
	    else if(leppt < 50.) lepidsf= 0.9814; 
	    else if(leppt < 70.) lepidsf= 0.9871; 
	    else if(leppt < 90.) lepidsf= 0.9846; 
	    else if(leppt < 130.) lepidsf= 0.9545; 
	    else if(leppt < 180.) lepidsf= 1.0141; 
	    else if(leppt < 250.) lepidsf= 0.9824; 
	    else if(leppt < 1000.) lepidsf= 0.9443;
	  } 
	  else if(lepeta < 1.6){
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9771; 
	    else if(leppt < 50.) lepidsf= 0.9796; 
	    else if(leppt < 70.) lepidsf= 0.9811; 
	    else if(leppt < 90.) lepidsf= 1.0291; 
	    else if(leppt < 130.) lepidsf= 0.9010; 
	    else if(leppt < 180.) lepidsf= 1.0490; 
	    else if(leppt < 250.) lepidsf= 0.6082; 
	    else if(leppt < 1000.) lepidsf= 1.1424;
	  } 
	  else if(lepeta < 2.5){
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9746; 
	    else if(leppt < 50.) lepidsf= 0.9835; 
	    else if(leppt < 70.) lepidsf= 0.9868; 
	    else if(leppt < 90.) lepidsf= 0.9843; 
	    else if(leppt < 130.) lepidsf= 1.0039; 
	    else if(leppt < 180.) lepidsf= 0.9597; 
	    else if(leppt < 250.) lepidsf= 0.9987; 
	    else if(leppt < 1000.) lepidsf= 1.0271;
	  }
	  else{lepidsf= 1.0;}
	}
      	if(isM){
	  for(unsigned int itrig=0; itrig < vsSelMCTriggersMu_singleLepCalc->size(); itrig++){
	    if((vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu20_v1" || vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu20_v1") && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigMC = 1;
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v1" && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigMCAlt = 1;
	  }

	  // Mu45_eta2p1 eff
	  if(leppt <  45){
	    if(fabs(lepeta) < 0.8) TrigEffAltWeight = 1.601; // 
	    else if(fabs(lepeta) < 1.442) TrigEffAltWeight = 1.710;
	    else if(fabs(lepeta) < 1.566) TrigEffAltWeight = 1.738;
	    else TrigEffAltWeight = 1.835;
	  }else if(leppt < 50){
	    if(fabs(lepeta) < 0.8) TrigEffAltWeight = 0.958; // 
	    else if(fabs(lepeta) < 1.442) TrigEffAltWeight = 0.952;
	    else if(fabs(lepeta) < 1.566) TrigEffAltWeight = 0.960;
	    else TrigEffAltWeight = 0.932;
	  }else if(leppt < 60){
	    if(fabs(lepeta) < 0.8) TrigEffAltWeight = 0.975; // 
	    else if(fabs(lepeta) < 1.442) TrigEffAltWeight = 0.975;
	    else if(fabs(lepeta) < 1.566) TrigEffAltWeight = 0.987;
	    else TrigEffAltWeight = 0.966;
	  }else if(leppt < 70){
	    if(fabs(lepeta) < 0.8) TrigEffAltWeight = 0.978; // 
	    else if(fabs(lepeta) < 1.442) TrigEffAltWeight = 0.974;
	    else if(fabs(lepeta) < 1.566) TrigEffAltWeight = 0.993;
	    else TrigEffAltWeight = 0.975;
	  }else if(leppt < 90){
	    if(fabs(lepeta) < 0.8) TrigEffAltWeight = 0.977; // 
	    else if(fabs(lepeta) < 1.442) TrigEffAltWeight = 0.975;
	    else if(fabs(lepeta) < 1.566) TrigEffAltWeight = 0.990;
	    else TrigEffAltWeight = 0.977;
	  }else if(leppt < 130){
	    if(fabs(lepeta) < 0.8) TrigEffAltWeight = 0.974; // 
	    else if(fabs(lepeta) < 1.442) TrigEffAltWeight = 0.965;
	    else if(fabs(lepeta) < 1.566) TrigEffAltWeight = 1.015;
	    else TrigEffAltWeight = 0.956;
	  }else if(leppt < 180){
	    if(fabs(lepeta) < 0.8) TrigEffAltWeight = 0.983; // 
	    else if(fabs(lepeta) < 1.442) TrigEffAltWeight = 0.979;
	    else if(fabs(lepeta) < 1.566) TrigEffAltWeight = 1.000;
	    else TrigEffAltWeight = 0.975;
	  }else{ TrigEffAltWeight = 1.000;}

	  // IsoMu20 || IsoTkMu20 Eff
	  if(leppt < 45){
	    if(fabs(lepeta) < 0.9) TrigEffWeight = 0.9920; //0.982; // 
	    else if(fabs(lepeta) < 1.2) TrigEffWeight = 0.9955; //0.983;
	    else if(fabs(lepeta) < 2.1) TrigEffWeight = 0.9889; //1.001;
	    else TrigEffWeight = 1.0156; //1.005;
	  }else if(leppt < 50){
	    if(fabs(lepeta) < 0.9) TrigEffWeight = 0.9894; //0.983; // 
	    else if(fabs(lepeta) < 1.2) TrigEffWeight = 0.9950; //0.983;
	    else if(fabs(lepeta) < 2.1) TrigEffWeight = 0.9891; //1.001;
	    else TrigEffWeight = 1.0110; //0.998;
	  }else if(leppt < 60){
	    if(fabs(lepeta) < 0.9) TrigEffWeight = 0.9905; //0.983; // 
	    else if(fabs(lepeta) < 1.2) TrigEffWeight = 0.9984; //0.983;
	    else if(fabs(lepeta) < 2.1) TrigEffWeight = 0.9903; //1.001;
	    else TrigEffWeight = 1.0170; //0.998;
	  }else if(leppt < 120){
	    if(fabs(lepeta) < 0.9) TrigEffWeight = 0.9902; //0.984; // 
	    else if(fabs(lepeta) < 1.2) TrigEffWeight = 0.9953; //0.983;
	    else if(fabs(lepeta) < 2.1) TrigEffWeight = 0.9882; //1.004;
	    else TrigEffWeight = 1.0129; //1.006;
	  }else{
	    if(fabs(lepeta) < 0.9) TrigEffWeight = 1.0146;// 
	    else if(fabs(lepeta) < 1.2) TrigEffWeight = 0.9853;
	    else if(fabs(lepeta) < 2.1) TrigEffWeight = 0.9866;
	    else TrigEffWeight = 1.0563;
	  }
 
	  //Mini-iso < 0.2 SFs from SUSY TWiki
	  if(leppt < 40){
	    if(fabs(lepeta) < 0.9) isosf= 1.000;
	    else if(fabs(lepeta) <  1.2) isosf= 1.000;
	    else if(fabs(lepeta) <  2.1) isosf= 0.999;
	    else if(fabs(lepeta) <  2.4) isosf= 0.999;
	  }
	  else if(leppt < 50){
	    if(fabs(lepeta) < 0.9) isosf= 1.000;
	    else if(fabs(lepeta) <  1.2) isosf= 1.000;
	    else if(fabs(lepeta) <  2.1) isosf= 0.999;
	    else if(fabs(lepeta) <  2.4) isosf= 1.000;
	  }
	  else if(leppt < 60){
	    if(fabs(lepeta) < 0.9) isosf= 1.000;
	    else if(fabs(lepeta) <  1.2) isosf= 1.000;
	    else if(fabs(lepeta) <  2.1) isosf= 1.000;
	    else if(fabs(lepeta) <  2.4) isosf= 1.000;
	  }
	  else{
	    if(fabs(lepeta) < 0.9) isosf= 1.000;
	    else if(fabs(lepeta) <  1.2) isosf= 0.999;
	    else if(fabs(lepeta) <  2.1) isosf= 0.998;
	    else if(fabs(lepeta) <  2.4) isosf= 1.000;
	  }
	  
	  //Cut-based ID scale factors from Clint Richardson https://indico.cern.ch/event/459111/contribution/1/attachments/1180755/1709309/B2G_Meeting_11.03.2015.pdf
	  if(lepeta >= -2.4 && lepeta < -2.1){
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9812;
	    else if(leppt < 60.) lepidsf= 0.9793;
	    else if(leppt < 100.) lepidsf= 0.9600;
	    else if(leppt < 1000.) lepidsf= 0.9738;
	  } 
	  else if(lepeta < -1.2){
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9910;
	    else if(leppt < 60.) lepidsf= 0.9922;
	    else if(leppt < 100.) lepidsf= 0.9923;
	    else if(leppt < 1000.) lepidsf= 1.0039;
	  }
	  else if(lepeta < -0.9){ 
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9828;
	    else if(leppt < 60.) lepidsf= 0.9886;
	    else if(leppt < 100.) lepidsf= 0.9873;
	    else if(leppt < 1000.) lepidsf= 0.9876;
	  }
	  else if(lepeta < -0.4){ 
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9909;
	    else if(leppt < 60.) lepidsf= 0.9920; 
	    else if(leppt < 100.) lepidsf= 0.9854;
	    else if(leppt < 1000.) lepidsf= 0.9951;
	  }
	  else if(lepeta < 0.0){ 
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9878;
	    else if(leppt < 60.) lepidsf= 0.9874;
	    else if(leppt < 100.) lepidsf= 0.9885;
	    else if(leppt < 1000.) lepidsf= 0.9985;
	  }
	  else if(lepeta < 0.4){
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9847;
	    else if(leppt < 60.) lepidsf= 0.9877;
	    else if(leppt < 100.) lepidsf= 0.9896;
	    else if(leppt < 1000.) lepidsf= 1.0165;
	  }
	  else if(lepeta < 0.9){ 
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9869;
	    else if(leppt < 60.) lepidsf= 0.9898;
	    else if(leppt < 100.) lepidsf= 0.9875;
	    else if(leppt < 1000.) lepidsf= 0.9754;
	  }
	  else if(lepeta < 1.2){ 
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9724;
	    else if(leppt < 60.) lepidsf= 0.9746;
	    else if(leppt < 100.) lepidsf= 0.9696;
	    else if(leppt < 1000.) lepidsf= 0.9757;
	  }
	  else if(lepeta < 2.1){ 
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9929;
	    else if(leppt < 60.) lepidsf= 0.9947;
	    else if(leppt < 100.) lepidsf= 0.9929;
	    else if(leppt < 1000.) lepidsf= 0.9987;
	  }
	  else if(lepeta < 2.4){ 
	    if(leppt > 30. && leppt < 40.) lepidsf= 0.9818;
	    else if(leppt < 60.) lepidsf= 0.9851;
	    else if(leppt < 100.) lepidsf= 0.9724;
	    else if(leppt < 1000.) lepidsf= 1.0028;
	  }
	  else{lepidsf= 1.0;} 
	}
      	isPastTrig = 1;
      	isPastTrigAlt = 1;
      }
      else{ //Data triggers check
	if(isE){
	  for(unsigned int itrig=0; itrig < vsSelTriggersEl_singleLepCalc->size(); itrig++){
	    if(vsSelTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele27_eta2p1_WPLoose_Gsf_v1" && viSelTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele27_eta2p1_WPLoose_Gsf_v2" && viSelTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele27_eta2p1_WPLoose_Gsf_v3" && viSelTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele27_eta2p1_WPLoose_Gsf_v4" && viSelTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v1" && viSelTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v2" && viSelTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v3" && viSelTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v4" && viSelTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	  }
	}
	if(isM){
	  for(unsigned int itrig=0; itrig < vsSelTriggersMu_singleLepCalc->size(); itrig++){
	    if((vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu20_v1" || vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu20_v1") && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if((vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu20_v2" || vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu20_v2") && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if((vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu20_v3" || vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu20_v3") && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if((vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu20_v4" || vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu20_v4") && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v1" && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v2" && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v3" && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v4" && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	  }
	}
	isPastTrigMC = 1;
	isPastTrigMCAlt = 1;
      }
      
      if(isPastTrig) npass_trigger+=1;

      float leadJetPtcsv = 0;
      int   njets = 0;
      int   nbtags = 0;
      float ht = 0;
      AK4HTnoSF = 0;
      vector<pair<double,int>> jetptindpair;
      JetSF_pTNbwflat = 1.0;
      JetSFup_pTNbwflat = 1.0;
      JetSFdn_pTNbwflat = 1.0;
      JetSFupwide_pTNbwflat = 1.0;
      JetSFdnwide_pTNbwflat = 1.0;

      std::vector<int> theJetBTagBuggy;

      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc->size(); ijet++){

	/// FIX THE MISTAGS -- value in theJetBTag is correct if flavor is 4/5
	theJetBTagBuggy.push_back(theJetBTag_JetSubCalc->at(ijet));

	if(isMC && AK4JetFlav_singleLepCalc->at(ijet) != 4 && AK4JetFlav_singleLepCalc->at(ijet) != 5){
	  double mistagSF = 1.0;

	  if(MistagSFup) mistagSF = 1.34022; // up
	  else if(MistagSFdn) mistagSF = 0.94022; // down
	  else mistagSF = 1.14022; // central
 
	  double mistageff = 0.0;
	  double pt = theJetPt_JetSubCalc->at(ijet);
	  if(pt < 20) mistageff = 0.003402;
	  else if(pt < 40) mistageff = 0.008067;
	  else if(pt < 60) mistageff = 0.006980;
	  else if(pt < 80) mistageff = 0.006316;
	  else if(pt < 100) mistageff = 0.006713;
	  else if(pt < 115) mistageff = 0.006598;
	  else if(pt < 400) mistageff = -0.00242504 + 9.15452e-05*pt - 9.63553e-08*pt*pt;
	  else mistageff = 0.0134038 + 1.24358e-05*pt;

	  bool isBTagged = (theJetCSV_JetSubCalc->at(ijet) > 0.890);
	  bool newBTag = isBTagged;

	  //throw die
	  float coin = gRandom->Uniform(1.);    
  
	  if(mistagSF > 1){  // use this if SF>1
	    if( !isBTagged ) {

	      //fraction of jets that need to be upgraded
	      float mistagPercent = (1.0 - mistagSF) / (1.0 - (mistagSF/mistageff) );

	      //upgrade to tagged
	      if( coin < mistagPercent ) {newBTag = true;} // is was false before
	    }	    
	  }else{  // use this if SF<1
  
	    //downgrade tagged to untagged
	    if( isBTagged && coin > mistagSF ) {newBTag = false;} // it was true before
	  }
	  theJetBTag_JetSubCalc->at(ijet) =  newBTag;
	}

	AK4HTnoSF += theJetPt_JetSubCalc->at(ijet);

	if(isMC){
	  float one = 1.0;
	    
	  float jetpt = theJetPt_JetSubCalc->at(ijet);
	  float jetsf = 1.09383 - 0.000477777*jetpt;
	  float jetsferr = sqrt(0.00314541714554 + 2.18390370364e-08*jetpt*jetpt + 2*jetpt*(-7.85447860996e-06));
	  
	  float wideup = min(one,max(float(0.747382 + 0.164524),jetsf+jetsferr));				    
	  float widedn = min(one,max(jetsf-jetsferr,float(0.747382 - 0.164524)));
	  
	  if(isTOP || isSig){
	    if(jetpt >= 200){
	      if(jetpt < 725){
		JetSF_pTNbwflat *= min(one,jetsf);
		JetSFup_pTNbwflat *= wideup;
		JetSFdn_pTNbwflat *= widedn;
		JetSFupwide_pTNbwflat *= wideup;
		JetSFdnwide_pTNbwflat *= widedn;
	      }else{
		JetSF_pTNbwflat *= 0.747382;
		JetSFup_pTNbwflat *= wideup;
		JetSFdn_pTNbwflat *= widedn;
		JetSFupwide_pTNbwflat *= wideup;
		JetSFdnwide_pTNbwflat *= widedn;
	      }
	    }
	  }else{
	    jetsf = 1.24507 - 0.000664768*jetpt;
	    jetsferr = sqrt(0.000506216376592 + 3.1532423475e-09*jetpt*jetpt + 2*jetpt*(-1.17981363543e-06));
	    if(jetpt < 1020){
	      JetSF_pTNbwflat *= min(one,jetsf);
	      JetSFup_pTNbwflat *= min(one,max(jetsf+jetsferr,float(0.568135+0.0522921)));
	      JetSFdn_pTNbwflat *= min(one,max(jetsf-jetsferr,float(0.568135-0.0522921)));
	      JetSFupwide_pTNbwflat *= max(wideup,min(one,max(jetsf+jetsferr,float(0.568135+0.0522921))));
	      JetSFdnwide_pTNbwflat *= min(widedn,min(one,max(jetsf-jetsferr,float(0.568135-0.0522921))));
	    }else{
	      JetSF_pTNbwflat *= 0.568135;
	      JetSFup_pTNbwflat *= min(one,max(jetsf+jetsferr,float(0.568135+0.0522921)));
	      JetSFdn_pTNbwflat *= min(one,max(jetsf-jetsferr,float(0.568135-0.0522921)));
	      JetSFupwide_pTNbwflat *= max(wideup,min(one,max(jetsf+jetsferr,float(0.568135+0.0522921))));
	      JetSFdnwide_pTNbwflat *= min(widedn,min(one,max(jetsf-jetsferr,float(0.568135-0.0522921))));
	    }
	  }
	  
	  jetptindpair.push_back(std::make_pair(theJetPt_JetSubCalc->at(ijet),ijet));
	  njets+=1;
	  ht+=theJetPt_JetSubCalc->at(ijet);
	  if(theJetCSV_JetSubCalc->at(ijet) > 0.890) nbtags+=1;
	  
	}else{
	  jetptindpair.push_back(std::make_pair(theJetPt_JetSubCalc->at(ijet),ijet));
	  njets+=1;
	  ht+=theJetPt_JetSubCalc->at(ijet);
	  if(theJetCSV_JetSubCalc->at(ijet) > 0.890) nbtags+=1;
	}
      }
	
      //Pt ordering
      std::sort(jetptindpair.begin(), jetptindpair.end(), comparepair);
      theJetPt_JetSubCalc_PtOrdered.clear();
      theJetEta_JetSubCalc_PtOrdered.clear();
      theJetPhi_JetSubCalc_PtOrdered.clear();
      theJetEnergy_JetSubCalc_PtOrdered.clear();
      theJetCSV_JetSubCalc_PtOrdered.clear();
      theJetBTag_JetSubCalc_PtOrdered.clear();
      theJetBTagBuggy_JetSubCalc_PtOrdered.clear();
      for(unsigned int ijet=0; ijet < jetptindpair.size(); ijet++){
      	theJetPt_JetSubCalc_PtOrdered.push_back(theJetPt_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetEta_JetSubCalc_PtOrdered.push_back(theJetEta_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetPhi_JetSubCalc_PtOrdered.push_back(theJetPhi_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetEnergy_JetSubCalc_PtOrdered.push_back(theJetEnergy_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetCSV_JetSubCalc_PtOrdered.push_back(theJetCSV_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetBTag_JetSubCalc_PtOrdered.push_back(theJetBTag_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetBTagBuggy_JetSubCalc_PtOrdered.push_back(theJetBTagBuggy.at(jetptindpair[ijet].second));
      }
	                
      //require "njetsCut" jets
      int isPastNJetsCut = 0;
      if(njets >= njetsCut){npass_njets+=1;isPastNJetsCut=1;}
      
      //check for high pt jet
      int isPastJetLeadPtCut = 0;
      if(theJetPt_JetSubCalc_PtOrdered[0] > JetLeadPtCut){npass_JetLeadPt+=1;isPastJetLeadPtCut=1;}
      
      //check for second high pt jet
      int isPastJetSubLeadPtCut = 0;
      if(theJetPt_JetSubCalc_PtOrdered[1] > JetSubLeadPtCut){npass_JetSubLeadPt+=1;isPastJetSubLeadPtCut=1;}
      
      //check met requirement
      int isPastMETcut = 0;
      if(corr_met_singleLepCalc > metCut){npass_met+=1;isPastMETcut=1;}

      //check lepton requirement
      int isPastLepPtCut = 0;
      if(leppt > lepPtCut){npass_lepPt+=1;isPastLepPtCut=1;}
      
      //require electron eta to be tighter than trigger eta cut
      int isPastElEtaCut = 0;
      if(isE && fabs(lepeta) < elEtaCut){npass_ElEta+=1;isPastElEtaCut=1;}
      if(isM){Nmuons+=1;isPastElEtaCut=1;}
      if(isE){Nelectrons+=1;}
      
      float st = 0;
      st = ht + corr_met_singleLepCalc + leppt;
      
      //count up tags
      int nHtags = 0;      
      int njetsak8 = 0;
      vector<float> maxsubcsv;
      vector<pair<double,int>> jetak8ptindpair;
      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc->size(); ijet++){
	maxsubcsv.push_back(-99.0);
	if(theJetAK8Pt_JetSubCalc->at(ijet) < 200 || fabs(theJetAK8Eta_JetSubCalc->at(ijet)) > 2.4) continue;
	if(theJetAK8NjettinessTau1_JetSubCalc->at(ijet)==0) continue;

	njetsak8 += 1; 
	jetak8ptindpair.push_back(std::make_pair(theJetAK8Pt_JetSubCalc->at(ijet),ijet));
	  
	int firstsub = theJetAK8SDSubjetIndex_JetSubCalc->at(ijet);
	int nsubs = theJetAK8SDSubjetSize_JetSubCalc->at(ijet);
	double maxCSVsubjet = 0;
	TLorentzVector tempsubjet;
	TLorentzVector sumsubjets; sumsubjets.SetPtEtaPhiM(0,0,0,0);
	for(int isub = firstsub; isub < firstsub + nsubs; isub++){
	  tempsubjet.SetPtEtaPhiM(theJetAK8SDSubjetPt_JetSubCalc->at(isub),theJetAK8SDSubjetEta_JetSubCalc->at(isub),theJetAK8SDSubjetPhi_JetSubCalc->at(isub),theJetAK8SDSubjetMass_JetSubCalc->at(isub));
	  sumsubjets += tempsubjet;
	  if(theJetAK8SDSubjetCSV_JetSubCalc->at(isub) > maxCSVsubjet) maxCSVsubjet = theJetAK8SDSubjetCSV_JetSubCalc->at(isub);
	  if(isub != firstsub && theJetAK8SDSubjetPt_JetSubCalc->at(isub) == theJetAK8SDSubjetPt_JetSubCalc->at(firstsub)) cout << "subjets have matching pT, something's wrong" << endl;
	}
	maxsubcsv.at(ijet) = maxCSVsubjet;
	if(theJetAK8Pt_JetSubCalc->at(ijet) > 300 &&  theJetAK8SDSubjetNCSVMSF_JetSubCalc->at(ijet) > 0 && sumsubjets.M() > 60 && sumsubjets.M() < 150) nHtags += 1;
      }

      int isPastNHjetsCut = 0;
      if(nHtags >= 0){npass_nHjets += 1; isPastNHjetsCut = 1; }

      // check all the cuts!
      if(!(isPastMETcut && isPastNJetsCut && isPastJetLeadPtCut && isPastLepPtCut && isPastElEtaCut && isPastJetSubLeadPtCut && isPastNHjetsCut)) continue;
      npass_all+=1;

      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /////////////// ONLY ON SELECTED EVENTS ////////////////////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

      //Pt ordering for AK8
      std::sort(jetak8ptindpair.begin(), jetak8ptindpair.end(), comparepair);
      theJetAK8Pt_JetSubCalc_PtOrdered.clear();
      theJetAK8Eta_JetSubCalc_PtOrdered.clear();
      theJetAK8Phi_JetSubCalc_PtOrdered.clear();
      theJetAK8Energy_JetSubCalc_PtOrdered.clear();
      theJetAK8Mass_JetSubCalc_PtOrdered.clear();
      theJetAK8PrunedMass_JetSubCalc_PtOrdered.clear();
      theJetAK8SoftDropMass_JetSubCalc_PtOrdered.clear();
      theJetAK8MaxSubCSV_JetSubCalc_PtOrdered.clear();
      theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.clear();
      theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.clear();
      theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.clear();
      for(unsigned int ijet=0; ijet < jetak8ptindpair.size(); ijet++){
      	theJetAK8Pt_JetSubCalc_PtOrdered.push_back(theJetAK8Pt_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Eta_JetSubCalc_PtOrdered.push_back(theJetAK8Eta_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Phi_JetSubCalc_PtOrdered.push_back(theJetAK8Phi_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Energy_JetSubCalc_PtOrdered.push_back(theJetAK8Energy_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Mass_JetSubCalc_PtOrdered.push_back(theJetAK8Mass_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8PrunedMass_JetSubCalc_PtOrdered.push_back(theJetAK8PrunedMass_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDropMass_JetSubCalc_PtOrdered.push_back(theJetAK8SoftDropMass_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8MaxSubCSV_JetSubCalc_PtOrdered.push_back(maxsubcsv.at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau1_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau2_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau3_JetSubCalc->at(jetak8ptindpair[ijet].second));
      }

      double lepM;
      double lepphi;
      if (isM){ 
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

      int   nbtagWithSF = 0;
      float leadBJetPt = 0;
      float minMlb = 1e8;
      float minMljet = 1e8;
      float deltaR_lepJetInMinMljet = -99;
      float deltaPhi_lepJetInMinMljet = -99;
      float deltaR_lepbJetInMinMlb = -99;
      float deltaPhi_lepbJetInMinMlb = -99;
      float mindeltar = 1e8;
      float ptrel_lepclosestjet = -99;
      deltaR_lepJets.clear();
      deltaR_lepBJets.clear();
      deltaPhi_lepJets.clear();
      deltaPhi_lepBJets.clear();
      mass_lepJets.clear();
      mass_lepBJets.clear();

      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc_PtOrdered.size(); ijet++){
        jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(ijet),theJetEta_JetSubCalc_PtOrdered.at(ijet),theJetPhi_JetSubCalc_PtOrdered.at(ijet),theJetEnergy_JetSubCalc_PtOrdered.at(ijet));
	if((lepton_lv + jet_lv).M() < minMljet) {
	  minMljet = fabs((lepton_lv + jet_lv).M());
	  deltaR_lepJetInMinMljet = jet_lv.DeltaR(lepton_lv);
	  deltaPhi_lepJetInMinMljet = jet_lv.DeltaPhi(lepton_lv);
	}

	deltaR_lepJets.push_back(lepton_lv.DeltaR(jet_lv));
	deltaPhi_lepJets.push_back(lepton_lv.DeltaPhi(jet_lv));
	mass_lepJets.push_back((lepton_lv + jet_lv).M());
	if(theJetBTag_JetSubCalc_PtOrdered.at(ijet) == 1){
	  nbtagWithSF += 1;
	  if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > leadBJetPt) leadBJetPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
	  deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));
	  deltaPhi_lepBJets.push_back(lepton_lv.DeltaPhi(jet_lv));
	  mass_lepBJets.push_back((lepton_lv + jet_lv).M());

	  if((lepton_lv + jet_lv).M() < minMlb) {
	    minMlb = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepbJetInMinMlb = jet_lv.DeltaR(lepton_lv);
	    deltaPhi_lepbJetInMinMlb = jet_lv.DeltaPhi(lepton_lv);
	  }
	}

 	if(deltaR_lepJets[ijet] < mindeltar) {
	  mindeltar = deltaR_lepJets[ijet];
	  ptrel_lepclosestjet = lepton_lv.P()*(jet_lv.Vect().Cross(lepton_lv.Vect()).Mag()/jet_lv.P()/lepton_lv.P());
	}
      }

      //8TeV Top Pt Reweighting
      float gen_tpt = -999;
      float gen_anti_tpt = -999;
      for(unsigned int ijet=0; ijet < topPt_TTbarMassCalc->size(); ijet++){
	if(gen_tpt < 0 && topID_TTbarMassCalc->at(ijet) == 6) gen_tpt = topPt_TTbarMassCalc->at(ijet);
	if(gen_anti_tpt < 0 && topID_TTbarMassCalc->at(ijet) == -6) gen_anti_tpt = topPt_TTbarMassCalc->at(ijet);
      }
      
      float toppt_temp = gen_tpt;
      if(gen_tpt > 400) toppt_temp = 400;
      float antitoppt_temp = gen_anti_tpt;
      if(gen_anti_tpt > 400) antitoppt_temp = 400;
      
      float SFtop = TMath::Exp(0.156-0.00137*toppt_temp); // using 8TeV TopPtReweighting: https://twiki.cern.ch/twiki/bin/viewauth/CMS/TopPtReweighting
      float SFantitop = TMath::Exp(0.156-0.00137*antitoppt_temp);
      float weight_toppt = TMath::Sqrt(SFtop*SFantitop)/0.99277; //0.99277-->average weight
      
      float SFtopPast400 = TMath::Exp(0.156-0.00137*gen_tpt);
      float SFantitopPast400 = TMath::Exp(0.156-0.00137*gen_anti_tpt);
      float weightPast400_toppt = TMath::Sqrt(SFtopPast400*SFantitopPast400)/0.9927;

      float SFtopHighPt = 0.98  - 0.00026*gen_tpt;  // 0.98 +- 0.24, 0.0026 +- 0.00039
      float SFantitopHighPt = 0.98  - 0.00026*gen_anti_tpt;
      float weightHighPt_toppt = TMath::Sqrt(SFtopHighPt*SFantitopHighPt);

      //Calculate neutrino Pz
      
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
      
      TLorentzVector Wlv_1, Wlv_2, Wlv,lvTop, lvXTF;
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
      
      double dMTOP = 1e8;
      unsigned int topIndex = 0;
      bool firstW = true;
      double MTop_1, MTop_2;
      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc_PtOrdered.size(); ijet++){
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
      }

      if(firstW) {Wlv = Wlv_1;}
      else{Wlv = Wlv_2;}

      jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(topIndex),theJetEta_JetSubCalc_PtOrdered.at(topIndex),theJetPhi_JetSubCalc_PtOrdered.at(topIndex),theJetEnergy_JetSubCalc_PtOrdered.at(topIndex));
      lvTop = jet_lv + Wlv; //Top LV

      
      int nWtags = 0;
      NJetsWtagged_0p6 = 0;
      deltaR_lepAK8s.clear();
      deltaPhi_lepAK8s.clear();
      mass_lepAK8s.clear();
      minDR_lepAK8 = 1000;
      leadWJetPtak8 = -99.0;
      deltaRtopWjet = -99;     deltaPhitopWjet = -99;
      deltaRlepWjet = -99;     deltaPhilepWjet = -99;	  

      NJetsWtagged_0p6_shifts.clear();
      theJetAK8Wmatch_JetSubCalc_PtOrdered.clear();
      leadWJetPtak8_shifts.clear();
      deltaRtopWjet_shifts.clear();  deltaPhitopWjet_shifts.clear(); 
      deltaRlepWjet_shifts.clear();  deltaPhilepWjet_shifts.clear(); 
      WJetTaggedPt.clear();           WJetTaggedMass.clear();
      WJetTaggedPtJMRup.clear();      WJetTaggedMassJMRup.clear();
      WJetTaggedPtJMRdn.clear();      WJetTaggedMassJMRdn.clear();
      WJetTaggedPtJMSup.clear();      WJetTaggedMassJMSup.clear();
      WJetTaggedPtJMSdn.clear();      WJetTaggedMassJMSdn.clear();
      WJetTaggedPtTAUup.clear();      WJetTaggedMassTAUup.clear();
      WJetTaggedPtTAUdn.clear();      WJetTaggedMassTAUdn.clear();
      theJetAK8PrunedMassJMRSmeared_JetSubCalc.clear();
      theJetAK8PrunedMassJMRSmearedUp_JetSubCalc.clear();
      theJetAK8PrunedMassJMRSmearedDn_JetSubCalc.clear();

      wjet1_lv.SetPtEtaPhiM(0,0,0,0);
      ak8_lv.SetPtEtaPhiM(0,0,0,0);

      for(int i = 0; i < 6; i++){
	NJetsWtagged_0p6_shifts.push_back(0);
	leadWJetPtak8_shifts.push_back(-99.0);
	deltaRtopWjet_shifts.push_back(-99.0);  deltaPhitopWjet_shifts.push_back(-99.0); 
	deltaRlepWjet_shifts.push_back(-99.0);  deltaPhilepWjet_shifts.push_back(-99.0); 
      }

      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc_PtOrdered.size(); ijet++){
	
	ak8_lv.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),theJetAK8Energy_JetSubCalc_PtOrdered.at(ijet));

	deltaR_lepAK8s.push_back(lepton_lv.DeltaR(ak8_lv));
	deltaPhi_lepAK8s.push_back(lepton_lv.DeltaPhi(ak8_lv));
	mass_lepAK8s.push_back((lepton_lv+ak8_lv).M());

	if(lepton_lv.DeltaR(ak8_lv) < minDR_lepAK8) minDR_lepAK8 = lepton_lv.DeltaR(ak8_lv);

	float tau21 = theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.at(ijet)/theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.at(ijet);
	float mass = theJetAK8PrunedMass_JetSubCalc_PtOrdered.at(ijet);

	if(tau21 < 0.6 && mass > 65.0 && mass < 105.0) nWtags += 1;

	//Wtagging with jet mass resolution smearing	
	//Jet Mass Resolution smearing: sqrt(c^2-1)*sigma_MC, where c = 1.12 +/- 0.07, sigma_MC = 7.3+/-0.4 // current values are from "AN2015_196_v7"
	//Smear nominal with sqrt(c^2-1)*sigma_MC = ~3.7, where c = 1.12 and sigma_MC = 7.3
	//+1sigma with sqrt(c^2-1)*sigma_MC = ~4.7, where c = 1.19 and sigma_MC = 7.3
	//-1sigma with sqrt(c^2-1)*sigma_MC = ~2.3, where c = 1.05 and sigma_MC = 7.3
	//
	//Jet Mass Scale: 1.011 +/- 0.016 with 1.6% uncertainty
	//1sigma up  : smeared pruned mass * 1.0270
	//1sigma down: smeared pruned mass * 0.0995
	
	float AK8massScale=1.0; //nominal (scale factor is consistent with one)
	float AK8massScaleUp=0.997; //scale up
	float AK8massScaleDn=0.987; //scale down
	float AK8massSmear=3.7; //nominal
	float AK8massSmearUp=4.7; //1sigma up
	float AK8massSmearDn=2.3; //1sigma down

	float gran = gRandom->Gaus(0, AK8massSmear);
	float granUp = gRandom->Gaus(0, AK8massSmearUp);
	float granDn = gRandom->Gaus(0, AK8massSmearDn);
	float prunedMassSmeared = (mass+gran)*AK8massScale;
	float prunedMassSmearedUp = (mass+granUp)*AK8massScale;
	float prunedMassSmearedDn = (mass+granDn)*AK8massScale;
	float prunedMassSmearedScaleUp = (mass+gran)*AK8massScaleUp;
	float prunedMassSmearedScaleDn = (mass+gran)*AK8massScaleDn;
	float tau0p6SF = 1.0;
	float tau0p6SFup = 1.0;
	float tau0p6SFdn = 1.0;

	if(isMC){
	  theJetAK8PrunedMassJMRSmeared_JetSubCalc.push_back(prunedMassSmeared);
	  theJetAK8PrunedMassJMRSmearedUp_JetSubCalc.push_back(prunedMassSmearedUp);
	  theJetAK8PrunedMassJMRSmearedDn_JetSubCalc.push_back(prunedMassSmearedDn);

	  float minDR = 1000;
	  float matchedPt= -99;
	  bool ismatched = false;
	  TLorentzVector trueW;

	  for(unsigned int iW = 0; iW < WPt_JetSubCalc->size(); iW++){
	    if(WPt_JetSubCalc->at(iW) < 200) continue;

	    trueW.SetPtEtaPhiE(WPt_JetSubCalc->at(iW),WEta_JetSubCalc->at(iW),WPhi_JetSubCalc->at(iW),WEnergy_JetSubCalc->at(iW));
	    if(ak8_lv.DeltaR(trueW) < minDR){
	      minDR = ak8_lv.DeltaR(trueW);
	      matchedPt = WPt_JetSubCalc->at(iW);
	    }
   	  }	 
	  if(minDR < 0.8) ismatched = true;

	  double coin = gRandom->Rndm();

	  // SCALE FACTOR ONLY USED ON MATCHED JETS
	  double tau0p6Eff = 1.0;
	  if(ismatched){	    
	    tau0p6SF = 1.03;
	    tau0p6SFup = 1.16;
	    tau0p6SFdn = 0.90;
	  
	    // Use matched W to find the efficiency -- calculated for TpTp and ttbar, EWK/QCD will almost never pass here (use ttbar eff when they do)
	    if(isSig){
	      int bin = (std::upper_bound(ptRangeTpTp.begin(), ptRangeTpTp.end(), matchedPt)-ptRangeTpTp.begin())-1;
	      tau0p6Eff = SignalEff[bin];
	    }else{
	      int bin = (std::upper_bound(ptRangeTTbar.begin(), ptRangeTTbar.end(), matchedPt)-ptRangeTTbar.begin())-1;
	      tau0p6Eff = TTbarEff[bin];
	    }
	  }

	  // Set the initial tagged/untagged state
	  int tag_JMS_JMR_tau0p6 = (prunedMassSmeared > 65) && (prunedMassSmeared < 105) && (tau21 < 0.6);
	  int tag_JMSup_JMR_tau0p6 = (prunedMassSmeared*AK8massScaleUp > 65) && (prunedMassSmeared*AK8massScaleUp < 105) && (tau21 < 0.6);
	  int tag_JMSdn_JMR_tau0p6 = (prunedMassSmeared*AK8massScaleDn > 65) && (prunedMassSmeared*AK8massScaleDn < 105) && (tau21 < 0.6);
	  int tag_JMS_JMRup_tau0p6 = (prunedMassSmearedUp > 65) && (prunedMassSmearedUp < 105) && (tau21 < 0.6);
	  int tag_JMS_JMRdn_tau0p6 = (prunedMassSmearedDn > 65) && (prunedMassSmearedDn < 105) && (tau21 < 0.6);
	  int tag_JMS_JMR_tau0p6up = (prunedMassSmeared > 65) && (prunedMassSmeared < 105) && (tau21 < 0.6);
	  int tag_JMS_JMR_tau0p6dn = (prunedMassSmeared > 65) && (prunedMassSmeared < 105) && (tau21 < 0.6);
 
	  // IF THE JET IS NOT TRUTH-MATCHED, THESE IFS WILL DO NOTHING, SF == 1
	  // For 0p6 central and up-shift scale factor, only care about > 1 case and "upgrading" tags
	  if(tau0p6SF > 1){
	    float mistagpercent = (1.0 - tau0p6SF) / (1.0 - (tau0p6SF/tau0p6Eff));
	    if(tag_JMS_JMR_tau0p6 == 0 && coin < mistagpercent) tag_JMS_JMR_tau0p6 = 1;	    
	    if(tag_JMSup_JMR_tau0p6 == 0 && coin < mistagpercent) tag_JMSup_JMR_tau0p6 = 1;	    
	    if(tag_JMSdn_JMR_tau0p6 == 0 && coin < mistagpercent) tag_JMSdn_JMR_tau0p6 = 1;	    
	    if(tag_JMS_JMRup_tau0p6 == 0 && coin < mistagpercent) tag_JMS_JMRup_tau0p6 = 1;	    
	    if(tag_JMS_JMRdn_tau0p6 == 0 && coin < mistagpercent) tag_JMS_JMRdn_tau0p6 = 1;	    
	  }
	  if(tau0p6SFup > 1){
	    float mistagpercent = (1.0 - tau0p6SF) / (1.0 - (tau0p6SF/tau0p6Eff));
	    if(tag_JMS_JMR_tau0p6up == 0 && coin < mistagpercent) tag_JMS_JMR_tau0p6up = 1;	    
	  }
	  // For 0p6 down-shifted scale factor, only care about < 1 case and "downgrading" tags
	  if(tau0p6SFdn < 1){
	    if(tag_JMS_JMR_tau0p6dn == 1 && coin > tau0p6SF) tag_JMS_JMR_tau0p6dn = 0;
	  }

	  // Now increase the tag count in the right variable	  
	  NJetsWtagged_0p6 += tag_JMS_JMR_tau0p6;
	  NJetsWtagged_0p6_shifts[0] += tag_JMS_JMRup_tau0p6;
	  NJetsWtagged_0p6_shifts[1] += tag_JMS_JMRdn_tau0p6;
	  NJetsWtagged_0p6_shifts[2] += tag_JMSup_JMR_tau0p6;
	  NJetsWtagged_0p6_shifts[3] += tag_JMSdn_JMR_tau0p6;
	  NJetsWtagged_0p6_shifts[4] += tag_JMS_JMR_tau0p6up;
	  NJetsWtagged_0p6_shifts[5] += tag_JMS_JMR_tau0p6dn;

	  if(tag_JMS_JMR_tau0p6 == 1){
	    WJetTaggedPt.push_back(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    WJetTaggedMass.push_back(prunedMassSmeared);
	    if(NJetsWtagged_0p6 == 1){
	      wjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				    theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),prunedMassSmeared);
	      deltaRtopWjet = wjet1_lv.DeltaR(lvTop);
	      deltaRlepWjet = wjet1_lv.DeltaR(lepton_lv);
	      deltaPhitopWjet = wjet1_lv.DeltaPhi(lvTop);
	      deltaPhilepWjet = wjet1_lv.DeltaPhi(lepton_lv);
	    }
	  }
	  if(tag_JMS_JMRup_tau0p6 == 1){
	    WJetTaggedPtJMRup.push_back(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    WJetTaggedMassJMRup.push_back(prunedMassSmearedUp);
	    if(NJetsWtagged_0p6_shifts[0] == 1){
	      wjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				    theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),prunedMassSmearedUp);
	      deltaRtopWjet_shifts.at(0) = wjet1_lv.DeltaR(lvTop);
	      deltaRlepWjet_shifts.at(0) = wjet1_lv.DeltaR(lepton_lv);
	      deltaPhitopWjet_shifts.at(0) = wjet1_lv.DeltaPhi(lvTop);
	      deltaPhilepWjet_shifts.at(0) = wjet1_lv.DeltaPhi(lepton_lv);
	    }
	  }
	  if(tag_JMS_JMRdn_tau0p6 == 1){
	    WJetTaggedPtJMRdn.push_back(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    WJetTaggedMassJMRdn.push_back(prunedMassSmearedDn);
	    if(NJetsWtagged_0p6_shifts[1] == 1){
	      wjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				    theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),prunedMassSmearedDn);
	      deltaRtopWjet_shifts.at(1) = wjet1_lv.DeltaR(lvTop);
	      deltaRlepWjet_shifts.at(1) = wjet1_lv.DeltaR(lepton_lv);
	      deltaPhitopWjet_shifts.at(1) = wjet1_lv.DeltaPhi(lvTop);
	      deltaPhilepWjet_shifts.at(1) = wjet1_lv.DeltaPhi(lepton_lv);
	    }
	  }
	  if(tag_JMSup_JMR_tau0p6 == 1){
	    WJetTaggedPtJMSup.push_back(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    WJetTaggedMassJMSup.push_back(prunedMassSmearedScaleUp);
	    if(NJetsWtagged_0p6_shifts[2] == 1){
	      wjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				    theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),prunedMassSmearedScaleUp);
	      deltaRtopWjet_shifts.at(2) = wjet1_lv.DeltaR(lvTop);
	      deltaRlepWjet_shifts.at(2) = wjet1_lv.DeltaR(lepton_lv);
	      deltaPhitopWjet_shifts.at(2) = wjet1_lv.DeltaPhi(lvTop);
	      deltaPhilepWjet_shifts.at(2) = wjet1_lv.DeltaPhi(lepton_lv);
	    }
	  }
	  if(tag_JMSdn_JMR_tau0p6 == 1){
	    WJetTaggedPtJMSdn.push_back(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    WJetTaggedMassJMSdn.push_back(prunedMassSmearedScaleDn);
	    if(NJetsWtagged_0p6_shifts[3] == 1){
	      wjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				    theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),prunedMassSmearedScaleDn);
	      deltaRtopWjet_shifts.at(3) = wjet1_lv.DeltaR(lvTop);
	      deltaRlepWjet_shifts.at(3) = wjet1_lv.DeltaR(lepton_lv);
	      deltaPhitopWjet_shifts.at(3) = wjet1_lv.DeltaPhi(lvTop);
	      deltaPhilepWjet_shifts.at(3) = wjet1_lv.DeltaPhi(lepton_lv);
	    }
	  }
	  if(tag_JMS_JMR_tau0p6up == 1){
	    WJetTaggedPtTAUup.push_back(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    WJetTaggedMassTAUup.push_back(prunedMassSmeared);
	    if(NJetsWtagged_0p6_shifts[4] == 1){
	      wjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				    theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),prunedMassSmeared);
	      deltaRtopWjet_shifts.at(4) = wjet1_lv.DeltaR(lvTop);
	      deltaRlepWjet_shifts.at(4) = wjet1_lv.DeltaR(lepton_lv);
	      deltaPhitopWjet_shifts.at(4) = wjet1_lv.DeltaPhi(lvTop);
	      deltaPhilepWjet_shifts.at(4) = wjet1_lv.DeltaPhi(lepton_lv);
	    }
	  }
	  if(tag_JMS_JMR_tau0p6dn == 1){
	    WJetTaggedPtTAUdn.push_back(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    WJetTaggedMassTAUdn.push_back(prunedMassSmeared);
	    if(NJetsWtagged_0p6_shifts[5] == 1){
	      wjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				    theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),prunedMassSmeared);
	      deltaRtopWjet_shifts.at(5) = wjet1_lv.DeltaR(lvTop);
	      deltaRlepWjet_shifts.at(5) = wjet1_lv.DeltaR(lepton_lv);
	      deltaPhitopWjet_shifts.at(5) = wjet1_lv.DeltaPhi(lvTop);
	      deltaPhilepWjet_shifts.at(5) = wjet1_lv.DeltaPhi(lepton_lv);
	    }
	  }
	}else{
	  
	  if(tau21 < 0.6 && mass > 65.0 && mass < 105.0){

	    NJetsWtagged_0p6 += 1;
	    WJetTaggedPt.push_back(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet));
	    WJetTaggedMass.push_back(prunedMassSmeared);
	    if(NJetsWtagged_0p6 == 1){
	      wjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				    theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),theJetAK8Mass_JetSubCalc_PtOrdered.at(ijet));
	      deltaRtopWjet = wjet1_lv.DeltaR(lvTop);
	      deltaRlepWjet = wjet1_lv.DeltaR(lepton_lv);
	      deltaPhitopWjet = wjet1_lv.DeltaPhi(lvTop);
	      deltaPhilepWjet = wjet1_lv.DeltaPhi(lepton_lv);
	    }
	  }
	}
      }

      TLorentzVector leadak8;
      if(theJetAK8Pt_JetSubCalc_PtOrdered.size() < 1) minDR_lepAK8 = -99.0;      
      if(theJetAK8Pt_JetSubCalc_PtOrdered.size() < 2) minDR_leadAK8otherAK8 = -99.0;
      else{
	leadak8.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc_PtOrdered.at(0),theJetAK8Eta_JetSubCalc_PtOrdered.at(0),theJetAK8Phi_JetSubCalc_PtOrdered.at(0),theJetAK8Energy_JetSubCalc_PtOrdered.at(0));
	minDR_leadAK8otherAK8 = 1000;
      
	for(unsigned int ijet = 1; ijet < theJetAK8Pt_JetSubCalc_PtOrdered.size(); ijet++){
	  ak8_lv.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),theJetAK8Energy_JetSubCalc_PtOrdered.at(ijet));
	  
	  float tempdr = leadak8.DeltaR(ak8_lv);
	  if(tempdr < minDR_leadAK8otherAK8){
	    minDR_leadAK8otherAK8 = tempdr;
	  }
	}
      }

      if(WJetTaggedPt.size() > 0) leadWJetPtak8 = WJetTaggedPt.at(0);
      if(WJetTaggedPtJMRup.size() > 0) leadWJetPtak8_shifts.at(0) = WJetTaggedPtJMRup.at(0);
      if(WJetTaggedPtJMRdn.size() > 0) leadWJetPtak8_shifts.at(1) = WJetTaggedPtJMRdn.at(0);
      if(WJetTaggedPtJMSup.size() > 0) leadWJetPtak8_shifts.at(2) = WJetTaggedPtJMSup.at(0);
      if(WJetTaggedPtJMSdn.size() > 0) leadWJetPtak8_shifts.at(3) = WJetTaggedPtJMSdn.at(0);
      if(WJetTaggedPtTAUup.size() > 0) leadWJetPtak8_shifts.at(4) = WJetTaggedPtTAUup.at(0);
      if(WJetTaggedPtTAUdn.size() > 0) leadWJetPtak8_shifts.at(5) = WJetTaggedPtTAUdn.at(0);

      
      //PDF and RENORM weights
      std::vector<double> renorm;
      std::vector<double> pdf;
      renormWeights.clear();
      pdfWeights.clear();
      if(isSig){
	// SEEMS TO APPLY TO ALL B2G MG+PYTHIA SIGNALS. LEADING ORDER 4-FLAVOR PDF
	for(unsigned int i = 0; i < LHEWeightids_singleLepCalc->size(); i++){
	  if(LHEWeightids_singleLepCalc->at(i) > 1 && LHEWeightids_singleLepCalc->at(i) < 10){
	    if(LHEWeightids_singleLepCalc->at(i) == 6 || LHEWeightids_singleLepCalc->at(i) == 8) continue;
	    renorm.push_back(LHEWeights_singleLepCalc->at(i));
	    renormWeights.push_back(LHEWeights_singleLepCalc->at(i));
	  }
	  if(LHEWeightids_singleLepCalc->at(i) > 111 && LHEWeightids_singleLepCalc->at(i) < 212){
	    pdf.push_back(LHEWeights_singleLepCalc->at(i));	    
	    pdfWeights.push_back(LHEWeights_singleLepCalc->at(i));	    
	  }
	}
      }
      else if(isMadgraphBkg){
	// SEEMS TO APPLY TO OTHER MG+PYTHIA BACKGROUNDS. LEADING ORDER 5-FLAVOR PDF
	for(unsigned int i = 0; i < LHEWeightids_singleLepCalc->size(); i++){
	  if(LHEWeightids_singleLepCalc->at(i) > 1 && LHEWeightids_singleLepCalc->at(i) < 10){
	    if(LHEWeightids_singleLepCalc->at(i) == 6 || LHEWeightids_singleLepCalc->at(i) == 8) continue;
	    renorm.push_back(LHEWeights_singleLepCalc->at(i));
	    renormWeights.push_back(LHEWeights_singleLepCalc->at(i));
	  }
	  if(LHEWeightids_singleLepCalc->at(i) > 10 && LHEWeightids_singleLepCalc->at(i) < 111){
	    pdf.push_back(LHEWeights_singleLepCalc->at(i));
	    pdfWeights.push_back(LHEWeights_singleLepCalc->at(i));
	  }
	}
      }
      else{
	// SEEMS TO APPLY TO ALL POWHEG AND MC@NLO BACKGROUNDS. NLO PDFs
	for(unsigned int i = 0; i < LHEWeightids_singleLepCalc->size(); i++){
	  if(LHEWeightids_singleLepCalc->at(i) > 1001 && LHEWeightids_singleLepCalc->at(i) < 1010){
	    if(LHEWeightids_singleLepCalc->at(i) == 1006 || LHEWeightids_singleLepCalc->at(i) == 1008) continue;
	    renorm.push_back(LHEWeights_singleLepCalc->at(i));
	    renormWeights.push_back(LHEWeights_singleLepCalc->at(i));
	  }
	  if(LHEWeightids_singleLepCalc->at(i) > 2000 && LHEWeightids_singleLepCalc->at(i) < 2101){
	    pdf.push_back(LHEWeights_singleLepCalc->at(i));
	    pdfWeights.push_back(LHEWeights_singleLepCalc->at(i));
	  }
	  if(LHEWeightids_singleLepCalc->at(i) == 2101 || LHEWeightids_singleLepCalc->at(i) == 2102){
	    alphaSWeights.push_back(LHEWeights_singleLepCalc->at(i));
	  }
	}
      }

      if(renormWeights.size() == 0){
	for(int irn = 0; irn < 6; irn++){
	  renormWeights.push_back(1.0);
	}
      }
      if(pdfWeights.size() == 0){
	for(int ipdf = 0; ipdf < 100; ipdf++){
	  pdfWeights.push_back(1.0);
	}
      }
           
      isElectron            = (int) isE;
      isMuon                = (int) isM;
      if(isE){
	leptonPt_singleLepCalc = (float) leppt;
	leptonEta_singleLepCalc = (float) lepeta;
	leptonPhi_singleLepCalc = (float) elPhi_singleLepCalc->at(0);
	leptonEnergy_singleLepCalc = (float) elEnergy_singleLepCalc->at(0);
	leptonMiniIso_singleLepCalc = (float) elMiniIso_singleLepCalc->at(0);
	leptonRelIso_singleLepCalc = (float) elRelIso_singleLepCalc->at(0);
	leptonDxy_singleLepCalc = (float) elDxy_singleLepCalc->at(0);
	leptonDz_singleLepCalc = (float) elDZ_singleLepCalc->at(0);
	leptonCharge_singleLepCalc = (int) elCharge_singleLepCalc->at(0);
      }
      if(isM){
	leptonPt_singleLepCalc = (float) leppt;
	leptonEta_singleLepCalc = (float) lepeta;
	leptonPhi_singleLepCalc = (float) muPhi_singleLepCalc->at(0);
	leptonEnergy_singleLepCalc = (float) muEnergy_singleLepCalc->at(0);
	leptonMiniIso_singleLepCalc = (float) muMiniIso_singleLepCalc->at(0);
	leptonRelIso_singleLepCalc = (float) muRelIso_singleLepCalc->at(0);
	leptonDxy_singleLepCalc = (float) muDxy_singleLepCalc->at(0);
	leptonDz_singleLepCalc = (float) muDz_singleLepCalc->at(0);
	leptonCharge_singleLepCalc = (int) muCharge_singleLepCalc->at(0);
      }
      BJetLeadPt_JetSubCalc = (float) leadBJetPt;
      WJetLeadPt_JetSubCalc = (float) leadWJetPtak8;
      AK4HTpMETpLepPt       = (float) st;
      AK4HT                 = (float) ht;
      NJets_JetSubCalc      = (int) njets;
      NJetsAK8_JetSubCalc   = (int) njetsak8;
      NJetsCSV_JetSubCalc   = (int) nbtags;
      NJetsCSVwithSF_JetSubCalc = (int) nbtagWithSF;
      NJetsWtagged          = (int) nWtags;
      NJetsHtagged          = (int) nHtags;
      
      pileupWeight          = (float) puweight;
      pileupWeight72ub      = (float) puweight72ub;
      pileupWeightUp        = (float) puweightup;
      pileupWeightDown      = (float) puweightdown;
      TrigEffAltWeight       = (float) TrigEffAlt;
      TrigEffWeight         = (float) TrigEff;
      isoSF                 = (float) isosf;
      lepIdSF               = (float) lepidsf;
      MCPastTrigger         = (int)   isPastTrigMC;
      MCPastTriggerAlt      = (int)   isPastTrigMCAlt;
      DataPastTrigger       = (int)   isPastTrig;
      DataPastTriggerAlt    = (int)   isPastTrigAlt;
      
      topPt          = (float) lvTop.Pt();
      topMass        = (float) lvTop.M();
      minMleppBjet   = (float) minMlb;
      minMleppJet    = (float) minMljet;
      genTopPt       = (float) gen_tpt;
      genAntiTopPt   = (float) gen_anti_tpt;
      topPtWeight    = (float) weight_toppt;
      topPtWeightPast400    = (float) weightPast400_toppt;
      topPtWeightHighPt    = (float) weightHighPt_toppt;
      deltaRlepJetInMinMljet   = (float) deltaR_lepJetInMinMljet;
      deltaPhilepJetInMinMljet = (float) deltaPhi_lepJetInMinMljet;
      deltaRlepbJetInMinMlb    = (float) deltaR_lepbJetInMinMlb;
      deltaPhilepbJetInMinMlb  = (float) deltaPhi_lepbJetInMinMlb;
      deltaR_lepClosestJet = (float) mindeltar;
      PtRelLepClosestJet   = (float) ptrel_lepclosestjet;
      if(fabs(lvTop.Pt()-gen_tpt)<=fabs(lvTop.Pt()-gen_anti_tpt)){
        topPtGen           = (float) gen_tpt;
      }
      else{
        topPtGen           = (float) gen_anti_tpt;
      }

      outputTree->Fill();
   }
   std::cout<<"Nelectrons             = "<<Nelectrons<<" / "<<nentries<<std::endl;
   std::cout<<"Nmuons                 = "<<Nmuons<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_Trigger(DATA)  = "<<npass_trigger<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_MET            = "<<npass_met<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_nJets          = "<<npass_njets<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_JetLeadPt      = "<<npass_JetLeadPt<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_JetSubLeadPt   = "<<npass_JetSubLeadPt<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_lepPt          = "<<npass_lepPt<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_ElEta          = "<<npass_ElEta<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_ALL            = "<<npass_all<<" / "<<nentries<<std::endl;
   outputTree->Write();

}
