#!/bin/bash

date

echo "SUBMITTING nominal"

python -u runCondorSlimmerJobs.py

echo "DONE"

date

