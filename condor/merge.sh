#!/bin/sh

mkdir sandbox
cd sandbox

hadd WJets.root ../WJets/*.root
hadd TT_LH.root ../TT_LH/*.root
hadd TT_LL.root ../TT_LL/*.root
hadd TT_HH.root ../TT_HH/*.root
hadd Ts.root ../T_SChn/*.root
hadd Tt.root ../T_TChn/*.root
hadd Ttw.root ../T_tWChn/*.root
hadd Tbs.root ../Tb_SChn/*.root
hadd Tbt.root ../Tb_TChn/*.root
hadd Tbtw.root ../Tb_tWChn/*.root
hadd WW.root ../WW/*.root
hadd WZ.root ../WZ/*.root
hadd ZZ.root ../ZZ/*.root
hadd ZJets.root ../ZJets/*.root
hadd QCD_170.root ../QCD170/*.root
hadd QCD_300.root ../QCD300/*.root
hadd QCD_470.root ../QCD470/*.root
hadd QCD_600.root ../QCD600/*.root
hadd QCD_800.root ../QCD800/*.root
hadd QCD_1000.root ../QCD1000/*.root
hadd QCD_1400.root ../QCD1400/*.root
hadd QCD_1800.root ../QCD1800/*.root

#hadd TpBW750.root ../TpBW/*.root 
#hadd TpTZ750.root ../TpTZ/*.root 
#hadd TpTH750.root ../TpTH/*.root

hadd Mu2012A.root ../Mu2012A/*.root
hadd Mu2012B.root ../Mu2012B/*.root
hadd Mu2012C_1.root ../Mu2012C/Mu2012C_[1,2,3,4]*.root
hadd Mu2012C_2.root ../Mu2012C/Mu2012C_[5,6,7,8,9]*.root
hadd Mu2012D_1.root ../Mu2012D/Mu2012D_[1,2,3,4]*.root
hadd Mu2012D_2.root ../Mu2012D/Mu2012D_[5,6,7,8,9]*.root
hadd mu2012.root Mu2012*.root

hadd Ele2012A.root ../Ele2012A/*.root
hadd Ele2012B.root ../Ele2012B/*.root
hadd Ele2012C_1.root ../Ele2012C/Ele2012C_[1,2,3,4]*.root
hadd Ele2012C_2.root ../Ele2012C/Ele2012C_[5,6,7,8,9]*.root
hadd Ele2012D_1.root ../Ele2012D/Ele2012D_[1,2,3,4]*.root
hadd Ele2012D_2.root ../Ele2012D/Ele2012D_[5,6,7,8,9]*.root
hadd ele2012.root Ele2012*.root


#EventWeightsIterative outputFile='TpTH750.root'      doOneD=1   weight=1.0   events=     histoName='histos/nevents'
#EventWeightsIterative outputFile='TpTZ750.root'      doOneD=1   weight=1.0   events=     histoName='histos/nevents'
#EventWeightsIterative outputFile='TpBW750.root'      doOneD=1   weight=1.0   events=     histoName='histos/nevents'

EventWeightsIterative outputFile='TT_LH.root'        doOneD=1   weight=104.7   events=25424818	  histoName='histos/nevents'
EventWeightsIterative outputFile='TT_LL.root'        doOneD=1   weight=25.1    events=4246444	  histoName='histos/nevents'
EventWeightsIterative outputFile='TT_HH.root'        doOneD=1   weight=109.2     events=10537444	  histoName='histos/nevents'
hadd TT.root TT_LH.root TT_LL.root TT_HH.root

EventWeightsIterative outputFile='Ttw.root'  	     doOneD=1   weight=11.1    events=497658	  histoName='histos/nevents' 
EventWeightsIterative outputFile='Tbtw.root'  	     doOneD=1   weight=11.1    events=493460	  histoName='histos/nevents' 
EventWeightsIterative outputFile='Ts.root'  	     doOneD=1   weight=3.79    events=259961	  histoName='histos/nevents' 
EventWeightsIterative outputFile='Tbs.root'  	     doOneD=1   weight=1.76    events=139974	  histoName='histos/nevents' 
EventWeightsIterative outputFile='Tt.root'  	     doOneD=1   weight=56.4    events=3758227	  histoName='histos/nevents' 
EventWeightsIterative outputFile='Tbt.root'  	     doOneD=1   weight=30.7    events=1935072	  histoName='histos/nevents' 
hadd STOP.root Ttw.root Tbtw.root Ts.root Tbs.root Tt.root Tbt.root

EventWeightsIterative outputFile='WJets.root'        doOneD=1   weight=36257   events=57709905	  histoName='histos/nevents'
EventWeightsIterative outputFile='ZJets.root'        doOneD=1   weight=3504   events=30459503	  histoName='histos/nevents'

EventWeightsIterative outputFile='WW.root'        	 doOneD=1   weight=56     events=10000431	  histoName='histos/nevents'
EventWeightsIterative outputFile='ZZ.root'        	 doOneD=1   weight=17     events=9799908	  histoName='histos/nevents'
EventWeightsIterative outputFile='WZ.root'        	 doOneD=1   weight=33.6   events=10000283	  histoName='histos/nevents'
hadd VV.root WW.root WZ.root ZZ.root

EventWeightsIterative outputFile='QCD_170.root'        doOneD=1   weight=34138   events=5814398	  histoName='histos/nevents'
EventWeightsIterative outputFile='QCD_300.root'        doOneD=1   weight=1760   	events=5978500	  histoName='histos/nevents'
EventWeightsIterative outputFile='QCD_470.root'        doOneD=1   weight=114   	events=3994848	  histoName='histos/nevents'
EventWeightsIterative outputFile='QCD_600.root'        doOneD=1   weight=27   	events=3996864	  histoName='histos/nevents'
EventWeightsIterative outputFile='QCD_800.root'        doOneD=1   weight=3.6   	events=3998563	  histoName='histos/nevents'
EventWeightsIterative outputFile='QCD_1000.root'       doOneD=1   weight=0.7   	events=1964088	  histoName='histos/nevents'
EventWeightsIterative outputFile='QCD_1400.root'       doOneD=1   weight=0.03   	events=2000062	  histoName='histos/nevents'
EventWeightsIterative outputFile='QCD_1800.root'       doOneD=1   weight=0.002  	events=971974	  histoName='histos/nevents'
hadd QCD.root QCD_*.root

rm Mu2012*.root Ele2012*.root TT_LH.root TT_HH.root TT_LL.root Ttw.root Tbtw.root Ts.root Tbs.root Tt.root Tbt.root WW.root WZ.root ZZ.root QCD_*.root