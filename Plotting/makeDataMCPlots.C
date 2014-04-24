{
   gROOT->ProcessLine(".L scripts/Plotter.C");
   
   //Mu Channel
   
   makePlot("jet_0_pt_WprimeCalc","TH",50,0,500,"nTightMuons_CommonCalc==1","19300.","mu","Leading Jet p_{T}","GeV",false,false,false,true);   
   makePlot("jet_0_pt_WprimeCalc","TH",50,0,1500,"nTightMuons_CommonCalc==1","19300.","mu","Leading Jet p_{T}","GeV",false,true,false,true);   

   makePlot("jet_1_pt_WprimeCalc","TH",50,0,400,"nTightMuons_CommonCalc==1","19300.","mu","2nd Jet p_{T}","GeV",false,false,false,true);   
   makePlot("jet_1_pt_WprimeCalc","TH",50,0,750,"nTightMuons_CommonCalc==1","19300.","mu","2nd Jet p_{T}","GeV",false,true,false,true);   

   makePlot("jet_2_pt_WprimeCalc","TH",50,0,200,"nTightMuons_CommonCalc==1","19300.","mu","3rd Jet p_{T}","GeV",false,false,false,true);   
   makePlot("jet_2_pt_WprimeCalc","TH",50,0,500,"nTightMuons_CommonCalc==1","19300.","mu","3rd Jet p_{T}","GeV",false,true,false,true);   

   makePlot("jet_3_pt_WprimeCalc","TH",50,0,100,"nTightMuons_CommonCalc==1","19300.","mu","4th Jet p_{T}","GeV",false,false,false,true);   
   makePlot("jet_3_pt_WprimeCalc","TH",50,0,300,"nTightMuons_CommonCalc==1","19300.","mu","4th Jet p_{T}","GeV",false,true,false,true);   

   makePlot("jet_0_eta_WprimeCalc","TH",50,-5.0,5.0,"nTightMuons_CommonCalc==1","19300.","mu","Leading Jet #eta","",false,false,false,true);   
   makePlot("jet_1_eta_WprimeCalc","TH",50,-5.0,5.0,"nTightMuons_CommonCalc==1","19300.","mu","2nd Jet #eta","",false,false,false,true);   
   makePlot("jet_2_eta_WprimeCalc","TH",50,-5.0,5.0,"nTightMuons_CommonCalc==1","19300.","mu","3rd Jet #eta","",false,false,false,true);   
   makePlot("jet_3_eta_WprimeCalc","TH",50,-5.0,5.0,"nTightMuons_CommonCalc==1","19300.","mu","4th Jet #eta","",false,false,false,true);   
   makePlot("jet_0_tag_WprimeCalc","TH",2,0,2,"nTightMuons_CommonCalc==1","19300.","mu","Leading Jet tag","",false,false,false,true);   
   makePlot("jet_1_tag_WprimeCalc","TH",2,0,2,"nTightMuons_CommonCalc==1","19300.","mu","2nd Jet tag","",false,false,false,true);   
   makePlot("jet_2_tag_WprimeCalc","TH",2,0,2,"nTightMuons_CommonCalc==1","19300.","mu","3rd Jet tag","",false,false,false,true);   
   makePlot("jet_3_tag_WprimeCalc","TH",2,0,2,"nTightMuons_CommonCalc==1","19300.","mu","4th Jet tag","",false,false,false,true);   

   makePlot("corr_met_WprimeCalc","TH",50,0,150,"nTightMuons_CommonCalc==1","19300.","mu","MET","GeV",false,false,false,true);   
   makePlot("corr_met_phi_WprimeCalc","TH",32,-3.2,3.2,"nTightMuons_CommonCalc==1","19300.","mu","MET #phi","",false,false,false,true);   

   makePlot("muon_1_pt_WprimeCalc","TH",50,0,150,"nTightMuons_CommonCalc==1","19300.","mu","#mu p_{T}","GeV",false,false,false,true);   
   makePlot("muon_1_eta_WprimeCalc","TH",50,-2.5,2.5,"nTightMuons_CommonCalc==1","19300.","mu","#mu #eta","",false,false,false,true);   

   makePlot("n_btags_WprimeCalc","TH",6,0,6,"nTightMuons_CommonCalc==1","19300.","mu","BTagged Jets","",false,false,false,true);   
   makePlot("nSelJets_CommonCalc","TH",9,0,9,"nTightMuons_CommonCalc==1","19300.","mu","Selected Jets","",false,false,false,true);   

   makePlot("Ht2_LjetsTopoCalcNew","TH",50,1,1500,"nTightMuons_CommonCalc==1","19300.","mu","H_{t2}","GeV",false,false,false,true);   
   makePlot("Ht2_LjetsTopoCalcNew","TH",50,1,1500,"nTightMuons_CommonCalc==1","19300.","mu","H_{t2}","GeV",false,true,false,true);   

   makePlot("LeptonJet_DeltaR_LjetsTopoCalcNew","TH",50,0,5,"nTightMuons_CommonCalc==1","19300.","mu","#DeltaR_{lj}","",false,false,false,true);   

   makePlot("SqrtsT_LjetsTopoCalcNew","TH",50,0,1000,"nTightMuons_CommonCalc==1","19300.","mu","#sqrt{sT}","GeV",false,false,false,true);   
   makePlot("SqrtsT_LjetsTopoCalcNew","TH",50,0,2000,"nTightMuons_CommonCalc==1","19300.","mu","#sqrt{sT}","GeV",false,true,false,true);   

   makePlot("Mevent_LjetsTopoCalcNew","TH",50,0,2500,"nTightMuons_CommonCalc==1","19300.","mu","Event Mass","",false,false,false,true);   
   makePlot("Mevent_LjetsTopoCalcNew","TH",50,0,2500,"nTightMuons_CommonCalc==1","19300.","mu","Event Mass","",false,true,false,true);   

   makePlot("CA8JetPt_JetSubCalc","TH",50,0,800,"nTightMuons_CommonCalc==1&&CA8JetPt_JetSubCalc>200","19300.","mu","CA8 Jet p_{T}","GeV",false,false,false,true);   
   makePlot("CA8JetPt_JetSubCalc","TH",50,0,1500,"nTightMuons_CommonCalc==1&&CA8JetPt_JetSubCalc>200","19300.","mu","CA8 Jet p_{T}","GeV",false,true,false,true);   

   makePlot("CAWJetMass_JetSubCalc","TH",50,0,250,"nTightMuons_CommonCalc==1&&CA8JetPt_JetSubCalc>200","19300.","mu","Pruned CA8 Jet Mass","GeV",false,false,false,true);   
   makePlot("CAWJetMass_JetSubCalc","TH",50,0,250,"nTightMuons_CommonCalc==1&&CA8JetPt_JetSubCalc>200","19300.","mu","Pruned CA8 Jet Mass","GeV",false,true,false,true);   

   makePlot("CA8Tau21_JetSubCalc","TH",50,0,1,"nTightMuons_CommonCalc==1&&CA8JetPt_JetSubCalc>200","19300.","mu","#tau_{21}","",false,false,false,true);   

   //ele Channel
   
//    makePlot("jet_0_pt_WprimeCalc","TH",50,0,750,"nTightMuons_CommonCalc==0","19300.","ele","Leading Jet p_{T}","GeV",false,false,false,true);   
//    makePlot("jet_0_pt_WprimeCalc","TH",50,0,750,"nTightMuons_CommonCalc==0","19300.","ele","Leading Jet p_{T}","GeV",false,true,false,true);   
// 
//    makePlot("jet_1_pt_WprimeCalc","TH",50,0,750,"nTightMuons_CommonCalc==0","19300.","ele","2nd Jet p_{T}","GeV",false,false,false,true);   
//    makePlot("jet_1_pt_WprimeCalc","TH",50,0,750,"nTightMuons_CommonCalc==0","19300.","ele","2nd Jet p_{T}","GeV",false,true,false,true);   
// 
//    makePlot("jet_2_pt_WprimeCalc","TH",50,0,750,"nTightMuons_CommonCalc==0","19300.","ele","3rd Jet p_{T}","GeV",false,false,false,true);   
//    makePlot("jet_2_pt_WprimeCalc","TH",50,0,750,"nTightMuons_CommonCalc==0","19300.","ele","3rd Jet p_{T}","GeV",false,true,false,true);   
// 
//    makePlot("jet_3_pt_WprimeCalc","TH",50,0,750,"nTightMuons_CommonCalc==0","19300.","ele","4th Jet p_{T}","GeV",false,false,false,true);   
//    makePlot("jet_3_pt_WprimeCalc","TH",50,0,750,"nTightMuons_CommonCalc==0","19300.","ele","4th Jet p_{T}","GeV",false,true,false,true);   
// 
//    makePlot("jet_0_eta_WprimeCalc","TH",50,-5.0,5.0,"nTightMuons_CommonCalc==0","19300.","ele","Leading Jet #eta","",false,false,false,true);   
//    makePlot("jet_1_eta_WprimeCalc","TH",50,-5.0,5.0,"nTightMuons_CommonCalc==0","19300.","ele","2nd Jet #eta","",false,false,false,true);   
//    makePlot("jet_2_eta_WprimeCalc","TH",50,-5.0,5.0,"nTightMuons_CommonCalc==0","19300.","ele","3rd Jet #eta","",false,false,false,true);   
//    makePlot("jet_3_eta_WprimeCalc","TH",50,-5.0,5.0,"nTightMuons_CommonCalc==0","19300.","ele","4th Jet #eta","",false,false,false,true);   
//    makePlot("jet_0_tag_WprimeCalc","TH",2,0,2,"nTightMuons_CommonCalc==0","19300.","ele","Leading Jet tag","",false,false,false,true);   
//    makePlot("jet_1_tag_WprimeCalc","TH",2,0,2,"nTightMuons_CommonCalc==0","19300.","ele","2nd Jet tag","",false,false,false,true);   
//    makePlot("jet_2_tag_WprimeCalc","TH",2,0,2,"nTightMuons_CommonCalc==0","19300.","ele","3rd Jet tag","",false,false,false,true);   
//    makePlot("jet_3_tag_WprimeCalc","TH",2,0,2,"nTightMuons_CommonCalc==0","19300.","ele","4th Jet tag","",false,false,false,true);   
// 
// makePlot("corr_met_WprimeCalc","TH",50,0,150,"nTightMuons_CommonCalc==0","19300.","ele","MET","GeV",false,false,false,true);   
//    makePlot("corr_met_phi_WprimeCalc","TH",32,-3.2,3.2,"nTightMuons_CommonCalc==0","19300.","ele","MET #phi","",false,false,false,true);   
// 
// makePlot("elec_1_pt_WprimeCalc","TH",50,0,150,"nTightMuons_CommonCalc==0","19300.","ele","e p_{T}","GeV",false,false,false,true);   
// makePlot("elec_1_eta_WprimeCalc","TH",50,-2.5,2.5,"nTightMuons_CommonCalc==0","19300.","ele","e #eta","",false,false,false,true);   
// 
//    makePlot("n_btags_WprimeCalc","TH",6,0,6,"nTightMuons_CommonCalc==0","19300.","ele","BTagged Jets","",false,false,false,true);   
//    makePlot("nSelJets_CommonCalc","TH",9,0,9,"nTightMuons_CommonCalc==0","19300.","ele","Selected Jets","",false,false,false,true);   
// 
//    makePlot("Ht2_LjetsTopoCalcNew","TH",50,1,1500,"nTightMuons_CommonCalc==0","19300.","ele","H_{t2}","GeV",false,false,false,true);   
//    makePlot("Ht2_LjetsTopoCalcNew","TH",50,1,1500,"nTightMuons_CommonCalc==0","19300.","ele","H_{t2}","GeV",false,true,false,true);   
// 
//    makePlot("LeptonJet_DeltaR_LjetsTopoCalcNew","TH",50,0,5,"nTightMuons_CommonCalc==0","19300.","ele","#DeltaR_{lj}","",false,false,false,true);   
// 
//    makePlot("SqrtsT_LjetsTopoCalcNew","TH",50,0,2000,"nTightMuons_CommonCalc==0","19300.","ele","#sqrt{sT}","GeV",false,false,false,true);   
//    makePlot("SqrtsT_LjetsTopoCalcNew","TH",50,0,2000,"nTightMuons_CommonCalc==0","19300.","ele","#sqrt{sT}","GeV",false,true,false,true);   
// 
//    makePlot("Mevent_LjetsTopoCalcNew","TH",50,0,2500,"nTightMuons_CommonCalc==0","19300.","ele","Event Mass","",false,false,false,true);   
//    makePlot("Mevent_LjetsTopoCalcNew","TH",50,0,2500,"nTightMuons_CommonCalc==0","19300.","ele","Event Mass","",false,true,false,true);   
// 
//    makePlot("CA8JetPt_JetSubCalc","TH",50,0,800,"nTightMuons_CommonCalc==0&&CA8JetPt_JetSubCalc>200","19300.","ele","CA8 Jet p_{T}","GeV",false,false,false,true);   
//    makePlot("CA8JetPt_JetSubCalc","TH",50,0,800,"nTightMuons_CommonCalc==0&&CA8JetPt_JetSubCalc>200","19300.","ele","CA8 Jet p_{T}","GeV",false,true,false,true);   
// 
//    makePlot("CAWJetMass_JetSubCalc","TH",50,0,250,"nTightMuons_CommonCalc==0&&CA8JetPt_JetSubCalc>200","19300.","ele","Pruned CA8 Jet Mass","GeV",false,false,false,true);   
//    makePlot("CAWJetMass_JetSubCalc","TH",50,0,250,"nTightMuons_CommonCalc==0&&CA8JetPt_JetSubCalc>200","19300.","ele","Pruned CA8 Jet Mass","GeV",false,true,false,true);   
// 
//    makePlot("CA8Tau21_JetSubCalc","TH",50,0,1,"nTightMuons_CommonCalc==0&&CA8JetPt_JetSubCalc>200","19300.","ele","#tau_{21}","",false,false,false,true);   
   
}