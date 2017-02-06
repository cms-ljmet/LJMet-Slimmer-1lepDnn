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

// ----------------------------------------------------------------------------
// Define functions
// ----------------------------------------------------------------------------

bool comparepair( const std::pair<double,int> a, const std::pair<double,int> b) { return a.first > b.first; }

TRandom3 Rand;

const double MTOP  = 173.5;
const double MW    = 80.4; 

bool step1::applySF(bool& isTagged, float tag_SF, float tag_eff){
  
  bool newTag = isTagged;
  if (tag_SF == 1) return newTag; //no correction needed 

  //throw die
  float coin = Rand.Uniform(1.);    

  if(tag_SF > 1){  // use this if SF>1

    if( !isTagged ) {

      //fraction of jets that need to be upgraded
      float mistagPercent = (1.0 - tag_SF) / (1.0 - (tag_SF/tag_eff) );

      //upgrade to tagged
      if( coin < mistagPercent ) {newTag = true;}
    }

  }else{  // use this if SF<1
      
    //downgrade tagged to untagged
    if( isTagged && coin > tag_SF ) {newTag = false;}

  }

  return newTag;
}

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
   inputTree->SetBranchStatus("theJetAK8PrunedMassWtagUncerts_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8PrunedMassWtagUncerts_JMSup_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8PrunedMassWtagUncerts_JMSdn_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8PrunedMassWtagUncerts_JMRup_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8PrunedMassWtagUncerts_JMRdn_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDropMass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDropMassWtagUncerts_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDropMassWtagUncerts_JMSup_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDropMassWtagUncerts_JMSdn_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDropMassWtagUncerts_JMRup_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDropMassWtagUncerts_JMRdn_JetSubCalc",1);
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
   inputTree->SetBranchStatus("isTT_TTbarMassCalc",1);
   inputTree->SetBranchStatus("isTTbb_TTbarMassCalc",1);
   inputTree->SetBranchStatus("isTTbj_TTbarMassCalc",1);
   inputTree->SetBranchStatus("isTTcc_TTbarMassCalc",1);
   inputTree->SetBranchStatus("isTTcj_TTbarMassCalc",1);
   inputTree->SetBranchStatus("isTTlf_TTbarMassCalc",1);
   inputTree->SetBranchStatus("isTTll_TTbarMassCalc",1);
   inputTree->SetBranchStatus("NExtraBs_TTbarMassCalc",1);
   inputTree->SetBranchStatus("NExtraCs_TTbarMassCalc",1);
   inputTree->SetBranchStatus("NExtraLs_TTbarMassCalc",1);
   inputTree->SetBranchStatus("isTau_singleLepCalc",1);
   
   //LHE weights
   inputTree->SetBranchStatus("LHEweightids_singleLepCalc",1);
   inputTree->SetBranchStatus("LHEweights_singleLepCalc",1);

  // ----------------------------------------------------------------------------
  // Create output tree and define branches
  // ----------------------------------------------------------------------------
   
   // OUTPUT FILE
   outputFile->cd();
   TTree *outputTree = new TTree("ljmet","ljmet");

   outputTree->Branch("event_CommonCalc",&event_CommonCalc,"event_CommonCalc/L");
   outputTree->Branch("run_CommonCalc",&run_CommonCalc,"run_CommonCalc/I");
   outputTree->Branch("lumi_CommonCalc",&lumi_CommonCalc,"lumi_CommonCalc/I");
   outputTree->Branch("nPV_singleLepCalc",&nPV_singleLepCalc,"nPV_singleLepCalc/I");
   outputTree->Branch("nTrueInteractions_singleLepCalc",&nTrueInteractions_singleLepCalc,"nTrueInteractions_singleLepCalc/I");
   outputTree->Branch("isElectron",&isElectron,"isElectron/I");
   outputTree->Branch("isMuon",&isMuon,"isMuon/I");
   outputTree->Branch("MCPastTrigger",&MCPastTrigger,"MCPastTrigger/I");
   outputTree->Branch("MCPastTriggerOR",&MCPastTriggerOR,"MCPastTriggerOR/I");
   outputTree->Branch("MCPastTriggerLepTight",&MCPastTriggerLepTight,"MCPastTriggerLepTight/I");
   outputTree->Branch("MCPastTriggerHTTight",&MCPastTriggerHTTight,"MCPastTriggerHTTight/I");
   outputTree->Branch("DataPastTrigger",&DataPastTrigger,"DataPastTrigger/I");
   outputTree->Branch("DataPastTriggerOR",&DataPastTriggerOR,"DataPastTriggerOR/I");
   outputTree->Branch("DataPastTriggerLepTight",&DataPastTriggerLepTight,"DataPastTriggerLepTight/I");
   outputTree->Branch("DataPastTriggerHTTight",&DataPastTriggerHTTight,"DataPastTriggerHTTight/I");
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
   outputTree->Branch("JetSF_80X",&JetSF_80X,"JetSF_80X/F");
   outputTree->Branch("JetSFup_80X",&JetSFup_80X,"JetSFup_80X/F");
   outputTree->Branch("JetSFdn_80X",&JetSFdn_80X,"JetSFdn_80X/F");
   outputTree->Branch("pileupWeight",&pileupWeight,"pileupWeight/F");
   outputTree->Branch("pileupWeightUp",&pileupWeightUp,"pileupWeightUp/F");
   outputTree->Branch("pileupWeightDown",&pileupWeightDown,"pileupWeightDown/F");
   outputTree->Branch("TrigEffAltWeight",&TrigEffAltWeight,"TrigEffAltWeight/F");
   outputTree->Branch("TrigEffWeight",&TrigEffWeight,"TrigEffWeight/F");
   outputTree->Branch("TrigEffWeightUncert",&TrigEffWeightUncert,"TrigEffWeightUncert/F");
   outputTree->Branch("isoSF",&isoSF,"isoSF/F");
   outputTree->Branch("lepIdSF",&lepIdSF,"lepIdSF/F");
   outputTree->Branch("EGammaGsfSF",&EGammaGsfSF,"EGammaGsfSF/F");
   outputTree->Branch("MuTrkSF",&MuTrkSF,"MuTrkSF/F");

   outputTree->Branch("ttbarMass_TTbarMassCalc",&ttbarMass_TTbarMassCalc,"ttbarMass_TTbarMassCalc/D");
   outputTree->Branch("isTT_TTbarMassCalc",&isTT_TTbarMassCalc,"isTT_TTbarMassCalc/I");
   outputTree->Branch("isTTbb_TTbarMassCalc",&isTTbb_TTbarMassCalc,"isTTbb_TTbarMassCalc/I");
   outputTree->Branch("isTTbj_TTbarMassCalc",&isTTbj_TTbarMassCalc,"isTTbj_TTbarMassCalc/I");
   outputTree->Branch("isTTcc_TTbarMassCalc",&isTTcc_TTbarMassCalc,"isTTcc_TTbarMassCalc/I");
   outputTree->Branch("isTTcj_TTbarMassCalc",&isTTcj_TTbarMassCalc,"isTTcj_TTbarMassCalc/I");
   outputTree->Branch("isTTlf_TTbarMassCalc",&isTTlf_TTbarMassCalc,"isTTlf_TTbarMassCalc/I");
   outputTree->Branch("isTTll_TTbarMassCalc",&isTTll_TTbarMassCalc,"isTTll_TTbarMassCalc/I");
   outputTree->Branch("NExtraBs_TTbarMassCalc",&NExtraBs_TTbarMassCalc,"NExtraBs_TTbarMassCalc/I");
   outputTree->Branch("NExtraCs_TTbarMassCalc",&NExtraCs_TTbarMassCalc,"NExtraCs_TTbarMassCalc/I");
   outputTree->Branch("NExtraLs_TTbarMassCalc",&NExtraLs_TTbarMassCalc,"NExtraLs_TTbarMassCalc/I");
   outputTree->Branch("isTau_singleLepCalc",&isTau_singleLepCalc,"isTau_singleLepCalc/O");
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
   outputTree->Branch("theJetAK8PrunedMassWtagUncerts_JetSubCalc_PtOrdered",&theJetAK8PrunedMassWtagUncerts_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8PrunedMassWtagUncerts_JMSup_JetSubCalc_PtOrdered",&theJetAK8PrunedMassWtagUncerts_JMSup_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8PrunedMassWtagUncerts_JMSdn_JetSubCalc_PtOrdered",&theJetAK8PrunedMassWtagUncerts_JMSdn_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8PrunedMassWtagUncerts_JMRup_JetSubCalc_PtOrdered",&theJetAK8PrunedMassWtagUncerts_JMRup_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8PrunedMassWtagUncerts_JMRdn_JetSubCalc_PtOrdered",&theJetAK8PrunedMassWtagUncerts_JMRdn_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SoftDropMassWtagUncerts_JetSubCalc_PtOrdered",&theJetAK8SoftDropMassWtagUncerts_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SoftDropMassWtagUncerts_JMSup_JetSubCalc_PtOrdered",&theJetAK8SoftDropMassWtagUncerts_JMSup_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SoftDropMassWtagUncerts_JMSdn_JetSubCalc_PtOrdered",&theJetAK8SoftDropMassWtagUncerts_JMSdn_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SoftDropMassWtagUncerts_JMRup_JetSubCalc_PtOrdered",&theJetAK8SoftDropMassWtagUncerts_JMRup_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SoftDropMassWtagUncerts_JMRdn_JetSubCalc_PtOrdered",&theJetAK8SoftDropMassWtagUncerts_JMRdn_JetSubCalc_PtOrdered);
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
   outputTree->Branch("genJetPt_singleLepCalc",&genJetPt_singleLepCalc);
   outputTree->Branch("genJetEta_singleLepCalc",&genJetEta_singleLepCalc);
   outputTree->Branch("genJetPhi_singleLepCalc",&genJetPhi_singleLepCalc);
   outputTree->Branch("genJetEnergy_singleLepCalc",&genJetEnergy_singleLepCalc);
   outputTree->Branch("BJetLeadPt",&BJetLeadPt,"BJetLeadPt/F");
   outputTree->Branch("BJetLeadPt_shifts",&BJetLeadPt_shifts);
   outputTree->Branch("WJetLeadPt",&WJetLeadPt,"WJetLeadPt/F");
   outputTree->Branch("WJetLeadPt_shifts",&WJetLeadPt_shifts);
   outputTree->Branch("TJetLeadPt",&TJetLeadPt,"TJetLeadPt/F");
   outputTree->Branch("TJetLeadPt_shifts",&TJetLeadPt_shifts);
   outputTree->Branch("AK4HTpMETpLepPt",&AK4HTpMETpLepPt,"AK4HTpMETpLepPt/F");
   outputTree->Branch("AK4HT",&AK4HT,"AK4HT/F");
   outputTree->Branch("NJets_JetSubCalc",&NJets_JetSubCalc,"NJets_JetSubCalc/I");
   outputTree->Branch("NJetsAK8_JetSubCalc",&NJetsAK8_JetSubCalc,"NJetsAK8_JetSubCalc/I");
   outputTree->Branch("NJetsCSV_JetSubCalc",&NJetsCSV_JetSubCalc,"NJetsCSV_JetSubCalc/I");
   outputTree->Branch("NJetsCSVwithSF_JetSubCalc",&NJetsCSVwithSF_JetSubCalc,"NJetsCSVwithSF_JetSubCalc/I");
   outputTree->Branch("NJetsCSVwithSF_JetSubCalc_shifts",&NJetsCSVwithSF_JetSubCalc_shifts);
   outputTree->Branch("NJetsH1btagged",&NJetsH1btagged,"NJetsH1btagged/I");
   outputTree->Branch("NJetsH1btagged_shifts",&NJetsH1btagged_shifts);
   outputTree->Branch("NJetsH2btagged",&NJetsH2btagged,"NJetsH2btagged/I");
   outputTree->Branch("NJetsH2btagged_shifts",&NJetsH2btagged_shifts);
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
   outputTree->Branch("topPtWeight13TeV",&topPtWeight13TeV,"topPtWeight13TeV/F");
   outputTree->Branch("TauPtWeightUp",&TauPtWeightUp,"TauPtWeightUp/F");
   outputTree->Branch("TauPtWeightDown",&TauPtWeightDown,"TauPtWeightDown/F");
   outputTree->Branch("deltaRlepJetInMinMljet",&deltaRlepJetInMinMljet,"deltaRlepJetInMinMljet/F");
   outputTree->Branch("deltaRlepbJetInMinMlb",&deltaRlepbJetInMinMlb,"deltaRlepbJetInMinMlb/F");
   outputTree->Branch("deltaRlepbJetInMinMlb_shifts",&deltaRlepbJetInMinMlb_shifts);
   outputTree->Branch("deltaPhilepJetInMinMljet",&deltaPhilepJetInMinMljet,"deltaPhilepJetInMinMljet/F");
   outputTree->Branch("deltaPhilepbJetInMinMlb",&deltaPhilepbJetInMinMlb,"deltaPhilepbJetInMinMlb/F");
   outputTree->Branch("deltaPhilepbJetInMinMlb_shifts",&deltaPhilepbJetInMinMlb_shifts);
   outputTree->Branch("deltaRtopWjet",&deltaRtopWjet,"deltaRtopWjet/F");
   outputTree->Branch("deltaRlepWjet",&deltaRlepWjet,"deltaRlepWjet/F");
   outputTree->Branch("deltaRlepTjet",&deltaRlepTjet,"deltaRlepTjet/F");
   outputTree->Branch("deltaPhitopWjet",&deltaPhitopWjet,"deltaPhitopWjet/F");
   outputTree->Branch("deltaPhilepWjet",&deltaPhilepWjet,"deltaPhilepWjet/F");
   outputTree->Branch("deltaPhilepTjet",&deltaPhilepTjet,"deltaPhilepTjet/F");
   outputTree->Branch("deltaRtopWjet_shifts",&deltaRtopWjet_shifts);
   outputTree->Branch("deltaRlepWjet_shifts",&deltaRlepWjet_shifts);
   outputTree->Branch("deltaRlepTjet_shifts",&deltaRlepTjet_shifts);
   outputTree->Branch("deltaPhitopWjet_shifts",&deltaPhitopWjet_shifts);
   outputTree->Branch("deltaPhilepWjet_shifts",&deltaPhilepWjet_shifts);
   outputTree->Branch("deltaPhilepTjet_shifts",&deltaPhilepTjet_shifts);
   outputTree->Branch("NJetsWtagged_0p6",&NJetsWtagged_0p6,"NJetsWtagged_0p6/I");
   outputTree->Branch("NJetsWtagged_0p6_shifts",&NJetsWtagged_0p6_shifts);
   outputTree->Branch("NJetsWtagged_0p6_notTtagged",&NJetsWtagged_0p6_notTtagged,"NJetsWtagged_0p6_notTtagged/I");
   outputTree->Branch("NJetsWtagged_0p6_notTtagged_shifts",&NJetsWtagged_0p6_notTtagged_shifts);
   outputTree->Branch("NJetsTtagged_0p81",&NJetsTtagged_0p81,"NJetsTtagged_0p81/I");
   outputTree->Branch("NJetsTtagged_0p81_shifts",&NJetsTtagged_0p81_shifts);
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

  // ----------------------------------------------------------------------------
  // Define and initialize objects / cuts / efficiencies
  // ----------------------------------------------------------------------------

   // basic cuts
   float metCut=30;
   int   njetsCut=3;
   float JetLeadPtCut=50;
   float JetSubLeadPtCut=30;
   float lepPtCut=30;
   float elEtaCut=2.5;
   float muEtaCut=2.4;
   float jetEtaCut=2.4;
   float ak8EtaCut=2.4;
   float jetPtCut=30;

   // counters
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
   
   // Muon tracking efficiencies
   float tracksf[10] = {0.9824, 0.9918, 0.9959, 0.9934, 0.9915, 0.9947, 0.9967, 0.9949, 0.9912, 0.9768};

   // W tagging efficiencies. Assumes each signal mass uses the same pT bins but has unique values.
   std::vector<float> ptRangeTpTp, ptRangeTTbar;
   float ptminTTbar[11] = {200,250,300,350,400,450,500,550,600,700,800};
   for (int i=0;i<11;++i) ptRangeTTbar.push_back(ptminTTbar[i]);
   float ptminTpTp[11] = {200,250,300,350,400,450,500,550,600,700,800};
   for (int i=0;i<11;++i) ptRangeTpTp.push_back(ptminTpTp[i]);

   std::vector<std::vector<float>> SignalEff;
   if(isTpTp){
     SignalEff = {//TpTp
       {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0},//700
       {0.542155115821,0.575132860149,0.58091518866,0.588012400965,0.595087182776,0.592679055,0.606709521896,0.602146478266,0.607605657661,0.611871419478,0.589529028436},//800
       {0.534155519543,0.562368452405,0.563465250965,0.564928335386,0.570521050069,0.578527298279,0.58054138368,0.586554895418,0.591619082147,0.587640213859,0.587026556378},//900
       {0.531189279732,0.553182041274,0.542545393621,0.546336861964,0.55737230824,0.563210567446,0.570254000881,0.567822899041,0.572519083969,0.589643341578,0.574335266924},//1000
       {0.526181982204,0.547823872319,0.534071901287,0.534315081121,0.54266543267,0.552942637199,0.556231342243,0.562947112928,0.568080496646,0.569671619428,0.567609469935},//1100
       {0.530513892304,0.547829864011,0.526266628927,0.523286958783,0.529797941094,0.539789712401,0.546641432842,0.546573042284,0.552191578198,0.551722304912,0.558194256151},//1200
       {0.534977711738,0.543346978478,0.525411905395,0.515838861993,0.518266007613,0.527089249773,0.53649057147,0.541357913127,0.540769663712,0.547631392882,0.548374166434},//1300
       {0.541429874412,0.547898452476,0.523515927595,0.513111857831,0.509468247896,0.521226201611,0.52366801741,0.533376499245,0.536777866798,0.539495148965,0.538332745858},//1400
       {0.54,0.555857705755,0.533621960206,0.507559308404,0.502171081198,0.509037056982,0.516793769268,0.521417445483,0.527783996005,0.53325093208,0.534566198493},//1500
       {0.555072326747,0.559549251991,0.531206804891,0.513979496738,0.500937851694,0.503579861376,0.505009370045,0.517146056407,0.518947294001,0.522793366344,0.527386071708},//1600
       {0.552914544426,0.566804724651,0.535233927537,0.516092666704,0.510090081023,0.50606884058,0.499600790016,0.506586540375,0.513597634517,0.518201416692,0.518731146604},//1700
       {0.557304785894,0.574445000835,0.548293442855,0.521840347975,0.505016722408,0.493875141437,0.498675288518,0.503879892038,0.505652397328,0.509588061125,0.514533401326},//1800
     };
   }else if(isBpBp){
     SignalEff = {//BpBp
       {0.571316812194,0.619171502902,0.630177262656,0.627737226277,0.626867694393,0.618013835791,0.617155612245,0.608659906824,0.602723551637,0.581827568405,0.513856185474},//700
       {0.56095311299,0.593338687369,0.600969270688,0.612646526256,0.610678186233,0.604357469948,0.603506499514,0.605046246775,0.60640974039,0.594612794613,0.560510732791},//800
       {0.548879276445,0.581034389678,0.584898428517,0.586931469903,0.589491369265,0.59254437494,0.588772123894,0.592661357307,0.592802688153,0.59106195835,0.561016663861},//900
       {0.547583223622,0.57284685249,0.565508265001,0.56937906299,0.576081139624,0.576754260959,0.579974164486,0.577656675749,0.584525039421,0.585134161714,0.573134939595},//1000
       {0.548974943052,0.568378818275,0.554797677205,0.551012493421,0.561901412261,0.571771483437,0.572043275141,0.569514474102,0.570573119809,0.570439367311,0.567815446527},//1100
       {0.55310880829,0.572242739251,0.554384809571,0.541857309646,0.544279078025,0.554630501294,0.558544063629,0.555428379061,0.564449833532,0.562727458002,0.554459845157},//1200
       {0.56469176818,0.57223482865,0.548051014909,0.534453522429,0.537845303867,0.545478340531,0.547438298991,0.553319366693,0.548403882718,0.552726120034,0.550669982042},//1300
       {0.568780282284,0.573462226048,0.550106168108,0.535709634003,0.529150011313,0.532763829566,0.536680189317,0.544223052917,0.543148628234,0.545385605295,0.54225539007},//1400
       {0.579244292837,0.588145250446,0.560811257184,0.536458050133,0.529834280081,0.527700771954,0.531121154456,0.530227290479,0.535775453868,0.540290126345,0.535991338731},//1500
       {0.580073671286,0.594465965689,0.568110373734,0.537333522244,0.519657808518,0.51708428246,0.526542537387,0.52463645348,0.523932398819,0.529809574657,0.531768715457},//1600
       {0.580860776003,0.610442607513,0.57023916415,0.542696862664,0.528352424916,0.520626684979,0.510434546933,0.515005650663,0.52263745963,0.528273592569,0.525057904901},//1700
       {0.574163568773,0.603955619875,0.580538497874,0.544635740475,0.528828473864,0.514449860724,0.513044812769,0.511588627193,0.518700025793,0.516953639579,0.518698466277},//1800
     };
   }else if(isXX){
     SignalEff = {//X53X53
       {0.566925893031,0.62161641629,0.636941836178,0.650958411183,0.667353274822,0.678406537283,0.673695578038,0.680802103879,0.679591117378,0.668444309005,0.599083438685},
       {0.556511089944,0.605295894793,0.61837536724,0.636037070102,0.648640452845,0.650873774001,0.672515347602,0.67375,0.6882467475,0.684533057138,0.650487845213},
       {0.553287435456,0.586659453866,0.593620001254,0.613787074351,0.62753902074,0.64008952301,0.656196654148,0.662242523485,0.674528152762,0.684610075914,0.6714004914},
       {0.549337325525,0.576449316307,0.581686793268,0.598489343252,0.60872148289,0.625341698992,0.636303111004,0.645827296436,0.660045875028,0.67767976032,0.673147561748},
       {0.561883067578,0.581489701089,0.576142490191,0.578519696167,0.594028654443,0.608761914602,0.620171857604,0.634996067121,0.646388319672,0.660065578028,0.672348649353},
       {0.57100230571,0.593421732392,0.570766821075,0.569674380977,0.58276797829,0.598245991607,0.612715779926,0.622911101447,0.630220803405,0.645870517605,0.662805826167},
       {0.573128288142,0.597828356651,0.576185834958,0.565503219248,0.573957093595,0.585485320117,0.599905790915,0.612320053565,0.624193950622,0.635501989235,0.65247853407},
       {0.58307603242,0.600175691786,0.577511869005,0.563568052357,0.566398882291,0.575695291926,0.593158367676,0.608965754066,0.615377984656,0.627299437915,0.645537430388},
       {0.600553505535,0.612926972909,0.581568040525,0.570012802883,0.560987493909,0.569187695179,0.576118785958,0.594428895109,0.603938465798,0.61662817552,0.634043796568},
       {0.597950653903,0.622669198895,0.591802168022,0.578664029884,0.565150382963,0.562586983217,0.579468453546,0.579576783988,0.600145653487,0.611545682103,0.628881540129},
       {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0},//1700
       {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0},//1800
     };
   }
   float TTbarEff[11] = {0.681206254288,0.735941209916,0.707103097861,0.677917682843,0.658083687932,0.647541816212,0.643957428932,0.638267559481,0.623471882641,0.600233100233,0.562602515036};
   float STEff[11] = {0.714838184078,0.78439868981,0.765502997656,0.743723066601,0.730054061917,0.718778986424,0.712329743992,0.712565925247,0.706687402799,0.705987889661,0.690933538225};
   float WVEff[11] = {0.721890942821,0.790270329132,0.764814186734,0.727797290517,0.702466303413,0.665134285023,0.658878504673,0.627565982405,0.63355635615,0.597587719298,0.579212916246};

   // Top tagging efficiencies
   std::vector<float> ptRangeTpTpTop, ptRangeTTbarTop;
   float ptminTTbarTop[9] = {400,450,500,550,600,700,800,1000,1200};
   for (int i=0;i<9;++i) ptRangeTTbarTop.push_back(ptminTTbarTop[i]);
   float ptminTpTpTop[9] = {400,450,500,550,600,700,800,1000,1200};//X53X53
   for (int i=0;i<9;++i) ptRangeTpTpTop.push_back(ptminTpTpTop[i]);
   float TTbarEffTop[9] = {0.64208858919,0.821519027925,0.839975416553,0.82829058032,0.803050070173,0.765524749265,0.725845116909,0.692908561801,0.688736374647};
   float STEffTop[9] = {0.63705887773,0.83559444489,0.856893441192,0.852849740933,0.826657296791,0.787193318253,0.748102815177,0.730245231608,0.719262295082};

   float SignalEffTop[10][9] = {//X53X53
     {0.589018843405,0.749030140257,0.783639056625,0.799945265463,0.793082826672,0.782485374934,0.761915318111,0.713728549142,0.66},
     {0.562738731856,0.733780948384,0.760017497813,0.77619841192,0.772791782118,0.765164162493,0.762129122628,0.733503618561,0.697087378641},
     {0.552508911434,0.701517956312,0.737090883048,0.744680851064,0.751427560766,0.753888452474,0.752504173623,0.73694880892,0.685790884718},
     {0.527962777119,0.668169331549,0.71597359736,0.728841413311,0.730256452073,0.735716361523,0.734179425977,0.741627595445,0.729747675963},
     {0.499089776756,0.649914941877,0.685815868263,0.706903008364,0.712857647474,0.713546408549,0.715045165752,0.722279555097,0.720125130344},
     {0.491063029163,0.633738824564,0.662361276569,0.678767163651,0.68772290589,0.693537401338,0.703355750059,0.711434204041,0.710015582944},
     {0.477746158224,0.605132578694,0.633594653643,0.658764111705,0.67115790726,0.676241961699,0.688610182602,0.697609264102,0.690987545356},
     {0.461648280337,0.593832076591,0.621836537132,0.643556135461,0.65182875783,0.660159744409,0.665966188138,0.674362627106,0.685412382101},
     {0.443819393042,0.578952408312,0.601645377787,0.621383490596,0.63452642535,0.646748362048,0.657257057207,0.668398791541,0.682943750667},
     {0.434303568492,0.56420027522,0.594215600351,0.602773683505,0.617693430657,0.628969294412,0.643941371723,0.653109176953,0.665804469951},
   }; 

   // Pileup distributions -- ReReco Data vs Moriond17MC
   double pileup_central[75] = {3.603e-01, 9.378e-01, 1.201e+00, 9.651e-01, 1.112e+00, 1.162e+00, 7.847e-01, 4.960e-01, 7.422e-01, 8.839e-01, 9.662e-01, 1.071e+00, 1.124e+00, 1.175e+00, 1.203e+00, 1.208e+00, 1.200e+00, 1.182e+00, 1.144e+00, 1.096e+00, 1.065e+00, 1.051e+00, 1.052e+00, 1.051e+00, 1.050e+00, 1.057e+00, 1.072e+00, 1.083e+00, 1.095e+00, 1.108e+00, 1.094e+00, 1.084e+00, 1.042e+00, 9.850e-01, 9.095e-01, 8.196e-01, 7.159e-01, 6.107e-01, 5.032e-01, 4.052e-01, 3.092e-01, 2.285e-01, 1.636e-01, 1.133e-01, 7.738e-02, 5.090e-02, 3.180e-02, 2.013e-02, 1.226e-02, 7.425e-03, 4.389e-03, 2.614e-03, 1.572e-03, 9.679e-04, 7.333e-04, 6.786e-04, 7.342e-04, 9.346e-04, 1.346e-03, 1.888e-03, 3.248e-03, 3.966e-03, 4.872e-03, 5.119e-03, 5.452e-03, 5.338e-03, 5.112e-03, 4.397e-03, 4.023e-03, 3.359e-03, 2.987e-03, 2.770e-03, 2.278e-03, 1.982e-03, 1.765e-03};

   double pileup_down[75] = {3.733e-01, 1.197e+00, 1.263e+00, 1.102e+00, 1.240e+00, 1.278e+00, 9.076e-01, 7.680e-01, 1.093e+00, 1.345e+00, 1.489e+00, 1.526e+00, 1.496e+00, 1.500e+00, 1.498e+00, 1.445e+00, 1.367e+00, 1.298e+00, 1.228e+00, 1.165e+00, 1.125e+00, 1.091e+00, 1.065e+00, 1.041e+00, 1.019e+00, 1.005e+00, 9.973e-01, 9.851e-01, 9.722e-01, 9.567e-01, 9.141e-01, 8.732e-01, 8.075e-01, 7.337e-01, 6.501e-01, 5.605e-01, 4.658e-01, 3.750e-01, 2.886e-01, 2.147e-01, 1.498e-01, 1.001e-01, 6.433e-02, 3.962e-02, 2.392e-02, 1.382e-02, 7.544e-03, 4.163e-03, 2.215e-03, 1.187e-03, 6.441e-04, 3.850e-04, 2.739e-04, 2.425e-04, 2.913e-04, 3.993e-04, 5.467e-04, 7.711e-04, 1.143e-03, 1.598e-03, 2.706e-03, 3.234e-03, 3.878e-03, 3.973e-03, 4.121e-03, 3.928e-03, 3.659e-03, 3.059e-03, 2.719e-03, 2.203e-03, 1.901e-03, 1.709e-03, 1.362e-03, 1.147e-03, 9.884e-04};

   double pileup_up[75] = {3.510e-01, 7.384e-01, 1.136e+00, 8.481e-01, 1.011e+00, 1.047e+00, 7.158e-01, 3.479e-01, 5.006e-01, 6.065e-01, 6.335e-01, 7.320e-01, 8.266e-01, 9.118e-01, 9.603e-01, 9.892e-01, 1.024e+00, 1.052e+00, 1.051e+00, 1.027e+00, 1.005e+00, 9.982e-01, 1.015e+00, 1.038e+00, 1.058e+00, 1.085e+00, 1.121e+00, 1.155e+00, 1.192e+00, 1.232e+00, 1.245e+00, 1.269e+00, 1.260e+00, 1.233e+00, 1.180e+00, 1.103e+00, 1.001e+00, 8.905e-01, 7.691e-01, 6.545e-01, 5.326e-01, 4.236e-01, 3.297e-01, 2.501e-01, 1.888e-01, 1.381e-01, 9.654e-02, 6.875e-02, 4.733e-02, 3.248e-02, 2.175e-02, 1.456e-02, 9.619e-03, 6.146e-03, 4.301e-03, 3.097e-03, 2.253e-03, 1.894e-03, 2.009e-03, 2.389e-03, 3.847e-03, 4.626e-03, 5.722e-03, 6.110e-03, 6.639e-03, 6.646e-03, 6.514e-03, 5.738e-03, 5.381e-03, 4.607e-03, 4.204e-03, 4.003e-03, 3.382e-03, 3.025e-03, 2.770e-03};


  // ----------------------------------------------------------------------------
  // RUN THE EVENT LOOP
  // ----------------------------------------------------------------------------

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
     	     
      isElectron = 0;
      isMuon = 0;
      if(elPt_singleLepCalc->size()==0 && muPt_singleLepCalc->size()==0){std::cout << "got no leptons, something wrong" << std::endl; continue;}
      if(elPt_singleLepCalc->size()>0 && muPt_singleLepCalc->size()>0) std::cout << "got el and mu, something wrong" << std::endl;
      if(elPt_singleLepCalc->size()>1 && muPt_singleLepCalc->size()>1) std::cout << "got more than one el or mu, something wrong" << std::endl;
      if(elPt_singleLepCalc->size()>0 && muPt_singleLepCalc->size()==0) {isElectron = 1; isMuon = 0;}
      if(elPt_singleLepCalc->size()==0 && muPt_singleLepCalc->size()>0) {isElectron = 0; isMuon = 1;}
      if(isElectron==0 && isMuon==0){std::cout << "got no leptons, something wrong" << std::endl; continue;}

      if(isSM && isElectron == 1) continue;
      if(isSE && isMuon == 1) continue;

      double leppt = 0;
      double lepeta = 0;
      if(isElectron){leppt = elPt_singleLepCalc->at(0); lepeta = elEta_singleLepCalc->at(0);}
      if(isMuon){leppt = muPt_singleLepCalc->at(0); lepeta = muEta_singleLepCalc->at(0);}

      // ICHEP dataset: Endcap muons outside 500 GeV had to be rejected
      //if(isMuon && leppt > 500 && fabs(lepeta) > 1.2) continue;
      //npass_mu500 += 1.0;

      // ----------------------------------------------------------------------------
      // Pileup weight calculation
      // ----------------------------------------------------------------------------

      pileupWeight = 1.0;
      pileupWeightUp = 1.0;
      pileupWeightDown = 1.0;
	
      if(nTrueInteractions_singleLepCalc > 74) nTrueInteractions_singleLepCalc = 74;
      pileupWeight = pileup_central[nTrueInteractions_singleLepCalc];
      pileupWeightUp = pileup_down[nTrueInteractions_singleLepCalc];
      pileupWeightDown = pileup_up[nTrueInteractions_singleLepCalc];

      // ----------------------------------------------------------------------------
      // Assign Lepton scale factor or efficiency weights, save trigger pass/fail
      // ----------------------------------------------------------------------------

      TrigEffAltWeight = 1.0;
      TrigEffWeight = 1.0;
      TrigEffWeightUncert = 1.0;
      isoSF = 1.0;
      lepIdSF = 1.0;
      EGammaGsfSF = 1.0;
      MuTrkSF = 1.0;

      DataPastTrigger = 0;
      DataPastTriggerOR = 0;
      DataPastTriggerLepTight = 0;
      DataPastTriggerHTTight = 0;
      MCPastTrigger = 0;
      MCPastTriggerOR = 0;
      MCPastTriggerLepTight = 0;
      MCPastTriggerHTTight = 0;
      
      if(isMC){ //MC triggers check
	if(isElectron){
	  std::string string_a = "Ele15_IsoVVVL_PFHT400";
	  std::string string_b = "Ele15_IsoVVVL_PFHT350";
	  std::string string_ORa = "Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50";
	  std::string string_ORb = "Ele32_WPTight_Gsf";
	  std::string string_LEP = "Ele32_eta2p1_WPTight_Gsf";
	  std::string string_HT = "PFHT600";
	  for(unsigned int itrig=0; itrig < vsSelMCTriggersEl_singleLepCalc->size(); itrig++){
	    if(vsSelMCTriggersEl_singleLepCalc->at(itrig).find(string_a) != std::string::npos && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0){ MCPastTrigger = 1; MCPastTriggerOR = 1;}
	    if(vsSelMCTriggersEl_singleLepCalc->at(itrig).find(string_b) != std::string::npos && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0){ MCPastTrigger = 1; MCPastTriggerOR = 1;}
	    if(vsSelMCTriggersEl_singleLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) MCPastTriggerOR = 1;
	    if(vsSelMCTriggersEl_singleLepCalc->at(itrig).find(string_LEP) != std::string::npos && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) MCPastTriggerLepTight = 1;
	    if(vsSelMCTriggersEl_singleLepCalc->at(itrig).find(string_HT) != std::string::npos && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) MCPastTriggerHTTight = 1;
	  }

	  // Gsf Tracking scale factor: http://fcouderc.web.cern.ch/fcouderc/EGamma/scaleFactors/Moriond17/approval/RECO/passingRECO/egammaEffi.txt_egammaPlots.pdf
	  if(lepeta < -2.45) EGammaGsfSF = 1.318;
	  else if(lepeta < -2.4) EGammaGsfSF = 1.114;
	  else if(lepeta < -2.3) EGammaGsfSF = 1.025;
	  else if(lepeta < -2.2) EGammaGsfSF = 1.014;
	  else if(lepeta < -2.0) EGammaGsfSF = 1.007;
	  else if(lepeta < -1.8) EGammaGsfSF = 0.995;
	  else if(lepeta < -1.65) EGammaGsfSF = 0.995;
	  else if(lepeta < -1.566) EGammaGsfSF = 0.992;
	  else if(lepeta < -1.4442) EGammaGsfSF = 0.963;
	  else if(lepeta < -1.2) EGammaGsfSF = 0.990;
	  else if(lepeta < -1.0) EGammaGsfSF = 0.986;
	  else if(lepeta < -0.6) EGammaGsfSF = 0.982;
	  else if(lepeta < -0.4) EGammaGsfSF = 0.985;
	  else if(lepeta < -0.2) EGammaGsfSF = 0.982;
	  else if(lepeta < 0.0) EGammaGsfSF = 0.980;
	  else if(lepeta < 0.2) EGammaGsfSF = 0.985;
	  else if(lepeta < 0.4) EGammaGsfSF = 0.989;
	  else if(lepeta < 0.6) EGammaGsfSF = 0.988;
	  else if(lepeta < 1.0) EGammaGsfSF = 0.988;
	  else if(lepeta < 1.2) EGammaGsfSF = 0.988;
	  else if(lepeta < 1.4442) EGammaGsfSF = 0.988;
	  else if(lepeta < 1.566) EGammaGsfSF = 0.968;
	  else if(lepeta < 1.65) EGammaGsfSF = 0.990;
	  else if(lepeta < 1.8) EGammaGsfSF = 0.993;
	  else if(lepeta < 2.0) EGammaGsfSF = 0.992;
	  else if(lepeta < 2.2) EGammaGsfSF = 0.998;
	  else if(lepeta < 2.3) EGammaGsfSF = 1.001;
	  else if(lepeta < 2.4) EGammaGsfSF = 0.990;
	  else if(lepeta < 2.45) EGammaGsfSF = 0.971;
	  else EGammaGsfSF = 0.907;
	  
	  // Ele15_IsoVVVL_PFHT350 || Ele15_IsoVVVL_PFHT400 || Ele32_WPTight_Gsf -- 80X DATA EFFICIENCIES, Julie - 22Jan17
	  //RRB2G:
	  double TrigEffWeightR = 1.0;
	  double TrigEffWeightH = 1.0;
	  double TrigEffWeightRUncert = 1.0;
	  double TrigEffWeightHUncert = 1.0;
	  if(leppt < 60){
	    if(fabs(lepeta) < 0.8) {TrigEffWeightR = 0.964; TrigEffWeightRUncert = 0.049;} // 
	    else if(fabs(lepeta) < 1.442) {TrigEffWeightR = 0.966; TrigEffWeightRUncert = 0.057;}
	    else if(fabs(lepeta) < 1.566) {TrigEffWeightR = 1.000; TrigEffWeightRUncert = 0.000;}
	    else if(fabs(lepeta) < 2.0) {TrigEffWeightR = 0.902; TrigEffWeightRUncert = 0.072;}
	    else {TrigEffWeightR = 0.899; TrigEffWeightRUncert = 0.089;}
	  }else if(leppt < 70){
	    if(fabs(lepeta) < 0.8) {TrigEffWeightR = 0.958; TrigEffWeightRUncert = 0.050;} // 
	    else if(fabs(lepeta) < 1.442) {TrigEffWeightR = 0.968; TrigEffWeightRUncert = 0.062;}
	    else if(fabs(lepeta) < 1.566) {TrigEffWeightR = 1.000; TrigEffWeightRUncert = 0.000;}
	    else if(fabs(lepeta) < 2.0) {TrigEffWeightR = 0.869; TrigEffWeightRUncert = 0.078;}
	    else {TrigEffWeightR = 0.938; TrigEffWeightRUncert = 0.102;}
	  }else if(leppt < 100){
	    if(fabs(lepeta) < 0.8) {TrigEffWeightR = 0.968; TrigEffWeightRUncert = 0.033;} // 
	    else if(fabs(lepeta) < 1.442) {TrigEffWeightR = 0.965; TrigEffWeightRUncert = 0.039;}
	    else if(fabs(lepeta) < 1.566) {TrigEffWeightR = 1.000; TrigEffWeightRUncert = 0.000;}
	    else if(fabs(lepeta) < 2.0) {TrigEffWeightR = 0.938; TrigEffWeightRUncert = 0.053;}
	    else {TrigEffWeightR = 0.929; TrigEffWeightRUncert = 0.065;}
	  }else if(leppt < 200){
	    if(fabs(lepeta) < 0.8) {TrigEffWeightR = 0.974; TrigEffWeightRUncert = 0.022;} // 
	    else if(fabs(lepeta) < 1.442) {TrigEffWeightR = 0.973; TrigEffWeightRUncert = 0.028;}
	    else if(fabs(lepeta) < 1.566) {TrigEffWeightR = 1.000; TrigEffWeightRUncert = 0.000;}
	    else if(fabs(lepeta) < 2.0) {TrigEffWeightR = 0.922; TrigEffWeightRUncert = 0.038;}
	    else {TrigEffWeightR = 0.924; TrigEffWeightRUncert = 0.053;}
	  }else{
	    if(fabs(lepeta) < 0.8) {TrigEffWeightR = 0.964; TrigEffWeightRUncert = 0.025;} // 
	    else if(fabs(lepeta) < 1.442) {TrigEffWeightR = 0.969; TrigEffWeightRUncert = 0.034;}
	    else if(fabs(lepeta) < 1.566) {TrigEffWeightR = 1.000; TrigEffWeightRUncert = 0.000;}
	    else if(fabs(lepeta) < 2.0) {TrigEffWeightR = 0.932; TrigEffWeightRUncert = 0.044;}
	    else {TrigEffWeightR = 0.954; TrigEffWeightRUncert = 0.064;}
	  }
	  //PRH:
	  if(leppt < 60){
	    if(fabs(lepeta) < 0.8) {TrigEffWeightH = 0.956; TrigEffWeightHUncert = 0.091;} // 
	    else if(fabs(lepeta) < 1.442) {TrigEffWeightH = 0.972; TrigEffWeightHUncert = 0.103;}
	    else if(fabs(lepeta) < 1.566) {TrigEffWeightH = 1.000; TrigEffWeightHUncert = 0.000;}
	    else if(fabs(lepeta) < 2.0) {TrigEffWeightH = 0.888; TrigEffWeightHUncert = 0.131;}
	    else {TrigEffWeightH = 0.898; TrigEffWeightHUncert = 0.170;}
	  }else if(leppt < 70){
	    if(fabs(lepeta) < 0.8) {TrigEffWeightH = 0.974; TrigEffWeightHUncert = 0.090;} // 
	    else if(fabs(lepeta) < 1.442) {TrigEffWeightH = 0.947; TrigEffWeightHUncert = 0.104;}
	    else if(fabs(lepeta) < 1.566) {TrigEffWeightH = 1.000; TrigEffWeightHUncert = 0.000;}
	    else if(fabs(lepeta) < 2.0) {TrigEffWeightH = 0.890; TrigEffWeightHUncert = 0.143;}
	    else {TrigEffWeightH = 0.836; TrigEffWeightHUncert = 0.167;}
	  }else if(leppt < 100){
	    if(fabs(lepeta) < 0.8) {TrigEffWeightH = 0.992; TrigEffWeightHUncert = 0.058;} // 
	    else if(fabs(lepeta) < 1.442) {TrigEffWeightH = 0.972; TrigEffWeightHUncert = 0.067;}
	    else if(fabs(lepeta) < 1.566) {TrigEffWeightH = 1.000; TrigEffWeightHUncert = 0.000;}
	    else if(fabs(lepeta) < 2.0) {TrigEffWeightH = 0.877; TrigEffWeightHUncert = 0.088;}
	    else {TrigEffWeightH = 0.928; TrigEffWeightHUncert = 0.120;}
	  }else if(leppt < 200){
	    if(fabs(lepeta) < 0.8) {TrigEffWeightH = 0.984; TrigEffWeightHUncert = 0.041;} // 
	    else if(fabs(lepeta) < 1.442) {TrigEffWeightH = 0.974; TrigEffWeightHUncert = 0.049;}
	    else if(fabs(lepeta) < 1.566) {TrigEffWeightH = 1.000; TrigEffWeightHUncert = 0.000;}
	    else if(fabs(lepeta) < 2.0) {TrigEffWeightH = 0.944; TrigEffWeightHUncert = 0.073;}
	    else {TrigEffWeightH = 0.884; TrigEffWeightHUncert = 0.092;}
	  }else{
	    if(fabs(lepeta) < 0.8) {TrigEffWeightH = 0.970; TrigEffWeightHUncert = 0.048;} // 
	    else if(fabs(lepeta) < 1.442) {TrigEffWeightH = 0.983; TrigEffWeightHUncert = 0.070;}
	    else if(fabs(lepeta) < 1.566) {TrigEffWeightH = 1.000; TrigEffWeightHUncert = 0.000;}
	    else if(fabs(lepeta) < 2.0) {TrigEffWeightH = 0.938; TrigEffWeightHUncert = 0.093;}
	    else {TrigEffWeightH = 0.847; TrigEffWeightHUncert = 0.147;}
	  }

	  TrigEffWeight = (27.957*TrigEffWeightR + 8.857*TrigEffWeightH)/36.814;
	  TrigEffWeightUncert = sqrt(pow(27.957*TrigEffWeightRUncert,2) + pow(8.857*TrigEffWeightHUncert,2))/36.814;

	  //miniIso < 0.1 scale factors -- Moriond17 -- from Julie - 22Jan17
	  if(fabs(lepeta) < 0.8){
	    if(leppt < 30) isoSF = 0.999;
	    else if(leppt < 40) isoSF = 0.999;
	    else if(leppt < 50) isoSF = 0.999;
	    else if(leppt < 60) isoSF = 0.998;
	    else if(leppt < 100) isoSF = 0.999;
	    else if(leppt < 200) isoSF = 1.002;
	    else isoSF = 1.001;
	  }
	  else if(fabs(lepeta) < 1.4442){
	    if(leppt < 30) isoSF = 1.005;
	    else if(leppt < 40) isoSF = 1.000;
	    else if(leppt < 50) isoSF = 1.000;
	    else if(leppt < 60) isoSF = 1.000;
	    else if(leppt < 100) isoSF = 1.000;
	    else if(leppt < 200) isoSF = 1.002;
	    else isoSF = 0.999;
	  }
	  else if(fabs(lepeta) < 1.566){
	    if(leppt < 30) isoSF = 1.000;
	    else if(leppt < 40) isoSF = 1.000;
	    else if(leppt < 50) isoSF = 1.000;
	    else if(leppt < 60) isoSF = 1.000;
	    else if(leppt < 100) isoSF = 1.000;
	    else if(leppt < 200) isoSF = 1.000;
	    else isoSF = 1.000;
	  }
	  else if(fabs(lepeta) < 2.0){
	    if(leppt < 30) isoSF = 0.992;
	    else if(leppt < 40) isoSF = 0.998;
	    else if(leppt < 50) isoSF = 0.997;
	    else if(leppt < 60) isoSF = 0.999;
	    else if(leppt < 100) isoSF = 0.999;
	    else if(leppt < 200) isoSF = 1.000;
	    else isoSF = 0.998;
	  }
	  else {
	    if(leppt < 30) isoSF = 0.978;
	    else if(leppt < 40) isoSF = 0.987;
	    else if(leppt < 50) isoSF = 0.993;
	    else if(leppt < 60) isoSF = 0.998;
	    else if(leppt < 100) isoSF = 1.001;
	    else if(leppt < 200) isoSF = 1.000;
	    else isoSF = 0.997;
	  }
	  
	  //MVA-based ID scale factors for 80X-trained MVA -- Moriond17 -- from Julie - 22Jan17
	  if(fabs(lepeta) < 0.8){
	    if(leppt < 30) lepIdSF = 0.965;
	    else if(leppt < 40) lepIdSF = 0.971;
	    else if(leppt < 50) lepIdSF = 0.973;
	    else if(leppt < 60) lepIdSF = 0.973;
	    else if(leppt < 100) lepIdSF = 0.977;
	    else if(leppt < 200) lepIdSF = 0.985;
	    else lepIdSF = 0.985;
	  }
	  else if(fabs(lepeta) < 1.4442){
	    if(leppt < 30) lepIdSF = 0.935;
	    else if(leppt < 40) lepIdSF = 0.947;
	    else if(leppt < 50) lepIdSF = 0.952;
	    else if(leppt < 60) lepIdSF = 0.951;
	    else if(leppt < 100) lepIdSF = 0.956;
	    else if(leppt < 200) lepIdSF = 0.974;
	    else lepIdSF = 0.942;
	  }
	  else if(fabs(lepeta) < 1.566){
	    if(leppt < 30) lepIdSF = 1.000;
	    else if(leppt < 40) lepIdSF = 1.000;
	    else if(leppt < 50) lepIdSF = 1.000;
	    else if(leppt < 60) lepIdSF = 1.000;
	    else if(leppt < 100) lepIdSF = 1.000;
	    else if(leppt < 200) lepIdSF = 1.000;
	    else lepIdSF = 1.000;
	  }
	  else if(fabs(lepeta) < 2.0){
	    if(leppt < 30) lepIdSF = 0.935;
	    else if(leppt < 40) lepIdSF = 0.947;
	    else if(leppt < 50) lepIdSF = 0.965;
	    else if(leppt < 60) lepIdSF = 0.970;
	    else if(leppt < 100) lepIdSF = 0.971;
	    else if(leppt < 200) lepIdSF = 0.992;
	    else lepIdSF = 1.010;
	  }
	  else {
	    if(leppt < 30) lepIdSF = 0.947;
	    else if(leppt < 40) lepIdSF = 0.963;
	    else if(leppt < 50) lepIdSF = 0.970;
	    else if(leppt < 60) lepIdSF = 0.973;
	    else if(leppt < 100) lepIdSF = 0.978;
	    else if(leppt < 200) lepIdSF = 1.013;
	    else lepIdSF = 0.971;
	  }	  
	}
	if(isMuon){
	  std::string string_a = "Mu15_IsoVVVL_PFHT400";
	  std::string string_b = "Mu15_IsoVVVL_PFHT350";
	  std::string string_ORa = "Mu40_eta2p1_PFJet200_PFJet50";
	  std::string string_ORb = "Mu50";
	  std::string string_ORc = "TkMu50";
	  std::string string_LEPa = "IsoMu24";
	  std::string string_LEPb = "IsoTkMu24";
	  std::string string_HT = "PFHT600";
	  for(unsigned int itrig=0; itrig < vsSelMCTriggersMu_singleLepCalc->size(); itrig++){
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_a) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0){ MCPastTrigger = 1; MCPastTriggerOR = 1;}
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_b) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0){ MCPastTrigger = 1; MCPastTriggerOR = 1;}
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTriggerOR = 1;
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_ORc) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTriggerOR = 1;
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_LEPa) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTriggerLepTight = 1;
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_LEPb) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTriggerLepTight = 1;
	    if(vsSelMCTriggersMu_singleLepCalc->at(itrig).find(string_HT) != std::string::npos && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) MCPastTriggerHTTight = 1;
	  }
	  
	  // Muon tracking SF -- NOT TO BE USED, calculate in case
	  int ebin = -1;
	  if(leptonEta_singleLepCalc < -2.1) ebin = 0;
	  else if(leptonEta_singleLepCalc < -1.6) ebin = 1;
	  else if(leptonEta_singleLepCalc < -1.1) ebin = 2;
	  else if(leptonEta_singleLepCalc < -0.6) ebin = 3;
	  else if(leptonEta_singleLepCalc <  0.0) ebin = 4;
	  else if(leptonEta_singleLepCalc <  0.6) ebin = 5;
	  else if(leptonEta_singleLepCalc <  1.1) ebin = 6;
	  else if(leptonEta_singleLepCalc <  1.6) ebin = 7;
	  else if(leptonEta_singleLepCalc <  2.1) ebin = 8;
	  else if(leptonEta_singleLepCalc <  2.4) ebin = 9;

	  MuTrkSF = tracksf[ebin];

	  // Mu15_IsoVVVL_PFHT350 || Mu15_IsoVVVL_PFHT400 || Mu50 || TkMu50 -- 80X DATA EFFICIENCIES, Julie - 22Jan17
	  //RRB2G:
	  double TrigEffWeightR = 1.0;
	  double TrigEffWeightH = 1.0;
	  double TrigEffWeightRUncert = 1.0;
	  double TrigEffWeightHUncert = 1.0;
	  if(leppt < 60){
	    if(fabs(lepeta) < 0.9) {TrigEffWeightR = 0.963; TrigEffWeightRUncert = 0.038;} // 
	    else if(fabs(lepeta) < 1.2) {TrigEffWeightR = 0.969; TrigEffWeightRUncert = 0.070;}
	    else if(fabs(lepeta) < 2.1) {TrigEffWeightR = 0.982; TrigEffWeightRUncert = 0.047;}
	    else {TrigEffWeightR = 0.954; TrigEffWeightRUncert = 0.104;}
	  }else if(leppt < 70){
	    if(fabs(lepeta) < 0.9) {TrigEffWeightR = 0.958; TrigEffWeightRUncert = 0.039;} // 
	    else if(fabs(lepeta) < 1.2) {TrigEffWeightR = 0.973; TrigEffWeightRUncert = 0.076;}
	    else if(fabs(lepeta) < 2.1) {TrigEffWeightR = 0.991; TrigEffWeightRUncert = 0.052;}
	    else {TrigEffWeightR = 0.971; TrigEffWeightRUncert = 0.119;}
	  }else if(leppt < 100){
	    if(fabs(lepeta) < 0.9) {TrigEffWeightR = 0.956; TrigEffWeightRUncert = 0.025;} // 
	    else if(fabs(lepeta) < 1.2) {TrigEffWeightR = 0.971; TrigEffWeightRUncert = 0.048;}
	    else if(fabs(lepeta) < 2.1) {TrigEffWeightR = 0.983; TrigEffWeightRUncert = 0.034;}
	    else {TrigEffWeightR = 0.983; TrigEffWeightRUncert = 0.080;}
	  }else if(leppt < 200){
	    if(fabs(lepeta) < 0.9) {TrigEffWeightR = 0.960; TrigEffWeightRUncert = 0.019;} // 
	    else if(fabs(lepeta) < 1.2) {TrigEffWeightR = 0.971; TrigEffWeightRUncert = 0.037;}
	    else if(fabs(lepeta) < 2.1) {TrigEffWeightR = 0.986; TrigEffWeightRUncert = 0.026;}
	    else {TrigEffWeightR = 0.958; TrigEffWeightRUncert = 0.068;}
	  }else{
	    if(fabs(lepeta) < 0.9) {TrigEffWeightR = 0.950; TrigEffWeightRUncert = 0.024;} // 
	    else if(fabs(lepeta) < 1.2) {TrigEffWeightR = 0.970; TrigEffWeightRUncert = 0.051;}
	    else if(fabs(lepeta) < 2.1) {TrigEffWeightR = 0.985; TrigEffWeightRUncert = 0.041;}
	    else {TrigEffWeightR = 0.936; TrigEffWeightRUncert = 0.129;}
	  }

	  //PRH:
	  if(leppt < 60){
	    if(fabs(lepeta) < 0.9) {TrigEffWeightH = 0.979; TrigEffWeightHUncert = 0.064;} // 
	    else if(fabs(lepeta) < 1.2) {TrigEffWeightH = 0.993; TrigEffWeightHUncert = 0.119;}
	    else if(fabs(lepeta) < 2.1) {TrigEffWeightH = 0.965; TrigEffWeightHUncert = 0.081;}
	    else {TrigEffWeightH = 0.954; TrigEffWeightHUncert = 0.169;}
	  }else if(leppt < 70){
	    if(fabs(lepeta) < 0.9) {TrigEffWeightH = 0.969; TrigEffWeightHUncert = 0.070;} // 
	    else if(fabs(lepeta) < 1.2) {TrigEffWeightH = 0.990; TrigEffWeightHUncert = 0.138;}
	    else if(fabs(lepeta) < 2.1) {TrigEffWeightH = 0.973; TrigEffWeightHUncert = 0.086;}
	    else {TrigEffWeightH = 0.963; TrigEffWeightHUncert = 0.187;}
	  }else if(leppt < 100){
	    if(fabs(lepeta) < 0.9) {TrigEffWeightH = 0.958; TrigEffWeightHUncert = 0.043;} // 
	    else if(fabs(lepeta) < 1.2) {TrigEffWeightH = 0.986; TrigEffWeightHUncert = 0.083;}
	    else if(fabs(lepeta) < 2.1) {TrigEffWeightH = 0.976; TrigEffWeightHUncert = 0.058;}
	    else {TrigEffWeightH = 0.981; TrigEffWeightHUncert = 0.134;}
	  }else if(leppt < 200){
	    if(fabs(lepeta) < 0.9) {TrigEffWeightH = 0.965; TrigEffWeightHUncert = 0.032;} // 
	    else if(fabs(lepeta) < 1.2) {TrigEffWeightH = 0.977; TrigEffWeightHUncert = 0.063;}
	    else if(fabs(lepeta) < 2.1) {TrigEffWeightH = 0.974; TrigEffWeightHUncert = 0.046;}
	    else {TrigEffWeightH = 0.986; TrigEffWeightHUncert = 0.118;}
	  }else{
	    if(fabs(lepeta) < 0.9) {TrigEffWeightH = 0.963; TrigEffWeightHUncert = 0.045;} // 
	    else if(fabs(lepeta) < 1.2) {TrigEffWeightH = 0.987; TrigEffWeightHUncert = 0.091;}
	    else if(fabs(lepeta) < 2.1) {TrigEffWeightH = 0.966; TrigEffWeightHUncert = 0.073;}
	    else {TrigEffWeightH = 0.967; TrigEffWeightHUncert = 0.252;}
	  }

	  TrigEffWeight = (27.957*TrigEffWeightR + 8.857*TrigEffWeightH)/36.814;
	  TrigEffWeightUncert = sqrt(pow(27.957*TrigEffWeightRUncert,2) + pow(8.857*TrigEffWeightHUncert,2))/36.814;
	  
	  //Mini-iso < 0.1 scale factors for ReReco B-H / Spring16MC from Clint's Jan 18th talk: https://indico.cern.ch/event/605620/                                                                                                              
	  if(leppt < 40){
	    if(fabs(lepeta) < 0.9) isoSF= 0.999708;
	    else if(fabs(lepeta) <  1.2) isoSF= 0.999764;
	    else if(fabs(lepeta) <  2.1) isoSF= 0.999537;
	    else if(fabs(lepeta) <  2.4) isoSF= 0.999363;
	  }
	  else if(leppt < 50){
	    if(fabs(lepeta) < 0.9) isoSF= 0.998914;
	    else if(fabs(lepeta) <  1.2) isoSF= 0.999142;
	    else if(fabs(lepeta) <  2.1) isoSF= 0.999084;
	    else if(fabs(lepeta) <  2.4) isoSF= 0.999475;
	  }
	  else if(leppt < 60){
	    if(fabs(lepeta) < 0.9) isoSF= 0.999181;
	    else if(fabs(lepeta) <  1.2) isoSF= 0.999393;
	    else if(fabs(lepeta) <  2.1) isoSF= 0.999276;
	    else if(fabs(lepeta) <  2.4) isoSF= 0.999611;
	  }
	  else if(leppt < 100){
	    if(fabs(lepeta) < 0.9) isoSF= 0.999594;
	    else if(fabs(lepeta) <  1.2) isoSF= 0.999992;
	    else if(fabs(lepeta) <  2.1) isoSF= 0.999704;
	    else if(fabs(lepeta) <  2.4) isoSF= 0.99999;
	  }
	  else{
	    if(fabs(lepeta) < 0.9) isoSF= 1.00003;
	    else if(fabs(lepeta) <  1.2) isoSF= 0.999797;
	    else if(fabs(lepeta) <  2.1) isoSF= 0.99981;
	    else if(fabs(lepeta) <  2.4) isoSF= 0.999982;
	  }
	  
	  //Cut-based Tight scale factors for ReReco B-H / Moriond17MC from Clint's Jan 18th talk: https://indico.cern.ch/event/605620/                                                                                                            
	  if(fabs(lepeta) < 0.9){
	    if(leppt < 40) lepIdSF = 0.983;
	    else if(leppt < 50) lepIdSF = 0.971;
	    else if(leppt < 60) lepIdSF = 0.987;
	    else if(leppt < 100) lepIdSF = 0.932;
	    else lepIdSF = 0.966;
	  }
	  else if(fabs(lepeta) < 1.2){
	    if(leppt < 40) lepIdSF = 0.948;
	    else if(leppt < 50) lepIdSF = 0.950;
	    else if(leppt < 60) lepIdSF = 0.950;
	    else if(leppt < 100) lepIdSF = 0.938;
	    else lepIdSF = 0.962;
	  }
	  else if(fabs(lepeta) < 2.1){
	    if(leppt < 40) lepIdSF = 0.975;
	    else if(leppt < 50) lepIdSF = 0.976;
	    else if(leppt < 60) lepIdSF = 0.972;
	    else if(leppt < 100) lepIdSF = 0.958;
	    else lepIdSF = 0.987;
	  }
	  else {
	    if(leppt < 40) lepIdSF = 0.945;
	    else if(leppt < 50) lepIdSF = 0.944;
	    else if(leppt < 60) lepIdSF = 0.939;
	    else if(leppt < 100) lepIdSF = 0.926;
	    else lepIdSF = 0.944;
	  }	
	}
	DataPastTrigger = 1;
	DataPastTriggerOR = 1;
	DataPastTriggerLepTight = 1;
	DataPastTriggerHTTight = 1;
      }
      else{ //Data triggers check
	if(isElectron){
	  std::string string_a = "Ele15_IsoVVVL_PFHT400";
	  std::string string_b = "Ele15_IsoVVVL_PFHT350";
	  std::string string_ORa = "Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50";
	  std::string string_ORb = "Ele32_WPTight_Gsf";
	  std::string string_LEP = "Ele32_eta2p1_WPTight_Gsf";
	  std::string string_HT = "PFHT600";
	  for(unsigned int itrig=0; itrig < vsSelTriggersEl_singleLepCalc->size(); itrig++){
	    if(vsSelTriggersEl_singleLepCalc->at(itrig).find(string_a) != std::string::npos && viSelTriggersEl_singleLepCalc->at(itrig) > 0){ DataPastTrigger = 1; DataPastTriggerOR = 1;}
	    if(vsSelTriggersEl_singleLepCalc->at(itrig).find(string_b) != std::string::npos && viSelTriggersEl_singleLepCalc->at(itrig) > 0){ DataPastTrigger = 1; DataPastTriggerOR = 1;}
	    if(vsSelTriggersEl_singleLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelTriggersEl_singleLepCalc->at(itrig) > 0) DataPastTriggerOR = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig).find(string_LEP) != std::string::npos && viSelTriggersEl_singleLepCalc->at(itrig) > 0) DataPastTriggerLepTight = 1;
	    if(vsSelTriggersEl_singleLepCalc->at(itrig).find(string_HT) != std::string::npos && viSelTriggersEl_singleLepCalc->at(itrig) > 0) DataPastTriggerHTTight = 1;
	  }
	}
	if(isMuon){
	  std::string string_a = "Mu15_IsoVVVL_PFHT400";
	  std::string string_b = "Mu15_IsoVVVL_PFHT350";
	  std::string string_ORa = "Mu40_eta2p1_PFJet200_PFJet50";
	  std::string string_ORb = "Mu50";
	  std::string string_ORc = "TkMu50";
	  std::string string_LEPa = "IsoMu24";
	  std::string string_LEPb = "IsoTkMu24";
	  std::string string_HT = "PFHT600";
	  for(unsigned int itrig=0; itrig < vsSelTriggersMu_singleLepCalc->size(); itrig++){
	    if(vsSelTriggersMu_singleLepCalc->at(itrig).find(string_a) != std::string::npos && viSelTriggersMu_singleLepCalc->at(itrig) > 0){ DataPastTrigger = 1; DataPastTriggerOR = 1;}
	    if(vsSelTriggersMu_singleLepCalc->at(itrig).find(string_b) != std::string::npos && viSelTriggersMu_singleLepCalc->at(itrig) > 0){ DataPastTrigger = 1; DataPastTriggerOR = 1;}
	    if(vsSelTriggersMu_singleLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelTriggersMu_singleLepCalc->at(itrig) > 0) DataPastTriggerOR = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig).find(string_ORc) != std::string::npos && viSelTriggersMu_singleLepCalc->at(itrig) > 0) DataPastTriggerOR = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig).find(string_LEPa) != std::string::npos && viSelTriggersMu_singleLepCalc->at(itrig) > 0) DataPastTriggerLepTight = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig).find(string_LEPb) != std::string::npos && viSelTriggersMu_singleLepCalc->at(itrig) > 0) DataPastTriggerLepTight = 1;
	    if(vsSelTriggersMu_singleLepCalc->at(itrig).find(string_HT) != std::string::npos && viSelTriggersMu_singleLepCalc->at(itrig) > 0) DataPastTriggerHTTight = 1;
	  }
	}
	MCPastTrigger = 1;
	MCPastTriggerOR = 1;
	MCPastTriggerLepTight = 1;
	MCPastTriggerHTTight = 1;
      }
      
      if(DataPastTrigger) npass_trigger+=1;

      // ----------------------------------------------------------------------------
      // Loop over AK4 jets for calculations and pt ordering pair
      // ----------------------------------------------------------------------------

      NJets_JetSubCalc = 0;
      AK4HT = 0;
      vector<pair<double,int>> jetptindpair;
      JetSF_pTNbwflat = 1.0;
      JetSFup_pTNbwflat = 1.0;
      JetSFdn_pTNbwflat = 1.0;
      JetSFupwide_pTNbwflat = 1.0;
      JetSFdnwide_pTNbwflat = 1.0;
      JetSF_80X = 1.0;
      JetSFup_80X = 1.0;
      JetSFdn_80X = 1.0;

      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc->size(); ijet++){

	// ----------------------------------------------------------------------------
	// Basic cuts
	// ----------------------------------------------------------------------------

	if(theJetPt_JetSubCalc->at(ijet) < jetPtCut || fabs(theJetEta_JetSubCalc->at(ijet)) > jetEtaCut) continue;

	if(isMC){

	  // ----------------------------------------------------------------------------
	  // Jet Scale factor
	  // ----------------------------------------------------------------------------

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
	    jetsf = 1.09502 - 0.00045995*jetpt;
	    jetsferr = sqrt(2.41563501145e-05 + 3.64859173927e-10*jetpt*jetpt + 2*jetpt*(-8.66909413702e-08));
	    if(jetpt < 801.75){
	      JetSF_80X *= min(one,jetsf);
	      JetSFup_80X *= min(one,max(jetsf+jetsferr,float(0.726255+0.0190384)));
	      JetSFdn_80X *= min(one,max(jetsf-jetsferr,float(0.726255-0.0190384)));
	    }else{
	      JetSF_80X *= 0.726255;
	      JetSFup_80X *= min(one,max(jetsf+jetsferr,float(0.726255+0.0190384)));
	      JetSFdn_80X *= min(one,max(jetsf-jetsferr,float(0.726255-0.0190384)));
	    }
	  }

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
      
      NJetsH1btagged = 0;
      int NJetsH1btagged_bSFup = 0;
      int NJetsH1btagged_bSFdn = 0;
      int NJetsH1btagged_lSFup = 0;
      int NJetsH1btagged_lSFdn = 0;
      int NJetsH1btagged_JMSup = 0;
      int NJetsH1btagged_JMSdn = 0;
      int NJetsH1btagged_JMRup = 0;
      int NJetsH1btagged_JMRdn = 0;
      NJetsH2btagged = 0;
      int NJetsH2btagged_bSFup = 0;
      int NJetsH2btagged_bSFdn = 0;
      int NJetsH2btagged_lSFup = 0;
      int NJetsH2btagged_lSFdn = 0;
      int NJetsH2btagged_JMSup = 0;
      int NJetsH2btagged_JMSdn = 0;
      int NJetsH2btagged_JMRup = 0;
      int NJetsH2btagged_JMRdn = 0;
      NJetsAK8_JetSubCalc = 0;
      vector<float> maxsubcsv;
      NJetsH1btagged_shifts.clear();
      NJetsH2btagged_shifts.clear();
      vector<pair<double,int>> jetak8ptindpair;
      
      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc->size(); ijet++){
	
        // ----------------------------------------------------------------------------                                  
        // Basic cuts                                                                                                    
        // ----------------------------------------------------------------------------                                  
	
        maxsubcsv.push_back(-99.0);
        if(fabs(theJetAK8Eta_JetSubCalc->at(ijet)) > ak8EtaCut) continue;
        if(theJetAK8NjettinessTau1_JetSubCalc->at(ijet)==0) continue;
        if(theJetAK8NjettinessTau2_JetSubCalc->at(ijet)==0) continue;
	
        // ----------------------------------------------------------------------------                                  
        // Counter and pt ordering pair                                                                                  
        // ----------------------------------------------------------------------------                                  
	
        NJetsAK8_JetSubCalc += 1;
        jetak8ptindpair.push_back(std::make_pair(theJetAK8Pt_JetSubCalc->at(ijet),ijet));
	
        // ----------------------------------------------------------------------------                                  
        // Count Higgs tags                                                                                              
        // ----------------------------------------------------------------------------                                  
	
        int firstsub = theJetAK8SDSubjetIndex_JetSubCalc->at(ijet);
        int nsubs = theJetAK8SDSubjetSize_JetSubCalc->at(ijet);
        double maxCSVsubjet = 0;
        int NsubCSVM = 0;
        for(int isub = firstsub; isub < firstsub + nsubs; isub++){
          if(theJetAK8SDSubjetCSV_JetSubCalc->at(isub) > maxCSVsubjet) maxCSVsubjet = theJetAK8SDSubjetCSV_JetSubCalc->at(isub);
          if(theJetAK8SDSubjetCSV_JetSubCalc->at(isub) > 0.8484) NsubCSVM += 1;
          if(isub != firstsub && theJetAK8SDSubjetPt_JetSubCalc->at(isub) == theJetAK8SDSubjetPt_JetSubCalc->at(firstsub)) cout << "subjets have matching pT, something's wrong" << endl;
        }
        maxsubcsv.at(ijet) = maxCSVsubjet;
        double sdmass = theJetAK8SoftDropMassWtagUncerts_JetSubCalc->at(ijet);
        double sdmass_JMSup = theJetAK8SoftDropMassWtagUncerts_JMSup_JetSubCalc->at(ijet);
        double sdmass_JMSdn = theJetAK8SoftDropMassWtagUncerts_JMSdn_JetSubCalc->at(ijet);
        double sdmass_JMRup = theJetAK8SoftDropMassWtagUncerts_JMRup_JetSubCalc->at(ijet);
        double sdmass_JMRdn = theJetAK8SoftDropMassWtagUncerts_JMRdn_JetSubCalc->at(ijet);
        double pt = theJetAK8Pt_JetSubCalc->at(ijet);
        if(pt > 300 && sdmass > 60 && sdmass < 160){
          //if(NsubCSVM == 1) NJetsH1btagged += 1;
          if(theJetAK8SDSubjetNCSVMSF_JetSubCalc->at(ijet) == 1) NJetsH1btagged += 1;                                  
          if(theJetAK8SDSubjetNCSVM_bSFup_JetSubCalc->at(ijet) == 1) NJetsH1btagged_bSFup += 1;
          if(theJetAK8SDSubjetNCSVM_bSFdn_JetSubCalc->at(ijet) == 1) NJetsH1btagged_bSFdn += 1;
          if(theJetAK8SDSubjetNCSVM_lSFup_JetSubCalc->at(ijet) == 1) NJetsH1btagged_lSFup += 1;
          if(theJetAK8SDSubjetNCSVM_lSFdn_JetSubCalc->at(ijet) == 1) NJetsH1btagged_lSFdn += 1;
          //if(NsubCSVM > 1) NJetsH2btagged += 1;
          if(theJetAK8SDSubjetNCSVMSF_JetSubCalc->at(ijet) > 1) NJetsH2btagged += 1;                                   
          if(theJetAK8SDSubjetNCSVM_bSFup_JetSubCalc->at(ijet) > 1) NJetsH2btagged_bSFup += 1;
          if(theJetAK8SDSubjetNCSVM_bSFdn_JetSubCalc->at(ijet) > 1) NJetsH2btagged_bSFdn += 1;
          if(theJetAK8SDSubjetNCSVM_lSFup_JetSubCalc->at(ijet) > 1) NJetsH2btagged_lSFup += 1;
          if(theJetAK8SDSubjetNCSVM_lSFdn_JetSubCalc->at(ijet) > 1) NJetsH2btagged_lSFdn += 1;
	}
	if(pt > 300 && theJetAK8SDSubjetNCSVMSF_JetSubCalc->at(ijet) == 1 && sdmass_JMSup > 60 && sdmass_JMSup < 160) NJetsH1btagged_JMSup += 1;
	if(pt > 300 && theJetAK8SDSubjetNCSVMSF_JetSubCalc->at(ijet) == 1 && sdmass_JMSdn > 60 && sdmass_JMSdn < 160) NJetsH1btagged_JMSdn += 1;
	if(pt > 300 && theJetAK8SDSubjetNCSVMSF_JetSubCalc->at(ijet) == 1 && sdmass_JMRup > 60 && sdmass_JMRup < 160) NJetsH1btagged_JMRup += 1;
	if(pt > 300 && theJetAK8SDSubjetNCSVMSF_JetSubCalc->at(ijet) == 1 && sdmass_JMRdn > 60 && sdmass_JMRdn < 160) NJetsH1btagged_JMRdn += 1;
	if(pt > 300 && theJetAK8SDSubjetNCSVMSF_JetSubCalc->at(ijet) > 1 && sdmass_JMSup > 60 && sdmass_JMSup < 160) NJetsH2btagged_JMSup += 1;
	if(pt > 300 && theJetAK8SDSubjetNCSVMSF_JetSubCalc->at(ijet) > 1 && sdmass_JMSdn > 60 && sdmass_JMSdn < 160) NJetsH2btagged_JMSdn += 1;
	if(pt > 300 && theJetAK8SDSubjetNCSVMSF_JetSubCalc->at(ijet) > 1 && sdmass_JMRup > 60 && sdmass_JMRup < 160) NJetsH2btagged_JMRup += 1;
	if(pt > 300 && theJetAK8SDSubjetNCSVMSF_JetSubCalc->at(ijet) > 1 && sdmass_JMRdn > 60 && sdmass_JMRdn < 160) NJetsH2btagged_JMRdn += 1;
      }
      NJetsH1btagged_shifts.push_back(NJetsH1btagged_bSFup);
      NJetsH1btagged_shifts.push_back(NJetsH1btagged_bSFdn);
      NJetsH1btagged_shifts.push_back(NJetsH1btagged_lSFup);
      NJetsH1btagged_shifts.push_back(NJetsH1btagged_lSFdn);
      NJetsH1btagged_shifts.push_back(NJetsH1btagged_JMSup);
      NJetsH1btagged_shifts.push_back(NJetsH1btagged_JMSdn);
      NJetsH1btagged_shifts.push_back(NJetsH1btagged_JMRup);
      NJetsH1btagged_shifts.push_back(NJetsH1btagged_JMRdn);
      NJetsH2btagged_shifts.push_back(NJetsH2btagged_bSFup);
      NJetsH2btagged_shifts.push_back(NJetsH2btagged_bSFdn);
      NJetsH2btagged_shifts.push_back(NJetsH2btagged_lSFup);
      NJetsH2btagged_shifts.push_back(NJetsH2btagged_lSFdn);
      NJetsH2btagged_shifts.push_back(NJetsH2btagged_JMSup);
      NJetsH2btagged_shifts.push_back(NJetsH2btagged_JMSdn);
      NJetsH2btagged_shifts.push_back(NJetsH2btagged_JMRup);
      NJetsH2btagged_shifts.push_back(NJetsH2btagged_JMRdn);

      // ----------------------------------------------------------------------------
      // Skip failing events
      // ----------------------------------------------------------------------------

      int isPastNHjetsCut = 0;
      if(NJetsH1btagged >= 0){npass_nHjets += 1; isPastNHjetsCut = 1; }

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
           
      if(isElectron){
	leptonPt_singleLepCalc = leppt;
	leptonEta_singleLepCalc = lepeta;
	leptonPhi_singleLepCalc = elPhi_singleLepCalc->at(0);
	leptonEnergy_singleLepCalc = elEnergy_singleLepCalc->at(0);
	leptonMiniIso_singleLepCalc = elMiniIso_singleLepCalc->at(0);
	leptonRelIso_singleLepCalc = elRelIso_singleLepCalc->at(0);
	leptonDxy_singleLepCalc = elDxy_singleLepCalc->at(0);
	leptonDz_singleLepCalc = elDZ_singleLepCalc->at(0);
	leptonCharge_singleLepCalc = elCharge_singleLepCalc->at(0);
      }
      if(isMuon){
	leptonPt_singleLepCalc = leppt;
	leptonEta_singleLepCalc = lepeta;
	leptonPhi_singleLepCalc = muPhi_singleLepCalc->at(0);
	leptonEnergy_singleLepCalc = muEnergy_singleLepCalc->at(0);
	leptonMiniIso_singleLepCalc = muMiniIso_singleLepCalc->at(0);
	leptonRelIso_singleLepCalc = muRelIso_singleLepCalc->at(0);
	leptonDxy_singleLepCalc = muDxy_singleLepCalc->at(0);
	leptonDz_singleLepCalc = muDz_singleLepCalc->at(0);
	leptonCharge_singleLepCalc = muCharge_singleLepCalc->at(0);
      }

      // ----------------------------------------------------------------------------
      // Apply pt ordering to AK8 vectors 
      // ----------------------------------------------------------------------------

      //Pt ordering for AK8
      std::sort(jetak8ptindpair.begin(), jetak8ptindpair.end(), comparepair);
      theJetAK8Pt_JetSubCalc_PtOrdered.clear();
      theJetAK8Eta_JetSubCalc_PtOrdered.clear();
      theJetAK8Phi_JetSubCalc_PtOrdered.clear();
      theJetAK8Energy_JetSubCalc_PtOrdered.clear();
      theJetAK8Mass_JetSubCalc_PtOrdered.clear();
      theJetAK8PrunedMass_JetSubCalc_PtOrdered.clear();
      theJetAK8PrunedMassWtagUncerts_JetSubCalc_PtOrdered.clear();
      theJetAK8PrunedMassWtagUncerts_JMSup_JetSubCalc_PtOrdered.clear();
      theJetAK8PrunedMassWtagUncerts_JMSdn_JetSubCalc_PtOrdered.clear();
      theJetAK8PrunedMassWtagUncerts_JMRup_JetSubCalc_PtOrdered.clear();
      theJetAK8PrunedMassWtagUncerts_JMRdn_JetSubCalc_PtOrdered.clear();
      theJetAK8SoftDropMassWtagUncerts_JetSubCalc_PtOrdered.clear();
      theJetAK8SoftDropMassWtagUncerts_JMSup_JetSubCalc_PtOrdered.clear();
      theJetAK8SoftDropMassWtagUncerts_JMSdn_JetSubCalc_PtOrdered.clear();
      theJetAK8SoftDropMassWtagUncerts_JMRup_JetSubCalc_PtOrdered.clear();
      theJetAK8SoftDropMassWtagUncerts_JMRdn_JetSubCalc_PtOrdered.clear();
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
      	theJetAK8PrunedMassWtagUncerts_JetSubCalc_PtOrdered.push_back(theJetAK8PrunedMassWtagUncerts_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8PrunedMassWtagUncerts_JMSup_JetSubCalc_PtOrdered.push_back(theJetAK8PrunedMassWtagUncerts_JMSup_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8PrunedMassWtagUncerts_JMSdn_JetSubCalc_PtOrdered.push_back(theJetAK8PrunedMassWtagUncerts_JMSdn_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8PrunedMassWtagUncerts_JMRup_JetSubCalc_PtOrdered.push_back(theJetAK8PrunedMassWtagUncerts_JMRup_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8PrunedMassWtagUncerts_JMRdn_JetSubCalc_PtOrdered.push_back(theJetAK8PrunedMassWtagUncerts_JMRdn_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDropMass_JetSubCalc_PtOrdered.push_back(theJetAK8SoftDropMass_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDropMassWtagUncerts_JetSubCalc_PtOrdered.push_back(theJetAK8SoftDropMassWtagUncerts_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDropMassWtagUncerts_JMSup_JetSubCalc_PtOrdered.push_back(theJetAK8SoftDropMassWtagUncerts_JMSup_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDropMassWtagUncerts_JMSdn_JetSubCalc_PtOrdered.push_back(theJetAK8SoftDropMassWtagUncerts_JMSdn_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDropMassWtagUncerts_JMRup_JetSubCalc_PtOrdered.push_back(theJetAK8SoftDropMassWtagUncerts_JMRup_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDropMassWtagUncerts_JMRdn_JetSubCalc_PtOrdered.push_back(theJetAK8SoftDropMassWtagUncerts_JMRdn_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8MaxSubCSV_JetSubCalc_PtOrdered.push_back(maxsubcsv.at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau1_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau2_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau3_JetSubCalc->at(jetak8ptindpair[ijet].second));
      }

      // ----------------------------------------------------------------------------
      // Lepton 4-vectors, calculate MT and electron trigger presel value
      // ----------------------------------------------------------------------------

      // Set lepton 4-vectors
      double lepM;
      double lepphi;
      elTrigPresel_singleLepCalc = false;
      if (isMuon){ 
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

      // ----------------------------------------------------------------------------
      // 8TeV Top pT reweighting
      // ----------------------------------------------------------------------------

      genTopPt = -999;
      genAntiTopPt = -999;
      topPtWeight = 1.0;
      topPtWeightPast400 = 1.0;
      topPtWeightHighPt = 1.0;
      topPtWeight13TeV = 1.0;

      for(unsigned int ijet=0; ijet < topPt_TTbarMassCalc->size(); ijet++){
	if(genTopPt < 0 && topID_TTbarMassCalc->at(ijet) == 6) genTopPt = topPt_TTbarMassCalc->at(ijet);
	if(genAntiTopPt < 0 && topID_TTbarMassCalc->at(ijet) == -6) genAntiTopPt = topPt_TTbarMassCalc->at(ijet);
      }

      if(genTopPt > 0 && genAntiTopPt > 0){
	float toppt_temp = genTopPt;
	if(genTopPt > 400) toppt_temp = 400;
	float antitoppt_temp = genAntiTopPt;
	if(genAntiTopPt > 400) antitoppt_temp = 400;
	
	float SFtop = TMath::Exp(0.156-0.00137*toppt_temp); // using 8TeV TopPtReweighting: https://twiki.cern.ch/twiki/bin/viewauth/CMS/TopPtReweighting
	float SFantitop = TMath::Exp(0.156-0.00137*antitoppt_temp);
	topPtWeight = TMath::Sqrt(SFtop*SFantitop)/0.99277; //0.99277-->average weight
	
	float SFtopPast400 = TMath::Exp(0.156-0.00137*genTopPt);
	float SFantitopPast400 = TMath::Exp(0.156-0.00137*genAntiTopPt);
	topPtWeightPast400 = TMath::Sqrt(SFtopPast400*SFantitopPast400)/0.9927;
	
	float SFtopHighPt = 0.98  - 0.00026*genTopPt;  // 0.98 +- 0.24, 0.0026 +- 0.00039
	float SFantitopHighPt = 0.98  - 0.00026*genAntiTopPt;
	topPtWeightHighPt = TMath::Sqrt(SFtopHighPt*SFantitopHighPt);

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
      
      // ----------------------------------------------------------------------------
      // top --> W b --> l nu b using W from above
      // ----------------------------------------------------------------------------

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

      topPt = lvTop.Pt();
      topMass = lvTop.M();
      topPtGen = genTopPt;
      if(fabs(lvTop.Pt() - genTopPt) > fabs(lvTop.Pt() - genAntiTopPt)) topPtGen = genAntiTopPt;

      // ----------------------------------------------------------------------------
      // AK4 Jet - lepton associations
      // ----------------------------------------------------------------------------

      NJetsCSV_JetSubCalc = 0;
      NJetsCSVwithSF_JetSubCalc = 0;
      BJetLeadPt = -99;
      minMleppBjet = 1e8;
      minMleppJet = 1e8;
      deltaRlepJetInMinMljet = -99;
      deltaPhilepJetInMinMljet = -99;
      deltaRlepbJetInMinMlb = -99;
      deltaPhilepbJetInMinMlb = -99;
      minDR_lepJet = 1e8;
      ptRel_lepJet = -99;
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
	if((lepton_lv + jet_lv).M() < minMleppJet) {
	  minMleppJet = fabs((lepton_lv + jet_lv).M());
	  deltaRlepJetInMinMljet = jet_lv.DeltaR(lepton_lv);
	  deltaPhilepJetInMinMljet = jet_lv.DeltaPhi(lepton_lv);
	}

	deltaR_lepJets.push_back(lepton_lv.DeltaR(jet_lv));
	deltaPhi_lepJets.push_back(lepton_lv.DeltaPhi(jet_lv));
	mass_lepJets.push_back((lepton_lv + jet_lv).M());

        // FOR NOW DON'T USE THE SCALE FACTORS                                         
	if(theJetCSV_JetSubCalc_PtOrdered.at(ijet) > 0.8484){
          NJetsCSV_JetSubCalc += 1;
	  //   if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt) BJetLeadPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
	  //   deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));
	  //   deltaPhi_lepBJets.push_back(lepton_lv.DeltaPhi(jet_lv));
	  //   mass_lepBJets.push_back((lepton_lv + jet_lv).M());
	  
	  //   if((lepton_lv + jet_lv).M() < minMleppBjet) {
	  //     minMleppBjet = fabs( (lepton_lv + jet_lv).M() );
	  //     deltaRlepbJetInMinMlb = jet_lv.DeltaR(lepton_lv);
	  //     deltaPhilepbJetInMinMlb = jet_lv.DeltaPhi(lepton_lv);
	  //   }
        }
	// OK, we're back to using SFs
	if(theJetBTag_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsCSVwithSF_JetSubCalc += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt) BJetLeadPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));
          deltaPhi_lepBJets.push_back(lepton_lv.DeltaPhi(jet_lv));
          mass_lepBJets.push_back((lepton_lv + jet_lv).M());
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet) {
            minMleppBjet = fabs( (lepton_lv + jet_lv).M() );
            deltaRlepbJetInMinMlb = jet_lv.DeltaR(lepton_lv);
            deltaPhilepbJetInMinMlb = jet_lv.DeltaPhi(lepton_lv);
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

 	if(deltaR_lepJets[ijet] < minDR_lepJet) {
	  minDR_lepJet = deltaR_lepJets[ijet];
	  ptRel_lepJet = lepton_lv.P()*(jet_lv.Vect().Cross(lepton_lv.Vect()).Mag()/jet_lv.P()/lepton_lv.P());
	}
      }

      // ----------------------------------------------------------------------------
      // AK8 Jet - lepton associations, Top and W taggging
      // ----------------------------------------------------------------------------

      NJetsWtagged_0p6 = 0;
      NJetsWtagged_0p6_notTtagged = 0;
      NJetsTtagged_0p81 = 0;
      deltaR_lepAK8s.clear();
      deltaPhi_lepAK8s.clear();
      mass_lepAK8s.clear();
      minDR_lepAK8 = 1000;
      minDR_leadAK8otherAK8 = 1000;
      if(theJetAK8Pt_JetSubCalc_PtOrdered.size() < 1) minDR_lepAK8 = -99.0;      
      if(theJetAK8Pt_JetSubCalc_PtOrdered.size() < 2) minDR_leadAK8otherAK8 = -99.0;
      WJetLeadPt = -99.0;
      TJetLeadPt = -99.0;
      deltaRtopWjet = -99;     deltaPhitopWjet = -99;
      deltaRlepWjet = -99;     deltaPhilepWjet = -99;	  
      deltaRlepTjet = -99;     deltaPhilepTjet = -99;	  

      TauPtWeightUp = 1.0;
      TauPtWeightDown = 1.0;
      NJetsWtagged_0p6_shifts.clear();
      NJetsWtagged_0p6_notTtagged_shifts.clear();
      NJetsTtagged_0p81_shifts.clear();
      theJetAK8Wmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8Hmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8Zmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8Tmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8MatchedPt_JetSubCalc_PtOrdered.clear();
      WJetLeadPt_shifts.clear();
      TJetLeadPt_shifts.clear();
      deltaRtopWjet_shifts.clear();  deltaPhitopWjet_shifts.clear(); 
      deltaRlepWjet_shifts.clear();  deltaPhilepWjet_shifts.clear(); 
      deltaRlepTjet_shifts.clear();  deltaPhilepTjet_shifts.clear(); 

      wjet1_lv.SetPtEtaPhiM(0,0,0,0);
      tjet1_lv.SetPtEtaPhiM(0,0,0,0);
      ak8_lv.SetPtEtaPhiM(0,0,0,0);
      TLorentzVector leadak8;
      leadak8.SetPtEtaPhiM(0,0,0,0);

      for(int i = 0; i < 6; i++){
	NJetsWtagged_0p6_shifts.push_back(0);
	NJetsWtagged_0p6_notTtagged_shifts.push_back(0);
	NJetsTtagged_0p81_shifts.push_back(0);
	WJetLeadPt_shifts.push_back(-99.0);
	TJetLeadPt_shifts.push_back(-99.0);
	deltaRtopWjet_shifts.push_back(-99.0);  deltaPhitopWjet_shifts.push_back(-99.0); 
	deltaRlepWjet_shifts.push_back(-99.0);  deltaPhilepWjet_shifts.push_back(-99.0); 
	deltaRlepTjet_shifts.push_back(-99.0);  deltaPhilepTjet_shifts.push_back(-99.0); 
      }

      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc_PtOrdered.size(); ijet++){

	// ----------------------------------------------------------------------------
	// AK8 - lepton and AK8 -- AK8 associations
	// ----------------------------------------------------------------------------
	
	ak8_lv.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),theJetAK8Energy_JetSubCalc_PtOrdered.at(ijet));
	if(ijet == 0) leadak8 = ak8_lv;

	deltaR_lepAK8s.push_back(lepton_lv.DeltaR(ak8_lv));
	deltaPhi_lepAK8s.push_back(lepton_lv.DeltaPhi(ak8_lv));
	mass_lepAK8s.push_back((lepton_lv+ak8_lv).M());

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
	float mass = theJetAK8PrunedMassWtagUncerts_JetSubCalc_PtOrdered.at(ijet);
	float mass_JMSup = theJetAK8PrunedMassWtagUncerts_JMSup_JetSubCalc_PtOrdered.at(ijet);
	float mass_JMSdn = theJetAK8PrunedMassWtagUncerts_JMSdn_JetSubCalc_PtOrdered.at(ijet);
	float mass_JMRup = theJetAK8PrunedMassWtagUncerts_JMRup_JetSubCalc_PtOrdered.at(ijet);
	float mass_JMRdn = theJetAK8PrunedMassWtagUncerts_JMRdn_JetSubCalc_PtOrdered.at(ijet);
	float massSD = theJetAK8SoftDropMass_JetSubCalc_PtOrdered.at(ijet);
	float massSD_JMSup = theJetAK8SoftDropMassWtagUncerts_JMSup_JetSubCalc_PtOrdered.at(ijet);
	float massSD_JMSdn = theJetAK8SoftDropMassWtagUncerts_JMSdn_JetSubCalc_PtOrdered.at(ijet);
	float massSD_JMRup = theJetAK8SoftDropMassWtagUncerts_JMRup_JetSubCalc_PtOrdered.at(ijet);
	float massSD_JMRdn = theJetAK8SoftDropMassWtagUncerts_JMRdn_JetSubCalc_PtOrdered.at(ijet);

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

	  // ------------------------------------------------------------------------------------------------------------------
	  // TOP TAGGING
	  // ------------------------------------------------------------------------------------------------------------------
	  float topTau81SF = 1.0;
	  float topTau81SFup = 1.0;
	  float topTau81SFdn = 1.0;
	  double topTau81Eff = 1.0;
	  if(isTmatched && matchedPt >= 400){	    
	    // VALUES FOR 76X FROM PAS
	    topTau81SF = 0.96;
	    topTau81SFup = 1.04;
	    topTau81SFdn = 0.88;
	    
	    // Use matched T to find the efficiency -- calculated for TpTp and ttbar, EWK/QCD will almost never pass here (use ttbar eff when they do)
	    if(isSig){
	      int bin = (std::upper_bound(ptRangeTpTpTop.begin(), ptRangeTpTpTop.end(), matchedPt)-ptRangeTpTpTop.begin())-1;
	      topTau81Eff = SignalEffTop[SigMass][bin];
	    }else{
	      int bin = (std::upper_bound(ptRangeTTbarTop.begin(), ptRangeTTbarTop.end(), matchedPt)-ptRangeTTbarTop.begin())-1;
	      if(isTT) topTau81Eff = TTbarEffTop[bin]; // ttbar
	      else topTau81Eff = STEffTop[bin]; // ST
	    }
	  }
	  
	  // Set the initial tagged/untagged state
	  bool isTtagged = (massSD > 105) && (massSD < 220) && (tau32 < 0.81) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);
	  bool isTtagged_JMSup = (massSD_JMSup > 105) && (massSD_JMSup < 220) && (tau32 < 0.81) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);
	  bool isTtagged_JMSdn = (massSD_JMSdn > 105) && (massSD_JMSdn < 220) && (tau32 < 0.81) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);
	  bool isTtagged_JMRup = (massSD_JMRup > 105) && (massSD_JMRup < 220) && (tau32 < 0.81) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);
	  bool isTtagged_JMRdn = (massSD_JMRdn > 105) && (massSD_JMRdn < 220) && (tau32 < 0.81) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);

	  // IF THE JET IS NOT TRUTH-MATCHED, THESE IFS WILL DO NOTHING, SF == 1
	  int tag_topTau81 = applySF(isTtagged,topTau81SF,topTau81Eff);
	  int tag_topTau81up = applySF(isTtagged,topTau81SFup,topTau81Eff);
	  int tag_topTau81dn = applySF(isTtagged,topTau81SFdn,topTau81Eff);
	  int tag_topTau81_JMSup = applySF(isTtagged_JMSup,topTau81SF,topTau81Eff);
	  int tag_topTau81_JMSdn = applySF(isTtagged_JMSdn,topTau81SF,topTau81Eff);
	  int tag_topTau81_JMRup = applySF(isTtagged_JMRup,topTau81SF,topTau81Eff);
	  int tag_topTau81_JMRdn = applySF(isTtagged_JMRdn,topTau81SF,topTau81Eff);
 
	  // Now increase the tag count in the right variable	  
	  NJetsTtagged_0p81 += tag_topTau81;
	  NJetsTtagged_0p81_shifts[0] += tag_topTau81up;
	  NJetsTtagged_0p81_shifts[1] += tag_topTau81dn;
	  NJetsTtagged_0p81_shifts[2] += tag_topTau81_JMSup;
	  NJetsTtagged_0p81_shifts[3] += tag_topTau81_JMSdn;
	  NJetsTtagged_0p81_shifts[4] += tag_topTau81_JMRup;
	  NJetsTtagged_0p81_shifts[5] += tag_topTau81_JMRdn;

 	  // ------------------------------------------------------------------------------------------------------------------
	  // Variable for top tagged jets
	  // ------------------------------------------------------------------------------------------------------------------

	  if(tag_topTau81 == 1){
	    TJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet);
	    if(NJetsTtagged_0p81 == 1){
	      tjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				    theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),massSD);
	      deltaRlepTjet = tjet1_lv.DeltaR(lepton_lv);
	      deltaPhilepTjet = tjet1_lv.DeltaPhi(lepton_lv);
	    }
	  }
	  if(tag_topTau81up == 1){
	    TJetLeadPt_shifts.at(0) = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet);
	    if(NJetsTtagged_0p81_shifts[0] == 1){
	      tjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				    theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),massSD);
	      deltaRlepTjet_shifts.at(0) = tjet1_lv.DeltaR(lepton_lv);
	      deltaPhilepTjet_shifts.at(0) = tjet1_lv.DeltaPhi(lepton_lv);
	    }
	  }
	  if(tag_topTau81dn == 1){
	    TJetLeadPt_shifts.at(1) = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet);
	    if(NJetsTtagged_0p81_shifts[1] == 1){
	      tjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				    theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),massSD);
	      deltaRlepTjet_shifts.at(1) = tjet1_lv.DeltaR(lepton_lv);
	      deltaPhilepTjet_shifts.at(1) = tjet1_lv.DeltaPhi(lepton_lv);
	    }
	  }
	  
	  // ------------------------------------------------------------------------------------------------------------------
	  // W TAGGING
	  // ------------------------------------------------------------------------------------------------------------------
	  
	  float tau0p6SF = 1.0;
	  float tau0p6SFup = 1.0;
	  float tau0p6SFdn = 1.0;
	  double tau0p6Eff = 1.0;
	  if(isWmatched && matchedPt >= 200){	    
	    // VALUES FOR 80X from TWiki
	    tau0p6SF = 1.002;
	    tau0p6SFup = 1.002+0.028;
	    tau0p6SFdn = 1.002-0.028;
	    
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
	  bool isWtagged = (mass > 65) && (mass < 105) && (tau21 < 0.6) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
	  bool isWtagged_JMSup = (mass_JMSup > 65) && (mass_JMSup < 105) && (tau21 < 0.6) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
	  bool isWtagged_JMSdn = (mass_JMSdn > 65) && (mass_JMSdn < 105) && (tau21 < 0.6) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
	  bool isWtagged_JMRup = (mass_JMRup > 65) && (mass_JMRup < 105) && (tau21 < 0.6) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
	  bool isWtagged_JMRdn = (mass_JMRdn > 65) && (mass_JMRdn < 105) && (tau21 < 0.6) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
 
	  // IF THE JET IS NOT TRUTH-MATCHED, THESE IFS WILL DO NOTHING, SF == 1
	  int tag_tau0p6 = applySF(isWtagged,tau0p6SF,tau0p6Eff);
	  int tag_tau0p6_JMSup = applySF(isWtagged_JMSup,tau0p6SF,tau0p6Eff);
	  int tag_tau0p6_JMSdn = applySF(isWtagged_JMSdn,tau0p6SF,tau0p6Eff);
	  int tag_tau0p6_JMRup = applySF(isWtagged_JMRup,tau0p6SF,tau0p6Eff);
	  int tag_tau0p6_JMRdn = applySF(isWtagged_JMRdn,tau0p6SF,tau0p6Eff);
 	  int tag_tau0p6up = applySF(isWtagged,tau0p6SFup,tau0p6Eff);
	  int tag_tau0p6dn = applySF(isWtagged,tau0p6SFdn,tau0p6Eff);
	  
	  // Now increase the tag count in the right variable	  
	  NJetsWtagged_0p6 += tag_tau0p6;
	  NJetsWtagged_0p6_shifts[0] += tag_tau0p6up;
	  NJetsWtagged_0p6_shifts[1] += tag_tau0p6dn;
	  NJetsWtagged_0p6_shifts[2] += tag_tau0p6_JMSup;
	  NJetsWtagged_0p6_shifts[3] += tag_tau0p6_JMSdn;
	  NJetsWtagged_0p6_shifts[4] += tag_tau0p6_JMRup;
	  NJetsWtagged_0p6_shifts[5] += tag_tau0p6_JMRdn;

	  NJetsWtagged_0p6_notTtagged += tag_tau0p6-tag_topTau81;
	  NJetsWtagged_0p6_notTtagged_shifts[0] += tag_tau0p6up-tag_topTau81up;
	  NJetsWtagged_0p6_notTtagged_shifts[1] += tag_tau0p6dn-tag_topTau81dn;
	  NJetsWtagged_0p6_notTtagged_shifts[2] += tag_tau0p6_JMSup-tag_topTau81_JMSup;
	  NJetsWtagged_0p6_notTtagged_shifts[3] += tag_tau0p6_JMSdn-tag_topTau81_JMSdn;
	  NJetsWtagged_0p6_notTtagged_shifts[4] += tag_tau0p6_JMRup-tag_topTau81_JMRup;
	  NJetsWtagged_0p6_notTtagged_shifts[5] += tag_tau0p6_JMRdn-tag_topTau81_JMRdn;

	  // Extra uncertainty for pt extrapolation
	  if(tag_tau0p6 == 1){
	    TauPtWeightUp *= 1 + 0.0453*log(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)/200);
	    TauPtWeightDown *= 1 - 0.0453*log(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)/200);
	  }

	  // ------------------------------------------------------------------------------------------------------------------
	  // Variables for W tagged jets
	  // ------------------------------------------------------------------------------------------------------------------

	  if(tag_tau0p6 == 1){
	    if(NJetsWtagged_0p6 == 1){
	      WJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet);
	      wjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				    theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),mass);
	      deltaRtopWjet = wjet1_lv.DeltaR(lvTop);
	      deltaRlepWjet = wjet1_lv.DeltaR(lepton_lv);
	      deltaPhitopWjet = wjet1_lv.DeltaPhi(lvTop);
	      deltaPhilepWjet = wjet1_lv.DeltaPhi(lepton_lv);
	    }
	  }
	  if(tag_tau0p6up == 1){
	    if(NJetsWtagged_0p6_shifts[0] == 1){
	      WJetLeadPt_shifts.at(0) = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet);
	      wjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				    theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),mass);
	      deltaRtopWjet_shifts.at(0) = wjet1_lv.DeltaR(lvTop);
	      deltaRlepWjet_shifts.at(0) = wjet1_lv.DeltaR(lepton_lv);
	      deltaPhitopWjet_shifts.at(0) = wjet1_lv.DeltaPhi(lvTop);
	      deltaPhilepWjet_shifts.at(0) = wjet1_lv.DeltaPhi(lepton_lv);
	    }
	  }
	  if(tag_tau0p6dn == 1){
	    if(NJetsWtagged_0p6_shifts[1] == 1){
	      WJetLeadPt_shifts.at(1) = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet);
	      wjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				    theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),mass);
	      deltaRtopWjet_shifts.at(1) = wjet1_lv.DeltaR(lvTop);
	      deltaRlepWjet_shifts.at(1) = wjet1_lv.DeltaR(lepton_lv);
	      deltaPhitopWjet_shifts.at(1) = wjet1_lv.DeltaPhi(lvTop);
	      deltaPhilepWjet_shifts.at(1) = wjet1_lv.DeltaPhi(lepton_lv);
	    }
	  }
	}
	// ------------------------------------------------------------------------------------------------------------------
	// DATA Calculation second
	// ------------------------------------------------------------------------------------------------------------------
	else{
	  
	  theJetAK8Wmatch_JetSubCalc_PtOrdered.push_back(0);
	  theJetAK8Hmatch_JetSubCalc_PtOrdered.push_back(0);
	  theJetAK8Zmatch_JetSubCalc_PtOrdered.push_back(0);
	  theJetAK8Tmatch_JetSubCalc_PtOrdered.push_back(0);
	  
	  bool isTtagged = (massSD > 105) && (massSD < 220) && (tau32 < 0.81) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);
	  
	  NJetsTtagged_0p81 += isTtagged;
	  if(NJetsTtagged_0p81 == 1){
	    TJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet);
	    tjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				  theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),massSD);
	    deltaRlepTjet = tjet1_lv.DeltaR(lepton_lv);
	    deltaPhilepTjet = tjet1_lv.DeltaPhi(lepton_lv);
	  }
	  
	  bool isWtagged = (mass > 65) && (mass < 105) && (tau21 < 0.6) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
	  
	  NJetsWtagged_0p6 += isWtagged;
	  NJetsWtagged_0p6_notTtagged += isWtagged-isTtagged;
	  if(NJetsWtagged_0p6 == 1){
	    WJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet);
	    wjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				  theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),mass);
	    deltaRtopWjet = wjet1_lv.DeltaR(lvTop);
	    deltaRlepWjet = wjet1_lv.DeltaR(lepton_lv);
	    deltaPhitopWjet = wjet1_lv.DeltaPhi(lvTop);
	    deltaPhilepWjet = wjet1_lv.DeltaPhi(lepton_lv);
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

      // ----------------------------------------------------------------------------
      // DONE!! Write the tree
      // ----------------------------------------------------------------------------
      
      outputTree->Fill();
   }
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
   outputTree->Write();

}
