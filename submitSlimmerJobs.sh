#!/bin/bash

date

echo "SUBMITTING nominal"

python -u makeStep1condor.py nominal

sleep 5

echo "SUBMITTING JECup"

python -u makeStep1condor.py JECup

sleep 5

echo "SUBMITTING JECdown"

python -u makeStep1condor.py JECdown

sleep 5

echo "SUBMITTING JERup"

python -u makeStep1condor.py JERup

sleep 5

echo "SUBMITTING JERdown"

python -u makeStep1condor.py JERdown

sleep 5

echo "SUBMITTING BTAGup"

python -u makeStep1condor.py BTAGup

sleep 5

echo "SUBMITTING BTAGdown"

python -u makeStep1condor.py BTAGdown

sleep 5

echo "DONE"

date

