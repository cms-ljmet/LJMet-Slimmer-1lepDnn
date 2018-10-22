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
   
   // Fixed size dimensions of array or collections stored in the TTree if any.

   // NEW BRANCHES
   vector<int>    theJetAK8Truth_JetSubCalc_PtOrdered;
   vector<double> deltaR_leptonicparticle_AK8_PtOrdered; 
   vector<int>    taggedXXXX_BEST;
   vector<int>    taggedXXXX_DeepAK8;
   vector<int>    taggedXXXX_DeepAK8_decorr;
   vector<int>    leptonicTprimeJetIDs_BEST;
   vector<int>    leptonicTprimeJetIDs_DeepAK8;
   vector<int>    leptonicTprimeJetIDs_DeepAK8_decorr;
   vector<int>    hadronicTprimeJetIDs_BEST;
   vector<int>    hadronicTprimeJetIDs_DeepAK8;
   vector<int>    hadronicTprimeJetIDs_DeepAK8_decorr;

   vector<double> dnn_B_DeepAK8Calc_PtOrdered;
   vector<double> dnn_T_DeepAK8Calc_PtOrdered;
   vector<double> dnn_H_DeepAK8Calc_PtOrdered;
   vector<double> dnn_W_DeepAK8Calc_PtOrdered;
   vector<double> dnn_Z_DeepAK8Calc_PtOrdered;
   vector<double> dnn_J_DeepAK8Calc_PtOrdered;

   vector<double> dnn_QCD_BestCalc_PtOrdered;
   vector<double> dnn_Top_BestCalc_PtOrdered;
   vector<double> dnn_Higgs_BestCalc_PtOrdered;
   vector<double> dnn_W_BestCalc_PtOrdered;
   vector<double> dnn_Z_BestCalc_PtOrdered;
   vector<double> dnn_B_BestCalc_PtOrdered;

   vector<double> decorr_B_DeepAK8Calc_PtOrdered;
   vector<double> decorr_T_DeepAK8Calc_PtOrdered;
   vector<double> decorr_H_DeepAK8Calc_PtOrdered;
   vector<double> decorr_W_DeepAK8Calc_PtOrdered;
   vector<double> decorr_Z_DeepAK8Calc_PtOrdered;
   vector<double> decorr_J_DeepAK8Calc_PtOrdered;
   
   double Tprime1_BEST_Mass;
   double Tprime2_BEST_Mass;
   double Tprime1_BEST_Pt;
   double Tprime2_BEST_Pt;
   double Tprime1_BEST_Eta;
   double Tprime2_BEST_Eta;
   double Tprime1_BEST_Phi;
   double Tprime2_BEST_Phi;
   double Tprime1_BEST_deltaR;
   double Tprime2_BEST_deltaR;
   double TprimeAvg_BEST_Mass;

   double Tprime1_DeepAK8_Mass;
   double Tprime2_DeepAK8_Mass;
   double Tprime1_DeepAK8_Pt;
   double Tprime2_DeepAK8_Pt;
   double Tprime1_DeepAK8_Eta;
   double Tprime2_DeepAK8_Eta;
   double Tprime1_DeepAK8_Phi;
   double Tprime2_DeepAK8_Phi;
   double Tprime1_DeepAK8_deltaR;
   double Tprime2_DeepAK8_deltaR;
   double TprimeAvg_DeepAK8_Mass;

   double Tprime1_DeepAK8_decorr_Mass;
   double Tprime2_DeepAK8_decorr_Mass;
   double Tprime1_DeepAK8_decorr_Pt;
   double Tprime2_DeepAK8_decorr_Pt;
   double Tprime1_DeepAK8_decorr_Eta;
   double Tprime2_DeepAK8_decorr_Eta;
   double Tprime1_DeepAK8_decorr_Phi;
   double Tprime2_DeepAK8_decorr_Phi;
   double Tprime1_DeepAK8_decorr_deltaR;
   double Tprime2_DeepAK8_decorr_deltaR;
   double TprimeAvg_DeepAK8_decorr_Mass;

   bool validDecay_BEST;
   bool validDecay_DeepAK8;
   bool validDecay_DeepAK8_decorr;

   bool isLeptonic_t;
   bool isLeptonic_W;

   bool taggedBWBW_BEST;
   bool taggedTHBW_BEST;
   bool taggedTHTH_BEST;
   bool taggedTZBW_BEST;
   bool taggedTZTH_BEST;
   bool taggedTZTZ_BEST;
   bool taggedBWBW_DeepAK8;
   bool taggedTHBW_DeepAK8;
   bool taggedTHTH_DeepAK8;
   bool taggedTZBW_DeepAK8;
   bool taggedTZTH_DeepAK8;
   bool taggedTZTZ_DeepAK8;
   bool taggedBWBW_DeepAK8_decorr;
   bool taggedTHBW_DeepAK8_decorr;
   bool taggedTHTH_DeepAK8_decorr;
   bool taggedTZBW_DeepAK8_decorr;
   bool taggedTZTH_DeepAK8_decorr;
   bool taggedTZTZ_DeepAK8_decorr;

   double highPtAK8Jet1_SoftDropCorrectedMass;
   double highPtAK8Jet2_SoftDropCorrectedMass;
   double highPtAK8Jet3_SoftDropCorrectedMass;

   double W_mass;
   double t_mass;

   double probSum_BEST_decay;
   double probSum_DeepAK8_decay;
   double probSum_DeepAK8_decorr_decay;
   double probSum_BEST_all;
   double probSum_DeepAK8_all;
   double probSum_DeepAK8_decorr_all;
   double probSum_BEST_four;
   double probSum_DeepAK8_four;
   double probSum_DeepAK8_decorr_four;

   Int_t nB_BEST;
   Int_t nH_BEST;
   Int_t nJ_BEST;
   Int_t nT_BEST;
   Int_t nW_BEST;
   Int_t nZ_BEST;

   Int_t nB_DeepAK8;
   Int_t nH_DeepAK8;
   Int_t nJ_DeepAK8;
   Int_t nT_DeepAK8;
   Int_t nW_DeepAK8;
   Int_t nZ_DeepAK8;

   Int_t nB_DeepAK8_decorr;
   Int_t nH_DeepAK8_decorr;
   Int_t nJ_DeepAK8_decorr;
   Int_t nT_DeepAK8_decorr;
   Int_t nW_DeepAK8_decorr;
   Int_t nZ_DeepAK8_decorr;

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
   vector<double>  theJetCSV_JetSubCalc_PtOrdered;
   vector<int>     theJetHFlav_JetSubCalc_PtOrdered;
   vector<int>     theJetBTag_JetSubCalc_PtOrdered;
   vector<int>     theJetBTag_bSFup_JetSubCalc_PtOrdered;
   vector<int>     theJetBTag_bSFdn_JetSubCalc_PtOrdered;
   vector<int>     theJetBTag_lSFup_JetSubCalc_PtOrdered;
   vector<int>     theJetBTag_lSFdn_JetSubCalc_PtOrdered;

   Float_t         AK4HTpMETpLepPt;
   Float_t         AK4HT;

   Float_t         minMleppJet;
   Float_t         deltaRlepJetInMinMljet;
   Float_t         deltaPhilepJetInMinMljet;
   Float_t         minDR_lepJet;
   Float_t         ptRel_lepJet;
   Float_t         MT_lepMet;
   vector<double>  deltaR_lepJets;
   vector<double>  deltaPhi_lepJets;
   vector<double>  mass_lepJets;

   Float_t         BJetLeadPt;
   Float_t         minMleppBjetPt;
   Float_t         minMleppBjet;
   Float_t         deltaRlepbJetInMinMlb;
   Float_t         deltaPhilepbJetInMinMlb;
   vector<double>  BJetLeadPt_shifts;
   vector<double>  minMleppBjetPt_shifts;
   vector<double>  minMleppBjet_shifts;
   vector<double>  deltaRlepbJetInMinMlb_shifts;
   vector<double>  deltaPhilepbJetInMinMlb_shifts;
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
   /*
   vector<double>("elIsTightBarrel_singleLepCalc",1);
   vector<double>("elIsMediumBarrel_singleLepCalc",1);
   vector<double>("elIsLooseBarrel_singleLepCalc",1);
   vector<double>("elIsVetoBarrel_singleLepCalc",1);
   vector<double>("elIsTIghtEndCap_singleLepCalc",1);
   vector<double>("elIsMediumEndCap_singleLepCalc",1);
   vector<double>("elIsLooseEndCap_singleLepCalc",1);
   vector<double>("elIsVetoEndCap_singleLepCalc",1);

   vector<double>("muIsTight_singleLepCalc",1);
   vector<double>("muIsMedium_singleLepCalc",1);
   vector<double>("muIsMediumPrompt_singleLepCalc",1);
   vector<double>("muIsLoose_singleLepCalc",1);

   vector<double>("dnn_QCD_BestCalc",1);
   vector<double>("dnn_Top_BestCalc",1);
   vector<double>("dnn_Higgs_BestCalc",1);
   vector<double>("dnn_Z_BestCalc",1);
   vector<double>("dnn_W_BestCalc",1);*/
   //vector<int> dnn_largest_BestCalc;

   /*   vector<double>("dnn_B_DeepAK8Calc",1);
   vector<double>("dnn_J_DeepAK8Calc",1);
   vector<double>("dnn_W_DeepAK8Calc",1);
   vector<double>("dnn_Z_DeepAK8Calc",1);
   vector<double>("dnn_H_DeepAK8Calc",1);*/
   //   vector<int>dnn_largest_DeepAK8Calc;
   //vector<int>decorr_largest_DeepAK8Calc;/*
   /*vector<double>("dnn_T_DeepAK8Calc",1);
   vector<double>("decorr_B_DeepAK8Calc",1);
   vector<double>("decorr_J_DeepAK8Calc",1);
   vector<double>("decorr_W_DeepAK8Calc",1);
   vector<double>("decorr_Z_DeepAK8Calc",1);
   vector<double>("decorr_H_DeepAK8Calc",1);
   vector<double>("decorr_T_DeepAK8Calc",1);*/

   //vector<double>*AK8JetDeepCSVb_singleLepCalc;
   //vector<double>*AK8JetDeepCSVbb_singleLepCalc;
   //vector<double>("AK8JetDeepCSVc_singleLepCalc",1);
   //vector<double>("AK8JetDeepCSVudsg_singleLepCalc",1);

   Int_t           NJetsWtagged_0p6;
   Int_t           NPuppiWtagged_0p55;
   Int_t           NJetsWtagged_0p6_notTtagged;
   Float_t         WJetLeadPt;
   Float_t         deltaRtopWjet;
   Float_t         deltaPhitopWjet;
   Float_t         deltaRlepWjet;
   Float_t         deltaPhilepWjet;
   vector<int>     NJetsWtagged_0p6_shifts;
   vector<int>     NPuppiWtagged_0p55_shifts;
   vector<int>     NJetsWtagged_0p6_notTtagged_shifts;
   vector<double>  WJetLeadPt_shifts;
   vector<double>  deltaRtopWjet_shifts;  
   vector<double>  deltaPhitopWjet_shifts; 
   vector<double>  deltaRlepWjet_shifts;  
   vector<double>  deltaPhilepWjet_shifts; 

   Int_t           NJetsTtagged_0p81;
   Float_t         TJetLeadPt;
   Float_t         deltaRlepTjet;
   Float_t         deltaPhilepTjet;
   vector<int>     NJetsTtagged_0p81_shifts;
   vector<double>  TJetLeadPt_shifts;
   vector<double>  deltaRlepTjet_shifts;  
   vector<double>  deltaPhilepTjet_shifts; 

   Int_t           NJetsH1btagged;
   vector<int>     NJetsH1btagged_shifts;
   Int_t           NJetsH2btagged;
   vector<int>     NJetsH2btagged_shifts;
   Int_t           NPuppiH1btagged;
   vector<int>     NPuppiH1btagged_shifts;
   Int_t           NPuppiH2btagged;
   vector<int>     NPuppiH2btagged_shifts;

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
   Int_t           NBsFromTTbar_TTbarMassCalc;
   Int_t           NCharm_TTbarMassCalc;
   Int_t           NExtraBs_TTbarMassCalc;
   Int_t           NExtraCs_TTbarMassCalc;
   Int_t           NExtraLs_TTbarMassCalc;
   Int_t           NLeptonDecays_TpTpCalc;
   Int_t           NLight_TTbarMassCalc;
   Int_t           NPartonsfromHEPUEP_singleLepCalc;
   Int_t           NTotalBs_TTbarMassCalc;
   Int_t           NWdecaysFromTTbar_TTbarMassCalc;
   Int_t           dataE_singleLepCalc;
   Int_t           dataM_singleLepCalc;
   Int_t           genTDLID_singleLepCalc;
   Int_t           isTT_TTbarMassCalc;
   Int_t           isTTbb_TTbarMassCalc;
   Int_t           isTTbj_TTbarMassCalc;
   Int_t           isTTcc_TTbarMassCalc;
   Int_t           isTTcj_TTbarMassCalc;
   Int_t           isTTlf_TTbarMassCalc;
   Int_t           isTTll_TTbarMassCalc;
   Int_t           lumi_CommonCalc;
   Int_t           nAllJets_CommonCalc;
   Int_t           nLooseMuons_CommonCalc;
   Int_t           nPV_singleLepCalc;
   Int_t           nPileupInteractions_singleLepCalc;
   Int_t           nSelBtagJets_CommonCalc;
   Int_t           nSelElectrons_CommonCalc;
   Int_t           nSelJets_CommonCalc;
   Int_t           nTightMuons_CommonCalc;
   Int_t           nTrueInteractions_singleLepCalc;
   Int_t           run_CommonCalc;
   Long64_t        event_CommonCalc;
   Double_t        AK4HT_jerdn_singleLepCalc;
   Double_t        AK4HT_jerup_singleLepCalc;
   Double_t        AK4HT_jesdn_singleLepCalc;
   Double_t        AK4HT_jesup_singleLepCalc;
   Double_t        AK4HT_singleLepCalc;
   Double_t        HTfromHEPUEP_singleLepCalc;
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
   Double_t        corr_metnohf_phi_singleLepCalc;
   Double_t        corr_metnohf_singleLepCalc;
   Double_t        genTDLEnergy_singleLepCalc;
   Double_t        genTDLEta_singleLepCalc;
   Double_t        genTDLPhi_singleLepCalc;
   Double_t        genTDLPt_singleLepCalc;
   Double_t        met_phi_singleLepCalc;
   Double_t        met_singleLepCalc;
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
   vector<int>     *maxProb_JetSubCalc;
   vector<int>     *dnn_largest_BestCalc;
   vector<int>     *dnn_largest_DeepAK8Calc;
   vector<int>     *decorr_largest_DeepAK8Calc;
   vector<int>     *elChargeConsistent_singleLepCalc;
   vector<int>     *elCharge_singleLepCalc;
   vector<int>     *elCtfCharge_singleLepCalc;
   vector<int>     *elGsfCharge_singleLepCalc;
   vector<int>     *elIsEBEE_singleLepCalc;
   vector<int>     *elIsMVALooseIso_singleLepCalc;
   vector<int>     *elIsMVALoose_singleLepCalc;
   vector<int>     *elIsMVATightIso_singleLepCalc;
   vector<int>     *elIsMVATight_singleLepCalc;
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
   vector<int>     *theJetAK8SDSubjetHFlav_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetIndex_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetNDeepCSVL_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetNDeepCSVM_bSFdn_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetNDeepCSVM_bSFup_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetNDeepCSVM_lSFdn_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetNDeepCSVM_lSFup_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetSize_JetSubCalc;
   vector<int>     *theJetAK8SJIndex_JetSubCalc;
   vector<int>     *theJetAK8SJSize_JetSubCalc;
   vector<int>     *theJetAK8nDaughters_JetSubCalc;
   vector<int>     *theJetBTag_JetSubCalc;
   vector<int>     *theJetBTag_bSFdn_JetSubCalc;
   vector<int>     *theJetBTag_bSFup_JetSubCalc;
   vector<int>     *theJetBTag_lSFdn_JetSubCalc;
   vector<int>     *theJetBTag_lSFup_JetSubCalc;
   vector<int>     *theJetHFlav_JetSubCalc;
   vector<int>     *theJetPFlav_JetSubCalc;
   vector<int>     theJetPFlav_JetSubCalc_PtOrdered;
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
   vector<double>  *AK4JetEnergy_jerdn_singleLepCalc;
   vector<double>  *AK4JetEnergy_jerup_singleLepCalc;
   vector<double>  *AK4JetEnergy_jesdn_singleLepCalc;
   vector<double>  *AK4JetEnergy_jesup_singleLepCalc;
   vector<double>  *AK4JetEnergy_singleLepCalc;
   vector<double>  *AK4JetEta_singleLepCalc;
   vector<double>  *AK4JetPhi_singleLepCalc;
   vector<double>  *AK4JetPt_jerdn_singleLepCalc;
   vector<double>  *AK4JetPt_jerup_singleLepCalc;
   vector<double>  *AK4JetPt_jesdn_singleLepCalc;
   vector<double>  *AK4JetPt_jesup_singleLepCalc;
   vector<double>  *AK4JetPt_singleLepCalc;
   vector<double>  *AK8JetCSV_BestCalc;
   vector<double>  *AK8JetCSV_singleLepCalc;
   vector<double>  *AK8JetEnergy_BestCalc;
   vector<double>  *AK8JetEnergy_jerdn_BestCalc;
   vector<double>  *AK8JetEnergy_jerdn_singleLepCalc;
   vector<double>  *AK8JetEnergy_jerup_BestCalc;
   vector<double>  *AK8JetEnergy_jerup_singleLepCalc;
   vector<double>  *AK8JetEnergy_jesdn_BestCalc;
   vector<double>  *AK8JetEnergy_jesdn_singleLepCalc;
   vector<double>  *AK8JetEnergy_jesup_BestCalc;
   vector<double>  *AK8JetEnergy_jesup_singleLepCalc;
   vector<double>  *AK8JetEnergy_singleLepCalc;
   vector<double>  *AK8JetEta_BestCalc;
   vector<double>  *AK8JetEta_singleLepCalc;
   vector<double>  *AK8JetPhi_BestCalc;
   vector<double>  *AK8JetPhi_singleLepCalc;
   vector<double>  *AK8JetPt_BestCalc;
   vector<double>  *AK8JetPt_jerdn_BestCalc;
   vector<double>  *AK8JetPt_jerdn_singleLepCalc;
   vector<double>  *AK8JetPt_jerup_BestCalc;
   vector<double>  *AK8JetPt_jerup_singleLepCalc;
   vector<double>  *AK8JetPt_jesdn_BestCalc;
   vector<double>  *AK8JetPt_jesdn_singleLepCalc;
   vector<double>  *AK8JetPt_jesup_BestCalc;
   vector<double>  *AK8JetPt_jesup_singleLepCalc;
   vector<double>  *AK8JetPt_singleLepCalc;
   vector<double>  *FWmoment1H_BestCalc;
   vector<double>  *FWmoment1W_BestCalc;
   vector<double>  *FWmoment1Z_BestCalc;
   vector<double>  *FWmoment1top_BestCalc;
   vector<double>  *FWmoment2H_BestCalc;
   vector<double>  *FWmoment2W_BestCalc;
   vector<double>  *FWmoment2Z_BestCalc;
   vector<double>  *FWmoment2top_BestCalc;
   vector<double>  *FWmoment3H_BestCalc;
   vector<double>  *FWmoment3W_BestCalc;
   vector<double>  *FWmoment3Z_BestCalc;
   vector<double>  *FWmoment3top_BestCalc;
   vector<double>  *FWmoment4H_BestCalc;
   vector<double>  *FWmoment4W_BestCalc;
   vector<double>  *FWmoment4Z_BestCalc;
   vector<double>  *FWmoment4top_BestCalc;
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
   vector<double>  *Njets_H_BestCalc;
   vector<double>  *Njets_W_BestCalc;
   vector<double>  *Njets_Z_BestCalc;
   vector<double>  *Njets_jet_BestCalc;
   vector<double>  *Njets_orig_BestCalc;
   vector<double>  *Njets_top_BestCalc;
   vector<double>  *SDmass_BestCalc;
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
   vector<double>  *aplanarityH_BestCalc;
   vector<double>  *aplanarityW_BestCalc;
   vector<double>  *aplanarityZ_BestCalc;
   vector<double>  *aplanaritytop_BestCalc;
   vector<double>  *bDisc1_BestCalc;
   vector<double>  *bDisc2_BestCalc;
   vector<double>  *bDisc_BestCalc;
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
   vector<double>  *decorr_H_DeepAK8Calc;
   vector<double>  *decorr_J_DeepAK8Calc;
   vector<double>  *decorr_T_DeepAK8Calc;
   vector<double>  *decorr_W_DeepAK8Calc;
   vector<double>  *decorr_Z_DeepAK8Calc;
   vector<double>  *dnn_B_DeepAK8Calc;
   vector<double>  *dnn_B_BestCalc;
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
   vector<double>  *elIsLooseBarrel_singleLepCalc;
   vector<double>  *elIsLooseEndCap_singleLepCalc;
   vector<double>  *elIsMediumBarrel_singleLepCalc;
   vector<double>  *elIsMediumEndCap_singleLepCalc;
   vector<double>  *elIsTightBarrel_singleLepCalc;
   vector<double>  *elIsTightEndCap_singleLepCalc;
   vector<double>  *elIsVetoBarrel_singleLepCalc;
   vector<double>  *elIsVetoEndCap_singleLepCalc;
   vector<double>  *elMVAValue_iso_singleLepCalc;
   vector<double>  *elMVAValue_singleLepCalc;
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
   vector<double>  *et_BestCalc;
   vector<double>  *eta_BestCalc;
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
   vector<double>  *isotropyH_BestCalc;
   vector<double>  *isotropyW_BestCalc;
   vector<double>  *isotropyZ_BestCalc;
   vector<double>  *isotropytop_BestCalc;
   vector<double>  *m1234H_BestCalc;
   vector<double>  *m1234W_BestCalc;
   vector<double>  *m1234Z_BestCalc;
   vector<double>  *m1234_jet_BestCalc;
   vector<double>  *m1234top_BestCalc;
   vector<double>  *m12H_BestCalc;
   vector<double>  *m12W_BestCalc;
   vector<double>  *m12Z_BestCalc;
   vector<double>  *m12_jet_BestCalc;
   vector<double>  *m12top_BestCalc;
   vector<double>  *m13H_BestCalc;
   vector<double>  *m13W_BestCalc;
   vector<double>  *m13Z_BestCalc;
   vector<double>  *m13_jet_BestCalc;
   vector<double>  *m13top_BestCalc;
   vector<double>  *m23H_BestCalc;
   vector<double>  *m23W_BestCalc;
   vector<double>  *m23Z_BestCalc;
   vector<double>  *m23_jet_BestCalc;
   vector<double>  *m23top_BestCalc;
   vector<double>  *mass_BestCalc;
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
   vector<double>  *pzOverp_H_BestCalc;
   vector<double>  *pzOverp_W_BestCalc;
   vector<double>  *pzOverp_Z_BestCalc;
   vector<double>  *pzOverp_jet_BestCalc;
   vector<double>  *pzOverp_top_BestCalc;
   vector<double>  *q_BestCalc;
   vector<double>  *quarkEnergy_TpTpCalc;
   vector<double>  *quarkEta_TpTpCalc;
   vector<double>  *quarkPhi_TpTpCalc;
   vector<double>  *quarkPt_TpTpCalc;
   vector<double>  *sphericityH_BestCalc;
   vector<double>  *sphericityW_BestCalc;
   vector<double>  *sphericityZ_BestCalc;
   vector<double>  *sphericitytop_BestCalc;
   vector<double>  *tPrimeEnergy_TpTpCalc;
   vector<double>  *tPrimeEta_TpTpCalc;
   vector<double>  *tPrimeMass_TpTpCalc;
   vector<double>  *tPrimePhi_TpTpCalc;
   vector<double>  *tPrimePt_TpTpCalc;
   vector<double>  *tau21_BestCalc;
   vector<double>  *tau32_BestCalc;
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
   vector<double>  *theJetAK8SDSubjetBTag_JetSubCalc;
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
   vector<double>  *theJetCSVb_JetSubCalc;
   vector<double>  *theJetCSVbb_JetSubCalc;
   vector<double>  theJetCSVb_JetSubCalc_PtOrdered;
   vector<double>  theJetCSVbb_JetSubCalc_PtOrdered;
   vector<double>  *theJetEnergy_JetSubCalc;
   vector<double>  *theJetEta_JetSubCalc;
   vector<double>  *theJetPhi_JetSubCalc;
   vector<double>  *theJetPileupJetId_JetSubCalc;
   vector<double>  *theJetPt_JetSubCalc;
   vector<double>  *thrustH_BestCalc;
   vector<double>  *thrustW_BestCalc;
   vector<double>  *thrustZ_BestCalc;
   vector<double>  *thrusttop_BestCalc;
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
   TBranch        *b_NBsFromTTbar_TTbarMassCalc;   //!
   TBranch        *b_NCharm_TTbarMassCalc;   //!
   TBranch        *b_NExtraBs_TTbarMassCalc;   //!
   TBranch        *b_NExtraCs_TTbarMassCalc;   //!
   TBranch        *b_NExtraLs_TTbarMassCalc;   //!
   TBranch        *b_NLeptonDecays_TpTpCalc;   //!
   TBranch        *b_NLight_TTbarMassCalc;   //!
   TBranch        *b_NPartonsfromHEPUEP_singleLepCalc;   //!
   TBranch        *b_NTotalBs_TTbarMassCalc;   //!
   TBranch        *b_NWdecaysFromTTbar_TTbarMassCalc;   //!
   TBranch        *b_dataE_singleLepCalc;   //!
   TBranch        *b_dataM_singleLepCalc;   //!
   TBranch        *b_genTDLID_singleLepCalc;   //!
   TBranch        *b_isTT_TTbarMassCalc;   //!
   TBranch        *b_isTTbb_TTbarMassCalc;   //!
   TBranch        *b_isTTbj_TTbarMassCalc;   //!
   TBranch        *b_isTTcc_TTbarMassCalc;   //!
   TBranch        *b_isTTcj_TTbarMassCalc;   //!
   TBranch        *b_isTTlf_TTbarMassCalc;   //!
   TBranch        *b_isTTll_TTbarMassCalc;   //!
   TBranch        *b_lumi_CommonCalc;   //!
   TBranch        *b_nAllJets_CommonCalc;   //!
   TBranch        *b_nLooseMuons_CommonCalc;   //!
   TBranch        *b_nPV_singleLepCalc;   //!
   TBranch        *b_nPileupInteractions_singleLepCalc;   //!
   TBranch        *b_nSelBtagJets_CommonCalc;   //!
   TBranch        *b_nSelElectrons_CommonCalc;   //!
   TBranch        *b_nSelJets_CommonCalc;   //!
   TBranch        *b_nTightMuons_CommonCalc;   //!
   TBranch        *b_nTrueInteractions_singleLepCalc;   //!
   TBranch        *b_run_CommonCalc;   //!
   TBranch        *b_event_CommonCalc;   //!
   TBranch        *b_AK4HT_jerdn_singleLepCalc;   //!
   TBranch        *b_AK4HT_jerup_singleLepCalc;   //!
   TBranch        *b_AK4HT_jesdn_singleLepCalc;   //!
   TBranch        *b_AK4HT_jesup_singleLepCalc;   //!
   TBranch        *b_AK4HT_singleLepCalc;   //!
   TBranch        *b_HTfromHEPUEP_singleLepCalc;   //!
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
   TBranch        *b_corr_metnohf_phi_singleLepCalc;   //!
   TBranch        *b_corr_metnohf_singleLepCalc;   //!
   TBranch        *b_genTDLEnergy_singleLepCalc;   //!
   TBranch        *b_genTDLEta_singleLepCalc;   //!
   TBranch        *b_genTDLPhi_singleLepCalc;   //!
   TBranch        *b_genTDLPt_singleLepCalc;   //!
   TBranch        *b_met_phi_singleLepCalc;   //!
   TBranch        *b_met_singleLepCalc;   //!
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
   TBranch        *b_maxProb_JetSubCalc;   //!
   TBranch        *b_dnn_largest_BestCalc;   //!
   TBranch        *b_dnn_largest_DeepAK8Calc;   //!
   TBranch        *b_decorr_largest_DeepAK8Calc;   //!
   TBranch        *b_elChargeConsistent_singleLepCalc;   //!
   TBranch        *b_elCharge_singleLepCalc;   //!
   TBranch        *b_elCtfCharge_singleLepCalc;   //!
   TBranch        *b_elGsfCharge_singleLepCalc;   //!
   TBranch        *b_elIsEBEE_singleLepCalc;   //!
   TBranch        *b_elIsMVALooseIso_singleLepCalc;   //!
   TBranch        *b_elIsMVALoose_singleLepCalc;   //!
   TBranch        *b_elIsMVATightIso_singleLepCalc;   //!
   TBranch        *b_elIsMVATight_singleLepCalc;   //!
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
   TBranch        *b_theJetAK8SDSubjetHFlav_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetIndex_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetNDeepCSVL_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetNDeepCSVM_bSFdn_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetNDeepCSVM_bSFup_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetNDeepCSVM_lSFdn_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetNDeepCSVM_lSFup_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetSize_JetSubCalc;   //!
   TBranch        *b_theJetAK8SJIndex_JetSubCalc;   //!
   TBranch        *b_theJetAK8SJSize_JetSubCalc;   //!
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
   TBranch        *b_AK4JetEnergy_jerdn_singleLepCalc;   //!
   TBranch        *b_AK4JetEnergy_jerup_singleLepCalc;   //!
   TBranch        *b_AK4JetEnergy_jesdn_singleLepCalc;   //!
   TBranch        *b_AK4JetEnergy_jesup_singleLepCalc;   //!
   TBranch        *b_AK4JetEnergy_singleLepCalc;   //!
   TBranch        *b_AK4JetEta_singleLepCalc;   //!
   TBranch        *b_AK4JetPhi_singleLepCalc;   //!
   TBranch        *b_AK4JetPt_jerdn_singleLepCalc;   //!
   TBranch        *b_AK4JetPt_jerup_singleLepCalc;   //!
   TBranch        *b_AK4JetPt_jesdn_singleLepCalc;   //!
   TBranch        *b_AK4JetPt_jesup_singleLepCalc;   //!
   TBranch        *b_AK4JetPt_singleLepCalc;   //!
   TBranch        *b_AK8JetCSV_BestCalc;   //!
   TBranch        *b_AK8JetCSV_singleLepCalc;   //!
   TBranch        *b_AK8JetEnergy_BestCalc;   //!
   TBranch        *b_AK8JetEnergy_jerdn_BestCalc;   //!
   TBranch        *b_AK8JetEnergy_jerdn_singleLepCalc;   //!
   TBranch        *b_AK8JetEnergy_jerup_BestCalc;   //!
   TBranch        *b_AK8JetEnergy_jerup_singleLepCalc;   //!
   TBranch        *b_AK8JetEnergy_jesdn_BestCalc;   //!
   TBranch        *b_AK8JetEnergy_jesdn_singleLepCalc;   //!
   TBranch        *b_AK8JetEnergy_jesup_BestCalc;   //!
   TBranch        *b_AK8JetEnergy_jesup_singleLepCalc;   //!
   TBranch        *b_AK8JetEnergy_singleLepCalc;   //!
   TBranch        *b_AK8JetEta_BestCalc;   //!
   TBranch        *b_AK8JetEta_singleLepCalc;   //!
   TBranch        *b_AK8JetPhi_BestCalc;   //!
   TBranch        *b_AK8JetPhi_singleLepCalc;   //!
   TBranch        *b_AK8JetPt_BestCalc;   //!
   TBranch        *b_AK8JetPt_jerdn_BestCalc;   //!
   TBranch        *b_AK8JetPt_jerdn_singleLepCalc;   //!
   TBranch        *b_AK8JetPt_jerup_BestCalc;   //!
   TBranch        *b_AK8JetPt_jerup_singleLepCalc;   //!
   TBranch        *b_AK8JetPt_jesdn_BestCalc;   //!
   TBranch        *b_AK8JetPt_jesdn_singleLepCalc;   //!
   TBranch        *b_AK8JetPt_jesup_BestCalc;   //!
   TBranch        *b_AK8JetPt_jesup_singleLepCalc;   //!
   TBranch        *b_AK8JetPt_singleLepCalc;   //!
   TBranch        *b_FWmoment1H_BestCalc;   //!
   TBranch        *b_FWmoment1W_BestCalc;   //!
   TBranch        *b_FWmoment1Z_BestCalc;   //!
   TBranch        *b_FWmoment1top_BestCalc;   //!
   TBranch        *b_FWmoment2H_BestCalc;   //!
   TBranch        *b_FWmoment2W_BestCalc;   //!
   TBranch        *b_FWmoment2Z_BestCalc;   //!
   TBranch        *b_FWmoment2top_BestCalc;   //!
   TBranch        *b_FWmoment3H_BestCalc;   //!
   TBranch        *b_FWmoment3W_BestCalc;   //!
   TBranch        *b_FWmoment3Z_BestCalc;   //!
   TBranch        *b_FWmoment3top_BestCalc;   //!
   TBranch        *b_FWmoment4H_BestCalc;   //!
   TBranch        *b_FWmoment4W_BestCalc;   //!
   TBranch        *b_FWmoment4Z_BestCalc;   //!
   TBranch        *b_FWmoment4top_BestCalc;   //!
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
   TBranch        *b_Njets_H_BestCalc;   //!
   TBranch        *b_Njets_W_BestCalc;   //!
   TBranch        *b_Njets_Z_BestCalc;   //!
   TBranch        *b_Njets_jet_BestCalc;   //!
   TBranch        *b_Njets_orig_BestCalc;   //!
   TBranch        *b_Njets_top_BestCalc;   //!
   TBranch        *b_SDmass_BestCalc;   //!
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
   TBranch        *b_aplanarityH_BestCalc;   //!
   TBranch        *b_aplanarityW_BestCalc;   //!
   TBranch        *b_aplanarityZ_BestCalc;   //!
   TBranch        *b_aplanaritytop_BestCalc;   //!
   TBranch        *b_bDisc1_BestCalc;   //!
   TBranch        *b_bDisc2_BestCalc;   //!
   TBranch        *b_bDisc_BestCalc;   //!
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
   TBranch        *b_decorr_H_DeepAK8Calc;   //!
   TBranch        *b_decorr_J_DeepAK8Calc;   //!
   TBranch        *b_decorr_T_DeepAK8Calc;   //!
   TBranch        *b_decorr_W_DeepAK8Calc;   //!
   TBranch        *b_decorr_Z_DeepAK8Calc;   //!
   TBranch        *b_dnn_B_DeepAK8Calc;   //!
   TBranch        *b_dnn_B_BestCalc;   //!
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
   TBranch        *b_elIsLooseBarrel_singleLepCalc;   //!
   TBranch        *b_elIsLooseEndCap_singleLepCalc;   //!
   TBranch        *b_elIsMediumBarrel_singleLepCalc;   //!
   TBranch        *b_elIsMediumEndCap_singleLepCalc;   //!
   TBranch        *b_elIsTightBarrel_singleLepCalc;   //!
   TBranch        *b_elIsTightEndCap_singleLepCalc;   //!
   TBranch        *b_elIsVetoBarrel_singleLepCalc;   //!
   TBranch        *b_elIsVetoEndCap_singleLepCalc;   //!
   TBranch        *b_elMVAValue_iso_singleLepCalc;   //!
   TBranch        *b_elMVAValue_singleLepCalc;   //!
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
   TBranch        *b_et_BestCalc;   //!
   TBranch        *b_eta_BestCalc;   //!
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
   TBranch        *b_isotropyH_BestCalc;   //!
   TBranch        *b_isotropyW_BestCalc;   //!
   TBranch        *b_isotropyZ_BestCalc;   //!
   TBranch        *b_isotropytop_BestCalc;   //!
   TBranch        *b_m1234H_BestCalc;   //!
   TBranch        *b_m1234W_BestCalc;   //!
   TBranch        *b_m1234Z_BestCalc;   //!
   TBranch        *b_m1234_jet_BestCalc;   //!
   TBranch        *b_m1234top_BestCalc;   //!
   TBranch        *b_m12H_BestCalc;   //!
   TBranch        *b_m12W_BestCalc;   //!
   TBranch        *b_m12Z_BestCalc;   //!
   TBranch        *b_m12_jet_BestCalc;   //!
   TBranch        *b_m12top_BestCalc;   //!
   TBranch        *b_m13H_BestCalc;   //!
   TBranch        *b_m13W_BestCalc;   //!
   TBranch        *b_m13Z_BestCalc;   //!
   TBranch        *b_m13_jet_BestCalc;   //!
   TBranch        *b_m13top_BestCalc;   //!
   TBranch        *b_m23H_BestCalc;   //!
   TBranch        *b_m23W_BestCalc;   //!
   TBranch        *b_m23Z_BestCalc;   //!
   TBranch        *b_m23_jet_BestCalc;   //!
   TBranch        *b_m23top_BestCalc;   //!
   TBranch        *b_mass_BestCalc;   //!
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
   TBranch        *b_pzOverp_H_BestCalc;   //!
   TBranch        *b_pzOverp_W_BestCalc;   //!
   TBranch        *b_pzOverp_Z_BestCalc;   //!
   TBranch        *b_pzOverp_jet_BestCalc;   //!
   TBranch        *b_pzOverp_top_BestCalc;   //!
   TBranch        *b_q_BestCalc;   //!
   TBranch        *b_quarkEnergy_TpTpCalc;   //!
   TBranch        *b_quarkEta_TpTpCalc;   //!
   TBranch        *b_quarkPhi_TpTpCalc;   //!
   TBranch        *b_quarkPt_TpTpCalc;   //!
   TBranch        *b_sphericityH_BestCalc;   //!
   TBranch        *b_sphericityW_BestCalc;   //!
   TBranch        *b_sphericityZ_BestCalc;   //!
   TBranch        *b_sphericitytop_BestCalc;   //!
   TBranch        *b_tPrimeEnergy_TpTpCalc;   //!
   TBranch        *b_tPrimeEta_TpTpCalc;   //!
   TBranch        *b_tPrimeMass_TpTpCalc;   //!
   TBranch        *b_tPrimePhi_TpTpCalc;   //!
   TBranch        *b_tPrimePt_TpTpCalc;   //!
   TBranch        *b_tau21_BestCalc;   //!
   TBranch        *b_tau32_BestCalc;   //!
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
   TBranch        *b_theJetAK8SDSubjetBTag_JetSubCalc;   //!
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
   TBranch        *b_theJetCSVb_JetSubCalc;   //!
   TBranch        *b_theJetCSVbb_JetSubCalc;   //!
   //TBranch        *b_theJetCSVc_JetSubCalc;   //!
   //TBranch        *b_theJetCSVudsg_JetSubCalc;   //!
   TBranch        *b_theJetEnergy_JetSubCalc;   //!
   TBranch        *b_theJetEta_JetSubCalc;   //!
   TBranch        *b_theJetPhi_JetSubCalc;   //!
   TBranch        *b_theJetPileupJetId_JetSubCalc;   //!
   TBranch        *b_theJetPt_JetSubCalc;   //!
   TBranch        *b_thrustH_BestCalc;   //!
   TBranch        *b_thrustW_BestCalc;   //!
   TBranch        *b_thrustZ_BestCalc;   //!
   TBranch        *b_thrusttop_BestCalc;   //!
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
 
   step1(TString inputFileName, TString outputFileName);
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
};

#endif

#ifdef step1_cxx
step1::step1(TString inputFileName, TString outputFileName) : inputTree(0), inputFile(0), outputFile(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.

  isSig  = (inputFileName.Contains("prime") || inputFileName.Contains("X53") || inputFileName.Contains("ChargedHiggs_Hplus"));
  if(isSig){
    if(inputFileName.Contains("Tprime")) isTpTp = true;
    else if(inputFileName.Contains("Bprime")) isBpBp = true;
    else if(inputFileName.Contains("X53")) isXX = true;

    if(inputFileName.Contains("_M-700")) SigMass = 0;
    else if(inputFileName.Contains("_M-800")) SigMass = 1;
    else if(inputFileName.Contains("_M-900")) SigMass = 2;
    else if(inputFileName.Contains("_M-1000")) SigMass = 3;
    else if(inputFileName.Contains("_M-1100")) {SigMass = 4; pileupIndex = 20;}
    else if(inputFileName.Contains("_M-1200")) {SigMass = 5; pileupIndex = 21;}
    else if(inputFileName.Contains("_M-1300")) {SigMass = 6; pileupIndex = 22;}
    else if(inputFileName.Contains("_M-1400")) {SigMass = 7; pileupIndex = 23;}
    else if(inputFileName.Contains("_M-1500")) {SigMass = 8; pileupIndex = 24;}
    else if(inputFileName.Contains("_M-1600")) {SigMass = 9; pileupIndex = 25;}
    else if(inputFileName.Contains("_M-1700")) {SigMass = 10; pileupIndex = 26;}
    else if(inputFileName.Contains("_M-1800")) {SigMass = 11; pileupIndex = 27;}
    else SigMass = -1;
  }  
  isMadgraphBkg = ((inputFileName.Contains("WJetsToLNu") || inputFileName.Contains("DYJetsToLL_M-50") || inputFileName.Contains("QCD")) && inputFileName.Contains("madgraph"));
  isTOP = (inputFileName.Contains("Mtt") || inputFileName.Contains("ST") || inputFileName.Contains("TTZ") || inputFileName.Contains("TTW") || inputFileName.Contains("TTTo"));
  isTT = (inputFileName.Contains("TT_Tune") || inputFileName.Contains("Mtt") || inputFileName.Contains("TTTo"));
  isSTt = inputFileName.Contains("ST_t-channel");
  isSTtW = inputFileName.Contains("ST_tW");
  isTTV = (inputFileName.Contains("TTZ") || inputFileName.Contains("TTW"));
  isVV = (inputFileName.Contains("WW_") || inputFileName.Contains("WZ_") || inputFileName.Contains("ZZ_"));
  isMC      = !inputFileName.Contains("Single");
  isSM = inputFileName.Contains("SingleMuon");
  isSE = inputFileName.Contains("SingleElectron");

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
  else if(inputFileName.Contains("TT_Mtt-1000")) pileupIndex = 13;
  else if(inputFileName.Contains("TTToSemi")) pileupIndex = 14;
  else if(inputFileName.Contains("TTTo2L2Nu")) pileupIndex = 15;
  else if(inputFileName.Contains("TT_Mtt-700")) pileupIndex = 16;
  else if(inputFileName.Contains("TTWJetsToLNu")) pileupIndex = 17;
  else if(inputFileName.Contains("TTZToLL")) pileupIndex = 18;
  else if(inputFileName.Contains("TTToHadronic")) pileupIndex = 19;
  else if(inputFileName.Contains("WJetsToLNu_HT-1200")) pileupIndex = 28;
  else if(inputFileName.Contains("WJetsToLNu_HT-200")) pileupIndex = 29;
  else if(inputFileName.Contains("WJetsToLNu_HT-2500")) pileupIndex = 30;
  else if(inputFileName.Contains("WJetsToLNu_HT-400")) pileupIndex = 31;
  else if(inputFileName.Contains("WJetsToLNu_HT-600")) pileupIndex = 32;
  else if(inputFileName.Contains("WJetsToLNu_HT-800")) pileupIndex = 32;

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
  inputFile=TFile::Open(inputFileName);
  inputTree=(TTree*)inputFile->Get("ljmet");
  if(inputTree->GetEntries()==0) std::cout<<"WARNING! Found 0 events in the tree!!!!"<<std::endl;;
  
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
   maxProb_JetSubCalc = 0;
   dnn_largest_BestCalc = 0;
   dnn_largest_DeepAK8Calc = 0;
   decorr_largest_DeepAK8Calc = 0;
   elChargeConsistent_singleLepCalc = 0;
   elCharge_singleLepCalc = 0;
   elCtfCharge_singleLepCalc = 0;
   elGsfCharge_singleLepCalc = 0;
   elIsEBEE_singleLepCalc = 0;
   elIsMVALooseIso_singleLepCalc = 0;
   elIsMVALoose_singleLepCalc = 0;
   elIsMVATightIso_singleLepCalc = 0;
   elIsMVATight_singleLepCalc = 0;
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
   theJetAK8SDSubjetHFlav_JetSubCalc = 0;
   theJetAK8SDSubjetIndex_JetSubCalc = 0;
   theJetAK8SDSubjetNDeepCSVL_JetSubCalc = 0;
   theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc = 0;
   theJetAK8SDSubjetNDeepCSVM_bSFdn_JetSubCalc = 0;
   theJetAK8SDSubjetNDeepCSVM_bSFup_JetSubCalc = 0;
   theJetAK8SDSubjetNDeepCSVM_lSFdn_JetSubCalc = 0;
   theJetAK8SDSubjetNDeepCSVM_lSFup_JetSubCalc = 0;
   theJetAK8SDSubjetSize_JetSubCalc = 0;
   theJetAK8SJIndex_JetSubCalc = 0;
   theJetAK8SJSize_JetSubCalc = 0;
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
   AK4JetEnergy_jerdn_singleLepCalc = 0;
   AK4JetEnergy_jerup_singleLepCalc = 0;
   AK4JetEnergy_jesdn_singleLepCalc = 0;
   AK4JetEnergy_jesup_singleLepCalc = 0;
   AK4JetEnergy_singleLepCalc = 0;
   AK4JetEta_singleLepCalc = 0;
   AK4JetPhi_singleLepCalc = 0;
   AK4JetPt_jerdn_singleLepCalc = 0;
   AK4JetPt_jerup_singleLepCalc = 0;
   AK4JetPt_jesdn_singleLepCalc = 0;
   AK4JetPt_jesup_singleLepCalc = 0;
   AK4JetPt_singleLepCalc = 0;
   AK8JetCSV_BestCalc = 0;
   AK8JetCSV_singleLepCalc = 0;
   AK8JetEnergy_BestCalc = 0;
   AK8JetEnergy_jerdn_BestCalc = 0;
   AK8JetEnergy_jerdn_singleLepCalc = 0;
   AK8JetEnergy_jerup_BestCalc = 0;
   AK8JetEnergy_jerup_singleLepCalc = 0;
   AK8JetEnergy_jesdn_BestCalc = 0;
   AK8JetEnergy_jesdn_singleLepCalc = 0;
   AK8JetEnergy_jesup_BestCalc = 0;
   AK8JetEnergy_jesup_singleLepCalc = 0;
   AK8JetEnergy_singleLepCalc = 0;
   AK8JetEta_BestCalc = 0;
   AK8JetEta_singleLepCalc = 0;
   AK8JetPhi_BestCalc = 0;
   AK8JetPhi_singleLepCalc = 0;
   AK8JetPt_BestCalc = 0;
   AK8JetPt_jerdn_BestCalc = 0;
   AK8JetPt_jerdn_singleLepCalc = 0;
   AK8JetPt_jerup_BestCalc = 0;
   AK8JetPt_jerup_singleLepCalc = 0;
   AK8JetPt_jesdn_BestCalc = 0;
   AK8JetPt_jesdn_singleLepCalc = 0;
   AK8JetPt_jesup_BestCalc = 0;
   AK8JetPt_jesup_singleLepCalc = 0;
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
   decorr_H_DeepAK8Calc = 0;
   decorr_J_DeepAK8Calc = 0;
   decorr_T_DeepAK8Calc = 0;
   decorr_W_DeepAK8Calc = 0;
   decorr_Z_DeepAK8Calc = 0;
   dnn_B_DeepAK8Calc = 0;
   dnn_B_BestCalc = 0;
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
   elIsLooseBarrel_singleLepCalc = 0;
   elIsLooseEndCap_singleLepCalc = 0;
   elIsMediumBarrel_singleLepCalc = 0;
   elIsMediumEndCap_singleLepCalc = 0;
   elIsTightBarrel_singleLepCalc = 0;
   elIsTightEndCap_singleLepCalc = 0;
   elIsVetoBarrel_singleLepCalc = 0;
   elIsVetoEndCap_singleLepCalc = 0;
   elMVAValue_iso_singleLepCalc = 0;
   elMVAValue_singleLepCalc = 0;
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
   theJetAK8SDSubjetBTag_JetSubCalc = 0;
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
   theJetCSVb_JetSubCalc = 0;
   theJetCSVbb_JetSubCalc = 0;
   //theJetCSVc_JetSubCalc = 0;
   //theJetCSVudsg_JetSubCalc = 0;
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
   inputTree->SetBranchAddress("NBsFromTTbar_TTbarMassCalc", &NBsFromTTbar_TTbarMassCalc, &b_NBsFromTTbar_TTbarMassCalc);
   inputTree->SetBranchAddress("NCharm_TTbarMassCalc", &NCharm_TTbarMassCalc, &b_NCharm_TTbarMassCalc);
   inputTree->SetBranchAddress("NExtraBs_TTbarMassCalc", &NExtraBs_TTbarMassCalc, &b_NExtraBs_TTbarMassCalc);
   inputTree->SetBranchAddress("NExtraCs_TTbarMassCalc", &NExtraCs_TTbarMassCalc, &b_NExtraCs_TTbarMassCalc);
   inputTree->SetBranchAddress("NExtraLs_TTbarMassCalc", &NExtraLs_TTbarMassCalc, &b_NExtraLs_TTbarMassCalc);
   inputTree->SetBranchAddress("NLeptonDecays_TpTpCalc", &NLeptonDecays_TpTpCalc, &b_NLeptonDecays_TpTpCalc);
   inputTree->SetBranchAddress("NLight_TTbarMassCalc", &NLight_TTbarMassCalc, &b_NLight_TTbarMassCalc);
   inputTree->SetBranchAddress("NPartonsfromHEPUEP_singleLepCalc", &NPartonsfromHEPUEP_singleLepCalc, &b_NPartonsfromHEPUEP_singleLepCalc);
   inputTree->SetBranchAddress("NTotalBs_TTbarMassCalc", &NTotalBs_TTbarMassCalc, &b_NTotalBs_TTbarMassCalc);
   inputTree->SetBranchAddress("NWdecaysFromTTbar_TTbarMassCalc", &NWdecaysFromTTbar_TTbarMassCalc, &b_NWdecaysFromTTbar_TTbarMassCalc);
   inputTree->SetBranchAddress("dataE_singleLepCalc", &dataE_singleLepCalc, &b_dataE_singleLepCalc);
   inputTree->SetBranchAddress("dataM_singleLepCalc", &dataM_singleLepCalc, &b_dataM_singleLepCalc);
   inputTree->SetBranchAddress("genTDLID_singleLepCalc", &genTDLID_singleLepCalc, &b_genTDLID_singleLepCalc);
   inputTree->SetBranchAddress("isTT_TTbarMassCalc", &isTT_TTbarMassCalc, &b_isTT_TTbarMassCalc);
   inputTree->SetBranchAddress("isTTbb_TTbarMassCalc", &isTTbb_TTbarMassCalc, &b_isTTbb_TTbarMassCalc);
   inputTree->SetBranchAddress("isTTbj_TTbarMassCalc", &isTTbj_TTbarMassCalc, &b_isTTbj_TTbarMassCalc);
   inputTree->SetBranchAddress("isTTcc_TTbarMassCalc", &isTTcc_TTbarMassCalc, &b_isTTcc_TTbarMassCalc);
   inputTree->SetBranchAddress("isTTcj_TTbarMassCalc", &isTTcj_TTbarMassCalc, &b_isTTcj_TTbarMassCalc);
   inputTree->SetBranchAddress("isTTlf_TTbarMassCalc", &isTTlf_TTbarMassCalc, &b_isTTlf_TTbarMassCalc);
   inputTree->SetBranchAddress("isTTll_TTbarMassCalc", &isTTll_TTbarMassCalc, &b_isTTll_TTbarMassCalc);
   inputTree->SetBranchAddress("lumi_CommonCalc", &lumi_CommonCalc, &b_lumi_CommonCalc);
   inputTree->SetBranchAddress("nAllJets_CommonCalc", &nAllJets_CommonCalc, &b_nAllJets_CommonCalc);
   inputTree->SetBranchAddress("nLooseMuons_CommonCalc", &nLooseMuons_CommonCalc, &b_nLooseMuons_CommonCalc);
   inputTree->SetBranchAddress("nPV_singleLepCalc", &nPV_singleLepCalc, &b_nPV_singleLepCalc);
   inputTree->SetBranchAddress("nPileupInteractions_singleLepCalc", &nPileupInteractions_singleLepCalc, &b_nPileupInteractions_singleLepCalc);
   inputTree->SetBranchAddress("nSelBtagJets_CommonCalc", &nSelBtagJets_CommonCalc, &b_nSelBtagJets_CommonCalc);
   inputTree->SetBranchAddress("nSelElectrons_CommonCalc", &nSelElectrons_CommonCalc, &b_nSelElectrons_CommonCalc);
   inputTree->SetBranchAddress("nSelJets_CommonCalc", &nSelJets_CommonCalc, &b_nSelJets_CommonCalc);
   inputTree->SetBranchAddress("nTightMuons_CommonCalc", &nTightMuons_CommonCalc, &b_nTightMuons_CommonCalc);
   inputTree->SetBranchAddress("nTrueInteractions_singleLepCalc", &nTrueInteractions_singleLepCalc, &b_nTrueInteractions_singleLepCalc);
   inputTree->SetBranchAddress("run_CommonCalc", &run_CommonCalc, &b_run_CommonCalc);
   inputTree->SetBranchAddress("event_CommonCalc", &event_CommonCalc, &b_event_CommonCalc);
   inputTree->SetBranchAddress("AK4HT_jerdn_singleLepCalc", &AK4HT_jerdn_singleLepCalc, &b_AK4HT_jerdn_singleLepCalc);
   inputTree->SetBranchAddress("AK4HT_jerup_singleLepCalc", &AK4HT_jerup_singleLepCalc, &b_AK4HT_jerup_singleLepCalc);
   inputTree->SetBranchAddress("AK4HT_jesdn_singleLepCalc", &AK4HT_jesdn_singleLepCalc, &b_AK4HT_jesdn_singleLepCalc);
   inputTree->SetBranchAddress("AK4HT_jesup_singleLepCalc", &AK4HT_jesup_singleLepCalc, &b_AK4HT_jesup_singleLepCalc);
   inputTree->SetBranchAddress("AK4HT_singleLepCalc", &AK4HT_singleLepCalc, &b_AK4HT_singleLepCalc);
   inputTree->SetBranchAddress("HTfromHEPUEP_singleLepCalc", &HTfromHEPUEP_singleLepCalc, &b_HTfromHEPUEP_singleLepCalc);
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
   inputTree->SetBranchAddress("corr_metnohf_phi_singleLepCalc", &corr_metnohf_phi_singleLepCalc, &b_corr_metnohf_phi_singleLepCalc);
   inputTree->SetBranchAddress("corr_metnohf_singleLepCalc", &corr_metnohf_singleLepCalc, &b_corr_metnohf_singleLepCalc);
   inputTree->SetBranchAddress("genTDLEnergy_singleLepCalc", &genTDLEnergy_singleLepCalc, &b_genTDLEnergy_singleLepCalc);
   inputTree->SetBranchAddress("genTDLEta_singleLepCalc", &genTDLEta_singleLepCalc, &b_genTDLEta_singleLepCalc);
   inputTree->SetBranchAddress("genTDLPhi_singleLepCalc", &genTDLPhi_singleLepCalc, &b_genTDLPhi_singleLepCalc);
   inputTree->SetBranchAddress("genTDLPt_singleLepCalc", &genTDLPt_singleLepCalc, &b_genTDLPt_singleLepCalc);
   inputTree->SetBranchAddress("met_phi_singleLepCalc", &met_phi_singleLepCalc, &b_met_phi_singleLepCalc);
   inputTree->SetBranchAddress("met_singleLepCalc", &met_singleLepCalc, &b_met_singleLepCalc);
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
   inputTree->SetBranchAddress("maxProb_JetSubCalc", &maxProb_JetSubCalc, &b_maxProb_JetSubCalc);
   inputTree->SetBranchAddress("dnn_largest_BestCalc", &dnn_largest_BestCalc, &b_dnn_largest_BestCalc);
   inputTree->SetBranchAddress("dnn_largest_DeepAK8Calc", &dnn_largest_DeepAK8Calc, &b_dnn_largest_DeepAK8Calc);
   inputTree->SetBranchAddress("decorr_largest_DeepAK8Calc", &decorr_largest_DeepAK8Calc, &b_decorr_largest_DeepAK8Calc);
   inputTree->SetBranchAddress("elChargeConsistent_singleLepCalc", &elChargeConsistent_singleLepCalc, &b_elChargeConsistent_singleLepCalc);
   inputTree->SetBranchAddress("elCharge_singleLepCalc", &elCharge_singleLepCalc, &b_elCharge_singleLepCalc);
   inputTree->SetBranchAddress("elCtfCharge_singleLepCalc", &elCtfCharge_singleLepCalc, &b_elCtfCharge_singleLepCalc);
   inputTree->SetBranchAddress("elGsfCharge_singleLepCalc", &elGsfCharge_singleLepCalc, &b_elGsfCharge_singleLepCalc);
   inputTree->SetBranchAddress("elIsEBEE_singleLepCalc", &elIsEBEE_singleLepCalc, &b_elIsEBEE_singleLepCalc);
   inputTree->SetBranchAddress("elIsMVALooseIso_singleLepCalc", &elIsMVALooseIso_singleLepCalc, &b_elIsMVALooseIso_singleLepCalc);
   inputTree->SetBranchAddress("elIsMVALoose_singleLepCalc", &elIsMVALoose_singleLepCalc, &b_elIsMVALoose_singleLepCalc);
   inputTree->SetBranchAddress("elIsMVATightIso_singleLepCalc", &elIsMVATightIso_singleLepCalc, &b_elIsMVATightIso_singleLepCalc);
   inputTree->SetBranchAddress("elIsMVATight_singleLepCalc", &elIsMVATight_singleLepCalc, &b_elIsMVATight_singleLepCalc);
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
   inputTree->SetBranchAddress("theJetAK8SDSubjetHFlav_JetSubCalc", &theJetAK8SDSubjetHFlav_JetSubCalc, &b_theJetAK8SDSubjetHFlav_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetIndex_JetSubCalc", &theJetAK8SDSubjetIndex_JetSubCalc, &b_theJetAK8SDSubjetIndex_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNDeepCSVL_JetSubCalc", &theJetAK8SDSubjetNDeepCSVL_JetSubCalc, &b_theJetAK8SDSubjetNDeepCSVL_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc", &theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc, &b_theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNDeepCSVM_bSFdn_JetSubCalc", &theJetAK8SDSubjetNDeepCSVM_bSFdn_JetSubCalc, &b_theJetAK8SDSubjetNDeepCSVM_bSFdn_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNDeepCSVM_bSFup_JetSubCalc", &theJetAK8SDSubjetNDeepCSVM_bSFup_JetSubCalc, &b_theJetAK8SDSubjetNDeepCSVM_bSFup_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNDeepCSVM_lSFdn_JetSubCalc", &theJetAK8SDSubjetNDeepCSVM_lSFdn_JetSubCalc, &b_theJetAK8SDSubjetNDeepCSVM_lSFdn_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNDeepCSVM_lSFup_JetSubCalc", &theJetAK8SDSubjetNDeepCSVM_lSFup_JetSubCalc, &b_theJetAK8SDSubjetNDeepCSVM_lSFup_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetSize_JetSubCalc", &theJetAK8SDSubjetSize_JetSubCalc, &b_theJetAK8SDSubjetSize_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SJIndex_JetSubCalc", &theJetAK8SJIndex_JetSubCalc, &b_theJetAK8SJIndex_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SJSize_JetSubCalc", &theJetAK8SJSize_JetSubCalc, &b_theJetAK8SJSize_JetSubCalc);
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
   inputTree->SetBranchAddress("AK4JetEnergy_jerdn_singleLepCalc", &AK4JetEnergy_jerdn_singleLepCalc, &b_AK4JetEnergy_jerdn_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetEnergy_jerup_singleLepCalc", &AK4JetEnergy_jerup_singleLepCalc, &b_AK4JetEnergy_jerup_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetEnergy_jesdn_singleLepCalc", &AK4JetEnergy_jesdn_singleLepCalc, &b_AK4JetEnergy_jesdn_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetEnergy_jesup_singleLepCalc", &AK4JetEnergy_jesup_singleLepCalc, &b_AK4JetEnergy_jesup_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetEnergy_singleLepCalc", &AK4JetEnergy_singleLepCalc, &b_AK4JetEnergy_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetEta_singleLepCalc", &AK4JetEta_singleLepCalc, &b_AK4JetEta_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetPhi_singleLepCalc", &AK4JetPhi_singleLepCalc, &b_AK4JetPhi_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetPt_jerdn_singleLepCalc", &AK4JetPt_jerdn_singleLepCalc, &b_AK4JetPt_jerdn_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetPt_jerup_singleLepCalc", &AK4JetPt_jerup_singleLepCalc, &b_AK4JetPt_jerup_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetPt_jesdn_singleLepCalc", &AK4JetPt_jesdn_singleLepCalc, &b_AK4JetPt_jesdn_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetPt_jesup_singleLepCalc", &AK4JetPt_jesup_singleLepCalc, &b_AK4JetPt_jesup_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetPt_singleLepCalc", &AK4JetPt_singleLepCalc, &b_AK4JetPt_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetCSV_BestCalc", &AK8JetCSV_BestCalc, &b_AK8JetCSV_BestCalc);
   inputTree->SetBranchAddress("AK8JetCSV_singleLepCalc", &AK8JetCSV_singleLepCalc, &b_AK8JetCSV_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetEnergy_BestCalc", &AK8JetEnergy_BestCalc, &b_AK8JetEnergy_BestCalc);
   inputTree->SetBranchAddress("AK8JetEnergy_jerdn_BestCalc", &AK8JetEnergy_jerdn_BestCalc, &b_AK8JetEnergy_jerdn_BestCalc);
   inputTree->SetBranchAddress("AK8JetEnergy_jerdn_singleLepCalc", &AK8JetEnergy_jerdn_singleLepCalc, &b_AK8JetEnergy_jerdn_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetEnergy_jerup_BestCalc", &AK8JetEnergy_jerup_BestCalc, &b_AK8JetEnergy_jerup_BestCalc);
   inputTree->SetBranchAddress("AK8JetEnergy_jerup_singleLepCalc", &AK8JetEnergy_jerup_singleLepCalc, &b_AK8JetEnergy_jerup_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetEnergy_jesdn_BestCalc", &AK8JetEnergy_jesdn_BestCalc, &b_AK8JetEnergy_jesdn_BestCalc);
   inputTree->SetBranchAddress("AK8JetEnergy_jesdn_singleLepCalc", &AK8JetEnergy_jesdn_singleLepCalc, &b_AK8JetEnergy_jesdn_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetEnergy_jesup_BestCalc", &AK8JetEnergy_jesup_BestCalc, &b_AK8JetEnergy_jesup_BestCalc);
   inputTree->SetBranchAddress("AK8JetEnergy_jesup_singleLepCalc", &AK8JetEnergy_jesup_singleLepCalc, &b_AK8JetEnergy_jesup_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetEnergy_singleLepCalc", &AK8JetEnergy_singleLepCalc, &b_AK8JetEnergy_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetEta_BestCalc", &AK8JetEta_BestCalc, &b_AK8JetEta_BestCalc);
   inputTree->SetBranchAddress("AK8JetEta_singleLepCalc", &AK8JetEta_singleLepCalc, &b_AK8JetEta_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetPhi_BestCalc", &AK8JetPhi_BestCalc, &b_AK8JetPhi_BestCalc);
   inputTree->SetBranchAddress("AK8JetPhi_singleLepCalc", &AK8JetPhi_singleLepCalc, &b_AK8JetPhi_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetPt_BestCalc", &AK8JetPt_BestCalc, &b_AK8JetPt_BestCalc);
   inputTree->SetBranchAddress("AK8JetPt_jerdn_BestCalc", &AK8JetPt_jerdn_BestCalc, &b_AK8JetPt_jerdn_BestCalc);
   inputTree->SetBranchAddress("AK8JetPt_jerdn_singleLepCalc", &AK8JetPt_jerdn_singleLepCalc, &b_AK8JetPt_jerdn_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetPt_jerup_BestCalc", &AK8JetPt_jerup_BestCalc, &b_AK8JetPt_jerup_BestCalc);
   inputTree->SetBranchAddress("AK8JetPt_jerup_singleLepCalc", &AK8JetPt_jerup_singleLepCalc, &b_AK8JetPt_jerup_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetPt_jesdn_BestCalc", &AK8JetPt_jesdn_BestCalc, &b_AK8JetPt_jesdn_BestCalc);
   inputTree->SetBranchAddress("AK8JetPt_jesdn_singleLepCalc", &AK8JetPt_jesdn_singleLepCalc, &b_AK8JetPt_jesdn_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetPt_jesup_BestCalc", &AK8JetPt_jesup_BestCalc, &b_AK8JetPt_jesup_BestCalc);
   inputTree->SetBranchAddress("AK8JetPt_jesup_singleLepCalc", &AK8JetPt_jesup_singleLepCalc, &b_AK8JetPt_jesup_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetPt_singleLepCalc", &AK8JetPt_singleLepCalc, &b_AK8JetPt_singleLepCalc);
   inputTree->SetBranchAddress("FWmoment1H_BestCalc", &FWmoment1H_BestCalc, &b_FWmoment1H_BestCalc);
   inputTree->SetBranchAddress("FWmoment1W_BestCalc", &FWmoment1W_BestCalc, &b_FWmoment1W_BestCalc);
   inputTree->SetBranchAddress("FWmoment1Z_BestCalc", &FWmoment1Z_BestCalc, &b_FWmoment1Z_BestCalc);
   inputTree->SetBranchAddress("FWmoment1top_BestCalc", &FWmoment1top_BestCalc, &b_FWmoment1top_BestCalc);
   inputTree->SetBranchAddress("FWmoment2H_BestCalc", &FWmoment2H_BestCalc, &b_FWmoment2H_BestCalc);
   inputTree->SetBranchAddress("FWmoment2W_BestCalc", &FWmoment2W_BestCalc, &b_FWmoment2W_BestCalc);
   inputTree->SetBranchAddress("FWmoment2Z_BestCalc", &FWmoment2Z_BestCalc, &b_FWmoment2Z_BestCalc);
   inputTree->SetBranchAddress("FWmoment2top_BestCalc", &FWmoment2top_BestCalc, &b_FWmoment2top_BestCalc);
   inputTree->SetBranchAddress("FWmoment3H_BestCalc", &FWmoment3H_BestCalc, &b_FWmoment3H_BestCalc);
   inputTree->SetBranchAddress("FWmoment3W_BestCalc", &FWmoment3W_BestCalc, &b_FWmoment3W_BestCalc);
   inputTree->SetBranchAddress("FWmoment3Z_BestCalc", &FWmoment3Z_BestCalc, &b_FWmoment3Z_BestCalc);
   inputTree->SetBranchAddress("FWmoment3top_BestCalc", &FWmoment3top_BestCalc, &b_FWmoment3top_BestCalc);
   inputTree->SetBranchAddress("FWmoment4H_BestCalc", &FWmoment4H_BestCalc, &b_FWmoment4H_BestCalc);
   inputTree->SetBranchAddress("FWmoment4W_BestCalc", &FWmoment4W_BestCalc, &b_FWmoment4W_BestCalc);
   inputTree->SetBranchAddress("FWmoment4Z_BestCalc", &FWmoment4Z_BestCalc, &b_FWmoment4Z_BestCalc);
   inputTree->SetBranchAddress("FWmoment4top_BestCalc", &FWmoment4top_BestCalc, &b_FWmoment4top_BestCalc);
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
   inputTree->SetBranchAddress("Njets_H_BestCalc", &Njets_H_BestCalc, &b_Njets_H_BestCalc);
   inputTree->SetBranchAddress("Njets_W_BestCalc", &Njets_W_BestCalc, &b_Njets_W_BestCalc);
   inputTree->SetBranchAddress("Njets_Z_BestCalc", &Njets_Z_BestCalc, &b_Njets_Z_BestCalc);
   inputTree->SetBranchAddress("Njets_jet_BestCalc", &Njets_jet_BestCalc, &b_Njets_jet_BestCalc);
   inputTree->SetBranchAddress("Njets_orig_BestCalc", &Njets_orig_BestCalc, &b_Njets_orig_BestCalc);
   inputTree->SetBranchAddress("Njets_top_BestCalc", &Njets_top_BestCalc, &b_Njets_top_BestCalc);
   inputTree->SetBranchAddress("SDmass_BestCalc", &SDmass_BestCalc, &b_SDmass_BestCalc);
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
   inputTree->SetBranchAddress("aplanarityH_BestCalc", &aplanarityH_BestCalc, &b_aplanarityH_BestCalc);
   inputTree->SetBranchAddress("aplanarityW_BestCalc", &aplanarityW_BestCalc, &b_aplanarityW_BestCalc);
   inputTree->SetBranchAddress("aplanarityZ_BestCalc", &aplanarityZ_BestCalc, &b_aplanarityZ_BestCalc);
   inputTree->SetBranchAddress("aplanaritytop_BestCalc", &aplanaritytop_BestCalc, &b_aplanaritytop_BestCalc);
   inputTree->SetBranchAddress("bDisc1_BestCalc", &bDisc1_BestCalc, &b_bDisc1_BestCalc);
   inputTree->SetBranchAddress("bDisc2_BestCalc", &bDisc2_BestCalc, &b_bDisc2_BestCalc);
   inputTree->SetBranchAddress("bDisc_BestCalc", &bDisc_BestCalc, &b_bDisc_BestCalc);
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
   inputTree->SetBranchAddress("decorr_H_DeepAK8Calc", &decorr_H_DeepAK8Calc, &b_decorr_H_DeepAK8Calc);
   inputTree->SetBranchAddress("decorr_J_DeepAK8Calc", &decorr_J_DeepAK8Calc, &b_decorr_J_DeepAK8Calc);
   inputTree->SetBranchAddress("decorr_T_DeepAK8Calc", &decorr_T_DeepAK8Calc, &b_decorr_T_DeepAK8Calc);
   inputTree->SetBranchAddress("decorr_W_DeepAK8Calc", &decorr_W_DeepAK8Calc, &b_decorr_W_DeepAK8Calc);
   inputTree->SetBranchAddress("decorr_Z_DeepAK8Calc", &decorr_Z_DeepAK8Calc, &b_decorr_Z_DeepAK8Calc);
   inputTree->SetBranchAddress("dnn_B_DeepAK8Calc", &dnn_B_DeepAK8Calc, &b_dnn_B_DeepAK8Calc);
   inputTree->SetBranchAddress("dnn_B_BestCalc", &dnn_B_BestCalc, &b_dnn_B_BestCalc);
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
   inputTree->SetBranchAddress("elIsLooseBarrel_singleLepCalc", &elIsLooseBarrel_singleLepCalc, &b_elIsLooseBarrel_singleLepCalc);
   inputTree->SetBranchAddress("elIsLooseEndCap_singleLepCalc", &elIsLooseEndCap_singleLepCalc, &b_elIsLooseEndCap_singleLepCalc);
   inputTree->SetBranchAddress("elIsMediumBarrel_singleLepCalc", &elIsMediumBarrel_singleLepCalc, &b_elIsMediumBarrel_singleLepCalc);
   inputTree->SetBranchAddress("elIsMediumEndCap_singleLepCalc", &elIsMediumEndCap_singleLepCalc, &b_elIsMediumEndCap_singleLepCalc);
   inputTree->SetBranchAddress("elIsTightBarrel_singleLepCalc", &elIsTightBarrel_singleLepCalc, &b_elIsTightBarrel_singleLepCalc);
   inputTree->SetBranchAddress("elIsTightEndCap_singleLepCalc", &elIsTightEndCap_singleLepCalc, &b_elIsTightEndCap_singleLepCalc);
   inputTree->SetBranchAddress("elIsVetoBarrel_singleLepCalc", &elIsVetoBarrel_singleLepCalc, &b_elIsVetoBarrel_singleLepCalc);
   inputTree->SetBranchAddress("elIsVetoEndCap_singleLepCalc", &elIsVetoEndCap_singleLepCalc, &b_elIsVetoEndCap_singleLepCalc);
   inputTree->SetBranchAddress("elMVAValue_iso_singleLepCalc", &elMVAValue_iso_singleLepCalc, &b_elMVAValue_iso_singleLepCalc);
   inputTree->SetBranchAddress("elMVAValue_singleLepCalc", &elMVAValue_singleLepCalc, &b_elMVAValue_singleLepCalc);
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
   inputTree->SetBranchAddress("et_BestCalc", &et_BestCalc, &b_et_BestCalc);
   inputTree->SetBranchAddress("eta_BestCalc", &eta_BestCalc, &b_eta_BestCalc);
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
   inputTree->SetBranchAddress("isotropyH_BestCalc", &isotropyH_BestCalc, &b_isotropyH_BestCalc);
   inputTree->SetBranchAddress("isotropyW_BestCalc", &isotropyW_BestCalc, &b_isotropyW_BestCalc);
   inputTree->SetBranchAddress("isotropyZ_BestCalc", &isotropyZ_BestCalc, &b_isotropyZ_BestCalc);
   inputTree->SetBranchAddress("isotropytop_BestCalc", &isotropytop_BestCalc, &b_isotropytop_BestCalc);
   inputTree->SetBranchAddress("m1234H_BestCalc", &m1234H_BestCalc, &b_m1234H_BestCalc);
   inputTree->SetBranchAddress("m1234W_BestCalc", &m1234W_BestCalc, &b_m1234W_BestCalc);
   inputTree->SetBranchAddress("m1234Z_BestCalc", &m1234Z_BestCalc, &b_m1234Z_BestCalc);
   inputTree->SetBranchAddress("m1234_jet_BestCalc", &m1234_jet_BestCalc, &b_m1234_jet_BestCalc);
   inputTree->SetBranchAddress("m1234top_BestCalc", &m1234top_BestCalc, &b_m1234top_BestCalc);
   inputTree->SetBranchAddress("m12H_BestCalc", &m12H_BestCalc, &b_m12H_BestCalc);
   inputTree->SetBranchAddress("m12W_BestCalc", &m12W_BestCalc, &b_m12W_BestCalc);
   inputTree->SetBranchAddress("m12Z_BestCalc", &m12Z_BestCalc, &b_m12Z_BestCalc);
   inputTree->SetBranchAddress("m12_jet_BestCalc", &m12_jet_BestCalc, &b_m12_jet_BestCalc);
   inputTree->SetBranchAddress("m12top_BestCalc", &m12top_BestCalc, &b_m12top_BestCalc);
   inputTree->SetBranchAddress("m13H_BestCalc", &m13H_BestCalc, &b_m13H_BestCalc);
   inputTree->SetBranchAddress("m13W_BestCalc", &m13W_BestCalc, &b_m13W_BestCalc);
   inputTree->SetBranchAddress("m13Z_BestCalc", &m13Z_BestCalc, &b_m13Z_BestCalc);
   inputTree->SetBranchAddress("m13_jet_BestCalc", &m13_jet_BestCalc, &b_m13_jet_BestCalc);
   inputTree->SetBranchAddress("m13top_BestCalc", &m13top_BestCalc, &b_m13top_BestCalc);
   inputTree->SetBranchAddress("m23H_BestCalc", &m23H_BestCalc, &b_m23H_BestCalc);
   inputTree->SetBranchAddress("m23W_BestCalc", &m23W_BestCalc, &b_m23W_BestCalc);
   inputTree->SetBranchAddress("m23Z_BestCalc", &m23Z_BestCalc, &b_m23Z_BestCalc);
   inputTree->SetBranchAddress("m23_jet_BestCalc", &m23_jet_BestCalc, &b_m23_jet_BestCalc);
   inputTree->SetBranchAddress("m23top_BestCalc", &m23top_BestCalc, &b_m23top_BestCalc);
   inputTree->SetBranchAddress("mass_BestCalc", &mass_BestCalc, &b_mass_BestCalc);
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
   inputTree->SetBranchAddress("pzOverp_H_BestCalc", &pzOverp_H_BestCalc, &b_pzOverp_H_BestCalc);
   inputTree->SetBranchAddress("pzOverp_W_BestCalc", &pzOverp_W_BestCalc, &b_pzOverp_W_BestCalc);
   inputTree->SetBranchAddress("pzOverp_Z_BestCalc", &pzOverp_Z_BestCalc, &b_pzOverp_Z_BestCalc);
   inputTree->SetBranchAddress("pzOverp_jet_BestCalc", &pzOverp_jet_BestCalc, &b_pzOverp_jet_BestCalc);
   inputTree->SetBranchAddress("pzOverp_top_BestCalc", &pzOverp_top_BestCalc, &b_pzOverp_top_BestCalc);
   inputTree->SetBranchAddress("q_BestCalc", &q_BestCalc, &b_q_BestCalc);
   inputTree->SetBranchAddress("quarkEnergy_TpTpCalc", &quarkEnergy_TpTpCalc, &b_quarkEnergy_TpTpCalc);
   inputTree->SetBranchAddress("quarkEta_TpTpCalc", &quarkEta_TpTpCalc, &b_quarkEta_TpTpCalc);
   inputTree->SetBranchAddress("quarkPhi_TpTpCalc", &quarkPhi_TpTpCalc, &b_quarkPhi_TpTpCalc);
   inputTree->SetBranchAddress("quarkPt_TpTpCalc", &quarkPt_TpTpCalc, &b_quarkPt_TpTpCalc);
   inputTree->SetBranchAddress("sphericityH_BestCalc", &sphericityH_BestCalc, &b_sphericityH_BestCalc);
   inputTree->SetBranchAddress("sphericityW_BestCalc", &sphericityW_BestCalc, &b_sphericityW_BestCalc);
   inputTree->SetBranchAddress("sphericityZ_BestCalc", &sphericityZ_BestCalc, &b_sphericityZ_BestCalc);
   inputTree->SetBranchAddress("sphericitytop_BestCalc", &sphericitytop_BestCalc, &b_sphericitytop_BestCalc);
   inputTree->SetBranchAddress("tPrimeEnergy_TpTpCalc", &tPrimeEnergy_TpTpCalc, &b_tPrimeEnergy_TpTpCalc);
   inputTree->SetBranchAddress("tPrimeEta_TpTpCalc", &tPrimeEta_TpTpCalc, &b_tPrimeEta_TpTpCalc);
   inputTree->SetBranchAddress("tPrimeMass_TpTpCalc", &tPrimeMass_TpTpCalc, &b_tPrimeMass_TpTpCalc);
   inputTree->SetBranchAddress("tPrimePhi_TpTpCalc", &tPrimePhi_TpTpCalc, &b_tPrimePhi_TpTpCalc);
   inputTree->SetBranchAddress("tPrimePt_TpTpCalc", &tPrimePt_TpTpCalc, &b_tPrimePt_TpTpCalc);
   inputTree->SetBranchAddress("tau21_BestCalc", &tau21_BestCalc, &b_tau21_BestCalc);
   inputTree->SetBranchAddress("tau32_BestCalc", &tau32_BestCalc, &b_tau32_BestCalc);
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
   inputTree->SetBranchAddress("theJetAK8SDSubjetBTag_JetSubCalc", &theJetAK8SDSubjetBTag_JetSubCalc, &b_theJetAK8SDSubjetBTag_JetSubCalc);
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
   inputTree->SetBranchAddress("theJetCSVb_JetSubCalc", &theJetCSVb_JetSubCalc, &b_theJetCSVb_JetSubCalc);
   inputTree->SetBranchAddress("theJetCSVbb_JetSubCalc", &theJetCSVbb_JetSubCalc, &b_theJetCSVbb_JetSubCalc);
   //inputTree->SetBranchAddress("theJetCSVc_JetSubCalc", &theJetCSVc_JetSubCalc, &b_theJetCSVc_JetSubCalc);
   //inputTree->SetBranchAddress("theJetCSVudsg_JetSubCalc", &theJetCSVudsg_JetSubCalc, &b_theJetCSVudsg_JetSubCalc);
   inputTree->SetBranchAddress("theJetEnergy_JetSubCalc", &theJetEnergy_JetSubCalc, &b_theJetEnergy_JetSubCalc);
   inputTree->SetBranchAddress("theJetEta_JetSubCalc", &theJetEta_JetSubCalc, &b_theJetEta_JetSubCalc);
   inputTree->SetBranchAddress("theJetPhi_JetSubCalc", &theJetPhi_JetSubCalc, &b_theJetPhi_JetSubCalc);
   inputTree->SetBranchAddress("theJetPileupJetId_JetSubCalc", &theJetPileupJetId_JetSubCalc, &b_theJetPileupJetId_JetSubCalc);
   inputTree->SetBranchAddress("theJetPt_JetSubCalc", &theJetPt_JetSubCalc, &b_theJetPt_JetSubCalc);
   inputTree->SetBranchAddress("thrustH_BestCalc", &thrustH_BestCalc, &b_thrustH_BestCalc);
   inputTree->SetBranchAddress("thrustW_BestCalc", &thrustW_BestCalc, &b_thrustW_BestCalc);
   inputTree->SetBranchAddress("thrustZ_BestCalc", &thrustZ_BestCalc, &b_thrustZ_BestCalc);
   inputTree->SetBranchAddress("thrusttop_BestCalc", &thrusttop_BestCalc, &b_thrusttop_BestCalc);
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
#endif // #ifdef step1_cxx
