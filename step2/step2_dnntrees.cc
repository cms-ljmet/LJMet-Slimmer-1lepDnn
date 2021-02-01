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
   inputTree->SetBranchStatus("NJetsDeepFlavwithSF_JetSubCalc",1);
   inputTree->SetBranchStatus("t_mass",1);
   inputTree->SetBranchStatus("t_pt",1);
   inputTree->SetBranchStatus("W_pt",1);
   inputTree->SetBranchStatus("minMleppBjet",1);
   inputTree->SetBranchStatus("minMleppJet",1);
   inputTree->SetBranchStatus("t_dRWb",1);
   inputTree->SetBranchStatus("W_dRLep",1);

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

   // Add some new branches as needed
   float weight;
   outputTree->Branch("weight",&weight,"weight/F");
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

   // Polynomials for corrections from HT and tpt
   TF1 *polyHT = new TF1("polyHT","min(1.0,max([0] + [1]*x,[2]))",700,5000);
   polyHT->SetParameter(0,     1.09245);
   polyHT->SetParameter(1,-0.000220375);
   polyHT->SetParameter(2,    0.607311);

   std::vector<float> dnnJcorrSF;
   std::vector<float> probjratio;
   if(year == 2017){
     dnnJcorrSF = {0.918,0.956,0.962,0.942,0.906,1.0173,1.0496,1.018}; //W400, 600, 800, 1200, 2500, ttbar, TT1000, BB1000 guess
     probjratio = {0.895978610288,1.16525315136,1.20747298989,1.19353489843,1.18540312118,1.18632840174,1.15826557542,1.17909153199,1.1741450779,1.17470932221,1.14152086917,1.2197336202,1.18811047751,1.15225187135,1.21357371137,1.16520406009,1.12996415871,1.1508927419,1.1186715293,1.15234318754,1.08876462251,1.10323576449,1.13570005709,1.1341834586,1.10422957542,1.23227254201,1.12565168224,1.14096049038,1.10447652923,1.13157946119,1.16375808236,1.14940833335,1.15607472711,1.18015479664,1.13812756764,1.1298478968,1.16623846496,1.16324157939,1.14357869922,1.16791151985,1.11825314392,1.12994111158,1.11389184899,1.04621473695,1.01500221633,0.925724410351,0.819028856086,0.731851041888,0.680752586579,0.72002981445};
   }else if(year == 2018){
     dnnJcorrSF = {0.869,0.949,0.964,0.955,0.923,1.006,1.0047,0.975};
     probjratio = {0.93502437536,1.16050105933,1.17907897781,1.19761779496,1.1605174677,1.21086755205,1.18172403861,1.17633653298,1.13539922593,1.1638942794,1.20042923129,1.15940403571,1.12754788226,1.12667308666,1.10719523961,1.12582949499,1.10189585351,1.12541409448,1.18383437813,1.1479992218,1.06086063339,1.17383559034,1.13233112262,1.1143887346,1.14445348826,1.14160659701,1.12601268962,1.1184326496,1.088199043,1.10070675891,1.13485746114,1.12776426817,1.12182946261,1.14623005575,1.11298486273,1.10253114396,1.13760859761,1.09899545364,1.10552205758,1.09028053261,1.08116624002,1.05868392915,1.03946854035,1.01164251299,0.950746433825,0.877552238296,0.816278871402,0.765795138198,0.815139345621,0.993521986454};	
   }else{
     dnnJcorrSF = {1};
   }

   // These can make labels for Signal, Top, and Wjets
   cout << "isSig = " << isSig << ", isTT = " << isTT << endl;
   cout << "Year = " << year << ", sampleIndex = " << sampleindex << endl;

   int npassed_all = 0;

   Long64_t nentries = inputTree->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      weight = 1.0;
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

      if(MCPastTrigger < 1 || NJetsAK8_JetSubCalc < 3 || AK4HT < 510. || corr_met_MultiLepCalc < 50. || leptonPt_MultiLepCalc < 55) continue;
      if(isValidTTDecayMode_DeepAK8 > 0 && isValidBBDecayMode_DeepAK8 > 0) continue;

      // do the below cut as a "sel" in the dnn training for more flexibility
      //if(!isSig && Tprime2_DeepAK8_Mass > -9) continue; // trying the scenario where TT can't be reconstructed for backgrounds, loosening to 2+ AK8 jets
      npassed_all++;

      jetPt_1 = theJetAK8Pt_JetSubCalc_PtOrdered->at(0);
      jetPt_2 = theJetAK8Pt_JetSubCalc_PtOrdered->at(1);
      jetPt_3 = theJetAK8Pt_JetSubCalc_PtOrdered->at(2);
      
      sdMass_1 = theJetAK8SoftDropCorr_JetSubCalc_PtOrdered->at(0);
      sdMass_2 = theJetAK8SoftDropCorr_JetSubCalc_PtOrdered->at(1);
      sdMass_3 = theJetAK8SoftDropCorr_JetSubCalc_PtOrdered->at(2);

      dnnLargest_1 = dnn_largest_DeepAK8Calc_PtOrdered->at(0);
      dnnLargest_2 = dnn_largest_DeepAK8Calc_PtOrdered->at(1);
      dnnLargest_3 = dnn_largest_DeepAK8Calc_PtOrdered->at(2);

      dnnB_1 = dnn_B_DeepAK8Calc_PtOrdered->at(0);
      dnnB_2 = dnn_B_DeepAK8Calc_PtOrdered->at(1);
      dnnB_3 = dnn_B_DeepAK8Calc_PtOrdered->at(2);

      dnnJ_1 = dnn_J_DeepAK8Calc_PtOrdered->at(0);
      dnnJ_2 = dnn_J_DeepAK8Calc_PtOrdered->at(1);
      dnnJ_3 = dnn_J_DeepAK8Calc_PtOrdered->at(2);

      dnnW_1 = dnn_W_DeepAK8Calc_PtOrdered->at(0);
      dnnW_2 = dnn_W_DeepAK8Calc_PtOrdered->at(1);
      dnnW_3 = dnn_W_DeepAK8Calc_PtOrdered->at(2);

      dnnZ_1 = dnn_Z_DeepAK8Calc_PtOrdered->at(0);
      dnnZ_2 = dnn_Z_DeepAK8Calc_PtOrdered->at(1);
      dnnZ_3 = dnn_Z_DeepAK8Calc_PtOrdered->at(2);

      dnnH_1 = dnn_H_DeepAK8Calc_PtOrdered->at(0);
      dnnH_2 = dnn_H_DeepAK8Calc_PtOrdered->at(1);
      dnnH_3 = dnn_H_DeepAK8Calc_PtOrdered->at(2);

      dnnT_1 = dnn_T_DeepAK8Calc_PtOrdered->at(0);
      dnnT_2 = dnn_T_DeepAK8Calc_PtOrdered->at(1);
      dnnT_3 = dnn_T_DeepAK8Calc_PtOrdered->at(2);

      tau21_1 = theJetAK8NjettinessTau2_JetSubCalc_PtOrdered->at(0)/theJetAK8NjettinessTau1_JetSubCalc_PtOrdered->at(0);
      tau21_2 = theJetAK8NjettinessTau2_JetSubCalc_PtOrdered->at(1)/theJetAK8NjettinessTau1_JetSubCalc_PtOrdered->at(1);
      tau21_3 = theJetAK8NjettinessTau2_JetSubCalc_PtOrdered->at(2)/theJetAK8NjettinessTau1_JetSubCalc_PtOrdered->at(2);

      tau32_1 = theJetAK8NjettinessTau3_JetSubCalc_PtOrdered->at(0)/theJetAK8NjettinessTau2_JetSubCalc_PtOrdered->at(0);
      tau32_2 = theJetAK8NjettinessTau3_JetSubCalc_PtOrdered->at(1)/theJetAK8NjettinessTau2_JetSubCalc_PtOrdered->at(1);
      tau32_3 = theJetAK8NjettinessTau3_JetSubCalc_PtOrdered->at(2)/theJetAK8NjettinessTau2_JetSubCalc_PtOrdered->at(2);

      float HT_Corr = 1.0;
      HT_Corr = polyHT->Eval(AK4HT);

      float dnnJweight3 = 1;
      
      if(year != 2016){
	dnnJweight3 = probjratio.at(floor(dnn_J_DeepAK8Calc_PtOrdered->at(0)/0.02)) * probjratio.at(floor(dnn_J_DeepAK8Calc_PtOrdered->at(1)/0.02)) 
	  * probjratio.at(floor(dnn_J_DeepAK8Calc_PtOrdered->at(2)/0.02)) * dnnJcorrSF.at(sampleindex);
      }

      weight = dnnJweight3*HT_Corr;

      outputTree->Fill();
      //if(npassed_all >= 80000){break;}
   }

   std::cout<<"NPassed ALL = " << npassed_all << "/"<<nentries<<std::endl;
   std::cout << "DONE" << std::endl;
   outputTree->Write();
}
