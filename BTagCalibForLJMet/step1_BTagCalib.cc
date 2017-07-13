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

#include "BTagCalibForLJMet.h"

using namespace std;

// ----------------------------------------------------------------------------
// MAIN EVENT LOOP
// ----------------------------------------------------------------------------

void step1::Loop() 
{

  // setup calibration + reader
  BTagCalibrationForLJMet calib("csvv2", "CSVv2_Moriond17_B_H.csv");
  BTagCalibrationForLJMetReader reader(BTagEntryForLJMet::OP_RESHAPING,  // operating point
			       "central",             // central sys type
			       {"up_jes", "down_jes", "up_lf", "down_lf", "up_hfstats1", "down_hfstats1",
				   "up_hfstats2", "down_hfstats2", "up_cferr1", "down_cferr1", "up_cferr2",
				   "down_cferr2", "up_hf", "down_hf", "up_lfstats1", "down_lfstats1",
				   "up_lfstats2", "down_lfstats2"});      // other sys types
  //C-only: cferr*. L-only: hf, lfstats*. B-only: lf, hfstats*
  
  reader.load(calib,                 // calibration instance
	      BTagEntryForLJMet::FLAV_B,     // btag flavour
	      "iterativefit");       // measurement type
  reader.load(calib, BTagEntryForLJMet::FLAV_C, "iterativefit");     // for FLAV_C
  reader.load(calib, BTagEntryForLJMet::FLAV_UDSG, "iterativefit");     // for FLAV_UDSG
    

  // ----------------------------------------------------------------------------
  // Turn on input tree branches
  // ----------------------------------------------------------------------------

   if (inputTree == 0) return;
   
   inputTree->SetBranchStatus("*",0);

   inputTree->SetBranchStatus("AK4JetFlav_singleLepCalc",1);
   inputTree->SetBranchStatus("AK4JetPt_singleLepCalc",1);
   inputTree->SetBranchStatus("AK4JetEta_singleLepCalc",1);
   inputTree->SetBranchStatus("AK4JetBDisc_singleLepCalc",1);

  // ----------------------------------------------------------------------------
  // Create output tree and define branches
  // ----------------------------------------------------------------------------
   
   // OUTPUT FILE
   outputFile->cd();
   TTree *outputTree = new TTree("ljmet","ljmet");

   outputTree->Branch("CalibReaderRewgt",&CalibReaderRewgt,"CalibReaderRewgt/F");
   outputTree->Branch("CalibReaderRewgt_JESup",&CalibReaderRewgt_JESup,"CalibReaderRewgt_JESup/F");
   outputTree->Branch("CalibReaderRewgt_JESdn",&CalibReaderRewgt_JESdn,"CalibReaderRewgt_JESdn/F");
   outputTree->Branch("CalibReaderRewgt_LFup",&CalibReaderRewgt_LFup,"CalibReaderRewgt_LFup/F");
   outputTree->Branch("CalibReaderRewgt_LFdn",&CalibReaderRewgt_LFdn,"CalibReaderRewgt_LFdn/F");
   outputTree->Branch("CalibReaderRewgt_HFstat1up",&CalibReaderRewgt_HFstat1up,"CalibReaderRewgt_HFstat1up/F");
   outputTree->Branch("CalibReaderRewgt_HFstat1dn",&CalibReaderRewgt_HFstat1dn,"CalibReaderRewgt_HFstat1dn/F");
   outputTree->Branch("CalibReaderRewgt_HFstat2up",&CalibReaderRewgt_HFstat2up,"CalibReaderRewgt_HFstat2up/F");
   outputTree->Branch("CalibReaderRewgt_HFstat2dn",&CalibReaderRewgt_HFstat2dn,"CalibReaderRewgt_HFstat2dn/F");
   outputTree->Branch("CalibReaderRewgt_CFerr1up",&CalibReaderRewgt_CFerr1up,"CalibReaderRewgt_CFerr1up/F");
   outputTree->Branch("CalibReaderRewgt_CFerr1dn",&CalibReaderRewgt_CFerr1dn,"CalibReaderRewgt_CFerr1dn/F");
   outputTree->Branch("CalibReaderRewgt_CFerr2up",&CalibReaderRewgt_CFerr2up,"CalibReaderRewgt_CFerr2up/F");
   outputTree->Branch("CalibReaderRewgt_CFerr2dn",&CalibReaderRewgt_CFerr2dn,"CalibReaderRewgt_CFerr2dn/F");
   outputTree->Branch("CalibReaderRewgt_HFup",&CalibReaderRewgt_HFup,"CalibReaderRewgt_HFup/F");
   outputTree->Branch("CalibReaderRewgt_HFdn",&CalibReaderRewgt_HFdn,"CalibReaderRewgt_HFdn/F");
   outputTree->Branch("CalibReaderRewgt_LFstat1up",&CalibReaderRewgt_LFstat1up,"CalibReaderRewgt_LFstat1up/F");
   outputTree->Branch("CalibReaderRewgt_LFstat1dn",&CalibReaderRewgt_LFstat1dn,"CalibReaderRewgt_LFstat1dn/F");
   outputTree->Branch("CalibReaderRewgt_LFstat2up",&CalibReaderRewgt_LFstat2up,"CalibReaderRewgt_LFstat2up/F");
   outputTree->Branch("CalibReaderRewgt_LFstat2dn",&CalibReaderRewgt_LFstat2dn,"CalibReaderRewgt_LFstat2dn/F");


   // ----------------------------------------------------------------------------
   // BASIC CUTS AND COUNTERS
   // ----------------------------------------------------------------------------

   float jetPtCut = 40;
   float jetEtaCut = 2.4;
 
   int npass_all = 0;
  
   // ----------------------------------------------------------------------------
   // RUN THE EVENT LOOP
   // ----------------------------------------------------------------------------

   cout << "RUN CONFIG: isMC = " << isMC << endl;
   cout << "BTagCalib isNOM = " << isNOMshift << ", isJEC = " << isJECshift << endl;
   
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
      // Loop over AK4 jets for calculations and pt ordering pair
      // ----------------------------------------------------------------------------

      CalibReaderRewgt = 1.0;
      // only in JECup, JECdn samples
      CalibReaderRewgt_JESup = 1.0;
      CalibReaderRewgt_JESdn = 1.0;
      // b-flavor only
      CalibReaderRewgt_LFup = 1.0;
      CalibReaderRewgt_LFdn = 1.0;
      CalibReaderRewgt_HFstat1up = 1.0;
      CalibReaderRewgt_HFstat1dn = 1.0;
      CalibReaderRewgt_HFstat2up = 1.0;
      CalibReaderRewgt_HFstat2dn = 1.0;
      // c-flavor only
      CalibReaderRewgt_CFerr1up = 1.0;
      CalibReaderRewgt_CFerr1dn = 1.0;
      CalibReaderRewgt_CFerr2up = 1.0;
      CalibReaderRewgt_CFerr2dn = 1.0;
      // udsg-flavor only
      CalibReaderRewgt_HFup = 1.0;
      CalibReaderRewgt_HFdn = 1.0;
      CalibReaderRewgt_LFstat1up = 1.0;
      CalibReaderRewgt_LFstat1dn = 1.0;
      CalibReaderRewgt_LFstat2up = 1.0;
      CalibReaderRewgt_LFstat2dn = 1.0;

      for(unsigned int ijet=0; ijet < AK4JetPt_singleLepCalc->size(); ijet++){

	// ----------------------------------------------------------------------------
	// Basic cuts
	// ----------------------------------------------------------------------------

	if(AK4JetPt_singleLepCalc->at(ijet) < jetPtCut || fabs(AK4JetEta_singleLepCalc->at(ijet)) > jetEtaCut) continue;

	if(isMC){

	  // ----------------------------------------------------------------------------
	  // Discriminator reweighting b-tagging Scale factor
	  // ----------------------------------------------------------------------------

	  int flav = AK4JetFlav_singleLepCalc->at(ijet);
	  double ak4jetpt = AK4JetPt_singleLepCalc->at(ijet);
	  double jeteta = AK4JetEta_singleLepCalc->at(ijet);
	  double jetcsv = AK4JetBDisc_singleLepCalc->at(ijet);

	  BTagEntryForLJMet::JetFlavor jf;
	  if(abs(flav) == 5) jf = BTagEntryForLJMet::FLAV_B;
	  else if(abs(flav) == 4) jf = BTagEntryForLJMet::FLAV_C;
	  else jf = BTagEntryForLJMet::FLAV_UDSG;
	  
	  if(isNOMshift){
	    CalibReaderRewgt *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	    if(abs(flav) == 5){
	      CalibReaderRewgt_LFup *= reader.eval_auto_bounds("up_lf",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFdn *= reader.eval_auto_bounds("down_lf",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFstat1up *= reader.eval_auto_bounds("up_hfstats1",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFstat1dn *= reader.eval_auto_bounds("down_hfstats1",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFstat2up *= reader.eval_auto_bounds("up_hfstats2",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFstat2dn *= reader.eval_auto_bounds("down_hfstats2",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_CFerr1up *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_CFerr1dn *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_CFerr2up *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_CFerr2dn *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFup *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFdn *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFstat1up *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFstat1dn *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFstat2up *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFstat2dn *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	    }else if(abs(flav) == 4){
	      CalibReaderRewgt_CFerr1up *= reader.eval_auto_bounds("up_cferr1",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_CFerr1dn *= reader.eval_auto_bounds("down_cferr1",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_CFerr2up *= reader.eval_auto_bounds("up_cferr2",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_CFerr2dn *= reader.eval_auto_bounds("down_cferr2",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFup *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFdn *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFstat1up *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFstat1dn *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFstat2up *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFstat2dn *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFup *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFdn *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFstat1up *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFstat1dn *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFstat2up *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFstat2dn *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	    }else{
	      CalibReaderRewgt_HFup *= reader.eval_auto_bounds("up_hf",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFdn *= reader.eval_auto_bounds("down_hf",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFstat1up *= reader.eval_auto_bounds("up_lfstats1",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFstat1dn *= reader.eval_auto_bounds("down_lfstats1",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFstat2up *= reader.eval_auto_bounds("up_lfstats2",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFstat2dn *= reader.eval_auto_bounds("down_lfstats2",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_CFerr1up *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_CFerr1dn *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_CFerr2up *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_CFerr2dn *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFup *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_LFdn *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFstat1up *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFstat1dn *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFstat2up *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	      CalibReaderRewgt_HFstat2dn *= reader.eval_auto_bounds("central",jf,jeteta,ak4jetpt,jetcsv); 
	    }
	  }else if(isJECshift){
	    CalibReaderRewgt_JESup *= reader.eval_auto_bounds("up_jes",jf,jeteta,ak4jetpt,jetcsv); 
	    CalibReaderRewgt_JESdn *= reader.eval_auto_bounds("down_jes",jf,jeteta,ak4jetpt,jetcsv); 
	  }
	}
      }
	
      // ----------------------------------------------------------------------------
      // DONE!! Write the tree
      // ----------------------------------------------------------------------------
      npass_all++;

      outputTree->Fill();
   }
   std::cout<<"Npassed_ALL            = "<<npass_all<<" / "<<nentries<<std::endl;
   outputTree->Write();

}
