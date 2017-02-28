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

enum shift:char{ central, uncert };

double step1::GetBtagSF2016Medium_comb(shift Shift, double pt, double eta){
    if(pt > 1000.) pt = 1000.;
    if(fabs(eta) > 2.4 or pt<20.) return 1.0; 
    switch(Shift){
	case uncert:
	    if(pt<30) return 0.040213499218225479;
	    else if(pt<50) return 0.014046305790543556;
	    else if(pt<70) return 0.012372690252959728;
	    else if(pt<100) return 0.012274007312953472;
	    else if(pt<140) return 0.011465910822153091;
	    else if(pt<200) return 0.012079551815986633;
	    else if(pt<300) return 0.014995276927947998;
	    else if(pt<600) return 0.021414462476968765;
	    else  return 0.032377112656831741;
	case central:
	default:
	    return    0.561694*((1.+(0.31439*pt))/(1.+(0.17756*pt)));
    }//end switch on shift
}

double step1::GetCtagSF2016Medium_comb(shift Shift, double pt, double eta){
  // SFs are identical with 3x uncertainty as B tag
  if(pt > 1000.) pt = 1000.;
  if(fabs(eta) > 2.4 or pt<20.) return 1.0; 
  switch(Shift){
  case uncert: return 3.0 * GetBtagSF2016Medium_comb(uncert, pt, eta);
  case central:
  default: return GetBtagSF2016Medium_comb(central, pt, eta);
  }//end switch on shift
}

double step1::GetLFSF2016Medium( shift Shift, double pt, double eta){
    if(pt > 1000.) pt = 1000.;
    if(fabs(eta) > 2.4 or pt<20.) return 1.;
    switch(Shift){
	case uncert:
	    return  (1.0589+0.000382569*pt+-2.4252e-07*pt*pt+2.20966e-10*pt*pt*pt)*((0.100485+3.95509e-05*pt+-4.90326e-08*pt*pt));
	case central:
	default:
	    return  1.0589+0.000382569*pt+-2.4252e-07*pt*pt+2.20966e-10*pt*pt*pt;
    }//end switch Shift
}//end GetLFSF2016

double step1::GetBtagEfficiency(double pt){
  // Efficiencies from TT powheg sample for Moriond17.
  // See distribution in /uscms_data/d3/jmanagan/EffsAndNewWeights/TagEffsM17/BEff.png
  // Uses hadronFlavour() rather than partonFlavour() as recommended in BTV physics plenary CMS Week 10/2015
  if(pt < 30) return 0.331971;
  else if(pt < 50) return 0.550937;
  else if(pt < 70) return 0.599929;
  else if(pt < 100) return 0.624677;
  else if(pt < 140) return 0.635101;
  else if(pt < 200) return 0.632463;
  else if(pt < 300) return 0.598059;
  else if(pt < 400) return 0.558359;
  else if(pt < 500) return 0.514297;
  else if(pt < 600) return 0.494422;
  else if(pt < 800) return 0.474555;
  else if(pt < 1000) return 0.451810;
  else if(pt < 1200) return 0.427328;
  else return 0.414162;
}

double step1::GetCtagEfficiency(double pt){
  if(pt < 30) return 0.057985;
  else if(pt < 50) return 0.111536;
  else if(pt < 70) return 0.112216;
  else if(pt < 100) return 0.120075;
  else if(pt < 140) return 0.128499;
  else if(pt < 200) return 0.132918;
  else if(pt < 300) return 0.126724;
  else if(pt < 400) return 0.126281;
  else if(pt < 500) return 0.123026;
  else if(pt < 600) return 0.124840;
  else if(pt < 800) return 0.130060;
  else if(pt < 1000) return 0.128022;
  else if(pt < 1200) return 0.134100;
  else return 0.125348;
}

double step1::GetMistagRate(double pt){
  // Mistag rates from TT powheg sample for Moriond17.
  // See distribution in /uscms_data/d3/jmanagan/EffsAndNewWeights/TagEffsM17/BEff.png
  // Uses hadronFlavour() rather than partonFlavour() as recommended in BTV physics plenary CMS Week 10/2015
  if(pt < 30)    return 0.003385;
  else if(pt < 50)   return 0.009673;
  else if(pt < 70)   return 0.008316;
  else if(pt < 100)  return 0.008524;
  else if(pt < 140)  return 0.009092;
  else if(pt < 200)  return 0.011431;
  else if(pt < 300)  return 0.013666;
  else if(pt < 400)  return 0.020405;
  else if(pt < 500)  return 0.023609;
  else if(pt < 600)  return 0.025348;
  else if(pt < 800)  return 0.028858;
  else if(pt < 1000) return 0.030427;
  else if(pt < 1200) return 0.034091;
  else return 0.047619;
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
   
   // Muon tracking efficiencies, https://twiki.cern.ch/twiki/bin/viewauth/CMS/MuonWorkInProgressAndPagResults#Results_on_the_full_2016_data, Feb 16 release for full data
   float tracksf[10] = {0.991237,0.994853, 0.996413,0.997157,0.997512,0.99756,0.996745,0.996996,0.99772,0.998604,0.998321,0.997682,0.995252,0.994919,0.987334};

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
       {0.882629107981,0.935650458396,0.926125554851,0.915223767622,0.908505591325,0.899603137107,0.900584446565,0.894058295964,0.88886135547,0.873863636364,0.858699169453},//800
       {0.886371923428,0.937473105822,0.926757037308,0.915546964127,0.908082018038,0.90164476403,0.892223942466,0.891238483893,0.88670530701,0.87592780686,0.855800964712},//900
       {0.8847226872,0.936903772315,0.923301732126,0.917872864941,0.909074416748,0.904095176433,0.897951634531,0.887102103756,0.88426236848,0.882177390474,0.859137558913},//1000
       {0.87794198139,0.937300280817,0.923460619525,0.916910543384,0.909492787343,0.907819634703,0.901596346041,0.895453390907,0.887547194376,0.876518899188,0.853909918996},//1100
       {0.88404490699,0.938576907665,0.924840827696,0.915264259074,0.910651563049,0.904443197029,0.898597772668,0.888706875155,0.887725001505,0.875015807444,0.855365585749},//1200
       {0.878918074407,0.932072585691,0.926704944926,0.915217391304,0.908792029888,0.90268202852,0.899502823768,0.893329356795,0.885924218412,0.878819969743,0.856432826194},//1300
       {0.882850932388,0.933115693925,0.925258452082,0.915451174289,0.911637193383,0.907109850872,0.900624645088,0.89678589943,0.888164946127,0.878565436242,0.854910436621},//1400
       {0.881720430108,0.928869516832,0.928365384615,0.915705476968,0.908900386404,0.903087120081,0.897435897436,0.894256455922,0.889204792712,0.879637676315,0.856817706153},//1500
       {0.889815095483,0.931134820563,0.922111480251,0.915960803853,0.903744924049,0.902039702572,0.893914263843,0.89407138536,0.887334159388,0.876581444386,0.857387672648},//1600
       {0.873725630478,0.932963009721,0.920225713653,0.911679776959,0.906294706724,0.900040273862,0.894986449864,0.892761958199,0.888896370615,0.878672886785,0.854709261565},//1700
       {0.882001195934,0.931015825781,0.926085396484,0.913360497534,0.903482099068,0.895140436915,0.88953860942,0.891176251212,0.886398281596,0.876747923006,0.855717353254},//1800
     };
   }else if(isBpBp){
     SignalEff = {//BpBp
       {0.881855718292,0.938172776615,0.928374136849,0.917290419162,0.909367934729,0.902499003057,0.892465184912,0.886862771197,0.879104477612,0.854867256637,0.805737006532},//700
       {0.885550647964,0.938596181671,0.92727393045,0.920922570016,0.913541138706,0.9001918363,0.900718033692,0.89012311395,0.884494019227,0.871299689879,0.830545653962},//800
       {0.887010676157,0.939956331878,0.929920780012,0.917938492216,0.912423454408,0.905170741172,0.900320183653,0.896923986986,0.887008704114,0.875215475962,0.837296935187},//900
       {0.888058563367,0.939879759519,0.927424863388,0.921997257401,0.917190733152,0.90581915846,0.901462108731,0.895116876759,0.887732771791,0.88001895863,0.85114793979},//1000
       {0.878986252689,0.938558659916,0.930149899552,0.919942651004,0.912802707335,0.912931734151,0.904592952612,0.8971838027,0.890851124803,0.879906744741,0.852980458316},//1100
       {0.877798081316,0.941631030085,0.928378875138,0.92248186946,0.911320287342,0.910201322841,0.905863817636,0.895905734144,0.894450595975,0.883283063705,0.854208904921},//1200
       {0.882081591466,0.937202210787,0.930324744626,0.923486715056,0.913280562885,0.912234624644,0.904392203703,0.900609312986,0.894434470377,0.88574694154,0.858801732124},//1300
       {0.889914304548,0.940799478601,0.927442591461,0.91753420583,0.912828519386,0.910504451039,0.906728352753,0.903650133819,0.892737806934,0.88486633608,0.860470992521},//1400
       {0.872445820433,0.944218241042,0.928213689482,0.920134040771,0.912471540602,0.906955938269,0.906326530612,0.897157520726,0.893982229402,0.885694167351,0.858649594694},//1500
       {0.886595174263,0.937183737568,0.925330678424,0.91816971311,0.91049218667,0.908432586946,0.905090228124,0.898018366361,0.89333703278,0.885597722154,0.861107866612},//1600
       {0.88127627999,0.939150032196,0.92591119947,0.917994376757,0.912410195847,0.908485709214,0.899108847868,0.901127874615,0.891985346982,0.885985748219,0.860144417233},//1700
       {0.875815140346,0.940646130729,0.930074163766,0.912161260179,0.914282470481,0.903025364164,0.900511807489,0.900189878643,0.892752765343,0.885828343313,0.86008404945},//1800
     };
   }else if(isXX){
     SignalEff = {//X53X53
       {0.886851914605,0.943074961483,0.93237659762,0.926341703594,0.922959415383,0.916790900558,0.906608536026,0.901708936541,0.887334315169,0.878630082115,0.818613690348},//700
       {0.890015668524,0.942851870079,0.937010377822,0.92943003572,0.924872986704,0.914120339211,0.91749193594,0.904017686971,0.902931785196,0.887533572068,0.843917614246},//800
       {0.888011049724,0.943309885788,0.93451146872,0.927802488236,0.924830193964,0.920539126936,0.920277711276,0.90682716705,0.904527725962,0.895711060948,0.860173759758},//900
       {0.887845146598,0.9416651283,0.93638647343,0.930002482181,0.926200462829,0.919989275729,0.917484836584,0.910344123353,0.907314368871,0.900824160628,0.868240483581},//1000
       {0.885167464115,0.939913681968,0.936628120411,0.929869392391,0.924636438068,0.920621899293,0.918717753531,0.916682437547,0.90773381295,0.89904930356,0.876642129105},//1100
       {0.887530304627,0.942044833242,0.935850499973,0.928164571859,0.928728971154,0.921897023464,0.918657033574,0.914663625998,0.908632640202,0.897587191822,0.877439139658},//1200
       {0.883689005366,0.942861847522,0.939229445254,0.929900813552,0.926411191016,0.923938894987,0.92037037037,0.918466103629,0.909518000363,0.901081762676,0.87809903732},//1300
       {0.884255194615,0.939495138002,0.938070506767,0.931117340809,0.926310979093,0.923306721607,0.918570057582,0.919101017716,0.910261641251,0.901643357713,0.880637353772},//1400
       {0.887072049055,0.936874085743,0.93347500693,0.928047556551,0.92161963845,0.924390812638,0.917535389005,0.918262301832,0.908880208333,0.903353927626,0.878233594532},//1500
       {0.884170653907,0.943492478744,0.929453075122,0.931058865123,0.929416282642,0.919454107573,0.923949579832,0.914571444714,0.915165632872,0.904887294193,0.879504893495},//1600
       {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0},//1700
       {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0},//1800
     };
   }
   float TTbarEff[11] = {0.871591160506,0.941302510747,0.9283897909,0.915552183708,0.903871015995,0.891792958732,0.87799522673,0.869734032227,0.855294681361,0.827974276527,0.795208655332};
   float STEff[11] = {0.870911904738,0.945643941514,0.934710724235,0.926644831904,0.921621373766,0.915942028986,0.907449414754,0.91384886798,0.905805765909,0.892826764956,0.873694437697};
   float WVEff[11] = {0.872952123429,0.945897875368,0.937289636847,0.924373288393,0.926175754169,0.906627489389,0.912530712531,0.897670549085,0.902474526929,0.880573248408,0.860740740741};

   // Top tagging efficiencies
   std::vector<float> ptRangeTpTpTop, ptRangeTTbarTop;
   float ptminTTbarTop[9] = {400,450,500,550,600,700,800,1000,1200};
   for (int i=0;i<9;++i) ptRangeTTbarTop.push_back(ptminTTbarTop[i]);
   float ptminTpTpTop[9] = {400,450,500,550,600,700,800,1000,1200};//X53X53
   for (int i=0;i<9;++i) ptRangeTpTpTop.push_back(ptminTpTpTop[i]);
   float TTbarEffTop[9] = {0.710731908673,0.911246812099,0.946258231276,0.950948087531,0.952308954524,0.947643078335,0.94133549608,0.929334428924,0.924661246612};
   float STEffTop[9] = {0.691643703728,0.906228313671,0.941468696261,0.948002294016,0.947021636542,0.941775836972,0.933049300061,0.936046511628,0.933862433862};

   float SignalEffTop[10][9] = {//X53X53
     {0.724620303757,0.899211846191,0.936291859515,0.944579091937,0.94692371772,0.945789586458,0.935492651062,0.913173652695,0.90977443609},
     {0.720768101761,0.907892004154,0.937210055022,0.945094294581,0.944494920294,0.941136208077,0.93661971831,0.924356223176,0.930051813472},
     {0.724299065421,0.904784643301,0.937938576506,0.940539456533,0.944067043362,0.943750614613,0.939160329201,0.925230671333,0.920143884892},
     {0.723555888972,0.891038887845,0.93702487906,0.943868050013,0.9433296466,0.941325202647,0.933387610095,0.930462184874,0.920435510888},
     {0.706017891027,0.891839315242,0.929181103693,0.945251210149,0.946220930233,0.943065231159,0.936117240989,0.930840845279,0.918595371109},
     {0.706572416905,0.885974797664,0.923103809857,0.938941876579,0.943281477238,0.942451135188,0.935289623871,0.926310160428,0.918116871222},
     {0.703368526898,0.873433303491,0.920978890342,0.936481121716,0.942840429532,0.941648216482,0.935452396142,0.926339285714,0.913049112349},
     {0.687741686002,0.876234529316,0.917185109638,0.93502800517,0.93907257226,0.941280976676,0.929876038507,0.923884514436,0.91489965922},
     {0.675073181716,0.87130710477,0.909954158481,0.928911723494,0.937305146274,0.940579646213,0.932647997164,0.921526157947,0.91551008728},
     {0.679444301518,0.863857374392,0.909068746953,0.920785999386,0.932639746077,0.937310063385,0.933625327818,0.923361250175,0.914409413854}
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
	  
	  // Muon tracking SF -- https://twiki.cern.ch/twiki/bin/viewauth/CMS/MuonWorkInProgressAndPagResults#Results_on_the_full_2016_data, Feb 16 version for full data
	  int ebin = -1;
	  if(leptonEta_singleLepCalc < -2.1) ebin = 0;
	  else if(leptonEta_singleLepCalc < -1.6) ebin = 1;
	  else if(leptonEta_singleLepCalc < -1.2) ebin = 2;
	  else if(leptonEta_singleLepCalc < -0.9) ebin = 3;
	  else if(leptonEta_singleLepCalc < -0.6) ebin = 4;
	  else if(leptonEta_singleLepCalc < -0.3) ebin = 5;
	  else if(leptonEta_singleLepCalc < -0.2) ebin = 6;
	  else if(leptonEta_singleLepCalc <  0.2) ebin = 7;
	  else if(leptonEta_singleLepCalc <  0.3) ebin = 8;
	  else if(leptonEta_singleLepCalc <  0.6) ebin = 9;
	  else if(leptonEta_singleLepCalc <  0.9) ebin = 10;
	  else if(leptonEta_singleLepCalc <  1.2) ebin = 11;
	  else if(leptonEta_singleLepCalc <  1.6) ebin = 12;
	  else if(leptonEta_singleLepCalc <  2.1) ebin = 13;
	  else if(leptonEta_singleLepCalc <  2.4) ebin = 14;

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
	  // B TAGGING fix -- from Moriond17 preliminary SFs to Feb 3 release
	  // ----------------------------------------------------------------------------

	  double heavySF = 1.0;
	  double heavySFerr = 0.0;
	  double heavySFup = 1.0;
	  double heavySFdn = 1.0;
	  double heavyEff = 1.0;
	  double lightSF = 1.0;
	  double lightSFerr = 0.0;
	  double lightSFup = 1.0;
	  double lightSFdn = 1.0;
	  double lightEff = 1.0;

	  // Set the initial tagged/untagged state
	  bool istagged = theJetCSV_JetSubCalc->at(ijet) > 0.8484;	  
	  double ijetPt = theJetPt_JetSubCalc->at(ijet);
	  double ijetEta= theJetEta_JetSubCalc->at(ijet);
	  
	  if(theJetHFlav_JetSubCalc->at(ijet) == 5){//b-quarks
		heavySF   = GetBtagSF2016Medium_comb(central, ijetPt, ijetEta);
		heavySFerr= GetBtagSF2016Medium_comb(uncert, ijetPt, ijetEta);
		if(ijetPt>1000){heavySFerr *=2.0;}
		heavySFup = heavySF + heavySFerr;
		heavySFdn = heavySF - heavySFerr;
		heavyEff  = GetBtagEfficiency(ijetPt);

		theJetBTag_JetSubCalc->at(ijet) = applySF(istagged,heavySF,heavyEff);
		theJetBTag_bSFup_JetSubCalc->at(ijet) = applySF(istagged,heavySFup,heavyEff);
		theJetBTag_bSFdn_JetSubCalc->at(ijet) = applySF(istagged,heavySFdn,heavyEff);
		theJetBTag_lSFup_JetSubCalc->at(ijet) = applySF(istagged,heavySF,heavyEff);
		theJetBTag_lSFdn_JetSubCalc->at(ijet) = applySF(istagged,heavySF,heavyEff);
		
	  }else if(theJetHFlav_JetSubCalc->at(ijet) == 4){//c-quarks
		heavySF   = GetCtagSF2016Medium_comb(central, ijetPt, ijetEta);
		heavySFerr= GetCtagSF2016Medium_comb(uncert, ijetPt, ijetEta);
		if(ijetPt>1000){heavySFerr *=2.0;}
		heavySFup = heavySF + heavySFerr;
		heavySFdn = heavySF - heavySFerr;
		heavyEff  = GetCtagEfficiency(ijetPt);
		
		theJetBTag_JetSubCalc->at(ijet) = applySF(istagged,heavySF,heavyEff);
		theJetBTag_bSFup_JetSubCalc->at(ijet) = applySF(istagged,heavySFup,heavyEff);
		theJetBTag_bSFdn_JetSubCalc->at(ijet) = applySF(istagged,heavySFdn,heavyEff);
		theJetBTag_lSFup_JetSubCalc->at(ijet) = applySF(istagged,heavySF,heavyEff);
		theJetBTag_lSFdn_JetSubCalc->at(ijet) = applySF(istagged,heavySF,heavyEff);
		
	  }else{//udsg-quarks
		lightSF   = GetLFSF2016Medium(central, ijetPt, ijetEta);
		lightSFerr= GetLFSF2016Medium(uncert, ijetPt, ijetEta);
		if(ijetPt>1000){lightSFerr *=2.0;}
		lightSFup = lightSF + lightSFerr;
		lightSFdn = lightSF - lightSFerr;
		lightEff  = GetMistagRate(ijetPt);
		
		theJetBTag_JetSubCalc->at(ijet) = applySF(istagged,lightSF,lightEff);
		theJetBTag_bSFup_JetSubCalc->at(ijet) = applySF(istagged,lightSF,lightEff);
		theJetBTag_bSFdn_JetSubCalc->at(ijet) = applySF(istagged,lightSF,lightEff);
		theJetBTag_lSFup_JetSubCalc->at(ijet) = applySF(istagged,lightSFup,lightEff);
		theJetBTag_lSFdn_JetSubCalc->at(ijet) = applySF(istagged,lightSFdn,lightEff);
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

      for(int i = 0; i < 8; i++){
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
	  float taupt0p6SFup = 1.0;
	  float taupt0p6SFdn = 1.0;
	  double tau0p6Eff = 1.0;
	  if(isWmatched && matchedPt >= 200 && mass > 65 && mass < 105){	    
	    // VALUES FOR 80X from TWiki
	    tau0p6SF = 1.002;
	    tau0p6SFup = 1.002+0.028;
	    tau0p6SFdn = 1.002-0.028;
	    taupt0p6SFup = 1.002+0.0453*log(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)/200);
	    taupt0p6SFdn = 1.002-0.0453*log(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet)/200);
	    
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
 	  int tag_tau0p6up = applySF(isWtagged,tau0p6SFup,tau0p6Eff);
	  int tag_tau0p6dn = applySF(isWtagged,tau0p6SFdn,tau0p6Eff);
	  int tag_tau0p6_JMSup = applySF(isWtagged_JMSup,tau0p6SF,tau0p6Eff);
	  int tag_tau0p6_JMSdn = applySF(isWtagged_JMSdn,tau0p6SF,tau0p6Eff);
	  int tag_tau0p6_JMRup = applySF(isWtagged_JMRup,tau0p6SF,tau0p6Eff);
	  int tag_tau0p6_JMRdn = applySF(isWtagged_JMRdn,tau0p6SF,tau0p6Eff);
 	  int tag_taupt0p6up = applySF(isWtagged,taupt0p6SFup,tau0p6Eff);
	  int tag_taupt0p6dn = applySF(isWtagged,taupt0p6SFdn,tau0p6Eff);
	  
	  // Now increase the tag count in the right variable	  
	  NJetsWtagged_0p6 += tag_tau0p6;
	  NJetsWtagged_0p6_shifts[0] += tag_tau0p6up;
	  NJetsWtagged_0p6_shifts[1] += tag_tau0p6dn;
	  NJetsWtagged_0p6_shifts[2] += tag_tau0p6_JMSup;
	  NJetsWtagged_0p6_shifts[3] += tag_tau0p6_JMSdn;
	  NJetsWtagged_0p6_shifts[4] += tag_tau0p6_JMRup;
	  NJetsWtagged_0p6_shifts[5] += tag_tau0p6_JMRdn;
	  NJetsWtagged_0p6_shifts[6] += tag_taupt0p6up;
	  NJetsWtagged_0p6_shifts[7] += tag_taupt0p6dn;

	  if(tag_tau0p6){NJetsWtagged_0p6_notTtagged += tag_tau0p6-tag_topTau81;}
	  if(tag_tau0p6up){NJetsWtagged_0p6_notTtagged_shifts[0] += tag_tau0p6up-tag_topTau81up;}
	  if(tag_tau0p6dn){NJetsWtagged_0p6_notTtagged_shifts[1] += tag_tau0p6dn-tag_topTau81dn;}
	  if(tag_tau0p6_JMSup){NJetsWtagged_0p6_notTtagged_shifts[2] += tag_tau0p6_JMSup-tag_topTau81_JMSup;}
	  if(tag_tau0p6_JMSdn){NJetsWtagged_0p6_notTtagged_shifts[3] += tag_tau0p6_JMSdn-tag_topTau81_JMSdn;}
	  if(tag_tau0p6_JMRup){NJetsWtagged_0p6_notTtagged_shifts[4] += tag_tau0p6_JMRup-tag_topTau81_JMRup;}
	  if(tag_tau0p6_JMRdn){NJetsWtagged_0p6_notTtagged_shifts[5] += tag_tau0p6_JMRdn-tag_topTau81_JMRdn;}
	  if(tag_taupt0p6up){NJetsWtagged_0p6_notTtagged_shifts[6] += tag_taupt0p6up-tag_topTau81up;}
	  if(tag_taupt0p6dn){NJetsWtagged_0p6_notTtagged_shifts[7] += tag_taupt0p6dn-tag_topTau81dn;}

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
	  if(isWtagged){NJetsWtagged_0p6_notTtagged += isWtagged-isTtagged;}
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
