//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Nov 16 20:39:17 2015 by ROOT version 6.02/05
// from TTree ljmet/ljmet
// found on file: /eos/uscms/store/user/lpcljm/LJMet_1lep_110915/X53X53_M-800_RH_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns/X53X53_M-800_RH_TuneCUETP8M1_13TeV-madgraph-pythia8_25ns_1.root
//////////////////////////////////////////////////////////

#ifndef step1_h
#define step1_h

#include <iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TH1.h"

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "TLorentzVector.h"

enum shift:char;

using namespace std;

class step1 {
public :
   TTree          *inputTree;   //!pointer to the analyzed TTree or TChain
   TFile          *inputFile, *outputFile;
   Int_t           fCurrent; //!current Tree number in a TChain

   Bool_t          isSig;
   Bool_t          isTpTp;
   Bool_t          isBpBp;
   Bool_t          isXX;
   Bool_t          isTOP;
   Bool_t          isMadgraphBkg;
   Bool_t          isMC;
   Bool_t          isSM;
   Bool_t          isSE;
   Bool_t          isTT;
   Bool_t          isTTV;
   Bool_t          isVV;
   Bool_t          isSTt;
   Bool_t          isSTtW;
   Bool_t          isTTincMtt0to1000;
   Bool_t          isTTincMtt0to700;
   Bool_t          isTTincMtt700to1000;
   Bool_t          isTTincMtt1000toInf;
   Bool_t          outBWBW;
   Bool_t          outTZBW;
   Bool_t          outTHBW;
   Bool_t          outTZTH;
   Bool_t          outTZTZ;
   Bool_t          outTHTH;
   Bool_t          outTWTW;
   Bool_t          outBZTW;
   Bool_t          outBHTW;
   Bool_t          outBZBH;
   Bool_t          outBZBZ;
   Bool_t          outBHBH;
   Int_t           SigMass;
   Int_t           pileupIndex;
   Bool_t          isNominal;
   Bool_t          isBUp;
   Bool_t          isBDn;
   Bool_t          isLUp;
   Bool_t          isLDn;

   // Pileup distributions -- 31Mar2018 Data vs RunIIFall17MC
   std::vector<std::vector<float>> pileupweight;
   std::vector<std::vector<float>> pileupweightUp;
   std::vector<std::vector<float>> pileupweightDn;
   
   // Fixed size dimensions of array or collections stored in the TTree if any.

   // NEW BRANCHES
   Float_t dnn_WJets;
   Float_t dnn_ttbar;
   Float_t dnn_Tprime;

   vector<int>    theJetAK8Truth_JetSubCalc_PtOrdered;
   vector<double> deltaR_leptonicparticle_AK8_PtOrdered; 
   vector<int>    leptonicTprimeJetIDs_DeepAK8;
   vector<int>    hadronicTprimeJetIDs_DeepAK8;
   vector<int>    leptonicBprimeJetIDs_DeepAK8;
   vector<int>    hadronicBprimeJetIDs_DeepAK8;

   vector<double> dnn_B_DeepAK8Calc_PtOrdered;
   vector<double> dnn_T_DeepAK8Calc_PtOrdered;
   vector<double> dnn_H_DeepAK8Calc_PtOrdered;
   vector<double> dnn_W_DeepAK8Calc_PtOrdered;
   vector<double> dnn_Z_DeepAK8Calc_PtOrdered;
   vector<double> dnn_J_DeepAK8Calc_PtOrdered;

   Float_t DeepAK8SF_TeffUp;
   Float_t DeepAK8SF_HeffUp;
   Float_t DeepAK8SF_ZeffUp;
   Float_t DeepAK8SF_WeffUp;
   Float_t DeepAK8SF_BeffUp;
   Float_t DeepAK8SF_JeffUp;
   Float_t DeepAK8SF_TmisUp;
   Float_t DeepAK8SF_HmisUp;
   Float_t DeepAK8SF_ZmisUp;
   Float_t DeepAK8SF_WmisUp;
   Float_t DeepAK8SF_BmisUp;
   Float_t DeepAK8SF_JmisUp;
   Float_t DeepAK8SF_TeffDn;
   Float_t DeepAK8SF_HeffDn;
   Float_t DeepAK8SF_ZeffDn;
   Float_t DeepAK8SF_WeffDn;
   Float_t DeepAK8SF_BeffDn;
   Float_t DeepAK8SF_JeffDn;
   Float_t DeepAK8SF_TmisDn;
   Float_t DeepAK8SF_HmisDn;
   Float_t DeepAK8SF_ZmisDn;
   Float_t DeepAK8SF_WmisDn;
   Float_t DeepAK8SF_BmisDn;
   Float_t DeepAK8SF_JmisDn;

   Float_t Tprime1_DeepAK8_Mass;
   Float_t Tprime2_DeepAK8_Mass;
   Float_t Tprime1_DeepAK8_Pt;
   Float_t Tprime2_DeepAK8_Pt;
   Float_t Tprime1_DeepAK8_Eta;
   Float_t Tprime2_DeepAK8_Eta;
   Float_t Tprime1_DeepAK8_Phi;
   Float_t Tprime2_DeepAK8_Phi;
   Float_t Tprime1_DeepAK8_deltaR;
   Float_t Tprime2_DeepAK8_deltaR;
   Float_t Bprime1_DeepAK8_Mass;
   Float_t Bprime2_DeepAK8_Mass;
   Float_t Bprime1_DeepAK8_Pt;
   Float_t Bprime2_DeepAK8_Pt;
   Float_t Bprime1_DeepAK8_Eta;
   Float_t Bprime2_DeepAK8_Eta;
   Float_t Bprime1_DeepAK8_Phi;
   Float_t Bprime2_DeepAK8_Phi;
   Float_t Bprime1_DeepAK8_deltaR;
   Float_t Bprime2_DeepAK8_deltaR;

   Bool_t validTDecay_DeepAK8;
   Bool_t validBDecay_DeepAK8;

   Bool_t isLeptonic_t;
   Bool_t isLeptonic_W;

   Bool_t taggedBWBW_DeepAK8;
   Bool_t taggedTHBW_DeepAK8;
   Bool_t taggedTHTH_DeepAK8;
   Bool_t taggedTZBW_DeepAK8;
   Bool_t taggedTZTH_DeepAK8;
   Bool_t taggedTZTZ_DeepAK8;
   Bool_t taggedTWTW_DeepAK8;
   Bool_t taggedBHTW_DeepAK8;
   Bool_t taggedBZTW_DeepAK8;

   Float_t highPtAK8Jet1_SoftDropCorrectedMass;
   Float_t highPtAK8Jet2_SoftDropCorrectedMass;
   Float_t highPtAK8Jet3_SoftDropCorrectedMass;

   Float_t W_mass;
   Float_t t_mass;
   Float_t W_pt;
   Float_t t_pt;
   Float_t W_dRLep;
   Float_t t_dRWb;

   Float_t probSum_DeepAK8_decay;
   Float_t probSum_DeepAK8_all;
   Float_t probSum_DeepAK8_four;

   Int_t nB_DeepAK8;
   Int_t nH_DeepAK8;
   Int_t nJ_DeepAK8;
   Int_t nT_DeepAK8;
   Int_t nW_DeepAK8;
   Int_t nZ_DeepAK8;

   Int_t           isElectron;
   Int_t           isMuon;
   Int_t           MCPastTrigger;
   Int_t           MCPastTriggerOR;
   Int_t           MCPastTriggerLepTight;
   Int_t           MCPastTriggerHTTight;
   Int_t           DataPastTrigger;
   Int_t           DataPastTriggerOR;
   Int_t           DataPastTriggerLepTight;
   Int_t           DataPastTriggerHTTight;
   Float_t         pileupWeight;
   Float_t         pileupWeightUp;
   Float_t         pileupWeightDown;
   Float_t         TrigEffAltWeight;
   Float_t         TrigEffWeight;
   Float_t         TrigEffWeightUncert;
   Float_t         isoSF;
   Float_t         lepIdSF;
   Float_t         MuTrkSF;
   Float_t         EGammaGsfSF;
   Float_t         JetSF_80X;
   Float_t         JetSFup_80X;
   Float_t         JetSFdn_80X;
   Float_t         JetSF_pTNbwflat;
   Float_t         JetSFup_pTNbwflat;
   Float_t         JetSFdn_pTNbwflat;
   Float_t         JetSFupwide_pTNbwflat;
   Float_t         JetSFdnwide_pTNbwflat;
   Float_t         HTSF_Exp;
   Float_t         HTSF_ExpUp;
   Float_t         HTSF_ExpDn;
   Float_t         HTSF_Pol;
   Float_t         HTSF_PolUp;
   Float_t         HTSF_PolDn;
   vector<double>  renormWeights;
   vector<double>  alphaSWeights;
   vector<double>  pdfWeights;
   vector<double>  pdfNewWeights;
   float_t         pdfNewNominalWeight;

   Float_t         leptonPt_singleLepCalc;
   Float_t         leptonEta_singleLepCalc;
   Float_t         leptonPhi_singleLepCalc;
   Float_t         leptonEnergy_singleLepCalc;
   Float_t         leptonMVAValue_singleLepCalc;
   Float_t         leptonMiniIso_singleLepCalc;
   Float_t         leptonRelIso_singleLepCalc;
   Float_t         leptonDxy_singleLepCalc;
   Float_t         leptonDz_singleLepCalc;
   Int_t           leptonCharge_singleLepCalc;
   Int_t           elTrigPresel_singleLepCalc;

   Int_t           NJets_JetSubCalc;
   Int_t           NJetsCSV_JetSubCalc;
   Int_t           NJetsCSVwithSF_JetSubCalc;
   Int_t           NJetsCSVnotH_JetSubCalc;
   Int_t           NJetsCSVnotPH_JetSubCalc;

   vector<int>     maxProb_JetSubCalc_PtOrdered;
   vector<int>     dnn_largest_BestCalc_PtOrdered;
   vector<int>     dnn_largest_DeepAK8Calc_PtOrdered;
   vector<int>     decorr_largest_DeepAK8Calc_PtOrdered;
   vector<int>     theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered;
   vector<int>     theJetAK8SDSubjetSize_JetSubCalc_PtOrdered;
   vector<int>     NJetsCSVwithSF_JetSubCalc_shifts;
   vector<int>     NJetsCSVnotH_JetSubCalc_shifts;
   vector<int>     NJetsCSVnotPH_JetSubCalc_shifts;
   vector<double>  theJetPt_JetSubCalc_PtOrdered;
   vector<double>  theJetEta_JetSubCalc_PtOrdered;
   vector<double>  theJetPhi_JetSubCalc_PtOrdered;
   vector<double>  theJetEnergy_JetSubCalc_PtOrdered;
   vector<double>  theJetDeepCSVb_JetSubCalc_PtOrdered;
   vector<double>  theJetDeepCSVbb_JetSubCalc_PtOrdered;
   vector<int>     theJetHFlav_JetSubCalc_PtOrdered;
   vector<int>     theJetPFlav_JetSubCalc_PtOrdered;
   vector<int>     theJetBTag_JetSubCalc_PtOrdered;
   vector<int>     theJetBTag_bSFup_JetSubCalc_PtOrdered;
   vector<int>     theJetBTag_bSFdn_JetSubCalc_PtOrdered;
   vector<int>     theJetBTag_lSFup_JetSubCalc_PtOrdered;
   vector<int>     theJetBTag_lSFdn_JetSubCalc_PtOrdered;

   Float_t         AK4HTpMETpLepPt;
   Float_t         AK4HT;

   Float_t         minMleppJet;
   Float_t         deltaR_lepMinMlj;
   Float_t         minDR_lepJet;
   Float_t         ptRel_lepJet;
   Float_t         ptRel_lepAK8;
   Float_t         minDPhi_MetJet;
   Float_t         MT_lepMet;
   Float_t         MT_lepMetmod;
   vector<double>  deltaR_lepJets;
   vector<double>  deltaPhi_lepJets;
   vector<double>  mass_lepJets;

   Float_t         BJetLeadPt;
   Float_t         minMleppBjetPt;
   Float_t         minMleppBjet;
   Float_t         deltaR_lepMinMlb;
   vector<double>  BJetLeadPt_shifts;
   vector<double>  minMleppBjetPt_shifts;
   vector<double>  minMleppBjet_shifts;
   vector<double>  deltaR_lepBJets;
   vector<double>  deltaR_lepBJets_bSFup;
   vector<double>  deltaR_lepBJets_bSFdn;
   vector<double>  deltaR_lepBJets_lSFup;
   vector<double>  deltaR_lepBJets_lSFdn;
   vector<double>  deltaPhi_lepBJets;
   vector<double>  deltaPhi_lepBJets_bSFup;
   vector<double>  deltaPhi_lepBJets_bSFdn;
   vector<double>  deltaPhi_lepBJets_lSFup;
   vector<double>  deltaPhi_lepBJets_lSFdn;
   vector<double>  mass_lepBJets;
   vector<double>  mass_lepBJets_bSFup;
   vector<double>  mass_lepBJets_bSFdn;
   vector<double>  mass_lepBJets_lSFup;
   vector<double>  mass_lepBJets_lSFdn;

   Int_t           NJetsAK8_JetSubCalc;
   Float_t         minDR_leadAK8otherAK8;
   Float_t         minDR_lepAK8;
   vector<double>  deltaR_lepAK8s;
   vector<double>  deltaPhi_lepAK8s;
   vector<double>  mass_lepAK8s;
   vector<double>  theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8PrunedMassWtagUncerts_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8PrunedMassWtagUncerts_JMSup_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8PrunedMassWtagUncerts_JMSdn_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8PrunedMassWtagUncerts_JMRup_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8PrunedMassWtagUncerts_JMRdn_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8NjettinessTau1_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8NjettinessTau2_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8NjettinessTau3_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8CHSTau1_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8CHSTau2_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8CHSTau3_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8Pt_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8Eta_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8Phi_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8Mass_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8Energy_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8SoftDropRaw_PtOrdered;
   vector<double>  theJetAK8SoftDropCorr_PtOrdered;
   vector<double>  theJetAK8SoftDrop_PtOrdered;
   vector<double>  theJetAK8DoubleB_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8PUPPISoftDrop_JMSup_PtOrdered;
   vector<double>  theJetAK8PUPPISoftDrop_JMSdn_PtOrdered;
   vector<double>  theJetAK8PUPPISoftDrop_JMRup_PtOrdered;
   vector<double>  theJetAK8PUPPISoftDrop_JMRdn_PtOrdered;
   vector<double>  theJetAK8SDSubjetNCSVM_PtOrdered;
   vector<double>  theJetAK8SDSubjetNCSVM_bSFup_PtOrdered;
   vector<double>  theJetAK8SDSubjetNCSVM_bSFdn_PtOrdered;
   vector<double>  theJetAK8SDSubjetNCSVM_lSFup_PtOrdered;
   vector<double>  theJetAK8SDSubjetNCSVM_lSFdn_PtOrdered;
   vector<int>     theJetAK8Wmatch_JetSubCalc_PtOrdered;
   vector<int>     theJetAK8Tmatch_JetSubCalc_PtOrdered;
   vector<int>     theJetAK8Zmatch_JetSubCalc_PtOrdered;
   vector<int>     theJetAK8Hmatch_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8MatchedPt_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8SoftDropCorr_JetSubCalc_PtOrdered;
   vector<int>     theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered;
   vector<int>     theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered;

   Float_t         topPt;
   Float_t         topPtGen;
   Float_t         topMass;
   Float_t         tmass;
   Float_t         wmass;
   Float_t         genTopPt;
   Float_t         genAntiTopPt;
   Float_t         topPtWeight13TeV;

   // Declaration of leaf types
   Bool_t          flagBadMu_singleLepCalc;
   Bool_t          flagDupMu_singleLepCalc;
   Bool_t          isBHBH_TpTpCalc;
   Bool_t          isBHTW_TpTpCalc;
   Bool_t          isBWBW_TpTpCalc;
   Bool_t          isBZBH_TpTpCalc;
   Bool_t          isBZBZ_TpTpCalc;
   Bool_t          isBZTW_TpTpCalc;
   Bool_t          isTHBW_TpTpCalc;
   Bool_t          isTHTH_TpTpCalc;
   Bool_t          isTWTW_TpTpCalc;
   Bool_t          isTZBW_TpTpCalc;
   Bool_t          isTZTH_TpTpCalc;
   Bool_t          isTZTZ_TpTpCalc;
   Bool_t          isTau_singleLepCalc;
   Int_t           NLeptonDecays_TpTpCalc;
   Int_t           NPartonsfromHEPUEP_singleLepCalc;
   Int_t           dataE_singleLepCalc;
   Int_t           dataM_singleLepCalc;
   Int_t           genTDLID_singleLepCalc;
   Int_t           lumi_CommonCalc;
   Int_t           nAllJets_CommonCalc;
   Int_t           nLooseMuons_CommonCalc;
   //   Int_t           nPV_singleLepCalc;
   Int_t           nPileupInteractions_singleLepCalc;
   Int_t           nSelBtagJets_CommonCalc;
   Int_t           nSelElectrons_CommonCalc;
   Int_t           nSelJets_CommonCalc;
   Int_t           nTightMuons_CommonCalc;
   Int_t           nTrueInteractions_singleLepCalc;
   Int_t           run_CommonCalc;
   Long64_t        event_CommonCalc;
   Double_t        AK4HT_singleLepCalc;
   Double_t        HTfromHEPUEP_singleLepCalc;
   Double_t        L1NonPrefiringProbDown_CommonCalc;
   Double_t        L1NonPrefiringProbUp_CommonCalc;
   Double_t        L1NonPrefiringProb_CommonCalc;
   Double_t        LHEweightorig_singleLepCalc;
   Double_t        MCWeight_singleLepCalc;
   Double_t        corr_met_jerdn_phi_singleLepCalc;
   Double_t        corr_met_jerdn_singleLepCalc;
   Double_t        corr_met_jerup_phi_singleLepCalc;
   Double_t        corr_met_jerup_singleLepCalc;
   Double_t        corr_met_jesdn_phi_singleLepCalc;
   Double_t        corr_met_jesdn_singleLepCalc;
   Double_t        corr_met_jesup_phi_singleLepCalc;
   Double_t        corr_met_jesup_singleLepCalc;
   Double_t        corr_met_phi_singleLepCalc;
   Double_t        corr_met_singleLepCalc;
   Double_t        corr_metmod_phi_singleLepCalc;
   Double_t        corr_metmod_singleLepCalc;
   Double_t        corr_metnohf_phi_singleLepCalc;
   Double_t        corr_metnohf_singleLepCalc;
   Double_t        genTDLEnergy_singleLepCalc;
   Double_t        genTDLEta_singleLepCalc;
   Double_t        genTDLPhi_singleLepCalc;
   Double_t        genTDLPt_singleLepCalc;
   Double_t        met_phi_singleLepCalc;
   Double_t        met_singleLepCalc;
   Double_t        metmod_phi_singleLepCalc;
   Double_t        metmod_singleLepCalc;
   Double_t        metnohf_phi_singleLepCalc;
   Double_t        metnohf_singleLepCalc;
   Double_t        theJetHT_JetSubCalc;
   Double_t        theJetLeadPt_JetSubCalc;
   Double_t        theJetSubLeadPt_JetSubCalc;
   Double_t        ttbarMass_TTbarMassCalc;
   vector<int>     *AK4JetBTag_bSFdn_singleLepCalc;
   vector<int>     *AK4JetBTag_bSFup_singleLepCalc;
   vector<int>     *AK4JetBTag_lSFdn_singleLepCalc;
   vector<int>     *AK4JetBTag_lSFup_singleLepCalc;
   vector<int>     *AK4JetBTag_singleLepCalc;
   vector<int>     *AK4JetFlav_singleLepCalc;
   vector<int>     *HadronicVHtID_JetSubCalc;
   vector<int>     *HadronicVHtStatus_JetSubCalc;
   vector<int>     *HdecayID_TpTpCalc;
   vector<int>     *HdecayIndex_TpTpCalc;
   vector<int>     *LHEweightids_singleLepCalc;
   vector<int>     *LeptonID_TpTpCalc;
   vector<int>     *LeptonParentID_TpTpCalc;
   vector<int>     *NewPDFids_singleLepCalc;
   vector<int>     *WdecayID_TpTpCalc;
   vector<int>     *WdecayIndex_TpTpCalc;
   vector<int>     *ZdecayID_TpTpCalc;
   vector<int>     *ZdecayIndex_TpTpCalc;
   vector<int>     *allTopsID_TTbarMassCalc;
   vector<int>     *allTopsStatus_TTbarMassCalc;
   vector<int>     *bPrimeID_TpTpCalc;
   vector<int>     *bPrimeNDaughters_TpTpCalc;
   vector<int>     *bPrimeStatus_TpTpCalc;
   vector<int>     *bosonID_TpTpCalc;
   vector<int>     *decorr_largest_DeepAK8Calc;
   vector<int>     *dnn_largest_BestCalc;
   vector<int>     *dnn_largest_DeepAK8Calc;
   vector<int>     *elChargeConsistent_singleLepCalc;
   vector<int>     *elCharge_singleLepCalc;
   vector<int>     *elCtfCharge_singleLepCalc;
   vector<int>     *elGsfCharge_singleLepCalc;
   vector<int>     *elIsEBEE_singleLepCalc;
   /* vector<int>     *elIsMVALooseIso_singleLepCalc; */
   /* vector<int>     *elIsMVALoose_singleLepCalc; */
   /* vector<int>     *elIsMVATight80_singleLepCalc; */
   /* vector<int>     *elIsMVATight90_singleLepCalc; */
   /* vector<int>     *elIsMVATightIso80_singleLepCalc; */
   /* vector<int>     *elIsMVATightIso90_singleLepCalc; */
   vector<int>     *elMHits_singleLepCalc;
   vector<int>     *elMatched_singleLepCalc;
   vector<int>     *elMother_id_singleLepCalc;
   vector<int>     *elMother_status_singleLepCalc;
   vector<int>     *elNotConversion_singleLepCalc;
   vector<int>     *elNumberOfMothers_singleLepCalc;
   vector<int>     *elPdgId_singleLepCalc;
   vector<int>     *elScPixCharge_singleLepCalc;
   vector<int>     *elStatus_singleLepCalc;
   vector<int>     *elVtxFitConv_singleLepCalc;
   vector<int>     *electron_1_hltmatched_singleLepCalc;
   vector<int>     *genBSLID_singleLepCalc;
   vector<int>     *genID_singleLepCalc;
   vector<int>     *genIndex_singleLepCalc;
   vector<int>     *genMotherID_singleLepCalc;
   vector<int>     *genMotherIndex_singleLepCalc;
   vector<int>     *genStatus_singleLepCalc;
   vector<int>     *genTtbarIdCategory_TTbarMassCalc;
   vector<int>     *genTtbarId_TTbarMassCalc;
   vector<int>     *maxProb_JetSubCalc;
   vector<int>     *muCharge_singleLepCalc;
   vector<int>     *muGlobal_singleLepCalc;
   vector<int>     *muIsGlobalHighPt_singleLepCalc;
   vector<int>     *muIsLoose_singleLepCalc;
   vector<int>     *muIsMediumPrompt_singleLepCalc;
   vector<int>     *muIsMedium_singleLepCalc;
   vector<int>     *muIsMiniIsoLoose_singleLepCalc;
   vector<int>     *muIsMiniIsoMedium_singleLepCalc;
   vector<int>     *muIsMiniIsoTight_singleLepCalc;
   vector<int>     *muIsMiniIsoVeryTight_singleLepCalc;
   vector<int>     *muIsMvaLoose_singleLepCalc;
   vector<int>     *muIsMvaMedium_singleLepCalc;
   vector<int>     *muIsMvaTight_singleLepCalc;
   vector<int>     *muIsTight_singleLepCalc;
   vector<int>     *muIsTrkHighPt_singleLepCalc;
   vector<int>     *muMatched_singleLepCalc;
   vector<int>     *muMother_id_singleLepCalc;
   vector<int>     *muMother_status_singleLepCalc;
   vector<int>     *muNMatchedStations_singleLepCalc;
   vector<int>     *muNTrackerLayers_singleLepCalc;
   vector<int>     *muNValMuHits_singleLepCalc;
   vector<int>     *muNValPixelHits_singleLepCalc;
   vector<int>     *muNumberOfMothers_singleLepCalc;
   vector<int>     *muPdgId_singleLepCalc;
   vector<int>     *muStatus_singleLepCalc;
   vector<int>     *muon_1_hltmatched_singleLepCalc;
   vector<int>     *quarkID_TpTpCalc;
   vector<int>     *tPrimeID_TpTpCalc;
   vector<int>     *tPrimeNDaughters_TpTpCalc;
   vector<int>     *tPrimeStatus_TpTpCalc;
   vector<int>     *theJetAK8SDSubjetBTag_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetHFlav_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetIndex_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetNDeepCSVL_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetNDeepCSVM_bSFdn_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetNDeepCSVM_bSFup_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetNDeepCSVM_lSFdn_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetNDeepCSVM_lSFup_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetSize_JetSubCalc;
   vector<int>     *theJetAK8nDaughters_JetSubCalc;
   vector<int>     *theJetBTag_JetSubCalc;
   vector<int>     *theJetBTag_bSFdn_JetSubCalc;
   vector<int>     *theJetBTag_bSFup_JetSubCalc;
   vector<int>     *theJetBTag_lSFdn_JetSubCalc;
   vector<int>     *theJetBTag_lSFup_JetSubCalc;
   vector<int>     *theJetHFlav_JetSubCalc;
   vector<int>     *theJetPFlav_JetSubCalc;
   vector<int>     *theJetnDaughters_JetSubCalc;
   vector<int>     *topID_TTbarMassCalc;
   vector<int>     *topWID_TTbarMassCalc;
   vector<int>     *topbID_TTbarMassCalc;
   vector<int>     *viSelMCTriggersEl_singleLepCalc;
   vector<int>     *viSelMCTriggersMu_singleLepCalc;
   vector<int>     *viSelTriggersEl_singleLepCalc;
   vector<int>     *viSelTriggersMu_singleLepCalc;
   vector<double>  *AK4JetBDeepCSVb_singleLepCalc;
   vector<double>  *AK4JetBDeepCSVbb_singleLepCalc;
   vector<double>  *AK4JetBDeepCSVc_singleLepCalc;
   vector<double>  *AK4JetBDeepCSVudsg_singleLepCalc;
   vector<double>  *AK4JetBDisc_singleLepCalc;
   vector<double>  *AK4JetEnergy_singleLepCalc;
   vector<double>  *AK4JetEta_singleLepCalc;
   vector<double>  *AK4JetPhi_singleLepCalc;
   vector<double>  *AK4JetPt_singleLepCalc;
   vector<double>  *AK8JetCSV_BestCalc;
   vector<double>  *AK8JetCSV_singleLepCalc;
   vector<double>  *AK8JetDoubleB_singleLepCalc;
   vector<double>  *AK8JetEnergy_BestCalc;
   vector<double>  *AK8JetEnergy_singleLepCalc;
   vector<double>  *AK8JetEta_BestCalc;
   vector<double>  *AK8JetEta_singleLepCalc;
   vector<double>  *AK8JetPhi_BestCalc;
   vector<double>  *AK8JetPhi_singleLepCalc;
   vector<double>  *AK8JetPt_BestCalc;
   vector<double>  *AK8JetPt_singleLepCalc;
   vector<double>  *HadronicVHtD0E_JetSubCalc;
   vector<double>  *HadronicVHtD0Eta_JetSubCalc;
   vector<double>  *HadronicVHtD0Phi_JetSubCalc;
   vector<double>  *HadronicVHtD0Pt_JetSubCalc;
   vector<double>  *HadronicVHtD1E_JetSubCalc;
   vector<double>  *HadronicVHtD1Eta_JetSubCalc;
   vector<double>  *HadronicVHtD1Phi_JetSubCalc;
   vector<double>  *HadronicVHtD1Pt_JetSubCalc;
   vector<double>  *HadronicVHtD2E_JetSubCalc;
   vector<double>  *HadronicVHtD2Eta_JetSubCalc;
   vector<double>  *HadronicVHtD2Phi_JetSubCalc;
   vector<double>  *HadronicVHtD2Pt_JetSubCalc;
   vector<double>  *HadronicVHtEnergy_JetSubCalc;
   vector<double>  *HadronicVHtEta_JetSubCalc;
   vector<double>  *HadronicVHtPhi_JetSubCalc;
   vector<double>  *HadronicVHtPt_JetSubCalc;
   vector<double>  *HdecayEnergy_TpTpCalc;
   vector<double>  *HdecayEta_TpTpCalc;
   vector<double>  *HdecayPhi_TpTpCalc;
   vector<double>  *HdecayPt_TpTpCalc;
   vector<double>  *LHEweights_singleLepCalc;
   vector<double>  *LeptonEnergy_TpTpCalc;
   vector<double>  *LeptonEta_TpTpCalc;
   vector<double>  *LeptonPhi_TpTpCalc;
   vector<double>  *LeptonPt_TpTpCalc;
   vector<double>  *NewPDFweightsBase_singleLepCalc;
   vector<double>  *NewPDFweights_singleLepCalc;
   vector<double>  *WdecayEnergy_TpTpCalc;
   vector<double>  *WdecayEta_TpTpCalc;
   vector<double>  *WdecayPhi_TpTpCalc;
   vector<double>  *WdecayPt_TpTpCalc;
   vector<double>  *ZdecayEnergy_TpTpCalc;
   vector<double>  *ZdecayEta_TpTpCalc;
   vector<double>  *ZdecayPhi_TpTpCalc;
   vector<double>  *ZdecayPt_TpTpCalc;
   vector<double>  *allTopsEnergy_TTbarMassCalc;
   vector<double>  *allTopsEta_TTbarMassCalc;
   vector<double>  *allTopsPhi_TTbarMassCalc;
   vector<double>  *allTopsPt_TTbarMassCalc;
   vector<double>  *bPrimeEnergy_TpTpCalc;
   vector<double>  *bPrimeEta_TpTpCalc;
   vector<double>  *bPrimeMass_TpTpCalc;
   vector<double>  *bPrimePhi_TpTpCalc;
   vector<double>  *bPrimePt_TpTpCalc;
   vector<double>  *bosonEnergy_TpTpCalc;
   vector<double>  *bosonEta_TpTpCalc;
   vector<double>  *bosonPhi_TpTpCalc;
   vector<double>  *bosonPt_TpTpCalc;
   vector<double>  *decorr_B_DeepAK8Calc;
   vector<double>  *decorr_C_DeepAK8Calc;
   vector<double>  *decorr_H_DeepAK8Calc;
   vector<double>  *decorr_J_DeepAK8Calc;
   vector<double>  *decorr_T_DeepAK8Calc;
   vector<double>  *decorr_W_DeepAK8Calc;
   vector<double>  *decorr_Z_DeepAK8Calc;
   vector<double>  *dnn_B_BestCalc;
   vector<double>  *dnn_B_DeepAK8Calc;
   vector<double>  *dnn_C_DeepAK8Calc;
   vector<double>  *dnn_H_DeepAK8Calc;
   vector<double>  *dnn_Higgs_BestCalc;
   vector<double>  *dnn_J_DeepAK8Calc;
   vector<double>  *dnn_QCD_BestCalc;
   vector<double>  *dnn_T_DeepAK8Calc;
   vector<double>  *dnn_Top_BestCalc;
   vector<double>  *dnn_W_BestCalc;
   vector<double>  *dnn_W_DeepAK8Calc;
   vector<double>  *dnn_Z_BestCalc;
   vector<double>  *dnn_Z_DeepAK8Calc;
   vector<double>  *elAEff_singleLepCalc;
   vector<double>  *elChIso_singleLepCalc;
   vector<double>  *elD0_singleLepCalc;
   vector<double>  *elDEtaSCTkAtVtx_singleLepCalc;
   vector<double>  *elDPhiSCTkAtVtx_singleLepCalc;
   vector<double>  *elDR03TkSumPt_singleLepCalc;
   vector<double>  *elDZ_singleLepCalc;
   vector<double>  *elDeta_singleLepCalc;
   vector<double>  *elDphi_singleLepCalc;
   vector<double>  *elDxy_singleLepCalc;
   vector<double>  *elEcalPFClusterIso_singleLepCalc;
   vector<double>  *elEnergy_singleLepCalc;
   vector<double>  *elEtaVtx_singleLepCalc;
   vector<double>  *elEta_singleLepCalc;
   vector<double>  *elGen_Reco_dr_singleLepCalc;
   vector<double>  *elHcalPFClusterIso_singleLepCalc;
   vector<double>  *elHoE_singleLepCalc;
   vector<double>  *elIsLoose_singleLepCalc;
   vector<double>  *elIsMedium_singleLepCalc;
   vector<double>  *elIsTight_singleLepCalc;
   vector<double>  *elIsVeto_singleLepCalc;
   /* vector<double>  *elMVAValue_iso_singleLepCalc; */
   /* vector<double>  *elMVAValue_singleLepCalc; */
   vector<double>  *elMatchedEnergy_singleLepCalc;
   vector<double>  *elMatchedEta_singleLepCalc;
   vector<double>  *elMatchedPhi_singleLepCalc;
   vector<double>  *elMatchedPt_singleLepCalc;
   vector<double>  *elMiniIso_singleLepCalc;
   vector<double>  *elMother_energy_singleLepCalc;
   vector<double>  *elMother_eta_singleLepCalc;
   vector<double>  *elMother_phi_singleLepCalc;
   vector<double>  *elMother_pt_singleLepCalc;
   vector<double>  *elNhIso_singleLepCalc;
   vector<double>  *elOoemoop_singleLepCalc;
   vector<double>  *elPFEta_singleLepCalc;
   vector<double>  *elPFPhi_singleLepCalc;
   vector<double>  *elPhIso_singleLepCalc;
   vector<double>  *elPhiVtx_singleLepCalc;
   vector<double>  *elPhi_singleLepCalc;
   vector<double>  *elPt_singleLepCalc;
   vector<double>  *elRelIso_singleLepCalc;
   vector<double>  *elRhoIso_singleLepCalc;
   vector<double>  *elSCE_singleLepCalc;
   vector<double>  *elSihih_singleLepCalc;
   vector<double>  *evtWeightsMC_singleLepCalc;
   vector<double>  *genBSLEnergy_singleLepCalc;
   vector<double>  *genBSLEta_singleLepCalc;
   vector<double>  *genBSLPhi_singleLepCalc;
   vector<double>  *genBSLPt_singleLepCalc;
   vector<double>  *genEnergy_singleLepCalc;
   vector<double>  *genEta_singleLepCalc;
   vector<double>  *genJetEnergy_singleLepCalc;
   vector<double>  *genJetEta_singleLepCalc;
   vector<double>  *genJetPhi_singleLepCalc;
   vector<double>  *genJetPt_singleLepCalc;
   vector<double>  *genPhi_singleLepCalc;
   vector<double>  *genPt_singleLepCalc;
   vector<double>  *muChIso_singleLepCalc;
   vector<double>  *muChi2_singleLepCalc;
   vector<double>  *muDxy_singleLepCalc;
   vector<double>  *muDz_singleLepCalc;
   vector<double>  *muEnergy_singleLepCalc;
   vector<double>  *muEta_singleLepCalc;
   vector<double>  *muGIso_singleLepCalc;
   vector<double>  *muGen_Reco_dr_singleLepCalc;
   vector<double>  *muInnerEta_singleLepCalc;
   vector<double>  *muInnerPhi_singleLepCalc;
   vector<double>  *muInnerPt_singleLepCalc;
   vector<double>  *muMatchedEnergy_singleLepCalc;
   vector<double>  *muMatchedEta_singleLepCalc;
   vector<double>  *muMatchedPhi_singleLepCalc;
   vector<double>  *muMatchedPt_singleLepCalc;
   vector<double>  *muMiniIsoDB_singleLepCalc;
   vector<double>  *muMiniIso_singleLepCalc;
   vector<double>  *muMother_energy_singleLepCalc;
   vector<double>  *muMother_eta_singleLepCalc;
   vector<double>  *muMother_phi_singleLepCalc;
   vector<double>  *muMother_pt_singleLepCalc;
   vector<double>  *muNhIso_singleLepCalc;
   vector<double>  *muPhi_singleLepCalc;
   vector<double>  *muPt_singleLepCalc;
   vector<double>  *muPuIso_singleLepCalc;
   vector<double>  *muRelIso_singleLepCalc;
   vector<double>  *quarkEnergy_TpTpCalc;
   vector<double>  *quarkEta_TpTpCalc;
   vector<double>  *quarkPhi_TpTpCalc;
   vector<double>  *quarkPt_TpTpCalc;
   vector<double>  *tPrimeEnergy_TpTpCalc;
   vector<double>  *tPrimeEta_TpTpCalc;
   vector<double>  *tPrimeMass_TpTpCalc;
   vector<double>  *tPrimePhi_TpTpCalc;
   vector<double>  *tPrimePt_TpTpCalc;
   vector<double>  *theJetAK8CHSEta_JetSubCalc;
   vector<double>  *theJetAK8CHSMass_JetSubCalc;
   vector<double>  *theJetAK8CHSPhi_JetSubCalc;
   vector<double>  *theJetAK8CHSPrunedMass_JetSubCalc;
   vector<double>  *theJetAK8CHSPt_JetSubCalc;
   vector<double>  *theJetAK8CHSSoftDropMass_JetSubCalc;
   vector<double>  *theJetAK8CHSTau1_JetSubCalc;
   vector<double>  *theJetAK8CHSTau2_JetSubCalc;
   vector<double>  *theJetAK8CHSTau3_JetSubCalc;
   vector<double>  *theJetAK8CSV_JetSubCalc;
   vector<double>  *theJetAK8DoubleB_JetSubCalc;
   vector<double>  *theJetAK8Energy_JetSubCalc;
   vector<double>  *theJetAK8Eta_JetSubCalc;
   vector<double>  *theJetAK8GenDR_JetSubCalc;
   vector<double>  *theJetAK8GenMass_JetSubCalc;
   vector<double>  *theJetAK8GenPt_JetSubCalc;
   vector<double>  *theJetAK8JetCharge_JetSubCalc;
   vector<double>  *theJetAK8Mass_JetSubCalc;
   vector<double>  *theJetAK8NjettinessTau1_JetSubCalc;
   vector<double>  *theJetAK8NjettinessTau2_JetSubCalc;
   vector<double>  *theJetAK8NjettinessTau3_JetSubCalc;
   vector<double>  *theJetAK8Phi_JetSubCalc;
   vector<double>  *theJetAK8Pt_JetSubCalc;
   vector<double>  *theJetAK8SDSubjetCSVb_JetSubCalc;
   vector<double>  *theJetAK8SDSubjetCSVbb_JetSubCalc;
   vector<double>  *theJetAK8SDSubjetCSVc_JetSubCalc;
   vector<double>  *theJetAK8SDSubjetCSVudsg_JetSubCalc;
   vector<double>  *theJetAK8SDSubjetDR_JetSubCalc;
   vector<double>  *theJetAK8SDSubjetEta_JetSubCalc;
   vector<double>  *theJetAK8SDSubjetMass_JetSubCalc;
   vector<double>  *theJetAK8SDSubjetPhi_JetSubCalc;
   vector<double>  *theJetAK8SDSubjetPt_JetSubCalc;
   vector<double>  *theJetAK8SoftDropCorr_JetSubCalc;
   vector<double>  *theJetAK8SoftDropRaw_JetSubCalc;
   vector<double>  *theJetAK8SoftDrop_JMRdn_JetSubCalc;
   vector<double>  *theJetAK8SoftDrop_JMRup_JetSubCalc;
   vector<double>  *theJetAK8SoftDrop_JMSdn_JetSubCalc;
   vector<double>  *theJetAK8SoftDrop_JMSup_JetSubCalc;
   vector<double>  *theJetAK8SoftDrop_JetSubCalc;
   vector<double>  *theJetAK8SoftDropn2b1_JetSubCalc;
   vector<double>  *theJetAK8SoftDropn2b2_JetSubCalc;
   vector<double>  *theJetAK8SoftDropn3b1_JetSubCalc;
   vector<double>  *theJetAK8SoftDropn3b2_JetSubCalc;
   vector<double>  *theJetDeepCSVb_JetSubCalc;
   vector<double>  *theJetDeepCSVbb_JetSubCalc;
   vector<double>  *theJetDeepCSVc_JetSubCalc;
   vector<double>  *theJetDeepCSVudsg_JetSubCalc;
   vector<double>  *theJetEnergy_JetSubCalc;
   vector<double>  *theJetEta_JetSubCalc;
   vector<double>  *theJetPhi_JetSubCalc;
   vector<double>  *theJetPileupJetId_JetSubCalc;
   vector<double>  *theJetPt_JetSubCalc;
   vector<double>  *topEnergy_TTbarMassCalc;
   vector<double>  *topEta_TTbarMassCalc;
   vector<double>  *topMass_TTbarMassCalc;
   vector<double>  *topPhi_TTbarMassCalc;
   vector<double>  *topPt_TTbarMassCalc;
   vector<double>  *topWEnergy_TTbarMassCalc;
   vector<double>  *topWEta_TTbarMassCalc;
   vector<double>  *topWPhi_TTbarMassCalc;
   vector<double>  *topWPt_TTbarMassCalc;
   vector<double>  *topbEnergy_TTbarMassCalc;
   vector<double>  *topbEta_TTbarMassCalc;
   vector<double>  *topbPhi_TTbarMassCalc;
   vector<double>  *topbPt_TTbarMassCalc;
   vector<string>  *electron_hltfilters_singleLepCalc;
   vector<string>  *muon_hltfilters_singleLepCalc;
   vector<string>  *vsSelMCTriggersEl_singleLepCalc;
   vector<string>  *vsSelMCTriggersMu_singleLepCalc;
   vector<string>  *vsSelTriggersEl_singleLepCalc;
   vector<string>  *vsSelTriggersMu_singleLepCalc;

   // List of branches
   TBranch        *b_flagBadMu_singleLepCalc;   //!
   TBranch        *b_flagDupMu_singleLepCalc;   //!
   TBranch        *b_isBHBH_TpTpCalc;   //!
   TBranch        *b_isBHTW_TpTpCalc;   //!
   TBranch        *b_isBWBW_TpTpCalc;   //!
   TBranch        *b_isBZBH_TpTpCalc;   //!
   TBranch        *b_isBZBZ_TpTpCalc;   //!
   TBranch        *b_isBZTW_TpTpCalc;   //!
   TBranch        *b_isTHBW_TpTpCalc;   //!
   TBranch        *b_isTHTH_TpTpCalc;   //!
   TBranch        *b_isTWTW_TpTpCalc;   //!
   TBranch        *b_isTZBW_TpTpCalc;   //!
   TBranch        *b_isTZTH_TpTpCalc;   //!
   TBranch        *b_isTZTZ_TpTpCalc;   //!
   TBranch        *b_isTau_singleLepCalc;   //!
   TBranch        *b_NLeptonDecays_TpTpCalc;   //!
   TBranch        *b_NPartonsfromHEPUEP_singleLepCalc;   //!
   TBranch        *b_dataE_singleLepCalc;   //!
   TBranch        *b_dataM_singleLepCalc;   //!
   TBranch        *b_genTDLID_singleLepCalc;   //!
   TBranch        *b_lumi_CommonCalc;   //!
   TBranch        *b_nAllJets_CommonCalc;   //!
   TBranch        *b_nLooseMuons_CommonCalc;   //!
   //   TBranch        *b_nPV_singleLepCalc;   //!
   TBranch        *b_nPileupInteractions_singleLepCalc;   //!
   TBranch        *b_nSelBtagJets_CommonCalc;   //!
   TBranch        *b_nSelElectrons_CommonCalc;   //!
   TBranch        *b_nSelJets_CommonCalc;   //!
   TBranch        *b_nTightMuons_CommonCalc;   //!
   TBranch        *b_nTrueInteractions_singleLepCalc;   //!
   TBranch        *b_run_CommonCalc;   //!
   TBranch        *b_event_CommonCalc;   //!
   TBranch        *b_AK4HT_singleLepCalc;   //!
   TBranch        *b_HTfromHEPUEP_singleLepCalc;   //!
   TBranch        *b_L1NonPrefiringProbDown_CommonCalc;   //!
   TBranch        *b_L1NonPrefiringProbUp_CommonCalc;   //!
   TBranch        *b_L1NonPrefiringProb_CommonCalc;   //!
   TBranch        *b_LHEweightorig_singleLepCalc;   //!
   TBranch        *b_MCWeight_singleLepCalc;   //!
   TBranch        *b_corr_met_jerdn_phi_singleLepCalc;   //!
   TBranch        *b_corr_met_jerdn_singleLepCalc;   //!
   TBranch        *b_corr_met_jerup_phi_singleLepCalc;   //!
   TBranch        *b_corr_met_jerup_singleLepCalc;   //!
   TBranch        *b_corr_met_jesdn_phi_singleLepCalc;   //!
   TBranch        *b_corr_met_jesdn_singleLepCalc;   //!
   TBranch        *b_corr_met_jesup_phi_singleLepCalc;   //!
   TBranch        *b_corr_met_jesup_singleLepCalc;   //!
   TBranch        *b_corr_met_phi_singleLepCalc;   //!
   TBranch        *b_corr_met_singleLepCalc;   //!
   TBranch        *b_corr_metmod_phi_singleLepCalc;   //!
   TBranch        *b_corr_metmod_singleLepCalc;   //!
   TBranch        *b_corr_metnohf_phi_singleLepCalc;   //!
   TBranch        *b_corr_metnohf_singleLepCalc;   //!
   TBranch        *b_genTDLEnergy_singleLepCalc;   //!
   TBranch        *b_genTDLEta_singleLepCalc;   //!
   TBranch        *b_genTDLPhi_singleLepCalc;   //!
   TBranch        *b_genTDLPt_singleLepCalc;   //!
   TBranch        *b_met_phi_singleLepCalc;   //!
   TBranch        *b_met_singleLepCalc;   //!
   TBranch        *b_metmod_phi_singleLepCalc;   //!
   TBranch        *b_metmod_singleLepCalc;   //!
   TBranch        *b_metnohf_phi_singleLepCalc;   //!
   TBranch        *b_metnohf_singleLepCalc;   //!
   TBranch        *b_theJetHT_JetSubCalc;   //!
   TBranch        *b_theJetLeadPt_JetSubCalc;   //!
   TBranch        *b_theJetSubLeadPt_JetSubCalc;   //!
   TBranch        *b_ttbarMass_TTbarMassCalc;   //!
   TBranch        *b_AK4JetBTag_bSFdn_singleLepCalc;   //!
   TBranch        *b_AK4JetBTag_bSFup_singleLepCalc;   //!
   TBranch        *b_AK4JetBTag_lSFdn_singleLepCalc;   //!
   TBranch        *b_AK4JetBTag_lSFup_singleLepCalc;   //!
   TBranch        *b_AK4JetBTag_singleLepCalc;   //!
   TBranch        *b_AK4JetFlav_singleLepCalc;   //!
   TBranch        *b_HadronicVHtID_JetSubCalc;   //!
   TBranch        *b_HadronicVHtStatus_JetSubCalc;   //!
   TBranch        *b_HdecayID_TpTpCalc;   //!
   TBranch        *b_HdecayIndex_TpTpCalc;   //!
   TBranch        *b_LHEweightids_singleLepCalc;   //!
   TBranch        *b_LeptonID_TpTpCalc;   //!
   TBranch        *b_LeptonParentID_TpTpCalc;   //!
   TBranch        *b_NewPDFids_singleLepCalc;   //!
   TBranch        *b_WdecayID_TpTpCalc;   //!
   TBranch        *b_WdecayIndex_TpTpCalc;   //!
   TBranch        *b_ZdecayID_TpTpCalc;   //!
   TBranch        *b_ZdecayIndex_TpTpCalc;   //!
   TBranch        *b_allTopsID_TTbarMassCalc;   //!
   TBranch        *b_allTopsStatus_TTbarMassCalc;   //!
   TBranch        *b_bPrimeID_TpTpCalc;   //!
   TBranch        *b_bPrimeNDaughters_TpTpCalc;   //!
   TBranch        *b_bPrimeStatus_TpTpCalc;   //!
   TBranch        *b_bosonID_TpTpCalc;   //!
   TBranch        *b_decorr_largest_DeepAK8Calc;   //!
   TBranch        *b_dnn_largest_BestCalc;   //!
   TBranch        *b_dnn_largest_DeepAK8Calc;   //!
   TBranch        *b_elChargeConsistent_singleLepCalc;   //!
   TBranch        *b_elCharge_singleLepCalc;   //!
   TBranch        *b_elCtfCharge_singleLepCalc;   //!
   TBranch        *b_elGsfCharge_singleLepCalc;   //!
   TBranch        *b_elIsEBEE_singleLepCalc;   //!
   /* TBranch        *b_elIsMVALooseIso_singleLepCalc;   //! */
   /* TBranch        *b_elIsMVALoose_singleLepCalc;   //! */
   /* TBranch        *b_elIsMVATight80_singleLepCalc;   //! */
   /* TBranch        *b_elIsMVATight90_singleLepCalc;   //! */
   /* TBranch        *b_elIsMVATightIso80_singleLepCalc;   //! */
   /* TBranch        *b_elIsMVATightIso90_singleLepCalc;   //! */
   TBranch        *b_elMHits_singleLepCalc;   //!
   TBranch        *b_elMatched_singleLepCalc;   //!
   TBranch        *b_elMother_id_singleLepCalc;   //!
   TBranch        *b_elMother_status_singleLepCalc;   //!
   TBranch        *b_elNotConversion_singleLepCalc;   //!
   TBranch        *b_elNumberOfMothers_singleLepCalc;   //!
   TBranch        *b_elPdgId_singleLepCalc;   //!
   TBranch        *b_elScPixCharge_singleLepCalc;   //!
   TBranch        *b_elStatus_singleLepCalc;   //!
   TBranch        *b_elVtxFitConv_singleLepCalc;   //!
   TBranch        *b_electron_1_hltmatched_singleLepCalc;   //!
   TBranch        *b_genBSLID_singleLepCalc;   //!
   TBranch        *b_genID_singleLepCalc;   //!
   TBranch        *b_genIndex_singleLepCalc;   //!
   TBranch        *b_genMotherID_singleLepCalc;   //!
   TBranch        *b_genMotherIndex_singleLepCalc;   //!
   TBranch        *b_genStatus_singleLepCalc;   //!
   TBranch        *b_genTtbarIdCategory_TTbarMassCalc;   //!
   TBranch        *b_genTtbarId_TTbarMassCalc;   //!
   TBranch        *b_maxProb_JetSubCalc;   //!
   TBranch        *b_muCharge_singleLepCalc;   //!
   TBranch        *b_muGlobal_singleLepCalc;   //!
   TBranch        *b_muIsGlobalHighPt_singleLepCalc;   //!
   TBranch        *b_muIsLoose_singleLepCalc;   //!
   TBranch        *b_muIsMediumPrompt_singleLepCalc;   //!
   TBranch        *b_muIsMedium_singleLepCalc;   //!
   TBranch        *b_muIsMiniIsoLoose_singleLepCalc;   //!
   TBranch        *b_muIsMiniIsoMedium_singleLepCalc;   //!
   TBranch        *b_muIsMiniIsoTight_singleLepCalc;   //!
   TBranch        *b_muIsMiniIsoVeryTight_singleLepCalc;   //!
   TBranch        *b_muIsMvaLoose_singleLepCalc;   //!
   TBranch        *b_muIsMvaMedium_singleLepCalc;   //!
   TBranch        *b_muIsMvaTight_singleLepCalc;   //!
   TBranch        *b_muIsTight_singleLepCalc;   //!
   TBranch        *b_muIsTrkHighPt_singleLepCalc;   //!
   TBranch        *b_muMatched_singleLepCalc;   //!
   TBranch        *b_muMother_id_singleLepCalc;   //!
   TBranch        *b_muMother_status_singleLepCalc;   //!
   TBranch        *b_muNMatchedStations_singleLepCalc;   //!
   TBranch        *b_muNTrackerLayers_singleLepCalc;   //!
   TBranch        *b_muNValMuHits_singleLepCalc;   //!
   TBranch        *b_muNValPixelHits_singleLepCalc;   //!
   TBranch        *b_muNumberOfMothers_singleLepCalc;   //!
   TBranch        *b_muPdgId_singleLepCalc;   //!
   TBranch        *b_muStatus_singleLepCalc;   //!
   TBranch        *b_muon_1_hltmatched_singleLepCalc;   //!
   TBranch        *b_quarkID_TpTpCalc;   //!
   TBranch        *b_tPrimeID_TpTpCalc;   //!
   TBranch        *b_tPrimeNDaughters_TpTpCalc;   //!
   TBranch        *b_tPrimeStatus_TpTpCalc;   //!
   TBranch        *b_theJetAK8SDSubjetBTag_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetHFlav_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetIndex_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetNDeepCSVL_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetNDeepCSVM_bSFdn_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetNDeepCSVM_bSFup_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetNDeepCSVM_lSFdn_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetNDeepCSVM_lSFup_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetSize_JetSubCalc;   //!
   TBranch        *b_theJetAK8nDaughters_JetSubCalc;   //!
   TBranch        *b_theJetBTag_JetSubCalc;   //!
   TBranch        *b_theJetBTag_bSFdn_JetSubCalc;   //!
   TBranch        *b_theJetBTag_bSFup_JetSubCalc;   //!
   TBranch        *b_theJetBTag_lSFdn_JetSubCalc;   //!
   TBranch        *b_theJetBTag_lSFup_JetSubCalc;   //!
   TBranch        *b_theJetHFlav_JetSubCalc;   //!
   TBranch        *b_theJetPFlav_JetSubCalc;   //!
   TBranch        *b_theJetnDaughters_JetSubCalc;   //!
   TBranch        *b_topID_TTbarMassCalc;   //!
   TBranch        *b_topWID_TTbarMassCalc;   //!
   TBranch        *b_topbID_TTbarMassCalc;   //!
   TBranch        *b_viSelMCTriggersEl_singleLepCalc;   //!
   TBranch        *b_viSelMCTriggersMu_singleLepCalc;   //!
   TBranch        *b_viSelTriggersEl_singleLepCalc;   //!
   TBranch        *b_viSelTriggersMu_singleLepCalc;   //!
   TBranch        *b_AK4JetBDeepCSVb_singleLepCalc;   //!
   TBranch        *b_AK4JetBDeepCSVbb_singleLepCalc;   //!
   TBranch        *b_AK4JetBDeepCSVc_singleLepCalc;   //!
   TBranch        *b_AK4JetBDeepCSVudsg_singleLepCalc;   //!
   TBranch        *b_AK4JetBDisc_singleLepCalc;   //!
   TBranch        *b_AK4JetEnergy_singleLepCalc;   //!
   TBranch        *b_AK4JetEta_singleLepCalc;   //!
   TBranch        *b_AK4JetPhi_singleLepCalc;   //!
   TBranch        *b_AK4JetPt_singleLepCalc;   //!
   TBranch        *b_AK8JetCSV_BestCalc;   //!
   TBranch        *b_AK8JetCSV_singleLepCalc;   //!
   TBranch        *b_AK8JetDoubleB_singleLepCalc;   //!
   TBranch        *b_AK8JetEnergy_BestCalc;   //!
   TBranch        *b_AK8JetEnergy_singleLepCalc;   //!
   TBranch        *b_AK8JetEta_BestCalc;   //!
   TBranch        *b_AK8JetEta_singleLepCalc;   //!
   TBranch        *b_AK8JetPhi_BestCalc;   //!
   TBranch        *b_AK8JetPhi_singleLepCalc;   //!
   TBranch        *b_AK8JetPt_BestCalc;   //!
   TBranch        *b_AK8JetPt_singleLepCalc;   //!
   TBranch        *b_HadronicVHtD0E_JetSubCalc;   //!
   TBranch        *b_HadronicVHtD0Eta_JetSubCalc;   //!
   TBranch        *b_HadronicVHtD0Phi_JetSubCalc;   //!
   TBranch        *b_HadronicVHtD0Pt_JetSubCalc;   //!
   TBranch        *b_HadronicVHtD1E_JetSubCalc;   //!
   TBranch        *b_HadronicVHtD1Eta_JetSubCalc;   //!
   TBranch        *b_HadronicVHtD1Phi_JetSubCalc;   //!
   TBranch        *b_HadronicVHtD1Pt_JetSubCalc;   //!
   TBranch        *b_HadronicVHtD2E_JetSubCalc;   //!
   TBranch        *b_HadronicVHtD2Eta_JetSubCalc;   //!
   TBranch        *b_HadronicVHtD2Phi_JetSubCalc;   //!
   TBranch        *b_HadronicVHtD2Pt_JetSubCalc;   //!
   TBranch        *b_HadronicVHtEnergy_JetSubCalc;   //!
   TBranch        *b_HadronicVHtEta_JetSubCalc;   //!
   TBranch        *b_HadronicVHtPhi_JetSubCalc;   //!
   TBranch        *b_HadronicVHtPt_JetSubCalc;   //!
   TBranch        *b_HdecayEnergy_TpTpCalc;   //!
   TBranch        *b_HdecayEta_TpTpCalc;   //!
   TBranch        *b_HdecayPhi_TpTpCalc;   //!
   TBranch        *b_HdecayPt_TpTpCalc;   //!
   TBranch        *b_LHEweights_singleLepCalc;   //!
   TBranch        *b_LeptonEnergy_TpTpCalc;   //!
   TBranch        *b_LeptonEta_TpTpCalc;   //!
   TBranch        *b_LeptonPhi_TpTpCalc;   //!
   TBranch        *b_LeptonPt_TpTpCalc;   //!
   TBranch        *b_NewPDFweightsBase_singleLepCalc;   //!
   TBranch        *b_NewPDFweights_singleLepCalc;   //!
   TBranch        *b_WdecayEnergy_TpTpCalc;   //!
   TBranch        *b_WdecayEta_TpTpCalc;   //!
   TBranch        *b_WdecayPhi_TpTpCalc;   //!
   TBranch        *b_WdecayPt_TpTpCalc;   //!
   TBranch        *b_ZdecayEnergy_TpTpCalc;   //!
   TBranch        *b_ZdecayEta_TpTpCalc;   //!
   TBranch        *b_ZdecayPhi_TpTpCalc;   //!
   TBranch        *b_ZdecayPt_TpTpCalc;   //!
   TBranch        *b_allTopsEnergy_TTbarMassCalc;   //!
   TBranch        *b_allTopsEta_TTbarMassCalc;   //!
   TBranch        *b_allTopsPhi_TTbarMassCalc;   //!
   TBranch        *b_allTopsPt_TTbarMassCalc;   //!
   TBranch        *b_bPrimeEnergy_TpTpCalc;   //!
   TBranch        *b_bPrimeEta_TpTpCalc;   //!
   TBranch        *b_bPrimeMass_TpTpCalc;   //!
   TBranch        *b_bPrimePhi_TpTpCalc;   //!
   TBranch        *b_bPrimePt_TpTpCalc;   //!
   TBranch        *b_bosonEnergy_TpTpCalc;   //!
   TBranch        *b_bosonEta_TpTpCalc;   //!
   TBranch        *b_bosonPhi_TpTpCalc;   //!
   TBranch        *b_bosonPt_TpTpCalc;   //!
   TBranch        *b_decorr_B_DeepAK8Calc;   //!
   TBranch        *b_decorr_C_DeepAK8Calc;   //!
   TBranch        *b_decorr_H_DeepAK8Calc;   //!
   TBranch        *b_decorr_J_DeepAK8Calc;   //!
   TBranch        *b_decorr_T_DeepAK8Calc;   //!
   TBranch        *b_decorr_W_DeepAK8Calc;   //!
   TBranch        *b_decorr_Z_DeepAK8Calc;   //!
   TBranch        *b_dnn_B_BestCalc;   //!
   TBranch        *b_dnn_B_DeepAK8Calc;   //!
   TBranch        *b_dnn_C_DeepAK8Calc;   //!
   TBranch        *b_dnn_H_DeepAK8Calc;   //!
   TBranch        *b_dnn_Higgs_BestCalc;   //!
   TBranch        *b_dnn_J_DeepAK8Calc;   //!
   TBranch        *b_dnn_QCD_BestCalc;   //!
   TBranch        *b_dnn_T_DeepAK8Calc;   //!
   TBranch        *b_dnn_Top_BestCalc;   //!
   TBranch        *b_dnn_W_BestCalc;   //!
   TBranch        *b_dnn_W_DeepAK8Calc;   //!
   TBranch        *b_dnn_Z_BestCalc;   //!
   TBranch        *b_dnn_Z_DeepAK8Calc;   //!
   TBranch        *b_elAEff_singleLepCalc;   //!
   TBranch        *b_elChIso_singleLepCalc;   //!
   TBranch        *b_elD0_singleLepCalc;   //!
   TBranch        *b_elDEtaSCTkAtVtx_singleLepCalc;   //!
   TBranch        *b_elDPhiSCTkAtVtx_singleLepCalc;   //!
   TBranch        *b_elDR03TkSumPt_singleLepCalc;   //!
   TBranch        *b_elDZ_singleLepCalc;   //!
   TBranch        *b_elDeta_singleLepCalc;   //!
   TBranch        *b_elDphi_singleLepCalc;   //!
   TBranch        *b_elDxy_singleLepCalc;   //!
   TBranch        *b_elEcalPFClusterIso_singleLepCalc;   //!
   TBranch        *b_elEnergy_singleLepCalc;   //!
   TBranch        *b_elEtaVtx_singleLepCalc;   //!
   TBranch        *b_elEta_singleLepCalc;   //!
   TBranch        *b_elGen_Reco_dr_singleLepCalc;   //!
   TBranch        *b_elHcalPFClusterIso_singleLepCalc;   //!
   TBranch        *b_elHoE_singleLepCalc;   //!
   TBranch        *b_elIsLoose_singleLepCalc;   //!
   TBranch        *b_elIsMedium_singleLepCalc;   //!
   TBranch        *b_elIsTight_singleLepCalc;   //!
   TBranch        *b_elIsVeto_singleLepCalc;   //!
   /* TBranch        *b_elMVAValue_iso_singleLepCalc;   //! */
   /* TBranch        *b_elMVAValue_singleLepCalc;   //! */
   TBranch        *b_elMatchedEnergy_singleLepCalc;   //!
   TBranch        *b_elMatchedEta_singleLepCalc;   //!
   TBranch        *b_elMatchedPhi_singleLepCalc;   //!
   TBranch        *b_elMatchedPt_singleLepCalc;   //!
   TBranch        *b_elMiniIso_singleLepCalc;   //!
   TBranch        *b_elMother_energy_singleLepCalc;   //!
   TBranch        *b_elMother_eta_singleLepCalc;   //!
   TBranch        *b_elMother_phi_singleLepCalc;   //!
   TBranch        *b_elMother_pt_singleLepCalc;   //!
   TBranch        *b_elNhIso_singleLepCalc;   //!
   TBranch        *b_elOoemoop_singleLepCalc;   //!
   TBranch        *b_elPFEta_singleLepCalc;   //!
   TBranch        *b_elPFPhi_singleLepCalc;   //!
   TBranch        *b_elPhIso_singleLepCalc;   //!
   TBranch        *b_elPhiVtx_singleLepCalc;   //!
   TBranch        *b_elPhi_singleLepCalc;   //!
   TBranch        *b_elPt_singleLepCalc;   //!
   TBranch        *b_elRelIso_singleLepCalc;   //!
   TBranch        *b_elRhoIso_singleLepCalc;   //!
   TBranch        *b_elSCE_singleLepCalc;   //!
   TBranch        *b_elSihih_singleLepCalc;   //!
   TBranch        *b_evtWeightsMC_singleLepCalc;   //!
   TBranch        *b_genBSLEnergy_singleLepCalc;   //!
   TBranch        *b_genBSLEta_singleLepCalc;   //!
   TBranch        *b_genBSLPhi_singleLepCalc;   //!
   TBranch        *b_genBSLPt_singleLepCalc;   //!
   TBranch        *b_genEnergy_singleLepCalc;   //!
   TBranch        *b_genEta_singleLepCalc;   //!
   TBranch        *b_genJetEnergy_singleLepCalc;   //!
   TBranch        *b_genJetEta_singleLepCalc;   //!
   TBranch        *b_genJetPhi_singleLepCalc;   //!
   TBranch        *b_genJetPt_singleLepCalc;   //!
   TBranch        *b_genPhi_singleLepCalc;   //!
   TBranch        *b_genPt_singleLepCalc;   //!
   TBranch        *b_muChIso_singleLepCalc;   //!
   TBranch        *b_muChi2_singleLepCalc;   //!
   TBranch        *b_muDxy_singleLepCalc;   //!
   TBranch        *b_muDz_singleLepCalc;   //!
   TBranch        *b_muEnergy_singleLepCalc;   //!
   TBranch        *b_muEta_singleLepCalc;   //!
   TBranch        *b_muGIso_singleLepCalc;   //!
   TBranch        *b_muGen_Reco_dr_singleLepCalc;   //!
   TBranch        *b_muInnerEta_singleLepCalc;   //!
   TBranch        *b_muInnerPhi_singleLepCalc;   //!
   TBranch        *b_muInnerPt_singleLepCalc;   //!
   TBranch        *b_muMatchedEnergy_singleLepCalc;   //!
   TBranch        *b_muMatchedEta_singleLepCalc;   //!
   TBranch        *b_muMatchedPhi_singleLepCalc;   //!
   TBranch        *b_muMatchedPt_singleLepCalc;   //!
   TBranch        *b_muMiniIsoDB_singleLepCalc;   //!
   TBranch        *b_muMiniIso_singleLepCalc;   //!
   TBranch        *b_muMother_energy_singleLepCalc;   //!
   TBranch        *b_muMother_eta_singleLepCalc;   //!
   TBranch        *b_muMother_phi_singleLepCalc;   //!
   TBranch        *b_muMother_pt_singleLepCalc;   //!
   TBranch        *b_muNhIso_singleLepCalc;   //!
   TBranch        *b_muPhi_singleLepCalc;   //!
   TBranch        *b_muPt_singleLepCalc;   //!
   TBranch        *b_muPuIso_singleLepCalc;   //!
   TBranch        *b_muRelIso_singleLepCalc;   //!
   TBranch        *b_quarkEnergy_TpTpCalc;   //!
   TBranch        *b_quarkEta_TpTpCalc;   //!
   TBranch        *b_quarkPhi_TpTpCalc;   //!
   TBranch        *b_quarkPt_TpTpCalc;   //!
   TBranch        *b_tPrimeEnergy_TpTpCalc;   //!
   TBranch        *b_tPrimeEta_TpTpCalc;   //!
   TBranch        *b_tPrimeMass_TpTpCalc;   //!
   TBranch        *b_tPrimePhi_TpTpCalc;   //!
   TBranch        *b_tPrimePt_TpTpCalc;   //!
   TBranch        *b_theJetAK8CHSEta_JetSubCalc;   //!
   TBranch        *b_theJetAK8CHSMass_JetSubCalc;   //!
   TBranch        *b_theJetAK8CHSPhi_JetSubCalc;   //!
   TBranch        *b_theJetAK8CHSPrunedMass_JetSubCalc;   //!
   TBranch        *b_theJetAK8CHSPt_JetSubCalc;   //!
   TBranch        *b_theJetAK8CHSSoftDropMass_JetSubCalc;   //!
   TBranch        *b_theJetAK8CHSTau1_JetSubCalc;   //!
   TBranch        *b_theJetAK8CHSTau2_JetSubCalc;   //!
   TBranch        *b_theJetAK8CHSTau3_JetSubCalc;   //!
   TBranch        *b_theJetAK8CSV_JetSubCalc;   //!
   TBranch        *b_theJetAK8DoubleB_JetSubCalc;   //!
   TBranch        *b_theJetAK8Energy_JetSubCalc;   //!
   TBranch        *b_theJetAK8Eta_JetSubCalc;   //!
   TBranch        *b_theJetAK8GenDR_JetSubCalc;   //!
   TBranch        *b_theJetAK8GenMass_JetSubCalc;   //!
   TBranch        *b_theJetAK8GenPt_JetSubCalc;   //!
   TBranch        *b_theJetAK8JetCharge_JetSubCalc;   //!
   TBranch        *b_theJetAK8Mass_JetSubCalc;   //!
   TBranch        *b_theJetAK8NjettinessTau1_JetSubCalc;   //!
   TBranch        *b_theJetAK8NjettinessTau2_JetSubCalc;   //!
   TBranch        *b_theJetAK8NjettinessTau3_JetSubCalc;   //!
   TBranch        *b_theJetAK8Phi_JetSubCalc;   //!
   TBranch        *b_theJetAK8Pt_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetCSVb_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetCSVbb_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetCSVc_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetCSVudsg_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetDR_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetEta_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetMass_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetPhi_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetPt_JetSubCalc;   //!
   TBranch        *b_theJetAK8SoftDropCorr_JetSubCalc;   //!
   TBranch        *b_theJetAK8SoftDropRaw_JetSubCalc;   //!
   TBranch        *b_theJetAK8SoftDrop_JMRdn_JetSubCalc;   //!
   TBranch        *b_theJetAK8SoftDrop_JMRup_JetSubCalc;   //!
   TBranch        *b_theJetAK8SoftDrop_JMSdn_JetSubCalc;   //!
   TBranch        *b_theJetAK8SoftDrop_JMSup_JetSubCalc;   //!
   TBranch        *b_theJetAK8SoftDrop_JetSubCalc;   //!
   TBranch        *b_theJetAK8SoftDropn2b1_JetSubCalc;   //!
   TBranch        *b_theJetAK8SoftDropn2b2_JetSubCalc;   //!
   TBranch        *b_theJetAK8SoftDropn3b1_JetSubCalc;   //!
   TBranch        *b_theJetAK8SoftDropn3b2_JetSubCalc;   //!
   TBranch        *b_theJetDeepCSVb_JetSubCalc;   //!
   TBranch        *b_theJetDeepCSVbb_JetSubCalc;   //!
   TBranch        *b_theJetDeepCSVc_JetSubCalc;   //!
   TBranch        *b_theJetDeepCSVudsg_JetSubCalc;   //!
   TBranch        *b_theJetEnergy_JetSubCalc;   //!
   TBranch        *b_theJetEta_JetSubCalc;   //!
   TBranch        *b_theJetPhi_JetSubCalc;   //!
   TBranch        *b_theJetPileupJetId_JetSubCalc;   //!
   TBranch        *b_theJetPt_JetSubCalc;   //!
   TBranch        *b_topEnergy_TTbarMassCalc;   //!
   TBranch        *b_topEta_TTbarMassCalc;   //!
   TBranch        *b_topMass_TTbarMassCalc;   //!
   TBranch        *b_topPhi_TTbarMassCalc;   //!
   TBranch        *b_topPt_TTbarMassCalc;   //!
   TBranch        *b_topWEnergy_TTbarMassCalc;   //!
   TBranch        *b_topWEta_TTbarMassCalc;   //!
   TBranch        *b_topWPhi_TTbarMassCalc;   //!
   TBranch        *b_topWPt_TTbarMassCalc;   //!
   TBranch        *b_topbEnergy_TTbarMassCalc;   //!
   TBranch        *b_topbEta_TTbarMassCalc;   //!
   TBranch        *b_topbPhi_TTbarMassCalc;   //!
   TBranch        *b_topbPt_TTbarMassCalc;   //!
   TBranch        *b_electron_hltfilters_singleLepCalc;   //!
   TBranch        *b_muon_hltfilters_singleLepCalc;   //!
   TBranch        *b_vsSelMCTriggersEl_singleLepCalc;   //!
   TBranch        *b_vsSelMCTriggersMu_singleLepCalc;   //!
   TBranch        *b_vsSelTriggersEl_singleLepCalc;   //!
   TBranch        *b_vsSelTriggersMu_singleLepCalc;   //!
 
   step1(TString inputFileName, TString outputFileName, TString outputDir);
   virtual ~step1();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   bool             applySF(bool& isTagged, float tag_SF, float tag_eff);
   double           GetBtagSF2016Medium_comb(shift Shift, double pt, double eta);
   double           GetCtagSF2016Medium_comb(shift Shift, double pt, double eta);
   double           GetLFSF2016Medium(shift Shift, double pt, double eta);
   double           GetBtagEfficiency(double pt);
   double           GetCtagEfficiency(double pt);
   double           GetMistagRate(double pt);
   void             InitPileup();
};

#endif

#ifdef step1_cxx
step1::step1(TString inputFileName, TString outputFileName, TString outputDir) : inputTree(0), inputFile(0), outputFile(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.

  isSig  = (inputFileName.Contains("prime") || inputFileName.Contains("X53") || inputFileName.Contains("ChargedHiggs_Hplus"));
  if(isSig){
    if(inputFileName.Contains("Tprime")) isTpTp = true;
    else if(inputFileName.Contains("Bprime")) isBpBp = true;
    else if(inputFileName.Contains("X53")) isXX = true;

    if(inputFileName.Contains("_M-700")) {SigMass = 0; pileupIndex = 24;}
    else if(inputFileName.Contains("_M-800")) SigMass = 1;
    else if(inputFileName.Contains("_M-900")) SigMass = 2;
    else if(inputFileName.Contains("_M-1000")) {SigMass = 3; pileupIndex = 25;}
    else if(inputFileName.Contains("_M-1100")) {SigMass = 4; pileupIndex = 26;}
    else if(inputFileName.Contains("_M-1200")) {SigMass = 5; pileupIndex = 27;}
    else if(inputFileName.Contains("_M-1300")) {SigMass = 6; pileupIndex = 28;}
    else if(inputFileName.Contains("_M-1400")) {SigMass = 7; pileupIndex = 29;}
    else if(inputFileName.Contains("_M-1500")) {SigMass = 8; pileupIndex = 30;}
    else if(inputFileName.Contains("_M-1600")) {SigMass = 9; pileupIndex = 31;}
    else if(inputFileName.Contains("_M-1700")) {SigMass = 10; pileupIndex = 32;}
    else if(inputFileName.Contains("_M-1800")) {SigMass = 11; pileupIndex = 33;}
    else SigMass = -1;
  }  

  isMadgraphBkg = (inputFileName.Contains("QCD") || inputFileName.Contains("madgraphMLM"));
  isTOP = (inputFileName.Contains("Mtt") || inputFileName.Contains("ST") || inputFileName.Contains("ttZ") || inputFileName.Contains("ttW") || inputFileName.Contains("ttH") || inputFileName.Contains("TTTo"));
  isTT = (inputFileName.Contains("TT_Tune") || inputFileName.Contains("Mtt") || inputFileName.Contains("TTTo"));
  isSTt = inputFileName.Contains("ST_t-channel");
  isSTtW = inputFileName.Contains("ST_tW");
  isTTV = (inputFileName.Contains("ttZ") || inputFileName.Contains("ttW") || inputFileName.Contains("ttH"));
  isVV = (inputFileName.Contains("WW_") || inputFileName.Contains("WZ_") || inputFileName.Contains("ZZ_"));
  isMC = !(inputFileName.Contains("Single") || inputFileName.Contains("Data18"));
  isSM = inputFileName.Contains("SingleMuon");
  isSE = (inputFileName.Contains("SingleElectron") || inputFileName.Contains("EGamma"));

  if(inputFileName.Contains("DYJets")) pileupIndex = 1;
  else if(inputFileName.Contains("QCD_HT1000")) pileupIndex = 2;
  else if(inputFileName.Contains("QCD_HT1500")) pileupIndex = 3;
  else if(inputFileName.Contains("QCD_HT2000")) pileupIndex = 4;
  else if(inputFileName.Contains("QCD_HT300")) pileupIndex = 5;
  else if(inputFileName.Contains("QCD_HT500")) pileupIndex = 6;
  else if(inputFileName.Contains("QCD_HT700")) pileupIndex = 7;
  else if(inputFileName.Contains("ST_s-channel")) pileupIndex = 8;
  else if(inputFileName.Contains("ST_t-channel_top")) pileupIndex = 9;
  else if(inputFileName.Contains("ST_t-channel_anti")) pileupIndex = 10;
  else if(inputFileName.Contains("ST_tW_top")) pileupIndex = 11;
  else if(inputFileName.Contains("ST_tW_anti")) pileupIndex = 12;
  else if(inputFileName.Contains("TTToHadronic")) pileupIndex = 13;
  else if(inputFileName.Contains("TTToSemi")) pileupIndex = 14;
  else if(inputFileName.Contains("TTTo2L2Nu")) pileupIndex = 15;
  else if(inputFileName.Contains("TT_Mtt-1000")) pileupIndex = 16;
  else if(inputFileName.Contains("TT_Mtt-700")) pileupIndex = 17;
  else if(inputFileName.Contains("ttW_")) pileupIndex = 18;
  else if(inputFileName.Contains("ttZ_")) pileupIndex = 19;
  else if(inputFileName.Contains("ttH_")) pileupIndex = 20;
  else if(inputFileName.Contains("WW_")) pileupIndex = 21;
  else if(inputFileName.Contains("WZ_")) pileupIndex = 22;
  else if(inputFileName.Contains("ZZ_")) pileupIndex = 23;
  else if(inputFileName.Contains("WJetsToLNu_HT-1200")) pileupIndex = 34;
  else if(inputFileName.Contains("WJetsToLNu_HT-200")) pileupIndex = 35;
  else if(inputFileName.Contains("WJetsToLNu_HT-2500")) pileupIndex = 36;
  else if(inputFileName.Contains("WJetsToLNu_HT-400")) pileupIndex = 37;
  else if(inputFileName.Contains("WJetsToLNu_HT-600")) pileupIndex = 38;
  else if(inputFileName.Contains("WJetsToLNu_HT-800")) pileupIndex = 39;

  std::cout << "output = " << outputDir << "/" << outputFileName << std::endl;

  isBUp = (outputDir.Contains("BTAGup"));
  isBDn = (outputDir.Contains("BTAGdown"));
  isLUp = (outputDir.Contains("LTAGup"));
  isLDn = (outputDir.Contains("LTAGdown"));
  isNominal = !(outputDir.Contains("BTAGup") || outputDir.Contains("BTAGdown") || outputDir.Contains("LTAGup") || outputDir.Contains("LTAGdown"));
  isTTincMtt0to700    = outputFileName.Contains("Mtt0to700");
  isTTincMtt0to1000   = outputFileName.Contains("Mtt0to1000");
  isTTincMtt700to1000 = outputFileName.Contains("Mtt700to1000");
  isTTincMtt1000toInf = outputFileName.Contains("Mtt1000toInf");
  outBWBW = outputFileName.Contains("BWBW");
  outTZBW = outputFileName.Contains("TZBW");
  outTHBW = outputFileName.Contains("THBW");
  outTZTH = outputFileName.Contains("TZTH");
  outTZTZ = outputFileName.Contains("TZTZ");
  outTHTH = outputFileName.Contains("THTH");
  outTWTW = outputFileName.Contains("TWTW");
  outBZTW = outputFileName.Contains("BZTW");
  outBHTW = outputFileName.Contains("BHTW");
  outBZBH = outputFileName.Contains("BZBH");
  outBZBZ = outputFileName.Contains("BZBZ");
  outBHBH = outputFileName.Contains("BHBH");

  std::cout<<"Opening file: "<<inputFileName<<std::endl;
  if(!(inputFile=TFile::Open(inputFileName))){
    std::cout<<"WARNING! File doesn't exist! Exiting" << std::endl;
    exit(1);
  }
  inputTree=(TTree*)inputFile->Get("ljmet");
  if(inputTree->GetEntries()==0){
    std::cout<<"WARNING! Found 0 events in the tree!!!!"<<std::endl;;
    exit(1);
  }

  InitPileup();
  
  outputFile=new TFile(outputFileName,"RECREATE");   
  
  Init(inputTree);
}

step1::~step1()
{
   if (!inputTree) return;
   delete inputTree->GetCurrentFile();
}

Int_t step1::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!inputTree) return 0;
   return inputTree->GetEntry(entry);
}
Long64_t step1::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!inputTree) return -5;
   Long64_t centry = inputTree->LoadTree(entry);
   if (centry <= 0) return centry;
   if (inputTree->GetTreeNumber() != fCurrent) {
      fCurrent = inputTree->GetTreeNumber();
      Notify();
   }
   return centry;
}

void step1::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   AK4JetBTag_bSFdn_singleLepCalc = 0;
   AK4JetBTag_bSFup_singleLepCalc = 0;
   AK4JetBTag_lSFdn_singleLepCalc = 0;
   AK4JetBTag_lSFup_singleLepCalc = 0;
   AK4JetBTag_singleLepCalc = 0;
   AK4JetFlav_singleLepCalc = 0;
   HadronicVHtID_JetSubCalc = 0;
   HadronicVHtStatus_JetSubCalc = 0;
   HdecayID_TpTpCalc = 0;
   HdecayIndex_TpTpCalc = 0;
   LHEweightids_singleLepCalc = 0;
   LeptonID_TpTpCalc = 0;
   LeptonParentID_TpTpCalc = 0;
   NewPDFids_singleLepCalc = 0;
   WdecayID_TpTpCalc = 0;
   WdecayIndex_TpTpCalc = 0;
   ZdecayID_TpTpCalc = 0;
   ZdecayIndex_TpTpCalc = 0;
   allTopsID_TTbarMassCalc = 0;
   allTopsStatus_TTbarMassCalc = 0;
   bPrimeID_TpTpCalc = 0;
   bPrimeNDaughters_TpTpCalc = 0;
   bPrimeStatus_TpTpCalc = 0;
   bosonID_TpTpCalc = 0;
   decorr_largest_DeepAK8Calc = 0;
   dnn_largest_BestCalc = 0;
   dnn_largest_DeepAK8Calc = 0;
   elChargeConsistent_singleLepCalc = 0;
   elCharge_singleLepCalc = 0;
   elCtfCharge_singleLepCalc = 0;
   elGsfCharge_singleLepCalc = 0;
   elIsEBEE_singleLepCalc = 0;
   /* elIsMVALooseIso_singleLepCalc = 0; */
   /* elIsMVALoose_singleLepCalc = 0; */
   /* elIsMVATight80_singleLepCalc = 0; */
   /* elIsMVATight90_singleLepCalc = 0; */
   /* elIsMVATightIso80_singleLepCalc = 0; */
   /* elIsMVATightIso90_singleLepCalc = 0; */
   elMHits_singleLepCalc = 0;
   elMatched_singleLepCalc = 0;
   elMother_id_singleLepCalc = 0;
   elMother_status_singleLepCalc = 0;
   elNotConversion_singleLepCalc = 0;
   elNumberOfMothers_singleLepCalc = 0;
   elPdgId_singleLepCalc = 0;
   elScPixCharge_singleLepCalc = 0;
   elStatus_singleLepCalc = 0;
   elVtxFitConv_singleLepCalc = 0;
   electron_1_hltmatched_singleLepCalc = 0;
   genBSLID_singleLepCalc = 0;
   genID_singleLepCalc = 0;
   genIndex_singleLepCalc = 0;
   genMotherID_singleLepCalc = 0;
   genMotherIndex_singleLepCalc = 0;
   genStatus_singleLepCalc = 0;
   genTtbarIdCategory_TTbarMassCalc = 0;
   genTtbarId_TTbarMassCalc = 0;
   maxProb_JetSubCalc = 0;
   muCharge_singleLepCalc = 0;
   muGlobal_singleLepCalc = 0;
   muIsGlobalHighPt_singleLepCalc = 0;
   muIsLoose_singleLepCalc = 0;
   muIsMediumPrompt_singleLepCalc = 0;
   muIsMedium_singleLepCalc = 0;
   muIsMiniIsoLoose_singleLepCalc = 0;
   muIsMiniIsoMedium_singleLepCalc = 0;
   muIsMiniIsoTight_singleLepCalc = 0;
   muIsMiniIsoVeryTight_singleLepCalc = 0;
   muIsMvaLoose_singleLepCalc = 0;
   muIsMvaMedium_singleLepCalc = 0;
   muIsMvaTight_singleLepCalc = 0;
   muIsTight_singleLepCalc = 0;
   muIsTrkHighPt_singleLepCalc = 0;
   muMatched_singleLepCalc = 0;
   muMother_id_singleLepCalc = 0;
   muMother_status_singleLepCalc = 0;
   muNMatchedStations_singleLepCalc = 0;
   muNTrackerLayers_singleLepCalc = 0;
   muNValMuHits_singleLepCalc = 0;
   muNValPixelHits_singleLepCalc = 0;
   muNumberOfMothers_singleLepCalc = 0;
   muPdgId_singleLepCalc = 0;
   muStatus_singleLepCalc = 0;
   muon_1_hltmatched_singleLepCalc = 0;
   quarkID_TpTpCalc = 0;
   tPrimeID_TpTpCalc = 0;
   tPrimeNDaughters_TpTpCalc = 0;
   tPrimeStatus_TpTpCalc = 0;
   theJetAK8SDSubjetBTag_JetSubCalc = 0;
   theJetAK8SDSubjetHFlav_JetSubCalc = 0;
   theJetAK8SDSubjetIndex_JetSubCalc = 0;
   theJetAK8SDSubjetNDeepCSVL_JetSubCalc = 0;
   theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc = 0;
   theJetAK8SDSubjetNDeepCSVM_bSFdn_JetSubCalc = 0;
   theJetAK8SDSubjetNDeepCSVM_bSFup_JetSubCalc = 0;
   theJetAK8SDSubjetNDeepCSVM_lSFdn_JetSubCalc = 0;
   theJetAK8SDSubjetNDeepCSVM_lSFup_JetSubCalc = 0;
   theJetAK8SDSubjetSize_JetSubCalc = 0;
   theJetAK8nDaughters_JetSubCalc = 0;
   theJetBTag_JetSubCalc = 0;
   theJetBTag_bSFdn_JetSubCalc = 0;
   theJetBTag_bSFup_JetSubCalc = 0;
   theJetBTag_lSFdn_JetSubCalc = 0;
   theJetBTag_lSFup_JetSubCalc = 0;
   theJetHFlav_JetSubCalc = 0;
   theJetPFlav_JetSubCalc = 0;
   theJetnDaughters_JetSubCalc = 0;
   topID_TTbarMassCalc = 0;
   topWID_TTbarMassCalc = 0;
   topbID_TTbarMassCalc = 0;
   viSelMCTriggersEl_singleLepCalc = 0;
   viSelMCTriggersMu_singleLepCalc = 0;
   viSelTriggersEl_singleLepCalc = 0;
   viSelTriggersMu_singleLepCalc = 0;
   AK4JetBDeepCSVb_singleLepCalc = 0;
   AK4JetBDeepCSVbb_singleLepCalc = 0;
   AK4JetBDeepCSVc_singleLepCalc = 0;
   AK4JetBDeepCSVudsg_singleLepCalc = 0;
   AK4JetBDisc_singleLepCalc = 0;
   AK4JetEnergy_singleLepCalc = 0;
   AK4JetEta_singleLepCalc = 0;
   AK4JetPhi_singleLepCalc = 0;
   AK4JetPt_singleLepCalc = 0;
   AK8JetCSV_BestCalc = 0;
   AK8JetCSV_singleLepCalc = 0;
   AK8JetDoubleB_singleLepCalc = 0;
   AK8JetEnergy_BestCalc = 0;
   AK8JetEnergy_singleLepCalc = 0;
   AK8JetEta_BestCalc = 0;
   AK8JetEta_singleLepCalc = 0;
   AK8JetPhi_BestCalc = 0;
   AK8JetPhi_singleLepCalc = 0;
   AK8JetPt_BestCalc = 0;
   AK8JetPt_singleLepCalc = 0;
   FWmoment1H_BestCalc = 0;
   FWmoment1W_BestCalc = 0;
   FWmoment1Z_BestCalc = 0;
   FWmoment1top_BestCalc = 0;
   FWmoment2H_BestCalc = 0;
   FWmoment2W_BestCalc = 0;
   FWmoment2Z_BestCalc = 0;
   FWmoment2top_BestCalc = 0;
   FWmoment3H_BestCalc = 0;
   FWmoment3W_BestCalc = 0;
   FWmoment3Z_BestCalc = 0;
   FWmoment3top_BestCalc = 0;
   FWmoment4H_BestCalc = 0;
   FWmoment4W_BestCalc = 0;
   FWmoment4Z_BestCalc = 0;
   FWmoment4top_BestCalc = 0;
   HadronicVHtD0E_JetSubCalc = 0;
   HadronicVHtD0Eta_JetSubCalc = 0;
   HadronicVHtD0Phi_JetSubCalc = 0;
   HadronicVHtD0Pt_JetSubCalc = 0;
   HadronicVHtD1E_JetSubCalc = 0;
   HadronicVHtD1Eta_JetSubCalc = 0;
   HadronicVHtD1Phi_JetSubCalc = 0;
   HadronicVHtD1Pt_JetSubCalc = 0;
   HadronicVHtD2E_JetSubCalc = 0;
   HadronicVHtD2Eta_JetSubCalc = 0;
   HadronicVHtD2Phi_JetSubCalc = 0;
   HadronicVHtD2Pt_JetSubCalc = 0;
   HadronicVHtEnergy_JetSubCalc = 0;
   HadronicVHtEta_JetSubCalc = 0;
   HadronicVHtPhi_JetSubCalc = 0;
   HadronicVHtPt_JetSubCalc = 0;
   HdecayEnergy_TpTpCalc = 0;
   HdecayEta_TpTpCalc = 0;
   HdecayPhi_TpTpCalc = 0;
   HdecayPt_TpTpCalc = 0;
   LHEweights_singleLepCalc = 0;
   LeptonEnergy_TpTpCalc = 0;
   LeptonEta_TpTpCalc = 0;
   LeptonPhi_TpTpCalc = 0;
   LeptonPt_TpTpCalc = 0;
   NewPDFweightsBase_singleLepCalc = 0;
   NewPDFweights_singleLepCalc = 0;
   Njets_H_BestCalc = 0;
   Njets_W_BestCalc = 0;
   Njets_Z_BestCalc = 0;
   Njets_jet_BestCalc = 0;
   Njets_orig_BestCalc = 0;
   Njets_top_BestCalc = 0;
   SDmass_BestCalc = 0;
   WdecayEnergy_TpTpCalc = 0;
   WdecayEta_TpTpCalc = 0;
   WdecayPhi_TpTpCalc = 0;
   WdecayPt_TpTpCalc = 0;
   ZdecayEnergy_TpTpCalc = 0;
   ZdecayEta_TpTpCalc = 0;
   ZdecayPhi_TpTpCalc = 0;
   ZdecayPt_TpTpCalc = 0;
   allTopsEnergy_TTbarMassCalc = 0;
   allTopsEta_TTbarMassCalc = 0;
   allTopsPhi_TTbarMassCalc = 0;
   allTopsPt_TTbarMassCalc = 0;
   aplanarityH_BestCalc = 0;
   aplanarityW_BestCalc = 0;
   aplanarityZ_BestCalc = 0;
   aplanaritytop_BestCalc = 0;
   bDisc1_BestCalc = 0;
   bDisc2_BestCalc = 0;
   bDisc_BestCalc = 0;
   bPrimeEnergy_TpTpCalc = 0;
   bPrimeEta_TpTpCalc = 0;
   bPrimeMass_TpTpCalc = 0;
   bPrimePhi_TpTpCalc = 0;
   bPrimePt_TpTpCalc = 0;
   bosonEnergy_TpTpCalc = 0;
   bosonEta_TpTpCalc = 0;
   bosonPhi_TpTpCalc = 0;
   bosonPt_TpTpCalc = 0;
   decorr_B_DeepAK8Calc = 0;
   decorr_C_DeepAK8Calc = 0;
   decorr_H_DeepAK8Calc = 0;
   decorr_J_DeepAK8Calc = 0;
   decorr_T_DeepAK8Calc = 0;
   decorr_W_DeepAK8Calc = 0;
   decorr_Z_DeepAK8Calc = 0;
   dnn_B_BestCalc = 0;
   dnn_B_DeepAK8Calc = 0;
   dnn_C_DeepAK8Calc = 0;
   dnn_H_DeepAK8Calc = 0;
   dnn_Higgs_BestCalc = 0;
   dnn_J_DeepAK8Calc = 0;
   dnn_QCD_BestCalc = 0;
   dnn_T_DeepAK8Calc = 0;
   dnn_Top_BestCalc = 0;
   dnn_W_BestCalc = 0;
   dnn_W_DeepAK8Calc = 0;
   dnn_Z_BestCalc = 0;
   dnn_Z_DeepAK8Calc = 0;
   elAEff_singleLepCalc = 0;
   elChIso_singleLepCalc = 0;
   elD0_singleLepCalc = 0;
   elDEtaSCTkAtVtx_singleLepCalc = 0;
   elDPhiSCTkAtVtx_singleLepCalc = 0;
   elDR03TkSumPt_singleLepCalc = 0;
   elDZ_singleLepCalc = 0;
   elDeta_singleLepCalc = 0;
   elDphi_singleLepCalc = 0;
   elDxy_singleLepCalc = 0;
   elEcalPFClusterIso_singleLepCalc = 0;
   elEnergy_singleLepCalc = 0;
   elEtaVtx_singleLepCalc = 0;
   elEta_singleLepCalc = 0;
   elGen_Reco_dr_singleLepCalc = 0;
   elHcalPFClusterIso_singleLepCalc = 0;
   elHoE_singleLepCalc = 0;
   elIsLoose_singleLepCalc = 0;
   elIsMedium_singleLepCalc = 0;
   elIsTight_singleLepCalc = 0;
   elIsVeto_singleLepCalc = 0;
   /* elMVAValue_iso_singleLepCalc = 0; */
   /* elMVAValue_singleLepCalc = 0; */
   elMatchedEnergy_singleLepCalc = 0;
   elMatchedEta_singleLepCalc = 0;
   elMatchedPhi_singleLepCalc = 0;
   elMatchedPt_singleLepCalc = 0;
   elMiniIso_singleLepCalc = 0;
   elMother_energy_singleLepCalc = 0;
   elMother_eta_singleLepCalc = 0;
   elMother_phi_singleLepCalc = 0;
   elMother_pt_singleLepCalc = 0;
   elNhIso_singleLepCalc = 0;
   elOoemoop_singleLepCalc = 0;
   elPFEta_singleLepCalc = 0;
   elPFPhi_singleLepCalc = 0;
   elPhIso_singleLepCalc = 0;
   elPhiVtx_singleLepCalc = 0;
   elPhi_singleLepCalc = 0;
   elPt_singleLepCalc = 0;
   elRelIso_singleLepCalc = 0;
   elRhoIso_singleLepCalc = 0;
   elSCE_singleLepCalc = 0;
   elSihih_singleLepCalc = 0;
   et_BestCalc = 0;
   eta_BestCalc = 0;
   evtWeightsMC_singleLepCalc = 0;
   genBSLEnergy_singleLepCalc = 0;
   genBSLEta_singleLepCalc = 0;
   genBSLPhi_singleLepCalc = 0;
   genBSLPt_singleLepCalc = 0;
   genEnergy_singleLepCalc = 0;
   genEta_singleLepCalc = 0;
   genJetEnergy_singleLepCalc = 0;
   genJetEta_singleLepCalc = 0;
   genJetPhi_singleLepCalc = 0;
   genJetPt_singleLepCalc = 0;
   genPhi_singleLepCalc = 0;
   genPt_singleLepCalc = 0;
   isotropyH_BestCalc = 0;
   isotropyW_BestCalc = 0;
   isotropyZ_BestCalc = 0;
   isotropytop_BestCalc = 0;
   m1234H_BestCalc = 0;
   m1234W_BestCalc = 0;
   m1234Z_BestCalc = 0;
   m1234_jet_BestCalc = 0;
   m1234top_BestCalc = 0;
   m12H_BestCalc = 0;
   m12W_BestCalc = 0;
   m12Z_BestCalc = 0;
   m12_jet_BestCalc = 0;
   m12top_BestCalc = 0;
   m13H_BestCalc = 0;
   m13W_BestCalc = 0;
   m13Z_BestCalc = 0;
   m13_jet_BestCalc = 0;
   m13top_BestCalc = 0;
   m23H_BestCalc = 0;
   m23W_BestCalc = 0;
   m23Z_BestCalc = 0;
   m23_jet_BestCalc = 0;
   m23top_BestCalc = 0;
   mass_BestCalc = 0;
   muChIso_singleLepCalc = 0;
   muChi2_singleLepCalc = 0;
   muDxy_singleLepCalc = 0;
   muDz_singleLepCalc = 0;
   muEnergy_singleLepCalc = 0;
   muEta_singleLepCalc = 0;
   muGIso_singleLepCalc = 0;
   muGen_Reco_dr_singleLepCalc = 0;
   muInnerEta_singleLepCalc = 0;
   muInnerPhi_singleLepCalc = 0;
   muInnerPt_singleLepCalc = 0;
   muMatchedEnergy_singleLepCalc = 0;
   muMatchedEta_singleLepCalc = 0;
   muMatchedPhi_singleLepCalc = 0;
   muMatchedPt_singleLepCalc = 0;
   muMiniIsoDB_singleLepCalc = 0;
   muMiniIso_singleLepCalc = 0;
   muMother_energy_singleLepCalc = 0;
   muMother_eta_singleLepCalc = 0;
   muMother_phi_singleLepCalc = 0;
   muMother_pt_singleLepCalc = 0;
   muNhIso_singleLepCalc = 0;
   muPhi_singleLepCalc = 0;
   muPt_singleLepCalc = 0;
   muPuIso_singleLepCalc = 0;
   muRelIso_singleLepCalc = 0;
   pzOverp_H_BestCalc = 0;
   pzOverp_W_BestCalc = 0;
   pzOverp_Z_BestCalc = 0;
   pzOverp_jet_BestCalc = 0;
   pzOverp_top_BestCalc = 0;
   q_BestCalc = 0;
   quarkEnergy_TpTpCalc = 0;
   quarkEta_TpTpCalc = 0;
   quarkPhi_TpTpCalc = 0;
   quarkPt_TpTpCalc = 0;
   sphericityH_BestCalc = 0;
   sphericityW_BestCalc = 0;
   sphericityZ_BestCalc = 0;
   sphericitytop_BestCalc = 0;
   tPrimeEnergy_TpTpCalc = 0;
   tPrimeEta_TpTpCalc = 0;
   tPrimeMass_TpTpCalc = 0;
   tPrimePhi_TpTpCalc = 0;
   tPrimePt_TpTpCalc = 0;
   tau21_BestCalc = 0;
   tau32_BestCalc = 0;
   theJetAK8CHSEta_JetSubCalc = 0;
   theJetAK8CHSMass_JetSubCalc = 0;
   theJetAK8CHSPhi_JetSubCalc = 0;
   theJetAK8CHSPrunedMass_JetSubCalc = 0;
   theJetAK8CHSPt_JetSubCalc = 0;
   theJetAK8CHSSoftDropMass_JetSubCalc = 0;
   theJetAK8CHSTau1_JetSubCalc = 0;
   theJetAK8CHSTau2_JetSubCalc = 0;
   theJetAK8CHSTau3_JetSubCalc = 0;
   theJetAK8CSV_JetSubCalc = 0;
   theJetAK8DoubleB_JetSubCalc = 0;
   theJetAK8Energy_JetSubCalc = 0;
   theJetAK8Eta_JetSubCalc = 0;
   theJetAK8GenDR_JetSubCalc = 0;
   theJetAK8GenMass_JetSubCalc = 0;
   theJetAK8GenPt_JetSubCalc = 0;
   theJetAK8JetCharge_JetSubCalc = 0;
   theJetAK8Mass_JetSubCalc = 0;
   theJetAK8NjettinessTau1_JetSubCalc = 0;
   theJetAK8NjettinessTau2_JetSubCalc = 0;
   theJetAK8NjettinessTau3_JetSubCalc = 0;
   theJetAK8Phi_JetSubCalc = 0;
   theJetAK8Pt_JetSubCalc = 0;
   theJetAK8SDSubjetCSVb_JetSubCalc = 0;
   theJetAK8SDSubjetCSVbb_JetSubCalc = 0;
   theJetAK8SDSubjetCSVc_JetSubCalc = 0;
   theJetAK8SDSubjetCSVudsg_JetSubCalc = 0;
   theJetAK8SDSubjetDR_JetSubCalc = 0;
   theJetAK8SDSubjetEta_JetSubCalc = 0;
   theJetAK8SDSubjetMass_JetSubCalc = 0;
   theJetAK8SDSubjetPhi_JetSubCalc = 0;
   theJetAK8SDSubjetPt_JetSubCalc = 0;
   theJetAK8SoftDropCorr_JetSubCalc = 0;
   theJetAK8SoftDropRaw_JetSubCalc = 0;
   theJetAK8SoftDrop_JMRdn_JetSubCalc = 0;
   theJetAK8SoftDrop_JMRup_JetSubCalc = 0;
   theJetAK8SoftDrop_JMSdn_JetSubCalc = 0;
   theJetAK8SoftDrop_JMSup_JetSubCalc = 0;
   theJetAK8SoftDrop_JetSubCalc = 0;
   theJetAK8SoftDropn2b1_JetSubCalc = 0;
   theJetAK8SoftDropn2b2_JetSubCalc = 0;
   theJetAK8SoftDropn3b1_JetSubCalc = 0;
   theJetAK8SoftDropn3b2_JetSubCalc = 0;
   theJetDeepCSVb_JetSubCalc = 0;
   theJetDeepCSVbb_JetSubCalc = 0;
   theJetDeepCSVc_JetSubCalc = 0;
   theJetDeepCSVudsg_JetSubCalc = 0;
   theJetEnergy_JetSubCalc = 0;
   theJetEta_JetSubCalc = 0;
   theJetPhi_JetSubCalc = 0;
   theJetPileupJetId_JetSubCalc = 0;
   theJetPt_JetSubCalc = 0;
   thrustH_BestCalc = 0;
   thrustW_BestCalc = 0;
   thrustZ_BestCalc = 0;
   thrusttop_BestCalc = 0;
   topEnergy_TTbarMassCalc = 0;
   topEta_TTbarMassCalc = 0;
   topMass_TTbarMassCalc = 0;
   topPhi_TTbarMassCalc = 0;
   topPt_TTbarMassCalc = 0;
   topWEnergy_TTbarMassCalc = 0;
   topWEta_TTbarMassCalc = 0;
   topWPhi_TTbarMassCalc = 0;
   topWPt_TTbarMassCalc = 0;
   topbEnergy_TTbarMassCalc = 0;
   topbEta_TTbarMassCalc = 0;
   topbPhi_TTbarMassCalc = 0;
   topbPt_TTbarMassCalc = 0;
   electron_hltfilters_singleLepCalc = 0;
   muon_hltfilters_singleLepCalc = 0;
   vsSelMCTriggersEl_singleLepCalc = 0;
   vsSelMCTriggersMu_singleLepCalc = 0;
   vsSelTriggersEl_singleLepCalc = 0;
   vsSelTriggersMu_singleLepCalc = 0;

   // Set branch addresses and branch pointers
   if (!tree) return;
   inputTree = tree;
   fCurrent = -1;
   inputTree->SetMakeClass(1);

   inputTree->SetBranchAddress("flagBadMu_singleLepCalc", &flagBadMu_singleLepCalc, &b_flagBadMu_singleLepCalc);
   inputTree->SetBranchAddress("flagDupMu_singleLepCalc", &flagDupMu_singleLepCalc, &b_flagDupMu_singleLepCalc);
   inputTree->SetBranchAddress("isBHBH_TpTpCalc", &isBHBH_TpTpCalc, &b_isBHBH_TpTpCalc);
   inputTree->SetBranchAddress("isBHTW_TpTpCalc", &isBHTW_TpTpCalc, &b_isBHTW_TpTpCalc);
   inputTree->SetBranchAddress("isBWBW_TpTpCalc", &isBWBW_TpTpCalc, &b_isBWBW_TpTpCalc);
   inputTree->SetBranchAddress("isBZBH_TpTpCalc", &isBZBH_TpTpCalc, &b_isBZBH_TpTpCalc);
   inputTree->SetBranchAddress("isBZBZ_TpTpCalc", &isBZBZ_TpTpCalc, &b_isBZBZ_TpTpCalc);
   inputTree->SetBranchAddress("isBZTW_TpTpCalc", &isBZTW_TpTpCalc, &b_isBZTW_TpTpCalc);
   inputTree->SetBranchAddress("isTHBW_TpTpCalc", &isTHBW_TpTpCalc, &b_isTHBW_TpTpCalc);
   inputTree->SetBranchAddress("isTHTH_TpTpCalc", &isTHTH_TpTpCalc, &b_isTHTH_TpTpCalc);
   inputTree->SetBranchAddress("isTWTW_TpTpCalc", &isTWTW_TpTpCalc, &b_isTWTW_TpTpCalc);
   inputTree->SetBranchAddress("isTZBW_TpTpCalc", &isTZBW_TpTpCalc, &b_isTZBW_TpTpCalc);
   inputTree->SetBranchAddress("isTZTH_TpTpCalc", &isTZTH_TpTpCalc, &b_isTZTH_TpTpCalc);
   inputTree->SetBranchAddress("isTZTZ_TpTpCalc", &isTZTZ_TpTpCalc, &b_isTZTZ_TpTpCalc);
   inputTree->SetBranchAddress("isTau_singleLepCalc", &isTau_singleLepCalc, &b_isTau_singleLepCalc);
   inputTree->SetBranchAddress("NLeptonDecays_TpTpCalc", &NLeptonDecays_TpTpCalc, &b_NLeptonDecays_TpTpCalc);
   inputTree->SetBranchAddress("NPartonsfromHEPUEP_singleLepCalc", &NPartonsfromHEPUEP_singleLepCalc, &b_NPartonsfromHEPUEP_singleLepCalc);
   inputTree->SetBranchAddress("dataE_singleLepCalc", &dataE_singleLepCalc, &b_dataE_singleLepCalc);
   inputTree->SetBranchAddress("dataM_singleLepCalc", &dataM_singleLepCalc, &b_dataM_singleLepCalc);
   inputTree->SetBranchAddress("genTDLID_singleLepCalc", &genTDLID_singleLepCalc, &b_genTDLID_singleLepCalc);
   inputTree->SetBranchAddress("lumi_CommonCalc", &lumi_CommonCalc, &b_lumi_CommonCalc);
   inputTree->SetBranchAddress("nAllJets_CommonCalc", &nAllJets_CommonCalc, &b_nAllJets_CommonCalc);
   inputTree->SetBranchAddress("nLooseMuons_CommonCalc", &nLooseMuons_CommonCalc, &b_nLooseMuons_CommonCalc);
   //   inputTree->SetBranchAddress("nPV_singleLepCalc", &nPV_singleLepCalc, &b_nPV_singleLepCalc);
   inputTree->SetBranchAddress("nPileupInteractions_singleLepCalc", &nPileupInteractions_singleLepCalc, &b_nPileupInteractions_singleLepCalc);
   inputTree->SetBranchAddress("nSelBtagJets_CommonCalc", &nSelBtagJets_CommonCalc, &b_nSelBtagJets_CommonCalc);
   inputTree->SetBranchAddress("nSelElectrons_CommonCalc", &nSelElectrons_CommonCalc, &b_nSelElectrons_CommonCalc);
   inputTree->SetBranchAddress("nSelJets_CommonCalc", &nSelJets_CommonCalc, &b_nSelJets_CommonCalc);
   inputTree->SetBranchAddress("nTightMuons_CommonCalc", &nTightMuons_CommonCalc, &b_nTightMuons_CommonCalc);
   inputTree->SetBranchAddress("nTrueInteractions_singleLepCalc", &nTrueInteractions_singleLepCalc, &b_nTrueInteractions_singleLepCalc);
   inputTree->SetBranchAddress("run_CommonCalc", &run_CommonCalc, &b_run_CommonCalc);
   inputTree->SetBranchAddress("event_CommonCalc", &event_CommonCalc, &b_event_CommonCalc);
   inputTree->SetBranchAddress("AK4HT_singleLepCalc", &AK4HT_singleLepCalc, &b_AK4HT_singleLepCalc);
   inputTree->SetBranchAddress("HTfromHEPUEP_singleLepCalc", &HTfromHEPUEP_singleLepCalc, &b_HTfromHEPUEP_singleLepCalc);
   inputTree->SetBranchAddress("L1NonPrefiringProbDown_CommonCalc", &L1NonPrefiringProbDown_CommonCalc, &b_L1NonPrefiringProbDown_CommonCalc);
   inputTree->SetBranchAddress("L1NonPrefiringProbUp_CommonCalc", &L1NonPrefiringProbUp_CommonCalc, &b_L1NonPrefiringProbUp_CommonCalc);
   inputTree->SetBranchAddress("L1NonPrefiringProb_CommonCalc", &L1NonPrefiringProb_CommonCalc, &b_L1NonPrefiringProb_CommonCalc);
   inputTree->SetBranchAddress("LHEweightorig_singleLepCalc", &LHEweightorig_singleLepCalc, &b_LHEweightorig_singleLepCalc);
   inputTree->SetBranchAddress("MCWeight_singleLepCalc", &MCWeight_singleLepCalc, &b_MCWeight_singleLepCalc);
   inputTree->SetBranchAddress("corr_met_jerdn_phi_singleLepCalc", &corr_met_jerdn_phi_singleLepCalc, &b_corr_met_jerdn_phi_singleLepCalc);
   inputTree->SetBranchAddress("corr_met_jerdn_singleLepCalc", &corr_met_jerdn_singleLepCalc, &b_corr_met_jerdn_singleLepCalc);
   inputTree->SetBranchAddress("corr_met_jerup_phi_singleLepCalc", &corr_met_jerup_phi_singleLepCalc, &b_corr_met_jerup_phi_singleLepCalc);
   inputTree->SetBranchAddress("corr_met_jerup_singleLepCalc", &corr_met_jerup_singleLepCalc, &b_corr_met_jerup_singleLepCalc);
   inputTree->SetBranchAddress("corr_met_jesdn_phi_singleLepCalc", &corr_met_jesdn_phi_singleLepCalc, &b_corr_met_jesdn_phi_singleLepCalc);
   inputTree->SetBranchAddress("corr_met_jesdn_singleLepCalc", &corr_met_jesdn_singleLepCalc, &b_corr_met_jesdn_singleLepCalc);
   inputTree->SetBranchAddress("corr_met_jesup_phi_singleLepCalc", &corr_met_jesup_phi_singleLepCalc, &b_corr_met_jesup_phi_singleLepCalc);
   inputTree->SetBranchAddress("corr_met_jesup_singleLepCalc", &corr_met_jesup_singleLepCalc, &b_corr_met_jesup_singleLepCalc);
   inputTree->SetBranchAddress("corr_met_phi_singleLepCalc", &corr_met_phi_singleLepCalc, &b_corr_met_phi_singleLepCalc);
   inputTree->SetBranchAddress("corr_met_singleLepCalc", &corr_met_singleLepCalc, &b_corr_met_singleLepCalc);
   inputTree->SetBranchAddress("corr_metmod_phi_singleLepCalc", &corr_metmod_phi_singleLepCalc, &b_corr_metmod_phi_singleLepCalc);
   inputTree->SetBranchAddress("corr_metmod_singleLepCalc", &corr_metmod_singleLepCalc, &b_corr_metmod_singleLepCalc);
   inputTree->SetBranchAddress("corr_metnohf_phi_singleLepCalc", &corr_metnohf_phi_singleLepCalc, &b_corr_metnohf_phi_singleLepCalc);
   inputTree->SetBranchAddress("corr_metnohf_singleLepCalc", &corr_metnohf_singleLepCalc, &b_corr_metnohf_singleLepCalc);
   inputTree->SetBranchAddress("genTDLEnergy_singleLepCalc", &genTDLEnergy_singleLepCalc, &b_genTDLEnergy_singleLepCalc);
   inputTree->SetBranchAddress("genTDLEta_singleLepCalc", &genTDLEta_singleLepCalc, &b_genTDLEta_singleLepCalc);
   inputTree->SetBranchAddress("genTDLPhi_singleLepCalc", &genTDLPhi_singleLepCalc, &b_genTDLPhi_singleLepCalc);
   inputTree->SetBranchAddress("genTDLPt_singleLepCalc", &genTDLPt_singleLepCalc, &b_genTDLPt_singleLepCalc);
   inputTree->SetBranchAddress("met_phi_singleLepCalc", &met_phi_singleLepCalc, &b_met_phi_singleLepCalc);
   inputTree->SetBranchAddress("met_singleLepCalc", &met_singleLepCalc, &b_met_singleLepCalc);
   inputTree->SetBranchAddress("metmod_phi_singleLepCalc", &metmod_phi_singleLepCalc, &b_metmod_phi_singleLepCalc);
   inputTree->SetBranchAddress("metmod_singleLepCalc", &metmod_singleLepCalc, &b_metmod_singleLepCalc);
   inputTree->SetBranchAddress("metnohf_phi_singleLepCalc", &metnohf_phi_singleLepCalc, &b_metnohf_phi_singleLepCalc);
   inputTree->SetBranchAddress("metnohf_singleLepCalc", &metnohf_singleLepCalc, &b_metnohf_singleLepCalc);
   inputTree->SetBranchAddress("theJetHT_JetSubCalc", &theJetHT_JetSubCalc, &b_theJetHT_JetSubCalc);
   inputTree->SetBranchAddress("theJetLeadPt_JetSubCalc", &theJetLeadPt_JetSubCalc, &b_theJetLeadPt_JetSubCalc);
   inputTree->SetBranchAddress("theJetSubLeadPt_JetSubCalc", &theJetSubLeadPt_JetSubCalc, &b_theJetSubLeadPt_JetSubCalc);
   inputTree->SetBranchAddress("ttbarMass_TTbarMassCalc", &ttbarMass_TTbarMassCalc, &b_ttbarMass_TTbarMassCalc);
   inputTree->SetBranchAddress("AK4JetBTag_bSFdn_singleLepCalc", &AK4JetBTag_bSFdn_singleLepCalc, &b_AK4JetBTag_bSFdn_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetBTag_bSFup_singleLepCalc", &AK4JetBTag_bSFup_singleLepCalc, &b_AK4JetBTag_bSFup_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetBTag_lSFdn_singleLepCalc", &AK4JetBTag_lSFdn_singleLepCalc, &b_AK4JetBTag_lSFdn_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetBTag_lSFup_singleLepCalc", &AK4JetBTag_lSFup_singleLepCalc, &b_AK4JetBTag_lSFup_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetBTag_singleLepCalc", &AK4JetBTag_singleLepCalc, &b_AK4JetBTag_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetFlav_singleLepCalc", &AK4JetFlav_singleLepCalc, &b_AK4JetFlav_singleLepCalc);
   inputTree->SetBranchAddress("HadronicVHtID_JetSubCalc", &HadronicVHtID_JetSubCalc, &b_HadronicVHtID_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtStatus_JetSubCalc", &HadronicVHtStatus_JetSubCalc, &b_HadronicVHtStatus_JetSubCalc);
   inputTree->SetBranchAddress("HdecayID_TpTpCalc", &HdecayID_TpTpCalc, &b_HdecayID_TpTpCalc);
   inputTree->SetBranchAddress("HdecayIndex_TpTpCalc", &HdecayIndex_TpTpCalc, &b_HdecayIndex_TpTpCalc);
   inputTree->SetBranchAddress("LHEweightids_singleLepCalc", &LHEweightids_singleLepCalc, &b_LHEweightids_singleLepCalc);
   inputTree->SetBranchAddress("LeptonID_TpTpCalc", &LeptonID_TpTpCalc, &b_LeptonID_TpTpCalc);
   inputTree->SetBranchAddress("LeptonParentID_TpTpCalc", &LeptonParentID_TpTpCalc, &b_LeptonParentID_TpTpCalc);
   inputTree->SetBranchAddress("NewPDFids_singleLepCalc", &NewPDFids_singleLepCalc, &b_NewPDFids_singleLepCalc);
   inputTree->SetBranchAddress("WdecayID_TpTpCalc", &WdecayID_TpTpCalc, &b_WdecayID_TpTpCalc);
   inputTree->SetBranchAddress("WdecayIndex_TpTpCalc", &WdecayIndex_TpTpCalc, &b_WdecayIndex_TpTpCalc);
   inputTree->SetBranchAddress("ZdecayID_TpTpCalc", &ZdecayID_TpTpCalc, &b_ZdecayID_TpTpCalc);
   inputTree->SetBranchAddress("ZdecayIndex_TpTpCalc", &ZdecayIndex_TpTpCalc, &b_ZdecayIndex_TpTpCalc);
   inputTree->SetBranchAddress("allTopsID_TTbarMassCalc", &allTopsID_TTbarMassCalc, &b_allTopsID_TTbarMassCalc);
   inputTree->SetBranchAddress("allTopsStatus_TTbarMassCalc", &allTopsStatus_TTbarMassCalc, &b_allTopsStatus_TTbarMassCalc);
   inputTree->SetBranchAddress("bPrimeID_TpTpCalc", &bPrimeID_TpTpCalc, &b_bPrimeID_TpTpCalc);
   inputTree->SetBranchAddress("bPrimeNDaughters_TpTpCalc", &bPrimeNDaughters_TpTpCalc, &b_bPrimeNDaughters_TpTpCalc);
   inputTree->SetBranchAddress("bPrimeStatus_TpTpCalc", &bPrimeStatus_TpTpCalc, &b_bPrimeStatus_TpTpCalc);
   inputTree->SetBranchAddress("bosonID_TpTpCalc", &bosonID_TpTpCalc, &b_bosonID_TpTpCalc);
   inputTree->SetBranchAddress("decorr_largest_DeepAK8Calc", &decorr_largest_DeepAK8Calc, &b_decorr_largest_DeepAK8Calc);
   inputTree->SetBranchAddress("dnn_largest_BestCalc", &dnn_largest_BestCalc, &b_dnn_largest_BestCalc);
   inputTree->SetBranchAddress("dnn_largest_DeepAK8Calc", &dnn_largest_DeepAK8Calc, &b_dnn_largest_DeepAK8Calc);
   inputTree->SetBranchAddress("elChargeConsistent_singleLepCalc", &elChargeConsistent_singleLepCalc, &b_elChargeConsistent_singleLepCalc);
   inputTree->SetBranchAddress("elCharge_singleLepCalc", &elCharge_singleLepCalc, &b_elCharge_singleLepCalc);
   inputTree->SetBranchAddress("elCtfCharge_singleLepCalc", &elCtfCharge_singleLepCalc, &b_elCtfCharge_singleLepCalc);
   inputTree->SetBranchAddress("elGsfCharge_singleLepCalc", &elGsfCharge_singleLepCalc, &b_elGsfCharge_singleLepCalc);
   inputTree->SetBranchAddress("elIsEBEE_singleLepCalc", &elIsEBEE_singleLepCalc, &b_elIsEBEE_singleLepCalc);
   /* inputTree->SetBranchAddress("elIsMVALooseIso_singleLepCalc", &elIsMVALooseIso_singleLepCalc, &b_elIsMVALooseIso_singleLepCalc); */
   /* inputTree->SetBranchAddress("elIsMVALoose_singleLepCalc", &elIsMVALoose_singleLepCalc, &b_elIsMVALoose_singleLepCalc); */
   /* inputTree->SetBranchAddress("elIsMVATight80_singleLepCalc", &elIsMVATight80_singleLepCalc, &b_elIsMVATight80_singleLepCalc); */
   /* inputTree->SetBranchAddress("elIsMVATight90_singleLepCalc", &elIsMVATight90_singleLepCalc, &b_elIsMVATight90_singleLepCalc); */
   /* inputTree->SetBranchAddress("elIsMVATightIso80_singleLepCalc", &elIsMVATightIso80_singleLepCalc, &b_elIsMVATightIso80_singleLepCalc); */
   /* inputTree->SetBranchAddress("elIsMVATightIso90_singleLepCalc", &elIsMVATightIso90_singleLepCalc, &b_elIsMVATightIso90_singleLepCalc); */
   inputTree->SetBranchAddress("elMHits_singleLepCalc", &elMHits_singleLepCalc, &b_elMHits_singleLepCalc);
   inputTree->SetBranchAddress("elMatched_singleLepCalc", &elMatched_singleLepCalc, &b_elMatched_singleLepCalc);
   inputTree->SetBranchAddress("elMother_id_singleLepCalc", &elMother_id_singleLepCalc, &b_elMother_id_singleLepCalc);
   inputTree->SetBranchAddress("elMother_status_singleLepCalc", &elMother_status_singleLepCalc, &b_elMother_status_singleLepCalc);
   inputTree->SetBranchAddress("elNotConversion_singleLepCalc", &elNotConversion_singleLepCalc, &b_elNotConversion_singleLepCalc);
   inputTree->SetBranchAddress("elNumberOfMothers_singleLepCalc", &elNumberOfMothers_singleLepCalc, &b_elNumberOfMothers_singleLepCalc);
   inputTree->SetBranchAddress("elPdgId_singleLepCalc", &elPdgId_singleLepCalc, &b_elPdgId_singleLepCalc);
   inputTree->SetBranchAddress("elScPixCharge_singleLepCalc", &elScPixCharge_singleLepCalc, &b_elScPixCharge_singleLepCalc);
   inputTree->SetBranchAddress("elStatus_singleLepCalc", &elStatus_singleLepCalc, &b_elStatus_singleLepCalc);
   inputTree->SetBranchAddress("elVtxFitConv_singleLepCalc", &elVtxFitConv_singleLepCalc, &b_elVtxFitConv_singleLepCalc);
   inputTree->SetBranchAddress("electron_1_hltmatched_singleLepCalc", &electron_1_hltmatched_singleLepCalc, &b_electron_1_hltmatched_singleLepCalc);
   inputTree->SetBranchAddress("genBSLID_singleLepCalc", &genBSLID_singleLepCalc, &b_genBSLID_singleLepCalc);
   inputTree->SetBranchAddress("genID_singleLepCalc", &genID_singleLepCalc, &b_genID_singleLepCalc);
   inputTree->SetBranchAddress("genIndex_singleLepCalc", &genIndex_singleLepCalc, &b_genIndex_singleLepCalc);
   inputTree->SetBranchAddress("genMotherID_singleLepCalc", &genMotherID_singleLepCalc, &b_genMotherID_singleLepCalc);
   inputTree->SetBranchAddress("genMotherIndex_singleLepCalc", &genMotherIndex_singleLepCalc, &b_genMotherIndex_singleLepCalc);
   inputTree->SetBranchAddress("genStatus_singleLepCalc", &genStatus_singleLepCalc, &b_genStatus_singleLepCalc);
   inputTree->SetBranchAddress("genTtbarIdCategory_TTbarMassCalc", &genTtbarIdCategory_TTbarMassCalc, &b_genTtbarIdCategory_TTbarMassCalc);
   inputTree->SetBranchAddress("genTtbarId_TTbarMassCalc", &genTtbarId_TTbarMassCalc, &b_genTtbarId_TTbarMassCalc);
   inputTree->SetBranchAddress("maxProb_JetSubCalc", &maxProb_JetSubCalc, &b_maxProb_JetSubCalc);
   inputTree->SetBranchAddress("muCharge_singleLepCalc", &muCharge_singleLepCalc, &b_muCharge_singleLepCalc);
   inputTree->SetBranchAddress("muGlobal_singleLepCalc", &muGlobal_singleLepCalc, &b_muGlobal_singleLepCalc);
   inputTree->SetBranchAddress("muIsGlobalHighPt_singleLepCalc", &muIsGlobalHighPt_singleLepCalc, &b_muIsGlobalHighPt_singleLepCalc);
   inputTree->SetBranchAddress("muIsLoose_singleLepCalc", &muIsLoose_singleLepCalc, &b_muIsLoose_singleLepCalc);
   inputTree->SetBranchAddress("muIsMediumPrompt_singleLepCalc", &muIsMediumPrompt_singleLepCalc, &b_muIsMediumPrompt_singleLepCalc);
   inputTree->SetBranchAddress("muIsMedium_singleLepCalc", &muIsMedium_singleLepCalc, &b_muIsMedium_singleLepCalc);
   inputTree->SetBranchAddress("muIsMiniIsoLoose_singleLepCalc", &muIsMiniIsoLoose_singleLepCalc, &b_muIsMiniIsoLoose_singleLepCalc);
   inputTree->SetBranchAddress("muIsMiniIsoMedium_singleLepCalc", &muIsMiniIsoMedium_singleLepCalc, &b_muIsMiniIsoMedium_singleLepCalc);
   inputTree->SetBranchAddress("muIsMiniIsoTight_singleLepCalc", &muIsMiniIsoTight_singleLepCalc, &b_muIsMiniIsoTight_singleLepCalc);
   inputTree->SetBranchAddress("muIsMiniIsoVeryTight_singleLepCalc", &muIsMiniIsoVeryTight_singleLepCalc, &b_muIsMiniIsoVeryTight_singleLepCalc);
   inputTree->SetBranchAddress("muIsMvaLoose_singleLepCalc", &muIsMvaLoose_singleLepCalc, &b_muIsMvaLoose_singleLepCalc);
   inputTree->SetBranchAddress("muIsMvaMedium_singleLepCalc", &muIsMvaMedium_singleLepCalc, &b_muIsMvaMedium_singleLepCalc);
   inputTree->SetBranchAddress("muIsMvaTight_singleLepCalc", &muIsMvaTight_singleLepCalc, &b_muIsMvaTight_singleLepCalc);
   inputTree->SetBranchAddress("muIsTight_singleLepCalc", &muIsTight_singleLepCalc, &b_muIsTight_singleLepCalc);
   inputTree->SetBranchAddress("muIsTrkHighPt_singleLepCalc", &muIsTrkHighPt_singleLepCalc, &b_muIsTrkHighPt_singleLepCalc);
   inputTree->SetBranchAddress("muMatched_singleLepCalc", &muMatched_singleLepCalc, &b_muMatched_singleLepCalc);
   inputTree->SetBranchAddress("muMother_id_singleLepCalc", &muMother_id_singleLepCalc, &b_muMother_id_singleLepCalc);
   inputTree->SetBranchAddress("muMother_status_singleLepCalc", &muMother_status_singleLepCalc, &b_muMother_status_singleLepCalc);
   inputTree->SetBranchAddress("muNMatchedStations_singleLepCalc", &muNMatchedStations_singleLepCalc, &b_muNMatchedStations_singleLepCalc);
   inputTree->SetBranchAddress("muNTrackerLayers_singleLepCalc", &muNTrackerLayers_singleLepCalc, &b_muNTrackerLayers_singleLepCalc);
   inputTree->SetBranchAddress("muNValMuHits_singleLepCalc", &muNValMuHits_singleLepCalc, &b_muNValMuHits_singleLepCalc);
   inputTree->SetBranchAddress("muNValPixelHits_singleLepCalc", &muNValPixelHits_singleLepCalc, &b_muNValPixelHits_singleLepCalc);
   inputTree->SetBranchAddress("muNumberOfMothers_singleLepCalc", &muNumberOfMothers_singleLepCalc, &b_muNumberOfMothers_singleLepCalc);
   inputTree->SetBranchAddress("muPdgId_singleLepCalc", &muPdgId_singleLepCalc, &b_muPdgId_singleLepCalc);
   inputTree->SetBranchAddress("muStatus_singleLepCalc", &muStatus_singleLepCalc, &b_muStatus_singleLepCalc);
   inputTree->SetBranchAddress("muon_1_hltmatched_singleLepCalc", &muon_1_hltmatched_singleLepCalc, &b_muon_1_hltmatched_singleLepCalc);
   inputTree->SetBranchAddress("quarkID_TpTpCalc", &quarkID_TpTpCalc, &b_quarkID_TpTpCalc);
   inputTree->SetBranchAddress("tPrimeID_TpTpCalc", &tPrimeID_TpTpCalc, &b_tPrimeID_TpTpCalc);
   inputTree->SetBranchAddress("tPrimeNDaughters_TpTpCalc", &tPrimeNDaughters_TpTpCalc, &b_tPrimeNDaughters_TpTpCalc);
   inputTree->SetBranchAddress("tPrimeStatus_TpTpCalc", &tPrimeStatus_TpTpCalc, &b_tPrimeStatus_TpTpCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetBTag_JetSubCalc", &theJetAK8SDSubjetBTag_JetSubCalc, &b_theJetAK8SDSubjetBTag_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetHFlav_JetSubCalc", &theJetAK8SDSubjetHFlav_JetSubCalc, &b_theJetAK8SDSubjetHFlav_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetIndex_JetSubCalc", &theJetAK8SDSubjetIndex_JetSubCalc, &b_theJetAK8SDSubjetIndex_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNDeepCSVL_JetSubCalc", &theJetAK8SDSubjetNDeepCSVL_JetSubCalc, &b_theJetAK8SDSubjetNDeepCSVL_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc", &theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc, &b_theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNDeepCSVM_bSFdn_JetSubCalc", &theJetAK8SDSubjetNDeepCSVM_bSFdn_JetSubCalc, &b_theJetAK8SDSubjetNDeepCSVM_bSFdn_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNDeepCSVM_bSFup_JetSubCalc", &theJetAK8SDSubjetNDeepCSVM_bSFup_JetSubCalc, &b_theJetAK8SDSubjetNDeepCSVM_bSFup_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNDeepCSVM_lSFdn_JetSubCalc", &theJetAK8SDSubjetNDeepCSVM_lSFdn_JetSubCalc, &b_theJetAK8SDSubjetNDeepCSVM_lSFdn_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNDeepCSVM_lSFup_JetSubCalc", &theJetAK8SDSubjetNDeepCSVM_lSFup_JetSubCalc, &b_theJetAK8SDSubjetNDeepCSVM_lSFup_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetSize_JetSubCalc", &theJetAK8SDSubjetSize_JetSubCalc, &b_theJetAK8SDSubjetSize_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8nDaughters_JetSubCalc", &theJetAK8nDaughters_JetSubCalc, &b_theJetAK8nDaughters_JetSubCalc);
   inputTree->SetBranchAddress("theJetBTag_JetSubCalc", &theJetBTag_JetSubCalc, &b_theJetBTag_JetSubCalc);
   inputTree->SetBranchAddress("theJetBTag_bSFdn_JetSubCalc", &theJetBTag_bSFdn_JetSubCalc, &b_theJetBTag_bSFdn_JetSubCalc);
   inputTree->SetBranchAddress("theJetBTag_bSFup_JetSubCalc", &theJetBTag_bSFup_JetSubCalc, &b_theJetBTag_bSFup_JetSubCalc);
   inputTree->SetBranchAddress("theJetBTag_lSFdn_JetSubCalc", &theJetBTag_lSFdn_JetSubCalc, &b_theJetBTag_lSFdn_JetSubCalc);
   inputTree->SetBranchAddress("theJetBTag_lSFup_JetSubCalc", &theJetBTag_lSFup_JetSubCalc, &b_theJetBTag_lSFup_JetSubCalc);
   inputTree->SetBranchAddress("theJetHFlav_JetSubCalc", &theJetHFlav_JetSubCalc, &b_theJetHFlav_JetSubCalc);
   inputTree->SetBranchAddress("theJetPFlav_JetSubCalc", &theJetPFlav_JetSubCalc, &b_theJetPFlav_JetSubCalc);
   inputTree->SetBranchAddress("theJetnDaughters_JetSubCalc", &theJetnDaughters_JetSubCalc, &b_theJetnDaughters_JetSubCalc);
   inputTree->SetBranchAddress("topID_TTbarMassCalc", &topID_TTbarMassCalc, &b_topID_TTbarMassCalc);
   inputTree->SetBranchAddress("topWID_TTbarMassCalc", &topWID_TTbarMassCalc, &b_topWID_TTbarMassCalc);
   inputTree->SetBranchAddress("topbID_TTbarMassCalc", &topbID_TTbarMassCalc, &b_topbID_TTbarMassCalc);
   inputTree->SetBranchAddress("viSelMCTriggersEl_singleLepCalc", &viSelMCTriggersEl_singleLepCalc, &b_viSelMCTriggersEl_singleLepCalc);
   inputTree->SetBranchAddress("viSelMCTriggersMu_singleLepCalc", &viSelMCTriggersMu_singleLepCalc, &b_viSelMCTriggersMu_singleLepCalc);
   inputTree->SetBranchAddress("viSelTriggersEl_singleLepCalc", &viSelTriggersEl_singleLepCalc, &b_viSelTriggersEl_singleLepCalc);
   inputTree->SetBranchAddress("viSelTriggersMu_singleLepCalc", &viSelTriggersMu_singleLepCalc, &b_viSelTriggersMu_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetBDeepCSVb_singleLepCalc", &AK4JetBDeepCSVb_singleLepCalc, &b_AK4JetBDeepCSVb_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetBDeepCSVbb_singleLepCalc", &AK4JetBDeepCSVbb_singleLepCalc, &b_AK4JetBDeepCSVbb_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetBDeepCSVc_singleLepCalc", &AK4JetBDeepCSVc_singleLepCalc, &b_AK4JetBDeepCSVc_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetBDeepCSVudsg_singleLepCalc", &AK4JetBDeepCSVudsg_singleLepCalc, &b_AK4JetBDeepCSVudsg_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetBDisc_singleLepCalc", &AK4JetBDisc_singleLepCalc, &b_AK4JetBDisc_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetEnergy_singleLepCalc", &AK4JetEnergy_singleLepCalc, &b_AK4JetEnergy_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetEta_singleLepCalc", &AK4JetEta_singleLepCalc, &b_AK4JetEta_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetPhi_singleLepCalc", &AK4JetPhi_singleLepCalc, &b_AK4JetPhi_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetPt_singleLepCalc", &AK4JetPt_singleLepCalc, &b_AK4JetPt_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetCSV_BestCalc", &AK8JetCSV_BestCalc, &b_AK8JetCSV_BestCalc);
   inputTree->SetBranchAddress("AK8JetCSV_singleLepCalc", &AK8JetCSV_singleLepCalc, &b_AK8JetCSV_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetDoubleB_singleLepCalc", &AK8JetDoubleB_singleLepCalc, &b_AK8JetDoubleB_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetEnergy_BestCalc", &AK8JetEnergy_BestCalc, &b_AK8JetEnergy_BestCalc);
   inputTree->SetBranchAddress("AK8JetEnergy_singleLepCalc", &AK8JetEnergy_singleLepCalc, &b_AK8JetEnergy_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetEta_BestCalc", &AK8JetEta_BestCalc, &b_AK8JetEta_BestCalc);
   inputTree->SetBranchAddress("AK8JetEta_singleLepCalc", &AK8JetEta_singleLepCalc, &b_AK8JetEta_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetPhi_BestCalc", &AK8JetPhi_BestCalc, &b_AK8JetPhi_BestCalc);
   inputTree->SetBranchAddress("AK8JetPhi_singleLepCalc", &AK8JetPhi_singleLepCalc, &b_AK8JetPhi_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetPt_BestCalc", &AK8JetPt_BestCalc, &b_AK8JetPt_BestCalc);
   inputTree->SetBranchAddress("AK8JetPt_singleLepCalc", &AK8JetPt_singleLepCalc, &b_AK8JetPt_singleLepCalc);
   inputTree->SetBranchAddress("HadronicVHtD0E_JetSubCalc", &HadronicVHtD0E_JetSubCalc, &b_HadronicVHtD0E_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtD0Eta_JetSubCalc", &HadronicVHtD0Eta_JetSubCalc, &b_HadronicVHtD0Eta_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtD0Phi_JetSubCalc", &HadronicVHtD0Phi_JetSubCalc, &b_HadronicVHtD0Phi_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtD0Pt_JetSubCalc", &HadronicVHtD0Pt_JetSubCalc, &b_HadronicVHtD0Pt_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtD1E_JetSubCalc", &HadronicVHtD1E_JetSubCalc, &b_HadronicVHtD1E_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtD1Eta_JetSubCalc", &HadronicVHtD1Eta_JetSubCalc, &b_HadronicVHtD1Eta_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtD1Phi_JetSubCalc", &HadronicVHtD1Phi_JetSubCalc, &b_HadronicVHtD1Phi_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtD1Pt_JetSubCalc", &HadronicVHtD1Pt_JetSubCalc, &b_HadronicVHtD1Pt_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtD2E_JetSubCalc", &HadronicVHtD2E_JetSubCalc, &b_HadronicVHtD2E_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtD2Eta_JetSubCalc", &HadronicVHtD2Eta_JetSubCalc, &b_HadronicVHtD2Eta_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtD2Phi_JetSubCalc", &HadronicVHtD2Phi_JetSubCalc, &b_HadronicVHtD2Phi_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtD2Pt_JetSubCalc", &HadronicVHtD2Pt_JetSubCalc, &b_HadronicVHtD2Pt_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtEnergy_JetSubCalc", &HadronicVHtEnergy_JetSubCalc, &b_HadronicVHtEnergy_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtEta_JetSubCalc", &HadronicVHtEta_JetSubCalc, &b_HadronicVHtEta_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtPhi_JetSubCalc", &HadronicVHtPhi_JetSubCalc, &b_HadronicVHtPhi_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtPt_JetSubCalc", &HadronicVHtPt_JetSubCalc, &b_HadronicVHtPt_JetSubCalc);
   inputTree->SetBranchAddress("HdecayEnergy_TpTpCalc", &HdecayEnergy_TpTpCalc, &b_HdecayEnergy_TpTpCalc);
   inputTree->SetBranchAddress("HdecayEta_TpTpCalc", &HdecayEta_TpTpCalc, &b_HdecayEta_TpTpCalc);
   inputTree->SetBranchAddress("HdecayPhi_TpTpCalc", &HdecayPhi_TpTpCalc, &b_HdecayPhi_TpTpCalc);
   inputTree->SetBranchAddress("HdecayPt_TpTpCalc", &HdecayPt_TpTpCalc, &b_HdecayPt_TpTpCalc);
   inputTree->SetBranchAddress("LHEweights_singleLepCalc", &LHEweights_singleLepCalc, &b_LHEweights_singleLepCalc);
   inputTree->SetBranchAddress("LeptonEnergy_TpTpCalc", &LeptonEnergy_TpTpCalc, &b_LeptonEnergy_TpTpCalc);
   inputTree->SetBranchAddress("LeptonEta_TpTpCalc", &LeptonEta_TpTpCalc, &b_LeptonEta_TpTpCalc);
   inputTree->SetBranchAddress("LeptonPhi_TpTpCalc", &LeptonPhi_TpTpCalc, &b_LeptonPhi_TpTpCalc);
   inputTree->SetBranchAddress("LeptonPt_TpTpCalc", &LeptonPt_TpTpCalc, &b_LeptonPt_TpTpCalc);
   inputTree->SetBranchAddress("NewPDFweightsBase_singleLepCalc", &NewPDFweightsBase_singleLepCalc, &b_NewPDFweightsBase_singleLepCalc);
   inputTree->SetBranchAddress("NewPDFweights_singleLepCalc", &NewPDFweights_singleLepCalc, &b_NewPDFweights_singleLepCalc);
   inputTree->SetBranchAddress("WdecayEnergy_TpTpCalc", &WdecayEnergy_TpTpCalc, &b_WdecayEnergy_TpTpCalc);
   inputTree->SetBranchAddress("WdecayEta_TpTpCalc", &WdecayEta_TpTpCalc, &b_WdecayEta_TpTpCalc);
   inputTree->SetBranchAddress("WdecayPhi_TpTpCalc", &WdecayPhi_TpTpCalc, &b_WdecayPhi_TpTpCalc);
   inputTree->SetBranchAddress("WdecayPt_TpTpCalc", &WdecayPt_TpTpCalc, &b_WdecayPt_TpTpCalc);
   inputTree->SetBranchAddress("ZdecayEnergy_TpTpCalc", &ZdecayEnergy_TpTpCalc, &b_ZdecayEnergy_TpTpCalc);
   inputTree->SetBranchAddress("ZdecayEta_TpTpCalc", &ZdecayEta_TpTpCalc, &b_ZdecayEta_TpTpCalc);
   inputTree->SetBranchAddress("ZdecayPhi_TpTpCalc", &ZdecayPhi_TpTpCalc, &b_ZdecayPhi_TpTpCalc);
   inputTree->SetBranchAddress("ZdecayPt_TpTpCalc", &ZdecayPt_TpTpCalc, &b_ZdecayPt_TpTpCalc);
   inputTree->SetBranchAddress("allTopsEnergy_TTbarMassCalc", &allTopsEnergy_TTbarMassCalc, &b_allTopsEnergy_TTbarMassCalc);
   inputTree->SetBranchAddress("allTopsEta_TTbarMassCalc", &allTopsEta_TTbarMassCalc, &b_allTopsEta_TTbarMassCalc);
   inputTree->SetBranchAddress("allTopsPhi_TTbarMassCalc", &allTopsPhi_TTbarMassCalc, &b_allTopsPhi_TTbarMassCalc);
   inputTree->SetBranchAddress("allTopsPt_TTbarMassCalc", &allTopsPt_TTbarMassCalc, &b_allTopsPt_TTbarMassCalc);
   inputTree->SetBranchAddress("bPrimeEnergy_TpTpCalc", &bPrimeEnergy_TpTpCalc, &b_bPrimeEnergy_TpTpCalc);
   inputTree->SetBranchAddress("bPrimeEta_TpTpCalc", &bPrimeEta_TpTpCalc, &b_bPrimeEta_TpTpCalc);
   inputTree->SetBranchAddress("bPrimeMass_TpTpCalc", &bPrimeMass_TpTpCalc, &b_bPrimeMass_TpTpCalc);
   inputTree->SetBranchAddress("bPrimePhi_TpTpCalc", &bPrimePhi_TpTpCalc, &b_bPrimePhi_TpTpCalc);
   inputTree->SetBranchAddress("bPrimePt_TpTpCalc", &bPrimePt_TpTpCalc, &b_bPrimePt_TpTpCalc);
   inputTree->SetBranchAddress("bosonEnergy_TpTpCalc", &bosonEnergy_TpTpCalc, &b_bosonEnergy_TpTpCalc);
   inputTree->SetBranchAddress("bosonEta_TpTpCalc", &bosonEta_TpTpCalc, &b_bosonEta_TpTpCalc);
   inputTree->SetBranchAddress("bosonPhi_TpTpCalc", &bosonPhi_TpTpCalc, &b_bosonPhi_TpTpCalc);
   inputTree->SetBranchAddress("bosonPt_TpTpCalc", &bosonPt_TpTpCalc, &b_bosonPt_TpTpCalc);
   inputTree->SetBranchAddress("decorr_B_DeepAK8Calc", &decorr_B_DeepAK8Calc, &b_decorr_B_DeepAK8Calc);
   inputTree->SetBranchAddress("decorr_C_DeepAK8Calc", &decorr_C_DeepAK8Calc, &b_decorr_C_DeepAK8Calc);
   inputTree->SetBranchAddress("decorr_H_DeepAK8Calc", &decorr_H_DeepAK8Calc, &b_decorr_H_DeepAK8Calc);
   inputTree->SetBranchAddress("decorr_J_DeepAK8Calc", &decorr_J_DeepAK8Calc, &b_decorr_J_DeepAK8Calc);
   inputTree->SetBranchAddress("decorr_T_DeepAK8Calc", &decorr_T_DeepAK8Calc, &b_decorr_T_DeepAK8Calc);
   inputTree->SetBranchAddress("decorr_W_DeepAK8Calc", &decorr_W_DeepAK8Calc, &b_decorr_W_DeepAK8Calc);
   inputTree->SetBranchAddress("decorr_Z_DeepAK8Calc", &decorr_Z_DeepAK8Calc, &b_decorr_Z_DeepAK8Calc);
   inputTree->SetBranchAddress("dnn_B_BestCalc", &dnn_B_BestCalc, &b_dnn_B_BestCalc);
   inputTree->SetBranchAddress("dnn_B_DeepAK8Calc", &dnn_B_DeepAK8Calc, &b_dnn_B_DeepAK8Calc);
   inputTree->SetBranchAddress("dnn_C_DeepAK8Calc", &dnn_C_DeepAK8Calc, &b_dnn_C_DeepAK8Calc);
   inputTree->SetBranchAddress("dnn_H_DeepAK8Calc", &dnn_H_DeepAK8Calc, &b_dnn_H_DeepAK8Calc);
   inputTree->SetBranchAddress("dnn_Higgs_BestCalc", &dnn_Higgs_BestCalc, &b_dnn_Higgs_BestCalc);
   inputTree->SetBranchAddress("dnn_J_DeepAK8Calc", &dnn_J_DeepAK8Calc, &b_dnn_J_DeepAK8Calc);
   inputTree->SetBranchAddress("dnn_QCD_BestCalc", &dnn_QCD_BestCalc, &b_dnn_QCD_BestCalc);
   inputTree->SetBranchAddress("dnn_T_DeepAK8Calc", &dnn_T_DeepAK8Calc, &b_dnn_T_DeepAK8Calc);
   inputTree->SetBranchAddress("dnn_Top_BestCalc", &dnn_Top_BestCalc, &b_dnn_Top_BestCalc);
   inputTree->SetBranchAddress("dnn_W_BestCalc", &dnn_W_BestCalc, &b_dnn_W_BestCalc);
   inputTree->SetBranchAddress("dnn_W_DeepAK8Calc", &dnn_W_DeepAK8Calc, &b_dnn_W_DeepAK8Calc);
   inputTree->SetBranchAddress("dnn_Z_BestCalc", &dnn_Z_BestCalc, &b_dnn_Z_BestCalc);
   inputTree->SetBranchAddress("dnn_Z_DeepAK8Calc", &dnn_Z_DeepAK8Calc, &b_dnn_Z_DeepAK8Calc);
   inputTree->SetBranchAddress("elAEff_singleLepCalc", &elAEff_singleLepCalc, &b_elAEff_singleLepCalc);
   inputTree->SetBranchAddress("elChIso_singleLepCalc", &elChIso_singleLepCalc, &b_elChIso_singleLepCalc);
   inputTree->SetBranchAddress("elD0_singleLepCalc", &elD0_singleLepCalc, &b_elD0_singleLepCalc);
   inputTree->SetBranchAddress("elDEtaSCTkAtVtx_singleLepCalc", &elDEtaSCTkAtVtx_singleLepCalc, &b_elDEtaSCTkAtVtx_singleLepCalc);
   inputTree->SetBranchAddress("elDPhiSCTkAtVtx_singleLepCalc", &elDPhiSCTkAtVtx_singleLepCalc, &b_elDPhiSCTkAtVtx_singleLepCalc);
   inputTree->SetBranchAddress("elDR03TkSumPt_singleLepCalc", &elDR03TkSumPt_singleLepCalc, &b_elDR03TkSumPt_singleLepCalc);
   inputTree->SetBranchAddress("elDZ_singleLepCalc", &elDZ_singleLepCalc, &b_elDZ_singleLepCalc);
   inputTree->SetBranchAddress("elDeta_singleLepCalc", &elDeta_singleLepCalc, &b_elDeta_singleLepCalc);
   inputTree->SetBranchAddress("elDphi_singleLepCalc", &elDphi_singleLepCalc, &b_elDphi_singleLepCalc);
   inputTree->SetBranchAddress("elDxy_singleLepCalc", &elDxy_singleLepCalc, &b_elDxy_singleLepCalc);
   inputTree->SetBranchAddress("elEcalPFClusterIso_singleLepCalc", &elEcalPFClusterIso_singleLepCalc, &b_elEcalPFClusterIso_singleLepCalc);
   inputTree->SetBranchAddress("elEnergy_singleLepCalc", &elEnergy_singleLepCalc, &b_elEnergy_singleLepCalc);
   inputTree->SetBranchAddress("elEtaVtx_singleLepCalc", &elEtaVtx_singleLepCalc, &b_elEtaVtx_singleLepCalc);
   inputTree->SetBranchAddress("elEta_singleLepCalc", &elEta_singleLepCalc, &b_elEta_singleLepCalc);
   inputTree->SetBranchAddress("elGen_Reco_dr_singleLepCalc", &elGen_Reco_dr_singleLepCalc, &b_elGen_Reco_dr_singleLepCalc);
   inputTree->SetBranchAddress("elHcalPFClusterIso_singleLepCalc", &elHcalPFClusterIso_singleLepCalc, &b_elHcalPFClusterIso_singleLepCalc);
   inputTree->SetBranchAddress("elHoE_singleLepCalc", &elHoE_singleLepCalc, &b_elHoE_singleLepCalc);
   inputTree->SetBranchAddress("elIsLoose_singleLepCalc", &elIsLoose_singleLepCalc, &b_elIsLoose_singleLepCalc);
   inputTree->SetBranchAddress("elIsMedium_singleLepCalc", &elIsMedium_singleLepCalc, &b_elIsMedium_singleLepCalc);
   inputTree->SetBranchAddress("elIsTight_singleLepCalc", &elIsTight_singleLepCalc, &b_elIsTight_singleLepCalc);
   inputTree->SetBranchAddress("elIsVeto_singleLepCalc", &elIsVeto_singleLepCalc, &b_elIsVeto_singleLepCalc);
   /* inputTree->SetBranchAddress("elMVAValue_iso_singleLepCalc", &elMVAValue_iso_singleLepCalc, &b_elMVAValue_iso_singleLepCalc); */
   /* inputTree->SetBranchAddress("elMVAValue_singleLepCalc", &elMVAValue_singleLepCalc, &b_elMVAValue_singleLepCalc); */
   inputTree->SetBranchAddress("elMatchedEnergy_singleLepCalc", &elMatchedEnergy_singleLepCalc, &b_elMatchedEnergy_singleLepCalc);
   inputTree->SetBranchAddress("elMatchedEta_singleLepCalc", &elMatchedEta_singleLepCalc, &b_elMatchedEta_singleLepCalc);
   inputTree->SetBranchAddress("elMatchedPhi_singleLepCalc", &elMatchedPhi_singleLepCalc, &b_elMatchedPhi_singleLepCalc);
   inputTree->SetBranchAddress("elMatchedPt_singleLepCalc", &elMatchedPt_singleLepCalc, &b_elMatchedPt_singleLepCalc);
   inputTree->SetBranchAddress("elMiniIso_singleLepCalc", &elMiniIso_singleLepCalc, &b_elMiniIso_singleLepCalc);
   inputTree->SetBranchAddress("elMother_energy_singleLepCalc", &elMother_energy_singleLepCalc, &b_elMother_energy_singleLepCalc);
   inputTree->SetBranchAddress("elMother_eta_singleLepCalc", &elMother_eta_singleLepCalc, &b_elMother_eta_singleLepCalc);
   inputTree->SetBranchAddress("elMother_phi_singleLepCalc", &elMother_phi_singleLepCalc, &b_elMother_phi_singleLepCalc);
   inputTree->SetBranchAddress("elMother_pt_singleLepCalc", &elMother_pt_singleLepCalc, &b_elMother_pt_singleLepCalc);
   inputTree->SetBranchAddress("elNhIso_singleLepCalc", &elNhIso_singleLepCalc, &b_elNhIso_singleLepCalc);
   inputTree->SetBranchAddress("elOoemoop_singleLepCalc", &elOoemoop_singleLepCalc, &b_elOoemoop_singleLepCalc);
   inputTree->SetBranchAddress("elPFEta_singleLepCalc", &elPFEta_singleLepCalc, &b_elPFEta_singleLepCalc);
   inputTree->SetBranchAddress("elPFPhi_singleLepCalc", &elPFPhi_singleLepCalc, &b_elPFPhi_singleLepCalc);
   inputTree->SetBranchAddress("elPhIso_singleLepCalc", &elPhIso_singleLepCalc, &b_elPhIso_singleLepCalc);
   inputTree->SetBranchAddress("elPhiVtx_singleLepCalc", &elPhiVtx_singleLepCalc, &b_elPhiVtx_singleLepCalc);
   inputTree->SetBranchAddress("elPhi_singleLepCalc", &elPhi_singleLepCalc, &b_elPhi_singleLepCalc);
   inputTree->SetBranchAddress("elPt_singleLepCalc", &elPt_singleLepCalc, &b_elPt_singleLepCalc);
   inputTree->SetBranchAddress("elRelIso_singleLepCalc", &elRelIso_singleLepCalc, &b_elRelIso_singleLepCalc);
   inputTree->SetBranchAddress("elRhoIso_singleLepCalc", &elRhoIso_singleLepCalc, &b_elRhoIso_singleLepCalc);
   inputTree->SetBranchAddress("elSCE_singleLepCalc", &elSCE_singleLepCalc, &b_elSCE_singleLepCalc);
   inputTree->SetBranchAddress("elSihih_singleLepCalc", &elSihih_singleLepCalc, &b_elSihih_singleLepCalc);
   inputTree->SetBranchAddress("evtWeightsMC_singleLepCalc", &evtWeightsMC_singleLepCalc, &b_evtWeightsMC_singleLepCalc);
   inputTree->SetBranchAddress("genBSLEnergy_singleLepCalc", &genBSLEnergy_singleLepCalc, &b_genBSLEnergy_singleLepCalc);
   inputTree->SetBranchAddress("genBSLEta_singleLepCalc", &genBSLEta_singleLepCalc, &b_genBSLEta_singleLepCalc);
   inputTree->SetBranchAddress("genBSLPhi_singleLepCalc", &genBSLPhi_singleLepCalc, &b_genBSLPhi_singleLepCalc);
   inputTree->SetBranchAddress("genBSLPt_singleLepCalc", &genBSLPt_singleLepCalc, &b_genBSLPt_singleLepCalc);
   inputTree->SetBranchAddress("genEnergy_singleLepCalc", &genEnergy_singleLepCalc, &b_genEnergy_singleLepCalc);
   inputTree->SetBranchAddress("genEta_singleLepCalc", &genEta_singleLepCalc, &b_genEta_singleLepCalc);
   inputTree->SetBranchAddress("genJetEnergy_singleLepCalc", &genJetEnergy_singleLepCalc, &b_genJetEnergy_singleLepCalc);
   inputTree->SetBranchAddress("genJetEta_singleLepCalc", &genJetEta_singleLepCalc, &b_genJetEta_singleLepCalc);
   inputTree->SetBranchAddress("genJetPhi_singleLepCalc", &genJetPhi_singleLepCalc, &b_genJetPhi_singleLepCalc);
   inputTree->SetBranchAddress("genJetPt_singleLepCalc", &genJetPt_singleLepCalc, &b_genJetPt_singleLepCalc);
   inputTree->SetBranchAddress("genPhi_singleLepCalc", &genPhi_singleLepCalc, &b_genPhi_singleLepCalc);
   inputTree->SetBranchAddress("genPt_singleLepCalc", &genPt_singleLepCalc, &b_genPt_singleLepCalc);
   inputTree->SetBranchAddress("muChIso_singleLepCalc", &muChIso_singleLepCalc, &b_muChIso_singleLepCalc);
   inputTree->SetBranchAddress("muChi2_singleLepCalc", &muChi2_singleLepCalc, &b_muChi2_singleLepCalc);
   inputTree->SetBranchAddress("muDxy_singleLepCalc", &muDxy_singleLepCalc, &b_muDxy_singleLepCalc);
   inputTree->SetBranchAddress("muDz_singleLepCalc", &muDz_singleLepCalc, &b_muDz_singleLepCalc);
   inputTree->SetBranchAddress("muEnergy_singleLepCalc", &muEnergy_singleLepCalc, &b_muEnergy_singleLepCalc);
   inputTree->SetBranchAddress("muEta_singleLepCalc", &muEta_singleLepCalc, &b_muEta_singleLepCalc);
   inputTree->SetBranchAddress("muGIso_singleLepCalc", &muGIso_singleLepCalc, &b_muGIso_singleLepCalc);
   inputTree->SetBranchAddress("muGen_Reco_dr_singleLepCalc", &muGen_Reco_dr_singleLepCalc, &b_muGen_Reco_dr_singleLepCalc);
   inputTree->SetBranchAddress("muInnerEta_singleLepCalc", &muInnerEta_singleLepCalc, &b_muInnerEta_singleLepCalc);
   inputTree->SetBranchAddress("muInnerPhi_singleLepCalc", &muInnerPhi_singleLepCalc, &b_muInnerPhi_singleLepCalc);
   inputTree->SetBranchAddress("muInnerPt_singleLepCalc", &muInnerPt_singleLepCalc, &b_muInnerPt_singleLepCalc);
   inputTree->SetBranchAddress("muMatchedEnergy_singleLepCalc", &muMatchedEnergy_singleLepCalc, &b_muMatchedEnergy_singleLepCalc);
   inputTree->SetBranchAddress("muMatchedEta_singleLepCalc", &muMatchedEta_singleLepCalc, &b_muMatchedEta_singleLepCalc);
   inputTree->SetBranchAddress("muMatchedPhi_singleLepCalc", &muMatchedPhi_singleLepCalc, &b_muMatchedPhi_singleLepCalc);
   inputTree->SetBranchAddress("muMatchedPt_singleLepCalc", &muMatchedPt_singleLepCalc, &b_muMatchedPt_singleLepCalc);
   inputTree->SetBranchAddress("muMiniIsoDB_singleLepCalc", &muMiniIsoDB_singleLepCalc, &b_muMiniIsoDB_singleLepCalc);
   inputTree->SetBranchAddress("muMiniIso_singleLepCalc", &muMiniIso_singleLepCalc, &b_muMiniIso_singleLepCalc);
   inputTree->SetBranchAddress("muMother_energy_singleLepCalc", &muMother_energy_singleLepCalc, &b_muMother_energy_singleLepCalc);
   inputTree->SetBranchAddress("muMother_eta_singleLepCalc", &muMother_eta_singleLepCalc, &b_muMother_eta_singleLepCalc);
   inputTree->SetBranchAddress("muMother_phi_singleLepCalc", &muMother_phi_singleLepCalc, &b_muMother_phi_singleLepCalc);
   inputTree->SetBranchAddress("muMother_pt_singleLepCalc", &muMother_pt_singleLepCalc, &b_muMother_pt_singleLepCalc);
   inputTree->SetBranchAddress("muNhIso_singleLepCalc", &muNhIso_singleLepCalc, &b_muNhIso_singleLepCalc);
   inputTree->SetBranchAddress("muPhi_singleLepCalc", &muPhi_singleLepCalc, &b_muPhi_singleLepCalc);
   inputTree->SetBranchAddress("muPt_singleLepCalc", &muPt_singleLepCalc, &b_muPt_singleLepCalc);
   inputTree->SetBranchAddress("muPuIso_singleLepCalc", &muPuIso_singleLepCalc, &b_muPuIso_singleLepCalc);
   inputTree->SetBranchAddress("muRelIso_singleLepCalc", &muRelIso_singleLepCalc, &b_muRelIso_singleLepCalc);
   inputTree->SetBranchAddress("quarkEnergy_TpTpCalc", &quarkEnergy_TpTpCalc, &b_quarkEnergy_TpTpCalc);
   inputTree->SetBranchAddress("quarkEta_TpTpCalc", &quarkEta_TpTpCalc, &b_quarkEta_TpTpCalc);
   inputTree->SetBranchAddress("quarkPhi_TpTpCalc", &quarkPhi_TpTpCalc, &b_quarkPhi_TpTpCalc);
   inputTree->SetBranchAddress("quarkPt_TpTpCalc", &quarkPt_TpTpCalc, &b_quarkPt_TpTpCalc);
   inputTree->SetBranchAddress("tPrimeEnergy_TpTpCalc", &tPrimeEnergy_TpTpCalc, &b_tPrimeEnergy_TpTpCalc);
   inputTree->SetBranchAddress("tPrimeEta_TpTpCalc", &tPrimeEta_TpTpCalc, &b_tPrimeEta_TpTpCalc);
   inputTree->SetBranchAddress("tPrimeMass_TpTpCalc", &tPrimeMass_TpTpCalc, &b_tPrimeMass_TpTpCalc);
   inputTree->SetBranchAddress("tPrimePhi_TpTpCalc", &tPrimePhi_TpTpCalc, &b_tPrimePhi_TpTpCalc);
   inputTree->SetBranchAddress("tPrimePt_TpTpCalc", &tPrimePt_TpTpCalc, &b_tPrimePt_TpTpCalc);
   inputTree->SetBranchAddress("theJetAK8CHSEta_JetSubCalc", &theJetAK8CHSEta_JetSubCalc, &b_theJetAK8CHSEta_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8CHSMass_JetSubCalc", &theJetAK8CHSMass_JetSubCalc, &b_theJetAK8CHSMass_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8CHSPhi_JetSubCalc", &theJetAK8CHSPhi_JetSubCalc, &b_theJetAK8CHSPhi_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8CHSPrunedMass_JetSubCalc", &theJetAK8CHSPrunedMass_JetSubCalc, &b_theJetAK8CHSPrunedMass_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8CHSPt_JetSubCalc", &theJetAK8CHSPt_JetSubCalc, &b_theJetAK8CHSPt_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8CHSSoftDropMass_JetSubCalc", &theJetAK8CHSSoftDropMass_JetSubCalc, &b_theJetAK8CHSSoftDropMass_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8CHSTau1_JetSubCalc", &theJetAK8CHSTau1_JetSubCalc, &b_theJetAK8CHSTau1_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8CHSTau2_JetSubCalc", &theJetAK8CHSTau2_JetSubCalc, &b_theJetAK8CHSTau2_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8CHSTau3_JetSubCalc", &theJetAK8CHSTau3_JetSubCalc, &b_theJetAK8CHSTau3_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8CSV_JetSubCalc", &theJetAK8CSV_JetSubCalc, &b_theJetAK8CSV_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8DoubleB_JetSubCalc", &theJetAK8DoubleB_JetSubCalc, &b_theJetAK8DoubleB_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8Energy_JetSubCalc", &theJetAK8Energy_JetSubCalc, &b_theJetAK8Energy_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8Eta_JetSubCalc", &theJetAK8Eta_JetSubCalc, &b_theJetAK8Eta_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8GenDR_JetSubCalc", &theJetAK8GenDR_JetSubCalc, &b_theJetAK8GenDR_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8GenMass_JetSubCalc", &theJetAK8GenMass_JetSubCalc, &b_theJetAK8GenMass_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8GenPt_JetSubCalc", &theJetAK8GenPt_JetSubCalc, &b_theJetAK8GenPt_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8JetCharge_JetSubCalc", &theJetAK8JetCharge_JetSubCalc, &b_theJetAK8JetCharge_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8Mass_JetSubCalc", &theJetAK8Mass_JetSubCalc, &b_theJetAK8Mass_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8NjettinessTau1_JetSubCalc", &theJetAK8NjettinessTau1_JetSubCalc, &b_theJetAK8NjettinessTau1_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8NjettinessTau2_JetSubCalc", &theJetAK8NjettinessTau2_JetSubCalc, &b_theJetAK8NjettinessTau2_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8NjettinessTau3_JetSubCalc", &theJetAK8NjettinessTau3_JetSubCalc, &b_theJetAK8NjettinessTau3_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8Phi_JetSubCalc", &theJetAK8Phi_JetSubCalc, &b_theJetAK8Phi_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8Pt_JetSubCalc", &theJetAK8Pt_JetSubCalc, &b_theJetAK8Pt_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetCSVb_JetSubCalc", &theJetAK8SDSubjetCSVb_JetSubCalc, &b_theJetAK8SDSubjetCSVb_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetCSVbb_JetSubCalc", &theJetAK8SDSubjetCSVbb_JetSubCalc, &b_theJetAK8SDSubjetCSVbb_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetCSVc_JetSubCalc", &theJetAK8SDSubjetCSVc_JetSubCalc, &b_theJetAK8SDSubjetCSVc_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetCSVudsg_JetSubCalc", &theJetAK8SDSubjetCSVudsg_JetSubCalc, &b_theJetAK8SDSubjetCSVudsg_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetDR_JetSubCalc", &theJetAK8SDSubjetDR_JetSubCalc, &b_theJetAK8SDSubjetDR_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetEta_JetSubCalc", &theJetAK8SDSubjetEta_JetSubCalc, &b_theJetAK8SDSubjetEta_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetMass_JetSubCalc", &theJetAK8SDSubjetMass_JetSubCalc, &b_theJetAK8SDSubjetMass_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetPhi_JetSubCalc", &theJetAK8SDSubjetPhi_JetSubCalc, &b_theJetAK8SDSubjetPhi_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetPt_JetSubCalc", &theJetAK8SDSubjetPt_JetSubCalc, &b_theJetAK8SDSubjetPt_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SoftDropCorr_JetSubCalc", &theJetAK8SoftDropCorr_JetSubCalc, &b_theJetAK8SoftDropCorr_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SoftDropRaw_JetSubCalc", &theJetAK8SoftDropRaw_JetSubCalc, &b_theJetAK8SoftDropRaw_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SoftDrop_JMRdn_JetSubCalc", &theJetAK8SoftDrop_JMRdn_JetSubCalc, &b_theJetAK8SoftDrop_JMRdn_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SoftDrop_JMRup_JetSubCalc", &theJetAK8SoftDrop_JMRup_JetSubCalc, &b_theJetAK8SoftDrop_JMRup_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SoftDrop_JMSdn_JetSubCalc", &theJetAK8SoftDrop_JMSdn_JetSubCalc, &b_theJetAK8SoftDrop_JMSdn_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SoftDrop_JMSup_JetSubCalc", &theJetAK8SoftDrop_JMSup_JetSubCalc, &b_theJetAK8SoftDrop_JMSup_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SoftDrop_JetSubCalc", &theJetAK8SoftDrop_JetSubCalc, &b_theJetAK8SoftDrop_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SoftDropn2b1_JetSubCalc", &theJetAK8SoftDropn2b1_JetSubCalc, &b_theJetAK8SoftDropn2b1_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SoftDropn2b2_JetSubCalc", &theJetAK8SoftDropn2b2_JetSubCalc, &b_theJetAK8SoftDropn2b2_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SoftDropn3b1_JetSubCalc", &theJetAK8SoftDropn3b1_JetSubCalc, &b_theJetAK8SoftDropn3b1_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SoftDropn3b2_JetSubCalc", &theJetAK8SoftDropn3b2_JetSubCalc, &b_theJetAK8SoftDropn3b2_JetSubCalc);
   inputTree->SetBranchAddress("theJetDeepCSVb_JetSubCalc", &theJetDeepCSVb_JetSubCalc, &b_theJetDeepCSVb_JetSubCalc);
   inputTree->SetBranchAddress("theJetDeepCSVbb_JetSubCalc", &theJetDeepCSVbb_JetSubCalc, &b_theJetDeepCSVbb_JetSubCalc);
   inputTree->SetBranchAddress("theJetDeepCSVc_JetSubCalc", &theJetDeepCSVc_JetSubCalc, &b_theJetDeepCSVc_JetSubCalc);
   inputTree->SetBranchAddress("theJetDeepCSVudsg_JetSubCalc", &theJetDeepCSVudsg_JetSubCalc, &b_theJetDeepCSVudsg_JetSubCalc);
   inputTree->SetBranchAddress("theJetEnergy_JetSubCalc", &theJetEnergy_JetSubCalc, &b_theJetEnergy_JetSubCalc);
   inputTree->SetBranchAddress("theJetEta_JetSubCalc", &theJetEta_JetSubCalc, &b_theJetEta_JetSubCalc);
   inputTree->SetBranchAddress("theJetPhi_JetSubCalc", &theJetPhi_JetSubCalc, &b_theJetPhi_JetSubCalc);
   inputTree->SetBranchAddress("theJetPileupJetId_JetSubCalc", &theJetPileupJetId_JetSubCalc, &b_theJetPileupJetId_JetSubCalc);
   inputTree->SetBranchAddress("theJetPt_JetSubCalc", &theJetPt_JetSubCalc, &b_theJetPt_JetSubCalc);
   inputTree->SetBranchAddress("topEnergy_TTbarMassCalc", &topEnergy_TTbarMassCalc, &b_topEnergy_TTbarMassCalc);
   inputTree->SetBranchAddress("topEta_TTbarMassCalc", &topEta_TTbarMassCalc, &b_topEta_TTbarMassCalc);
   inputTree->SetBranchAddress("topMass_TTbarMassCalc", &topMass_TTbarMassCalc, &b_topMass_TTbarMassCalc);
   inputTree->SetBranchAddress("topPhi_TTbarMassCalc", &topPhi_TTbarMassCalc, &b_topPhi_TTbarMassCalc);
   inputTree->SetBranchAddress("topPt_TTbarMassCalc", &topPt_TTbarMassCalc, &b_topPt_TTbarMassCalc);
   inputTree->SetBranchAddress("topWEnergy_TTbarMassCalc", &topWEnergy_TTbarMassCalc, &b_topWEnergy_TTbarMassCalc);
   inputTree->SetBranchAddress("topWEta_TTbarMassCalc", &topWEta_TTbarMassCalc, &b_topWEta_TTbarMassCalc);
   inputTree->SetBranchAddress("topWPhi_TTbarMassCalc", &topWPhi_TTbarMassCalc, &b_topWPhi_TTbarMassCalc);
   inputTree->SetBranchAddress("topWPt_TTbarMassCalc", &topWPt_TTbarMassCalc, &b_topWPt_TTbarMassCalc);
   inputTree->SetBranchAddress("topbEnergy_TTbarMassCalc", &topbEnergy_TTbarMassCalc, &b_topbEnergy_TTbarMassCalc);
   inputTree->SetBranchAddress("topbEta_TTbarMassCalc", &topbEta_TTbarMassCalc, &b_topbEta_TTbarMassCalc);
   inputTree->SetBranchAddress("topbPhi_TTbarMassCalc", &topbPhi_TTbarMassCalc, &b_topbPhi_TTbarMassCalc);
   inputTree->SetBranchAddress("topbPt_TTbarMassCalc", &topbPt_TTbarMassCalc, &b_topbPt_TTbarMassCalc);
   inputTree->SetBranchAddress("electron_hltfilters_singleLepCalc", &electron_hltfilters_singleLepCalc, &b_electron_hltfilters_singleLepCalc);
   inputTree->SetBranchAddress("muon_hltfilters_singleLepCalc", &muon_hltfilters_singleLepCalc, &b_muon_hltfilters_singleLepCalc);
   inputTree->SetBranchAddress("vsSelMCTriggersEl_singleLepCalc", &vsSelMCTriggersEl_singleLepCalc, &b_vsSelMCTriggersEl_singleLepCalc);
   inputTree->SetBranchAddress("vsSelMCTriggersMu_singleLepCalc", &vsSelMCTriggersMu_singleLepCalc, &b_vsSelMCTriggersMu_singleLepCalc);
   inputTree->SetBranchAddress("vsSelTriggersEl_singleLepCalc", &vsSelTriggersEl_singleLepCalc, &b_vsSelTriggersEl_singleLepCalc);
   inputTree->SetBranchAddress("vsSelTriggersMu_singleLepCalc", &vsSelTriggersMu_singleLepCalc, &b_vsSelTriggersMu_singleLepCalc);
   Notify();
}

Bool_t step1::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void step1::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!inputTree) return;
   inputTree->Show(entry);
}
Int_t step1::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

void step1::InitPileup()
{
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
}

#endif // #ifdef step1_cxx
