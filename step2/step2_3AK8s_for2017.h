//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Nov  3 15:29:03 2018 by ROOT version 6.10/09
// from TTree ljmet/ljmet
// found on file: root://cmseos.fnal.gov//store/user/lpcljm/2018/LJMet94X_1lepTT_101118newB_step1hadds/nominal/WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root
//////////////////////////////////////////////////////////

#ifndef step2_h
#define step2_h

#include <iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class step2 {
public :
   TTree          *inputTree;   //!pointer to the analyzed TTree or TChain
   TFile          *inputFile, *outputFile;
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   Bool_t          isMC;
   Bool_t          isSig;
   Bool_t          isTT;
   Int_t           SigMass;

   // Declaration of leaf types
   Long64_t        event_CommonCalc;
   Int_t           run_CommonCalc;
   Int_t           lumi_CommonCalc;
   Int_t           nTrueInteractions_MultiLepCalc;
   Int_t           isElectron;
   Int_t           isMuon;
   Int_t           MCPastTrigger;
   Int_t           DataPastTrigger;
   Double_t        L1NonPrefiringProb_CommonCalc;
   Double_t        L1NonPrefiringProbUp_CommonCalc;
   Double_t        L1NonPrefiringProbDown_CommonCalc;
   Bool_t          isTHBW_TpTpCalc;
   Bool_t          isTHTH_TpTpCalc;
   Bool_t          isBWBW_TpTpCalc;
   Bool_t          isTZBW_TpTpCalc;
   Bool_t          isTZTH_TpTpCalc;
   Bool_t          isTZTZ_TpTpCalc;
   Bool_t          isBHTW_TpTpCalc;
   Bool_t          isBHBH_TpTpCalc;
   Bool_t          isTWTW_TpTpCalc;
   Bool_t          isBZTW_TpTpCalc;
   Bool_t          isBZBH_TpTpCalc;
   Bool_t          isBZBZ_TpTpCalc;
   Bool_t          tPrimePt_TpTpCalc;
   Int_t           NLeptonDecays_TpTpCalc;
   Double_t        MCWeight_MultiLepCalc;
   vector<double>  *renormWeights;
   vector<double>  *pdfWeights;
   vector<double>  *pdfWeights4LHC;
   vector<double>  *pdfWeightsMSTW;
   vector<double>  *pdfNewWeights;
   Float_t         pdfNewNominalWeight;
   Float_t         pileupWeight;
   Float_t         pileupWeightUp;
   Float_t         pileupWeightDown;
   Float_t         HTSF_Pol;
   Float_t         HTSF_PolUp;
   Float_t         HTSF_PolDn;
   Float_t         topPtWeight13TeV;
   Float_t         EGammaGsfSF;
   Float_t         lepIdSF;
   Float_t         isoSF;
   Float_t         triggerSF;
   Float_t         triggerSFUncert;
   Float_t         muPtSF;
   Double_t        ttbarMass_TTbarMassCalc;
   Float_t         genTopPt;
   Float_t         genAntiTopPt;
   Double_t        corr_met_MultiLepCalc;
   Double_t        corr_met_phi_MultiLepCalc;
   Double_t        corr_metmod_MultiLepCalc;
   Double_t        corr_metmod_phi_MultiLepCalc;
   Float_t         leptonPt_MultiLepCalc;
   Float_t         leptonEta_MultiLepCalc;
   Float_t         leptonPhi_MultiLepCalc;
   Float_t         leptonEnergy_MultiLepCalc;
   Float_t         leptonMVAValue_MultiLepCalc;
   Float_t         leptonMiniIso_MultiLepCalc;
   Float_t         MT_lepMet;
   Float_t         MT_lepMetmod;
   Float_t         minDPhi_MetJet;
   vector<double>  *theJetPt_JetSubCalc_PtOrdered;
   vector<double>  *theJetEta_JetSubCalc_PtOrdered;
   vector<double>  *theJetPhi_JetSubCalc_PtOrdered;
   vector<double>  *theJetEnergy_JetSubCalc_PtOrdered;
   vector<double>  *AK4JetDeepCSVb_MultiLepCalc_PtOrdered;
   vector<double>  *AK4JetDeepCSVbb_MultiLepCalc_PtOrdered;
   vector<double>  *AK4JetDeepFlavb_MultiLepCalc_PtOrdered;
   vector<double>  *AK4JetDeepFlavbb_MultiLepCalc_PtOrdered;
   vector<double>  *AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered;
   vector<int>     *theJetHFlav_JetSubCalc_PtOrdered;
   vector<int>     *theJetPFlav_JetSubCalc_PtOrdered;
   vector<int>     *theJetBTag_JetSubCalc_PtOrdered;
   vector<int>     *theJetBTagDeepCSV_JetSubCalc_PtOrdered;
   Float_t         AK4HTpMETpLepPt;
   Float_t         AK4HT;
   Int_t           NJets_JetSubCalc;
   Int_t           NJetsDeepFlav_JetSubCalc;
   Int_t           NJetsDeepCSV_JetSubCalc;
   Int_t           NJetsDeepFlavwithSF_JetSubCalc;
   Int_t           NJetsDeepCSVwithSF_JetSubCalc;
   Float_t         deltaR_lepMinMlb;
   Float_t         deltaR_lepMinMlj;
   Float_t         minMleppBjet;
   Float_t         minMleppJet;
   Float_t         minDR_lepJet;
   Float_t         ptRel_lepJet;
   vector<double>  *deltaR_lepJets;
   vector<double>  *deltaR_lepBJets;
   vector<int>     *HadronicVHtID_JetSubCalc;
   vector<double>  *HadronicVHtPt_JetSubCalc;
   vector<double>  *HadronicVHtEta_JetSubCalc;
   vector<double>  *HadronicVHtPhi_JetSubCalc;
   vector<double>  *HadronicVHtEnergy_JetSubCalc;
   vector<int>     *theJetAK8Wmatch_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8Tmatch_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8Zmatch_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8Hmatch_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8MatchedPt_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8Truth_JetSubCalc_PtOrdered;
   Int_t           NJetsAK8_JetSubCalc;
   vector<double>  *theJetAK8Pt_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8Eta_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8Phi_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8Mass_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8Energy_JetSubCalc_PtOrdered;
   Float_t         minDR_leadAK8otherAK8;
   Float_t         minDR_lepAK8;
   Float_t         ptRel_lepAK8;
   vector<double>  *deltaR_lepAK8s;
   vector<int>     *maxProb_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8SoftDropRaw_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8SoftDropCorr_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8DoubleB_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8SoftDrop_PtOrdered;
   vector<double>  *theJetAK8NjettinessTau1_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8NjettinessTau2_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8NjettinessTau3_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8CHSTau1_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8CHSTau2_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8CHSTau3_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8SDSubjetSize_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered;
   vector<int>     *dnn_largest_DeepAK8Calc_PtOrdered;
   vector<double>  *dnn_B_DeepAK8Calc_PtOrdered;
   vector<double>  *dnn_J_DeepAK8Calc_PtOrdered;
   vector<double>  *dnn_W_DeepAK8Calc_PtOrdered;
   vector<double>  *dnn_Z_DeepAK8Calc_PtOrdered;
   vector<double>  *dnn_H_DeepAK8Calc_PtOrdered;
   vector<double>  *dnn_T_DeepAK8Calc_PtOrdered;
   Float_t         probSum_DeepAK8_decay;
   Float_t         probSum_DeepAK8_all;
   Float_t         probSum_DeepAK8_four;
   Int_t           nB_DeepAK8;
   Int_t           nH_DeepAK8;
   Int_t           nJ_DeepAK8;
   Int_t           nT_DeepAK8;
   Int_t           nW_DeepAK8;
   Int_t           nZ_DeepAK8;
   Float_t         DeepAK8SF_TeffUp;
   Float_t         DeepAK8SF_HeffUp;
   Float_t         DeepAK8SF_ZeffUp;
   Float_t         DeepAK8SF_WeffUp;
   Float_t         DeepAK8SF_BeffUp;
   Float_t         DeepAK8SF_JeffUp;
   Float_t         DeepAK8SF_TmisUp;
   Float_t         DeepAK8SF_HmisUp;
   Float_t         DeepAK8SF_ZmisUp;
   Float_t         DeepAK8SF_WmisUp;
   Float_t         DeepAK8SF_BmisUp;
   Float_t         DeepAK8SF_JmisUp;
   Float_t         DeepAK8SF_TeffDn;
   Float_t         DeepAK8SF_HeffDn;
   Float_t         DeepAK8SF_ZeffDn;
   Float_t         DeepAK8SF_WeffDn;
   Float_t         DeepAK8SF_BeffDn;
   Float_t         DeepAK8SF_JeffDn;
   Float_t         DeepAK8SF_TmisDn;
   Float_t         DeepAK8SF_HmisDn;
   Float_t         DeepAK8SF_ZmisDn;
   Float_t         DeepAK8SF_WmisDn;
   Float_t         DeepAK8SF_BmisDn;
   Float_t         DeepAK8SF_JmisDn;
   Float_t         W_mass;
   Float_t         W_pt;
   Float_t         W_dRLep;
   Float_t         t_mass;
   Float_t         t_pt;
   Float_t         t_dRWb;
   vector<double>  *deltaR_leptonicparticle_AK8_PtOrdered;
   Bool_t          isLeptonic_t;
   Bool_t          isLeptonic_W;
   Float_t         Tprime1_DeepAK8_Mass;
   Float_t         Tprime2_DeepAK8_Mass;
   Float_t         Tprime1_DeepAK8_Pt;
   Float_t         Tprime2_DeepAK8_Pt;
   Float_t         Tprime1_DeepAK8_Eta;
   Float_t         Tprime2_DeepAK8_Eta;
   Float_t         Tprime1_DeepAK8_Phi;
   Float_t         Tprime2_DeepAK8_Phi;
   Float_t         Tprime1_DeepAK8_deltaR;
   Float_t         Tprime2_DeepAK8_deltaR;
   Bool_t          isValidTTDecayMode_DeepAK8;
   Bool_t          taggedBWBW_DeepAK8;
   Bool_t          taggedTHBW_DeepAK8;
   Bool_t          taggedTHTH_DeepAK8;
   Bool_t          taggedTZBW_DeepAK8;
   Bool_t          taggedTZTH_DeepAK8;
   Bool_t          taggedTZTZ_DeepAK8;
   Float_t         highPtAK8Jet1_SoftDropCorrectedMass;
   Float_t         highPtAK8Jet2_SoftDropCorrectedMass;
   Float_t         highPtAK8Jet3_SoftDropCorrectedMass;
   vector<int>     *leptonicTprimeJetIDs_DeepAK8;
   vector<int>     *hadronicTprimeJetIDs_DeepAK8;
   Float_t         Bprime1_DeepAK8_Mass;
   Float_t         Bprime2_DeepAK8_Mass;
   Float_t         Bprime1_DeepAK8_Pt;
   Float_t         Bprime2_DeepAK8_Pt;
   Float_t         Bprime1_DeepAK8_Eta;
   Float_t         Bprime2_DeepAK8_Eta;
   Float_t         Bprime1_DeepAK8_Phi;
   Float_t         Bprime2_DeepAK8_Phi;
   Float_t         Bprime1_DeepAK8_deltaR;
   Float_t         Bprime2_DeepAK8_deltaR;
   Bool_t          isValidBBDecayMode_DeepAK8;
   Bool_t          taggedTWTW_DeepAK8;
   Bool_t          taggedBHTW_DeepAK8;
   Bool_t          taggedBZTW_DeepAK8;
   vector<int>     *leptonicBprimeJetIDs_DeepAK8;
   vector<int>     *hadronicBprimeJetIDs_DeepAK8;
   Float_t         dnn_WJets;
   Float_t         dnn_ttbar;
   Float_t         dnn_Tprime;
   Float_t         dnn_WJetsBB;
   Float_t         dnn_ttbarBB;
   Float_t         dnn_Bprime;

   // List of branches
   TBranch        *b_event_CommonCalc;   //!
   TBranch        *b_run_CommonCalc;   //!
   TBranch        *b_lumi_CommonCalc;   //!
   TBranch        *b_nTrueInteractions_MultiLepCalc;   //!
   TBranch        *b_isElectron;   //!
   TBranch        *b_isMuon;   //!
   TBranch        *b_MCPastTrigger;   //!
   TBranch        *b_DataPastTrigger;   //!
   TBranch        *b_L1NonPrefiringProb_CommonCalc;   //!
   TBranch        *b_L1NonPrefiringProbUp_CommonCalc;   //!
   TBranch        *b_L1NonPrefiringProbDown_CommonCalc;   //!
   TBranch        *b_isTHBW_TpTpCalc;   //!
   TBranch        *b_isTHTH_TpTpCalc;   //!
   TBranch        *b_isBWBW_TpTpCalc;   //!
   TBranch        *b_isTZBW_TpTpCalc;   //!
   TBranch        *b_isTZTH_TpTpCalc;   //!
   TBranch        *b_isTZTZ_TpTpCalc;   //!
   TBranch        *b_isBHTW_TpTpCalc;   //!
   TBranch        *b_isBHBH_TpTpCalc;   //!
   TBranch        *b_isTWTW_TpTpCalc;   //!
   TBranch        *b_isBZTW_TpTpCalc;   //!
   TBranch        *b_isBZBH_TpTpCalc;   //!
   TBranch        *b_isBZBZ_TpTpCalc;   //!
   TBranch        *b_tPrimePt_TpTpCalc;   //!
   TBranch        *b_NLeptonDecays_TpTpCalc;   //!
   TBranch        *b_MCWeight_MultiLepCalc;   //!
   TBranch        *b_renormWeights;   //!
   TBranch        *b_pdfWeights;   //!
   TBranch        *b_pdfWeights4LHC;   //!
   TBranch        *b_pdfWeightsMSTW;   //!
   TBranch        *b_pdfNewWeights;   //!
   TBranch        *b_pdfNewNominalWeight;   //!
   TBranch        *b_pileupWeight;   //!
   TBranch        *b_pileupWeightUp;   //!
   TBranch        *b_pileupWeightDown;   //!
   TBranch        *b_HTSF_Pol;   //!
   TBranch        *b_HTSF_PolUp;   //!
   TBranch        *b_HTSF_PolDn;   //!
   TBranch        *b_topPtWeight13TeV;   //!
   TBranch        *b_EGammaGsfSF;   //!
   TBranch        *b_lepIdSF;   //!
   TBranch        *b_isoSF;   //!
   TBranch        *b_triggerSF;   //!
   TBranch        *b_triggerSFUncert;   //!
   TBranch        *b_muPtSF;   //!
   TBranch        *b_ttbarMass_TTbarMassCalc;   //!
   TBranch        *b_genTopPt;   //!
   TBranch        *b_genAntiTopPt;   //!
   TBranch        *b_corr_met_MultiLepCalc;   //!
   TBranch        *b_corr_met_phi_MultiLepCalc;   //!
   TBranch        *b_corr_metmod_MultiLepCalc;   //!
   TBranch        *b_corr_metmod_phi_MultiLepCalc;   //!
   TBranch        *b_leptonPt_MultiLepCalc;   //!
   TBranch        *b_leptonEta_MultiLepCalc;   //!
   TBranch        *b_leptonPhi_MultiLepCalc;   //!
   TBranch        *b_leptonEnergy_MultiLepCalc;   //!
   TBranch        *b_leptonMVAValue_MultiLepCalc;   //!
   TBranch        *b_leptonMiniIso_MultiLepCalc;   //!
   TBranch        *b_MT_lepMet;   //!
   TBranch        *b_MT_lepMetmod;   //!
   TBranch        *b_minDPhi_MetJet;   //!
   TBranch        *b_theJetPt_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetEta_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetPhi_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetEnergy_JetSubCalc_PtOrdered;   //!
   TBranch        *b_AK4JetDeepCSVb_MultiLepCalc_PtOrdered;   //!
   TBranch        *b_AK4JetDeepCSVbb_MultiLepCalc_PtOrdered;   //!
   TBranch        *b_AK4JetDeepFlavb_MultiLepCalc_PtOrdered;   //!
   TBranch        *b_AK4JetDeepFlavbb_MultiLepCalc_PtOrdered;   //!
   TBranch        *b_AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered;   //!
   TBranch        *b_theJetHFlav_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetPFlav_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetBTag_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetBTagDeepCSV_JetSubCalc_PtOrdered;   //!
   TBranch        *b_AK4HTpMETpLepPt;   //!
   TBranch        *b_AK4HT;   //!
   TBranch        *b_NJets_JetSubCalc;   //!
   TBranch        *b_NJetsDeepFlav_JetSubCalc;   //!
   TBranch        *b_NJetsDeepCSV_JetSubCalc;   //!
   TBranch        *b_NJetsDeepFlavwithSF_JetSubCalc;   //!
   TBranch        *b_NJetsDeepCSVwithSF_JetSubCalc;   //!
   TBranch        *b_deltaR_lepMinMlb;   //!
   TBranch        *b_deltaR_lepMinMlj;   //!
   TBranch        *b_minMleppBjet;   //!
   TBranch        *b_minMleppJet;   //!
   TBranch        *b_minDR_lepJet;   //!
   TBranch        *b_ptRel_lepJet;   //!
   TBranch        *b_deltaR_lepJets;   //!
   TBranch        *b_deltaR_lepBJets;   //!
   TBranch        *b_HadronicVHtID_JetSubCalc;   //!
   TBranch        *b_HadronicVHtPt_JetSubCalc;   //!
   TBranch        *b_HadronicVHtEta_JetSubCalc;   //!
   TBranch        *b_HadronicVHtPhi_JetSubCalc;   //!
   TBranch        *b_HadronicVHtEnergy_JetSubCalc;   //!
   TBranch        *b_theJetAK8Wmatch_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Tmatch_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Zmatch_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Hmatch_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8MatchedPt_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Truth_JetSubCalc_PtOrdered;   //!
   TBranch        *b_NJetsAK8_JetSubCalc;   //!
   TBranch        *b_theJetAK8Pt_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Eta_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Phi_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Mass_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Energy_JetSubCalc_PtOrdered;   //!
   TBranch        *b_minDR_leadAK8otherAK8;   //!
   TBranch        *b_minDR_lepAK8;   //!
   TBranch        *b_ptRel_lepAK8;   //!
   TBranch        *b_deltaR_lepAK8s;   //!
   TBranch        *b_maxProb_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8SoftDropRaw_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8SoftDropCorr_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8DoubleB_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8SoftDrop_PtOrdered;   //!
   TBranch        *b_theJetAK8NjettinessTau1_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8NjettinessTau2_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8NjettinessTau3_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8CHSTau1_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8CHSTau2_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8CHSTau3_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8SDSubjetSize_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered;   //!
   TBranch        *b_dnn_largest_DeepAK8Calc_PtOrdered;   //!
   TBranch        *b_dnn_B_DeepAK8Calc_PtOrdered;   //!
   TBranch        *b_dnn_J_DeepAK8Calc_PtOrdered;   //!
   TBranch        *b_dnn_W_DeepAK8Calc_PtOrdered;   //!
   TBranch        *b_dnn_Z_DeepAK8Calc_PtOrdered;   //!
   TBranch        *b_dnn_H_DeepAK8Calc_PtOrdered;   //!
   TBranch        *b_dnn_T_DeepAK8Calc_PtOrdered;   //!
   TBranch        *b_probSum_DeepAK8_decay;   //!
   TBranch        *b_probSum_DeepAK8_all;   //!
   TBranch        *b_probSum_DeepAK8_four;   //!
   TBranch        *b_nB_DeepAK8;   //!
   TBranch        *b_nH_DeepAK8;   //!
   TBranch        *b_nJ_DeepAK8;   //!
   TBranch        *b_nT_DeepAK8;   //!
   TBranch        *b_nW_DeepAK8;   //!
   TBranch        *b_nZ_DeepAK8;   //!
   TBranch        *b_DeepAK8SF_TeffUp;   //!
   TBranch        *b_DeepAK8SF_HeffUp;   //!
   TBranch        *b_DeepAK8SF_ZeffUp;   //!
   TBranch        *b_DeepAK8SF_WeffUp;   //!
   TBranch        *b_DeepAK8SF_BeffUp;   //!
   TBranch        *b_DeepAK8SF_JeffUp;   //!
   TBranch        *b_DeepAK8SF_TmisUp;   //!
   TBranch        *b_DeepAK8SF_HmisUp;   //!
   TBranch        *b_DeepAK8SF_ZmisUp;   //!
   TBranch        *b_DeepAK8SF_WmisUp;   //!
   TBranch        *b_DeepAK8SF_BmisUp;   //!
   TBranch        *b_DeepAK8SF_JmisUp;   //!
   TBranch        *b_DeepAK8SF_TeffDn;   //!
   TBranch        *b_DeepAK8SF_HeffDn;   //!
   TBranch        *b_DeepAK8SF_ZeffDn;   //!
   TBranch        *b_DeepAK8SF_WeffDn;   //!
   TBranch        *b_DeepAK8SF_BeffDn;   //!
   TBranch        *b_DeepAK8SF_JeffDn;   //!
   TBranch        *b_DeepAK8SF_TmisDn;   //!
   TBranch        *b_DeepAK8SF_HmisDn;   //!
   TBranch        *b_DeepAK8SF_ZmisDn;   //!
   TBranch        *b_DeepAK8SF_WmisDn;   //!
   TBranch        *b_DeepAK8SF_BmisDn;   //!
   TBranch        *b_DeepAK8SF_JmisDn;   //!
   TBranch        *b_W_mass;   //!
   TBranch        *b_W_pt;   //!
   TBranch        *b_W_dRLep;   //!
   TBranch        *b_t_mass;   //!
   TBranch        *b_t_pt;   //!
   TBranch        *b_t_dRWb;   //!
   TBranch        *b_deltaR_leptonicparticle_AK8_PtOrdered;   //!
   TBranch        *b_isLeptonic_t;   //!
   TBranch        *b_isLeptonic_W;   //!
   TBranch        *b_Tprime1_DeepAK8_Mass;   //!
   TBranch        *b_Tprime2_DeepAK8_Mass;   //!
   TBranch        *b_Tprime1_DeepAK8_Pt;   //!
   TBranch        *b_Tprime2_DeepAK8_Pt;   //!
   TBranch        *b_Tprime1_DeepAK8_Eta;   //!
   TBranch        *b_Tprime2_DeepAK8_Eta;   //!
   TBranch        *b_Tprime1_DeepAK8_Phi;   //!
   TBranch        *b_Tprime2_DeepAK8_Phi;   //!
   TBranch        *b_Tprime1_DeepAK8_deltaR;   //!
   TBranch        *b_Tprime2_DeepAK8_deltaR;   //!
   TBranch        *b_validTDecay_DeepAK8;   //!
   TBranch        *b_taggedBWBW_DeepAK8;   //!
   TBranch        *b_taggedTHBW_DeepAK8;   //!
   TBranch        *b_taggedTHTH_DeepAK8;   //!
   TBranch        *b_taggedTZBW_DeepAK8;   //!
   TBranch        *b_taggedTZTH_DeepAK8;   //!
   TBranch        *b_taggedTZTZ_DeepAK8;   //!
   TBranch        *b_highPtAK8Jet1_SoftDropCorrectedMass;   //!
   TBranch        *b_highPtAK8Jet2_SoftDropCorrectedMass;   //!
   TBranch        *b_highPtAK8Jet3_SoftDropCorrectedMass;   //!
   TBranch        *b_leptonicTprimeJetIDs_DeepAK8;   //!
   TBranch        *b_hadronicTprimeJetIDs_DeepAK8;   //!
   TBranch        *b_Bprime1_DeepAK8_Mass;   //!
   TBranch        *b_Bprime2_DeepAK8_Mass;   //!
   TBranch        *b_Bprime1_DeepAK8_Pt;   //!
   TBranch        *b_Bprime2_DeepAK8_Pt;   //!
   TBranch        *b_Bprime1_DeepAK8_Eta;   //!
   TBranch        *b_Bprime2_DeepAK8_Eta;   //!
   TBranch        *b_Bprime1_DeepAK8_Phi;   //!
   TBranch        *b_Bprime2_DeepAK8_Phi;   //!
   TBranch        *b_Bprime1_DeepAK8_deltaR;   //!
   TBranch        *b_Bprime2_DeepAK8_deltaR;   //!
   TBranch        *b_validBDecay_DeepAK8;   //!
   TBranch        *b_taggedTWTW_DeepAK8;   //!
   TBranch        *b_taggedBZTW_DeepAK8;   //!
   TBranch        *b_taggedBHTW_DeepAK8;   //!
   TBranch        *b_leptonicBprimeJetIDs_DeepAK8;   //!
   TBranch        *b_hadronicBprimeJetIDs_DeepAK8;   //!
   TBranch        *b_dnn_WJets;   //!
   TBranch        *b_dnn_ttbar;   //!
   TBranch        *b_dnn_Tprime;   //!
   TBranch        *b_dnn_WJetsBB;   //!
   TBranch        *b_dnn_ttbarBB;   //!
   TBranch        *b_dnn_Bprime;   //!

   step2(TString inputFileName, TString outputFileName);
   virtual ~step2();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(TString inTreeName, TString outTreeName);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef step2_cxx
step2::step2(TString inputFileName, TString outputFileName) : inputTree(0), inputFile(0), outputFile(0) 
{
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
 
  //  cout << "Opening file: " << inputFileName << endl;

  isSig  = inputFileName.Contains("prime");
  if(isSig){
    if(inputFileName.Contains("_M-1100")) SigMass = 11;
    else if(inputFileName.Contains("_M-1800")) SigMass = 18;
    else SigMass = -1;
  }
  isMC = !(inputFileName.Contains("SingleMu") || inputFileName.Contains("SingleEl") || inputFileName.Contains("EGamma"));
  isTT = (inputFileName.Contains("TTTo") || inputFileName.Contains("Mtt"));  

  std::cout<<"Opening file: "<<inputFileName<<std::endl;
  if(!(inputFile=TFile::Open(inputFileName))){
    std::cout<<"WARNING! File doesn't exist! Exiting" << std::endl;
    exit(1);
  }
  //inputTree=(TTree*)inputFile->Get("ljmet");
  //  if(inputTree->GetEntries()==0) cout << "WARNING! Found 0 events in the tree!!!!" << endl;
  
  outputFile=new TFile(outputFileName,"RECREATE");
  
  //Init(inputTree);
}

step2::~step2()
{
   if (!inputTree) return;
   delete inputTree->GetCurrentFile();
}

Int_t step2::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!inputTree) return 0;
   return inputTree->GetEntry(entry);
}
Long64_t step2::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!inputTree) return -5;
   Long64_t centry = inputTree->LoadTree(entry);
   if (centry < 0) return centry;
   if (inputTree->GetTreeNumber() != fCurrent) {
      fCurrent = inputTree->GetTreeNumber();
      Notify();
   }
   return centry;
}

void step2::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   renormWeights = 0;
   pdfWeights = 0;
   pdfWeights4LHC = 0;
   pdfWeightsMSTW = 0;
   pdfNewWeights = 0;
   theJetPt_JetSubCalc_PtOrdered = 0;
   theJetEta_JetSubCalc_PtOrdered = 0;
   theJetPhi_JetSubCalc_PtOrdered = 0;
   theJetEnergy_JetSubCalc_PtOrdered = 0;
   AK4JetDeepCSVb_MultiLepCalc_PtOrdered = 0;
   AK4JetDeepCSVbb_MultiLepCalc_PtOrdered = 0;
   AK4JetDeepFlavb_MultiLepCalc_PtOrdered = 0;
   AK4JetDeepFlavbb_MultiLepCalc_PtOrdered = 0;
   AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered = 0;
   theJetHFlav_JetSubCalc_PtOrdered = 0;
   theJetPFlav_JetSubCalc_PtOrdered = 0;
   theJetBTag_JetSubCalc_PtOrdered = 0;
   theJetBTagDeepCSV_JetSubCalc_PtOrdered = 0;
   deltaR_lepJets = 0;
   deltaR_lepBJets = 0;
   HadronicVHtID_JetSubCalc = 0;
   HadronicVHtPt_JetSubCalc = 0;
   HadronicVHtEta_JetSubCalc = 0;
   HadronicVHtPhi_JetSubCalc = 0;
   HadronicVHtEnergy_JetSubCalc = 0;
   theJetAK8Wmatch_JetSubCalc_PtOrdered = 0;
   theJetAK8Tmatch_JetSubCalc_PtOrdered = 0;
   theJetAK8Zmatch_JetSubCalc_PtOrdered = 0;
   theJetAK8Hmatch_JetSubCalc_PtOrdered = 0;
   theJetAK8MatchedPt_JetSubCalc_PtOrdered = 0;
   theJetAK8Truth_JetSubCalc_PtOrdered = 0;
   theJetAK8Pt_JetSubCalc_PtOrdered = 0;
   theJetAK8Eta_JetSubCalc_PtOrdered = 0;
   theJetAK8Phi_JetSubCalc_PtOrdered = 0;
   theJetAK8Mass_JetSubCalc_PtOrdered = 0;
   theJetAK8Energy_JetSubCalc_PtOrdered = 0;
   deltaR_lepAK8s = 0;
   maxProb_JetSubCalc_PtOrdered = 0;
   theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered = 0;
   theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered = 0;
   theJetAK8SoftDropRaw_JetSubCalc_PtOrdered = 0;
   theJetAK8SoftDropCorr_JetSubCalc_PtOrdered = 0;
   theJetAK8DoubleB_JetSubCalc_PtOrdered = 0;
   theJetAK8SoftDrop_PtOrdered = 0;
   theJetAK8NjettinessTau1_JetSubCalc_PtOrdered = 0;
   theJetAK8NjettinessTau2_JetSubCalc_PtOrdered = 0;
   theJetAK8NjettinessTau3_JetSubCalc_PtOrdered = 0;
   theJetAK8CHSTau1_JetSubCalc_PtOrdered = 0;
   theJetAK8CHSTau2_JetSubCalc_PtOrdered = 0;
   theJetAK8CHSTau3_JetSubCalc_PtOrdered = 0;
   theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered = 0;
   theJetAK8SDSubjetSize_JetSubCalc_PtOrdered = 0;
   theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered = 0;
   theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered = 0;
   dnn_largest_DeepAK8Calc_PtOrdered = 0;
   dnn_B_DeepAK8Calc_PtOrdered = 0;
   dnn_J_DeepAK8Calc_PtOrdered = 0;
   dnn_W_DeepAK8Calc_PtOrdered = 0;
   dnn_Z_DeepAK8Calc_PtOrdered = 0;
   dnn_H_DeepAK8Calc_PtOrdered = 0;
   dnn_T_DeepAK8Calc_PtOrdered = 0;
   deltaR_leptonicparticle_AK8_PtOrdered = 0;
   leptonicTprimeJetIDs_DeepAK8 = 0;
   hadronicTprimeJetIDs_DeepAK8 = 0;
   leptonicBprimeJetIDs_DeepAK8 = 0;
   hadronicBprimeJetIDs_DeepAK8 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   inputTree = tree;
   fCurrent = -1;
   inputTree->SetMakeClass(1);

   inputTree->SetBranchAddress("event_CommonCalc", &event_CommonCalc, &b_event_CommonCalc);
   inputTree->SetBranchAddress("run_CommonCalc", &run_CommonCalc, &b_run_CommonCalc);
   inputTree->SetBranchAddress("lumi_CommonCalc", &lumi_CommonCalc, &b_lumi_CommonCalc);
   inputTree->SetBranchAddress("nTrueInteractions_MultiLepCalc", &nTrueInteractions_MultiLepCalc, &b_nTrueInteractions_MultiLepCalc);
   inputTree->SetBranchAddress("isElectron", &isElectron, &b_isElectron);
   inputTree->SetBranchAddress("isMuon", &isMuon, &b_isMuon);
   inputTree->SetBranchAddress("MCPastTrigger", &MCPastTrigger, &b_MCPastTrigger);
   inputTree->SetBranchAddress("DataPastTrigger", &DataPastTrigger, &b_DataPastTrigger);
   inputTree->SetBranchAddress("L1NonPrefiringProb_CommonCalc", &L1NonPrefiringProb_CommonCalc, &b_L1NonPrefiringProb_CommonCalc);
   inputTree->SetBranchAddress("L1NonPrefiringProbUp_CommonCalc", &L1NonPrefiringProbUp_CommonCalc, &b_L1NonPrefiringProbUp_CommonCalc);
   inputTree->SetBranchAddress("L1NonPrefiringProbDown_CommonCalc", &L1NonPrefiringProbDown_CommonCalc, &b_L1NonPrefiringProbDown_CommonCalc);
   inputTree->SetBranchAddress("isTHBW_TpTpCalc", &isTHBW_TpTpCalc, &b_isTHBW_TpTpCalc);
   inputTree->SetBranchAddress("isTHTH_TpTpCalc", &isTHTH_TpTpCalc, &b_isTHTH_TpTpCalc);
   inputTree->SetBranchAddress("isBWBW_TpTpCalc", &isBWBW_TpTpCalc, &b_isBWBW_TpTpCalc);
   inputTree->SetBranchAddress("isTZBW_TpTpCalc", &isTZBW_TpTpCalc, &b_isTZBW_TpTpCalc);
   inputTree->SetBranchAddress("isTZTH_TpTpCalc", &isTZTH_TpTpCalc, &b_isTZTH_TpTpCalc);
   inputTree->SetBranchAddress("isTZTZ_TpTpCalc", &isTZTZ_TpTpCalc, &b_isTZTZ_TpTpCalc);
   inputTree->SetBranchAddress("isBHTW_TpTpCalc", &isBHTW_TpTpCalc, &b_isBHTW_TpTpCalc);
   inputTree->SetBranchAddress("isBHBH_TpTpCalc", &isBHBH_TpTpCalc, &b_isBHBH_TpTpCalc);
   inputTree->SetBranchAddress("isTWTW_TpTpCalc", &isTWTW_TpTpCalc, &b_isTWTW_TpTpCalc);
   inputTree->SetBranchAddress("isBZTW_TpTpCalc", &isBZTW_TpTpCalc, &b_isBZTW_TpTpCalc);
   inputTree->SetBranchAddress("isBZBH_TpTpCalc", &isBZBH_TpTpCalc, &b_isBZBH_TpTpCalc);
   inputTree->SetBranchAddress("isBZBZ_TpTpCalc", &isBZBZ_TpTpCalc, &b_isBZBZ_TpTpCalc);
   inputTree->SetBranchAddress("tPrimePt_TpTpCalc", &tPrimePt_TpTpCalc, &b_tPrimePt_TpTpCalc);
   inputTree->SetBranchAddress("NLeptonDecays_TpTpCalc", &NLeptonDecays_TpTpCalc, &b_NLeptonDecays_TpTpCalc);
   inputTree->SetBranchAddress("MCWeight_MultiLepCalc", &MCWeight_MultiLepCalc, &b_MCWeight_MultiLepCalc);
   inputTree->SetBranchAddress("renormWeights", &renormWeights, &b_renormWeights);
   inputTree->SetBranchAddress("pdfWeights", &pdfWeights, &b_pdfWeights);
   inputTree->SetBranchAddress("pdfWeights4LHC", &pdfWeights4LHC, &b_pdfWeights4LHC);
   inputTree->SetBranchAddress("pdfWeightsMSTW", &pdfWeightsMSTW, &b_pdfWeightsMSTW);
   inputTree->SetBranchAddress("pdfNewWeights", &pdfNewWeights, &b_pdfNewWeights);
   inputTree->SetBranchAddress("pdfNewNominalWeight", &pdfNewNominalWeight, &b_pdfNewNominalWeight);
   inputTree->SetBranchAddress("pileupWeight", &pileupWeight, &b_pileupWeight);
   inputTree->SetBranchAddress("pileupWeightUp", &pileupWeightUp, &b_pileupWeightUp);
   inputTree->SetBranchAddress("pileupWeightDown", &pileupWeightDown, &b_pileupWeightDown);
   inputTree->SetBranchAddress("HTSF_Pol", &HTSF_Pol, &b_HTSF_Pol);
   inputTree->SetBranchAddress("HTSF_PolUp", &HTSF_PolUp, &b_HTSF_PolUp);
   inputTree->SetBranchAddress("HTSF_PolDn", &HTSF_PolDn, &b_HTSF_PolDn);
   inputTree->SetBranchAddress("topPtWeight13TeV", &topPtWeight13TeV, &b_topPtWeight13TeV);
   inputTree->SetBranchAddress("EGammaGsfSF", &EGammaGsfSF, &b_EGammaGsfSF);
   inputTree->SetBranchAddress("lepIdSF", &lepIdSF, &b_lepIdSF);
   inputTree->SetBranchAddress("isoSF", &isoSF, &b_isoSF);
   inputTree->SetBranchAddress("triggerSF", &triggerSF, &b_triggerSF);
   inputTree->SetBranchAddress("triggerSFUncert", &triggerSFUncert, &b_triggerSFUncert);
   inputTree->SetBranchAddress("muPtSF", &muPtSF, &b_muPtSF);
   inputTree->SetBranchAddress("ttbarMass_TTbarMassCalc", &ttbarMass_TTbarMassCalc, &b_ttbarMass_TTbarMassCalc);
   inputTree->SetBranchAddress("genTopPt", &genTopPt, &b_genTopPt);
   inputTree->SetBranchAddress("genAntiTopPt", &genAntiTopPt, &b_genAntiTopPt);
   inputTree->SetBranchAddress("corr_met_MultiLepCalc", &corr_met_MultiLepCalc, &b_corr_met_MultiLepCalc);
   inputTree->SetBranchAddress("corr_met_phi_MultiLepCalc", &corr_met_phi_MultiLepCalc, &b_corr_met_phi_MultiLepCalc);
   inputTree->SetBranchAddress("corr_metmod_MultiLepCalc", &corr_metmod_MultiLepCalc, &b_corr_metmod_MultiLepCalc);
   inputTree->SetBranchAddress("corr_metmod_phi_MultiLepCalc", &corr_metmod_phi_MultiLepCalc, &b_corr_metmod_phi_MultiLepCalc);
   inputTree->SetBranchAddress("leptonPt_MultiLepCalc", &leptonPt_MultiLepCalc, &b_leptonPt_MultiLepCalc);
   inputTree->SetBranchAddress("leptonEta_MultiLepCalc", &leptonEta_MultiLepCalc, &b_leptonEta_MultiLepCalc);
   inputTree->SetBranchAddress("leptonPhi_MultiLepCalc", &leptonPhi_MultiLepCalc, &b_leptonPhi_MultiLepCalc);
   inputTree->SetBranchAddress("leptonEnergy_MultiLepCalc", &leptonEnergy_MultiLepCalc, &b_leptonEnergy_MultiLepCalc);
   inputTree->SetBranchAddress("leptonMVAValue_MultiLepCalc", &leptonMVAValue_MultiLepCalc, &b_leptonMVAValue_MultiLepCalc);
   inputTree->SetBranchAddress("leptonMiniIso_MultiLepCalc", &leptonMiniIso_MultiLepCalc, &b_leptonMiniIso_MultiLepCalc);
   inputTree->SetBranchAddress("MT_lepMet", &MT_lepMet, &b_MT_lepMet);
   inputTree->SetBranchAddress("MT_lepMetmod", &MT_lepMetmod, &b_MT_lepMetmod);
   inputTree->SetBranchAddress("minDPhi_MetJet", &minDPhi_MetJet, &b_minDPhi_MetJet);
   inputTree->SetBranchAddress("theJetPt_JetSubCalc_PtOrdered", &theJetPt_JetSubCalc_PtOrdered, &b_theJetPt_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetEta_JetSubCalc_PtOrdered", &theJetEta_JetSubCalc_PtOrdered, &b_theJetEta_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetPhi_JetSubCalc_PtOrdered", &theJetPhi_JetSubCalc_PtOrdered, &b_theJetPhi_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetEnergy_JetSubCalc_PtOrdered", &theJetEnergy_JetSubCalc_PtOrdered, &b_theJetEnergy_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4JetDeepCSVb_MultiLepCalc_PtOrdered", &AK4JetDeepCSVb_MultiLepCalc_PtOrdered, &b_AK4JetDeepCSVb_MultiLepCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4JetDeepCSVbb_MultiLepCalc_PtOrdered", &AK4JetDeepCSVbb_MultiLepCalc_PtOrdered, &b_AK4JetDeepCSVbb_MultiLepCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4JetDeepFlavb_MultiLepCalc_PtOrdered", &AK4JetDeepFlavb_MultiLepCalc_PtOrdered, &b_AK4JetDeepFlavb_MultiLepCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4JetDeepFlavbb_MultiLepCalc_PtOrdered", &AK4JetDeepFlavbb_MultiLepCalc_PtOrdered, &b_AK4JetDeepFlavbb_MultiLepCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered", &AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered, &b_AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetHFlav_JetSubCalc_PtOrdered", &theJetHFlav_JetSubCalc_PtOrdered, &b_theJetHFlav_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetPFlav_JetSubCalc_PtOrdered", &theJetPFlav_JetSubCalc_PtOrdered, &b_theJetPFlav_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetBTag_JetSubCalc_PtOrdered", &theJetBTag_JetSubCalc_PtOrdered, &b_theJetBTag_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetBTagDeepCSV_JetSubCalc_PtOrdered", &theJetBTagDeepCSV_JetSubCalc_PtOrdered, &b_theJetBTagDeepCSV_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4HTpMETpLepPt", &AK4HTpMETpLepPt, &b_AK4HTpMETpLepPt);
   inputTree->SetBranchAddress("AK4HT", &AK4HT, &b_AK4HT);
   inputTree->SetBranchAddress("NJets_JetSubCalc", &NJets_JetSubCalc, &b_NJets_JetSubCalc);
   inputTree->SetBranchAddress("NJetsDeepFlav_JetSubCalc", &NJetsDeepFlav_JetSubCalc, &b_NJetsDeepFlav_JetSubCalc);
   inputTree->SetBranchAddress("NJetsDeepCSV_JetSubCalc", &NJetsDeepCSV_JetSubCalc, &b_NJetsDeepCSV_JetSubCalc);
   inputTree->SetBranchAddress("NJetsDeepFlavwithSF_JetSubCalc", &NJetsDeepFlavwithSF_JetSubCalc, &b_NJetsDeepFlavwithSF_JetSubCalc);
   inputTree->SetBranchAddress("NJetsDeepCSVwithSF_JetSubCalc", &NJetsDeepCSVwithSF_JetSubCalc, &b_NJetsDeepCSVwithSF_JetSubCalc);
   inputTree->SetBranchAddress("deltaR_lepMinMlb", &deltaR_lepMinMlb, &b_deltaR_lepMinMlb);
   inputTree->SetBranchAddress("deltaR_lepMinMlj", &deltaR_lepMinMlj, &b_deltaR_lepMinMlj);
   inputTree->SetBranchAddress("minMleppBjet", &minMleppBjet, &b_minMleppBjet);
   inputTree->SetBranchAddress("minMleppJet", &minMleppJet, &b_minMleppJet);
   inputTree->SetBranchAddress("minDR_lepJet", &minDR_lepJet, &b_minDR_lepJet);
   inputTree->SetBranchAddress("ptRel_lepJet", &ptRel_lepJet, &b_ptRel_lepJet);
   inputTree->SetBranchAddress("deltaR_lepJets", &deltaR_lepJets, &b_deltaR_lepJets);
   inputTree->SetBranchAddress("deltaR_lepBJets", &deltaR_lepBJets, &b_deltaR_lepBJets);
   inputTree->SetBranchAddress("HadronicVHtID_JetSubCalc", &HadronicVHtID_JetSubCalc, &b_HadronicVHtID_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtPt_JetSubCalc", &HadronicVHtPt_JetSubCalc, &b_HadronicVHtPt_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtEta_JetSubCalc", &HadronicVHtEta_JetSubCalc, &b_HadronicVHtEta_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtPhi_JetSubCalc", &HadronicVHtPhi_JetSubCalc, &b_HadronicVHtPhi_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtEnergy_JetSubCalc", &HadronicVHtEnergy_JetSubCalc, &b_HadronicVHtEnergy_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8Wmatch_JetSubCalc_PtOrdered", &theJetAK8Wmatch_JetSubCalc_PtOrdered, &b_theJetAK8Wmatch_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Tmatch_JetSubCalc_PtOrdered", &theJetAK8Tmatch_JetSubCalc_PtOrdered, &b_theJetAK8Tmatch_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Zmatch_JetSubCalc_PtOrdered", &theJetAK8Zmatch_JetSubCalc_PtOrdered, &b_theJetAK8Zmatch_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Hmatch_JetSubCalc_PtOrdered", &theJetAK8Hmatch_JetSubCalc_PtOrdered, &b_theJetAK8Hmatch_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8MatchedPt_JetSubCalc_PtOrdered", &theJetAK8MatchedPt_JetSubCalc_PtOrdered, &b_theJetAK8MatchedPt_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Truth_JetSubCalc_PtOrdered", &theJetAK8Truth_JetSubCalc_PtOrdered, &b_theJetAK8Truth_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("NJetsAK8_JetSubCalc", &NJetsAK8_JetSubCalc, &b_NJetsAK8_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8Pt_JetSubCalc_PtOrdered", &theJetAK8Pt_JetSubCalc_PtOrdered, &b_theJetAK8Pt_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Eta_JetSubCalc_PtOrdered", &theJetAK8Eta_JetSubCalc_PtOrdered, &b_theJetAK8Eta_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Phi_JetSubCalc_PtOrdered", &theJetAK8Phi_JetSubCalc_PtOrdered, &b_theJetAK8Phi_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Mass_JetSubCalc_PtOrdered", &theJetAK8Mass_JetSubCalc_PtOrdered, &b_theJetAK8Mass_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Energy_JetSubCalc_PtOrdered", &theJetAK8Energy_JetSubCalc_PtOrdered, &b_theJetAK8Energy_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("minDR_leadAK8otherAK8", &minDR_leadAK8otherAK8, &b_minDR_leadAK8otherAK8);
   inputTree->SetBranchAddress("minDR_lepAK8", &minDR_lepAK8, &b_minDR_lepAK8);
   inputTree->SetBranchAddress("ptRel_lepAK8", &ptRel_lepAK8, &b_ptRel_lepAK8);
   inputTree->SetBranchAddress("deltaR_lepAK8s", &deltaR_lepAK8s, &b_deltaR_lepAK8s);
   inputTree->SetBranchAddress("maxProb_JetSubCalc_PtOrdered", &maxProb_JetSubCalc_PtOrdered, &b_maxProb_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered", &theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered, &b_theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered", &theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered, &b_theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SoftDropRaw_JetSubCalc_PtOrdered", &theJetAK8SoftDropRaw_JetSubCalc_PtOrdered, &b_theJetAK8SoftDropRaw_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SoftDropCorr_JetSubCalc_PtOrdered", &theJetAK8SoftDropCorr_JetSubCalc_PtOrdered, &b_theJetAK8SoftDropCorr_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8DoubleB_JetSubCalc_PtOrdered", &theJetAK8DoubleB_JetSubCalc_PtOrdered, &b_theJetAK8DoubleB_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SoftDrop_PtOrdered", &theJetAK8SoftDrop_PtOrdered, &b_theJetAK8SoftDrop_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8NjettinessTau1_JetSubCalc_PtOrdered", &theJetAK8NjettinessTau1_JetSubCalc_PtOrdered, &b_theJetAK8NjettinessTau1_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8NjettinessTau2_JetSubCalc_PtOrdered", &theJetAK8NjettinessTau2_JetSubCalc_PtOrdered, &b_theJetAK8NjettinessTau2_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8NjettinessTau3_JetSubCalc_PtOrdered", &theJetAK8NjettinessTau3_JetSubCalc_PtOrdered, &b_theJetAK8NjettinessTau3_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8CHSTau1_JetSubCalc_PtOrdered", &theJetAK8CHSTau1_JetSubCalc_PtOrdered, &b_theJetAK8CHSTau1_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8CHSTau2_JetSubCalc_PtOrdered", &theJetAK8CHSTau2_JetSubCalc_PtOrdered, &b_theJetAK8CHSTau2_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8CHSTau3_JetSubCalc_PtOrdered", &theJetAK8CHSTau3_JetSubCalc_PtOrdered, &b_theJetAK8CHSTau3_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered", &theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered, &b_theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SDSubjetSize_JetSubCalc_PtOrdered", &theJetAK8SDSubjetSize_JetSubCalc_PtOrdered, &b_theJetAK8SDSubjetSize_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered", &theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered, &b_theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered", &theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered, &b_theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("dnn_largest_DeepAK8Calc_PtOrdered", &dnn_largest_DeepAK8Calc_PtOrdered, &b_dnn_largest_DeepAK8Calc_PtOrdered);
   inputTree->SetBranchAddress("dnn_B_DeepAK8Calc_PtOrdered", &dnn_B_DeepAK8Calc_PtOrdered, &b_dnn_B_DeepAK8Calc_PtOrdered);
   inputTree->SetBranchAddress("dnn_J_DeepAK8Calc_PtOrdered", &dnn_J_DeepAK8Calc_PtOrdered, &b_dnn_J_DeepAK8Calc_PtOrdered);
   inputTree->SetBranchAddress("dnn_W_DeepAK8Calc_PtOrdered", &dnn_W_DeepAK8Calc_PtOrdered, &b_dnn_W_DeepAK8Calc_PtOrdered);
   inputTree->SetBranchAddress("dnn_Z_DeepAK8Calc_PtOrdered", &dnn_Z_DeepAK8Calc_PtOrdered, &b_dnn_Z_DeepAK8Calc_PtOrdered);
   inputTree->SetBranchAddress("dnn_H_DeepAK8Calc_PtOrdered", &dnn_H_DeepAK8Calc_PtOrdered, &b_dnn_H_DeepAK8Calc_PtOrdered);
   inputTree->SetBranchAddress("dnn_T_DeepAK8Calc_PtOrdered", &dnn_T_DeepAK8Calc_PtOrdered, &b_dnn_T_DeepAK8Calc_PtOrdered);
   inputTree->SetBranchAddress("probSum_DeepAK8_decay", &probSum_DeepAK8_decay, &b_probSum_DeepAK8_decay);
   inputTree->SetBranchAddress("probSum_DeepAK8_all", &probSum_DeepAK8_all, &b_probSum_DeepAK8_all);
   inputTree->SetBranchAddress("probSum_DeepAK8_four", &probSum_DeepAK8_four, &b_probSum_DeepAK8_four);
   inputTree->SetBranchAddress("nB_DeepAK8", &nB_DeepAK8, &b_nB_DeepAK8);
   inputTree->SetBranchAddress("nH_DeepAK8", &nH_DeepAK8, &b_nH_DeepAK8);
   inputTree->SetBranchAddress("nJ_DeepAK8", &nJ_DeepAK8, &b_nJ_DeepAK8);
   inputTree->SetBranchAddress("nT_DeepAK8", &nT_DeepAK8, &b_nT_DeepAK8);
   inputTree->SetBranchAddress("nW_DeepAK8", &nW_DeepAK8, &b_nW_DeepAK8);
   inputTree->SetBranchAddress("nZ_DeepAK8", &nZ_DeepAK8, &b_nZ_DeepAK8);
   inputTree->SetBranchAddress("DeepAK8SF_TeffUp", &DeepAK8SF_TeffUp, &b_DeepAK8SF_TeffUp);
   inputTree->SetBranchAddress("DeepAK8SF_HeffUp", &DeepAK8SF_HeffUp, &b_DeepAK8SF_HeffUp);
   inputTree->SetBranchAddress("DeepAK8SF_ZeffUp", &DeepAK8SF_ZeffUp, &b_DeepAK8SF_ZeffUp);
   inputTree->SetBranchAddress("DeepAK8SF_WeffUp", &DeepAK8SF_WeffUp, &b_DeepAK8SF_WeffUp);
   inputTree->SetBranchAddress("DeepAK8SF_BeffUp", &DeepAK8SF_BeffUp, &b_DeepAK8SF_BeffUp);
   inputTree->SetBranchAddress("DeepAK8SF_JeffUp", &DeepAK8SF_JeffUp, &b_DeepAK8SF_JeffUp);
   inputTree->SetBranchAddress("DeepAK8SF_TmisUp", &DeepAK8SF_TmisUp, &b_DeepAK8SF_TmisUp);
   inputTree->SetBranchAddress("DeepAK8SF_HmisUp", &DeepAK8SF_HmisUp, &b_DeepAK8SF_HmisUp);
   inputTree->SetBranchAddress("DeepAK8SF_ZmisUp", &DeepAK8SF_ZmisUp, &b_DeepAK8SF_ZmisUp);
   inputTree->SetBranchAddress("DeepAK8SF_WmisUp", &DeepAK8SF_WmisUp, &b_DeepAK8SF_WmisUp);
   inputTree->SetBranchAddress("DeepAK8SF_BmisUp", &DeepAK8SF_BmisUp, &b_DeepAK8SF_BmisUp);
   inputTree->SetBranchAddress("DeepAK8SF_JmisUp", &DeepAK8SF_JmisUp, &b_DeepAK8SF_JmisUp);
   inputTree->SetBranchAddress("DeepAK8SF_TeffDn", &DeepAK8SF_TeffDn, &b_DeepAK8SF_TeffDn);
   inputTree->SetBranchAddress("DeepAK8SF_HeffDn", &DeepAK8SF_HeffDn, &b_DeepAK8SF_HeffDn);
   inputTree->SetBranchAddress("DeepAK8SF_ZeffDn", &DeepAK8SF_ZeffDn, &b_DeepAK8SF_ZeffDn);
   inputTree->SetBranchAddress("DeepAK8SF_WeffDn", &DeepAK8SF_WeffDn, &b_DeepAK8SF_WeffDn);
   inputTree->SetBranchAddress("DeepAK8SF_BeffDn", &DeepAK8SF_BeffDn, &b_DeepAK8SF_BeffDn);
   inputTree->SetBranchAddress("DeepAK8SF_JeffDn", &DeepAK8SF_JeffDn, &b_DeepAK8SF_JeffDn);
   inputTree->SetBranchAddress("DeepAK8SF_TmisDn", &DeepAK8SF_TmisDn, &b_DeepAK8SF_TmisDn);
   inputTree->SetBranchAddress("DeepAK8SF_HmisDn", &DeepAK8SF_HmisDn, &b_DeepAK8SF_HmisDn);
   inputTree->SetBranchAddress("DeepAK8SF_ZmisDn", &DeepAK8SF_ZmisDn, &b_DeepAK8SF_ZmisDn);
   inputTree->SetBranchAddress("DeepAK8SF_WmisDn", &DeepAK8SF_WmisDn, &b_DeepAK8SF_WmisDn);
   inputTree->SetBranchAddress("DeepAK8SF_BmisDn", &DeepAK8SF_BmisDn, &b_DeepAK8SF_BmisDn);
   inputTree->SetBranchAddress("DeepAK8SF_JmisDn", &DeepAK8SF_JmisDn, &b_DeepAK8SF_JmisDn);
   inputTree->SetBranchAddress("W_mass", &W_mass, &b_W_mass);
   inputTree->SetBranchAddress("W_pt", &W_pt, &b_W_pt);
   inputTree->SetBranchAddress("W_dRLep", &W_dRLep, &b_W_dRLep);
   inputTree->SetBranchAddress("t_mass", &t_mass, &b_t_mass);
   inputTree->SetBranchAddress("t_pt", &t_pt, &b_t_pt);
   inputTree->SetBranchAddress("t_dRWb", &t_dRWb, &b_t_dRWb);
   inputTree->SetBranchAddress("deltaR_leptonicparticle_AK8_PtOrdered", &deltaR_leptonicparticle_AK8_PtOrdered, &b_deltaR_leptonicparticle_AK8_PtOrdered);
   inputTree->SetBranchAddress("isLeptonic_t", &isLeptonic_t, &b_isLeptonic_t);
   inputTree->SetBranchAddress("isLeptonic_W", &isLeptonic_W, &b_isLeptonic_W);
   inputTree->SetBranchAddress("Tprime1_DeepAK8_Mass", &Tprime1_DeepAK8_Mass, &b_Tprime1_DeepAK8_Mass);
   inputTree->SetBranchAddress("Tprime2_DeepAK8_Mass", &Tprime2_DeepAK8_Mass, &b_Tprime2_DeepAK8_Mass);
   inputTree->SetBranchAddress("Tprime1_DeepAK8_Pt", &Tprime1_DeepAK8_Pt, &b_Tprime1_DeepAK8_Pt);
   inputTree->SetBranchAddress("Tprime2_DeepAK8_Pt", &Tprime2_DeepAK8_Pt, &b_Tprime2_DeepAK8_Pt);
   inputTree->SetBranchAddress("Tprime1_DeepAK8_Eta", &Tprime1_DeepAK8_Eta, &b_Tprime1_DeepAK8_Eta);
   inputTree->SetBranchAddress("Tprime2_DeepAK8_Eta", &Tprime2_DeepAK8_Eta, &b_Tprime2_DeepAK8_Eta);
   inputTree->SetBranchAddress("Tprime1_DeepAK8_Phi", &Tprime1_DeepAK8_Phi, &b_Tprime1_DeepAK8_Phi);
   inputTree->SetBranchAddress("Tprime2_DeepAK8_Phi", &Tprime2_DeepAK8_Phi, &b_Tprime2_DeepAK8_Phi);
   inputTree->SetBranchAddress("Tprime1_DeepAK8_deltaR", &Tprime1_DeepAK8_deltaR, &b_Tprime1_DeepAK8_deltaR);
   inputTree->SetBranchAddress("Tprime2_DeepAK8_deltaR", &Tprime2_DeepAK8_deltaR, &b_Tprime2_DeepAK8_deltaR);
   inputTree->SetBranchAddress("isValidTTDecayMode_DeepAK8", &isValidTTDecayMode_DeepAK8, &b_validTDecay_DeepAK8);
   inputTree->SetBranchAddress("taggedBWBW_DeepAK8", &taggedBWBW_DeepAK8, &b_taggedBWBW_DeepAK8);
   inputTree->SetBranchAddress("taggedTHBW_DeepAK8", &taggedTHBW_DeepAK8, &b_taggedTHBW_DeepAK8);
   inputTree->SetBranchAddress("taggedTHTH_DeepAK8", &taggedTHTH_DeepAK8, &b_taggedTHTH_DeepAK8);
   inputTree->SetBranchAddress("taggedTZBW_DeepAK8", &taggedTZBW_DeepAK8, &b_taggedTZBW_DeepAK8);
   inputTree->SetBranchAddress("taggedTZTH_DeepAK8", &taggedTZTH_DeepAK8, &b_taggedTZTH_DeepAK8);
   inputTree->SetBranchAddress("taggedTZTZ_DeepAK8", &taggedTZTZ_DeepAK8, &b_taggedTZTZ_DeepAK8);
   inputTree->SetBranchAddress("highPtAK8Jet1_SoftDropCorrectedMass", &highPtAK8Jet1_SoftDropCorrectedMass, &b_highPtAK8Jet1_SoftDropCorrectedMass);
   inputTree->SetBranchAddress("highPtAK8Jet2_SoftDropCorrectedMass", &highPtAK8Jet2_SoftDropCorrectedMass, &b_highPtAK8Jet2_SoftDropCorrectedMass);
   inputTree->SetBranchAddress("highPtAK8Jet3_SoftDropCorrectedMass", &highPtAK8Jet3_SoftDropCorrectedMass, &b_highPtAK8Jet3_SoftDropCorrectedMass);
   inputTree->SetBranchAddress("leptonicTprimeJetIDs_DeepAK8", &leptonicTprimeJetIDs_DeepAK8, &b_leptonicTprimeJetIDs_DeepAK8);
   inputTree->SetBranchAddress("hadronicTprimeJetIDs_DeepAK8", &hadronicTprimeJetIDs_DeepAK8, &b_hadronicTprimeJetIDs_DeepAK8);
   inputTree->SetBranchAddress("Bprime1_DeepAK8_Mass", &Bprime1_DeepAK8_Mass, &b_Bprime1_DeepAK8_Mass);
   inputTree->SetBranchAddress("Bprime2_DeepAK8_Mass", &Bprime2_DeepAK8_Mass, &b_Bprime2_DeepAK8_Mass);
   inputTree->SetBranchAddress("Bprime1_DeepAK8_Pt", &Bprime1_DeepAK8_Pt, &b_Bprime1_DeepAK8_Pt);
   inputTree->SetBranchAddress("Bprime2_DeepAK8_Pt", &Bprime2_DeepAK8_Pt, &b_Bprime2_DeepAK8_Pt);
   inputTree->SetBranchAddress("Bprime1_DeepAK8_Eta", &Bprime1_DeepAK8_Eta, &b_Bprime1_DeepAK8_Eta);
   inputTree->SetBranchAddress("Bprime2_DeepAK8_Eta", &Bprime2_DeepAK8_Eta, &b_Bprime2_DeepAK8_Eta);
   inputTree->SetBranchAddress("Bprime1_DeepAK8_Phi", &Bprime1_DeepAK8_Phi, &b_Bprime1_DeepAK8_Phi);
   inputTree->SetBranchAddress("Bprime2_DeepAK8_Phi", &Bprime2_DeepAK8_Phi, &b_Bprime2_DeepAK8_Phi);
   inputTree->SetBranchAddress("Bprime1_DeepAK8_deltaR", &Bprime1_DeepAK8_deltaR, &b_Bprime1_DeepAK8_deltaR);
   inputTree->SetBranchAddress("Bprime2_DeepAK8_deltaR", &Bprime2_DeepAK8_deltaR, &b_Bprime2_DeepAK8_deltaR);
   inputTree->SetBranchAddress("isValidBBDecayMode_DeepAK8", &isValidBBDecayMode_DeepAK8, &b_validBDecay_DeepAK8);
   inputTree->SetBranchAddress("taggedTWTW_DeepAK8", &taggedTWTW_DeepAK8, &b_taggedTWTW_DeepAK8);
   inputTree->SetBranchAddress("taggedBHTW_DeepAK8", &taggedBHTW_DeepAK8, &b_taggedBZTW_DeepAK8);
   inputTree->SetBranchAddress("taggedBZTW_DeepAK8", &taggedBZTW_DeepAK8, &b_taggedBHTW_DeepAK8);
   inputTree->SetBranchAddress("leptonicBprimeJetIDs_DeepAK8", &leptonicBprimeJetIDs_DeepAK8, &b_leptonicBprimeJetIDs_DeepAK8);
   inputTree->SetBranchAddress("hadronicBprimeJetIDs_DeepAK8", &hadronicBprimeJetIDs_DeepAK8, &b_hadronicBprimeJetIDs_DeepAK8);
   inputTree->SetBranchAddress("dnn_WJets", &dnn_WJets, &b_dnn_WJets);
   inputTree->SetBranchAddress("dnn_ttbar", &dnn_ttbar, &b_dnn_ttbar);
   inputTree->SetBranchAddress("dnn_Tprime", &dnn_Tprime, &b_dnn_Tprime);
   inputTree->SetBranchAddress("dnn_WJetsBB", &dnn_WJetsBB, &b_dnn_WJetsBB);
   inputTree->SetBranchAddress("dnn_ttbarBB", &dnn_ttbarBB, &b_dnn_ttbarBB);
   inputTree->SetBranchAddress("dnn_Bprime", &dnn_Bprime, &b_dnn_Bprime);
   Notify();
}

Bool_t step2::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void step2::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!inputTree) return;
   inputTree->Show(entry);
}
Int_t step2::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef step2_cxx
