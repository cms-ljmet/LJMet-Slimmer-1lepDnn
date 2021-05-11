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

std::string dnnFileTT = "vlq_mlp_3by10_060920_TT2018_test90.json"; //change to TT file X
std::ifstream input_cfgTT( dnnFileTT );
lwt::JSONConfig cfgTT = lwt::parse_json(input_cfgTT);
lwt::LightweightNeuralNetwork* lwtnnTT = new lwt::LightweightNeuralNetwork(cfgTT.inputs, cfgTT.layers, cfgTT.outputs);

std::string dnnFileBB = "vlq_mlp_3by10_060920_BB2018_test67.json"; //change to BB file X
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
  
  }
  else{  // use this if SF<1
                                              
       //downgrade tagged to untagged
       if( isTagged && coin > tag_SF ) {newTag = false;}
  
  }
  
  return newTag;
}

enum shift:char{ central, uncert };

double step1::GetBtagSF2018Medium_comb(shift Shift, double pt, double eta){
  if(pt > 1000.) pt = 1000.;
  if(fabs(eta) > 2.5 or pt<20.) return 1.0; 
  switch(Shift){
  case uncert:
    if(pt<30)       return 0.065904870629310608;
    else if(pt<50)  return 0.015055687166750431;
    else if(pt<70)  return 0.013506759889423847;
    else if(pt<100) return 0.015106724575161934;
    else if(pt<140) return 0.014620178379118443;
    else if(pt<200) return 0.012161554768681526;
    else if(pt<300) return 0.016239689663052559;
    else if(pt<600) return 0.039990410208702087;
    else            return 0.068454340100288391;
  case central:
  default:
    return 0.909339+(0.00354*(log(pt+19)*(log(pt+18)*(3-(0.471623*log(pt+18))))));
  }//end switch on shift
}

double step1::GetCtagSF2018Medium_comb(shift Shift, double pt, double eta){
  // SFs are identical with 3x uncertainty as B tag, checked for '18
  if(pt > 1000.) pt = 1000.;
  if(fabs(eta) > 2.5 or pt<20.) return 1.0; 
  switch(Shift){
  case uncert: return 3.0 * GetBtagSF2018Medium_comb(uncert, pt, eta);
  case central:
  default: return GetBtagSF2018Medium_comb(central, pt, eta);
  }//end switch on shift
}

double step1::GetLFSF2018Medium( shift Shift, double pt, double eta){
  if(pt > 1000.) pt = 1000.;
  if(fabs(eta) > 2.4 or pt<20.) return 1.;
  switch(Shift){
  case uncert:
    return  (1.6329+-0.00160255*pt+1.9899e-06*pt*pt+-6.72613e-10*pt*pt*pt)*(0.122811+0.000162564*pt+-1.66422e-07*pt*pt);
  case central:
  default:
    return  1.6329+-0.00160255*pt+1.9899e-06*pt*pt+-6.72613e-10*pt*pt*pt;
  }//end switch Shift
}

double step1::GetBtagEfficiency(double pt){
// Efficiencies from TT powheg sample for Moriond17.
//See distribution in /uscms_data/d3/jmanagan/EffsAndNewWeights/TagEffsM17/BEff.png
//Uses hadronFlavour() rather than partonFlavour() as recommended in BTV physics plenary CMS Week 10/2015

  if(pt < 30)        return 0.403823;
  else if(pt < 50)   return 0.618852;
  else if(pt < 70)   return 0.679287;
  else if(pt < 100)  return 0.706293;
  else if(pt < 140)  return 0.717887;
  else if(pt < 200)  return 0.713093;
  else if(pt < 300)  return 0.670051;
  else if(pt < 400)  return 0.59587; 
  else if(pt < 500)  return 0.531372;
  else if(pt < 600)  return 0.483849;
  else if(pt < 800)  return 0.417429;
  else if(pt < 1000) return 0.30052; 
  else if(pt < 1200) return 0.20051; 
  else return 0.124058;
}

double step1::GetCtagEfficiency(double pt){
  if(pt < 30)        return 0.055637;
  else if(pt < 50)   return 0.089934;
  else if(pt < 70)   return 0.09309;
  else if(pt < 100)  return 0.099994;
  else if(pt < 140)  return 0.108785;
  else if(pt < 200)  return 0.114926;
  else if(pt < 300)  return 0.110015;
  else if(pt < 400)  return 0.093696;
  else if(pt < 500)  return 0.087263;
  else if(pt < 600)  return 0.068838;
  else if(pt < 800)  return 0.047241;
  else if(pt < 1000) return 0.022655;
  else if(pt < 1200) return 0.015532;
  else return 0.008043;
}

double step1::GetMistagRate(double pt){
  // Mistag rates from TT powheg sample for Moriond17.
  //See distribution in /uscms_data/d3/jmanagan/EffsAndNewWeights/TagEffsM17/BEff.png
  //Uses hadronFlavour() rather than partonFlavour() as recommended in BTV physics plenary CMS Week 10/2015

  if(pt < 30)        return 0.00308;
  else if(pt < 50)   return 0.007497;
  else if(pt < 70)   return 0.006558;
  else if(pt < 100)  return 0.006771;
  else if(pt < 140)  return 0.00761;
  else if(pt < 200)  return 0.008422;
  else if(pt < 300)  return 0.009002;
  else if(pt < 400)  return 0.00957;
  else if(pt < 500)  return 0.010041;
  else if(pt < 600)  return 0.00947;
  else if(pt < 800)  return 0.007225;
  else if(pt < 1000) return 0.00395;
  else if(pt < 1200) return 0.002117;
  else return 0.001617;

}

void step1::saveHistograms()
{
  TH1D* numhist = (TH1D*)inputFile->Get("mcweightanalyzer/NumTrueHist");
  TH1D* wgthist = (TH1D*)inputFile->Get("mcweightanalyzer/weightHist");
  outputFile->cd();
  numhist->Write();
  wgthist->Write();
}

// ----------------------------------------------------------------------------
// MAIN EVENT LOOP
// ----------------------------------------------------------------------------

void step1::Loop(TString inTreeName, TString outTreeName) 
{
  
  // ----------------------------------------------------------------------------
  // Turn on input tree branches
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

   inputTree->SetBranchStatus("*",0);

   //Event info

   inputTree->SetBranchStatus("event_CommonCalc",1);
   inputTree->SetBranchStatus("run_CommonCalc",1);
   inputTree->SetBranchStatus("lumi_CommonCalc",1);
   inputTree->SetBranchStatus("nPV_MultiLepCalc",1);
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
   outputTree->Branch("nPV_MultiLepCalc",&nPV_MultiLepCalc,"nPV_MultiLepCalc/I");
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
   outputTree->Branch("pdfWeights4LHC",&pdfWeights4LHC);
   outputTree->Branch("pdfWeightsMSTW",&pdfWeightsMSTW);
   outputTree->Branch("pdfNewWeights",&pdfNewWeights);
   outputTree->Branch("pdfNewNominalWeight",&pdfNewNominalWeight,"pdfNewNominalWeight/F");
   outputTree->Branch("pileupWeight",&pileupWeight,"pileupWeight/F");
   outputTree->Branch("pileupWeightUp",&pileupWeightUp,"pileupWeightUp/F");
   outputTree->Branch("pileupWeightDown",&pileupWeightDown,"pileupWeightDown/F");
   outputTree->Branch("HTSF_Pol",&HTSF_Pol,"HTSF_Pol/F");
   outputTree->Branch("HTSF_PolUp",&HTSF_PolUp,"HTSF_PolUp/F");
   outputTree->Branch("HTSF_PolDn",&HTSF_PolDn,"HTSF_PolDn/F");
   outputTree->Branch("HT_Corr",&HT_Corr,"HT_Corr/F");
   outputTree->Branch("HT_CorrUp",&HT_CorrUp,"HT_CorrUp/F");
   outputTree->Branch("HT_CorrDn",&HT_CorrDn,"HT_CorrDn/F");
   outputTree->Branch("tpt_Corr",&tpt_Corr,"tpt_Corr/F");
   outputTree->Branch("tpt_CorrUp",&tpt_CorrUp,"tpt_CorrUp/F");
   outputTree->Branch("tpt_CorrDn",&tpt_CorrDn,"tpt_CorrDn/F");
   outputTree->Branch("topPtWeight13TeV",&topPtWeight13TeV,"topPtWeight13TeV/F");
   outputTree->Branch("EGammaGsfSF",&EGammaGsfSF,"EGammaGsfSF/F");
   outputTree->Branch("lepIdSF",&lepIdSF,"lepIdSF/F");
   outputTree->Branch("isoSF",&isoSF,"isoSF/F");
   outputTree->Branch("triggSF",&triggSF,"triggSF/F");
   outputTree->Branch("triggSFUncert",&triggSFUncert,"triggSFUncert/F");
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
   

   // Pileup distributions -- Centrally-stored data PU hists 2018 vs 2018 TTToSemiLeptonic
   std::vector<float> pileupweight;
   std::vector<float> pileupweightUp;
   std::vector<float> pileupweightDn;

   pileupweight = { 0.000e+00,  1.250e+01,  5.025e+01,  1.900e+01,  1.197e+01,  9.118e+00,  6.647e+00,  4.832e+00,  3.633e+00,  2.747e+00,  
		    2.238e+00,  1.904e+00,  1.694e+00,  1.572e+00,  1.502e+00,  1.468e+00,  1.451e+00,  1.452e+00,  1.461e+00,  1.467e+00,  
		    1.458e+00,  1.436e+00,  1.401e+00,  1.352e+00,  1.302e+00,  1.250e+00,  1.205e+00,  1.167e+00,  1.138e+00,  1.116e+00,  
		    1.100e+00,  1.089e+00,  1.081e+00,  1.077e+00,  1.074e+00,  1.069e+00,  1.063e+00,  1.052e+00,  1.035e+00,  1.012e+00,  
		    9.794e-01,  9.367e-01,  8.867e-01,  8.272e-01,  7.609e-01,  6.925e-01,  6.209e-01,  5.505e-01,  4.824e-01,  4.193e-01,  
		    3.621e-01,  3.103e-01,  2.658e-01,  2.276e-01,  1.948e-01,  1.679e-01,  1.455e-01,  1.262e-01,  1.098e-01,  9.584e-02,  
		    8.398e-02,  7.342e-02,  6.469e-02,  5.654e-02,  4.900e-02,  4.233e-02,  3.634e-02,  3.081e-02,  2.661e-02,  2.266e-02,  
		    1.889e-02,  1.652e-02,  1.344e-02,  1.173e-02,  9.423e-03,  8.155e-03,  6.671e-03,  5.637e-03,  4.504e-03,  3.920e-03,  
		    3.007e-03,  2.567e-03,  1.909e-03,  1.425e-03,  1.084e-03,  8.974e-04,  8.267e-04,  4.805e-04,  2.814e-04,  1.588e-04,  
		    1.206e-04,  6.816e-05,  2.870e-05,  1.436e-05,  7.136e-06,  4.702e-06,  1.107e-06,  1.723e-06,  1.079e-06,  1.269e-07,  0.000e+00,  }; // TTToSemiLeptonic
   pileupweightDn = { 0.000e+00,  1.447e+01,  5.931e+01,  2.226e+01,  1.397e+01,  1.063e+01,  7.865e+00,  5.773e+00,  4.367e+00,  3.362e+00,  
			2.793e+00,  2.408e+00,  2.153e+00,  1.999e+00,  1.907e+00,  1.857e+00,  1.824e+00,  1.805e+00,  1.789e+00,  1.761e+00,  
			1.710e+00,  1.645e+00,  1.572e+00,  1.493e+00,  1.423e+00,  1.358e+00,  1.306e+00,  1.264e+00,  1.232e+00,  1.206e+00,  
			1.185e+00,  1.166e+00,  1.148e+00,  1.131e+00,  1.111e+00,  1.085e+00,  1.054e+00,  1.014e+00,  9.643e-01,  9.065e-01,  
			8.402e-01,  7.663e-01,  6.892e-01,  6.091e-01,  5.296e-01,  4.550e-01,  3.850e-01,  3.223e-01,  2.671e-01,  2.202e-01,  
			1.810e-01,  1.482e-01,  1.217e-01,  1.003e-01,  8.289e-02,  6.902e-02,  5.780e-02,  4.834e-02,  4.046e-02,  3.384e-02,  
			2.830e-02,  2.351e-02,  1.962e-02,  1.619e-02,  1.322e-02,  1.075e-02,  8.680e-03,  6.919e-03,  5.624e-03,  4.508e-03,  
			3.538e-03,  2.915e-03,  2.233e-03,  1.832e-03,  1.382e-03,  1.121e-03,  8.562e-04,  6.734e-04,  4.991e-04,  4.012e-04,  
			2.833e-04,  2.218e-04,  1.506e-04,  1.023e-04,  7.060e-05,  5.282e-05,  4.385e-05,  2.290e-05,  1.202e-05,  6.059e-06,  
			4.098e-06,  2.061e-06,  7.699e-07,  3.418e-07,  1.507e-07,  8.865e-08,  1.895e-08,  2.792e-08,  1.816e-08,  2.615e-09,  0.000e+00,  }; // TTToSemiLeptonic
   pileupweightUp = { 0.000e+00,  1.091e+01,  4.288e+01,  1.632e+01,  1.032e+01,  7.892e+00,  5.683e+00,  4.086e+00,  3.057e+00,  2.285e+00,  
		      1.826e+00,  1.531e+00,  1.349e+00,  1.249e+00,  1.194e+00,  1.169e+00,  1.161e+00,  1.169e+00,  1.188e+00,  1.211e+00,  
		      1.226e+00,  1.233e+00,  1.230e+00,  1.210e+00,  1.183e+00,  1.147e+00,  1.112e+00,  1.080e+00,  1.053e+00,  1.034e+00,  
		      1.020e+00,  1.013e+00,  1.010e+00,  1.013e+00,  1.018e+00,  1.026e+00,  1.035e+00,  1.044e+00,  1.051e+00,  1.055e+00,  
		      1.054e+00,  1.045e+00,  1.030e+00,  1.004e+00,  9.672e-01,  9.247e-01,  8.727e-01,  8.155e-01,  7.534e-01,  6.903e-01,  
		      6.275e-01,  5.648e-01,  5.067e-01,  4.529e-01,  4.034e-01,  3.604e-01,  3.231e-01,  2.891e-01,  2.595e-01,  2.338e-01,  
		      2.119e-01,  1.921e-01,  1.761e-01,  1.607e-01,  1.459e-01,  1.325e-01,  1.199e-01,  1.073e-01,  9.796e-02,  8.821e-02,  
		      7.775e-02,  7.190e-02,  6.182e-02,  5.697e-02,  4.835e-02,  4.420e-02,  3.822e-02,  3.417e-02,  2.895e-02,  2.677e-02,  
		      2.188e-02,  1.996e-02,  1.591e-02,  1.278e-02,  1.049e-02,  9.408e-03,  9.417e-03,  5.965e-03,  3.820e-03,  2.364e-03,  
		      1.972e-03,  1.229e-03,  5.718e-04,  3.170e-04,  1.748e-04,  1.282e-04,  3.363e-05,  5.837e-05,  4.079e-05,  5.342e-06,  0.000e+00,  }; // TTToSemiLeptonic

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


   // Polynomials for corrections from HT and tpt
   TF1 *polyHT = new TF1("polyHT","min(1.0,max([0] + [1]*x,[2]))",700,5000);
   polyHT->SetParameter(0,     1.09245);
   polyHT->SetParameter(1,-0.000220375);
   polyHT->SetParameter(2,    0.607311);

   TF1 *polyHTU = new TF1("polyHTU","min(1.0,max([0] + [1]*x + sqrt([3] + 2*x*[4] + x*x*[5]),[2] + [6]))",700,5000);
   polyHTU->SetParameter(0,     1.09245);
   polyHTU->SetParameter(1,-0.000220375);
   polyHTU->SetParameter(2,    0.607311);
   polyHTU->SetParameter(3, 0.000531602);
   polyHTU->SetParameter(4,-3.99715e-07);
   polyHTU->SetParameter(5, 3.19837e-10);
   polyHTU->SetParameter(6, 0.000541832);

   TF1 *polyHTD = new TF1("polyHTD","min(1.0,max([0] + [1]*x - sqrt([3] + 2*x*[4] + x*x*[5]),[2] - [6]))",700,5000);
   polyHTD->SetParameter(0,     1.09245);
   polyHTD->SetParameter(1,-0.000220375);
   polyHTD->SetParameter(2,    0.607311);
   polyHTD->SetParameter(3, 0.000531602);
   polyHTD->SetParameter(4,-3.99715e-07);
   polyHTD->SetParameter(5, 3.19837e-10);
   polyHTD->SetParameter(6, 0.000541832);

   TF1 *polytpt = new TF1("polytpt","min([0] + [1]*x,[2] + [3]*x)",20,1000);
   polytpt->SetParameter(0,      1.0887);
   polytpt->SetParameter(1,-0.000283915);
   polytpt->SetParameter(2,     1.28807);
   polytpt->SetParameter(3,-0.000872673);

   TF1 *polytptU = new TF1("polytptU","min([0] + [1]*x + sqrt([4] + 2*x*[5] + x*x*[6]),[2] + [3]*x + sqrt([7] + 2*x*[8] + x*x*[9]))",20,1000);
   polytptU->SetParameter(0,      1.0887);
   polytptU->SetParameter(1,-0.000283915);
   polytptU->SetParameter(2,     1.28807);
   polytptU->SetParameter(3,-0.000872673);
   polytptU->SetParameter(4, 0.000313783);
   polytptU->SetParameter(5,-1.11006e-06);
   polytptU->SetParameter(6, 4.52345e-09);
   polytptU->SetParameter(7, 0.000412213);
   polytptU->SetParameter(8,-6.84715e-07);
   polytptU->SetParameter(9, 1.23876e-09);   

   TF1 *polytptD = new TF1("polytptD","min([0] + [1]*x - sqrt([4] + 2*x*[5] + x*x*[6]),[2] + [3]*x - sqrt([7] + 2*x*[8] + x*x*[9]))",20,1000);
   polytptD->SetParameter(0,      1.0887);
   polytptD->SetParameter(1,-0.000283915);
   polytptD->SetParameter(2,     1.28807);
   polytptD->SetParameter(3,-0.000872673);
   polytptD->SetParameter(4, 0.000313783);
   polytptD->SetParameter(5,-1.11006e-06);
   polytptD->SetParameter(6, 4.52345e-09);
   polytptD->SetParameter(7, 0.000412213);
   polytptD->SetParameter(8,-6.84715e-07);
   polytptD->SetParameter(9, 1.23876e-09);

   
  // ----------------------------------------------------------------------------
  // RUN THE EVENT LOOP
  // ----------------------------------------------------------------------------

   cout << "RUN CONFIG: isMC = " << isMC << endl;
   cout << "isSig = " << isSig << ", SigMass = " << SigMass << endl;
   cout << "For W's: isTT = " << isTT << ", isSTt = " << isSTt << ", isSTtW = " << isSTtW << endl;
   cout << "Fot jets & PDF: isTOP = " << isTOP << ", isMadgraphBkg = " << isMadgraphBkg << endl;
   //   cout << "Pileup index: " << pileupIndex << endl;
   cout << "Shift (Bup,Bdn,Lup,Ldn,None) = (" << isBUp << "," << isBDn << "," << isLUp << "," << isLDn << "," << isNominal << ")" << endl;
   
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

      float confusionTruth = -1;
      
      if(isTTincMtt0to700 && ttbarMass_TTbarMassCalc >= 700.) continue;
      if(isTTincMtt0to1000 && ttbarMass_TTbarMassCalc >= 1000.) continue;
      if(isTTincMtt700to1000 && (ttbarMass_TTbarMassCalc < 700. || ttbarMass_TTbarMassCalc >= 1000.)) continue;
      if(isTTincMtt1000toInf && ttbarMass_TTbarMassCalc < 1000.) continue;
      if(outBWBW && !isBWBW_TpTpCalc) {confusionTruth = 0.5; continue;}
      if(outTZBW && !isTZBW_TpTpCalc) {confusionTruth = 1.5; continue;}
      if(outTHBW && !isTHBW_TpTpCalc) {confusionTruth = 2.5; continue;}
      if(outTZTH && !isTZTH_TpTpCalc) {confusionTruth = 3.5; continue;}
      if(outTZTZ && !isTZTZ_TpTpCalc) {confusionTruth = 4.5; continue;}
      if(outTHTH && !isTHTH_TpTpCalc) {confusionTruth = 5.5; continue;}
      if(outTWTW && !isTWTW_TpTpCalc) {confusionTruth = 6.5; continue;}
      if(outBZTW && !isBZTW_TpTpCalc) {confusionTruth = 7.5; continue;}
      if(outBHTW && !isBHTW_TpTpCalc) {confusionTruth = 8.5; continue;}
      if(outBZBH && !isBZBH_TpTpCalc) {confusionTruth = 9.5; continue;}
      if(outBZBZ && !isBZBZ_TpTpCalc) {confusionTruth = 10.5; continue;}
      if(outBHBH && !isBHBH_TpTpCalc) {confusionTruth = 11.5; continue;}

      if(isSig){
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
	if(nTrueInteractions_MultiLepCalc > 99) nTrueInteractions_MultiLepCalc = 99;
	if(nTrueInteractions_MultiLepCalc < 0) nTrueInteractions_MultiLepCalc = 0;
	pileupWeight = pileupweight[nTrueInteractions_MultiLepCalc];
	pileupWeightUp = pileupweightUp[nTrueInteractions_MultiLepCalc];
	pileupWeightDown = pileupweightDn[nTrueInteractions_MultiLepCalc];
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
      triggSF = 1.0;
      triggSFUncert = 0.0;
      isoSF = 1.0;
      muPtSF = 1.0;

      if(isMC){ //MC triggers check
	if(isElectron){
	  std::string string_a = "Ele15_IsoVVVL_PFHT450";
	  std::string string_b = "Ele15_IsoVVVL_PFHT450_PFMET50";
	  std::string string_c = "Ele50_IsoVVVL_PFHT450";
	  std::string string_d = "Ele15_IsoVVVL_PFHT600";
	  std::string string_ORa = "Ele35_WPTight_Gsf";
	  std::string string_ORb = "Ele38_WPTight_Gsf";
	  for(unsigned int itrig=0; itrig < vsSelMCTriggersEl_MultiLepCalc->size(); itrig++){
	    if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find(string_a) != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
//	    if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find(string_b) != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
            if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find(string_c) != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
            if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find(string_d) != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find(string_ORa) != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	  }

	  // JH update 10/27/20: Gsf Tracking scale factor https://indico.cern.ch/event/794628/contributions/3303043/attachments/1791305/2923400/RECOSFs_0208_update.pdf
	  if (leppt < 45) {
	    if (lepeta < -2.0) EGammaGsfSF = 0.987;
	    else if (lepeta < -1.566) EGammaGsfSF = 0.987;
	    else if (lepeta < -1.442) EGammaGsfSF = 0.986;
	    else if (lepeta < -1.0) EGammaGsfSF = 0.988;
	    else if (lepeta < -0.5) EGammaGsfSF = 0.992;
            else if (lepeta < 0.0) EGammaGsfSF = 0.990;
	    else if (lepeta < 0.5) EGammaGsfSF = 0.997;
	    else if (lepeta < 1.0) EGammaGsfSF = 0.999;
	    else if (lepeta < 1.442) EGammaGsfSF = 0.988;
	    else if (lepeta < 1.556) EGammaGsfSF = 0.973;
	    else if (lepeta < 2.0) EGammaGsfSF = 0.988;
	    else EGammaGsfSF = 0.984; }
	  else if (leppt < 75) {
	    if (lepeta < -2.0) EGammaGsfSF = 0.988;
	    else if (lepeta < -1.556) EGammaGsfSF = 0.989;
	    else if (lepeta < -1.442) EGammaGsfSF = 0.968;
	    else if (lepeta < -1.0) EGammaGsfSF = 0.990;
            else if (lepeta < -0.5) EGammaGsfSF = 0.990;
	    else if (lepeta < 0.0) EGammaGsfSF = 0.990;
	    else if (lepeta < 0.5) EGammaGsfSF = 0.997;
	    else if (lepeta < 1.0) EGammaGsfSF = 0.998;
	    else if (lepeta < 1.442) EGammaGsfSF = 0.990;
	    else if (lepeta < 1.566) EGammaGsfSF = 0.980;
	    else if (lepeta < 2.0) EGammaGsfSF = 0.991;
	    else EGammaGsfSF = 0.988; }
	  else if (leppt < 100) {
            if (lepeta < -2.0) EGammaGsfSF = 1.002;
	    else if (lepeta < -1.566) EGammaGsfSF = 1.018;
	    else if (lepeta < -1.442) EGammaGsfSF = 1.044;
	    else if (lepeta < -1.0) EGammaGsfSF = 1.008;
            else if (lepeta < -0.5) EGammaGsfSF = 1.008;
            else if (lepeta < 0.0) EGammaGsfSF = 1.003;
            else if (lepeta < 0.5) EGammaGsfSF = 1.022;
	    else if (lepeta < 1.0) EGammaGsfSF = 1.019;
	    else if (lepeta < 1.442) EGammaGsfSF = 1.010;
	    else if (lepeta < 1.566) EGammaGsfSF = 1.035;
            else if (lepeta < 2.0) EGammaGsfSF = 1.010;
	    else EGammaGsfSF = 1.007; }
	  else {
            if (lepeta < -2.0) EGammaGsfSF = 0.984;
	    else if (lepeta < -1.566) EGammaGsfSF = 0.998;
	    else if (lepeta < -1.442) EGammaGsfSF = 1.037;
	    else if (lepeta < -1.0) EGammaGsfSF = 1.007;
	    else if (lepeta < -0.5) EGammaGsfSF = 1.006;
            else if (lepeta < 0.0) EGammaGsfSF = 1.003;
	    else if (lepeta < 0.5) EGammaGsfSF = 1.003;
	    else if (lepeta < 1.0) EGammaGsfSF = 1.006;
	    else if (lepeta < 1.442) EGammaGsfSF = 1.007;
	    else if (lepeta < 1.566) EGammaGsfSF = 1.037;
	    else if (lepeta < 2.0) EGammaGsfSF = 0.998;
	    else EGammaGsfSF = 0.984; }

          //JH update 10/27/2020: Electron ID SF https://twiki.cern.ch/twiki/pub/CMS/EgammaIDRecipesRun2/2018_ElectronMVA90noiso_2D_r1.pdf  (_r1 not there before!) 
	  if (leppt < 50) {
	    if (lepeta < -2.0) lepIdSF = 0.994;
	    else if (lepeta < -1.566) lepIdSF = 0.969;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.978;
	    else if (lepeta < 0.0) lepIdSF = 0.979;
	    else if (lepeta < 0.8) lepIdSF = 0.978;
	    else if (lepeta < 1.442) lepIdSF = 0.978;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.969;
	    else lepIdSF = 0.993; }
	  else if (leppt < 100) {
	    if (lepeta < -2.0) lepIdSF = 0.989;
	    else if (lepeta < -1.566) lepIdSF = 0.976;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.977;
	    else if (lepeta < 0.0) lepIdSF = 0.978;
	    else if (lepeta < 0.8) lepIdSF = 0.979;
	    else if (lepeta < 1.442) lepIdSF = 0.975;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.977;
	    else lepIdSF = 0.975; }
	  else if (leppt < 200) {
	    if (lepeta < -2.0) lepIdSF = 0.983;
	    else if (lepeta < -1.566) lepIdSF = 0.982;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.985;
	    else if (lepeta < 0.0) lepIdSF = 0.985;
	    else if (lepeta < 0.8) lepIdSF = 0.977;
	    else if (lepeta < 1.442) lepIdSF = 1.000;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.972;
	    else lepIdSF = 0.988; }
	  else {
	    if (lepeta < -2.0) lepIdSF = 0.953;
	    else if (lepeta < -1.566) lepIdSF = 0.966;
	    else if (lepeta < -1.442) lepIdSF = 1.000;
	    else if (lepeta < -0.8) lepIdSF = 0.998;
	    else if (lepeta < 0.0) lepIdSF = 1.007;
	    else if (lepeta < 0.8) lepIdSF = 0.966;
	    else if (lepeta < 1.442) lepIdSF = 0.966;
	    else if (lepeta < 1.566) lepIdSF = 1.000;
	    else if (lepeta < 2.0) lepIdSF = 0.974;
	    else lepIdSF = 1.014; }

	  // mini isolation scale factors: https://wiwong.web.cern.ch/wiwong/Ele_Eff_Plots/2018passingMiniIsoTight_updated/egammaEffi.txt_egammaPlots.pdf
	  if (leppt < 20){
            if (fabs(lepeta) < -2.0) isoSF = 1.039;
            else if (fabs(lepeta) < -1.566) isoSF = 1.026;
            else if (fabs(lepeta) < -1.442) isoSF = 1.115;
            else if (fabs(lepeta) < -0.8) isoSF = 0.998;
            else if (fabs(lepeta) < 0.0) isoSF = 0.996;
            else if (fabs(lepeta) < 0.8) isoSF = 0.996;
            else if (fabs(lepeta) < 1.442) isoSF = 0.998;
            else if (fabs(lepeta) < 1.566) isoSF = 1.115;
            else if (fabs(lepeta) < 2.0) isoSF = 1.026;
            else isoSF = 1.039;}
          else if (leppt < 40){
            if (fabs(lepeta) < -2.0) isoSF = 1.019;
            else if (fabs(lepeta) < -1.566) isoSF = 1.011;
            else if (fabs(lepeta) < -1.442) isoSF = 1.045;
            else if (fabs(lepeta) < -0.8) isoSF = 1.000;
            else if (fabs(lepeta) < 0.0) isoSF = 0.997;
            else if (fabs(lepeta) < 0.8) isoSF = 0.997;
            else if (fabs(lepeta) < 1.442) isoSF = 1.000;
            else if (fabs(lepeta) < 1.566) isoSF = 1.045;
            else if (fabs(lepeta) < 2.0) isoSF = 1.011;
            else isoSF = 1.019;}
          else if (leppt < 50){
            if (fabs(lepeta) < -2.0) isoSF = 1.010;
            else if (fabs(lepeta) < -1.566) isoSF = 1.006;
            else if (fabs(lepeta) < -1.442) isoSF = 1.024;
            else if (fabs(lepeta) < -0.8) isoSF = 0.998;
            else if (fabs(lepeta) < 0.0) isoSF = 0.998;
            else if (fabs(lepeta) < 0.8) isoSF = 0.998;
            else if (fabs(lepeta) < 1.442) isoSF = 0.998;
            else if (fabs(lepeta) < 1.566) isoSF = 1.024;
            else if (fabs(lepeta) < 2.0) isoSF = 1.006;
            else isoSF = 1.010;}
          else if (leppt < 60){
            if (fabs(lepeta) < -2.0) isoSF = 1.008;
            else if (fabs(lepeta) < -1.566) isoSF = 1.003;
            else if (fabs(lepeta) < -1.442) isoSF = 1.035;
            else if (fabs(lepeta) < -0.8) isoSF = 0.999;
            else if (fabs(lepeta) < 0.0) isoSF = 0.999;
            else if (fabs(lepeta) < 0.8) isoSF = 0.999;
            else if (fabs(lepeta) < 1.442) isoSF = 0.999;
            else if (fabs(lepeta) < 1.566) isoSF = 1.035;
            else if (fabs(lepeta) < 2.0) isoSF = 1.003;
            else isoSF = 1.008;}
          else if (leppt < 100){
            if (fabs(lepeta) < -2.0) isoSF = 1.001;
            else if (fabs(lepeta) < -1.566) isoSF = 1.000;
            else if (fabs(lepeta) < -1.442) isoSF = 1.032;
            else if (fabs(lepeta) < -0.8) isoSF = 1.000;
            else if (fabs(lepeta) < 0.0) isoSF = 1.000;
            else if (fabs(lepeta) < 0.8) isoSF = 1.000;
            else if (fabs(lepeta) < 1.442) isoSF = 1.000;
            else if (fabs(lepeta) < 1.566) isoSF = 1.032;
            else if (fabs(lepeta) < 2.0) isoSF = 1.000;
            else isoSF = 1.001;}
           else if (leppt < 200){
            if (fabs(lepeta) < -2.0) isoSF = 1.003;
            else if (fabs(lepeta) < -1.566) isoSF = 1.001;
            else if (fabs(lepeta) < -1.442) isoSF = 1.018;
            else if (fabs(lepeta) < -0.8) isoSF = 1.002;
            else if (fabs(lepeta) < 0.0) isoSF = 1.001;
            else if (fabs(lepeta) < 0.8) isoSF = 1.001;
            else if (fabs(lepeta) < 1.442) isoSF = 1.002;
            else if (fabs(lepeta) < 1.566) isoSF = 1.018;
            else if (fabs(lepeta) < 2.0) isoSF = 1.001;
            else isoSF = 1.003;}
          else{
            if (fabs(lepeta) < -2.0) isoSF = 1.003;
            else if (fabs(lepeta) < -1.566) isoSF = 1.001;
            else if (fabs(lepeta) < -1.442) isoSF = 0.999;
            else if (fabs(lepeta) < -0.8) isoSF = 0.999;
            else if (fabs(lepeta) < 0.0) isoSF = 1.000;
            else if (fabs(lepeta) < 0.8) isoSF = 1.000;
            else if (fabs(lepeta) < 1.442) isoSF = 0.999;
            else if (fabs(lepeta) < 1.566) isoSF = 0.999;
            else if (fabs(lepeta) < 2) isoSF = 1.001;
            else isoSF = 1.003;}

          //Trigger SF calculated by JHogan, HT > 430, ttbar tag/probe, Id+iso applied
          if (fabs(lepeta) < 0.8){
	    if (leppt < 30) {triggSF = 0.924; triggSFUncert = 0.025;}
	    else if (leppt < 40) {triggSF = 1.030; triggSFUncert = 0.018;}
            else if (leppt < 50) {triggSF = 1.033; triggSFUncert = 0.015;}
            else if (leppt < 60) {triggSF = 1.029; triggSFUncert = 0.014;}
            else if (leppt < 70) {triggSF = 1.001; triggSFUncert = 0.014;}
            else if (leppt < 100) {triggSF = 1.001; triggSFUncert = 0.010;}
            else if (leppt < 200) {triggSF = 0.980; triggSFUncert = 0.010;}
            else {triggSF = 0.983; triggSFUncert = 0.013;}
	  }
          else if (fabs(lepeta) < 1.442){
	    if (leppt < 30) {triggSF = 0.929; triggSFUncert = 0.037;}
            else if (leppt < 40) {triggSF = 1.057; triggSFUncert = 0.025;}
            else if (leppt < 50) {triggSF = 1.076; triggSFUncert = 0.023;}
            else if (leppt < 60) {triggSF = 1.035; triggSFUncert = 0.020;}
            else if (leppt < 70) {triggSF = 1.023; triggSFUncert = 0.021;}
            else if (leppt < 100) {triggSF = 1.010; triggSFUncert = 0.013;}
            else if (leppt < 200) {triggSF = 1.002; triggSFUncert = 0.010;}
            else {triggSF = 0.982; triggSFUncert = 0.021;}
       	  }
          else if (fabs(lepeta) < 1.556) {
 	    if (leppt < 30) {triggSF = 0.673; triggSFUncert = 0.171;}
            else if (leppt < 40) {triggSF = 1.197; triggSFUncert = 0.116;}
            else if (leppt < 50) {triggSF = 1.143; triggSFUncert = 0.087;}
            else if (leppt < 60) {triggSF = 0.928; triggSFUncert = 0.092;}
            else if (leppt < 70) {triggSF = 1.082; triggSFUncert = 0.076;}
            else if (leppt < 100) {triggSF = 0.951; triggSFUncert = 0.054;}
            else if (leppt < 200) {triggSF = 1.016; triggSFUncert = 0.029;}
            else {triggSF = 0.978; triggSFUncert = 0.062;}
	  }
          else if (fabs(lepeta) < 2.0){ 
	    if (leppt < 30) {triggSF = 0.827; triggSFUncert = 0.073;}
            else if (leppt < 40) {triggSF = 0.976; triggSFUncert = 0.052;}
            else if (leppt < 50) {triggSF = 1.114; triggSFUncert = 0.042;}
            else if (leppt < 60) {triggSF = 1.099; triggSFUncert = 0.041;}
            else if (leppt < 70) {triggSF = 1.030; triggSFUncert = 0.040;}
            else if (leppt < 100) {triggSF = 0.990; triggSFUncert = 0.032;}
            else if (leppt < 200) {triggSF = 1.028; triggSFUncert = 0.022;}
            else {triggSF = 0.948; triggSFUncert = 0.058;}
          }	  
          else{ 
            if (leppt < 30) {triggSF = 1.047; triggSFUncert = 0.093;}
            else if (leppt < 40) {triggSF = 1.150; triggSFUncert = 0.080;}
            else if (leppt < 50) {triggSF = 1.094; triggSFUncert = 0.061;}
            else if (leppt < 60) {triggSF = 1.063; triggSFUncert = 0.060;}
            else if (leppt < 70) {triggSF = 1.073; triggSFUncert = 0.058;}
            else if (leppt < 100) {triggSF = 1.005; triggSFUncert = 0.039;}
            else if (leppt < 200) {triggSF = 0.978; triggSFUncert = 0.041;}
            else {triggSF = 1.103; triggSFUncert = 0.035;}
         }
        }	  
          
	if(isMuon){
	  std::string string_a = "Mu15_IsoVVVL_PFHT450";
	  std::string string_b = "Mu15_IsoVVVL_PFHT450_PFMET50";
	  std::string string_d = "Mu50_IsoVVVL_PFHT450";
	  std::string string_e = "Mu15_IsoVVVL_PFHT600";
	  std::string string_ORb = "Mu50";
	  std::string string_ORc = "TkMu50";
	  for(unsigned int itrig=0; itrig < vsSelMCTriggersMu_MultiLepCalc->size(); itrig++){
	    if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find(string_a) != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
      //	    if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find(string_b) != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
            if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find(string_d) != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
            if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find(string_e) != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find(string_ORc) != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	  }

	  // isGlobal SF from 2016 analysis task force
	  if(lepton_lv.P() > 100 && fabs(lepeta) < 1.6) muPtSF = (0.9828 - 1.947e-5*lepton_lv.P())/(0.989 - 2.399e-6*lepton_lv.P());
	  else if(lepton_lv.P() > 275 && fabs(lepeta) > 1.6) muPtSF = (0.9893 - 3.666e-5*lepton_lv.P())/(0.9974 - 1.721e-5*lepton_lv.Pt());

	  //Miniisolation SF, Jess Wong approved in MUO 8/26/19, slide 38 upper left
          if(leppt < 30){ // 25-30
           if(fabs(lepeta) < 0.9) isoSF= 0.9925;
            else if(fabs(lepeta) <  1.2) isoSF= 0.9932;
            else if(fabs(lepeta) <  2.1) isoSF= 1.0124;
            else isoSF= 1.0202;
          }
          else if(leppt < 40){
            if(fabs(lepeta) < 0.9) isoSF= 0.9959;
            else if(fabs(lepeta) <  1.2) isoSF= 0.9957;
            else if(fabs(lepeta) <  2.1) isoSF= 1.0076;
            else isoSF= 1.0101;
          }
          else if(leppt < 50){
            if(fabs(lepeta) < 0.9) isoSF= 0.9981;
            else if(fabs(lepeta) <  1.2) isoSF= 0.9978;
            else if(fabs(lepeta) <  2.1) isoSF= 1.0040;
            else isoSF= 1.0059;
          }
          else if(leppt < 60){
            if(fabs(lepeta) < 0.9) isoSF= 0.9989;
            else if(fabs(lepeta) <  1.2) isoSF= 0.9982;
            else if(fabs(lepeta) <  2.1) isoSF= 1.0019;
            else isoSF= 1.0029;
          }
          else if(leppt < 120){
            if(fabs(lepeta) < 0.9) isoSF= 0.9997;
            else if(fabs(lepeta) <  1.2) isoSF= 0.9995;
            else if(fabs(lepeta) <  2.1) isoSF= 1.0001;
            else isoSF= 1.0003;
          }
          else{ //120-200, ignoring 200-300 for low stats
           if(fabs(lepeta) < 0.9) isoSF= 1.0000;
            else if(fabs(lepeta) <  1.2) isoSF= 1.0016;
            else if(fabs(lepeta) <  2.1) isoSF= 0.9983;
            else isoSF= 1.0000;
          }
            
          //cut based tight id: https://gitlab.cern.ch/cms-muonPOG/MuonReferenceEfficiencies/blob/master/EfficienciesStudies/2018/jsonfiles/RunABCD_SF_ID.json
	  if (fabs(lepeta) > 0.00 && fabs(lepeta) < 0.90) {
	    if (leppt >20.00 && leppt < 25.00) lepIdSF = 0.9913892461286353;
            else if (leppt > 25.00 && leppt < 30.00) lepIdSF = 0.991434774563006;
            else if (leppt > 30.00 && leppt < 40.00) lepIdSF = 0.99137555469275;
            else if (leppt > 40.00 && leppt < 50.00) lepIdSF = 0.9914412620030336;
            else if (leppt > 50.00 && leppt < 60.00) lepIdSF = 0.9916861853024751;
            else {lepIdSF = 0.9905799448514033;}  
          }
          else if (fabs(lepeta) > 0.90 && fabs(lepeta) < 1.20) {
            if (leppt >20.00 && leppt < 25.00) lepIdSF = 0.985987369423937;
            else if (leppt > 25.00 && leppt < 30.00) lepIdSF = 0.983987818122965;
            else if (leppt > 30.00 && leppt < 40.00) lepIdSF = 0.983823809537526;
            else if (leppt > 40.00 && leppt < 50.00) lepIdSF = 0.9842166496308641;
            else if (leppt > 50.00 && leppt < 60.00) lepIdSF = 0.9830003119378048;
            else {lepIdSF = 0.9816888807775153;}
          }
          else if (fabs(lepeta) > 1.20 && fabs(lepeta) < 2.10) {
            if (leppt >20.00 && leppt < 25.00) lepIdSF = 0.991472765372932;
            else if (leppt > 25.00 && leppt < 30.00) lepIdSF = 0.991184702552688;
            else if (leppt > 30.00 && leppt < 40.00) lepIdSF = 0.9907979966866818;
            else if (leppt > 40.00 && leppt < 50.00) lepIdSF = 0.98999331286624;
            else if (leppt > 50.00 && leppt < 60.00) lepIdSF = 0.9907796746368196;
            else {lepIdSF = 0.9886366722532979;}
          }
          else{
            if (leppt >20.00 && leppt < 25.00) lepIdSF = 0.9762336613870103;
            else if (leppt > 25.00 && leppt < 30.00) lepIdSF = 0.9735941110201962;
            else if (leppt > 30.00 && leppt < 40.00) lepIdSF = 0.973964994647057;
            else if (leppt > 40.00 && leppt < 50.00) lepIdSF = 0.9738877279555861;
            else if (leppt > 50.00 && leppt < 60.00) lepIdSF = 0.9737076412350453;
            else {lepIdSF = 0.9677501192438909;}
          }
          
          if (fabs(lepeta) < 0.9){
	    if (leppt < 30) {triggSF = 0.995; triggSFUncert = 0.014;}
            else if (leppt < 40) {triggSF = 1.047; triggSFUncert = 0.013;} 
            else if (leppt < 50) {triggSF = 1.050; triggSFUncert = 0.012;}
            else if (leppt < 60) {triggSF = 1.019; triggSFUncert = 0.009;}
            else if (leppt < 70) {triggSF = 1.035; triggSFUncert = 0.007;}
            else if (leppt < 100) {triggSF = 0.997; triggSFUncert = 0.007;}
            else if (leppt < 200) {triggSF = 0.989; triggSFUncert = 0.007;}
            else {triggSF = 0.960; triggSFUncert = 0.021;}
          }	  
          else if (fabs(lepeta) < 1.2){ 
            if (leppt < 30) {triggSF = 0.944; triggSFUncert = 0.030;}
            else if (leppt < 40) {triggSF = 1.017; triggSFUncert = 0.022;}
            else if (leppt < 50) {triggSF = 0.986; triggSFUncert = 0.024;}
            else if (leppt < 60) {triggSF = 0.987; triggSFUncert = 0.016;}
            else if (leppt < 70) {triggSF = 0.988; triggSFUncert = 0.018;}
            else if (leppt < 100) {triggSF = 0.982; triggSFUncert = 0.013;}
            else if (leppt < 200) {triggSF = 0.983; triggSFUncert = 0.012;}
            else {triggSF = 0.997; triggSFUncert = 0.021;}
          }
          else if (fabs(lepeta) < 2.1){ 
            if (leppt < 30) {triggSF = 0.989; triggSFUncert = 0.021;}
            else if (leppt < 40) {triggSF = 1.041; triggSFUncert = 0.018;}
            else if (leppt < 50) {triggSF = 1.050; triggSFUncert = 0.020;}
            else if (leppt < 60) {triggSF = 1.033; triggSFUncert = 0.012;}
            else if (leppt < 70) {triggSF = 0.981; triggSFUncert = 0.018;}
            else if (leppt < 100) {triggSF = 1.008; triggSFUncert = 0.009;}
            else if (leppt < 200) {triggSF = 1.001; triggSFUncert = 0.010;}
            else {triggSF = 0.938; triggSFUncert = 0.045;}
          }	  
          else{
            if (leppt < 30) {triggSF = 0.964; triggSFUncert = 0.078;}
            else if (leppt < 40) {triggSF = 1.069; triggSFUncert = 0.066;}
            else if (leppt < 50) {triggSF = 1.088; triggSFUncert = 0.053;}
            else if (leppt < 60) {triggSF = 1.067; triggSFUncert = 0.055;}
            else if (leppt < 70) {triggSF = 1.017; triggSFUncert = 0.055;}
            else if (leppt < 100) {triggSF = 1.128; triggSFUncert = 0.020;}
            else if (leppt < 200) {triggSF = 0.958; triggSFUncert = 0.067;}
            else {triggSF = 1.066; triggSFUncert = 0.042;}
         }	  
          
	}
	DataPastTrigger = 1;
      }
      else{ //Data triggers check
	if(isElectron){
	  std::string string_a = "Ele15_IsoVVVL_PFHT450";
	  std::string string_b = "Ele15_IsoVVVL_PFHT450_PFMET50";
	  std::string string_c = "Ele50_IsoVVVL_PFHT450";
	  std::string string_d = "Ele15_IsoVVVL_PFHT600";
	  std::string string_ORa = "Ele35_WPTight_Gsf";
	  std::string string_ORb = "Ele38_WPTight_Gsf";
	  for(unsigned int itrig=0; itrig < vsSelTriggersEl_MultiLepCalc->size(); itrig++){
	    if(vsSelTriggersEl_MultiLepCalc->at(itrig).find(string_a) != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	  //  if(vsSelTriggersEl_MultiLepCalc->at(itrig).find(string_b) != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
            if(vsSelTriggersEl_MultiLepCalc->at(itrig).find(string_c) != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
            if(vsSelTriggersEl_MultiLepCalc->at(itrig).find(string_d) != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersEl_MultiLepCalc->at(itrig).find(string_ORa) != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersEl_MultiLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	  }
	}



	if(isMuon){
	  std::string string_a = "Mu15_IsoVVVL_PFHT450";
	  std::string string_b = "Mu15_IsoVVVL_PFHT450_PFMET50";
	  std::string string_d = "Mu50_IsoVVVL_PFHT450";
	  std::string string_e = "Mu15_IsoVVVL_PFHT600";
	  std::string string_ORb = "Mu50";
	  std::string string_ORc = "TkMu50";
	  for(unsigned int itrig=0; itrig < vsSelTriggersMu_MultiLepCalc->size(); itrig++){
	    if(vsSelTriggersMu_MultiLepCalc->at(itrig).find(string_a) != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	 //   if(vsSelTriggersMu_MultiLepCalc->at(itrig).find(string_b) != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
            if(vsSelTriggersMu_MultiLepCalc->at(itrig).find(string_d) != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
            if(vsSelTriggersMu_MultiLepCalc->at(itrig).find(string_e) != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersMu_MultiLepCalc->at(itrig).find(string_ORb) != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    if(vsSelTriggersMu_MultiLepCalc->at(itrig).find(string_ORc) != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
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
	bool istagged = AK4JetDeepCSVb_MultiLepCalc->at(ijet) + AK4JetDeepCSVbb_MultiLepCalc->at(ijet) > 0.4184;

	double ijetPt = theJetPt_JetSubCalc->at(ijet);
	double ijetEta= theJetEta_JetSubCalc->at(ijet);
	double ijetPhi= theJetPhi_JetSubCalc->at(ijet);
   
	float multiplier = 1;
	if(ijetPt>1000) multiplier = 2;

	if(theJetHFlav_JetSubCalc->at(ijet) == 5){//b-quarks
	  double heavySF   = GetBtagSF2018Medium_comb(central, ijetPt, ijetEta);
	  if(isBUp) heavySF += GetBtagSF2018Medium_comb(uncert, ijetPt, ijetEta);
	  else if(isBDn) heavySF -= GetBtagSF2018Medium_comb(uncert, ijetPt, ijetEta);
	  double heavyEff  = GetBtagEfficiency(ijetPt);

	  theJetBTagDeepCSV.push_back(applySF(istagged,heavySF,heavyEff,ijetPhi));
  
	}else if(theJetHFlav_JetSubCalc->at(ijet) == 4){//c-quarks
	  double heavySF   = GetCtagSF2018Medium_comb(central, ijetPt, ijetEta);
	  if(isBUp) heavySF += GetCtagSF2018Medium_comb(uncert, ijetPt, ijetEta);
	  else if(isBDn) heavySF -= GetCtagSF2018Medium_comb(uncert, ijetPt, ijetEta);
	  double heavyEff  = GetCtagEfficiency(ijetPt);

	  theJetBTagDeepCSV.push_back(applySF(istagged,heavySF,heavyEff,ijetPhi));

	}else{//udsg-quarks
	  double lightSF   = GetLFSF2018Medium(central, ijetPt, ijetEta);
	  if(isLUp) lightSF += GetLFSF2018Medium(uncert, ijetPt, ijetEta);
	  else if(isLUp) lightSF -= GetLFSF2018Medium(uncert, ijetPt, ijetEta);
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

      if(isSig){
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

	// 2018 values for the Medium WPs
   	if(AK4JetDeepCSVb_MultiLepCalc_PtOrdered.at(ijet) + AK4JetDeepCSVbb_MultiLepCalc_PtOrdered.at(ijet) > 0.4184){
          NJetsDeepCSV_JetSubCalc += 1;
        }
	if(AK4JetDeepFlavb_MultiLepCalc_PtOrdered.at(ijet) + AK4JetDeepFlavbb_MultiLepCalc_PtOrdered.at(ijet) +
	   AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered.at(ijet) > 0.2770) NJetsDeepFlav_JetSubCalc += 1;

	// This one is already computed bSFup/dn, lSFup/dn as needed above.
	if(theJetBTagDeepCSV_JetSubCalc_PtOrdered.at(ijet) == 1) NJetsDeepCSVwithSF_JetSubCalc += 1;

	// 2/28: For now...banking on the idea that DeepFlav SFs are ok to 1-2 b's, should be enough for leptonic top
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
	    if(isTmatched) DeepAK8SF_TeffUp += 0.25;
	    else DeepAK8SF_TmisUp += 0.25;
	  }
	  else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 2){
	    if(isHmatched) DeepAK8SF_HeffUp += 0.25;
	    else DeepAK8SF_HmisUp += 0.25;
	  }
	  else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 3){
	    if(isZmatched) DeepAK8SF_ZeffUp += 0.25;
	    else DeepAK8SF_ZmisUp += 0.25;
	  }
	  else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 4){
	    if(isWmatched) DeepAK8SF_WeffUp += 0.25;
	    else DeepAK8SF_WmisUp += 0.25;
	  }
	  else if (dnn_largest_DeepAK8Calc_PtOrdered.at(ijet) == 5){
	    if(isBmatched) DeepAK8SF_BeffUp += 0.25;
	    else DeepAK8SF_BmisUp += 0.25;
	  }
	  else{
	    if(isJmatched) DeepAK8SF_JeffUp += 0.25;
	    else DeepAK8SF_JmisUp += 0.25;
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
      // Evaluate the VLQ / ttbar / WJets DNN
      // ----------------------------------------------------------------------------


      myMapTT = {
	{"Wjets",  -999},
	{"ttbar",  -999},
	{"Tprime",-999},
      };
      
      varMapTT = {
	{"corr_met_MultiLepCalc", -999}, //update with TT variables X
	{"AK4HTpMETpLepPt", -999},
	{"AK4HT", -999},
	{"NJets_JetSubCalc", -999},
	{"NJetsAK8_JetSubCalc", -999},
	{"minDR_leadAK8otherAK8", -999},
	{"nH_DeepAK8", -999},
	{"nT_DeepAK8", -999},
	{"jetPt_1", -999},
	{"jetPt_2", -999},
	{"jetPt_3", -999},
	{"sdMass_1", -999},
	{"sdMass_2", -999},
	{"sdMass_3", -999},
	{"dnnLargest_2", -999},
	{"dnnLargest_3", -999},
	{"dnnJ_1", -999},
	{"dnnJ_2", -999},
	{"dnnJ_3", -999},
      };

      myMapBB = {
	{"WjetsBB",  -999},
	{"ttbarBB",  -999},
	{"Bprime",-999},
      };
    
      varMapBB = {
	{"corr_met_MultiLepCalc", -999}, //update with BB variables X
	{"AK4HTpMETpLepPt", -999},
	{"AK4HT", -999},
	{"NJets_JetSubCalc", -999},
	{"NJetsAK8_JetSubCalc", -999},
	{"minDR_leadAK8otherAK8", -999},
	{"nH_DeepAK8", -999},
	{"nT_DeepAK8", -999},
	{"nW_DeepAK8", -999},
	{"jetPt_1", -999},
	{"jetPt_2", -999},
	{"jetPt_3", -999},
        {"sdMass_1", -999},
        {"sdMass_2", -999},
        {"sdMass_3", -999},
        {"tau21_3", -999},
	{"dnnLargest_1", -999},
	{"dnnLargest_2", -999},
	{"dnnLargest_3", -999},
	{"dnnJ_1", -999},
	{"dnnJ_2", -999},
	{"dnnJ_3", -999},
        {"dnnH_1", -999},
        {"dnnH_2", -999},
        {"dnnH_3", -999},
        {"dnnT_1", -999},
        {"dnnT_2", -999},
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
	float dnnLargest_1, dnnLargest_2, dnnLargest_3;
	float dnnJ_1, dnnJ_2, dnnJ_3;
	float dnnT_1, dnnT_2, dnnT_3;
        float dnnH_1, dnnH_2, dnnH_3;
	float tau21_3;


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
	
	dnnH_1 = dnn_H_DeepAK8Calc_PtOrdered.at(0);
	dnnH_2 = dnn_H_DeepAK8Calc_PtOrdered.at(1);
	if(NJetsAK8_JetSubCalc > 2) dnnH_3 = dnn_H_DeepAK8Calc_PtOrdered.at(2);
	else dnnH_3 = -9;

	dnnT_1 = dnn_T_DeepAK8Calc_PtOrdered.at(0);
	dnnT_2 = dnn_T_DeepAK8Calc_PtOrdered.at(1);
	//if(NJetsAK8_JetSubCalc > 2) dnnT_3 = dnn_T_DeepAK8Calc_PtOrdered.at(2);
	//else dnnT_3 = -9;
	
	//tau21_1 = theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.at(0)/theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.at(0);
	//tau21_2 = theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.at(1)/theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.at(1);
	if(NJetsAK8_JetSubCalc > 2) tau21_3 = theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.at(2)/theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.at(2);
	else tau21_3 = 1;

	dnnLargest_1 = dnn_largest_DeepAK8Calc_PtOrdered.at(0);
	//dnnLargest_2 = dnn_largest_DeepAK8Calc_PtOrdered.at(1);
	//if(NJetsAK8_JetSubCalc > 2) dnnLargest_3 = dnn_largest_DeepAK8Calc_PtOrdered.at(2);
	//else dnnLargest_3 = 10;

	varMapTT = { //update with TT vars
	  {"corr_met_MultiLepCalc", corr_met_MultiLepCalc}, //update with TT variables X
	  {"AK4HTpMETpLepPt", AK4HTpMETpLepPt},
	  {"AK4HT", AK4HT},
	  {"NJets_JetSubCalc", NJets_JetSubCalc},
	  {"NJetsAK8_JetSubCalc", NJetsAK8_JetSubCalc},
	  {"minDR_leadAK8otherAK8", minDR_leadAK8otherAK8},
	  {"nH_DeepAK8", nH_DeepAK8},
	  {"nT_DeepAK8", nT_DeepAK8},
	  {"jetPt_1", jetPt_1},
	  {"jetPt_2", jetPt_2},
	  {"jetPt_3", jetPt_3},
	  {"sdMass_1", sdMass_1},
	  {"sdMass_2", sdMass_2},
	  {"sdMass_3", sdMass_3},
	  {"dnnLargest_2", dnnLargest_2},
	  {"dnnLargest_3", dnnLargest_3},
	  {"dnnJ_1", dnnJ_1},
	  {"dnnJ_2", dnnJ_2},
	  {"dnnJ_3", dnnJ_3},
	};
	
	varMapBB = { //update with BB vars
	  {"corr_met_MultiLepCalc", corr_met_MultiLepCalc}, //update with BB variables X
	  {"AK4HTpMETpLepPt", AK4HTpMETpLepPt},
	  {"AK4HT", AK4HT},
	  {"NJets_JetSubCalc", NJets_JetSubCalc},
	  {"NJetsAK8_JetSubCalc", NJetsAK8_JetSubCalc},
	  {"minDR_leadAK8otherAK8", minDR_leadAK8otherAK8},
	  {"nH_DeepAK8", nH_DeepAK8},
	  {"nT_DeepAK8", nT_DeepAK8},
	  {"nW_DeepAK8", nW_DeepAK8},
	  {"jetPt_1", jetPt_1},
	  {"jetPt_2", jetPt_2},
	  {"jetPt_3", jetPt_3},
	  {"sdMass_1", sdMass_1},
	  {"sdMass_2", sdMass_2},
	  {"sdMass_3", sdMass_3},
	  {"tau21_3", tau21_3},
	  {"dnnLargest_1", dnnLargest_1},
	  {"dnnLargest_2", dnnLargest_2},
	  {"dnnLargest_3", dnnLargest_3},
	  {"dnnJ_1", dnnJ_1},
	  {"dnnJ_2", dnnJ_2},
	  {"dnnJ_3", dnnJ_3},
	  {"dnnH_1", dnnH_1},
	  {"dnnH_2", dnnH_2},
	  {"dnnH_3", dnnH_3},
	  {"dnnT_1", dnnT_1},
	  {"dnnT_2", dnnT_2},

	};
	
	myMapTT = lwtnnTT->compute(varMapTT);      
	myMapBB = lwtnnBB->compute(varMapBB);      

	dnn_WJets = myMapTT["Wjets"];
	dnn_ttbar = myMapTT["ttbar"];
	dnn_Tprime = myMapTT["Tprime"];
	dnn_WJetsBB = myMapBB["WjetsBB"];
	dnn_ttbarBB = myMapBB["ttbarBB"];
	dnn_Bprime = myMapBB["Bprime"];

      }

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
      // Leptonic top quark decay
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
      t_pt = -999;
      t_dRWb = 999;
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

      // ----------------------------------------------------------------------------
      // TTbar CR modeling corrections -- HT and top pT
      // ----------------------------------------------------------------------------      

      HT_Corr = 1;
      HT_CorrUp = 1;
      HT_CorrDn = 1;
      tpt_Corr = 1;
      tpt_CorrUp = 1;
      tpt_CorrDn = 1;

      // Piece-wise splice with a flat line. Uncertainty from covariance matrix
      // Evaluate for all samples, plan to apply only to ttbar
      // HT fit computed using TTbar CR, top pT fit computed in full CR
      HT_Corr = polyHT->Eval(AK4HT);
      HT_CorrUp = polyHTU->Eval(AK4HT);
      HT_CorrDn = polyHTD->Eval(AK4HT);
      if (t_mass > -999){
	tpt_Corr = polytpt->Eval(t_pt);
	tpt_CorrUp = polytptU->Eval(t_pt);
	tpt_CorrDn = polytptD->Eval(t_pt);
      }
      
      // ----------------------------------------------------------------------------
      // VLQ decay
      // ----------------------------------------------------------------------------                                                                                                       

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
	if(isSig){
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
      pdfWeights4LHC.clear();
      pdfWeightsMSTW.clear();
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
	  if(LHEweightids_MultiLepCalc->at(i) > 442 && LHEweightids_MultiLepCalc->at(i) < 474){
	    pdfWeights4LHC.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	  if(LHEweightids_MultiLepCalc->at(i) > 205 && LHEweightids_MultiLepCalc->at(i) < 247){
	    pdfWeightsMSTW.push_back(LHEweights_MultiLepCalc->at(i));
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
	  if(LHEweightids_MultiLepCalc->at(i) > 714 && LHEweightids_MultiLepCalc->at(i) < 746){
	    pdfWeights4LHC.push_back(LHEweights_MultiLepCalc->at(i));
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
      else if(isTTV || isSTs){
	for(unsigned int i = 0; i < LHEweightids_MultiLepCalc->size(); i++){
	  if(LHEweightids_MultiLepCalc->at(i) > 1001 && LHEweightids_MultiLepCalc->at(i) < 1010){
	    if(LHEweightids_MultiLepCalc->at(i) == 1006 || LHEweightids_MultiLepCalc->at(i) == 1008) continue;
	    renorm.push_back(LHEweights_MultiLepCalc->at(i));
	    renormWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	  if(LHEweightids_MultiLepCalc->at(i) > 1009 && LHEweightids_MultiLepCalc->at(i) < 1111){
	    pdf.push_back(LHEweights_MultiLepCalc->at(i));
	    pdfWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	  if(LHEweightids_MultiLepCalc->at(i) == 1111 || LHEweightids_MultiLepCalc->at(i) == 1112){
	    if(isTTV) alphaSWeights.push_back(LHEweights_MultiLepCalc->at(i));
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
	  if(LHEweightids_MultiLepCalc->at(i) > 10999 && LHEweightids_MultiLepCalc->at(i) < 11031){
	    pdfWeights4LHC.push_back(LHEweights_MultiLepCalc->at(i));
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
   
   if(isSig){
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
