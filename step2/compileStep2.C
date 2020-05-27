{

  // close but not quite, internal linkages needed in Eigen
  //  gROOT->ProcessLine(".include /cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/eigen/c7dc0a897676/include/eigen3");
  //  gROOT->LoadMacro("/uscms_data/d3/jmanagan/CMSSW_9_4_6_patch1/src/lwtnn/lwtnn/src/parse_json.cxx");
  //  gROOT->LoadMacro("/uscms_data/d3/jmanagan/CMSSW_9_4_6_patch1/src/lwtnn/lwtnn/src/LightweightNeuralNetwork.cxx");

  // works
  gSystem->Load("/uscms_data/d3/jmanagan/CMSSW_9_4_6_patch1/lib/slc6_amd64_gcc630/liblwtnnlwtnn.so");
  gROOT->LoadMacro("step2.cc+");
}
