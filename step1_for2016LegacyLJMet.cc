#define step1_cxx

#include "step1.h"
#include <fstream>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <TH2.h>
#include <TF1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TRandom.h>
#include <TRandom3.h>
#include <sstream>
#include <string>
#include <vector>
#include <TH3.h>

#include "lwtnn/lwtnn/interface/parse_json.hh"
#include "lwtnn/lwtnn/interface/LightweightNeuralNetwork.hh"

using namespace std;

// ----------------------------------------------------------------------------
// DNN stuff
// ----------------------------------------------------------------------------

std::string dnnFileTT = "vlq_mlp_3by10_062819_TT2017.json";
std::ifstream input_cfgTT( dnnFileTT );
lwt::JSONConfig cfgTT = lwt::parse_json(input_cfgTT);
lwt::LightweightNeuralNetwork* lwtnnTT = new lwt::LightweightNeuralNetwork(cfgTT.inputs, cfgTT.layers, cfgTT.outputs);

std::string dnnFileBB = "vlq_mlp_3by10_072519_BB2017.json";
std::ifstream input_cfgBB( dnnFileBB );
lwt::JSONConfig cfgBB = lwt::parse_json(input_cfgBB);
lwt::LightweightNeuralNetwork* lwtnnBB = new lwt::LightweightNeuralNetwork(cfgBB.inputs, cfgBB.layers, cfgBB.outputs);

// ----------------------------------------------------------------------------
// Define functions
// ----------------------------------------------------------------------------

bool comparepair( const std::pair<double,int> a, const std::pair<double,int> b) { return a.first > b.first; }

TRandom3 Rand;

const double MTOP  = 173.5;
const double MW    = 80.4; 

void step1::saveHistograms()
{
  TH1D* numhist = (TH1D*)inputFile->Get("mcweightanalyzer/NumTrueHist");
  TH1D* wgthist = (TH1D*)inputFile->Get("mcweightanalyzer/weightHist");
  outputFile->cd();
  numhist->Write();
  wgthist->Write();
}

bool step1::applySF(bool& isTagged, float tag_SF, float tag_eff, float jet_phi){
  
  bool newTag = isTagged;
  if (tag_SF == 1) return newTag; //no correction needed 

  //throw die
  Rand.SetSeed(jet_phi*10e4);
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
  // updated with https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation2016Legacy
  if(pt > 1000.) pt = 1000.;
  if(fabs(eta) > 2.4 or pt<20.) return 1.0; 
  switch(Shift){
  case uncert:
    if(pt<30) return 0.043795019388198853;
    else if(pt<50) return 0.015845479443669319;
    else if(pt<70) return 0.014174085110425949;
    else if(pt<100) return 0.013200919143855572;
    else if(pt<140) return 0.012912030331790447;
    else if(pt<200) return 0.019475525245070457;
    else if(pt<300) return 0.01628459244966507;
    else if(pt<600) return 0.034840557724237442;
    else  return 0.049875054508447647;
  case central:
  default:
    return     0.653526*((1.+(0.220245*pt))/(1.+(0.14383*pt)));
  }//end switch on shift
}

double step1::GetCtagSF2016Medium_comb(shift Shift, double pt, double eta){
  // SFs are identical with 3x uncertainty as B tag
  if(pt > 1000.) pt = 1000.;
  if(fabs(eta) > 2.4 or pt<20.) return 1.0; 
  switch(Shift)
    {
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
    return  (1.09286+-0.00052597*pt+1.88225e-06*pt*pt+-1.27417e-09*pt*pt*pt)*((0.101915+0.000192134*pt+-1.94974e-07*pt*pt));
  case central:
  default:
    return   1.09286+-0.00052597*pt+1.88225e-06*pt*pt+-1.27417e-09*pt*pt*pt;
  }//end switch Shift
}//end GetLFSF2016

double step1::GetBtagEfficiency(double pt){
  // Efficiencies from TT powheg sample for Moriond17.
  // See distribution in /uscms_data/d3/jmanagan/EffsAndNewWeights/TagEffsM17/BEff.png
  // Uses hadronFlavour() rather than partonFlavour() as recommended in BTV physics plenary CMS Week 10/2015
	
  // UPDATED USING DeepCSVMEDIUM Btagging: https://github.com/cms-ljmet/FWLJMET/blob/10_2_X_fullRun2data/LJMet/plugins/BtagHardcodedConditions.cc
  if(pt < 30)        return 0.447390;
  else if(pt < 50)   return 0.652679;
  else if(pt < 70)   return 0.704724;
  else if(pt < 100)  return 0.727924;
  else if(pt < 140)  return 0.737712;
  else if(pt < 200)  return 0.731578;
  else if(pt < 300)  return 0.689644;
  else if(pt < 400)  return 0.615546;
  else if(pt < 500)  return 0.552437;
  else if(pt < 600)  return 0.501756;
  else if(pt < 800)  return 0.433998;
  else if(pt < 1000) return 0.318242;
  else if(pt < 1200) return 0.220351;
  else               return 0.140777;
}

double step1::GetCtagEfficiency(double pt){
  // UPDATED USING DeepCSVMEDIUM Ctagging: https://github.com/cms-ljmet/FWLJMET/blob/10_2_X_fullRun2data/LJMet/plugins/BtagHardcodedConditions.cc
  if(pt < 30)        return 0.070384; //0.057985;
  else if(pt < 50)   return 0.107334; //0.111536;
  else if(pt < 70)   return 0.111125; //0.112216;
  else if(pt < 100)  return 0.119346; //0.120075;
  else if(pt < 140)  return 0.128583; //0.128499;
  else if(pt < 200)  return 0.134354; //0.132918;
  else if(pt < 300)  return 0.127251; //0.126724;
  else if(pt < 400)  return 0.107927; //0.126281;
  else if(pt < 500)  return 0.099135; //0.123026;
  else if(pt < 600)  return 0.081601; //0.124840;
  else if(pt < 800)  return 0.056054; //0.130060;
  else if(pt < 1000) return 0.032320; //0.128022;
  else if(pt < 1200) return 0.014388; //0.134100;
  else               return 0.012887; //0.125348;
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

void step1::Loop(TString inTreeName, TString outTreeName) 
{
  
  // ----------------------------------------------------------------------------
  // More histograms and load input tree
  // ----------------------------------------------------------------------------
  
  inputTree = (TTree*)inputFile->Get(inTreeName+"/"+inTreeName);
  if (inputTree == 0) return;
  if(inputTree->GetEntries() == 0){
    std::cout << "WARNING! Found 0 events in the tree!!!" << std::endl;
    return;
  }

  Init(inputTree);

  if(outTreeName.Contains("BTAGup")) {isBUp = true; isBDn = false; isLUp = false; isLDn = false; isNominal = false;}
  else if(outTreeName.Contains("BTAGdown")) {isBUp = false; isBDn = true; isLUp = false; isLDn = false; isNominal = false;}
  else if(outTreeName.Contains("LTAGup")) {isBUp = false; isBDn = false; isLUp = true; isLDn = false; isNominal = false;}
  else if(outTreeName.Contains("LTAGdown")) {isBUp = false; isBDn = false; isLUp = false; isLDn = true; isNominal = false;}
  else {isBUp = false; isBDn = false; isLUp = false; isLDn = false; isNominal = true;}  

  std::map<std::string,double> myMapTT;
  std::map<std::string,double> varMapTT;
  std::map<std::string,double> myMapBB;
  std::map<std::string,double> varMapBB;
  
  // ----------------------------------------------------------------------------
  // Turn on input tree branches
  // ----------------------------------------------------------------------------
  
   inputTree->SetBranchStatus("*",0);

   //Event info

   inputTree->SetBranchStatus("event_CommonCalc",1);
   inputTree->SetBranchStatus("run_CommonCalc",1);
   inputTree->SetBranchStatus("lumi_CommonCalc",1);
   //   inputTree->SetBranchStatus("nPV_MultiLepCalc",1);
   inputTree->SetBranchStatus("nTrueInteractions_MultiLepCalc",1);
   inputTree->SetBranchStatus("MCWeight_MultiLepCalc",1);
   inputTree->SetBranchStatus("LHEweightids_MultiLepCalc",1);
   inputTree->SetBranchStatus("LHEweights_MultiLepCalc",1);
   inputTree->SetBranchStatus("NewPDFweights_MultiLepCalc",1);
   inputTree->SetBranchStatus("HTfromHEPUEP_MultiLepCalc",1);
   inputTree->SetBranchStatus("L1NonPrefiringProb_CommonCalc",1);
   inputTree->SetBranchStatus("L1NonPrefiringProbUp_CommonCalc",1);
   inputTree->SetBranchStatus("L1NonPrefiringProbDown_CommonCalc",1);

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
   inputTree->SetBranchStatus("tPrimePt_TpTpCalc",1);
   inputTree->SetBranchStatus("NLeptonDecays_TpTpCalc",1);
   
   //triggers
   inputTree->SetBranchStatus("vsSelMCTriggersEl_MultiLepCalc",1);
   inputTree->SetBranchStatus("viSelMCTriggersEl_MultiLepCalc",1);
   inputTree->SetBranchStatus("vsSelMCTriggersMu_MultiLepCalc",1);
   inputTree->SetBranchStatus("viSelMCTriggersMu_MultiLepCalc",1);
   inputTree->SetBranchStatus("vsSelTriggersEl_MultiLepCalc",1);
   inputTree->SetBranchStatus("viSelTriggersEl_MultiLepCalc",1);
   inputTree->SetBranchStatus("vsSelTriggersMu_MultiLepCalc",1);
   inputTree->SetBranchStatus("viSelTriggersMu_MultiLepCalc",1);
   
   //electrons
   inputTree->SetBranchStatus("elPt_MultiLepCalc",1);
   inputTree->SetBranchStatus("elEta_MultiLepCalc",1);
   inputTree->SetBranchStatus("elPhi_MultiLepCalc",1);
   inputTree->SetBranchStatus("elEnergy_MultiLepCalc",1);
   //   inputTree->SetBranchStatus("elMVAValue_MultiLepCalc",1);
   inputTree->SetBranchStatus("elMiniIso_MultiLepCalc",1);
   
   //muons
   inputTree->SetBranchStatus("muPt_MultiLepCalc",1);
   inputTree->SetBranchStatus("muEta_MultiLepCalc",1);
   inputTree->SetBranchStatus("muPhi_MultiLepCalc",1);
   inputTree->SetBranchStatus("muEnergy_MultiLepCalc",1);
   inputTree->SetBranchStatus("muMiniIso_MultiLepCalc",1);

   //missing et
   inputTree->SetBranchStatus("corr_met_MultiLepCalc",1);
   inputTree->SetBranchStatus("corr_met_phi_MultiLepCalc",1);
   inputTree->SetBranchStatus("corr_metmod_MultiLepCalc",1);
   inputTree->SetBranchStatus("corr_metmod_phi_MultiLepCalc",1);

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

   //JetSubCalc
   inputTree->SetBranchStatus("theJetHFlav_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetPFlav_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetPt_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetEta_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetPhi_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetEnergy_JetSubCalc",1);
   inputTree->SetBranchStatus("AK4JetDeepCSVb_MultiLepCalc",1);
   inputTree->SetBranchStatus("AK4JetDeepCSVbb_MultiLepCalc",1);
   inputTree->SetBranchStatus("AK4JetDeepFlavb_MultiLepCalc",1);
   inputTree->SetBranchStatus("AK4JetDeepFlavbb_MultiLepCalc",1);
   inputTree->SetBranchStatus("AK4JetDeepFlavlepb_MultiLepCalc",1);
   inputTree->SetBranchStatus("theJetAK8DoubleB_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_bSFup_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_bSFdn_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_lSFup_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_lSFdn_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Pt_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Eta_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Phi_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Mass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Energy_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau1_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau2_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau3_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8CHSTau1_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8CHSTau2_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8CHSTau3_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8CHSPrunedMass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8CHSSoftDropMass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDropRaw_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDropCorr_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDrop_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetNDeepCSVL_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetHFlav_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetIndex_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetSize_JetSubCalc",1);

   //DeepAK8
   inputTree->SetBranchStatus("dnn_B_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_C_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_J_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_W_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_Z_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_H_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_largest_DeepAK8Calc",1);
   inputTree->SetBranchStatus("dnn_T_DeepAK8Calc",1);

   //JetSubCalc
   inputTree->SetBranchStatus("maxProb_JetSubCalc",1);

   //top
   inputTree->SetBranchStatus("ttbarMass_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topMass_TTbarMassCalc",1);

   inputTree->SetBranchStatus("allTopsEnergy_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsEta_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsPhi_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsPt_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsID_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsStatus_TTbarMassCalc",1);

   // ----------------------------------------------------------------------------
   // Create output tree and define branches
   // ----------------------------------------------------------------------------
   
   // OUTPUT FILE
   outputFile->cd();
   TTree *outputTree = new TTree(outTreeName,outTreeName);
   TH2D *TTconfusionD = new TH2D("TTconfusionD",";tagged decay;true decay",10,0,10,6,0,6);
   TH2D *TTconfusionN = new TH2D("TTconfusionN",";tagged decay;true decay",10,0,10,6,0,6);
   TH2D *BBconfusionD = new TH2D("BBconfusionD",";tagged decay;true decay",7,0,7,6,0,6);
   TH2D *BBconfusionN = new TH2D("BBconfusionN",";tagged decay;true decay",7,0,7,6,0,6);

   // Common things
   outputTree->Branch("event_CommonCalc",&event_CommonCalc,"event_CommonCalc/L");
   outputTree->Branch("run_CommonCalc",&run_CommonCalc,"run_CommonCalc/I");
   outputTree->Branch("lumi_CommonCalc",&lumi_CommonCalc,"lumi_CommonCalc/I");
   //   outputTree->Branch("nPV_MultiLepCalc",&nPV_MultiLepCalc,"nPV_MultiLepCalc/I");
   outputTree->Branch("nTrueInteractions_MultiLepCalc",&nTrueInteractions_MultiLepCalc,"nTrueInteractions_MultiLepCalc/I");
   outputTree->Branch("isElectron",&isElectron,"isElectron/I");
   outputTree->Branch("isMuon",&isMuon,"isMuon/I");
   outputTree->Branch("MCPastTrigger",&MCPastTrigger,"MCPastTrigger/I");
   outputTree->Branch("DataPastTrigger",&DataPastTrigger,"DataPastTrigger/I");
   outputTree->Branch("L1NonPrefiringProb_CommonCalc",&L1NonPrefiringProb_CommonCalc,"L1NonPrefiringProb_CommonCalc/D");
   outputTree->Branch("L1NonPrefiringProbUp_CommonCalc",&L1NonPrefiringProbUp_CommonCalc,"L1NonPrefiringProbUp_CommonCalc/D");
   outputTree->Branch("L1NonPrefiringProbDown_CommonCalc",&L1NonPrefiringProbDown_CommonCalc,"L1NonPrefiringProbDown_CommonCalc/D");

   // Tprime generator
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
   outputTree->Branch("tPrimePt_TpTpCalc",&tPrimePt_TpTpCalc,"tPrimePt_TpTpCalc/O");
   outputTree->Branch("NLeptonDecays_TpTpCalc",&NLeptonDecays_TpTpCalc,"NLeptonDecays_TpTpCalc/I");
   outputTree->Branch("MCWeight_MultiLepCalc",&MCWeight_MultiLepCalc,"MCWeight_MultiLepCalc/D");

   // weights
   outputTree->Branch("renormWeights",&renormWeights);
   outputTree->Branch("pdfWeights",&pdfWeights);
   outputTree->Branch("pdfNewWeights",&pdfNewWeights);
   outputTree->Branch("pdfNewNominalWeight",&pdfNewNominalWeight,"pdfNewNominalWeight/F");
   outputTree->Branch("pileupWeight",&pileupWeight,"pileupWeight/F");
   outputTree->Branch("pileupWeightUp",&pileupWeightUp,"pileupWeightUp/F");
   outputTree->Branch("pileupWeightDown",&pileupWeightDown,"pileupWeightDown/F");
   outputTree->Branch("HTSF_Pol",&HTSF_Pol,"HTSF_Pol/F");
   outputTree->Branch("HTSF_PolUp",&HTSF_PolUp,"HTSF_PolUp/F");
   outputTree->Branch("HTSF_PolDn",&HTSF_PolDn,"HTSF_PolDn/F");
   outputTree->Branch("topPtWeight13TeV",&topPtWeight13TeV,"topPtWeight13TeV/F");
   outputTree->Branch("EGammaGsfSF",&EGammaGsfSF,"EGammaGsfSF/F");
   outputTree->Branch("MuTrkSF",&MuTrkSF,"MuTrkSF/F");
   outputTree->Branch("lepIdSF",&lepIdSF,"lepIdSF/F");
   outputTree->Branch("triggerSF",&triggerSF,"triggerSF/F");
   outputTree->Branch("triggerSFUncert",&triggerSFUncert,"triggerSFUncert/F");
   outputTree->Branch("isoSF",&isoSF,"isoSF/F");
   outputTree->Branch("muPtSF",&muPtSF,"muPtSF/F");

   // ttbar generator
   outputTree->Branch("ttbarMass_TTbarMassCalc",&ttbarMass_TTbarMassCalc,"ttbarMass_TTbarMassCalc/D");
   outputTree->Branch("genTopPt",&genTopPt,"genTopPt/F");
   outputTree->Branch("genAntiTopPt",&genAntiTopPt,"genAntiTopPt/F");

   // leptons
   outputTree->Branch("corr_met_MultiLepCalc",&corr_met_MultiLepCalc,"corr_met_MultiLepCalc/D");
   outputTree->Branch("corr_met_phi_MultiLepCalc",&corr_met_phi_MultiLepCalc,"corr_met_phi_MultiLepCalc/D");
   outputTree->Branch("corr_metmod_MultiLepCalc",&corr_metmod_MultiLepCalc,"corr_metmod_MultiLepCalc/D");
   outputTree->Branch("corr_metmod_phi_MultiLepCalc",&corr_metmod_phi_MultiLepCalc,"corr_metmod_phi_MultiLepCalc/D");
   outputTree->Branch("leptonPt_MultiLepCalc",&leptonPt_MultiLepCalc,"leptonPt_MultiLepCalc/F");
   outputTree->Branch("leptonEta_MultiLepCalc",&leptonEta_MultiLepCalc,"leptonEta_MultiLepCalc/F");
   outputTree->Branch("leptonPhi_MultiLepCalc",&leptonPhi_MultiLepCalc,"leptonPhi_MultiLepCalc/F");
   outputTree->Branch("leptonEnergy_MultiLepCalc",&leptonEnergy_MultiLepCalc,"leptonEnergy_MultiLepCalc/F");
   outputTree->Branch("leptonMVAValue_MultiLepCalc",&leptonMVAValue_MultiLepCalc,"leptonMVAValue_MultiLepCalc/F");
   outputTree->Branch("leptonMiniIso_MultiLepCalc",&leptonMiniIso_MultiLepCalc,"leptonMiniIso_MultiLepCalc/F");
   outputTree->Branch("MT_lepMet",&MT_lepMet,"MT_lepMet/F");
   outputTree->Branch("MT_lepMetmod",&MT_lepMetmod,"MT_lepMetmod/F");
   outputTree->Branch("minDPhi_MetJet",&minDPhi_MetJet,"minDPhi_MetJet/F");

   // AK4
   outputTree->Branch("theJetPt_JetSubCalc_PtOrdered",&theJetPt_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetEta_JetSubCalc_PtOrdered",&theJetEta_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetPhi_JetSubCalc_PtOrdered",&theJetPhi_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetEnergy_JetSubCalc_PtOrdered",&theJetEnergy_JetSubCalc_PtOrdered);
   outputTree->Branch("AK4JetDeepCSVb_MultiLepCalc_PtOrdered",&AK4JetDeepCSVb_MultiLepCalc_PtOrdered);
   outputTree->Branch("AK4JetDeepCSVbb_MultiLepCalc_PtOrdered",&AK4JetDeepCSVbb_MultiLepCalc_PtOrdered);
   outputTree->Branch("AK4JetDeepFlavb_MultiLepCalc_PtOrdered",&AK4JetDeepFlavb_MultiLepCalc_PtOrdered);
   outputTree->Branch("AK4JetDeepFlavbb_MultiLepCalc_PtOrdered",&AK4JetDeepFlavbb_MultiLepCalc_PtOrdered);
   outputTree->Branch("AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered",&AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered);
   outputTree->Branch("theJetHFlav_JetSubCalc_PtOrdered",&theJetHFlav_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetPFlav_JetSubCalc_PtOrdered",&theJetPFlav_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetBTag_JetSubCalc_PtOrdered",&theJetBTag_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetBTagDeepCSV_JetSubCalc_PtOrdered",&theJetBTagDeepCSV_JetSubCalc_PtOrdered);
   outputTree->Branch("AK4HTpMETpLepPt",&AK4HTpMETpLepPt,"AK4HTpMETpLepPt/F");
   outputTree->Branch("AK4HT",&AK4HT,"AK4HT/F");
   outputTree->Branch("NJets_JetSubCalc",&NJets_JetSubCalc,"NJets_JetSubCalc/I");
   outputTree->Branch("NJetsDeepFlav_JetSubCalc",&NJetsDeepFlav_JetSubCalc,"NJetsDeepFlav_JetSubCalc/I");
   outputTree->Branch("NJetsDeepCSV_JetSubCalc",&NJetsDeepCSV_JetSubCalc,"NJetsDeepCSV_JetSubCalc/I");
   outputTree->Branch("NJetsDeepFlavwithSF_JetSubCalc",&NJetsDeepFlavwithSF_JetSubCalc,"NJetsDeepFlavwithSF_JetSubCalc/I");
   outputTree->Branch("NJetsDeepCSVwithSF_JetSubCalc",&NJetsDeepCSVwithSF_JetSubCalc,"NJetsDeepCSVwithSF_JetSubCalc/I");
   outputTree->Branch("deltaR_lepMinMlb",&deltaR_lepMinMlb,"deltaR_lepMinMlb/F");
   outputTree->Branch("deltaR_lepMinMlj",&deltaR_lepMinMlj,"deltaR_lepMinMlj/F");
   outputTree->Branch("minMleppBjet",&minMleppBjet,"minMleppBjet/F");
   outputTree->Branch("minMleppJet",&minMleppJet,"minMleppJet/F");
   outputTree->Branch("minDR_lepJet",&minDR_lepJet,"minDR_lepJet/F");
   outputTree->Branch("ptRel_lepJet",&ptRel_lepJet,"ptRel_lepJet/F");
   outputTree->Branch("deltaR_lepJets",&deltaR_lepJets);
   outputTree->Branch("deltaR_lepBJets",&deltaR_lepBJets);

   // jet truth
   outputTree->Branch("HadronicVHtID_JetSubCalc",&HadronicVHtID_JetSubCalc);
   outputTree->Branch("HadronicVHtPt_JetSubCalc",&HadronicVHtPt_JetSubCalc);
   outputTree->Branch("HadronicVHtEta_JetSubCalc",&HadronicVHtEta_JetSubCalc);
   outputTree->Branch("HadronicVHtPhi_JetSubCalc",&HadronicVHtPhi_JetSubCalc);
   outputTree->Branch("HadronicVHtEnergy_JetSubCalc",&HadronicVHtEnergy_JetSubCalc);
   outputTree->Branch("theJetAK8Wmatch_JetSubCalc_PtOrdered",&theJetAK8Wmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Tmatch_JetSubCalc_PtOrdered",&theJetAK8Tmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Zmatch_JetSubCalc_PtOrdered",&theJetAK8Zmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Hmatch_JetSubCalc_PtOrdered",&theJetAK8Hmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8MatchedPt_JetSubCalc_PtOrdered",&theJetAK8MatchedPt_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Truth_JetSubCalc_PtOrdered",&theJetAK8Truth_JetSubCalc_PtOrdered);

   // AK8
   outputTree->Branch("NJetsAK8_JetSubCalc",&NJetsAK8_JetSubCalc,"NJetsAK8_JetSubCalc/I");
   outputTree->Branch("theJetAK8Pt_JetSubCalc_PtOrdered",&theJetAK8Pt_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Eta_JetSubCalc_PtOrdered",&theJetAK8Eta_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Phi_JetSubCalc_PtOrdered",&theJetAK8Phi_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Mass_JetSubCalc_PtOrdered",&theJetAK8Mass_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Energy_JetSubCalc_PtOrdered",&theJetAK8Energy_JetSubCalc_PtOrdered);
   outputTree->Branch("minDR_leadAK8otherAK8",&minDR_leadAK8otherAK8,"minDR_leadAK8otherAK8/F");
   outputTree->Branch("minDR_lepAK8",&minDR_lepAK8,"minDR_lepAK8/F");
   outputTree->Branch("ptRel_lepAK8",&ptRel_lepAK8,"ptRel_lepAK8/F");
   outputTree->Branch("deltaR_lepAK8s",&deltaR_lepAK8s);

   // mass + sub tagging 
   outputTree->Branch("maxProb_JetSubCalc_PtOrdered",&maxProb_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered",&theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered",&theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SoftDropRaw_JetSubCalc_PtOrdered",&theJetAK8SoftDropRaw_PtOrdered);
   outputTree->Branch("theJetAK8SoftDropCorr_JetSubCalc_PtOrdered",&theJetAK8SoftDropCorr_PtOrdered);
   outputTree->Branch("theJetAK8DoubleB_JetSubCalc_PtOrdered",&theJetAK8DoubleB_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SoftDrop_PtOrdered",&theJetAK8SoftDrop_PtOrdered);
   outputTree->Branch("theJetAK8NjettinessTau1_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau1_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8NjettinessTau2_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau2_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8NjettinessTau3_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau3_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSTau1_JetSubCalc_PtOrdered",&theJetAK8CHSTau1_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSTau2_JetSubCalc_PtOrdered",&theJetAK8CHSTau2_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSTau3_JetSubCalc_PtOrdered",&theJetAK8CHSTau3_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered",&theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SDSubjetSize_JetSubCalc_PtOrdered",&theJetAK8SDSubjetSize_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered",&theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered",&theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered);

   // DeepAK8 tagging
   outputTree->Branch("dnn_largest_DeepAK8Calc_PtOrdered",&dnn_largest_DeepAK8Calc_PtOrdered);
   outputTree->Branch("dnn_B_DeepAK8Calc_PtOrdered",&dnn_B_DeepAK8Calc_PtOrdered);
   outputTree->Branch("dnn_J_DeepAK8Calc_PtOrdered",&dnn_J_DeepAK8Calc_PtOrdered);
   outputTree->Branch("dnn_W_DeepAK8Calc_PtOrdered",&dnn_W_DeepAK8Calc_PtOrdered);
   outputTree->Branch("dnn_Z_DeepAK8Calc_PtOrdered",&dnn_Z_DeepAK8Calc_PtOrdered);
   outputTree->Branch("dnn_H_DeepAK8Calc_PtOrdered",&dnn_H_DeepAK8Calc_PtOrdered);
   outputTree->Branch("dnn_T_DeepAK8Calc_PtOrdered",&dnn_T_DeepAK8Calc_PtOrdered);
   outputTree->Branch("probSum_DeepAK8_decay",&probSum_DeepAK8_decay,"probSum_DeepAK8_decay/F");
   outputTree->Branch("probSum_DeepAK8_all",&probSum_DeepAK8_all,"probSum_DeepAK8_all/F");
   outputTree->Branch("probSum_DeepAK8_four",&probSum_DeepAK8_four,"probSum_DeepAK8_four/F");
   outputTree->Branch("nB_DeepAK8",&nB_DeepAK8,"nB_DeepAK8/I");
   outputTree->Branch("nH_DeepAK8",&nH_DeepAK8,"nH_DeepAK8/I");
   outputTree->Branch("nJ_DeepAK8",&nJ_DeepAK8,"nJ_DeepAK8/I");
   outputTree->Branch("nT_DeepAK8",&nT_DeepAK8,"nT_DeepAK8/I");
   outputTree->Branch("nW_DeepAK8",&nW_DeepAK8,"nW_DeepAK8/I");
   outputTree->Branch("nZ_DeepAK8",&nZ_DeepAK8,"nZ_DeepAK8/I");
   outputTree->Branch("DeepAK8SF_TeffUp",&DeepAK8SF_TeffUp,"DeepAK8SF_TeffUp/F");
   outputTree->Branch("DeepAK8SF_HeffUp",&DeepAK8SF_HeffUp,"DeepAK8SF_HeffUp/F");
   outputTree->Branch("DeepAK8SF_ZeffUp",&DeepAK8SF_ZeffUp,"DeepAK8SF_ZeffUp/F");
   outputTree->Branch("DeepAK8SF_WeffUp",&DeepAK8SF_WeffUp,"DeepAK8SF_WeffUp/F");
   outputTree->Branch("DeepAK8SF_BeffUp",&DeepAK8SF_BeffUp,"DeepAK8SF_BeffUp/F");
   outputTree->Branch("DeepAK8SF_JeffUp",&DeepAK8SF_JeffUp,"DeepAK8SF_JeffUp/F");
   outputTree->Branch("DeepAK8SF_TmisUp",&DeepAK8SF_TmisUp,"DeepAK8SF_TmisUp/F");
   outputTree->Branch("DeepAK8SF_HmisUp",&DeepAK8SF_HmisUp,"DeepAK8SF_HmisUp/F");
   outputTree->Branch("DeepAK8SF_ZmisUp",&DeepAK8SF_ZmisUp,"DeepAK8SF_ZmisUp/F");
   outputTree->Branch("DeepAK8SF_WmisUp",&DeepAK8SF_WmisUp,"DeepAK8SF_WmisUp/F");
   outputTree->Branch("DeepAK8SF_BmisUp",&DeepAK8SF_BmisUp,"DeepAK8SF_BmisUp/F");
   outputTree->Branch("DeepAK8SF_JmisUp",&DeepAK8SF_JmisUp,"DeepAK8SF_JmisUp/F");
   outputTree->Branch("DeepAK8SF_TeffDn",&DeepAK8SF_TeffDn,"DeepAK8SF_TeffDn/F");
   outputTree->Branch("DeepAK8SF_HeffDn",&DeepAK8SF_HeffDn,"DeepAK8SF_HeffDn/F");
   outputTree->Branch("DeepAK8SF_ZeffDn",&DeepAK8SF_ZeffDn,"DeepAK8SF_ZeffDn/F");
   outputTree->Branch("DeepAK8SF_WeffDn",&DeepAK8SF_WeffDn,"DeepAK8SF_WeffDn/F");
   outputTree->Branch("DeepAK8SF_BeffDn",&DeepAK8SF_BeffDn,"DeepAK8SF_BeffDn/F");
   outputTree->Branch("DeepAK8SF_JeffDn",&DeepAK8SF_JeffDn,"DeepAK8SF_JeffDn/F");
   outputTree->Branch("DeepAK8SF_TmisDn",&DeepAK8SF_TmisDn,"DeepAK8SF_TmisDn/F");
   outputTree->Branch("DeepAK8SF_HmisDn",&DeepAK8SF_HmisDn,"DeepAK8SF_HmisDn/F");
   outputTree->Branch("DeepAK8SF_ZmisDn",&DeepAK8SF_ZmisDn,"DeepAK8SF_ZmisDn/F");
   outputTree->Branch("DeepAK8SF_WmisDn",&DeepAK8SF_WmisDn,"DeepAK8SF_WmisDn/F");
   outputTree->Branch("DeepAK8SF_BmisDn",&DeepAK8SF_BmisDn,"DeepAK8SF_BmisDn/F");
   outputTree->Branch("DeepAK8SF_JmisDn",&DeepAK8SF_JmisDn,"DeepAK8SF_JmisDn/F");

   // VLQ reco   
   outputTree->Branch("W_mass",&W_mass,"W_mass/F");
   outputTree->Branch("W_pt",&W_pt,"W_pt/F");
   outputTree->Branch("W_dRLep",&W_dRLep,"W_dRLep/F");
   outputTree->Branch("t_mass",&t_mass,"t_mass/F");
   outputTree->Branch("t_pt",&t_pt,"t_pt/F");
   outputTree->Branch("t_dRWb",&t_dRWb,"t_dRWb/F");
   outputTree->Branch("deltaR_leptonicparticle_AK8_PtOrdered",&deltaR_leptonicparticle_AK8_PtOrdered);
   outputTree->Branch("isLeptonic_t",&isLeptonic_t,"isLeptonic_t/O");
   outputTree->Branch("isLeptonic_W",&isLeptonic_W,"isLeptonic_W/O");
   outputTree->Branch("Tprime1_DeepAK8_Mass",&Tprime1_DeepAK8_Mass,"Tprime1_DeepAK8_Mass/F");
   outputTree->Branch("Tprime2_DeepAK8_Mass",&Tprime2_DeepAK8_Mass,"Tprime2_DeepAK8_Mass/F");
   outputTree->Branch("Tprime1_DeepAK8_Pt",&Tprime1_DeepAK8_Pt,"Tprime1_DeepAK8_Pt/F");
   outputTree->Branch("Tprime2_DeepAK8_Pt",&Tprime2_DeepAK8_Pt,"Tprime2_DeepAK8_Pt/F");
   outputTree->Branch("Tprime1_DeepAK8_Eta",&Tprime1_DeepAK8_Eta,"Tprime1_DeepAK8_Eta/F");
   outputTree->Branch("Tprime2_DeepAK8_Eta",&Tprime2_DeepAK8_Eta,"Tprime2_DeepAK8_Eta/F");
   outputTree->Branch("Tprime1_DeepAK8_Phi",&Tprime1_DeepAK8_Phi,"Tprime1_DeepAK8_Phi/F");
   outputTree->Branch("Tprime2_DeepAK8_Phi",&Tprime2_DeepAK8_Phi,"Tprime2_DeepAK8_Phi/F");
   outputTree->Branch("Tprime1_DeepAK8_deltaR",&Tprime1_DeepAK8_deltaR,"Tprime1_DeepAK8_deltaR/F");
   outputTree->Branch("Tprime2_DeepAK8_deltaR",&Tprime2_DeepAK8_deltaR,"Tprime2_DeepAK8_deltaR/F");
   outputTree->Branch("isValidTTDecayMode_DeepAK8",&validTDecay_DeepAK8,"validTDecay_DeepAK8/O");
   outputTree->Branch("taggedBWBW_DeepAK8",&taggedBWBW_DeepAK8,"taggedBWBW_DeepAK8/O");
   outputTree->Branch("taggedTHBW_DeepAK8",&taggedTHBW_DeepAK8,"taggedTHBW_DeepAK8/O");
   outputTree->Branch("taggedTHTH_DeepAK8",&taggedTHTH_DeepAK8,"taggedTHTH_DeepAK8/O");
   outputTree->Branch("taggedTZBW_DeepAK8",&taggedTZBW_DeepAK8,"taggedTZBW_DeepAK8/O");
   outputTree->Branch("taggedTZTH_DeepAK8",&taggedTZTH_DeepAK8,"taggedTZTH_DeepAK8/O");
   outputTree->Branch("taggedTZTZ_DeepAK8",&taggedTZTZ_DeepAK8,"taggedTZTZ_DeepAK8/O");
   outputTree->Branch("highPtAK8Jet1_SoftDropCorrectedMass",&highPtAK8Jet1_SoftDropCorrectedMass,"highPtAK8Jet1_SoftDropCorrectedMass/F");
   outputTree->Branch("highPtAK8Jet2_SoftDropCorrectedMass",&highPtAK8Jet2_SoftDropCorrectedMass,"highPtAK8Jet2_SoftDropCorrectedMass/F");
   outputTree->Branch("highPtAK8Jet3_SoftDropCorrectedMass",&highPtAK8Jet3_SoftDropCorrectedMass,"highPtAK8Jet3_SoftDropCorrectedMass/F");
   outputTree->Branch("leptonicTprimeJetIDs_DeepAK8",&leptonicTprimeJetIDs_DeepAK8);
   outputTree->Branch("hadronicTprimeJetIDs_DeepAK8",&hadronicTprimeJetIDs_DeepAK8);

   outputTree->Branch("Bprime1_DeepAK8_Mass",&Bprime1_DeepAK8_Mass,"Bprime1_DeepAK8_Mass/F");
   outputTree->Branch("Bprime2_DeepAK8_Mass",&Bprime2_DeepAK8_Mass,"Bprime2_DeepAK8_Mass/F");
   outputTree->Branch("Bprime1_DeepAK8_Pt",&Bprime1_DeepAK8_Pt,"Bprime1_DeepAK8_Pt/F");
   outputTree->Branch("Bprime2_DeepAK8_Pt",&Bprime2_DeepAK8_Pt,"Bprime2_DeepAK8_Pt/F");
   outputTree->Branch("Bprime1_DeepAK8_Eta",&Bprime1_DeepAK8_Eta,"Bprime1_DeepAK8_Eta/F");
   outputTree->Branch("Bprime2_DeepAK8_Eta",&Bprime2_DeepAK8_Eta,"Bprime2_DeepAK8_Eta/F");
   outputTree->Branch("Bprime1_DeepAK8_Phi",&Bprime1_DeepAK8_Phi,"Bprime1_DeepAK8_Phi/F");
   outputTree->Branch("Bprime2_DeepAK8_Phi",&Bprime2_DeepAK8_Phi,"Bprime2_DeepAK8_Phi/F");
   outputTree->Branch("Bprime1_DeepAK8_deltaR",&Bprime1_DeepAK8_deltaR,"Bprime1_DeepAK8_deltaR/F");
   outputTree->Branch("Bprime2_DeepAK8_deltaR",&Bprime2_DeepAK8_deltaR,"Bprime2_DeepAK8_deltaR/F");
   outputTree->Branch("isValidBBDecayMode_DeepAK8",&validBDecay_DeepAK8,"validBDecay_DeepAK8/O");
   outputTree->Branch("taggedTWTW_DeepAK8",&taggedTWTW_DeepAK8,"taggedTWTW_DeepAK8/O");
   outputTree->Branch("taggedBHTW_DeepAK8",&taggedBHTW_DeepAK8,"taggedBZTW_DeepAK8/O");
   outputTree->Branch("taggedBZTW_DeepAK8",&taggedBZTW_DeepAK8,"taggedBHTW_DeepAK8/O");
   outputTree->Branch("leptonicBprimeJetIDs_DeepAK8",&leptonicBprimeJetIDs_DeepAK8);
   outputTree->Branch("hadronicBprimeJetIDs_DeepAK8",&hadronicBprimeJetIDs_DeepAK8);

   // VLQ dnn output
   outputTree->Branch("dnn_WJets",&dnn_WJets,"dnn_WJets/F");
   outputTree->Branch("dnn_ttbar",&dnn_ttbar,"dnn_ttbar/F");
   outputTree->Branch("dnn_Tprime",&dnn_Tprime,"dnn_Tprime/F");
   outputTree->Branch("dnn_WJetsBB",&dnn_WJetsBB,"dnn_WJetsBB/F");
   outputTree->Branch("dnn_ttbarBB",&dnn_ttbarBB,"dnn_ttbarBB/F");
   outputTree->Branch("dnn_Bprime",&dnn_Bprime,"dnn_Bprime/F");

   // ----------------------------------------------------------------------------
   // Define and initialize objects / cuts / efficiencies
   // ----------------------------------------------------------------------------

   // basic cuts
   float metCut=50;
   int   htCut=510;
   int   nAK8jetsCut=0;
   float lepPtCut=50;
   float elEtaCut=2.5;
   float muEtaCut=2.4;
   float jetEtaCut=2.4;
   float ak8EtaCut=2.4;
   float jetPtCut=30;
   float ak8PtCut=200;

   // counters
   int n_vectorSizeMismatch = 0;

   int n_jetstotal        = 0;
   int n_jetsnearlep      = 0;
   int n_jetspassed       = 0;
   int npass_ThreeJets    = 0;
   int npass_trigger      = 0;
   int npass_mu500        = 0;
   int npass_met          = 0;
   int npass_ht           = 0;
   int npass_nAK8jets     = 0;
   int npass_nHjets       = 0;
   int npass_lepPt        = 0;
   int npass_ElEta        = 0;
   int npass_MuEta        = 0;
   int npass_all          = 0;
   int Nelectrons         = 0;
   int Nmuons             = 0;

   // Lorentz vectors
   TLorentzVector jet_lv;
   TLorentzVector lepton_lv;
   TLorentzVector ak8_lv;
   
   // Muon tracking efficiencies, https://twiki.cern.ch/twiki/bin/viewauth/CMS/MuonWorkInProgressAndPagResults#Results_on_the_full_2016_data, Feb 16 release for full data
   float tracksf[15] = {0.991237,0.994853,0.996413,0.997157,0.997512,0.99756,0.996745,0.996996,0.99772,0.998604,0.998321,0.997682,0.995252,0.994919,0.987334};

   // Pileup distributions -- ReReco Data vs Moriond17MC
   double pileup_central[75] = {3.603e-01, 9.378e-01, 1.201e+00, 9.651e-01, 1.112e+00, 1.162e+00, 7.847e-01, 4.960e-01, 7.422e-01, 8.839e-01, 9.662e-01, 1.071e+00, 1.124e+00, 1.175e+00, 1.203e+00, 1.208e+00, 1.200e+00, 1.182e+00, 1.144e+00, 1.096e+00, 1.065e+00, 1.051e+00, 1.052e+00, 1.051e+00, 1.050e+00, 1.057e+00, 1.072e+00, 1.083e+00, 1.095e+00, 1.108e+00, 1.094e+00, 1.084e+00, 1.042e+00, 9.850e-01, 9.095e-01, 8.196e-01, 7.159e-01, 6.107e-01, 5.032e-01, 4.052e-01, 3.092e-01, 2.285e-01, 1.636e-01, 1.133e-01, 7.738e-02, 5.090e-02, 3.180e-02, 2.013e-02, 1.226e-02, 7.425e-03, 4.389e-03, 2.614e-03, 1.572e-03, 9.679e-04, 7.333e-04, 6.786e-04, 7.342e-04, 9.346e-04, 1.346e-03, 1.888e-03, 3.248e-03, 3.966e-03, 4.872e-03, 5.119e-03, 5.452e-03, 5.338e-03, 5.112e-03, 4.397e-03, 4.023e-03, 3.359e-03, 2.987e-03, 2.770e-03, 2.278e-03, 1.982e-03, 1.765e-03};

   double pileup_down[75] = {3.733e-01, 1.197e+00, 1.263e+00, 1.102e+00, 1.240e+00, 1.278e+00, 9.076e-01, 7.680e-01, 1.093e+00, 1.345e+00, 1.489e+00, 1.526e+00, 1.496e+00, 1.500e+00, 1.498e+00, 1.445e+00, 1.367e+00, 1.298e+00, 1.228e+00, 1.165e+00, 1.125e+00, 1.091e+00, 1.065e+00, 1.041e+00, 1.019e+00, 1.005e+00, 9.973e-01, 9.851e-01, 9.722e-01, 9.567e-01, 9.141e-01, 8.732e-01, 8.075e-01, 7.337e-01, 6.501e-01, 5.605e-01, 4.658e-01, 3.750e-01, 2.886e-01, 2.147e-01, 1.498e-01, 1.001e-01, 6.433e-02, 3.962e-02, 2.392e-02, 1.382e-02, 7.544e-03, 4.163e-03, 2.215e-03, 1.187e-03, 6.441e-04, 3.850e-04, 2.739e-04, 2.425e-04, 2.913e-04, 3.993e-04, 5.467e-04, 7.711e-04, 1.143e-03, 1.598e-03, 2.706e-03, 3.234e-03, 3.878e-03, 3.973e-03, 4.121e-03, 3.928e-03, 3.659e-03, 3.059e-03, 2.719e-03, 2.203e-03, 1.901e-03, 1.709e-03, 1.362e-03, 1.147e-03, 9.884e-04};

   double pileup_up[75] = {3.510e-01, 7.384e-01, 1.136e+00, 8.481e-01, 1.011e+00, 1.047e+00, 7.158e-01, 3.479e-01, 5.006e-01, 6.065e-01, 6.335e-01, 7.320e-01, 8.266e-01, 9.118e-01, 9.603e-01, 9.892e-01, 1.024e+00, 1.052e+00, 1.051e+00, 1.027e+00, 1.005e+00, 9.982e-01, 1.015e+00, 1.038e+00, 1.058e+00, 1.085e+00, 1.121e+00, 1.155e+00, 1.192e+00, 1.232e+00, 1.245e+00, 1.269e+00, 1.260e+00, 1.233e+00, 1.180e+00, 1.103e+00, 1.001e+00, 8.905e-01, 7.691e-01, 6.545e-01, 5.326e-01, 4.236e-01, 3.297e-01, 2.501e-01, 1.888e-01, 1.381e-01, 9.654e-02, 6.875e-02, 4.733e-02, 3.248e-02, 2.175e-02, 1.456e-02, 9.619e-03, 6.146e-03, 4.301e-03, 3.097e-03, 2.253e-03, 1.894e-03, 2.009e-03, 2.389e-03, 3.847e-03, 4.626e-03, 5.722e-03, 6.110e-03, 6.639e-03, 6.646e-03, 6.514e-03, 5.738e-03, 5.381e-03, 4.607e-03, 4.204e-03, 4.003e-03, 3.382e-03, 3.025e-03, 2.770e-03};

   // Polynominals for WJets HT scaling
   TF1 *poly2 = new TF1("poly2","max([6],[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x + [5]*x*x*x*x*x)",100,5000);
   poly2->SetParameter(0,    0.998174);  
   poly2->SetParameter(1, 8.40861e-05); 
   poly2->SetParameter(2,-6.63274e-07);
   poly2->SetParameter(3, 4.09272e-10); 
   poly2->SetParameter(4,-9.50233e-14); 
   poly2->SetParameter(5, 7.59648e-18); 
   poly2->SetParameter(6,0.402806);
   
   TF1 *poly2U = new TF1("poly2U","max([6],[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x + [5]*x*x*x*x*x)",100,5000);
   poly2U->SetParameter(0,    0.998164);  
   poly2U->SetParameter(1, 8.51652e-05); 
   poly2U->SetParameter(2,-6.62919e-07);
   poly2U->SetParameter(3,  4.1205e-10); 
   poly2U->SetParameter(4,-9.57795e-14); 
   poly2U->SetParameter(5, 7.67371e-18); 
   poly2U->SetParameter(6,0.454456);
   
   TF1 *poly2D = new TF1("poly2D","max([6],[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x + [5]*x*x*x*x*x)",100,5000);
   poly2D->SetParameter(0,    0.998183);  
   poly2D->SetParameter(1, 8.30069e-05); 
   poly2D->SetParameter(2,-6.63629e-07);
   poly2D->SetParameter(3, 4.06495e-10); 
   poly2D->SetParameter(4,-9.42671e-14); 
   poly2D->SetParameter(5, 7.51924e-18); 
   poly2D->SetParameter(6,0.351156);

   
  // ----------------------------------------------------------------------------
  // RUN THE EVENT LOOP
  // ----------------------------------------------------------------------------

   cout << "RUN CONFIG: isMC = " << isMC << ", isNominal for btag = " << isNominal << endl;
   cout << "isSig = " << isSig << ", SigMass = " << SigMass << endl;
   cout << "For W's: isTT = " << isTT << ", isSTt = " << isSTt << ", isSTtW = " << isSTtW << endl;
   cout << "Fot jets & PDF: isTOP = " << isTOP << ", isMadgraphBkg = " << isMadgraphBkg << endl;
   cout << "Shift (Bup,Bdn,Lup,Ldn,None) = (" << isBUp << "," << isBDn << "," << isLUp << "," << isLDn << "," << isNominal << ")" << endl;
   
   Long64_t nentries = inputTree->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = inputTree->GetEntry(jentry);   nbytes += nb;
      if (Cut(ientry) != 1) continue;
      
      //      if (ientry > 50) continue;
      
      if(jentry % 1000 ==0) std::cout<<"Completed "<<jentry<<" out of "<<nentries<<" events"<<std::endl;

      // ----------------------------------------------------------------------------
      // Filter input file by mass or decay
      // ----------------------------------------------------------------------------

      float confusionTruth = -1;
      
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
      if(outBWBW) confusionTruth = 0.5;
      if(outTZBW) confusionTruth = 1.5;
      if(outTHBW) confusionTruth = 2.5;
      if(outTZTH) confusionTruth = 3.5;
      if(outTZTZ) confusionTruth = 4.5;
      if(outTHTH) confusionTruth = 5.5;
      if(outTWTW) confusionTruth = 6.5;
      if(outBZTW) confusionTruth = 7.5;
      if(outBHTW) confusionTruth = 8.5;
      if(outBZBH) confusionTruth = 9.5;
      if(outBZBZ) confusionTruth = 10.5;
      if(outBHBH) confusionTruth = 11.5;

      // ----------------------------------------------------------------------------
      // Assign as electron or muon event
      // ----------------------------------------------------------------------------
      // **** If we had saveLooseLeps == True in TTsinglelep_MC_cfg.py then this needs work!
      // **** Choose an electron and muon ID for "tight" and find events with only 1 tight el or mu by that definition
      isElectron = 0;
      isMuon = 0;
      if(elPt_MultiLepCalc->size()==0 && muPt_MultiLepCalc->size()==0){std::cout << "got no leptons, something wrong" << std::endl; continue;}
      if(elPt_MultiLepCalc->size()>0 && muPt_MultiLepCalc->size()>0) std::cout << "got el and mu, something wrong" << std::endl;
      if(elPt_MultiLepCalc->size()>1 || muPt_MultiLepCalc->size()>1) std::cout << "got more than one el or mu, something wrong" << std::endl;
      if(elPt_MultiLepCalc->size()>0 && muPt_MultiLepCalc->size()==0) {isElectron = 1; isMuon = 0;}
      if(elPt_MultiLepCalc->size()==0 && muPt_MultiLepCalc->size()>0) {isElectron = 0; isMuon = 1;}
      if(isElectron==0 && isMuon==0){std::cout << "got no leptons, something wrong" << std::endl; continue;}

      if(isSM && isElectron == 1) continue;
      if(isSE && isMuon == 1) continue;

      double leppt = 0;
      double lepeta = 0;
      if(isElectron){leppt = elPt_MultiLepCalc->at(0); lepeta = elEta_MultiLepCalc->at(0);}
      if(isMuon){leppt = muPt_MultiLepCalc->at(0); lepeta = muEta_MultiLepCalc->at(0);}

      // ----------------------------------------------------------------------------
      // Check jet size alignment
      // ----------------------------------------------------------------------------

      unsigned int ak8ptsize = theJetAK8Pt_JetSubCalc->size();
      unsigned int deepak8size = dnn_H_DeepAK8Calc->size();
      if(deepak8size != ak8ptsize){
	std::cout << "Something's wrong! DeepAK8 has " << deepak8size << " jets, expected " << ak8ptsize << std::endl;
	continue;
      }

      // ----------------------------------------------------------------------------
      // Pileup weight calculation
      // ----------------------------------------------------------------------------

      pileupWeight = 1.0;
      pileupWeightUp = 1.0;
      pileupWeightDown = 1.0;
	
      if(isMC){
	if(nTrueInteractions_MultiLepCalc > 74) nTrueInteractions_MultiLepCalc = 74;
	if(nTrueInteractions_MultiLepCalc < 0) nTrueInteractions_MultiLepCalc = 0;
	pileupWeight = pileup_central[nTrueInteractions_MultiLepCalc];
	pileupWeightUp = pileup_up[nTrueInteractions_MultiLepCalc];
	pileupWeightDown = pileup_down[nTrueInteractions_MultiLepCalc];
      }

      // ----------------------------------------------------------------------------
      // Lepton 4-vectors, calculate MT and electron trigger presel value
      // ----------------------------------------------------------------------------

      // Set lepton 4-vectors
      double lepM;
      double lepphi;
      if (isMuon){ 
	lepM = 0.105658367;
	lepphi = muPhi_MultiLepCalc->at(0);
	lepton_lv.SetPtEtaPhiM(muPt_MultiLepCalc->at(0),muEta_MultiLepCalc->at(0),muPhi_MultiLepCalc->at(0),lepM);
      }
      else{
	lepM = 0.00051099891;
	lepphi = elPhi_MultiLepCalc->at(0);
	lepton_lv.SetPtEtaPhiM(elPt_MultiLepCalc->at(0),elEta_MultiLepCalc->at(0),elPhi_MultiLepCalc->at(0),lepM);
      }

      MT_lepMet = sqrt(2*leppt*corr_met_MultiLepCalc*(1 - cos(lepphi - corr_met_phi_MultiLepCalc)));

      // ----------------------------------------------------------------------------
      // Assign Lepton scale factor or efficiency weights, save trigger pass/fail
      // ----------------------------------------------------------------------------

      DataPastTrigger = 0;
      MCPastTrigger = 0;
      EGammaGsfSF = 1.0;
      lepIdSF = 1.0;
      MuTrkSF = 1.0;
      float mu_BCDEF = 1.0;
      float mu_GH = 1.0;
      muPtSF = 1.0;

      triggerSF = 1.0;
      triggerSFUncert = 0.0;
      isoSF = 1.0;
      if(isMC){ //MC triggers check
	if(isElectron){
	  std::string string_350 = "Ele15_IsoVVVL_PFHT350";
	  std::string string_400 = "Ele15_IsoVVVL_PFHT400";
	  std::string string_a = "Ele15_IsoVVVL_PFHT450";
	  std::string string_c = "Ele50_IsoVVVL_PFHT450";
	  std::string string_d = "Ele15_IsoVVVL_PFHT600";
	  std::string string_ORa = "Ele35_WPTight_Gsf";
	  std::string string_ORb = "Ele38_WPTight_Gsf";
	  for(unsigned int itrig=0; itrig < vsSelMCTriggersEl_MultiLepCalc->size(); itrig++){
	    if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find(string_a) != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find(string_c) != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find(string_d) != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find(string_350) != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find(string_400) != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find(string_ORa) != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	  }

	// EGamma updates 
	if (leppt < 45) 
	{
		if (fabs(lepeta) < 0.5) EGammaGsfSF = 0.984;
		else if (fabs(lepeta) < 1) EGammaGsfSF = 0.987;
		else if (fabs(lepeta) < 1.442) EGammaGsfSF = 0.992;
		else if (fabs(lepeta) < 1.556) EGammaGsfSF = 0.991;
		else if (fabs(lepeta) < 2) EGammaGsfSF = 0.998;
		else EGammaGsfSF = 1.016;
	}
	  else if (leppt < 75) 
	{
	   if (fabs(lepeta) < 0.5) EGammaGsfSF = 0.987;
		else if (fabs(lepeta) < 1) EGammaGsfSF = 0.998;
		else if (fabs(lepeta) < 1.442) EGammaGsfSF = 0.992;
		else if (fabs(lepeta) < 1.556) EGammaGsfSF = 0.962;
		else if (fabs(lepeta) < 2) EGammaGsfSF = 0.997;
		else EGammaGsfSF = 1.002;
	}
	  else if (leppt < 100) 
	{
	   if (fabs(lepeta) < 0.5) EGammaGsfSF = 0.997;
		else if (fabs(lepeta) < 1) EGammaGsfSF = 1.005;
		else if (fabs(lepeta) < 1.442) EGammaGsfSF = 1.008;
		else if (fabs(lepeta) < 1.556) EGammaGsfSF = 1.033;
		else if (fabs(lepeta) < 2) EGammaGsfSF = 1.015;
		else EGammaGsfSF = 1.018; 
	}
	  else  
	{
	    if (fabs(lepeta) < 0.5) EGammaGsfSF = 0.986;
		else if (fabs(lepeta) < 1) EGammaGsfSF = 0.994;
		else if (fabs(lepeta) < 1.442) EGammaGsfSF = 0.987;
		else if (fabs(lepeta) < 1.556) EGammaGsfSF = 1.002;
		else if (fabs(lepeta) < 2) EGammaGsfSF = 1.000;
		else EGammaGsfSF = 0.984;
	}

	// updated to 2016 Egamma scale factors: https://twiki.cern.ch/twiki/pub/CMS/EgammaIDRecipesRun2/2016LegacyReReco_ElectronMVA90noiso_Fall17V2.pdf
	if (leppt < 20) 
	{
	    if (lepeta < -2.0) lepIdSF = 1.017;
	    else if (lepeta < -1.566) lepIdSF =0.949 ;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.967;
	    else if (lepeta < 0.0) lepIdSF = 0.955;
	    else if (lepeta < 0.8) lepIdSF = 0.976;
	    else if (lepeta < 1.442) lepIdSF = 0.945;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.959;
	    else lepIdSF = 0.971; 
	}
	  else if (leppt < 35) 
	{
	    if (lepeta < -2.0) lepIdSF = 0.994;
	    else if (lepeta < -1.566) lepIdSF = 0.950;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.940;
	    else if (lepeta < 0.0) lepIdSF = 0.946;
	    else if (lepeta < 0.8) lepIdSF = 0.976;
	    else if (lepeta < 1.442) lepIdSF = 0.948;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.927;
	    else lepIdSF = 0.951; 
	}
	  else if (leppt < 50) 
	{
	    if (lepeta < -2.0) lepIdSF = 0.996;
	    else if (lepeta < -1.566) lepIdSF = 0.962;
	    else if (lepeta < -1.442) lepIdSF = 1.00;
	    else if (lepeta < -0.8) lepIdSF = 0.961;
	    else if (lepeta < 0.0) lepIdSF = 0.958;
	    else if (lepeta < 0.8) lepIdSF = 0.980;
	    else if (lepeta < 1.442) lepIdSF = 0.966;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.953;
	    else lepIdSF = 0.964; 
	}
	  else if (leppt < 100) 
		{
	    if (lepeta < -2.0) lepIdSF = 0.998;
	    else if (lepeta < -1.566) lepIdSF = 0.971;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.964;
	    else if (lepeta < 0.0) lepIdSF = 0.961;
	    else if (lepeta < 0.8) lepIdSF = 0.982;
	    else if (lepeta < 1.442) lepIdSF = 0.973;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.965;
	    else lepIdSF = 0.969; 
		}
	  else if (leppt < 110) 
	  {
	    if (lepeta < -2.0) lepIdSF = 1.005;
	    else if (lepeta < -1.566) lepIdSF = 0.988;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.979;
	    else if (lepeta < 0.0) lepIdSF = 0.979;
	    else if (lepeta < 0.8) lepIdSF = 0.991;
	    else if (lepeta < 1.442) lepIdSF = 0.997;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.988;
	    else lepIdSF = 0.990; 
	}
	  else 
	  {
	    if (lepeta < -2.0) lepIdSF = 0.941;
	    else if (lepeta < -1.566) lepIdSF = 1.003;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.974;
	    else if (lepeta < 0.0) lepIdSF = 0.978;
	    else if (lepeta < 0.8) lepIdSF = 0.972;
	    else if (lepeta < 1.442) lepIdSF = 0.971;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.953;
	    else lepIdSF = 0.960; 
	}

	  // mini isolation scale factors: https://wiwong.web.cern.ch/wiwong/Ele_Eff_Plots/2017passingMiniIsoTight/
	  if (leppt < 50){
            if (fabs(lepeta) < 0.8) isoSF = 0.997;
            else if (fabs(lepeta) < 1.442) isoSF = 0.999;
            else if (fabs(lepeta) < 1.566) isoSF = 1.009;
            else if (fabs(lepeta) < 2) isoSF = 0.998;
            else isoSF = 0.997;}
	  else if (leppt < 60){
            if (fabs(lepeta) < 0.8) isoSF = 0.998;
            else if (fabs(lepeta) < 1.442) isoSF = 0.999;
            else if (fabs(lepeta) < 1.566) isoSF = 1.022;
            else if (fabs(lepeta) < 2) isoSF = 0.999;
            else isoSF = 1.000;}
	  else if (leppt < 100){
            if (fabs(lepeta) < 0.8) isoSF = 0.998;
            else if (fabs(lepeta) < 1.442) isoSF = 1.001;
            else if (fabs(lepeta) < 1.566) isoSF = 1.024;
            else if (fabs(lepeta) < 2) isoSF = 1.001;
            else isoSF = 1.001;}
	  else if (leppt < 200){
            if (fabs(lepeta) < 0.8) isoSF = 0.999;
            else if (fabs(lepeta) < 1.442) isoSF = 1.001;
            else if (fabs(lepeta) < 1.566) isoSF = 1.021;
            else if (fabs(lepeta) < 2) isoSF = 1.003;
            else isoSF = 1.000;}
	  else{
            if (fabs(lepeta) < 0.8) isoSF = 1.000;
            else if (fabs(lepeta) < 1.442) isoSF = 1.001;
            else if (fabs(lepeta) < 1.566) isoSF = 1.008;
            else if (fabs(lepeta) < 2) isoSF = 1.000;
            else isoSF = 0.999;}

	  // Trigger Scale Factors, SF2017B_Bkg_LepPtEta_EOR.png & SF2017CDEF_Bkg_LepPtEta_EOR.png
	  float trigSFB = 1.0;
	  float trigSFCDEF = 1.0;
	  float trigSFBunc = 0.0;
	  float trigSFCDEFunc = 0.0;
	  if (fabs(lepeta) < 0.8){
	    if (leppt < 50) {trigSFB = 0.741; trigSFBunc = 0.079; trigSFCDEF = 1.051; trigSFCDEFunc = 0.018;}
	    else if (leppt < 60) {trigSFB = 0.830; trigSFBunc = 0.075; trigSFCDEF = 1.029; trigSFCDEFunc = 0.016;}
	    else if (leppt < 70) {trigSFB = 0.722; trigSFBunc = 0.092;  trigSFCDEF = 0.988; trigSFCDEFunc = 0.019;}
	    else if (leppt < 100) {trigSFB = 0.718; trigSFBunc = 0.053;  trigSFCDEF = 0.972; trigSFCDEFunc = 0.012;}
	    else if (leppt < 200) {trigSFB = 0.698; trigSFBunc = 0.050;  trigSFCDEF = 0.972; trigSFCDEFunc = 0.01;}
	    else {trigSFB = 1.021; trigSFBunc = 0.01;  trigSFCDEF = 0.964; trigSFCDEFunc = 0.019;}
	  }else if (fabs(lepeta) < 1.442){
            if (leppt < 50) {trigSFB = 0.735; trigSFBunc = 0.149;  trigSFCDEF = 1.020; trigSFCDEFunc = 0.029;}
            else if (leppt < 60) {trigSFB = 0.772; trigSFBunc = 0.138;  trigSFCDEF = 1.063; trigSFCDEFunc = 0.024;}
            else if (leppt < 70) {trigSFB = 0.711; trigSFBunc = 0.122;  trigSFCDEF = 0.962; trigSFCDEFunc = 0.031;}
            else if (leppt < 100) {trigSFB = 0.739; trigSFBunc = 0.078;  trigSFCDEF = 0.923; trigSFCDEFunc = 0.020;}
            else if (leppt < 200) {trigSFB = 0.803; trigSFBunc = 0.063;  trigSFCDEF = 0.957; trigSFCDEFunc = 0.015;}
            else {trigSFB = 0.801; trigSFBunc = 0.143;  trigSFCDEF = 1.015; trigSFCDEFunc = 0.015;}
	  }else if (fabs(lepeta) < 1.566) {trigSFB = 1.0; trigSFCDEF = 1.0;}
	  else if (fabs(lepeta) < 2.0){
            if (leppt < 50) {trigSFB = 0.987; trigSFBunc = 0.205;  trigSFCDEF = 1.060; trigSFCDEFunc = 0.059;}
            else if (leppt < 60) {trigSFB = 0.241; trigSFBunc = 0.079;  trigSFCDEF = 1.109; trigSFCDEFunc = 0.045;}
            else if (leppt < 70) {trigSFB = 0.213; trigSFBunc = 0.079;  trigSFCDEF = 1.061; trigSFCDEFunc = 0.054;}
            else if (leppt < 100) {trigSFB = 0.133; trigSFBunc = 0.079;  trigSFCDEF = 0.996; trigSFCDEFunc = 0.035;}
            else if (leppt < 200) {trigSFB = 0.199; trigSFBunc = 0.079;  trigSFCDEF = 0.960; trigSFCDEFunc = 0.039;}
            else {trigSFB = 1.144; trigSFBunc = 0.026;  trigSFCDEF = 0.924; trigSFCDEFunc = 0.099;}
	  }else {
            if (leppt < 50) {trigSFB = 1.098; trigSFBunc = 0.318;  trigSFCDEF = 1.007; trigSFCDEFunc = 0.087;}
            else if (leppt < 60) {trigSFB = 1.082; trigSFBunc = 0.199;  trigSFCDEF = 0.903; trigSFCDEFunc = 0.092;}
            else if (leppt < 70) {trigSFB = 1.0; trigSFBunc = 0.05;  trigSFCDEF = 1.037; trigSFCDEFunc = 0.077;}
            else if (leppt < 100) {trigSFB = 1.017; trigSFBunc = 0.158;  trigSFCDEF = 1.027; trigSFCDEFunc = 0.045;}
            else if (leppt < 200) {trigSFB = 1.0; trigSFBunc = 0.05;  trigSFCDEF = 0.910; trigSFCDEFunc = 0.071;}
            else {trigSFB = 1.0; trigSFBunc = 0.05;  trigSFCDEF = 0.910; trigSFCDEFunc = 0.071;}
	  }
	  triggerSF = (4.823*trigSFB + 36.734*trigSFCDEF)/41.557;
	  triggerSFUncert = sqrt( pow(4.823*trigSFBunc/41.557,2) + pow(36.734*trigSFCDEFunc/41.557,2) );
	}
	if(isMuon){
	  std::string string_350 = "Mu15_IsoVVVL_PFHT350";
	  std::string string_400 = "Mu15_IsoVVVL_PFHT400";
	  std::string string_a = "Mu15_IsoVVVL_PFHT450";
	  std::string string_d = "Mu50_IsoVVVL_PFHT450";
	  std::string string_e = "Mu15_IsoVVVL_PFHT600";
	  std::string string_ORb = "Mu50"; // not really saved in FWLJMET due to bug!
	  for(unsigned int itrig=0; itrig < vsSelMCTriggersMu_MultiLepCalc->size(); itrig++){
	    if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find(string_a) != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
            if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find(string_d) != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
            if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find(string_e) != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find(string_350) != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find(string_400) != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	  }

	  // isGlobal SF from 2016 analysis task force
	  if(lepton_lv.P() > 100 && fabs(lepeta) < 1.6) muPtSF = (0.9828 - 1.947e-5*lepton_lv.P())/(0.989 - 2.399e-6*lepton_lv.P());
	  else if(lepton_lv.P() > 275 && fabs(lepeta) > 1.6) muPtSF = (0.9893 - 3.666e-5*lepton_lv.P())/(0.9974 - 1.721e-5*lepton_lv.Pt());

	  // MiniIsoTight/Tight
	  // Jess Wong, approved in MUO 8/26/19, slide 37 upper left
	  if(leppt < 30){
            if(fabs(lepeta) < 0.9) isoSF= 0.9961;
            else if(fabs(lepeta) <  1.2) isoSF= 0.9921;
            else if(fabs(lepeta) <  2.1) isoSF= 0.9973;
            else if(fabs(lepeta) <  2.4) isoSF= 0.9990;
          }
          else if(leppt < 40){
            if(fabs(lepeta) < 0.9) isoSF= 0.9968;
            else if(fabs(lepeta) <  1.2) isoSF= 0.9962;
            else if(fabs(lepeta) <  2.1) isoSF= 0.9978;
            else if(fabs(lepeta) <  2.4) isoSF= 0.9988;
          }
          else if(leppt < 50){
            if(fabs(lepeta) < 0.9) isoSF= 0.9984;
            else if(fabs(lepeta) <  1.2) isoSF= 0.9976;
            else if(fabs(lepeta) <  2.1) isoSF= 0.9984;
            else if(fabs(lepeta) <  2.4) isoSF= 0.9996;
          }
          else if(leppt < 60){
            if(fabs(lepeta) < 0.9) isoSF= 0.9992;
            else if(fabs(lepeta) <  1.2) isoSF= 0.9989;
            else if(fabs(lepeta) <  2.1) isoSF= 0.9993;
            else if(fabs(lepeta) <  2.4) isoSF= 0.9988;
          }
          else if(leppt < 120){
            if(fabs(lepeta) < 0.9) isoSF= 0.9996;
            else if(fabs(lepeta) <  1.2) isoSF= 1.0000;
            else if(fabs(lepeta) <  2.1) isoSF= 1.0004;
            else if(fabs(lepeta) <  2.4) isoSF= 0.9987;
          }
	  else{ // ignoring the 200-300, low stats, using 120+
	    if(fabs(lepeta) < 0.9) isoSF= 0.9999;
            else if(fabs(lepeta) <  1.2) isoSF= 0.9992;
            else if(fabs(lepeta) <  2.1) isoSF= 1.0005;
            else if(fabs(lepeta) <  2.4) isoSF= 0.9964;
	  }
	  
	  // Cut based tight id
	  // Scale Factor 3: https://twiki.cern.ch/twiki/pub/CMS/MuonReferenceEffs2017/RunBCDEF_SF_ID.json
	  if (fabs(lepeta) < 0.90) {
	    if (leppt < 25.0) lepIdSF = 0.9910777627756951;
	    else if (leppt < 30.0) lepIdSF = 0.987410468262084;
	    else if (leppt < 40.0) lepIdSF = 0.9907753279135898;
	    else if (leppt < 50.0) lepIdSF = 0.9892483588952047;
	    else if (leppt < 60.0) lepIdSF = 0.9855545160334763;
	    else lepIdSF = 0.9898057377093389; 
	  }
	  else if (fabs(lepeta) < 1.20) {
	    if (leppt < 25.0) lepIdSF = 0.9927389275515244;
	    else if (leppt < 30.0) lepIdSF = 0.985063939762512;
	    else if (leppt < 40.0) lepIdSF = 0.9865359464182247;
	    else if (leppt < 50.0) lepIdSF = 0.984913093101493;
	    else if (leppt < 60.0) lepIdSF = 0.9839056384760008;
	    else lepIdSF = 0.984060403143468; 
	  }  
	  else if (fabs(lepeta) < 2.10) {
	    if (leppt < 25.0) lepIdSF = 0.9924252719877384;
	    else if (leppt < 30.0) lepIdSF = 0.9890884461284933;
	    else if (leppt < 40.0) lepIdSF = 0.9946469069883841;
	    else if (leppt < 50.0) lepIdSF = 0.9926528825155183;
	    else if (leppt < 60.0) lepIdSF = 0.9906364222943529;
	    else lepIdSF = 0.9920464322143979; 
	  }
	  else {
	    if (leppt < 25.0) lepIdSF = 0.9758095839531763;
	    else if (leppt < 30.0) lepIdSF = 0.9745153594179884;
	    else if (leppt < 40.0) lepIdSF = 0.9787410500158746;
	    else if (leppt < 50.0) lepIdSF = 0.978189122919501;
	    else if (leppt < 60.0) lepIdSF = 0.9673568416097894;
	    else lepIdSF = 0.9766311856731202; 
	  }

	// Updated by Blake Burgstahler
	// 2016 Legacy BCDEF -- https://gitlab.cern.ch/cms-muonPOG/MuonReferenceEfficiencies/blob/master/EfficienciesStudies/2016_legacy_rereco/systematic/RunBCDEF_SF_ID.json
	// NUM_TightID_Den_genTracks ~ line 2570	
	// and 2016 Legacy GH -- https://gitlab.cern.ch/cms-muonPOG/MuonReferenceEfficiencies/blob/master/EfficienciesStudies/2016_legacy_rereco/systematic/RunGH_SF_ID.json#L2570
	// NUM_TightID_DEN_genTracks ~ line 2570

	if (leppt < 25)
	{
		if (lepeta < -2.3) {mu_BCDEF = 0.99292112983971637; mu_GH = 0.97339213009889913;}
		else if (lepeta < -2.2) {mu_BCDEF = 0.98772201639146417; mu_GH = 0.97461671208188305;}
		else if (lepeta < -2.1) {mu_BCDEF = 0.96526020885176012; mu_GH = 0.9619849274476705;}
		else if (lepeta < -2.0) {mu_BCDEF = 0.9900303892649952; mu_GH = 0.97149124906897466;}
		else if (lepeta < -1.7) {mu_BCDEF = 0.97893709485777503; mu_GH = 0.97616525215196848;}
		else if (lepeta < -1.6) {mu_BCDEF = 0.98834445623599498; mu_GH = 1.0063603975007103;}
		else if (lepeta < -1.5) {mu_BCDEF = 0.99845578876203922; mu_GH = 0.9984464523276988;}
		else if (lepeta < -1.4) {mu_BCDEF = 0.99247325825239929; mu_GH = 1.0132084820233951;}
		else if (lepeta < -1.2) {mu_BCDEF = 1.0048853912805875; mu_GH = 1.0024926975300286;}
		else if (lepeta < -0.8) {mu_BCDEF = 0.98934276851977587; mu_GH = 0.98339891327812257;}
		else if (lepeta < -0.5) {mu_BCDEF = 1.0133004952917493; mu_GH = 0.98990301438061823;}
		else if (lepeta < -0.3) {mu_BCDEF = 1.0072435847140979; mu_GH = 1.0112287803397224;}
		else if (lepeta < -0.2) {mu_BCDEF = 0.98454049239696939; mu_GH = 0.97235229992617755;}
		else if (lepeta <  0.0) {mu_BCDEF = 0.96776167972632399; mu_GH = 0.97687108917154053;}
		else if (lepeta <  0.2) {mu_BCDEF = 0.99331970040951589; mu_GH = 0.99941318246955324;}
		else if (lepeta <  0.3) {mu_BCDEF = 0.9450394908539369; mu_GH = 0.9773520605775291;}
		else if (lepeta <  0.5) {mu_BCDEF = 1.0087081340094111; mu_GH = 1.0024302051000797;}
		else if (lepeta <  0.8) {mu_BCDEF = 1.0011821354733665; mu_GH = 1.0014789133978552;}
		else if (lepeta <  1.2) {mu_BCDEF = 0.98693131199421769; mu_GH = 0.9838738877157881;}
		else if (lepeta <  1.4) {mu_BCDEF = 1.0025617408372454; mu_GH = 1.0044043983087432;}
		else if (lepeta <  1.5) {mu_BCDEF = 1.005706370433407; mu_GH = 1.0093019504389056;}
		else if (lepeta <  1.6) {mu_BCDEF = 0.99986455501950411; mu_GH = 1.0090670745217407;}
		else if (lepeta <  1.7) {mu_BCDEF = 0.99504801315147584; mu_GH = 1.0033721334989849;}
		else if (lepeta <  2.0) {mu_BCDEF = 0.9860611614733753; mu_GH = 0.9809895386054287;}
		else if (lepeta <  2.1) {mu_BCDEF = 0.98457585652352919; mu_GH = 0.97984011300971896;}
		else if (lepeta <  2.2) {mu_BCDEF = 0.97899678760119591; mu_GH = 0.97566898826813231;}
		else if (lepeta <  2.3) {mu_BCDEF = 0.99772488199067666; mu_GH = 0.98729150401824439;}
		else  {mu_BCDEF = 0.99955346105165988; mu_GH = 0.99929346670153385;}

	}
	if (leppt < 30)
	{
		if (lepeta < -2.3) {mu_BCDEF = 0.98625646375432063; mu_GH = 0.98292068765651575;}
		else if (lepeta < -2.2) {mu_BCDEF = 0.99008190949639785; mu_GH = 0.98953705500088152;}
		else if (lepeta < -2.1) {mu_BCDEF = 0.96551335383549508; mu_GH = 0.95830890245843603;}
		else if (lepeta < -2.0) {mu_BCDEF = 0.98303784370774727; mu_GH = 0.97864787547073506;}
		else if (lepeta < -1.7) {mu_BCDEF = 0.98378317736077803; mu_GH = 0.9807130087660233;}
		else if (lepeta < -1.6) {mu_BCDEF = 0.99167994105285728; mu_GH = 0.98549299018323377;}
		else if (lepeta < -1.5) {mu_BCDEF = 0.99352303172392697; mu_GH = 1.0002699414137737;}
		else if (lepeta < -1.4) {mu_BCDEF = 0.99123226820031429; mu_GH = 0.99641573543843842;}
		else if (lepeta < -1.2) {mu_BCDEF = 0.98830258727978482; mu_GH = 0.99614453237686507;}
		else if (lepeta < -0.8) {mu_BCDEF = 0.98158867357130219; mu_GH = 0.98621330353287628;}
		else if (lepeta < -0.5) {mu_BCDEF = 0.99809719427031629; mu_GH = 0.99671464130022713;}
		else if (lepeta < -0.3) {mu_BCDEF = 0.98962781653006426; mu_GH = 0.99279176053753337;}
		else if (lepeta < -0.2) {mu_BCDEF = 0.97884422751525701; mu_GH = 0.96534783821048797;}
		else if (lepeta <  0.0) {mu_BCDEF = 0.98850127318640812; mu_GH = 0.99221126613811395;}
		else if (lepeta <  0.2) {mu_BCDEF = 0.98446157697736503; mu_GH = 0.99743116554426425;}
		else if (lepeta <  0.3) {mu_BCDEF = 0.96513228464968515; mu_GH = 0.96958523049172429;}
		else if (lepeta <  0.5) {mu_BCDEF = 0.99533976834497428; mu_GH = 0.99692854017288468;}
		else if (lepeta <  0.8) {mu_BCDEF = 0.99557747946810315; mu_GH = 0.99378985199298142;}
		else if (lepeta <  1.2) {mu_BCDEF = 0.98038296004370218; mu_GH = 0.98235100337469727;}
		else if (lepeta <  1.4) {mu_BCDEF = 0.99954928234752849; mu_GH = 0.99917611800879724;}
		else if (lepeta <  1.5) {mu_BCDEF = 1.0005497651575073; mu_GH = 1.0086056459350083;}
		else if (lepeta <  1.6) {mu_BCDEF = 1.0009367687478941; mu_GH = 0.99229378486025699;}
		else if (lepeta <  1.7) {mu_BCDEF = 0.99768014135108396; mu_GH = 0.9965033246480961;}
		else if (lepeta <  2.0) {mu_BCDEF = 0.98465671814518563; mu_GH = 0.9850131997381657;}
		else if (lepeta <  2.1) {mu_BCDEF = 0.9829690564506528; mu_GH = 0.97924380702294789;}
		else if (lepeta <  2.2) {mu_BCDEF = 0.97284544606081735; mu_GH = 0.96926082952818382;}
		else if (lepeta <  2.3) {mu_BCDEF = 0.98949046118866424; mu_GH = 0.99547908543287222;}
		else  {mu_BCDEF = 0.96895024296047505; mu_GH = 0.9778601250332507;}
	}
	if (leppt < 40)
	{
		if (lepeta < -2.3) {mu_BCDEF = 0.98690415676091403; mu_GH = 0.97883969587681763;}
		else if (lepeta < -2.2) {mu_BCDEF = 0.98431854198019664; mu_GH = 0.98317184903504662;}
		else if (lepeta < -2.1) {mu_BCDEF = 0.95923430341132132; mu_GH = 0.95279691299754921;}
		else if (lepeta < -2.0) {mu_BCDEF = 0.98025469396847908; mu_GH = 0.97920473032255839;}
		else if (lepeta < -1.7) {mu_BCDEF = 0.98493670918856058; mu_GH = 0.98344623532718001;}
		else if (lepeta < -1.6) {mu_BCDEF = 0.99211199294732544; mu_GH = 0.99322878307759277;}
		else if (lepeta < -1.5) {mu_BCDEF = 0.99452826082543211; mu_GH = 0.99527701483624553;}
		else if (lepeta < -1.4) {mu_BCDEF = 0.99338961330217446; mu_GH = 0.99932136796640736;}
		else if (lepeta < -1.2) {mu_BCDEF = 0.99442967227025347; mu_GH = 0.99711060910828886;}
		else if (lepeta < -0.8) {mu_BCDEF = 0.9793690095388593; mu_GH = 0.9822439962681061;}
		else if (lepeta < -0.5) {mu_BCDEF = 0.9901123255352875; mu_GH = 0.99247437425390161;}
		else if (lepeta < -0.3) {mu_BCDEF = 0.99071454640551027; mu_GH = 0.99434248246993162;}
		else if (lepeta < -0.2) {mu_BCDEF = 0.97048201732336026; mu_GH = 0.96699382178716875;}
		else if (lepeta <  0.0) {mu_BCDEF = 0.99299683439629138; mu_GH = 0.99543203986255935;}
		else if (lepeta <  0.2) {mu_BCDEF = 0.98944489649235945; mu_GH = 0.99194105148567557;}
		else if (lepeta <  0.3) {mu_BCDEF = 0.95601023357613268; mu_GH = 0.96466191601360141;}
		else if (lepeta <  0.5) {mu_BCDEF = 0.98879288815444422; mu_GH = 0.99053997520001402;}
		else if (lepeta <  0.8) {mu_BCDEF = 0.99146688462890653; mu_GH = 0.99183329424706368;}
		else if (lepeta <  1.2) {mu_BCDEF = 0.97887602846853072; mu_GH = 0.98238090856032156;}
		else if (lepeta <  1.4) {mu_BCDEF = 0.99556687160412172; mu_GH = 1.0004353595664346;}
		else if (lepeta <  1.5) {mu_BCDEF = 0.99786217763505503; mu_GH = 1.003615328099192;}
		else if (lepeta <  1.6) {mu_BCDEF = 1.0005594471159178; mu_GH = 1.0050891570595673;}
		else if (lepeta <  1.7) {mu_BCDEF = 0.99605723205881669; mu_GH = 0.99717453031963876;}
		else if (lepeta <  2.0) {mu_BCDEF = 0.98669447262259602; mu_GH = 0.9867957381732696;}
		else if (lepeta <  2.1) {mu_BCDEF = 0.98647184692916645; mu_GH = 0.98209898585185817;}
		else if (lepeta <  2.2) {mu_BCDEF = 0.96301003305917776; mu_GH = 0.96164510169102735;}
		else if (lepeta <  2.3) {mu_BCDEF = 0.9899920784449795; mu_GH = 0.98375391143012259;}
		else  {mu_BCDEF = 0.97844699326059859; mu_GH = 0.9759203927413086;}
	}
	if (leppt < 50)
	{
		if (lepeta < -2.3) {mu_BCDEF = 0.98617002052872049; mu_GH = 0.97863405588203156;}
		else if (lepeta < -2.2) {mu_BCDEF = 0.99254357754076772; mu_GH = 0.98350972753312038;}
		else if (lepeta < -2.1) {mu_BCDEF = 0.96076908827313523; mu_GH = 0.95002609708088082;}
		else if (lepeta < -2.0) {mu_BCDEF = 0.98025563567587692; mu_GH = 0.97956028739263878;}
		else if (lepeta < -1.7) {mu_BCDEF = 0.98409506320892459; mu_GH = 0.98089681629562997;}
		else if (lepeta < -1.6) {mu_BCDEF = 0.99377120417985343; mu_GH = 0.99285709287609281;}
		else if (lepeta < -1.5) {mu_BCDEF = 0.99672926390757521; mu_GH = 1.0000806789775922;}
		else if (lepeta < -1.4) {mu_BCDEF = 0.99721832927800236; mu_GH = 1.0006062095528969;}
		else if (lepeta < -1.2) {mu_BCDEF = 0.99641665848487726; mu_GH = 0.99746407603381493;}
		else if (lepeta < -0.8) {mu_BCDEF = 0.97858694089341025; mu_GH = 0.98295726261870253;}
		else if (lepeta < -0.5) {mu_BCDEF = 0.99052105160093673; mu_GH = 0.99446083440152055;}
		else if (lepeta < -0.3) {mu_BCDEF = 0.99282792739917891; mu_GH = 0.99510246516504974;}
		else if (lepeta < -0.2) {mu_BCDEF = 0.96993678510843506; mu_GH = 0.96949373143029305;}
		else if (lepeta <  0.0) {mu_BCDEF = 0.99088821123577431; mu_GH = 0.9966426354720066;}
		else if (lepeta <  0.2) {mu_BCDEF = 0.99138079578664606; mu_GH = 0.99420126066462855;}
		else if (lepeta <  0.3) {mu_BCDEF = 0.95840143173201431; mu_GH = 0.96727749078190872;}
		else if (lepeta <  0.5) {mu_BCDEF = 0.98787959532763581; mu_GH = 0.99221648855436728;}
		else if (lepeta <  0.8) {mu_BCDEF = 0.99087793710662653; mu_GH = 0.993038846925826;}
		else if (lepeta <  1.2) {mu_BCDEF = 0.9785120474753094; mu_GH = 0.98210991502747658;}
		else if (lepeta <  1.4) {mu_BCDEF = 0.99850009614465396; mu_GH = 1.0012607992291958;}
		else if (lepeta <  1.5) {mu_BCDEF = 0.99995371057360771; mu_GH = 1.0025251953501411;}
		else if (lepeta <  1.6) {mu_BCDEF = 1.0009601125988856; mu_GH = 1.0045976283226679;}
		else if (lepeta <  1.7) {mu_BCDEF = 0.99932361834420469; mu_GH = 1.0006407269340183;}
		else if (lepeta <  2.0) {mu_BCDEF = 0.9870978476573502; mu_GH = 0.98665081667288412;}
		else if (lepeta <  2.1) {mu_BCDEF = 0.98752584233292917; mu_GH = 0.98336157845093297;}
		else if (lepeta <  2.2) {mu_BCDEF = 0.97078858684796354; mu_GH = 0.96305211769189214;}
		else if (lepeta <  2.3) {mu_BCDEF = 0.98331684551102927; mu_GH = 0.9881283609907614;}
		else  {mu_BCDEF = 0.98966831619286377; mu_GH = 0.98952365119379826;}
	}
	if (leppt < 60)
	{
		if (lepeta < -2.3) {mu_BCDEF = 0.9734886584950061; mu_GH = 0.97833955803512307;}
		else if (lepeta < -2.2) {mu_BCDEF = 0.97902898432498431; mu_GH = 0.96901684616388861;}
		else if (lepeta < -2.1) {mu_BCDEF = 0.95743065381097336; mu_GH = 0.9518258446793727;}
		else if (lepeta < -2.0) {mu_BCDEF = 0.98346414028063822; mu_GH = 0.97943271615738159;}
		else if (lepeta < -1.7) {mu_BCDEF = 0.98309586900592838; mu_GH = 0.97980872496969262;}
		else if (lepeta < -1.6) {mu_BCDEF = 0.99284997119254181; mu_GH = 0.99070404919224897;}
		else if (lepeta < -1.5) {mu_BCDEF = 0.99164484150212795; mu_GH = 0.99316102265487438;}
		else if (lepeta < -1.4) {mu_BCDEF = 0.99383701270378855; mu_GH = 0.99712464423491465;}
		else if (lepeta < -1.2) {mu_BCDEF = 0.98995092287147668; mu_GH = 0.99325072441778139;}
		else if (lepeta < -0.8) {mu_BCDEF = 0.97330646323864289; mu_GH = 0.97786756883076564;}
		else if (lepeta < -0.5) {mu_BCDEF = 0.98785060502729805; mu_GH = 0.99031010248346785;}
		else if (lepeta < -0.3) {mu_BCDEF = 0.99066244769695655; mu_GH = 0.99016556104846909;}
		else if (lepeta < -0.2) {mu_BCDEF = 0.9650449166883639; mu_GH = 0.97260164403966232;}
		else if (lepeta <  0.0) {mu_BCDEF = 0.98684690441780665; mu_GH = 0.99107983559520685;}
		else if (lepeta <  0.2) {mu_BCDEF = 0.98595875873717387; mu_GH = 0.99214382359212716;}
		else if (lepeta <  0.3) {mu_BCDEF = 0.95493197161735899; mu_GH = 0.97094901721362192;}
		else if (lepeta <  0.5) {mu_BCDEF = 0.98778136508035852; mu_GH = 0.99058263816452086;}
		else if (lepeta <  0.8) {mu_BCDEF = 0.98287501240922814; mu_GH = 0.98781552029743414;}
		else if (lepeta <  1.2) {mu_BCDEF = 0.97764031022661535; mu_GH = 0.97310011058129087;}
		else if (lepeta <  1.4) {mu_BCDEF = 0.98764309521656857; mu_GH = 0.98565099382144439;}
		else if (lepeta <  1.5) {mu_BCDEF = 0.98421547852416025; mu_GH = 0.98523386811473668;}
		else if (lepeta <  1.6) {mu_BCDEF = 0.99469841465735154; mu_GH = 0.99189466472831445;}
		else if (lepeta <  1.7) {mu_BCDEF = 0.99407822661546996; mu_GH = 0.97970464311456584;}
		else if (lepeta <  2.0) {mu_BCDEF = 0.98511587647233989; mu_GH = 0.97897622723974531;}
		else if (lepeta <  2.1) {mu_BCDEF = 0.9862527541010172; mu_GH = 0.97194700291500136;}
		else if (lepeta <  2.2) {mu_BCDEF = 0.95831202392828052; mu_GH = 0.95747764082446618;}
		else if (lepeta <  2.3) {mu_BCDEF = 0.97922804334004065; mu_GH = 0.97813587990429507;}
		else  {mu_BCDEF = 0.99318781884250906; mu_GH = 0.9729891453159244;}
	}
	if (leppt < 120)
	{
		if (lepeta < -2.3) {mu_BCDEF = 0.97674364817526582; mu_GH = 0.96900914461648979;}
		else if (lepeta < -2.2) {mu_BCDEF = 0.97787813519378253; mu_GH = 0.9960027273930151;}
		else if (lepeta < -2.1) {mu_BCDEF = 0.95511049723682362; mu_GH = 0.93443505878885458;}
		else if (lepeta < -2.0) {mu_BCDEF = 0.99892986858034416; mu_GH = 0.97037894578983597;}
		else if (lepeta < -1.7) {mu_BCDEF = 0.98320011762381243; mu_GH = 0.9744482564708502;}
		else if (lepeta < -1.6) {mu_BCDEF = 0.98497814759878854; mu_GH = 0.98056746626297053;}
		else if (lepeta < -1.5) {mu_BCDEF = 1.0019042077293925; mu_GH = 1.0057697895090931;}
		else if (lepeta < -1.4) {mu_BCDEF = 0.99647744640662994; mu_GH = 0.98913555236688744;}
		else if (lepeta < -1.2) {mu_BCDEF = 0.99556988987554573; mu_GH = 0.99291871392998088;}
		else if (lepeta < -0.8) {mu_BCDEF = 0.97937397360236056; mu_GH = 0.98442437716201514;}
		else if (lepeta < -0.5) {mu_BCDEF = 0.99992215473273294; mu_GH = 0.99312123872539104;}
		else if (lepeta < -0.3) {mu_BCDEF = 1.0070290015197862; mu_GH = 1.0052120507661046;}
		else if (lepeta < -0.2) {mu_BCDEF = 0.96682442700516313; mu_GH = 0.97017838184624161;}
		else if (lepeta <  0.0) {mu_BCDEF = 0.99223417250980794; mu_GH = 0.99489492775958055;}
		else if (lepeta <  0.2) {mu_BCDEF = 0.9912907830615566; mu_GH = 0.99514414023292974;}
		else if (lepeta <  0.3) {mu_BCDEF = 0.97343256539318468; mu_GH = 0.98037777070478349;}
		else if (lepeta <  0.5) {mu_BCDEF = 1.0014858928833419; mu_GH = 0.99767539669347705;}
		else if (lepeta <  0.8) {mu_BCDEF = 0.98927264098029188; mu_GH = 0.98729965711486656;}
		else if (lepeta <  1.2) {mu_BCDEF = 0.97545587023597147; mu_GH = 0.98043974203251294;}
		else if (lepeta <  1.4) {mu_BCDEF = 0.98955470582272687; mu_GH = 1.0010360703429044;}
		else if (lepeta <  1.5) {mu_BCDEF = 1.0062606037077773; mu_GH = 1.0023162742754319;}
		else if (lepeta <  1.6) {mu_BCDEF = 1.0083891620272829; mu_GH = 0.99342718111987782;}
		else if (lepeta <  1.7) {mu_BCDEF = 0.99101023524339393; mu_GH = 0.98185295376297643;}
		else if (lepeta <  2.0) {mu_BCDEF = 0.9792741661544031; mu_GH = 0.98022170182495449;}
		else if (lepeta <  2.1) {mu_BCDEF = 0.99746541815341172; mu_GH = 0.98753232440668215;}
		else if (lepeta <  2.2) {mu_BCDEF = 0.95764436682936227; mu_GH = 0.95572838866344212;}
		else if (lepeta <  2.3) {mu_BCDEF = 0.98647184459464032; mu_GH = 0.98924969046030575;}
		else  {mu_BCDEF = 0.99772119443737017; mu_GH = 1.0006767314018075;}
	}
	lepIdSF = (20.236*mu_BCDEF + 16.578*mu_GH)/36.814;
       

	// Muon tracking SF -- https://twiki.cern.ch/twiki/bin/viewauth/CMS/MuonWorkInProgressAndPagResults#Results_on_the_full_2016_data, Feb 16 version for full data
	  int ebin = -1;
	  if(lepeta < -2.1) ebin = 0;
	  else if(lepeta < -1.6) ebin = 1;
	  else if(lepeta < -1.2) ebin = 2;
	  else if(lepeta < -0.9) ebin = 3;
	  else if(lepeta < -0.6) ebin = 4;
	  else if(lepeta < -0.3) ebin = 5;
	  else if(lepeta < -0.2) ebin = 6;
	  else if(lepeta <  0.2) ebin = 7;
	  else if(lepeta <  0.3) ebin = 8;
	  else if(lepeta <  0.6) ebin = 9;
	  else if(lepeta <  0.9) ebin = 10;
	  else if(lepeta <  1.2) ebin = 11;
	  else if(lepeta <  1.6) ebin = 12;
	  else if(lepeta <  2.1) ebin = 13;
	  else if(lepeta <  2.4) ebin = 14;

	  MuTrkSF = tracksf[ebin];

	  float triggerSFB = 1.0;
          float triggerSFCDEF = 1.0;
	  float triggerSFBunc = 0.0;
	  float triggerSFCDEFunc = 0.0;
	  if (fabs(lepeta) < 0.90){
	    if (leppt < 50.0){
	      triggerSFB = 1.0; triggerSFBunc = 0.0;
	      triggerSFCDEF = 1.034; triggerSFCDEFunc = 0.014;
	    }
	    else if (leppt < 60.0){
	      triggerSFB = 0.920; triggerSFBunc = 0.058;
	      triggerSFCDEF = 0.984;  triggerSFCDEFunc = 0.017;
	    }
	    else if (leppt < 70.0){
	      triggerSFB = 0.995; triggerSFBunc = 0.050;
	      triggerSFCDEF = 0.993;  triggerSFCDEFunc = 0.017;
	    }
	    else if (leppt < 100){
	      triggerSFB = 0.936; triggerSFBunc = 0.040;
	      triggerSFCDEF = 1.006;  triggerSFCDEFunc = 0.01;
	    }
	    else if (leppt < 200){
	      triggerSFB = 0.981; triggerSFBunc = 0.029;
	      triggerSFCDEF = 0.960;  triggerSFCDEFunc = 0.012;
	    }
	    else{
	      triggerSFB = 0.981; triggerSFBunc = 0.063;
	      triggerSFCDEF = 0.963;  triggerSFCDEFunc = 0.027;
	    }
	  }
	  else if (fabs(lepeta) < 1.20){
	    if (leppt < 50.0){
	      triggerSFB = 1.0; triggerSFBunc = 0.0;
	      triggerSFCDEF = 1.006; triggerSFCDEFunc = 0.028;
	    }
	    else if (leppt < 60.0){
	      triggerSFB = 0.944; triggerSFBunc = 0.127;
	      triggerSFCDEF = 1.045;  triggerSFCDEFunc = 0.022;
	    }
	    else if (leppt < 70.0){
	      triggerSFB = 1.080; triggerSFBunc = 0.011;
	      triggerSFCDEF = 0.987;  triggerSFCDEFunc = 0.037;
	    }
	    else if (leppt < 100){
	      triggerSFB = 0.992; triggerSFBunc = 0.049;
	      triggerSFCDEF = 0.934;  triggerSFCDEFunc = 0.026;
	    }
	    else if (leppt < 200){
	      triggerSFB = 0.993; triggerSFBunc = 0.044;
	      triggerSFCDEF = 0.958;  triggerSFCDEFunc = 0.024;
	    }
	    else{
	      triggerSFB = 1.054; triggerSFBunc = 0.010;
	      triggerSFCDEF = 1.018;  triggerSFCDEFunc = 0.036;
	    }
	  }
	  else if (fabs(lepeta) < 2.10){
	    if (leppt < 50.0){
	      triggerSFB = 1.0; triggerSFBunc = 0.0;
	      triggerSFCDEF = 1.080; triggerSFCDEFunc = 0.027;
	    }
	    else if (leppt < 60.0){
	      triggerSFB = 0.815; triggerSFBunc = 0.112;
	      triggerSFCDEF = 1.063;  triggerSFCDEFunc = 0.021;
	    }
	    else if (leppt < 70.0){
	      triggerSFB = 1.045; triggerSFBunc = 0.057;
	      triggerSFCDEF = 1.038;  triggerSFCDEFunc = 0.027;
	    }
	    else if (leppt < 100){
	      triggerSFB = 0.944; triggerSFBunc = 0.054;
	      triggerSFCDEF = 1.024;  triggerSFCDEFunc = 0.016;
	    }
	    else if (leppt < 200){
	      triggerSFB = 0.881; triggerSFBunc = 0.084;
	      triggerSFCDEF = 0.974;  triggerSFCDEFunc = 0.021;
	    }
	    else{
	      triggerSFB = 1.0; triggerSFBunc = 0.05;
	      triggerSFCDEF = 1.050;  triggerSFCDEFunc = 0.010;
	    }
	  }
	  else{
	    if (leppt < 50.0){
	      triggerSFB = 1.0; triggerSFBunc = 0.0;
	      triggerSFCDEF = 1.166; triggerSFCDEFunc = 0.033;
	    }
	    else if (leppt < 60.0){
	      triggerSFB = 1.126; triggerSFBunc = 0.029;
	      triggerSFCDEF = 1.126;  triggerSFCDEFunc = 0.029;
	    }
	    else if (leppt < 70.0){
	      triggerSFB = 0.731; triggerSFBunc = 0.299;
	      triggerSFCDEF = 0.959;  triggerSFCDEFunc = 0.093;
	    }
	    else if (leppt < 100){
	      triggerSFB = 1.089; triggerSFBunc = 0.017;
	      triggerSFCDEF = 1.045;  triggerSFCDEFunc = 0.046;
	    }
	    else if (leppt < 200){
	      triggerSFB = 1.067; triggerSFBunc = 0.015;
	      triggerSFCDEF = 0.942;  triggerSFCDEFunc = 0.084;
	    }
	    else{
	      triggerSFB = 1.00; triggerSFBunc = 0.050;
	      triggerSFCDEF = 1.006;  triggerSFCDEFunc = 0.01;
	    }
	  }
	  triggerSF = (4.823*triggerSFB+36.734*triggerSFCDEF)/41.557;
	  triggerSFUncert = sqrt( pow(4.823*triggerSFBunc/41.557,2) + pow(36.734*triggerSFCDEFunc/41.557,2) );
	 
	}
	DataPastTrigger = 1;
        // Trigger SF Muon 
      }
      
      else{ //Data triggers check
	if(isElectron){
	  std::string string_350 = "Ele15_IsoVVVL_PFHT350";
	  std::string string_400 = "Ele15_IsoVVVL_PFHT400";
	  std::string string_a = "Ele15_IsoVVVL_PFHT450";
	  std::string string_c = "Ele50_IsoVVVL_PFHT450";
	  std::string string_d = "Ele15_IsoVVVL_PFHT600";
	  std::string string_ORa = "Ele35_WPTight_Gsf";
	  std::string string_ORb = "Ele38_WPTight_Gsf";
	  for(unsigned int itrig=0; itrig < vsSelTriggersEl_MultiLepCalc->size(); itrig++){
	    if(vsSelTriggersEl_MultiLepCalc->at(itrig).find(string_a) != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersEl_MultiLepCalc->at(itrig).find(string_c) != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersEl_MultiLepCalc->at(itrig).find(string_d) != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersEl_MultiLepCalc->at(itrig).find(string_350) != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersEl_MultiLepCalc->at(itrig).find(string_400) != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersEl_MultiLepCalc->at(itrig).find(string_ORa) != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersEl_MultiLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	  }
	}


	//
	if(isMuon){
	  std::string string_350 = "Mu15_IsoVVVL_PFHT350";
	  std::string string_400 = "Mu15_IsoVVVL_PFHT400";
	  std::string string_a = "Mu15_IsoVVVL_PFHT450";
	  std::string string_d = "Mu50_IsoVVVL_PFHT450";
	  std::string string_e = "Mu15_IsoVVVL_PFHT600";
	  std::string string_ORb = "Mu50";
	  for(unsigned int itrig=0; itrig < vsSelTriggersMu_MultiLepCalc->size(); itrig++){
	      if(vsSelTriggersMu_MultiLepCalc->at(itrig).find(string_a) != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	      if(vsSelTriggersMu_MultiLepCalc->at(itrig).find(string_d) != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	      if(vsSelTriggersMu_MultiLepCalc->at(itrig).find(string_e) != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	      if(vsSelTriggersMu_MultiLepCalc->at(itrig).find(string_350) != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	      if(vsSelTriggersMu_MultiLepCalc->at(itrig).find(string_400) != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	      if(vsSelTriggersMu_MultiLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	  }
	}
	MCPastTrigger = 1;
      }
      
      if(isMC && MCPastTrigger) npass_trigger+=1;
      if(!isMC && DataPastTrigger) npass_trigger+=1;

      // ----------------------------------------------------------------------------
      // Generator-level HT correction
      // ----------------------------------------------------------------------------      

      HTSF_Pol = 1;
      HTSF_PolUp = 1;
      HTSF_PolDn = 1;

      if(isMadgraphBkg){
	// Piece-wise splice with a flat line. Uncertainty from upper/lower error bar fits
	HTSF_Pol = poly2->Eval(HTfromHEPUEP_MultiLepCalc);
	HTSF_PolUp = poly2U->Eval(HTfromHEPUEP_MultiLepCalc);
	HTSF_PolDn = poly2D->Eval(HTfromHEPUEP_MultiLepCalc);
      }

      // ----------------------------------------------------------------------------
      // Loop over AK4 jets for calculations and pt ordering pair
      // ----------------------------------------------------------------------------

      NJets_JetSubCalc = 0;
      AK4HT = 0;
      int nskipped = 0;
      float deltaR1 = -1; float deltaR2 = -1;
      float ptRel1 = -1; float ptRel2 = -1;
      int ind1 = -1; int ind2 = -1;
      vector<pair<double,int>> jetptindpair;
      std::vector<int> theJetBTagDeepCSV;

      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc->size(); ijet++){

	// ----------------------------------------------------------------------------
	// Apply DeepCSV scale factors -- DeepJet is the default from LJMet
	// ----------------------------------------------------------------------------

	// Set the initial tagged/untagged state
	bool istagged = AK4JetDeepCSVb_MultiLepCalc->at(ijet) + AK4JetDeepCSVbb_MultiLepCalc->at(ijet) > 0.6321;

	double ijetPt = theJetPt_JetSubCalc->at(ijet);
	double ijetEta= theJetEta_JetSubCalc->at(ijet);
	double ijetPhi= theJetPhi_JetSubCalc->at(ijet);
   
	float multiplier = 1;
	if(ijetPt>1000) multiplier = 2;

	if(theJetHFlav_JetSubCalc->at(ijet) == 5){//b-quarks
	  double heavySF   = GetBtagSF2016Medium_comb(central, ijetPt, ijetEta);
	  if(isBUp) heavySF += GetBtagSF2016Medium_comb(uncert, ijetPt, ijetEta);
	  else if(isBDn) heavySF -= GetBtagSF2016Medium_comb(uncert, ijetPt, ijetEta);
	  double heavyEff  = GetBtagEfficiency(ijetPt);

	  theJetBTagDeepCSV.push_back(applySF(istagged,heavySF,heavyEff,ijetPhi));
  
	}else if(theJetHFlav_JetSubCalc->at(ijet) == 4){//c-quarks
	  double heavySF   = GetCtagSF2016Medium_comb(central, ijetPt, ijetEta);
	  if(isBUp) heavySF += GetCtagSF2016Medium_comb(uncert, ijetPt, ijetEta);
	  else if(isBDn) heavySF -= GetCtagSF2016Medium_comb(uncert, ijetPt, ijetEta);
	  double heavyEff  = GetCtagEfficiency(ijetPt);

	  theJetBTagDeepCSV.push_back(applySF(istagged,heavySF,heavyEff,ijetPhi));

	}else{//udsg-quarks
	  double lightSF   = GetLFSF2016Medium(central, ijetPt, ijetEta);
	  if(isLUp) lightSF += GetLFSF2016Medium(uncert, ijetPt, ijetEta);
	  else if(isLUp) lightSF -= GetLFSF2016Medium(uncert, ijetPt, ijetEta);
	  double lightEff  = GetMistagRate(ijetPt);
  
	  theJetBTagDeepCSV.push_back(applySF(istagged,lightSF,lightEff,ijetPhi));
	}

	// ----------------------------------------------------------------------------
	// Basic cuts   NEW NEW NEW NEW 2D cut right here
	// ----------------------------------------------------------------------------

	if(theJetPt_JetSubCalc->at(ijet) < jetPtCut || fabs(theJetEta_JetSubCalc->at(ijet)) > jetEtaCut) continue;
	
	jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc->at(ijet),theJetEta_JetSubCalc->at(ijet),theJetPhi_JetSubCalc->at(ijet),theJetEnergy_JetSubCalc->at(ijet));
	float deltaR = lepton_lv.DeltaR(jet_lv);
	float ptRel = lepton_lv.P()*(jet_lv.Vect().Cross(lepton_lv.Vect()).Mag()/jet_lv.P()/lepton_lv.P());
	if(deltaR < 0.4 && ptRel < 20){
	  nskipped += 1;
	  if(deltaR1 < 0){
	    deltaR1 = deltaR;
	    ptRel1 = ptRel;
	    ind1 = ijet;
	  }else{
	    if(deltaR2 < 0){
	      deltaR2 = deltaR;
	      ptRel2 = ptRel;
	      ind2 = ijet;
	    }else std::cout << "3rd close jet!" << std::endl;
	  }
	  continue; // not ONLY checking the closest jet, but should be impossible for 2 to be that close...
	}

	// ----------------------------------------------------------------------------
	// Counts and pt ordering pair
	// ----------------------------------------------------------------------------

	jetptindpair.push_back(std::make_pair(theJetPt_JetSubCalc->at(ijet),ijet));
	NJets_JetSubCalc+=1;
	AK4HT+=theJetPt_JetSubCalc->at(ijet);
      }

      if(nskipped > 1){
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "Weird thing! " << nskipped << " AK4s had DR < 0.4 && PtRel < 20!" << std::endl;
	std::cout << "dr1 = " << deltaR1 << ", dr2 = " << deltaR2 << std::endl;
	std::cout << "pt1 = " << ptRel1 << ", pt2 = " << ptRel2 << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
      }
	
      // ----------------------------------------------------------------------------
      // Loop over AK8 jets for calculations and pt ordering pair
      // ----------------------------------------------------------------------------

      NJetsAK8_JetSubCalc = 0;
      vector<pair<double,int>> jetak8ptindpair;      
      nskipped = 0;      
      deltaR1 = -1; deltaR2 = -1;
      ptRel1 = -1; ptRel2 = -1;
      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc->size(); ijet++){

        // ----------------------------------------------------------------------------                                  
        // Basic cuts    NEW NEW NEW NEW NEW 2D cut right here
        // ----------------------------------------------------------------------------                                  
	
        if(fabs(theJetAK8Eta_JetSubCalc->at(ijet)) > ak8EtaCut) continue;
        if(theJetAK8Pt_JetSubCalc->at(ijet) < ak8PtCut) continue;
        if(theJetAK8NjettinessTau1_JetSubCalc->at(ijet)==0) continue;
        if(theJetAK8NjettinessTau2_JetSubCalc->at(ijet)==0) continue;
	
	ak8_lv.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc->at(ijet),theJetAK8Eta_JetSubCalc->at(ijet),theJetAK8Phi_JetSubCalc->at(ijet),theJetAK8Energy_JetSubCalc->at(ijet));
	float deltaR = lepton_lv.DeltaR(ak8_lv);
	float ptRel = lepton_lv.P()*(ak8_lv.Vect().Cross(lepton_lv.Vect()).Mag()/ak8_lv.P()/lepton_lv.P());
	if(deltaR < 0.8 && ptRel < 20){
	  nskipped += 1;
	  if(deltaR1 < 0){
	    deltaR1 = deltaR;
	    ptRel1 = ptRel;
	  }else{
	    if(deltaR2 < 0){
	      deltaR2 = deltaR;
	      ptRel2 = ptRel;
	    }else std::cout << "3rd close jet!" << std::endl;
	  }
	  continue;   // not ONLY checking the closest jet, but should be impossible for 2 to be that close...
	}

        // ----------------------------------------------------------------------------                                  
        // Counters and pt ordering pair                                                                                  
        // ----------------------------------------------------------------------------                                  

	n_jetstotal++;	
        NJetsAK8_JetSubCalc += 1;
        jetak8ptindpair.push_back(std::make_pair(theJetAK8Pt_JetSubCalc->at(ijet),ijet));
	
        // ----------------------------------------------------------------------------                                  
        // Combine DeepAK8 C and B results
        // ----------------------------------------------------------------------------                                  

	if(dnn_largest_DeepAK8Calc->at(ijet) == 6) dnn_largest_DeepAK8Calc->at(ijet) = 5;

      }

      if(nskipped > 1){
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "Weird thing! " << nskipped << " AK8s had DR < 0.8 && PtRel < 20!" << std::endl;
	std::cout << "dr1 = " << deltaR1 << ", dr2 = " << deltaR2 << std::endl;
	std::cout << "pt1 = " << ptRel1 << ", pt2 = " << ptRel2 << std::endl; 
	std::cout << "------------------------------------------------------------" << std::endl;
     }

      // ----------------------------------------------------------------------------
      // Apply kinematic cuts
      // ----------------------------------------------------------------------------
	                
      int isPastHTCut = 0;
      if(AK4HT >= htCut){npass_ht+=1;isPastHTCut=1;}

      int isPastNAK8JetsCut = 0;
      if(NJetsAK8_JetSubCalc >= nAK8jetsCut){npass_nAK8jets+=1;isPastNAK8JetsCut=1;}
      
      int isPastMETcut = 0;
      if(corr_met_MultiLepCalc > metCut){npass_met+=1;isPastMETcut=1;}

      int isPastLepPtCut = 0;
      if(leppt > lepPtCut){npass_lepPt+=1;isPastLepPtCut=1;}
      
      int isPastElEtaCut = 0;
      int isPastMuEtaCut = 0;
      if(isElectron && fabs(lepeta) < elEtaCut){npass_ElEta+=1;isPastElEtaCut=1;}
      if(isMuon && fabs(lepeta) < muEtaCut){npass_MuEta+=1;isPastMuEtaCut=1;}
      if(isElectron){Nelectrons+=1;}
      if(isMuon){Nmuons+=1;}
      
      AK4HTpMETpLepPt = 0;
      AK4HTpMETpLepPt = AK4HT + corr_met_MultiLepCalc + leppt;


      // ----------------------------------------------------------------------------
      // Skip failing events
      // ----------------------------------------------------------------------------
            
      if(!(isPastMETcut && isPastHTCut && isPastNAK8JetsCut && isPastLepPtCut && (isPastElEtaCut || isPastMuEtaCut))) continue;
      npass_all+=1;

      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /////////////// ONLY ON SELECTED EVENTS ////////////////////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////      

      if(isSig && inTreeName.EqualTo("ljmet")){
	if(confusionTruth < 6.0){
	  TTconfusionD->Fill(0.5,confusionTruth);
	  TTconfusionD->Fill(1.5,confusionTruth);
	  TTconfusionD->Fill(2.5,confusionTruth);
	  TTconfusionD->Fill(3.5,confusionTruth);
	  TTconfusionD->Fill(4.5,confusionTruth);
	  TTconfusionD->Fill(5.5,confusionTruth);
	  TTconfusionD->Fill(6.5,confusionTruth);
	  TTconfusionD->Fill(7.5,confusionTruth);
	  TTconfusionD->Fill(8.5,confusionTruth);
	  TTconfusionD->Fill(9.5,confusionTruth);
	}else{
	  BBconfusionD->Fill(0.5,confusionTruth-6.0);
	  BBconfusionD->Fill(1.5,confusionTruth-6.0);
	  BBconfusionD->Fill(2.5,confusionTruth-6.0);
	  BBconfusionD->Fill(3.5,confusionTruth-6.0);
	  BBconfusionD->Fill(4.5,confusionTruth-6.0);
	  BBconfusionD->Fill(5.5,confusionTruth-6.0);
	  BBconfusionD->Fill(6.5,confusionTruth-6.0);
	}
      }
      
      // ----------------------------------------------------------------------------
      // Combine lepton variables into one set
      // ----------------------------------------------------------------------------

      if(isElectron){
	leptonPt_MultiLepCalc = leppt;
	leptonEta_MultiLepCalc = lepeta;
	leptonPhi_MultiLepCalc = elPhi_MultiLepCalc->at(0);
	leptonEnergy_MultiLepCalc = elEnergy_MultiLepCalc->at(0);
	leptonMiniIso_MultiLepCalc = elMiniIso_MultiLepCalc->at(0);
	leptonMVAValue_MultiLepCalc = -99.9; //elMVAValue_MultiLepCalc->at(0);
      }
      if(isMuon){
	leptonPt_MultiLepCalc = leppt;
	leptonEta_MultiLepCalc = lepeta;
	leptonPhi_MultiLepCalc = muPhi_MultiLepCalc->at(0);
	leptonEnergy_MultiLepCalc = muEnergy_MultiLepCalc->at(0);
	leptonMiniIso_MultiLepCalc = muMiniIso_MultiLepCalc->at(0);
	leptonMVAValue_MultiLepCalc = -99.9;
      }

      // ----------------------------------------------------------------------------
      // Apply pt ordering to AK4 vectors
      // ----------------------------------------------------------------------------

      std::sort(jetptindpair.begin(), jetptindpair.end(), comparepair);
      theJetPt_JetSubCalc_PtOrdered.clear();
      theJetEta_JetSubCalc_PtOrdered.clear();
      theJetPhi_JetSubCalc_PtOrdered.clear();
      theJetEnergy_JetSubCalc_PtOrdered.clear();
      AK4JetDeepCSVb_MultiLepCalc_PtOrdered.clear();
      AK4JetDeepCSVbb_MultiLepCalc_PtOrdered.clear();
      AK4JetDeepFlavb_MultiLepCalc_PtOrdered.clear();
      AK4JetDeepFlavbb_MultiLepCalc_PtOrdered.clear();
      AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered.clear();
      theJetHFlav_JetSubCalc_PtOrdered.clear();
      theJetPFlav_JetSubCalc_PtOrdered.clear();
      theJetBTagDeepCSV_JetSubCalc_PtOrdered.clear();
      theJetBTag_JetSubCalc_PtOrdered.clear();
      theJetBTag_bSFup_JetSubCalc_PtOrdered.clear();
      theJetBTag_bSFdn_JetSubCalc_PtOrdered.clear();
      theJetBTag_lSFup_JetSubCalc_PtOrdered.clear();
      theJetBTag_lSFdn_JetSubCalc_PtOrdered.clear();
      for(unsigned int ijet=0; ijet < jetptindpair.size(); ijet++){
      	theJetPt_JetSubCalc_PtOrdered.push_back(theJetPt_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetEta_JetSubCalc_PtOrdered.push_back(theJetEta_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetPhi_JetSubCalc_PtOrdered.push_back(theJetPhi_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetEnergy_JetSubCalc_PtOrdered.push_back(theJetEnergy_JetSubCalc->at(jetptindpair[ijet].second));
      	AK4JetDeepCSVb_MultiLepCalc_PtOrdered.push_back(AK4JetDeepCSVb_MultiLepCalc->at(jetptindpair[ijet].second));
	AK4JetDeepCSVbb_MultiLepCalc_PtOrdered.push_back(AK4JetDeepCSVbb_MultiLepCalc->at(jetptindpair[ijet].second));
      	AK4JetDeepFlavb_MultiLepCalc_PtOrdered.push_back(AK4JetDeepFlavb_MultiLepCalc->at(jetptindpair[ijet].second));
	AK4JetDeepFlavbb_MultiLepCalc_PtOrdered.push_back(AK4JetDeepFlavbb_MultiLepCalc->at(jetptindpair[ijet].second));
	AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered.push_back(AK4JetDeepFlavlepb_MultiLepCalc->at(jetptindpair[ijet].second));
      	theJetHFlav_JetSubCalc_PtOrdered.push_back(theJetHFlav_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetPFlav_JetSubCalc_PtOrdered.push_back(theJetPFlav_JetSubCalc->at(jetptindpair[ijet].second));
	theJetBTagDeepCSV_JetSubCalc_PtOrdered.push_back(theJetBTagDeepCSV.at(jetptindpair[ijet].second));
	theJetBTag_JetSubCalc_PtOrdered.push_back(theJetBTag_JetSubCalc->at(jetptindpair[ijet].second));
	theJetBTag_bSFup_JetSubCalc_PtOrdered.push_back(theJetBTag_bSFup_JetSubCalc->at(jetptindpair[ijet].second));
	theJetBTag_bSFdn_JetSubCalc_PtOrdered.push_back(theJetBTag_bSFdn_JetSubCalc->at(jetptindpair[ijet].second));
	theJetBTag_lSFup_JetSubCalc_PtOrdered.push_back(theJetBTag_lSFup_JetSubCalc->at(jetptindpair[ijet].second));
	theJetBTag_lSFdn_JetSubCalc_PtOrdered.push_back(theJetBTag_lSFdn_JetSubCalc->at(jetptindpair[ijet].second));
      }

      // ----------------------------------------------------------------------------
      // AK4 Jet - lepton associations
      // ----------------------------------------------------------------------------
         
      int ind_MinMlb = -1;
      int ind_MinMlj = -1;
      BJetLeadPt = -99;
      minMleppBjet = 1e8;
      minMleppJet = 1e8;      
      minDPhi_MetJet = 1e8;
      minDR_lepJet = 1e8;
      ptRel_lepJet = -99;
      deltaR_lepJets.clear();
      deltaR_lepBJets.clear();
      deltaR_lepMinMlb = 1e8;
      deltaR_lepMinMlj = 1e8;
      NJetsDeepCSV_JetSubCalc = 0;
      NJetsDeepFlav_JetSubCalc = 0;
      NJetsDeepCSVwithSF_JetSubCalc = 0;
      NJetsDeepFlavwithSF_JetSubCalc = 0;
      TLorentzVector nu;
      nu.SetPtEtaPhiE(corr_met_MultiLepCalc,0,corr_met_phi_MultiLepCalc,corr_met_MultiLepCalc);

      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc_PtOrdered.size(); ijet++){
        jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(ijet),theJetEta_JetSubCalc_PtOrdered.at(ijet),theJetPhi_JetSubCalc_PtOrdered.at(ijet),theJetEnergy_JetSubCalc_PtOrdered.at(ijet));
	if((lepton_lv + jet_lv).M() < minMleppJet) {
	  minMleppJet = fabs((lepton_lv + jet_lv).M());
	  deltaR_lepMinMlj = jet_lv.DeltaR(lepton_lv);
	  ind_MinMlj = ijet;
	}

	deltaR_lepJets.push_back(lepton_lv.DeltaR(jet_lv));

	// 2016 values for the Medium WPs
   	if(AK4JetDeepCSVb_MultiLepCalc_PtOrdered.at(ijet) + AK4JetDeepCSVbb_MultiLepCalc_PtOrdered.at(ijet) > 0.6321){
          NJetsDeepCSV_JetSubCalc += 1;
        }
	if(AK4JetDeepFlavb_MultiLepCalc_PtOrdered.at(ijet) + AK4JetDeepFlavbb_MultiLepCalc_PtOrdered.at(ijet) +
	   AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered.at(ijet) > 0.3093) NJetsDeepFlav_JetSubCalc += 1;

	// This one is already computed bSFup/dn, lSFup/dn as needed above.
	if(theJetBTagDeepCSV_JetSubCalc_PtOrdered.at(ijet) == 1) NJetsDeepCSVwithSF_JetSubCalc += 1;

	if(isNominal && theJetBTag_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsDeepFlavwithSF_JetSubCalc += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt) BJetLeadPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet) {
            minMleppBjet = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepMinMlb = jet_lv.DeltaR(lepton_lv);
	    ind_MinMlb = ijet;
          }
	}
	else if(isBUp && theJetBTag_bSFup_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsDeepFlavwithSF_JetSubCalc += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt) BJetLeadPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet) {
            minMleppBjet = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepMinMlb = jet_lv.DeltaR(lepton_lv);
	    ind_MinMlb = ijet;
          }
	}
	else if(isBDn && theJetBTag_bSFdn_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsDeepFlavwithSF_JetSubCalc += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt) BJetLeadPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet) {
            minMleppBjet = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepMinMlb = jet_lv.DeltaR(lepton_lv);
	    ind_MinMlb = ijet;
          }
	}
	else if(isLUp && theJetBTag_lSFup_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsDeepFlavwithSF_JetSubCalc += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt) BJetLeadPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet) {
            minMleppBjet = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepMinMlb = jet_lv.DeltaR(lepton_lv);
	    ind_MinMlb = ijet;
          }
	}
	else if(isLDn && theJetBTag_lSFdn_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsDeepFlavwithSF_JetSubCalc += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt) BJetLeadPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet) {
            minMleppBjet = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepMinMlb = jet_lv.DeltaR(lepton_lv);
	    ind_MinMlb = ijet;
          }
	}
	
	if(jet_lv.DeltaPhi(nu) < minDPhi_MetJet) minDPhi_MetJet = jet_lv.DeltaPhi(nu);	  

 	if(deltaR_lepJets[ijet] < minDR_lepJet) {
	  minDR_lepJet = deltaR_lepJets[ijet];
	  ptRel_lepJet = lepton_lv.P()*(jet_lv.Vect().Cross(lepton_lv.Vect()).Mag()/jet_lv.P()/lepton_lv.P());
	}
      }

      // ----------------------------------------------------------------------------
      // 13TeV Top pT reweighting -- TTbarMassCalc top vectors are the wrong tops....
      // ----------------------------------------------------------------------------
      
      genTopPt = -999;
      genAntiTopPt = -999;
      topPtWeight13TeV = 1.0;
      
      if(isTT){
	int top1index = -1;
	int top2index = -1;
	for(unsigned int itop=0; itop < allTopsStatus_TTbarMassCalc->size(); itop++){
	  //	  std::cout << "Status: " << allTopsStatus_TTbarMassCalc->at(itop) << ", Pt: " << allTopsPt_TTbarMassCalc->at(itop) << std::endl;
	  if(allTopsStatus_TTbarMassCalc->at(itop) != 62) continue;
	  if(top1index < 0){
	    top1index = itop;
	    continue;
	  }
	  if(top2index < 0){
	    top2index = itop;
	    continue;
	  }
	}

	float SFtop1 = TMath::Exp(0.0615-0.0005*allTopsPt_TTbarMassCalc->at(top1index));
	float SFtop2 = TMath::Exp(0.0615-0.0005*allTopsPt_TTbarMassCalc->at(top2index));
	topPtWeight13TeV = TMath::Sqrt(SFtop1*SFtop2);

	if(allTopsID_TTbarMassCalc->at(top1index) == 6){
	  genTopPt = allTopsPt_TTbarMassCalc->at(top1index);
	  genAntiTopPt = allTopsPt_TTbarMassCalc->at(top2index);
	}
	else{
	  genAntiTopPt = allTopsPt_TTbarMassCalc->at(top1index);
	  genTopPt = allTopsPt_TTbarMassCalc->at(top2index);
	}
      }

      // ----------------------------------------------------------------------------
      // Apply pt ordering to AK8 vectors 
      // ----------------------------------------------------------------------------

      //Pt ordering for AK8
      std::sort(jetak8ptindpair.begin(), jetak8ptindpair.end(), comparepair);

      dnn_J_DeepAK8Calc_PtOrdered.clear();
      dnn_T_DeepAK8Calc_PtOrdered.clear();
      dnn_H_DeepAK8Calc_PtOrdered.clear();
      dnn_W_DeepAK8Calc_PtOrdered.clear();
      dnn_Z_DeepAK8Calc_PtOrdered.clear();
      dnn_B_DeepAK8Calc_PtOrdered.clear();

      maxProb_JetSubCalc_PtOrdered.clear();
      dnn_largest_DeepAK8Calc_PtOrdered.clear();
      theJetAK8DoubleB_JetSubCalc_PtOrdered.clear();
      theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.clear();
      theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered.clear();
      theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered.clear();
      theJetAK8SDSubjetSize_JetSubCalc_PtOrdered.clear();
      theJetAK8Pt_JetSubCalc_PtOrdered.clear();
      theJetAK8Eta_JetSubCalc_PtOrdered.clear();
      theJetAK8Phi_JetSubCalc_PtOrdered.clear();
      theJetAK8Energy_JetSubCalc_PtOrdered.clear();
      theJetAK8Mass_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered.clear();
      theJetAK8SoftDropRaw_PtOrdered.clear();
      theJetAK8SoftDropCorr_PtOrdered.clear();
      theJetAK8SoftDrop_PtOrdered.clear();
      theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.clear();
      theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.clear();
      theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSTau1_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSTau2_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSTau3_JetSubCalc_PtOrdered.clear();
      for(unsigned int ijet=0; ijet < jetak8ptindpair.size(); ijet++){
	dnn_J_DeepAK8Calc_PtOrdered.push_back(dnn_J_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	dnn_T_DeepAK8Calc_PtOrdered.push_back(dnn_T_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	dnn_H_DeepAK8Calc_PtOrdered.push_back(dnn_H_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	dnn_W_DeepAK8Calc_PtOrdered.push_back(dnn_W_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	dnn_Z_DeepAK8Calc_PtOrdered.push_back(dnn_Z_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	dnn_B_DeepAK8Calc_PtOrdered.push_back(dnn_B_DeepAK8Calc->at(jetak8ptindpair[ijet].second)+dnn_C_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
	maxProb_JetSubCalc_PtOrdered.push_back(maxProb_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	dnn_largest_DeepAK8Calc_PtOrdered.push_back(dnn_largest_DeepAK8Calc->at(jetak8ptindpair[ijet].second));
      	theJetAK8DoubleB_JetSubCalc_PtOrdered.push_back(theJetAK8DoubleB_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetIndex_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SDSubjetSize_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetSize_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetNDeepCSVL_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Pt_JetSubCalc_PtOrdered.push_back(theJetAK8Pt_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Eta_JetSubCalc_PtOrdered.push_back(theJetAK8Eta_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Phi_JetSubCalc_PtOrdered.push_back(theJetAK8Phi_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Energy_JetSubCalc_PtOrdered.push_back(theJetAK8Energy_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Mass_JetSubCalc_PtOrdered.push_back(theJetAK8Mass_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered.push_back(theJetAK8CHSPrunedMass_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered.push_back(theJetAK8CHSSoftDropMass_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDropRaw_PtOrdered.push_back(theJetAK8SoftDropRaw_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDropCorr_PtOrdered.push_back(theJetAK8SoftDropCorr_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SoftDrop_PtOrdered.push_back(theJetAK8SoftDrop_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau1_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau2_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau3_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8CHSTau1_JetSubCalc_PtOrdered.push_back(theJetAK8CHSTau1_JetSubCalc->at(jetak8ptindpair[ijet].second));      	
	theJetAK8CHSTau2_JetSubCalc_PtOrdered.push_back(theJetAK8CHSTau2_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8CHSTau3_JetSubCalc_PtOrdered.push_back(theJetAK8CHSTau3_JetSubCalc->at(jetak8ptindpair[ijet].second));
      }

      // Add probabilities
      probSum_DeepAK8_all = 0;
      nB_DeepAK8 = 0;
      nH_DeepAK8 = 0;
      nJ_DeepAK8 = 0;
      nT_DeepAK8 = 0;
      nW_DeepAK8 = 0;
      nZ_DeepAK8 = 0;
      // 0 = J, 1 = T, 2 = H, 3 = Z, 4 = W, 5 = B
      for(unsigned int ijet=0; ijet < jetak8ptindpair.size(); ijet++){
        if (dnn_B_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_B_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (dnn_H_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_H_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (dnn_J_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_J_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (dnn_T_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_T_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (dnn_W_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_W_DeepAK8Calc_PtOrdered.at(ijet) = 0;
        if (dnn_Z_DeepAK8Calc_PtOrdered.at(ijet) < -900) dnn_Z_DeepAK8Calc_PtOrdered.at(ijet) = 0;

        probSum_DeepAK8_all += dnn_B_DeepAK8Calc_PtOrdered.at(ijet) + 2*dnn_W_DeepAK8Calc_PtOrdered.at(ijet) + 2*dnn_T_DeepAK8Calc_PtOrdered.at(ijet) + 3*dnn_Z_DeepAK8Calc_PtOrdered.at(ijet) + 4*dnn_H_DeepAK8Calc_PtOrdered.at(ijet);

        if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 1) nT_DeepAK8 += 1;
        else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 2) nH_DeepAK8 += 1;
        else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 3) nZ_DeepAK8 += 1;
        else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 4) nW_DeepAK8 += 1;
	else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 5) nB_DeepAK8 += 1;
	//	else if (theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered.at(ijet) > 0) nB_DeepAK8 += 1;
        else nJ_DeepAK8 += 1;
      }

      // ----------------------------------------------------------------------------
      // Evaluate the VLQ / ttbar / WJets DNN
      // ----------------------------------------------------------------------------
      
      myMapTT = {
	{"Wjets",  -999},
	{"ttbar",  -999},
	{"Tprime",-999},
      };

      varMapTT = {
	{"corr_met_singleLepCalc", -999},
	{"AK4HTpMETpLepPt", -999},
	{"AK4HT", -999},
	{"NJets_JetSubCalc", -999},
	{"NJetsAK8_JetSubCalc", -999},
	{"jetPt_1", -999},
	{"jetPt_2", -999},
	{"jetPt_3", -999},
	{"dnnJ_1", -999},
	{"dnnJ_2", -999},
	{"dnnJ_3", -999},
      };

      myMapBB = {
	{"Wjets",  -999},
	{"ttbar",  -999},
	{"Bprime",-999},
      };

      varMapBB = {
	{"corr_met_singleLepCalc", -999},
	{"AK4HTpMETpLepPt", -999},
	{"AK4HT", -999},
	{"NJets_JetSubCalc", -999},
	{"NJetsAK8_JetSubCalc", -999},
	{"nH_DeepAK8", -999},
	{"nT_DeepAK8", -999},
	{"jetPt_1", -999},
	{"jetPt_2", -999},
	{"jetPt_3", -999},
	{"sdMass_2", -999},
	{"sdMass_3", -999},
	{"dnnJ_1", -999},
	{"dnnJ_2", -999},
	{"dnnJ_3", -999},
      };

      dnn_WJets = -1;
      dnn_ttbar = -1;
      dnn_Tprime = -1;
      dnn_WJetsBB = -1;
      dnn_ttbarBB = -1;
      dnn_Bprime = -1;

      if(NJetsAK8_JetSubCalc > 1){
	float jetPt_1, jetPt_2, jetPt_3;
	float sdMass_1, sdMass_2, sdMass_3;
	float dnnLargest_2, dnnLargest_3;
	float dnnJ_1, dnnJ_2, dnnJ_3;

	jetPt_1 = theJetAK8Pt_JetSubCalc_PtOrdered.at(0);
	jetPt_2 = theJetAK8Pt_JetSubCalc_PtOrdered.at(1);
	if(NJetsAK8_JetSubCalc > 2) jetPt_3 = theJetAK8Pt_JetSubCalc_PtOrdered.at(2);
	else jetPt_3 = 0;
	
	sdMass_1 = theJetAK8SoftDropCorr_PtOrdered.at(0);
	sdMass_2 = theJetAK8SoftDropCorr_PtOrdered.at(1);
	if(NJetsAK8_JetSubCalc > 2) sdMass_3 = theJetAK8SoftDropCorr_PtOrdered.at(2);
	else sdMass_3 = 0;
	
	dnnLargest_2 = dnn_largest_DeepAK8Calc_PtOrdered.at(1);
	if(NJetsAK8_JetSubCalc > 2) dnnLargest_3 = dnn_largest_DeepAK8Calc_PtOrdered.at(2);
	else dnnLargest_3 = 10;
	
	dnnJ_1 = dnn_J_DeepAK8Calc_PtOrdered.at(0);
	dnnJ_2 = dnn_J_DeepAK8Calc_PtOrdered.at(1);
	if(NJetsAK8_JetSubCalc > 2) dnnJ_3 = dnn_J_DeepAK8Calc_PtOrdered.at(2);
	else dnnJ_3 = -9;

	varMapTT = {
	  {"corr_met_singleLepCalc", corr_met_MultiLepCalc},
	  {"AK4HTpMETpLepPt", AK4HTpMETpLepPt},
	  {"AK4HT", AK4HT},
	  {"NJets_JetSubCalc", NJets_JetSubCalc},
	  {"NJetsAK8_JetSubCalc", NJetsAK8_JetSubCalc},
	  {"jetPt_1", jetPt_1},
	  {"jetPt_2", jetPt_2},
	  {"jetPt_3", jetPt_3},
	  {"dnnJ_1", dnnJ_1},
	  {"dnnJ_2", dnnJ_2},
	  {"dnnJ_3", dnnJ_3},
	};

	varMapBB = {
	  {"corr_met_singleLepCalc", corr_met_MultiLepCalc},
	  {"AK4HTpMETpLepPt", AK4HTpMETpLepPt},
	  {"AK4HT", AK4HT},
	  {"NJets_JetSubCalc", NJets_JetSubCalc},
	  {"NJetsAK8_JetSubCalc", NJetsAK8_JetSubCalc},
	  {"nH_DeepAK8", nH_DeepAK8},
	  {"nT_DeepAK8", nT_DeepAK8},
	  {"jetPt_1", jetPt_1},
	  {"jetPt_2", jetPt_2},
	  {"jetPt_3", jetPt_3},
	  {"sdMass_2", sdMass_1},
	  {"sdMass_3", sdMass_2},
	  {"dnnJ_1", dnnJ_1},
	  {"dnnJ_2", dnnJ_2},
	  {"dnnJ_3", dnnJ_3},
	};
	
	myMapTT = lwtnnTT->compute(varMapTT);      
	myMapBB = lwtnnBB->compute(varMapBB);      

	dnn_WJets = myMapTT["Wjets"];
	dnn_ttbar = myMapTT["ttbar"];
	dnn_Tprime = myMapTT["Tprime"];
	dnn_WJetsBB = myMapBB["Wjets"];
	dnn_ttbarBB = myMapBB["ttbar"];
	dnn_Bprime = myMapBB["Bprime"];
      }

      // ----------------------------------------------------------------------------
      // AK8 Jet - lepton associations and truth matching
      // ----------------------------------------------------------------------------

      deltaR_lepAK8s.clear();
      minDR_lepAK8 = 1000;
      minDR_leadAK8otherAK8 = 1000;
      ptRel_lepAK8 = -99;
      if(theJetAK8Pt_JetSubCalc_PtOrdered.size() < 1) minDR_lepAK8 = -99.0;      
      if(theJetAK8Pt_JetSubCalc_PtOrdered.size() < 2) minDR_leadAK8otherAK8 = -99.0;

      theJetAK8Wmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8Hmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8Zmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8Tmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8MatchedPt_JetSubCalc_PtOrdered.clear();
      theJetAK8Truth_JetSubCalc_PtOrdered.clear();
      DeepAK8SF_TeffUp = 1.0;
      DeepAK8SF_HeffUp = 1.0;
      DeepAK8SF_ZeffUp = 1.0;
      DeepAK8SF_WeffUp = 1.0;
      DeepAK8SF_BeffUp = 1.0;
      DeepAK8SF_JeffUp = 1.0;
      DeepAK8SF_TmisUp = 1.0;
      DeepAK8SF_HmisUp = 1.0;
      DeepAK8SF_ZmisUp = 1.0;
      DeepAK8SF_WmisUp = 1.0;
      DeepAK8SF_BmisUp = 1.0;
      DeepAK8SF_JmisUp = 1.0;
      DeepAK8SF_TeffDn = 1.0;
      DeepAK8SF_HeffDn = 1.0;
      DeepAK8SF_ZeffDn = 1.0;
      DeepAK8SF_WeffDn = 1.0;
      DeepAK8SF_BeffDn = 1.0;
      DeepAK8SF_JeffDn = 1.0;
      DeepAK8SF_TmisDn = 1.0;
      DeepAK8SF_HmisDn = 1.0;
      DeepAK8SF_ZmisDn = 1.0;
      DeepAK8SF_WmisDn = 1.0;
      DeepAK8SF_BmisDn = 1.0;
      DeepAK8SF_JmisDn = 1.0;

      ak8_lv.SetPtEtaPhiM(0,0,0,0);
      TLorentzVector leadak8;
      leadak8.SetPtEtaPhiM(0,0,0,0);

      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc_PtOrdered.size(); ijet++){

	// ----------------------------------------------------------------------------
	// AK8 - lepton and AK8 -- AK8 associations
	// ----------------------------------------------------------------------------
	
	ak8_lv.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),theJetAK8Energy_JetSubCalc_PtOrdered.at(ijet));
	if(ijet == 0) leadak8 = ak8_lv;

	deltaR_lepAK8s.push_back(lepton_lv.DeltaR(ak8_lv));
	if(lepton_lv.DeltaR(ak8_lv) < minDR_lepAK8){
	  minDR_lepAK8 = lepton_lv.DeltaR(ak8_lv);
	  ptRel_lepAK8 = lepton_lv.P()*(ak8_lv.Vect().Cross(lepton_lv.Vect()).Mag()/ak8_lv.P()/lepton_lv.P());
	}

	if(ijet > 0){
	  float tempdr = leadak8.DeltaR(ak8_lv);
	  if(tempdr < minDR_leadAK8otherAK8){
	    minDR_leadAK8otherAK8 = tempdr;
	  }
	}

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
	  bool isJmatched = false;
	  bool isBmatched = false;
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

	  if (not (isWmatched && matchedPt > 200) && not (isZmatched && matchedPt > 200) && not (isTmatched && matchedPt > 400) && not (isHmatched && matchedPt > 300)) {
	    int firstsub = theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered.at(ijet);
	    int nsubs = theJetAK8SDSubjetSize_JetSubCalc_PtOrdered.at(ijet);
	    for(int isub = firstsub; isub < firstsub + nsubs; isub++){
	      if( theJetAK8SDSubjetHFlav_JetSubCalc->at(isub) == 5 ) isBmatched = true;
	    }
	    if ( not isBmatched ) isJmatched = true;
	  }

	  if(isJmatched) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(0);
	  if(isTmatched && matchedPt > 400) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(1);
	  if(isHmatched && matchedPt > 300) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(2);
	  if(isZmatched && matchedPt > 200) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(3);
	  if(isWmatched && matchedPt > 200) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(4);
	  if(isBmatched) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(5);

	  // ------------------------------------------------------------------------------------------------------------------
	  // Sum up an input uncertainty for DeepAK8 scale factors
	  // ------------------------------------------------------------------------------------------------------------------

	  if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 1){
	    if(isTmatched) DeepAK8SF_TeffUp += 0.10;
	    else DeepAK8SF_TmisUp += 0.10;
	  }
	  else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 2){
	    if(isHmatched) DeepAK8SF_HeffUp += 0.10;
	    else DeepAK8SF_HmisUp += 0.10;
	  }
	  else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 3){
	    if(isZmatched) DeepAK8SF_ZeffUp += 0.10;
	    else DeepAK8SF_ZmisUp += 0.10;
	  }
	  else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 4){
	    if(isWmatched) DeepAK8SF_WeffUp += 0.10;
	    else DeepAK8SF_WmisUp += 0.10;
	  }
	  else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 5){
	    if(isBmatched) DeepAK8SF_BeffUp += 0.10;
	    else DeepAK8SF_BmisUp += 0.10;
	  }
	  else{
	    if(isJmatched) DeepAK8SF_JeffUp += 0.10;
	    else DeepAK8SF_JmisUp += 0.10;
	  }
	}
      }

      // ----------------------------------------------------------------------------
      // Set the input down uncertainties for DeepAK8 scale factors
      // ----------------------------------------------------------------------------
      DeepAK8SF_TeffDn = 1.0 - (DeepAK8SF_TeffUp - 1.0);
      DeepAK8SF_HeffDn = 1.0 - (DeepAK8SF_HeffUp - 1.0);
      DeepAK8SF_ZeffDn = 1.0 - (DeepAK8SF_ZeffUp - 1.0);
      DeepAK8SF_WeffDn = 1.0 - (DeepAK8SF_WeffUp - 1.0);
      DeepAK8SF_BeffDn = 1.0 - (DeepAK8SF_BeffUp - 1.0);
      DeepAK8SF_JeffDn = 1.0 - (DeepAK8SF_JeffUp - 1.0);
      DeepAK8SF_TmisDn = 1.0 - (DeepAK8SF_TmisUp - 1.0);
      DeepAK8SF_HmisDn = 1.0 - (DeepAK8SF_HmisUp - 1.0);
      DeepAK8SF_ZmisDn = 1.0 - (DeepAK8SF_ZmisUp - 1.0);
      DeepAK8SF_WmisDn = 1.0 - (DeepAK8SF_WmisUp - 1.0);
      DeepAK8SF_BmisDn = 1.0 - (DeepAK8SF_BmisUp - 1.0);
      DeepAK8SF_JmisDn = 1.0 - (DeepAK8SF_JmisUp - 1.0);

      // ----------------------------------------------------------------------------
      // W --> l nu with mass constraint
      // ----------------------------------------------------------------------------

      double metpx = corr_met_MultiLepCalc*cos(corr_met_phi_MultiLepCalc);
      double metpy = corr_met_MultiLepCalc*sin(corr_met_phi_MultiLepCalc);
      double metpt = corr_met_MultiLepCalc;
      TLorentzVector Wlv_1, Wlv_2, Wlv, Nulv_1, Nulv_2;
      double nuPz_1;
      double nuPz_2;
      
      double Dtmp = MW*MW - lepM*lepM + 2*(lepton_lv.Px()*metpx + lepton_lv.Py()*metpy);
      double Atmp = 4.0*(lepton_lv.Energy()*lepton_lv.Energy() - lepton_lv.Pz()*lepton_lv.Pz());
      double Btmp = -4.0*Dtmp*lepton_lv.Pz();
      double Ctmp = 4.0*lepton_lv.Energy()*lepton_lv.Energy()*metpt*metpt - Dtmp*Dtmp;
      
      double DETtmp = Btmp*Btmp-4.0*Atmp*Ctmp;

      if(DETtmp >= 0) {
      	nuPz_1 = (-Btmp+TMath::Sqrt(DETtmp))/(2.0*Atmp);
      	nuPz_2 = (-Btmp-TMath::Sqrt(DETtmp))/(2.0*Atmp);
      	Nulv_1.SetPxPyPzE(metpx,metpy,nuPz_1,TMath::Sqrt((metpt)*(metpt)+(nuPz_1)*(nuPz_1)));
      	Nulv_2.SetPxPyPzE(metpx,metpy,nuPz_2,TMath::Sqrt((metpt)*(metpt)+(nuPz_2)*(nuPz_2)));
      }else{
      	nuPz_1 = -Btmp/(2.0*Atmp);
      	nuPz_2 = -Btmp/(2.0*Atmp);
	// does another quad solution for pT and scales pT in result. Reduces M, pT, DR.
      	double alpha = lepton_lv.Px()*metpx/metpt + lepton_lv.Py()*metpy/metpt;
      	double Delta = MW*MW - lepM*lepM;
      	Atmp = 4.0*(lepton_lv.Pz()*lepton_lv.Pz() - lepton_lv.Energy()*lepton_lv.Energy() + alpha*alpha);
      	Btmp = 4.0*alpha*Delta;
      	Ctmp = Delta*Delta;
      	float DETtmp2 = Btmp*Btmp-4.0*Atmp*Ctmp;
      	double pTnu_1 = (-Btmp+TMath::Sqrt(DETtmp2))/(2.0*Atmp);
      	double pTnu_2 = (-Btmp-TMath::Sqrt(DETtmp2))/(2.0*Atmp);
      	Nulv_1.SetPxPyPzE(metpx*pTnu_1/metpt,metpy*pTnu_1/metpt,nuPz_1,TMath::Sqrt(pTnu_1*pTnu_1 + nuPz_1*nuPz_1));
      	Nulv_2.SetPxPyPzE(metpx*pTnu_2/metpt,metpy*pTnu_2/metpt,nuPz_2,TMath::Sqrt(pTnu_2*pTnu_2 + nuPz_2*nuPz_2));
      }
      Wlv_1 = Nulv_1+lepton_lv;
      Wlv_2 = Nulv_2+lepton_lv;
      
      if (fabs(Wlv_1.M()-MW) < fabs(Wlv_2.M()-MW)) Wlv = Wlv_1;
      else Wlv = Wlv_2;
 
      W_mass = Wlv.M();
      W_pt = Wlv.Pt();
      W_dRLep = Wlv.DeltaR(lepton_lv);

      // ----------------------------------------------------------------------------
      // VLQ decay
      // ----------------------------------------------------------------------------                                                                                                           
      // Find closest b-tagged AK4 to the W vector
      float deltaRbW = 999;
      int bIndex = 999;
      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc_PtOrdered.size(); ijet++){
	if(isNominal && theJetBTag_JetSubCalc_PtOrdered.at(ijet) == 0) continue;
	else if(isBUp && theJetBTag_bSFup_JetSubCalc_PtOrdered.at(ijet) == 0) continue;
	else if(isBDn && theJetBTag_bSFdn_JetSubCalc_PtOrdered.at(ijet) == 0) continue;
	else if(isLUp && theJetBTag_lSFup_JetSubCalc_PtOrdered.at(ijet) == 0) continue;
	else if(isLDn && theJetBTag_lSFdn_JetSubCalc_PtOrdered.at(ijet) == 0) continue;

	jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(ijet),theJetEta_JetSubCalc_PtOrdered.at(ijet),theJetPhi_JetSubCalc_PtOrdered.at(ijet),theJetEnergy_JetSubCalc_PtOrdered.at(ijet));
	if(jet_lv.DeltaR(Wlv) < deltaRbW){
	  deltaRbW = jet_lv.DeltaR(Wlv);
	  bIndex = ijet;
	}
      }

      // Form a leptonic top candidate if the b is close enough
      TLorentzVector top_lv;
      t_mass = -999;
      isLeptonic_W = false;
      isLeptonic_t = false;
      if(minMleppJet > 150){  // best combo of W vs t truth match with this
	//if(deltaRbW >= 0.8 && minMleppJet > 150){  // favors tops
	isLeptonic_W = true;
      }else{
	if(deltaRbW > 0.8) bIndex = ind_MinMlj; // use a close b unless it doesn't exist
	TLorentzVector bottom_lv;
	bottom_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(bIndex),theJetEta_JetSubCalc_PtOrdered.at(bIndex),theJetPhi_JetSubCalc_PtOrdered.at(bIndex),theJetEnergy_JetSubCalc_PtOrdered.at(bIndex));
	top_lv = bottom_lv + Wlv;
	t_mass = top_lv.M();
	t_pt = top_lv.Pt();
	t_dRWb = bottom_lv.DeltaR(Wlv);
	isLeptonic_t = true;
      } 

      // Fill the vector for deltaR from leptonic particle (W or t) from all AK8 Jets
      std::vector<pair<TLorentzVector,int>> jets_lv;
      deltaR_leptonicparticle_AK8_PtOrdered.clear();
      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc_PtOrdered.size(); ijet++){
	jet_lv.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),theJetAK8Energy_JetSubCalc_PtOrdered.at(ijet));
	if(isLeptonic_W) deltaR_leptonicparticle_AK8_PtOrdered.push_back(jet_lv.DeltaR(Wlv));
	if(isLeptonic_t) deltaR_leptonicparticle_AK8_PtOrdered.push_back(jet_lv.DeltaR(top_lv));

	// Get 3 highest-pT jets that are not close to t/W (deltaR > .8) and store AK8 index and 4-vector
	if(jets_lv.size() >= 3) continue;

	//	if(jet_lv.DeltaR(top_lv) > .6 and isLeptonic_t) jets_lv.push_back(std::make_pair(jet_lv,ijet)); // b-quark peak at low DR, minimum near 0.6
	//	if(jet_lv.DeltaR(Wlv) > 0 and isLeptonic_W) jets_lv.push_back(std::make_pair(jet_lv,ijet)); // no peak at low DR in all AK8, cut only very close
	if(jet_lv.DeltaR(top_lv) > 0.8 and isLeptonic_t) jets_lv.push_back(std::make_pair(jet_lv,ijet));
	if(jet_lv.DeltaR(Wlv) > 0.8 and isLeptonic_W) jets_lv.push_back(std::make_pair(jet_lv,ijet));
      }

      highPtAK8Jet1_SoftDropCorrectedMass = -999;
      highPtAK8Jet2_SoftDropCorrectedMass = -999;
      highPtAK8Jet3_SoftDropCorrectedMass = -999;

      leptonicTprimeJetIDs_DeepAK8.clear();
      hadronicTprimeJetIDs_DeepAK8.clear();
      leptonicBprimeJetIDs_DeepAK8.clear();
      hadronicBprimeJetIDs_DeepAK8.clear();
	
      Tprime1_DeepAK8_Mass = -999;
      Tprime2_DeepAK8_Mass = -999;
      Tprime1_DeepAK8_Pt = -999;
      Tprime2_DeepAK8_Pt = -999;
      Tprime1_DeepAK8_Eta = -999;
      Tprime2_DeepAK8_Eta = -999;
      Tprime1_DeepAK8_Phi = -999;
      Tprime2_DeepAK8_Phi = -999;
      Tprime1_DeepAK8_deltaR = -999;
      Tprime2_DeepAK8_deltaR = -999;
      Bprime1_DeepAK8_Mass = -999;
      Bprime2_DeepAK8_Mass = -999;
      Bprime1_DeepAK8_Pt = -999;
      Bprime2_DeepAK8_Pt = -999;
      Bprime1_DeepAK8_Eta = -999;
      Bprime2_DeepAK8_Eta = -999;
      Bprime1_DeepAK8_Phi = -999;
      Bprime2_DeepAK8_Phi = -999;
      Bprime1_DeepAK8_deltaR = -999;
      Bprime2_DeepAK8_deltaR = -999;
      
      validTDecay_DeepAK8 = false;
      validBDecay_DeepAK8 = false;
      taggedBWBW_DeepAK8 = false;
      taggedTHBW_DeepAK8 = false;
      taggedTHTH_DeepAK8 = false;
      taggedTZBW_DeepAK8 = false;
      taggedTZTH_DeepAK8 = false;
      taggedTZTZ_DeepAK8 = false;      
      taggedTWTW_DeepAK8 = false;
      taggedBZTW_DeepAK8 = false;
      taggedBHTW_DeepAK8 = false;

      probSum_DeepAK8_decay = -999;
      probSum_DeepAK8_four = -999;

      // ----------------------------------------------------------------------------
      // VLQ Decay -- 3 AK8 jets away from leptonic particle
      // ----------------------------------------------------------------------------                                                                                                           
      if(jets_lv.size() > 3) std::cout << "Problem: > 3 AK8s for Tprime reco" << std::endl;
      if(jets_lv.size() == 3){

	npass_ThreeJets = npass_ThreeJets + 1;

	// Sums of tag probabilities
	probSum_DeepAK8_decay = 0;
	probSum_DeepAK8_four = 0;
        for (unsigned int i = 0; i < jets_lv.size(); i++) {
	  // "decay" weighted sum of probabilities including B
          probSum_DeepAK8_decay += dnn_B_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second) + 2*dnn_W_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second) + 3*dnn_T_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second) + 4*dnn_Z_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second) + 5*dnn_H_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second);

	  // "four" raw sum of heavy particle probabilities
          probSum_DeepAK8_four += dnn_W_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second) + dnn_T_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second) + dnn_Z_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second) + dnn_H_DeepAK8Calc_PtOrdered.at(jets_lv.at(i).second);
	}
	
	// First guess at leptonic T particles
	if(isLeptonic_W) leptonicTprimeJetIDs_DeepAK8.push_back(4);
	if(isLeptonic_t) leptonicTprimeJetIDs_DeepAK8.push_back(1);
	
	// Save masses of the 3 jets for plotting
	highPtAK8Jet1_SoftDropCorrectedMass = theJetAK8SoftDropCorr_PtOrdered.at(jets_lv.at(0).second);
	highPtAK8Jet2_SoftDropCorrectedMass = theJetAK8SoftDropCorr_PtOrdered.at(jets_lv.at(1).second);
	highPtAK8Jet3_SoftDropCorrectedMass = theJetAK8SoftDropCorr_PtOrdered.at(jets_lv.at(2).second);
	
	// ----------------------------------------------------------------------------
	// DeepAK8 SECTION -- TT
	// ----------------------------------------------------------------------------                                                                                                   

	// get the tags
	int jet1_DeepAK8 = dnn_largest_DeepAK8Calc_PtOrdered.at(jets_lv.at(0).second);
	int jet2_DeepAK8 = dnn_largest_DeepAK8Calc_PtOrdered.at(jets_lv.at(1).second);
	int jet3_DeepAK8 = dnn_largest_DeepAK8Calc_PtOrdered.at(jets_lv.at(2).second);
	// Group all the light quarks up, boosts valids without loss of res
	//	if(jet1_DeepAK8 == 0) jet1_DeepAK8 = 5;
	//	if(jet2_DeepAK8 == 0) jet2_DeepAK8 = 5;
	//	if(jet3_DeepAK8 == 0) jet3_DeepAK8 = 5;

	// pair up the jet tag with the pT index 0,1,2 and sort by tag (orders J, T, H, Z, W, B)
	std::vector <pair<int,int>> decayJets_DeepAK8;
	decayJets_DeepAK8.push_back(std::make_pair(jet1_DeepAK8,0));
	decayJets_DeepAK8.push_back(std::make_pair(jet2_DeepAK8,1));
	decayJets_DeepAK8.push_back(std::make_pair(jet3_DeepAK8,2));
	std::sort(decayJets_DeepAK8.begin(),decayJets_DeepAK8.end());

	// Start forming 4 particle groups
	TLorentzVector Tprime1_DeepAK8_lv;
	TLorentzVector Tprime2_DeepAK8_lv;
	TLorentzVector Bprime1_DeepAK8_lv;
	TLorentzVector Bprime2_DeepAK8_lv;
	validBDecay_DeepAK8 = false;
	validTDecay_DeepAK8 = false;
	if(isLeptonic_t){

	  float massDiff1=(top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();
	  float massDiff2=(top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M();
	  float massDiff3=(top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();

	  if(decayJets_DeepAK8.at(0).first==2 && decayJets_DeepAK8.at(1).first==4 && decayJets_DeepAK8.at(2).first==5){ // TT -> tH bW, BB -> tW bH
	    validTDecay_DeepAK8 = true;
	    taggedTHBW_DeepAK8 = true;
	    leptonicTprimeJetIDs_DeepAK8.push_back(2); // assign the H with the leptonic top
	    hadronicTprimeJetIDs_DeepAK8 = {4,5};      // assign the b & W as hadronic
	    Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first; // decayJets.second gives the jets_lv index to get 4-vec
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);

	    validBDecay_DeepAK8 = true;
	    taggedBHTW_DeepAK8 = true;
	    leptonicBprimeJetIDs_DeepAK8.push_back(4); // assign the W with leptonic top
	    hadronicBprimeJetIDs_DeepAK8 = {2,5};      // assign bH hadronic
	    Bprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; // decayJets.second gives the jets_lv index to get 4-vec
	    Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Bprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	    Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);

	  }
	  else if(decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==2 && decayJets_DeepAK8.at(2).first==2){ // TTbar --> tH and tH
	    validTDecay_DeepAK8 = true;
	    taggedTHTH_DeepAK8 = true;
	    leptonicTprimeJetIDs_DeepAK8.push_back(2); // assign an H with leptonic top
	    hadronicTprimeJetIDs_DeepAK8 = {1,2};      // assign tH hadronic
	    // options (lepTop + H1) - (T0 + H2) OR (lepTop + H2) - (T0 + H1) checking smallest
	    if(massDiff1 < massDiff2) { // (lepTop + H1) wins
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; 
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // (lepTop + H2) wins
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    }
	  }
	  else if(decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==2 && decayJets_DeepAK8.at(2).first==3){ // TTbar --> tH and tZ
	    validTDecay_DeepAK8 = true;
	    taggedTZTH_DeepAK8 = true;
	    // options (lepTop + H1) - (T0 + Z2) OR (lepTop + Z2) - (T0 + H1)
	    if(massDiff1 < massDiff2) { // (lepTop + H1) wins
	      leptonicTprimeJetIDs_DeepAK8.push_back(2); // tH
	      hadronicTprimeJetIDs_DeepAK8 = {1,3}; // tZ
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; 
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // (lepTop + Z2) wins
	      leptonicTprimeJetIDs_DeepAK8.push_back(3);
	      hadronicTprimeJetIDs_DeepAK8 = {1,2};
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    }
	  }
	  else if(decayJets_DeepAK8.at(0).first==3 && decayJets_DeepAK8.at(1).first==4 && decayJets_DeepAK8.at(2).first==5){ // TT -> tZ bW, BB -> tW bZ
	    validTDecay_DeepAK8 = true;
	    taggedTZBW_DeepAK8 = true;
	    leptonicTprimeJetIDs_DeepAK8.push_back(3); // tZ
	    hadronicTprimeJetIDs_DeepAK8 = {4,5}; // bW
	    Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);

	    validBDecay_DeepAK8 = true;
	    taggedBZTW_DeepAK8 = true;
	    leptonicBprimeJetIDs_DeepAK8.push_back(4); // assign the W with the leptonic top
	    hadronicBprimeJetIDs_DeepAK8 = {3,5};      // assign the b & Z as hadronic
	    Bprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; // decayJets.second gives the jets_lv index to get 4-vec
	    Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Bprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	    Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	  }
	  else if(decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==3 && decayJets_DeepAK8.at(2).first==3){ // TTbar --> tZ tZ
	    validTDecay_DeepAK8 = true;
	    taggedTZTZ_DeepAK8 = true;
	    leptonicTprimeJetIDs_DeepAK8.push_back(3); // tZ
	    hadronicTprimeJetIDs_DeepAK8 = {1,3}; // tZ
	    // options (lepTop + Z1) - (T0 + Z2) OR (lepTop + Z2) - (T0 + Z1)
	    if(massDiff1 < massDiff2) { // (lepTop + Z1) wins
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; 
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // (lepTop + Z2) wins
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    } 
	  }
	  else if(decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==4 && decayJets_DeepAK8.at(2).first==4){ // BB/XX -> tW tW, jets t W W
	    validBDecay_DeepAK8 = true;
	    taggedTWTW_DeepAK8 = true;
	    leptonicBprimeJetIDs_DeepAK8.push_back(4); // tW
	    hadronicBprimeJetIDs_DeepAK8 = {1,4}; // tW
	    // options (lepTop + W1) - (T0 + W2) OR (lepTop + W2) - (T0 + W1)
	    if(massDiff1 < massDiff2) { // (lepTop + W1) wins
	      Bprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first; 
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // (lepTop + W2) wins
	      Bprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Bprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	    }
	  }

	  if(!validTDecay_DeepAK8){ // Not a valid T decay combination
	    if(massDiff3 < massDiff1 and massDiff3 < massDiff2){  // lepTop + 0 is best
	      leptonicTprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(0).first);
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(1).first, decayJets_DeepAK8.at(2).first};
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else if(massDiff1 < massDiff2 and massDiff1 < massDiff3){ // lepTop + 1 is best 
	      leptonicTprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(1).first);
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(2).first};
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // lepTop + 2 is best
	      leptonicTprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(2).first);
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(1).first};
	      Tprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    }
	  }
	  if(!validBDecay_DeepAK8){ // Not a valid B decay combination
	    if(massDiff3 < massDiff1 and massDiff3 < massDiff2){  // lepTop + 0 is best
	      leptonicBprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(0).first);
	      hadronicBprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(1).first, decayJets_DeepAK8.at(2).first};
	      Bprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else if(massDiff1 < massDiff2 and massDiff1 < massDiff3){ // lepTop + 1 is best 
	      leptonicBprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(1).first);
	      hadronicBprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(2).first};
	      Bprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // lepTop + 2 is best
	      leptonicBprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(2).first);
	      hadronicBprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(1).first};
	      Bprime1_DeepAK8_lv = top_lv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Bprime1_DeepAK8_deltaR = top_lv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    }
	  }
	}else{ // isLeptonic_W

	  float massDiff1=(Wlv+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();
	  float massDiff2=(Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first).M();
	  float massDiff3=(Wlv+jets_lv.at(decayJets_DeepAK8.at(0).second).first).M()-(jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first).M();

	  if(decayJets_DeepAK8.at(0).first==4 && decayJets_DeepAK8.at(1).first==5 && decayJets_DeepAK8.at(2).first==5){ // bW bW
	    validTDecay_DeepAK8 = true;
	    taggedBWBW_DeepAK8 = true;
	    leptonicTprimeJetIDs_DeepAK8.push_back(5); // bW
	    hadronicTprimeJetIDs_DeepAK8 = {4,5}; // bW
	    // options (lepW + b1) - (W0 + b2) OR (lepW + b2) - (W0 + b1)
	    if(massDiff1 < massDiff2) { // (lepW + b1) wins
	      Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // (lepW + b2) wins
	      Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	    }
	  }
	  else if(decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==3 && decayJets_DeepAK8.at(2).first==5){ // TT -> bW tZ, BB -> tW bZ
	    validTDecay_DeepAK8 = true;
	    taggedTZBW_DeepAK8 = true;
	    leptonicTprimeJetIDs_DeepAK8.push_back(5); // bW
	    hadronicTprimeJetIDs_DeepAK8 = {1,3}; // tZ
	    Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	    Tprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);

	    validBDecay_DeepAK8 = true;
	    taggedBZTW_DeepAK8 = true;
	    leptonicBprimeJetIDs_DeepAK8.push_back(4); // tW
	    hadronicBprimeJetIDs_DeepAK8 = {3,5}; // bZ
	    Bprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	    Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Bprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	  }
	  else if(decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==2 && decayJets_DeepAK8.at(2).first==5){ // TT -> bW tH, BB -> tW bH
	    validTDecay_DeepAK8 = true;	    
	    taggedTHBW_DeepAK8 = true;
	    leptonicTprimeJetIDs_DeepAK8.push_back(5); // bW
	    hadronicTprimeJetIDs_DeepAK8 = {1,2}; // tH
	    Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	    Tprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);

	    validBDecay_DeepAK8 = true;	    
	    taggedBHTW_DeepAK8 = true;
	    leptonicBprimeJetIDs_DeepAK8.push_back(4); // tW
	    hadronicBprimeJetIDs_DeepAK8 = {2,5}; // bH
	    Bprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	    Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	    Bprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	    Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(2).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	  }
	  else if(decayJets_DeepAK8.at(0).first==1 && decayJets_DeepAK8.at(1).first==1 && decayJets_DeepAK8.at(2).first==4){ // BB -> tW tW, jets t t W
	    validBDecay_DeepAK8 = true;
	    taggedTWTW_DeepAK8 = true;
	    leptonicBprimeJetIDs_DeepAK8.push_back(1); // tW
	    hadronicBprimeJetIDs_DeepAK8 = {1,4}; // tW
	    // options (lepW + t0) - (W2 + t1) OR (lepW + t1) - (W2 + t0)
	    if(massDiff3 < massDiff1) { // (lepW + t0) wins
	      Bprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // (lepW + t1) wins
	      Bprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    }
	  }
	  
	  if(!validTDecay_DeepAK8){ // not a valid grouping
	    if(massDiff3 < massDiff1 and massDiff3 < massDiff2){ // lepW + 0 wins
	      leptonicTprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(0).first);
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(1).first, decayJets_DeepAK8.at(2).first};
	      Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else if(massDiff1 < massDiff2 and massDiff1 < massDiff3){ // lepW + 1 wins
	      leptonicTprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(1).first);
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(2).first};
	      Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // lepW + 2 wins
	      leptonicTprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(2).first);
	      hadronicTprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(1).first};
	      Tprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Tprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Tprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Tprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    }
	  }
	  if(!validBDecay_DeepAK8){ // not a valid grouping
	    if(massDiff3 < massDiff1 and massDiff3 < massDiff2){ // lepW + 0 wins
	      leptonicBprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(0).first);
	      hadronicBprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(1).first, decayJets_DeepAK8.at(2).first};
	      Bprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(0).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(1).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(0).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(1).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else if(massDiff1 < massDiff2 and massDiff1 < massDiff3){ // lepW + 1 wins
	      leptonicBprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(1).first);
	      hadronicBprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(2).first};
	      Bprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(1).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    } else { // lepW + 2 wins
	      leptonicBprimeJetIDs_DeepAK8.push_back(decayJets_DeepAK8.at(2).first);
	      hadronicBprimeJetIDs_DeepAK8 = {decayJets_DeepAK8.at(0).first, decayJets_DeepAK8.at(1).first};
	      Bprime1_DeepAK8_lv = Wlv+jets_lv.at(decayJets_DeepAK8.at(2).second).first;
	      Bprime2_DeepAK8_lv = jets_lv.at(decayJets_DeepAK8.at(0).second).first+jets_lv.at(decayJets_DeepAK8.at(1).second).first;
	      Bprime1_DeepAK8_deltaR = Wlv.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	      Bprime2_DeepAK8_deltaR = jets_lv.at(decayJets_DeepAK8.at(0).second).first.DeltaR(jets_lv.at(decayJets_DeepAK8.at(2).second).first);
	    }
	  }
	}
	
        if(Tprime1_DeepAK8_lv.M() != -999){
	  Tprime1_DeepAK8_Mass = Tprime1_DeepAK8_lv.M();
	  Tprime2_DeepAK8_Mass = Tprime2_DeepAK8_lv.M();
	  Tprime1_DeepAK8_Pt = Tprime1_DeepAK8_lv.Pt();
	  Tprime2_DeepAK8_Pt = Tprime2_DeepAK8_lv.Pt();
	  Tprime1_DeepAK8_Eta = Tprime1_DeepAK8_lv.Eta();
	  Tprime2_DeepAK8_Eta = Tprime2_DeepAK8_lv.Eta();
	  Tprime1_DeepAK8_Phi = Tprime1_DeepAK8_lv.Phi();
	  Tprime2_DeepAK8_Phi = Tprime2_DeepAK8_lv.Phi();
	}
        if(Bprime1_DeepAK8_lv.M() != -999){
	  Bprime1_DeepAK8_Mass = Bprime1_DeepAK8_lv.M();
	  Bprime2_DeepAK8_Mass = Bprime2_DeepAK8_lv.M();
	  Bprime1_DeepAK8_Pt = Bprime1_DeepAK8_lv.Pt();
	  Bprime2_DeepAK8_Pt = Bprime2_DeepAK8_lv.Pt();
	  Bprime1_DeepAK8_Eta = Bprime1_DeepAK8_lv.Eta();
	  Bprime2_DeepAK8_Eta = Bprime2_DeepAK8_lv.Eta();
	  Bprime1_DeepAK8_Phi = Bprime1_DeepAK8_lv.Phi();
	  Bprime2_DeepAK8_Phi = Bprime2_DeepAK8_lv.Phi();
	}

	// Numerator of confusion matrix
	if(isSig && inTreeName.EqualTo("ljmet")){
	  if(confusionTruth < 6.0){
	    if(taggedBWBW_DeepAK8) TTconfusionN->Fill(0.5,confusionTruth);
	    else if(taggedTZBW_DeepAK8) TTconfusionN->Fill(1.5,confusionTruth);
	    else if(taggedTHBW_DeepAK8) TTconfusionN->Fill(2.5,confusionTruth);
	    else if(taggedTZTH_DeepAK8) TTconfusionN->Fill(3.5,confusionTruth);
	    else if(taggedTZTZ_DeepAK8) TTconfusionN->Fill(4.5,confusionTruth);
	    else if(taggedTHTH_DeepAK8) TTconfusionN->Fill(5.5,confusionTruth);
	    else{
	      if(hadronicTprimeJetIDs_DeepAK8.at(0) == 4 && hadronicTprimeJetIDs_DeepAK8.at(1) == 5) TTconfusionN->Fill(6.5,confusionTruth);
	      else if(hadronicTprimeJetIDs_DeepAK8.at(0) == 1 && hadronicTprimeJetIDs_DeepAK8.at(1) == 3) TTconfusionN->Fill(7.5,confusionTruth);
	      else if(hadronicTprimeJetIDs_DeepAK8.at(0) == 1 && hadronicTprimeJetIDs_DeepAK8.at(1) == 2) TTconfusionN->Fill(8.5,confusionTruth);
	      else TTconfusionN->Fill(9.5,confusionTruth);
	    }
	  }else{
	    if(taggedTWTW_DeepAK8) BBconfusionN->Fill(0.5,confusionTruth-6.0);
	    else if(taggedBZTW_DeepAK8) BBconfusionN->Fill(1.5,confusionTruth-6.0);
	    else if(taggedBHTW_DeepAK8) BBconfusionN->Fill(2.5,confusionTruth-6.0);
	    else{
	      if(hadronicBprimeJetIDs_DeepAK8.at(0) == 1 && hadronicBprimeJetIDs_DeepAK8.at(1) == 4) BBconfusionN->Fill(3.5,confusionTruth-6.0);
	      else if(hadronicBprimeJetIDs_DeepAK8.at(0) == 3 && hadronicBprimeJetIDs_DeepAK8.at(1) == 5) BBconfusionN->Fill(4.5,confusionTruth-6.0);
	      else if(hadronicBprimeJetIDs_DeepAK8.at(0) == 2 && hadronicBprimeJetIDs_DeepAK8.at(1) == 5) BBconfusionN->Fill(5.5,confusionTruth-6.0);
	      else BBconfusionN->Fill(6.5,confusionTruth-6.0);
	    }
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
      pdfNewWeights.clear();
      pdfNewNominalWeight = 1.0;
      if(isSig){
	pdfNewNominalWeight = NewPDFweights_MultiLepCalc->at(0);
	// SEEMS TO APPLY TO ALL B2G MG+PYTHIA SIGNALS. NNLO 4-FLAVOR PDF
	for(unsigned int i = 0; i < LHEweightids_MultiLepCalc->size(); i++){
	  if(i > 0 && i < 101) pdfNewWeights.push_back(NewPDFweights_MultiLepCalc->at(i));
	  if(LHEweightids_MultiLepCalc->at(i) > 1 && LHEweightids_MultiLepCalc->at(i) < 10){
	    if(LHEweightids_MultiLepCalc->at(i) == 6 || LHEweightids_MultiLepCalc->at(i) == 8) continue;
	    renormWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	  if(LHEweightids_MultiLepCalc->at(i) > 474 && LHEweightids_MultiLepCalc->at(i) < 575){
	    pdfWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	}
      }
      else if(isMadgraphBkg){
	// SEEMS TO APPLY TO OTHER MG+PYTHIA BACKGROUNDS. LEADING ORDER 5-FLAVOR PDF
	for(unsigned int i = 0; i < LHEweightids_MultiLepCalc->size(); i++){
	  if(LHEweightids_MultiLepCalc->at(i) > 1 && LHEweightids_MultiLepCalc->at(i) < 10){
	    if(LHEweightids_MultiLepCalc->at(i) == 6 || LHEweightids_MultiLepCalc->at(i) == 8) continue;
	    renorm.push_back(LHEweights_MultiLepCalc->at(i));
	    renormWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	  if(LHEweightids_MultiLepCalc->at(i) > 10 && LHEweightids_MultiLepCalc->at(i) < 111){
	    pdf.push_back(LHEweights_MultiLepCalc->at(i));
	    pdfWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	  if(LHEweightids_MultiLepCalc->at(i) == 111 || LHEweightids_MultiLepCalc->at(i) == 112){
	    alphaSWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	}
      }
      else{
	// SEEMS TO APPLY TO ALL POWHEG AND MC@NLO BACKGROUNDS. NLO PDFs
	for(unsigned int i = 0; i < LHEweightids_MultiLepCalc->size(); i++){
	  if(LHEweightids_MultiLepCalc->at(i) > 1001 && LHEweightids_MultiLepCalc->at(i) < 1010){
	    if(LHEweightids_MultiLepCalc->at(i) == 1006 || LHEweightids_MultiLepCalc->at(i) == 1008) continue;
	    renorm.push_back(LHEweights_MultiLepCalc->at(i));
	    renormWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	  if(LHEweightids_MultiLepCalc->at(i) > 2000 && LHEweightids_MultiLepCalc->at(i) < 2101){
	    pdf.push_back(LHEweights_MultiLepCalc->at(i));
	    pdfWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	  if(LHEweightids_MultiLepCalc->at(i) == 2101 || LHEweightids_MultiLepCalc->at(i) == 2102){
	    alphaSWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	}
      }

      if(renormWeights.size() == 0){
	if(isVV){
	  renormWeights.push_back(0.85);
	  renormWeights.push_back(1.15);
	  renormWeights.push_back(0.85);
	  renormWeights.push_back(0.85);
	  renormWeights.push_back(1.15);
	  renormWeights.push_back(1.15);
	}else{
	  for(int irn = 0; irn < 6; irn++){
	    renormWeights.push_back(1.0);
	  }
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
   std::cout<<"Npassed_ElEta          = "<<npass_ElEta<<" / "<<nentries<<std::endl;
   std::cout<<"Nmuons                 = "<<Nmuons<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_MuEta          = "<<npass_MuEta<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_nAK8Jets       = "<<npass_nAK8jets<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_Trigger        = "<<npass_trigger<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_MET            = "<<npass_met<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_lepPt          = "<<npass_lepPt<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_HT             = "<<npass_ht<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_ALL            = "<<npass_all<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_ThreeJets      = "<<npass_ThreeJets<<" / "<<nentries<<std::endl;
   
   if(isSig && inTreeName.EqualTo("ljmet")){
     TTconfusionD->Write();
     TTconfusionN->Write();
     BBconfusionD->Write();
     BBconfusionN->Write();
   }
   outputTree->Write();
   delete outputTree;
   delete TTconfusionD;
   delete TTconfusionN;
   delete BBconfusionD;
   delete BBconfusionN;
   delete poly2;
   delete poly2U;
   delete poly2D;
}



