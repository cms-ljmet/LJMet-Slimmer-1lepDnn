#!/bin/bash

hostname
date

infilename=${1}
outfilename=${2}
inputDir=${3}
outputDir=${4}
scratch=${PWD}
url=${5}

source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc7_amd64_gcc700
scramv1 project CMSSW CMSSW_10_2_16_UL
cd CMSSW_10_2_16_UL

echo "unpacking tar"
tar -xf ${scratch}/slimmerdnn.tar
rm ${scratch}/slimmerdnn.tar

cd src/LJMet-Slimmer-1lepDnn/step2/

echo "cmsenv"
eval `scramv1 runtime -sh`

echo "setting macroDir to PWD"
macroDir=${PWD}
export PATH=$PATH:$macroDir

XRDpath=$url/$inputDir

echo "creating ${outfilename} by reading ${infilename}"
root -l -b -q runStep2Dnn.C\(\"$macroDir\",\"$XRDpath/${infilename}\",\"${outfilename}\"\)

rm *.json

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
