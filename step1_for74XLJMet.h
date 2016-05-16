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

using namespace std;

class step1 {
public :
   TTree          *inputTree;   //!pointer to the analyzed TTree or TChain
   TFile          *inputFile, *outputFile;
   Int_t           fCurrent; //!current Tree number in a TChain
   TFile          *filedataOverMChists;

   Bool_t          MistagSFup;
   Bool_t          MistagSFdn;
   Bool_t          isSig;
   Bool_t          isTOP;
   Bool_t          isMadgraphBkg;
   Bool_t          isMC;
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
   
   //Declaration of data/MC ratio hists
   TH1F           *hJet1Pt;
   TH1F           *hJet1PtE;
   TH1F           *hJet1PtM;
   TH1F           *hJet2Pt;
   TH1F           *hJet2PtE;
   TH1F           *hJet2PtM;
   TH1F           *hJet3Pt;
   TH1F           *hJet3PtE;
   TH1F           *hJet3PtM;
   TH1F           *hJet1Eta;
   TH1F           *hJet1EtaE;
   TH1F           *hJet1EtaM;
   TH1F           *hJet2Eta;
   TH1F           *hJet2EtaE;
   TH1F           *hJet2EtaM;
   TH1F           *hJet3Eta;
   TH1F           *hJet3EtaE;
   TH1F           *hJet3EtaM;
   TH1F           *hmet;
   TH1F           *hmetE;
   TH1F           *hmetM;

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t AK4HTpJetSFMETpLepPt;
   Float_t AK4HTnoSF;
   Double_t corr_JetSFmet_singleLepCalc;
   Double_t corr_JetSFmet_phi_singleLepCalc;
   Double_t corr_JetSFRawmet_singleLepCalc;
   Double_t corr_JetSFRawmet_phi_singleLepCalc;


   vector<double> WJetTaggedPtJMRup;      
   vector<double> WJetTaggedMassJMRup;
   vector<double> WJetTaggedPtJMRdn;      
   vector<double> WJetTaggedMassJMRdn;
   vector<double> WJetTaggedPtJMSup;      
   vector<double> WJetTaggedMassJMSup;
   vector<double> WJetTaggedPtJMSdn;      
   vector<double> WJetTaggedMassJMSdn;
   vector<double> WJetTaggedPtTAUup;      
   vector<double> WJetTaggedMassTAUup;
   vector<double> WJetTaggedPtTAUdn;      
   vector<double> WJetTaggedMassTAUdn;

   Int_t           isElectron;
   Int_t           isMuon;
   Int_t           CSCfiltered;
   Int_t           MCPastTrigger;
   Int_t           MCPastTriggerAlt;
   Int_t           DataPastTrigger;
   Int_t           DataPastTriggerAlt;
   Float_t         leptonPt_singleLepCalc;
   Float_t         leptonEta_singleLepCalc;
   Float_t         leptonPhi_singleLepCalc;
   Float_t         leptonEnergy_singleLepCalc;
   Float_t         leptonMiniIso_singleLepCalc;
   Float_t         leptonDxy_singleLepCalc;
   Float_t         leptonDz_singleLepCalc;
   Int_t           leptonCharge_singleLepCalc;
   vector<double>  theJetPt_JetSubCalc_new;
   vector<double>  theJetEta_JetSubCalc_new;
   vector<double>  theJetPhi_JetSubCalc_new;
   vector<double>  theJetEnergy_JetSubCalc_new;
   vector<double>  theJetAK8Pt_JetSubCalc_new;
   vector<double>  theJetAK8Eta_JetSubCalc_new;
   vector<double>  theJetAK8Phi_JetSubCalc_new;
   vector<double>  theJetAK8Mass_JetSubCalc_new;
   vector<double>  theJetAK8SoftDropMass_JetSubCalc_new;
   vector<double>  theJetAK8TrimmedMass_JetSubCalc_new;
   vector<double>  theJetAK8JetCharge_JetSubCalc_new; 
   vector<double>  theJetAK8PrunedMass_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8FilteredMass_JetSubCalc_new;
   vector<double>  theJetAK8NjettinessTau1_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8NjettinessTau2_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8NjettinessTau3_JetSubCalc_new;
   vector<double>  theJetPt_JetSubCalc_PtOrdered;
   vector<double>  theJetEta_JetSubCalc_PtOrdered;
   vector<double>  theJetPhi_JetSubCalc_PtOrdered;
   vector<double>  theJetEnergy_JetSubCalc_PtOrdered;
   vector<double>  theJetCSV_JetSubCalc_PtOrdered;
   vector<int>     theJetBTag_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8Pt_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8Eta_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8Phi_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8Mass_JetSubCalc_PtOrdered;
   vector<double>  theJetAK8Energy_JetSubCalc_PtOrdered;
   vector<double>  renormWeights;
   vector<double>  alphaSWeights;
   Float_t         BJetLeadPt_JetSubCalc;
   Float_t         BJetLeadPtWithSF_JetSubCalc;
   Float_t         WJetLeadPt_JetSubCalc;
   Float_t         AK4HTpMETpLepPt;
   Float_t         AK4HT;
   Float_t         minMleppBjetPt;
   Float_t         TotalWeight;
   Float_t         PVWeight;
   Float_t         PVWeightUp;
   Float_t         PVWeightDown;
   Float_t         pileupWeight;
   Float_t         pileupWeight72ub;
   Float_t         pileupWeightUp;
   Float_t         pileupWeightDown;
   Float_t         TrigEffAltWeight;
   Float_t         TrigEffWeight;
   Float_t         isoSF;
   Float_t         isoSFUp;
   Float_t         isoSFDown;
   Float_t         lepIdSF;
   Float_t         lepIdSFUp;
   Float_t         lepIdSFDown;
   Float_t         pdfUp;
   Float_t         pdfMean;
   Float_t         pdfDown;
   Float_t         renormUp;
   Float_t         renormDown;
   Int_t           NJets_JetSubCalc;
   Int_t           NJetsAK8_JetSubCalc;
   Int_t           NJetsCSV_JetSubCalc;
   Int_t           NJetsCSVwithSF_JetSubCalc;
   Int_t           NJetsWtagged;
   Int_t           NJetsHtagged;
   Float_t         topPt;
   Float_t         topPtGen;
   Float_t         topMass;
   Float_t         minMleppBjet;
   Float_t         minMleppJet;
   Float_t         genTopPt;
   Float_t         genAntiTopPt;
   Float_t         topPtWeight;
   Float_t         deltaRlepJetInMinMljet;
   Float_t         deltaPhilepJetInMinMljet;
   Float_t         deltaRlepbJetInMinMlb;
   Float_t         deltaPhilepbJetInMinMlb;
   Float_t         deltaRlepbJetNotInMinMlb;
   Float_t         HT_AllJets_MinusBestJet;
   Float_t         MT_AllJets_MinusBestJet;
   Float_t         Pt_AllJets_MinusBestJet;
   Float_t         M_AllJets_MinusBestJet;
   Float_t         M_taggedW_bjet1;
   Float_t         M_taggedW_bjet2;
   Float_t         HT_AllBjets;
   Float_t         HT_leading4jets;
   Float_t         HToverHT4;
   Float_t         deltaRlepbJet1;
   Float_t         deltaPhilepbJet1;
   Float_t         deltaRlepbJet2;
   Float_t         deltaPhilepbJet2;
   Float_t         deltaRtopWjet;
   Float_t         deltaPhitopWjet;
   Float_t         deltaRlepWjet;
   Float_t         deltaPhilepWjet;
   Float_t         deltaRtaggedWbJet1;
   Float_t         deltaPhitaggedWbJet1;
   Float_t         deltaRtaggedWbJet2;
   Float_t         deltaPhitaggedWbJet2;
   vector<double>  WJetDijetPt;
   vector<double>  WJetDijetMass;
   vector<double>  WJetTaggedPt;
   vector<double>  WJetTaggedMass;
   Int_t           isleadBjetTheBestJet;
   vector<double>  deltaR_lepJets;
   Float_t         deltaR_lepClosestJet;
   vector<double>  theJetAK8PrunedMassJMRSmeared_JetSubCalc;
   vector<double>  theJetAK8PrunedMassJMRSmearedUp_JetSubCalc;
   vector<double>  theJetAK8PrunedMassJMRSmearedDn_JetSubCalc;
   Int_t           NJetsWtagged_JMR;
   Int_t           NJetsWtagged_JMRup;
   Int_t           NJetsWtagged_JMRdn;
   Int_t           NJetsWtagged_JMSup;
   Int_t           NJetsWtagged_JMSdn;
   Int_t           NJetsWtagged_TAUup;
   Int_t           NJetsWtagged_TAUdn;
   Float_t         deltaPhilepMET;
   Float_t         PtRelLepClosestJet;

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
   Int_t           dataE_singleLepCalc;
   Int_t           dataM_singleLepCalc;
   Int_t           event_CommonCalc;
   Int_t           genTDLID_singleLepCalc;
   Int_t           lumi_CommonCalc;
   Int_t           nAllJets_CommonCalc;
   Int_t           nLooseElectrons_CommonCalc;
   Int_t           nLooseMuons_CommonCalc;
   Int_t           nPV_singleLepCalc;
   Int_t           nPileupInteractions_singleLepCalc;
   Int_t           nSelBtagJets_CommonCalc;
   Int_t           nSelElectrons_CommonCalc;
   Int_t           nSelJets_CommonCalc;
   Int_t           nSelMuons_CommonCalc;
   Int_t           nTrueInteractions_singleLepCalc;
   Int_t           run_CommonCalc;
   Double_t        AK4HT_singleLepCalc;
   Double_t        MCWeight_singleLepCalc;
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
   vector<bool>    *theJetAK8PrunedTau21Tag_JetSubCalc;
   vector<bool>    *theJetAK8SoftDropTau21Tag_JetSubCalc;
   vector<bool>    *theJetAK8SoftDropTau32Tag_JetSubCalc;
   vector<bool>    *theJetAK8caTopRun1Tag_JetSubCalc;
   vector<int>     *AK4JetBTag_singleLepCalc;
   vector<int>     *AK4JetFlav_singleLepCalc;
   vector<int>     *LHEWeightids_singleLepCalc;
   vector<int>     *LeptonID_TpTpCalc;
   vector<int>     *LeptonParentID_TpTpCalc;
   vector<int>     *bPrimeID_TpTpCalc;
   vector<int>     *bPrimeNDaughters_TpTpCalc;
   vector<int>     *bPrimeStatus_TpTpCalc;
   vector<int>     *bosonID_TpTpCalc;
   vector<int>     *elChargeConsistent_singleLepCalc;
   vector<int>     *elCharge_singleLepCalc;
   vector<int>     *elIDLevel25ns_singleLepCalc;
   vector<int>     *elIDLevel50ns_singleLepCalc;
   vector<int>     *elIsEBEE_singleLepCalc;
   vector<int>     *elMHits_singleLepCalc;
   vector<int>     *elMatched_singleLepCalc;
   vector<int>     *elMother_id_singleLepCalc;
   vector<int>     *elMother_status_singleLepCalc;
   vector<int>     *elNotConversion_singleLepCalc;
   vector<int>     *elNumberOfMothers_singleLepCalc;
   vector<int>     *elPdgId_singleLepCalc;
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
   vector<int>     *muIsLoose_singleLepCalc;
   vector<int>     *muIsMedium_singleLepCalc;
   vector<int>     *muIsTight_singleLepCalc;
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
   vector<int>     *theJetAK8SDSubjetIndex_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetNCSVL_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetNCSVM_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetNCSVMSF_JetSubCalc;
   vector<int>     *theJetAK8SDSubjetSize_JetSubCalc;
   vector<int>     *theJetAK8caTopSubjetIndex_JetSubCalc;
   vector<int>     *theJetAK8caTopSubjetNCSVL_JetSubCalc;
   vector<int>     *theJetAK8caTopSubjetNCSVM_JetSubCalc;
   vector<int>     *theJetAK8caTopSubjetSize_JetSubCalc;
   vector<int>     *theJetAK8caTopnSubJets_JetSubCalc;
   vector<int>     *theJetAK8nDaughters_JetSubCalc;
   vector<int>     *theJetBTagLoose_JetSubCalc;
   vector<int>     *theJetBTag_JetSubCalc;
   vector<int>     *theJetFlav_JetSubCalc;
   vector<int>     *theJetnDaughters_JetSubCalc;
   vector<int>     *topID_TTbarMassCalc;
   vector<int>     *viSelMCTriggersEl_singleLepCalc;
   vector<int>     *viSelMCTriggersMu_singleLepCalc;
   vector<int>     *viSelTriggersEl_singleLepCalc;
   vector<int>     *viSelTriggersMu_singleLepCalc;
   vector<double>  *AK4JetBDisc_singleLepCalc;
   vector<double>  *AK4JetEnergy_singleLepCalc;
   vector<double>  *AK4JetEta_singleLepCalc;
   vector<double>  *AK4JetPhi_singleLepCalc;
   vector<double>  *AK4JetPt_singleLepCalc;
   vector<double>  *AK8JetCSV_singleLepCalc;
   vector<double>  *AK8JetEnergy_singleLepCalc;
   vector<double>  *AK8JetEta_singleLepCalc;
   vector<double>  *AK8JetPhi_singleLepCalc;
   vector<double>  *AK8JetPt_singleLepCalc;
   vector<double>  *LHEWeights_singleLepCalc;
   vector<double>  *LeptonEnergy_TpTpCalc;
   vector<double>  *LeptonEta_TpTpCalc;
   vector<double>  *LeptonPhi_TpTpCalc;
   vector<double>  *LeptonPt_TpTpCalc;
   vector<double>  *bPrimeEnergy_TpTpCalc;
   vector<double>  *bPrimeEta_TpTpCalc;
   vector<double>  *bPrimeMass_TpTpCalc;
   vector<double>  *bPrimePhi_TpTpCalc;
   vector<double>  *bPrimePt_TpTpCalc;
   vector<double>  *bosonEnergy_TpTpCalc;
   vector<double>  *bosonEta_TpTpCalc;
   vector<double>  *bosonPhi_TpTpCalc;
   vector<double>  *bosonPt_TpTpCalc;
   vector<double>  *elAEff_singleLepCalc;
   vector<double>  *elChIso_singleLepCalc;
   vector<double>  *elD0_singleLepCalc;
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
   vector<double>  *elMVATrigValue_singleLepCalc;
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
   vector<double>  *elPhIso_singleLepCalc;
   vector<double>  *elPhiVtx_singleLepCalc;
   vector<double>  *elPhi_singleLepCalc;
   vector<double>  *elPt_singleLepCalc;
   vector<double>  *elRelIso_singleLepCalc;
   vector<double>  *elRhoIso_singleLepCalc;
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
   vector<double>  *muMatchedEnergy_singleLepCalc;
   vector<double>  *muMatchedEta_singleLepCalc;
   vector<double>  *muMatchedPhi_singleLepCalc;
   vector<double>  *muMatchedPt_singleLepCalc;
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
   vector<double>  *pfCombinedInclusiveSecondaryVertexV2BJetTags_BTagSFCalc;
   vector<double>  *pfCombinedMVABJetTags_BTagSFCalc;
   vector<double>  *pfCombinedSecondaryVertexV2BJetTags_BTagSFCalc;
   vector<double>  *pfJetBProbabilityBJetTags_BTagSFCalc;
   vector<double>  *pfJetProbabilityBJetTags_BTagSFCalc;
   vector<double>  *pfSimpleSecondaryVertexHighEffBJetTags_BTagSFCalc;
   vector<double>  *pfSimpleSecondaryVertexHighPurBJetTags_BTagSFCalc;
   vector<double>  *pfTrackCountingHighEffBJetTags_BTagSFCalc;
   vector<double>  *pfTrackCountingHighPurBJetTags_BTagSFCalc;
   vector<double>  *quarkEnergy_TpTpCalc;
   vector<double>  *quarkEta_TpTpCalc;
   vector<double>  *quarkPhi_TpTpCalc;
   vector<double>  *quarkPt_TpTpCalc;
   vector<double>  *tPrimeEnergy_TpTpCalc;
   vector<double>  *tPrimeEta_TpTpCalc;
   vector<double>  *tPrimeMass_TpTpCalc;
   vector<double>  *tPrimePhi_TpTpCalc;
   vector<double>  *tPrimePt_TpTpCalc;
   vector<double>  *theJetAK8CEmEFrac_JetSubCalc;
   vector<double>  *theJetAK8CEmEnergy_JetSubCalc;
   vector<double>  *theJetAK8CHadEFrac_JetSubCalc;
   vector<double>  *theJetAK8CHadEnergy_JetSubCalc;
   vector<double>  *theJetAK8CSV_JetSubCalc;
   vector<double>  *theJetAK8Energy_JetSubCalc;
   vector<double>  *theJetAK8Eta_JetSubCalc;
   vector<double>  *theJetAK8FilteredMass_JetSubCalc;
   vector<double>  *theJetAK8JetCharge_JetSubCalc;
   vector<double>  *theJetAK8Mass_JetSubCalc;
   vector<double>  *theJetAK8NEmEFrac_JetSubCalc;
   vector<double>  *theJetAK8NEmEnergy_JetSubCalc;
   vector<double>  *theJetAK8NHadEFrac_JetSubCalc;
   vector<double>  *theJetAK8NHadEnergy_JetSubCalc;
   vector<double>  *theJetAK8NjettinessTau1_JetSubCalc;
   vector<double>  *theJetAK8NjettinessTau2_JetSubCalc;
   vector<double>  *theJetAK8NjettinessTau3_JetSubCalc;
   vector<double>  *theJetAK8Phi_JetSubCalc;
   vector<double>  *theJetAK8PrunedMass_JetSubCalc;
   vector<double>  *theJetAK8Pt_JetSubCalc;
   vector<double>  *theJetAK8SDSubjetCSV_JetSubCalc;
   vector<double>  *theJetAK8SDSubjetDR_JetSubCalc;
   vector<double>  *theJetAK8SDSubjetEta_JetSubCalc;
   vector<double>  *theJetAK8SDSubjetMass_JetSubCalc;
   vector<double>  *theJetAK8SDSubjetPhi_JetSubCalc;
   vector<double>  *theJetAK8SDSubjetPt_JetSubCalc;
   vector<double>  *theJetAK8SoftDropMass_JetSubCalc;
   vector<double>  *theJetAK8TrimmedMass_JetSubCalc;
   vector<double>  *theJetAK8caTopMinMass_JetSubCalc;
   vector<double>  *theJetAK8caTopSubjetCSV_JetSubCalc;
   vector<double>  *theJetAK8caTopSubjetDR_JetSubCalc;
   vector<double>  *theJetAK8caTopSubjetEta_JetSubCalc;
   vector<double>  *theJetAK8caTopSubjetMass_JetSubCalc;
   vector<double>  *theJetAK8caTopSubjetPhi_JetSubCalc;
   vector<double>  *theJetAK8caTopSubjetPt_JetSubCalc;
   vector<double>  *theJetAK8caTopTopMass_JetSubCalc;
   vector<double>  *theJetCEmEFrac_JetSubCalc;
   vector<double>  *theJetCEmEnergy_JetSubCalc;
   vector<double>  *theJetCHadEFrac_JetSubCalc;
   vector<double>  *theJetCHadEnergy_JetSubCalc;
   vector<double>  *theJetCSV_JetSubCalc;
   vector<double>  *theJetEnergy_JetSubCalc;
   vector<double>  *theJetEta_JetSubCalc;
   vector<double>  *theJetMuonEFrac_JetSubCalc;
   vector<double>  *theJetNEmEFrac_JetSubCalc;
   vector<double>  *theJetNEmEnergy_JetSubCalc;
   vector<double>  *theJetNHadEFrac_JetSubCalc;
   vector<double>  *theJetNHadEnergy_JetSubCalc;
   vector<double>  *theJetPhi_JetSubCalc;
   vector<double>  *theJetPileupJetId_JetSubCalc;
   vector<double>  *theJetPt_JetSubCalc;
   vector<double>  *theJetVtx3DSig_JetSubCalc;
   vector<double>  *theJetVtx3DVal_JetSubCalc;
   vector<double>  *theJetVtxMass_JetSubCalc;
   vector<double>  *theJetVtxNtracks_JetSubCalc;
   vector<double>  *topEnergy_TTbarMassCalc;
   vector<double>  *topEta_TTbarMassCalc;
   vector<double>  *topMass_TTbarMassCalc;
   vector<double>  *topPhi_TTbarMassCalc;
   vector<double>  *topPt_TTbarMassCalc;
   vector<string>  *electron_hltfilters_singleLepCalc;
   vector<string>  *muon_hltfilters_singleLepCalc;
   vector<string>  *vsSelMCTriggersEl_singleLepCalc;
   vector<string>  *vsSelMCTriggersMu_singleLepCalc;
   vector<string>  *vsSelTriggersEl_singleLepCalc;
   vector<string>  *vsSelTriggersMu_singleLepCalc;
   vector<double>  *WPt_JetSubCalc;
   vector<double>  *WEta_JetSubCalc;
   vector<double>  *WPhi_JetSubCalc;
   vector<double>  *WEnergy_JetSubCalc;
   vector<double>  *WdecayDR_JetSubCalc;

   // List of branches
   TBranch        *b_isElectron;
   TBranch        *b_isMuon;
   TBranch        *b_CSCfiltered;
   TBranch        *b_MCPastTrigger;
   TBranch        *b_MCPastTriggerAlt;
   TBranch        *b_DataPastTrigger;
   TBranch        *b_DataPastTriggerAlt;
   TBranch        *b_leptonPt_singleLepCalc;
   TBranch        *b_leptonEta_singleLepCalc;
   TBranch        *b_leptonPhi_singleLepCalc;
   TBranch        *b_leptonEnergy_singleLepCalc;
   TBranch        *b_leptonMiniIso_singleLepCalc;
   TBranch        *b_leptonDxy_singleLepCalc;
   TBranch        *b_leptonDz_singleLepCalc;
   TBranch        *b_leptonCharge_singleLepCalc;
   TBranch        *b_theJetPt_JetSubCalc_new;
   TBranch        *b_theJetEta_JetSubCalc_new;
   TBranch        *b_theJetPhi_JetSubCalc_new;
   TBranch        *b_theJetEnergy_JetSubCalc_new;
   TBranch        *b_theJetAK8Pt_JetSubCalc_new;
   TBranch        *b_theJetAK8Eta_JetSubCalc_new;
   TBranch        *b_theJetAK8Phi_JetSubCalc_new;
   TBranch        *b_theJetAK8Mass_JetSubCalc_new;
   TBranch        *b_theJetAK8SoftDropMass_JetSubCalc_new;
   TBranch        *b_theJetAK8TrimmedMass_JetSubCalc_new;
   TBranch        *b_theJetAK8JetCharge_JetSubCalc_new; 
   TBranch        *b_theJetAK8PrunedMass_JetSubCalc_PtOrdered;
   TBranch        *b_theJetAK8FilteredMass_JetSubCalc_new;
   TBranch        *b_theJetAK8NjettinessTau1_JetSubCalc_PtOrdered;
   TBranch        *b_theJetAK8NjettinessTau2_JetSubCalc_PtOrdered;
   TBranch        *b_theJetAK8NjettinessTau3_JetSubCalc_new;
   TBranch        *b_theJetPt_JetSubCalc_PtOrdered;
   TBranch        *b_theJetEta_JetSubCalc_PtOrdered;
   TBranch        *b_theJetPhi_JetSubCalc_PtOrdered;
   TBranch        *b_theJetEnergy_JetSubCalc_PtOrdered;
   TBranch        *b_theJetCSV_JetSubCalc_PtOrdered;
   TBranch        *b_theJetBTag_JetSubCalc_PtOrdered;
   TBranch        *b_theJetAK8Pt_JetSubCalc_PtOrdered;
   TBranch        *b_theJetAK8Eta_JetSubCalc_PtOrdered;
   TBranch        *b_theJetAK8Phi_JetSubCalc_PtOrdered;
   TBranch        *b_theJetAK8Mass_JetSubCalc_PtOrdered;
   TBranch        *b_theJetAK8Energy_JetSubCalc_PtOrdered;
   TBranch        *b_renormWeights;
   TBranch        *b_alphaSWeights;
   TBranch        *b_BJetLeadPt_JetSubCalc;
   TBranch        *b_BJetLeadPtWithSF_JetSubCalc;
   TBranch        *b_WJetLeadPt_JetSubCalc;
   TBranch        *b_AK4HTpMETpLepPt;
   TBranch        *b_AK4HT;
   TBranch        *b_minMleppBjetPt;
   TBranch        *b_TotalWeight;
   TBranch        *b_PVWeight;
   TBranch        *b_PVWeightUp;
   TBranch        *b_PVWeightDown;
   TBranch        *b_pileupWeight;
   TBranch        *b_pileupWeight72ub;
   TBranch        *b_pileupWeightUp;
   TBranch        *b_pileupWeightDown;
   TBranch        *b_TrigEffAltWeight;
   TBranch        *b_TrigEffWeight;
   TBranch        *b_isoSF;
   TBranch        *b_isoSFUp;
   TBranch        *b_isoSFDown;
   TBranch        *b_lepIdSF;
   TBranch        *b_lepIdSFUp;
   TBranch        *b_lepIdSFDown;
   TBranch        *b_pdfUp;
   TBranch        *b_pdfMean;
   TBranch        *b_pdfDown;
   TBranch        *b_renormUp;
   TBranch        *b_renormDown;
   TBranch        *b_NJets_JetSubCalc;
   TBranch        *b_NJetsAK8_JetSubCalc;
   TBranch        *b_NJetsCSV_JetSubCalc;
   TBranch        *b_NJetsCSVwithSF_JetSubCalc;
   TBranch        *b_NJetsWtagged;
   TBranch        *b_NJetsHtagged;
   TBranch        *b_topPt;
   TBranch        *b_topPtGen;
   TBranch        *b_topMass;
   TBranch        *b_minMleppBjet;
   TBranch        *b_minMleppJet;
   TBranch        *b_genTopPt;
   TBranch        *b_genAntiTopPt;
   TBranch        *b_topPtWeight;
   TBranch        *b_deltaRlepJetInMinMljet;
   TBranch        *b_deltaPhilepJetInMinMljet;
   TBranch        *b_deltaRlepbJetInMinMlb;
   TBranch        *b_deltaPhilepbJetInMinMlb;
   TBranch        *b_deltaRlepbJetNotInMinMlb;
   TBranch        *b_HT_AllJets_MinusBestJet;
   TBranch        *b_MT_AllJets_MinusBestJet;
   TBranch        *b_Pt_AllJets_MinusBestJet;
   TBranch        *b_M_AllJets_MinusBestJet;
   TBranch        *b_M_taggedW_bjet1;
   TBranch        *b_M_taggedW_bjet2;
   TBranch        *b_HT_AllBjets;
   TBranch        *b_HT_leading4jets;
   TBranch        *b_HToverHT4;
   TBranch        *b_deltaRlepbJet1;
   TBranch        *b_deltaPhilepbJet1;
   TBranch        *b_deltaRlepbJet2;
   TBranch        *b_deltaPhilepbJet2;
   TBranch        *b_deltaRtopWjet;
   TBranch        *b_deltaPhitopWjet;
   TBranch        *b_deltaRlepWjet;
   TBranch        *b_deltaPhilepWjet;
   TBranch        *b_deltaRtaggedWbJet1;
   TBranch        *b_deltaPhitaggedWbJet1;
   TBranch        *b_deltaRtaggedWbJet2;
   TBranch        *b_deltaPhitaggedWbJet2;
   TBranch        *b_WJetDijetPt;
   TBranch        *b_WJetDijetMass;
   TBranch        *b_WJetTaggedPt;
   TBranch        *b_WJetTaggedMass;
   TBranch        *b_isleadBjetTheBestJet;
   TBranch        *b_deltaR_lepJets;
   TBranch        *b_deltaR_lepClosestJet;
   TBranch        *b_theJetAK8PrunedMassJMRSmeared_JetSubCalc;
   TBranch        *b_theJetAK8PrunedMassJMRSmearedUp_JetSubCalc;
   TBranch        *b_theJetAK8PrunedMassJMRSmearedDn_JetSubCalc;
   TBranch        *b_NJetsWtagged_JMR;
   TBranch        *b_NJetsWtagged_JMRup;
   TBranch        *b_NJetsWtagged_JMRdn;
   TBranch        *b_NJetsWtagged_JMSup;
   TBranch        *b_NJetsWtagged_JMSdn;
   TBranch        *b_NJetsWtagged_TAUup;
   TBranch        *b_NJetsWtagged_TAUdn;
   TBranch        *b_deltaPhilepMET;
   TBranch        *b_PtRelLepClosestJet;

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
   TBranch        *b_dataE_singleLepCalc;   //!
   TBranch        *b_dataM_singleLepCalc;   //!
   TBranch        *b_event_CommonCalc;   //!
   TBranch        *b_genTDLID_singleLepCalc;   //!
   TBranch        *b_lumi_CommonCalc;   //!
   TBranch        *b_nAllJets_CommonCalc;   //!
   TBranch        *b_nLooseElectrons_CommonCalc;   //!
   TBranch        *b_nLooseMuons_CommonCalc;   //!
   TBranch        *b_nPV_singleLepCalc;   //!
   TBranch        *b_nPileupInteractions_singleLepCalc;   //!
   TBranch        *b_nSelBtagJets_CommonCalc;   //!
   TBranch        *b_nSelElectrons_CommonCalc;   //!
   TBranch        *b_nSelJets_CommonCalc;   //!
   TBranch        *b_nSelMuons_CommonCalc;   //!
   TBranch        *b_nTrueInteractions_singleLepCalc;   //!
   TBranch        *b_run_CommonCalc;   //!
   TBranch        *b_AK4HT_singleLepCalc;   //!
   TBranch        *b_MCWeight_singleLepCalc;   //!
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
   TBranch        *b_theJetAK8PrunedTau21Tag_JetSubCalc;   //!
   TBranch        *b_theJetAK8SoftDropTau21Tag_JetSubCalc;   //!
   TBranch        *b_theJetAK8SoftDropTau32Tag_JetSubCalc;   //!
   TBranch        *b_theJetAK8caTopRun1Tag_JetSubCalc;   //!
   TBranch        *b_AK4JetBTag_singleLepCalc;   //!
   TBranch        *b_AK4JetFlav_singleLepCalc;   //!
   TBranch        *b_LHEWeightids_singleLepCalc;   //!
   TBranch        *b_LeptonID_TpTpCalc;   //!
   TBranch        *b_LeptonParentID_TpTpCalc;   //!
   TBranch        *b_bPrimeID_TpTpCalc;   //!
   TBranch        *b_bPrimeNDaughters_TpTpCalc;   //!
   TBranch        *b_bPrimeStatus_TpTpCalc;   //!
   TBranch        *b_bosonID_TpTpCalc;   //!
   TBranch        *b_elChargeConsistent_singleLepCalc;   //!
   TBranch        *b_elCharge_singleLepCalc;   //!
   TBranch        *b_elIDLevel25ns_singleLepCalc;   //!
   TBranch        *b_elIDLevel50ns_singleLepCalc;   //!
   TBranch        *b_elIsEBEE_singleLepCalc;   //!
   TBranch        *b_elMHits_singleLepCalc;   //!
   TBranch        *b_elMatched_singleLepCalc;   //!
   TBranch        *b_elMother_id_singleLepCalc;   //!
   TBranch        *b_elMother_status_singleLepCalc;   //!
   TBranch        *b_elNotConversion_singleLepCalc;   //!
   TBranch        *b_elNumberOfMothers_singleLepCalc;   //!
   TBranch        *b_elPdgId_singleLepCalc;   //!
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
   TBranch        *b_muIsLoose_singleLepCalc;   //!
   TBranch        *b_muIsMedium_singleLepCalc;   //!
   TBranch        *b_muIsTight_singleLepCalc;   //!
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
   TBranch        *b_theJetAK8SDSubjetIndex_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetNCSVL_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetNCSVM_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetNCSVMSF_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetSize_JetSubCalc;   //!
   TBranch        *b_theJetAK8caTopSubjetIndex_JetSubCalc;   //!
   TBranch        *b_theJetAK8caTopSubjetNCSVL_JetSubCalc;   //!
   TBranch        *b_theJetAK8caTopSubjetNCSVM_JetSubCalc;   //!
   TBranch        *b_theJetAK8caTopSubjetSize_JetSubCalc;   //!
   TBranch        *b_theJetAK8caTopnSubJets_JetSubCalc;   //!
   TBranch        *b_theJetAK8nDaughters_JetSubCalc;   //!
   TBranch        *b_theJetBTagLoose_JetSubCalc;   //!
   TBranch        *b_theJetBTag_JetSubCalc;   //!
   TBranch        *b_theJetFlav_JetSubCalc;   //!
   TBranch        *b_theJetnDaughters_JetSubCalc;   //!
   TBranch        *b_topID_TTbarMassCalc;   //!
   TBranch        *b_viSelMCTriggersEl_singleLepCalc;   //!
   TBranch        *b_viSelMCTriggersMu_singleLepCalc;   //!
   TBranch        *b_viSelTriggersEl_singleLepCalc;   //!
   TBranch        *b_viSelTriggersMu_singleLepCalc;   //!
   TBranch        *b_AK4JetBDisc_singleLepCalc;   //!
   TBranch        *b_AK4JetEnergy_singleLepCalc;   //!
   TBranch        *b_AK4JetEta_singleLepCalc;   //!
   TBranch        *b_AK4JetPhi_singleLepCalc;   //!
   TBranch        *b_AK4JetPt_singleLepCalc;   //!
   TBranch        *b_AK8JetCSV_singleLepCalc;   //!
   TBranch        *b_AK8JetEnergy_singleLepCalc;   //!
   TBranch        *b_AK8JetEta_singleLepCalc;   //!
   TBranch        *b_AK8JetPhi_singleLepCalc;   //!
   TBranch        *b_AK8JetPt_singleLepCalc;   //!
   TBranch        *b_LHEWeights_singleLepCalc;   //!
   TBranch        *b_LeptonEnergy_TpTpCalc;   //!
   TBranch        *b_LeptonEta_TpTpCalc;   //!
   TBranch        *b_LeptonPhi_TpTpCalc;   //!
   TBranch        *b_LeptonPt_TpTpCalc;   //!
   TBranch        *b_bPrimeEnergy_TpTpCalc;   //!
   TBranch        *b_bPrimeEta_TpTpCalc;   //!
   TBranch        *b_bPrimeMass_TpTpCalc;   //!
   TBranch        *b_bPrimePhi_TpTpCalc;   //!
   TBranch        *b_bPrimePt_TpTpCalc;   //!
   TBranch        *b_bosonEnergy_TpTpCalc;   //!
   TBranch        *b_bosonEta_TpTpCalc;   //!
   TBranch        *b_bosonPhi_TpTpCalc;   //!
   TBranch        *b_bosonPt_TpTpCalc;   //!
   TBranch        *b_elAEff_singleLepCalc;   //!
   TBranch        *b_elChIso_singleLepCalc;   //!
   TBranch        *b_elD0_singleLepCalc;   //!
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
   TBranch        *b_elMVATrigValue_singleLepCalc;   //!
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
   TBranch        *b_elPhIso_singleLepCalc;   //!
   TBranch        *b_elPhiVtx_singleLepCalc;   //!
   TBranch        *b_elPhi_singleLepCalc;   //!
   TBranch        *b_elPt_singleLepCalc;   //!
   TBranch        *b_elRelIso_singleLepCalc;   //!
   TBranch        *b_elRhoIso_singleLepCalc;   //!
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
   TBranch        *b_muMatchedEnergy_singleLepCalc;   //!
   TBranch        *b_muMatchedEta_singleLepCalc;   //!
   TBranch        *b_muMatchedPhi_singleLepCalc;   //!
   TBranch        *b_muMatchedPt_singleLepCalc;   //!
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
   TBranch        *b_pfCombinedInclusiveSecondaryVertexV2BJetTags_BTagSFCalc;   //!
   TBranch        *b_pfCombinedMVABJetTags_BTagSFCalc;   //!
   TBranch        *b_pfCombinedSecondaryVertexV2BJetTags_BTagSFCalc;   //!
   TBranch        *b_pfJetBProbabilityBJetTags_BTagSFCalc;   //!
   TBranch        *b_pfJetProbabilityBJetTags_BTagSFCalc;   //!
   TBranch        *b_pfSimpleSecondaryVertexHighEffBJetTags_BTagSFCalc;   //!
   TBranch        *b_pfSimpleSecondaryVertexHighPurBJetTags_BTagSFCalc;   //!
   TBranch        *b_pfTrackCountingHighEffBJetTags_BTagSFCalc;   //!
   TBranch        *b_pfTrackCountingHighPurBJetTags_BTagSFCalc;   //!
   TBranch        *b_quarkEnergy_TpTpCalc;   //!
   TBranch        *b_quarkEta_TpTpCalc;   //!
   TBranch        *b_quarkPhi_TpTpCalc;   //!
   TBranch        *b_quarkPt_TpTpCalc;   //!
   TBranch        *b_tPrimeEnergy_TpTpCalc;   //!
   TBranch        *b_tPrimeEta_TpTpCalc;   //!
   TBranch        *b_tPrimeMass_TpTpCalc;   //!
   TBranch        *b_tPrimePhi_TpTpCalc;   //!
   TBranch        *b_tPrimePt_TpTpCalc;   //!
   TBranch        *b_WPt_JetSubCalc;
   TBranch        *b_WEta_JetSubCalc;
   TBranch        *b_WPhi_JetSubCalc;
   TBranch        *b_WEnergy_JetSubCalc;
   TBranch        *b_WdecayDR_JetSubCalc;
   TBranch        *b_theJetAK8CEmEFrac_JetSubCalc;   //!
   TBranch        *b_theJetAK8CEmEnergy_JetSubCalc;   //!
   TBranch        *b_theJetAK8CHadEFrac_JetSubCalc;   //!
   TBranch        *b_theJetAK8CHadEnergy_JetSubCalc;   //!
   TBranch        *b_theJetAK8CSV_JetSubCalc;   //!
   TBranch        *b_theJetAK8Energy_JetSubCalc;   //!
   TBranch        *b_theJetAK8Eta_JetSubCalc;   //!
   TBranch        *b_theJetAK8FilteredMass_JetSubCalc;   //!
   TBranch        *b_theJetAK8JetCharge_JetSubCalc;   //!
   TBranch        *b_theJetAK8Mass_JetSubCalc;   //!
   TBranch        *b_theJetAK8NEmEFrac_JetSubCalc;   //!
   TBranch        *b_theJetAK8NEmEnergy_JetSubCalc;   //!
   TBranch        *b_theJetAK8NHadEFrac_JetSubCalc;   //!
   TBranch        *b_theJetAK8NHadEnergy_JetSubCalc;   //!
   TBranch        *b_theJetAK8NjettinessTau1_JetSubCalc;   //!
   TBranch        *b_theJetAK8NjettinessTau2_JetSubCalc;   //!
   TBranch        *b_theJetAK8NjettinessTau3_JetSubCalc;   //!
   TBranch        *b_theJetAK8Phi_JetSubCalc;   //!
   TBranch        *b_theJetAK8PrunedMass_JetSubCalc;   //!
   TBranch        *b_theJetAK8Pt_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetCSV_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetDR_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetEta_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetMass_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetPhi_JetSubCalc;   //!
   TBranch        *b_theJetAK8SDSubjetPt_JetSubCalc;   //!
   TBranch        *b_theJetAK8SoftDropMass_JetSubCalc;   //!
   TBranch        *b_theJetAK8TrimmedMass_JetSubCalc;   //!
   TBranch        *b_theJetAK8caTopMinMass_JetSubCalc;   //!
   TBranch        *b_theJetAK8caTopSubjetCSV_JetSubCalc;   //!
   TBranch        *b_theJetAK8caTopSubjetDR_JetSubCalc;   //!
   TBranch        *b_theJetAK8caTopSubjetEta_JetSubCalc;   //!
   TBranch        *b_theJetAK8caTopSubjetMass_JetSubCalc;   //!
   TBranch        *b_theJetAK8caTopSubjetPhi_JetSubCalc;   //!
   TBranch        *b_theJetAK8caTopSubjetPt_JetSubCalc;   //!
   TBranch        *b_theJetAK8caTopTopMass_JetSubCalc;   //!
   TBranch        *b_theJetCEmEFrac_JetSubCalc;   //!
   TBranch        *b_theJetCEmEnergy_JetSubCalc;   //!
   TBranch        *b_theJetCHadEFrac_JetSubCalc;   //!
   TBranch        *b_theJetCHadEnergy_JetSubCalc;   //!
   TBranch        *b_theJetCSV_JetSubCalc;   //!
   TBranch        *b_theJetEnergy_JetSubCalc;   //!
   TBranch        *b_theJetEta_JetSubCalc;   //!
   TBranch        *b_theJetMuonEFrac_JetSubCalc;   //!
   TBranch        *b_theJetNEmEFrac_JetSubCalc;   //!
   TBranch        *b_theJetNEmEnergy_JetSubCalc;   //!
   TBranch        *b_theJetNHadEFrac_JetSubCalc;   //!
   TBranch        *b_theJetNHadEnergy_JetSubCalc;   //!
   TBranch        *b_theJetPhi_JetSubCalc;   //!
   TBranch        *b_theJetPileupJetId_JetSubCalc;   //!
   TBranch        *b_theJetPt_JetSubCalc;   //!
   TBranch        *b_theJetVtx3DSig_JetSubCalc;   //!
   TBranch        *b_theJetVtx3DVal_JetSubCalc;   //!
   TBranch        *b_theJetVtxMass_JetSubCalc;   //!
   TBranch        *b_theJetVtxNtracks_JetSubCalc;   //!
   TBranch        *b_topEnergy_TTbarMassCalc;   //!
   TBranch        *b_topEta_TTbarMassCalc;   //!
   TBranch        *b_topMass_TTbarMassCalc;   //!
   TBranch        *b_topPhi_TTbarMassCalc;   //!
   TBranch        *b_topPt_TTbarMassCalc;   //!
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
};

#endif

#ifdef step1_cxx
step1::step1(TString inputFileName, TString outputFileName) : inputTree(0), inputFile(0), outputFile(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.

  MistagSFup = outputFileName.Contains("BTAGup");
  MistagSFdn = outputFileName.Contains("BTAGdown");
  isSig  = inputFileName.Contains("prime") || inputFileName.Contains("X53");
  isMadgraphBkg = inputFileName.Contains("WJetsToLNu_HT") || inputFileName.Contains("QCD");
  isTOP = (inputFileName.Contains("Mtt") || inputFileName.Contains("ST") || inputFileName.Contains("TTZ_") || inputFileName.Contains("TTW_") || inputFileName.Contains("TT_Tune"));
  isMC      = !inputFileName.Contains("Single");
  isTTincMtt0to700    = outputFileName.Contains("Mtt0to700");
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
   theJetAK8PrunedTau21Tag_JetSubCalc = 0;
   theJetAK8SoftDropTau21Tag_JetSubCalc = 0;
   theJetAK8SoftDropTau32Tag_JetSubCalc = 0;
   theJetAK8caTopRun1Tag_JetSubCalc = 0;
   AK4JetBTag_singleLepCalc = 0;
   AK4JetFlav_singleLepCalc = 0;
   LHEWeightids_singleLepCalc = 0;
   LeptonID_TpTpCalc = 0;
   LeptonParentID_TpTpCalc = 0;
   bPrimeID_TpTpCalc = 0;
   bPrimeNDaughters_TpTpCalc = 0;
   bPrimeStatus_TpTpCalc = 0;
   bosonID_TpTpCalc = 0;
   elChargeConsistent_singleLepCalc = 0;
   elCharge_singleLepCalc = 0;
   elIDLevel25ns_singleLepCalc = 0;
   elIDLevel50ns_singleLepCalc = 0;
   elIsEBEE_singleLepCalc = 0;
   elMHits_singleLepCalc = 0;
   elMatched_singleLepCalc = 0;
   elMother_id_singleLepCalc = 0;
   elMother_status_singleLepCalc = 0;
   elNotConversion_singleLepCalc = 0;
   elNumberOfMothers_singleLepCalc = 0;
   elPdgId_singleLepCalc = 0;
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
   muIsLoose_singleLepCalc = 0;
   muIsMedium_singleLepCalc = 0;
   muIsTight_singleLepCalc = 0;
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
   theJetAK8SDSubjetIndex_JetSubCalc = 0;
   theJetAK8SDSubjetNCSVL_JetSubCalc = 0;
   theJetAK8SDSubjetNCSVM_JetSubCalc = 0;
   theJetAK8SDSubjetNCSVMSF_JetSubCalc = 0;
   theJetAK8SDSubjetSize_JetSubCalc = 0;
   theJetAK8caTopSubjetIndex_JetSubCalc = 0;
   theJetAK8caTopSubjetNCSVL_JetSubCalc = 0;
   theJetAK8caTopSubjetNCSVM_JetSubCalc = 0;
   theJetAK8caTopSubjetSize_JetSubCalc = 0;
   theJetAK8caTopnSubJets_JetSubCalc = 0;
   theJetAK8nDaughters_JetSubCalc = 0;
   theJetBTagLoose_JetSubCalc = 0;
   theJetBTag_JetSubCalc = 0;
   theJetFlav_JetSubCalc = 0;
   theJetnDaughters_JetSubCalc = 0;
   topID_TTbarMassCalc = 0;
   viSelMCTriggersEl_singleLepCalc = 0;
   viSelMCTriggersMu_singleLepCalc = 0;
   viSelTriggersEl_singleLepCalc = 0;
   viSelTriggersMu_singleLepCalc = 0;
   AK4JetBDisc_singleLepCalc = 0;
   AK4JetEnergy_singleLepCalc = 0;
   AK4JetEta_singleLepCalc = 0;
   AK4JetPhi_singleLepCalc = 0;
   AK4JetPt_singleLepCalc = 0;
   AK8JetCSV_singleLepCalc = 0;
   AK8JetEnergy_singleLepCalc = 0;
   AK8JetEta_singleLepCalc = 0;
   AK8JetPhi_singleLepCalc = 0;
   AK8JetPt_singleLepCalc = 0;
   LHEWeights_singleLepCalc = 0;
   LeptonEnergy_TpTpCalc = 0;
   LeptonEta_TpTpCalc = 0;
   LeptonPhi_TpTpCalc = 0;
   LeptonPt_TpTpCalc = 0;
   bPrimeEnergy_TpTpCalc = 0;
   bPrimeEta_TpTpCalc = 0;
   bPrimeMass_TpTpCalc = 0;
   bPrimePhi_TpTpCalc = 0;
   bPrimePt_TpTpCalc = 0;
   bosonEnergy_TpTpCalc = 0;
   bosonEta_TpTpCalc = 0;
   bosonPhi_TpTpCalc = 0;
   bosonPt_TpTpCalc = 0;
   elAEff_singleLepCalc = 0;
   elChIso_singleLepCalc = 0;
   elD0_singleLepCalc = 0;
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
   elMVATrigValue_singleLepCalc = 0;
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
   elPhIso_singleLepCalc = 0;
   elPhiVtx_singleLepCalc = 0;
   elPhi_singleLepCalc = 0;
   elPt_singleLepCalc = 0;
   elRelIso_singleLepCalc = 0;
   elRhoIso_singleLepCalc = 0;
   elSihih_singleLepCalc = 0;
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
   muChIso_singleLepCalc = 0;
   muChi2_singleLepCalc = 0;
   muDxy_singleLepCalc = 0;
   muDz_singleLepCalc = 0;
   muEnergy_singleLepCalc = 0;
   muEta_singleLepCalc = 0;
   muGIso_singleLepCalc = 0;
   muGen_Reco_dr_singleLepCalc = 0;
   muMatchedEnergy_singleLepCalc = 0;
   muMatchedEta_singleLepCalc = 0;
   muMatchedPhi_singleLepCalc = 0;
   muMatchedPt_singleLepCalc = 0;
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
   pfCombinedInclusiveSecondaryVertexV2BJetTags_BTagSFCalc = 0;
   pfCombinedMVABJetTags_BTagSFCalc = 0;
   pfCombinedSecondaryVertexV2BJetTags_BTagSFCalc = 0;
   pfJetBProbabilityBJetTags_BTagSFCalc = 0;
   pfJetProbabilityBJetTags_BTagSFCalc = 0;
   pfSimpleSecondaryVertexHighEffBJetTags_BTagSFCalc = 0;
   pfSimpleSecondaryVertexHighPurBJetTags_BTagSFCalc = 0;
   pfTrackCountingHighEffBJetTags_BTagSFCalc = 0;
   pfTrackCountingHighPurBJetTags_BTagSFCalc = 0;
   quarkEnergy_TpTpCalc = 0;
   quarkEta_TpTpCalc = 0;
   quarkPhi_TpTpCalc = 0;
   quarkPt_TpTpCalc = 0;
   tPrimeEnergy_TpTpCalc = 0;
   tPrimeEta_TpTpCalc = 0;
   tPrimeMass_TpTpCalc = 0;
   tPrimePhi_TpTpCalc = 0;
   tPrimePt_TpTpCalc = 0;
   theJetAK8CEmEFrac_JetSubCalc = 0;
   theJetAK8CEmEnergy_JetSubCalc = 0;
   theJetAK8CHadEFrac_JetSubCalc = 0;
   theJetAK8CHadEnergy_JetSubCalc = 0;
   theJetAK8CSV_JetSubCalc = 0;
   theJetAK8Energy_JetSubCalc = 0;
   theJetAK8Eta_JetSubCalc = 0;
   theJetAK8FilteredMass_JetSubCalc = 0;
   theJetAK8JetCharge_JetSubCalc = 0;
   theJetAK8Mass_JetSubCalc = 0;
   theJetAK8NEmEFrac_JetSubCalc = 0;
   theJetAK8NEmEnergy_JetSubCalc = 0;
   theJetAK8NHadEFrac_JetSubCalc = 0;
   theJetAK8NHadEnergy_JetSubCalc = 0;
   theJetAK8NjettinessTau1_JetSubCalc = 0;
   theJetAK8NjettinessTau2_JetSubCalc = 0;
   theJetAK8NjettinessTau3_JetSubCalc = 0;
   theJetAK8Phi_JetSubCalc = 0;
   theJetAK8PrunedMass_JetSubCalc = 0;
   theJetAK8Pt_JetSubCalc = 0;
   theJetAK8SDSubjetCSV_JetSubCalc = 0;
   theJetAK8SDSubjetDR_JetSubCalc = 0;
   theJetAK8SDSubjetEta_JetSubCalc = 0;
   theJetAK8SDSubjetMass_JetSubCalc = 0;
   theJetAK8SDSubjetPhi_JetSubCalc = 0;
   theJetAK8SDSubjetPt_JetSubCalc = 0;
   theJetAK8SoftDropMass_JetSubCalc = 0;
   theJetAK8TrimmedMass_JetSubCalc = 0;
   theJetAK8caTopMinMass_JetSubCalc = 0;
   theJetAK8caTopSubjetCSV_JetSubCalc = 0;
   theJetAK8caTopSubjetDR_JetSubCalc = 0;
   theJetAK8caTopSubjetEta_JetSubCalc = 0;
   theJetAK8caTopSubjetMass_JetSubCalc = 0;
   theJetAK8caTopSubjetPhi_JetSubCalc = 0;
   theJetAK8caTopSubjetPt_JetSubCalc = 0;
   theJetAK8caTopTopMass_JetSubCalc = 0;
   theJetCEmEFrac_JetSubCalc = 0;
   theJetCEmEnergy_JetSubCalc = 0;
   theJetCHadEFrac_JetSubCalc = 0;
   theJetCHadEnergy_JetSubCalc = 0;
   theJetCSV_JetSubCalc = 0;
   theJetEnergy_JetSubCalc = 0;
   theJetEta_JetSubCalc = 0;
   theJetMuonEFrac_JetSubCalc = 0;
   theJetNEmEFrac_JetSubCalc = 0;
   theJetNEmEnergy_JetSubCalc = 0;
   theJetNHadEFrac_JetSubCalc = 0;
   theJetNHadEnergy_JetSubCalc = 0;
   theJetPhi_JetSubCalc = 0;
   theJetPileupJetId_JetSubCalc = 0;
   theJetPt_JetSubCalc = 0;
   theJetVtx3DSig_JetSubCalc = 0;
   theJetVtx3DVal_JetSubCalc = 0;
   theJetVtxMass_JetSubCalc = 0;
   theJetVtxNtracks_JetSubCalc = 0;
   topEnergy_TTbarMassCalc = 0;
   topEta_TTbarMassCalc = 0;
   topMass_TTbarMassCalc = 0;
   topPhi_TTbarMassCalc = 0;
   topPt_TTbarMassCalc = 0;
   electron_hltfilters_singleLepCalc = 0;
   muon_hltfilters_singleLepCalc = 0;
   vsSelMCTriggersEl_singleLepCalc = 0;
   vsSelMCTriggersMu_singleLepCalc = 0;
   vsSelTriggersEl_singleLepCalc = 0;
   vsSelTriggersMu_singleLepCalc = 0;
   WPt_JetSubCalc = 0;
   WEta_JetSubCalc = 0;
   WPhi_JetSubCalc = 0;
   WEnergy_JetSubCalc = 0;
   WdecayDR_JetSubCalc = 0;

   // Set branch addresses and branch pointers
   if (!tree) return;
   inputTree = tree;
   fCurrent = -1;
   inputTree->SetMakeClass(1);
   b_isElectron=inputTree->Branch("isElectron",&isElectron,"isElectron/I");
   b_isMuon=inputTree->Branch("isMuon",&isMuon,"isMuon/I");
   b_CSCfiltered=inputTree->Branch("CSCfiltered",&CSCfiltered,"CSCfiltered/I");
   b_MCPastTrigger=inputTree->Branch("MCPastTrigger",&MCPastTrigger,"MCPastTrigger/I");
   b_MCPastTriggerAlt=inputTree->Branch("MCPastTriggerAlt",&MCPastTriggerAlt,"MCPastTriggerAlt/I");
   b_DataPastTrigger=inputTree->Branch("DataPastTrigger",&DataPastTrigger,"DataPastTrigger/I");
   b_DataPastTriggerAlt=inputTree->Branch("DataPastTriggerAlt",&DataPastTriggerAlt,"DataPastTriggerAlt/I");
   b_leptonPt_singleLepCalc=inputTree->Branch("leptonPt_singleLepCalc",&leptonPt_singleLepCalc,"leptonPt_singleLepCalc/F");
   b_leptonEta_singleLepCalc=inputTree->Branch("leptonEta_singleLepCalc",&leptonEta_singleLepCalc,"leptonEta_singleLepCalc/F");
   b_leptonPhi_singleLepCalc=inputTree->Branch("leptonPhi_singleLepCalc",&leptonPhi_singleLepCalc,"leptonPhi_singleLepCalc/F");
   b_leptonEnergy_singleLepCalc=inputTree->Branch("leptonEnergy_singleLepCalc",&leptonEnergy_singleLepCalc,"leptonEnergy_singleLepCalc/F");
   b_leptonMiniIso_singleLepCalc=inputTree->Branch("leptonMiniIso_singleLepCalc",&leptonMiniIso_singleLepCalc,"leptonMiniIso_singleLepCalc/F");
   b_leptonDxy_singleLepCalc=inputTree->Branch("leptonDxy_singleLepCalc",&leptonDxy_singleLepCalc,"leptonDxy_singleLepCalc/F");
   b_leptonDz_singleLepCalc=inputTree->Branch("leptonDz_singleLepCalc",&leptonDz_singleLepCalc,"leptonDz_singleLepCalc/F");
   b_leptonCharge_singleLepCalc=inputTree->Branch("leptonCharge_singleLepCalc",&leptonCharge_singleLepCalc,"leptonCharge_singleLepCalc/I");
   b_theJetPt_JetSubCalc_new=inputTree->Branch("theJetPt_JetSubCalc_new",&theJetPt_JetSubCalc_new);
   b_theJetEta_JetSubCalc_new=inputTree->Branch("theJetEta_JetSubCalc_new",&theJetEta_JetSubCalc_new);
   b_theJetPhi_JetSubCalc_new=inputTree->Branch("theJetPhi_JetSubCalc_new",&theJetPhi_JetSubCalc_new);
   b_theJetEnergy_JetSubCalc_new=inputTree->Branch("theJetEnergy_JetSubCalc_new",&theJetEnergy_JetSubCalc_new);
   b_theJetAK8Pt_JetSubCalc_new=inputTree->Branch("theJetAK8Pt_JetSubCalc_new",&theJetAK8Pt_JetSubCalc_new);
   b_theJetAK8Eta_JetSubCalc_new=inputTree->Branch("theJetAK8Eta_JetSubCalc_new",&theJetAK8Eta_JetSubCalc_new);
   b_theJetAK8Phi_JetSubCalc_new=inputTree->Branch("theJetAK8Phi_JetSubCalc_new",&theJetAK8Phi_JetSubCalc_new);
   b_theJetAK8Mass_JetSubCalc_new=inputTree->Branch("theJetAK8Mass_JetSubCalc_new",&theJetAK8Mass_JetSubCalc_new);
   b_theJetAK8SoftDropMass_JetSubCalc_new=inputTree->Branch("theJetAK8SoftDropMass_JetSubCalc_new",&theJetAK8SoftDropMass_JetSubCalc_new);
   b_theJetAK8TrimmedMass_JetSubCalc_new=inputTree->Branch("theJetAK8TrimmedMass_JetSubCalc_new",&theJetAK8TrimmedMass_JetSubCalc_new);
   b_theJetAK8JetCharge_JetSubCalc_new=inputTree->Branch("theJetAK8JetCharge_JetSubCalc_new",&theJetAK8JetCharge_JetSubCalc_new); 
   b_theJetAK8PrunedMass_JetSubCalc_PtOrdered=inputTree->Branch("theJetAK8PrunedMass_JetSubCalc_PtOrdered",&theJetAK8PrunedMass_JetSubCalc_PtOrdered);
   b_theJetAK8FilteredMass_JetSubCalc_new=inputTree->Branch("theJetAK8FilteredMass_JetSubCalc_new",&theJetAK8FilteredMass_JetSubCalc_new);
   b_theJetAK8NjettinessTau1_JetSubCalc_PtOrdered=inputTree->Branch("theJetAK8NjettinessTau1_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau1_JetSubCalc_PtOrdered);
   b_theJetAK8NjettinessTau2_JetSubCalc_PtOrdered=inputTree->Branch("theJetAK8NjettinessTau2_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau2_JetSubCalc_PtOrdered);
   b_theJetAK8NjettinessTau3_JetSubCalc_new=inputTree->Branch("theJetAK8NjettinessTau3_JetSubCalc_new",&theJetAK8NjettinessTau3_JetSubCalc_new);
   b_theJetPt_JetSubCalc_PtOrdered=inputTree->Branch("theJetPt_JetSubCalc_PtOrdered",&theJetPt_JetSubCalc_PtOrdered);
   b_theJetEta_JetSubCalc_PtOrdered=inputTree->Branch("theJetEta_JetSubCalc_PtOrdered",&theJetEta_JetSubCalc_PtOrdered);
   b_theJetPhi_JetSubCalc_PtOrdered=inputTree->Branch("theJetPhi_JetSubCalc_PtOrdered",&theJetPhi_JetSubCalc_PtOrdered);
   b_theJetEnergy_JetSubCalc_PtOrdered=inputTree->Branch("theJetEnergy_JetSubCalc_PtOrdered",&theJetEnergy_JetSubCalc_PtOrdered);
   b_theJetCSV_JetSubCalc_PtOrdered=inputTree->Branch("theJetCSV_JetSubCalc_PtOrdered",&theJetCSV_JetSubCalc_PtOrdered);
   b_theJetBTag_JetSubCalc_PtOrdered=inputTree->Branch("theJetBTag_JetSubCalc_PtOrdered",&theJetBTag_JetSubCalc_PtOrdered);
   b_theJetAK8Pt_JetSubCalc_PtOrdered=inputTree->Branch("theJetAK8Pt_JetSubCalc_PtOrdered",&theJetAK8Pt_JetSubCalc_PtOrdered);
   b_theJetAK8Eta_JetSubCalc_PtOrdered=inputTree->Branch("theJetAK8Eta_JetSubCalc_PtOrdered",&theJetAK8Eta_JetSubCalc_PtOrdered);
   b_theJetAK8Phi_JetSubCalc_PtOrdered=inputTree->Branch("theJetAK8Phi_JetSubCalc_PtOrdered",&theJetAK8Phi_JetSubCalc_PtOrdered);
   b_theJetAK8Mass_JetSubCalc_PtOrdered=inputTree->Branch("theJetAK8Mass_JetSubCalc_PtOrdered",&theJetAK8Mass_JetSubCalc_PtOrdered);
   b_theJetAK8Energy_JetSubCalc_PtOrdered=inputTree->Branch("theJetAK8Energy_JetSubCalc_PtOrdered",&theJetAK8Energy_JetSubCalc_PtOrdered);
   b_renormWeights=inputTree->Branch("renormWeights",&renormWeights);
   b_alphaSWeights=inputTree->Branch("alphaSWeights",&alphaSWeights);
   b_BJetLeadPt_JetSubCalc=inputTree->Branch("BJetLeadPt_JetSubCalc",&BJetLeadPt_JetSubCalc,"BJetLeadPt_JetSubCalc/F");
   b_BJetLeadPtWithSF_JetSubCalc=inputTree->Branch("BJetLeadPtWithSF_JetSubCalc",&BJetLeadPtWithSF_JetSubCalc,"BJetLeadPtWithSF_JetSubCalc/F");
   b_WJetLeadPt_JetSubCalc=inputTree->Branch("WJetLeadPt_JetSubCalc",&WJetLeadPt_JetSubCalc,"WJetLeadPt_JetSubCalc/F");
   b_AK4HTpMETpLepPt=inputTree->Branch("AK4HTpMETpLepPt",&AK4HTpMETpLepPt,"AK4HTpMETpLepPt/F");
   b_AK4HT=inputTree->Branch("AK4HT",&AK4HT,"AK4HT/F");
   b_minMleppBjetPt=inputTree->Branch("minMleppBjetPt",&minMleppBjetPt,"minMleppBjetPt/F");
   b_TotalWeight=inputTree->Branch("TotalWeight",&TotalWeight,"TotalWeight/F");
   b_PVWeight=inputTree->Branch("PVWeight",&PVWeight,"PVWeight/F");
   b_PVWeightUp=inputTree->Branch("PVWeightUp",&PVWeightUp,"PVWeightUp/F");
   b_PVWeightDown=inputTree->Branch("PVWeightDown",&PVWeightDown,"PVWeightDown/F");
   b_pileupWeight=inputTree->Branch("pileupWeight",&pileupWeight,"pileupWeight/F");
   b_pileupWeight72ub=inputTree->Branch("pileupWeight72ub",&pileupWeight72ub,"pileupWeight72ub/F");
   b_pileupWeightUp=inputTree->Branch("pileupWeightUp",&pileupWeightUp,"pileupWeightUp/F");
   b_pileupWeightDown=inputTree->Branch("pileupWeightDown",&pileupWeightDown,"pileupWeightDown/F");
   b_TrigEffAltWeight=inputTree->Branch("TrigEffAltWeight",&TrigEffAltWeight,"TrigEffAltWeight/F");
   b_TrigEffWeight=inputTree->Branch("TrigEffWeight",&TrigEffWeight,"TrigEffWeight/F");
   b_isoSF=inputTree->Branch("isoSF",&isoSF,"isoSF/F");
   b_isoSFUp=inputTree->Branch("isoSFUp",&isoSFUp,"isoSFUp/F");
   b_isoSFDown=inputTree->Branch("isoSFDown",&isoSFDown,"isoSFDown/F");
   b_lepIdSF=inputTree->Branch("lepIdSF",&lepIdSF,"lepIdSF/F");
   b_lepIdSFUp=inputTree->Branch("lepIdSFUp",&lepIdSFUp,"lepIdSFUp/F");
   b_lepIdSFDown=inputTree->Branch("lepIdSFDown",&lepIdSFDown,"lepIdSFDown/F");
   b_pdfUp=inputTree->Branch("pdfUp",&pdfUp,"pdfUp/F");
   b_pdfMean=inputTree->Branch("pdfMean",&pdfMean,"pdfMean/F");
   b_pdfDown=inputTree->Branch("pdfDown",&pdfDown,"pdfDown/F");
   b_renormUp=inputTree->Branch("renormUp",&renormUp,"renormUp/F");
   b_renormDown=inputTree->Branch("renormDown",&renormDown,"renormDown/F");
   b_NJets_JetSubCalc=inputTree->Branch("NJets_JetSubCalc",&NJets_JetSubCalc,"NJets_JetSubCalc/I");
   b_NJetsAK8_JetSubCalc=inputTree->Branch("NJetsAK8_JetSubCalc",&NJetsAK8_JetSubCalc,"NJetsAK8_JetSubCalc/I");
   b_NJetsCSV_JetSubCalc=inputTree->Branch("NJetsCSV_JetSubCalc",&NJetsCSV_JetSubCalc,"NJetsCSV_JetSubCalc/I");
   b_NJetsCSVwithSF_JetSubCalc=inputTree->Branch("NJetsCSVwithSF_JetSubCalc",&NJetsCSVwithSF_JetSubCalc,"NJetsCSVwithSF_JetSubCalc/I");
   b_NJetsWtagged=inputTree->Branch("NJetsWtagged",&NJetsWtagged,"NJetsWtagged/I");
   b_NJetsHtagged=inputTree->Branch("NJetsHtagged",&NJetsHtagged,"NJetsHtagged/I");
   b_topPt=inputTree->Branch("topPt",&topPt,"topPt/F");
   b_topPtGen=inputTree->Branch("topPtGen",&topPtGen,"topPtGen/F");
   b_topMass=inputTree->Branch("topMass",&topMass,"topMass/F");
   b_minMleppBjet=inputTree->Branch("minMleppBjet",&minMleppBjet,"minMleppBjet/F");
   b_minMleppJet=inputTree->Branch("minMleppJet",&minMleppJet,"minMleppJet/F");
   b_genTopPt=inputTree->Branch("genTopPt",&genTopPt,"genTopPt/F");
   b_genAntiTopPt=inputTree->Branch("genAntiTopPt",&genAntiTopPt,"genAntiTopPt/F");
   b_topPtWeight=inputTree->Branch("topPtWeight",&topPtWeight,"topPtWeight/F");
   b_deltaRlepJetInMinMljet=inputTree->Branch("deltaRlepJetInMinMljet",&deltaRlepJetInMinMljet,"deltaRlepJetInMinMljet/F");
   b_deltaPhilepJetInMinMljet=inputTree->Branch("deltaPhilepJetInMinMljet",&deltaPhilepJetInMinMljet,"deltaPhilepJetInMinMljet/F");
   b_deltaRlepbJetInMinMlb=inputTree->Branch("deltaRlepbJetInMinMlb",&deltaRlepbJetInMinMlb,"deltaRlepbJetInMinMlb/F");
   b_deltaPhilepbJetInMinMlb=inputTree->Branch("deltaPhilepbJetInMinMlb",&deltaPhilepbJetInMinMlb,"deltaPhilepbJetInMinMlb/F");
   b_deltaRlepbJetNotInMinMlb=inputTree->Branch("deltaRlepbJetNotInMinMlb",&deltaRlepbJetNotInMinMlb,"deltaRlepbJetNotInMinMlb/F");
   b_HT_AllJets_MinusBestJet=inputTree->Branch("HT_AllJets_MinusBestJet",&HT_AllJets_MinusBestJet,"HT_AllJets_MinusBestJet/F");
   b_MT_AllJets_MinusBestJet=inputTree->Branch("MT_AllJets_MinusBestJet",&MT_AllJets_MinusBestJet,"MT_AllJets_MinusBestJet/F");
   b_Pt_AllJets_MinusBestJet=inputTree->Branch("Pt_AllJets_MinusBestJet",&Pt_AllJets_MinusBestJet,"Pt_AllJets_MinusBestJet/F");
   b_M_AllJets_MinusBestJet=inputTree->Branch("M_AllJets_MinusBestJet",&M_AllJets_MinusBestJet,"M_AllJets_MinusBestJet/F");
   b_M_taggedW_bjet1=inputTree->Branch("M_taggedW_bjet1",&M_taggedW_bjet1,"M_taggedW_bjet1/F");
   b_M_taggedW_bjet2=inputTree->Branch("M_taggedW_bjet2",&M_taggedW_bjet2,"M_taggedW_bjet2/F");
   b_HT_AllBjets=inputTree->Branch("HT_AllBjets",&HT_AllBjets,"HT_AllBjets/F");
   b_HT_leading4jets=inputTree->Branch("HT_leading4jets",&HT_leading4jets,"HT_leading4jets/F");
   b_HToverHT4=inputTree->Branch("HToverHT4",&HToverHT4,"HToverHT4/F");
   b_deltaRlepbJet1=inputTree->Branch("deltaRlepbJet1",&deltaRlepbJet1,"deltaRlepbJet1/F");
   b_deltaPhilepbJet1=inputTree->Branch("deltaPhilepbJet1",&deltaPhilepbJet1,"deltaPhilepbJet1/F");
   b_deltaRlepbJet2=inputTree->Branch("deltaRlepbJet2",&deltaRlepbJet2,"deltaRlepbJet2/F");
   b_deltaPhilepbJet2=inputTree->Branch("deltaPhilepbJet2",&deltaPhilepbJet2,"deltaPhilepbJet2/F");
   b_deltaRtopWjet=inputTree->Branch("deltaRtopWjet",&deltaRtopWjet,"deltaRtopWjet/F");
   b_deltaPhitopWjet=inputTree->Branch("deltaPhitopWjet",&deltaPhitopWjet,"deltaPhitopWjet/F");
   b_deltaRlepWjet=inputTree->Branch("deltaRlepWjet",&deltaRlepWjet,"deltaRlepWjet/F");
   b_deltaPhilepWjet=inputTree->Branch("deltaPhilepWjet",&deltaPhilepWjet,"deltaPhilepWjet/F");
   b_deltaRtaggedWbJet1=inputTree->Branch("deltaRtaggedWbJet1",&deltaRtaggedWbJet1,"deltaRtaggedWbJet1/F");
   b_deltaPhitaggedWbJet1=inputTree->Branch("deltaPhitaggedWbJet1",&deltaPhitaggedWbJet1,"deltaPhitaggedWbJet1/F");
   b_deltaRtaggedWbJet2=inputTree->Branch("deltaRtaggedWbJet2",&deltaRtaggedWbJet2,"deltaRtaggedWbJet2/F");
   b_deltaPhitaggedWbJet2=inputTree->Branch("deltaPhitaggedWbJet2",&deltaPhitaggedWbJet2,"deltaPhitaggedWbJet2/F");
   b_WJetDijetPt=inputTree->Branch("WJetDijetPt",&WJetDijetPt);
   b_WJetDijetMass=inputTree->Branch("WJetDijetMass",&WJetDijetMass);
   b_WJetTaggedPt=inputTree->Branch("WJetTaggedPt",&WJetTaggedPt);
   b_WJetTaggedMass=inputTree->Branch("WJetTaggedMass",&WJetTaggedMass);
   b_isleadBjetTheBestJet=inputTree->Branch("isleadBjetTheBestJet",&isleadBjetTheBestJet,"isleadBjetTheBestJet/I");
   b_deltaR_lepJets=inputTree->Branch("deltaR_lepJets",&deltaR_lepJets);
   b_deltaR_lepClosestJet=inputTree->Branch("deltaR_lepClosestJet",&deltaR_lepClosestJet,"deltaR_lepClosestJet/F");
   b_theJetAK8PrunedMassJMRSmeared_JetSubCalc=inputTree->Branch("theJetAK8PrunedMassJMRSmeared_JetSubCalc",&theJetAK8PrunedMassJMRSmeared_JetSubCalc);
   b_theJetAK8PrunedMassJMRSmearedUp_JetSubCalc=inputTree->Branch("theJetAK8PrunedMassJMRSmearedUp_JetSubCalc",&theJetAK8PrunedMassJMRSmearedUp_JetSubCalc);
   b_theJetAK8PrunedMassJMRSmearedDn_JetSubCalc=inputTree->Branch("theJetAK8PrunedMassJMRSmearedDn_JetSubCalc",&theJetAK8PrunedMassJMRSmearedDn_JetSubCalc);
   b_NJetsWtagged_JMR=inputTree->Branch("NJetsWtagged_JMR",&NJetsWtagged_JMR,"NJetsWtagged_JMR/I");
   b_NJetsWtagged_JMRup=inputTree->Branch("NJetsWtagged_JMRup",&NJetsWtagged_JMRup,"NJetsWtagged_JMRup/I");
   b_NJetsWtagged_JMRdn=inputTree->Branch("NJetsWtagged_JMRdn",&NJetsWtagged_JMRdn,"NJetsWtagged_JMRdn/I");
   b_NJetsWtagged_JMSup=inputTree->Branch("NJetsWtagged_JMSup",&NJetsWtagged_JMSup,"NJetsWtagged_JMSup/I");
   b_NJetsWtagged_JMSdn=inputTree->Branch("NJetsWtagged_JMSdn",&NJetsWtagged_JMSdn,"NJetsWtagged_JMSdn/I");
   b_NJetsWtagged_TAUup=inputTree->Branch("NJetsWtagged_TAUup",&NJetsWtagged_TAUup,"NJetsWtagged_TAUup/I");
   b_NJetsWtagged_TAUdn=inputTree->Branch("NJetsWtagged_TAUdn",&NJetsWtagged_TAUdn,"NJetsWtagged_TAUdn/I");
   b_deltaPhilepMET=inputTree->Branch("deltaPhilepMET",&deltaPhilepMET,"deltaPhilepMET/F");
   b_PtRelLepClosestJet=inputTree->Branch("PtRelLepClosestJet",&PtRelLepClosestJet,"PtRelLepClosestJet/F");
   
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
   inputTree->SetBranchAddress("dataE_singleLepCalc", &dataE_singleLepCalc, &b_dataE_singleLepCalc);
   inputTree->SetBranchAddress("dataM_singleLepCalc", &dataM_singleLepCalc, &b_dataM_singleLepCalc);
   inputTree->SetBranchAddress("event_CommonCalc", &event_CommonCalc, &b_event_CommonCalc);
   inputTree->SetBranchAddress("genTDLID_singleLepCalc", &genTDLID_singleLepCalc, &b_genTDLID_singleLepCalc);
   inputTree->SetBranchAddress("lumi_CommonCalc", &lumi_CommonCalc, &b_lumi_CommonCalc);
   inputTree->SetBranchAddress("nAllJets_CommonCalc", &nAllJets_CommonCalc, &b_nAllJets_CommonCalc);
   inputTree->SetBranchAddress("nLooseElectrons_CommonCalc", &nLooseElectrons_CommonCalc, &b_nLooseElectrons_CommonCalc);
   inputTree->SetBranchAddress("nLooseMuons_CommonCalc", &nLooseMuons_CommonCalc, &b_nLooseMuons_CommonCalc);
   inputTree->SetBranchAddress("nPV_singleLepCalc", &nPV_singleLepCalc, &b_nPV_singleLepCalc);
   inputTree->SetBranchAddress("nPileupInteractions_singleLepCalc", &nPileupInteractions_singleLepCalc, &b_nPileupInteractions_singleLepCalc);
   inputTree->SetBranchAddress("nSelBtagJets_CommonCalc", &nSelBtagJets_CommonCalc, &b_nSelBtagJets_CommonCalc);
   inputTree->SetBranchAddress("nSelElectrons_CommonCalc", &nSelElectrons_CommonCalc, &b_nSelElectrons_CommonCalc);
   inputTree->SetBranchAddress("nSelJets_CommonCalc", &nSelJets_CommonCalc, &b_nSelJets_CommonCalc);
   inputTree->SetBranchAddress("nSelMuons_CommonCalc", &nSelMuons_CommonCalc, &b_nSelMuons_CommonCalc);
   inputTree->SetBranchAddress("nTrueInteractions_singleLepCalc", &nTrueInteractions_singleLepCalc, &b_nTrueInteractions_singleLepCalc);
   inputTree->SetBranchAddress("run_CommonCalc", &run_CommonCalc, &b_run_CommonCalc);
   inputTree->SetBranchAddress("AK4HT_singleLepCalc", &AK4HT_singleLepCalc, &b_AK4HT_singleLepCalc);
   inputTree->SetBranchAddress("MCWeight_singleLepCalc", &MCWeight_singleLepCalc, &b_MCWeight_singleLepCalc);
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
   //   inputTree->SetBranchAddress("theJetAK8PrunedTau21Tag_JetSubCalc", &theJetAK8PrunedTau21Tag_JetSubCalc, &b_theJetAK8PrunedTau21Tag_JetSubCalc);
   //   inputTree->SetBranchAddress("theJetAK8SoftDropTau21Tag_JetSubCalc", &theJetAK8SoftDropTau21Tag_JetSubCalc, &b_theJetAK8SoftDropTau21Tag_JetSubCalc);
   //   inputTree->SetBranchAddress("theJetAK8SoftDropTau32Tag_JetSubCalc", &theJetAK8SoftDropTau32Tag_JetSubCalc, &b_theJetAK8SoftDropTau32Tag_JetSubCalc);
   //   inputTree->SetBranchAddress("theJetAK8caTopRun1Tag_JetSubCalc", &theJetAK8caTopRun1Tag_JetSubCalc, &b_theJetAK8caTopRun1Tag_JetSubCalc);
   inputTree->SetBranchAddress("AK4JetBTag_singleLepCalc", &AK4JetBTag_singleLepCalc, &b_AK4JetBTag_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetFlav_singleLepCalc", &AK4JetFlav_singleLepCalc, &b_AK4JetFlav_singleLepCalc);
   inputTree->SetBranchAddress("LHEWeightids_singleLepCalc", &LHEWeightids_singleLepCalc, &b_LHEWeightids_singleLepCalc);
   inputTree->SetBranchAddress("LeptonID_TpTpCalc", &LeptonID_TpTpCalc, &b_LeptonID_TpTpCalc);
   inputTree->SetBranchAddress("LeptonParentID_TpTpCalc", &LeptonParentID_TpTpCalc, &b_LeptonParentID_TpTpCalc);
   inputTree->SetBranchAddress("bPrimeID_TpTpCalc", &bPrimeID_TpTpCalc, &b_bPrimeID_TpTpCalc);
   inputTree->SetBranchAddress("bPrimeNDaughters_TpTpCalc", &bPrimeNDaughters_TpTpCalc, &b_bPrimeNDaughters_TpTpCalc);
   inputTree->SetBranchAddress("bPrimeStatus_TpTpCalc", &bPrimeStatus_TpTpCalc, &b_bPrimeStatus_TpTpCalc);
   inputTree->SetBranchAddress("bosonID_TpTpCalc", &bosonID_TpTpCalc, &b_bosonID_TpTpCalc);
   inputTree->SetBranchAddress("elChargeConsistent_singleLepCalc", &elChargeConsistent_singleLepCalc, &b_elChargeConsistent_singleLepCalc);
   inputTree->SetBranchAddress("elCharge_singleLepCalc", &elCharge_singleLepCalc, &b_elCharge_singleLepCalc);
   inputTree->SetBranchAddress("elIDLevel25ns_singleLepCalc", &elIDLevel25ns_singleLepCalc, &b_elIDLevel25ns_singleLepCalc);
   inputTree->SetBranchAddress("elIDLevel50ns_singleLepCalc", &elIDLevel50ns_singleLepCalc, &b_elIDLevel50ns_singleLepCalc);
   inputTree->SetBranchAddress("elIsEBEE_singleLepCalc", &elIsEBEE_singleLepCalc, &b_elIsEBEE_singleLepCalc);
   inputTree->SetBranchAddress("elMHits_singleLepCalc", &elMHits_singleLepCalc, &b_elMHits_singleLepCalc);
   inputTree->SetBranchAddress("elMatched_singleLepCalc", &elMatched_singleLepCalc, &b_elMatched_singleLepCalc);
   inputTree->SetBranchAddress("elMother_id_singleLepCalc", &elMother_id_singleLepCalc, &b_elMother_id_singleLepCalc);
   inputTree->SetBranchAddress("elMother_status_singleLepCalc", &elMother_status_singleLepCalc, &b_elMother_status_singleLepCalc);
   inputTree->SetBranchAddress("elNotConversion_singleLepCalc", &elNotConversion_singleLepCalc, &b_elNotConversion_singleLepCalc);
   inputTree->SetBranchAddress("elNumberOfMothers_singleLepCalc", &elNumberOfMothers_singleLepCalc, &b_elNumberOfMothers_singleLepCalc);
   inputTree->SetBranchAddress("elPdgId_singleLepCalc", &elPdgId_singleLepCalc, &b_elPdgId_singleLepCalc);
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
   inputTree->SetBranchAddress("muIsLoose_singleLepCalc", &muIsLoose_singleLepCalc, &b_muIsLoose_singleLepCalc);
   inputTree->SetBranchAddress("muIsMedium_singleLepCalc", &muIsMedium_singleLepCalc, &b_muIsMedium_singleLepCalc);
   inputTree->SetBranchAddress("muIsTight_singleLepCalc", &muIsTight_singleLepCalc, &b_muIsTight_singleLepCalc);
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
   inputTree->SetBranchAddress("theJetAK8SDSubjetIndex_JetSubCalc", &theJetAK8SDSubjetIndex_JetSubCalc, &b_theJetAK8SDSubjetIndex_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNCSVL_JetSubCalc", &theJetAK8SDSubjetNCSVL_JetSubCalc, &b_theJetAK8SDSubjetNCSVL_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNCSVM_JetSubCalc", &theJetAK8SDSubjetNCSVM_JetSubCalc, &b_theJetAK8SDSubjetNCSVM_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNCSVMSF_JetSubCalc", &theJetAK8SDSubjetNCSVMSF_JetSubCalc, &b_theJetAK8SDSubjetNCSVMSF_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetSize_JetSubCalc", &theJetAK8SDSubjetSize_JetSubCalc, &b_theJetAK8SDSubjetSize_JetSubCalc);
   /*
   inputTree->SetBranchAddress("theJetAK8caTopSubjetIndex_JetSubCalc", &theJetAK8caTopSubjetIndex_JetSubCalc, &b_theJetAK8caTopSubjetIndex_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8caTopSubjetNCSVL_JetSubCalc", &theJetAK8caTopSubjetNCSVL_JetSubCalc, &b_theJetAK8caTopSubjetNCSVL_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8caTopSubjetNCSVM_JetSubCalc", &theJetAK8caTopSubjetNCSVM_JetSubCalc, &b_theJetAK8caTopSubjetNCSVM_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8caTopSubjetSize_JetSubCalc", &theJetAK8caTopSubjetSize_JetSubCalc, &b_theJetAK8caTopSubjetSize_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8caTopnSubJets_JetSubCalc", &theJetAK8caTopnSubJets_JetSubCalc, &b_theJetAK8caTopnSubJets_JetSubCalc);
   */
   inputTree->SetBranchAddress("theJetAK8nDaughters_JetSubCalc", &theJetAK8nDaughters_JetSubCalc, &b_theJetAK8nDaughters_JetSubCalc);
   inputTree->SetBranchAddress("theJetBTagLoose_JetSubCalc", &theJetBTagLoose_JetSubCalc, &b_theJetBTagLoose_JetSubCalc);
   inputTree->SetBranchAddress("theJetBTag_JetSubCalc", &theJetBTag_JetSubCalc, &b_theJetBTag_JetSubCalc);
   inputTree->SetBranchAddress("theJetFlav_JetSubCalc", &theJetFlav_JetSubCalc, &b_theJetFlav_JetSubCalc);
   inputTree->SetBranchAddress("theJetnDaughters_JetSubCalc", &theJetnDaughters_JetSubCalc, &b_theJetnDaughters_JetSubCalc);
   inputTree->SetBranchAddress("topID_TTbarMassCalc", &topID_TTbarMassCalc, &b_topID_TTbarMassCalc);
   inputTree->SetBranchAddress("viSelMCTriggersEl_singleLepCalc", &viSelMCTriggersEl_singleLepCalc, &b_viSelMCTriggersEl_singleLepCalc);
   inputTree->SetBranchAddress("viSelMCTriggersMu_singleLepCalc", &viSelMCTriggersMu_singleLepCalc, &b_viSelMCTriggersMu_singleLepCalc);
   inputTree->SetBranchAddress("viSelTriggersEl_singleLepCalc", &viSelTriggersEl_singleLepCalc, &b_viSelTriggersEl_singleLepCalc);
   inputTree->SetBranchAddress("viSelTriggersMu_singleLepCalc", &viSelTriggersMu_singleLepCalc, &b_viSelTriggersMu_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetBDisc_singleLepCalc", &AK4JetBDisc_singleLepCalc, &b_AK4JetBDisc_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetEnergy_singleLepCalc", &AK4JetEnergy_singleLepCalc, &b_AK4JetEnergy_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetEta_singleLepCalc", &AK4JetEta_singleLepCalc, &b_AK4JetEta_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetPhi_singleLepCalc", &AK4JetPhi_singleLepCalc, &b_AK4JetPhi_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetPt_singleLepCalc", &AK4JetPt_singleLepCalc, &b_AK4JetPt_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetCSV_singleLepCalc", &AK8JetCSV_singleLepCalc, &b_AK8JetCSV_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetEnergy_singleLepCalc", &AK8JetEnergy_singleLepCalc, &b_AK8JetEnergy_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetEta_singleLepCalc", &AK8JetEta_singleLepCalc, &b_AK8JetEta_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetPhi_singleLepCalc", &AK8JetPhi_singleLepCalc, &b_AK8JetPhi_singleLepCalc);
   inputTree->SetBranchAddress("AK8JetPt_singleLepCalc", &AK8JetPt_singleLepCalc, &b_AK8JetPt_singleLepCalc);
   inputTree->SetBranchAddress("LHEWeights_singleLepCalc", &LHEWeights_singleLepCalc, &b_LHEWeights_singleLepCalc);
   inputTree->SetBranchAddress("LeptonEnergy_TpTpCalc", &LeptonEnergy_TpTpCalc, &b_LeptonEnergy_TpTpCalc);
   inputTree->SetBranchAddress("LeptonEta_TpTpCalc", &LeptonEta_TpTpCalc, &b_LeptonEta_TpTpCalc);
   inputTree->SetBranchAddress("LeptonPhi_TpTpCalc", &LeptonPhi_TpTpCalc, &b_LeptonPhi_TpTpCalc);
   inputTree->SetBranchAddress("LeptonPt_TpTpCalc", &LeptonPt_TpTpCalc, &b_LeptonPt_TpTpCalc);
   inputTree->SetBranchAddress("bPrimeEnergy_TpTpCalc", &bPrimeEnergy_TpTpCalc, &b_bPrimeEnergy_TpTpCalc);
   inputTree->SetBranchAddress("bPrimeEta_TpTpCalc", &bPrimeEta_TpTpCalc, &b_bPrimeEta_TpTpCalc);
   inputTree->SetBranchAddress("bPrimeMass_TpTpCalc", &bPrimeMass_TpTpCalc, &b_bPrimeMass_TpTpCalc);
   inputTree->SetBranchAddress("bPrimePhi_TpTpCalc", &bPrimePhi_TpTpCalc, &b_bPrimePhi_TpTpCalc);
   inputTree->SetBranchAddress("bPrimePt_TpTpCalc", &bPrimePt_TpTpCalc, &b_bPrimePt_TpTpCalc);
   inputTree->SetBranchAddress("bosonEnergy_TpTpCalc", &bosonEnergy_TpTpCalc, &b_bosonEnergy_TpTpCalc);
   inputTree->SetBranchAddress("bosonEta_TpTpCalc", &bosonEta_TpTpCalc, &b_bosonEta_TpTpCalc);
   inputTree->SetBranchAddress("bosonPhi_TpTpCalc", &bosonPhi_TpTpCalc, &b_bosonPhi_TpTpCalc);
   inputTree->SetBranchAddress("bosonPt_TpTpCalc", &bosonPt_TpTpCalc, &b_bosonPt_TpTpCalc);
   inputTree->SetBranchAddress("elAEff_singleLepCalc", &elAEff_singleLepCalc, &b_elAEff_singleLepCalc);
   inputTree->SetBranchAddress("elChIso_singleLepCalc", &elChIso_singleLepCalc, &b_elChIso_singleLepCalc);
   inputTree->SetBranchAddress("elD0_singleLepCalc", &elD0_singleLepCalc, &b_elD0_singleLepCalc);
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
   inputTree->SetBranchAddress("elMVATrigValue_singleLepCalc", &elMVATrigValue_singleLepCalc, &b_elMVATrigValue_singleLepCalc);
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
   inputTree->SetBranchAddress("elPhIso_singleLepCalc", &elPhIso_singleLepCalc, &b_elPhIso_singleLepCalc);
   inputTree->SetBranchAddress("elPhiVtx_singleLepCalc", &elPhiVtx_singleLepCalc, &b_elPhiVtx_singleLepCalc);
   inputTree->SetBranchAddress("elPhi_singleLepCalc", &elPhi_singleLepCalc, &b_elPhi_singleLepCalc);
   inputTree->SetBranchAddress("elPt_singleLepCalc", &elPt_singleLepCalc, &b_elPt_singleLepCalc);
   inputTree->SetBranchAddress("elRelIso_singleLepCalc", &elRelIso_singleLepCalc, &b_elRelIso_singleLepCalc);
   inputTree->SetBranchAddress("elRhoIso_singleLepCalc", &elRhoIso_singleLepCalc, &b_elRhoIso_singleLepCalc);
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
   inputTree->SetBranchAddress("muMatchedEnergy_singleLepCalc", &muMatchedEnergy_singleLepCalc, &b_muMatchedEnergy_singleLepCalc);
   inputTree->SetBranchAddress("muMatchedEta_singleLepCalc", &muMatchedEta_singleLepCalc, &b_muMatchedEta_singleLepCalc);
   inputTree->SetBranchAddress("muMatchedPhi_singleLepCalc", &muMatchedPhi_singleLepCalc, &b_muMatchedPhi_singleLepCalc);
   inputTree->SetBranchAddress("muMatchedPt_singleLepCalc", &muMatchedPt_singleLepCalc, &b_muMatchedPt_singleLepCalc);
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
   inputTree->SetBranchAddress("pfCombinedInclusiveSecondaryVertexV2BJetTags_BTagSFCalc", &pfCombinedInclusiveSecondaryVertexV2BJetTags_BTagSFCalc, &b_pfCombinedInclusiveSecondaryVertexV2BJetTags_BTagSFCalc);
   inputTree->SetBranchAddress("pfCombinedMVABJetTags_BTagSFCalc", &pfCombinedMVABJetTags_BTagSFCalc, &b_pfCombinedMVABJetTags_BTagSFCalc);
   inputTree->SetBranchAddress("pfCombinedSecondaryVertexV2BJetTags_BTagSFCalc", &pfCombinedSecondaryVertexV2BJetTags_BTagSFCalc, &b_pfCombinedSecondaryVertexV2BJetTags_BTagSFCalc);
   inputTree->SetBranchAddress("pfJetBProbabilityBJetTags_BTagSFCalc", &pfJetBProbabilityBJetTags_BTagSFCalc, &b_pfJetBProbabilityBJetTags_BTagSFCalc);
   inputTree->SetBranchAddress("pfJetProbabilityBJetTags_BTagSFCalc", &pfJetProbabilityBJetTags_BTagSFCalc, &b_pfJetProbabilityBJetTags_BTagSFCalc);
   inputTree->SetBranchAddress("pfSimpleSecondaryVertexHighEffBJetTags_BTagSFCalc", &pfSimpleSecondaryVertexHighEffBJetTags_BTagSFCalc, &b_pfSimpleSecondaryVertexHighEffBJetTags_BTagSFCalc);
   inputTree->SetBranchAddress("pfSimpleSecondaryVertexHighPurBJetTags_BTagSFCalc", &pfSimpleSecondaryVertexHighPurBJetTags_BTagSFCalc, &b_pfSimpleSecondaryVertexHighPurBJetTags_BTagSFCalc);
   inputTree->SetBranchAddress("pfTrackCountingHighEffBJetTags_BTagSFCalc", &pfTrackCountingHighEffBJetTags_BTagSFCalc, &b_pfTrackCountingHighEffBJetTags_BTagSFCalc);
   inputTree->SetBranchAddress("pfTrackCountingHighPurBJetTags_BTagSFCalc", &pfTrackCountingHighPurBJetTags_BTagSFCalc, &b_pfTrackCountingHighPurBJetTags_BTagSFCalc);
   inputTree->SetBranchAddress("quarkEnergy_TpTpCalc", &quarkEnergy_TpTpCalc, &b_quarkEnergy_TpTpCalc);
   inputTree->SetBranchAddress("quarkEta_TpTpCalc", &quarkEta_TpTpCalc, &b_quarkEta_TpTpCalc);
   inputTree->SetBranchAddress("quarkPhi_TpTpCalc", &quarkPhi_TpTpCalc, &b_quarkPhi_TpTpCalc);
   inputTree->SetBranchAddress("quarkPt_TpTpCalc", &quarkPt_TpTpCalc, &b_quarkPt_TpTpCalc);
   inputTree->SetBranchAddress("tPrimeEnergy_TpTpCalc", &tPrimeEnergy_TpTpCalc, &b_tPrimeEnergy_TpTpCalc);
   inputTree->SetBranchAddress("tPrimeEta_TpTpCalc", &tPrimeEta_TpTpCalc, &b_tPrimeEta_TpTpCalc);
   inputTree->SetBranchAddress("tPrimeMass_TpTpCalc", &tPrimeMass_TpTpCalc, &b_tPrimeMass_TpTpCalc);
   inputTree->SetBranchAddress("tPrimePhi_TpTpCalc", &tPrimePhi_TpTpCalc, &b_tPrimePhi_TpTpCalc);
   inputTree->SetBranchAddress("tPrimePt_TpTpCalc", &tPrimePt_TpTpCalc, &b_tPrimePt_TpTpCalc);
   inputTree->SetBranchAddress("theJetAK8CEmEFrac_JetSubCalc", &theJetAK8CEmEFrac_JetSubCalc, &b_theJetAK8CEmEFrac_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8CEmEnergy_JetSubCalc", &theJetAK8CEmEnergy_JetSubCalc, &b_theJetAK8CEmEnergy_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8CHadEFrac_JetSubCalc", &theJetAK8CHadEFrac_JetSubCalc, &b_theJetAK8CHadEFrac_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8CHadEnergy_JetSubCalc", &theJetAK8CHadEnergy_JetSubCalc, &b_theJetAK8CHadEnergy_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8CSV_JetSubCalc", &theJetAK8CSV_JetSubCalc, &b_theJetAK8CSV_JetSubCalc);
   inputTree->SetBranchAddress("WEnergy_JetSubCalc", &WEnergy_JetSubCalc, &b_WEnergy_JetSubCalc);
   inputTree->SetBranchAddress("WEta_JetSubCalc", &WEta_JetSubCalc, &b_WEta_JetSubCalc);
   inputTree->SetBranchAddress("WPhi_JetSubCalc", &WPhi_JetSubCalc, &b_WPhi_JetSubCalc);
   inputTree->SetBranchAddress("WPt_JetSubCalc", &WPt_JetSubCalc, &b_WPt_JetSubCalc);
   inputTree->SetBranchAddress("WdecayDR_JetSubCalc", &WdecayDR_JetSubCalc, &b_WdecayDR_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8Energy_JetSubCalc", &theJetAK8Energy_JetSubCalc, &b_theJetAK8Energy_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8Eta_JetSubCalc", &theJetAK8Eta_JetSubCalc, &b_theJetAK8Eta_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8FilteredMass_JetSubCalc", &theJetAK8FilteredMass_JetSubCalc, &b_theJetAK8FilteredMass_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8JetCharge_JetSubCalc", &theJetAK8JetCharge_JetSubCalc, &b_theJetAK8JetCharge_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8Mass_JetSubCalc", &theJetAK8Mass_JetSubCalc, &b_theJetAK8Mass_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8NEmEFrac_JetSubCalc", &theJetAK8NEmEFrac_JetSubCalc, &b_theJetAK8NEmEFrac_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8NEmEnergy_JetSubCalc", &theJetAK8NEmEnergy_JetSubCalc, &b_theJetAK8NEmEnergy_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8NHadEFrac_JetSubCalc", &theJetAK8NHadEFrac_JetSubCalc, &b_theJetAK8NHadEFrac_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8NHadEnergy_JetSubCalc", &theJetAK8NHadEnergy_JetSubCalc, &b_theJetAK8NHadEnergy_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8NjettinessTau1_JetSubCalc", &theJetAK8NjettinessTau1_JetSubCalc, &b_theJetAK8NjettinessTau1_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8NjettinessTau2_JetSubCalc", &theJetAK8NjettinessTau2_JetSubCalc, &b_theJetAK8NjettinessTau2_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8NjettinessTau3_JetSubCalc", &theJetAK8NjettinessTau3_JetSubCalc, &b_theJetAK8NjettinessTau3_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8Phi_JetSubCalc", &theJetAK8Phi_JetSubCalc, &b_theJetAK8Phi_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8PrunedMass_JetSubCalc", &theJetAK8PrunedMass_JetSubCalc, &b_theJetAK8PrunedMass_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8Pt_JetSubCalc", &theJetAK8Pt_JetSubCalc, &b_theJetAK8Pt_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetCSV_JetSubCalc", &theJetAK8SDSubjetCSV_JetSubCalc, &b_theJetAK8SDSubjetCSV_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetDR_JetSubCalc", &theJetAK8SDSubjetDR_JetSubCalc, &b_theJetAK8SDSubjetDR_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetEta_JetSubCalc", &theJetAK8SDSubjetEta_JetSubCalc, &b_theJetAK8SDSubjetEta_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetMass_JetSubCalc", &theJetAK8SDSubjetMass_JetSubCalc, &b_theJetAK8SDSubjetMass_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetPhi_JetSubCalc", &theJetAK8SDSubjetPhi_JetSubCalc, &b_theJetAK8SDSubjetPhi_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SDSubjetPt_JetSubCalc", &theJetAK8SDSubjetPt_JetSubCalc, &b_theJetAK8SDSubjetPt_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8SoftDropMass_JetSubCalc", &theJetAK8SoftDropMass_JetSubCalc, &b_theJetAK8SoftDropMass_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8TrimmedMass_JetSubCalc", &theJetAK8TrimmedMass_JetSubCalc, &b_theJetAK8TrimmedMass_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8caTopMinMass_JetSubCalc", &theJetAK8caTopMinMass_JetSubCalc, &b_theJetAK8caTopMinMass_JetSubCalc);
   /*
   inputTree->SetBranchAddress("theJetAK8caTopSubjetCSV_JetSubCalc", &theJetAK8caTopSubjetCSV_JetSubCalc, &b_theJetAK8caTopSubjetCSV_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8caTopSubjetDR_JetSubCalc", &theJetAK8caTopSubjetDR_JetSubCalc, &b_theJetAK8caTopSubjetDR_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8caTopSubjetEta_JetSubCalc", &theJetAK8caTopSubjetEta_JetSubCalc, &b_theJetAK8caTopSubjetEta_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8caTopSubjetMass_JetSubCalc", &theJetAK8caTopSubjetMass_JetSubCalc, &b_theJetAK8caTopSubjetMass_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8caTopSubjetPhi_JetSubCalc", &theJetAK8caTopSubjetPhi_JetSubCalc, &b_theJetAK8caTopSubjetPhi_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8caTopSubjetPt_JetSubCalc", &theJetAK8caTopSubjetPt_JetSubCalc, &b_theJetAK8caTopSubjetPt_JetSubCalc);
   */
   inputTree->SetBranchAddress("theJetAK8caTopTopMass_JetSubCalc", &theJetAK8caTopTopMass_JetSubCalc, &b_theJetAK8caTopTopMass_JetSubCalc);
   inputTree->SetBranchAddress("theJetCEmEFrac_JetSubCalc", &theJetCEmEFrac_JetSubCalc, &b_theJetCEmEFrac_JetSubCalc);
   inputTree->SetBranchAddress("theJetCEmEnergy_JetSubCalc", &theJetCEmEnergy_JetSubCalc, &b_theJetCEmEnergy_JetSubCalc);
   inputTree->SetBranchAddress("theJetCHadEFrac_JetSubCalc", &theJetCHadEFrac_JetSubCalc, &b_theJetCHadEFrac_JetSubCalc);
   inputTree->SetBranchAddress("theJetCHadEnergy_JetSubCalc", &theJetCHadEnergy_JetSubCalc, &b_theJetCHadEnergy_JetSubCalc);
   inputTree->SetBranchAddress("theJetCSV_JetSubCalc", &theJetCSV_JetSubCalc, &b_theJetCSV_JetSubCalc);
   inputTree->SetBranchAddress("theJetEnergy_JetSubCalc", &theJetEnergy_JetSubCalc, &b_theJetEnergy_JetSubCalc);
   inputTree->SetBranchAddress("theJetEta_JetSubCalc", &theJetEta_JetSubCalc, &b_theJetEta_JetSubCalc);
   inputTree->SetBranchAddress("theJetMuonEFrac_JetSubCalc", &theJetMuonEFrac_JetSubCalc, &b_theJetMuonEFrac_JetSubCalc);
   inputTree->SetBranchAddress("theJetNEmEFrac_JetSubCalc", &theJetNEmEFrac_JetSubCalc, &b_theJetNEmEFrac_JetSubCalc);
   inputTree->SetBranchAddress("theJetNEmEnergy_JetSubCalc", &theJetNEmEnergy_JetSubCalc, &b_theJetNEmEnergy_JetSubCalc);
   inputTree->SetBranchAddress("theJetNHadEFrac_JetSubCalc", &theJetNHadEFrac_JetSubCalc, &b_theJetNHadEFrac_JetSubCalc);
   inputTree->SetBranchAddress("theJetNHadEnergy_JetSubCalc", &theJetNHadEnergy_JetSubCalc, &b_theJetNHadEnergy_JetSubCalc);
   inputTree->SetBranchAddress("theJetPhi_JetSubCalc", &theJetPhi_JetSubCalc, &b_theJetPhi_JetSubCalc);
   inputTree->SetBranchAddress("theJetPileupJetId_JetSubCalc", &theJetPileupJetId_JetSubCalc, &b_theJetPileupJetId_JetSubCalc);
   inputTree->SetBranchAddress("theJetPt_JetSubCalc", &theJetPt_JetSubCalc, &b_theJetPt_JetSubCalc);
   inputTree->SetBranchAddress("theJetVtx3DSig_JetSubCalc", &theJetVtx3DSig_JetSubCalc, &b_theJetVtx3DSig_JetSubCalc);
   inputTree->SetBranchAddress("theJetVtx3DVal_JetSubCalc", &theJetVtx3DVal_JetSubCalc, &b_theJetVtx3DVal_JetSubCalc);
   inputTree->SetBranchAddress("theJetVtxMass_JetSubCalc", &theJetVtxMass_JetSubCalc, &b_theJetVtxMass_JetSubCalc);
   inputTree->SetBranchAddress("theJetVtxNtracks_JetSubCalc", &theJetVtxNtracks_JetSubCalc, &b_theJetVtxNtracks_JetSubCalc);
   inputTree->SetBranchAddress("topEnergy_TTbarMassCalc", &topEnergy_TTbarMassCalc, &b_topEnergy_TTbarMassCalc);
   inputTree->SetBranchAddress("topEta_TTbarMassCalc", &topEta_TTbarMassCalc, &b_topEta_TTbarMassCalc);
   inputTree->SetBranchAddress("topMass_TTbarMassCalc", &topMass_TTbarMassCalc, &b_topMass_TTbarMassCalc);
   inputTree->SetBranchAddress("topPhi_TTbarMassCalc", &topPhi_TTbarMassCalc, &b_topPhi_TTbarMassCalc);
   inputTree->SetBranchAddress("topPt_TTbarMassCalc", &topPt_TTbarMassCalc, &b_topPt_TTbarMassCalc);
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
