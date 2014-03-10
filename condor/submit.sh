#!/bin/sh

####### MC Signal

if [ "$1" == true ]; 
then

python singletPrimeSubmit.py --useMC True --sample TpBW --fileList TprimeToBW_750_Madgraph.txt --submit True
python singletPrimeSubmit.py --useMC True --sample TpTH --fileList TprimeToTH_750_Madgraph.txt --submit True
python singletPrimeSubmit.py --useMC True --sample TpTZ --fileList TprimeToTZ_750_Madgraph.txt --submit True

fi

####### MC Background

if [ "$2" == true ]; 
then

python singletPrimeSubmit.py --useMC True --sample WJets --fileList WJets_Madgraph.txt --submit True
python singletPrimeSubmit.py --useMC True --sample W1Jets --fileList W1Jets_Madgraph.txt --submit True
python singletPrimeSubmit.py --useMC True --sample TT_LH --fileList TTJETS_SemiLeptonic_Madgraph.txt --submit True
python singletPrimeSubmit.py --useMC True --sample TT_LL --fileList TTJETS_Leptonic_Madgraph.txt --submit True
python singletPrimeSubmit.py --useMC True --sample TT_HH --fileList TTJETS_Hadronic_Madgraph.txt --submit True
python singletPrimeSubmit.py --useMC True --sample T_SChn --fileList T_SChannel_Powheg.txt --submit True
python singletPrimeSubmit.py --useMC True --sample T_TChn --fileList T_TChannel_Powheg.txt --submit True
python singletPrimeSubmit.py --useMC True --sample T_tWChn --fileList T_tWChannel_Powheg.txt --submit True
python singletPrimeSubmit.py --useMC True --sample Tb_SChn --fileList TBar_SChannel_Powheg.txt --submit True
python singletPrimeSubmit.py --useMC True --sample Tb_TChn --fileList TBar_TChannel_Powheg.txt --submit True
python singletPrimeSubmit.py --useMC True --sample Tb_tWChn --fileList TBar_tWChannel_Powheg.txt --submit True


fi

####### Data

if [ "$3" == true ]; 
then

python singletPrimeSubmit.py --useMC False --sample Mu2012A --fileList singleMu2012A_22Jan2013.txt --json Jan222013ReReco_json.txt --submit True
python singletPrimeSubmit.py --useMC False --sample Mu2012B --fileList singleMu2012B_22Jan2013.txt --json Jan222013ReReco_json.txt --submit True
python singletPrimeSubmit.py --useMC False --sample Mu2012C --fileList singleMu2012C_22Jan2013.txt --json Jan222013ReReco_json.txt --submit True
python singletPrimeSubmit.py --useMC False --sample Mu2012D --fileList singleMu2012D_22Jan2013.txt --json Jan222013ReReco_json.txt --submit True

fi