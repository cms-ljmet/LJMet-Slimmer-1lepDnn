#define step2_cxx
#include "step2.h"
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
#include <TLorentzVector.h>

using namespace std;

void step2::saveHistograms()
{
   TH1D* numhist = (TH1D*)inputFile->Get("NumTrueHist");
   TH1D* wgthist = (TH1D*)inputFile->Get("weightHist");
   outputFile->cd();
   numhist->Write();
   wgthist->Write();
}

void step2::Loop(TString inTreeName, TString outTreeName) 
{
   if (inputTree == 0) return;
   
   inputTree->SetBranchStatus("*",0);

   // Only branches you want to use or copy into the new tree with "clone" below
   inputTree->SetBranchStatus("AK4HT",1);
   inputTree->SetBranchStatus("AK4HTpMETpLepPt",1);
   inputTree->SetBranchStatus("corr_met_MultiLepCalc",1);
   inputTree->SetBranchStatus("NJetsCSVwithSF_JetSubCalc",1);
   inputTree->SetBranchStatus("NJets_JetSubCalc",1);
   inputTree->SetBranchStatus("NJetsAK8_JetSubCalc",1);
   inputTree->SetBranchStatus("nB_DeepAK8",1);
   inputTree->SetBranchStatus("nH_DeepAK8",1);
   inputTree->SetBranchStatus("nW_DeepAK8",1);
   inputTree->SetBranchStatus("nZ_DeepAK8",1);
   inputTree->SetBranchStatus("nT_DeepAK8",1);
   inputTree->SetBranchStatus("Tprime2_DeepAK8_Mass",1);
   inputTree->SetBranchStatus("Tprime2_DeepAK8_Pt",1);
   inputTree->SetBranchStatus("Tprime2_DeepAK8_Eta",1);
   inputTree->SetBranchStatus("Tprime2_DeepAK8_deltaR",1);
   inputTree->SetBranchStatus("Bprime2_DeepAK8_Mass",1);
   inputTree->SetBranchStatus("Bprime2_DeepAK8_Pt",1);
   inputTree->SetBranchStatus("Bprime2_DeepAK8_Eta",1);
   inputTree->SetBranchStatus("Bprime2_DeepAK8_deltaR",1);
   inputTree->SetBranchStatus("leptonPt_MultiLepCalc",1);
   inputTree->SetBranchStatus("minDR_leadAK8otherAK8",1);
   inputTree->SetBranchStatus("minDR_lepAK8",1);
   inputTree->SetBranchStatus("isValidTTDecayMode_DeepAK8",1);
   inputTree->SetBranchStatus("isValidBBDecayMode_DeepAK8",1);

   // Makes a copy of the branches with status 1
   outputFile->cd();
   TTree *outputTree = inputTree->CloneTree(0);

   inputTree->SetBranchStatus("dnn_largest_DeepAK8Calc_PtOrdered",1);
   inputTree->SetBranchStatus("dnn_B_DeepAK8Calc_PtOrdered",1);
   inputTree->SetBranchStatus("dnn_J_DeepAK8Calc_PtOrdered",1);
   inputTree->SetBranchStatus("dnn_W_DeepAK8Calc_PtOrdered",1);
   inputTree->SetBranchStatus("dnn_Z_DeepAK8Calc_PtOrdered",1);
   inputTree->SetBranchStatus("dnn_H_DeepAK8Calc_PtOrdered",1);
   inputTree->SetBranchStatus("dnn_T_DeepAK8Calc_PtOrdered",1);
   inputTree->SetBranchStatus("theJetAK8SoftDropCorr_JetSubCalc_PtOrdered",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau1_JetSubCalc_PtOrdered",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau2_JetSubCalc_PtOrdered",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau3_JetSubCalc_PtOrdered",1);
   inputTree->SetBranchStatus("theJetAK8Pt_JetSubCalc_PtOrdered",1);
   inputTree->SetBranchStatus("MCPastTrigger",1);
   inputTree->SetBranchStatus("minDR_lepJet",1);
   inputTree->SetBranchStatus("ptRel_lepJet",1);
   inputTree->SetBranchStatus("isBWBW_TpTpCalc",1);
   inputTree->SetBranchStatus("isTHBW_TpTpCalc",1);
   inputTree->SetBranchStatus("isTZBW_TpTpCalc",1);
   inputTree->SetBranchStatus("isTZTZ_TpTpCalc",1);
   inputTree->SetBranchStatus("isTZTH_TpTpCalc",1);
   inputTree->SetBranchStatus("isTHTH_TpTpCalc",1);
   inputTree->SetBranchStatus("isTWTW_BpBpCalc",1);
   inputTree->SetBranchStatus("isBHTW_BpBpCalc",1);
   inputTree->SetBranchStatus("isBZTW_BpBpCalc",1);
   inputTree->SetBranchStatus("isBZBZ_BpBpCalc",1);
   inputTree->SetBranchStatus("isBZBH_BpBpCalc",1);
   inputTree->SetBranchStatus("isBHBH_BpBpCalc",1);

   // Add some new branches as needed
   int targetLabel;
   outputTree->Branch("targetLabel",&targetLabel,"targetLabel/I");
   float jetPt_1,jetPt_2,jetPt_3;
   outputTree->Branch("jetPt_1",&jetPt_1,"jetPt_1/F");
   outputTree->Branch("jetPt_2",&jetPt_2,"jetPt_2/F");
   outputTree->Branch("jetPt_3",&jetPt_3,"jetPt_3/F");
   float sdMass_1,sdMass_2,sdMass_3;
   outputTree->Branch("sdMass_1",&sdMass_1,"sdMass_1/F");
   outputTree->Branch("sdMass_2",&sdMass_2,"sdMass_2/F");
   outputTree->Branch("sdMass_3",&sdMass_3,"sdMass_3/F");
   float tau21_1,tau21_2,tau21_3,tau32_1,tau32_2,tau32_3;
   outputTree->Branch("tau21_1",&tau21_1,"tau21_1/F");
   outputTree->Branch("tau21_2",&tau21_2,"tau21_2/F");
   outputTree->Branch("tau21_3",&tau21_3,"tau21_3/F");
   outputTree->Branch("tau32_1",&tau32_1,"tau32_1/F");
   outputTree->Branch("tau32_2",&tau32_2,"tau32_2/F");
   outputTree->Branch("tau32_3",&tau32_3,"tau32_3/F");
   int dnnLargest_1,dnnLargest_2,dnnLargest_3;
   float dnnB_1,dnnB_2,dnnB_3;
   float dnnJ_1,dnnJ_2,dnnJ_3;
   float dnnW_1,dnnW_2,dnnW_3;
   float dnnZ_1,dnnZ_2,dnnZ_3;
   float dnnH_1,dnnH_2,dnnH_3;
   float dnnT_1,dnnT_2,dnnT_3;
   outputTree->Branch("dnnLargest_1",&dnnLargest_1,"dnnLargest_1/I");
   outputTree->Branch("dnnLargest_2",&dnnLargest_2,"dnnLargest_2/I");
   outputTree->Branch("dnnLargest_3",&dnnLargest_3,"dnnLargest_3/I");
   outputTree->Branch("dnnB_1",&dnnB_1,"dnnB_1/F");
   outputTree->Branch("dnnB_2",&dnnB_2,"dnnB_2/F");
   outputTree->Branch("dnnB_3",&dnnB_3,"dnnB_3/F");
   outputTree->Branch("dnnJ_1",&dnnJ_1,"dnnJ_1/F");
   outputTree->Branch("dnnJ_2",&dnnJ_2,"dnnJ_2/F");
   outputTree->Branch("dnnJ_3",&dnnJ_3,"dnnJ_3/F");
   outputTree->Branch("dnnW_1",&dnnW_1,"dnnW_1/F");
   outputTree->Branch("dnnW_2",&dnnW_2,"dnnW_2/F");
   outputTree->Branch("dnnW_3",&dnnW_3,"dnnW_3/F");
   outputTree->Branch("dnnZ_1",&dnnZ_1,"dnnZ_1/F");
   outputTree->Branch("dnnZ_2",&dnnZ_2,"dnnZ_2/F");
   outputTree->Branch("dnnZ_3",&dnnZ_3,"dnnZ_3/F");
   outputTree->Branch("dnnH_1",&dnnH_1,"dnnH_1/F");
   outputTree->Branch("dnnH_2",&dnnH_2,"dnnH_2/F");
   outputTree->Branch("dnnH_3",&dnnH_3,"dnnH_3/F");
   outputTree->Branch("dnnT_1",&dnnT_1,"dnnT_1/F");
   outputTree->Branch("dnnT_2",&dnnT_2,"dnnT_2/F");
   outputTree->Branch("dnnT_3",&dnnT_3,"dnnT_3/F");

   // These can make labels for Signal, Top, and Wjets
   cout << "isSig = " << isSig << ", SigMass = " << SigMass << endl;
   cout << "isTT = " << isTT << endl;
   if(isTT) targetLabel = 0; // Top
   if(!isTT and !isSig) targetLabel = 1; // WJets

   int npassed_all = 0;

   Long64_t nentries = inputTree->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      jetPt_1 = 0;
      jetPt_2 = 0;
      jetPt_3 = 0;
      sdMass_1 = 0;
      sdMass_2 = 0;
      sdMass_3 = 0;
      dnnLargest_1 = 0;
      dnnLargest_2 = 0;
      dnnLargest_3 = 0;
      dnnB_1 = 0;
      dnnB_2 = 0;
      dnnB_3 = 0;
      dnnJ_1 = 0;
      dnnJ_2 = 0;
      dnnJ_3 = 0;
      dnnW_1 = 0;
      dnnW_2 = 0;
      dnnW_3 = 0;
      dnnZ_1 = 0;
      dnnZ_2 = 0;
      dnnZ_3 = 0;
      dnnH_1 = 0;
      dnnH_2 = 0;
      dnnH_3 = 0;
      dnnT_1 = 0;
      dnnT_2 = 0;
      dnnT_3 = 0;
      tau21_1 = 0;
      tau21_2 = 0;
      tau21_3 = 0;
      tau32_1 = 0;
      tau32_2 = 0;
      tau32_3 = 0;
      if (ientry < 0) break;
      nb = inputTree->GetEntry(jentry);   nbytes += nb;
      if (Cut(ientry) != 1) continue;  //Pre-selection

      //      if (ientry > 5000) continue;
      
      if(jentry % 10000 ==0) std::cout<<"Completed "<<jentry<<" out of "<<nentries<<" events"<<std::endl;

      if(MCPastTrigger < 1 || NJetsAK8_JetSubCalc < 2 || AK4HT < 510. || corr_met_MultiLepCalc < 50. || leptonPt_MultiLepCalc < 55) continue;
      if(isValidTTDecayMode_DeepAK8 > 0 && isValidBBDecayMode_DeepAK8 > 0) continue;
      // do the below cut as a "sel" in the dnn training for more flexibility
      //if(!isSig && Tprime2_DeepAK8_Mass > -9) continue; // trying the scenario where TT can't be reconstructed for backgrounds, loosening to 2+ AK8 jets
      npassed_all++;

      jetPt_1 = theJetAK8Pt_JetSubCalc_PtOrdered->at(0);
      jetPt_2 = theJetAK8Pt_JetSubCalc_PtOrdered->at(1);
      if(NJetsAK8_JetSubCalc > 2) jetPt_3 = theJetAK8Pt_JetSubCalc_PtOrdered->at(2);
      else jetPt_3 = 0;
      
      sdMass_1 = theJetAK8SoftDropCorr_JetSubCalc_PtOrdered->at(0);
      sdMass_2 = theJetAK8SoftDropCorr_JetSubCalc_PtOrdered->at(1);
      if(NJetsAK8_JetSubCalc > 2) sdMass_3 = theJetAK8SoftDropCorr_JetSubCalc_PtOrdered->at(2);
      else sdMass_3 = 0;

      dnnLargest_1 = dnn_largest_DeepAK8Calc_PtOrdered->at(0);
      dnnLargest_2 = dnn_largest_DeepAK8Calc_PtOrdered->at(1);
      if(NJetsAK8_JetSubCalc > 2) dnnLargest_3 = dnn_largest_DeepAK8Calc_PtOrdered->at(2);
      else dnnLargest_3 = 10;

      dnnB_1 = dnn_B_DeepAK8Calc_PtOrdered->at(0);
      dnnB_2 = dnn_B_DeepAK8Calc_PtOrdered->at(1);
      if(NJetsAK8_JetSubCalc > 2) dnnB_3 = dnn_B_DeepAK8Calc_PtOrdered->at(2);
      else dnnB_3 = -9;

      dnnJ_1 = dnn_J_DeepAK8Calc_PtOrdered->at(0);
      dnnJ_2 = dnn_J_DeepAK8Calc_PtOrdered->at(1);
      if(NJetsAK8_JetSubCalc > 2) dnnJ_3 = dnn_J_DeepAK8Calc_PtOrdered->at(2);
      else dnnJ_3 = -9;

      dnnW_1 = dnn_W_DeepAK8Calc_PtOrdered->at(0);
      dnnW_2 = dnn_W_DeepAK8Calc_PtOrdered->at(1);
      if(NJetsAK8_JetSubCalc > 2) dnnW_3 = dnn_W_DeepAK8Calc_PtOrdered->at(2);
      else dnnW_3 = -9;

      dnnZ_1 = dnn_Z_DeepAK8Calc_PtOrdered->at(0);
      dnnZ_2 = dnn_Z_DeepAK8Calc_PtOrdered->at(1);
      if(NJetsAK8_JetSubCalc > 2) dnnZ_3 = dnn_Z_DeepAK8Calc_PtOrdered->at(2);
      else dnnZ_3 = -9;

      dnnH_1 = dnn_H_DeepAK8Calc_PtOrdered->at(0);
      dnnH_2 = dnn_H_DeepAK8Calc_PtOrdered->at(1);
      if(NJetsAK8_JetSubCalc > 2) dnnH_3 = dnn_H_DeepAK8Calc_PtOrdered->at(2);
      else dnnH_3 = -9;

      dnnT_1 = dnn_T_DeepAK8Calc_PtOrdered->at(0);
      dnnT_2 = dnn_T_DeepAK8Calc_PtOrdered->at(1);
      if(NJetsAK8_JetSubCalc > 2) dnnT_3 = dnn_T_DeepAK8Calc_PtOrdered->at(2);
      else dnnT_3 = -9;

      tau21_1 = theJetAK8NjettinessTau2_JetSubCalc_PtOrdered->at(0)/theJetAK8NjettinessTau1_JetSubCalc_PtOrdered->at(0);
      tau21_2 = theJetAK8NjettinessTau2_JetSubCalc_PtOrdered->at(1)/theJetAK8NjettinessTau1_JetSubCalc_PtOrdered->at(1);
      if(NJetsAK8_JetSubCalc > 2) tau21_3 = theJetAK8NjettinessTau2_JetSubCalc_PtOrdered->at(2)/theJetAK8NjettinessTau1_JetSubCalc_PtOrdered->at(2);
      else tau21_3 = 1;

      tau32_1 = theJetAK8NjettinessTau3_JetSubCalc_PtOrdered->at(0)/theJetAK8NjettinessTau2_JetSubCalc_PtOrdered->at(0);
      tau32_2 = theJetAK8NjettinessTau3_JetSubCalc_PtOrdered->at(1)/theJetAK8NjettinessTau2_JetSubCalc_PtOrdered->at(1);
      if(NJetsAK8_JetSubCalc > 2) tau32_3 = theJetAK8NjettinessTau3_JetSubCalc_PtOrdered->at(2)/theJetAK8NjettinessTau2_JetSubCalc_PtOrdered->at(2);
      else tau32_3 = 1;

      if(isSig){
	if(isBWBW_TpTpCalc) targetLabel = 2;
	else if(isTZBW_TpTpCalc) targetLabel = 3;
	else if(isTHBW_TpTpCalc) targetLabel = 4;
	else if(isTZTZ_TpTpCalc) targetLabel = 5;
	else if(isTZTH_TpTpCalc) targetLabel = 6;
	else targetLabel = 7;
      }

      outputTree->Fill();
      //if(npassed_all >= 80000){break;}
   }

   std::cout<<"NPassed ALL = " << npassed_all << "/"<<nentries<<std::endl;
   std::cout << "DONE" << std::endl;
   outputTree->Write();
}
