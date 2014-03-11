#!/bin/sh

mkdir sandbox
cd sanbox

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

hadd Ele2012A.root ../Ele2012A/*.root
hadd Ele2012B.root ../Ele2012B/*.root
hadd Ele2012C.root ../Ele2012C/*.root
hadd Ele2012D.root ../Ele2012D/*.root



