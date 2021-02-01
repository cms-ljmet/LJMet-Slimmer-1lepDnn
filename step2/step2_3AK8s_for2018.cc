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

void step2::Loop(TString inTreeName, TString outTreeName) 
{
  inputTree = (TTree*)inputFile->Get(inTreeName);
  if (inputTree == 0) return;
  if(inputTree->GetEntries() == 0){
    std::cout << "WARNING! Found 0 events in the tree!!!" << std::endl;
    return;
  }

  Init(inputTree);
   
  inputTree->SetBranchStatus("*",1);

  // Makes a copy of the branches with status 1
  outputFile->cd();
  if(isMC && inTreeName == "ljmet"){
    TH1D* numhist = (TH1D*)inputFile->Get("NumTrueHist");
    TH1D* wgthist = (TH1D*)inputFile->Get("weightHist");
    numhist->Write();
    wgthist->Write();
  }
  TTree *outputTree = inputTree->CloneTree(0);
  outputTree->Branch("AK8HT",&AK8HT,"AK8HT/D");
  outputTree->Branch("AK8JetsPt_Exclude_Hole",&AK8JetsPt_Exclude_Hole);
  outputTree->Branch("AK4JetsPt_Exclude_Hole",&AK4JetsPt_Exclude_Hole);
  outputTree->Branch("AK8HT_Exclude_Hole",&AK8HT_Exclude_Hole,"AK8HT_Exclude_Hole/D");
  outputTree->Branch("AK4HT_Exclude_Hole",&AK4HT_Exclude_Hole,"AK4HT_Exclude_Hole/D");
  int npassed_all = 0;
  int npassed_hole = 0;
  Long64_t nentries = inputTree->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = inputTree->GetEntry(jentry);   nbytes += nb;
    if (Cut(ientry) != 1) continue; 
    
    //      if (ientry > 5000) continue;

    
    if(jentry % 10000 ==0) std::cout<<"Completed "<<jentry<<" out of "<<nentries<<" events"<<std::endl;

    if( isElectron && (leptonEta_MultiLepCalc>-2.5 && leptonEta_MultiLepCalc<-1.479 && leptonPhi_MultiLepCalc>-1.55 && leptonPhi_MultiLepCalc<-0.9)) continue;
    npassed_hole++;
    if( MCPastTrigger < 1 || DataPastTrigger < 1 || NJetsAK8_JetSubCalc < 3 || corr_met_MultiLepCalc < 50. || leptonPt_MultiLepCalc < 55) continue;
    


    AK4JetsPt_Exclude_Hole.clear();
    AK4HT_Exclude_Hole=0;
    AK8JetsPt_Exclude_Hole.clear();
    AK8HT_Exclude_Hole=0;
    AK8HT=0;

    for(int jjet8=0; jjet8<theJetAK8Pt_JetSubCalc_PtOrdered->size();jjet8++)
      {
	AK8HT+=theJetAK8Pt_JetSubCalc_PtOrdered->at(jjet8);
      }

    for(int jjet4=0; jjet4<theJetPt_JetSubCalc_PtOrdered->size();jjet4++)
      {
	if (-2.5<theJetEta_JetSubCalc_PtOrdered->at(jjet4) && theJetEta_JetSubCalc_PtOrdered->at(jjet4)<-1.3 && -1.57<theJetPhi_JetSubCalc_PtOrdered->at(jjet4) && theJetPhi_JetSubCalc_PtOrdered->at(jjet4)<-.87)
	  {
	    TLorentzVector jet4; 
	    jet4.SetPtEtaPhiE (theJetPt_JetSubCalc_PtOrdered->at(jjet4), theJetEta_JetSubCalc_PtOrdered->at(jjet4), theJetPhi_JetSubCalc_PtOrdered->at(jjet4), theJetEnergy_JetSubCalc_PtOrdered->at(jjet4));
	    jet4=jet4*1.2;
	    if(jet4.Pt()>30)
	      {
		AK4JetsPt_Exclude_Hole.push_back(jet4.Pt());
		AK4HT_Exclude_Hole+=jet4.Pt();
	      }
	  }

	else if (-3<theJetEta_JetSubCalc_PtOrdered->at(jjet4) && theJetEta_JetSubCalc_PtOrdered->at(jjet4)<-2.5 && -1.57<theJetPhi_JetSubCalc_PtOrdered->at(jjet4) && theJetPhi_JetSubCalc_PtOrdered->at(jjet4)<-.87)
	  {
	    TLorentzVector jet4; 
	    jet4.SetPtEtaPhiE (theJetPt_JetSubCalc_PtOrdered->at(jjet4), theJetEta_JetSubCalc_PtOrdered->at(jjet4), theJetPhi_JetSubCalc_PtOrdered->at(jjet4), theJetEnergy_JetSubCalc_PtOrdered->at(jjet4));
	    jet4=jet4*1.35;
	    if(jet4.Pt()>30)
	      {
		AK4JetsPt_Exclude_Hole.push_back(jet4.Pt());
		AK4HT_Exclude_Hole+=jet4.Pt();
	      }
	  }
	else
	  {
	    AK4JetsPt_Exclude_Hole.push_back(theJetPt_JetSubCalc_PtOrdered->at(jjet4));
	    AK4HT_Exclude_Hole+=theJetPt_JetSubCalc_PtOrdered->at(jjet4);
	  }

      }


    for(int jjet8=0; jjet8<theJetAK8Pt_JetSubCalc_PtOrdered->size();jjet8++)
      {
	if (-2.5<theJetAK8Eta_JetSubCalc_PtOrdered->at(jjet8) && theJetAK8Eta_JetSubCalc_PtOrdered->at(jjet8)<-1.3 && -1.57<theJetAK8Phi_JetSubCalc_PtOrdered->at(jjet8) && theJetAK8Phi_JetSubCalc_PtOrdered->at(jjet8)<-.87)
	  {
	    TLorentzVector jet8; 
	    jet8.SetPtEtaPhiE (theJetAK8Pt_JetSubCalc_PtOrdered->at(jjet8), theJetAK8Eta_JetSubCalc_PtOrdered->at(jjet8), theJetAK8Phi_JetSubCalc_PtOrdered->at(jjet8), theJetAK8Energy_JetSubCalc_PtOrdered->at(jjet8));
	    jet8=jet8*1.2;
	    if(jet8.Pt()>200)
	      {
		AK8JetsPt_Exclude_Hole.push_back(jet8.Pt());
		AK8HT_Exclude_Hole+=jet8.Pt();
	      }
	  }
	else if (-3<theJetAK8Eta_JetSubCalc_PtOrdered->at(jjet8) && theJetAK8Eta_JetSubCalc_PtOrdered->at(jjet8)<-2.5 && -1.57<theJetAK8Phi_JetSubCalc_PtOrdered->at(jjet8) && theJetAK8Phi_JetSubCalc_PtOrdered->at(jjet8)<-.87)
	  {
	    TLorentzVector jet8; 
	    jet8.SetPtEtaPhiE (theJetAK8Pt_JetSubCalc_PtOrdered->at(jjet8), theJetAK8Eta_JetSubCalc_PtOrdered->at(jjet8), theJetAK8Phi_JetSubCalc_PtOrdered->at(jjet8), theJetAK8Energy_JetSubCalc_PtOrdered->at(jjet8));
	    jet8=jet8*1.35;
	    if(jet8.Pt()>200)
	      {
		AK8JetsPt_Exclude_Hole.push_back(jet8.Pt());
		AK8HT_Exclude_Hole+=jet8.Pt();
	      }
	  }

	else
	  {
	    AK8JetsPt_Exclude_Hole.push_back(theJetAK8Pt_JetSubCalc_PtOrdered->at(jjet8));
	    AK8HT_Exclude_Hole+=theJetAK8Pt_JetSubCalc_PtOrdered->at(jjet8);
	  }
      }
    
    npassed_all++;
    outputTree->Fill();
  }
  
  std::cout<<"NPassed HOLE = " << npassed_hole << "/"<<nentries<<std::endl;
  std::cout<<"NPassed ALL = " << npassed_all << "/"<<nentries<<std::endl;
  std::cout << "DONE" << std::endl;
  outputTree->Write();
}
