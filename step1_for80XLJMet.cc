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
   inputTree->SetBranchStatus("theJetAK8PrunedMassWtagUncerts_JetSubCalc",1);
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
   outputTree->Branch("EGammaGsfSF",&EGammaGsfSF,"EGammaGsfSF/F");

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
   outputTree->Branch("theJetAK8PrunedMassWtagUncerts_JetSubCalc_PtOrdered",&theJetAK8PrunedMassWtagUncerts_JetSubCalc_PtOrdered);
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

   TLorentzVector jet_lv;
   TLorentzVector bjet_lv;
   TLorentzVector wjet1_lv;
   TLorentzVector tjet1_lv;
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

   // B tagging efficiencies. This will not be needed after 8/1/16 LJMet
   std::vector<float> ptRangeSF, ptRangeEff;
   float SFerr[7]  = {0.011629186570644379, 0.011501740664243698, 0.01121238712221384, 0.016118986532092094, 0.016830746084451675, 0.032492130994796753, 0.036446873098611832};
   float ptmin16[7] = {30, 50, 70, 100, 140, 200, 300};
   for (int i=0;i<7;++i) ptRangeSF.push_back(ptmin16[i]);
   float ptminEff[19] = {30, 50, 70, 100, 140, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1400, 1600, 1800};
   for (int i=0;i<19;++i) ptRangeEff.push_back(ptminEff[i]);
   float BtagEff[19] = {0.598502,0.650253,0.675872,0.684356,0.681335,0.647372,0.607565,0.563892,0.536284,0.526137,0.511053,0.490886,0.482464,0.461109,0.447184,0.452516,0.455189,0.399306,0.367347};
   float MistagEff[19] = {0.014675,0.012310,0.012179,0.012088,0.013761,0.015344,0.021110,0.023148,0.023755,0.028529,0.030575,0.030955,0.034016,0.037446,0.034907,0.043372,0.052239,0.049661,0.073034};

   // W tagging efficiencies. Assumes each signal mass uses the same pT bins but has unique values.
   std::vector<float> ptRangeTpTp, ptRangeTTbar;
   float ptminTTbar[14] = {200, 250, 300, 350, 400, 450, 500, 550, 600, 700, 800, 1000, 1200, 1600};
   for (int i=0;i<14;++i) ptRangeTTbar.push_back(ptminTTbar[i]);
   float ptminTpTp[14] = {200, 250, 300, 350, 400, 450, 500, 550, 600, 700, 800, 1000, 1200, 1600};
   for (int i=0;i<14;++i) ptRangeTpTp.push_back(ptminTpTp[i]);

   float SignalEff[11][14] = {
     {0.548356, 0.582139, 0.583056, 0.589624, 0.593879, 0.596037, 0.606139, 0.603989, 0.604075, 0.612769, 0.598276, 0.563951, 0.562433, 0.481481},
     {0.537263, 0.566472, 0.563321, 0.566097, 0.569125, 0.578216, 0.579019, 0.585555, 0.589941, 0.589891, 0.590064, 0.591820, 0.566303, 0.476440},
     {0.538521, 0.557660, 0.543946, 0.545865, 0.558151, 0.563405, 0.572813, 0.570846, 0.573461, 0.586819, 0.578804, 0.572940, 0.561443, 0.555556},
     {0.530602, 0.550354, 0.538940, 0.536638, 0.544389, 0.550410, 0.554327, 0.562982, 0.568316, 0.567526, 0.576123, 0.575019, 0.560201, 0.550186},
     {0.533944, 0.550041, 0.530723, 0.522086, 0.528805, 0.539058, 0.545445, 0.549327, 0.552455, 0.554668, 0.559353, 0.558860, 0.553680, 0.531915},
     {0.538718, 0.549315, 0.523989, 0.518197, 0.516679, 0.527819, 0.534820, 0.540149, 0.540099, 0.549270, 0.550459, 0.557293, 0.545746, 0.559468},
     {0.542657, 0.554109, 0.528772, 0.512938, 0.509910, 0.519070, 0.522395, 0.532678, 0.535456, 0.538611, 0.540082, 0.546394, 0.540544, 0.539807},
     {0.539844, 0.566326, 0.531928, 0.506292, 0.502152, 0.510498, 0.513585, 0.520557, 0.527288, 0.534014, 0.538507, 0.537015, 0.535885, 0.540658},
     {0.548628, 0.559869, 0.551592, 0.510941, 0.501727, 0.506774, 0.502805, 0.513068, 0.519535, 0.520095, 0.519365, 0.519234, 0.537919, 0.519135},
     {0.549918, 0.577604, 0.540031, 0.518584, 0.507735, 0.504109, 0.500252, 0.506397, 0.513234, 0.518664, 0.521474, 0.520294, 0.518832, 0.532468},
     {0.554463, 0.581864, 0.553090, 0.522106, 0.504654, 0.496037, 0.501408, 0.500636, 0.504387, 0.509833, 0.515884, 0.510956, 0.515713, 0.538008},
   };
   float TTbarEff[14] = {0.682439, 0.738105, 0.707007, 0.676506, 0.655480, 0.647157, 0.640495, 0.631280, 0.629425, 0.588845, 0.572383,  0.631179, 0.528302, 0.333333};
   float STEff[14] = {0.721371, 0.799146, 0.782680, 0.762160, 0.743905, 0.729174, 0.727657, 0.709333, 0.724403, 0.717466, 0.690385,  0.666667, 0.483333, 0.600000};
   float WVEff[14] = {0.712598, 0.791459, 0.756127, 0.723847, 0.705318, 0.674699, 0.718884, 0.626923, 0.662162, 0.656250, 0.564356,  0.454545, 0.285714, 0.285714};
   float TTVEff[14] = {0.605128, 0.633895, 0.614585, 0.602014, 0.588748, 0.569500, 0.557702, 0.571873, 0.539608, 0.537893, 0.540462,  0.444444, 0.189189, 0.600000};

   // Top tagging efficiencies
   std::vector<float> ptRangeTpTpTop, ptRangeTTbarTop;
   float ptminTTbarTop[10] = {400, 450, 500, 550, 600, 700, 800, 1000, 1200, 1600};
   for (int i=0;i<10;++i) ptRangeTTbarTop.push_back(ptminTTbarTop[i]);
   float ptminTpTpTop[10] = {400, 450, 500, 550, 600, 700, 800, 1000, 1200, 1600};
   for (int i=0;i<10;++i) ptRangeTpTpTop.push_back(ptminTpTpTop[i]);
   float TTbarEffTop[10] = {0.656721, 0.842644, 0.864036, 0.851990, 0.824271, 0.782050, 0.738981, 0.699812, 0.676243, 0.646388};
   float SignalEffTop[11][10] = {
     {0.611732, 0.780089, 0.804294, 0.810772, 0.799419, 0.780285, 0.757704, 0.712814, 0.647868, 0.658120}, 
     {0.581438, 0.746973, 0.777896, 0.788666, 0.782500, 0.766847, 0.748906, 0.725802, 0.698985, 0.673077}, 
     {0.559565, 0.718270, 0.750923, 0.766999, 0.757874, 0.751325, 0.737532, 0.718955, 0.700150, 0.679035}, 
     {0.541422, 0.681966, 0.728139, 0.738110, 0.738715, 0.726217, 0.711723, 0.707830, 0.692991, 0.666259}, 
     {0.522404, 0.666741, 0.702028, 0.713631, 0.718917, 0.715071, 0.701261, 0.698686, 0.692463, 0.678025}, 
     {0.495974, 0.639434, 0.678278, 0.690605, 0.700150, 0.696724, 0.687981, 0.683291, 0.694443, 0.679642}, 
     {0.491851, 0.625171, 0.657520, 0.672060, 0.678105, 0.680814, 0.674685, 0.671018, 0.672606, 0.687192}, 
     {0.482352, 0.607627, 0.638979, 0.653509, 0.661607, 0.663634, 0.662143, 0.662867, 0.667102, 0.685247}, 
     {0.474970, 0.611347, 0.612631, 0.644484, 0.641295, 0.656193, 0.649018, 0.645009, 0.665298, 0.674550}, 
     {0.472171, 0.591681, 0.617293, 0.622990, 0.628382, 0.632128, 0.637580, 0.638157, 0.650723, 0.662004}, 
     {0.470206, 0.584249, 0.607135, 0.604068, 0.614005, 0.621413, 0.624816, 0.626804, 0.639740, 0.659275},
   }; 

   // Pileup distributions
   double pileup_central[40] = {1.990e-04, 9.977e-03, 1.408e-02, 2.362e-02, 3.913e-02, 3.103e-02, 3.369e-02, 6.947e-02, 1.636e-01, 3.170e-01, 4.966e-01, 7.191e-01, 9.710e-01, 1.155e+00, 1.264e+00, 1.220e+00, 1.142e+00, 1.214e+00, 1.182e+00, 1.275e+00, 1.137e+00, 1.055e+00, 1.070e+00, 1.112e+00, 1.067e+00, 1.149e+00, 1.019e+00, 1.008e+00, 8.370e-01, 7.521e-01, 6.384e-01, 5.358e-01, 5.765e-01, 5.628e-01, 7.408e-01, 1.209e+00, 2.364e+00, 3.325e+00, 0.000e+00, 0.000e+00};

   double pileup_down[40] =    {3.167e-04, 1.224e-02, 1.592e-02, 2.817e-02, 4.279e-02, 3.554e-02, 4.153e-02, 1.191e-01, 2.535e-01, 4.625e-01, 6.876e-01, 9.668e-01, 1.248e+00, 1.411e+00, 1.502e+00, 1.421e+00, 1.293e+00, 1.335e+00, 1.263e+00, 1.324e+00, 1.145e+00, 1.030e+00, 1.011e+00, 1.013e+00, 9.292e-01, 9.449e-01, 7.845e-01, 7.233e-01, 5.580e-01, 4.638e-01, 3.611e-01, 2.756e-01, 2.680e-01, 2.356e-01, 2.784e-01, 4.070e-01, 7.124e-01, 8.988e-01, 0.000e+00, 0.000e+00};

   double pileup_up[40] =      {1.230e-04, 8.231e-03, 1.238e-02, 1.978e-02, 3.623e-02, 2.701e-02, 2.954e-02, 4.398e-02, 1.026e-01, 2.169e-01, 3.559e-01, 5.350e-01, 7.430e-01, 9.278e-01, 1.057e+00, 1.041e+00, 9.943e-01, 1.085e+00, 1.085e+00, 1.200e+00, 1.098e+00, 1.049e+00, 1.095e+00, 1.172e+00, 1.162e+00, 1.302e+00, 1.215e+00, 1.275e+00, 1.128e+00, 1.082e+00, 9.846e-01, 8.912e-01, 1.042e+00, 1.113e+00, 1.610e+00, 2.896e+00, 6.253e+00, 9.726e+00, 0.000e+00, 0.000e+00};

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
      if(isTTincMtt0to1000 && ttbarMass_TTbarMassCalc >= 1000.) continue;
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
     	     
      int isE = 0;
      int isM = 0;
      if(elPt_singleLepCalc->size()==0 && muPt_singleLepCalc->size()==0){std::cout << "got no leptons, something wrong" << std::endl; continue;}
      if(elPt_singleLepCalc->size()>0 && muPt_singleLepCalc->size()>0) std::cout << "got el and mu, something wrong" << std::endl;
      if(elPt_singleLepCalc->size()>1 && muPt_singleLepCalc->size()>1) std::cout << "got more than one el or mu, something wrong" << std::endl;
      if(elPt_singleLepCalc->size()>0 && muPt_singleLepCalc->size()==0) {isE = 1; isM = 0;}
      if(elPt_singleLepCalc->size()==0 && muPt_singleLepCalc->size()>0) {isE = 0; isM = 1;}
      if(isE==0 && isM==0){std::cout << "got no leptons, something wrong" << std::endl; continue;}

      if(nTrueInteractions_singleLepCalc > 39) nTrueInteractions_singleLepCalc = 39;
      double puweight = pileup_central[nTrueInteractions_singleLepCalc];
      double puweightup = pileup_down[nTrueInteractions_singleLepCalc];
      double puweightdown = pileup_up[nTrueInteractions_singleLepCalc];

      int   isPastTrig = 0;
      int   isPastTrigAlt = 0;
      int   isPastTrigMC = 0;
      int   isPastTrigMCAlt = 0;
      TrigEffAltWeight = 1.0;
      TrigEffWeight = 1.0;
      float isosf = 1.0;
      float lepidsf = 1.0;
      float egammasf = 1.0;  
      float gsfsf = 1.0;

      double leppt = 0;
      double lepeta = 0;
      if(isE){leppt = elPt_singleLepCalc->at(0); lepeta = elEta_singleLepCalc->at(0);}
      if(isM){leppt = muPt_singleLepCalc->at(0); lepeta = muEta_singleLepCalc->at(0);}

      if(isMC){ //MC triggers check
      	if(isE){
	  if(isSig){
	    for(unsigned int itrig=0; itrig < vsSelMCTriggersEl_singleLepCalc->size(); itrig++){
	      if(vsSelMCTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele27_eta2p1_WPLoose_Gsf_v1" && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigMC = 1;
	      if(vsSelMCTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele27_eta2p1_WPLoose_Gsf_v2" && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigMC = 1;
	      if(vsSelMCTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele27_eta2p1_WPLoose_Gsf_v3" && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigMC = 1;
	      if(vsSelMCTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele27_eta2p1_WPLoose_Gsf_v4" && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigMC = 1;
	      if(vsSelMCTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele27_eta2p1_WPLoose_Gsf_v5" && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigMC = 1;
	      if(vsSelMCTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v1" && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigMCAlt = 1;
	      if(vsSelMCTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v2" && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigMCAlt = 1;
	      if(vsSelMCTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v3" && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigMCAlt = 1;
	      if(vsSelMCTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v4" && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigMCAlt = 1;
	      if(vsSelMCTriggersEl_singleLepCalc->at(itrig) == "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v5" && viSelMCTriggersEl_singleLepCalc->at(itrig) > 0) isPastTrigMCAlt = 1;
	    }
	  }else{
	    isPastTrigMC = 1;
	    isPastTrigMCAlt = 1;
	  }
	  // Gsf Tracking scale factor: http://fcouderc.web.cern.ch/fcouderc/EGamma/scaleFactors/ichep2016_80X/resultsGsfID/egammaEffi.txt_egammaPlots.pdf
	  if(lepeta < -2.4) gsfsf = 1.170;
	  else if(lepeta < -2.3) gsfsf = 1.009;
	  else if(lepeta < -2.2) gsfsf = 1.010;
	  else if(lepeta < -2.0) gsfsf = 1.005;
	  else if(lepeta < -1.8) gsfsf = 0.998;
	  else if(lepeta < -1.65) gsfsf = 0.992;
	  else if(lepeta < -1.566) gsfsf = 0.986;
	  else if(lepeta < -1.4442) gsfsf = 0.962;
	  else if(lepeta < -1.2) gsfsf = 0.987;
	  else if(lepeta < -1.0) gsfsf = 0.978;
	  else if(lepeta < -0.6) gsfsf = 0.969;
	  else if(lepeta < -0.4) gsfsf = 0.966;
	  else if(lepeta < -0.2) gsfsf = 0.963;
	  else if(lepeta < 0.0) gsfsf = 0.960;
	  else if(lepeta < 0.2) gsfsf = 0.966;
	  else if(lepeta < 0.4) gsfsf = 0.980;
	  else if(lepeta < 0.6) gsfsf = 0.977;
	  else if(lepeta < 1.0) gsfsf = 0.981;
	  else if(lepeta < 1.2) gsfsf = 0.987;
	  else if(lepeta < 1.4442) gsfsf = 0.987;
	  else if(lepeta < 1.566) gsfsf = 0.971;
	  else if(lepeta < 1.65) gsfsf = 0.990;
	  else if(lepeta < 1.8) gsfsf = 0.996;
	  else if(lepeta < 2.0) gsfsf = 0.990;
	  else if(lepeta < 2.2) gsfsf = 0.995;
	  else if(lepeta < 2.3) gsfsf = 0.993;
	  else if(lepeta < 2.4) gsfsf = 0.967;
	  else gsfsf = 0.884;
	  
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
	  

	  // Ele27_eta2p1 -- 80X DATA EFFICIENCIES
	  if(leppt < 45){
            if(fabs(lepeta) < 0.8) TrigEffWeight = 0.811; // 
            else if(fabs(lepeta) < 1.442) TrigEffWeight = 0.832;
            else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.758;
            else TrigEffWeight = 0.772;
          }else if(leppt < 50){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.844; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 0.860;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.776;
	    else TrigEffWeight = 0.789;
	  }else if(leppt < 60){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.861; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 0.873;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.782;
	    else TrigEffWeight = 0.796;
	  }else if(leppt < 70){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.877; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 0.885;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.779;
	    else TrigEffWeight = 0.798;
	  }else if(leppt < 90){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.887; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 0.893;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.750;
	    else TrigEffWeight = 0.799;
	  }else if(leppt < 130){
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.900; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 0.901;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.774;
	    else TrigEffWeight = 0.809;
	  }else{
	    if(fabs(lepeta) < 0.8) TrigEffWeight = 0.909; // 
	    else if(fabs(lepeta) < 1.442) TrigEffWeight = 0.912;
	    else if(fabs(lepeta) < 1.566) TrigEffWeight = 0.797;
	    else TrigEffWeight = 0.816;
	  }
	  	
	  //miniIso < 0.1 scale factors from SUSYLepSF: http://tomc.web.cern.ch/tomc/tagAndProbe/20160726/output/scaleFactors.root
	  if(fabs(lepeta) < 0.8){
	    if(leppt < 30) isosf = 0.991;
	    else if(leppt < 40) isosf = 0.993;
	    else if(leppt < 50) isosf = 0.996;
	    else if(leppt < 100) isosf = 0.996;
	    else isosf = 0.996;
	  }
	  else if(fabs(lepeta) < 1.4442){
	    if(leppt < 30) isosf = 0.989;
	    else if(leppt < 40) isosf = 0.993;
	    else if(leppt < 50) isosf = 0.995;
	    else if(leppt < 100) isosf = 0.996;
	    else isosf = 0.998;
	  }
	  else if(fabs(lepeta) < 1.566){
	    if(leppt < 30) isosf = 1.007;
	    else if(leppt < 40) isosf = 0.998;
	    else if(leppt < 50) isosf = 0.995;
	    else if(leppt < 100) isosf = 1.004;
	    else isosf = 0.988;
	  }
	  else if(fabs(lepeta) < 2.0){
	    if(leppt < 30) isosf = 0.990;
	    else if(leppt < 40) isosf = 0.999;
	    else if(leppt < 50) isosf = 0.998;
	    else if(leppt < 100) isosf = 0.999;
	    else isosf = 1.000;
	  }
	  else {
	    if(leppt < 30) isosf = 0.978;
	    else if(leppt < 40) isosf = 0.991;
	    else if(leppt < 50) isosf = 0.995;
	    else if(leppt < 100) isosf = 0.999;
	    else isosf = 1.001;
	  }
	  
	  //MVA-based ID scale factors (non-triggering): http://fcouderc.web.cern.ch/fcouderc/EGamma/scaleFactors/ichep2016_80X//resultsEleID/runBCD/passingMVA80/egammaEffi.txt_egammaPlots.pdf
	  if(lepeta < -2.0){
	    if(leppt < 30) lepidsf = 0.863;
	    else if(leppt < 40) lepidsf = 0.915;
	    else if(leppt < 50) lepidsf = 0.930;
	    else lepidsf = 0.936;
	  }
	  else if(lepeta < -1.566){
	    if(leppt < 30) lepidsf = 0.871;
	    else if(leppt < 40) lepidsf = 0.916;
	    else if(leppt < 50) lepidsf = 0.939;
	    else lepidsf = 0.950;
	  }
	  else if(lepeta < -1.4442){
	    if(leppt < 30) lepidsf = 0.891;
	    else if(leppt < 40) lepidsf = 0.920;
	    else if(leppt < 50) lepidsf = 0.953;
	    else lepidsf = 0.965;
	  }
	  else if(lepeta < -0.8){
	    if(leppt < 30) lepidsf = 0.923;
	    else if(leppt < 40) lepidsf = 0.949;
	    else if(leppt < 50) lepidsf = 0.956;
	    else lepidsf = 0.957;
	  }
	  else if(lepeta < 0.0){
	    if(leppt < 30) lepidsf = 0.920;
	    else if(leppt < 40) lepidsf = 0.941;
	    else if(leppt < 50) lepidsf = 0.951;
	    else lepidsf = 0.957;
	  }
	  else if(lepeta < 0.8){
	    if(leppt < 30) lepidsf = 0.945;
	    else if(leppt < 40) lepidsf = 0.961;
	    else if(leppt < 50) lepidsf = 0.965;
	    else lepidsf = 0.971;
	  }
	  else if(lepeta < 1.4442){
	    if(leppt < 30) lepidsf = 0.919;
	    else if(leppt < 40) lepidsf = 0.945;
	    else if(leppt < 50) lepidsf = 0.954;
	    else lepidsf = 0.964;
	  }
	  else if(lepeta < 1.566){
	    if(leppt < 30) lepidsf = 0.865;
	    else if(leppt < 40) lepidsf = 0.918;
	    else if(leppt < 50) lepidsf = 0.932;
	    else lepidsf = 0.944;
	  }
	  else if(lepeta < 2.0){
	    if(leppt < 30) lepidsf = 0.866;
	    else if(leppt < 40) lepidsf = 0.919;
	    else if(leppt < 50) lepidsf = 0.943;
	    else lepidsf = 0.958;
	  }
	  else{
	    if(leppt < 30) lepidsf = 0.892;
	    else if(leppt < 40) lepidsf = 0.927;
	    else if(leppt < 50) lepidsf = 0.943;
	    else lepidsf = 0.954;
	  }
	}
      	if(isM){
	  if(isSig){
	    for(unsigned int itrig=0; itrig < vsSelMCTriggersMu_singleLepCalc->size(); itrig++){
	      if((vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu24_v1" || vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu24_v1") && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigMC = 1;
	      if((vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu24_v2" || vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu24_v2") && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigMC = 1;
	      if((vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu24_v3" || vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu24_v3") && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigMC = 1;
	      if((vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu24_v4" || vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu24_v4") && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigMC = 1;
	      if((vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu24_v5" || vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu24_v5") && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigMC = 1;
	      if((vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu24_v6" || vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu24_v6") && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigMC = 1;
	      if(vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v1" && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigMCAlt = 1;
	      if(vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v2" && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigMCAlt = 1;
	      if(vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v3" && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigMCAlt = 1;
	      if(vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v4" && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigMCAlt = 1;
	      if(vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v5" && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigMCAlt = 1;
	      if(vsSelMCTriggersMu_singleLepCalc->at(itrig) == "HLT_Mu45_eta2p1_v6" && viSelMCTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrigMCAlt = 1;
	    }
	  }else{
	    isPastTrigMC = 1;
	    isPastTrigMCAlt = 1;
	  }
	  
	  // IsoMu24 || IsoTkMu24 Eff -- 80X DATA EFFICIENCIES
	  if(leppt < 40){
	    if(fabs(lepeta) < 0.9) TrigEffWeight = 0.907; //0.984; // 
	    else if(fabs(lepeta) < 1.2) TrigEffWeight = 0.891; //0.983;
	    else if(fabs(lepeta) < 2.1) TrigEffWeight = 0.834; //1.004;
	    else TrigEffWeight = 0.786; //1.006;
	  }else if(leppt < 50){
	    if(fabs(lepeta) < 0.9) TrigEffWeight = 0.926; //0.984; // 
	    else if(fabs(lepeta) < 1.2) TrigEffWeight = 0.916; //0.983;
	    else if(fabs(lepeta) < 2.1) TrigEffWeight = 0.856; //1.004;
	    else TrigEffWeight = 0.817; //1.006;
          }else if(leppt < 60){
            if(fabs(lepeta) < 0.9) TrigEffWeight = 0.930; //0.984; // 
            else if(fabs(lepeta) < 1.2) TrigEffWeight = 0.921; //0.983;
            else if(fabs(lepeta) < 2.1) TrigEffWeight = 0.861; //1.004;
            else TrigEffWeight = 0.820; //1.006;
          }else if(leppt < 120){
            if(fabs(lepeta) < 0.9) TrigEffWeight = 0.929; //0.984; // 
            else if(fabs(lepeta) < 1.2) TrigEffWeight = 0.920; //0.983;
            else if(fabs(lepeta) < 2.1) TrigEffWeight = 0.858; //1.004;
            else TrigEffWeight = 0.823; //1.006;
          }else{
            if(fabs(lepeta) < 0.9) TrigEffWeight = 0.925; //0.984; // 
            else if(fabs(lepeta) < 1.2) TrigEffWeight = 0.902; //0.983;
            else if(fabs(lepeta) < 2.1) TrigEffWeight = 0.835; //1.004;
            else TrigEffWeight = 0.773; //1.006;
	  } 

	  //Mini-iso < 0.2 SFs from SUSY Lepton SF: https://jrgonzal.web.cern.ch/jrgonzal/MuonSF/4.MiniIso0.2_Loose/TnP_MuonID_NUM_MiniIsoTight_DENOM_LooseID_VAR_map_pt_eta.png
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
	  
	  //Cut-based ID scale factors from POG TWiki 7.6/fb: https://cmsdoc.cern.ch/cms/Physics/muon/ReferenceEfficiencies/Run2016/25ns/proviSFs_7p65/MuonID_Z_RunBCD_prompt80X_7p65.root
	  if(fabs(lepeta) < 0.9){
	    if(leppt < 30) lepidsf = 0.971;
	    else if(leppt < 40) lepidsf = 0.976;
	    else if(leppt < 50) lepidsf = 0.976;
	    else if(leppt < 60) lepidsf = 0.972;
	    else if(leppt < 100) lepidsf = 0.974;
	    else lepidsf = 0.988;
	  }
	  else if(fabs(lepeta) < 1.2){
	    if(leppt < 30) lepidsf = 0.967;
	    else if(leppt < 40) lepidsf = 0.972;
	    else if(leppt < 50) lepidsf = 0.971;
	    else if(leppt < 60) lepidsf = 0.971;
	    else if(leppt < 100) lepidsf = 0.968;
	    else lepidsf = 1.027;
	  }
	  else if(fabs(lepeta) < 2.1){
	    if(leppt < 30) lepidsf = 0.990;
	    else if(leppt < 40) lepidsf = 0.990;
	    else if(leppt < 50) lepidsf = 0.991;
	    else if(leppt < 60) lepidsf = 0.992;
	    else if(leppt < 100) lepidsf = 0.990;
	    else lepidsf = 1.013;
	  }
	  else {
	    if(leppt < 30) lepidsf = 0.976;
	    else if(leppt < 40) lepidsf = 0.974;
	    else if(leppt < 50) lepidsf = 0.970;
	    else if(leppt < 60) lepidsf = 0.981;
	    else if(leppt < 100) lepidsf = 0.975;
	    else lepidsf = 0.918;
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
	    if((vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu24_v1" || vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu24_v1") && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if((vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu24_v2" || vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu24_v2") && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if((vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu24_v3" || vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu24_v3") && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if((vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu24_v4" || vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu24_v4") && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if((vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu24_v5" || vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu24_v5") && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
	    if((vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoMu24_v6" || vsSelTriggersMu_singleLepCalc->at(itrig) == "HLT_IsoTkMu24_v6") && viSelTriggersMu_singleLepCalc->at(itrig) > 0) isPastTrig = 1;
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
	if(theJetPt_JetSubCalc->at(ijet) < jetPtCut || fabs(theJetEta_JetSubCalc->at(ijet)) > jetEtaCut) continue;

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

	  // ------------------------------------------------------------------------------------------------------------------
	  // B TAGGING fix
	  // ------------------------------------------------------------------------------------------------------------------

	  float bSF = 1.0;
	  float bSFup = 1.0;
	  float bSFdn = 1.0;
	  double bEff = 1.0;
	  float lSF = 1.0;
	  float lSFup = 1.0;
	  float lSFdn = 1.0;
	  double lEff = 1.0;

	  // Set the initial tagged/untagged state
	  bool istagged = theJetCSV_JetSubCalc->at(ijet) > 0.800;

	  if(theJetHFlav_JetSubCalc->at(ijet) == 5 || theJetHFlav_JetSubCalc->at(ijet) == 4){	    

	    int binSF = (std::upper_bound(ptRangeSF.begin(), ptRangeSF.end(), theJetPt_JetSubCalc->at(ijet))-ptRangeSF.begin())-1;
	    float err = SFerr[binSF];
	    if(theJetHFlav_JetSubCalc->at(ijet) == 4) err *= 2;
	    bSF = 0.901114+(1.32145e-05*theJetPt_JetSubCalc->at(ijet));	    
	    bSFup = bSF + err;
	    bSFdn = bSF - err;
	  
	    int bin = (std::upper_bound(ptRangeEff.begin(), ptRangeEff.end(), theJetPt_JetSubCalc->at(ijet))-ptRangeEff.begin())-1;
	    bEff = BtagEff[bin];
	    if(theJetHFlav_JetSubCalc->at(ijet) == 4) bEff *= 0.2;

	    int tag = applySF(istagged,bSF,bEff);
	    int tag_up = applySF(istagged,bSFup,bEff);
	    int tag_dn = applySF(istagged,bSFdn,bEff);

	    theJetBTag_JetSubCalc->at(ijet) = tag;
	    theJetBTag_bSFup_JetSubCalc->at(ijet) = tag_up;
	    theJetBTag_bSFdn_JetSubCalc->at(ijet) = tag_dn;
	    theJetBTag_lSFup_JetSubCalc->at(ijet) = tag;
	    theJetBTag_lSFdn_JetSubCalc->at(ijet) = tag;

	  }else{

	    int binSF = (std::upper_bound(ptRangeSF.begin(), ptRangeSF.end(), theJetPt_JetSubCalc->at(ijet))-ptRangeSF.begin())-1;
	    float pt = theJetPt_JetSubCalc->at(ijet);
	    lSF = 0.980777+(-0.00109334*pt)+(4.2909e-06*pt*pt)+(-2.78512e-09*pt*pt*pt);
	    lSFdn = lSF*(1-(0.0672836+(0.000102309*pt)+(-1.01558e-07*pt*pt)));
	    lSFup = lSF*(1+(0.0672836+(0.000102309*pt)+(-1.01558e-07*pt*pt)));

	    int bin = (std::upper_bound(ptRangeEff.begin(), ptRangeEff.end(), theJetPt_JetSubCalc->at(ijet))-ptRangeEff.begin())-1;
	    lEff = MistagEff[bin];

	    int tag = applySF(istagged,lSF,lEff);
	    int tag_up = applySF(istagged,lSFup,lEff);
	    int tag_dn = applySF(istagged,lSFdn,lEff);

	    theJetBTag_JetSubCalc->at(ijet) = tag;
	    theJetBTag_bSFup_JetSubCalc->at(ijet) = tag;
	    theJetBTag_bSFdn_JetSubCalc->at(ijet) = tag;
	    theJetBTag_lSFup_JetSubCalc->at(ijet) = tag_up;
	    theJetBTag_lSFdn_JetSubCalc->at(ijet) = tag_dn;

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
      if(theJetPt_JetSubCalc_PtOrdered.size() > 0 && theJetPt_JetSubCalc_PtOrdered[0] > JetLeadPtCut){npass_JetLeadPt+=1;isPastJetLeadPtCut=1;}
      
      //check for second high pt jet
      int isPastJetSubLeadPtCut = 0;
      if(theJetPt_JetSubCalc_PtOrdered.size() > 1 && theJetPt_JetSubCalc_PtOrdered[1] > JetSubLeadPtCut){npass_JetSubLeadPt+=1;isPastJetSubLeadPtCut=1;}
      
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
      theJetAK8PrunedMassWtagUncerts_JetSubCalc_PtOrdered.clear();
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
      NJetsTtagged_0p81 = 0;
      deltaR_lepAK8s.clear();
      deltaPhi_lepAK8s.clear();
      mass_lepAK8s.clear();
      minDR_lepAK8 = 1000;
      WJetLeadPt = -99.0;
      TJetLeadPt = -99.0;
      deltaRtopWjet = -99;     deltaPhitopWjet = -99;
      deltaRlepWjet = -99;     deltaPhilepWjet = -99;	  
      deltaRlepTjet = -99;     deltaPhilepTjet = -99;	  

      NJetsWtagged_0p6_shifts.clear();
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

      for(int i = 0; i < 2; i++){
	NJetsWtagged_0p6_shifts.push_back(0);
	NJetsTtagged_0p81_shifts.push_back(0);
	WJetLeadPt_shifts.push_back(-99.0);
	TJetLeadPt_shifts.push_back(-99.0);
	deltaRtopWjet_shifts.push_back(-99.0);  deltaPhitopWjet_shifts.push_back(-99.0); 
	deltaRlepWjet_shifts.push_back(-99.0);  deltaPhilepWjet_shifts.push_back(-99.0); 
	deltaRlepTjet_shifts.push_back(-99.0);  deltaPhilepTjet_shifts.push_back(-99.0); 
      }

      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc_PtOrdered.size(); ijet++){
	
	ak8_lv.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),theJetAK8Energy_JetSubCalc_PtOrdered.at(ijet));

	deltaR_lepAK8s.push_back(lepton_lv.DeltaR(ak8_lv));
	deltaPhi_lepAK8s.push_back(lepton_lv.DeltaPhi(ak8_lv));
	mass_lepAK8s.push_back((lepton_lv+ak8_lv).M());

	if(lepton_lv.DeltaR(ak8_lv) < minDR_lepAK8) minDR_lepAK8 = lepton_lv.DeltaR(ak8_lv);

	float tau21 = theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.at(ijet)/theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.at(ijet);
	float tau32 = theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.at(ijet)/theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.at(ijet);
	float mass = theJetAK8PrunedMassWtagUncerts_JetSubCalc_PtOrdered.at(ijet);
	float massSD = theJetAK8SoftDropMass_JetSubCalc_PtOrdered.at(ijet);

	if(tau21 < 0.6 && mass > 65.0 && mass < 105.0) nWtags += 1;

	// ------------------------------------------------------------------------------------------------------------------
	// MONTE CARLO
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
	  // W TAGGING
	  // ------------------------------------------------------------------------------------------------------------------
	  // SCALE FACTOR ONLY USED ON MATCHED JETS
	  float tau0p6SF = 1.0;
	  float tau0p6SFup = 1.0;
	  float tau0p6SFdn = 1.0;
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
	      else if(isTTV) tau0p6Eff = TTVEff[bin]; // tt+V
	      else tau0p6Eff = WVEff[bin]; // WW, WZ, etc. 
	    }
	  }

	  // Set the initial tagged/untagged state
	  bool isWtagged = (mass > 65) && (mass < 105) && (tau21 < 0.6);
 
	  // IF THE JET IS NOT TRUTH-MATCHED, THESE IFS WILL DO NOTHING, SF == 1
	  int tag_tau0p6 = applySF(isWtagged,tau0p6SF,tau0p6Eff);
	  int tag_tau0p6up = applySF(isWtagged,tau0p6SFup,tau0p6Eff);
	  int tag_tau0p6dn = applySF(isWtagged,tau0p6SFdn,tau0p6Eff);
	  
	  // Now increase the tag count in the right variable	  
	  NJetsWtagged_0p6 += tag_tau0p6;
	  NJetsWtagged_0p6_shifts[0] += tag_tau0p6up;
	  NJetsWtagged_0p6_shifts[1] += tag_tau0p6dn;

	  // Variables related to W-tagged jets
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

	  // ------------------------------------------------------------------------------------------------------------------
	  // TOP TAGGING
	  // ------------------------------------------------------------------------------------------------------------------
	  float topTau81SF = 1.0;
	  float topTau81SFup = 1.0;
	  float topTau81SFdn = 1.0;
	  double topTau81Eff = 1.0;
	  if(isTmatched){	    
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
	      topTau81Eff = TTbarEffTop[bin];
	    }
	  }

	  // Set the initial tagged/untagged state
	  bool isTtagged = (massSD > 105) && (massSD < 220) && (tau32 < 0.81);

	  // IF THE JET IS NOT TRUTH-MATCHED, THESE IFS WILL DO NOTHING, SF == 1
	  int tag_topTau81 = applySF(isTtagged,topTau81SF,topTau81Eff);
	  int tag_topTau81up = applySF(isTtagged,topTau81SFup,topTau81Eff);
	  int tag_topTau81dn = applySF(isTtagged,topTau81SFdn,topTau81Eff);
 
	  // Now increase the tag count in the right variable	  
	  NJetsTtagged_0p81 += tag_topTau81;
	  NJetsTtagged_0p81_shifts[0] += tag_topTau81up;
	  NJetsTtagged_0p81_shifts[1] += tag_topTau81dn;

	  // Variables related to top-tagged jets
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
	}
	// ------------------------------------------------------------------------------------------------------------------
	// DATA
	// ------------------------------------------------------------------------------------------------------------------
	else{
	 
	  theJetAK8Wmatch_JetSubCalc_PtOrdered.push_back(0);
	  theJetAK8Hmatch_JetSubCalc_PtOrdered.push_back(0);
	  theJetAK8Zmatch_JetSubCalc_PtOrdered.push_back(0);
	  theJetAK8Tmatch_JetSubCalc_PtOrdered.push_back(0);
 
	  if(tau21 < 0.6 && mass > 65.0 && mass < 105.0){

	    NJetsWtagged_0p6 += 1;
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
	  if(tau32 < 0.81 && massSD > 105.0 && massSD < 220.0){

	    NJetsTtagged_0p81 += 1;
	    if(NJetsTtagged_0p81 == 1){
	      TJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet);
	      tjet1_lv.SetPtEtaPhiM(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),
				    theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),massSD);
	      deltaRlepTjet = tjet1_lv.DeltaR(lepton_lv);
	      deltaPhilepTjet = tjet1_lv.DeltaPhi(lepton_lv);
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
      EGammaGsfSF           = (float) gsfsf;
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
