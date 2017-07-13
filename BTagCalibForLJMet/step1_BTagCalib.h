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

   Bool_t          isNOMshift;
   Bool_t          isJECshift;
   Bool_t          isMC;
   
   // Fixed size dimensions of array or collections stored in the TTree if any.

   // NEW BRANCHES

   float CalibReaderRewgt;
   float CalibReaderRewgt_JESup;
   float CalibReaderRewgt_JESdn;
   float CalibReaderRewgt_LFup;
   float CalibReaderRewgt_LFdn;
   float CalibReaderRewgt_HFstat1up;
   float CalibReaderRewgt_HFstat1dn;
   float CalibReaderRewgt_HFstat2up;
   float CalibReaderRewgt_HFstat2dn;
   float CalibReaderRewgt_CFerr1up;
   float CalibReaderRewgt_CFerr1dn;
   float CalibReaderRewgt_CFerr2up;
   float CalibReaderRewgt_CFerr2dn;
   float CalibReaderRewgt_HFup;
   float CalibReaderRewgt_HFdn;
   float CalibReaderRewgt_LFstat1up;
   float CalibReaderRewgt_LFstat1dn;
   float CalibReaderRewgt_LFstat2up;
   float CalibReaderRewgt_LFstat2dn;

   // Declaration of leaf types
   vector<int>     *AK4JetFlav_singleLepCalc;
   vector<double>  *AK4JetBDisc_singleLepCalc;
   vector<double>  *AK4JetEta_singleLepCalc;
   vector<double>  *AK4JetPt_singleLepCalc;

   // List of branches
   TBranch        *b_AK4JetFlav_singleLepCalc;   //!
   TBranch        *b_AK4JetBDisc_singleLepCalc;   //!
   TBranch        *b_AK4JetEta_singleLepCalc;   //!
   TBranch        *b_AK4JetPt_singleLepCalc;   //!
 
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

  isNOMshift = inputFileName.Contains("/nominal/");
  isJECshift = inputFileName.Contains("/JEC");
  isMC      = !inputFileName.Contains("Single");

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
   AK4JetFlav_singleLepCalc = 0;
   AK4JetBDisc_singleLepCalc = 0;
   AK4JetEta_singleLepCalc = 0;
   AK4JetPt_singleLepCalc = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   inputTree = tree;
   fCurrent = -1;
   inputTree->SetMakeClass(1);

   inputTree->SetBranchAddress("AK4JetFlav_singleLepCalc", &AK4JetFlav_singleLepCalc, &b_AK4JetFlav_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetBDisc_singleLepCalc", &AK4JetBDisc_singleLepCalc, &b_AK4JetBDisc_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetEta_singleLepCalc", &AK4JetEta_singleLepCalc, &b_AK4JetEta_singleLepCalc);
   inputTree->SetBranchAddress("AK4JetPt_singleLepCalc", &AK4JetPt_singleLepCalc, &b_AK4JetPt_singleLepCalc);
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
