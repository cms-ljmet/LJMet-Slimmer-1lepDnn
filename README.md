# LJMet-Slimmer

Code (step1.cc/.h) to slim LJMet trees. Built on ROOT's MakeClass.
Download the CSC & ECAL bad event files from CMS TWiki!

To test: give input file name in testStep1.C, copy a relevant step1 onto step1.*
Run: root -l testStep1.C

Set up runCondorSlimmerJobs.py to run over LJMet files stored on Fermilab's EOS.
Run with submitSlimmerJobs.sh
Hadd output files with hadd.sh after setting up haddoutput.py

NEW: setup for 76X LJMet files available, see b-tagging differences and hadronic decay matching, etc. The 74X version is still here in step1_for74XLJMet.

