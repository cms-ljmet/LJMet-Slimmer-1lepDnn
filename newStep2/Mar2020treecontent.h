//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Apr 13 11:31:55 2020 by ROOT version 6.12/07
// from TTree ljmet/ljmet
// found on file: root://cmseos.fnal.gov//store/user/cholz/FWLJMET102X_1lep2018Dnn_Mar2020_step1hadds/ZZ_TuneCP5_13TeV-pythia8_hadd.root
//////////////////////////////////////////////////////////

#ifndef Mar2020treecontent_h
#define Mar2020treecontent_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class Mar2020treecontent {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

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
   Float_t         triggSF;
   Float_t         triggSFUncert;
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
   TBranch        *b_triggSF;   //!
   TBranch        *b_triggSFUncert;   //!
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

   Mar2020treecontent(TTree *tree=0);
   virtual ~Mar2020treecontent();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Mar2020treecontent_cxx
Mar2020treecontent::Mar2020treecontent(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("root://cmseos.fnal.gov//store/user/cholz/FWLJMET102X_1lep2018Dnn_Mar2020_step1hadds/ZZ_TuneCP5_13TeV-pythia8_hadd.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("root://cmseos.fnal.gov//store/user/cholz/FWLJMET102X_1lep2018Dnn_Mar2020_step1hadds/ZZ_TuneCP5_13TeV-pythia8_hadd.root");
      }
      f->GetObject("ljmet",tree);

   }
   Init(tree);
}

Mar2020treecontent::~Mar2020treecontent()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Mar2020treecontent::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Mar2020treecontent::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Mar2020treecontent::Init(TTree *tree)
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
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("event_CommonCalc", &event_CommonCalc, &b_event_CommonCalc);
   fChain->SetBranchAddress("run_CommonCalc", &run_CommonCalc, &b_run_CommonCalc);
   fChain->SetBranchAddress("lumi_CommonCalc", &lumi_CommonCalc, &b_lumi_CommonCalc);
   fChain->SetBranchAddress("nTrueInteractions_MultiLepCalc", &nTrueInteractions_MultiLepCalc, &b_nTrueInteractions_MultiLepCalc);
   fChain->SetBranchAddress("isElectron", &isElectron, &b_isElectron);
   fChain->SetBranchAddress("isMuon", &isMuon, &b_isMuon);
   fChain->SetBranchAddress("MCPastTrigger", &MCPastTrigger, &b_MCPastTrigger);
   fChain->SetBranchAddress("DataPastTrigger", &DataPastTrigger, &b_DataPastTrigger);
   fChain->SetBranchAddress("L1NonPrefiringProb_CommonCalc", &L1NonPrefiringProb_CommonCalc, &b_L1NonPrefiringProb_CommonCalc);
   fChain->SetBranchAddress("L1NonPrefiringProbUp_CommonCalc", &L1NonPrefiringProbUp_CommonCalc, &b_L1NonPrefiringProbUp_CommonCalc);
   fChain->SetBranchAddress("L1NonPrefiringProbDown_CommonCalc", &L1NonPrefiringProbDown_CommonCalc, &b_L1NonPrefiringProbDown_CommonCalc);
   fChain->SetBranchAddress("isTHBW_TpTpCalc", &isTHBW_TpTpCalc, &b_isTHBW_TpTpCalc);
   fChain->SetBranchAddress("isTHTH_TpTpCalc", &isTHTH_TpTpCalc, &b_isTHTH_TpTpCalc);
   fChain->SetBranchAddress("isBWBW_TpTpCalc", &isBWBW_TpTpCalc, &b_isBWBW_TpTpCalc);
   fChain->SetBranchAddress("isTZBW_TpTpCalc", &isTZBW_TpTpCalc, &b_isTZBW_TpTpCalc);
   fChain->SetBranchAddress("isTZTH_TpTpCalc", &isTZTH_TpTpCalc, &b_isTZTH_TpTpCalc);
   fChain->SetBranchAddress("isTZTZ_TpTpCalc", &isTZTZ_TpTpCalc, &b_isTZTZ_TpTpCalc);
   fChain->SetBranchAddress("isBHTW_TpTpCalc", &isBHTW_TpTpCalc, &b_isBHTW_TpTpCalc);
   fChain->SetBranchAddress("isBHBH_TpTpCalc", &isBHBH_TpTpCalc, &b_isBHBH_TpTpCalc);
   fChain->SetBranchAddress("isTWTW_TpTpCalc", &isTWTW_TpTpCalc, &b_isTWTW_TpTpCalc);
   fChain->SetBranchAddress("isBZTW_TpTpCalc", &isBZTW_TpTpCalc, &b_isBZTW_TpTpCalc);
   fChain->SetBranchAddress("isBZBH_TpTpCalc", &isBZBH_TpTpCalc, &b_isBZBH_TpTpCalc);
   fChain->SetBranchAddress("isBZBZ_TpTpCalc", &isBZBZ_TpTpCalc, &b_isBZBZ_TpTpCalc);
   fChain->SetBranchAddress("tPrimePt_TpTpCalc", &tPrimePt_TpTpCalc, &b_tPrimePt_TpTpCalc);
   fChain->SetBranchAddress("NLeptonDecays_TpTpCalc", &NLeptonDecays_TpTpCalc, &b_NLeptonDecays_TpTpCalc);
   fChain->SetBranchAddress("MCWeight_MultiLepCalc", &MCWeight_MultiLepCalc, &b_MCWeight_MultiLepCalc);
   fChain->SetBranchAddress("renormWeights", &renormWeights, &b_renormWeights);
   fChain->SetBranchAddress("pdfWeights", &pdfWeights, &b_pdfWeights);
   fChain->SetBranchAddress("pdfNewWeights", &pdfNewWeights, &b_pdfNewWeights);
   fChain->SetBranchAddress("pdfNewNominalWeight", &pdfNewNominalWeight, &b_pdfNewNominalWeight);
   fChain->SetBranchAddress("pileupWeight", &pileupWeight, &b_pileupWeight);
   fChain->SetBranchAddress("pileupWeightUp", &pileupWeightUp, &b_pileupWeightUp);
   fChain->SetBranchAddress("pileupWeightDown", &pileupWeightDown, &b_pileupWeightDown);
   fChain->SetBranchAddress("HTSF_Pol", &HTSF_Pol, &b_HTSF_Pol);
   fChain->SetBranchAddress("HTSF_PolUp", &HTSF_PolUp, &b_HTSF_PolUp);
   fChain->SetBranchAddress("HTSF_PolDn", &HTSF_PolDn, &b_HTSF_PolDn);
   fChain->SetBranchAddress("topPtWeight13TeV", &topPtWeight13TeV, &b_topPtWeight13TeV);
   fChain->SetBranchAddress("EGammaGsfSF", &EGammaGsfSF, &b_EGammaGsfSF);
   fChain->SetBranchAddress("lepIdSF", &lepIdSF, &b_lepIdSF);
   fChain->SetBranchAddress("isoSF", &isoSF, &b_isoSF);
   fChain->SetBranchAddress("triggSF", &triggSF, &b_triggSF);
   fChain->SetBranchAddress("triggSFUncert", &triggSFUncert, &b_triggSFUncert);
   fChain->SetBranchAddress("muPtSF", &muPtSF, &b_muPtSF);
   fChain->SetBranchAddress("ttbarMass_TTbarMassCalc", &ttbarMass_TTbarMassCalc, &b_ttbarMass_TTbarMassCalc);
   fChain->SetBranchAddress("genTopPt", &genTopPt, &b_genTopPt);
   fChain->SetBranchAddress("genAntiTopPt", &genAntiTopPt, &b_genAntiTopPt);
   fChain->SetBranchAddress("corr_met_MultiLepCalc", &corr_met_MultiLepCalc, &b_corr_met_MultiLepCalc);
   fChain->SetBranchAddress("corr_met_phi_MultiLepCalc", &corr_met_phi_MultiLepCalc, &b_corr_met_phi_MultiLepCalc);
   fChain->SetBranchAddress("corr_metmod_MultiLepCalc", &corr_metmod_MultiLepCalc, &b_corr_metmod_MultiLepCalc);
   fChain->SetBranchAddress("corr_metmod_phi_MultiLepCalc", &corr_metmod_phi_MultiLepCalc, &b_corr_metmod_phi_MultiLepCalc);
   fChain->SetBranchAddress("leptonPt_MultiLepCalc", &leptonPt_MultiLepCalc, &b_leptonPt_MultiLepCalc);
   fChain->SetBranchAddress("leptonEta_MultiLepCalc", &leptonEta_MultiLepCalc, &b_leptonEta_MultiLepCalc);
   fChain->SetBranchAddress("leptonPhi_MultiLepCalc", &leptonPhi_MultiLepCalc, &b_leptonPhi_MultiLepCalc);
   fChain->SetBranchAddress("leptonEnergy_MultiLepCalc", &leptonEnergy_MultiLepCalc, &b_leptonEnergy_MultiLepCalc);
   fChain->SetBranchAddress("leptonMVAValue_MultiLepCalc", &leptonMVAValue_MultiLepCalc, &b_leptonMVAValue_MultiLepCalc);
   fChain->SetBranchAddress("leptonMiniIso_MultiLepCalc", &leptonMiniIso_MultiLepCalc, &b_leptonMiniIso_MultiLepCalc);
   fChain->SetBranchAddress("MT_lepMet", &MT_lepMet, &b_MT_lepMet);
   fChain->SetBranchAddress("MT_lepMetmod", &MT_lepMetmod, &b_MT_lepMetmod);
   fChain->SetBranchAddress("minDPhi_MetJet", &minDPhi_MetJet, &b_minDPhi_MetJet);
   fChain->SetBranchAddress("theJetPt_JetSubCalc_PtOrdered", &theJetPt_JetSubCalc_PtOrdered, &b_theJetPt_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetEta_JetSubCalc_PtOrdered", &theJetEta_JetSubCalc_PtOrdered, &b_theJetEta_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetPhi_JetSubCalc_PtOrdered", &theJetPhi_JetSubCalc_PtOrdered, &b_theJetPhi_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetEnergy_JetSubCalc_PtOrdered", &theJetEnergy_JetSubCalc_PtOrdered, &b_theJetEnergy_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("AK4JetDeepCSVb_MultiLepCalc_PtOrdered", &AK4JetDeepCSVb_MultiLepCalc_PtOrdered, &b_AK4JetDeepCSVb_MultiLepCalc_PtOrdered);
   fChain->SetBranchAddress("AK4JetDeepCSVbb_MultiLepCalc_PtOrdered", &AK4JetDeepCSVbb_MultiLepCalc_PtOrdered, &b_AK4JetDeepCSVbb_MultiLepCalc_PtOrdered);
   fChain->SetBranchAddress("AK4JetDeepFlavb_MultiLepCalc_PtOrdered", &AK4JetDeepFlavb_MultiLepCalc_PtOrdered, &b_AK4JetDeepFlavb_MultiLepCalc_PtOrdered);
   fChain->SetBranchAddress("AK4JetDeepFlavbb_MultiLepCalc_PtOrdered", &AK4JetDeepFlavbb_MultiLepCalc_PtOrdered, &b_AK4JetDeepFlavbb_MultiLepCalc_PtOrdered);
   fChain->SetBranchAddress("AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered", &AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered, &b_AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered);
   fChain->SetBranchAddress("theJetHFlav_JetSubCalc_PtOrdered", &theJetHFlav_JetSubCalc_PtOrdered, &b_theJetHFlav_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetPFlav_JetSubCalc_PtOrdered", &theJetPFlav_JetSubCalc_PtOrdered, &b_theJetPFlav_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetBTag_JetSubCalc_PtOrdered", &theJetBTag_JetSubCalc_PtOrdered, &b_theJetBTag_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetBTagDeepCSV_JetSubCalc_PtOrdered", &theJetBTagDeepCSV_JetSubCalc_PtOrdered, &b_theJetBTagDeepCSV_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("AK4HTpMETpLepPt", &AK4HTpMETpLepPt, &b_AK4HTpMETpLepPt);
   fChain->SetBranchAddress("AK4HT", &AK4HT, &b_AK4HT);
   fChain->SetBranchAddress("NJets_JetSubCalc", &NJets_JetSubCalc, &b_NJets_JetSubCalc);
   fChain->SetBranchAddress("NJetsDeepFlav_JetSubCalc", &NJetsDeepFlav_JetSubCalc, &b_NJetsDeepFlav_JetSubCalc);
   fChain->SetBranchAddress("NJetsDeepCSV_JetSubCalc", &NJetsDeepCSV_JetSubCalc, &b_NJetsDeepCSV_JetSubCalc);
   fChain->SetBranchAddress("NJetsDeepFlavwithSF_JetSubCalc", &NJetsDeepFlavwithSF_JetSubCalc, &b_NJetsDeepFlavwithSF_JetSubCalc);
   fChain->SetBranchAddress("NJetsDeepCSVwithSF_JetSubCalc", &NJetsDeepCSVwithSF_JetSubCalc, &b_NJetsDeepCSVwithSF_JetSubCalc);
   fChain->SetBranchAddress("deltaR_lepMinMlb", &deltaR_lepMinMlb, &b_deltaR_lepMinMlb);
   fChain->SetBranchAddress("deltaR_lepMinMlj", &deltaR_lepMinMlj, &b_deltaR_lepMinMlj);
   fChain->SetBranchAddress("minMleppBjet", &minMleppBjet, &b_minMleppBjet);
   fChain->SetBranchAddress("minMleppJet", &minMleppJet, &b_minMleppJet);
   fChain->SetBranchAddress("minDR_lepJet", &minDR_lepJet, &b_minDR_lepJet);
   fChain->SetBranchAddress("ptRel_lepJet", &ptRel_lepJet, &b_ptRel_lepJet);
   fChain->SetBranchAddress("deltaR_lepJets", &deltaR_lepJets, &b_deltaR_lepJets);
   fChain->SetBranchAddress("deltaR_lepBJets", &deltaR_lepBJets, &b_deltaR_lepBJets);
   fChain->SetBranchAddress("HadronicVHtID_JetSubCalc", &HadronicVHtID_JetSubCalc, &b_HadronicVHtID_JetSubCalc);
   fChain->SetBranchAddress("HadronicVHtPt_JetSubCalc", &HadronicVHtPt_JetSubCalc, &b_HadronicVHtPt_JetSubCalc);
   fChain->SetBranchAddress("HadronicVHtEta_JetSubCalc", &HadronicVHtEta_JetSubCalc, &b_HadronicVHtEta_JetSubCalc);
   fChain->SetBranchAddress("HadronicVHtPhi_JetSubCalc", &HadronicVHtPhi_JetSubCalc, &b_HadronicVHtPhi_JetSubCalc);
   fChain->SetBranchAddress("HadronicVHtEnergy_JetSubCalc", &HadronicVHtEnergy_JetSubCalc, &b_HadronicVHtEnergy_JetSubCalc);
   fChain->SetBranchAddress("theJetAK8Wmatch_JetSubCalc_PtOrdered", &theJetAK8Wmatch_JetSubCalc_PtOrdered, &b_theJetAK8Wmatch_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8Tmatch_JetSubCalc_PtOrdered", &theJetAK8Tmatch_JetSubCalc_PtOrdered, &b_theJetAK8Tmatch_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8Zmatch_JetSubCalc_PtOrdered", &theJetAK8Zmatch_JetSubCalc_PtOrdered, &b_theJetAK8Zmatch_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8Hmatch_JetSubCalc_PtOrdered", &theJetAK8Hmatch_JetSubCalc_PtOrdered, &b_theJetAK8Hmatch_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8MatchedPt_JetSubCalc_PtOrdered", &theJetAK8MatchedPt_JetSubCalc_PtOrdered, &b_theJetAK8MatchedPt_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8Truth_JetSubCalc_PtOrdered", &theJetAK8Truth_JetSubCalc_PtOrdered, &b_theJetAK8Truth_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("NJetsAK8_JetSubCalc", &NJetsAK8_JetSubCalc, &b_NJetsAK8_JetSubCalc);
   fChain->SetBranchAddress("theJetAK8Pt_JetSubCalc_PtOrdered", &theJetAK8Pt_JetSubCalc_PtOrdered, &b_theJetAK8Pt_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8Eta_JetSubCalc_PtOrdered", &theJetAK8Eta_JetSubCalc_PtOrdered, &b_theJetAK8Eta_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8Phi_JetSubCalc_PtOrdered", &theJetAK8Phi_JetSubCalc_PtOrdered, &b_theJetAK8Phi_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8Mass_JetSubCalc_PtOrdered", &theJetAK8Mass_JetSubCalc_PtOrdered, &b_theJetAK8Mass_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8Energy_JetSubCalc_PtOrdered", &theJetAK8Energy_JetSubCalc_PtOrdered, &b_theJetAK8Energy_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("minDR_leadAK8otherAK8", &minDR_leadAK8otherAK8, &b_minDR_leadAK8otherAK8);
   fChain->SetBranchAddress("minDR_lepAK8", &minDR_lepAK8, &b_minDR_lepAK8);
   fChain->SetBranchAddress("ptRel_lepAK8", &ptRel_lepAK8, &b_ptRel_lepAK8);
   fChain->SetBranchAddress("deltaR_lepAK8s", &deltaR_lepAK8s, &b_deltaR_lepAK8s);
   fChain->SetBranchAddress("maxProb_JetSubCalc_PtOrdered", &maxProb_JetSubCalc_PtOrdered, &b_maxProb_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered", &theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered, &b_theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered", &theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered, &b_theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8SoftDropRaw_JetSubCalc_PtOrdered", &theJetAK8SoftDropRaw_JetSubCalc_PtOrdered, &b_theJetAK8SoftDropRaw_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8SoftDropCorr_JetSubCalc_PtOrdered", &theJetAK8SoftDropCorr_JetSubCalc_PtOrdered, &b_theJetAK8SoftDropCorr_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8DoubleB_JetSubCalc_PtOrdered", &theJetAK8DoubleB_JetSubCalc_PtOrdered, &b_theJetAK8DoubleB_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8SoftDrop_PtOrdered", &theJetAK8SoftDrop_PtOrdered, &b_theJetAK8SoftDrop_PtOrdered);
   fChain->SetBranchAddress("theJetAK8NjettinessTau1_JetSubCalc_PtOrdered", &theJetAK8NjettinessTau1_JetSubCalc_PtOrdered, &b_theJetAK8NjettinessTau1_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8NjettinessTau2_JetSubCalc_PtOrdered", &theJetAK8NjettinessTau2_JetSubCalc_PtOrdered, &b_theJetAK8NjettinessTau2_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8NjettinessTau3_JetSubCalc_PtOrdered", &theJetAK8NjettinessTau3_JetSubCalc_PtOrdered, &b_theJetAK8NjettinessTau3_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8CHSTau1_JetSubCalc_PtOrdered", &theJetAK8CHSTau1_JetSubCalc_PtOrdered, &b_theJetAK8CHSTau1_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8CHSTau2_JetSubCalc_PtOrdered", &theJetAK8CHSTau2_JetSubCalc_PtOrdered, &b_theJetAK8CHSTau2_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8CHSTau3_JetSubCalc_PtOrdered", &theJetAK8CHSTau3_JetSubCalc_PtOrdered, &b_theJetAK8CHSTau3_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered", &theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered, &b_theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8SDSubjetSize_JetSubCalc_PtOrdered", &theJetAK8SDSubjetSize_JetSubCalc_PtOrdered, &b_theJetAK8SDSubjetSize_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered", &theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered, &b_theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered", &theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered, &b_theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered);
   fChain->SetBranchAddress("dnn_largest_DeepAK8Calc_PtOrdered", &dnn_largest_DeepAK8Calc_PtOrdered, &b_dnn_largest_DeepAK8Calc_PtOrdered);
   fChain->SetBranchAddress("dnn_B_DeepAK8Calc_PtOrdered", &dnn_B_DeepAK8Calc_PtOrdered, &b_dnn_B_DeepAK8Calc_PtOrdered);
   fChain->SetBranchAddress("dnn_J_DeepAK8Calc_PtOrdered", &dnn_J_DeepAK8Calc_PtOrdered, &b_dnn_J_DeepAK8Calc_PtOrdered);
   fChain->SetBranchAddress("dnn_W_DeepAK8Calc_PtOrdered", &dnn_W_DeepAK8Calc_PtOrdered, &b_dnn_W_DeepAK8Calc_PtOrdered);
   fChain->SetBranchAddress("dnn_Z_DeepAK8Calc_PtOrdered", &dnn_Z_DeepAK8Calc_PtOrdered, &b_dnn_Z_DeepAK8Calc_PtOrdered);
   fChain->SetBranchAddress("dnn_H_DeepAK8Calc_PtOrdered", &dnn_H_DeepAK8Calc_PtOrdered, &b_dnn_H_DeepAK8Calc_PtOrdered);
   fChain->SetBranchAddress("dnn_T_DeepAK8Calc_PtOrdered", &dnn_T_DeepAK8Calc_PtOrdered, &b_dnn_T_DeepAK8Calc_PtOrdered);
   fChain->SetBranchAddress("probSum_DeepAK8_decay", &probSum_DeepAK8_decay, &b_probSum_DeepAK8_decay);
   fChain->SetBranchAddress("probSum_DeepAK8_all", &probSum_DeepAK8_all, &b_probSum_DeepAK8_all);
   fChain->SetBranchAddress("probSum_DeepAK8_four", &probSum_DeepAK8_four, &b_probSum_DeepAK8_four);
   fChain->SetBranchAddress("nB_DeepAK8", &nB_DeepAK8, &b_nB_DeepAK8);
   fChain->SetBranchAddress("nH_DeepAK8", &nH_DeepAK8, &b_nH_DeepAK8);
   fChain->SetBranchAddress("nJ_DeepAK8", &nJ_DeepAK8, &b_nJ_DeepAK8);
   fChain->SetBranchAddress("nT_DeepAK8", &nT_DeepAK8, &b_nT_DeepAK8);
   fChain->SetBranchAddress("nW_DeepAK8", &nW_DeepAK8, &b_nW_DeepAK8);
   fChain->SetBranchAddress("nZ_DeepAK8", &nZ_DeepAK8, &b_nZ_DeepAK8);
   fChain->SetBranchAddress("DeepAK8SF_TeffUp", &DeepAK8SF_TeffUp, &b_DeepAK8SF_TeffUp);
   fChain->SetBranchAddress("DeepAK8SF_HeffUp", &DeepAK8SF_HeffUp, &b_DeepAK8SF_HeffUp);
   fChain->SetBranchAddress("DeepAK8SF_ZeffUp", &DeepAK8SF_ZeffUp, &b_DeepAK8SF_ZeffUp);
   fChain->SetBranchAddress("DeepAK8SF_WeffUp", &DeepAK8SF_WeffUp, &b_DeepAK8SF_WeffUp);
   fChain->SetBranchAddress("DeepAK8SF_BeffUp", &DeepAK8SF_BeffUp, &b_DeepAK8SF_BeffUp);
   fChain->SetBranchAddress("DeepAK8SF_JeffUp", &DeepAK8SF_JeffUp, &b_DeepAK8SF_JeffUp);
   fChain->SetBranchAddress("DeepAK8SF_TmisUp", &DeepAK8SF_TmisUp, &b_DeepAK8SF_TmisUp);
   fChain->SetBranchAddress("DeepAK8SF_HmisUp", &DeepAK8SF_HmisUp, &b_DeepAK8SF_HmisUp);
   fChain->SetBranchAddress("DeepAK8SF_ZmisUp", &DeepAK8SF_ZmisUp, &b_DeepAK8SF_ZmisUp);
   fChain->SetBranchAddress("DeepAK8SF_WmisUp", &DeepAK8SF_WmisUp, &b_DeepAK8SF_WmisUp);
   fChain->SetBranchAddress("DeepAK8SF_BmisUp", &DeepAK8SF_BmisUp, &b_DeepAK8SF_BmisUp);
   fChain->SetBranchAddress("DeepAK8SF_JmisUp", &DeepAK8SF_JmisUp, &b_DeepAK8SF_JmisUp);
   fChain->SetBranchAddress("DeepAK8SF_TeffDn", &DeepAK8SF_TeffDn, &b_DeepAK8SF_TeffDn);
   fChain->SetBranchAddress("DeepAK8SF_HeffDn", &DeepAK8SF_HeffDn, &b_DeepAK8SF_HeffDn);
   fChain->SetBranchAddress("DeepAK8SF_ZeffDn", &DeepAK8SF_ZeffDn, &b_DeepAK8SF_ZeffDn);
   fChain->SetBranchAddress("DeepAK8SF_WeffDn", &DeepAK8SF_WeffDn, &b_DeepAK8SF_WeffDn);
   fChain->SetBranchAddress("DeepAK8SF_BeffDn", &DeepAK8SF_BeffDn, &b_DeepAK8SF_BeffDn);
   fChain->SetBranchAddress("DeepAK8SF_JeffDn", &DeepAK8SF_JeffDn, &b_DeepAK8SF_JeffDn);
   fChain->SetBranchAddress("DeepAK8SF_TmisDn", &DeepAK8SF_TmisDn, &b_DeepAK8SF_TmisDn);
   fChain->SetBranchAddress("DeepAK8SF_HmisDn", &DeepAK8SF_HmisDn, &b_DeepAK8SF_HmisDn);
   fChain->SetBranchAddress("DeepAK8SF_ZmisDn", &DeepAK8SF_ZmisDn, &b_DeepAK8SF_ZmisDn);
   fChain->SetBranchAddress("DeepAK8SF_WmisDn", &DeepAK8SF_WmisDn, &b_DeepAK8SF_WmisDn);
   fChain->SetBranchAddress("DeepAK8SF_BmisDn", &DeepAK8SF_BmisDn, &b_DeepAK8SF_BmisDn);
   fChain->SetBranchAddress("DeepAK8SF_JmisDn", &DeepAK8SF_JmisDn, &b_DeepAK8SF_JmisDn);
   fChain->SetBranchAddress("W_mass", &W_mass, &b_W_mass);
   fChain->SetBranchAddress("W_pt", &W_pt, &b_W_pt);
   fChain->SetBranchAddress("W_dRLep", &W_dRLep, &b_W_dRLep);
   fChain->SetBranchAddress("t_mass", &t_mass, &b_t_mass);
   fChain->SetBranchAddress("t_pt", &t_pt, &b_t_pt);
   fChain->SetBranchAddress("t_dRWb", &t_dRWb, &b_t_dRWb);
   fChain->SetBranchAddress("deltaR_leptonicparticle_AK8_PtOrdered", &deltaR_leptonicparticle_AK8_PtOrdered, &b_deltaR_leptonicparticle_AK8_PtOrdered);
   fChain->SetBranchAddress("isLeptonic_t", &isLeptonic_t, &b_isLeptonic_t);
   fChain->SetBranchAddress("isLeptonic_W", &isLeptonic_W, &b_isLeptonic_W);
   fChain->SetBranchAddress("Tprime1_DeepAK8_Mass", &Tprime1_DeepAK8_Mass, &b_Tprime1_DeepAK8_Mass);
   fChain->SetBranchAddress("Tprime2_DeepAK8_Mass", &Tprime2_DeepAK8_Mass, &b_Tprime2_DeepAK8_Mass);
   fChain->SetBranchAddress("Tprime1_DeepAK8_Pt", &Tprime1_DeepAK8_Pt, &b_Tprime1_DeepAK8_Pt);
   fChain->SetBranchAddress("Tprime2_DeepAK8_Pt", &Tprime2_DeepAK8_Pt, &b_Tprime2_DeepAK8_Pt);
   fChain->SetBranchAddress("Tprime1_DeepAK8_Eta", &Tprime1_DeepAK8_Eta, &b_Tprime1_DeepAK8_Eta);
   fChain->SetBranchAddress("Tprime2_DeepAK8_Eta", &Tprime2_DeepAK8_Eta, &b_Tprime2_DeepAK8_Eta);
   fChain->SetBranchAddress("Tprime1_DeepAK8_Phi", &Tprime1_DeepAK8_Phi, &b_Tprime1_DeepAK8_Phi);
   fChain->SetBranchAddress("Tprime2_DeepAK8_Phi", &Tprime2_DeepAK8_Phi, &b_Tprime2_DeepAK8_Phi);
   fChain->SetBranchAddress("Tprime1_DeepAK8_deltaR", &Tprime1_DeepAK8_deltaR, &b_Tprime1_DeepAK8_deltaR);
   fChain->SetBranchAddress("Tprime2_DeepAK8_deltaR", &Tprime2_DeepAK8_deltaR, &b_Tprime2_DeepAK8_deltaR);
   fChain->SetBranchAddress("isValidTTDecayMode_DeepAK8", &isValidTTDecayMode_DeepAK8, &b_validTDecay_DeepAK8);
   fChain->SetBranchAddress("taggedBWBW_DeepAK8", &taggedBWBW_DeepAK8, &b_taggedBWBW_DeepAK8);
   fChain->SetBranchAddress("taggedTHBW_DeepAK8", &taggedTHBW_DeepAK8, &b_taggedTHBW_DeepAK8);
   fChain->SetBranchAddress("taggedTHTH_DeepAK8", &taggedTHTH_DeepAK8, &b_taggedTHTH_DeepAK8);
   fChain->SetBranchAddress("taggedTZBW_DeepAK8", &taggedTZBW_DeepAK8, &b_taggedTZBW_DeepAK8);
   fChain->SetBranchAddress("taggedTZTH_DeepAK8", &taggedTZTH_DeepAK8, &b_taggedTZTH_DeepAK8);
   fChain->SetBranchAddress("taggedTZTZ_DeepAK8", &taggedTZTZ_DeepAK8, &b_taggedTZTZ_DeepAK8);
   fChain->SetBranchAddress("highPtAK8Jet1_SoftDropCorrectedMass", &highPtAK8Jet1_SoftDropCorrectedMass, &b_highPtAK8Jet1_SoftDropCorrectedMass);
   fChain->SetBranchAddress("highPtAK8Jet2_SoftDropCorrectedMass", &highPtAK8Jet2_SoftDropCorrectedMass, &b_highPtAK8Jet2_SoftDropCorrectedMass);
   fChain->SetBranchAddress("highPtAK8Jet3_SoftDropCorrectedMass", &highPtAK8Jet3_SoftDropCorrectedMass, &b_highPtAK8Jet3_SoftDropCorrectedMass);
   fChain->SetBranchAddress("leptonicTprimeJetIDs_DeepAK8", &leptonicTprimeJetIDs_DeepAK8, &b_leptonicTprimeJetIDs_DeepAK8);
   fChain->SetBranchAddress("hadronicTprimeJetIDs_DeepAK8", &hadronicTprimeJetIDs_DeepAK8, &b_hadronicTprimeJetIDs_DeepAK8);
   fChain->SetBranchAddress("Bprime1_DeepAK8_Mass", &Bprime1_DeepAK8_Mass, &b_Bprime1_DeepAK8_Mass);
   fChain->SetBranchAddress("Bprime2_DeepAK8_Mass", &Bprime2_DeepAK8_Mass, &b_Bprime2_DeepAK8_Mass);
   fChain->SetBranchAddress("Bprime1_DeepAK8_Pt", &Bprime1_DeepAK8_Pt, &b_Bprime1_DeepAK8_Pt);
   fChain->SetBranchAddress("Bprime2_DeepAK8_Pt", &Bprime2_DeepAK8_Pt, &b_Bprime2_DeepAK8_Pt);
   fChain->SetBranchAddress("Bprime1_DeepAK8_Eta", &Bprime1_DeepAK8_Eta, &b_Bprime1_DeepAK8_Eta);
   fChain->SetBranchAddress("Bprime2_DeepAK8_Eta", &Bprime2_DeepAK8_Eta, &b_Bprime2_DeepAK8_Eta);
   fChain->SetBranchAddress("Bprime1_DeepAK8_Phi", &Bprime1_DeepAK8_Phi, &b_Bprime1_DeepAK8_Phi);
   fChain->SetBranchAddress("Bprime2_DeepAK8_Phi", &Bprime2_DeepAK8_Phi, &b_Bprime2_DeepAK8_Phi);
   fChain->SetBranchAddress("Bprime1_DeepAK8_deltaR", &Bprime1_DeepAK8_deltaR, &b_Bprime1_DeepAK8_deltaR);
   fChain->SetBranchAddress("Bprime2_DeepAK8_deltaR", &Bprime2_DeepAK8_deltaR, &b_Bprime2_DeepAK8_deltaR);
   fChain->SetBranchAddress("isValidBBDecayMode_DeepAK8", &isValidBBDecayMode_DeepAK8, &b_validBDecay_DeepAK8);
   fChain->SetBranchAddress("taggedTWTW_DeepAK8", &taggedTWTW_DeepAK8, &b_taggedTWTW_DeepAK8);
   fChain->SetBranchAddress("taggedBHTW_DeepAK8", &taggedBHTW_DeepAK8, &b_taggedBZTW_DeepAK8);
   fChain->SetBranchAddress("taggedBZTW_DeepAK8", &taggedBZTW_DeepAK8, &b_taggedBHTW_DeepAK8);
   fChain->SetBranchAddress("leptonicBprimeJetIDs_DeepAK8", &leptonicBprimeJetIDs_DeepAK8, &b_leptonicBprimeJetIDs_DeepAK8);
   fChain->SetBranchAddress("hadronicBprimeJetIDs_DeepAK8", &hadronicBprimeJetIDs_DeepAK8, &b_hadronicBprimeJetIDs_DeepAK8);
   fChain->SetBranchAddress("dnn_WJets", &dnn_WJets, &b_dnn_WJets);
   fChain->SetBranchAddress("dnn_ttbar", &dnn_ttbar, &b_dnn_ttbar);
   fChain->SetBranchAddress("dnn_Tprime", &dnn_Tprime, &b_dnn_Tprime);
   fChain->SetBranchAddress("dnn_WJetsBB", &dnn_WJetsBB, &b_dnn_WJetsBB);
   fChain->SetBranchAddress("dnn_ttbarBB", &dnn_ttbarBB, &b_dnn_ttbarBB);
   fChain->SetBranchAddress("dnn_Bprime", &dnn_Bprime, &b_dnn_Bprime);
   Notify();
}

Bool_t Mar2020treecontent::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Mar2020treecontent::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Mar2020treecontent::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Mar2020treecontent_cxx
