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
   inputTree->SetBranchStatus("elDEtaSCTkAtVtx_singleLepCalc",1);
   inputTree->SetBranchStatus("elDPhiSCTkAtVtx_singleLepCalc",1);
   inputTree->SetBranchStatus("elDR03TkSumPt_singleLepCalc",1);
   inputTree->SetBranchStatus("elSihih_singleLepCalc",1);
   inputTree->SetBranchStatus("elHoE_singleLepCalc",1);
   inputTree->SetBranchStatus("elEcalPFClusterIso_singleLepCalc",1);
   inputTree->SetBranchStatus("elHcalPFClusterIso_singleLepCalc",1);
   
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
   inputTree->SetBranchStatus("corr_met_singleLepCalc",1);
   inputTree->SetBranchStatus("corr_met_phi_singleLepCalc",1);

   // genParticles
   inputTree->SetBranchStatus("genPt_singleLepCalc",1);
   inputTree->SetBranchStatus("genEta_singleLepCalc",1);
   inputTree->SetBranchStatus("genPhi_singleLepCalc",1);
   inputTree->SetBranchStatus("genEnergy_singleLepCalc",1);
   inputTree->SetBranchStatus("genStatus_singleLepCalc",1);
   inputTree->SetBranchStatus("genID_singleLepCalc",1);
   inputTree->SetBranchStatus("genMotherID_singleLepCalc",1);
   inputTree->SetBranchStatus("genJetPt_singleLepCalc",1);
   inputTree->SetBranchStatus("genJetEta_singleLepCalc",1);
   inputTree->SetBranchStatus("genJetPhi_singleLepCalc",1);
   inputTree->SetBranchStatus("genJetEnergy_singleLepCalc",1);

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

   //jets
   inputTree->SetBranchStatus("theJetHFlav_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetPFlav_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetPt_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetEta_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetPhi_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetEnergy_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetCSV_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_bSFup_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_bSFdn_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_lSFup_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_lSFdn_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Pt_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Eta_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Phi_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Mass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Energy_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau1_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau2_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau3_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8PrunedMass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDropMass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8PrunedTau21Tag_JetSubCalc",1);

   inputTree->SetBranchStatus("theJetAK8SDSubjetNCSVMSF_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetNCSVM_bSFdn_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetNCSVM_bSFup_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetNCSVM_lSFdn_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetNCSVM_lSFup_JetSubCalc",1);
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
   inputTree->SetBranchStatus("LHEweightids_singleLepCalc",1);
   inputTree->SetBranchStatus("LHEweights_singleLepCalc",1);
   
   // OUTPUT FILE
   outputFile->cd();
   TTree *outputTree = new TTree("ljmet","ljmet");

   outputTree->Branch("event_CommonCalc",&event_CommonCalc,"event_CommonCalc/I");
   outputTree->Branch("run_CommonCalc",&run_CommonCalc,"run_CommonCalc/I");
   outputTree->Branch("lumi_CommonCalc",&lumi_CommonCalc,"lumi_CommonCalc/I");
   outputTree->Branch("nPV_singleLepCalc",&nPV_singleLepCalc,"nPV_singleLepCalc/I");
   outputTree->Branch("nTrueInteractions_singleLepCalc",&nTrueInteractions_singleLepCalc,"nTrueInteractions_singleLepCalc/I");
   outputTree->Branch("isElectron",&isElectron,"isElectron/I");
   outputTree->Branch("isMuon",&isMuon,"isMuon/I");
   outputTree->Branch("MCPastTrigger",&MCPastTrigger,"MCPastTrigger/I");
   outputTree->Branch("MCPastTriggerAlt",&MCPastTriggerAlt,"MCPastTriggerAlt/I");
   outputTree->Branch("DataPastTrigger",&DataPastTrigger,"DataPastTrigger/I");
   outputTree->Branch("DataPastTriggerAlt",&DataPastTriggerAlt,"DataPastTriggerAlt/I");
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
   outputTree->Branch("NLeptonDecays_TpTpCalc",&NLeptonDecays_TpTpCalc,"NLeptonDecays_TpTpCalc/I");
   outputTree->Branch("MCWeight_singleLepCalc",&MCWeight_singleLepCalc,"MCWeight_singleLepCalc/D");
   outputTree->Branch("renormWeights",&renormWeights);
   outputTree->Branch("pdfWeights",&pdfWeights);
   outputTree->Branch("JetSF_pTNbwflat",&JetSF_pTNbwflat,"JetSF_pTNbwflat/F");
   outputTree->Branch("JetSFup_pTNbwflat",&JetSFup_pTNbwflat,"JetSFup_pTNbwflat/F");
   outputTree->Branch("JetSFdn_pTNbwflat",&JetSFdn_pTNbwflat,"JetSFdn_pTNbwflat/F");
   outputTree->Branch("JetSFupwide_pTNbwflat",&JetSFupwide_pTNbwflat,"JetSFupwide_pTNbwflat/F");
   outputTree->Branch("JetSFdnwide_pTNbwflat",&JetSFdnwide_pTNbwflat,"JetSFdnwide_pTNbwflat/F");
   outputTree->Branch("pileupWeight",&pileupWeight,"pileupWeight/F");
   outputTree->Branch("pileupWeightUp",&pileupWeightUp,"pileupWeightUp/F");
   outputTree->Branch("pileupWeightDown",&pileupWeightDown,"pileupWeightDown/F");
   outputTree->Branch("TrigEffAltWeight",&TrigEffAltWeight,"TrigEffAltWeight/F");
   outputTree->Branch("TrigEffWeight",&TrigEffWeight,"TrigEffWeight/F");
   outputTree->Branch("isoSF",&isoSF,"isoSF/F");
   outputTree->Branch("lepIdSF",&lepIdSF,"lepIdSF/F");
   outputTree->Branch("EGammaRecoSF",&EGammaRecoSF,"EGammaRecoSF/F");

   outputTree->Branch("ttbarMass_TTbarMassCalc",&ttbarMass_TTbarMassCalc,"ttbarMass_TTbarMassCalc/D");
   outputTree->Branch("corr_met_singleLepCalc",&corr_met_singleLepCalc,"corr_met_singleLepCalc/D");
   outputTree->Branch("corr_met_phi_singleLepCalc",&corr_met_phi_singleLepCalc,"corr_met_phi_singleLepCalc/D");
   outputTree->Branch("leptonPt_singleLepCalc",&leptonPt_singleLepCalc,"leptonPt_singleLepCalc/F");
   outputTree->Branch("leptonEta_singleLepCalc",&leptonEta_singleLepCalc,"leptonEta_singleLepCalc/F");
   outputTree->Branch("leptonPhi_singleLepCalc",&leptonPhi_singleLepCalc,"leptonPhi_singleLepCalc/F");
   outputTree->Branch("leptonEnergy_singleLepCalc",&leptonEnergy_singleLepCalc,"leptonEnergy_singleLepCalc/F");
   outputTree->Branch("leptonMiniIso_singleLepCalc",&leptonMiniIso_singleLepCalc,"leptonMiniIso_singleLepCalc/F");
   outputTree->Branch("leptonRelIso_singleLepCalc",&leptonRelIso_singleLepCalc,"leptonRelIso_singleLepCalc/F");
   outputTree->Branch("leptonDxy_singleLepCalc",&leptonDxy_singleLepCalc,"leptonDxy_singleLepCalc/F");
   outputTree->Branch("leptonDz_singleLepCalc",&leptonDz_singleLepCalc,"leptonDz_singleLepCalc/F");
   outputTree->Branch("leptonCharge_singleLepCalc",&leptonCharge_singleLepCalc,"leptonCharge_singleLepCalc/I");
   outputTree->Branch("elTrigPresel_singleLepCalc",&elTrigPresel_singleLepCalc,"elTrigPresel_singleLepCalc/I");
   outputTree->Branch("theJetPt_JetSubCalc_PtOrdered",&theJetPt_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetEta_JetSubCalc_PtOrdered",&theJetEta_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetPhi_JetSubCalc_PtOrdered",&theJetPhi_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetEnergy_JetSubCalc_PtOrdered",&theJetEnergy_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetBTag_JetSubCalc_PtOrdered",&theJetBTag_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetBTag_bSFup_JetSubCalc_PtOrdered",&theJetBTag_bSFup_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetBTag_bSFdn_JetSubCalc_PtOrdered",&theJetBTag_bSFdn_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetBTag_lSFup_JetSubCalc_PtOrdered",&theJetBTag_lSFup_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetBTag_lSFdn_JetSubCalc_PtOrdered",&theJetBTag_lSFdn_JetSubCalc_PtOrdered);
   outputTree->Branch("HadronicVHtID_JetSubCalc",&HadronicVHtID_JetSubCalc);
   outputTree->Branch("HadronicVHtPt_JetSubCalc",&HadronicVHtPt_JetSubCalc);
   outputTree->Branch("HadronicVHtEta_JetSubCalc",&HadronicVHtEta_JetSubCalc);
   outputTree->Branch("HadronicVHtPhi_JetSubCalc",&HadronicVHtPhi_JetSubCalc);
   outputTree->Branch("HadronicVHtEnergy_JetSubCalc",&HadronicVHtEnergy_JetSubCalc);
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
   outputTree->Branch("theJetAK8Wmatch_JetSubCalc_PtOrdered",&theJetAK8Wmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Tmatch_JetSubCalc_PtOrdered",&theJetAK8Tmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Zmatch_JetSubCalc_PtOrdered",&theJetAK8Zmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Hmatch_JetSubCalc_PtOrdered",&theJetAK8Hmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8MatchedPt_JetSubCalc_PtOrdered",&theJetAK8MatchedPt_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8PrunedMassJMRSmeared_JetSubCalc",&theJetAK8PrunedMassJMRSmeared_JetSubCalc);
   outputTree->Branch("theJetAK8PrunedMassJMRSmearedUp_JetSubCalc",&theJetAK8PrunedMassJMRSmearedUp_JetSubCalc);
   outputTree->Branch("theJetAK8PrunedMassJMRSmearedDn_JetSubCalc",&theJetAK8PrunedMassJMRSmearedDn_JetSubCalc);
   outputTree->Branch("genJetPt_singleLepCalc",&genJetPt_singleLepCalc);
   outputTree->Branch("genJetEta_singleLepCalc",&genJetEta_singleLepCalc);
   outputTree->Branch("genJetPhi_singleLepCalc",&genJetPhi_singleLepCalc);
   outputTree->Branch("genJetEnergy_singleLepCalc",&genJetEnergy_singleLepCalc);
   outputTree->Branch("BJetLeadPt",&BJetLeadPt,"BJetLeadPt/F");
   outputTree->Branch("BJetLeadPt_shifts",&BJetLeadPt_shifts);
   outputTree->Branch("WJetLeadPt",&WJetLeadPt,"WJetLeadPt/F");
   outputTree->Branch("WJetLeadPt_shifts",&WJetLeadPt_shifts);
   outputTree->Branch("AK4HTpMETpLepPt",&AK4HTpMETpLepPt,"AK4HTpMETpLepPt/F");
   outputTree->Branch("AK4HT",&AK4HT,"AK4HT/F");
   outputTree->Branch("NJets_JetSubCalc",&NJets_JetSubCalc,"NJets_JetSubCalc/I");
   outputTree->Branch("NJetsAK8_JetSubCalc",&NJetsAK8_JetSubCalc,"NJetsAK8_JetSubCalc/I");
   outputTree->Branch("NJetsCSVwithSF_JetSubCalc",&NJetsCSVwithSF_JetSubCalc,"NJetsCSVwithSF_JetSubCalc/I");
   outputTree->Branch("NJetsCSVwithSF_JetSubCalc_shifts",&NJetsCSVwithSF_JetSubCalc_shifts);
   outputTree->Branch("NJetsHtagged",&NJetsHtagged,"NJetsHtagged/I");
   outputTree->Branch("NJetsHtagged_shifts",&NJetsHtagged_shifts);
   outputTree->Branch("topPt",&topPt,"topPt/F");
   outputTree->Branch("topPtGen",&topPtGen,"topPtGen/F");
   outputTree->Branch("topMass",&topMass,"topMass/F");
   outputTree->Branch("minMleppBjet",&minMleppBjet,"minMleppBjet/F");
   outputTree->Branch("minMleppBjet_shifts",&minMleppBjet_shifts);
   outputTree->Branch("minMleppJet",&minMleppJet,"mixnMleppJet/F");
   outputTree->Branch("genTopPt",&genTopPt,"genTopPt/F");
   outputTree->Branch("genAntiTopPt",&genAntiTopPt,"genAntiTopPt/F");
   outputTree->Branch("topPtWeight",&topPtWeight,"topPtWeight/F");
   outputTree->Branch("topPtWeightPast400",&topPtWeightPast400,"topPtWeightPast400/F");
   outputTree->Branch("topPtWeightHighPt",&topPtWeightHighPt,"topPtWeightHighPt/F");
   outputTree->Branch("deltaRlepJetInMinMljet",&deltaRlepJetInMinMljet,"deltaRlepJetInMinMljet/F");
   outputTree->Branch("deltaRlepbJetInMinMlb",&deltaRlepbJetInMinMlb,"deltaRlepbJetInMinMlb/F");
   outputTree->Branch("deltaRlepbJetInMinMlb_shifts",&deltaRlepbJetInMinMlb_shifts);
   outputTree->Branch("deltaPhilepJetInMinMljet",&deltaPhilepJetInMinMljet,"deltaPhilepJetInMinMljet/F");
   outputTree->Branch("deltaPhilepbJetInMinMlb",&deltaPhilepbJetInMinMlb,"deltaPhilepbJetInMinMlb/F");
   outputTree->Branch("deltaPhilepbJetInMinMlb_shifts",&deltaPhilepbJetInMinMlb_shifts);
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
   outputTree->Branch("NJetsWtagged_0p6",&NJetsWtagged_0p6,"NJetsWtagged_0p6/I");
   outputTree->Branch("NJetsWtagged_0p6_shifts",&NJetsWtagged_0p6_shifts);
   outputTree->Branch("minDR_leadAK8otherAK8",&minDR_leadAK8otherAK8,"minDR_leadAK8otherAK8/F");
   outputTree->Branch("minDR_lepAK8",&minDR_lepAK8,"minDR_lepAK8/F");
   outputTree->Branch("minDR_lepJet",&minDR_lepJet,"minDR_lepJet/F");
   outputTree->Branch("ptRel_lepJet",&ptRel_lepJet,"ptRel_lepJet/F");
   outputTree->Branch("MT_lepMet",&MT_lepMet,"MT_lepMet/F");
   outputTree->Branch("deltaR_lepJets",&deltaR_lepJets);
   outputTree->Branch("deltaR_lepBJets",&deltaR_lepBJets);
   outputTree->Branch("deltaR_lepBJets_bSFup",&deltaR_lepBJets_bSFup);
   outputTree->Branch("deltaR_lepBJets_bSFdn",&deltaR_lepBJets_bSFdn);
   outputTree->Branch("deltaR_lepBJets_lSFup",&deltaR_lepBJets_lSFup);
   outputTree->Branch("deltaR_lepBJets_lSFdn",&deltaR_lepBJets_lSFdn);
   outputTree->Branch("deltaR_lepAK8s",&deltaR_lepAK8s);
   outputTree->Branch("deltaPhi_lepJets",&deltaPhi_lepJets);
   outputTree->Branch("deltaPhi_lepBJets",&deltaPhi_lepBJets);
   outputTree->Branch("deltaPhi_lepBJets_bSFup",&deltaPhi_lepBJets_bSFup);
   outputTree->Branch("deltaPhi_lepBJets_bSFdn",&deltaPhi_lepBJets_bSFdn);
   outputTree->Branch("deltaPhi_lepBJets_lSFup",&deltaPhi_lepBJets_lSFup);
   outputTree->Branch("deltaPhi_lepBJets_lSFdn",&deltaPhi_lepBJets_lSFdn);
   outputTree->Branch("deltaPhi_lepAK8s",&deltaPhi_lepAK8s);
   outputTree->Branch("mass_lepJets",&mass_lepJets);
   outputTree->Branch("mass_lepBJets",&mass_lepBJets);
   outputTree->Branch("mass_lepBJets_bSFup",&mass_lepBJets_bSFup);
   outputTree->Branch("mass_lepBJets_bSFdn",&mass_lepBJets_bSFdn);
   outputTree->Branch("mass_lepBJets_lSFup",&mass_lepBJets_lSFup);
   outputTree->Branch("mass_lepBJets_lSFdn",&mass_lepBJets_lSFdn);
   outputTree->Branch("mass_lepAK8s",&mass_lepAK8s);

   TLorentzVector jet_lv;
   TLorentzVector bjet_lv;
   TLorentzVector wjet1_lv;
   TLorentzVector lepton_lv;
   TLorentzVector ak8_lv;
   
   // basic cuts
   float metCut=30;
   int   njetsCut=2;
   float JetLeadPtCut=50;
   float JetSubLeadPtCut=30;
   float lepPtCut=30;
   float elEtaCut=2.1;
   float jetEtaCut=2.4;
   float ak8EtaCut=2.4;
   float jetPtCut=30;

   // W tagging efficiencies. Assumes each signal mass uses the same pT bins but has unique values.
   std::vector<float> ptRangeTpTp, ptRangeTTbar;
   float ptminTTbar[17] = {200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700, 750, 800, 900, 1000, 1100, 1200};
   for (int i=0;i<17;++i) ptRangeTTbar.push_back(ptminTTbar[i]);
   float ptminTpTp[20] = {200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700, 750, 800, 900, 1000, 1100, 1200, 1400, 1600, 1800};
   for (int i=0;i<20;++i) ptRangeTpTp.push_back(ptminTpTp[i]);

   float SignalEff[12][20] = {
     {0.564508, 0.608000, 0.606345, 0.610230, 0.611723, 0.619561, 0.625576, 0.622267, 0.616639, 0.613650, 0.613298, 0.607818, 0.598630, 0.580504, 0.551724,0.557235,0.573113,0.483051,0.543478,0.384615},
     {0.548629, 0.583188, 0.586383, 0.588656, 0.592233, 0.596651, 0.602861, 0.603671, 0.607767, 0.613201, 0.614011, 0.615429, 0.608499, 0.598631, 0.569672,0.563758,0.583679,0.543210,0.483333,0.450000},
     {0.534358, 0.569013, 0.564901, 0.569156, 0.570370, 0.578915, 0.578805, 0.584476, 0.588793, 0.587046, 0.588409, 0.592822, 0.593446, 0.593232, 0.582446,0.619464,0.563874,0.525424,0.500000,0.450980},
     {0.538454, 0.557137, 0.545319, 0.548106, 0.555391, 0.562675, 0.571853, 0.567900, 0.575301, 0.575040, 0.584643, 0.589661, 0.582756, 0.574006, 0.571275,0.582245,0.565997,0.532086,0.588000,0.517647},
     {0.525286, 0.551142, 0.534871, 0.535766, 0.543462, 0.550923, 0.554155, 0.563145, 0.567262, 0.568506, 0.569613, 0.572914, 0.574414, 0.571416, 0.575626,0.577349,0.566807,0.567276,0.593052,0.523438},
     {0.535650, 0.551255, 0.527912, 0.523938, 0.529138, 0.539762, 0.544520, 0.549281, 0.549178, 0.554746, 0.550871, 0.559603, 0.564062, 0.560952, 0.564291,0.557285,0.555885,0.554862,0.546512,0.542955},
     {0.538705, 0.549720, 0.525772, 0.517480, 0.516984, 0.526490, 0.534243, 0.539233, 0.542263, 0.537705, 0.547191, 0.550480, 0.553255, 0.552288, 0.551672,0.565510,0.551236,0.559540,0.551724,0.561856},
     {0.542911, 0.551923, 0.527378, 0.511120, 0.511213, 0.519235, 0.521617, 0.531310, 0.536900, 0.537253, 0.539322, 0.542000, 0.538708, 0.546960, 0.547060,0.552621,0.540629,0.541027,0.542459,0.503937},
     {0.535188, 0.562270, 0.533453, 0.506059, 0.503329, 0.509019, 0.511890, 0.519123, 0.527211, 0.526664, 0.531581, 0.532783, 0.537525, 0.541424, 0.534916,0.542254,0.542909,0.543891,0.532174,0.540279},
     {0.547503, 0.567619, 0.533486, 0.513874, 0.503044, 0.502185, 0.505648, 0.517570, 0.518406, 0.520316, 0.525227, 0.520015, 0.527185, 0.530408, 0.530671,0.526384,0.533087,0.529443,0.534278,0.539708},
     {0.550201, 0.574215, 0.539318, 0.519348, 0.508372, 0.503091, 0.499538, 0.507907, 0.511284, 0.514325, 0.514122, 0.521448, 0.520427, 0.520246, 0.520341,0.526883,0.520512,0.517572,0.527374,0.539618},
     {0.554137, 0.581898, 0.552245, 0.519768, 0.501204, 0.494958, 0.499119, 0.501657, 0.503040, 0.504813, 0.511540, 0.507806, 0.515420, 0.519994, 0.511150,0.514094,0.516915,0.521633,0.532456,0.520919},
   };
   float TTbarEff[17] = {0.685039,0.739539,0.706915,0.675907,0.658715,0.651691,0.644650,0.634328,0.626901,0.621236,0.625850,0.605793,0.590250,0.563380,0.504950,0.457627,0.531250};
   float STEff[17] = {0.718269,0.796822,0.783475,0.762890,0.741929,0.722222,0.716766,0.702391,0.724490,0.709125,0.671554,0.752033,0.705202,0.691011,0.677966,0.661972,0.500000};
   float WVEff[17] = {0.700646,0.775087,0.749880,0.717758,0.684090,0.656286,0.650381,0.613069,0.601344,0.602273,0.562660,0.581481,0.531977,0.604396,0.602151,0.546875,0.546875};

   // Pileup distributions
   double pileup_71300mb[40] = {8.446e-04, 7.527e-03, 1.129e-02, 2.534e-02, 4.204e-02, 3.838e-02, 4.979e-02, 2.754e-01, 5.848e-01, 6.689e-01, 6.987e-01, 8.628e-01, 1.196e+00, 1.611e+00, 1.993e+00, 2.038e+00, 1.900e+00, 1.921e+00, 1.698e+00, 1.597e+00, 1.204e+00, 9.219e-01, 7.490e-01, 6.001e-01, 4.247e-01, 3.230e-01, 1.955e-01, 1.287e-01, 6.994e-02, 4.072e-02, 2.233e-02, 1.219e-02, 8.711e-03, 5.919e-03, 5.998e-03, 9.109e-03, 2.150e-02, 4.643e-02, 0.000e+00, 0.000e+00};
   double pileup_67735mb[40] = {1.242e-03, 8.530e-03, 1.420e-02, 2.959e-02, 4.947e-02, 4.348e-02, 9.419e-02, 5.241e-01, 7.498e-01, 7.964e-01, 8.872e-01, 1.189e+00, 1.697e+00, 2.193e+00, 2.527e+00, 2.403e+00, 2.085e+00, 1.949e+00, 1.596e+00, 1.399e+00, 9.835e-01, 6.957e-01, 5.143e-01, 3.690e-01, 2.312e-01, 1.549e-01, 8.270e-02, 4.824e-02, 2.335e-02, 1.219e-02, 6.048e-03, 3.053e-03, 2.141e-03, 1.622e-03, 2.177e-03, 4.772e-03, 1.514e-02, 3.869e-02, 0.000e+00, 0.000e+00};
   double pileup_74865mb[40] = {5.248e-04, 6.697e-03, 9.126e-03, 2.162e-02, 3.659e-02, 3.318e-02, 3.588e-02, 1.305e-01, 4.046e-01, 5.691e-01, 5.765e-01, 6.640e-01, 8.634e-01, 1.163e+00, 1.513e+00, 1.654e+00, 1.646e+00, 1.777e+00, 1.687e+00, 1.700e+00, 1.365e+00, 1.114e+00, 9.713e-01, 8.461e-01, 6.602e-01, 5.597e-01, 3.797e-01, 2.804e-01, 1.703e-01, 1.103e-01, 6.695e-02, 4.021e-02, 3.127e-02, 2.247e-02, 2.246e-02, 2.955e-02, 5.230e-02, 8.101e-02, 0.000e+00, 0.000e+00};

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

   cout << "RUN CONFIG: isMC = " << isMC << endl;
   cout << "isSig = " << isSig << ", SigMass = " << SigMass << endl;
   cout << "For W's: isTT = " << isTT << ", isST = " << isST << endl;
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

      // Filter input file by mass or decay
      //if(isTTincMtt0to700 && ttbarMass_TTbarMassCalc >= 700.) continue;
      //if(isTTincMtt700to1000 && (ttbarMass_TTbarMassCalc < 700. || ttbarMass_TTbarMassCalc >= 1000.)) continue;
      //if(isTTincMtt1000toInf && ttbarMass_TTbarMassCalc < 1000.) continue;
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
     	     
      int isE = 0;
      int isM = 0;
      if(elPt_singleLepCalc->size()==0 && muPt_singleLepCalc->size()==0){std::cout << "got no leptons, something wrong" << std::endl; continue;}
      if(elPt_singleLepCalc->size()>0 && muPt_singleLepCalc->size()>0) std::cout << "got el and mu, something wrong" << std::endl;
      if(elPt_singleLepCalc->size()>1 && muPt_singleLepCalc->size()>1) std::cout << "got more than one el or mu, something wrong" << std::endl;
      if(elPt_singleLepCalc->size()>0 && muPt_singleLepCalc->size()==0) {isE = 1; isM = 0;}
      if(elPt_singleLepCalc->size()==0 && muPt_singleLepCalc->size()>0) {isE = 0; isM = 1;}
      if(isE==0 && isM==0){std::cout << "got no leptons, something wrong" << std::endl; continue;}

      double puweight = pileup_71300mb[nTrueInteractions_singleLepCalc];
      double puweightup = pileup_67735mb[nTrueInteractions_singleLepCalc];
      double puweightdown = pileup_74865mb[nTrueInteractions_singleLepCalc];

      int   isPastTrig = 0;
      int   isPastTrigAlt = 0;
      int   isPastTrigMC = 0;
      int   isPastTrigMCAlt = 0;
      float TrigEffAlt = 1.0;
      float TrigEff = 1.0;
      float isosf = 1.0;
      float lepidsf = 1.0;
      float egammasf = 1.0;      

      double leppt, lepeta;
      if(isE){leppt = elPt_singleLepCalc->at(0); lepeta = elEta_singleLepCalc->at(0);}
      if(isM){leppt = muPt_singleLepCalc->at(0); lepeta = muEta_singleLepCalc->at(0);}

      if(isMC){ //MC triggers check
      	if(isE){
	  isPastTrigMC = 1;
	  isPastTrigMCAlt = 1;

          //EGamma Scale Factors from http://fcouderc.web.cern.ch/fcouderc/EGamma/scaleFactors/moriond2016_76X/reco/eleRECO.txt.egamma_egammaPlots.pdf
	  if(lepeta > -2.5 && lepeta < -2.0){
            if(leppt > 10. && leppt < 20.) egammasf = 1.006;
            else if(leppt < 30.) egammasf= 1.027;
            else if(leppt < 40.) egammasf= 1.024;
            else if(leppt < 50.) egammasf= 1.023;
            else egammasf= 1.019;
          }
          else if(lepeta < -1.566){
            if(leppt > 10. && leppt < 20.) egammasf= 1.024;
            else if(leppt < 30.) egammasf= 0.999;
            else if(leppt < 40.) egammasf= 0.999;
            else if(leppt < 50.) egammasf= 1.000;
            else egammasf= 0.990;
          }
          else if(lepeta < -1.444){
            if(leppt > 10. && leppt < 20.) egammasf= 1.065;
            else if(leppt < 30.) egammasf= 1.000;
            else if(leppt < 40.) egammasf= 0.939;
            else if(leppt < 50.) egammasf= 0.970;
            else egammasf= 0.919;
          }
          else if(lepeta < -0.8){
            if(leppt > 10. && leppt < 20.) egammasf= 1.028;
            else if(leppt < 30.) egammasf= 1.000;
            else if(leppt < 40.) egammasf= 0.994;
            else if(leppt < 50.) egammasf= 0.995;
            else egammasf= 0.989;
          }
          else if(lepeta < 0.0 ){
            if(leppt > 10. && leppt < 20.) egammasf= 0.924;
            else if(leppt < 30.) egammasf= 0.988;
            else if(leppt < 40.) egammasf= 0.986;
            else if(leppt < 50.) egammasf= 0.991;
            else egammasf= 0.985;
          }
          else if(lepeta < 0.8){
            if(leppt > 10. && leppt < 20.) egammasf= 0.924;
            else if(leppt < 30.) egammasf= 0.992;
            else if(leppt < 40.) egammasf= 0.989;
            else if(leppt < 50.) egammasf= 0.993;
            else egammasf= 0.990;
          }
          else if(lepeta < 1.444){
            if(leppt > 10. && leppt < 20.) egammasf= 1.028;
            else if(leppt < 30.) egammasf= 0.990;
            else if(leppt < 40.) egammasf= 0.991;
            else if(leppt < 50.) egammasf= 0.997;
            else egammasf= 0.987;
          }
          else if(lepeta < 1.566){
            if(leppt > 10. && leppt < 20.) egammasf= 1.065;
            else if(leppt < 30.) egammasf= 0.929;
            else if(leppt < 40.) egammasf= 0.954;
            else if(leppt < 50.) egammasf= 0.952;
            else egammasf= 0.944;
          }
          else if(lepeta < 2.0){
            if(leppt > 10. && leppt < 20.) egammasf= 1.024;
            else if(leppt < 30.) egammasf= 0.993;
            else if(leppt < 40.) egammasf= 0.987;
            else if(leppt < 50.) egammasf= 0.995;
            else egammasf= 0.986;
          }
          else if(lepeta < 2.5){
            if(leppt > 10. && leppt < 20.) egammasf= 1.006;
            else if(leppt < 30.) egammasf= 0.977;
            else if(leppt < 40.) egammasf= 0.988;
            else if(leppt < 50.) egammasf= 0.989;
            else egammasf= 0.984;
          }
          else egammasf= 1.0;


	  // Ele27_eta2p1 -- 76X DATA EFFICIENCIES
	  if(leppt < 45){
            if(fabs(lepeta) < 0.8) TrigEffAltWeight = 0.843; // 
            else if(fabs(lepeta) < 1.442) TrigEffAltWeight = 0.829;
            else if(fabs(lepeta) < 1.566) TrigEffAltWeight = 0.750;
            else TrigEffAltWeight = 0.815;
          }else if(leppt < 50){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.866; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 0.856;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.777;
	    else TrigEffWeight = 0.829;
	  }else if(leppt < 60){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.881; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 0.871;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.792;
	    else TrigEffWeight = 0.834;
	  }else if(leppt < 70){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.891; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 0.885;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.789;
	    else TrigEffWeight = 0.838;
	  }else if(leppt < 90){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.901; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 0.893;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.809;
	    else TrigEffWeight = 0.846;
	  }else if(leppt < 130){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.919; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 0.910;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.820;
	    else TrigEffWeight = 0.845;
	  }else{
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.922; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 0.925;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.837;
	    else TrigEffWeight = 0.844;
	  }
	  	
	  //miniIso < 0.1 scale factors from SUSYLepSF TWiki for 80X/ICHEP
	  if(fabs(lepeta) < 0.8){
	    if(leppt < 40) isosf = 0.979; // +/-0.022
	    else if(leppt < 50) isosf = 0.979; // +/-0.011
	    else isosf = 0.985; // +/-0.000
	  }
	  else if(fabs(lepeta) < 1.442){
	    if(leppt < 40) isosf = 0.990; // +/-0.006
	    else if(leppt < 50) isosf = 0.991; // +/-0.007
	    else isosf = 0.998; // +/-0.014
	  }
	  else if(fabs(lepeta) < 1.566){
	    if(leppt < 40) isosf = 1.023; // +/-0.006
	    else if(leppt < 50) isosf = 1.011; // +/-0.007
	    else isosf = 1.020; // +/-0.014
	  }
	  else if(fabs(lepeta) < 2.0){
	    if(leppt < 40) isosf = 1.012; // +/-0.006
	    else if(leppt < 50) isosf = 1.006; // +/-0.007
	    else isosf = 1.002; // +/-0.014
	  }
	  else {
	    if(leppt < 40) isosf = 1.042; // +/-0.001
	    else if(leppt < 50) isosf = 1.033; // +/-0.002
	    else isosf = 1.021; // +/-0.002
	  }
	  
	  //MVA-based ID scale factors (non-triggering) from TWiki CMS/EgammaIDRecipesRun2
	  if(run_CommonCalc < 273726){
	    if(lepeta < -2.0){
	      if(leppt < 40.) lepidsf= 0.840;
	      else if(leppt < 50.) lepidsf= 0.856; 
	      else lepidsf= 0.886;
	    } 
	    else if(lepeta < -1.566){
	      if(leppt < 40.) lepidsf= 0.813;
	      else if(leppt < 50.) lepidsf= 0.851; 
	      else lepidsf= 0.867;
	    } 
	    else if(lepeta < -1.442){
	      if(leppt < 40.) lepidsf= 0.826;
	      else if(leppt < 50.) lepidsf= 0.861; 
	      else lepidsf= 0.902;
	    } 
	    else if(lepeta < -0.8){
	      if(leppt < 40.) lepidsf= 0.958;
	      else if(leppt < 50.) lepidsf= 0.949; 
	      else lepidsf= 0.952;
	    } 
	    else if(lepeta < 0.0){
	      if(leppt < 40.) lepidsf= 0.955;
	      else if(leppt < 50.) lepidsf= 0.964; 
	      else lepidsf= 0.984;
	    } 
	    else if(lepeta < 0.8){
	      if(leppt < 40.) lepidsf= 1.021;
	      else if(leppt < 50.) lepidsf= 0.999; 
	      else lepidsf= 1.014;
	    } 
	    else if(lepeta < 1.442){
	      if(leppt < 40.) lepidsf= 0.946;
	      else if(leppt < 50.) lepidsf= 0.960; 
	      else lepidsf= 0.976;
	    } 
	    else if(lepeta < 1.566){
	      if(leppt < 40.) lepidsf= 0.871;
	      else if(leppt < 50.) lepidsf= 0.870; 
	      else lepidsf= 0.875;
	    } 
	    else if(lepeta < 2.0){
	      if(leppt < 40.) lepidsf= 0.823;
	      else if(leppt < 50.) lepidsf= 0.856; 
	      else lepidsf= 0.862;
	    } 
	    else{
	      if(leppt < 40.) lepidsf= 0.858;
	      else if(leppt < 50.) lepidsf= 0.865; 
	      else lepidsf= 0.892;
	    } 
	  }else{ // Run >= 275726
	    if(lepeta < -2.0){
	      if(leppt < 40.) lepidsf= 0.906;
	      else if(leppt < 50.) lepidsf= 0.912; 
	      else lepidsf= 0.909;
	    } 
	    else if(lepeta < -1.566){
	      if(leppt < 40.) lepidsf= 0.904;
	      else if(leppt < 50.) lepidsf= 0.922; 
	      else lepidsf= 0.934;
	    } 
	    else if(lepeta < -1.442){
	      if(leppt < 40.) lepidsf= 0.909;
	      else if(leppt < 50.) lepidsf= 0.938; 
	      else lepidsf= 0.954;
	    } 
	    else if(lepeta < -0.8){
	      if(leppt < 40.) lepidsf= 0.930;
	      else if(leppt < 50.) lepidsf= 0.936; 
	      else lepidsf= 0.938;
	    } 
	    else if(lepeta < 0.0){
	      if(leppt < 40.) lepidsf= 0.920;
	      else if(leppt < 50.) lepidsf= 0.928; 
	      else lepidsf= 0.938;
	    } 
	    else if(lepeta < 0.8){
	      if(leppt < 40.) lepidsf= 0.967;
	      else if(leppt < 50.) lepidsf= 0.965; 
	      else lepidsf= 0.972;
	    } 
	    else if(lepeta < 1.442){
	      if(leppt < 40.) lepidsf= 0.929;
	      else if(leppt < 50.) lepidsf= 0.941; 
	      else lepidsf= 0.947;
	    } 
	    else if(lepeta < 1.566){
	      if(leppt < 40.) lepidsf= 0.898;
	      else if(leppt < 50.) lepidsf= 0.916; 
	      else lepidsf= 0.907;
	    } 
	    else if(lepeta < 2.0){
	      if(leppt < 40.) lepidsf= 0.907;
	      else if(leppt < 50.) lepidsf= 0.927; 
	      else lepidsf= 0.943;
	    } 
	    else{
	      if(leppt < 40.) lepidsf= 0.923;
	      else if(leppt < 50.) lepidsf= 0.935; 
	      else lepidsf= 0.952;
	    } 
	  }
	}
      	if(isM){
	  isPastTrigMC = 1;
	  isPastTrigMCAlt = 1;

	  // IsoMu20 || IsoTkMu20 Eff -- 76X DATA EFFICIENCIES
	  if(leppt < 50){
	    if(fabs(lepeta) < 0.9) TrigEffWeight = 0.947; //0.984; // 
	    else if(fabs(lepeta) < 1.2) TrigEffWeight = 0.936; //0.983;
	    else if(fabs(lepeta) < 2.1) TrigEffWeight = 0.936; //1.004;
	    else TrigEffWeight = 0.897; //1.006;
          }else if(leppt < 60){
            if(fabs(lepeta) < 0.9) TrigEffWeight = 0.953; //0.984; // 
            else if(fabs(lepeta) < 1.2) TrigEffWeight = 0.937; //0.983;
            else if(fabs(lepeta) < 2.1) TrigEffWeight = 0.941; //1.004;
            else TrigEffWeight = 0.901; //1.006;
          }else{
            if(fabs(lepeta) < 0.9) TrigEffWeight = 0.955; //0.984; // 
            else if(fabs(lepeta) < 1.2) TrigEffWeight = 0.939; //0.983;
            else if(fabs(lepeta) < 2.1) TrigEffWeight = 0.942; //1.004;
            else TrigEffWeight = 0.907; //1.006;
	  } 

	  //Mini-iso < 0.2 SFs from SUSY TWiki for 80X/ICHEP
	  if(leppt < 40){
	    if(fabs(lepeta) < 0.9) isosf= 0.999;
	    else if(fabs(lepeta) <  1.2) isosf= 1.000;
	    else if(fabs(lepeta) <  2.1) isosf= 0.999;
	    else if(fabs(lepeta) <  2.4) isosf= 1.000;
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
	    else if(fabs(lepeta) <  2.1) isosf= 1.000;
	    else if(fabs(lepeta) <  2.4) isosf= 0.999;
	  }
	  
	  //Cut-based ID scale factors from POG TWiki -- Prelim 80X 2.6/fb
	  if(fabs(lepeta) < 0.9){
	    if(leppt < 40.) lepidsf= 0.9805;
	    else if(leppt < 50.) lepidsf= 0.9793;
            else if(leppt < 60.) lepidsf= 0.9789;
            else lepidsf= 0.9791;
	  } 
	  else if(fabs(lepeta) < 1.2){ 
            if(leppt < 40.) lepidsf= 0.9730;
	    else if(leppt < 50.) lepidsf= 0.9728;
            else if(leppt < 60.) lepidsf= 0.9720;
	    else lepidsf= 0.9780;
	  }
	  else if(fabs(lepeta) < 2.1){ 
	    if(leppt < 40.) lepidsf= 0.9915;
	    else if(leppt < 50.) lepidsf= 0.9928;
            else if(leppt < 60.) lepidsf= 0.9945;
	    else lepidsf= 0.9965;
	  }
	  else{
	    if(leppt < 40.) lepidsf= 0.9785;
	    else if(leppt < 50.) lepidsf= 0.9782;
            else if(leppt < 60.) lepidsf= 0.9786;
	    else lepidsf= 0.9793;
	  }
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
	    if(vsSelTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele27_eta2p1_WPLoose_Gsf_v5" && viSelTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v1" && viSelTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v2" && viSelTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v3" && viSelTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v4" && viSelTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v5" && viSelTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	  }
	}
	if(isM){
	  for(unsigned int itrig=0; itrig < vsSelTriggersMu_singleLepCalc->size(); itrig++){
	    if((vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu20_v1" || vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu20_v1") && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if((vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu20_v2" || vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu20_v2") && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if((vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu20_v3" || vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu20_v3") && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if((vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu20_v4" || vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu20_v4") && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if((vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu20_v5" || vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu20_v5") && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if((vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu20_v6" || vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu20_v6") && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v1" && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v2" && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v3" && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v4" && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v5" && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v6" && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigAlt = 1;
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
      vector<pair<double,int>> jetptindpair;
      JetSF_pTNbwflat = 1.0;
      JetSFup_pTNbwflat = 1.0;
      JetSFdn_pTNbwflat = 1.0;
      JetSFupwide_pTNbwflat = 1.0;
      JetSFdnwide_pTNbwflat = 1.0;

      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc->size(); ijet++){

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
      theJetBTag_bSFdn_JetSubCalc_PtOrdered.clear();
      theJetBTag_bSFup_JetSubCalc_PtOrdered.clear();
      theJetBTag_lSFdn_JetSubCalc_PtOrdered.clear();
      theJetBTag_lSFup_JetSubCalc_PtOrdered.clear();
      for(unsigned int ijet=0; ijet < jetptindpair.size(); ijet++){
      	theJetPt_JetSubCalc_PtOrdered.push_back(theJetPt_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetEta_JetSubCalc_PtOrdered.push_back(theJetEta_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetPhi_JetSubCalc_PtOrdered.push_back(theJetPhi_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetEnergy_JetSubCalc_PtOrdered.push_back(theJetEnergy_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetCSV_JetSubCalc_PtOrdered.push_back(theJetCSV_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetBTag_JetSubCalc_PtOrdered.push_back(theJetBTag_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetBTag_bSFdn_JetSubCalc_PtOrdered.push_back(theJetBTag_bSFdn_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetBTag_bSFup_JetSubCalc_PtOrdered.push_back(theJetBTag_bSFup_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetBTag_lSFdn_JetSubCalc_PtOrdered.push_back(theJetBTag_lSFdn_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetBTag_lSFup_JetSubCalc_PtOrdered.push_back(theJetBTag_lSFup_JetSubCalc->at(jetptindpair[ijet].second));
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
      int nHtags_bSFup = 0;      
      int nHtags_bSFdn = 0;      
      int nHtags_lSFup = 0;      
      int nHtags_lSFdn = 0;      
      int njetsak8 = 0;
      vector<float> maxsubcsv;
      NJetsHtagged_shifts.clear();
      vector<pair<double,int>> jetak8ptindpair;
      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc->size(); ijet++){
	maxsubcsv.push_back(-99.0);
	if(theJetAK8Pt_JetSubCalc->at(ijet) < 180 || fabs(theJetAK8Eta_JetSubCalc->at(ijet)) > ak8EtaCut) continue;
	if(theJetAK8NjettinessTau1_JetSubCalc->at(ijet)==0) continue;
	if(theJetAK8NjettinessTau2_JetSubCalc->at(ijet)==0) continue;

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
	if(theJetAK8Pt_JetSubCalc->at(ijet) > 300 &&  theJetAK8SDSubjetNCSVM_bSFup_JetSubCalc->at(ijet) > 0 && sumsubjets.M() > 60 && sumsubjets.M() < 150) nHtags_bSFup += 1;
	if(theJetAK8Pt_JetSubCalc->at(ijet) > 300 &&  theJetAK8SDSubjetNCSVM_bSFdn_JetSubCalc->at(ijet) > 0 && sumsubjets.M() > 60 && sumsubjets.M() < 150) nHtags_bSFdn += 1;
	if(theJetAK8Pt_JetSubCalc->at(ijet) > 300 &&  theJetAK8SDSubjetNCSVM_lSFup_JetSubCalc->at(ijet) > 0 && sumsubjets.M() > 60 && sumsubjets.M() < 150) nHtags_lSFup += 1;
	if(theJetAK8Pt_JetSubCalc->at(ijet) > 300 &&  theJetAK8SDSubjetNCSVM_lSFdn_JetSubCalc->at(ijet) > 0 && sumsubjets.M() > 60 && sumsubjets.M() < 150) nHtags_lSFdn += 1;
      }
      NJetsHtagged_shifts.push_back(nHtags_bSFup);
      NJetsHtagged_shifts.push_back(nHtags_bSFdn);
      NJetsHtagged_shifts.push_back(nHtags_lSFup);
      NJetsHtagged_shifts.push_back(nHtags_lSFdn);

      int isPastNHjetsCut = 0;
      if(nHtags >= 0){npass_nHjets += 1; isPastNHjetsCut = 1; }

      // check all the cuts!
      if(!(isPastMETcut && isPastNJetsCut && isPastJetLeadPtCut && isPastLepPtCut && isPastElEtaCut && isPastJetSubLeadPtCut)) continue;
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

      // Set lepton 4-vectors
      double lepM;
      double lepphi;
      elTrigPresel_singleLepCalc = false;
      if (isM){ 
	lepM = 0.105658367;
	lepphi = muPhi_singleLepCalc->at(0);
	lepton_lv.SetPtEtaPhiM(muPt_singleLepCalc->at(0),muEta_singleLepCalc->at(0),muPhi_singleLepCalc->at(0),lepM);
      }
      else{
	lepM = 0.00051099891;
	lepphi = elPhi_singleLepCalc->at(0);
	lepton_lv.SetPtEtaPhiM(elPt_singleLepCalc->at(0),elEta_singleLepCalc->at(0),elPhi_singleLepCalc->at(0),lepM);

	if(elEta_singleLepCalc->at(0) < 1.442){
	  if(elSihih_singleLepCalc->at(0) < 0.012 &&
	     elHoE_singleLepCalc->at(0) < 0.09 &&
	     elEcalPFClusterIso_singleLepCalc->at(0)/leppt < 0.37 &&
	     elHcalPFClusterIso_singleLepCalc->at(0)/leppt < 0.25 &&
	     elDR03TkSumPt_singleLepCalc->at(0)/leppt < 0.18 &&
	     fabs(elDEtaSCTkAtVtx_singleLepCalc->at(0)) < 0.0095 &&
	     fabs(elDPhiSCTkAtVtx_singleLepCalc->at(0)) < 0.065
	     ) elTrigPresel_singleLepCalc = true;
	}else{
	  if(elSihih_singleLepCalc->at(0) < 0.033 &&
	     elHoE_singleLepCalc->at(0) < 0.09 &&
	     elEcalPFClusterIso_singleLepCalc->at(0)/leppt < 0.45 &&
	     elHcalPFClusterIso_singleLepCalc->at(0)/leppt < 0.28 &&
	     elDR03TkSumPt_singleLepCalc->at(0)/leppt < 0.18
	     ) elTrigPresel_singleLepCalc = true;
	}	  
      }
      MT_lepMet = sqrt(2*leppt*corr_met_singleLepCalc*(1 - cos(lepphi - corr_met_phi_singleLepCalc)));

      // Save lepton - AK4 jet information
      int   nbtagWithSF = 0;
      BJetLeadPt = -99;
      float minMlb = 1e8;
      float minMljet = 1e8;
      float deltaR_lepJetInMinMljet = -99;
      float deltaPhi_lepJetInMinMljet = -99;
      float deltaR_lepbJetInMinMlb = -99;
      float deltaPhi_lepbJetInMinMlb = -99;
      float mindeltar = 1e8;
      float ptrel_lepclosestjet = -99;
      BJetLeadPt_shifts.clear();
      deltaR_lepJets.clear();
      deltaR_lepBJets.clear();
      deltaR_lepBJets_bSFup.clear();
      deltaR_lepBJets_bSFdn.clear();
      deltaR_lepBJets_lSFup.clear();
      deltaR_lepBJets_lSFdn.clear();
      deltaPhi_lepJets.clear();
      deltaPhi_lepBJets.clear();
      deltaPhi_lepBJets_bSFup.clear();
      deltaPhi_lepBJets_bSFdn.clear();
      deltaPhi_lepBJets_lSFup.clear();
      deltaPhi_lepBJets_lSFdn.clear();
      mass_lepJets.clear();
      mass_lepBJets.clear();
      mass_lepBJets_bSFup.clear();
      mass_lepBJets_bSFdn.clear();
      mass_lepBJets_lSFup.clear();
      mass_lepBJets_lSFdn.clear();
      NJetsCSVwithSF_JetSubCalc_shifts.clear();
      minMleppBjet_shifts.clear();
      deltaRlepbJetInMinMlb_shifts.clear();
      deltaPhilepbJetInMinMlb_shifts.clear();
      for(int i = 0; i < 4; i++){
	BJetLeadPt_shifts.push_back(-99);
	NJetsCSVwithSF_JetSubCalc_shifts.push_back(0);
	minMleppBjet_shifts.push_back(1e8);
	deltaRlepbJetInMinMlb_shifts.push_back(-99);
	deltaPhilepbJetInMinMlb_shifts.push_back(-99);
      }	

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
	  if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt) BJetLeadPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
	  deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));
	  deltaPhi_lepBJets.push_back(lepton_lv.DeltaPhi(jet_lv));
	  mass_lepBJets.push_back((lepton_lv + jet_lv).M());

	  if((lepton_lv + jet_lv).M() < minMlb) {
	    minMlb = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepbJetInMinMlb = jet_lv.DeltaR(lepton_lv);
	    deltaPhi_lepbJetInMinMlb = jet_lv.DeltaPhi(lepton_lv);
	  }
	}
	if(theJetBTag_bSFup_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsCSVwithSF_JetSubCalc_shifts.at(0) += 1;
	  if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt_shifts.at(0)) BJetLeadPt_shifts.at(0) = theJetPt_JetSubCalc_PtOrdered.at(ijet);
	  deltaR_lepBJets_bSFup.push_back(lepton_lv.DeltaR(jet_lv));
	  deltaPhi_lepBJets_bSFup.push_back(lepton_lv.DeltaPhi(jet_lv));
	  mass_lepBJets_bSFup.push_back((lepton_lv + jet_lv).M());

	  if((lepton_lv + jet_lv).M() < minMleppBjet_shifts.at(0)) {
	    minMleppBjet_shifts.at(0) = fabs( (lepton_lv + jet_lv).M() );
	    deltaRlepbJetInMinMlb_shifts.at(0) = jet_lv.DeltaR(lepton_lv);
	    deltaPhilepbJetInMinMlb_shifts.at(0) = jet_lv.DeltaPhi(lepton_lv);
	  }
	}
	if(theJetBTag_bSFdn_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsCSVwithSF_JetSubCalc_shifts.at(1) += 1;
	  if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt_shifts.at(1)) BJetLeadPt_shifts.at(1) = theJetPt_JetSubCalc_PtOrdered.at(ijet);
	  deltaR_lepBJets_bSFdn.push_back(lepton_lv.DeltaR(jet_lv));
	  deltaPhi_lepBJets_bSFdn.push_back(lepton_lv.DeltaPhi(jet_lv));
	  mass_lepBJets_bSFdn.push_back((lepton_lv + jet_lv).M());

	  if((lepton_lv + jet_lv).M() < minMleppBjet_shifts.at(1)) {
	    minMleppBjet_shifts.at(1) = fabs( (lepton_lv + jet_lv).M() );
	    deltaRlepbJetInMinMlb_shifts.at(1) = jet_lv.DeltaR(lepton_lv);
	    deltaPhilepbJetInMinMlb_shifts.at(1) = jet_lv.DeltaPhi(lepton_lv);
	  }
	}
	if(theJetBTag_lSFup_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsCSVwithSF_JetSubCalc_shifts.at(2) += 1;
	  if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt_shifts.at(2)) BJetLeadPt_shifts.at(2) = theJetPt_JetSubCalc_PtOrdered.at(ijet);
	  deltaR_lepBJets_lSFup.push_back(lepton_lv.DeltaR(jet_lv));
	  deltaPhi_lepBJets_lSFup.push_back(lepton_lv.DeltaPhi(jet_lv));
	  mass_lepBJets_lSFup.push_back((lepton_lv + jet_lv).M());

	  if((lepton_lv + jet_lv).M() < minMleppBjet_shifts.at(2)) {
	    minMleppBjet_shifts.at(2) = fabs( (lepton_lv + jet_lv).M() );
	    deltaRlepbJetInMinMlb_shifts.at(2) = jet_lv.DeltaR(lepton_lv);
	    deltaPhilepbJetInMinMlb_shifts.at(2) = jet_lv.DeltaPhi(lepton_lv);
	  }
	}
	if(theJetBTag_lSFdn_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsCSVwithSF_JetSubCalc_shifts.at(3) += 1;
	  if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt_shifts.at(3)) BJetLeadPt_shifts.at(3) = theJetPt_JetSubCalc_PtOrdered.at(ijet);
	  deltaR_lepBJets_lSFdn.push_back(lepton_lv.DeltaR(jet_lv));
	  deltaPhi_lepBJets_lSFdn.push_back(lepton_lv.DeltaPhi(jet_lv));
	  mass_lepBJets_lSFdn.push_back((lepton_lv + jet_lv).M());

	  if((lepton_lv + jet_lv).M() < minMleppBjet_shifts.at(3)) {
	    minMleppBjet_shifts.at(3) = fabs( (lepton_lv + jet_lv).M() );
	    deltaRlepbJetInMinMlb_shifts.at(3) = jet_lv.DeltaR(lepton_lv);
	    deltaPhilepbJetInMinMlb_shifts.at(3) = jet_lv.DeltaPhi(lepton_lv);
	  }
	}

 	if(deltaR_lepJets[ijet] < mindeltar) {
	  mindeltar = deltaR_lepJets[ijet];
	  ptrel_lepclosestjet = lepton_lv.P()*(jet_lv.Vect().Cross(lepton_lv.Vect()).Mag()/jet_lv.P()/lepton_lv.P());
	}
      }

      //8TeV Top Pt Reweighting
      /*
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
      */
      //Calculate neutrino Pz with W constraint to the lepton
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
      
      // Create a leptonic top with the W -> lnu from above
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

      // Tag hadronic W jets, save lepton - AK8 jet information
      int nWtags = 0;
      NJetsWtagged_0p6 = 0;
      deltaR_lepAK8s.clear();
      deltaPhi_lepAK8s.clear();
      mass_lepAK8s.clear();
      minDR_lepAK8 = 1000;
      WJetLeadPt = -99.0;
      deltaRtopWjet = -99;     deltaPhitopWjet = -99;
      deltaRlepWjet = -99;     deltaPhilepWjet = -99;	  

      NJetsWtagged_0p6_shifts.clear();
      theJetAK8Wmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8Hmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8Zmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8Tmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8MatchedPt_JetSubCalc_PtOrdered.clear();
      WJetLeadPt_shifts.clear();
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
	WJetLeadPt_shifts.push_back(-99.0);
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
	//76X with v2 JEC: NO SCALE OR SMEAR CORRECTION, will add uncertainties later
	
	float AK8massScale=1.0; //0.982; //nominal
	float AK8massScaleUp=1.0; //0.990; //scale up
	float AK8massScaleDn=1.0; //0.974; //scale down
	float AK8massSmear=0.0; //3.7; //nominal
	float AK8massSmearUp=0.0; //4.7; //1sigma up
	float AK8massSmearDn=0.0; //2.3; //1sigma down

	float gran = 0; //gRandom->Gaus(0, AK8massSmear);
	float granUp = 0; //gRandom->Gaus(0, AK8massSmearUp);
	float granDn = 0; //gRandom->Gaus(0, AK8massSmearDn);
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
	  int matchedID = 0;
	  bool isWmatched = false;
	  bool isHmatched = false;
	  bool isZmatched = false;
	  bool isTmatched = false;
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
	  
	  double coin = gRandom->Rndm();

	  // SCALE FACTOR ONLY USED ON MATCHED JETS
	  double tau0p6Eff = 1.0;
	  if(isWmatched){	    
	    // VALUES FOR 76X FROM TWIKI 76X with JEC v2
	    tau0p6SF = 0.980;
	    tau0p6SFup = 1.014;
	    tau0p6SFdn = 0.946;
	  
	    // Use matched W to find the efficiency -- calculated for TpTp and ttbar, EWK/QCD will almost never pass here (use ttbar eff when they do)
	    if(isSig){
	      int bin = (std::upper_bound(ptRangeTpTp.begin(), ptRangeTpTp.end(), matchedPt)-ptRangeTpTp.begin())-1;
	      tau0p6Eff = SignalEff[SigMass][bin];
	    }else{
	      int bin = (std::upper_bound(ptRangeTTbar.begin(), ptRangeTTbar.end(), matchedPt)-ptRangeTTbar.begin())-1;
	      if(isTT) tau0p6Eff = TTbarEff[bin]; // ttbar
	      else if(isST) tau0p6Eff = STEff[bin]; // single top (s and t channel had 0 boosted tops)
	      else tau0p6Eff = WVEff[bin]; // WW, WZ, etc. 
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
	  if(tau0p6SF > 1){
	    float mistagpercent = (1.0 - tau0p6SF) / (1.0 - (tau0p6SF/tau0p6Eff));
	    if(tag_JMS_JMR_tau0p6 == 0 && coin < mistagpercent) tag_JMS_JMR_tau0p6 = 1;	    
	    if(tag_JMSup_JMR_tau0p6 == 0 && coin < mistagpercent) tag_JMSup_JMR_tau0p6 = 1;	    
	    if(tag_JMSdn_JMR_tau0p6 == 0 && coin < mistagpercent) tag_JMSdn_JMR_tau0p6 = 1;	    
	    if(tag_JMS_JMRup_tau0p6 == 0 && coin < mistagpercent) tag_JMS_JMRup_tau0p6 = 1;	    
	    if(tag_JMS_JMRdn_tau0p6 == 0 && coin < mistagpercent) tag_JMS_JMRdn_tau0p6 = 1;	    
	  }
	  else if(tau0p6SF < 1){
	    if(tag_JMS_JMR_tau0p6 == 1 && coin > tau0p6SF) tag_JMS_JMR_tau0p6 = 0;	    
	    if(tag_JMSup_JMR_tau0p6 == 1 && coin > tau0p6SF) tag_JMSup_JMR_tau0p6 = 0;	    
	    if(tag_JMSdn_JMR_tau0p6 == 1 && coin > tau0p6SF) tag_JMSdn_JMR_tau0p6 = 0;	    
	    if(tag_JMS_JMRup_tau0p6 == 1 && coin > tau0p6SF) tag_JMS_JMRup_tau0p6 = 0;	    
	    if(tag_JMS_JMRdn_tau0p6 == 1 && coin > tau0p6SF) tag_JMS_JMRdn_tau0p6 = 0;	    
	  }

	  if(tau0p6SFup > 1){
	    float mistagpercent = (1.0 - tau0p6SFup) / (1.0 - (tau0p6SFup/tau0p6Eff));
	    if(tag_JMS_JMR_tau0p6up == 0 && coin < mistagpercent) tag_JMS_JMR_tau0p6up = 1;	    
	  }
	  else if(tau0p6SFup < 1){
	    if(tag_JMS_JMR_tau0p6up == 1 && coin > tau0p6SFup) tag_JMS_JMR_tau0p6up = 0;	    
	  }

	  if(tau0p6SFdn > 1){
	    float mistagpercent = (1.0 - tau0p6SFdn) / (1.0 - (tau0p6SFdn/tau0p6Eff));
	    if(tag_JMS_JMR_tau0p6dn == 0 && coin < mistagpercent) tag_JMS_JMR_tau0p6dn = 1;	    
	  }
	  else if(tau0p6SFdn < 1){
	    if(tag_JMS_JMR_tau0p6dn == 1 && coin > tau0p6SFdn) tag_JMS_JMR_tau0p6dn = 0;
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
	 
	  theJetAK8Wmatch_JetSubCalc_PtOrdered.push_back(0);
	  theJetAK8Hmatch_JetSubCalc_PtOrdered.push_back(0);
	  theJetAK8Zmatch_JetSubCalc_PtOrdered.push_back(0);
	  theJetAK8Tmatch_JetSubCalc_PtOrdered.push_back(0);
 
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

      if(WJetTaggedPt.size() > 0) WJetLeadPt = WJetTaggedPt.at(0);
      if(WJetTaggedPtJMRup.size() > 0) WJetLeadPt_shifts.at(0) = WJetTaggedPtJMRup.at(0);
      if(WJetTaggedPtJMRdn.size() > 0) WJetLeadPt_shifts.at(1) = WJetTaggedPtJMRdn.at(0);
      if(WJetTaggedPtJMSup.size() > 0) WJetLeadPt_shifts.at(2) = WJetTaggedPtJMSup.at(0);
      if(WJetTaggedPtJMSdn.size() > 0) WJetLeadPt_shifts.at(3) = WJetTaggedPtJMSdn.at(0);
      if(WJetTaggedPtTAUup.size() > 0) WJetLeadPt_shifts.at(4) = WJetTaggedPtTAUup.at(0);
      if(WJetTaggedPtTAUdn.size() > 0) WJetLeadPt_shifts.at(5) = WJetTaggedPtTAUdn.at(0);

      
      //PDF and RENORM weights
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

      AK4HTpMETpLepPt       = (float) st;
      AK4HT                 = (float) ht;
      NJets_JetSubCalc      = (int) njets;
      NJetsAK8_JetSubCalc   = (int) njetsak8;
      NJetsCSVwithSF_JetSubCalc = (int) nbtagWithSF;
      NJetsHtagged          = (int) nHtags;
      
      pileupWeight          = (float) puweight;
      pileupWeightUp        = (float) puweightup;
      pileupWeightDown      = (float) puweightdown;
      isoSF                 = (float) isosf;
      lepIdSF               = (float) lepidsf;
      EGammaRecoSF          = (float) egammasf;
      MCPastTrigger         = (int)   isPastTrigMC;
      MCPastTriggerAlt      = (int)   isPastTrigMCAlt;
      DataPastTrigger       = (int)   isPastTrig;
      DataPastTriggerAlt    = (int)   isPastTrigAlt;
      
      topPt          = (float) lvTop.Pt();
      topMass        = (float) lvTop.M();
      minMleppBjet   = (float) minMlb;
      minMleppJet    = (float) minMljet;
      genTopPt       = -999; //(float) gen_tpt;
      genAntiTopPt   = -999; //(float) gen_anti_tpt;
      topPtWeight    = 1.0; //(float) weight_toppt;
      topPtWeightPast400    = 1.0; //(float) weightPast400_toppt;
      topPtWeightHighPt    = 1.0; //(float) weightHighPt_toppt;
      deltaRlepJetInMinMljet   = (float) deltaR_lepJetInMinMljet;
      deltaPhilepJetInMinMljet = (float) deltaPhi_lepJetInMinMljet;
      deltaRlepbJetInMinMlb    = (float) deltaR_lepbJetInMinMlb;
      deltaPhilepbJetInMinMlb  = (float) deltaPhi_lepbJetInMinMlb;
      minDR_lepJet = (float) mindeltar;
      ptRel_lepJet = (float) ptrel_lepclosestjet;
      topPtGen = -999;
      /*
      if(fabs(lvTop.Pt()-gen_tpt)<=fabs(lvTop.Pt()-gen_anti_tpt)){
        topPtGen           = -999; //(float) gen_tpt;
      }
      else{
        topPtGen           = -999; //(float) gen_anti_tpt;
      }
      */
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
