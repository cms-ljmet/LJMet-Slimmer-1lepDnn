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
   Float_t         triggerSF;
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

   Float_t         leptonPt_MultiLepCalc;
   Float_t         leptonEta_MultiLepCalc;
   Float_t         leptonPhi_MultiLepCalc;
   Float_t         leptonEnergy_MultiLepCalc;
   Float_t         leptonMVAValue_MultiLepCalc;
   Float_t         leptonMiniIso_MultiLepCalc;
   Float_t         leptonRelIso_MultiLepCalc;
   Float_t         leptonDxy_MultiLepCalc;
   Float_t         leptonDz_MultiLepCalc;
   Int_t           leptonCharge_MultiLepCalc;
   Int_t           elTrigPresel_MultiLepCalc;

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
   Bool_t          flagBadMu_MultiLepCalc;
   Bool_t          flagDupMu_MultiLepCalc;
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
   Int_t           NLeptonDecays_TpTpCalc;
   Int_t           NPartonsfromHEPUEP_MultiLepCalc;
   Int_t           genTDLID_MultiLepCalc;
   Int_t           lumi_CommonCalc;
   Int_t           nAllJets_CommonCalc;
   Int_t           nLooseMuons_CommonCalc;
   //   Int_t           nPV_MultiLepCalc;
   Int_t           nPileupInteractions_MultiLepCalc;
   Int_t           nSelBtagJets_CommonCalc;
   Int_t           nSelElectrons_CommonCalc;
   Int_t           nSelJets_CommonCalc;
   Int_t           nTightMuons_CommonCalc;
   Int_t           nTrueInteractions_MultiLepCalc;
   Int_t           run_CommonCalc;
   Long64_t        event_CommonCalc;
   Double_t        AK4HT_MultiLepCalc;
   Double_t        HTfromHEPUEP_MultiLepCalc;
   Double_t        L1NonPrefiringProbDown_CommonCalc;
   Double_t        L1NonPrefiringProbUp_CommonCalc;
   Double_t        L1NonPrefiringProb_CommonCalc;
   Double_t        LHEweightorig_MultiLepCalc;
   Double_t        MCWeight_MultiLepCalc;
   Double_t        corr_met_phi_MultiLepCalc;
   Double_t        corr_met_MultiLepCalc;
   Double_t        corr_metmod_phi_MultiLepCalc;
   Double_t        corr_metmod_MultiLepCalc;
   Double_t        corr_metnohf_phi_MultiLepCalc;
   Double_t        corr_metnohf_MultiLepCalc;
   Double_t        genTDLEnergy_MultiLepCalc;
   Double_t        genTDLEta_MultiLepCalc;
   Double_t        genTDLPhi_MultiLepCalc;
   Double_t        genTDLPt_MultiLepCalc;
   Double_t        met_phi_MultiLepCalc;
   Double_t        met_MultiLepCalc;
   Double_t        metmod_phi_MultiLepCalc;
   Double_t        metmod_MultiLepCalc;
   Double_t        metnohf_phi_MultiLepCalc;
   Double_t        metnohf_MultiLepCalc;
   Double_t        theJetHT_JetSubCalc;
   Double_t        theJetLeadPt_JetSubCalc;
   Double_t        theJetSubLeadPt_JetSubCalc;
   Double_t        ttbarMass_TTbarMassCalc;
   vector<int>     *AK4JetBTag_bSFdn_MultiLepCalc;
   vector<int>     *AK4JetBTag_bSFup_MultiLepCalc;
   vector<int>     *AK4JetBTag_lSFdn_MultiLepCalc;
   vector<int>     *AK4JetBTag_lSFup_MultiLepCalc;
   vector<int>     *AK4JetBTag_MultiLepCalc;
   vector<int>     *AK4JetFlav_MultiLepCalc;
   vector<int>     *HadronicVHtID_JetSubCalc;
   vector<int>     *HadronicVHtStatus_JetSubCalc;
   vector<int>     *HdecayID_TpTpCalc;
   vector<int>     *HdecayIndex_TpTpCalc;
   vector<int>     *LHEweightids_MultiLepCalc;
   vector<int>     *LeptonID_TpTpCalc;
   vector<int>     *LeptonParentID_TpTpCalc;
   vector<int>     *NewPDFids_MultiLepCalc;
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
   vector<int>     *elChargeConsistent_MultiLepCalc;
   vector<int>     *elCharge_MultiLepCalc;
   vector<int>     *elCtfCharge_MultiLepCalc;
   vector<int>     *elGsfCharge_MultiLepCalc;
   vector<int>     *elIsEBEE_MultiLepCalc;
   /* vector<int>     *elIsMVALooseIso_MultiLepCalc; */
   /* vector<int>     *elIsMVALoose_MultiLepCalc; */
   /* vector<int>     *elIsMVATight80_MultiLepCalc; */
   /* vector<int>     *elIsMVATight90_MultiLepCalc; */
   /* vector<int>     *elIsMVATightIso80_MultiLepCalc; */
   /* vector<int>     *elIsMVATightIso90_MultiLepCalc; */
   vector<int>     *elMHits_MultiLepCalc;
   vector<int>     *elMatched_MultiLepCalc;
   vector<int>     *elMother_id_MultiLepCalc;
   vector<int>     *elMother_status_MultiLepCalc;
   vector<int>     *elNotConversion_MultiLepCalc;
   vector<int>     *elNumberOfMothers_MultiLepCalc;
   vector<int>     *elPdgId_MultiLepCalc;
   vector<int>     *elScPixCharge_MultiLepCalc;
   vector<int>     *elStatus_MultiLepCalc;
   vector<int>     *elVtxFitConv_MultiLepCalc;
   vector<int>     *genBSLID_MultiLepCalc;
   vector<int>     *genID_MultiLepCalc;
   vector<int>     *genIndex_MultiLepCalc;
   vector<int>     *genMotherID_MultiLepCalc;
   vector<int>     *genMotherIndex_MultiLepCalc;
   vector<int>     *genStatus_MultiLepCalc;
   vector<int>     *genTtbarIdCategory_TTbarMassCalc;
   vector<int>     *genTtbarId_TTbarMassCalc;
   vector<int>     *maxProb_JetSubCalc;
   vector<int>     *muCharge_MultiLepCalc;
   vector<int>     *muGlobal_MultiLepCalc;
   vector<int>     *muIsGlobalHighPt_MultiLepCalc;
   vector<int>     *muIsLoose_MultiLepCalc;
   vector<int>     *muIsMediumPrompt_MultiLepCalc;
   vector<int>     *muIsMedium_MultiLepCalc;
   vector<int>     *muIsMiniIsoLoose_MultiLepCalc;
   vector<int>     *muIsMiniIsoMedium_MultiLepCalc;
   vector<int>     *muIsMiniIsoTight_MultiLepCalc;
   vector<int>     *muIsMiniIsoVeryTight_MultiLepCalc;
   vector<int>     *muIsMvaLoose_MultiLepCalc;
   vector<int>     *muIsMvaMedium_MultiLepCalc;
   vector<int>     *muIsMvaTight_MultiLepCalc;
   vector<int>     *muIsTight_MultiLepCalc;
   vector<int>     *muIsTrkHighPt_MultiLepCalc;
   vector<int>     *muMatched_MultiLepCalc;
   vector<int>     *muMother_id_MultiLepCalc;
   vector<int>     *muMother_status_MultiLepCalc;
   vector<int>     *muNMatchedStations_MultiLepCalc;
   vector<int>     *muNTrackerLayers_MultiLepCalc;
   vector<int>     *muNValMuHits_MultiLepCalc;
   vector<int>     *muNValPixelHits_MultiLepCalc;
   vector<int>     *muNumberOfMothers_MultiLepCalc;
   vector<int>     *muPdgId_MultiLepCalc;
   vector<int>     *muStatus_MultiLepCalc;
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
   vector<int>     *viSelMCTriggersEl_MultiLepCalc;
   vector<int>     *viSelMCTriggersMu_MultiLepCalc;
   vector<int>     *viSelTriggersEl_MultiLepCalc;
   vector<int>     *viSelTriggersMu_MultiLepCalc;
   vector<double>  *AK4JetBDeepCSVb_MultiLepCalc;
   vector<double>  *AK4JetBDeepCSVbb_MultiLepCalc;
   vector<double>  *AK4JetBDeepCSVc_MultiLepCalc;
   vector<double>  *AK4JetBDeepCSVudsg_MultiLepCalc;
   vector<double>  *AK4JetBDisc_MultiLepCalc;
   vector<double>  *AK4JetEnergy_MultiLepCalc;
   vector<double>  *AK4JetEta_MultiLepCalc;
   vector<double>  *AK4JetPhi_MultiLepCalc;
   vector<double>  *AK4JetPt_MultiLepCalc;
   vector<double>  *AK8JetCSV_MultiLepCalc;
   vector<double>  *AK8JetDoubleB_MultiLepCalc;
   vector<double>  *AK8JetEnergy_BestCalc;
   vector<double>  *AK8JetEnergy_MultiLepCalc;
   vector<double>  *AK8JetEta_BestCalc;
   vector<double>  *AK8JetEta_MultiLepCalc;
   vector<double>  *AK8JetPhi_BestCalc;
   vector<double>  *AK8JetPhi_MultiLepCalc;
   vector<double>  *AK8JetPt_BestCalc;
   vector<double>  *AK8JetPt_MultiLepCalc;
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
   vector<double>  *LHEweights_MultiLepCalc;
   vector<double>  *LeptonEnergy_TpTpCalc;
   vector<double>  *LeptonEta_TpTpCalc;
   vector<double>  *LeptonPhi_TpTpCalc;
   vector<double>  *LeptonPt_TpTpCalc;
   vector<double>  *NewPDFweightsBase_MultiLepCalc;
   vector<double>  *NewPDFweights_MultiLepCalc;
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
   vector<double>  *elAEff_MultiLepCalc;
   vector<double>  *elChIso_MultiLepCalc;
   vector<double>  *elD0_MultiLepCalc;
   vector<double>  *elDEtaSCTkAtVtx_MultiLepCalc;
   vector<double>  *elDPhiSCTkAtVtx_MultiLepCalc;
   vector<double>  *elDR03TkSumPt_MultiLepCalc;
   vector<double>  *elDZ_MultiLepCalc;
   vector<double>  *elDeta_MultiLepCalc;
   vector<double>  *elDphi_MultiLepCalc;
   vector<double>  *elDxy_MultiLepCalc;
   vector<double>  *elEcalPFClusterIso_MultiLepCalc;
   vector<double>  *elEnergy_MultiLepCalc;
   vector<double>  *elEtaVtx_MultiLepCalc;
   vector<double>  *elEta_MultiLepCalc;
   vector<double>  *elGen_Reco_dr_MultiLepCalc;
   vector<double>  *elHcalPFClusterIso_MultiLepCalc;
   vector<double>  *elHoE_MultiLepCalc;
   vector<double>  *elIsLoose_MultiLepCalc;
   vector<double>  *elIsMedium_MultiLepCalc;
   vector<double>  *elIsTight_MultiLepCalc;
   vector<double>  *elIsVeto_MultiLepCalc;
   /* vector<double>  *elMVAValue_iso_MultiLepCalc; */
   /* vector<double>  *elMVAValue_MultiLepCalc; */
   vector<double>  *elMatchedEnergy_MultiLepCalc;
   vector<double>  *elMatchedEta_MultiLepCalc;
   vector<double>  *elMatchedPhi_MultiLepCalc;
   vector<double>  *elMatchedPt_MultiLepCalc;
   vector<double>  *elMiniIso_MultiLepCalc;
   vector<double>  *elMother_energy_MultiLepCalc;
   vector<double>  *elMother_eta_MultiLepCalc;
   vector<double>  *elMother_phi_MultiLepCalc;
   vector<double>  *elMother_pt_MultiLepCalc;
   vector<double>  *elNhIso_MultiLepCalc;
   vector<double>  *elOoemoop_MultiLepCalc;
   vector<double>  *elPFEta_MultiLepCalc;
   vector<double>  *elPFPhi_MultiLepCalc;
   vector<double>  *elPhIso_MultiLepCalc;
   vector<double>  *elPhiVtx_MultiLepCalc;
   vector<double>  *elPhi_MultiLepCalc;
   vector<double>  *elPt_MultiLepCalc;
   vector<double>  *elRelIso_MultiLepCalc;
   vector<double>  *elRhoIso_MultiLepCalc;
   vector<double>  *elSCE_MultiLepCalc;
   vector<double>  *elSihih_MultiLepCalc;
   vector<double>  *evtWeightsMC_MultiLepCalc;
   vector<double>  *genBSLEnergy_MultiLepCalc;
   vector<double>  *genBSLEta_MultiLepCalc;
   vector<double>  *genBSLPhi_MultiLepCalc;
   vector<double>  *genBSLPt_MultiLepCalc;
   vector<double>  *genEnergy_MultiLepCalc;
   vector<double>  *genEta_MultiLepCalc;
   vector<double>  *genJetEnergy_MultiLepCalc;
   vector<double>  *genJetEta_MultiLepCalc;
   vector<double>  *genJetPhi_MultiLepCalc;
   vector<double>  *genJetPt_MultiLepCalc;
   vector<double>  *genPhi_MultiLepCalc;
   vector<double>  *genPt_MultiLepCalc;
   vector<double>  *muChIso_MultiLepCalc;
   vector<double>  *muChi2_MultiLepCalc;
   vector<double>  *muDxy_MultiLepCalc;
   vector<double>  *muDz_MultiLepCalc;
   vector<double>  *muEnergy_MultiLepCalc;
   vector<double>  *muEta_MultiLepCalc;
   vector<double>  *muGIso_MultiLepCalc;
   vector<double>  *muGen_Reco_dr_MultiLepCalc;
   vector<double>  *muInnerEta_MultiLepCalc;
   vector<double>  *muInnerPhi_MultiLepCalc;
   vector<double>  *muInnerPt_MultiLepCalc;
   vector<double>  *muMatchedEnergy_MultiLepCalc;
   vector<double>  *muMatchedEta_MultiLepCalc;
   vector<double>  *muMatchedPhi_MultiLepCalc;
   vector<double>  *muMatchedPt_MultiLepCalc;
   vector<double>  *muMiniIsoDB_MultiLepCalc;
   vector<double>  *muMiniIso_MultiLepCalc;
   vector<double>  *muMother_energy_MultiLepCalc;
   vector<double>  *muMother_eta_MultiLepCalc;
   vector<double>  *muMother_phi_MultiLepCalc;
   vector<double>  *muMother_pt_MultiLepCalc;
   vector<double>  *muNhIso_MultiLepCalc;
   vector<double>  *muPhi_MultiLepCalc;
   vector<double>  *muPt_MultiLepCalc;
   vector<double>  *muPuIso_MultiLepCalc;
   vector<double>  *muRelIso_MultiLepCalc;
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
   vector<string>  *vsSelMCTriggersEl_MultiLepCalc;
   vector<string>  *vsSelMCTriggersMu_MultiLepCalc;
   vector<string>  *vsSelTriggersEl_MultiLepCalc;
   vector<string>  *vsSelTriggersMu_MultiLepCalc;

   // List of branches
   TBranch        *b_flagBadMu_MultiLepCalc;   //!
   TBranch        *b_flagDupMu_MultiLepCalc;   //!
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
   TBranch        *b_NLeptonDecays_TpTpCalc;   //!
   TBranch        *b_NPartonsfromHEPUEP_MultiLepCalc;   //!
   TBranch        *b_genTDLID_MultiLepCalc;   //!
   TBranch        *b_lumi_CommonCalc;   //!
   TBranch        *b_nAllJets_CommonCalc;   //!
   TBranch        *b_nLooseMuons_CommonCalc;   //!
   //   TBranch        *b_nPV_MultiLepCalc;   //!
   TBranch        *b_nPileupInteractions_MultiLepCalc;   //!
   TBranch        *b_nSelBtagJets_CommonCalc;   //!
   TBranch        *b_nSelElectrons_CommonCalc;   //!
   TBranch        *b_nSelJets_CommonCalc;   //!
   TBranch        *b_nTightMuons_CommonCalc;   //!
   TBranch        *b_nTrueInteractions_MultiLepCalc;   //!
   TBranch        *b_run_CommonCalc;   //!
   TBranch        *b_event_CommonCalc;   //!
   TBranch        *b_AK4HT_MultiLepCalc;   //!
   TBranch        *b_HTfromHEPUEP_MultiLepCalc;   //!
   TBranch        *b_L1NonPrefiringProbDown_CommonCalc;   //!
   TBranch        *b_L1NonPrefiringProbUp_CommonCalc;   //!
   TBranch        *b_L1NonPrefiringProb_CommonCalc;   //!
   TBranch        *b_LHEweightorig_MultiLepCalc;   //!
   TBranch        *b_MCWeight_MultiLepCalc;   //!
   TBranch        *b_corr_met_phi_MultiLepCalc;   //!
   TBranch        *b_corr_met_MultiLepCalc;   //!
   TBranch        *b_corr_metmod_phi_MultiLepCalc;   //!
   TBranch        *b_corr_metmod_MultiLepCalc;   //!
   TBranch        *b_corr_metnohf_phi_MultiLepCalc;   //!
   TBranch        *b_corr_metnohf_MultiLepCalc;   //!
   TBranch        *b_genTDLEnergy_MultiLepCalc;   //!
   TBranch        *b_genTDLEta_MultiLepCalc;   //!
   TBranch        *b_genTDLPhi_MultiLepCalc;   //!
   TBranch        *b_genTDLPt_MultiLepCalc;   //!
   TBranch        *b_met_phi_MultiLepCalc;   //!
   TBranch        *b_met_MultiLepCalc;   //!
   TBranch        *b_metmod_phi_MultiLepCalc;   //!
   TBranch        *b_metmod_MultiLepCalc;   //!
   TBranch        *b_metnohf_phi_MultiLepCalc;   //!
   TBranch        *b_metnohf_MultiLepCalc;   //!
   TBranch        *b_theJetHT_JetSubCalc;   //!
   TBranch        *b_theJetLeadPt_JetSubCalc;   //!
   TBranch        *b_theJetSubLeadPt_JetSubCalc;   //!
   TBranch        *b_ttbarMass_TTbarMassCalc;   //!
   TBranch        *b_AK4JetBTag_bSFdn_MultiLepCalc;   //!
   TBranch        *b_AK4JetBTag_bSFup_MultiLepCalc;   //!
   TBranch        *b_AK4JetBTag_lSFdn_MultiLepCalc;   //!
   TBranch        *b_AK4JetBTag_lSFup_MultiLepCalc;   //!
   TBranch        *b_AK4JetBTag_MultiLepCalc;   //!
   TBranch        *b_AK4JetFlav_MultiLepCalc;   //!
   TBranch        *b_HadronicVHtID_JetSubCalc;   //!
   TBranch        *b_HadronicVHtStatus_JetSubCalc;   //!
   TBranch        *b_HdecayID_TpTpCalc;   //!
   TBranch        *b_HdecayIndex_TpTpCalc;   //!
   TBranch        *b_LHEweightids_MultiLepCalc;   //!
   TBranch        *b_LeptonID_TpTpCalc;   //!
   TBranch        *b_LeptonParentID_TpTpCalc;   //!
   TBranch        *b_NewPDFids_MultiLepCalc;   //!
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
   TBranch        *b_elChargeConsistent_MultiLepCalc;   //!
   TBranch        *b_elCharge_MultiLepCalc;   //!
   TBranch        *b_elCtfCharge_MultiLepCalc;   //!
   TBranch        *b_elGsfCharge_MultiLepCalc;   //!
   TBranch        *b_elIsEBEE_MultiLepCalc;   //!
   /* TBranch        *b_elIsMVALooseIso_MultiLepCalc;   //! */
   /* TBranch        *b_elIsMVALoose_MultiLepCalc;   //! */
   /* TBranch        *b_elIsMVATight80_MultiLepCalc;   //! */
   /* TBranch        *b_elIsMVATight90_MultiLepCalc;   //! */
   /* TBranch        *b_elIsMVATightIso80_MultiLepCalc;   //! */
   /* TBranch        *b_elIsMVATightIso90_MultiLepCalc;   //! */
   TBranch        *b_elMHits_MultiLepCalc;   //!
   TBranch        *b_elMatched_MultiLepCalc;   //!
   TBranch        *b_elMother_id_MultiLepCalc;   //!
   TBranch        *b_elMother_status_MultiLepCalc;   //!
   TBranch        *b_elNotConversion_MultiLepCalc;   //!
   TBranch        *b_elNumberOfMothers_MultiLepCalc;   //!
   TBranch        *b_elPdgId_MultiLepCalc;   //!
   TBranch        *b_elScPixCharge_MultiLepCalc;   //!
   TBranch        *b_elStatus_MultiLepCalc;   //!
   TBranch        *b_elVtxFitConv_MultiLepCalc;   //!
   TBranch        *b_genBSLID_MultiLepCalc;   //!
   TBranch        *b_genID_MultiLepCalc;   //!
   TBranch        *b_genIndex_MultiLepCalc;   //!
   TBranch        *b_genMotherID_MultiLepCalc;   //!
   TBranch        *b_genMotherIndex_MultiLepCalc;   //!
   TBranch        *b_genStatus_MultiLepCalc;   //!
   TBranch        *b_genTtbarIdCategory_TTbarMassCalc;   //!
   TBranch        *b_genTtbarId_TTbarMassCalc;   //!
   TBranch        *b_maxProb_JetSubCalc;   //!
   TBranch        *b_muCharge_MultiLepCalc;   //!
   TBranch        *b_muGlobal_MultiLepCalc;   //!
   TBranch        *b_muIsGlobalHighPt_MultiLepCalc;   //!
   TBranch        *b_muIsLoose_MultiLepCalc;   //!
   TBranch        *b_muIsMediumPrompt_MultiLepCalc;   //!
   TBranch        *b_muIsMedium_MultiLepCalc;   //!
   TBranch        *b_muIsMiniIsoLoose_MultiLepCalc;   //!
   TBranch        *b_muIsMiniIsoMedium_MultiLepCalc;   //!
   TBranch        *b_muIsMiniIsoTight_MultiLepCalc;   //!
   TBranch        *b_muIsMiniIsoVeryTight_MultiLepCalc;   //!
   TBranch        *b_muIsMvaLoose_MultiLepCalc;   //!
   TBranch        *b_muIsMvaMedium_MultiLepCalc;   //!
   TBranch        *b_muIsMvaTight_MultiLepCalc;   //!
   TBranch        *b_muIsTight_MultiLepCalc;   //!
   TBranch        *b_muIsTrkHighPt_MultiLepCalc;   //!
   TBranch        *b_muMatched_MultiLepCalc;   //!
   TBranch        *b_muMother_id_MultiLepCalc;   //!
   TBranch        *b_muMother_status_MultiLepCalc;   //!
   TBranch        *b_muNMatchedStations_MultiLepCalc;   //!
   TBranch        *b_muNTrackerLayers_MultiLepCalc;   //!
   TBranch        *b_muNValMuHits_MultiLepCalc;   //!
   TBranch        *b_muNValPixelHits_MultiLepCalc;   //!
   TBranch        *b_muNumberOfMothers_MultiLepCalc;   //!
   TBranch        *b_muPdgId_MultiLepCalc;   //!
   TBranch        *b_muStatus_MultiLepCalc;   //!
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
   TBranch        *b_viSelMCTriggersEl_MultiLepCalc;   //!
   TBranch        *b_viSelMCTriggersMu_MultiLepCalc;   //!
   TBranch        *b_viSelTriggersEl_MultiLepCalc;   //!
   TBranch        *b_viSelTriggersMu_MultiLepCalc;   //!
   TBranch        *b_AK4JetBDeepCSVb_MultiLepCalc;   //!
   TBranch        *b_AK4JetBDeepCSVbb_MultiLepCalc;   //!
   TBranch        *b_AK4JetBDeepCSVc_MultiLepCalc;   //!
   TBranch        *b_AK4JetBDeepCSVudsg_MultiLepCalc;   //!
   TBranch        *b_AK4JetBDisc_MultiLepCalc;   //!
   TBranch        *b_AK4JetEnergy_MultiLepCalc;   //!
   TBranch        *b_AK4JetEta_MultiLepCalc;   //!
   TBranch        *b_AK4JetPhi_MultiLepCalc;   //!
   TBranch        *b_AK4JetPt_MultiLepCalc;   //!
   TBranch        *b_AK8JetCSV_MultiLepCalc;   //!
   TBranch        *b_AK8JetDoubleB_MultiLepCalc;   //!
   TBranch        *b_AK8JetEnergy_BestCalc;   //!
   TBranch        *b_AK8JetEnergy_MultiLepCalc;   //!
   TBranch        *b_AK8JetEta_BestCalc;   //!
   TBranch        *b_AK8JetEta_MultiLepCalc;   //!
   TBranch        *b_AK8JetPhi_BestCalc;   //!
   TBranch        *b_AK8JetPhi_MultiLepCalc;   //!
   TBranch        *b_AK8JetPt_BestCalc;   //!
   TBranch        *b_AK8JetPt_MultiLepCalc;   //!
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
   TBranch        *b_LHEweights_MultiLepCalc;   //!
   TBranch        *b_LeptonEnergy_TpTpCalc;   //!
   TBranch        *b_LeptonEta_TpTpCalc;   //!
   TBranch        *b_LeptonPhi_TpTpCalc;   //!
   TBranch        *b_LeptonPt_TpTpCalc;   //!
   TBranch        *b_NewPDFweightsBase_MultiLepCalc;   //!
   TBranch        *b_NewPDFweights_MultiLepCalc;   //!
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
   TBranch        *b_elAEff_MultiLepCalc;   //!
   TBranch        *b_elChIso_MultiLepCalc;   //!
   TBranch        *b_elD0_MultiLepCalc;   //!
   TBranch        *b_elDEtaSCTkAtVtx_MultiLepCalc;   //!
   TBranch        *b_elDPhiSCTkAtVtx_MultiLepCalc;   //!
   TBranch        *b_elDR03TkSumPt_MultiLepCalc;   //!
   TBranch        *b_elDZ_MultiLepCalc;   //!
   TBranch        *b_elDeta_MultiLepCalc;   //!
   TBranch        *b_elDphi_MultiLepCalc;   //!
   TBranch        *b_elDxy_MultiLepCalc;   //!
   TBranch        *b_elEcalPFClusterIso_MultiLepCalc;   //!
   TBranch        *b_elEnergy_MultiLepCalc;   //!
   TBranch        *b_elEtaVtx_MultiLepCalc;   //!
   TBranch        *b_elEta_MultiLepCalc;   //!
   TBranch        *b_elGen_Reco_dr_MultiLepCalc;   //!
   TBranch        *b_elHcalPFClusterIso_MultiLepCalc;   //!
   TBranch        *b_elHoE_MultiLepCalc;   //!
   TBranch        *b_elIsLoose_MultiLepCalc;   //!
   TBranch        *b_elIsMedium_MultiLepCalc;   //!
   TBranch        *b_elIsTight_MultiLepCalc;   //!
   TBranch        *b_elIsVeto_MultiLepCalc;   //!
   /* TBranch        *b_elMVAValue_iso_MultiLepCalc;   //! */
   /* TBranch        *b_elMVAValue_MultiLepCalc;   //! */
   TBranch        *b_elMatchedEnergy_MultiLepCalc;   //!
   TBranch        *b_elMatchedEta_MultiLepCalc;   //!
   TBranch        *b_elMatchedPhi_MultiLepCalc;   //!
   TBranch        *b_elMatchedPt_MultiLepCalc;   //!
   TBranch        *b_elMiniIso_MultiLepCalc;   //!
   TBranch        *b_elMother_energy_MultiLepCalc;   //!
   TBranch        *b_elMother_eta_MultiLepCalc;   //!
   TBranch        *b_elMother_phi_MultiLepCalc;   //!
   TBranch        *b_elMother_pt_MultiLepCalc;   //!
   TBranch        *b_elNhIso_MultiLepCalc;   //!
   TBranch        *b_elOoemoop_MultiLepCalc;   //!
   TBranch        *b_elPFEta_MultiLepCalc;   //!
   TBranch        *b_elPFPhi_MultiLepCalc;   //!
   TBranch        *b_elPhIso_MultiLepCalc;   //!
   TBranch        *b_elPhiVtx_MultiLepCalc;   //!
   TBranch        *b_elPhi_MultiLepCalc;   //!
   TBranch        *b_elPt_MultiLepCalc;   //!
   TBranch        *b_elRelIso_MultiLepCalc;   //!
   TBranch        *b_elRhoIso_MultiLepCalc;   //!
   TBranch        *b_elSCE_MultiLepCalc;   //!
   TBranch        *b_elSihih_MultiLepCalc;   //!
   TBranch        *b_evtWeightsMC_MultiLepCalc;   //!
   TBranch        *b_genBSLEnergy_MultiLepCalc;   //!
   TBranch        *b_genBSLEta_MultiLepCalc;   //!
   TBranch        *b_genBSLPhi_MultiLepCalc;   //!
   TBranch        *b_genBSLPt_MultiLepCalc;   //!
   TBranch        *b_genEnergy_MultiLepCalc;   //!
   TBranch        *b_genEta_MultiLepCalc;   //!
   TBranch        *b_genJetEnergy_MultiLepCalc;   //!
   TBranch        *b_genJetEta_MultiLepCalc;   //!
   TBranch        *b_genJetPhi_MultiLepCalc;   //!
   TBranch        *b_genJetPt_MultiLepCalc;   //!
   TBranch        *b_genPhi_MultiLepCalc;   //!
   TBranch        *b_genPt_MultiLepCalc;   //!
   TBranch        *b_muChIso_MultiLepCalc;   //!
   TBranch        *b_muChi2_MultiLepCalc;   //!
   TBranch        *b_muDxy_MultiLepCalc;   //!
   TBranch        *b_muDz_MultiLepCalc;   //!
   TBranch        *b_muEnergy_MultiLepCalc;   //!
   TBranch        *b_muEta_MultiLepCalc;   //!
   TBranch        *b_muGIso_MultiLepCalc;   //!
   TBranch        *b_muGen_Reco_dr_MultiLepCalc;   //!
   TBranch        *b_muInnerEta_MultiLepCalc;   //!
   TBranch        *b_muInnerPhi_MultiLepCalc;   //!
   TBranch        *b_muInnerPt_MultiLepCalc;   //!
   TBranch        *b_muMatchedEnergy_MultiLepCalc;   //!
   TBranch        *b_muMatchedEta_MultiLepCalc;   //!
   TBranch        *b_muMatchedPhi_MultiLepCalc;   //!
   TBranch        *b_muMatchedPt_MultiLepCalc;   //!
   TBranch        *b_muMiniIsoDB_MultiLepCalc;   //!
   TBranch        *b_muMiniIso_MultiLepCalc;   //!
   TBranch        *b_muMother_energy_MultiLepCalc;   //!
   TBranch        *b_muMother_eta_MultiLepCalc;   //!
   TBranch        *b_muMother_phi_MultiLepCalc;   //!
   TBranch        *b_muMother_pt_MultiLepCalc;   //!
   TBranch        *b_muNhIso_MultiLepCalc;   //!
   TBranch        *b_muPhi_MultiLepCalc;   //!
   TBranch        *b_muPt_MultiLepCalc;   //!
   TBranch        *b_muPuIso_MultiLepCalc;   //!
   TBranch        *b_muRelIso_MultiLepCalc;   //!
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
   TBranch        *b_vsSelMCTriggersEl_MultiLepCalc;   //!
   TBranch        *b_vsSelMCTriggersMu_MultiLepCalc;   //!
   TBranch        *b_vsSelTriggersEl_MultiLepCalc;   //!
   TBranch        *b_vsSelTriggersMu_MultiLepCalc;   //!
 
   step1(TString inputFileName, TString outputFileName, TString outputDir);
   virtual ~step1();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(TString inTreeName, TString outTreeName);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual void     saveHistograms();
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

  pileupIndex = -1;

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
  else SigMass = -1;

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

  isSig  = (inputFileName.Contains("prime") || inputFileName.Contains("X53") || inputFileName.Contains("ChargedHiggs_Hplus"));
  if(isSig){
    if(inputFileName.Contains("Bprime")){
      if(inputFileName.Contains("_M-900")) {SigMass = 2; pileupIndex = 44;}
      else if(inputFileName.Contains("_M-1000")) {SigMass = 3; pileupIndex = 44;}
      else if(inputFileName.Contains("_M-1100")) {SigMass = 4; pileupIndex = 45;}
      else if(inputFileName.Contains("_M-1200")) {SigMass = 5; pileupIndex = 46;}
      else if(inputFileName.Contains("_M-1300")) {SigMass = 6; pileupIndex = 47;}
      else if(inputFileName.Contains("_M-1400")) {SigMass = 7; pileupIndex = 48;}
      else if(inputFileName.Contains("_M-1500")) {SigMass = 8; pileupIndex = 49;}
      else if(inputFileName.Contains("_M-1600")) {SigMass = 9; pileupIndex = 50;}
      else if(inputFileName.Contains("_M-1700")) {SigMass = 10; pileupIndex = 50;}
      else if(inputFileName.Contains("_M-1800")) {SigMass = 11; pileupIndex = 51;}
      else SigMass = -1;
    } 
    else if(inputFileName.Contains("Tprime")){
      if(inputFileName.Contains("_M-700")) {SigMass = 0; pileupIndex = 52;}
      else if(inputFileName.Contains("_M-1000")) {SigMass = 3; pileupIndex = 52;}
      else if(inputFileName.Contains("_M-1100")) {SigMass = 4; pileupIndex = 53;}
      else if(inputFileName.Contains("_M-1200")) {SigMass = 5; pileupIndex = 54;}
      else if(inputFileName.Contains("_M-1300")) {SigMass = 6; pileupIndex = 55;}
      else if(inputFileName.Contains("_M-1400")) {SigMass = 7; pileupIndex = 56;}
      else if(inputFileName.Contains("_M-1500")) {SigMass = 8; pileupIndex = 57;}
      else if(inputFileName.Contains("_M-1600")) {SigMass = 9; pileupIndex = 58;}
      else if(inputFileName.Contains("_M-1700")) {SigMass = 10; pileupIndex = 59;}
      else if(inputFileName.Contains("_M-1800")) {SigMass = 11; pileupIndex = 60;}
      else SigMass = -1;
    }
  }  
  else SigMass = -1;


  if(inputFileName.Contains("DYJetsToLL_M-50_HT-200")) pileupIndex = 0;
  else if(inputFileName.Contains("DYJetsToLL_M-50_HT-400")) pileupIndex = 1;
  else if(inputFileName.Contains("DYJetsToLL_M-50_HT-600")) pileupIndex = 2;
  else if(inputFileName.Contains("DYJetsToLL_M-50_HT-800")) pileupIndex = 3;
  else if(inputFileName.Contains("DYJetsToLL_M-50_HT-1200")) pileupIndex = 4;
  else if(inputFileName.Contains("DYJetsToLL_M-50_HT-2500")) pileupIndex = 5;
  else if(inputFileName.Contains("TTWJetsToQQ")) pileupIndex = 6;
  else if(inputFileName.Contains("QCD_HT1000")) pileupIndex = 7;
  else if(inputFileName.Contains("QCD_HT1500")) pileupIndex = 8;
  else if(inputFileName.Contains("QCD_HT2000")) pileupIndex = 9;
  else if(inputFileName.Contains("QCD_HT200")) pileupIndex = 10;
  else if(inputFileName.Contains("QCD_HT300")) pileupIndex = 11;
  else if(inputFileName.Contains("QCD_HT500")) pileupIndex = 12;
  else if(inputFileName.Contains("QCD_HT700")) pileupIndex = 13;
  else if(inputFileName.Contains("ST_s-channel_antitop")) pileupIndex = 14;
  else if(inputFileName.Contains("ST_s-channel_top")) pileupIndex = 15;
  else if(inputFileName.Contains("ST_t-channel_antitop")) pileupIndex = 16;
  else if(inputFileName.Contains("ST_t-channel_top")) pileupIndex = 17;
  else if(inputFileName.Contains("ST_tW_antitop")) pileupIndex = 18;
  else if(inputFileName.Contains("ST_tW_top")) pileupIndex = 19;
  else if(inputFileName.Contains("TTTo2") && inputFileName.Contains("0to7")) pileupIndex = 20;
  else if(inputFileName.Contains("TTTo2") && inputFileName.Contains("Inf")) pileupIndex = 21;
  else if(inputFileName.Contains("TTTo2") && inputFileName.Contains("700to")) pileupIndex = 22;
  else if(inputFileName.Contains("TTToH") && inputFileName.Contains("0to7")) pileupIndex = 23;
  else if(inputFileName.Contains("TTToH") && inputFileName.Contains("Inf")) pileupIndex = 24;
  else if(inputFileName.Contains("TTToH") && inputFileName.Contains("700to")) pileupIndex = 25;
  else if(inputFileName.Contains("TTToS") && inputFileName.Contains("0to7")) pileupIndex = 26;
  else if(inputFileName.Contains("TTToS") && inputFileName.Contains("Inf")) pileupIndex = 27;
  else if(inputFileName.Contains("TTToS") && inputFileName.Contains("700to")) pileupIndex = 28;
  else if(inputFileName.Contains("TT_Mtt-700")) pileupIndex = 29;
  else if(inputFileName.Contains("TT_Mtt-1000")) pileupIndex = 30;
  else if(inputFileName.Contains("TTZToLLNuNu")) pileupIndex = 31;
  else if(inputFileName.Contains("TTWJetsToLNu")) pileupIndex = 32;
  else if(inputFileName.Contains("ttHTobb")) pileupIndex = 33;
  else if(inputFileName.Contains("ttHToNonbb")) pileupIndex = 34;
  else if(inputFileName.Contains("WJetsToLNu_HT-1200")) pileupIndex = 35;
  else if(inputFileName.Contains("WJetsToLNu_HT-200")) pileupIndex = 36;
  else if(inputFileName.Contains("WJetsToLNu_HT-2500")) pileupIndex = 37;
  else if(inputFileName.Contains("WJetsToLNu_HT-400")) pileupIndex = 38;
  else if(inputFileName.Contains("WJetsToLNu_HT-600")) pileupIndex = 39;
  else if(inputFileName.Contains("WJetsToLNu_HT-800")) pileupIndex = 40;
  else if(inputFileName.Contains("WW_")) pileupIndex = 41;
  else if(inputFileName.Contains("WZ_")) pileupIndex = 42;
  else if(inputFileName.Contains("ZZ_")) pileupIndex = 43;


  std::cout << "output = " << outputDir << "/" << outputFileName << std::endl;

  isBUp = false; // these will now get changed in makeStep1Dnn.C
  isBDn = false;
  isLUp = false;
  isLDn = false;
  isNominal = true;
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
  // Now done in the .cc
  /* inputTree=(TTree*)inputFile->Get("ljmet"); */
  /* if(inputTree->GetEntries()==0){ */
  /*   std::cout<<"WARNING! Found 0 events in the tree!!!!"<<std::endl;; */
  /*   exit(1); */
  /* } */

  InitPileup();
  
  outputFile=new TFile(outputFileName,"RECREATE");   
  
  //  Init(inputTree);
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
   AK4JetBTag_bSFdn_MultiLepCalc = 0;
   AK4JetBTag_bSFup_MultiLepCalc = 0;
   AK4JetBTag_lSFdn_MultiLepCalc = 0;
   AK4JetBTag_lSFup_MultiLepCalc = 0;
   AK4JetBTag_MultiLepCalc = 0;
   AK4JetFlav_MultiLepCalc = 0;
   HadronicVHtID_JetSubCalc = 0;
   HadronicVHtStatus_JetSubCalc = 0;
   HdecayID_TpTpCalc = 0;
   HdecayIndex_TpTpCalc = 0;
   LHEweightids_MultiLepCalc = 0;
   LeptonID_TpTpCalc = 0;
   LeptonParentID_TpTpCalc = 0;
   NewPDFids_MultiLepCalc = 0;
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
   elChargeConsistent_MultiLepCalc = 0;
   elCharge_MultiLepCalc = 0;
   elCtfCharge_MultiLepCalc = 0;
   elGsfCharge_MultiLepCalc = 0;
   elIsEBEE_MultiLepCalc = 0;
   /* elIsMVALooseIso_MultiLepCalc = 0; */
   /* elIsMVALoose_MultiLepCalc = 0; */
   /* elIsMVATight80_MultiLepCalc = 0; */
   /* elIsMVATight90_MultiLepCalc = 0; */
   /* elIsMVATightIso80_MultiLepCalc = 0; */
   /* elIsMVATightIso90_MultiLepCalc = 0; */
   elMHits_MultiLepCalc = 0;
   elMatched_MultiLepCalc = 0;
   elMother_id_MultiLepCalc = 0;
   elMother_status_MultiLepCalc = 0;
   elNotConversion_MultiLepCalc = 0;
   elNumberOfMothers_MultiLepCalc = 0;
   elPdgId_MultiLepCalc = 0;
   elScPixCharge_MultiLepCalc = 0;
   elStatus_MultiLepCalc = 0;
   elVtxFitConv_MultiLepCalc = 0;
   genBSLID_MultiLepCalc = 0;
   genID_MultiLepCalc = 0;
   genIndex_MultiLepCalc = 0;
   genMotherID_MultiLepCalc = 0;
   genMotherIndex_MultiLepCalc = 0;
   genStatus_MultiLepCalc = 0;
   genTtbarIdCategory_TTbarMassCalc = 0;
   genTtbarId_TTbarMassCalc = 0;
   maxProb_JetSubCalc = 0;
   muCharge_MultiLepCalc = 0;
   muGlobal_MultiLepCalc = 0;
   muIsGlobalHighPt_MultiLepCalc = 0;
   muIsLoose_MultiLepCalc = 0;
   muIsMediumPrompt_MultiLepCalc = 0;
   muIsMedium_MultiLepCalc = 0;
   muIsMiniIsoLoose_MultiLepCalc = 0;
   muIsMiniIsoMedium_MultiLepCalc = 0;
   muIsMiniIsoTight_MultiLepCalc = 0;
   muIsMiniIsoVeryTight_MultiLepCalc = 0;
   muIsMvaLoose_MultiLepCalc = 0;
   muIsMvaMedium_MultiLepCalc = 0;
   muIsMvaTight_MultiLepCalc = 0;
   muIsTight_MultiLepCalc = 0;
   muIsTrkHighPt_MultiLepCalc = 0;
   muMatched_MultiLepCalc = 0;
   muMother_id_MultiLepCalc = 0;
   muMother_status_MultiLepCalc = 0;
   muNMatchedStations_MultiLepCalc = 0;
   muNTrackerLayers_MultiLepCalc = 0;
   muNValMuHits_MultiLepCalc = 0;
   muNValPixelHits_MultiLepCalc = 0;
   muNumberOfMothers_MultiLepCalc = 0;
   muPdgId_MultiLepCalc = 0;
   muStatus_MultiLepCalc = 0;
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
   viSelMCTriggersEl_MultiLepCalc = 0;
   viSelMCTriggersMu_MultiLepCalc = 0;
   viSelTriggersEl_MultiLepCalc = 0;
   viSelTriggersMu_MultiLepCalc = 0;
   AK4JetBDeepCSVb_MultiLepCalc = 0;
   AK4JetBDeepCSVbb_MultiLepCalc = 0;
   AK4JetBDeepCSVc_MultiLepCalc = 0;
   AK4JetBDeepCSVudsg_MultiLepCalc = 0;
   AK4JetBDisc_MultiLepCalc = 0;
   AK4JetEnergy_MultiLepCalc = 0;
   AK4JetEta_MultiLepCalc = 0;
   AK4JetPhi_MultiLepCalc = 0;
   AK4JetPt_MultiLepCalc = 0;
   AK8JetCSV_MultiLepCalc = 0;
   AK8JetDoubleB_MultiLepCalc = 0;
   AK8JetEnergy_BestCalc = 0;
   AK8JetEnergy_MultiLepCalc = 0;
   AK8JetEta_BestCalc = 0;
   AK8JetEta_MultiLepCalc = 0;
   AK8JetPhi_BestCalc = 0;
   AK8JetPhi_MultiLepCalc = 0;
   AK8JetPt_BestCalc = 0;
   AK8JetPt_MultiLepCalc = 0;
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
   LHEweights_MultiLepCalc = 0;
   LeptonEnergy_TpTpCalc = 0;
   LeptonEta_TpTpCalc = 0;
   LeptonPhi_TpTpCalc = 0;
   LeptonPt_TpTpCalc = 0;
   NewPDFweightsBase_MultiLepCalc = 0;
   NewPDFweights_MultiLepCalc = 0;
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
   elAEff_MultiLepCalc = 0;
   elChIso_MultiLepCalc = 0;
   elD0_MultiLepCalc = 0;
   elDEtaSCTkAtVtx_MultiLepCalc = 0;
   elDPhiSCTkAtVtx_MultiLepCalc = 0;
   elDR03TkSumPt_MultiLepCalc = 0;
   elDZ_MultiLepCalc = 0;
   elDeta_MultiLepCalc = 0;
   elDphi_MultiLepCalc = 0;
   elDxy_MultiLepCalc = 0;
   elEcalPFClusterIso_MultiLepCalc = 0;
   elEnergy_MultiLepCalc = 0;
   elEtaVtx_MultiLepCalc = 0;
   elEta_MultiLepCalc = 0;
   elGen_Reco_dr_MultiLepCalc = 0;
   elHcalPFClusterIso_MultiLepCalc = 0;
   elHoE_MultiLepCalc = 0;
   elIsLoose_MultiLepCalc = 0;
   elIsMedium_MultiLepCalc = 0;
   elIsTight_MultiLepCalc = 0;
   elIsVeto_MultiLepCalc = 0;
   /* elMVAValue_iso_MultiLepCalc = 0; */
   /* elMVAValue_MultiLepCalc = 0; */
   elMatchedEnergy_MultiLepCalc = 0;
   elMatchedEta_MultiLepCalc = 0;
   elMatchedPhi_MultiLepCalc = 0;
   elMatchedPt_MultiLepCalc = 0;
   elMiniIso_MultiLepCalc = 0;
   elMother_energy_MultiLepCalc = 0;
   elMother_eta_MultiLepCalc = 0;
   elMother_phi_MultiLepCalc = 0;
   elMother_pt_MultiLepCalc = 0;
   elNhIso_MultiLepCalc = 0;
   elOoemoop_MultiLepCalc = 0;
   elPFEta_MultiLepCalc = 0;
   elPFPhi_MultiLepCalc = 0;
   elPhIso_MultiLepCalc = 0;
   elPhiVtx_MultiLepCalc = 0;
   elPhi_MultiLepCalc = 0;
   elPt_MultiLepCalc = 0;
   elRelIso_MultiLepCalc = 0;
   elRhoIso_MultiLepCalc = 0;
   elSCE_MultiLepCalc = 0;
   elSihih_MultiLepCalc = 0;
   evtWeightsMC_MultiLepCalc = 0;
   genBSLEnergy_MultiLepCalc = 0;
   genBSLEta_MultiLepCalc = 0;
   genBSLPhi_MultiLepCalc = 0;
   genBSLPt_MultiLepCalc = 0;
   genEnergy_MultiLepCalc = 0;
   genEta_MultiLepCalc = 0;
   genJetEnergy_MultiLepCalc = 0;
   genJetEta_MultiLepCalc = 0;
   genJetPhi_MultiLepCalc = 0;
   genJetPt_MultiLepCalc = 0;
   genPhi_MultiLepCalc = 0;
   genPt_MultiLepCalc = 0;
   muChIso_MultiLepCalc = 0;
   muChi2_MultiLepCalc = 0;
   muDxy_MultiLepCalc = 0;
   muDz_MultiLepCalc = 0;
   muEnergy_MultiLepCalc = 0;
   muEta_MultiLepCalc = 0;
   muGIso_MultiLepCalc = 0;
   muGen_Reco_dr_MultiLepCalc = 0;
   muInnerEta_MultiLepCalc = 0;
   muInnerPhi_MultiLepCalc = 0;
   muInnerPt_MultiLepCalc = 0;
   muMatchedEnergy_MultiLepCalc = 0;
   muMatchedEta_MultiLepCalc = 0;
   muMatchedPhi_MultiLepCalc = 0;
   muMatchedPt_MultiLepCalc = 0;
   muMiniIsoDB_MultiLepCalc = 0;
   muMiniIso_MultiLepCalc = 0;
   muMother_energy_MultiLepCalc = 0;
   muMother_eta_MultiLepCalc = 0;
   muMother_phi_MultiLepCalc = 0;
   muMother_pt_MultiLepCalc = 0;
   muNhIso_MultiLepCalc = 0;
   muPhi_MultiLepCalc = 0;
   muPt_MultiLepCalc = 0;
   muPuIso_MultiLepCalc = 0;
   muRelIso_MultiLepCalc = 0;
   quarkEnergy_TpTpCalc = 0;
   quarkEta_TpTpCalc = 0;
   quarkPhi_TpTpCalc = 0;
   quarkPt_TpTpCalc = 0;
   tPrimeEnergy_TpTpCalc = 0;
   tPrimeEta_TpTpCalc = 0;
   tPrimeMass_TpTpCalc = 0;
   tPrimePhi_TpTpCalc = 0;
   tPrimePt_TpTpCalc = 0;
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
   vsSelMCTriggersEl_MultiLepCalc = 0;
   vsSelMCTriggersMu_MultiLepCalc = 0;
   vsSelTriggersEl_MultiLepCalc = 0;
   vsSelTriggersMu_MultiLepCalc = 0;

   // Set branch addresses and branch pointers
   if (!tree) return;
   inputTree = tree;
   fCurrent = -1;
   inputTree->SetMakeClass(1);

   inputTree->SetBranchAddress("flagBadMu_MultiLepCalc", &flagBadMu_MultiLepCalc, &b_flagBadMu_MultiLepCalc);
   inputTree->SetBranchAddress("flagDupMu_MultiLepCalc", &flagDupMu_MultiLepCalc, &b_flagDupMu_MultiLepCalc);
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
   inputTree->SetBranchAddress("NLeptonDecays_TpTpCalc", &NLeptonDecays_TpTpCalc, &b_NLeptonDecays_TpTpCalc);
   inputTree->SetBranchAddress("NPartonsfromHEPUEP_MultiLepCalc", &NPartonsfromHEPUEP_MultiLepCalc, &b_NPartonsfromHEPUEP_MultiLepCalc);
   inputTree->SetBranchAddress("genTDLID_MultiLepCalc", &genTDLID_MultiLepCalc, &b_genTDLID_MultiLepCalc);
   inputTree->SetBranchAddress("lumi_CommonCalc", &lumi_CommonCalc, &b_lumi_CommonCalc);
   inputTree->SetBranchAddress("nAllJets_CommonCalc", &nAllJets_CommonCalc, &b_nAllJets_CommonCalc);
   inputTree->SetBranchAddress("nLooseMuons_CommonCalc", &nLooseMuons_CommonCalc, &b_nLooseMuons_CommonCalc);
   //   inputTree->SetBranchAddress("nPV_MultiLepCalc", &nPV_MultiLepCalc, &b_nPV_MultiLepCalc);
   inputTree->SetBranchAddress("nPileupInteractions_MultiLepCalc", &nPileupInteractions_MultiLepCalc, &b_nPileupInteractions_MultiLepCalc);
   inputTree->SetBranchAddress("nSelBtagJets_CommonCalc", &nSelBtagJets_CommonCalc, &b_nSelBtagJets_CommonCalc);
   inputTree->SetBranchAddress("nSelElectrons_CommonCalc", &nSelElectrons_CommonCalc, &b_nSelElectrons_CommonCalc);
   inputTree->SetBranchAddress("nSelJets_CommonCalc", &nSelJets_CommonCalc, &b_nSelJets_CommonCalc);
   inputTree->SetBranchAddress("nTightMuons_CommonCalc", &nTightMuons_CommonCalc, &b_nTightMuons_CommonCalc);
   inputTree->SetBranchAddress("nTrueInteractions_MultiLepCalc", &nTrueInteractions_MultiLepCalc, &b_nTrueInteractions_MultiLepCalc);
   inputTree->SetBranchAddress("run_CommonCalc", &run_CommonCalc, &b_run_CommonCalc);
   inputTree->SetBranchAddress("event_CommonCalc", &event_CommonCalc, &b_event_CommonCalc);
   inputTree->SetBranchAddress("AK4HT_MultiLepCalc", &AK4HT_MultiLepCalc, &b_AK4HT_MultiLepCalc);
   inputTree->SetBranchAddress("HTfromHEPUEP_MultiLepCalc", &HTfromHEPUEP_MultiLepCalc, &b_HTfromHEPUEP_MultiLepCalc);
   inputTree->SetBranchAddress("L1NonPrefiringProbDown_CommonCalc", &L1NonPrefiringProbDown_CommonCalc, &b_L1NonPrefiringProbDown_CommonCalc);
   inputTree->SetBranchAddress("L1NonPrefiringProbUp_CommonCalc", &L1NonPrefiringProbUp_CommonCalc, &b_L1NonPrefiringProbUp_CommonCalc);
   inputTree->SetBranchAddress("L1NonPrefiringProb_CommonCalc", &L1NonPrefiringProb_CommonCalc, &b_L1NonPrefiringProb_CommonCalc);
   inputTree->SetBranchAddress("LHEweightorig_MultiLepCalc", &LHEweightorig_MultiLepCalc, &b_LHEweightorig_MultiLepCalc);
   inputTree->SetBranchAddress("MCWeight_MultiLepCalc", &MCWeight_MultiLepCalc, &b_MCWeight_MultiLepCalc);
   inputTree->SetBranchAddress("corr_met_phi_MultiLepCalc", &corr_met_phi_MultiLepCalc, &b_corr_met_phi_MultiLepCalc);
   inputTree->SetBranchAddress("corr_met_MultiLepCalc", &corr_met_MultiLepCalc, &b_corr_met_MultiLepCalc);
   inputTree->SetBranchAddress("corr_metmod_phi_MultiLepCalc", &corr_metmod_phi_MultiLepCalc, &b_corr_metmod_phi_MultiLepCalc);
   inputTree->SetBranchAddress("corr_metmod_MultiLepCalc", &corr_metmod_MultiLepCalc, &b_corr_metmod_MultiLepCalc);
   inputTree->SetBranchAddress("corr_metnohf_phi_MultiLepCalc", &corr_metnohf_phi_MultiLepCalc, &b_corr_metnohf_phi_MultiLepCalc);
   inputTree->SetBranchAddress("corr_metnohf_MultiLepCalc", &corr_metnohf_MultiLepCalc, &b_corr_metnohf_MultiLepCalc);
   inputTree->SetBranchAddress("genTDLEnergy_MultiLepCalc", &genTDLEnergy_MultiLepCalc, &b_genTDLEnergy_MultiLepCalc);
   inputTree->SetBranchAddress("genTDLEta_MultiLepCalc", &genTDLEta_MultiLepCalc, &b_genTDLEta_MultiLepCalc);
   inputTree->SetBranchAddress("genTDLPhi_MultiLepCalc", &genTDLPhi_MultiLepCalc, &b_genTDLPhi_MultiLepCalc);
   inputTree->SetBranchAddress("genTDLPt_MultiLepCalc", &genTDLPt_MultiLepCalc, &b_genTDLPt_MultiLepCalc);
   inputTree->SetBranchAddress("met_phi_MultiLepCalc", &met_phi_MultiLepCalc, &b_met_phi_MultiLepCalc);
   inputTree->SetBranchAddress("met_MultiLepCalc", &met_MultiLepCalc, &b_met_MultiLepCalc);
   inputTree->SetBranchAddress("metmod_phi_MultiLepCalc", &metmod_phi_MultiLepCalc, &b_metmod_phi_MultiLepCalc);
   inputTree->SetBranchAddress("metmod_MultiLepCalc", &metmod_MultiLepCalc, &b_metmod_MultiLepCalc);
   inputTree->SetBranchAddress("metnohf_phi_MultiLepCalc", &metnohf_phi_MultiLepCalc, &b_metnohf_phi_MultiLepCalc);
   inputTree->SetBranchAddress("metnohf_MultiLepCalc", &metnohf_MultiLepCalc, &b_metnohf_MultiLepCalc);
   inputTree->SetBranchAddress("theJetHT_JetSubCalc", &theJetHT_JetSubCalc, &b_theJetHT_JetSubCalc);
   inputTree->SetBranchAddress("theJetLeadPt_JetSubCalc", &theJetLeadPt_JetSubCalc, &b_theJetLeadPt_JetSubCalc);
   inputTree->SetBranchAddress("theJetSubLeadPt_JetSubCalc", &theJetSubLeadPt_JetSubCalc, &b_theJetSubLeadPt_JetSubCalc);
   inputTree->SetBranchAddress("ttbarMass_TTbarMassCalc", &ttbarMass_TTbarMassCalc, &b_ttbarMass_TTbarMassCalc);
   inputTree->SetBranchAddress("AK4JetBTag_bSFdn_MultiLepCalc", &AK4JetBTag_bSFdn_MultiLepCalc, &b_AK4JetBTag_bSFdn_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetBTag_bSFup_MultiLepCalc", &AK4JetBTag_bSFup_MultiLepCalc, &b_AK4JetBTag_bSFup_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetBTag_lSFdn_MultiLepCalc", &AK4JetBTag_lSFdn_MultiLepCalc, &b_AK4JetBTag_lSFdn_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetBTag_lSFup_MultiLepCalc", &AK4JetBTag_lSFup_MultiLepCalc, &b_AK4JetBTag_lSFup_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetBTag_MultiLepCalc", &AK4JetBTag_MultiLepCalc, &b_AK4JetBTag_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetFlav_MultiLepCalc", &AK4JetFlav_MultiLepCalc, &b_AK4JetFlav_MultiLepCalc);
   inputTree->SetBranchAddress("HadronicVHtID_JetSubCalc", &HadronicVHtID_JetSubCalc, &b_HadronicVHtID_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtStatus_JetSubCalc", &HadronicVHtStatus_JetSubCalc, &b_HadronicVHtStatus_JetSubCalc);
   inputTree->SetBranchAddress("HdecayID_TpTpCalc", &HdecayID_TpTpCalc, &b_HdecayID_TpTpCalc);
   inputTree->SetBranchAddress("HdecayIndex_TpTpCalc", &HdecayIndex_TpTpCalc, &b_HdecayIndex_TpTpCalc);
   inputTree->SetBranchAddress("LHEweightids_MultiLepCalc", &LHEweightids_MultiLepCalc, &b_LHEweightids_MultiLepCalc);
   inputTree->SetBranchAddress("LeptonID_TpTpCalc", &LeptonID_TpTpCalc, &b_LeptonID_TpTpCalc);
   inputTree->SetBranchAddress("LeptonParentID_TpTpCalc", &LeptonParentID_TpTpCalc, &b_LeptonParentID_TpTpCalc);
   inputTree->SetBranchAddress("NewPDFids_MultiLepCalc", &NewPDFids_MultiLepCalc, &b_NewPDFids_MultiLepCalc);
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
   inputTree->SetBranchAddress("elChargeConsistent_MultiLepCalc", &elChargeConsistent_MultiLepCalc, &b_elChargeConsistent_MultiLepCalc);
   inputTree->SetBranchAddress("elCharge_MultiLepCalc", &elCharge_MultiLepCalc, &b_elCharge_MultiLepCalc);
   inputTree->SetBranchAddress("elCtfCharge_MultiLepCalc", &elCtfCharge_MultiLepCalc, &b_elCtfCharge_MultiLepCalc);
   inputTree->SetBranchAddress("elGsfCharge_MultiLepCalc", &elGsfCharge_MultiLepCalc, &b_elGsfCharge_MultiLepCalc);
   inputTree->SetBranchAddress("elIsEBEE_MultiLepCalc", &elIsEBEE_MultiLepCalc, &b_elIsEBEE_MultiLepCalc);
   /* inputTree->SetBranchAddress("elIsMVALooseIso_MultiLepCalc", &elIsMVALooseIso_MultiLepCalc, &b_elIsMVALooseIso_MultiLepCalc); */
   /* inputTree->SetBranchAddress("elIsMVALoose_MultiLepCalc", &elIsMVALoose_MultiLepCalc, &b_elIsMVALoose_MultiLepCalc); */
   /* inputTree->SetBranchAddress("elIsMVATight80_MultiLepCalc", &elIsMVATight80_MultiLepCalc, &b_elIsMVATight80_MultiLepCalc); */
   /* inputTree->SetBranchAddress("elIsMVATight90_MultiLepCalc", &elIsMVATight90_MultiLepCalc, &b_elIsMVATight90_MultiLepCalc); */
   /* inputTree->SetBranchAddress("elIsMVATightIso80_MultiLepCalc", &elIsMVATightIso80_MultiLepCalc, &b_elIsMVATightIso80_MultiLepCalc); */
   /* inputTree->SetBranchAddress("elIsMVATightIso90_MultiLepCalc", &elIsMVATightIso90_MultiLepCalc, &b_elIsMVATightIso90_MultiLepCalc); */
   inputTree->SetBranchAddress("elMHits_MultiLepCalc", &elMHits_MultiLepCalc, &b_elMHits_MultiLepCalc);
   inputTree->SetBranchAddress("elMatched_MultiLepCalc", &elMatched_MultiLepCalc, &b_elMatched_MultiLepCalc);
   inputTree->SetBranchAddress("elMother_id_MultiLepCalc", &elMother_id_MultiLepCalc, &b_elMother_id_MultiLepCalc);
   inputTree->SetBranchAddress("elMother_status_MultiLepCalc", &elMother_status_MultiLepCalc, &b_elMother_status_MultiLepCalc);
   inputTree->SetBranchAddress("elNotConversion_MultiLepCalc", &elNotConversion_MultiLepCalc, &b_elNotConversion_MultiLepCalc);
   inputTree->SetBranchAddress("elNumberOfMothers_MultiLepCalc", &elNumberOfMothers_MultiLepCalc, &b_elNumberOfMothers_MultiLepCalc);
   inputTree->SetBranchAddress("elPdgId_MultiLepCalc", &elPdgId_MultiLepCalc, &b_elPdgId_MultiLepCalc);
   inputTree->SetBranchAddress("elScPixCharge_MultiLepCalc", &elScPixCharge_MultiLepCalc, &b_elScPixCharge_MultiLepCalc);
   inputTree->SetBranchAddress("elStatus_MultiLepCalc", &elStatus_MultiLepCalc, &b_elStatus_MultiLepCalc);
   inputTree->SetBranchAddress("elVtxFitConv_MultiLepCalc", &elVtxFitConv_MultiLepCalc, &b_elVtxFitConv_MultiLepCalc);
   inputTree->SetBranchAddress("genBSLID_MultiLepCalc", &genBSLID_MultiLepCalc, &b_genBSLID_MultiLepCalc);
   inputTree->SetBranchAddress("genID_MultiLepCalc", &genID_MultiLepCalc, &b_genID_MultiLepCalc);
   inputTree->SetBranchAddress("genIndex_MultiLepCalc", &genIndex_MultiLepCalc, &b_genIndex_MultiLepCalc);
   inputTree->SetBranchAddress("genMotherID_MultiLepCalc", &genMotherID_MultiLepCalc, &b_genMotherID_MultiLepCalc);
   inputTree->SetBranchAddress("genMotherIndex_MultiLepCalc", &genMotherIndex_MultiLepCalc, &b_genMotherIndex_MultiLepCalc);
   inputTree->SetBranchAddress("genStatus_MultiLepCalc", &genStatus_MultiLepCalc, &b_genStatus_MultiLepCalc);
   inputTree->SetBranchAddress("genTtbarIdCategory_TTbarMassCalc", &genTtbarIdCategory_TTbarMassCalc, &b_genTtbarIdCategory_TTbarMassCalc);
   inputTree->SetBranchAddress("genTtbarId_TTbarMassCalc", &genTtbarId_TTbarMassCalc, &b_genTtbarId_TTbarMassCalc);
   inputTree->SetBranchAddress("maxProb_JetSubCalc", &maxProb_JetSubCalc, &b_maxProb_JetSubCalc);
   inputTree->SetBranchAddress("muCharge_MultiLepCalc", &muCharge_MultiLepCalc, &b_muCharge_MultiLepCalc);
   inputTree->SetBranchAddress("muGlobal_MultiLepCalc", &muGlobal_MultiLepCalc, &b_muGlobal_MultiLepCalc);
   inputTree->SetBranchAddress("muIsGlobalHighPt_MultiLepCalc", &muIsGlobalHighPt_MultiLepCalc, &b_muIsGlobalHighPt_MultiLepCalc);
   inputTree->SetBranchAddress("muIsLoose_MultiLepCalc", &muIsLoose_MultiLepCalc, &b_muIsLoose_MultiLepCalc);
   inputTree->SetBranchAddress("muIsMediumPrompt_MultiLepCalc", &muIsMediumPrompt_MultiLepCalc, &b_muIsMediumPrompt_MultiLepCalc);
   inputTree->SetBranchAddress("muIsMedium_MultiLepCalc", &muIsMedium_MultiLepCalc, &b_muIsMedium_MultiLepCalc);
   inputTree->SetBranchAddress("muIsMiniIsoLoose_MultiLepCalc", &muIsMiniIsoLoose_MultiLepCalc, &b_muIsMiniIsoLoose_MultiLepCalc);
   inputTree->SetBranchAddress("muIsMiniIsoMedium_MultiLepCalc", &muIsMiniIsoMedium_MultiLepCalc, &b_muIsMiniIsoMedium_MultiLepCalc);
   inputTree->SetBranchAddress("muIsMiniIsoTight_MultiLepCalc", &muIsMiniIsoTight_MultiLepCalc, &b_muIsMiniIsoTight_MultiLepCalc);
   inputTree->SetBranchAddress("muIsMiniIsoVeryTight_MultiLepCalc", &muIsMiniIsoVeryTight_MultiLepCalc, &b_muIsMiniIsoVeryTight_MultiLepCalc);
   inputTree->SetBranchAddress("muIsMvaLoose_MultiLepCalc", &muIsMvaLoose_MultiLepCalc, &b_muIsMvaLoose_MultiLepCalc);
   inputTree->SetBranchAddress("muIsMvaMedium_MultiLepCalc", &muIsMvaMedium_MultiLepCalc, &b_muIsMvaMedium_MultiLepCalc);
   inputTree->SetBranchAddress("muIsMvaTight_MultiLepCalc", &muIsMvaTight_MultiLepCalc, &b_muIsMvaTight_MultiLepCalc);
   inputTree->SetBranchAddress("muIsTight_MultiLepCalc", &muIsTight_MultiLepCalc, &b_muIsTight_MultiLepCalc);
   inputTree->SetBranchAddress("muIsTrkHighPt_MultiLepCalc", &muIsTrkHighPt_MultiLepCalc, &b_muIsTrkHighPt_MultiLepCalc);
   inputTree->SetBranchAddress("muMatched_MultiLepCalc", &muMatched_MultiLepCalc, &b_muMatched_MultiLepCalc);
   inputTree->SetBranchAddress("muMother_id_MultiLepCalc", &muMother_id_MultiLepCalc, &b_muMother_id_MultiLepCalc);
   inputTree->SetBranchAddress("muMother_status_MultiLepCalc", &muMother_status_MultiLepCalc, &b_muMother_status_MultiLepCalc);
   inputTree->SetBranchAddress("muNMatchedStations_MultiLepCalc", &muNMatchedStations_MultiLepCalc, &b_muNMatchedStations_MultiLepCalc);
   inputTree->SetBranchAddress("muNTrackerLayers_MultiLepCalc", &muNTrackerLayers_MultiLepCalc, &b_muNTrackerLayers_MultiLepCalc);
   inputTree->SetBranchAddress("muNValMuHits_MultiLepCalc", &muNValMuHits_MultiLepCalc, &b_muNValMuHits_MultiLepCalc);
   inputTree->SetBranchAddress("muNValPixelHits_MultiLepCalc", &muNValPixelHits_MultiLepCalc, &b_muNValPixelHits_MultiLepCalc);
   inputTree->SetBranchAddress("muNumberOfMothers_MultiLepCalc", &muNumberOfMothers_MultiLepCalc, &b_muNumberOfMothers_MultiLepCalc);
   inputTree->SetBranchAddress("muPdgId_MultiLepCalc", &muPdgId_MultiLepCalc, &b_muPdgId_MultiLepCalc);
   inputTree->SetBranchAddress("muStatus_MultiLepCalc", &muStatus_MultiLepCalc, &b_muStatus_MultiLepCalc);
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
   inputTree->SetBranchAddress("viSelMCTriggersEl_MultiLepCalc", &viSelMCTriggersEl_MultiLepCalc, &b_viSelMCTriggersEl_MultiLepCalc);
   inputTree->SetBranchAddress("viSelMCTriggersMu_MultiLepCalc", &viSelMCTriggersMu_MultiLepCalc, &b_viSelMCTriggersMu_MultiLepCalc);
   inputTree->SetBranchAddress("viSelTriggersEl_MultiLepCalc", &viSelTriggersEl_MultiLepCalc, &b_viSelTriggersEl_MultiLepCalc);
   inputTree->SetBranchAddress("viSelTriggersMu_MultiLepCalc", &viSelTriggersMu_MultiLepCalc, &b_viSelTriggersMu_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetBDeepCSVb_MultiLepCalc", &AK4JetBDeepCSVb_MultiLepCalc, &b_AK4JetBDeepCSVb_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetBDeepCSVbb_MultiLepCalc", &AK4JetBDeepCSVbb_MultiLepCalc, &b_AK4JetBDeepCSVbb_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetBDeepCSVc_MultiLepCalc", &AK4JetBDeepCSVc_MultiLepCalc, &b_AK4JetBDeepCSVc_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetBDeepCSVudsg_MultiLepCalc", &AK4JetBDeepCSVudsg_MultiLepCalc, &b_AK4JetBDeepCSVudsg_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetBDisc_MultiLepCalc", &AK4JetBDisc_MultiLepCalc, &b_AK4JetBDisc_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetEnergy_MultiLepCalc", &AK4JetEnergy_MultiLepCalc, &b_AK4JetEnergy_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetEta_MultiLepCalc", &AK4JetEta_MultiLepCalc, &b_AK4JetEta_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetPhi_MultiLepCalc", &AK4JetPhi_MultiLepCalc, &b_AK4JetPhi_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetPt_MultiLepCalc", &AK4JetPt_MultiLepCalc, &b_AK4JetPt_MultiLepCalc);
   inputTree->SetBranchAddress("AK8JetCSV_MultiLepCalc", &AK8JetCSV_MultiLepCalc, &b_AK8JetCSV_MultiLepCalc);
   inputTree->SetBranchAddress("AK8JetDoubleB_MultiLepCalc", &AK8JetDoubleB_MultiLepCalc, &b_AK8JetDoubleB_MultiLepCalc);
   inputTree->SetBranchAddress("AK8JetEnergy_BestCalc", &AK8JetEnergy_BestCalc, &b_AK8JetEnergy_BestCalc);
   inputTree->SetBranchAddress("AK8JetEnergy_MultiLepCalc", &AK8JetEnergy_MultiLepCalc, &b_AK8JetEnergy_MultiLepCalc);
   inputTree->SetBranchAddress("AK8JetEta_BestCalc", &AK8JetEta_BestCalc, &b_AK8JetEta_BestCalc);
   inputTree->SetBranchAddress("AK8JetEta_MultiLepCalc", &AK8JetEta_MultiLepCalc, &b_AK8JetEta_MultiLepCalc);
   inputTree->SetBranchAddress("AK8JetPhi_BestCalc", &AK8JetPhi_BestCalc, &b_AK8JetPhi_BestCalc);
   inputTree->SetBranchAddress("AK8JetPhi_MultiLepCalc", &AK8JetPhi_MultiLepCalc, &b_AK8JetPhi_MultiLepCalc);
   inputTree->SetBranchAddress("AK8JetPt_BestCalc", &AK8JetPt_BestCalc, &b_AK8JetPt_BestCalc);
   inputTree->SetBranchAddress("AK8JetPt_MultiLepCalc", &AK8JetPt_MultiLepCalc, &b_AK8JetPt_MultiLepCalc);
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
   inputTree->SetBranchAddress("LHEweights_MultiLepCalc", &LHEweights_MultiLepCalc, &b_LHEweights_MultiLepCalc);
   inputTree->SetBranchAddress("LeptonEnergy_TpTpCalc", &LeptonEnergy_TpTpCalc, &b_LeptonEnergy_TpTpCalc);
   inputTree->SetBranchAddress("LeptonEta_TpTpCalc", &LeptonEta_TpTpCalc, &b_LeptonEta_TpTpCalc);
   inputTree->SetBranchAddress("LeptonPhi_TpTpCalc", &LeptonPhi_TpTpCalc, &b_LeptonPhi_TpTpCalc);
   inputTree->SetBranchAddress("LeptonPt_TpTpCalc", &LeptonPt_TpTpCalc, &b_LeptonPt_TpTpCalc);
   inputTree->SetBranchAddress("NewPDFweightsBase_MultiLepCalc", &NewPDFweightsBase_MultiLepCalc, &b_NewPDFweightsBase_MultiLepCalc);
   inputTree->SetBranchAddress("NewPDFweights_MultiLepCalc", &NewPDFweights_MultiLepCalc, &b_NewPDFweights_MultiLepCalc);
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
   inputTree->SetBranchAddress("elAEff_MultiLepCalc", &elAEff_MultiLepCalc, &b_elAEff_MultiLepCalc);
   inputTree->SetBranchAddress("elChIso_MultiLepCalc", &elChIso_MultiLepCalc, &b_elChIso_MultiLepCalc);
   inputTree->SetBranchAddress("elD0_MultiLepCalc", &elD0_MultiLepCalc, &b_elD0_MultiLepCalc);
   inputTree->SetBranchAddress("elDEtaSCTkAtVtx_MultiLepCalc", &elDEtaSCTkAtVtx_MultiLepCalc, &b_elDEtaSCTkAtVtx_MultiLepCalc);
   inputTree->SetBranchAddress("elDPhiSCTkAtVtx_MultiLepCalc", &elDPhiSCTkAtVtx_MultiLepCalc, &b_elDPhiSCTkAtVtx_MultiLepCalc);
   inputTree->SetBranchAddress("elDR03TkSumPt_MultiLepCalc", &elDR03TkSumPt_MultiLepCalc, &b_elDR03TkSumPt_MultiLepCalc);
   inputTree->SetBranchAddress("elDZ_MultiLepCalc", &elDZ_MultiLepCalc, &b_elDZ_MultiLepCalc);
   inputTree->SetBranchAddress("elDeta_MultiLepCalc", &elDeta_MultiLepCalc, &b_elDeta_MultiLepCalc);
   inputTree->SetBranchAddress("elDphi_MultiLepCalc", &elDphi_MultiLepCalc, &b_elDphi_MultiLepCalc);
   inputTree->SetBranchAddress("elDxy_MultiLepCalc", &elDxy_MultiLepCalc, &b_elDxy_MultiLepCalc);
   inputTree->SetBranchAddress("elEcalPFClusterIso_MultiLepCalc", &elEcalPFClusterIso_MultiLepCalc, &b_elEcalPFClusterIso_MultiLepCalc);
   inputTree->SetBranchAddress("elEnergy_MultiLepCalc", &elEnergy_MultiLepCalc, &b_elEnergy_MultiLepCalc);
   inputTree->SetBranchAddress("elEtaVtx_MultiLepCalc", &elEtaVtx_MultiLepCalc, &b_elEtaVtx_MultiLepCalc);
   inputTree->SetBranchAddress("elEta_MultiLepCalc", &elEta_MultiLepCalc, &b_elEta_MultiLepCalc);
   inputTree->SetBranchAddress("elGen_Reco_dr_MultiLepCalc", &elGen_Reco_dr_MultiLepCalc, &b_elGen_Reco_dr_MultiLepCalc);
   inputTree->SetBranchAddress("elHcalPFClusterIso_MultiLepCalc", &elHcalPFClusterIso_MultiLepCalc, &b_elHcalPFClusterIso_MultiLepCalc);
   inputTree->SetBranchAddress("elHoE_MultiLepCalc", &elHoE_MultiLepCalc, &b_elHoE_MultiLepCalc);
   inputTree->SetBranchAddress("elIsLoose_MultiLepCalc", &elIsLoose_MultiLepCalc, &b_elIsLoose_MultiLepCalc);
   inputTree->SetBranchAddress("elIsMedium_MultiLepCalc", &elIsMedium_MultiLepCalc, &b_elIsMedium_MultiLepCalc);
   inputTree->SetBranchAddress("elIsTight_MultiLepCalc", &elIsTight_MultiLepCalc, &b_elIsTight_MultiLepCalc);
   inputTree->SetBranchAddress("elIsVeto_MultiLepCalc", &elIsVeto_MultiLepCalc, &b_elIsVeto_MultiLepCalc);
   /* inputTree->SetBranchAddress("elMVAValue_iso_MultiLepCalc", &elMVAValue_iso_MultiLepCalc, &b_elMVAValue_iso_MultiLepCalc); */
   /* inputTree->SetBranchAddress("elMVAValue_MultiLepCalc", &elMVAValue_MultiLepCalc, &b_elMVAValue_MultiLepCalc); */
   inputTree->SetBranchAddress("elMatchedEnergy_MultiLepCalc", &elMatchedEnergy_MultiLepCalc, &b_elMatchedEnergy_MultiLepCalc);
   inputTree->SetBranchAddress("elMatchedEta_MultiLepCalc", &elMatchedEta_MultiLepCalc, &b_elMatchedEta_MultiLepCalc);
   inputTree->SetBranchAddress("elMatchedPhi_MultiLepCalc", &elMatchedPhi_MultiLepCalc, &b_elMatchedPhi_MultiLepCalc);
   inputTree->SetBranchAddress("elMatchedPt_MultiLepCalc", &elMatchedPt_MultiLepCalc, &b_elMatchedPt_MultiLepCalc);
   inputTree->SetBranchAddress("elMiniIso_MultiLepCalc", &elMiniIso_MultiLepCalc, &b_elMiniIso_MultiLepCalc);
   inputTree->SetBranchAddress("elMother_energy_MultiLepCalc", &elMother_energy_MultiLepCalc, &b_elMother_energy_MultiLepCalc);
   inputTree->SetBranchAddress("elMother_eta_MultiLepCalc", &elMother_eta_MultiLepCalc, &b_elMother_eta_MultiLepCalc);
   inputTree->SetBranchAddress("elMother_phi_MultiLepCalc", &elMother_phi_MultiLepCalc, &b_elMother_phi_MultiLepCalc);
   inputTree->SetBranchAddress("elMother_pt_MultiLepCalc", &elMother_pt_MultiLepCalc, &b_elMother_pt_MultiLepCalc);
   inputTree->SetBranchAddress("elNhIso_MultiLepCalc", &elNhIso_MultiLepCalc, &b_elNhIso_MultiLepCalc);
   inputTree->SetBranchAddress("elOoemoop_MultiLepCalc", &elOoemoop_MultiLepCalc, &b_elOoemoop_MultiLepCalc);
   inputTree->SetBranchAddress("elPFEta_MultiLepCalc", &elPFEta_MultiLepCalc, &b_elPFEta_MultiLepCalc);
   inputTree->SetBranchAddress("elPFPhi_MultiLepCalc", &elPFPhi_MultiLepCalc, &b_elPFPhi_MultiLepCalc);
   inputTree->SetBranchAddress("elPhIso_MultiLepCalc", &elPhIso_MultiLepCalc, &b_elPhIso_MultiLepCalc);
   inputTree->SetBranchAddress("elPhiVtx_MultiLepCalc", &elPhiVtx_MultiLepCalc, &b_elPhiVtx_MultiLepCalc);
   inputTree->SetBranchAddress("elPhi_MultiLepCalc", &elPhi_MultiLepCalc, &b_elPhi_MultiLepCalc);
   inputTree->SetBranchAddress("elPt_MultiLepCalc", &elPt_MultiLepCalc, &b_elPt_MultiLepCalc);
   inputTree->SetBranchAddress("elRelIso_MultiLepCalc", &elRelIso_MultiLepCalc, &b_elRelIso_MultiLepCalc);
   inputTree->SetBranchAddress("elRhoIso_MultiLepCalc", &elRhoIso_MultiLepCalc, &b_elRhoIso_MultiLepCalc);
   inputTree->SetBranchAddress("elSCE_MultiLepCalc", &elSCE_MultiLepCalc, &b_elSCE_MultiLepCalc);
   inputTree->SetBranchAddress("elSihih_MultiLepCalc", &elSihih_MultiLepCalc, &b_elSihih_MultiLepCalc);
   inputTree->SetBranchAddress("evtWeightsMC_MultiLepCalc", &evtWeightsMC_MultiLepCalc, &b_evtWeightsMC_MultiLepCalc);
   inputTree->SetBranchAddress("genBSLEnergy_MultiLepCalc", &genBSLEnergy_MultiLepCalc, &b_genBSLEnergy_MultiLepCalc);
   inputTree->SetBranchAddress("genBSLEta_MultiLepCalc", &genBSLEta_MultiLepCalc, &b_genBSLEta_MultiLepCalc);
   inputTree->SetBranchAddress("genBSLPhi_MultiLepCalc", &genBSLPhi_MultiLepCalc, &b_genBSLPhi_MultiLepCalc);
   inputTree->SetBranchAddress("genBSLPt_MultiLepCalc", &genBSLPt_MultiLepCalc, &b_genBSLPt_MultiLepCalc);
   inputTree->SetBranchAddress("genEnergy_MultiLepCalc", &genEnergy_MultiLepCalc, &b_genEnergy_MultiLepCalc);
   inputTree->SetBranchAddress("genEta_MultiLepCalc", &genEta_MultiLepCalc, &b_genEta_MultiLepCalc);
   inputTree->SetBranchAddress("genJetEnergy_MultiLepCalc", &genJetEnergy_MultiLepCalc, &b_genJetEnergy_MultiLepCalc);
   inputTree->SetBranchAddress("genJetEta_MultiLepCalc", &genJetEta_MultiLepCalc, &b_genJetEta_MultiLepCalc);
   inputTree->SetBranchAddress("genJetPhi_MultiLepCalc", &genJetPhi_MultiLepCalc, &b_genJetPhi_MultiLepCalc);
   inputTree->SetBranchAddress("genJetPt_MultiLepCalc", &genJetPt_MultiLepCalc, &b_genJetPt_MultiLepCalc);
   inputTree->SetBranchAddress("genPhi_MultiLepCalc", &genPhi_MultiLepCalc, &b_genPhi_MultiLepCalc);
   inputTree->SetBranchAddress("genPt_MultiLepCalc", &genPt_MultiLepCalc, &b_genPt_MultiLepCalc);
   inputTree->SetBranchAddress("muChIso_MultiLepCalc", &muChIso_MultiLepCalc, &b_muChIso_MultiLepCalc);
   inputTree->SetBranchAddress("muChi2_MultiLepCalc", &muChi2_MultiLepCalc, &b_muChi2_MultiLepCalc);
   inputTree->SetBranchAddress("muDxy_MultiLepCalc", &muDxy_MultiLepCalc, &b_muDxy_MultiLepCalc);
   inputTree->SetBranchAddress("muDz_MultiLepCalc", &muDz_MultiLepCalc, &b_muDz_MultiLepCalc);
   inputTree->SetBranchAddress("muEnergy_MultiLepCalc", &muEnergy_MultiLepCalc, &b_muEnergy_MultiLepCalc);
   inputTree->SetBranchAddress("muEta_MultiLepCalc", &muEta_MultiLepCalc, &b_muEta_MultiLepCalc);
   inputTree->SetBranchAddress("muGIso_MultiLepCalc", &muGIso_MultiLepCalc, &b_muGIso_MultiLepCalc);
   inputTree->SetBranchAddress("muGen_Reco_dr_MultiLepCalc", &muGen_Reco_dr_MultiLepCalc, &b_muGen_Reco_dr_MultiLepCalc);
   inputTree->SetBranchAddress("muInnerEta_MultiLepCalc", &muInnerEta_MultiLepCalc, &b_muInnerEta_MultiLepCalc);
   inputTree->SetBranchAddress("muInnerPhi_MultiLepCalc", &muInnerPhi_MultiLepCalc, &b_muInnerPhi_MultiLepCalc);
   inputTree->SetBranchAddress("muInnerPt_MultiLepCalc", &muInnerPt_MultiLepCalc, &b_muInnerPt_MultiLepCalc);
   inputTree->SetBranchAddress("muMatchedEnergy_MultiLepCalc", &muMatchedEnergy_MultiLepCalc, &b_muMatchedEnergy_MultiLepCalc);
   inputTree->SetBranchAddress("muMatchedEta_MultiLepCalc", &muMatchedEta_MultiLepCalc, &b_muMatchedEta_MultiLepCalc);
   inputTree->SetBranchAddress("muMatchedPhi_MultiLepCalc", &muMatchedPhi_MultiLepCalc, &b_muMatchedPhi_MultiLepCalc);
   inputTree->SetBranchAddress("muMatchedPt_MultiLepCalc", &muMatchedPt_MultiLepCalc, &b_muMatchedPt_MultiLepCalc);
   inputTree->SetBranchAddress("muMiniIsoDB_MultiLepCalc", &muMiniIsoDB_MultiLepCalc, &b_muMiniIsoDB_MultiLepCalc);
   inputTree->SetBranchAddress("muMiniIso_MultiLepCalc", &muMiniIso_MultiLepCalc, &b_muMiniIso_MultiLepCalc);
   inputTree->SetBranchAddress("muMother_energy_MultiLepCalc", &muMother_energy_MultiLepCalc, &b_muMother_energy_MultiLepCalc);
   inputTree->SetBranchAddress("muMother_eta_MultiLepCalc", &muMother_eta_MultiLepCalc, &b_muMother_eta_MultiLepCalc);
   inputTree->SetBranchAddress("muMother_phi_MultiLepCalc", &muMother_phi_MultiLepCalc, &b_muMother_phi_MultiLepCalc);
   inputTree->SetBranchAddress("muMother_pt_MultiLepCalc", &muMother_pt_MultiLepCalc, &b_muMother_pt_MultiLepCalc);
   inputTree->SetBranchAddress("muNhIso_MultiLepCalc", &muNhIso_MultiLepCalc, &b_muNhIso_MultiLepCalc);
   inputTree->SetBranchAddress("muPhi_MultiLepCalc", &muPhi_MultiLepCalc, &b_muPhi_MultiLepCalc);
   inputTree->SetBranchAddress("muPt_MultiLepCalc", &muPt_MultiLepCalc, &b_muPt_MultiLepCalc);
   inputTree->SetBranchAddress("muPuIso_MultiLepCalc", &muPuIso_MultiLepCalc, &b_muPuIso_MultiLepCalc);
   inputTree->SetBranchAddress("muRelIso_MultiLepCalc", &muRelIso_MultiLepCalc, &b_muRelIso_MultiLepCalc);
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
   inputTree->SetBranchAddress("vsSelMCTriggersEl_MultiLepCalc", &vsSelMCTriggersEl_MultiLepCalc, &b_vsSelMCTriggersEl_MultiLepCalc);
   inputTree->SetBranchAddress("vsSelMCTriggersMu_MultiLepCalc", &vsSelMCTriggersMu_MultiLepCalc, &b_vsSelMCTriggersMu_MultiLepCalc);
   inputTree->SetBranchAddress("vsSelTriggersEl_MultiLepCalc", &vsSelTriggersEl_MultiLepCalc, &b_vsSelTriggersEl_MultiLepCalc);
   inputTree->SetBranchAddress("vsSelTriggersMu_MultiLepCalc", &vsSelTriggersMu_MultiLepCalc, &b_vsSelTriggersMu_MultiLepCalc);
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
{ 1.768e-01,  4.107e+00,  3.478e+00,  2.368e+00,  1.552e+00,  1.556e+00,  1.295e+00,  1.254e+00,  6.272e-01,  1.463e+00,  1.473e+00,  1.480e+00,  1.325e+00,  1.167e+00,  1.079e+00,  1.053e+00,  1.087e+00,  1.126e+00,  1.163e+00,  1.189e+00,  1.209e+00,  1.236e+00,  1.262e+00,  1.271e+00,  1.275e+00,  1.273e+00,  1.272e+00,  1.265e+00,  1.274e+00,  1.250e+00,  1.225e+00,  1.171e+00,  1.109e+00,  1.040e+00,  9.681e-01,  9.124e-01,  8.668e-01,  8.337e-01,  7.864e-01,  7.501e-01,  7.585e-01,  7.938e-01,  8.590e-01,  9.606e-01,  1.090e+00,  1.254e+00,  1.419e+00,  1.496e+00,  1.530e+00,  1.464e+00,  1.337e+00,  1.156e+00,  9.501e-01,  7.507e-01,  5.714e-01,  4.116e-01,  2.893e-01,  1.983e-01,  1.380e-01,  9.645e-02,  6.933e-02,  5.061e-02,  3.844e-02,  3.011e-02,  2.407e-02,  1.715e-02,  1.241e-02,  1.070e-02,  9.663e-03,  8.949e-03,  8.231e-03,  8.094e-03,  7.946e-03,  7.974e-03,  6.490e-03,  5.392e-03,  5.367e-03,  5.789e-03,  5.517e-03,  6.496e-03,  6.447e-03,  6.003e-03,  7.472e-03,  5.167e-03,  4.724e-03,  6.645e-03,  3.867e-03,  6.246e-03,  5.034e-03,  5.474e-03,  1.348e-02,  4.113e-03,  9.943e-04,  2.976e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.927e-01,  5.011e+00,  3.624e+00,  2.585e+00,  1.535e+00,  1.512e+00,  1.265e+00,  1.241e+00,  6.101e-01,  1.460e+00,  1.474e+00,  1.481e+00,  1.338e+00,  1.168e+00,  1.077e+00,  1.056e+00,  1.087e+00,  1.126e+00,  1.165e+00,  1.187e+00,  1.210e+00,  1.238e+00,  1.257e+00,  1.270e+00,  1.271e+00,  1.270e+00,  1.271e+00,  1.263e+00,  1.275e+00,  1.253e+00,  1.224e+00,  1.170e+00,  1.112e+00,  1.039e+00,  9.682e-01,  9.138e-01,  8.670e-01,  8.355e-01,  7.879e-01,  7.524e-01,  7.599e-01,  7.932e-01,  8.584e-01,  9.590e-01,  1.097e+00,  1.263e+00,  1.421e+00,  1.479e+00,  1.529e+00,  1.465e+00,  1.335e+00,  1.150e+00,  9.494e-01,  7.483e-01,  5.690e-01,  4.105e-01,  2.896e-01,  2.000e-01,  1.376e-01,  9.723e-02,  6.903e-02,  5.082e-02,  3.845e-02,  2.976e-02,  2.415e-02,  1.709e-02,  1.252e-02,  1.073e-02,  9.586e-03,  8.949e-03,  8.293e-03,  7.967e-03,  8.087e-03,  8.015e-03,  6.300e-03,  5.234e-03,  5.574e-03,  5.610e-03,  5.790e-03,  5.574e-03,  5.847e-03,  6.031e-03,  6.626e-03,  5.603e-03,  4.217e-03,  4.281e-03,  6.041e-03,  4.455e-03,  4.189e-03,  3.470e-03,  2.564e-03,  1.956e-03,  1.576e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 2.036e-01,  3.719e+00,  3.315e+00,  2.794e+00,  1.757e+00,  1.489e+00,  1.262e+00,  1.287e+00,  6.035e-01,  1.444e+00,  1.509e+00,  1.485e+00,  1.336e+00,  1.165e+00,  1.081e+00,  1.048e+00,  1.081e+00,  1.126e+00,  1.165e+00,  1.194e+00,  1.217e+00,  1.240e+00,  1.263e+00,  1.265e+00,  1.272e+00,  1.269e+00,  1.272e+00,  1.263e+00,  1.270e+00,  1.250e+00,  1.225e+00,  1.169e+00,  1.110e+00,  1.041e+00,  9.702e-01,  9.123e-01,  8.658e-01,  8.345e-01,  7.881e-01,  7.513e-01,  7.580e-01,  7.945e-01,  8.608e-01,  9.598e-01,  1.097e+00,  1.258e+00,  1.421e+00,  1.495e+00,  1.527e+00,  1.456e+00,  1.334e+00,  1.154e+00,  9.500e-01,  7.479e-01,  5.703e-01,  4.109e-01,  2.894e-01,  1.988e-01,  1.375e-01,  9.674e-02,  6.941e-02,  5.087e-02,  3.824e-02,  2.989e-02,  2.419e-02,  1.714e-02,  1.251e-02,  1.072e-02,  9.610e-03,  8.944e-03,  8.300e-03,  8.145e-03,  7.606e-03,  7.887e-03,  6.196e-03,  5.502e-03,  5.342e-03,  5.697e-03,  6.310e-03,  5.414e-03,  6.132e-03,  7.429e-03,  6.981e-03,  4.787e-03,  3.756e-03,  4.929e-03,  4.250e-03,  3.806e-03,  5.725e-03,  3.557e-03,  1.095e-02,  6.682e-03,  4.039e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.925e-01,  6.204e+00,  4.276e+00,  2.532e+00,  1.764e+00,  1.482e+00,  1.395e+00,  1.478e+00,  6.245e-01,  1.488e+00,  1.518e+00,  1.483e+00,  1.299e+00,  1.175e+00,  1.079e+00,  1.047e+00,  1.069e+00,  1.132e+00,  1.165e+00,  1.186e+00,  1.214e+00,  1.235e+00,  1.261e+00,  1.275e+00,  1.276e+00,  1.270e+00,  1.272e+00,  1.256e+00,  1.276e+00,  1.256e+00,  1.220e+00,  1.168e+00,  1.111e+00,  1.042e+00,  9.694e-01,  9.133e-01,  8.702e-01,  8.306e-01,  7.877e-01,  7.505e-01,  7.537e-01,  8.003e-01,  8.602e-01,  9.598e-01,  1.098e+00,  1.255e+00,  1.421e+00,  1.484e+00,  1.528e+00,  1.457e+00,  1.349e+00,  1.157e+00,  9.466e-01,  7.544e-01,  5.640e-01,  4.091e-01,  2.895e-01,  2.006e-01,  1.374e-01,  9.694e-02,  6.937e-02,  5.080e-02,  3.882e-02,  2.971e-02,  2.425e-02,  1.701e-02,  1.242e-02,  1.096e-02,  9.670e-03,  8.692e-03,  8.242e-03,  8.000e-03,  8.012e-03,  8.072e-03,  5.896e-03,  5.085e-03,  5.798e-03,  5.538e-03,  5.657e-03,  5.095e-03,  6.150e-03,  5.407e-03,  7.090e-03,  5.105e-03,  2.728e-03,  3.664e-03,  8.561e-03,  5.411e-03,  5.088e-03,  6.323e-03,  3.893e-03,  7.918e-04,  7.179e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 5.202e-04,  1.732e-01,  6.524e-02,  1.051e-01,  7.782e-02,  7.074e-02,  5.636e-02,  1.578e-01,  1.041e-01,  2.976e-01,  4.844e-01,  8.430e-01,  6.433e-01,  6.391e-01,  6.185e-01,  6.598e-01,  7.822e-01,  9.093e-01,  1.069e+00,  1.086e+00,  1.211e+00,  1.252e+00,  1.298e+00,  1.322e+00,  1.355e+00,  1.372e+00,  1.174e+00,  1.383e+00,  1.413e+00,  1.396e+00,  1.341e+00,  1.287e+00,  1.197e+00,  1.112e+00,  1.062e+00,  1.003e+00,  9.522e-01,  9.235e-01,  8.274e-01,  8.367e-01,  7.672e-01,  8.866e-01,  9.070e-01,  1.072e+00,  1.230e+00,  1.408e+00,  1.541e+00,  1.679e+00,  1.737e+00,  1.642e+00,  1.427e+00,  1.265e+00,  1.031e+00,  8.213e-01,  6.221e-01,  4.057e-01,  3.109e-01,  2.122e-01,  1.497e-01,  9.110e-02,  7.505e-02,  5.398e-02,  4.104e-02,  2.899e-02,  2.612e-02,  1.903e-02,  1.301e-02,  1.146e-02,  1.055e-02,  1.017e-02,  9.379e-03,  7.285e-03,  1.100e-03,  8.660e-03,  4.736e-04,  6.339e-03,  5.531e-03,  5.185e-03,  2.455e-04,  1.158e-04,  9.824e-03,  1.564e-03,  7.432e-03,  2.421e-03,  1.253e-02,  4.023e-03,  0.000e+00,  3.241e-03,  1.472e-05,  0.000e+00,  7.774e-04,  0.000e+00,  0.000e+00,  1.716e-04,  0.000e+00,  0.000e+00,  3.470e-05,  1.996e-05,  0.000e+00,  1.942e-07,  0.000e+00,  }, // DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 2.500e-01,  3.492e+00,  4.860e+00,  4.056e+00,  1.567e+00,  1.494e+00,  1.133e+00,  1.246e+00,  7.152e-01,  1.517e+00,  1.398e+00,  1.490e+00,  1.296e+00,  1.144e+00,  1.087e+00,  1.079e+00,  1.105e+00,  1.119e+00,  1.147e+00,  1.176e+00,  1.207e+00,  1.223e+00,  1.251e+00,  1.276e+00,  1.283e+00,  1.282e+00,  1.271e+00,  1.286e+00,  1.273e+00,  1.237e+00,  1.246e+00,  1.154e+00,  1.122e+00,  1.047e+00,  9.742e-01,  9.220e-01,  8.832e-01,  8.296e-01,  7.859e-01,  7.315e-01,  7.527e-01,  7.973e-01,  8.528e-01,  9.597e-01,  1.111e+00,  1.247e+00,  1.429e+00,  1.496e+00,  1.505e+00,  1.470e+00,  1.311e+00,  1.135e+00,  9.619e-01,  7.553e-01,  5.713e-01,  4.166e-01,  2.828e-01,  1.963e-01,  1.396e-01,  9.582e-02,  6.930e-02,  5.052e-02,  3.820e-02,  3.023e-02,  2.362e-02,  1.661e-02,  1.264e-02,  1.092e-02,  9.747e-03,  8.866e-03,  8.610e-03,  8.709e-03,  8.045e-03,  7.947e-03,  6.080e-03,  4.973e-03,  4.198e-03,  4.600e-03,  4.225e-03,  6.136e-03,  6.391e-03,  4.917e-03,  6.447e-03,  3.150e-03,  2.717e-03,  0.000e+00,  3.336e-03,  2.109e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.196e-01,  3.842e+00,  2.673e+00,  2.114e+00,  1.391e+00,  1.689e+00,  9.939e-01,  1.172e+00,  6.387e-01,  1.589e+00,  1.447e+00,  1.528e+00,  1.426e+00,  1.172e+00,  1.126e+00,  1.049e+00,  1.076e+00,  1.127e+00,  1.194e+00,  1.170e+00,  1.208e+00,  1.247e+00,  1.263e+00,  1.271e+00,  1.291e+00,  1.281e+00,  1.271e+00,  1.269e+00,  1.277e+00,  1.255e+00,  1.208e+00,  1.175e+00,  1.121e+00,  1.037e+00,  9.857e-01,  8.943e-01,  8.604e-01,  8.540e-01,  7.981e-01,  7.348e-01,  7.543e-01,  7.774e-01,  8.580e-01,  9.335e-01,  1.098e+00,  1.266e+00,  1.443e+00,  1.484e+00,  1.544e+00,  1.459e+00,  1.309e+00,  1.143e+00,  9.758e-01,  7.455e-01,  5.578e-01,  3.962e-01,  2.868e-01,  1.953e-01,  1.395e-01,  9.678e-02,  7.154e-02,  5.207e-02,  3.726e-02,  2.936e-02,  2.574e-02,  1.781e-02,  1.253e-02,  1.115e-02,  8.425e-03,  8.174e-03,  7.346e-03,  7.581e-03,  8.104e-03,  9.333e-03,  4.828e-03,  4.895e-03,  5.668e-03,  5.061e-03,  5.312e-03,  3.909e-03,  4.922e-03,  4.637e-03,  5.319e-03,  1.386e-02,  2.989e-03,  2.880e-03,  3.670e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTWJetsToQQ_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8_hadd.root
{ 1.957e-01,  4.016e+00,  3.198e+00,  2.581e+00,  1.609e+00,  1.488e+00,  1.311e+00,  1.285e+00,  6.157e-01,  1.497e+00,  1.491e+00,  1.485e+00,  1.332e+00,  1.162e+00,  1.082e+00,  1.050e+00,  1.082e+00,  1.129e+00,  1.164e+00,  1.188e+00,  1.211e+00,  1.238e+00,  1.259e+00,  1.273e+00,  1.270e+00,  1.266e+00,  1.273e+00,  1.267e+00,  1.274e+00,  1.253e+00,  1.224e+00,  1.167e+00,  1.111e+00,  1.039e+00,  9.689e-01,  9.114e-01,  8.672e-01,  8.349e-01,  7.884e-01,  7.513e-01,  7.584e-01,  7.940e-01,  8.597e-01,  9.612e-01,  1.096e+00,  1.257e+00,  1.422e+00,  1.502e+00,  1.528e+00,  1.468e+00,  1.335e+00,  1.156e+00,  9.493e-01,  7.492e-01,  5.713e-01,  4.111e-01,  2.901e-01,  1.981e-01,  1.378e-01,  9.664e-02,  6.912e-02,  5.065e-02,  3.833e-02,  2.985e-02,  2.404e-02,  1.705e-02,  1.252e-02,  1.077e-02,  9.567e-03,  8.751e-03,  8.326e-03,  7.909e-03,  7.754e-03,  7.791e-03,  6.346e-03,  5.424e-03,  5.444e-03,  5.321e-03,  6.079e-03,  5.542e-03,  6.050e-03,  6.164e-03,  6.122e-03,  4.578e-03,  4.423e-03,  4.051e-03,  4.979e-03,  4.005e-03,  4.603e-03,  3.813e-03,  2.642e-03,  6.447e-03,  1.559e-03,  4.665e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT1000to1500_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.749e-01,  4.172e+00,  3.462e+00,  2.677e+00,  1.657e+00,  1.475e+00,  1.255e+00,  1.247e+00,  6.001e-01,  1.423e+00,  1.498e+00,  1.492e+00,  1.325e+00,  1.164e+00,  1.082e+00,  1.052e+00,  1.083e+00,  1.127e+00,  1.163e+00,  1.191e+00,  1.212e+00,  1.241e+00,  1.255e+00,  1.270e+00,  1.274e+00,  1.273e+00,  1.272e+00,  1.268e+00,  1.278e+00,  1.250e+00,  1.223e+00,  1.171e+00,  1.111e+00,  1.036e+00,  9.706e-01,  9.105e-01,  8.681e-01,  8.332e-01,  7.863e-01,  7.510e-01,  7.603e-01,  7.926e-01,  8.584e-01,  9.578e-01,  1.096e+00,  1.256e+00,  1.416e+00,  1.494e+00,  1.526e+00,  1.468e+00,  1.336e+00,  1.152e+00,  9.529e-01,  7.485e-01,  5.702e-01,  4.122e-01,  2.880e-01,  1.984e-01,  1.374e-01,  9.694e-02,  6.917e-02,  5.072e-02,  3.858e-02,  2.990e-02,  2.407e-02,  1.711e-02,  1.255e-02,  1.081e-02,  9.625e-03,  8.906e-03,  8.153e-03,  8.132e-03,  7.846e-03,  7.748e-03,  6.233e-03,  5.267e-03,  5.609e-03,  6.071e-03,  6.121e-03,  6.164e-03,  6.168e-03,  6.767e-03,  6.302e-03,  3.970e-03,  5.435e-03,  5.004e-03,  3.543e-03,  5.497e-03,  4.211e-03,  2.944e-03,  3.626e-03,  2.949e-03,  5.348e-03,  3.201e-03,  9.489e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT1500to2000_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.673e-01,  4.002e+00,  3.617e+00,  2.548e+00,  1.509e+00,  1.493e+00,  1.296e+00,  1.240e+00,  6.044e-01,  1.455e+00,  1.499e+00,  1.488e+00,  1.340e+00,  1.174e+00,  1.086e+00,  1.052e+00,  1.083e+00,  1.128e+00,  1.168e+00,  1.181e+00,  1.205e+00,  1.236e+00,  1.259e+00,  1.272e+00,  1.271e+00,  1.272e+00,  1.271e+00,  1.267e+00,  1.278e+00,  1.251e+00,  1.219e+00,  1.164e+00,  1.109e+00,  1.038e+00,  9.690e-01,  9.157e-01,  8.645e-01,  8.360e-01,  7.876e-01,  7.518e-01,  7.621e-01,  7.940e-01,  8.594e-01,  9.634e-01,  1.096e+00,  1.255e+00,  1.424e+00,  1.511e+00,  1.535e+00,  1.457e+00,  1.342e+00,  1.153e+00,  9.464e-01,  7.538e-01,  5.673e-01,  4.094e-01,  2.882e-01,  1.995e-01,  1.377e-01,  9.630e-02,  6.900e-02,  5.090e-02,  3.856e-02,  2.996e-02,  2.428e-02,  1.692e-02,  1.250e-02,  1.082e-02,  9.818e-03,  8.680e-03,  8.325e-03,  8.296e-03,  7.673e-03,  7.873e-03,  6.039e-03,  5.129e-03,  5.625e-03,  5.495e-03,  6.660e-03,  5.474e-03,  5.696e-03,  6.031e-03,  5.399e-03,  4.689e-03,  3.380e-03,  4.749e-03,  6.917e-03,  1.020e-02,  2.398e-03,  2.980e-03,  2.447e-03,  4.479e-03,  1.353e-03,  5.401e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT2000toInf_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.810e-01,  3.970e+00,  3.636e+00,  2.556e+00,  1.633e+00,  1.550e+00,  1.272e+00,  1.241e+00,  6.184e-01,  1.457e+00,  1.490e+00,  1.488e+00,  1.334e+00,  1.168e+00,  1.080e+00,  1.055e+00,  1.082e+00,  1.129e+00,  1.166e+00,  1.189e+00,  1.212e+00,  1.238e+00,  1.260e+00,  1.270e+00,  1.273e+00,  1.271e+00,  1.271e+00,  1.266e+00,  1.274e+00,  1.253e+00,  1.225e+00,  1.171e+00,  1.109e+00,  1.038e+00,  9.680e-01,  9.115e-01,  8.658e-01,  8.345e-01,  7.894e-01,  7.502e-01,  7.581e-01,  7.933e-01,  8.595e-01,  9.600e-01,  1.093e+00,  1.256e+00,  1.420e+00,  1.494e+00,  1.527e+00,  1.463e+00,  1.340e+00,  1.153e+00,  9.532e-01,  7.507e-01,  5.697e-01,  4.092e-01,  2.900e-01,  1.986e-01,  1.378e-01,  9.651e-02,  6.932e-02,  5.073e-02,  3.841e-02,  2.996e-02,  2.409e-02,  1.707e-02,  1.250e-02,  1.073e-02,  9.622e-03,  8.778e-03,  8.259e-03,  8.007e-03,  7.893e-03,  7.876e-03,  6.407e-03,  5.402e-03,  5.506e-03,  5.545e-03,  5.858e-03,  6.293e-03,  6.013e-03,  5.799e-03,  6.706e-03,  4.849e-03,  4.076e-03,  4.423e-03,  4.340e-03,  4.844e-03,  5.114e-03,  4.313e-03,  4.957e-03,  3.024e-03,  1.828e-03,  5.471e-03,  9.730e-03,  9.519e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT200to300_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.860e-01,  4.053e+00,  3.613e+00,  2.537e+00,  1.578e+00,  1.495e+00,  1.297e+00,  1.279e+00,  6.177e-01,  1.453e+00,  1.500e+00,  1.482e+00,  1.327e+00,  1.166e+00,  1.077e+00,  1.055e+00,  1.082e+00,  1.128e+00,  1.165e+00,  1.188e+00,  1.212e+00,  1.239e+00,  1.261e+00,  1.269e+00,  1.272e+00,  1.271e+00,  1.272e+00,  1.266e+00,  1.275e+00,  1.252e+00,  1.221e+00,  1.170e+00,  1.110e+00,  1.037e+00,  9.683e-01,  9.119e-01,  8.668e-01,  8.343e-01,  7.886e-01,  7.514e-01,  7.580e-01,  7.928e-01,  8.605e-01,  9.609e-01,  1.093e+00,  1.258e+00,  1.421e+00,  1.493e+00,  1.529e+00,  1.463e+00,  1.337e+00,  1.152e+00,  9.530e-01,  7.506e-01,  5.697e-01,  4.109e-01,  2.901e-01,  1.987e-01,  1.375e-01,  9.669e-02,  6.936e-02,  5.089e-02,  3.840e-02,  2.999e-02,  2.406e-02,  1.711e-02,  1.249e-02,  1.072e-02,  9.602e-03,  8.792e-03,  8.250e-03,  8.079e-03,  7.874e-03,  7.887e-03,  6.207e-03,  5.379e-03,  5.522e-03,  5.680e-03,  5.723e-03,  5.939e-03,  6.301e-03,  6.390e-03,  6.083e-03,  4.925e-03,  4.178e-03,  4.215e-03,  3.954e-03,  5.039e-03,  4.080e-03,  3.925e-03,  2.676e-03,  2.857e-03,  1.727e-03,  2.067e-03,  9.805e-03,  2.878e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT300to500_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.834e-01,  3.830e+00,  3.431e+00,  2.566e+00,  1.607e+00,  1.516e+00,  1.322e+00,  1.286e+00,  6.178e-01,  1.451e+00,  1.510e+00,  1.489e+00,  1.334e+00,  1.166e+00,  1.079e+00,  1.051e+00,  1.080e+00,  1.129e+00,  1.168e+00,  1.188e+00,  1.212e+00,  1.236e+00,  1.259e+00,  1.270e+00,  1.275e+00,  1.273e+00,  1.272e+00,  1.266e+00,  1.275e+00,  1.251e+00,  1.222e+00,  1.170e+00,  1.108e+00,  1.038e+00,  9.692e-01,  9.114e-01,  8.675e-01,  8.339e-01,  7.873e-01,  7.504e-01,  7.585e-01,  7.925e-01,  8.606e-01,  9.600e-01,  1.097e+00,  1.258e+00,  1.417e+00,  1.495e+00,  1.532e+00,  1.461e+00,  1.339e+00,  1.155e+00,  9.511e-01,  7.497e-01,  5.697e-01,  4.110e-01,  2.903e-01,  1.985e-01,  1.376e-01,  9.636e-02,  6.920e-02,  5.083e-02,  3.837e-02,  2.997e-02,  2.407e-02,  1.708e-02,  1.248e-02,  1.079e-02,  9.597e-03,  8.774e-03,  8.342e-03,  8.039e-03,  7.871e-03,  7.898e-03,  6.371e-03,  5.334e-03,  5.530e-03,  5.678e-03,  5.844e-03,  6.165e-03,  6.247e-03,  6.308e-03,  6.138e-03,  5.205e-03,  4.022e-03,  4.512e-03,  3.981e-03,  4.461e-03,  3.549e-03,  3.699e-03,  3.210e-03,  3.590e-03,  2.367e-03,  1.732e-03,  4.620e-03,  2.712e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT500to700_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.879e-01,  3.816e+00,  3.218e+00,  2.454e+00,  1.641e+00,  1.494e+00,  1.304e+00,  1.240e+00,  6.218e-01,  1.457e+00,  1.500e+00,  1.489e+00,  1.328e+00,  1.166e+00,  1.081e+00,  1.054e+00,  1.079e+00,  1.130e+00,  1.166e+00,  1.190e+00,  1.211e+00,  1.241e+00,  1.258e+00,  1.270e+00,  1.270e+00,  1.272e+00,  1.273e+00,  1.266e+00,  1.275e+00,  1.250e+00,  1.221e+00,  1.170e+00,  1.110e+00,  1.038e+00,  9.694e-01,  9.114e-01,  8.672e-01,  8.367e-01,  7.879e-01,  7.498e-01,  7.579e-01,  7.935e-01,  8.617e-01,  9.591e-01,  1.097e+00,  1.255e+00,  1.422e+00,  1.495e+00,  1.530e+00,  1.462e+00,  1.341e+00,  1.155e+00,  9.510e-01,  7.488e-01,  5.689e-01,  4.108e-01,  2.892e-01,  1.990e-01,  1.375e-01,  9.631e-02,  6.932e-02,  5.092e-02,  3.836e-02,  2.995e-02,  2.401e-02,  1.709e-02,  1.245e-02,  1.070e-02,  9.656e-03,  8.801e-03,  8.344e-03,  8.060e-03,  7.939e-03,  7.699e-03,  6.254e-03,  5.278e-03,  5.482e-03,  5.668e-03,  5.810e-03,  6.086e-03,  6.095e-03,  6.078e-03,  6.937e-03,  5.137e-03,  4.083e-03,  4.345e-03,  3.657e-03,  4.376e-03,  4.655e-03,  3.409e-03,  2.351e-03,  2.758e-03,  1.445e-03,  1.081e-03,  2.564e-03,  1.505e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT700to1000_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.803e-01,  5.928e+00,  2.750e+00,  2.419e+00,  1.593e+00,  1.440e+00,  1.337e+00,  1.229e+00,  6.134e-01,  1.448e+00,  1.581e+00,  1.476e+00,  1.342e+00,  1.168e+00,  1.082e+00,  1.055e+00,  1.092e+00,  1.129e+00,  1.163e+00,  1.186e+00,  1.217e+00,  1.233e+00,  1.255e+00,  1.266e+00,  1.277e+00,  1.273e+00,  1.272e+00,  1.266e+00,  1.271e+00,  1.248e+00,  1.223e+00,  1.169e+00,  1.115e+00,  1.039e+00,  9.698e-01,  9.093e-01,  8.651e-01,  8.358e-01,  7.850e-01,  7.509e-01,  7.577e-01,  7.946e-01,  8.607e-01,  9.629e-01,  1.096e+00,  1.257e+00,  1.420e+00,  1.510e+00,  1.519e+00,  1.460e+00,  1.342e+00,  1.159e+00,  9.444e-01,  7.466e-01,  5.680e-01,  4.106e-01,  2.915e-01,  1.987e-01,  1.379e-01,  9.649e-02,  6.923e-02,  5.152e-02,  3.845e-02,  2.990e-02,  2.394e-02,  1.698e-02,  1.234e-02,  1.050e-02,  9.671e-03,  8.746e-03,  8.200e-03,  8.309e-03,  7.932e-03,  7.767e-03,  6.096e-03,  5.745e-03,  5.503e-03,  6.036e-03,  6.486e-03,  5.339e-03,  7.313e-03,  5.293e-03,  9.484e-03,  4.413e-03,  6.662e-03,  3.851e-03,  4.908e-03,  3.878e-03,  4.861e-03,  1.510e-03,  3.720e-03,  1.135e-03,  1.372e-03,  8.212e-04,  0.000e+00,  2.857e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_s-channel_antitop_leptonDecays_13TeV-PSweights_powheg-pythia_hadd.root
{ 1.746e-01,  3.830e+00,  3.553e+00,  2.403e+00,  1.599e+00,  1.559e+00,  1.322e+00,  1.260e+00,  6.069e-01,  1.461e+00,  1.501e+00,  1.472e+00,  1.320e+00,  1.158e+00,  1.080e+00,  1.055e+00,  1.084e+00,  1.121e+00,  1.171e+00,  1.191e+00,  1.209e+00,  1.237e+00,  1.260e+00,  1.273e+00,  1.272e+00,  1.267e+00,  1.272e+00,  1.269e+00,  1.271e+00,  1.252e+00,  1.223e+00,  1.171e+00,  1.111e+00,  1.044e+00,  9.695e-01,  9.127e-01,  8.670e-01,  8.365e-01,  7.866e-01,  7.524e-01,  7.567e-01,  7.963e-01,  8.596e-01,  9.551e-01,  1.093e+00,  1.260e+00,  1.425e+00,  1.487e+00,  1.521e+00,  1.463e+00,  1.343e+00,  1.156e+00,  9.445e-01,  7.558e-01,  5.707e-01,  4.089e-01,  2.878e-01,  1.986e-01,  1.374e-01,  9.582e-02,  6.921e-02,  5.063e-02,  3.820e-02,  3.022e-02,  2.411e-02,  1.709e-02,  1.256e-02,  1.082e-02,  9.682e-03,  8.739e-03,  8.479e-03,  8.119e-03,  8.084e-03,  7.948e-03,  6.203e-03,  5.410e-03,  5.892e-03,  5.502e-03,  5.216e-03,  5.742e-03,  6.863e-03,  6.583e-03,  7.384e-03,  6.367e-03,  4.829e-03,  4.283e-03,  3.582e-03,  5.176e-03,  3.785e-03,  2.822e-03,  8.689e-03,  2.651e-03,  3.204e-03,  9.591e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_s-channel_top_leptonDecays_13TeV-PSweights_powheg-pythia_hadd.root
{ 1.852e-01,  3.872e+00,  3.527e+00,  2.555e+00,  1.599e+00,  1.529e+00,  1.308e+00,  1.270e+00,  6.120e-01,  1.461e+00,  1.499e+00,  1.481e+00,  1.335e+00,  1.168e+00,  1.079e+00,  1.051e+00,  1.078e+00,  1.128e+00,  1.167e+00,  1.190e+00,  1.212e+00,  1.238e+00,  1.260e+00,  1.272e+00,  1.272e+00,  1.271e+00,  1.270e+00,  1.267e+00,  1.278e+00,  1.253e+00,  1.222e+00,  1.170e+00,  1.109e+00,  1.038e+00,  9.688e-01,  9.125e-01,  8.665e-01,  8.339e-01,  7.873e-01,  7.505e-01,  7.585e-01,  7.922e-01,  8.598e-01,  9.591e-01,  1.096e+00,  1.256e+00,  1.419e+00,  1.497e+00,  1.529e+00,  1.464e+00,  1.338e+00,  1.158e+00,  9.496e-01,  7.484e-01,  5.695e-01,  4.107e-01,  2.897e-01,  1.987e-01,  1.375e-01,  9.643e-02,  6.918e-02,  5.080e-02,  3.835e-02,  3.004e-02,  2.410e-02,  1.712e-02,  1.248e-02,  1.078e-02,  9.636e-03,  8.782e-03,  8.289e-03,  8.057e-03,  7.851e-03,  7.971e-03,  6.259e-03,  5.394e-03,  5.467e-03,  5.733e-03,  5.734e-03,  5.922e-03,  6.267e-03,  6.286e-03,  6.323e-03,  4.593e-03,  3.965e-03,  4.804e-03,  4.310e-03,  4.481e-03,  4.186e-03,  3.790e-03,  2.723e-03,  2.931e-03,  1.882e-03,  2.003e-03,  1.069e-02,  8.963e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.825e-01,  3.909e+00,  3.371e+00,  2.523e+00,  1.643e+00,  1.508e+00,  1.285e+00,  1.257e+00,  6.197e-01,  1.460e+00,  1.502e+00,  1.487e+00,  1.334e+00,  1.168e+00,  1.080e+00,  1.053e+00,  1.081e+00,  1.128e+00,  1.166e+00,  1.189e+00,  1.214e+00,  1.238e+00,  1.260e+00,  1.270e+00,  1.273e+00,  1.272e+00,  1.271e+00,  1.267e+00,  1.275e+00,  1.252e+00,  1.221e+00,  1.170e+00,  1.109e+00,  1.038e+00,  9.690e-01,  9.118e-01,  8.668e-01,  8.344e-01,  7.886e-01,  7.506e-01,  7.584e-01,  7.925e-01,  8.602e-01,  9.579e-01,  1.094e+00,  1.256e+00,  1.420e+00,  1.496e+00,  1.530e+00,  1.462e+00,  1.337e+00,  1.153e+00,  9.504e-01,  7.509e-01,  5.697e-01,  4.111e-01,  2.900e-01,  1.986e-01,  1.377e-01,  9.650e-02,  6.921e-02,  5.083e-02,  3.841e-02,  3.001e-02,  2.415e-02,  1.713e-02,  1.248e-02,  1.077e-02,  9.577e-03,  8.775e-03,  8.270e-03,  8.056e-03,  7.813e-03,  7.842e-03,  6.354e-03,  5.325e-03,  5.540e-03,  5.616e-03,  5.825e-03,  6.069e-03,  6.155e-03,  6.495e-03,  6.770e-03,  4.718e-03,  4.354e-03,  4.733e-03,  4.094e-03,  4.475e-03,  3.960e-03,  4.563e-03,  2.711e-03,  2.947e-03,  1.628e-03,  1.795e-03,  6.741e-03,  1.696e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_t-channel_top_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.923e-01,  3.858e+00,  3.294e+00,  2.403e+00,  1.686e+00,  1.567e+00,  1.329e+00,  1.244e+00,  6.014e-01,  1.447e+00,  1.506e+00,  1.487e+00,  1.325e+00,  1.173e+00,  1.079e+00,  1.053e+00,  1.079e+00,  1.127e+00,  1.171e+00,  1.188e+00,  1.213e+00,  1.238e+00,  1.255e+00,  1.271e+00,  1.274e+00,  1.271e+00,  1.271e+00,  1.267e+00,  1.271e+00,  1.255e+00,  1.224e+00,  1.167e+00,  1.110e+00,  1.039e+00,  9.678e-01,  9.130e-01,  8.656e-01,  8.348e-01,  7.886e-01,  7.502e-01,  7.614e-01,  7.936e-01,  8.597e-01,  9.614e-01,  1.090e+00,  1.261e+00,  1.414e+00,  1.498e+00,  1.524e+00,  1.460e+00,  1.328e+00,  1.158e+00,  9.470e-01,  7.491e-01,  5.716e-01,  4.128e-01,  2.892e-01,  1.986e-01,  1.370e-01,  9.649e-02,  6.938e-02,  5.098e-02,  3.854e-02,  3.016e-02,  2.394e-02,  1.713e-02,  1.252e-02,  1.078e-02,  9.578e-03,  8.740e-03,  8.257e-03,  7.846e-03,  7.829e-03,  8.136e-03,  6.325e-03,  5.530e-03,  5.481e-03,  5.873e-03,  5.533e-03,  6.041e-03,  6.394e-03,  6.647e-03,  6.734e-03,  5.885e-03,  4.336e-03,  4.177e-03,  3.758e-03,  6.731e-03,  4.219e-03,  2.621e-03,  2.421e-03,  5.909e-03,  1.190e-03,  2.138e-03,  0.000e+00,  3.720e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_tW_antitop_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.706e-01,  4.036e+00,  4.062e+00,  2.813e+00,  1.666e+00,  1.506e+00,  1.243e+00,  1.212e+00,  6.098e-01,  1.456e+00,  1.456e+00,  1.476e+00,  1.333e+00,  1.172e+00,  1.073e+00,  1.053e+00,  1.082e+00,  1.124e+00,  1.171e+00,  1.194e+00,  1.215e+00,  1.233e+00,  1.264e+00,  1.270e+00,  1.273e+00,  1.275e+00,  1.272e+00,  1.266e+00,  1.273e+00,  1.249e+00,  1.221e+00,  1.168e+00,  1.105e+00,  1.037e+00,  9.676e-01,  9.107e-01,  8.676e-01,  8.343e-01,  7.912e-01,  7.511e-01,  7.582e-01,  7.948e-01,  8.562e-01,  9.601e-01,  1.099e+00,  1.257e+00,  1.423e+00,  1.487e+00,  1.521e+00,  1.465e+00,  1.342e+00,  1.157e+00,  9.496e-01,  7.494e-01,  5.700e-01,  4.126e-01,  2.901e-01,  1.984e-01,  1.380e-01,  9.621e-02,  6.949e-02,  5.070e-02,  3.833e-02,  3.015e-02,  2.417e-02,  1.718e-02,  1.252e-02,  1.094e-02,  9.618e-03,  8.845e-03,  8.205e-03,  7.989e-03,  7.797e-03,  7.889e-03,  6.438e-03,  5.379e-03,  5.799e-03,  5.502e-03,  6.000e-03,  5.766e-03,  6.608e-03,  6.037e-03,  5.066e-03,  4.670e-03,  5.930e-03,  5.713e-03,  4.681e-03,  5.178e-03,  3.246e-03,  3.227e-03,  1.656e-03,  6.062e-03,  9.159e-04,  2.193e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_tW_top_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.788e-01,  3.918e+00,  3.422e+00,  2.558e+00,  1.640e+00,  1.547e+00,  1.294e+00,  1.245e+00,  6.140e-01,  1.462e+00,  1.487e+00,  1.493e+00,  1.332e+00,  1.172e+00,  1.079e+00,  1.054e+00,  1.082e+00,  1.126e+00,  1.165e+00,  1.190e+00,  1.212e+00,  1.238e+00,  1.260e+00,  1.269e+00,  1.271e+00,  1.272e+00,  1.271e+00,  1.266e+00,  1.275e+00,  1.251e+00,  1.223e+00,  1.171e+00,  1.110e+00,  1.039e+00,  9.682e-01,  9.119e-01,  8.664e-01,  8.355e-01,  7.881e-01,  7.501e-01,  7.599e-01,  7.924e-01,  8.597e-01,  9.594e-01,  1.094e+00,  1.259e+00,  1.422e+00,  1.495e+00,  1.531e+00,  1.461e+00,  1.339e+00,  1.156e+00,  9.484e-01,  7.504e-01,  5.701e-01,  4.114e-01,  2.895e-01,  1.988e-01,  1.375e-01,  9.635e-02,  6.927e-02,  5.070e-02,  3.840e-02,  3.003e-02,  2.402e-02,  1.707e-02,  1.246e-02,  1.077e-02,  9.651e-03,  8.821e-03,  8.296e-03,  8.108e-03,  7.676e-03,  7.829e-03,  6.228e-03,  5.362e-03,  5.526e-03,  5.500e-03,  5.669e-03,  5.859e-03,  6.026e-03,  6.557e-03,  6.010e-03,  4.681e-03,  4.003e-03,  4.407e-03,  3.879e-03,  4.291e-03,  3.963e-03,  3.509e-03,  3.201e-03,  3.102e-03,  2.125e-03,  2.120e-03,  5.656e-03,  2.213e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt0to700_hadd.root
{ 1.788e-01,  3.918e+00,  3.422e+00,  2.558e+00,  1.640e+00,  1.547e+00,  1.294e+00,  1.245e+00,  6.140e-01,  1.462e+00,  1.487e+00,  1.493e+00,  1.332e+00,  1.172e+00,  1.079e+00,  1.054e+00,  1.082e+00,  1.126e+00,  1.165e+00,  1.190e+00,  1.212e+00,  1.238e+00,  1.260e+00,  1.269e+00,  1.271e+00,  1.272e+00,  1.271e+00,  1.266e+00,  1.275e+00,  1.251e+00,  1.223e+00,  1.171e+00,  1.110e+00,  1.039e+00,  9.682e-01,  9.119e-01,  8.664e-01,  8.355e-01,  7.881e-01,  7.501e-01,  7.599e-01,  7.924e-01,  8.597e-01,  9.594e-01,  1.094e+00,  1.259e+00,  1.422e+00,  1.495e+00,  1.531e+00,  1.461e+00,  1.339e+00,  1.156e+00,  9.484e-01,  7.504e-01,  5.701e-01,  4.114e-01,  2.895e-01,  1.988e-01,  1.375e-01,  9.635e-02,  6.927e-02,  5.070e-02,  3.840e-02,  3.003e-02,  2.402e-02,  1.707e-02,  1.246e-02,  1.077e-02,  9.651e-03,  8.821e-03,  8.296e-03,  8.108e-03,  7.676e-03,  7.829e-03,  6.228e-03,  5.362e-03,  5.526e-03,  5.500e-03,  5.669e-03,  5.859e-03,  6.026e-03,  6.557e-03,  6.010e-03,  4.681e-03,  4.003e-03,  4.407e-03,  3.879e-03,  4.291e-03,  3.963e-03,  3.509e-03,  3.201e-03,  3.102e-03,  2.125e-03,  2.120e-03,  5.656e-03,  2.213e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt1000toInf_hadd.root
{ 1.788e-01,  3.918e+00,  3.422e+00,  2.558e+00,  1.640e+00,  1.547e+00,  1.294e+00,  1.245e+00,  6.140e-01,  1.462e+00,  1.487e+00,  1.493e+00,  1.332e+00,  1.172e+00,  1.079e+00,  1.054e+00,  1.082e+00,  1.126e+00,  1.165e+00,  1.190e+00,  1.212e+00,  1.238e+00,  1.260e+00,  1.269e+00,  1.271e+00,  1.272e+00,  1.271e+00,  1.266e+00,  1.275e+00,  1.251e+00,  1.223e+00,  1.171e+00,  1.110e+00,  1.039e+00,  9.682e-01,  9.119e-01,  8.664e-01,  8.355e-01,  7.881e-01,  7.501e-01,  7.599e-01,  7.924e-01,  8.597e-01,  9.594e-01,  1.094e+00,  1.259e+00,  1.422e+00,  1.495e+00,  1.531e+00,  1.461e+00,  1.339e+00,  1.156e+00,  9.484e-01,  7.504e-01,  5.701e-01,  4.114e-01,  2.895e-01,  1.988e-01,  1.375e-01,  9.635e-02,  6.927e-02,  5.070e-02,  3.840e-02,  3.003e-02,  2.402e-02,  1.707e-02,  1.246e-02,  1.077e-02,  9.651e-03,  8.821e-03,  8.296e-03,  8.108e-03,  7.676e-03,  7.829e-03,  6.228e-03,  5.362e-03,  5.526e-03,  5.500e-03,  5.669e-03,  5.859e-03,  6.026e-03,  6.557e-03,  6.010e-03,  4.681e-03,  4.003e-03,  4.407e-03,  3.879e-03,  4.291e-03,  3.963e-03,  3.509e-03,  3.201e-03,  3.102e-03,  2.125e-03,  2.120e-03,  5.656e-03,  2.213e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt700to1000_hadd.root
{ 1.866e-01,  3.670e+00,  3.368e+00,  2.530e+00,  1.611e+00,  1.512e+00,  1.281e+00,  1.273e+00,  6.152e-01,  1.451e+00,  1.487e+00,  1.485e+00,  1.333e+00,  1.169e+00,  1.077e+00,  1.054e+00,  1.081e+00,  1.128e+00,  1.164e+00,  1.188e+00,  1.213e+00,  1.238e+00,  1.261e+00,  1.271e+00,  1.272e+00,  1.271e+00,  1.271e+00,  1.267e+00,  1.274e+00,  1.251e+00,  1.222e+00,  1.169e+00,  1.110e+00,  1.038e+00,  9.684e-01,  9.112e-01,  8.669e-01,  8.359e-01,  7.887e-01,  7.499e-01,  7.594e-01,  7.938e-01,  8.594e-01,  9.585e-01,  1.094e+00,  1.257e+00,  1.418e+00,  1.494e+00,  1.531e+00,  1.462e+00,  1.337e+00,  1.155e+00,  9.514e-01,  7.501e-01,  5.697e-01,  4.109e-01,  2.898e-01,  1.986e-01,  1.374e-01,  9.662e-02,  6.932e-02,  5.093e-02,  3.845e-02,  2.997e-02,  2.409e-02,  1.708e-02,  1.250e-02,  1.079e-02,  9.602e-03,  8.834e-03,  8.263e-03,  8.024e-03,  7.805e-03,  7.871e-03,  6.320e-03,  5.381e-03,  5.496e-03,  5.492e-03,  5.883e-03,  5.872e-03,  6.124e-03,  6.422e-03,  6.412e-03,  4.852e-03,  4.302e-03,  4.580e-03,  4.068e-03,  4.437e-03,  4.092e-03,  4.068e-03,  3.540e-03,  3.821e-03,  1.937e-03,  1.892e-03,  7.102e-03,  2.501e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt0to700_hadd.root
{ 1.866e-01,  3.670e+00,  3.368e+00,  2.530e+00,  1.611e+00,  1.512e+00,  1.281e+00,  1.273e+00,  6.152e-01,  1.451e+00,  1.487e+00,  1.485e+00,  1.333e+00,  1.169e+00,  1.077e+00,  1.054e+00,  1.081e+00,  1.128e+00,  1.164e+00,  1.188e+00,  1.213e+00,  1.238e+00,  1.261e+00,  1.271e+00,  1.272e+00,  1.271e+00,  1.271e+00,  1.267e+00,  1.274e+00,  1.251e+00,  1.222e+00,  1.169e+00,  1.110e+00,  1.038e+00,  9.684e-01,  9.112e-01,  8.669e-01,  8.359e-01,  7.887e-01,  7.499e-01,  7.594e-01,  7.938e-01,  8.594e-01,  9.585e-01,  1.094e+00,  1.257e+00,  1.418e+00,  1.494e+00,  1.531e+00,  1.462e+00,  1.337e+00,  1.155e+00,  9.514e-01,  7.501e-01,  5.697e-01,  4.109e-01,  2.898e-01,  1.986e-01,  1.374e-01,  9.662e-02,  6.932e-02,  5.093e-02,  3.845e-02,  2.997e-02,  2.409e-02,  1.708e-02,  1.250e-02,  1.079e-02,  9.602e-03,  8.834e-03,  8.263e-03,  8.024e-03,  7.805e-03,  7.871e-03,  6.320e-03,  5.381e-03,  5.496e-03,  5.492e-03,  5.883e-03,  5.872e-03,  6.124e-03,  6.422e-03,  6.412e-03,  4.852e-03,  4.302e-03,  4.580e-03,  4.068e-03,  4.437e-03,  4.092e-03,  4.068e-03,  3.540e-03,  3.821e-03,  1.937e-03,  1.892e-03,  7.102e-03,  2.501e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt1000toInf_hadd.root
{ 1.866e-01,  3.670e+00,  3.368e+00,  2.530e+00,  1.611e+00,  1.512e+00,  1.281e+00,  1.273e+00,  6.152e-01,  1.451e+00,  1.487e+00,  1.485e+00,  1.333e+00,  1.169e+00,  1.077e+00,  1.054e+00,  1.081e+00,  1.128e+00,  1.164e+00,  1.188e+00,  1.213e+00,  1.238e+00,  1.261e+00,  1.271e+00,  1.272e+00,  1.271e+00,  1.271e+00,  1.267e+00,  1.274e+00,  1.251e+00,  1.222e+00,  1.169e+00,  1.110e+00,  1.038e+00,  9.684e-01,  9.112e-01,  8.669e-01,  8.359e-01,  7.887e-01,  7.499e-01,  7.594e-01,  7.938e-01,  8.594e-01,  9.585e-01,  1.094e+00,  1.257e+00,  1.418e+00,  1.494e+00,  1.531e+00,  1.462e+00,  1.337e+00,  1.155e+00,  9.514e-01,  7.501e-01,  5.697e-01,  4.109e-01,  2.898e-01,  1.986e-01,  1.374e-01,  9.662e-02,  6.932e-02,  5.093e-02,  3.845e-02,  2.997e-02,  2.409e-02,  1.708e-02,  1.250e-02,  1.079e-02,  9.602e-03,  8.834e-03,  8.263e-03,  8.024e-03,  7.805e-03,  7.871e-03,  6.320e-03,  5.381e-03,  5.496e-03,  5.492e-03,  5.883e-03,  5.872e-03,  6.124e-03,  6.422e-03,  6.412e-03,  4.852e-03,  4.302e-03,  4.580e-03,  4.068e-03,  4.437e-03,  4.092e-03,  4.068e-03,  3.540e-03,  3.821e-03,  1.937e-03,  1.892e-03,  7.102e-03,  2.501e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt700to1000_hadd.root
{ 1.802e-01,  3.818e+00,  3.486e+00,  2.560e+00,  1.644e+00,  1.521e+00,  1.281e+00,  1.246e+00,  6.131e-01,  1.454e+00,  1.494e+00,  1.485e+00,  1.335e+00,  1.169e+00,  1.078e+00,  1.054e+00,  1.081e+00,  1.128e+00,  1.166e+00,  1.189e+00,  1.212e+00,  1.238e+00,  1.260e+00,  1.271e+00,  1.273e+00,  1.272e+00,  1.271e+00,  1.267e+00,  1.275e+00,  1.252e+00,  1.222e+00,  1.170e+00,  1.111e+00,  1.037e+00,  9.690e-01,  9.110e-01,  8.666e-01,  8.345e-01,  7.878e-01,  7.509e-01,  7.581e-01,  7.934e-01,  8.582e-01,  9.589e-01,  1.096e+00,  1.258e+00,  1.420e+00,  1.496e+00,  1.530e+00,  1.462e+00,  1.337e+00,  1.155e+00,  9.500e-01,  7.497e-01,  5.697e-01,  4.111e-01,  2.902e-01,  1.988e-01,  1.375e-01,  9.667e-02,  6.919e-02,  5.097e-02,  3.840e-02,  3.001e-02,  2.409e-02,  1.705e-02,  1.247e-02,  1.077e-02,  9.649e-03,  8.840e-03,  8.295e-03,  8.003e-03,  7.891e-03,  7.831e-03,  6.270e-03,  5.289e-03,  5.419e-03,  5.406e-03,  5.901e-03,  5.930e-03,  6.144e-03,  6.537e-03,  6.476e-03,  4.929e-03,  4.254e-03,  4.667e-03,  3.827e-03,  4.901e-03,  4.923e-03,  4.466e-03,  3.354e-03,  4.661e-03,  1.636e-03,  1.786e-03,  4.499e-03,  3.521e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt0to700_hadd.root
{ 1.802e-01,  3.818e+00,  3.486e+00,  2.560e+00,  1.644e+00,  1.521e+00,  1.281e+00,  1.246e+00,  6.131e-01,  1.454e+00,  1.494e+00,  1.485e+00,  1.335e+00,  1.169e+00,  1.078e+00,  1.054e+00,  1.081e+00,  1.128e+00,  1.166e+00,  1.189e+00,  1.212e+00,  1.238e+00,  1.260e+00,  1.271e+00,  1.273e+00,  1.272e+00,  1.271e+00,  1.267e+00,  1.275e+00,  1.252e+00,  1.222e+00,  1.170e+00,  1.111e+00,  1.037e+00,  9.690e-01,  9.110e-01,  8.666e-01,  8.345e-01,  7.878e-01,  7.509e-01,  7.581e-01,  7.934e-01,  8.582e-01,  9.589e-01,  1.096e+00,  1.258e+00,  1.420e+00,  1.496e+00,  1.530e+00,  1.462e+00,  1.337e+00,  1.155e+00,  9.500e-01,  7.497e-01,  5.697e-01,  4.111e-01,  2.902e-01,  1.988e-01,  1.375e-01,  9.667e-02,  6.919e-02,  5.097e-02,  3.840e-02,  3.001e-02,  2.409e-02,  1.705e-02,  1.247e-02,  1.077e-02,  9.649e-03,  8.840e-03,  8.295e-03,  8.003e-03,  7.891e-03,  7.831e-03,  6.270e-03,  5.289e-03,  5.419e-03,  5.406e-03,  5.901e-03,  5.930e-03,  6.144e-03,  6.537e-03,  6.476e-03,  4.929e-03,  4.254e-03,  4.667e-03,  3.827e-03,  4.901e-03,  4.923e-03,  4.466e-03,  3.354e-03,  4.661e-03,  1.636e-03,  1.786e-03,  4.499e-03,  3.521e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt1000toInf_hadd.root
{ 1.802e-01,  3.818e+00,  3.486e+00,  2.560e+00,  1.644e+00,  1.521e+00,  1.281e+00,  1.246e+00,  6.131e-01,  1.454e+00,  1.494e+00,  1.485e+00,  1.335e+00,  1.169e+00,  1.078e+00,  1.054e+00,  1.081e+00,  1.128e+00,  1.166e+00,  1.189e+00,  1.212e+00,  1.238e+00,  1.260e+00,  1.271e+00,  1.273e+00,  1.272e+00,  1.271e+00,  1.267e+00,  1.275e+00,  1.252e+00,  1.222e+00,  1.170e+00,  1.111e+00,  1.037e+00,  9.690e-01,  9.110e-01,  8.666e-01,  8.345e-01,  7.878e-01,  7.509e-01,  7.581e-01,  7.934e-01,  8.582e-01,  9.589e-01,  1.096e+00,  1.258e+00,  1.420e+00,  1.496e+00,  1.530e+00,  1.462e+00,  1.337e+00,  1.155e+00,  9.500e-01,  7.497e-01,  5.697e-01,  4.111e-01,  2.902e-01,  1.988e-01,  1.375e-01,  9.667e-02,  6.919e-02,  5.097e-02,  3.840e-02,  3.001e-02,  2.409e-02,  1.705e-02,  1.247e-02,  1.077e-02,  9.649e-03,  8.840e-03,  8.295e-03,  8.003e-03,  7.891e-03,  7.831e-03,  6.270e-03,  5.289e-03,  5.419e-03,  5.406e-03,  5.901e-03,  5.930e-03,  6.144e-03,  6.537e-03,  6.476e-03,  4.929e-03,  4.254e-03,  4.667e-03,  3.827e-03,  4.901e-03,  4.923e-03,  4.466e-03,  3.354e-03,  4.661e-03,  1.636e-03,  1.786e-03,  4.499e-03,  3.521e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt700to1000_hadd.root
{ 1.821e-01,  3.873e+00,  3.552e+00,  2.580e+00,  1.611e+00,  1.566e+00,  1.287e+00,  1.275e+00,  6.160e-01,  1.460e+00,  1.511e+00,  1.472e+00,  1.330e+00,  1.159e+00,  1.080e+00,  1.054e+00,  1.081e+00,  1.129e+00,  1.164e+00,  1.189e+00,  1.212e+00,  1.238e+00,  1.261e+00,  1.271e+00,  1.273e+00,  1.271e+00,  1.272e+00,  1.266e+00,  1.276e+00,  1.253e+00,  1.222e+00,  1.168e+00,  1.109e+00,  1.038e+00,  9.695e-01,  9.131e-01,  8.669e-01,  8.354e-01,  7.879e-01,  7.502e-01,  7.586e-01,  7.935e-01,  8.598e-01,  9.589e-01,  1.093e+00,  1.257e+00,  1.418e+00,  1.498e+00,  1.522e+00,  1.461e+00,  1.337e+00,  1.156e+00,  9.521e-01,  7.512e-01,  5.698e-01,  4.100e-01,  2.896e-01,  1.977e-01,  1.378e-01,  9.664e-02,  6.947e-02,  5.083e-02,  3.849e-02,  2.998e-02,  2.409e-02,  1.702e-02,  1.248e-02,  1.075e-02,  9.631e-03,  8.801e-03,  8.327e-03,  8.027e-03,  7.886e-03,  7.826e-03,  6.217e-03,  5.422e-03,  5.620e-03,  5.729e-03,  5.899e-03,  6.343e-03,  6.461e-03,  6.127e-03,  6.661e-03,  5.069e-03,  4.219e-03,  5.063e-03,  4.840e-03,  3.883e-03,  4.364e-03,  3.419e-03,  4.402e-03,  2.462e-03,  2.976e-03,  3.563e-03,  1.584e-03,  1.860e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TT_Mtt-700to1000_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.792e-01,  3.632e+00,  3.580e+00,  2.499e+00,  1.583e+00,  1.543e+00,  1.256e+00,  1.254e+00,  6.115e-01,  1.454e+00,  1.506e+00,  1.474e+00,  1.342e+00,  1.167e+00,  1.076e+00,  1.059e+00,  1.076e+00,  1.127e+00,  1.169e+00,  1.188e+00,  1.212e+00,  1.239e+00,  1.260e+00,  1.271e+00,  1.273e+00,  1.271e+00,  1.271e+00,  1.266e+00,  1.275e+00,  1.250e+00,  1.224e+00,  1.168e+00,  1.110e+00,  1.039e+00,  9.674e-01,  9.121e-01,  8.663e-01,  8.357e-01,  7.902e-01,  7.506e-01,  7.585e-01,  7.936e-01,  8.594e-01,  9.565e-01,  1.098e+00,  1.255e+00,  1.418e+00,  1.498e+00,  1.529e+00,  1.461e+00,  1.340e+00,  1.152e+00,  9.469e-01,  7.508e-01,  5.685e-01,  4.097e-01,  2.895e-01,  1.993e-01,  1.373e-01,  9.688e-02,  6.912e-02,  5.075e-02,  3.843e-02,  2.994e-02,  2.415e-02,  1.717e-02,  1.250e-02,  1.086e-02,  9.623e-03,  8.817e-03,  8.263e-03,  7.916e-03,  7.914e-03,  7.808e-03,  6.224e-03,  5.459e-03,  5.397e-03,  5.942e-03,  5.846e-03,  5.784e-03,  6.132e-03,  6.259e-03,  6.839e-03,  4.075e-03,  4.118e-03,  5.340e-03,  4.213e-03,  5.326e-03,  5.008e-03,  4.840e-03,  2.235e-03,  1.637e-02,  1.413e-03,  1.974e-03,  0.000e+00,  1.030e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TT_Mtt-1000toInf_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.909e-01,  3.419e+00,  3.339e+00,  2.336e+00,  1.564e+00,  1.778e+00,  1.310e+00,  1.249e+00,  6.491e-01,  1.471e+00,  1.485e+00,  1.484e+00,  1.312e+00,  1.177e+00,  1.075e+00,  1.056e+00,  1.089e+00,  1.131e+00,  1.162e+00,  1.192e+00,  1.216e+00,  1.246e+00,  1.259e+00,  1.280e+00,  1.274e+00,  1.277e+00,  1.267e+00,  1.269e+00,  1.268e+00,  1.254e+00,  1.224e+00,  1.172e+00,  1.107e+00,  1.035e+00,  9.686e-01,  9.117e-01,  8.680e-01,  8.377e-01,  7.833e-01,  7.461e-01,  7.584e-01,  7.940e-01,  8.556e-01,  9.610e-01,  1.104e+00,  1.255e+00,  1.416e+00,  1.495e+00,  1.523e+00,  1.457e+00,  1.317e+00,  1.148e+00,  9.458e-01,  7.459e-01,  5.699e-01,  4.125e-01,  2.889e-01,  1.985e-01,  1.372e-01,  9.581e-02,  6.918e-02,  5.162e-02,  3.844e-02,  3.025e-02,  2.414e-02,  1.708e-02,  1.244e-02,  1.111e-02,  9.695e-03,  8.772e-03,  8.088e-03,  8.092e-03,  7.848e-03,  7.564e-03,  6.635e-03,  5.332e-03,  6.230e-03,  5.662e-03,  6.334e-03,  6.250e-03,  7.893e-03,  5.664e-03,  6.824e-03,  4.217e-03,  3.433e-03,  5.257e-03,  4.839e-03,  3.059e-03,  4.314e-03,  2.680e-03,  1.320e-03,  0.000e+00,  2.435e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTZToLLNuNu_M-10_TuneCP5_PSweights_13TeV-amcatnlo-pythia8_hadd.root
{ 1.963e-01,  2.913e+00,  2.948e+00,  2.677e+00,  1.437e+00,  1.469e+00,  1.400e+00,  1.178e+00,  6.319e-01,  1.489e+00,  1.546e+00,  1.471e+00,  1.349e+00,  1.157e+00,  1.081e+00,  1.063e+00,  1.092e+00,  1.124e+00,  1.170e+00,  1.181e+00,  1.214e+00,  1.239e+00,  1.252e+00,  1.261e+00,  1.276e+00,  1.269e+00,  1.285e+00,  1.263e+00,  1.280e+00,  1.263e+00,  1.227e+00,  1.163e+00,  1.110e+00,  1.044e+00,  9.648e-01,  9.062e-01,  8.640e-01,  8.284e-01,  7.839e-01,  7.470e-01,  7.639e-01,  7.898e-01,  8.616e-01,  9.682e-01,  1.096e+00,  1.247e+00,  1.414e+00,  1.499e+00,  1.526e+00,  1.453e+00,  1.342e+00,  1.145e+00,  9.450e-01,  7.433e-01,  5.676e-01,  4.125e-01,  2.913e-01,  2.000e-01,  1.415e-01,  9.638e-02,  6.950e-02,  5.026e-02,  3.891e-02,  3.058e-02,  2.368e-02,  1.690e-02,  1.264e-02,  1.086e-02,  9.634e-03,  8.931e-03,  8.180e-03,  7.492e-03,  7.486e-03,  7.452e-03,  6.615e-03,  5.830e-03,  5.686e-03,  4.869e-03,  5.734e-03,  9.383e-03,  5.059e-03,  7.290e-03,  6.145e-03,  1.201e-02,  6.043e-03,  3.881e-03,  3.180e-03,  7.035e-03,  4.410e-03,  1.370e-03,  -3.374e-03,  0.000e+00,  0.000e+00,  3.724e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTWJetsToLNu_TuneCP5_PSweights_13TeV-amcatnloFXFX-madspin-pythia8_hadd.root
{ 1.814e-01,  4.869e+00,  3.328e+00,  2.649e+00,  1.539e+00,  1.459e+00,  1.240e+00,  1.245e+00,  6.164e-01,  1.457e+00,  1.487e+00,  1.486e+00,  1.338e+00,  1.172e+00,  1.080e+00,  1.049e+00,  1.083e+00,  1.127e+00,  1.162e+00,  1.192e+00,  1.214e+00,  1.236e+00,  1.264e+00,  1.269e+00,  1.270e+00,  1.271e+00,  1.270e+00,  1.267e+00,  1.275e+00,  1.251e+00,  1.224e+00,  1.169e+00,  1.110e+00,  1.040e+00,  9.670e-01,  9.113e-01,  8.653e-01,  8.359e-01,  7.899e-01,  7.515e-01,  7.573e-01,  7.931e-01,  8.636e-01,  9.604e-01,  1.094e+00,  1.256e+00,  1.421e+00,  1.503e+00,  1.522e+00,  1.462e+00,  1.344e+00,  1.151e+00,  9.522e-01,  7.464e-01,  5.692e-01,  4.098e-01,  2.902e-01,  1.990e-01,  1.377e-01,  9.661e-02,  6.950e-02,  5.084e-02,  3.821e-02,  3.001e-02,  2.393e-02,  1.717e-02,  1.241e-02,  1.069e-02,  9.439e-03,  8.829e-03,  8.278e-03,  7.919e-03,  8.173e-03,  8.321e-03,  6.351e-03,  5.280e-03,  5.702e-03,  5.654e-03,  5.687e-03,  6.971e-03,  6.876e-03,  7.289e-03,  5.101e-03,  4.640e-03,  4.187e-03,  4.087e-03,  5.009e-03,  4.116e-03,  4.300e-03,  1.781e-03,  3.290e-03,  6.023e-03,  9.100e-04,  2.179e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ttHTobb_M125_TuneCP5_13TeV-powheg-pythia8_hadd.root
{ 1.803e-01,  3.458e+00,  3.320e+00,  2.672e+00,  1.673e+00,  1.617e+00,  1.216e+00,  1.254e+00,  5.875e-01,  1.508e+00,  1.485e+00,  1.469e+00,  1.337e+00,  1.158e+00,  1.083e+00,  1.052e+00,  1.077e+00,  1.128e+00,  1.165e+00,  1.185e+00,  1.215e+00,  1.238e+00,  1.267e+00,  1.269e+00,  1.272e+00,  1.267e+00,  1.272e+00,  1.268e+00,  1.274e+00,  1.250e+00,  1.219e+00,  1.169e+00,  1.112e+00,  1.039e+00,  9.677e-01,  9.125e-01,  8.686e-01,  8.354e-01,  7.882e-01,  7.527e-01,  7.564e-01,  7.919e-01,  8.570e-01,  9.614e-01,  1.101e+00,  1.253e+00,  1.426e+00,  1.490e+00,  1.537e+00,  1.467e+00,  1.327e+00,  1.145e+00,  9.504e-01,  7.503e-01,  5.704e-01,  4.090e-01,  2.908e-01,  1.991e-01,  1.382e-01,  9.642e-02,  6.952e-02,  5.087e-02,  3.848e-02,  2.981e-02,  2.406e-02,  1.711e-02,  1.247e-02,  1.064e-02,  9.808e-03,  8.913e-03,  8.170e-03,  8.021e-03,  8.009e-03,  7.519e-03,  6.414e-03,  5.711e-03,  5.312e-03,  5.423e-03,  5.859e-03,  5.321e-03,  5.620e-03,  5.984e-03,  6.974e-03,  4.543e-03,  4.534e-03,  7.841e-03,  4.640e-03,  2.737e-03,  3.677e-03,  7.996e-03,  1.641e-03,  0.000e+00,  1.816e-03,  7.246e-04,  0.000e+00,  7.564e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8_hadd.root
{ 1.872e-01,  4.734e+00,  3.232e+00,  2.391e+00,  1.802e+00,  1.487e+00,  1.329e+00,  1.206e+00,  6.104e-01,  1.495e+00,  1.516e+00,  1.479e+00,  1.319e+00,  1.164e+00,  1.076e+00,  1.050e+00,  1.080e+00,  1.130e+00,  1.165e+00,  1.189e+00,  1.212e+00,  1.236e+00,  1.259e+00,  1.271e+00,  1.271e+00,  1.272e+00,  1.272e+00,  1.268e+00,  1.277e+00,  1.253e+00,  1.221e+00,  1.169e+00,  1.109e+00,  1.039e+00,  9.689e-01,  9.134e-01,  8.660e-01,  8.371e-01,  7.901e-01,  7.512e-01,  7.588e-01,  7.926e-01,  8.575e-01,  9.588e-01,  1.093e+00,  1.257e+00,  1.421e+00,  1.494e+00,  1.528e+00,  1.463e+00,  1.338e+00,  1.155e+00,  9.496e-01,  7.493e-01,  5.703e-01,  4.107e-01,  2.901e-01,  1.994e-01,  1.376e-01,  9.651e-02,  6.894e-02,  5.072e-02,  3.840e-02,  3.000e-02,  2.413e-02,  1.700e-02,  1.244e-02,  1.072e-02,  9.628e-03,  8.830e-03,  8.313e-03,  8.099e-03,  7.728e-03,  7.914e-03,  6.299e-03,  5.288e-03,  5.475e-03,  5.778e-03,  5.868e-03,  6.319e-03,  6.639e-03,  6.376e-03,  6.585e-03,  4.473e-03,  3.405e-03,  3.717e-03,  4.364e-03,  6.166e-03,  3.458e-03,  1.944e-03,  3.591e-03,  5.113e-03,  3.090e-03,  1.110e-03,  0.000e+00,  1.931e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.913e-01,  4.255e+00,  3.444e+00,  2.481e+00,  1.640e+00,  1.532e+00,  1.288e+00,  1.270e+00,  5.997e-01,  1.442e+00,  1.477e+00,  1.476e+00,  1.330e+00,  1.169e+00,  1.083e+00,  1.051e+00,  1.078e+00,  1.126e+00,  1.166e+00,  1.188e+00,  1.211e+00,  1.239e+00,  1.256e+00,  1.271e+00,  1.274e+00,  1.274e+00,  1.271e+00,  1.267e+00,  1.274e+00,  1.254e+00,  1.220e+00,  1.167e+00,  1.113e+00,  1.037e+00,  9.689e-01,  9.130e-01,  8.681e-01,  8.336e-01,  7.865e-01,  7.516e-01,  7.577e-01,  7.949e-01,  8.594e-01,  9.562e-01,  1.097e+00,  1.258e+00,  1.421e+00,  1.493e+00,  1.534e+00,  1.461e+00,  1.341e+00,  1.156e+00,  9.519e-01,  7.507e-01,  5.693e-01,  4.101e-01,  2.896e-01,  1.981e-01,  1.374e-01,  9.659e-02,  6.938e-02,  5.074e-02,  3.867e-02,  2.989e-02,  2.413e-02,  1.713e-02,  1.251e-02,  1.076e-02,  9.503e-03,  8.768e-03,  8.259e-03,  8.064e-03,  7.856e-03,  7.777e-03,  6.306e-03,  5.442e-03,  5.529e-03,  5.516e-03,  6.169e-03,  5.712e-03,  6.266e-03,  7.418e-03,  7.192e-03,  4.264e-03,  4.179e-03,  5.316e-03,  3.595e-03,  6.186e-03,  2.908e-03,  3.336e-03,  3.338e-03,  5.431e-03,  1.969e-03,  1.179e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.893e-01,  4.111e+00,  3.265e+00,  2.650e+00,  1.614e+00,  1.489e+00,  1.286e+00,  1.242e+00,  6.233e-01,  1.437e+00,  1.485e+00,  1.483e+00,  1.338e+00,  1.164e+00,  1.076e+00,  1.050e+00,  1.080e+00,  1.130e+00,  1.168e+00,  1.188e+00,  1.213e+00,  1.239e+00,  1.262e+00,  1.272e+00,  1.272e+00,  1.269e+00,  1.273e+00,  1.266e+00,  1.276e+00,  1.250e+00,  1.221e+00,  1.171e+00,  1.110e+00,  1.038e+00,  9.688e-01,  9.133e-01,  8.687e-01,  8.352e-01,  7.870e-01,  7.480e-01,  7.603e-01,  7.925e-01,  8.593e-01,  9.609e-01,  1.091e+00,  1.256e+00,  1.416e+00,  1.495e+00,  1.528e+00,  1.461e+00,  1.340e+00,  1.154e+00,  9.491e-01,  7.498e-01,  5.704e-01,  4.106e-01,  2.895e-01,  1.986e-01,  1.373e-01,  9.674e-02,  6.937e-02,  5.068e-02,  3.836e-02,  3.009e-02,  2.404e-02,  1.719e-02,  1.254e-02,  1.088e-02,  9.526e-03,  8.853e-03,  8.373e-03,  8.004e-03,  7.929e-03,  7.867e-03,  6.149e-03,  5.388e-03,  5.507e-03,  5.840e-03,  5.703e-03,  6.378e-03,  6.406e-03,  6.041e-03,  6.583e-03,  5.059e-03,  4.319e-03,  4.639e-03,  5.043e-03,  5.162e-03,  3.576e-03,  1.055e-02,  5.199e-03,  3.965e-03,  3.195e-03,  1.913e-03,  3.402e-03,  6.656e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.901e-01,  3.983e+00,  3.839e+00,  2.689e+00,  1.651e+00,  1.478e+00,  1.306e+00,  1.287e+00,  6.127e-01,  1.433e+00,  1.498e+00,  1.483e+00,  1.326e+00,  1.166e+00,  1.080e+00,  1.051e+00,  1.074e+00,  1.126e+00,  1.163e+00,  1.187e+00,  1.212e+00,  1.238e+00,  1.260e+00,  1.268e+00,  1.274e+00,  1.274e+00,  1.271e+00,  1.269e+00,  1.277e+00,  1.252e+00,  1.224e+00,  1.171e+00,  1.110e+00,  1.038e+00,  9.698e-01,  9.116e-01,  8.653e-01,  8.349e-01,  7.897e-01,  7.499e-01,  7.575e-01,  7.923e-01,  8.595e-01,  9.568e-01,  1.096e+00,  1.260e+00,  1.420e+00,  1.496e+00,  1.534e+00,  1.465e+00,  1.339e+00,  1.157e+00,  9.517e-01,  7.509e-01,  5.693e-01,  4.109e-01,  2.895e-01,  1.974e-01,  1.380e-01,  9.661e-02,  6.950e-02,  5.090e-02,  3.837e-02,  2.964e-02,  2.417e-02,  1.699e-02,  1.248e-02,  1.080e-02,  9.537e-03,  8.780e-03,  8.265e-03,  8.057e-03,  7.838e-03,  7.899e-03,  6.211e-03,  5.415e-03,  5.542e-03,  5.351e-03,  5.709e-03,  6.011e-03,  5.815e-03,  6.560e-03,  6.051e-03,  4.592e-03,  4.724e-03,  6.169e-03,  3.276e-03,  4.660e-03,  2.596e-03,  5.807e-03,  4.470e-03,  3.636e-03,  6.593e-03,  1.316e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.888e-01,  3.502e+00,  3.514e+00,  2.629e+00,  1.583e+00,  1.493e+00,  1.298e+00,  1.288e+00,  6.142e-01,  1.484e+00,  1.475e+00,  1.479e+00,  1.324e+00,  1.167e+00,  1.074e+00,  1.054e+00,  1.080e+00,  1.133e+00,  1.165e+00,  1.186e+00,  1.215e+00,  1.238e+00,  1.261e+00,  1.271e+00,  1.273e+00,  1.274e+00,  1.268e+00,  1.265e+00,  1.275e+00,  1.254e+00,  1.224e+00,  1.171e+00,  1.109e+00,  1.036e+00,  9.681e-01,  9.106e-01,  8.671e-01,  8.344e-01,  7.894e-01,  7.522e-01,  7.563e-01,  7.951e-01,  8.590e-01,  9.587e-01,  1.094e+00,  1.253e+00,  1.420e+00,  1.494e+00,  1.534e+00,  1.461e+00,  1.336e+00,  1.154e+00,  9.529e-01,  7.531e-01,  5.698e-01,  4.116e-01,  2.904e-01,  1.985e-01,  1.375e-01,  9.615e-02,  6.909e-02,  5.076e-02,  3.842e-02,  2.983e-02,  2.402e-02,  1.707e-02,  1.243e-02,  1.084e-02,  9.665e-03,  8.754e-03,  8.300e-03,  8.017e-03,  7.666e-03,  7.911e-03,  6.434e-03,  5.313e-03,  5.527e-03,  5.339e-03,  5.820e-03,  5.713e-03,  5.771e-03,  6.272e-03,  7.239e-03,  5.111e-03,  4.011e-03,  5.152e-03,  4.546e-03,  3.502e-03,  3.697e-03,  3.637e-03,  3.840e-03,  2.050e-03,  1.982e-03,  1.483e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.711e-01,  3.600e+00,  3.097e+00,  2.605e+00,  1.589e+00,  1.439e+00,  1.297e+00,  1.250e+00,  6.092e-01,  1.445e+00,  1.499e+00,  1.471e+00,  1.332e+00,  1.165e+00,  1.075e+00,  1.055e+00,  1.081e+00,  1.127e+00,  1.166e+00,  1.190e+00,  1.212e+00,  1.240e+00,  1.261e+00,  1.271e+00,  1.275e+00,  1.275e+00,  1.271e+00,  1.265e+00,  1.274e+00,  1.250e+00,  1.222e+00,  1.170e+00,  1.107e+00,  1.039e+00,  9.693e-01,  9.131e-01,  8.674e-01,  8.347e-01,  7.890e-01,  7.505e-01,  7.591e-01,  7.920e-01,  8.588e-01,  9.598e-01,  1.092e+00,  1.260e+00,  1.417e+00,  1.489e+00,  1.528e+00,  1.462e+00,  1.335e+00,  1.156e+00,  9.474e-01,  7.490e-01,  5.693e-01,  4.120e-01,  2.903e-01,  1.986e-01,  1.383e-01,  9.635e-02,  6.923e-02,  5.101e-02,  3.853e-02,  2.984e-02,  2.411e-02,  1.705e-02,  1.249e-02,  1.076e-02,  9.660e-03,  8.827e-03,  8.297e-03,  7.973e-03,  7.932e-03,  8.049e-03,  6.384e-03,  5.142e-03,  5.646e-03,  5.485e-03,  5.502e-03,  6.078e-03,  6.366e-03,  5.985e-03,  6.880e-03,  4.359e-03,  4.626e-03,  4.639e-03,  4.321e-03,  4.438e-03,  3.035e-03,  4.149e-03,  2.838e-03,  3.897e-03,  3.140e-03,  0.000e+00,  1.671e-03,  1.962e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.747e-01,  3.754e+00,  3.329e+00,  2.355e+00,  1.696e+00,  1.497e+00,  1.243e+00,  1.161e+00,  6.304e-01,  1.463e+00,  1.500e+00,  1.485e+00,  1.340e+00,  1.163e+00,  1.075e+00,  1.056e+00,  1.083e+00,  1.133e+00,  1.161e+00,  1.192e+00,  1.211e+00,  1.240e+00,  1.261e+00,  1.273e+00,  1.272e+00,  1.270e+00,  1.272e+00,  1.263e+00,  1.272e+00,  1.254e+00,  1.220e+00,  1.169e+00,  1.111e+00,  1.037e+00,  9.708e-01,  9.098e-01,  8.665e-01,  8.359e-01,  7.902e-01,  7.517e-01,  7.575e-01,  7.910e-01,  8.594e-01,  9.547e-01,  1.092e+00,  1.255e+00,  1.425e+00,  1.496e+00,  1.535e+00,  1.463e+00,  1.344e+00,  1.154e+00,  9.460e-01,  7.464e-01,  5.712e-01,  4.131e-01,  2.907e-01,  1.988e-01,  1.374e-01,  9.660e-02,  6.931e-02,  5.074e-02,  3.861e-02,  2.972e-02,  2.417e-02,  1.708e-02,  1.251e-02,  1.077e-02,  9.748e-03,  8.891e-03,  8.086e-03,  8.099e-03,  7.509e-03,  7.948e-03,  6.661e-03,  5.426e-03,  5.356e-03,  5.449e-03,  5.574e-03,  5.704e-03,  5.771e-03,  5.596e-03,  5.198e-03,  4.780e-03,  5.257e-03,  6.753e-03,  3.397e-03,  4.534e-03,  8.525e-03,  3.973e-03,  3.262e-03,  5.971e-03,  9.021e-04,  7.201e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WW_TuneCP5_13TeV-pythia8_hadd.root
{ 2.885e-04,  9.426e-03,  3.709e-02,  6.739e-02,  9.283e-02,  1.810e-01,  1.933e-01,  2.232e-01,  1.095e-01,  4.127e-01,  4.222e-01,  6.463e-01,  7.086e-01,  7.589e-01,  7.401e-01,  7.535e-01,  8.487e-01,  1.014e+00,  1.090e+00,  1.144e+00,  1.238e+00,  1.270e+00,  1.304e+00,  1.329e+00,  1.353e+00,  1.354e+00,  1.340e+00,  1.366e+00,  1.392e+00,  1.375e+00,  1.305e+00,  1.262e+00,  1.203e+00,  1.138e+00,  1.076e+00,  1.014e+00,  9.526e-01,  9.096e-01,  8.524e-01,  8.366e-01,  8.149e-01,  8.498e-01,  9.367e-01,  1.070e+00,  1.217e+00,  1.370e+00,  1.555e+00,  1.651e+00,  1.661e+00,  1.619e+00,  1.441e+00,  1.254e+00,  1.031e+00,  7.733e-01,  6.002e-01,  4.269e-01,  3.139e-01,  2.145e-01,  1.491e-01,  1.047e-01,  7.117e-02,  5.268e-02,  3.779e-02,  2.871e-02,  2.464e-02,  1.834e-02,  1.201e-02,  1.115e-02,  7.759e-03,  8.828e-03,  4.914e-03,  4.979e-03,  4.248e-03,  8.633e-03,  3.551e-03,  1.225e-03,  8.479e-04,  5.544e-03,  2.923e-04,  2.167e-04,  4.406e-04,  9.199e-05,  1.197e-04,  2.637e-05,  4.199e-03,  3.283e-05,  2.446e-05,  3.924e-05,  2.652e-06,  1.347e-05,  3.182e-06,  2.517e-04,  6.085e-04,  5.464e-04,  2.159e-04,  9.482e-07,  3.683e-05,  1.271e-04,  2.586e-07,  2.874e-07,  0.000e+00,  }, // WZ_TuneCP5_13TeV-pythia8_hadd.root
{ 2.034e-01,  4.570e+00,  3.455e+00,  2.433e+00,  2.113e+00,  1.497e+00,  1.226e+00,  1.242e+00,  6.374e-01,  1.528e+00,  1.536e+00,  1.507e+00,  1.329e+00,  1.159e+00,  1.065e+00,  1.041e+00,  1.082e+00,  1.144e+00,  1.158e+00,  1.193e+00,  1.211e+00,  1.235e+00,  1.258e+00,  1.277e+00,  1.272e+00,  1.264e+00,  1.269e+00,  1.273e+00,  1.269e+00,  1.264e+00,  1.223e+00,  1.173e+00,  1.104e+00,  1.033e+00,  9.748e-01,  9.112e-01,  8.653e-01,  8.366e-01,  7.900e-01,  7.484e-01,  7.577e-01,  7.925e-01,  8.630e-01,  9.599e-01,  1.088e+00,  1.262e+00,  1.443e+00,  1.488e+00,  1.536e+00,  1.452e+00,  1.325e+00,  1.154e+00,  9.670e-01,  7.471e-01,  5.738e-01,  4.083e-01,  2.878e-01,  1.975e-01,  1.365e-01,  9.673e-02,  6.975e-02,  5.090e-02,  3.868e-02,  3.004e-02,  2.368e-02,  1.673e-02,  1.234e-02,  1.077e-02,  9.694e-03,  8.566e-03,  8.172e-03,  7.909e-03,  7.901e-03,  7.859e-03,  6.528e-03,  5.654e-03,  5.522e-03,  6.173e-03,  6.403e-03,  7.198e-03,  7.156e-03,  5.899e-03,  3.712e-03,  4.030e-03,  2.445e-03,  6.280e-03,  8.004e-03,  1.687e-03,  3.171e-03,  3.941e-03,  1.213e-03,  1.481e-03,  8.949e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ZZ_TuneCP5_13TeV-pythia8_hadd.root
{ 1.966E-01,  7.140E+00,  3.613E+00,  2.666E+00,  1.484E+00,  1.843E+00,  1.287E+00,  1.262E+00,  5.802E-01,  1.404E+00,  1.596E+00,  1.455E+00,  1.309E+00,  1.135E+00,  1.084E+00,  1.060E+00,  1.096E+00,  1.124E+00,  1.165E+00,  1.181E+00,  1.205E+00,  1.236E+00,  1.257E+00,  1.270E+00,  1.297E+00,  1.278E+00,  1.260E+00,  1.278E+00,  1.278E+00,  1.247E+00,  1.208E+00,  1.161E+00,  1.112E+00,  1.036E+00,  9.728E-01,  9.100E-01,  8.676E-01,  8.357E-01,  7.996E-01,  7.427E-01,  7.554E-01,  8.000E-01,  8.619E-01,  9.551E-01,  1.087E+00,  1.251E+00,  1.421E+00,  1.483E+00,  1.526E+00,  1.459E+00,  1.343E+00,  1.142E+00,  9.510E-01,  7.526E-01,  5.729E-01,  4.126E-01,  2.910E-01,  1.989E-01,  1.362E-01,  9.563E-02,  7.127E-02,  5.097E-02,  3.825E-02,  2.968E-02,  2.414E-02,  1.696E-02,  1.248E-02,  1.074E-02,  9.987E-03,  9.320E-03,  8.271E-03,  8.234E-03,  8.818E-03,  7.835E-03,  6.105E-03,  5.859E-03,  4.983E-03,  4.926E-03,  6.097E-03,  6.572E-03,  }, // BB1000.root
{ 1.588E-01,  3.993E+00,  3.087E+00,  2.783E+00,  1.697E+00,  1.568E+00,  1.061E+00,  1.258E+00,  6.869E-01,  1.461E+00,  1.439E+00,  1.422E+00,  1.295E+00,  1.147E+00,  1.088E+00,  1.058E+00,  1.069E+00,  1.141E+00,  1.169E+00,  1.178E+00,  1.215E+00,  1.251E+00,  1.246E+00,  1.266E+00,  1.247E+00,  1.272E+00,  1.274E+00,  1.272E+00,  1.284E+00,  1.259E+00,  1.222E+00,  1.185E+00,  1.104E+00,  1.040E+00,  9.689E-01,  9.133E-01,  8.726E-01,  8.402E-01,  7.896E-01,  7.608E-01,  7.585E-01,  7.863E-01,  8.430E-01,  9.522E-01,  1.089E+00,  1.244E+00,  1.449E+00,  1.479E+00,  1.502E+00,  1.463E+00,  1.325E+00,  1.147E+00,  9.511E-01,  7.526E-01,  5.672E-01,  4.105E-01,  2.898E-01,  1.977E-01,  1.388E-01,  9.614E-02,  7.058E-02,  5.079E-02,  3.833E-02,  2.974E-02,  2.476E-02,  1.757E-02,  1.208E-02,  1.136E-02,  9.501E-03,  8.402E-03,  8.454E-03,  7.414E-03,  9.199E-03,  8.364E-03,  7.341E-03,  5.603E-03,  5.610E-03,  6.154E-03,  7.157E-03,  7.146E-03,  }, // BB1100.root
{ 1.582E-01,  4.109E+00,  4.764E+00,  2.169E+00,  1.921E+00,  1.825E+00,  1.142E+00,  1.321E+00,  6.374E-01,  1.401E+00,  1.553E+00,  1.458E+00,  1.339E+00,  1.185E+00,  1.075E+00,  1.047E+00,  1.074E+00,  1.121E+00,  1.165E+00,  1.202E+00,  1.197E+00,  1.233E+00,  1.256E+00,  1.277E+00,  1.277E+00,  1.252E+00,  1.271E+00,  1.274E+00,  1.275E+00,  1.256E+00,  1.223E+00,  1.167E+00,  1.107E+00,  1.043E+00,  9.691E-01,  9.135E-01,  8.646E-01,  8.364E-01,  7.880E-01,  7.512E-01,  7.500E-01,  7.933E-01,  8.557E-01,  9.609E-01,  1.131E+00,  1.273E+00,  1.426E+00,  1.511E+00,  1.522E+00,  1.474E+00,  1.324E+00,  1.152E+00,  9.592E-01,  7.494E-01,  5.663E-01,  4.090E-01,  2.865E-01,  1.996E-01,  1.366E-01,  9.480E-02,  6.916E-02,  5.078E-02,  3.723E-02,  3.090E-02,  2.457E-02,  1.708E-02,  1.264E-02,  1.075E-02,  9.878E-03,  9.188E-03,  8.359E-03,  8.390E-03,  8.059E-03,  8.812E-03,  6.642E-03,  5.480E-03,  5.051E-03,  6.765E-03,  4.971E-03,  5.515E-03,  }, // BB1200.root
{ 1.761E-01,  4.427E+00,  3.651E+00,  2.286E+00,  1.577E+00,  1.684E+00,  1.424E+00,  1.213E+00,  6.297E-01,  1.443E+00,  1.457E+00,  1.461E+00,  1.373E+00,  1.139E+00,  1.066E+00,  1.054E+00,  1.089E+00,  1.116E+00,  1.151E+00,  1.181E+00,  1.225E+00,  1.242E+00,  1.257E+00,  1.258E+00,  1.274E+00,  1.268E+00,  1.266E+00,  1.268E+00,  1.278E+00,  1.245E+00,  1.225E+00,  1.172E+00,  1.107E+00,  1.037E+00,  9.767E-01,  9.209E-01,  8.633E-01,  8.511E-01,  7.814E-01,  7.458E-01,  7.505E-01,  7.887E-01,  8.692E-01,  9.632E-01,  1.099E+00,  1.263E+00,  1.440E+00,  1.505E+00,  1.508E+00,  1.461E+00,  1.349E+00,  1.175E+00,  9.598E-01,  7.511E-01,  5.592E-01,  4.089E-01,  2.921E-01,  1.978E-01,  1.377E-01,  9.596E-02,  6.830E-02,  5.054E-02,  3.885E-02,  2.991E-02,  2.402E-02,  1.650E-02,  1.206E-02,  1.096E-02,  9.714E-03,  9.081E-03,  8.460E-03,  8.897E-03,  9.400E-03,  7.051E-03,  6.563E-03,  6.081E-03,  6.282E-03,  5.832E-03,  6.856E-03,  9.509E-03,  }, // BB1300.root
{ 1.936E-01,  2.028E+00,  3.010E+00,  2.692E+00,  1.839E+00,  1.543E+00,  1.322E+00,  1.328E+00,  5.792E-01,  1.593E+00,  1.368E+00,  1.563E+00,  1.323E+00,  1.138E+00,  1.104E+00,  1.026E+00,  1.097E+00,  1.151E+00,  1.167E+00,  1.209E+00,  1.211E+00,  1.246E+00,  1.261E+00,  1.265E+00,  1.282E+00,  1.277E+00,  1.270E+00,  1.264E+00,  1.281E+00,  1.247E+00,  1.230E+00,  1.173E+00,  1.104E+00,  1.038E+00,  9.717E-01,  9.095E-01,  8.663E-01,  8.321E-01,  7.895E-01,  7.559E-01,  7.566E-01,  7.874E-01,  8.563E-01,  9.585E-01,  1.094E+00,  1.247E+00,  1.404E+00,  1.498E+00,  1.482E+00,  1.463E+00,  1.351E+00,  1.162E+00,  9.489E-01,  7.423E-01,  5.620E-01,  4.156E-01,  2.898E-01,  1.953E-01,  1.373E-01,  9.429E-02,  6.909E-02,  5.093E-02,  3.877E-02,  2.969E-02,  2.399E-02,  1.743E-02,  1.255E-02,  1.130E-02,  9.844E-03,  8.774E-03,  8.427E-03,  7.442E-03,  6.835E-03,  8.534E-03,  5.832E-03,  6.019E-03,  4.619E-03,  5.597E-03,  6.543E-03,  5.502E-03,  }, // BB1400.root
{ 2.591E-01,  1.411E+01,  4.365E+00,  6.148E+00,  1.553E+00,  1.471E+00,  1.400E+00,  1.308E+00,  5.963E-01,  1.671E+00,  1.489E+00,  1.440E+00,  1.328E+00,  1.148E+00,  1.077E+00,  1.060E+00,  1.084E+00,  1.133E+00,  1.136E+00,  1.197E+00,  1.221E+00,  1.226E+00,  1.260E+00,  1.270E+00,  1.301E+00,  1.247E+00,  1.277E+00,  1.281E+00,  1.256E+00,  1.251E+00,  1.242E+00,  1.180E+00,  1.092E+00,  1.041E+00,  9.683E-01,  9.190E-01,  8.732E-01,  8.396E-01,  7.830E-01,  7.523E-01,  7.470E-01,  7.849E-01,  8.450E-01,  9.410E-01,  1.082E+00,  1.285E+00,  1.425E+00,  1.531E+00,  1.527E+00,  1.467E+00,  1.354E+00,  1.159E+00,  9.474E-01,  7.466E-01,  5.701E-01,  4.174E-01,  2.880E-01,  1.970E-01,  1.399E-01,  9.717E-02,  6.971E-02,  5.259E-02,  3.746E-02,  2.929E-02,  2.340E-02,  1.662E-02,  1.214E-02,  1.084E-02,  9.747E-03,  8.910E-03,  7.819E-03,  7.530E-03,  7.492E-03,  9.247E-03,  7.311E-03,  5.556E-03,  6.787E-03,  5.681E-03,  4.711E-03,  5.052E-03,  }, // BB1500.root
{ 2.699E-01,  7.352E+00,  2.728E+00,  2.562E+00,  1.618E+00,  1.328E+00,  1.215E+00,  1.173E+00,  5.891E-01,  1.549E+00,  1.474E+00,  1.461E+00,  1.292E+00,  1.225E+00,  1.058E+00,  1.057E+00,  1.084E+00,  1.116E+00,  1.167E+00,  1.185E+00,  1.207E+00,  1.241E+00,  1.279E+00,  1.271E+00,  1.269E+00,  1.262E+00,  1.275E+00,  1.286E+00,  1.269E+00,  1.247E+00,  1.217E+00,  1.165E+00,  1.102E+00,  1.024E+00,  9.703E-01,  9.172E-01,  8.808E-01,  8.410E-01,  7.840E-01,  7.454E-01,  7.468E-01,  8.053E-01,  8.554E-01,  9.532E-01,  1.086E+00,  1.253E+00,  1.417E+00,  1.471E+00,  1.520E+00,  1.458E+00,  1.325E+00,  1.173E+00,  9.520E-01,  7.586E-01,  5.650E-01,  4.155E-01,  2.901E-01,  2.024E-01,  1.402E-01,  9.716E-02,  6.946E-02,  5.128E-02,  3.841E-02,  2.984E-02,  2.345E-02,  1.708E-02,  1.271E-02,  1.111E-02,  9.707E-03,  9.177E-03,  8.128E-03,  7.596E-03,  8.000E-03,  7.967E-03,  6.268E-03,  5.103E-03,  5.582E-03,  4.438E-03,  6.469E-03,  5.573E-03,  }, // BB1600.root
{ 3.243E-01,  0.000E+00,  3.241E+00,  3.874E+00,  1.634E+00,  1.205E+00,  1.427E+00,  1.150E+00,  5.963E-01,  1.367E+00,  1.535E+00,  1.353E+00,  1.331E+00,  1.146E+00,  1.111E+00,  1.025E+00,  1.050E+00,  1.136E+00,  1.194E+00,  1.194E+00,  1.213E+00,  1.203E+00,  1.274E+00,  1.282E+00,  1.243E+00,  1.284E+00,  1.291E+00,  1.288E+00,  1.286E+00,  1.230E+00,  1.228E+00,  1.152E+00,  1.117E+00,  1.046E+00,  9.710E-01,  9.065E-01,  8.581E-01,  8.082E-01,  7.938E-01,  7.632E-01,  7.600E-01,  7.938E-01,  8.554E-01,  9.553E-01,  1.116E+00,  1.276E+00,  1.396E+00,  1.489E+00,  1.525E+00,  1.497E+00,  1.337E+00,  1.150E+00,  9.649E-01,  7.620E-01,  5.542E-01,  4.081E-01,  2.892E-01,  2.029E-01,  1.374E-01,  9.800E-02,  7.007E-02,  4.905E-02,  3.799E-02,  2.933E-02,  2.460E-02,  1.675E-02,  1.282E-02,  1.112E-02,  9.116E-03,  8.720E-03,  8.960E-03,  7.077E-03,  8.174E-03,  8.725E-03,  6.850E-03,  5.126E-03,  5.400E-03,  6.328E-03,  7.398E-03,  7.163E-03,  }, // BB1800.root
{ 1.875E-01,  4.242E+00,  2.624E+00,  2.240E+00,  1.587E+00,  1.455E+00,  1.372E+00,  1.061E+00,  5.604E-01,  1.342E+00,  1.505E+00,  1.511E+00,  1.339E+00,  1.188E+00,  1.120E+00,  1.043E+00,  1.090E+00,  1.126E+00,  1.159E+00,  1.179E+00,  1.210E+00,  1.231E+00,  1.259E+00,  1.265E+00,  1.280E+00,  1.279E+00,  1.280E+00,  1.261E+00,  1.269E+00,  1.263E+00,  1.216E+00,  1.158E+00,  1.117E+00,  1.042E+00,  9.759E-01,  9.145E-01,  8.574E-01,  8.281E-01,  7.890E-01,  7.517E-01,  7.487E-01,  7.954E-01,  8.684E-01,  9.680E-01,  1.090E+00,  1.249E+00,  1.407E+00,  1.487E+00,  1.537E+00,  1.485E+00,  1.334E+00,  1.161E+00,  9.685E-01,  7.463E-01,  5.761E-01,  4.040E-01,  2.921E-01,  1.990E-01,  1.370E-01,  9.548E-02,  6.825E-02,  5.148E-02,  3.840E-02,  3.014E-02,  2.454E-02,  1.696E-02,  1.267E-02,  1.055E-02,  9.746E-03,  8.898E-03,  8.372E-03,  8.391E-03,  7.481E-03,  7.044E-03,  5.584E-03,  5.658E-03,  4.883E-03,  4.657E-03,  4.368E-03,  5.942E-03,  }, // TpTp1000.root
{ 2.315E-01,  3.072E+00,  2.850E+00,  2.379E+00,  1.814E+00,  1.427E+00,  1.502E+00,  1.198E+00,  6.637E-01,  1.478E+00,  1.465E+00,  1.593E+00,  1.334E+00,  1.162E+00,  1.089E+00,  1.052E+00,  1.074E+00,  1.133E+00,  1.161E+00,  1.196E+00,  1.212E+00,  1.235E+00,  1.260E+00,  1.276E+00,  1.285E+00,  1.278E+00,  1.270E+00,  1.259E+00,  1.272E+00,  1.265E+00,  1.203E+00,  1.151E+00,  1.119E+00,  1.035E+00,  9.633E-01,  9.135E-01,  8.644E-01,  8.412E-01,  7.865E-01,  7.494E-01,  7.635E-01,  7.874E-01,  8.475E-01,  9.577E-01,  1.104E+00,  1.274E+00,  1.419E+00,  1.490E+00,  1.524E+00,  1.496E+00,  1.342E+00,  1.169E+00,  9.458E-01,  7.514E-01,  5.769E-01,  4.126E-01,  2.925E-01,  2.000E-01,  1.368E-01,  9.616E-02,  6.762E-02,  5.076E-02,  3.781E-02,  2.879E-02,  2.332E-02,  1.717E-02,  1.265E-02,  1.079E-02,  9.486E-03,  9.464E-03,  8.739E-03,  8.339E-03,  8.351E-03,  7.462E-03,  7.104E-03,  5.085E-03,  4.805E-03,  6.677E-03,  5.575E-03,  5.164E-03,  }, // TpTp1100.root
{ 2.174E-01,  2.227E+00,  2.479E+00,  2.328E+00,  1.704E+00,  1.940E+00,  1.549E+00,  1.289E+00,  5.517E-01,  1.441E+00,  1.490E+00,  1.434E+00,  1.362E+00,  1.171E+00,  1.073E+00,  1.050E+00,  1.080E+00,  1.120E+00,  1.159E+00,  1.167E+00,  1.210E+00,  1.239E+00,  1.259E+00,  1.290E+00,  1.269E+00,  1.256E+00,  1.265E+00,  1.263E+00,  1.287E+00,  1.244E+00,  1.225E+00,  1.178E+00,  1.111E+00,  1.037E+00,  9.787E-01,  9.073E-01,  8.541E-01,  8.298E-01,  7.933E-01,  7.530E-01,  7.696E-01,  7.966E-01,  8.582E-01,  9.675E-01,  1.092E+00,  1.266E+00,  1.416E+00,  1.513E+00,  1.557E+00,  1.461E+00,  1.341E+00,  1.135E+00,  9.446E-01,  7.411E-01,  5.572E-01,  4.133E-01,  2.920E-01,  1.992E-01,  1.383E-01,  9.723E-02,  6.830E-02,  5.173E-02,  3.840E-02,  3.008E-02,  2.393E-02,  1.743E-02,  1.259E-02,  1.057E-02,  9.381E-03,  8.891E-03,  8.430E-03,  7.669E-03,  8.314E-03,  8.597E-03,  6.436E-03,  6.161E-03,  5.354E-03,  5.808E-03,  7.759E-03,  4.967E-03,  }, // TpTp1200.root
{ 1.572E-01,  2.823E+00,  3.055E+00,  2.295E+00,  1.478E+00,  1.373E+00,  1.264E+00,  1.132E+00,  6.411E-01,  1.457E+00,  1.430E+00,  1.465E+00,  1.362E+00,  1.154E+00,  1.093E+00,  1.051E+00,  1.061E+00,  1.118E+00,  1.178E+00,  1.191E+00,  1.207E+00,  1.267E+00,  1.251E+00,  1.274E+00,  1.267E+00,  1.288E+00,  1.274E+00,  1.276E+00,  1.269E+00,  1.253E+00,  1.226E+00,  1.163E+00,  1.108E+00,  1.031E+00,  9.792E-01,  9.190E-01,  8.577E-01,  8.364E-01,  7.998E-01,  7.505E-01,  7.587E-01,  7.996E-01,  8.608E-01,  9.585E-01,  1.094E+00,  1.239E+00,  1.403E+00,  1.476E+00,  1.520E+00,  1.470E+00,  1.327E+00,  1.124E+00,  9.653E-01,  7.601E-01,  5.713E-01,  4.137E-01,  2.874E-01,  1.990E-01,  1.410E-01,  9.522E-02,  6.876E-02,  4.921E-02,  3.726E-02,  2.983E-02,  2.373E-02,  1.658E-02,  1.257E-02,  1.075E-02,  9.609E-03,  8.271E-03,  8.340E-03,  8.770E-03,  7.378E-03,  7.303E-03,  5.912E-03,  5.315E-03,  7.372E-03,  6.092E-03,  5.033E-03,  5.305E-03,  }, // TpTp1300.root
{ 2.160E-01,  2.263E+00,  1.119E+01,  2.336E+00,  1.736E+00,  1.510E+00,  1.077E+00,  1.176E+00,  7.053E-01,  1.423E+00,  1.569E+00,  1.440E+00,  1.375E+00,  1.159E+00,  1.075E+00,  1.069E+00,  1.062E+00,  1.133E+00,  1.158E+00,  1.204E+00,  1.216E+00,  1.240E+00,  1.263E+00,  1.282E+00,  1.286E+00,  1.287E+00,  1.260E+00,  1.280E+00,  1.266E+00,  1.247E+00,  1.234E+00,  1.178E+00,  1.121E+00,  1.030E+00,  9.682E-01,  9.054E-01,  8.685E-01,  8.296E-01,  7.917E-01,  7.498E-01,  7.487E-01,  7.899E-01,  8.571E-01,  9.687E-01,  1.098E+00,  1.254E+00,  1.410E+00,  1.492E+00,  1.542E+00,  1.455E+00,  1.350E+00,  1.139E+00,  9.516E-01,  7.482E-01,  5.658E-01,  4.106E-01,  2.926E-01,  1.957E-01,  1.395E-01,  9.392E-02,  6.780E-02,  5.034E-02,  3.757E-02,  3.000E-02,  2.382E-02,  1.738E-02,  1.216E-02,  1.105E-02,  9.388E-03,  8.357E-03,  8.885E-03,  8.099E-03,  7.050E-03,  6.724E-03,  6.228E-03,  4.828E-03,  5.222E-03,  5.245E-03,  7.617E-03,  7.289E-03,  }, // TpTp1400.root
{ 2.423E-01,  4.315E+00,  2.464E+00,  2.864E+00,  1.174E+00,  1.485E+00,  1.268E+00,  1.222E+00,  5.845E-01,  1.453E+00,  1.426E+00,  1.488E+00,  1.321E+00,  1.167E+00,  1.076E+00,  1.052E+00,  1.066E+00,  1.122E+00,  1.151E+00,  1.206E+00,  1.209E+00,  1.239E+00,  1.250E+00,  1.286E+00,  1.282E+00,  1.269E+00,  1.251E+00,  1.263E+00,  1.273E+00,  1.269E+00,  1.204E+00,  1.178E+00,  1.108E+00,  1.043E+00,  9.572E-01,  9.212E-01,  8.694E-01,  8.428E-01,  7.893E-01,  7.578E-01,  7.580E-01,  7.940E-01,  8.664E-01,  9.559E-01,  1.096E+00,  1.248E+00,  1.412E+00,  1.500E+00,  1.509E+00,  1.463E+00,  1.369E+00,  1.149E+00,  9.606E-01,  7.550E-01,  5.693E-01,  4.126E-01,  2.883E-01,  1.976E-01,  1.379E-01,  9.559E-02,  6.876E-02,  5.059E-02,  3.842E-02,  3.008E-02,  2.387E-02,  1.667E-02,  1.304E-02,  1.021E-02,  1.031E-02,  8.361E-03,  8.001E-03,  8.146E-03,  7.446E-03,  8.348E-03,  5.815E-03,  4.387E-03,  4.728E-03,  6.252E-03,  4.515E-03,  5.561E-03,  }, // TpTp1500.root
{ 1.617E-01,  4.064E+00,  2.742E+00,  2.266E+00,  1.559E+00,  1.377E+00,  1.402E+00,  1.178E+00,  6.902E-01,  1.501E+00,  1.659E+00,  1.587E+00,  1.368E+00,  1.170E+00,  1.114E+00,  1.061E+00,  1.092E+00,  1.130E+00,  1.172E+00,  1.207E+00,  1.183E+00,  1.234E+00,  1.261E+00,  1.254E+00,  1.287E+00,  1.263E+00,  1.272E+00,  1.246E+00,  1.266E+00,  1.262E+00,  1.218E+00,  1.166E+00,  1.121E+00,  1.039E+00,  9.762E-01,  8.993E-01,  8.753E-01,  8.349E-01,  7.893E-01,  7.575E-01,  7.539E-01,  7.984E-01,  8.531E-01,  9.740E-01,  1.119E+00,  1.251E+00,  1.404E+00,  1.488E+00,  1.556E+00,  1.446E+00,  1.355E+00,  1.132E+00,  9.286E-01,  7.537E-01,  5.683E-01,  4.106E-01,  2.881E-01,  1.966E-01,  1.355E-01,  9.763E-02,  6.776E-02,  5.132E-02,  3.890E-02,  2.995E-02,  2.371E-02,  1.746E-02,  1.324E-02,  1.051E-02,  9.834E-03,  8.969E-03,  7.766E-03,  7.762E-03,  8.075E-03,  9.524E-03,  8.243E-03,  5.045E-03,  5.098E-03,  4.711E-03,  4.371E-03,  6.547E-03,  }, // TpTp1600.root
{ 3.073E-01,  2.023E+00,  2.628E+00,  2.467E+00,  1.432E+00,  1.146E+00,  1.139E+00,  1.750E+00,  5.444E-01,  1.307E+00,  1.464E+00,  1.483E+00,  1.358E+00,  1.188E+00,  1.069E+00,  1.036E+00,  1.110E+00,  1.127E+00,  1.156E+00,  1.209E+00,  1.195E+00,  1.237E+00,  1.262E+00,  1.289E+00,  1.287E+00,  1.264E+00,  1.262E+00,  1.249E+00,  1.281E+00,  1.250E+00,  1.228E+00,  1.186E+00,  1.097E+00,  1.033E+00,  9.705E-01,  9.052E-01,  8.553E-01,  8.536E-01,  7.986E-01,  7.560E-01,  7.652E-01,  8.156E-01,  8.463E-01,  9.698E-01,  1.088E+00,  1.243E+00,  1.417E+00,  1.469E+00,  1.544E+00,  1.439E+00,  1.331E+00,  1.134E+00,  9.276E-01,  7.655E-01,  5.659E-01,  4.075E-01,  2.903E-01,  1.991E-01,  1.353E-01,  9.565E-02,  6.819E-02,  5.082E-02,  3.936E-02,  2.947E-02,  2.426E-02,  1.780E-02,  1.251E-02,  1.031E-02,  1.034E-02,  9.703E-03,  8.115E-03,  7.457E-03,  6.907E-03,  6.714E-03,  5.733E-03,  7.032E-03,  5.893E-03,  4.560E-03,  7.615E-03,  4.148E-03,  }, // TpTp1700.root
{ 1.575E-01,  2.376E+00,  5.511E+00,  4.140E+00,  2.222E+00,  1.022E+00,  1.414E+00,  1.012E+00,  5.570E-01,  1.627E+00,  1.349E+00,  1.507E+00,  1.347E+00,  1.251E+00,  1.103E+00,  1.054E+00,  1.092E+00,  1.122E+00,  1.182E+00,  1.167E+00,  1.212E+00,  1.234E+00,  1.264E+00,  1.287E+00,  1.260E+00,  1.284E+00,  1.277E+00,  1.250E+00,  1.300E+00,  1.262E+00,  1.246E+00,  1.159E+00,  1.099E+00,  1.041E+00,  9.627E-01,  9.212E-01,  8.749E-01,  8.307E-01,  7.929E-01,  7.360E-01,  7.686E-01,  7.892E-01,  8.466E-01,  9.500E-01,  1.047E+00,  1.288E+00,  1.426E+00,  1.505E+00,  1.517E+00,  1.455E+00,  1.287E+00,  1.121E+00,  9.316E-01,  7.538E-01,  5.805E-01,  4.069E-01,  2.963E-01,  1.982E-01,  1.402E-01,  9.389E-02,  6.983E-02,  5.031E-02,  3.893E-02,  3.000E-02,  2.573E-02,  1.678E-02,  1.244E-02,  1.088E-02,  9.356E-03,  8.698E-03,  8.022E-03,  6.875E-03,  1.100E-02,  9.955E-03,  7.337E-03,  4.677E-03,  6.427E-03,  6.148E-03,  8.214E-03,  3.827E-03,  }, // TpTp1800.root
};

   pileupweightDn = { // 69.2 - 4.6%
{ 1.849e-01,  4.546e+00,  4.543e+00,  2.289e+00,  1.790e+00,  1.736e+00,  1.351e+00,  1.406e+00,  9.077e-01,  2.178e+00,  2.154e+00,  2.059e+00,  1.735e+00,  1.537e+00,  1.440e+00,  1.422e+00,  1.442e+00,  1.430e+00,  1.421e+00,  1.408e+00,  1.390e+00,  1.387e+00,  1.394e+00,  1.394e+00,  1.394e+00,  1.383e+00,  1.362e+00,  1.328e+00,  1.308e+00,  1.255e+00,  1.205e+00,  1.126e+00,  1.042e+00,  9.563e-01,  8.764e-01,  8.178e-01,  7.734e-01,  7.459e-01,  7.142e-01,  7.034e-01,  7.467e-01,  8.275e-01,  9.439e-01,  1.091e+00,  1.244e+00,  1.390e+00,  1.483e+00,  1.436e+00,  1.323e+00,  1.126e+00,  9.070e-01,  6.905e-01,  5.005e-01,  3.506e-01,  2.385e-01,  1.551e-01,  9.946e-02,  6.288e-02,  4.082e-02,  2.687e-02,  1.838e-02,  1.290e-02,  9.519e-03,  7.319e-03,  5.804e-03,  4.141e-03,  3.024e-03,  2.641e-03,  2.421e-03,  2.270e-03,  2.104e-03,  2.072e-03,  2.022e-03,  2.004e-03,  1.600e-03,  1.297e-03,  1.253e-03,  1.307e-03,  1.199e-03,  1.355e-03,  1.286e-03,  1.142e-03,  1.352e-03,  8.874e-04,  7.679e-04,  1.020e-03,  5.594e-04,  8.497e-04,  6.427e-04,  6.547e-04,  1.508e-03,  4.294e-04,  9.676e-05,  2.695e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 2.015e-01,  5.547e+00,  4.734e+00,  2.499e+00,  1.771e+00,  1.687e+00,  1.320e+00,  1.391e+00,  8.830e-01,  2.174e+00,  2.157e+00,  2.061e+00,  1.752e+00,  1.538e+00,  1.437e+00,  1.426e+00,  1.442e+00,  1.430e+00,  1.424e+00,  1.406e+00,  1.391e+00,  1.388e+00,  1.388e+00,  1.392e+00,  1.390e+00,  1.379e+00,  1.360e+00,  1.325e+00,  1.309e+00,  1.258e+00,  1.203e+00,  1.125e+00,  1.045e+00,  9.559e-01,  8.765e-01,  8.190e-01,  7.735e-01,  7.475e-01,  7.156e-01,  7.055e-01,  7.481e-01,  8.270e-01,  9.431e-01,  1.089e+00,  1.252e+00,  1.400e+00,  1.485e+00,  1.419e+00,  1.322e+00,  1.126e+00,  9.058e-01,  6.869e-01,  5.001e-01,  3.495e-01,  2.375e-01,  1.547e-01,  9.955e-02,  6.342e-02,  4.070e-02,  2.709e-02,  1.830e-02,  1.295e-02,  9.521e-03,  7.234e-03,  5.824e-03,  4.128e-03,  3.050e-03,  2.650e-03,  2.401e-03,  2.270e-03,  2.120e-03,  2.039e-03,  2.059e-03,  2.015e-03,  1.553e-03,  1.259e-03,  1.302e-03,  1.266e-03,  1.258e-03,  1.162e-03,  1.166e-03,  1.148e-03,  1.199e-03,  9.624e-04,  6.856e-04,  6.572e-04,  8.739e-04,  6.061e-04,  5.348e-04,  4.151e-04,  2.868e-04,  2.042e-04,  1.534e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 2.129e-01,  4.117e+00,  4.330e+00,  2.700e+00,  2.026e+00,  1.661e+00,  1.316e+00,  1.443e+00,  8.735e-01,  2.150e+00,  2.207e+00,  2.067e+00,  1.749e+00,  1.534e+00,  1.442e+00,  1.416e+00,  1.433e+00,  1.431e+00,  1.424e+00,  1.414e+00,  1.398e+00,  1.392e+00,  1.394e+00,  1.387e+00,  1.391e+00,  1.379e+00,  1.362e+00,  1.326e+00,  1.304e+00,  1.255e+00,  1.205e+00,  1.124e+00,  1.043e+00,  9.580e-01,  8.783e-01,  8.177e-01,  7.725e-01,  7.466e-01,  7.158e-01,  7.045e-01,  7.462e-01,  8.283e-01,  9.458e-01,  1.090e+00,  1.251e+00,  1.395e+00,  1.485e+00,  1.435e+00,  1.320e+00,  1.119e+00,  9.050e-01,  6.895e-01,  5.004e-01,  3.493e-01,  2.380e-01,  1.548e-01,  9.949e-02,  6.305e-02,  4.065e-02,  2.695e-02,  1.841e-02,  1.297e-02,  9.470e-03,  7.265e-03,  5.832e-03,  4.139e-03,  3.047e-03,  2.647e-03,  2.407e-03,  2.269e-03,  2.121e-03,  2.085e-03,  1.936e-03,  1.982e-03,  1.528e-03,  1.324e-03,  1.247e-03,  1.286e-03,  1.371e-03,  1.129e-03,  1.223e-03,  1.413e-03,  1.263e-03,  8.221e-04,  6.106e-04,  7.567e-04,  6.148e-04,  5.177e-04,  7.310e-04,  4.255e-04,  1.225e-03,  6.977e-04,  3.930e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 2.014e-01,  6.867e+00,  5.585e+00,  2.447e+00,  2.035e+00,  1.653e+00,  1.456e+00,  1.656e+00,  9.039e-01,  2.215e+00,  2.221e+00,  2.063e+00,  1.700e+00,  1.547e+00,  1.440e+00,  1.414e+00,  1.418e+00,  1.439e+00,  1.424e+00,  1.404e+00,  1.395e+00,  1.386e+00,  1.393e+00,  1.398e+00,  1.396e+00,  1.379e+00,  1.362e+00,  1.318e+00,  1.310e+00,  1.261e+00,  1.200e+00,  1.123e+00,  1.044e+00,  9.583e-01,  8.776e-01,  8.186e-01,  7.764e-01,  7.431e-01,  7.154e-01,  7.037e-01,  7.419e-01,  8.343e-01,  9.451e-01,  1.090e+00,  1.252e+00,  1.391e+00,  1.485e+00,  1.424e+00,  1.321e+00,  1.120e+00,  9.150e-01,  6.909e-01,  4.986e-01,  3.523e-01,  2.354e-01,  1.541e-01,  9.951e-02,  6.362e-02,  4.062e-02,  2.701e-02,  1.840e-02,  1.295e-02,  9.612e-03,  7.223e-03,  5.847e-03,  4.108e-03,  3.025e-03,  2.707e-03,  2.422e-03,  2.205e-03,  2.107e-03,  2.048e-03,  2.039e-03,  2.029e-03,  1.454e-03,  1.223e-03,  1.354e-03,  1.250e-03,  1.229e-03,  1.062e-03,  1.227e-03,  1.029e-03,  1.283e-03,  8.767e-04,  4.435e-04,  5.625e-04,  1.238e-03,  7.362e-04,  6.496e-04,  7.562e-04,  4.355e-04,  8.268e-05,  6.986e-05,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 5.442e-04,  1.917e-01,  8.522e-02,  1.016e-01,  8.975e-02,  7.892e-02,  5.881e-02,  1.769e-01,  1.507e-01,  4.431e-01,  7.086e-01,  1.173e+00,  8.420e-01,  8.414e-01,  8.254e-01,  8.910e-01,  1.038e+00,  1.155e+00,  1.307e+00,  1.285e+00,  1.392e+00,  1.404e+00,  1.433e+00,  1.450e+00,  1.482e+00,  1.490e+00,  1.257e+00,  1.452e+00,  1.450e+00,  1.402e+00,  1.319e+00,  1.238e+00,  1.125e+00,  1.023e+00,  9.612e-01,  8.986e-01,  8.495e-01,  8.262e-01,  7.515e-01,  7.846e-01,  7.553e-01,  9.243e-01,  9.966e-01,  1.218e+00,  1.403e+00,  1.561e+00,  1.610e+00,  1.611e+00,  1.502e+00,  1.262e+00,  9.683e-01,  7.556e-01,  5.432e-01,  3.836e-01,  2.596e-01,  1.528e-01,  1.069e-01,  6.729e-02,  4.427e-02,  2.538e-02,  1.990e-02,  1.376e-02,  1.016e-02,  7.047e-03,  6.298e-03,  4.594e-03,  3.170e-03,  2.830e-03,  2.643e-03,  2.578e-03,  2.397e-03,  1.865e-03,  2.800e-04,  2.177e-03,  1.168e-04,  1.525e-03,  1.291e-03,  1.170e-03,  5.334e-05,  2.415e-05,  1.960e-03,  2.975e-04,  1.345e-03,  4.157e-04,  2.037e-03,  6.177e-04,  0.000e+00,  4.410e-04,  1.880e-06,  0.000e+00,  8.695e-05,  0.000e+00,  0.000e+00,  1.554e-05,  0.000e+00,  0.000e+00,  2.511e-06,  1.336e-06,  0.000e+00,  1.109e-08,  0.000e+00,  }, // DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 2.615e-01,  3.865e+00,  6.348e+00,  3.921e+00,  1.808e+00,  1.667e+00,  1.183e+00,  1.396e+00,  1.035e+00,  2.259e+00,  2.045e+00,  2.073e+00,  1.697e+00,  1.506e+00,  1.451e+00,  1.457e+00,  1.465e+00,  1.422e+00,  1.401e+00,  1.392e+00,  1.387e+00,  1.372e+00,  1.381e+00,  1.399e+00,  1.403e+00,  1.392e+00,  1.361e+00,  1.350e+00,  1.307e+00,  1.242e+00,  1.225e+00,  1.110e+00,  1.055e+00,  9.634e-01,  8.820e-01,  8.264e-01,  7.880e-01,  7.423e-01,  7.137e-01,  6.859e-01,  7.409e-01,  8.312e-01,  9.370e-01,  1.090e+00,  1.267e+00,  1.383e+00,  1.493e+00,  1.436e+00,  1.301e+00,  1.130e+00,  8.897e-01,  6.779e-01,  5.067e-01,  3.527e-01,  2.385e-01,  1.569e-01,  9.719e-02,  6.225e-02,  4.128e-02,  2.670e-02,  1.838e-02,  1.288e-02,  9.458e-03,  7.347e-03,  5.697e-03,  4.012e-03,  3.080e-03,  2.696e-03,  2.442e-03,  2.249e-03,  2.201e-03,  2.229e-03,  2.048e-03,  1.997e-03,  1.499e-03,  1.196e-03,  9.802e-04,  1.038e-03,  9.181e-04,  1.280e-03,  1.275e-03,  9.355e-04,  1.167e-03,  5.409e-04,  4.417e-04,  0.000e+00,  4.826e-04,  2.869e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.251e-01,  4.253e+00,  3.492e+00,  2.043e+00,  1.604e+00,  1.884e+00,  1.037e+00,  1.313e+00,  9.244e-01,  2.366e+00,  2.117e+00,  2.126e+00,  1.867e+00,  1.542e+00,  1.503e+00,  1.417e+00,  1.427e+00,  1.431e+00,  1.460e+00,  1.385e+00,  1.389e+00,  1.399e+00,  1.395e+00,  1.393e+00,  1.412e+00,  1.391e+00,  1.361e+00,  1.332e+00,  1.311e+00,  1.260e+00,  1.188e+00,  1.130e+00,  1.054e+00,  9.543e-01,  8.923e-01,  8.015e-01,  7.676e-01,  7.641e-01,  7.249e-01,  6.891e-01,  7.425e-01,  8.105e-01,  9.428e-01,  1.061e+00,  1.253e+00,  1.403e+00,  1.508e+00,  1.425e+00,  1.334e+00,  1.121e+00,  8.885e-01,  6.830e-01,  5.140e-01,  3.482e-01,  2.328e-01,  1.493e-01,  9.857e-02,  6.193e-02,  4.124e-02,  2.697e-02,  1.897e-02,  1.327e-02,  9.227e-03,  7.136e-03,  6.207e-03,  4.300e-03,  3.053e-03,  2.754e-03,  2.110e-03,  2.073e-03,  1.878e-03,  1.941e-03,  2.063e-03,  2.346e-03,  1.191e-03,  1.178e-03,  1.324e-03,  1.142e-03,  1.154e-03,  8.150e-04,  9.818e-04,  8.822e-04,  9.628e-04,  2.381e-03,  4.859e-04,  4.421e-04,  5.310e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTWJetsToQQ_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8_hadd.root
{ 2.047e-01,  4.445e+00,  4.178e+00,  2.495e+00,  1.855e+00,  1.660e+00,  1.368e+00,  1.440e+00,  8.912e-01,  2.230e+00,  2.181e+00,  2.066e+00,  1.744e+00,  1.530e+00,  1.444e+00,  1.418e+00,  1.435e+00,  1.434e+00,  1.422e+00,  1.406e+00,  1.393e+00,  1.389e+00,  1.390e+00,  1.395e+00,  1.390e+00,  1.375e+00,  1.362e+00,  1.330e+00,  1.307e+00,  1.258e+00,  1.203e+00,  1.123e+00,  1.044e+00,  9.555e-01,  8.772e-01,  8.168e-01,  7.737e-01,  7.470e-01,  7.161e-01,  7.045e-01,  7.466e-01,  8.278e-01,  9.446e-01,  1.092e+00,  1.251e+00,  1.394e+00,  1.486e+00,  1.442e+00,  1.321e+00,  1.128e+00,  9.060e-01,  6.908e-01,  5.000e-01,  3.499e-01,  2.385e-01,  1.549e-01,  9.973e-02,  6.280e-02,  4.075e-02,  2.693e-02,  1.833e-02,  1.291e-02,  9.491e-03,  7.256e-03,  5.796e-03,  4.117e-03,  3.050e-03,  2.660e-03,  2.397e-03,  2.220e-03,  2.128e-03,  2.024e-03,  1.974e-03,  1.958e-03,  1.565e-03,  1.305e-03,  1.271e-03,  1.201e-03,  1.321e-03,  1.156e-03,  1.207e-03,  1.173e-03,  1.108e-03,  7.862e-04,  7.191e-04,  6.219e-04,  7.202e-04,  5.449e-04,  5.877e-04,  4.561e-04,  2.955e-04,  6.731e-04,  1.517e-04,  4.225e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT1000to1500_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.829e-01,  4.618e+00,  4.523e+00,  2.588e+00,  1.911e+00,  1.646e+00,  1.310e+00,  1.398e+00,  8.685e-01,  2.119e+00,  2.192e+00,  2.076e+00,  1.735e+00,  1.532e+00,  1.443e+00,  1.420e+00,  1.437e+00,  1.432e+00,  1.421e+00,  1.410e+00,  1.394e+00,  1.392e+00,  1.385e+00,  1.393e+00,  1.394e+00,  1.383e+00,  1.362e+00,  1.330e+00,  1.312e+00,  1.256e+00,  1.202e+00,  1.126e+00,  1.044e+00,  9.529e-01,  8.787e-01,  8.160e-01,  7.746e-01,  7.455e-01,  7.141e-01,  7.043e-01,  7.484e-01,  8.263e-01,  9.432e-01,  1.088e+00,  1.250e+00,  1.393e+00,  1.479e+00,  1.433e+00,  1.319e+00,  1.129e+00,  9.066e-01,  6.883e-01,  5.019e-01,  3.495e-01,  2.380e-01,  1.553e-01,  9.900e-02,  6.291e-02,  4.064e-02,  2.701e-02,  1.834e-02,  1.293e-02,  9.552e-03,  7.268e-03,  5.805e-03,  4.131e-03,  3.057e-03,  2.669e-03,  2.411e-03,  2.259e-03,  2.084e-03,  2.082e-03,  1.997e-03,  1.948e-03,  1.537e-03,  1.267e-03,  1.310e-03,  1.370e-03,  1.330e-03,  1.285e-03,  1.230e-03,  1.288e-03,  1.141e-03,  6.818e-04,  8.836e-04,  7.682e-04,  5.126e-04,  7.479e-04,  5.377e-04,  3.521e-04,  4.055e-04,  3.079e-04,  5.204e-04,  2.899e-04,  7.985e-05,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT1500to2000_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.750e-01,  4.429e+00,  4.725e+00,  2.462e+00,  1.740e+00,  1.666e+00,  1.353e+00,  1.390e+00,  8.748e-01,  2.167e+00,  2.192e+00,  2.071e+00,  1.754e+00,  1.546e+00,  1.449e+00,  1.421e+00,  1.437e+00,  1.433e+00,  1.428e+00,  1.399e+00,  1.385e+00,  1.386e+00,  1.391e+00,  1.395e+00,  1.390e+00,  1.382e+00,  1.361e+00,  1.329e+00,  1.312e+00,  1.256e+00,  1.198e+00,  1.119e+00,  1.042e+00,  9.544e-01,  8.772e-01,  8.207e-01,  7.713e-01,  7.479e-01,  7.153e-01,  7.050e-01,  7.503e-01,  8.277e-01,  9.443e-01,  1.095e+00,  1.250e+00,  1.392e+00,  1.487e+00,  1.450e+00,  1.327e+00,  1.120e+00,  9.107e-01,  6.889e-01,  4.985e-01,  3.520e-01,  2.368e-01,  1.542e-01,  9.906e-02,  6.327e-02,  4.071e-02,  2.683e-02,  1.830e-02,  1.298e-02,  9.548e-03,  7.284e-03,  5.854e-03,  4.086e-03,  3.046e-03,  2.670e-03,  2.459e-03,  2.202e-03,  2.128e-03,  2.124e-03,  1.953e-03,  1.979e-03,  1.489e-03,  1.234e-03,  1.313e-03,  1.240e-03,  1.447e-03,  1.141e-03,  1.136e-03,  1.148e-03,  9.771e-04,  8.053e-04,  5.495e-04,  7.291e-04,  1.001e-03,  1.388e-03,  3.062e-04,  3.565e-04,  2.737e-04,  4.676e-04,  1.317e-04,  4.892e-05,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT2000toInf_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.893e-01,  4.394e+00,  4.750e+00,  2.470e+00,  1.883e+00,  1.729e+00,  1.328e+00,  1.391e+00,  8.950e-01,  2.170e+00,  2.180e+00,  2.070e+00,  1.746e+00,  1.537e+00,  1.441e+00,  1.425e+00,  1.435e+00,  1.434e+00,  1.424e+00,  1.407e+00,  1.394e+00,  1.389e+00,  1.392e+00,  1.393e+00,  1.392e+00,  1.381e+00,  1.360e+00,  1.329e+00,  1.307e+00,  1.258e+00,  1.204e+00,  1.126e+00,  1.043e+00,  9.544e-01,  8.763e-01,  8.169e-01,  7.725e-01,  7.466e-01,  7.170e-01,  7.035e-01,  7.463e-01,  8.270e-01,  9.443e-01,  1.091e+00,  1.248e+00,  1.392e+00,  1.484e+00,  1.434e+00,  1.320e+00,  1.124e+00,  9.091e-01,  6.887e-01,  5.021e-01,  3.506e-01,  2.378e-01,  1.542e-01,  9.967e-02,  6.299e-02,  4.074e-02,  2.689e-02,  1.838e-02,  1.293e-02,  9.511e-03,  7.283e-03,  5.808e-03,  4.123e-03,  3.046e-03,  2.648e-03,  2.410e-03,  2.226e-03,  2.111e-03,  2.050e-03,  2.009e-03,  1.980e-03,  1.580e-03,  1.299e-03,  1.286e-03,  1.251e-03,  1.273e-03,  1.312e-03,  1.199e-03,  1.103e-03,  1.214e-03,  8.328e-04,  6.626e-04,  6.791e-04,  6.279e-04,  6.590e-04,  6.530e-04,  5.158e-04,  5.544e-04,  3.158e-04,  1.779e-04,  4.955e-04,  8.188e-04,  7.433e-05,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT200to300_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.945e-01,  4.485e+00,  4.720e+00,  2.452e+00,  1.819e+00,  1.667e+00,  1.353e+00,  1.433e+00,  8.940e-01,  2.163e+00,  2.194e+00,  2.062e+00,  1.737e+00,  1.535e+00,  1.437e+00,  1.425e+00,  1.435e+00,  1.433e+00,  1.424e+00,  1.406e+00,  1.394e+00,  1.390e+00,  1.392e+00,  1.392e+00,  1.391e+00,  1.380e+00,  1.362e+00,  1.329e+00,  1.309e+00,  1.257e+00,  1.201e+00,  1.125e+00,  1.043e+00,  9.540e-01,  8.766e-01,  8.173e-01,  7.734e-01,  7.464e-01,  7.162e-01,  7.046e-01,  7.462e-01,  8.265e-01,  9.455e-01,  1.092e+00,  1.247e+00,  1.395e+00,  1.485e+00,  1.433e+00,  1.321e+00,  1.124e+00,  9.070e-01,  6.883e-01,  5.020e-01,  3.505e-01,  2.378e-01,  1.548e-01,  9.972e-02,  6.302e-02,  4.066e-02,  2.694e-02,  1.839e-02,  1.297e-02,  9.508e-03,  7.289e-03,  5.803e-03,  4.132e-03,  3.044e-03,  2.646e-03,  2.405e-03,  2.230e-03,  2.109e-03,  2.068e-03,  2.004e-03,  1.982e-03,  1.531e-03,  1.294e-03,  1.289e-03,  1.282e-03,  1.244e-03,  1.238e-03,  1.257e-03,  1.216e-03,  1.101e-03,  8.458e-04,  6.793e-04,  6.471e-04,  5.720e-04,  6.855e-04,  5.209e-04,  4.695e-04,  2.993e-04,  2.983e-04,  1.680e-04,  1.872e-04,  8.251e-04,  2.247e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT300to500_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.918e-01,  4.239e+00,  4.483e+00,  2.480e+00,  1.854e+00,  1.692e+00,  1.379e+00,  1.441e+00,  8.941e-01,  2.161e+00,  2.208e+00,  2.072e+00,  1.746e+00,  1.535e+00,  1.440e+00,  1.419e+00,  1.432e+00,  1.434e+00,  1.428e+00,  1.407e+00,  1.393e+00,  1.387e+00,  1.390e+00,  1.393e+00,  1.395e+00,  1.383e+00,  1.361e+00,  1.329e+00,  1.309e+00,  1.256e+00,  1.201e+00,  1.126e+00,  1.041e+00,  9.551e-01,  8.774e-01,  8.169e-01,  7.739e-01,  7.461e-01,  7.151e-01,  7.037e-01,  7.467e-01,  8.262e-01,  9.456e-01,  1.091e+00,  1.251e+00,  1.395e+00,  1.480e+00,  1.435e+00,  1.325e+00,  1.123e+00,  9.082e-01,  6.897e-01,  5.010e-01,  3.501e-01,  2.378e-01,  1.548e-01,  9.977e-02,  6.294e-02,  4.068e-02,  2.685e-02,  1.835e-02,  1.296e-02,  9.501e-03,  7.286e-03,  5.804e-03,  4.125e-03,  3.039e-03,  2.665e-03,  2.404e-03,  2.226e-03,  2.132e-03,  2.058e-03,  2.003e-03,  1.985e-03,  1.571e-03,  1.283e-03,  1.291e-03,  1.281e-03,  1.270e-03,  1.285e-03,  1.246e-03,  1.200e-03,  1.111e-03,  8.939e-04,  6.538e-04,  6.927e-04,  5.760e-04,  6.069e-04,  4.532e-04,  4.425e-04,  3.590e-04,  3.749e-04,  2.304e-04,  1.569e-04,  3.888e-04,  2.118e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT500to700_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.966e-01,  4.224e+00,  4.203e+00,  2.372e+00,  1.893e+00,  1.666e+00,  1.360e+00,  1.390e+00,  8.999e-01,  2.170e+00,  2.194e+00,  2.073e+00,  1.738e+00,  1.535e+00,  1.442e+00,  1.423e+00,  1.431e+00,  1.436e+00,  1.425e+00,  1.409e+00,  1.393e+00,  1.393e+00,  1.389e+00,  1.392e+00,  1.389e+00,  1.381e+00,  1.363e+00,  1.329e+00,  1.308e+00,  1.255e+00,  1.201e+00,  1.125e+00,  1.043e+00,  9.549e-01,  8.776e-01,  8.168e-01,  7.737e-01,  7.485e-01,  7.156e-01,  7.031e-01,  7.461e-01,  8.273e-01,  9.468e-01,  1.090e+00,  1.252e+00,  1.391e+00,  1.486e+00,  1.435e+00,  1.322e+00,  1.124e+00,  9.096e-01,  6.901e-01,  5.010e-01,  3.497e-01,  2.375e-01,  1.548e-01,  9.942e-02,  6.312e-02,  4.066e-02,  2.684e-02,  1.838e-02,  1.298e-02,  9.500e-03,  7.280e-03,  5.790e-03,  4.127e-03,  3.032e-03,  2.641e-03,  2.419e-03,  2.232e-03,  2.133e-03,  2.063e-03,  2.021e-03,  1.935e-03,  1.542e-03,  1.270e-03,  1.280e-03,  1.279e-03,  1.263e-03,  1.269e-03,  1.216e-03,  1.157e-03,  1.256e-03,  8.823e-04,  6.637e-04,  6.671e-04,  5.291e-04,  5.953e-04,  5.943e-04,  4.077e-04,  2.629e-04,  2.880e-04,  1.406e-04,  9.791e-05,  2.157e-04,  1.175e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT700to1000_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.886e-01,  6.561e+00,  3.592e+00,  2.338e+00,  1.837e+00,  1.607e+00,  1.395e+00,  1.378e+00,  8.878e-01,  2.156e+00,  2.312e+00,  2.054e+00,  1.756e+00,  1.538e+00,  1.444e+00,  1.424e+00,  1.449e+00,  1.434e+00,  1.422e+00,  1.405e+00,  1.399e+00,  1.383e+00,  1.386e+00,  1.388e+00,  1.397e+00,  1.382e+00,  1.362e+00,  1.329e+00,  1.304e+00,  1.253e+00,  1.203e+00,  1.124e+00,  1.047e+00,  9.556e-01,  8.779e-01,  8.150e-01,  7.719e-01,  7.478e-01,  7.130e-01,  7.041e-01,  7.459e-01,  8.284e-01,  9.457e-01,  1.094e+00,  1.250e+00,  1.394e+00,  1.484e+00,  1.449e+00,  1.314e+00,  1.122e+00,  9.105e-01,  6.921e-01,  4.975e-01,  3.487e-01,  2.371e-01,  1.547e-01,  1.002e-01,  6.301e-02,  4.078e-02,  2.688e-02,  1.836e-02,  1.313e-02,  9.521e-03,  7.269e-03,  5.773e-03,  4.099e-03,  3.007e-03,  2.591e-03,  2.423e-03,  2.218e-03,  2.096e-03,  2.127e-03,  2.019e-03,  1.952e-03,  1.503e-03,  1.382e-03,  1.285e-03,  1.362e-03,  1.409e-03,  1.113e-03,  1.459e-03,  1.007e-03,  1.717e-03,  7.579e-04,  1.083e-03,  5.912e-04,  7.100e-04,  5.276e-04,  6.207e-04,  1.806e-04,  4.161e-04,  1.185e-04,  1.335e-04,  7.437e-05,  0.000e+00,  2.231e-05,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_s-channel_antitop_leptonDecays_13TeV-PSweights_powheg-pythia_hadd.root
{ 1.827e-01,  4.239e+00,  4.641e+00,  2.323e+00,  1.844e+00,  1.739e+00,  1.380e+00,  1.413e+00,  8.784e-01,  2.175e+00,  2.196e+00,  2.049e+00,  1.728e+00,  1.525e+00,  1.442e+00,  1.424e+00,  1.439e+00,  1.425e+00,  1.431e+00,  1.411e+00,  1.390e+00,  1.388e+00,  1.391e+00,  1.395e+00,  1.391e+00,  1.377e+00,  1.362e+00,  1.331e+00,  1.304e+00,  1.257e+00,  1.202e+00,  1.126e+00,  1.044e+00,  9.607e-01,  8.777e-01,  8.180e-01,  7.735e-01,  7.484e-01,  7.144e-01,  7.056e-01,  7.449e-01,  8.301e-01,  9.445e-01,  1.085e+00,  1.247e+00,  1.396e+00,  1.489e+00,  1.427e+00,  1.315e+00,  1.125e+00,  9.113e-01,  6.905e-01,  4.975e-01,  3.530e-01,  2.382e-01,  1.540e-01,  9.892e-02,  6.298e-02,  4.062e-02,  2.670e-02,  1.835e-02,  1.291e-02,  9.459e-03,  7.347e-03,  5.813e-03,  4.126e-03,  3.059e-03,  2.672e-03,  2.425e-03,  2.216e-03,  2.167e-03,  2.078e-03,  2.058e-03,  1.998e-03,  1.530e-03,  1.301e-03,  1.376e-03,  1.242e-03,  1.133e-03,  1.197e-03,  1.369e-03,  1.252e-03,  1.337e-03,  1.093e-03,  7.851e-04,  6.575e-04,  5.183e-04,  7.042e-04,  4.833e-04,  3.376e-04,  9.719e-04,  2.768e-04,  3.118e-04,  8.686e-05,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_s-channel_top_leptonDecays_13TeV-PSweights_powheg-pythia_hadd.root
{ 1.937e-01,  4.285e+00,  4.608e+00,  2.469e+00,  1.844e+00,  1.705e+00,  1.365e+00,  1.423e+00,  8.858e-01,  2.176e+00,  2.193e+00,  2.060e+00,  1.747e+00,  1.538e+00,  1.440e+00,  1.420e+00,  1.430e+00,  1.433e+00,  1.426e+00,  1.409e+00,  1.393e+00,  1.389e+00,  1.392e+00,  1.394e+00,  1.392e+00,  1.381e+00,  1.360e+00,  1.329e+00,  1.311e+00,  1.258e+00,  1.201e+00,  1.125e+00,  1.042e+00,  9.546e-01,  8.770e-01,  8.178e-01,  7.731e-01,  7.461e-01,  7.151e-01,  7.038e-01,  7.467e-01,  8.259e-01,  9.447e-01,  1.090e+00,  1.251e+00,  1.393e+00,  1.483e+00,  1.436e+00,  1.322e+00,  1.126e+00,  9.080e-01,  6.916e-01,  5.002e-01,  3.495e-01,  2.377e-01,  1.547e-01,  9.960e-02,  6.302e-02,  4.066e-02,  2.687e-02,  1.834e-02,  1.295e-02,  9.497e-03,  7.302e-03,  5.810e-03,  4.134e-03,  3.040e-03,  2.661e-03,  2.414e-03,  2.228e-03,  2.119e-03,  2.062e-03,  1.998e-03,  2.004e-03,  1.543e-03,  1.298e-03,  1.277e-03,  1.294e-03,  1.246e-03,  1.235e-03,  1.250e-03,  1.196e-03,  1.144e-03,  7.888e-04,  6.446e-04,  7.375e-04,  6.236e-04,  6.096e-04,  5.344e-04,  4.533e-04,  3.045e-04,  3.061e-04,  1.832e-04,  1.814e-04,  8.995e-04,  6.998e-05,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.909e-01,  4.326e+00,  4.404e+00,  2.438e+00,  1.895e+00,  1.683e+00,  1.341e+00,  1.409e+00,  8.969e-01,  2.174e+00,  2.197e+00,  2.069e+00,  1.746e+00,  1.538e+00,  1.441e+00,  1.422e+00,  1.434e+00,  1.433e+00,  1.424e+00,  1.407e+00,  1.395e+00,  1.389e+00,  1.392e+00,  1.393e+00,  1.392e+00,  1.381e+00,  1.361e+00,  1.329e+00,  1.308e+00,  1.257e+00,  1.201e+00,  1.126e+00,  1.042e+00,  9.550e-01,  8.772e-01,  8.172e-01,  7.734e-01,  7.465e-01,  7.162e-01,  7.039e-01,  7.466e-01,  8.262e-01,  9.452e-01,  1.088e+00,  1.248e+00,  1.393e+00,  1.483e+00,  1.436e+00,  1.323e+00,  1.124e+00,  9.072e-01,  6.888e-01,  5.006e-01,  3.507e-01,  2.378e-01,  1.549e-01,  9.968e-02,  6.299e-02,  4.072e-02,  2.689e-02,  1.835e-02,  1.296e-02,  9.511e-03,  7.295e-03,  5.823e-03,  4.136e-03,  3.040e-03,  2.658e-03,  2.399e-03,  2.226e-03,  2.114e-03,  2.062e-03,  1.989e-03,  1.971e-03,  1.567e-03,  1.281e-03,  1.294e-03,  1.268e-03,  1.266e-03,  1.265e-03,  1.228e-03,  1.236e-03,  1.225e-03,  8.103e-04,  7.079e-04,  7.266e-04,  5.923e-04,  6.088e-04,  5.056e-04,  5.458e-04,  3.032e-04,  3.077e-04,  1.585e-04,  1.626e-04,  5.673e-04,  1.324e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_t-channel_top_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 2.012e-01,  4.270e+00,  4.304e+00,  2.322e+00,  1.945e+00,  1.748e+00,  1.387e+00,  1.395e+00,  8.704e-01,  2.155e+00,  2.203e+00,  2.069e+00,  1.735e+00,  1.544e+00,  1.441e+00,  1.422e+00,  1.431e+00,  1.432e+00,  1.431e+00,  1.407e+00,  1.395e+00,  1.389e+00,  1.386e+00,  1.393e+00,  1.394e+00,  1.381e+00,  1.361e+00,  1.330e+00,  1.305e+00,  1.260e+00,  1.203e+00,  1.122e+00,  1.043e+00,  9.561e-01,  8.762e-01,  8.183e-01,  7.723e-01,  7.469e-01,  7.162e-01,  7.035e-01,  7.495e-01,  8.273e-01,  9.446e-01,  1.092e+00,  1.243e+00,  1.398e+00,  1.478e+00,  1.437e+00,  1.318e+00,  1.123e+00,  9.013e-01,  6.919e-01,  4.988e-01,  3.498e-01,  2.386e-01,  1.555e-01,  9.940e-02,  6.298e-02,  4.051e-02,  2.688e-02,  1.840e-02,  1.299e-02,  9.542e-03,  7.331e-03,  5.774e-03,  4.136e-03,  3.049e-03,  2.662e-03,  2.399e-03,  2.217e-03,  2.111e-03,  2.008e-03,  1.993e-03,  2.045e-03,  1.560e-03,  1.330e-03,  1.280e-03,  1.325e-03,  1.202e-03,  1.260e-03,  1.275e-03,  1.265e-03,  1.219e-03,  1.011e-03,  7.049e-04,  6.413e-04,  5.437e-04,  9.157e-04,  5.387e-04,  3.135e-04,  2.708e-04,  6.170e-04,  1.159e-04,  1.936e-04,  0.000e+00,  2.904e-05,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_tW_antitop_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.784e-01,  4.467e+00,  5.307e+00,  2.718e+00,  1.922e+00,  1.680e+00,  1.297e+00,  1.359e+00,  8.826e-01,  2.168e+00,  2.130e+00,  2.054e+00,  1.745e+00,  1.543e+00,  1.432e+00,  1.422e+00,  1.435e+00,  1.428e+00,  1.431e+00,  1.414e+00,  1.396e+00,  1.383e+00,  1.395e+00,  1.392e+00,  1.392e+00,  1.385e+00,  1.362e+00,  1.328e+00,  1.307e+00,  1.254e+00,  1.201e+00,  1.123e+00,  1.038e+00,  9.542e-01,  8.759e-01,  8.162e-01,  7.741e-01,  7.464e-01,  7.186e-01,  7.044e-01,  7.464e-01,  8.286e-01,  9.407e-01,  1.091e+00,  1.254e+00,  1.394e+00,  1.486e+00,  1.427e+00,  1.315e+00,  1.126e+00,  9.108e-01,  6.908e-01,  5.002e-01,  3.500e-01,  2.379e-01,  1.554e-01,  9.973e-02,  6.290e-02,  4.081e-02,  2.681e-02,  1.843e-02,  1.292e-02,  9.491e-03,  7.328e-03,  5.827e-03,  4.150e-03,  3.050e-03,  2.700e-03,  2.409e-03,  2.243e-03,  2.097e-03,  2.045e-03,  1.985e-03,  1.983e-03,  1.588e-03,  1.294e-03,  1.354e-03,  1.242e-03,  1.304e-03,  1.202e-03,  1.318e-03,  1.149e-03,  9.169e-04,  8.020e-04,  9.641e-04,  8.771e-04,  6.772e-04,  7.045e-04,  4.144e-04,  3.860e-04,  1.852e-04,  6.329e-04,  8.913e-05,  1.986e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_tW_top_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.870e-01,  4.337e+00,  4.470e+00,  2.473e+00,  1.891e+00,  1.726e+00,  1.350e+00,  1.395e+00,  8.887e-01,  2.177e+00,  2.175e+00,  2.077e+00,  1.744e+00,  1.544e+00,  1.439e+00,  1.423e+00,  1.436e+00,  1.431e+00,  1.423e+00,  1.409e+00,  1.393e+00,  1.389e+00,  1.392e+00,  1.392e+00,  1.390e+00,  1.382e+00,  1.361e+00,  1.329e+00,  1.308e+00,  1.256e+00,  1.202e+00,  1.126e+00,  1.043e+00,  9.555e-01,  8.765e-01,  8.173e-01,  7.730e-01,  7.475e-01,  7.158e-01,  7.034e-01,  7.481e-01,  8.260e-01,  9.445e-01,  1.090e+00,  1.249e+00,  1.396e+00,  1.486e+00,  1.435e+00,  1.324e+00,  1.123e+00,  9.082e-01,  6.907e-01,  4.996e-01,  3.504e-01,  2.379e-01,  1.550e-01,  9.952e-02,  6.304e-02,  4.067e-02,  2.685e-02,  1.837e-02,  1.293e-02,  9.508e-03,  7.300e-03,  5.792e-03,  4.121e-03,  3.035e-03,  2.660e-03,  2.418e-03,  2.237e-03,  2.121e-03,  2.075e-03,  1.954e-03,  1.968e-03,  1.536e-03,  1.290e-03,  1.290e-03,  1.241e-03,  1.232e-03,  1.222e-03,  1.202e-03,  1.248e-03,  1.088e-03,  8.040e-04,  6.508e-04,  6.766e-04,  5.611e-04,  5.837e-04,  5.060e-04,  4.197e-04,  3.581e-04,  3.239e-04,  2.068e-04,  1.920e-04,  4.759e-04,  1.728e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt0to700_hadd.root
{ 1.870e-01,  4.337e+00,  4.470e+00,  2.473e+00,  1.891e+00,  1.726e+00,  1.350e+00,  1.395e+00,  8.887e-01,  2.177e+00,  2.175e+00,  2.077e+00,  1.744e+00,  1.544e+00,  1.439e+00,  1.423e+00,  1.436e+00,  1.431e+00,  1.423e+00,  1.409e+00,  1.393e+00,  1.389e+00,  1.392e+00,  1.392e+00,  1.390e+00,  1.382e+00,  1.361e+00,  1.329e+00,  1.308e+00,  1.256e+00,  1.202e+00,  1.126e+00,  1.043e+00,  9.555e-01,  8.765e-01,  8.173e-01,  7.730e-01,  7.475e-01,  7.158e-01,  7.034e-01,  7.481e-01,  8.260e-01,  9.445e-01,  1.090e+00,  1.249e+00,  1.396e+00,  1.486e+00,  1.435e+00,  1.324e+00,  1.123e+00,  9.082e-01,  6.907e-01,  4.996e-01,  3.504e-01,  2.379e-01,  1.550e-01,  9.952e-02,  6.304e-02,  4.067e-02,  2.685e-02,  1.837e-02,  1.293e-02,  9.508e-03,  7.300e-03,  5.792e-03,  4.121e-03,  3.035e-03,  2.660e-03,  2.418e-03,  2.237e-03,  2.121e-03,  2.075e-03,  1.954e-03,  1.968e-03,  1.536e-03,  1.290e-03,  1.290e-03,  1.241e-03,  1.232e-03,  1.222e-03,  1.202e-03,  1.248e-03,  1.088e-03,  8.040e-04,  6.508e-04,  6.766e-04,  5.611e-04,  5.837e-04,  5.060e-04,  4.197e-04,  3.581e-04,  3.239e-04,  2.068e-04,  1.920e-04,  4.759e-04,  1.728e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt1000toInf_hadd.root
{ 1.870e-01,  4.337e+00,  4.470e+00,  2.473e+00,  1.891e+00,  1.726e+00,  1.350e+00,  1.395e+00,  8.887e-01,  2.177e+00,  2.175e+00,  2.077e+00,  1.744e+00,  1.544e+00,  1.439e+00,  1.423e+00,  1.436e+00,  1.431e+00,  1.423e+00,  1.409e+00,  1.393e+00,  1.389e+00,  1.392e+00,  1.392e+00,  1.390e+00,  1.382e+00,  1.361e+00,  1.329e+00,  1.308e+00,  1.256e+00,  1.202e+00,  1.126e+00,  1.043e+00,  9.555e-01,  8.765e-01,  8.173e-01,  7.730e-01,  7.475e-01,  7.158e-01,  7.034e-01,  7.481e-01,  8.260e-01,  9.445e-01,  1.090e+00,  1.249e+00,  1.396e+00,  1.486e+00,  1.435e+00,  1.324e+00,  1.123e+00,  9.082e-01,  6.907e-01,  4.996e-01,  3.504e-01,  2.379e-01,  1.550e-01,  9.952e-02,  6.304e-02,  4.067e-02,  2.685e-02,  1.837e-02,  1.293e-02,  9.508e-03,  7.300e-03,  5.792e-03,  4.121e-03,  3.035e-03,  2.660e-03,  2.418e-03,  2.237e-03,  2.121e-03,  2.075e-03,  1.954e-03,  1.968e-03,  1.536e-03,  1.290e-03,  1.290e-03,  1.241e-03,  1.232e-03,  1.222e-03,  1.202e-03,  1.248e-03,  1.088e-03,  8.040e-04,  6.508e-04,  6.766e-04,  5.611e-04,  5.837e-04,  5.060e-04,  4.197e-04,  3.581e-04,  3.239e-04,  2.068e-04,  1.920e-04,  4.759e-04,  1.728e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt700to1000_hadd.root
{ 1.952e-01,  4.062e+00,  4.400e+00,  2.445e+00,  1.858e+00,  1.687e+00,  1.337e+00,  1.427e+00,  8.905e-01,  2.160e+00,  2.175e+00,  2.066e+00,  1.745e+00,  1.539e+00,  1.437e+00,  1.424e+00,  1.433e+00,  1.433e+00,  1.422e+00,  1.407e+00,  1.394e+00,  1.390e+00,  1.392e+00,  1.394e+00,  1.391e+00,  1.381e+00,  1.361e+00,  1.329e+00,  1.308e+00,  1.256e+00,  1.202e+00,  1.125e+00,  1.043e+00,  9.551e-01,  8.767e-01,  8.166e-01,  7.735e-01,  7.479e-01,  7.163e-01,  7.032e-01,  7.475e-01,  8.276e-01,  9.443e-01,  1.089e+00,  1.248e+00,  1.393e+00,  1.482e+00,  1.434e+00,  1.324e+00,  1.124e+00,  9.073e-01,  6.900e-01,  5.011e-01,  3.503e-01,  2.378e-01,  1.548e-01,  9.962e-02,  6.299e-02,  4.064e-02,  2.692e-02,  1.838e-02,  1.298e-02,  9.520e-03,  7.285e-03,  5.810e-03,  4.125e-03,  3.045e-03,  2.665e-03,  2.405e-03,  2.241e-03,  2.112e-03,  2.054e-03,  1.987e-03,  1.978e-03,  1.559e-03,  1.294e-03,  1.283e-03,  1.240e-03,  1.278e-03,  1.224e-03,  1.222e-03,  1.222e-03,  1.161e-03,  8.333e-04,  6.993e-04,  7.031e-04,  5.885e-04,  6.037e-04,  5.224e-04,  4.865e-04,  3.959e-04,  3.989e-04,  1.885e-04,  1.713e-04,  5.977e-04,  1.953e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt0to700_hadd.root
{ 1.952e-01,  4.062e+00,  4.400e+00,  2.445e+00,  1.858e+00,  1.687e+00,  1.337e+00,  1.427e+00,  8.905e-01,  2.160e+00,  2.175e+00,  2.066e+00,  1.745e+00,  1.539e+00,  1.437e+00,  1.424e+00,  1.433e+00,  1.433e+00,  1.422e+00,  1.407e+00,  1.394e+00,  1.390e+00,  1.392e+00,  1.394e+00,  1.391e+00,  1.381e+00,  1.361e+00,  1.329e+00,  1.308e+00,  1.256e+00,  1.202e+00,  1.125e+00,  1.043e+00,  9.551e-01,  8.767e-01,  8.166e-01,  7.735e-01,  7.479e-01,  7.163e-01,  7.032e-01,  7.475e-01,  8.276e-01,  9.443e-01,  1.089e+00,  1.248e+00,  1.393e+00,  1.482e+00,  1.434e+00,  1.324e+00,  1.124e+00,  9.073e-01,  6.900e-01,  5.011e-01,  3.503e-01,  2.378e-01,  1.548e-01,  9.962e-02,  6.299e-02,  4.064e-02,  2.692e-02,  1.838e-02,  1.298e-02,  9.520e-03,  7.285e-03,  5.810e-03,  4.125e-03,  3.045e-03,  2.665e-03,  2.405e-03,  2.241e-03,  2.112e-03,  2.054e-03,  1.987e-03,  1.978e-03,  1.559e-03,  1.294e-03,  1.283e-03,  1.240e-03,  1.278e-03,  1.224e-03,  1.222e-03,  1.222e-03,  1.161e-03,  8.333e-04,  6.993e-04,  7.031e-04,  5.885e-04,  6.037e-04,  5.224e-04,  4.865e-04,  3.959e-04,  3.989e-04,  1.885e-04,  1.713e-04,  5.977e-04,  1.953e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt1000toInf_hadd.root
{ 1.952e-01,  4.062e+00,  4.400e+00,  2.445e+00,  1.858e+00,  1.687e+00,  1.337e+00,  1.427e+00,  8.905e-01,  2.160e+00,  2.175e+00,  2.066e+00,  1.745e+00,  1.539e+00,  1.437e+00,  1.424e+00,  1.433e+00,  1.433e+00,  1.422e+00,  1.407e+00,  1.394e+00,  1.390e+00,  1.392e+00,  1.394e+00,  1.391e+00,  1.381e+00,  1.361e+00,  1.329e+00,  1.308e+00,  1.256e+00,  1.202e+00,  1.125e+00,  1.043e+00,  9.551e-01,  8.767e-01,  8.166e-01,  7.735e-01,  7.479e-01,  7.163e-01,  7.032e-01,  7.475e-01,  8.276e-01,  9.443e-01,  1.089e+00,  1.248e+00,  1.393e+00,  1.482e+00,  1.434e+00,  1.324e+00,  1.124e+00,  9.073e-01,  6.900e-01,  5.011e-01,  3.503e-01,  2.378e-01,  1.548e-01,  9.962e-02,  6.299e-02,  4.064e-02,  2.692e-02,  1.838e-02,  1.298e-02,  9.520e-03,  7.285e-03,  5.810e-03,  4.125e-03,  3.045e-03,  2.665e-03,  2.405e-03,  2.241e-03,  2.112e-03,  2.054e-03,  1.987e-03,  1.978e-03,  1.559e-03,  1.294e-03,  1.283e-03,  1.240e-03,  1.278e-03,  1.224e-03,  1.222e-03,  1.222e-03,  1.161e-03,  8.333e-04,  6.993e-04,  7.031e-04,  5.885e-04,  6.037e-04,  5.224e-04,  4.865e-04,  3.959e-04,  3.989e-04,  1.885e-04,  1.713e-04,  5.977e-04,  1.953e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt700to1000_hadd.root
{ 1.885e-01,  4.226e+00,  4.554e+00,  2.475e+00,  1.896e+00,  1.697e+00,  1.336e+00,  1.397e+00,  8.874e-01,  2.165e+00,  2.186e+00,  2.067e+00,  1.748e+00,  1.540e+00,  1.439e+00,  1.423e+00,  1.433e+00,  1.433e+00,  1.425e+00,  1.408e+00,  1.393e+00,  1.389e+00,  1.391e+00,  1.393e+00,  1.392e+00,  1.382e+00,  1.361e+00,  1.330e+00,  1.309e+00,  1.257e+00,  1.201e+00,  1.125e+00,  1.044e+00,  9.542e-01,  8.772e-01,  8.165e-01,  7.732e-01,  7.466e-01,  7.155e-01,  7.042e-01,  7.463e-01,  8.271e-01,  9.429e-01,  1.089e+00,  1.250e+00,  1.394e+00,  1.484e+00,  1.436e+00,  1.323e+00,  1.123e+00,  9.069e-01,  6.897e-01,  5.004e-01,  3.501e-01,  2.378e-01,  1.549e-01,  9.976e-02,  6.303e-02,  4.067e-02,  2.693e-02,  1.835e-02,  1.299e-02,  9.509e-03,  7.294e-03,  5.808e-03,  4.118e-03,  3.039e-03,  2.659e-03,  2.417e-03,  2.242e-03,  2.120e-03,  2.049e-03,  2.009e-03,  1.968e-03,  1.546e-03,  1.272e-03,  1.265e-03,  1.220e-03,  1.282e-03,  1.237e-03,  1.225e-03,  1.244e-03,  1.172e-03,  8.465e-04,  6.915e-04,  7.164e-04,  5.537e-04,  6.667e-04,  6.286e-04,  5.342e-04,  3.751e-04,  4.867e-04,  1.592e-04,  1.617e-04,  3.786e-04,  2.749e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt0to700_hadd.root
{ 1.885e-01,  4.226e+00,  4.554e+00,  2.475e+00,  1.896e+00,  1.697e+00,  1.336e+00,  1.397e+00,  8.874e-01,  2.165e+00,  2.186e+00,  2.067e+00,  1.748e+00,  1.540e+00,  1.439e+00,  1.423e+00,  1.433e+00,  1.433e+00,  1.425e+00,  1.408e+00,  1.393e+00,  1.389e+00,  1.391e+00,  1.393e+00,  1.392e+00,  1.382e+00,  1.361e+00,  1.330e+00,  1.309e+00,  1.257e+00,  1.201e+00,  1.125e+00,  1.044e+00,  9.542e-01,  8.772e-01,  8.165e-01,  7.732e-01,  7.466e-01,  7.155e-01,  7.042e-01,  7.463e-01,  8.271e-01,  9.429e-01,  1.089e+00,  1.250e+00,  1.394e+00,  1.484e+00,  1.436e+00,  1.323e+00,  1.123e+00,  9.069e-01,  6.897e-01,  5.004e-01,  3.501e-01,  2.378e-01,  1.549e-01,  9.976e-02,  6.303e-02,  4.067e-02,  2.693e-02,  1.835e-02,  1.299e-02,  9.509e-03,  7.294e-03,  5.808e-03,  4.118e-03,  3.039e-03,  2.659e-03,  2.417e-03,  2.242e-03,  2.120e-03,  2.049e-03,  2.009e-03,  1.968e-03,  1.546e-03,  1.272e-03,  1.265e-03,  1.220e-03,  1.282e-03,  1.237e-03,  1.225e-03,  1.244e-03,  1.172e-03,  8.465e-04,  6.915e-04,  7.164e-04,  5.537e-04,  6.667e-04,  6.286e-04,  5.342e-04,  3.751e-04,  4.867e-04,  1.592e-04,  1.617e-04,  3.786e-04,  2.749e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt1000toInf_hadd.root
{ 1.885e-01,  4.226e+00,  4.554e+00,  2.475e+00,  1.896e+00,  1.697e+00,  1.336e+00,  1.397e+00,  8.874e-01,  2.165e+00,  2.186e+00,  2.067e+00,  1.748e+00,  1.540e+00,  1.439e+00,  1.423e+00,  1.433e+00,  1.433e+00,  1.425e+00,  1.408e+00,  1.393e+00,  1.389e+00,  1.391e+00,  1.393e+00,  1.392e+00,  1.382e+00,  1.361e+00,  1.330e+00,  1.309e+00,  1.257e+00,  1.201e+00,  1.125e+00,  1.044e+00,  9.542e-01,  8.772e-01,  8.165e-01,  7.732e-01,  7.466e-01,  7.155e-01,  7.042e-01,  7.463e-01,  8.271e-01,  9.429e-01,  1.089e+00,  1.250e+00,  1.394e+00,  1.484e+00,  1.436e+00,  1.323e+00,  1.123e+00,  9.069e-01,  6.897e-01,  5.004e-01,  3.501e-01,  2.378e-01,  1.549e-01,  9.976e-02,  6.303e-02,  4.067e-02,  2.693e-02,  1.835e-02,  1.299e-02,  9.509e-03,  7.294e-03,  5.808e-03,  4.118e-03,  3.039e-03,  2.659e-03,  2.417e-03,  2.242e-03,  2.120e-03,  2.049e-03,  2.009e-03,  1.968e-03,  1.546e-03,  1.272e-03,  1.265e-03,  1.220e-03,  1.282e-03,  1.237e-03,  1.225e-03,  1.244e-03,  1.172e-03,  8.465e-04,  6.915e-04,  7.164e-04,  5.537e-04,  6.667e-04,  6.286e-04,  5.342e-04,  3.751e-04,  4.867e-04,  1.592e-04,  1.617e-04,  3.786e-04,  2.749e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt700to1000_hadd.root
{ 1.904e-01,  4.287e+00,  4.640e+00,  2.493e+00,  1.858e+00,  1.747e+00,  1.343e+00,  1.429e+00,  8.915e-01,  2.173e+00,  2.211e+00,  2.048e+00,  1.741e+00,  1.526e+00,  1.442e+00,  1.423e+00,  1.434e+00,  1.434e+00,  1.423e+00,  1.407e+00,  1.393e+00,  1.389e+00,  1.392e+00,  1.393e+00,  1.392e+00,  1.381e+00,  1.362e+00,  1.329e+00,  1.310e+00,  1.258e+00,  1.201e+00,  1.124e+00,  1.042e+00,  9.544e-01,  8.777e-01,  8.184e-01,  7.734e-01,  7.474e-01,  7.156e-01,  7.035e-01,  7.467e-01,  8.272e-01,  9.447e-01,  1.089e+00,  1.247e+00,  1.393e+00,  1.481e+00,  1.437e+00,  1.316e+00,  1.123e+00,  9.074e-01,  6.907e-01,  5.015e-01,  3.508e-01,  2.378e-01,  1.545e-01,  9.954e-02,  6.270e-02,  4.076e-02,  2.693e-02,  1.842e-02,  1.296e-02,  9.532e-03,  7.287e-03,  5.808e-03,  4.110e-03,  3.039e-03,  2.653e-03,  2.413e-03,  2.232e-03,  2.128e-03,  2.055e-03,  2.007e-03,  1.967e-03,  1.533e-03,  1.304e-03,  1.312e-03,  1.293e-03,  1.282e-03,  1.323e-03,  1.289e-03,  1.166e-03,  1.206e-03,  8.705e-04,  6.858e-04,  7.773e-04,  7.002e-04,  5.282e-04,  5.572e-04,  4.089e-04,  4.924e-04,  2.571e-04,  2.896e-04,  3.227e-04,  1.333e-04,  1.452e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TT_Mtt-700to1000_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.875e-01,  4.020e+00,  4.677e+00,  2.415e+00,  1.826e+00,  1.722e+00,  1.311e+00,  1.405e+00,  8.850e-01,  2.164e+00,  2.203e+00,  2.051e+00,  1.756e+00,  1.537e+00,  1.436e+00,  1.430e+00,  1.427e+00,  1.432e+00,  1.429e+00,  1.406e+00,  1.394e+00,  1.390e+00,  1.391e+00,  1.393e+00,  1.392e+00,  1.381e+00,  1.361e+00,  1.329e+00,  1.308e+00,  1.256e+00,  1.203e+00,  1.123e+00,  1.043e+00,  9.560e-01,  8.757e-01,  8.175e-01,  7.729e-01,  7.477e-01,  7.176e-01,  7.038e-01,  7.467e-01,  8.273e-01,  9.442e-01,  1.087e+00,  1.253e+00,  1.392e+00,  1.482e+00,  1.438e+00,  1.321e+00,  1.123e+00,  9.094e-01,  6.883e-01,  4.988e-01,  3.506e-01,  2.373e-01,  1.543e-01,  9.952e-02,  6.319e-02,  4.061e-02,  2.699e-02,  1.833e-02,  1.294e-02,  9.517e-03,  7.278e-03,  5.824e-03,  4.147e-03,  3.045e-03,  2.680e-03,  2.411e-03,  2.236e-03,  2.112e-03,  2.026e-03,  2.014e-03,  1.962e-03,  1.535e-03,  1.313e-03,  1.260e-03,  1.341e-03,  1.270e-03,  1.206e-03,  1.223e-03,  1.191e-03,  1.238e-03,  6.998e-04,  6.694e-04,  8.198e-04,  6.095e-04,  7.246e-04,  6.394e-04,  5.789e-04,  2.500e-04,  1.709e-03,  1.375e-04,  1.788e-04,  0.000e+00,  8.045e-05,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TT_Mtt-1000toInf_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.997e-01,  3.784e+00,  4.362e+00,  2.258e+00,  1.804e+00,  1.983e+00,  1.367e+00,  1.400e+00,  9.395e-01,  2.191e+00,  2.173e+00,  2.065e+00,  1.718e+00,  1.550e+00,  1.435e+00,  1.426e+00,  1.445e+00,  1.437e+00,  1.420e+00,  1.411e+00,  1.397e+00,  1.397e+00,  1.391e+00,  1.403e+00,  1.393e+00,  1.387e+00,  1.357e+00,  1.332e+00,  1.302e+00,  1.259e+00,  1.204e+00,  1.128e+00,  1.041e+00,  9.517e-01,  8.769e-01,  8.171e-01,  7.745e-01,  7.495e-01,  7.114e-01,  6.997e-01,  7.466e-01,  8.277e-01,  9.401e-01,  1.092e+00,  1.259e+00,  1.392e+00,  1.480e+00,  1.435e+00,  1.316e+00,  1.120e+00,  8.938e-01,  6.857e-01,  4.982e-01,  3.483e-01,  2.379e-01,  1.554e-01,  9.930e-02,  6.293e-02,  4.058e-02,  2.670e-02,  1.834e-02,  1.316e-02,  9.518e-03,  7.353e-03,  5.821e-03,  4.125e-03,  3.031e-03,  2.742e-03,  2.429e-03,  2.225e-03,  2.067e-03,  2.071e-03,  1.998e-03,  1.901e-03,  1.636e-03,  1.283e-03,  1.455e-03,  1.278e-03,  1.376e-03,  1.303e-03,  1.574e-03,  1.078e-03,  1.235e-03,  7.243e-04,  5.580e-04,  8.071e-04,  7.001e-04,  4.161e-04,  5.508e-04,  3.206e-04,  1.477e-04,  0.000e+00,  2.369e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTZToLLNuNu_M-10_TuneCP5_PSweights_13TeV-amcatnlo-pythia8_hadd.root
{ 2.053e-01,  3.224e+00,  3.851e+00,  2.587e+00,  1.657e+00,  1.638e+00,  1.461e+00,  1.320e+00,  9.145e-01,  2.217e+00,  2.262e+00,  2.046e+00,  1.766e+00,  1.524e+00,  1.442e+00,  1.436e+00,  1.448e+00,  1.429e+00,  1.430e+00,  1.399e+00,  1.395e+00,  1.390e+00,  1.383e+00,  1.383e+00,  1.395e+00,  1.379e+00,  1.376e+00,  1.325e+00,  1.314e+00,  1.268e+00,  1.206e+00,  1.119e+00,  1.043e+00,  9.602e-01,  8.735e-01,  8.122e-01,  7.708e-01,  7.411e-01,  7.119e-01,  7.005e-01,  7.520e-01,  8.234e-01,  9.467e-01,  1.100e+00,  1.250e+00,  1.382e+00,  1.477e+00,  1.438e+00,  1.319e+00,  1.117e+00,  9.103e-01,  6.841e-01,  4.978e-01,  3.471e-01,  2.369e-01,  1.554e-01,  1.001e-01,  6.343e-02,  4.185e-02,  2.685e-02,  1.843e-02,  1.281e-02,  9.634e-03,  7.434e-03,  5.711e-03,  4.081e-03,  3.078e-03,  2.682e-03,  2.413e-03,  2.265e-03,  2.091e-03,  1.918e-03,  1.906e-03,  1.873e-03,  1.631e-03,  1.402e-03,  1.328e-03,  1.099e-03,  1.246e-03,  1.956e-03,  1.009e-03,  1.387e-03,  1.112e-03,  2.062e-03,  9.823e-04,  5.958e-04,  4.600e-04,  9.570e-04,  5.630e-04,  1.639e-04,  -3.774e-04,  0.000e+00,  0.000e+00,  3.373e-05,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTWJetsToLNu_TuneCP5_PSweights_13TeV-amcatnloFXFX-madspin-pythia8_hadd.root
{ 1.898e-01,  5.389e+00,  4.348e+00,  2.560e+00,  1.775e+00,  1.627e+00,  1.294e+00,  1.396e+00,  8.921e-01,  2.170e+00,  2.176e+00,  2.068e+00,  1.751e+00,  1.543e+00,  1.442e+00,  1.417e+00,  1.437e+00,  1.432e+00,  1.420e+00,  1.412e+00,  1.395e+00,  1.386e+00,  1.396e+00,  1.391e+00,  1.389e+00,  1.380e+00,  1.359e+00,  1.330e+00,  1.308e+00,  1.256e+00,  1.203e+00,  1.124e+00,  1.043e+00,  9.569e-01,  8.754e-01,  8.168e-01,  7.720e-01,  7.478e-01,  7.174e-01,  7.047e-01,  7.455e-01,  8.268e-01,  9.489e-01,  1.091e+00,  1.248e+00,  1.392e+00,  1.485e+00,  1.443e+00,  1.316e+00,  1.124e+00,  9.119e-01,  6.876e-01,  5.016e-01,  3.486e-01,  2.376e-01,  1.544e-01,  9.974e-02,  6.310e-02,  4.072e-02,  2.692e-02,  1.843e-02,  1.296e-02,  9.461e-03,  7.294e-03,  5.771e-03,  4.147e-03,  3.024e-03,  2.640e-03,  2.364e-03,  2.239e-03,  2.116e-03,  2.027e-03,  2.080e-03,  2.091e-03,  1.566e-03,  1.270e-03,  1.331e-03,  1.276e-03,  1.236e-03,  1.454e-03,  1.372e-03,  1.387e-03,  9.233e-04,  7.969e-04,  6.806e-04,  6.275e-04,  7.246e-04,  5.600e-04,  5.490e-04,  2.130e-04,  3.680e-04,  6.289e-04,  8.856e-05,  1.973e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ttHTobb_M125_TuneCP5_13TeV-powheg-pythia8_hadd.root
{ 1.886e-01,  3.827e+00,  4.337e+00,  2.583e+00,  1.930e+00,  1.804e+00,  1.269e+00,  1.406e+00,  8.503e-01,  2.245e+00,  2.172e+00,  2.044e+00,  1.751e+00,  1.525e+00,  1.445e+00,  1.421e+00,  1.429e+00,  1.433e+00,  1.424e+00,  1.403e+00,  1.397e+00,  1.389e+00,  1.399e+00,  1.392e+00,  1.391e+00,  1.377e+00,  1.362e+00,  1.331e+00,  1.308e+00,  1.255e+00,  1.199e+00,  1.124e+00,  1.044e+00,  9.561e-01,  8.761e-01,  8.178e-01,  7.750e-01,  7.474e-01,  7.159e-01,  7.058e-01,  7.446e-01,  8.256e-01,  9.417e-01,  1.092e+00,  1.257e+00,  1.390e+00,  1.490e+00,  1.430e+00,  1.329e+00,  1.128e+00,  9.002e-01,  6.841e-01,  5.006e-01,  3.504e-01,  2.381e-01,  1.541e-01,  9.996e-02,  6.314e-02,  4.088e-02,  2.686e-02,  1.844e-02,  1.297e-02,  9.528e-03,  7.247e-03,  5.801e-03,  4.132e-03,  3.039e-03,  2.626e-03,  2.457e-03,  2.261e-03,  2.088e-03,  2.053e-03,  2.039e-03,  1.890e-03,  1.582e-03,  1.374e-03,  1.240e-03,  1.224e-03,  1.273e-03,  1.110e-03,  1.121e-03,  1.138e-03,  1.262e-03,  7.802e-04,  7.372e-04,  1.204e-03,  6.712e-04,  3.724e-04,  4.694e-04,  9.564e-04,  1.836e-04,  0.000e+00,  1.767e-04,  6.562e-05,  0.000e+00,  5.906e-05,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8_hadd.root
{ 1.958e-01,  5.240e+00,  4.222e+00,  2.311e+00,  2.078e+00,  1.658e+00,  1.387e+00,  1.351e+00,  8.834e-01,  2.225e+00,  2.218e+00,  2.058e+00,  1.727e+00,  1.533e+00,  1.435e+00,  1.417e+00,  1.433e+00,  1.436e+00,  1.423e+00,  1.408e+00,  1.393e+00,  1.387e+00,  1.390e+00,  1.393e+00,  1.390e+00,  1.382e+00,  1.361e+00,  1.331e+00,  1.310e+00,  1.258e+00,  1.200e+00,  1.125e+00,  1.042e+00,  9.554e-01,  8.772e-01,  8.186e-01,  7.726e-01,  7.490e-01,  7.176e-01,  7.045e-01,  7.470e-01,  8.263e-01,  9.422e-01,  1.089e+00,  1.247e+00,  1.393e+00,  1.484e+00,  1.433e+00,  1.321e+00,  1.124e+00,  9.077e-01,  6.901e-01,  5.002e-01,  3.499e-01,  2.381e-01,  1.547e-01,  9.971e-02,  6.322e-02,  4.068e-02,  2.689e-02,  1.828e-02,  1.293e-02,  9.509e-03,  7.293e-03,  5.819e-03,  4.106e-03,  3.030e-03,  2.646e-03,  2.412e-03,  2.240e-03,  2.125e-03,  2.073e-03,  1.967e-03,  1.989e-03,  1.553e-03,  1.272e-03,  1.279e-03,  1.304e-03,  1.275e-03,  1.318e-03,  1.324e-03,  1.213e-03,  1.192e-03,  7.683e-04,  5.535e-04,  5.707e-04,  6.313e-04,  8.389e-04,  4.415e-04,  2.325e-04,  4.017e-04,  5.338e-04,  3.007e-04,  1.005e-04,  0.000e+00,  1.508e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 2.002e-01,  4.710e+00,  4.499e+00,  2.398e+00,  1.891e+00,  1.709e+00,  1.344e+00,  1.424e+00,  8.680e-01,  2.147e+00,  2.161e+00,  2.054e+00,  1.741e+00,  1.539e+00,  1.446e+00,  1.420e+00,  1.430e+00,  1.431e+00,  1.425e+00,  1.407e+00,  1.392e+00,  1.390e+00,  1.387e+00,  1.393e+00,  1.393e+00,  1.384e+00,  1.361e+00,  1.330e+00,  1.307e+00,  1.260e+00,  1.200e+00,  1.123e+00,  1.046e+00,  9.542e-01,  8.771e-01,  8.183e-01,  7.745e-01,  7.458e-01,  7.144e-01,  7.048e-01,  7.459e-01,  8.286e-01,  9.442e-01,  1.086e+00,  1.251e+00,  1.395e+00,  1.485e+00,  1.432e+00,  1.327e+00,  1.123e+00,  9.097e-01,  6.906e-01,  5.014e-01,  3.506e-01,  2.376e-01,  1.545e-01,  9.954e-02,  6.282e-02,  4.064e-02,  2.691e-02,  1.840e-02,  1.294e-02,  9.575e-03,  7.267e-03,  5.819e-03,  4.135e-03,  3.046e-03,  2.656e-03,  2.380e-03,  2.224e-03,  2.111e-03,  2.064e-03,  2.000e-03,  1.955e-03,  1.555e-03,  1.309e-03,  1.291e-03,  1.245e-03,  1.340e-03,  1.191e-03,  1.250e-03,  1.411e-03,  1.302e-03,  7.324e-04,  6.793e-04,  8.161e-04,  5.201e-04,  8.416e-04,  3.713e-04,  3.990e-04,  3.733e-04,  5.671e-04,  1.917e-04,  1.068e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.980e-01,  4.550e+00,  4.265e+00,  2.562e+00,  1.861e+00,  1.661e+00,  1.342e+00,  1.392e+00,  9.020e-01,  2.140e+00,  2.172e+00,  2.063e+00,  1.752e+00,  1.533e+00,  1.435e+00,  1.418e+00,  1.433e+00,  1.435e+00,  1.427e+00,  1.407e+00,  1.394e+00,  1.390e+00,  1.394e+00,  1.394e+00,  1.392e+00,  1.378e+00,  1.363e+00,  1.329e+00,  1.309e+00,  1.256e+00,  1.201e+00,  1.126e+00,  1.043e+00,  9.545e-01,  8.770e-01,  8.185e-01,  7.750e-01,  7.473e-01,  7.148e-01,  7.015e-01,  7.485e-01,  8.262e-01,  9.442e-01,  1.092e+00,  1.244e+00,  1.393e+00,  1.480e+00,  1.435e+00,  1.321e+00,  1.123e+00,  9.089e-01,  6.890e-01,  4.999e-01,  3.502e-01,  2.381e-01,  1.547e-01,  9.950e-02,  6.297e-02,  4.061e-02,  2.695e-02,  1.839e-02,  1.292e-02,  9.498e-03,  7.314e-03,  5.797e-03,  4.151e-03,  3.056e-03,  2.686e-03,  2.386e-03,  2.245e-03,  2.140e-03,  2.049e-03,  2.018e-03,  1.977e-03,  1.516e-03,  1.296e-03,  1.286e-03,  1.318e-03,  1.239e-03,  1.330e-03,  1.278e-03,  1.149e-03,  1.192e-03,  8.689e-04,  7.022e-04,  7.122e-04,  7.296e-04,  7.022e-04,  4.566e-04,  1.262e-03,  5.815e-04,  4.140e-04,  3.110e-04,  1.732e-04,  2.863e-04,  5.197e-05,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.989e-01,  4.408e+00,  5.015e+00,  2.599e+00,  1.904e+00,  1.649e+00,  1.363e+00,  1.442e+00,  8.867e-01,  2.134e+00,  2.191e+00,  2.063e+00,  1.735e+00,  1.535e+00,  1.441e+00,  1.419e+00,  1.424e+00,  1.430e+00,  1.422e+00,  1.405e+00,  1.393e+00,  1.389e+00,  1.392e+00,  1.391e+00,  1.394e+00,  1.383e+00,  1.360e+00,  1.332e+00,  1.311e+00,  1.257e+00,  1.203e+00,  1.126e+00,  1.043e+00,  9.545e-01,  8.779e-01,  8.170e-01,  7.720e-01,  7.470e-01,  7.173e-01,  7.032e-01,  7.457e-01,  8.259e-01,  9.444e-01,  1.087e+00,  1.250e+00,  1.397e+00,  1.483e+00,  1.435e+00,  1.326e+00,  1.126e+00,  9.088e-01,  6.909e-01,  5.013e-01,  3.507e-01,  2.376e-01,  1.548e-01,  9.950e-02,  6.260e-02,  4.080e-02,  2.692e-02,  1.843e-02,  1.298e-02,  9.502e-03,  7.206e-03,  5.828e-03,  4.104e-03,  3.040e-03,  2.667e-03,  2.389e-03,  2.227e-03,  2.113e-03,  2.062e-03,  1.995e-03,  1.985e-03,  1.532e-03,  1.303e-03,  1.294e-03,  1.208e-03,  1.240e-03,  1.253e-03,  1.160e-03,  1.248e-03,  1.095e-03,  7.886e-04,  7.680e-04,  9.471e-04,  4.740e-04,  6.339e-04,  3.315e-04,  6.946e-04,  5.000e-04,  3.797e-04,  6.416e-04,  1.191e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.975e-01,  3.876e+00,  4.590e+00,  2.541e+00,  1.825e+00,  1.666e+00,  1.355e+00,  1.443e+00,  8.889e-01,  2.209e+00,  2.158e+00,  2.058e+00,  1.733e+00,  1.536e+00,  1.433e+00,  1.424e+00,  1.433e+00,  1.440e+00,  1.424e+00,  1.404e+00,  1.397e+00,  1.389e+00,  1.393e+00,  1.394e+00,  1.392e+00,  1.384e+00,  1.357e+00,  1.328e+00,  1.308e+00,  1.259e+00,  1.203e+00,  1.126e+00,  1.042e+00,  9.533e-01,  8.764e-01,  8.161e-01,  7.736e-01,  7.465e-01,  7.170e-01,  7.054e-01,  7.446e-01,  8.289e-01,  9.439e-01,  1.089e+00,  1.249e+00,  1.389e+00,  1.484e+00,  1.434e+00,  1.326e+00,  1.123e+00,  9.063e-01,  6.894e-01,  5.020e-01,  3.517e-01,  2.378e-01,  1.550e-01,  9.982e-02,  6.295e-02,  4.066e-02,  2.679e-02,  1.832e-02,  1.294e-02,  9.513e-03,  7.252e-03,  5.793e-03,  4.122e-03,  3.027e-03,  2.677e-03,  2.421e-03,  2.220e-03,  2.122e-03,  2.052e-03,  1.951e-03,  1.988e-03,  1.587e-03,  1.278e-03,  1.290e-03,  1.205e-03,  1.265e-03,  1.191e-03,  1.151e-03,  1.193e-03,  1.310e-03,  8.779e-04,  6.521e-04,  7.910e-04,  6.577e-04,  4.765e-04,  4.721e-04,  4.351e-04,  4.295e-04,  2.140e-04,  1.929e-04,  1.343e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.790e-01,  3.985e+00,  4.046e+00,  2.518e+00,  1.832e+00,  1.605e+00,  1.353e+00,  1.401e+00,  8.817e-01,  2.151e+00,  2.193e+00,  2.047e+00,  1.744e+00,  1.534e+00,  1.435e+00,  1.424e+00,  1.433e+00,  1.432e+00,  1.425e+00,  1.409e+00,  1.393e+00,  1.391e+00,  1.392e+00,  1.393e+00,  1.395e+00,  1.385e+00,  1.361e+00,  1.328e+00,  1.308e+00,  1.255e+00,  1.202e+00,  1.125e+00,  1.040e+00,  9.553e-01,  8.775e-01,  8.183e-01,  7.739e-01,  7.468e-01,  7.166e-01,  7.038e-01,  7.473e-01,  8.257e-01,  9.436e-01,  1.090e+00,  1.246e+00,  1.397e+00,  1.481e+00,  1.429e+00,  1.321e+00,  1.124e+00,  9.057e-01,  6.905e-01,  4.991e-01,  3.498e-01,  2.376e-01,  1.552e-01,  9.978e-02,  6.296e-02,  4.089e-02,  2.685e-02,  1.836e-02,  1.300e-02,  9.541e-03,  7.254e-03,  5.813e-03,  4.116e-03,  3.043e-03,  2.656e-03,  2.420e-03,  2.239e-03,  2.121e-03,  2.041e-03,  2.019e-03,  2.023e-03,  1.574e-03,  1.237e-03,  1.318e-03,  1.238e-03,  1.196e-03,  1.267e-03,  1.270e-03,  1.139e-03,  1.245e-03,  7.486e-04,  7.521e-04,  7.122e-04,  6.251e-04,  6.038e-04,  3.875e-04,  4.962e-04,  3.175e-04,  4.069e-04,  3.056e-04,  0.000e+00,  1.407e-04,  1.532e-04,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.827e-01,  4.155e+00,  4.348e+00,  2.276e+00,  1.956e+00,  1.670e+00,  1.297e+00,  1.302e+00,  9.124e-01,  2.178e+00,  2.194e+00,  2.067e+00,  1.753e+00,  1.531e+00,  1.434e+00,  1.426e+00,  1.436e+00,  1.439e+00,  1.418e+00,  1.411e+00,  1.392e+00,  1.391e+00,  1.393e+00,  1.395e+00,  1.392e+00,  1.379e+00,  1.362e+00,  1.326e+00,  1.306e+00,  1.259e+00,  1.199e+00,  1.124e+00,  1.044e+00,  9.542e-01,  8.789e-01,  8.155e-01,  7.731e-01,  7.479e-01,  7.177e-01,  7.049e-01,  7.457e-01,  8.246e-01,  9.442e-01,  1.085e+00,  1.245e+00,  1.392e+00,  1.488e+00,  1.435e+00,  1.327e+00,  1.125e+00,  9.117e-01,  6.896e-01,  4.983e-01,  3.486e-01,  2.384e-01,  1.556e-01,  9.993e-02,  6.303e-02,  4.062e-02,  2.692e-02,  1.838e-02,  1.294e-02,  9.562e-03,  7.224e-03,  5.827e-03,  4.125e-03,  3.048e-03,  2.660e-03,  2.442e-03,  2.255e-03,  2.067e-03,  2.073e-03,  1.911e-03,  1.998e-03,  1.643e-03,  1.305e-03,  1.251e-03,  1.230e-03,  1.211e-03,  1.189e-03,  1.151e-03,  1.065e-03,  9.408e-04,  8.209e-04,  8.546e-04,  1.037e-03,  4.915e-04,  6.168e-04,  1.089e-03,  4.752e-04,  3.648e-04,  6.234e-04,  8.779e-05,  6.521e-05,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WW_TuneCP5_13TeV-pythia8_hadd.root
{ 3.018e-04,  1.043e-02,  4.845e-02,  6.513e-02,  1.071e-01,  2.019e-01,  2.017e-01,  2.501e-01,  1.584e-01,  6.145e-01,  6.177e-01,  8.993e-01,  9.275e-01,  9.992e-01,  9.877e-01,  1.018e+00,  1.126e+00,  1.289e+00,  1.331e+00,  1.355e+00,  1.423e+00,  1.425e+00,  1.440e+00,  1.457e+00,  1.480e+00,  1.471e+00,  1.434e+00,  1.434e+00,  1.429e+00,  1.381e+00,  1.283e+00,  1.213e+00,  1.131e+00,  1.047e+00,  9.739e-01,  9.086e-01,  8.499e-01,  8.138e-01,  7.742e-01,  7.845e-01,  8.022e-01,  8.859e-01,  1.029e+00,  1.216e+00,  1.389e+00,  1.519e+00,  1.625e+00,  1.584e+00,  1.436e+00,  1.245e+00,  9.776e-01,  7.491e-01,  5.429e-01,  3.611e-01,  2.505e-01,  1.608e-01,  1.079e-01,  6.801e-02,  4.409e-02,  2.918e-02,  1.887e-02,  1.343e-02,  9.357e-03,  6.979e-03,  5.942e-03,  4.430e-03,  2.926e-03,  2.752e-03,  1.944e-03,  2.239e-03,  1.256e-03,  1.275e-03,  1.081e-03,  2.170e-03,  8.758e-04,  2.946e-04,  1.980e-04,  1.251e-03,  6.351e-05,  4.519e-05,  8.788e-05,  1.750e-05,  2.166e-05,  4.529e-06,  6.827e-04,  5.040e-06,  3.539e-06,  5.339e-06,  3.386e-07,  1.611e-06,  3.558e-07,  2.628e-05,  5.922e-05,  4.948e-05,  1.817e-05,  7.404e-08,  2.665e-06,  8.511e-06,  1.599e-08,  1.641e-08,  0.000e+00,  }, // WZ_TuneCP5_13TeV-pythia8_hadd.root
{ 2.127e-01,  5.059e+00,  4.513e+00,  2.352e+00,  2.437e+00,  1.670e+00,  1.279e+00,  1.393e+00,  9.226e-01,  2.276e+00,  2.247e+00,  2.097e+00,  1.739e+00,  1.526e+00,  1.422e+00,  1.405e+00,  1.435e+00,  1.454e+00,  1.415e+00,  1.413e+00,  1.392e+00,  1.385e+00,  1.389e+00,  1.400e+00,  1.391e+00,  1.373e+00,  1.358e+00,  1.336e+00,  1.303e+00,  1.270e+00,  1.203e+00,  1.128e+00,  1.038e+00,  9.504e-01,  8.825e-01,  8.167e-01,  7.721e-01,  7.485e-01,  7.175e-01,  7.018e-01,  7.459e-01,  8.262e-01,  9.482e-01,  1.091e+00,  1.241e+00,  1.400e+00,  1.508e+00,  1.428e+00,  1.328e+00,  1.116e+00,  8.987e-01,  6.891e-01,  5.094e-01,  3.489e-01,  2.395e-01,  1.538e-01,  9.893e-02,  6.262e-02,  4.037e-02,  2.695e-02,  1.850e-02,  1.297e-02,  9.579e-03,  7.301e-03,  5.711e-03,  4.039e-03,  3.006e-03,  2.658e-03,  2.428e-03,  2.173e-03,  2.089e-03,  2.024e-03,  2.011e-03,  1.975e-03,  1.610e-03,  1.360e-03,  1.289e-03,  1.393e-03,  1.391e-03,  1.501e-03,  1.427e-03,  1.122e-03,  6.719e-04,  6.922e-04,  3.974e-04,  9.641e-04,  1.158e-03,  2.294e-04,  4.049e-04,  4.714e-04,  1.357e-04,  1.546e-04,  8.709e-05,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ZZ_TuneCP5_13TeV-pythia8_hadd.root

{ 2.056E-01,  7.899E+00,  4.713E+00,  2.577E+00,  1.710E+00,  2.055E+00,  1.343E+00,  1.413E+00,  8.378E-01,  2.087E+00,  2.329E+00,  2.022E+00,  1.711E+00,  1.492E+00,  1.444E+00,  1.429E+00,  1.452E+00,  1.426E+00,  1.422E+00,  1.398E+00,  1.384E+00,  1.386E+00,  1.388E+00,  1.392E+00,  1.417E+00,  1.387E+00,  1.348E+00,  1.341E+00,  1.312E+00,  1.252E+00,  1.188E+00,  1.117E+00,  1.046E+00,  9.538E-01,  8.812E-01,  8.161E-01,  7.746E-01,  7.481E-01,  7.265E-01,  6.966E-01,  7.434E-01,  8.335E-01,  9.463E-01,  1.084E+00,  1.240E+00,  1.386E+00,  1.485E+00,  1.425E+00,  1.322E+00,  1.124E+00,  9.141E-01,  6.846E-01,  5.031E-01,  3.532E-01,  2.404E-01,  1.564E-01,  1.007E-01,  6.349E-02,  4.057E-02,  2.684E-02,  1.904E-02,  1.309E-02,  9.545E-03,  7.271E-03,  5.865E-03,  4.127E-03,  3.062E-03,  2.671E-03,  2.520E-03,  2.381E-03,  2.130E-03,  2.124E-03,  2.262E-03,  1.985E-03,  1.517E-03,  1.421E-03,  1.173E-03,  1.121E-03,  1.337E-03,  1.383E-03,  }, // BB1000.root
{ 1.661E-01,  4.417E+00,  4.027E+00,  2.690E+00,  1.956E+00,  1.749E+00,  1.106E+00,  1.409E+00,  9.919E-01,  2.171E+00,  2.101E+00,  1.976E+00,  1.693E+00,  1.508E+00,  1.449E+00,  1.427E+00,  1.416E+00,  1.448E+00,  1.427E+00,  1.394E+00,  1.395E+00,  1.403E+00,  1.375E+00,  1.387E+00,  1.363E+00,  1.381E+00,  1.364E+00,  1.335E+00,  1.317E+00,  1.264E+00,  1.201E+00,  1.140E+00,  1.038E+00,  9.574E-01,  8.777E-01,  8.191E-01,  7.790E-01,  7.521E-01,  7.174E-01,  7.135E-01,  7.466E-01,  8.193E-01,  9.256E-01,  1.081E+00,  1.242E+00,  1.379E+00,  1.514E+00,  1.421E+00,  1.300E+00,  1.127E+00,  9.013E-01,  6.879E-01,  5.031E-01,  3.532E-01,  2.380E-01,  1.556E-01,  1.002E-01,  6.311E-02,  4.133E-02,  2.698E-02,  1.886E-02,  1.305E-02,  9.565E-03,  7.287E-03,  6.017E-03,  4.276E-03,  2.966E-03,  2.825E-03,  2.398E-03,  2.147E-03,  2.177E-03,  1.912E-03,  2.359E-03,  2.119E-03,  1.825E-03,  1.359E-03,  1.321E-03,  1.401E-03,  1.569E-03,  1.504E-03,  }, // BB1100.root
{ 1.654E-01,  4.545E+00,  6.215E+00,  2.097E+00,  2.214E+00,  2.036E+00,  1.192E+00,  1.480E+00,  9.204E-01,  2.083E+00,  2.268E+00,  2.025E+00,  1.751E+00,  1.558E+00,  1.432E+00,  1.412E+00,  1.423E+00,  1.422E+00,  1.422E+00,  1.423E+00,  1.375E+00,  1.382E+00,  1.387E+00,  1.399E+00,  1.396E+00,  1.359E+00,  1.361E+00,  1.337E+00,  1.308E+00,  1.261E+00,  1.203E+00,  1.123E+00,  1.041E+00,  9.600E-01,  8.778E-01,  8.192E-01,  7.719E-01,  7.487E-01,  7.160E-01,  7.045E-01,  7.382E-01,  8.266E-01,  9.395E-01,  1.091E+00,  1.289E+00,  1.411E+00,  1.491E+00,  1.451E+00,  1.318E+00,  1.136E+00,  9.007E-01,  6.904E-01,  5.074E-01,  3.517E-01,  2.377E-01,  1.550E-01,  9.910E-02,  6.372E-02,  4.068E-02,  2.661E-02,  1.848E-02,  1.304E-02,  9.289E-03,  7.570E-03,  5.970E-03,  4.156E-03,  3.102E-03,  2.675E-03,  2.493E-03,  2.348E-03,  2.153E-03,  2.164E-03,  2.067E-03,  2.232E-03,  1.651E-03,  1.329E-03,  1.189E-03,  1.540E-03,  1.090E-03,  1.160E-03,  }, // BB1200.root
{ 1.842E-01,  4.898E+00,  4.763E+00,  2.210E+00,  1.818E+00,  1.878E+00,  1.485E+00,  1.359E+00,  9.092E-01,  2.144E+00,  2.126E+00,  2.030E+00,  1.795E+00,  1.497E+00,  1.421E+00,  1.421E+00,  1.442E+00,  1.416E+00,  1.406E+00,  1.398E+00,  1.407E+00,  1.392E+00,  1.388E+00,  1.379E+00,  1.393E+00,  1.377E+00,  1.355E+00,  1.330E+00,  1.311E+00,  1.250E+00,  1.205E+00,  1.127E+00,  1.041E+00,  9.541E-01,  8.848E-01,  8.259E-01,  7.707E-01,  7.619E-01,  7.099E-01,  6.994E-01,  7.386E-01,  8.218E-01,  9.544E-01,  1.093E+00,  1.253E+00,  1.400E+00,  1.505E+00,  1.446E+00,  1.306E+00,  1.125E+00,  9.179E-01,  7.043E-01,  5.078E-01,  3.525E-01,  2.347E-01,  1.550E-01,  1.011E-01,  6.314E-02,  4.100E-02,  2.693E-02,  1.825E-02,  1.298E-02,  9.695E-03,  7.328E-03,  5.836E-03,  4.015E-03,  2.960E-03,  2.726E-03,  2.452E-03,  2.320E-03,  2.179E-03,  2.294E-03,  2.411E-03,  1.786E-03,  1.631E-03,  1.475E-03,  1.479E-03,  1.327E-03,  1.503E-03,  2.001E-03,  }, // BB1300.root
{ 2.024E-01,  2.243E+00,  3.927E+00,  2.603E+00,  2.119E+00,  1.720E+00,  1.379E+00,  1.487E+00,  8.364E-01,  2.367E+00,  1.997E+00,  2.172E+00,  1.729E+00,  1.496E+00,  1.472E+00,  1.383E+00,  1.453E+00,  1.460E+00,  1.425E+00,  1.431E+00,  1.391E+00,  1.397E+00,  1.392E+00,  1.386E+00,  1.402E+00,  1.387E+00,  1.359E+00,  1.326E+00,  1.315E+00,  1.252E+00,  1.210E+00,  1.128E+00,  1.038E+00,  9.551E-01,  8.802E-01,  8.157E-01,  7.734E-01,  7.449E-01,  7.173E-01,  7.089E-01,  7.447E-01,  8.204E-01,  9.401E-01,  1.088E+00,  1.247E+00,  1.382E+00,  1.467E+00,  1.439E+00,  1.283E+00,  1.127E+00,  9.193E-01,  6.967E-01,  5.020E-01,  3.484E-01,  2.358E-01,  1.575E-01,  1.002E-01,  6.237E-02,  4.088E-02,  2.647E-02,  1.846E-02,  1.308E-02,  9.674E-03,  7.274E-03,  5.831E-03,  4.240E-03,  3.081E-03,  2.811E-03,  2.484E-03,  2.242E-03,  2.170E-03,  1.919E-03,  1.753E-03,  2.161E-03,  1.450E-03,  1.460E-03,  1.087E-03,  1.274E-03,  1.434E-03,  1.158E-03,  }, // BB1400.root
{ 2.710E-01,  1.562E+01,  5.694E+00,  5.944E+00,  1.790E+00,  1.641E+00,  1.460E+00,  1.465E+00,  8.610E-01,  2.483E+00,  2.174E+00,  2.001E+00,  1.736E+00,  1.509E+00,  1.435E+00,  1.429E+00,  1.436E+00,  1.437E+00,  1.387E+00,  1.416E+00,  1.403E+00,  1.375E+00,  1.391E+00,  1.391E+00,  1.422E+00,  1.354E+00,  1.367E+00,  1.344E+00,  1.289E+00,  1.257E+00,  1.221E+00,  1.136E+00,  1.026E+00,  9.583E-01,  8.771E-01,  8.242E-01,  7.796E-01,  7.516E-01,  7.115E-01,  7.056E-01,  7.352E-01,  8.179E-01,  9.278E-01,  1.068E+00,  1.234E+00,  1.424E+00,  1.490E+00,  1.471E+00,  1.322E+00,  1.130E+00,  9.215E-01,  6.946E-01,  5.012E-01,  3.504E-01,  2.393E-01,  1.582E-01,  9.964E-02,  6.288E-02,  4.165E-02,  2.727E-02,  1.862E-02,  1.351E-02,  9.349E-03,  7.174E-03,  5.686E-03,  4.044E-03,  2.981E-03,  2.696E-03,  2.460E-03,  2.277E-03,  2.014E-03,  1.942E-03,  1.921E-03,  2.342E-03,  1.817E-03,  1.347E-03,  1.598E-03,  1.293E-03,  1.033E-03,  1.063E-03,  }, // BB1500.root
{ 2.823E-01,  8.133E+00,  3.559E+00,  2.477E+00,  1.864E+00,  1.481E+00,  1.267E+00,  1.314E+00,  8.506E-01,  2.302E+00,  2.152E+00,  2.030E+00,  1.689E+00,  1.611E+00,  1.410E+00,  1.425E+00,  1.436E+00,  1.417E+00,  1.425E+00,  1.401E+00,  1.386E+00,  1.392E+00,  1.412E+00,  1.393E+00,  1.387E+00,  1.371E+00,  1.365E+00,  1.349E+00,  1.302E+00,  1.252E+00,  1.197E+00,  1.121E+00,  1.036E+00,  9.429E-01,  8.789E-01,  8.225E-01,  7.863E-01,  7.528E-01,  7.123E-01,  6.990E-01,  7.350E-01,  8.391E-01,  9.391E-01,  1.082E+00,  1.238E+00,  1.389E+00,  1.481E+00,  1.413E+00,  1.316E+00,  1.123E+00,  9.017E-01,  7.032E-01,  5.037E-01,  3.560E-01,  2.371E-01,  1.575E-01,  1.004E-01,  6.463E-02,  4.175E-02,  2.727E-02,  1.856E-02,  1.317E-02,  9.584E-03,  7.311E-03,  5.700E-03,  4.156E-03,  3.120E-03,  2.764E-03,  2.450E-03,  2.345E-03,  2.093E-03,  1.959E-03,  2.052E-03,  2.018E-03,  1.558E-03,  1.238E-03,  1.314E-03,  1.010E-03,  1.418E-03,  1.173E-03,  }, // BB1600.root
{ 3.391E-01,  0.000E+00,  4.228E+00,  3.745E+00,  1.883E+00,  1.344E+00,  1.488E+00,  1.288E+00,  8.610E-01,  2.032E+00,  2.241E+00,  1.879E+00,  1.740E+00,  1.507E+00,  1.481E+00,  1.382E+00,  1.391E+00,  1.442E+00,  1.458E+00,  1.413E+00,  1.394E+00,  1.349E+00,  1.406E+00,  1.405E+00,  1.358E+00,  1.394E+00,  1.381E+00,  1.351E+00,  1.320E+00,  1.235E+00,  1.208E+00,  1.108E+00,  1.050E+00,  9.623E-01,  8.796E-01,  8.129E-01,  7.661E-01,  7.235E-01,  7.212E-01,  7.158E-01,  7.480E-01,  8.271E-01,  9.392E-01,  1.084E+00,  1.273E+00,  1.414E+00,  1.459E+00,  1.430E+00,  1.320E+00,  1.154E+00,  9.099E-01,  6.897E-01,  5.105E-01,  3.576E-01,  2.326E-01,  1.547E-01,  1.001E-01,  6.478E-02,  4.092E-02,  2.751E-02,  1.872E-02,  1.260E-02,  9.481E-03,  7.185E-03,  5.979E-03,  4.075E-03,  3.148E-03,  2.765E-03,  2.301E-03,  2.228E-03,  2.307E-03,  1.825E-03,  2.096E-03,  2.210E-03,  1.702E-03,  1.243E-03,  1.271E-03,  1.440E-03,  1.622E-03,  1.507E-03,  }, // BB1800.root
{ 1.961E-01,  4.693E+00,  3.423E+00,  2.165E+00,  1.829E+00,  1.623E+00,  1.431E+00,  1.188E+00,  8.092E-01,  1.995E+00,  2.197E+00,  2.099E+00,  1.750E+00,  1.561E+00,  1.492E+00,  1.407E+00,  1.444E+00,  1.429E+00,  1.414E+00,  1.395E+00,  1.390E+00,  1.380E+00,  1.389E+00,  1.387E+00,  1.399E+00,  1.389E+00,  1.370E+00,  1.323E+00,  1.303E+00,  1.268E+00,  1.196E+00,  1.114E+00,  1.050E+00,  9.590E-01,  8.840E-01,  8.201E-01,  7.654E-01,  7.413E-01,  7.169E-01,  7.049E-01,  7.369E-01,  8.288E-01,  9.535E-01,  1.099E+00,  1.243E+00,  1.384E+00,  1.470E+00,  1.429E+00,  1.331E+00,  1.144E+00,  9.079E-01,  6.958E-01,  5.124E-01,  3.503E-01,  2.418E-01,  1.531E-01,  1.011E-01,  6.354E-02,  4.080E-02,  2.680E-02,  1.823E-02,  1.322E-02,  9.581E-03,  7.384E-03,  5.964E-03,  4.126E-03,  3.110E-03,  2.624E-03,  2.460E-03,  2.274E-03,  2.156E-03,  2.164E-03,  1.919E-03,  1.784E-03,  1.388E-03,  1.372E-03,  1.150E-03,  1.060E-03,  9.575E-04,  1.250E-03,  }, // TpTp1000.root
{ 2.421E-01,  3.399E+00,  3.718E+00,  2.300E+00,  2.091E+00,  1.592E+00,  1.567E+00,  1.341E+00,  9.583E-01,  2.196E+00,  2.139E+00,  2.213E+00,  1.743E+00,  1.527E+00,  1.451E+00,  1.419E+00,  1.423E+00,  1.438E+00,  1.418E+00,  1.415E+00,  1.392E+00,  1.385E+00,  1.391E+00,  1.399E+00,  1.405E+00,  1.387E+00,  1.359E+00,  1.321E+00,  1.305E+00,  1.270E+00,  1.183E+00,  1.107E+00,  1.052E+00,  9.529E-01,  8.726E-01,  8.193E-01,  7.717E-01,  7.530E-01,  7.146E-01,  7.028E-01,  7.514E-01,  8.205E-01,  9.305E-01,  1.087E+00,  1.258E+00,  1.412E+00,  1.483E+00,  1.431E+00,  1.319E+00,  1.153E+00,  9.135E-01,  7.011E-01,  5.003E-01,  3.526E-01,  2.421E-01,  1.564E-01,  1.012E-01,  6.385E-02,  4.073E-02,  2.699E-02,  1.807E-02,  1.304E-02,  9.435E-03,  7.052E-03,  5.666E-03,  4.177E-03,  3.104E-03,  2.684E-03,  2.394E-03,  2.418E-03,  2.250E-03,  2.151E-03,  2.142E-03,  1.890E-03,  1.766E-03,  1.233E-03,  1.131E-03,  1.520E-03,  1.222E-03,  1.086E-03,  }, // TpTp1100.root
{ 2.274E-01,  2.464E+00,  3.234E+00,  2.251E+00,  1.963E+00,  2.163E+00,  1.615E+00,  1.444E+00,  7.966E-01,  2.141E+00,  2.176E+00,  1.993E+00,  1.780E+00,  1.540E+00,  1.430E+00,  1.415E+00,  1.431E+00,  1.421E+00,  1.415E+00,  1.381E+00,  1.390E+00,  1.389E+00,  1.390E+00,  1.414E+00,  1.387E+00,  1.364E+00,  1.354E+00,  1.325E+00,  1.321E+00,  1.250E+00,  1.205E+00,  1.133E+00,  1.045E+00,  9.548E-01,  8.865E-01,  8.137E-01,  7.625E-01,  7.428E-01,  7.208E-01,  7.062E-01,  7.575E-01,  8.301E-01,  9.422E-01,  1.098E+00,  1.245E+00,  1.404E+00,  1.480E+00,  1.453E+00,  1.348E+00,  1.126E+00,  9.126E-01,  6.806E-01,  4.997E-01,  3.478E-01,  2.339E-01,  1.566E-01,  1.010E-01,  6.358E-02,  4.118E-02,  2.729E-02,  1.825E-02,  1.329E-02,  9.582E-03,  7.369E-03,  5.816E-03,  4.242E-03,  3.090E-03,  2.630E-03,  2.368E-03,  2.272E-03,  2.171E-03,  1.978E-03,  2.132E-03,  2.177E-03,  1.600E-03,  1.494E-03,  1.260E-03,  1.322E-03,  1.701E-03,  1.045E-03,  }, // TpTp1200.root
{ 1.644E-01,  3.123E+00,  3.986E+00,  2.219E+00,  1.704E+00,  1.531E+00,  1.319E+00,  1.268E+00,  9.258E-01,  2.165E+00,  2.087E+00,  2.035E+00,  1.780E+00,  1.517E+00,  1.457E+00,  1.418E+00,  1.405E+00,  1.419E+00,  1.438E+00,  1.409E+00,  1.386E+00,  1.420E+00,  1.381E+00,  1.396E+00,  1.386E+00,  1.398E+00,  1.364E+00,  1.339E+00,  1.302E+00,  1.258E+00,  1.206E+00,  1.119E+00,  1.042E+00,  9.488E-01,  8.870E-01,  8.242E-01,  7.657E-01,  7.487E-01,  7.267E-01,  7.039E-01,  7.467E-01,  8.331E-01,  9.451E-01,  1.088E+00,  1.248E+00,  1.374E+00,  1.467E+00,  1.418E+00,  1.316E+00,  1.133E+00,  9.029E-01,  6.741E-01,  5.107E-01,  3.567E-01,  2.398E-01,  1.568E-01,  9.943E-02,  6.354E-02,  4.198E-02,  2.673E-02,  1.837E-02,  1.264E-02,  9.297E-03,  7.306E-03,  5.766E-03,  4.035E-03,  3.086E-03,  2.674E-03,  2.425E-03,  2.113E-03,  2.148E-03,  2.262E-03,  1.892E-03,  1.850E-03,  1.470E-03,  1.289E-03,  1.736E-03,  1.386E-03,  1.103E-03,  1.116E-03,  }, // TpTp1300.root
{ 2.259E-01,  2.503E+00,  1.460E+01,  2.258E+00,  2.001E+00,  1.683E+00,  1.123E+00,  1.317E+00,  1.018E+00,  2.115E+00,  2.290E+00,  2.001E+00,  1.798E+00,  1.523E+00,  1.432E+00,  1.442E+00,  1.406E+00,  1.438E+00,  1.414E+00,  1.425E+00,  1.396E+00,  1.390E+00,  1.394E+00,  1.405E+00,  1.406E+00,  1.398E+00,  1.349E+00,  1.343E+00,  1.299E+00,  1.252E+00,  1.214E+00,  1.133E+00,  1.054E+00,  9.478E-01,  8.770E-01,  8.120E-01,  7.754E-01,  7.426E-01,  7.193E-01,  7.032E-01,  7.369E-01,  8.230E-01,  9.410E-01,  1.100E+00,  1.252E+00,  1.390E+00,  1.473E+00,  1.433E+00,  1.335E+00,  1.121E+00,  9.185E-01,  6.828E-01,  5.034E-01,  3.511E-01,  2.375E-01,  1.556E-01,  1.012E-01,  6.249E-02,  4.154E-02,  2.636E-02,  1.811E-02,  1.293E-02,  9.374E-03,  7.349E-03,  5.789E-03,  4.230E-03,  2.986E-03,  2.748E-03,  2.369E-03,  2.135E-03,  2.288E-03,  2.089E-03,  1.808E-03,  1.703E-03,  1.548E-03,  1.171E-03,  1.230E-03,  1.194E-03,  1.670E-03,  1.534E-03,  }, // TpTp1400.root
{ 2.534E-01,  4.774E+00,  3.214E+00,  2.769E+00,  1.353E+00,  1.656E+00,  1.323E+00,  1.369E+00,  8.440E-01,  2.160E+00,  2.081E+00,  2.068E+00,  1.726E+00,  1.534E+00,  1.434E+00,  1.419E+00,  1.411E+00,  1.424E+00,  1.405E+00,  1.426E+00,  1.388E+00,  1.389E+00,  1.380E+00,  1.409E+00,  1.402E+00,  1.378E+00,  1.339E+00,  1.325E+00,  1.307E+00,  1.274E+00,  1.184E+00,  1.134E+00,  1.041E+00,  9.602E-01,  8.671E-01,  8.262E-01,  7.761E-01,  7.544E-01,  7.171E-01,  7.107E-01,  7.460E-01,  8.273E-01,  9.512E-01,  1.085E+00,  1.249E+00,  1.383E+00,  1.475E+00,  1.440E+00,  1.307E+00,  1.127E+00,  9.317E-01,  6.889E-01,  5.082E-01,  3.543E-01,  2.389E-01,  1.564E-01,  9.975E-02,  6.308E-02,  4.107E-02,  2.683E-02,  1.837E-02,  1.300E-02,  9.587E-03,  7.369E-03,  5.801E-03,  4.057E-03,  3.202E-03,  2.540E-03,  2.601E-03,  2.136E-03,  2.060E-03,  2.101E-03,  1.910E-03,  2.114E-03,  1.445E-03,  1.064E-03,  1.113E-03,  1.423E-03,  9.898E-04,  1.170E-03,  }, // TpTp1500.root
{ 1.691E-01,  4.496E+00,  3.577E+00,  2.191E+00,  1.797E+00,  1.535E+00,  1.462E+00,  1.319E+00,  9.965E-01,  2.230E+00,  2.421E+00,  2.204E+00,  1.788E+00,  1.538E+00,  1.485E+00,  1.431E+00,  1.447E+00,  1.434E+00,  1.431E+00,  1.428E+00,  1.359E+00,  1.384E+00,  1.392E+00,  1.374E+00,  1.407E+00,  1.371E+00,  1.361E+00,  1.308E+00,  1.299E+00,  1.267E+00,  1.197E+00,  1.122E+00,  1.053E+00,  9.560E-01,  8.843E-01,  8.065E-01,  7.815E-01,  7.474E-01,  7.171E-01,  7.104E-01,  7.420E-01,  8.319E-01,  9.367E-01,  1.106E+00,  1.275E+00,  1.387E+00,  1.467E+00,  1.429E+00,  1.347E+00,  1.114E+00,  9.222E-01,  6.787E-01,  4.913E-01,  3.537E-01,  2.385E-01,  1.556E-01,  9.965E-02,  6.276E-02,  4.035E-02,  2.740E-02,  1.810E-02,  1.318E-02,  9.708E-03,  7.336E-03,  5.762E-03,  4.249E-03,  3.249E-03,  2.613E-03,  2.482E-03,  2.292E-03,  2.000E-03,  2.002E-03,  2.071E-03,  2.412E-03,  2.049E-03,  1.224E-03,  1.200E-03,  1.072E-03,  9.581E-04,  1.377E-03,  }, // TpTp1600.root
{ 3.213E-01,  2.238E+00,  3.428E+00,  2.385E+00,  1.650E+00,  1.278E+00,  1.188E+00,  1.960E+00,  7.860E-01,  1.943E+00,  2.136E+00,  2.060E+00,  1.775E+00,  1.562E+00,  1.424E+00,  1.397E+00,  1.471E+00,  1.430E+00,  1.411E+00,  1.430E+00,  1.373E+00,  1.387E+00,  1.393E+00,  1.413E+00,  1.407E+00,  1.372E+00,  1.351E+00,  1.310E+00,  1.314E+00,  1.255E+00,  1.208E+00,  1.141E+00,  1.031E+00,  9.504E-01,  8.791E-01,  8.118E-01,  7.635E-01,  7.642E-01,  7.256E-01,  7.090E-01,  7.532E-01,  8.499E-01,  9.292E-01,  1.101E+00,  1.240E+00,  1.378E+00,  1.481E+00,  1.411E+00,  1.337E+00,  1.109E+00,  9.057E-01,  6.796E-01,  4.907E-01,  3.592E-01,  2.375E-01,  1.545E-01,  1.004E-01,  6.358E-02,  4.029E-02,  2.685E-02,  1.822E-02,  1.306E-02,  9.822E-03,  7.220E-03,  5.894E-03,  4.330E-03,  3.072E-03,  2.566E-03,  2.609E-03,  2.479E-03,  2.090E-03,  1.923E-03,  1.771E-03,  1.701E-03,  1.425E-03,  1.705E-03,  1.387E-03,  1.038E-03,  1.669E-03,  8.726E-04,  }, // TpTp1700.root
{ 1.647E-01,  2.629E+00,  7.189E+00,  4.002E+00,  2.561E+00,  1.140E+00,  1.475E+00,  1.133E+00,  8.043E-01,  2.417E+00,  1.969E+00,  2.093E+00,  1.760E+00,  1.645E+00,  1.470E+00,  1.421E+00,  1.446E+00,  1.424E+00,  1.443E+00,  1.381E+00,  1.392E+00,  1.383E+00,  1.395E+00,  1.410E+00,  1.378E+00,  1.394E+00,  1.367E+00,  1.311E+00,  1.335E+00,  1.267E+00,  1.225E+00,  1.115E+00,  1.033E+00,  9.579E-01,  8.720E-01,  8.262E-01,  7.811E-01,  7.436E-01,  7.204E-01,  6.902E-01,  7.564E-01,  8.223E-01,  9.296E-01,  1.078E+00,  1.194E+00,  1.428E+00,  1.491E+00,  1.445E+00,  1.314E+00,  1.121E+00,  8.760E-01,  6.718E-01,  4.929E-01,  3.538E-01,  2.436E-01,  1.542E-01,  1.025E-01,  6.329E-02,  4.176E-02,  2.635E-02,  1.866E-02,  1.292E-02,  9.715E-03,  7.350E-03,  6.253E-03,  4.082E-03,  3.054E-03,  2.707E-03,  2.361E-03,  2.222E-03,  2.066E-03,  1.773E-03,  2.820E-03,  2.522E-03,  1.824E-03,  1.134E-03,  1.513E-03,  1.399E-03,  1.800E-03,  8.053E-04,  }, // TpTp1800.root
};

   pileupweightUp = { // 69.2 + 4.6%
{ 1.713e-01,  3.545e+00,  2.846e+00,  2.380e+00,  1.336e+00,  1.378e+00,  1.251e+00,  1.148e+00,  5.048e-01,  9.470e-01,  1.048e+00,  1.028e+00,  1.005e+00,  9.025e-01,  8.265e-01,  7.959e-01,  8.164e-01,  8.660e-01,  9.318e-01,  9.855e-01,  1.031e+00,  1.083e+00,  1.131e+00,  1.155e+00,  1.167e+00,  1.168e+00,  1.173e+00,  1.180e+00,  1.210e+00,  1.211e+00,  1.211e+00,  1.180e+00,  1.139e+00,  1.091e+00,  1.037e+00,  9.949e-01,  9.570e-01,  9.275e-01,  8.771e-01,  8.328e-01,  8.285e-01,  8.401e-01,  8.685e-01,  9.214e-01,  9.967e-01,  1.111e+00,  1.249e+00,  1.347e+00,  1.448e+00,  1.490e+00,  1.491e+00,  1.431e+00,  1.315e+00,  1.167e+00,  9.974e-01,  8.041e-01,  6.288e-01,  4.757e-01,  3.622e-01,  2.742e-01,  2.116e-01,  1.642e-01,  1.314e-01,  1.076e-01,  8.905e-02,  6.510e-02,  4.791e-02,  4.161e-02,  3.756e-02,  3.452e-02,  3.138e-02,  3.044e-02,  2.952e-02,  2.937e-02,  2.383e-02,  1.984e-02,  1.993e-02,  2.181e-02,  2.121e-02,  2.560e-02,  2.614e-02,  2.514e-02,  3.242e-02,  2.330e-02,  2.219e-02,  3.260e-02,  1.986e-02,  3.366e-02,  2.852e-02,  3.267e-02,  8.494e-02,  2.740e-02,  7.017e-03,  2.228e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.866e-01,  4.325e+00,  2.965e+00,  2.599e+00,  1.322e+00,  1.339e+00,  1.222e+00,  1.135e+00,  4.911e-01,  9.451e-01,  1.050e+00,  1.029e+00,  1.015e+00,  9.035e-01,  8.252e-01,  7.978e-01,  8.163e-01,  8.662e-01,  9.333e-01,  9.841e-01,  1.032e+00,  1.084e+00,  1.126e+00,  1.155e+00,  1.163e+00,  1.165e+00,  1.172e+00,  1.179e+00,  1.211e+00,  1.214e+00,  1.210e+00,  1.179e+00,  1.143e+00,  1.090e+00,  1.037e+00,  9.964e-01,  9.572e-01,  9.294e-01,  8.787e-01,  8.353e-01,  8.300e-01,  8.395e-01,  8.679e-01,  9.199e-01,  1.003e+00,  1.119e+00,  1.251e+00,  1.331e+00,  1.447e+00,  1.491e+00,  1.488e+00,  1.423e+00,  1.314e+00,  1.163e+00,  9.932e-01,  8.020e-01,  6.294e-01,  4.798e-01,  3.612e-01,  2.765e-01,  2.107e-01,  1.649e-01,  1.315e-01,  1.063e-01,  8.934e-02,  6.489e-02,  4.832e-02,  4.175e-02,  3.726e-02,  3.452e-02,  3.161e-02,  2.996e-02,  3.005e-02,  2.953e-02,  2.313e-02,  1.926e-02,  2.070e-02,  2.114e-02,  2.226e-02,  2.196e-02,  2.371e-02,  2.526e-02,  2.875e-02,  2.526e-02,  1.981e-02,  2.100e-02,  3.103e-02,  2.401e-02,  2.373e-02,  2.071e-02,  1.616e-02,  1.303e-02,  1.112e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.972e-01,  3.210e+00,  2.712e+00,  2.808e+00,  1.512e+00,  1.318e+00,  1.219e+00,  1.177e+00,  4.858e-01,  9.347e-01,  1.074e+00,  1.032e+00,  1.013e+00,  9.009e-01,  8.281e-01,  7.922e-01,  8.116e-01,  8.663e-01,  9.334e-01,  9.899e-01,  1.037e+00,  1.087e+00,  1.131e+00,  1.150e+00,  1.164e+00,  1.165e+00,  1.173e+00,  1.179e+00,  1.206e+00,  1.210e+00,  1.211e+00,  1.178e+00,  1.140e+00,  1.093e+00,  1.039e+00,  9.948e-01,  9.559e-01,  9.283e-01,  8.790e-01,  8.341e-01,  8.279e-01,  8.408e-01,  8.703e-01,  9.206e-01,  1.003e+00,  1.115e+00,  1.251e+00,  1.346e+00,  1.445e+00,  1.481e+00,  1.487e+00,  1.429e+00,  1.315e+00,  1.162e+00,  9.954e-01,  8.026e-01,  6.291e-01,  4.770e-01,  3.608e-01,  2.751e-01,  2.118e-01,  1.650e-01,  1.308e-01,  1.068e-01,  8.947e-02,  6.508e-02,  4.828e-02,  4.171e-02,  3.735e-02,  3.450e-02,  3.164e-02,  3.064e-02,  2.826e-02,  2.905e-02,  2.275e-02,  2.025e-02,  1.984e-02,  2.147e-02,  2.426e-02,  2.133e-02,  2.486e-02,  3.111e-02,  3.029e-02,  2.158e-02,  1.764e-02,  2.418e-02,  2.183e-02,  2.051e-02,  3.244e-02,  2.123e-02,  6.900e-02,  4.452e-02,  2.850e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.865e-01,  5.354e+00,  3.499e+00,  2.545e+00,  1.518e+00,  1.312e+00,  1.347e+00,  1.352e+00,  5.027e-01,  9.633e-01,  1.081e+00,  1.030e+00,  9.848e-01,  9.086e-01,  8.266e-01,  7.914e-01,  8.031e-01,  8.712e-01,  9.336e-01,  9.830e-01,  1.035e+00,  1.082e+00,  1.130e+00,  1.159e+00,  1.168e+00,  1.165e+00,  1.173e+00,  1.172e+00,  1.212e+00,  1.216e+00,  1.206e+00,  1.177e+00,  1.141e+00,  1.093e+00,  1.038e+00,  9.959e-01,  9.608e-01,  9.240e-01,  8.785e-01,  8.332e-01,  8.232e-01,  8.469e-01,  8.697e-01,  9.207e-01,  1.003e+00,  1.112e+00,  1.251e+00,  1.336e+00,  1.446e+00,  1.483e+00,  1.504e+00,  1.431e+00,  1.310e+00,  1.173e+00,  9.843e-01,  7.992e-01,  6.291e-01,  4.813e-01,  3.605e-01,  2.756e-01,  2.117e-01,  1.648e-01,  1.327e-01,  1.061e-01,  8.969e-02,  6.459e-02,  4.793e-02,  4.264e-02,  3.758e-02,  3.353e-02,  3.142e-02,  3.009e-02,  2.977e-02,  2.974e-02,  2.164e-02,  1.871e-02,  2.153e-02,  2.087e-02,  2.174e-02,  2.007e-02,  2.494e-02,  2.265e-02,  3.076e-02,  2.302e-02,  1.282e-02,  1.797e-02,  4.397e-02,  2.916e-02,  2.883e-02,  3.774e-02,  2.453e-02,  5.275e-03,  5.066e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 5.039e-04,  1.494e-01,  5.339e-02,  1.056e-01,  6.698e-02,  6.264e-02,  5.444e-02,  1.444e-01,  8.380e-02,  1.927e-01,  3.448e-01,  5.859e-01,  4.878e-01,  4.942e-01,  4.739e-01,  4.986e-01,  5.874e-01,  6.995e-01,  8.566e-01,  8.998e-01,  1.033e+00,  1.097e+00,  1.162e+00,  1.202e+00,  1.241e+00,  1.259e+00,  1.083e+00,  1.291e+00,  1.341e+00,  1.352e+00,  1.326e+00,  1.297e+00,  1.230e+00,  1.166e+00,  1.137e+00,  1.093e+00,  1.051e+00,  1.027e+00,  9.228e-01,  9.289e-01,  8.380e-01,  9.384e-01,  9.171e-01,  1.028e+00,  1.125e+00,  1.247e+00,  1.356e+00,  1.511e+00,  1.643e+00,  1.671e+00,  1.591e+00,  1.566e+00,  1.428e+00,  1.277e+00,  1.086e+00,  7.924e-01,  6.757e-01,  5.091e-01,  3.928e-01,  2.590e-01,  2.290e-01,  1.752e-01,  1.403e-01,  1.036e-01,  9.661e-02,  7.223e-02,  5.024e-02,  4.459e-02,  4.100e-02,  3.921e-02,  3.575e-02,  2.740e-02,  4.088e-03,  3.190e-02,  1.739e-03,  2.333e-02,  2.054e-02,  1.954e-02,  9.435e-04,  4.563e-04,  3.984e-02,  6.548e-03,  3.225e-02,  1.091e-02,  5.885e-02,  1.974e-02,  0.000e+00,  1.747e-02,  8.341e-05,  0.000e+00,  4.898e-03,  0.000e+00,  0.000e+00,  1.285e-03,  0.000e+00,  0.000e+00,  3.131e-04,  1.923e-04,  0.000e+00,  2.138e-06,  0.000e+00,  }, // DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 2.422e-01,  3.014e+00,  3.977e+00,  4.078e+00,  1.349e+00,  1.323e+00,  1.095e+00,  1.140e+00,  5.757e-01,  9.821e-01,  9.954e-01,  1.035e+00,  9.831e-01,  8.844e-01,  8.331e-01,  8.155e-01,  8.296e-01,  8.611e-01,  9.186e-01,  9.746e-01,  1.029e+00,  1.071e+00,  1.120e+00,  1.160e+00,  1.175e+00,  1.176e+00,  1.172e+00,  1.200e+00,  1.209e+00,  1.198e+00,  1.231e+00,  1.163e+00,  1.153e+00,  1.099e+00,  1.044e+00,  1.005e+00,  9.751e-01,  9.229e-01,  8.765e-01,  8.121e-01,  8.221e-01,  8.438e-01,  8.623e-01,  9.205e-01,  1.016e+00,  1.105e+00,  1.258e+00,  1.347e+00,  1.424e+00,  1.495e+00,  1.462e+00,  1.405e+00,  1.332e+00,  1.174e+00,  9.972e-01,  8.138e-01,  6.145e-01,  4.709e-01,  3.664e-01,  2.725e-01,  2.115e-01,  1.639e-01,  1.306e-01,  1.080e-01,  8.739e-02,  6.307e-02,  4.881e-02,  4.247e-02,  3.788e-02,  3.420e-02,  3.282e-02,  3.276e-02,  2.989e-02,  2.927e-02,  2.232e-02,  1.830e-02,  1.559e-02,  1.733e-02,  1.624e-02,  2.418e-02,  2.592e-02,  2.059e-02,  2.797e-02,  1.420e-02,  1.276e-02,  0.000e+00,  1.713e-02,  1.136e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.159e-01,  3.316e+00,  2.188e+00,  2.125e+00,  1.197e+00,  1.495e+00,  9.600e-01,  1.072e+00,  5.141e-01,  1.029e+00,  1.030e+00,  1.062e+00,  1.082e+00,  9.059e-01,  8.631e-01,  7.931e-01,  8.078e-01,  8.667e-01,  9.568e-01,  9.698e-01,  1.030e+00,  1.093e+00,  1.132e+00,  1.155e+00,  1.182e+00,  1.175e+00,  1.172e+00,  1.185e+00,  1.212e+00,  1.215e+00,  1.194e+00,  1.184e+00,  1.152e+00,  1.088e+00,  1.056e+00,  9.751e-01,  9.499e-01,  9.500e-01,  8.902e-01,  8.158e-01,  8.238e-01,  8.228e-01,  8.676e-01,  8.954e-01,  1.004e+00,  1.121e+00,  1.270e+00,  1.336e+00,  1.460e+00,  1.484e+00,  1.460e+00,  1.415e+00,  1.351e+00,  1.159e+00,  9.735e-01,  7.739e-01,  6.232e-01,  4.685e-01,  3.660e-01,  2.752e-01,  2.183e-01,  1.689e-01,  1.274e-01,  1.049e-01,  9.521e-02,  6.761e-02,  4.838e-02,  4.338e-02,  3.274e-02,  3.153e-02,  2.801e-02,  2.851e-02,  3.011e-02,  3.438e-02,  1.773e-02,  1.802e-02,  2.105e-02,  1.907e-02,  2.042e-02,  1.540e-02,  1.996e-02,  1.942e-02,  2.308e-02,  6.250e-02,  1.404e-02,  1.413e-02,  1.885e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTWJetsToQQ_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8_hadd.root
{ 1.895e-01,  3.466e+00,  2.617e+00,  2.595e+00,  1.384e+00,  1.317e+00,  1.266e+00,  1.175e+00,  4.957e-01,  9.695e-01,  1.061e+00,  1.032e+00,  1.010e+00,  8.984e-01,  8.290e-01,  7.935e-01,  8.126e-01,  8.684e-01,  9.323e-01,  9.843e-01,  1.033e+00,  1.085e+00,  1.128e+00,  1.157e+00,  1.163e+00,  1.161e+00,  1.174e+00,  1.183e+00,  1.209e+00,  1.213e+00,  1.209e+00,  1.177e+00,  1.142e+00,  1.090e+00,  1.038e+00,  9.938e-01,  9.574e-01,  9.288e-01,  8.794e-01,  8.341e-01,  8.284e-01,  8.403e-01,  8.692e-01,  9.220e-01,  1.002e+00,  1.114e+00,  1.252e+00,  1.352e+00,  1.446e+00,  1.494e+00,  1.489e+00,  1.431e+00,  1.314e+00,  1.164e+00,  9.972e-01,  8.030e-01,  6.306e-01,  4.751e-01,  3.616e-01,  2.748e-01,  2.109e-01,  1.643e-01,  1.311e-01,  1.066e-01,  8.892e-02,  6.473e-02,  4.833e-02,  4.190e-02,  3.718e-02,  3.376e-02,  3.174e-02,  2.975e-02,  2.881e-02,  2.870e-02,  2.330e-02,  1.997e-02,  2.021e-02,  2.005e-02,  2.337e-02,  2.183e-02,  2.453e-02,  2.581e-02,  2.657e-02,  2.064e-02,  2.078e-02,  1.987e-02,  2.557e-02,  2.158e-02,  2.608e-02,  2.276e-02,  1.664e-02,  4.295e-02,  1.100e-02,  3.493e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT1000to1500_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.694e-01,  3.601e+00,  2.833e+00,  2.691e+00,  1.426e+00,  1.306e+00,  1.212e+00,  1.141e+00,  4.830e-01,  9.215e-01,  1.067e+00,  1.037e+00,  1.005e+00,  9.000e-01,  8.288e-01,  7.948e-01,  8.136e-01,  8.674e-01,  9.318e-01,  9.872e-01,  1.034e+00,  1.087e+00,  1.124e+00,  1.155e+00,  1.167e+00,  1.168e+00,  1.173e+00,  1.183e+00,  1.213e+00,  1.211e+00,  1.209e+00,  1.180e+00,  1.142e+00,  1.087e+00,  1.040e+00,  9.928e-01,  9.585e-01,  9.269e-01,  8.769e-01,  8.338e-01,  8.304e-01,  8.389e-01,  8.680e-01,  9.187e-01,  1.002e+00,  1.113e+00,  1.246e+00,  1.345e+00,  1.444e+00,  1.494e+00,  1.490e+00,  1.426e+00,  1.319e+00,  1.163e+00,  9.951e-01,  8.053e-01,  6.260e-01,  4.760e-01,  3.607e-01,  2.757e-01,  2.111e-01,  1.646e-01,  1.319e-01,  1.068e-01,  8.906e-02,  6.495e-02,  4.843e-02,  4.205e-02,  3.741e-02,  3.436e-02,  3.108e-02,  3.059e-02,  2.915e-02,  2.854e-02,  2.288e-02,  1.939e-02,  2.083e-02,  2.287e-02,  2.353e-02,  2.429e-02,  2.501e-02,  2.834e-02,  2.735e-02,  1.790e-02,  2.553e-02,  2.455e-02,  1.820e-02,  2.962e-02,  2.386e-02,  1.757e-02,  2.284e-02,  1.965e-02,  3.774e-02,  2.397e-02,  7.550e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT1500to2000_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.620e-01,  3.454e+00,  2.960e+00,  2.561e+00,  1.299e+00,  1.322e+00,  1.252e+00,  1.134e+00,  4.865e-01,  9.423e-01,  1.067e+00,  1.034e+00,  1.016e+00,  9.080e-01,  8.318e-01,  7.951e-01,  8.135e-01,  8.676e-01,  9.358e-01,  9.792e-01,  1.028e+00,  1.083e+00,  1.128e+00,  1.156e+00,  1.163e+00,  1.167e+00,  1.172e+00,  1.182e+00,  1.214e+00,  1.212e+00,  1.205e+00,  1.173e+00,  1.140e+00,  1.089e+00,  1.038e+00,  9.985e-01,  9.545e-01,  9.299e-01,  8.784e-01,  8.347e-01,  8.324e-01,  8.403e-01,  8.690e-01,  9.242e-01,  1.002e+00,  1.112e+00,  1.253e+00,  1.360e+00,  1.452e+00,  1.483e+00,  1.497e+00,  1.427e+00,  1.310e+00,  1.172e+00,  9.902e-01,  7.997e-01,  6.263e-01,  4.786e-01,  3.613e-01,  2.738e-01,  2.106e-01,  1.652e-01,  1.318e-01,  1.070e-01,  8.981e-02,  6.424e-02,  4.827e-02,  4.207e-02,  3.816e-02,  3.348e-02,  3.173e-02,  3.120e-02,  2.851e-02,  2.900e-02,  2.217e-02,  1.888e-02,  2.088e-02,  2.070e-02,  2.560e-02,  2.157e-02,  2.310e-02,  2.526e-02,  2.343e-02,  2.114e-02,  1.588e-02,  2.330e-02,  3.553e-02,  5.498e-02,  1.359e-02,  1.779e-02,  1.542e-02,  2.984e-02,  9.552e-03,  4.044e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT2000toInf_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.753e-01,  3.426e+00,  2.975e+00,  2.569e+00,  1.406e+00,  1.372e+00,  1.229e+00,  1.135e+00,  4.978e-01,  9.436e-01,  1.061e+00,  1.034e+00,  1.012e+00,  9.029e-01,  8.276e-01,  7.972e-01,  8.125e-01,  8.683e-01,  9.337e-01,  9.853e-01,  1.034e+00,  1.085e+00,  1.129e+00,  1.155e+00,  1.165e+00,  1.167e+00,  1.172e+00,  1.182e+00,  1.209e+00,  1.214e+00,  1.210e+00,  1.180e+00,  1.140e+00,  1.089e+00,  1.037e+00,  9.939e-01,  9.560e-01,  9.283e-01,  8.804e-01,  8.329e-01,  8.281e-01,  8.395e-01,  8.690e-01,  9.208e-01,  9.997e-01,  1.113e+00,  1.250e+00,  1.345e+00,  1.445e+00,  1.489e+00,  1.494e+00,  1.427e+00,  1.320e+00,  1.167e+00,  9.944e-01,  7.993e-01,  6.302e-01,  4.765e-01,  3.616e-01,  2.744e-01,  2.115e-01,  1.646e-01,  1.313e-01,  1.070e-01,  8.910e-02,  6.482e-02,  4.826e-02,  4.172e-02,  3.740e-02,  3.386e-02,  3.148e-02,  3.012e-02,  2.933e-02,  2.901e-02,  2.352e-02,  1.988e-02,  2.045e-02,  2.089e-02,  2.252e-02,  2.480e-02,  2.438e-02,  2.428e-02,  2.910e-02,  2.186e-02,  1.915e-02,  2.170e-02,  2.229e-02,  2.610e-02,  2.897e-02,  2.574e-02,  3.123e-02,  2.015e-02,  1.290e-02,  4.097e-02,  7.742e-02,  8.060e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT200to300_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.801e-01,  3.498e+00,  2.957e+00,  2.550e+00,  1.358e+00,  1.324e+00,  1.253e+00,  1.170e+00,  4.972e-01,  9.406e-01,  1.068e+00,  1.030e+00,  1.006e+00,  9.016e-01,  8.250e-01,  7.976e-01,  8.124e-01,  8.679e-01,  9.332e-01,  9.845e-01,  1.034e+00,  1.085e+00,  1.129e+00,  1.154e+00,  1.165e+00,  1.166e+00,  1.173e+00,  1.181e+00,  1.211e+00,  1.212e+00,  1.207e+00,  1.179e+00,  1.141e+00,  1.088e+00,  1.037e+00,  9.943e-01,  9.570e-01,  9.281e-01,  8.796e-01,  8.342e-01,  8.279e-01,  8.390e-01,  8.700e-01,  9.218e-01,  9.995e-01,  1.115e+00,  1.251e+00,  1.344e+00,  1.446e+00,  1.488e+00,  1.491e+00,  1.426e+00,  1.319e+00,  1.167e+00,  9.943e-01,  8.026e-01,  6.305e-01,  4.768e-01,  3.609e-01,  2.749e-01,  2.117e-01,  1.651e-01,  1.313e-01,  1.071e-01,  8.902e-02,  6.497e-02,  4.823e-02,  4.169e-02,  3.732e-02,  3.391e-02,  3.145e-02,  3.039e-02,  2.926e-02,  2.906e-02,  2.279e-02,  1.980e-02,  2.050e-02,  2.140e-02,  2.200e-02,  2.340e-02,  2.555e-02,  2.676e-02,  2.640e-02,  2.220e-02,  1.963e-02,  2.068e-02,  2.031e-02,  2.715e-02,  2.311e-02,  2.343e-02,  1.686e-02,  1.903e-02,  1.219e-02,  1.548e-02,  7.801e-02,  2.437e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT300to500_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.776e-01,  3.305e+00,  2.808e+00,  2.579e+00,  1.384e+00,  1.343e+00,  1.277e+00,  1.176e+00,  4.973e-01,  9.395e-01,  1.075e+00,  1.035e+00,  1.011e+00,  9.015e-01,  8.271e-01,  7.941e-01,  8.110e-01,  8.684e-01,  9.360e-01,  9.846e-01,  1.034e+00,  1.083e+00,  1.128e+00,  1.155e+00,  1.168e+00,  1.168e+00,  1.173e+00,  1.181e+00,  1.211e+00,  1.212e+00,  1.208e+00,  1.179e+00,  1.138e+00,  1.089e+00,  1.038e+00,  9.938e-01,  9.578e-01,  9.277e-01,  8.782e-01,  8.331e-01,  8.284e-01,  8.388e-01,  8.702e-01,  9.208e-01,  1.003e+00,  1.115e+00,  1.247e+00,  1.346e+00,  1.450e+00,  1.487e+00,  1.492e+00,  1.429e+00,  1.317e+00,  1.165e+00,  9.944e-01,  8.028e-01,  6.308e-01,  4.762e-01,  3.610e-01,  2.740e-01,  2.112e-01,  1.649e-01,  1.312e-01,  1.071e-01,  8.903e-02,  6.484e-02,  4.816e-02,  4.199e-02,  3.730e-02,  3.385e-02,  3.180e-02,  3.024e-02,  2.925e-02,  2.910e-02,  2.339e-02,  1.963e-02,  2.053e-02,  2.139e-02,  2.246e-02,  2.429e-02,  2.533e-02,  2.642e-02,  2.663e-02,  2.347e-02,  1.889e-02,  2.214e-02,  2.045e-02,  2.404e-02,  2.011e-02,  2.208e-02,  2.022e-02,  2.392e-02,  1.671e-02,  1.297e-02,  3.676e-02,  2.297e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT500to700_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.821e-01,  3.294e+00,  2.633e+00,  2.467e+00,  1.412e+00,  1.323e+00,  1.259e+00,  1.134e+00,  5.005e-01,  9.435e-01,  1.068e+00,  1.035e+00,  1.007e+00,  9.015e-01,  8.280e-01,  7.965e-01,  8.102e-01,  8.695e-01,  9.340e-01,  9.863e-01,  1.033e+00,  1.088e+00,  1.127e+00,  1.154e+00,  1.163e+00,  1.167e+00,  1.174e+00,  1.181e+00,  1.210e+00,  1.211e+00,  1.207e+00,  1.179e+00,  1.141e+00,  1.089e+00,  1.039e+00,  9.938e-01,  9.575e-01,  9.307e-01,  8.787e-01,  8.325e-01,  8.278e-01,  8.398e-01,  8.713e-01,  9.200e-01,  1.003e+00,  1.112e+00,  1.252e+00,  1.346e+00,  1.447e+00,  1.488e+00,  1.495e+00,  1.430e+00,  1.317e+00,  1.164e+00,  9.930e-01,  8.024e-01,  6.286e-01,  4.775e-01,  3.609e-01,  2.739e-01,  2.115e-01,  1.652e-01,  1.312e-01,  1.070e-01,  8.883e-02,  6.489e-02,  4.804e-02,  4.161e-02,  3.753e-02,  3.395e-02,  3.181e-02,  3.032e-02,  2.950e-02,  2.836e-02,  2.296e-02,  1.943e-02,  2.036e-02,  2.136e-02,  2.234e-02,  2.398e-02,  2.471e-02,  2.546e-02,  3.010e-02,  2.316e-02,  1.918e-02,  2.132e-02,  1.878e-02,  2.358e-02,  2.637e-02,  2.035e-02,  1.481e-02,  1.838e-02,  1.020e-02,  8.095e-03,  2.040e-02,  1.274e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // QCD_HT700to1000_TuneCP5_13TeV-madgraph-pythia8_hadd.root
{ 1.747e-01,  5.116e+00,  2.250e+00,  2.432e+00,  1.371e+00,  1.276e+00,  1.291e+00,  1.125e+00,  4.938e-01,  9.376e-01,  1.125e+00,  1.026e+00,  1.018e+00,  9.031e-01,  8.293e-01,  7.971e-01,  8.202e-01,  8.686e-01,  9.318e-01,  9.833e-01,  1.038e+00,  1.080e+00,  1.124e+00,  1.151e+00,  1.169e+00,  1.168e+00,  1.173e+00,  1.182e+00,  1.207e+00,  1.209e+00,  1.209e+00,  1.178e+00,  1.145e+00,  1.090e+00,  1.039e+00,  9.915e-01,  9.552e-01,  9.298e-01,  8.755e-01,  8.336e-01,  8.276e-01,  8.410e-01,  8.703e-01,  9.237e-01,  1.002e+00,  1.114e+00,  1.250e+00,  1.359e+00,  1.437e+00,  1.486e+00,  1.496e+00,  1.434e+00,  1.307e+00,  1.160e+00,  9.914e-01,  8.021e-01,  6.335e-01,  4.767e-01,  3.619e-01,  2.744e-01,  2.113e-01,  1.672e-01,  1.315e-01,  1.068e-01,  8.856e-02,  6.445e-02,  4.765e-02,  4.082e-02,  3.759e-02,  3.374e-02,  3.126e-02,  3.125e-02,  2.947e-02,  2.861e-02,  2.238e-02,  2.114e-02,  2.043e-02,  2.274e-02,  2.493e-02,  2.104e-02,  2.965e-02,  2.217e-02,  4.115e-02,  1.990e-02,  3.129e-02,  1.889e-02,  2.521e-02,  2.090e-02,  2.754e-02,  9.015e-03,  2.344e-02,  7.561e-03,  9.681e-03,  6.149e-03,  0.000e+00,  2.420e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_s-channel_antitop_leptonDecays_13TeV-PSweights_powheg-pythia_hadd.root
{ 1.692e-01,  3.305e+00,  2.908e+00,  2.416e+00,  1.376e+00,  1.380e+00,  1.277e+00,  1.153e+00,  4.885e-01,  9.458e-01,  1.069e+00,  1.023e+00,  1.001e+00,  8.954e-01,  8.278e-01,  7.969e-01,  8.144e-01,  8.628e-01,  9.383e-01,  9.874e-01,  1.031e+00,  1.084e+00,  1.129e+00,  1.157e+00,  1.165e+00,  1.163e+00,  1.173e+00,  1.184e+00,  1.206e+00,  1.212e+00,  1.208e+00,  1.180e+00,  1.142e+00,  1.096e+00,  1.039e+00,  9.952e-01,  9.573e-01,  9.305e-01,  8.773e-01,  8.353e-01,  8.265e-01,  8.427e-01,  8.691e-01,  9.161e-01,  9.991e-01,  1.116e+00,  1.254e+00,  1.339e+00,  1.439e+00,  1.489e+00,  1.498e+00,  1.431e+00,  1.307e+00,  1.175e+00,  9.960e-01,  7.987e-01,  6.254e-01,  4.765e-01,  3.605e-01,  2.725e-01,  2.112e-01,  1.643e-01,  1.306e-01,  1.080e-01,  8.918e-02,  6.487e-02,  4.847e-02,  4.210e-02,  3.763e-02,  3.371e-02,  3.232e-02,  3.054e-02,  3.004e-02,  2.928e-02,  2.277e-02,  1.991e-02,  2.188e-02,  2.073e-02,  2.005e-02,  2.262e-02,  2.783e-02,  2.757e-02,  3.204e-02,  2.871e-02,  2.268e-02,  2.101e-02,  1.840e-02,  2.789e-02,  2.144e-02,  1.685e-02,  5.475e-02,  1.766e-02,  2.261e-02,  7.181e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_s-channel_top_leptonDecays_13TeV-PSweights_powheg-pythia_hadd.root
{ 1.793e-01,  3.342e+00,  2.887e+00,  2.568e+00,  1.376e+00,  1.354e+00,  1.263e+00,  1.162e+00,  4.927e-01,  9.461e-01,  1.067e+00,  1.029e+00,  1.012e+00,  9.031e-01,  8.271e-01,  7.946e-01,  8.098e-01,  8.675e-01,  9.350e-01,  9.860e-01,  1.034e+00,  1.085e+00,  1.129e+00,  1.156e+00,  1.165e+00,  1.166e+00,  1.171e+00,  1.182e+00,  1.213e+00,  1.213e+00,  1.208e+00,  1.179e+00,  1.140e+00,  1.089e+00,  1.038e+00,  9.950e-01,  9.567e-01,  9.276e-01,  8.781e-01,  8.332e-01,  8.285e-01,  8.384e-01,  8.694e-01,  9.200e-01,  1.002e+00,  1.113e+00,  1.249e+00,  1.347e+00,  1.446e+00,  1.490e+00,  1.492e+00,  1.433e+00,  1.315e+00,  1.163e+00,  9.939e-01,  8.023e-01,  6.297e-01,  4.768e-01,  3.608e-01,  2.742e-01,  2.111e-01,  1.648e-01,  1.311e-01,  1.073e-01,  8.913e-02,  6.499e-02,  4.818e-02,  4.192e-02,  3.745e-02,  3.388e-02,  3.160e-02,  3.030e-02,  2.917e-02,  2.937e-02,  2.298e-02,  1.985e-02,  2.030e-02,  2.160e-02,  2.204e-02,  2.333e-02,  2.541e-02,  2.632e-02,  2.744e-02,  2.071e-02,  1.863e-02,  2.357e-02,  2.214e-02,  2.415e-02,  2.372e-02,  2.262e-02,  1.715e-02,  1.953e-02,  1.328e-02,  1.500e-02,  8.504e-02,  7.589e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.768e-01,  3.374e+00,  2.759e+00,  2.536e+00,  1.414e+00,  1.336e+00,  1.241e+00,  1.150e+00,  4.988e-01,  9.453e-01,  1.069e+00,  1.033e+00,  1.012e+00,  9.035e-01,  8.272e-01,  7.957e-01,  8.121e-01,  8.678e-01,  9.337e-01,  9.853e-01,  1.035e+00,  1.084e+00,  1.129e+00,  1.155e+00,  1.165e+00,  1.167e+00,  1.172e+00,  1.182e+00,  1.210e+00,  1.212e+00,  1.207e+00,  1.179e+00,  1.140e+00,  1.089e+00,  1.038e+00,  9.942e-01,  9.570e-01,  9.282e-01,  8.796e-01,  8.334e-01,  8.283e-01,  8.387e-01,  8.698e-01,  9.188e-01,  1.000e+00,  1.113e+00,  1.250e+00,  1.347e+00,  1.447e+00,  1.488e+00,  1.491e+00,  1.427e+00,  1.316e+00,  1.167e+00,  9.943e-01,  8.031e-01,  6.303e-01,  4.766e-01,  3.613e-01,  2.744e-01,  2.112e-01,  1.649e-01,  1.313e-01,  1.072e-01,  8.932e-02,  6.502e-02,  4.817e-02,  4.188e-02,  3.722e-02,  3.385e-02,  3.153e-02,  3.030e-02,  2.903e-02,  2.889e-02,  2.333e-02,  1.960e-02,  2.057e-02,  2.116e-02,  2.239e-02,  2.391e-02,  2.496e-02,  2.720e-02,  2.937e-02,  2.127e-02,  2.045e-02,  2.322e-02,  2.103e-02,  2.411e-02,  2.244e-02,  2.724e-02,  1.708e-02,  1.963e-02,  1.149e-02,  1.344e-02,  5.363e-02,  1.436e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_t-channel_top_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.863e-01,  3.330e+00,  2.696e+00,  2.415e+00,  1.451e+00,  1.388e+00,  1.284e+00,  1.138e+00,  4.841e-01,  9.371e-01,  1.072e+00,  1.033e+00,  1.005e+00,  9.067e-01,  8.271e-01,  7.960e-01,  8.104e-01,  8.670e-01,  9.379e-01,  9.847e-01,  1.035e+00,  1.085e+00,  1.124e+00,  1.155e+00,  1.167e+00,  1.166e+00,  1.172e+00,  1.183e+00,  1.207e+00,  1.215e+00,  1.210e+00,  1.176e+00,  1.141e+00,  1.090e+00,  1.037e+00,  9.956e-01,  9.558e-01,  9.287e-01,  8.795e-01,  8.329e-01,  8.316e-01,  8.399e-01,  8.692e-01,  9.222e-01,  9.963e-01,  1.117e+00,  1.245e+00,  1.348e+00,  1.442e+00,  1.486e+00,  1.481e+00,  1.433e+00,  1.311e+00,  1.164e+00,  9.976e-01,  8.064e-01,  6.285e-01,  4.764e-01,  3.595e-01,  2.744e-01,  2.117e-01,  1.654e-01,  1.318e-01,  1.077e-01,  8.857e-02,  6.503e-02,  4.831e-02,  4.194e-02,  3.723e-02,  3.371e-02,  3.148e-02,  2.951e-02,  2.909e-02,  2.997e-02,  2.322e-02,  2.036e-02,  2.035e-02,  2.213e-02,  2.127e-02,  2.380e-02,  2.593e-02,  2.784e-02,  2.922e-02,  2.653e-02,  2.037e-02,  2.049e-02,  1.930e-02,  3.627e-02,  2.390e-02,  1.565e-02,  1.525e-02,  3.937e-02,  8.401e-03,  1.601e-02,  0.000e+00,  3.150e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_tW_antitop_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.652e-01,  3.483e+00,  3.324e+00,  2.827e+00,  1.434e+00,  1.333e+00,  1.201e+00,  1.109e+00,  4.909e-01,  9.427e-01,  1.037e+00,  1.026e+00,  1.011e+00,  9.062e-01,  8.225e-01,  7.959e-01,  8.123e-01,  8.647e-01,  9.383e-01,  9.896e-01,  1.036e+00,  1.080e+00,  1.132e+00,  1.154e+00,  1.165e+00,  1.170e+00,  1.173e+00,  1.181e+00,  1.209e+00,  1.209e+00,  1.207e+00,  1.177e+00,  1.135e+00,  1.088e+00,  1.037e+00,  9.930e-01,  9.579e-01,  9.280e-01,  8.824e-01,  8.339e-01,  8.281e-01,  8.412e-01,  8.657e-01,  9.209e-01,  1.005e+00,  1.113e+00,  1.252e+00,  1.338e+00,  1.439e+00,  1.491e+00,  1.497e+00,  1.431e+00,  1.315e+00,  1.165e+00,  9.948e-01,  8.060e-01,  6.306e-01,  4.759e-01,  3.622e-01,  2.736e-01,  2.121e-01,  1.645e-01,  1.311e-01,  1.077e-01,  8.939e-02,  6.524e-02,  4.833e-02,  4.253e-02,  3.738e-02,  3.412e-02,  3.128e-02,  3.005e-02,  2.897e-02,  2.906e-02,  2.363e-02,  1.980e-02,  2.153e-02,  2.073e-02,  2.306e-02,  2.272e-02,  2.680e-02,  2.528e-02,  2.198e-02,  2.106e-02,  2.786e-02,  2.803e-02,  2.404e-02,  2.790e-02,  1.839e-02,  1.926e-02,  1.043e-02,  4.038e-02,  6.464e-03,  1.642e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ST_tW_top_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.732e-01,  3.382e+00,  2.800e+00,  2.572e+00,  1.412e+00,  1.370e+00,  1.250e+00,  1.138e+00,  4.943e-01,  9.468e-01,  1.058e+00,  1.037e+00,  1.010e+00,  9.067e-01,  8.265e-01,  7.962e-01,  8.128e-01,  8.662e-01,  9.331e-01,  9.862e-01,  1.034e+00,  1.085e+00,  1.129e+00,  1.154e+00,  1.163e+00,  1.167e+00,  1.173e+00,  1.182e+00,  1.210e+00,  1.211e+00,  1.208e+00,  1.180e+00,  1.140e+00,  1.090e+00,  1.037e+00,  9.944e-01,  9.566e-01,  9.294e-01,  8.790e-01,  8.327e-01,  8.300e-01,  8.386e-01,  8.692e-01,  9.203e-01,  1.001e+00,  1.115e+00,  1.252e+00,  1.346e+00,  1.449e+00,  1.487e+00,  1.492e+00,  1.431e+00,  1.313e+00,  1.166e+00,  9.950e-01,  8.037e-01,  6.292e-01,  4.769e-01,  3.609e-01,  2.740e-01,  2.114e-01,  1.645e-01,  1.313e-01,  1.073e-01,  8.885e-02,  6.479e-02,  4.809e-02,  4.190e-02,  3.751e-02,  3.403e-02,  3.162e-02,  3.050e-02,  2.852e-02,  2.884e-02,  2.286e-02,  1.974e-02,  2.052e-02,  2.072e-02,  2.179e-02,  2.309e-02,  2.443e-02,  2.746e-02,  2.608e-02,  2.111e-02,  1.880e-02,  2.162e-02,  1.992e-02,  2.312e-02,  2.246e-02,  2.095e-02,  2.017e-02,  2.067e-02,  1.500e-02,  1.587e-02,  4.500e-02,  1.874e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt0to700_hadd.root
{ 1.732e-01,  3.382e+00,  2.800e+00,  2.572e+00,  1.412e+00,  1.370e+00,  1.250e+00,  1.138e+00,  4.943e-01,  9.468e-01,  1.058e+00,  1.037e+00,  1.010e+00,  9.067e-01,  8.265e-01,  7.962e-01,  8.128e-01,  8.662e-01,  9.331e-01,  9.862e-01,  1.034e+00,  1.085e+00,  1.129e+00,  1.154e+00,  1.163e+00,  1.167e+00,  1.173e+00,  1.182e+00,  1.210e+00,  1.211e+00,  1.208e+00,  1.180e+00,  1.140e+00,  1.090e+00,  1.037e+00,  9.944e-01,  9.566e-01,  9.294e-01,  8.790e-01,  8.327e-01,  8.300e-01,  8.386e-01,  8.692e-01,  9.203e-01,  1.001e+00,  1.115e+00,  1.252e+00,  1.346e+00,  1.449e+00,  1.487e+00,  1.492e+00,  1.431e+00,  1.313e+00,  1.166e+00,  9.950e-01,  8.037e-01,  6.292e-01,  4.769e-01,  3.609e-01,  2.740e-01,  2.114e-01,  1.645e-01,  1.313e-01,  1.073e-01,  8.885e-02,  6.479e-02,  4.809e-02,  4.190e-02,  3.751e-02,  3.403e-02,  3.162e-02,  3.050e-02,  2.852e-02,  2.884e-02,  2.286e-02,  1.974e-02,  2.052e-02,  2.072e-02,  2.179e-02,  2.309e-02,  2.443e-02,  2.746e-02,  2.608e-02,  2.111e-02,  1.880e-02,  2.162e-02,  1.992e-02,  2.312e-02,  2.246e-02,  2.095e-02,  2.017e-02,  2.067e-02,  1.500e-02,  1.587e-02,  4.500e-02,  1.874e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt1000toInf_hadd.root
{ 1.732e-01,  3.382e+00,  2.800e+00,  2.572e+00,  1.412e+00,  1.370e+00,  1.250e+00,  1.138e+00,  4.943e-01,  9.468e-01,  1.058e+00,  1.037e+00,  1.010e+00,  9.067e-01,  8.265e-01,  7.962e-01,  8.128e-01,  8.662e-01,  9.331e-01,  9.862e-01,  1.034e+00,  1.085e+00,  1.129e+00,  1.154e+00,  1.163e+00,  1.167e+00,  1.173e+00,  1.182e+00,  1.210e+00,  1.211e+00,  1.208e+00,  1.180e+00,  1.140e+00,  1.090e+00,  1.037e+00,  9.944e-01,  9.566e-01,  9.294e-01,  8.790e-01,  8.327e-01,  8.300e-01,  8.386e-01,  8.692e-01,  9.203e-01,  1.001e+00,  1.115e+00,  1.252e+00,  1.346e+00,  1.449e+00,  1.487e+00,  1.492e+00,  1.431e+00,  1.313e+00,  1.166e+00,  9.950e-01,  8.037e-01,  6.292e-01,  4.769e-01,  3.609e-01,  2.740e-01,  2.114e-01,  1.645e-01,  1.313e-01,  1.073e-01,  8.885e-02,  6.479e-02,  4.809e-02,  4.190e-02,  3.751e-02,  3.403e-02,  3.162e-02,  3.050e-02,  2.852e-02,  2.884e-02,  2.286e-02,  1.974e-02,  2.052e-02,  2.072e-02,  2.179e-02,  2.309e-02,  2.443e-02,  2.746e-02,  2.608e-02,  2.111e-02,  1.880e-02,  2.162e-02,  1.992e-02,  2.312e-02,  2.246e-02,  2.095e-02,  2.017e-02,  2.067e-02,  1.500e-02,  1.587e-02,  4.500e-02,  1.874e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt700to1000_hadd.root
{ 1.807e-01,  3.168e+00,  2.756e+00,  2.543e+00,  1.386e+00,  1.339e+00,  1.237e+00,  1.164e+00,  4.953e-01,  9.393e-01,  1.058e+00,  1.032e+00,  1.011e+00,  9.039e-01,  8.250e-01,  7.967e-01,  8.116e-01,  8.675e-01,  9.321e-01,  9.850e-01,  1.034e+00,  1.085e+00,  1.129e+00,  1.155e+00,  1.165e+00,  1.167e+00,  1.172e+00,  1.182e+00,  1.210e+00,  1.212e+00,  1.208e+00,  1.178e+00,  1.141e+00,  1.089e+00,  1.037e+00,  9.935e-01,  9.572e-01,  9.299e-01,  8.797e-01,  8.326e-01,  8.294e-01,  8.401e-01,  8.690e-01,  9.194e-01,  1.000e+00,  1.113e+00,  1.248e+00,  1.345e+00,  1.448e+00,  1.488e+00,  1.491e+00,  1.429e+00,  1.317e+00,  1.166e+00,  9.943e-01,  8.027e-01,  6.299e-01,  4.765e-01,  3.607e-01,  2.747e-01,  2.115e-01,  1.653e-01,  1.315e-01,  1.071e-01,  8.912e-02,  6.485e-02,  4.825e-02,  4.198e-02,  3.732e-02,  3.408e-02,  3.150e-02,  3.018e-02,  2.900e-02,  2.900e-02,  2.320e-02,  1.981e-02,  2.041e-02,  2.069e-02,  2.262e-02,  2.314e-02,  2.483e-02,  2.689e-02,  2.782e-02,  2.188e-02,  2.021e-02,  2.247e-02,  2.089e-02,  2.391e-02,  2.318e-02,  2.428e-02,  2.230e-02,  2.545e-02,  1.367e-02,  1.416e-02,  5.651e-02,  2.118e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt0to700_hadd.root
{ 1.807e-01,  3.168e+00,  2.756e+00,  2.543e+00,  1.386e+00,  1.339e+00,  1.237e+00,  1.164e+00,  4.953e-01,  9.393e-01,  1.058e+00,  1.032e+00,  1.011e+00,  9.039e-01,  8.250e-01,  7.967e-01,  8.116e-01,  8.675e-01,  9.321e-01,  9.850e-01,  1.034e+00,  1.085e+00,  1.129e+00,  1.155e+00,  1.165e+00,  1.167e+00,  1.172e+00,  1.182e+00,  1.210e+00,  1.212e+00,  1.208e+00,  1.178e+00,  1.141e+00,  1.089e+00,  1.037e+00,  9.935e-01,  9.572e-01,  9.299e-01,  8.797e-01,  8.326e-01,  8.294e-01,  8.401e-01,  8.690e-01,  9.194e-01,  1.000e+00,  1.113e+00,  1.248e+00,  1.345e+00,  1.448e+00,  1.488e+00,  1.491e+00,  1.429e+00,  1.317e+00,  1.166e+00,  9.943e-01,  8.027e-01,  6.299e-01,  4.765e-01,  3.607e-01,  2.747e-01,  2.115e-01,  1.653e-01,  1.315e-01,  1.071e-01,  8.912e-02,  6.485e-02,  4.825e-02,  4.198e-02,  3.732e-02,  3.408e-02,  3.150e-02,  3.018e-02,  2.900e-02,  2.900e-02,  2.320e-02,  1.981e-02,  2.041e-02,  2.069e-02,  2.262e-02,  2.314e-02,  2.483e-02,  2.689e-02,  2.782e-02,  2.188e-02,  2.021e-02,  2.247e-02,  2.089e-02,  2.391e-02,  2.318e-02,  2.428e-02,  2.230e-02,  2.545e-02,  1.367e-02,  1.416e-02,  5.651e-02,  2.118e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt1000toInf_hadd.root
{ 1.807e-01,  3.168e+00,  2.756e+00,  2.543e+00,  1.386e+00,  1.339e+00,  1.237e+00,  1.164e+00,  4.953e-01,  9.393e-01,  1.058e+00,  1.032e+00,  1.011e+00,  9.039e-01,  8.250e-01,  7.967e-01,  8.116e-01,  8.675e-01,  9.321e-01,  9.850e-01,  1.034e+00,  1.085e+00,  1.129e+00,  1.155e+00,  1.165e+00,  1.167e+00,  1.172e+00,  1.182e+00,  1.210e+00,  1.212e+00,  1.208e+00,  1.178e+00,  1.141e+00,  1.089e+00,  1.037e+00,  9.935e-01,  9.572e-01,  9.299e-01,  8.797e-01,  8.326e-01,  8.294e-01,  8.401e-01,  8.690e-01,  9.194e-01,  1.000e+00,  1.113e+00,  1.248e+00,  1.345e+00,  1.448e+00,  1.488e+00,  1.491e+00,  1.429e+00,  1.317e+00,  1.166e+00,  9.943e-01,  8.027e-01,  6.299e-01,  4.765e-01,  3.607e-01,  2.747e-01,  2.115e-01,  1.653e-01,  1.315e-01,  1.071e-01,  8.912e-02,  6.485e-02,  4.825e-02,  4.198e-02,  3.732e-02,  3.408e-02,  3.150e-02,  3.018e-02,  2.900e-02,  2.900e-02,  2.320e-02,  1.981e-02,  2.041e-02,  2.069e-02,  2.262e-02,  2.314e-02,  2.483e-02,  2.689e-02,  2.782e-02,  2.188e-02,  2.021e-02,  2.247e-02,  2.089e-02,  2.391e-02,  2.318e-02,  2.428e-02,  2.230e-02,  2.545e-02,  1.367e-02,  1.416e-02,  5.651e-02,  2.118e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt700to1000_hadd.root
{ 1.746e-01,  3.296e+00,  2.853e+00,  2.574e+00,  1.415e+00,  1.347e+00,  1.237e+00,  1.140e+00,  4.936e-01,  9.416e-01,  1.064e+00,  1.032e+00,  1.013e+00,  9.043e-01,  8.262e-01,  7.965e-01,  8.115e-01,  8.675e-01,  9.341e-01,  9.858e-01,  1.034e+00,  1.084e+00,  1.128e+00,  1.155e+00,  1.165e+00,  1.168e+00,  1.172e+00,  1.182e+00,  1.210e+00,  1.212e+00,  1.208e+00,  1.179e+00,  1.141e+00,  1.088e+00,  1.038e+00,  9.934e-01,  9.568e-01,  9.283e-01,  8.787e-01,  8.337e-01,  8.280e-01,  8.396e-01,  8.677e-01,  9.198e-01,  1.002e+00,  1.114e+00,  1.250e+00,  1.347e+00,  1.447e+00,  1.487e+00,  1.490e+00,  1.429e+00,  1.315e+00,  1.165e+00,  9.943e-01,  8.030e-01,  6.307e-01,  4.768e-01,  3.609e-01,  2.749e-01,  2.111e-01,  1.654e-01,  1.313e-01,  1.072e-01,  8.910e-02,  6.473e-02,  4.815e-02,  4.188e-02,  3.750e-02,  3.410e-02,  3.162e-02,  3.010e-02,  2.932e-02,  2.885e-02,  2.302e-02,  1.947e-02,  2.012e-02,  2.037e-02,  2.268e-02,  2.336e-02,  2.491e-02,  2.738e-02,  2.810e-02,  2.222e-02,  1.998e-02,  2.289e-02,  1.966e-02,  2.641e-02,  2.789e-02,  2.666e-02,  2.113e-02,  3.105e-02,  1.154e-02,  1.337e-02,  3.579e-02,  2.981e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt0to700_hadd.root
{ 1.746e-01,  3.296e+00,  2.853e+00,  2.574e+00,  1.415e+00,  1.347e+00,  1.237e+00,  1.140e+00,  4.936e-01,  9.416e-01,  1.064e+00,  1.032e+00,  1.013e+00,  9.043e-01,  8.262e-01,  7.965e-01,  8.115e-01,  8.675e-01,  9.341e-01,  9.858e-01,  1.034e+00,  1.084e+00,  1.128e+00,  1.155e+00,  1.165e+00,  1.168e+00,  1.172e+00,  1.182e+00,  1.210e+00,  1.212e+00,  1.208e+00,  1.179e+00,  1.141e+00,  1.088e+00,  1.038e+00,  9.934e-01,  9.568e-01,  9.283e-01,  8.787e-01,  8.337e-01,  8.280e-01,  8.396e-01,  8.677e-01,  9.198e-01,  1.002e+00,  1.114e+00,  1.250e+00,  1.347e+00,  1.447e+00,  1.487e+00,  1.490e+00,  1.429e+00,  1.315e+00,  1.165e+00,  9.943e-01,  8.030e-01,  6.307e-01,  4.768e-01,  3.609e-01,  2.749e-01,  2.111e-01,  1.654e-01,  1.313e-01,  1.072e-01,  8.910e-02,  6.473e-02,  4.815e-02,  4.188e-02,  3.750e-02,  3.410e-02,  3.162e-02,  3.010e-02,  2.932e-02,  2.885e-02,  2.302e-02,  1.947e-02,  2.012e-02,  2.037e-02,  2.268e-02,  2.336e-02,  2.491e-02,  2.738e-02,  2.810e-02,  2.222e-02,  1.998e-02,  2.289e-02,  1.966e-02,  2.641e-02,  2.789e-02,  2.666e-02,  2.113e-02,  3.105e-02,  1.154e-02,  1.337e-02,  3.579e-02,  2.981e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt1000toInf_hadd.root
{ 1.746e-01,  3.296e+00,  2.853e+00,  2.574e+00,  1.415e+00,  1.347e+00,  1.237e+00,  1.140e+00,  4.936e-01,  9.416e-01,  1.064e+00,  1.032e+00,  1.013e+00,  9.043e-01,  8.262e-01,  7.965e-01,  8.115e-01,  8.675e-01,  9.341e-01,  9.858e-01,  1.034e+00,  1.084e+00,  1.128e+00,  1.155e+00,  1.165e+00,  1.168e+00,  1.172e+00,  1.182e+00,  1.210e+00,  1.212e+00,  1.208e+00,  1.179e+00,  1.141e+00,  1.088e+00,  1.038e+00,  9.934e-01,  9.568e-01,  9.283e-01,  8.787e-01,  8.337e-01,  8.280e-01,  8.396e-01,  8.677e-01,  9.198e-01,  1.002e+00,  1.114e+00,  1.250e+00,  1.347e+00,  1.447e+00,  1.487e+00,  1.490e+00,  1.429e+00,  1.315e+00,  1.165e+00,  9.943e-01,  8.030e-01,  6.307e-01,  4.768e-01,  3.609e-01,  2.749e-01,  2.111e-01,  1.654e-01,  1.313e-01,  1.072e-01,  8.910e-02,  6.473e-02,  4.815e-02,  4.188e-02,  3.750e-02,  3.410e-02,  3.162e-02,  3.010e-02,  2.932e-02,  2.885e-02,  2.302e-02,  1.947e-02,  2.012e-02,  2.037e-02,  2.268e-02,  2.336e-02,  2.491e-02,  2.738e-02,  2.810e-02,  2.222e-02,  1.998e-02,  2.289e-02,  1.966e-02,  2.641e-02,  2.789e-02,  2.666e-02,  2.113e-02,  3.105e-02,  1.154e-02,  1.337e-02,  3.579e-02,  2.981e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt700to1000_hadd.root
{ 1.764e-01,  3.343e+00,  2.907e+00,  2.593e+00,  1.387e+00,  1.387e+00,  1.243e+00,  1.167e+00,  4.958e-01,  9.450e-01,  1.076e+00,  1.023e+00,  1.009e+00,  8.965e-01,  8.279e-01,  7.963e-01,  8.119e-01,  8.686e-01,  9.327e-01,  9.853e-01,  1.034e+00,  1.085e+00,  1.129e+00,  1.155e+00,  1.165e+00,  1.167e+00,  1.173e+00,  1.182e+00,  1.211e+00,  1.213e+00,  1.207e+00,  1.177e+00,  1.140e+00,  1.089e+00,  1.039e+00,  9.957e-01,  9.571e-01,  9.293e-01,  8.788e-01,  8.329e-01,  8.285e-01,  8.398e-01,  8.693e-01,  9.198e-01,  9.996e-01,  1.113e+00,  1.248e+00,  1.348e+00,  1.440e+00,  1.487e+00,  1.491e+00,  1.431e+00,  1.318e+00,  1.168e+00,  9.946e-01,  8.010e-01,  6.293e-01,  4.743e-01,  3.618e-01,  2.748e-01,  2.120e-01,  1.649e-01,  1.316e-01,  1.071e-01,  8.910e-02,  6.461e-02,  4.816e-02,  4.180e-02,  3.743e-02,  3.395e-02,  3.174e-02,  3.019e-02,  2.930e-02,  2.883e-02,  2.282e-02,  1.996e-02,  2.087e-02,  2.159e-02,  2.267e-02,  2.499e-02,  2.620e-02,  2.566e-02,  2.890e-02,  2.285e-02,  1.982e-02,  2.484e-02,  2.486e-02,  2.092e-02,  2.473e-02,  2.041e-02,  2.773e-02,  1.640e-02,  2.100e-02,  2.668e-02,  1.260e-02,  1.575e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TT_Mtt-700to1000_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.736e-01,  3.135e+00,  2.930e+00,  2.512e+00,  1.363e+00,  1.367e+00,  1.213e+00,  1.147e+00,  4.922e-01,  9.412e-01,  1.072e+00,  1.024e+00,  1.017e+00,  9.025e-01,  8.247e-01,  8.002e-01,  8.078e-01,  8.674e-01,  9.366e-01,  9.843e-01,  1.034e+00,  1.085e+00,  1.128e+00,  1.155e+00,  1.165e+00,  1.166e+00,  1.172e+00,  1.182e+00,  1.210e+00,  1.211e+00,  1.210e+00,  1.177e+00,  1.141e+00,  1.090e+00,  1.036e+00,  9.946e-01,  9.565e-01,  9.296e-01,  8.813e-01,  8.333e-01,  8.285e-01,  8.399e-01,  8.689e-01,  9.175e-01,  1.004e+00,  1.112e+00,  1.249e+00,  1.348e+00,  1.446e+00,  1.486e+00,  1.494e+00,  1.426e+00,  1.311e+00,  1.167e+00,  9.922e-01,  8.003e-01,  6.293e-01,  4.781e-01,  3.604e-01,  2.755e-01,  2.109e-01,  1.647e-01,  1.314e-01,  1.069e-01,  8.935e-02,  6.519e-02,  4.826e-02,  4.222e-02,  3.740e-02,  3.401e-02,  3.150e-02,  2.977e-02,  2.941e-02,  2.876e-02,  2.285e-02,  2.009e-02,  2.004e-02,  2.239e-02,  2.247e-02,  2.279e-02,  2.486e-02,  2.621e-02,  2.968e-02,  1.837e-02,  1.934e-02,  2.620e-02,  2.164e-02,  2.870e-02,  2.837e-02,  2.889e-02,  1.408e-02,  1.090e-01,  9.973e-03,  1.478e-02,  0.000e+00,  8.724e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TT_Mtt-1000toInf_TuneCP5_PSweights_13TeV-powheg-pythia8_hadd.root
{ 1.849e-01,  2.951e+00,  2.732e+00,  2.349e+00,  1.347e+00,  1.574e+00,  1.266e+00,  1.143e+00,  5.225e-01,  9.525e-01,  1.058e+00,  1.031e+00,  9.952e-01,  9.102e-01,  8.238e-01,  7.977e-01,  8.181e-01,  8.702e-01,  9.308e-01,  9.879e-01,  1.037e+00,  1.091e+00,  1.128e+00,  1.163e+00,  1.166e+00,  1.172e+00,  1.169e+00,  1.184e+00,  1.204e+00,  1.214e+00,  1.210e+00,  1.182e+00,  1.138e+00,  1.085e+00,  1.038e+00,  9.941e-01,  9.584e-01,  9.318e-01,  8.736e-01,  8.283e-01,  8.283e-01,  8.403e-01,  8.651e-01,  9.219e-01,  1.009e+00,  1.112e+00,  1.247e+00,  1.346e+00,  1.441e+00,  1.482e+00,  1.469e+00,  1.421e+00,  1.309e+00,  1.159e+00,  9.946e-01,  8.058e-01,  6.278e-01,  4.761e-01,  3.601e-01,  2.725e-01,  2.111e-01,  1.675e-01,  1.314e-01,  1.080e-01,  8.931e-02,  6.485e-02,  4.803e-02,  4.320e-02,  3.768e-02,  3.384e-02,  3.083e-02,  3.044e-02,  2.916e-02,  2.786e-02,  2.436e-02,  1.962e-02,  2.313e-02,  2.133e-02,  2.435e-02,  2.462e-02,  3.200e-02,  2.372e-02,  2.961e-02,  1.901e-02,  1.612e-02,  2.579e-02,  2.485e-02,  1.648e-02,  2.444e-02,  1.600e-02,  8.319e-03,  0.000e+00,  1.718e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTZToLLNuNu_M-10_TuneCP5_PSweights_13TeV-amcatnlo-pythia8_hadd.root
{ 1.901e-01,  2.514e+00,  2.412e+00,  2.691e+00,  1.236e+00,  1.300e+00,  1.353e+00,  1.077e+00,  5.086e-01,  9.639e-01,  1.101e+00,  1.022e+00,  1.023e+00,  8.949e-01,  8.282e-01,  8.036e-01,  8.199e-01,  8.650e-01,  9.376e-01,  9.793e-01,  1.035e+00,  1.085e+00,  1.121e+00,  1.147e+00,  1.168e+00,  1.165e+00,  1.185e+00,  1.178e+00,  1.215e+00,  1.223e+00,  1.213e+00,  1.172e+00,  1.140e+00,  1.095e+00,  1.034e+00,  9.882e-01,  9.539e-01,  9.215e-01,  8.743e-01,  8.294e-01,  8.344e-01,  8.359e-01,  8.712e-01,  9.288e-01,  1.002e+00,  1.105e+00,  1.244e+00,  1.349e+00,  1.444e+00,  1.479e+00,  1.496e+00,  1.417e+00,  1.308e+00,  1.155e+00,  9.907e-01,  8.057e-01,  6.332e-01,  4.798e-01,  3.714e-01,  2.741e-01,  2.121e-01,  1.631e-01,  1.330e-01,  1.092e-01,  8.761e-02,  6.417e-02,  4.877e-02,  4.225e-02,  3.744e-02,  3.445e-02,  3.118e-02,  2.818e-02,  2.782e-02,  2.745e-02,  2.429e-02,  2.146e-02,  2.111e-02,  1.835e-02,  2.204e-02,  3.697e-02,  2.051e-02,  3.053e-02,  2.666e-02,  5.414e-02,  2.838e-02,  1.904e-02,  1.633e-02,  3.791e-02,  2.498e-02,  8.177e-03,  -2.126e-02,  0.000e+00,  0.000e+00,  2.789e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // TTWJetsToLNu_TuneCP5_PSweights_13TeV-amcatnloFXFX-madspin-pythia8_hadd.root
{ 1.757e-01,  4.202e+00,  2.724e+00,  2.663e+00,  1.325e+00,  1.292e+00,  1.198e+00,  1.139e+00,  4.962e-01,  9.436e-01,  1.059e+00,  1.033e+00,  1.014e+00,  9.063e-01,  8.277e-01,  7.931e-01,  8.135e-01,  8.669e-01,  9.307e-01,  9.881e-01,  1.035e+00,  1.082e+00,  1.132e+00,  1.153e+00,  1.163e+00,  1.166e+00,  1.171e+00,  1.182e+00,  1.210e+00,  1.211e+00,  1.210e+00,  1.178e+00,  1.141e+00,  1.091e+00,  1.036e+00,  9.937e-01,  9.554e-01,  9.298e-01,  8.810e-01,  8.343e-01,  8.271e-01,  8.393e-01,  8.732e-01,  9.213e-01,  1.000e+00,  1.113e+00,  1.251e+00,  1.353e+00,  1.440e+00,  1.488e+00,  1.498e+00,  1.425e+00,  1.318e+00,  1.160e+00,  9.935e-01,  8.006e-01,  6.306e-01,  4.774e-01,  3.614e-01,  2.747e-01,  2.121e-01,  1.650e-01,  1.306e-01,  1.072e-01,  8.853e-02,  6.520e-02,  4.792e-02,  4.159e-02,  3.668e-02,  3.406e-02,  3.156e-02,  2.979e-02,  3.037e-02,  3.065e-02,  2.332e-02,  1.944e-02,  2.117e-02,  2.131e-02,  2.186e-02,  2.747e-02,  2.788e-02,  3.053e-02,  2.214e-02,  2.092e-02,  1.967e-02,  2.005e-02,  2.573e-02,  2.218e-02,  2.436e-02,  1.063e-02,  2.073e-02,  4.012e-02,  6.422e-03,  1.632e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ttHTobb_M125_TuneCP5_13TeV-powheg-pythia8_hadd.root
{ 1.747e-01,  2.984e+00,  2.717e+00,  2.686e+00,  1.440e+00,  1.432e+00,  1.175e+00,  1.147e+00,  4.729e-01,  9.762e-01,  1.057e+00,  1.021e+00,  1.014e+00,  8.959e-01,  8.300e-01,  7.950e-01,  8.088e-01,  8.677e-01,  9.335e-01,  9.819e-01,  1.036e+00,  1.085e+00,  1.134e+00,  1.154e+00,  1.165e+00,  1.163e+00,  1.174e+00,  1.183e+00,  1.209e+00,  1.211e+00,  1.205e+00,  1.178e+00,  1.142e+00,  1.090e+00,  1.037e+00,  9.950e-01,  9.591e-01,  9.293e-01,  8.791e-01,  8.356e-01,  8.262e-01,  8.381e-01,  8.665e-01,  9.222e-01,  1.007e+00,  1.110e+00,  1.255e+00,  1.342e+00,  1.454e+00,  1.493e+00,  1.479e+00,  1.417e+00,  1.316e+00,  1.166e+00,  9.955e-01,  7.989e-01,  6.320e-01,  4.777e-01,  3.628e-01,  2.742e-01,  2.122e-01,  1.651e-01,  1.316e-01,  1.065e-01,  8.899e-02,  6.496e-02,  4.815e-02,  4.137e-02,  3.812e-02,  3.438e-02,  3.115e-02,  3.017e-02,  2.976e-02,  2.770e-02,  2.355e-02,  2.102e-02,  1.972e-02,  2.043e-02,  2.252e-02,  2.097e-02,  2.279e-02,  2.506e-02,  3.026e-02,  2.048e-02,  2.130e-02,  3.847e-02,  2.383e-02,  1.475e-02,  2.083e-02,  4.773e-02,  1.034e-02,  0.000e+00,  1.281e-02,  5.425e-03,  0.000e+00,  6.405e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8_hadd.root
{ 1.813e-01,  4.086e+00,  2.645e+00,  2.404e+00,  1.551e+00,  1.316e+00,  1.284e+00,  1.103e+00,  4.913e-01,  9.677e-01,  1.079e+00,  1.028e+00,  1.000e+00,  9.004e-01,  8.242e-01,  7.931e-01,  8.111e-01,  8.694e-01,  9.330e-01,  9.854e-01,  1.033e+00,  1.083e+00,  1.127e+00,  1.155e+00,  1.164e+00,  1.168e+00,  1.173e+00,  1.183e+00,  1.212e+00,  1.214e+00,  1.207e+00,  1.178e+00,  1.140e+00,  1.090e+00,  1.038e+00,  9.960e-01,  9.561e-01,  9.312e-01,  8.812e-01,  8.340e-01,  8.288e-01,  8.388e-01,  8.670e-01,  9.197e-01,  9.991e-01,  1.113e+00,  1.250e+00,  1.344e+00,  1.445e+00,  1.488e+00,  1.492e+00,  1.430e+00,  1.315e+00,  1.165e+00,  9.955e-01,  8.023e-01,  6.305e-01,  4.783e-01,  3.610e-01,  2.744e-01,  2.104e-01,  1.646e-01,  1.313e-01,  1.072e-01,  8.926e-02,  6.455e-02,  4.802e-02,  4.169e-02,  3.742e-02,  3.406e-02,  3.169e-02,  3.046e-02,  2.871e-02,  2.915e-02,  2.312e-02,  1.946e-02,  2.033e-02,  2.177e-02,  2.256e-02,  2.490e-02,  2.692e-02,  2.670e-02,  2.857e-02,  2.017e-02,  1.599e-02,  1.824e-02,  2.241e-02,  3.323e-02,  1.959e-02,  1.160e-02,  2.263e-02,  3.406e-02,  2.181e-02,  8.310e-03,  0.000e+00,  1.635e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.853e-01,  3.673e+00,  2.819e+00,  2.494e+00,  1.411e+00,  1.356e+00,  1.244e+00,  1.162e+00,  4.828e-01,  9.335e-01,  1.052e+00,  1.026e+00,  1.009e+00,  9.039e-01,  8.301e-01,  7.946e-01,  8.098e-01,  8.666e-01,  9.340e-01,  9.849e-01,  1.033e+00,  1.085e+00,  1.125e+00,  1.155e+00,  1.166e+00,  1.169e+00,  1.173e+00,  1.183e+00,  1.209e+00,  1.215e+00,  1.206e+00,  1.176e+00,  1.143e+00,  1.088e+00,  1.038e+00,  9.955e-01,  9.585e-01,  9.273e-01,  8.773e-01,  8.345e-01,  8.276e-01,  8.412e-01,  8.689e-01,  9.172e-01,  1.003e+00,  1.114e+00,  1.251e+00,  1.344e+00,  1.452e+00,  1.487e+00,  1.495e+00,  1.431e+00,  1.318e+00,  1.167e+00,  9.937e-01,  8.011e-01,  6.293e-01,  4.753e-01,  3.607e-01,  2.747e-01,  2.117e-01,  1.646e-01,  1.322e-01,  1.068e-01,  8.927e-02,  6.502e-02,  4.827e-02,  4.185e-02,  3.693e-02,  3.382e-02,  3.148e-02,  3.033e-02,  2.919e-02,  2.865e-02,  2.315e-02,  2.003e-02,  2.053e-02,  2.079e-02,  2.371e-02,  2.251e-02,  2.541e-02,  3.107e-02,  3.121e-02,  1.923e-02,  1.963e-02,  2.608e-02,  1.846e-02,  3.333e-02,  1.648e-02,  1.991e-02,  2.103e-02,  3.618e-02,  1.390e-02,  8.827e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.833e-01,  3.548e+00,  2.672e+00,  2.664e+00,  1.389e+00,  1.318e+00,  1.242e+00,  1.136e+00,  5.017e-01,  9.307e-01,  1.057e+00,  1.030e+00,  1.015e+00,  9.003e-01,  8.242e-01,  7.936e-01,  8.110e-01,  8.690e-01,  9.355e-01,  9.848e-01,  1.034e+00,  1.086e+00,  1.130e+00,  1.156e+00,  1.165e+00,  1.164e+00,  1.174e+00,  1.182e+00,  1.211e+00,  1.211e+00,  1.207e+00,  1.180e+00,  1.140e+00,  1.089e+00,  1.038e+00,  9.958e-01,  9.591e-01,  9.291e-01,  8.777e-01,  8.305e-01,  8.305e-01,  8.387e-01,  8.688e-01,  9.217e-01,  9.970e-01,  1.113e+00,  1.247e+00,  1.346e+00,  1.446e+00,  1.486e+00,  1.494e+00,  1.428e+00,  1.314e+00,  1.165e+00,  9.955e-01,  8.020e-01,  6.291e-01,  4.764e-01,  3.604e-01,  2.751e-01,  2.117e-01,  1.644e-01,  1.312e-01,  1.075e-01,  8.893e-02,  6.525e-02,  4.842e-02,  4.231e-02,  3.702e-02,  3.415e-02,  3.192e-02,  3.011e-02,  2.946e-02,  2.898e-02,  2.257e-02,  1.983e-02,  2.045e-02,  2.201e-02,  2.192e-02,  2.513e-02,  2.597e-02,  2.530e-02,  2.857e-02,  2.281e-02,  2.029e-02,  2.276e-02,  2.590e-02,  2.781e-02,  2.026e-02,  6.299e-02,  3.276e-02,  2.642e-02,  2.255e-02,  1.432e-02,  2.707e-02,  5.636e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.841e-01,  3.437e+00,  3.142e+00,  2.703e+00,  1.421e+00,  1.309e+00,  1.262e+00,  1.177e+00,  4.932e-01,  9.280e-01,  1.066e+00,  1.030e+00,  1.005e+00,  9.017e-01,  8.276e-01,  7.943e-01,  8.065e-01,  8.659e-01,  9.319e-01,  9.838e-01,  1.033e+00,  1.085e+00,  1.129e+00,  1.153e+00,  1.167e+00,  1.169e+00,  1.172e+00,  1.184e+00,  1.212e+00,  1.213e+00,  1.210e+00,  1.180e+00,  1.140e+00,  1.089e+00,  1.039e+00,  9.940e-01,  9.554e-01,  9.287e-01,  8.808e-01,  8.326e-01,  8.273e-01,  8.385e-01,  8.691e-01,  9.178e-01,  1.002e+00,  1.116e+00,  1.250e+00,  1.346e+00,  1.451e+00,  1.491e+00,  1.493e+00,  1.431e+00,  1.317e+00,  1.167e+00,  9.936e-01,  8.026e-01,  6.291e-01,  4.736e-01,  3.621e-01,  2.747e-01,  2.121e-01,  1.652e-01,  1.312e-01,  1.059e-01,  8.941e-02,  6.452e-02,  4.817e-02,  4.202e-02,  3.707e-02,  3.387e-02,  3.151e-02,  3.030e-02,  2.912e-02,  2.910e-02,  2.280e-02,  1.993e-02,  2.058e-02,  2.016e-02,  2.194e-02,  2.368e-02,  2.358e-02,  2.747e-02,  2.626e-02,  2.070e-02,  2.219e-02,  3.027e-02,  1.683e-02,  2.511e-02,  1.471e-02,  3.466e-02,  2.816e-02,  2.423e-02,  4.653e-02,  9.851e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.828e-01,  3.022e+00,  2.876e+00,  2.643e+00,  1.362e+00,  1.322e+00,  1.254e+00,  1.178e+00,  4.944e-01,  9.607e-01,  1.050e+00,  1.028e+00,  1.004e+00,  9.024e-01,  8.230e-01,  7.966e-01,  8.113e-01,  8.719e-01,  9.334e-01,  9.830e-01,  1.036e+00,  1.084e+00,  1.130e+00,  1.156e+00,  1.165e+00,  1.169e+00,  1.169e+00,  1.181e+00,  1.210e+00,  1.214e+00,  1.210e+00,  1.180e+00,  1.140e+00,  1.087e+00,  1.037e+00,  9.929e-01,  9.574e-01,  9.282e-01,  8.804e-01,  8.351e-01,  8.261e-01,  8.414e-01,  8.686e-01,  9.196e-01,  1.001e+00,  1.110e+00,  1.250e+00,  1.345e+00,  1.451e+00,  1.487e+00,  1.489e+00,  1.428e+00,  1.319e+00,  1.171e+00,  9.945e-01,  8.040e-01,  6.311e-01,  4.762e-01,  3.609e-01,  2.734e-01,  2.108e-01,  1.647e-01,  1.314e-01,  1.066e-01,  8.887e-02,  6.481e-02,  4.796e-02,  4.217e-02,  3.756e-02,  3.377e-02,  3.164e-02,  3.016e-02,  2.848e-02,  2.914e-02,  2.362e-02,  1.955e-02,  2.052e-02,  2.012e-02,  2.237e-02,  2.251e-02,  2.340e-02,  2.626e-02,  3.141e-02,  2.305e-02,  1.884e-02,  2.528e-02,  2.335e-02,  1.887e-02,  2.095e-02,  2.171e-02,  2.419e-02,  1.366e-02,  1.399e-02,  1.111e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.658e-01,  3.107e+00,  2.535e+00,  2.618e+00,  1.367e+00,  1.274e+00,  1.253e+00,  1.143e+00,  4.904e-01,  9.354e-01,  1.067e+00,  1.022e+00,  1.010e+00,  9.009e-01,  8.238e-01,  7.969e-01,  8.115e-01,  8.673e-01,  9.340e-01,  9.865e-01,  1.033e+00,  1.086e+00,  1.129e+00,  1.155e+00,  1.168e+00,  1.170e+00,  1.172e+00,  1.180e+00,  1.210e+00,  1.210e+00,  1.208e+00,  1.179e+00,  1.137e+00,  1.090e+00,  1.038e+00,  9.956e-01,  9.578e-01,  9.285e-01,  8.800e-01,  8.332e-01,  8.291e-01,  8.382e-01,  8.683e-01,  9.206e-01,  9.987e-01,  1.116e+00,  1.248e+00,  1.340e+00,  1.445e+00,  1.488e+00,  1.488e+00,  1.431e+00,  1.312e+00,  1.164e+00,  9.937e-01,  8.049e-01,  6.308e-01,  4.763e-01,  3.629e-01,  2.740e-01,  2.113e-01,  1.655e-01,  1.318e-01,  1.066e-01,  8.917e-02,  6.471e-02,  4.822e-02,  4.185e-02,  3.754e-02,  3.405e-02,  3.163e-02,  2.999e-02,  2.947e-02,  2.965e-02,  2.344e-02,  1.893e-02,  2.097e-02,  2.067e-02,  2.115e-02,  2.395e-02,  2.581e-02,  2.506e-02,  2.985e-02,  1.965e-02,  2.173e-02,  2.276e-02,  2.219e-02,  2.392e-02,  1.719e-02,  2.476e-02,  1.788e-02,  2.596e-02,  2.216e-02,  0.000e+00,  1.330e-02,  1.662e-02,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
{ 1.692e-01,  3.240e+00,  2.724e+00,  2.367e+00,  1.460e+00,  1.326e+00,  1.201e+00,  1.062e+00,  5.075e-01,  9.471e-01,  1.068e+00,  1.032e+00,  1.016e+00,  8.993e-01,  8.235e-01,  7.977e-01,  8.132e-01,  8.716e-01,  9.297e-01,  9.878e-01,  1.033e+00,  1.086e+00,  1.130e+00,  1.157e+00,  1.165e+00,  1.165e+00,  1.173e+00,  1.179e+00,  1.208e+00,  1.214e+00,  1.206e+00,  1.178e+00,  1.141e+00,  1.088e+00,  1.040e+00,  9.921e-01,  9.568e-01,  9.299e-01,  8.814e-01,  8.345e-01,  8.274e-01,  8.371e-01,  8.689e-01,  9.158e-01,  9.980e-01,  1.112e+00,  1.254e+00,  1.346e+00,  1.452e+00,  1.489e+00,  1.498e+00,  1.429e+00,  1.310e+00,  1.160e+00,  9.970e-01,  8.069e-01,  6.318e-01,  4.768e-01,  3.605e-01,  2.747e-01,  2.115e-01,  1.646e-01,  1.320e-01,  1.062e-01,  8.940e-02,  6.485e-02,  4.829e-02,  4.191e-02,  3.788e-02,  3.430e-02,  3.082e-02,  3.046e-02,  2.790e-02,  2.928e-02,  2.445e-02,  1.997e-02,  1.989e-02,  2.053e-02,  2.143e-02,  2.247e-02,  2.340e-02,  2.344e-02,  2.255e-02,  2.155e-02,  2.470e-02,  3.313e-02,  1.745e-02,  2.443e-02,  4.830e-02,  2.371e-02,  2.055e-02,  3.978e-02,  6.366e-03,  5.391e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // WW_TuneCP5_13TeV-pythia8_hadd.root
{ 2.795e-04,  8.136e-03,  3.035e-02,  6.774e-02,  7.990e-02,  1.602e-01,  1.867e-01,  2.041e-01,  8.812e-02,  2.672e-01,  3.006e-01,  4.491e-01,  5.373e-01,  5.869e-01,  5.671e-01,  5.694e-01,  6.374e-01,  7.804e-01,  8.728e-01,  9.482e-01,  1.056e+00,  1.113e+00,  1.168e+00,  1.208e+00,  1.239e+00,  1.243e+00,  1.236e+00,  1.275e+00,  1.322e+00,  1.332e+00,  1.290e+00,  1.272e+00,  1.237e+00,  1.194e+00,  1.153e+00,  1.105e+00,  1.052e+00,  1.012e+00,  9.507e-01,  9.288e-01,  8.900e-01,  8.994e-01,  9.471e-01,  1.026e+00,  1.113e+00,  1.214e+00,  1.369e+00,  1.486e+00,  1.571e+00,  1.648e+00,  1.606e+00,  1.552e+00,  1.427e+00,  1.202e+00,  1.048e+00,  8.340e-01,  6.822e-01,  5.145e-01,  3.913e-01,  2.978e-01,  2.172e-01,  1.709e-01,  1.292e-01,  1.026e-01,  9.116e-02,  6.964e-02,  4.636e-02,  4.335e-02,  3.016e-02,  3.406e-02,  1.873e-02,  1.873e-02,  1.578e-02,  3.180e-02,  1.304e-02,  4.507e-03,  3.148e-03,  2.089e-02,  1.124e-03,  8.538e-04,  1.786e-03,  3.853e-04,  5.193e-04,  1.189e-04,  1.973e-02,  1.610e-04,  1.256e-04,  2.115e-04,  1.502e-05,  8.038e-05,  2.004e-05,  1.677e-03,  4.294e-03,  4.091e-03,  1.718e-03,  8.029e-06,  3.324e-04,  1.224e-03,  2.661e-06,  3.164e-06,  0.000e+00,  }, // WZ_TuneCP5_13TeV-pythia8_hadd.root
{ 1.970e-01,  3.944e+00,  2.827e+00,  2.446e+00,  1.819e+00,  1.326e+00,  1.184e+00,  1.137e+00,  5.131e-01,  9.896e-01,  1.094e+00,  1.047e+00,  1.008e+00,  8.963e-01,  8.164e-01,  7.864e-01,  8.124e-01,  8.802e-01,  9.277e-01,  9.891e-01,  1.033e+00,  1.082e+00,  1.126e+00,  1.161e+00,  1.164e+00,  1.160e+00,  1.170e+00,  1.188e+00,  1.205e+00,  1.224e+00,  1.209e+00,  1.182e+00,  1.135e+00,  1.084e+00,  1.044e+00,  9.936e-01,  9.554e-01,  9.307e-01,  8.811e-01,  8.309e-01,  8.276e-01,  8.387e-01,  8.725e-01,  9.208e-01,  9.946e-01,  1.118e+00,  1.270e+00,  1.340e+00,  1.453e+00,  1.478e+00,  1.477e+00,  1.428e+00,  1.339e+00,  1.161e+00,  1.002e+00,  7.975e-01,  6.255e-01,  4.737e-01,  3.583e-01,  2.751e-01,  2.129e-01,  1.651e-01,  1.323e-01,  1.073e-01,  8.761e-02,  6.351e-02,  4.763e-02,  4.187e-02,  3.768e-02,  3.304e-02,  3.115e-02,  2.975e-02,  2.936e-02,  2.895e-02,  2.396e-02,  2.081e-02,  2.050e-02,  2.326e-02,  2.461e-02,  2.836e-02,  2.902e-02,  2.470e-02,  1.611e-02,  1.817e-02,  1.148e-02,  3.081e-02,  4.111e-02,  9.088e-03,  1.797e-02,  2.352e-02,  7.645e-03,  9.865e-03,  6.315e-03,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  0.000e+00,  }, // ZZ_TuneCP5_13TeV-pythia8_hadd.root
{ 1.905E-01,  6.168E+00,  2.959E+00,  2.680E+00,  1.278E+00,  1.633E+00,  1.244E+00,  1.154E+00,  4.675E-01,  9.112E-01,  1.138E+00,  1.013E+00,  9.944E-01,  8.785E-01,  8.314E-01,  8.021E-01,  8.246E-01,  8.658E-01,  9.342E-01,  9.803E-01,  1.028E+00,  1.084E+00,  1.127E+00,  1.155E+00,  1.188E+00,  1.173E+00,  1.162E+00,  1.193E+00,  1.213E+00,  1.208E+00,  1.194E+00,  1.171E+00,  1.143E+00,  1.087E+00,  1.042E+00,  9.919E-01,  9.575E-01,  9.291E-01,  8.913E-01,  8.241E-01,  8.246E-01,  8.462E-01,  8.712E-01,  9.161E-01,  9.942E-01,  1.109E+00,  1.252E+00,  1.336E+00,  1.445E+00,  1.485E+00,  1.498E+00,  1.413E+00,  1.315E+00,  1.168E+00,  9.977E-01,  8.038E-01,  6.304E-01,  4.752E-01,  3.559E-01,  2.706E-01,  2.163E-01,  1.644E-01,  1.300E-01,  1.054E-01,  8.871E-02,  6.396E-02,  4.783E-02,  4.147E-02,  3.854E-02,  3.570E-02,  3.131E-02,  3.076E-02,  3.254E-02,  2.867E-02,  2.226E-02,  2.142E-02,  1.838E-02,  1.844E-02,  2.328E-02,  2.571E-02,  }, // BB1000.root
{ 1.539E-01,  3.449E+00,  2.528E+00,  2.798E+00,  1.462E+00,  1.390E+00,  1.025E+00,  1.151E+00,  5.534E-01,  9.481E-01,  1.027E+00,  9.903E-01,  9.838E-01,  8.884E-01,  8.347E-01,  8.007E-01,  8.043E-01,  8.794E-01,  9.372E-01,  9.776E-01,  1.037E+00,  1.097E+00,  1.117E+00,  1.151E+00,  1.142E+00,  1.168E+00,  1.176E+00,  1.188E+00,  1.219E+00,  1.219E+00,  1.208E+00,  1.195E+00,  1.134E+00,  1.091E+00,  1.038E+00,  9.955E-01,  9.629E-01,  9.342E-01,  8.802E-01,  8.441E-01,  8.281E-01,  8.318E-01,  8.521E-01,  9.133E-01,  9.962E-01,  1.103E+00,  1.276E+00,  1.332E+00,  1.421E+00,  1.490E+00,  1.477E+00,  1.419E+00,  1.315E+00,  1.168E+00,  9.878E-01,  7.997E-01,  6.277E-01,  4.724E-01,  3.626E-01,  2.720E-01,  2.142E-01,  1.639E-01,  1.303E-01,  1.056E-01,  9.100E-02,  6.627E-02,  4.632E-02,  4.386E-02,  3.666E-02,  3.218E-02,  3.200E-02,  2.769E-02,  3.394E-02,  3.060E-02,  2.677E-02,  2.049E-02,  2.069E-02,  2.303E-02,  2.732E-02,  2.796E-02,  }, // BB1100.root
{ 1.532E-01,  3.549E+00,  3.902E+00,  2.181E+00,  1.655E+00,  1.618E+00,  1.104E+00,  1.209E+00,  5.136E-01,  9.095E-01,  1.108E+00,  1.015E+00,  1.017E+00,  9.178E-01,  8.249E-01,  7.925E-01,  8.079E-01,  8.634E-01,  9.341E-01,  9.977E-01,  1.022E+00,  1.081E+00,  1.126E+00,  1.161E+00,  1.169E+00,  1.149E+00,  1.173E+00,  1.189E+00,  1.211E+00,  1.217E+00,  1.209E+00,  1.176E+00,  1.138E+00,  1.094E+00,  1.038E+00,  9.957E-01,  9.542E-01,  9.299E-01,  8.784E-01,  8.335E-01,  8.187E-01,  8.392E-01,  8.649E-01,  9.217E-01,  1.034E+00,  1.128E+00,  1.256E+00,  1.361E+00,  1.441E+00,  1.501E+00,  1.476E+00,  1.425E+00,  1.326E+00,  1.163E+00,  9.862E-01,  7.968E-01,  6.205E-01,  4.769E-01,  3.569E-01,  2.683E-01,  2.099E-01,  1.638E-01,  1.265E-01,  1.097E-01,  9.029E-02,  6.441E-02,  4.844E-02,  4.154E-02,  3.812E-02,  3.519E-02,  3.164E-02,  3.134E-02,  2.974E-02,  3.224E-02,  2.422E-02,  2.003E-02,  1.863E-02,  2.532E-02,  1.898E-02,  2.158E-02,  }, // BB1200.root
{ 1.706E-01,  3.825E+00,  2.990E+00,  2.298E+00,  1.359E+00,  1.492E+00,  1.376E+00,  1.110E+00,  5.073E-01,  9.364E-01,  1.039E+00,  1.017E+00,  1.043E+00,  8.819E-01,  8.181E-01,  7.975E-01,  8.188E-01,  8.599E-01,  9.235E-01,  9.803E-01,  1.045E+00,  1.089E+00,  1.127E+00,  1.144E+00,  1.167E+00,  1.164E+00,  1.168E+00,  1.184E+00,  1.213E+00,  1.206E+00,  1.211E+00,  1.181E+00,  1.138E+00,  1.087E+00,  1.046E+00,  1.004E+00,  9.528E-01,  9.463E-01,  8.710E-01,  8.275E-01,  8.192E-01,  8.343E-01,  8.786E-01,  9.239E-01,  1.005E+00,  1.119E+00,  1.268E+00,  1.356E+00,  1.427E+00,  1.487E+00,  1.504E+00,  1.453E+00,  1.327E+00,  1.166E+00,  9.739E-01,  7.966E-01,  6.327E-01,  4.726E-01,  3.597E-01,  2.715E-01,  2.073E-01,  1.631E-01,  1.321E-01,  1.062E-01,  8.826E-02,  6.222E-02,  4.622E-02,  4.232E-02,  3.749E-02,  3.478E-02,  3.202E-02,  3.323E-02,  3.469E-02,  2.580E-02,  2.393E-02,  2.223E-02,  2.317E-02,  2.183E-02,  2.618E-02,  3.721E-02,  }, // BB1300.root
{ 1.876E-01,  1.752E+00,  2.465E+00,  2.706E+00,  1.584E+00,  1.367E+00,  1.277E+00,  1.215E+00,  4.667E-01,  1.034E+00,  9.756E-01,  1.089E+00,  1.005E+00,  8.809E-01,  8.474E-01,  7.764E-01,  8.249E-01,  8.866E-01,  9.360E-01,  1.004E+00,  1.034E+00,  1.092E+00,  1.131E+00,  1.151E+00,  1.174E+00,  1.173E+00,  1.172E+00,  1.180E+00,  1.217E+00,  1.208E+00,  1.216E+00,  1.182E+00,  1.135E+00,  1.089E+00,  1.041E+00,  9.914E-01,  9.560E-01,  9.252E-01,  8.801E-01,  8.387E-01,  8.260E-01,  8.329E-01,  8.655E-01,  9.194E-01,  1.000E+00,  1.105E+00,  1.237E+00,  1.349E+00,  1.403E+00,  1.489E+00,  1.506E+00,  1.438E+00,  1.312E+00,  1.152E+00,  9.788E-01,  8.096E-01,  6.276E-01,  4.668E-01,  3.586E-01,  2.668E-01,  2.097E-01,  1.643E-01,  1.318E-01,  1.054E-01,  8.818E-02,  6.571E-02,  4.812E-02,  4.365E-02,  3.799E-02,  3.361E-02,  3.190E-02,  2.780E-02,  2.522E-02,  3.122E-02,  2.127E-02,  2.200E-02,  1.704E-02,  2.095E-02,  2.498E-02,  2.153E-02,  }, // BB1400.root
{ 2.510E-01,  1.219E+01,  3.575E+00,  6.181E+00,  1.338E+00,  1.304E+00,  1.352E+00,  1.197E+00,  4.804E-01,  1.084E+00,  1.062E+00,  1.003E+00,  1.009E+00,  8.886E-01,  8.266E-01,  8.019E-01,  8.155E-01,  8.726E-01,  9.115E-01,  9.930E-01,  1.042E+00,  1.075E+00,  1.130E+00,  1.155E+00,  1.192E+00,  1.145E+00,  1.178E+00,  1.196E+00,  1.193E+00,  1.212E+00,  1.227E+00,  1.190E+00,  1.122E+00,  1.092E+00,  1.037E+00,  1.002E+00,  9.637E-01,  9.335E-01,  8.729E-01,  8.348E-01,  8.155E-01,  8.303E-01,  8.541E-01,  9.026E-01,  9.895E-01,  1.139E+00,  1.256E+00,  1.379E+00,  1.445E+00,  1.493E+00,  1.510E+00,  1.433E+00,  1.310E+00,  1.159E+00,  9.929E-01,  8.132E-01,  6.239E-01,  4.707E-01,  3.654E-01,  2.750E-01,  2.116E-01,  1.697E-01,  1.273E-01,  1.040E-01,  8.600E-02,  6.267E-02,  4.656E-02,  4.187E-02,  3.762E-02,  3.413E-02,  2.960E-02,  2.812E-02,  2.765E-02,  3.383E-02,  2.666E-02,  2.031E-02,  2.503E-02,  2.126E-02,  1.799E-02,  1.977E-02,  }, // BB1500.root
{ 2.615E-01,  6.351E+00,  2.234E+00,  2.576E+00,  1.393E+00,  1.177E+00,  1.174E+00,  1.073E+00,  4.746E-01,  1.005E+00,  1.051E+00,  1.017E+00,  9.814E-01,  9.487E-01,  8.122E-01,  7.996E-01,  8.152E-01,  8.601E-01,  9.359E-01,  9.829E-01,  1.030E+00,  1.088E+00,  1.146E+00,  1.156E+00,  1.162E+00,  1.159E+00,  1.177E+00,  1.200E+00,  1.205E+00,  1.208E+00,  1.203E+00,  1.174E+00,  1.132E+00,  1.075E+00,  1.039E+00,  9.997E-01,  9.720E-01,  9.350E-01,  8.739E-01,  8.270E-01,  8.153E-01,  8.519E-01,  8.646E-01,  9.143E-01,  9.931E-01,  1.110E+00,  1.248E+00,  1.325E+00,  1.439E+00,  1.484E+00,  1.477E+00,  1.451E+00,  1.317E+00,  1.177E+00,  9.840E-01,  8.094E-01,  6.284E-01,  4.837E-01,  3.663E-01,  2.749E-01,  2.108E-01,  1.655E-01,  1.305E-01,  1.059E-01,  8.620E-02,  6.441E-02,  4.872E-02,  4.292E-02,  3.746E-02,  3.515E-02,  3.077E-02,  2.837E-02,  2.952E-02,  2.915E-02,  2.286E-02,  1.866E-02,  2.059E-02,  1.661E-02,  2.470E-02,  2.181E-02,  }, // BB1600.root
{ 3.142E-01,  0.000E+00,  2.655E+00,  3.895E+00,  1.407E+00,  1.068E+00,  1.378E+00,  1.053E+00,  4.804E-01,  8.873E-01,  1.095E+00,  9.420E-01,  1.011E+00,  8.877E-01,  8.528E-01,  7.755E-01,  7.899E-01,  8.752E-01,  9.578E-01,  9.909E-01,  1.036E+00,  1.055E+00,  1.142E+00,  1.166E+00,  1.138E+00,  1.178E+00,  1.191E+00,  1.202E+00,  1.221E+00,  1.192E+00,  1.214E+00,  1.161E+00,  1.148E+00,  1.097E+00,  1.040E+00,  9.880E-01,  9.470E-01,  8.985E-01,  8.849E-01,  8.469E-01,  8.296E-01,  8.398E-01,  8.647E-01,  9.163E-01,  1.021E+00,  1.131E+00,  1.230E+00,  1.341E+00,  1.443E+00,  1.524E+00,  1.491E+00,  1.423E+00,  1.334E+00,  1.183E+00,  9.651E-01,  7.950E-01,  6.265E-01,  4.849E-01,  3.590E-01,  2.773E-01,  2.127E-01,  1.583E-01,  1.291E-01,  1.041E-01,  9.042E-02,  6.315E-02,  4.917E-02,  4.294E-02,  3.518E-02,  3.340E-02,  3.392E-02,  2.643E-02,  3.016E-02,  3.192E-02,  2.498E-02,  1.874E-02,  1.992E-02,  2.368E-02,  2.824E-02,  2.803E-02,  }, // BB1800.root
{ 1.816E-01,  3.665E+00,  2.149E+00,  2.252E+00,  1.367E+00,  1.290E+00,  1.325E+00,  9.709E-01,  4.515E-01,  8.712E-01,  1.073E+00,  1.052E+00,  1.017E+00,  9.196E-01,  8.591E-01,  7.895E-01,  8.197E-01,  8.676E-01,  9.293E-01,  9.786E-01,  1.033E+00,  1.079E+00,  1.128E+00,  1.151E+00,  1.172E+00,  1.174E+00,  1.181E+00,  1.177E+00,  1.206E+00,  1.224E+00,  1.202E+00,  1.167E+00,  1.148E+00,  1.093E+00,  1.045E+00,  9.968E-01,  9.462E-01,  9.207E-01,  8.796E-01,  8.340E-01,  8.173E-01,  8.414E-01,  8.778E-01,  9.285E-01,  9.967E-01,  1.107E+00,  1.239E+00,  1.340E+00,  1.455E+00,  1.512E+00,  1.488E+00,  1.436E+00,  1.339E+00,  1.158E+00,  1.003E+00,  7.870E-01,  6.327E-01,  4.756E-01,  3.580E-01,  2.702E-01,  2.072E-01,  1.661E-01,  1.305E-01,  1.070E-01,  9.020E-02,  6.394E-02,  4.857E-02,  4.074E-02,  3.761E-02,  3.408E-02,  3.169E-02,  3.134E-02,  2.761E-02,  2.577E-02,  2.036E-02,  2.069E-02,  1.801E-02,  1.743E-02,  1.668E-02,  2.325E-02,  }, // TpTp1000.root
{ 2.243E-01,  2.654E+00,  2.334E+00,  2.392E+00,  1.563E+00,  1.265E+00,  1.451E+00,  1.096E+00,  5.347E-01,  9.591E-01,  1.045E+00,  1.109E+00,  1.013E+00,  8.996E-01,  8.355E-01,  7.965E-01,  8.081E-01,  8.730E-01,  9.315E-01,  9.924E-01,  1.035E+00,  1.083E+00,  1.129E+00,  1.161E+00,  1.178E+00,  1.173E+00,  1.172E+00,  1.175E+00,  1.208E+00,  1.225E+00,  1.189E+00,  1.159E+00,  1.150E+00,  1.086E+00,  1.032E+00,  9.957E-01,  9.539E-01,  9.352E-01,  8.767E-01,  8.315E-01,  8.334E-01,  8.330E-01,  8.566E-01,  9.186E-01,  1.009E+00,  1.129E+00,  1.250E+00,  1.342E+00,  1.442E+00,  1.523E+00,  1.497E+00,  1.447E+00,  1.308E+00,  1.166E+00,  1.005E+00,  8.039E-01,  6.337E-01,  4.779E-01,  3.574E-01,  2.721E-01,  2.053E-01,  1.638E-01,  1.285E-01,  1.022E-01,  8.569E-02,  6.474E-02,  4.848E-02,  4.168E-02,  3.661E-02,  3.625E-02,  3.308E-02,  3.115E-02,  3.082E-02,  2.730E-02,  2.590E-02,  1.859E-02,  1.772E-02,  2.499E-02,  2.129E-02,  2.020E-02,  }, // TpTp1100.root
{ 2.106E-01,  1.924E+00,  2.030E+00,  2.340E+00,  1.468E+00,  1.719E+00,  1.496E+00,  1.179E+00,  4.445E-01,  9.348E-01,  1.063E+00,  9.988E-01,  1.034E+00,  9.068E-01,  8.234E-01,  7.943E-01,  8.123E-01,  8.627E-01,  9.299E-01,  9.686E-01,  1.033E+00,  1.086E+00,  1.129E+00,  1.173E+00,  1.162E+00,  1.153E+00,  1.167E+00,  1.179E+00,  1.222E+00,  1.205E+00,  1.211E+00,  1.187E+00,  1.142E+00,  1.088E+00,  1.048E+00,  9.889E-01,  9.426E-01,  9.226E-01,  8.844E-01,  8.355E-01,  8.402E-01,  8.427E-01,  8.674E-01,  9.280E-01,  9.988E-01,  1.122E+00,  1.247E+00,  1.363E+00,  1.474E+00,  1.488E+00,  1.495E+00,  1.404E+00,  1.306E+00,  1.150E+00,  9.705E-01,  8.050E-01,  6.325E-01,  4.759E-01,  3.613E-01,  2.751E-01,  2.073E-01,  1.669E-01,  1.305E-01,  1.068E-01,  8.796E-02,  6.574E-02,  4.827E-02,  4.084E-02,  3.620E-02,  3.406E-02,  3.191E-02,  2.864E-02,  3.068E-02,  3.145E-02,  2.347E-02,  2.252E-02,  1.975E-02,  2.174E-02,  2.962E-02,  1.943E-02,  }, // TpTp1200.root
{ 1.523E-01,  2.439E+00,  2.502E+00,  2.307E+00,  1.273E+00,  1.217E+00,  1.221E+00,  1.036E+00,  5.165E-01,  9.453E-01,  1.020E+00,  1.020E+00,  1.034E+00,  8.935E-01,  8.389E-01,  7.957E-01,  7.980E-01,  8.616E-01,  9.450E-01,  9.884E-01,  1.030E+00,  1.111E+00,  1.121E+00,  1.159E+00,  1.161E+00,  1.182E+00,  1.176E+00,  1.191E+00,  1.205E+00,  1.213E+00,  1.212E+00,  1.173E+00,  1.139E+00,  1.081E+00,  1.049E+00,  1.002E+00,  9.466E-01,  9.299E-01,  8.915E-01,  8.328E-01,  8.282E-01,  8.458E-01,  8.701E-01,  9.194E-01,  1.001E+00,  1.098E+00,  1.236E+00,  1.329E+00,  1.438E+00,  1.497E+00,  1.479E+00,  1.391E+00,  1.335E+00,  1.180E+00,  9.951E-01,  8.059E-01,  6.225E-01,  4.756E-01,  3.683E-01,  2.694E-01,  2.087E-01,  1.588E-01,  1.266E-01,  1.059E-01,  8.720E-02,  6.254E-02,  4.819E-02,  4.152E-02,  3.708E-02,  3.168E-02,  3.157E-02,  3.276E-02,  2.723E-02,  2.672E-02,  2.156E-02,  1.943E-02,  2.719E-02,  2.280E-02,  1.922E-02,  2.076E-02,  }, // TpTp1300.root
{ 2.093E-01,  1.955E+00,  9.168E+00,  2.349E+00,  1.495E+00,  1.338E+00,  1.040E+00,  1.076E+00,  5.682E-01,  9.235E-01,  1.119E+00,  1.003E+00,  1.045E+00,  8.971E-01,  8.249E-01,  8.091E-01,  7.984E-01,  8.729E-01,  9.288E-01,  9.994E-01,  1.038E+00,  1.087E+00,  1.132E+00,  1.166E+00,  1.178E+00,  1.182E+00,  1.163E+00,  1.195E+00,  1.202E+00,  1.208E+00,  1.220E+00,  1.187E+00,  1.152E+00,  1.080E+00,  1.037E+00,  9.869E-01,  9.585E-01,  9.223E-01,  8.825E-01,  8.320E-01,  8.173E-01,  8.356E-01,  8.663E-01,  9.292E-01,  1.004E+00,  1.112E+00,  1.242E+00,  1.344E+00,  1.459E+00,  1.481E+00,  1.505E+00,  1.409E+00,  1.316E+00,  1.161E+00,  9.854E-01,  7.999E-01,  6.339E-01,  4.678E-01,  3.645E-01,  2.658E-01,  2.058E-01,  1.624E-01,  1.277E-01,  1.065E-01,  8.755E-02,  6.555E-02,  4.663E-02,  4.267E-02,  3.623E-02,  3.201E-02,  3.363E-02,  3.025E-02,  2.602E-02,  2.460E-02,  2.271E-02,  1.765E-02,  1.926E-02,  1.963E-02,  2.908E-02,  2.852E-02,  }, // TpTp1400.root
{ 2.348E-01,  3.728E+00,  2.018E+00,  2.879E+00,  1.011E+00,  1.316E+00,  1.225E+00,  1.119E+00,  4.709E-01,  9.432E-01,  1.017E+00,  1.036E+00,  1.003E+00,  9.033E-01,  8.257E-01,  7.965E-01,  8.014E-01,  8.643E-01,  9.231E-01,  1.000E+00,  1.032E+00,  1.086E+00,  1.121E+00,  1.169E+00,  1.175E+00,  1.165E+00,  1.154E+00,  1.179E+00,  1.209E+00,  1.229E+00,  1.190E+00,  1.188E+00,  1.138E+00,  1.094E+00,  1.025E+00,  1.004E+00,  9.594E-01,  9.370E-01,  8.798E-01,  8.409E-01,  8.275E-01,  8.399E-01,  8.757E-01,  9.169E-01,  1.002E+00,  1.106E+00,  1.243E+00,  1.351E+00,  1.429E+00,  1.490E+00,  1.527E+00,  1.421E+00,  1.328E+00,  1.172E+00,  9.914E-01,  8.037E-01,  6.246E-01,  4.722E-01,  3.603E-01,  2.705E-01,  2.087E-01,  1.632E-01,  1.306E-01,  1.068E-01,  8.774E-02,  6.288E-02,  5.001E-02,  3.944E-02,  3.977E-02,  3.202E-02,  3.029E-02,  3.043E-02,  2.748E-02,  3.054E-02,  2.120E-02,  1.604E-02,  1.744E-02,  2.340E-02,  1.724E-02,  2.176E-02,  }, // TpTp1500.root
{ 1.566E-01,  3.511E+00,  2.246E+00,  2.278E+00,  1.343E+00,  1.220E+00,  1.354E+00,  1.078E+00,  5.560E-01,  9.739E-01,  1.183E+00,  1.105E+00,  1.039E+00,  9.057E-01,  8.551E-01,  8.030E-01,  8.216E-01,  8.706E-01,  9.400E-01,  1.002E+00,  1.009E+00,  1.082E+00,  1.130E+00,  1.141E+00,  1.179E+00,  1.159E+00,  1.173E+00,  1.163E+00,  1.202E+00,  1.222E+00,  1.204E+00,  1.175E+00,  1.151E+00,  1.090E+00,  1.046E+00,  9.802E-01,  9.660E-01,  9.283E-01,  8.798E-01,  8.405E-01,  8.230E-01,  8.446E-01,  8.623E-01,  9.343E-01,  1.023E+00,  1.109E+00,  1.236E+00,  1.340E+00,  1.473E+00,  1.473E+00,  1.511E+00,  1.400E+00,  1.284E+00,  1.170E+00,  9.897E-01,  7.999E-01,  6.240E-01,  4.698E-01,  3.540E-01,  2.763E-01,  2.057E-01,  1.656E-01,  1.322E-01,  1.063E-01,  8.714E-02,  6.585E-02,  5.075E-02,  4.058E-02,  3.795E-02,  3.435E-02,  2.940E-02,  2.899E-02,  2.980E-02,  3.485E-02,  3.006E-02,  1.845E-02,  1.880E-02,  1.763E-02,  1.669E-02,  2.562E-02,  }, // TpTp1600.root
{ 2.977E-01,  1.748E+00,  2.152E+00,  2.481E+00,  1.233E+00,  1.015E+00,  1.100E+00,  1.601E+00,  4.386E-01,  8.484E-01,  1.044E+00,  1.032E+00,  1.031E+00,  9.199E-01,  8.199E-01,  7.843E-01,  8.351E-01,  8.682E-01,  9.269E-01,  1.003E+00,  1.020E+00,  1.085E+00,  1.131E+00,  1.173E+00,  1.179E+00,  1.160E+00,  1.164E+00,  1.166E+00,  1.216E+00,  1.210E+00,  1.214E+00,  1.196E+00,  1.127E+00,  1.083E+00,  1.039E+00,  9.867E-01,  9.439E-01,  9.491E-01,  8.902E-01,  8.389E-01,  8.354E-01,  8.628E-01,  8.554E-01,  9.302E-01,  9.948E-01,  1.102E+00,  1.248E+00,  1.323E+00,  1.461E+00,  1.465E+00,  1.484E+00,  1.402E+00,  1.283E+00,  1.188E+00,  9.855E-01,  7.939E-01,  6.287E-01,  4.759E-01,  3.535E-01,  2.707E-01,  2.070E-01,  1.640E-01,  1.338E-01,  1.046E-01,  8.914E-02,  6.711E-02,  4.797E-02,  3.984E-02,  3.990E-02,  3.717E-02,  3.072E-02,  2.785E-02,  2.549E-02,  2.456E-02,  2.090E-02,  2.571E-02,  2.173E-02,  1.707E-02,  2.907E-02,  1.623E-02,  }, // TpTp1700.root
{ 1.526E-01,  2.053E+00,  4.513E+00,  4.162E+00,  1.914E+00,  9.058E-01,  1.366E+00,  9.259E-01,  4.488E-01,  1.056E+00,  9.620E-01,  1.049E+00,  1.023E+00,  9.690E-01,  8.464E-01,  7.974E-01,  8.210E-01,  8.648E-01,  9.480E-01,  9.687E-01,  1.034E+00,  1.082E+00,  1.133E+00,  1.170E+00,  1.155E+00,  1.179E+00,  1.178E+00,  1.167E+00,  1.235E+00,  1.222E+00,  1.232E+00,  1.168E+00,  1.129E+00,  1.092E+00,  1.031E+00,  1.004E+00,  9.656E-01,  9.236E-01,  8.838E-01,  8.166E-01,  8.390E-01,  8.349E-01,  8.558E-01,  9.112E-01,  9.572E-01,  1.142E+00,  1.256E+00,  1.355E+00,  1.436E+00,  1.481E+00,  1.435E+00,  1.386E+00,  1.288E+00,  1.170E+00,  1.011E+00,  7.926E-01,  6.417E-01,  4.737E-01,  3.663E-01,  2.657E-01,  2.120E-01,  1.623E-01,  1.323E-01,  1.065E-01,  9.456E-02,  6.326E-02,  4.770E-02,  4.204E-02,  3.611E-02,  3.331E-02,  3.037E-02,  2.568E-02,  4.057E-02,  3.642E-02,  2.675E-02,  1.710E-02,  2.370E-02,  2.301E-02,  3.136E-02,  1.498E-02,  }, // TpTp1800.root
};
}

#endif // #ifdef step1_cxx
