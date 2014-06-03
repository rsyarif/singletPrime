{
   gROOT->ProcessLine(".L scripts/PlotCompNorm.C");
   
   PlotComp("jet_0_pt_WprimeCalc","40","0","800","Leading Jet p_{T} [GeV]");
   PlotComp("jet_1_pt_WprimeCalc","40","0","600","2nd Jet p_{T} [GeV]");
   PlotComp("jet_2_pt_WprimeCalc","40","0","400","3rd Jet p_{T} [GeV]");
   PlotComp("jet_3_pt_WprimeCalc","40","0","200","4th Jet p_{T} [GeV]");
   PlotComp("jet_0_eta_WprimeCalc","25","-5","5","Leading Jet #eta");
   PlotComp("jet_1_eta_WprimeCalc","25","-5","5","2nd Jet #eta");
   PlotComp("jet_2_eta_WprimeCalc","25","-5","5","3rd Jet #eta");
   PlotComp("jet_3_eta_WprimeCalc","25","-5","5","4th Jet #eta");
   PlotComp("jet_0_tag_WprimeCalc","2","0","2","Leading Jet tagged");
   PlotComp("jet_1_tag_WprimeCalc","2","0","2","2nd Jet tagged");
   PlotComp("jet_2_tag_WprimeCalc","2","0","2","3rd Jet tagged");
   PlotComp("jet_3_tag_WprimeCalc","2","0","2","4th Jet tagged");
   
   PlotComp("corr_met_WprimeCalc","40","0","800","MET [GeV]");
   PlotComp("corr_met_phi_WprimeCalc","32","-3.2","3.2","MET [GeV]");
   
   PlotComp("muon_1_eta_WprimeCalc","25","-5","5","#mu #eta");
   PlotComp("muon_1_pt_WprimeCalc","40","0","400","#mu p_{T}");
   PlotComp("elec_1_eta_WprimeCalc","25","-5","5","e #eta");
   PlotComp("elec_1_pt_WprimeCalc","40","0","400","e p_{T}");
   
   PlotComp("n_btags_WprimeCalc","6","0","6","BTagged Jets");
   PlotComp("nSelJets_CommonCalc","9","0","9","Number of Jets");

   TString Cuts = "CA8Tau2_JetSubCalc/CA8Tau1_JetSubCalc<0.5&&CA8JetPt_JetSubCalc>200";
      
   PlotComp("Jet1Jet2_M_LjetsTopoCalcNew","50","1","2000","M_{jj} (2 Leading Jets)",Cuts);
   PlotComp("Jet1Jet2_Pt_LjetsTopoCalcNew","50","1","1000","p_{t}^{jj} (2 Leading Jets)",Cuts);
   PlotComp("Jet1Jet2W_M_LjetsTopoCalcNew","50","1","3000","M_{jj} W (2 Leading Jets)",Cuts);
   PlotComp("Jet1Jet2W_Pt_LjetsTopoCalcNew","50","1","1000","p_{t}^{jj} W (2 Leading Jets)",Cuts);
   PlotComp("DphiJMET_LjetsTopoCalcNew","32","0","3.2","#Delta#phi(J,MET)",Cuts,"",false);
   PlotComp("dphiLepMet_LjetsTopoCalcNew","32","0","3.2","#Delta#phi(l,MET)",Cuts);
   PlotComp("Ht2_LjetsTopoCalcNew","50","1","1500","H_{t2}",Cuts);
   PlotComp("HT2prime_LjetsTopoCalcNew","50","0","3","H_{t2}^{'}",Cuts);
   PlotComp("Hz_LjetsTopoCalcNew","50","1","4000","H_{z}",Cuts);
   PlotComp("LeptonJet_DeltaR_LjetsTopoCalcNew","50","0","5","#DeltaR_{lj}",Cuts);
   PlotComp("W_MT_LjetsTopoCalcNew","50","0","500","M_{T}(l,MET)",Cuts);
   PlotComp("W_Pt_LjetsTopoCalcNew","50","0","1000","p_{T}(l,MET)",Cuts);
   PlotComp("JetEtaMax_LjetsTopoCalcNew","50","0","5","Max jet #eta",Cuts);
   PlotComp("KtminpReduced_LjetsTopoCalcNew","50","0","2000","K_{t} minp reduced?",Cuts);
   PlotComp("Ktminp_LjetsTopoCalcNew","50","0","20","K_{t} minp",Cuts);
   PlotComp("PzOverHT_LjetsTopoCalcNew","50","-10","10","P_{z}/H_{T}",Cuts);
   PlotComp("SqrtsT_LjetsTopoCalcNew","50","0","2000","#sqrt{sT}",Cuts);
   PlotComp("BTagTopMass_LjetsTopoCalcNew","50","1","2000","BTagTopMass",Cuts);
   PlotComp("Mevent_LjetsTopoCalcNew","50","0","2500","Event Mass",Cuts);

   PlotComp("CA8JetPt_JetSubCalc","50","0","800","CA8 Jet p_{T}");
   PlotComp("CA8Tau1_JetSubCalc","50","0","1","#tau_{1}","CA8JetPt_JetSubCalc>200");
   PlotComp("CA8Tau2_JetSubCalc","50","0","1","#tau_{2}","CA8JetPt_JetSubCalc>200");
   PlotComp("CA8Tau3_JetSubCalc","50","0","1","#tau_{3}","CA8JetPt_JetSubCalc>200");
   PlotComp("CA8Tau4_JetSubCalc","50","0","1","#tau_{4}","CA8JetPt_JetSubCalc>200");
   PlotComp("CA8Tau21_JetSubCalc","50","0","1","#tau_{21}","CA8JetPt_JetSubCalc>200","",false);
   
   PlotComp("CAWJetCSV_JetSubCalc","50","0","1","Pruned Jet CSV","CA8JetPt_JetSubCalc>200");
   PlotComp("CAWJetMass_JetSubCalc","50","0","250","Pruned Jet Mass [GeV]","CA8JetPt_JetSubCalc>200");
   PlotComp("CAWJetMass_JetSubCalc","50","0","250","Pruned Jet Mass [GeV]","CA8Tau2_JetSubCalc/CA8Tau1_JetSubCalc<0.5&&CA8JetPt_JetSubCalc>200","JetMassATau21");
   PlotComp("CA8Tau21_JetSubCalc","50","0","1","#tau_{21}","CA8JetMass_JetSubCalc>80","JetTau21AMass80",false);
   
   PlotComp("BestTop_LjetsTopoCalcNew","50","0","1200","Best Top Mass",Cuts);
   PlotComp("Centrality_LjetsTopoCalcNew","50","0","1","Centrality",Cuts,"",false);
   PlotComp("Sphericity_LjetsTopoCalcNew","50","0","1","Sphericity",Cuts);
   PlotComp("aplanarity_LjetsTopoCalcNew","50","0","1","Aplanarity",Cuts);
   PlotComp("Cos_BestJetLepton_BestTop_LjetsTopoCalcNew","50","0","1","Centrality",Cuts);
   PlotComp("CAWCSVLSubJets_JetSubCalc","5","0","5","CSVL BTagged Subjets",Cuts);
   PlotComp("CAWCSVMSubJets_JetSubCalc","5","0","5","CSVM BTagged Subjets",Cuts);
   PlotComp("CAWCSVTSubJets_JetSubCalc","5","0","5","CSVT BTagged Subjets",Cuts);
   PlotComp("CAHEPTopJetMass_JetSubCalc","25","0","500","HEP Top Tagged Mass [GeV]",Cuts);
   
   
}