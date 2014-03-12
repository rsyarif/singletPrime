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

hadd TpBW750.root ../TpBW/*.root 
hadd TpTZ750.root ../TpTZ/*.root 
hadd TpTH750.root ../TpTH/*.root

hadd Mu2012A.root ../Mu2012A/*.root
hadd Mu2012B.root ../Mu2012B/*.root
hadd Mu2012C.root ../Mu2012C/*.root
hadd Mu2012D.root ../Mu2012D/*.root
hadd mu2012.root Mu2012*.root

hadd Ele2012A.root ../Ele2012A/*.root
hadd Ele2012B.root ../Ele2012B/*.root
hadd Ele2012C.root ../Ele2012C/*.root
hadd Ele2012D.root ../Ele2012D/*.root
hadd ele2012.root Ele2012*.root


EventWeightsIterative outputFile='TpTH750.root'      doOneD=1   weight=225.2    histoName='histos/nevents'
EventWeightsIterative outputFile='TpTZ750.root'      doOneD=1   weight=225.2    histoName='histos/nevents'
EventWeightsIterative outputFile='TpBW750.root'      doOneD=1   weight=225.2    histoName='histos/nevents'

EventWeightsIterative outputFile='TT_LH.root'        doOneD=1   weight=109.3    histoName='histos/nevents'
EventWeightsIterative outputFile='TT_LL.root'        doOneD=1   weight=26.2     histoName='histos/nevents'
EventWeightsIterative outputFile='TT_HH.root'        doOneD=1   weight=114      histoName='histos/nevents'
hadd TT.root TT_LH.root TT_LL.root TT_HH.root

EventWeightsIterative outputFile='Ttw.root'  	     doOneD=1   weight=11.1     histoName='histos/nevents' 
EventWeightsIterative outputFile='Tbtw.root'  	     doOneD=1   weight=11.1     histoName='histos/nevents' 
EventWeightsIterative outputFile='Ts.root'  	     doOneD=1   weight=3.79     histoName='histos/nevents' 
EventWeightsIterative outputFile='Tbs.root'  	     doOneD=1   weight=1.76     histoName='histos/nevents' 
EventWeightsIterative outputFile='Tt.root'  	     doOneD=1   weight=56.4     histoName='histos/nevents' 
EventWeightsIterative outputFile='Tbt.root'  	     doOneD=1   weight=30.7     histoName='histos/nevents' 
hadd STOP.root Ttw.root Tbtw.root Ts.root Tbs.root Tt.root Tbt.root

EventWeightsIterative outputFile='WJets.root'        doOneD=1   weight=36257    histoName='histos/nevents'

rm Mu2012*.root Ele2012*.root TT_LH.root TT_HH.root TT_LL.root Ttw.root Tbtw.root Ts.root Tbs.root Tt.root Tbt.root