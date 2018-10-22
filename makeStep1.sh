#!/bin/bash

hostname

infilename=${1}
outfilename=${2}
inputDir=${3}
outputDir=${4}
minid=${5}
maxid=${6}

scratch=${PWD}
macroDir=${PWD}
source /cvmfs/cms.cern.ch/cmsset_default.sh
scramv1 project CMSSW CMSSW_9_4_6_patch1
cd CMSSW_9_4_6_patch1
eval `scramv1 runtime -sh`
cd -

export PATH=$PATH:$macroDir

XRDpath=root://cmseos.fnal.gov/$inputDir
#root -l -b -q makeStep1.C\(\"$macroDir\",\"$XRDpath/$infilename\",\"$outfilename\"\)

for iFile in $(seq $minid $maxid); do
    echo $iFile
    root -l -b -q makeStep1.C\(\"$macroDir\",\"$XRDpath/${infilename}_${iFile}.root\",\"${outfilename}_${iFile}.root\"\)
done


echo "ROOT Files:"
ls -l *.root

# copy output to eos

echo "xrdcp output for condor"
for FILE in *.root
do
  echo "xrdcp -f ${FILE} root://cmseos.fnal.gov/${outputDir}/${FILE}"
  xrdcp -f ${FILE} root://cmseos.fnal.gov/${outputDir}/${FILE} 2>&1
  XRDEXIT=$?
  if [[ $XRDEXIT -ne 0 ]]; then
    rm *.root
    echo "exit code $XRDEXIT, failure in xrdcp"
    exit $XRDEXIT
  fi
  rm ${FILE}
done

echo "done"