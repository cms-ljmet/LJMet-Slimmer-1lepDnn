#!/bin/bash

echo "HADDING NOMINAL"

python -u haddoutput.py LJMet_1lepTT_031516_step1 LJMet_1lepTT_031516_step1hadds nominal

echo "HADDING JECUP"

python -u haddoutput.py LJMet_1lepTT_031516_step1 LJMet_1lepTT_031516_step1hadds JECup

echo "HADDING JECDOWN"
python -u haddoutput.py LJMet_1lepTT_031516_step1 LJMet_1lepTT_031516_step1hadds JECdown

echo "HADDING JERUP"

python -u haddoutput.py LJMet_1lepTT_031516_step1 LJMet_1lepTT_031516_step1hadds JERup

echo "HADDING JERDOWN"

python -u haddoutput.py LJMet_1lepTT_031516_step1 LJMet_1lepTT_031516_step1hadds JERdown

echo "HADDING BTAGUP"

python -u haddoutput.py LJMet_1lepTT_031516_step1 LJMet_1lepTT_031516_step1hadds BTAGup

echo "HADDING BTAGDOWN"

python -u haddoutput.py LJMet_1lepTT_031516_step1 LJMet_1lepTT_031516_step1hadds BTAGdown

echo "DONE"
