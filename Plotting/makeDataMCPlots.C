{
   gROOT->ProcessLine(".L scripts/Plotter.C");
   
   /*Define Cut*/

   std::string mu_cut = "nTightMuons_CommonCalc==1";
   std::string more_cuts =  "CA8Tau21_JetSubCalc[0]<0.5&&CA8WJetPt_JetSubCalc>200";

   /*Folder to save in*/
   std::string parent_folder = "Plots";
   TString cmd = "mkdir "+parent_folder;
   gSystem->Exec(cmd);   
   std::string folder1 = parent_folder+"/Plots_ALL";
   TString cmd ="mkdir "+folder1;
   gSystem->Exec(cmd);
   std::string folder2 = parent_folder+"/Plots_THTZ_moreCuts";
   TString cmd ="mkdir "+folder2;
   gSystem->Exec(cmd);
   std::string folder3 = parent_folder+"/Plots_BW_moreCuts";
   TString cmd ="mkdir "+folder3;
   gSystem->Exec(cmd);
   
   /*Mu Channel - ALL decay*/
//    
//    makePlot("AllJets_M_LjetsTopoCalcNew","ALL",50,0,3000,mu_cut,"19300.","mu","AllJets M LjetsTopoCalcNew","",false,false,false,true,folder1);
//    makePlot("AllJets_M_LjetsTopoCalcNew","ALL",50,0,5000,mu_cut,"19300.","mu","AllJets M LjetsTopoCalcNew","",false,true,false,true,folder1);
//    
//    makePlot("BTagTopMass_LjetsTopoCalcNew","ALL",50,0,4000,mu_cut,"19300.","mu","BTagTopMass LjetsTopoCalcNew","GeV",false,false,false,true,folder1);
//    makePlot("BTagTop_Pt_LjetsTopoCalcNew","ALL",50,0,1000,mu_cut,"19300.","mu","BTagTop Pt LjetsTopoCalcNew","GeV",false,false,false,true,folder1);
//    
//    makePlot("BestJetJet2W_M_LjetsTopoCalcNew","ALL",50,0,2000,mu_cut,"19300.","mu","BestJetJet2W M LjetsTopoCalcNew","",false,false,false,true,folder1);
//    makePlot("BestTop_LjetsTopoCalcNew","ALL",50,0,1000,mu_cut,"19300.","mu","BestTop LjetsTopoCalcNew ","GeV",false,false,false,true,folder1);
//    makePlot("BestTop_Pt_LjetsTopoCalcNew","ALL",50,0,500,mu_cut,"19300.","mu","BestTop Pt LjetsTopoCalcNew ","GeV",false,false,false,true,folder1);
// 
//    makePlot("Centrality_LjetsTopoCalcNew","ALL",50,0,1,mu_cut,"19300.","mu","Centrality LjetsTopoCalcNew","",false,false,false,true,folder1);
//    makePlot("Cos_BestJetLepton_BestTop_LjetsTopoCalcNew","ALL",50,-1,1,mu_cut,"19300.","mu","Cos BestJetLepton BestTop LjetsTopoCalcNew","",false,false,false,true,folder1);
// 
//    makePlot("DphiJMET_LjetsTopoCalcNew","ALL",50,0,4,mu_cut,"19300.","mu","DphiJMET LjetsTopoCalcNew","",true,false,false,true,folder1);
//    makePlot("DphiMuMet_LjetsTopoCalcNew","ALL",50,0,4,mu_cut,"19300.","mu","DphiMuMet LjetsTopoCalcNew","",true,false,false,true,folder1);
//    makePlot("DrMinJetJet_LjetsTopoCalcNew","ALL",40,0,8,mu_cut,"19300.","mu","DrMinJetJet LjetsTopoCalcNew","",false,false,false,true,folder1);
//    makePlot("DrMinJetJet_LjetsTopoCalcNew","ALL",40,0,8,mu_cut,"19300.","mu","DrMinJetJet LjetsTopoCalcNew","",false,true,false,true,folder1);
// 
//    makePlot("Et3_LjetsTopoCalcNew","ALL",50,0,1200,mu_cut,"19300.","mu","Et3","",false,true,false,true,folder1);
//    makePlot("Eta2Sum_LjetsTopoCalcNew","ALL",50,0,50,mu_cut,"19300.","mu","Eta2Sum","",false,true,false,true,folder1);
// 
//    makePlot("HT2_LjetsTopoCalcNew","ALL",50,0,1500,mu_cut,"19300.","mu","HT2 LjetsTopoCalcNew","",false,true,false,true,folder1);
//    makePlot("HT2prime_LjetsTopoCalcNew","ALL",50,0,5,mu_cut,"19300.","mu","HT2prime LjetsTopoCalcNew","",false,true,false,true,folder1);
//    makePlot("HT_AllJets_MinusBestJet_LjetsTopoCalcNew","ALL",50,0,5000,mu_cut,"19300.","mu","HT AllJets MinusBestJet LjetsTopoCalcNew","",false,true,false,true,folder1);
//    makePlot("H_AllJets_MinusBestJet_LjetsTopoCalcNew","ALL",50,0,3000,mu_cut,"19300.","mu","H AllJets MinusBestJet LjetsTopoCalcNew","",false,true,false,true,folder1);
//    makePlot("H_LjetsTopoCalcNew","ALL",50,0,5000,mu_cut,"19300.","mu","H LjetsTopoCalcNew","",false,false,false,true,folder1);
//    makePlot("H_LjetsTopoCalcNew","ALL",50,0,5000,mu_cut,"19300.","mu","H LjetsTopoCalcNew","",false,true,false,true,folder1);
//    
//    makePlot("Ht2_LjetsTopoCalcNew","ALL",50,1,1500,mu_cut,"19300.","mu","H_{t2}","GeV",false,false,false,true,folder1);   
//    makePlot("Ht2_LjetsTopoCalcNew","ALL",50,1,1500,mu_cut,"19300.","mu","H_{t2}","GeV",false,true,false,true,folder1);   
// 
//    makePlot("Ht2p_LjetsTopoCalcNew","ALL",50,0,10,mu_cut,"19300.","mu","Ht2p LjetsTopoCalcNew","",false,true,false,true,folder1);
//    makePlot("Ht2pp_LjetsTopoCalcNew","ALL",50,0,20,mu_cut,"19300.","mu","Ht2pp LjetsTopoCalcNew","",false,true,false,true,folder1);
//    makePlot("Ht3_LjetsTopoCalcNew","ALL",50,0,1200,mu_cut,"19300.","mu","Ht3 LjetsTopoCalcNew","",false,true,false,true,folder1);
//    makePlot("Ht3p_LjetsTopoCalcNew","ALL",50,0,2,mu_cut,"19300.","mu","Ht3p LjetsTopoCalcNew","",false,true,false,true,folder1);
//    makePlot("Ht3pp_LjetsTopoCalcNew","ALL",50,0,5,mu_cut,"19300.","mu","Ht3pp LjetsTopoCalcNew","",false,true,false,true,folder1);
// 
//    makePlot("Ht_LjetsTopoCalcNew","ALL",50,0,3000,mu_cut,"19300.","mu","Ht LjetsTopoCalcNew","",false,true,false,true,folder1);
//    makePlot("Htp_LjetsTopoCalcNew","ALL",50,0,20,mu_cut,"19300.","mu","Htp LjetsTopoCalcNew","",false,true,false,true,folder1);
//    makePlot("Htpp_LjetsTopoCalcNew","ALL",50,0,100,mu_cut,"19300.","mu","Htpp LjetsTopoCalcNew","",false,true,false,true,folder1);
//    makePlot("Hz_LjetsTopoCalcNew","ALL",50,0,5000,mu_cut,"19300.","mu","Hz LjetsTopoCalcNew","",false,true,false,true,folder1);
// 
//    makePlot("Jet1Jet2W_M_LjetsTopoCalcNew","ALL",50,0,5000,mu_cut,"19300.","mu","Jet1Jet2W M LjetsTopoCalcNew","GeV",false,true,false,true,folder1);
//    makePlot("Jet1Jet2W_Pt_LjetsTopoCalcNew","ALL",50,0,1000,mu_cut,"19300.","mu","Jet1Jet2W Pt LjetsTopoCalcNew","GeV",false,true,false,true,folder1);
//    makePlot("Jet1Jet2_DeltaPhi_LjetsTopoCalcNew","ALL",50,0,4,mu_cut,"19300.","mu","Jet1Jet2 #Delta#phi LjetsTopoCalcNew","",true,true,false,true,folder1);
//    makePlot("Jet1Jet2_DeltaR_LjetsTopoCalcNew","ALL",50,0,10,mu_cut,"19300.","mu","Jet1Jet2 #Delta R LjetsTopoCalcNew","",false,true,false,true,folder1);
//    makePlot("Jet1Jet2_M_LjetsTopoCalcNew","ALL",50,0,3000,mu_cut,"19300.","mu"," Jet1Jet2 M LjetsTopoCalcNew","GeV",false,true,false,true,folder1);
//    makePlot("Jet1Jet2_Pt_LjetsTopoCalcNew","ALL",50,0,1000,mu_cut,"19300.","mu"," Jet1Jet2 Pt LjetsTopoCalcNew","GeV",false,true,false,true,folder1);
//    makePlot("Jet1TagJet2TagW_M_LjetsTopoCalcNew","ALL",50,0,5000,mu_cut,"19300.","mu","Jet1TagJet2TagW M LjetsTopoCalcNew","GeV",false,true,false,true,folder1);
//    makePlot("JetEtaMax_LjetsTopoCalcNew","ALL",50,0,5,mu_cut,"19300.","mu","Jet #eta_max_LjetsTopoCalcNew","",false,true,false,true,folder1);
//    makePlot("KtminpReduced_LjetsTopoCalcNew","ALL",50,0,3500,mu_cut,"19300.","mu","KtminpReduced LjetsTopoCalcNew","",false,true,false,true,folder1);
//    makePlot("Ktminp_LjetsTopoCalcNew","ALL",50,0,50,mu_cut,"19300.","mu","Ktminp LjetsTopoCalcNew","",false,true,false,true,folder1);
// 
//    makePlot("LeptonJet_DeltaR_LjetsTopoCalcNew","ALL",50,0,5,mu_cut,"19300.","mu","#DeltaR_{lj}","",false,false,false,true,folder1);   
// 
//    makePlot("M123inv_LjetsTopoCalcNew","ALL",50,0,5000,mu_cut,"19300.","mu","M123inv","GeV",false,false,false,true,folder1);
//    makePlot("M123inv_LjetsTopoCalcNew","ALL",50,0,5000,mu_cut,"19300.","mu","M123inv","GeV",false,true,false,true,folder1);
//    makePlot("MdijetMin_LjetsTopoCalcNew","ALL",50,0,500,mu_cut,"19300.","mu","MdijetMin","",false,false,false,true,folder1);
//    makePlot("MdijetMin_LjetsTopoCalcNew","ALL",50,0,1500,mu_cut,"19300.","mu","MdijetMin","",false,true,false,true,folder1);
// 
//    makePlot("Mevent_LjetsTopoCalcNew","ALL",50,0,2500,mu_cut,"19300.","mu","Mevent","",false,false,false,true,folder1);
//    makePlot("Mevent_LjetsTopoCalcNew","ALL",50,0,2500,mu_cut,"19300.","mu","Event Mass","",false,true,false,true,folder1);   
// 
//    makePlot("MtAurelio_LjetsTopoCalcNew","ALL",50,100,2000,mu_cut,"19300.","mu","MtAurelio","",false,true,false,true,folder1);
//    makePlot("Mt_LjetsTopoCalcNew","ALL",50,0,100,mu_cut,"19300.","mu","Mt","",true,true,false,true,folder1);
// 
//    makePlot("Mtjets_LjetsTopoCalcNew","ALL",50,0,1000,mu_cut,"19300.","mu","Mtjets","",false,false,false,true,folder1);
//    makePlot("Mtjets_LjetsTopoCalcNew","ALL",50,0,3000,mu_cut,"19300.","mu","Mtjets","",false,true,false,true,folder1);
// 
//    makePlot("MwRec_LjetsTopoCalcNew","ALL",50,0,1000,mu_cut,"19300.","mu","MwRec","",false,true,false,true,folder1);
// 
//    makePlot("NJW_LjetsTopoCalcNew","ALL",50,0,300,mu_cut,"19300.","mu","NJW","",false,true,false,true,folder1);
//    
//    makePlot("PzOverHT_LjetsTopoCalcNew","ALL",50,0,10,mu_cut,"19300.","mu","PzOverHT","",false,true,false,true,folder1);
//    makePlot("PzOverHT_LjetsTopoCalcNew","ALL",50,0,5,mu_cut,"19300.","mu","PzOverHT","",false,false,false,true,folder1);
// 
//    makePlot("Sphericity_LjetsTopoCalcNew","ALL",50,0,1,mu_cut,"19300.","mu","Sphericity","",false,true,false,true,folder1);
// 
//    makePlot("SqrtsT_LjetsTopoCalcNew","ALL",50,0,1000,mu_cut,"19300.","mu","#sqrt{sT}","GeV",false,false,false,true,folder1);   
//    makePlot("SqrtsT_LjetsTopoCalcNew","ALL",50,0,2000,mu_cut,"19300.","mu","#sqrt{sT}","GeV",false,true,false,true,folder1);   
// 
//    makePlot("W_MT_LjetsTopoCalcNew","ALL",50,0,1000,mu_cut,"19300.","mu","W MT","",false,true,false,true,folder1);
//    makePlot("W_M_LjetsTopoCalcNew","ALL",50,50,1500,mu_cut,"19300.","mu","W M","GeV",false,true,false,true,folder1);
// 
//    makePlot("W_Pt_LjetsTopoCalcNew","ALL",50,50,1000,mu_cut,"19300.","mu","W P_t","GeV",false,true,false,true,folder1);
//    makePlot("W_Pt_LjetsTopoCalcNew","ALL",50,50,500,mu_cut,"19300.","mu","W P_t","GeV",false,false,false,true,folder1);
// 
//    makePlot("aplanarity_LjetsTopoCalcNew","ALL",50,0,0.4,mu_cut,"19300.","mu","aplanarity","",false,true,false,true,folder1);
//    
//    makePlot("centrality_LjetsTopoCalcNew","ALL",50,0,1,mu_cut,"19300.","mu","centrality","",true,false,false,true,folder1);
//    makePlot("centrality_LjetsTopoCalcNew","ALL",50,0,1,mu_cut,"19300.","mu","centrality","",true,true,false,true,folder1);
// 
//    makePlot("corr_met_singleLepCalc","ALL",50,0,150,mu_cut,"19300.","mu","MET","GeV",false,false,false,true,folder1);   
//    makePlot("corr_met_phi_singleLepCalc","ALL",32,-3.2,3.2,mu_cut,"19300.","mu","MET #phi","",false,false,false,true,folder1);   
// 
//    makePlot("dphiLepLeadBTagJet_LjetsTopoCalcNew","ALL",50,0,4,mu_cut,"19300.","mu","dphiLepLeadBTagJet","",true,false,false,true,folder1);
//    makePlot("dphiLepLeadBTagJet_LjetsTopoCalcNew","ALL",50,0,4,mu_cut,"19300.","mu","dphiLepLeadBTagJet","",true,true,false,true,folder1);
// 
//    makePlot("dphiLepLightJet_LjetsTopoCalcNew","ALL",50,0,4,mu_cut,"19300.","mu","dphiLepLightJet","",true,false,false,true,folder1);
//    makePlot("dphiLepLightJet_LjetsTopoCalcNew","ALL",50,0,4,mu_cut,"19300.","mu","dphiLepLightJet","",true,true,false,true,folder1);
//    
//    makePlot("dphiLepMet_LjetsTopoCalcNew","ALL",50,0,4,mu_cut,"19300.","mu","dphiLepMet","",false,false,false,true,folder1);
//    makePlot("dphiLepMet_LjetsTopoCalcNew","ALL",50,0,4,mu_cut,"19300.","mu","dphiLepMet","",false,true,false,true,folder1);
// 
//    makePlot("dphiLepSecLeadBTagJet_LjetsTopoCalcNew","ALL",50,0,4,mu_cut,"19300.","mu","dphiLepSecLeadBTagJet","",false,false,false,true,folder1);
//    makePlot("dphiLepSecLeadBTagJet_LjetsTopoCalcNew","ALL",50,0,4,mu_cut,"19300.","mu","dphiLepSecLeadBTagJet","",false,true,false,true,folder1);
// 
//    makePlot("h_LjetsTopoCalcNew","ALL",50,200,3000,mu_cut,"19300.","mu","h","",false,false,false,true,folder1);
//    makePlot("h_LjetsTopoCalcNew","ALL",50,200,5000,mu_cut,"19300.","mu","h","",false,true,false,true,folder1);
// 
//    makePlot("ht_LjetsTopoCalcNew","ALL",50,200,3000,mu_cut,"19300.","mu","ht","",false,true,false,true,folder1);
//    makePlot("ht_LjetsTopoCalcNew","ALL",50,200,1000,mu_cut,"19300.","mu","ht","",false,false,false,true,folder1);
// 
//    makePlot("htpluslepton_LjetsTopoCalcNew","ALL",50,200,1000,mu_cut,"19300.","mu","ht plus lepton","",false,false,false,true,folder1);
//    makePlot("htpluslepton_LjetsTopoCalcNew","ALL",50,200,3000,mu_cut,"19300.","mu","ht plus lepton","",false,true,false,true,folder1);
// 
//    makePlot("ktMinPrime_LjetsTopoCalcNew","ALL",50,0,20,mu_cut,"19300.","mu","ktMinPrime","",false,true,false,true,folder1);
// 
//    makePlot("maxJetEta_LjetsTopoCalcNew","ALL",50,0,5,mu_cut,"19300.","mu","maxJetEta","",false,true,false,true,folder1);
//    makePlot("maxJetEta_LjetsTopoCalcNew","ALL",50,0,5,mu_cut,"19300.","mu","maxJetEta","",false,false,false,true,folder1);
// 
//    makePlot("methtpluslepton_LjetsTopoCalcNew","ALL",50,100,3000,mu_cut,"19300.","mu","methtpluslepton","",false,true,false,true,folder1);
//    makePlot("methtpluslepton_LjetsTopoCalcNew","ALL",50,100,3000,mu_cut,"19300.","mu","methtpluslepton","",false,false,false,true,folder1);
// 
//    makePlot("minDijetDeltaR_LjetsTopoCalcNew","ALL",50,0,10,mu_cut,"19300.","mu","minDijetDeltaR","",false,false,false,true,folder1);
//    makePlot("minDijetDeltaR_LjetsTopoCalcNew","ALL",50,0,10,mu_cut,"19300.","mu","minDijetDeltaR","",false,true,false,true,folder1);
// 
//    makePlot("minDijetMass_LjetsTopoCalcNew","ALL",50,0,3000,mu_cut,"19300.","mu","minDijetMass","GeV",false,true,false,true,folder1);
//    makePlot("minDijetMass_LjetsTopoCalcNew","ALL",50,0,1000,mu_cut,"19300.","mu","minDijetMass","GeV",false,false,false,true,folder1);
// 
//    makePlot("muon_1_RelIso_singleLepCalc","ALL",50,0,0.5,mu_cut,"19300.","mu","#mu Rel Iso","",false,false,false,true,folder1);   
//    makePlot("muon_1_RelIso_singleLepCalc","ALL",50,0,0.5,mu_cut,"19300.","mu","#mu Rel Iso","",false,true,false,true,folder1);   
//    
//    makePlot("muon_1_eta_singleLepCalc","ALL",50,-2.5,2.5,mu_cut,"19300.","mu","#mu #eta","",false,false,false,true,folder1);   
//    makePlot("muon_1_phi_singleLepCalc","ALL",50,-2.5,2.5,mu_cut,"19300.","mu","#mu #phi","",false,false,false,true,folder1);   
//    makePlot("muon_1_pt_singleLepCalc","ALL",50,0,150,mu_cut,"19300.","mu","#mu p_{T}","GeV",false,false,false,true,folder1);   
//    
//    makePlot("sphericity_LjetsTopoCalcNew","ALL",50,0,1,mu_cut,"19300.","mu","sphericity","",false,true,false,true,folder1);
//    
//    makePlot("type1corrmet_phi_singleLepCalc","ALL",50,-4,4,mu_cut,"19300.","mu","type1corrmet_phi_singleLepCalc","",false,false,false,true,folder1);
//    makePlot("type1corrmet_singleLepCalc","ALL",50,00,400,mu_cut,"19300.","mu","type1corrmet_singleLepCalc","",false,false,false,true,folder1);
//    makePlot("type1corrmet_singleLepCalc","ALL",50,00,1000,mu_cut,"19300.","mu","type1corrmet_singleLepCalc","",false,true,false,true,folder1);
// 
//    makePlot("jet_pt_singleLepCalc[0]","ALL",50,180,500,mu_cut,"19300.","mu","Leading Jet p_{T}","GeV",false,false,false,true,folder1);   
//    makePlot("jet_pt_singleLepCalc[0]","ALL",50,150,1500,mu_cut,"19300.","mu","Leading Jet p_{T}","GeV",false,true,false,true,folder1);   
// 
//    makePlot("jet_pt_singleLepCalc[1]","ALL",50,0,400,mu_cut,"19300.","mu","2nd Jet p_{T}","GeV",false,false,false,true,folder1);   
//    makePlot("jet_pt_singleLepCalc[1]","ALL",50,0,750,mu_cut,"19300.","mu","2nd Jet p_{T}","GeV",false,true,false,true,folder1);   
// 
//    makePlot("jet_pt_singleLepCalc[2]","ALL",50,0,200,mu_cut,"19300.","mu","3rd Jet p_{T}","GeV",false,false,false,true,folder1);   
//    makePlot("jet_pt_singleLepCalc[2]","ALL",50,0,500,mu_cut,"19300.","mu","3rd Jet p_{T}","GeV",false,true,false,true,folder1);   
// 
//    makePlot("jet_pt_singleLepCalc[3]","ALL",50,0,100,mu_cut,"19300.","mu","4th Jet p_{T}","GeV",false,false,false,true,folder1);   
//    makePlot("jet_pt_singleLepCalc[3]","ALL",50,0,300,mu_cut,"19300.","mu","4th Jet p_{T}","GeV",false,true,false,true,folder1);   
// 
//    makePlot("jet_eta_singleLepCalc[0]","ALL",50,-5.0,5.0,mu_cut,"19300.","mu","Leading Jet #eta","",false,false,false,true,folder1);   
//    makePlot("jet_eta_singleLepCalc[1]","ALL",50,-5.0,5.0,mu_cut,"19300.","mu","2nd Jet #eta","",false,false,false,true,folder1);   
//    makePlot("jet_eta_singleLepCalc[2]","ALL",50,-5.0,5.0,mu_cut,"19300.","mu","3rd Jet #eta","",false,false,false,true,folder1);   
//    makePlot("jet_eta_singleLepCalc[3]","ALL",50,-5.0,5.0,mu_cut,"19300.","mu","4th Jet #eta","",false,false,false,true,folder1);   
// 
//    makePlot("jet_phi_singleLepCalc[0]","ALL",50,-4,4,mu_cut,"19300.","mu","Leading Jet #phi","GeV",false,false,false,true,folder1);   
//    makePlot("jet_phi_singleLepCalc[0]","ALL",50,-4,4,mu_cut,"19300.","mu","Leading Jet #phi","GeV",false,true,false,true,folder1);   
//    makePlot("jet_phi_singleLepCalc[1]","ALL",50,-4,4,mu_cut,"19300.","mu","2nd Jet #phi","GeV",false,false,false,true,folder1);   
//    makePlot("jet_phi_singleLepCalc[1]","ALL",50,-4,4,mu_cut,"19300.","mu","2nd Jet #phi","GeV",false,true,false,true,folder1);   
//    makePlot("jet_phi_singleLepCalc[2]","ALL",50,-4,4,mu_cut,"19300.","mu","3rd Jet #phi","GeV",false,false,false,true,folder1);   
//    makePlot("jet_phi_singleLepCalc[2]","ALL",50,-4,4,mu_cut,"19300.","mu","3rd Jet #phi","GeV",false,true,false,true,folder1);   
//    makePlot("jet_phi_singleLepCalc[3]","ALL",50,-4,4,mu_cut,"19300.","mu","4th Jet #phi","GeV",false,false,false,true,folder1);   
//    makePlot("jet_phi_singleLepCalc[3]","ALL",50,-4,4,mu_cut,"19300.","mu","4th Jet #phi","GeV",false,true,false,true,folder1);   
//    
//    makePlot("jet_tag_singleLepCalc[0]","ALL",2,0,2,mu_cut,"19300.","mu","Leading Jet tag","",false,false,false,true,folder1);   
//    makePlot("jet_tag_singleLepCalc[1]","ALL",2,0,2,mu_cut,"19300.","mu","2nd Jet tag","",false,false,false,true,folder1);   
//    makePlot("jet_tag_singleLepCalc[2]","ALL",2,0,2,mu_cut,"19300.","mu","3rd Jet tag","",false,false,false,true,folder1);   
//    makePlot("jet_tag_singleLepCalc[3]","ALL",2,0,2,mu_cut,"19300.","mu","4th Jet tag","",false,false,false,true,folder1);   
// 
//    makePlot("bjet_pt_singleLepCalc[0]","ALL",50,0,500,mu_cut,"19300.","mu","Leading bJet p_{T}","GeV",false,false,false,true,folder1);   
//    makePlot("bjet_pt_singleLepCalc[0]","ALL",50,0,1500,mu_cut,"19300.","mu","Leading bJet p_{T}","GeV",false,true,false,true,folder1);   
//    makePlot("bjet_pt_singleLepCalc[1]","ALL",50,0,400,mu_cut,"19300.","mu","2nd bJet p_{T}","GeV",false,false,false,true,folder1);   
//    makePlot("bjet_pt_singleLepCalc[1]","ALL",50,0,750,mu_cut,"19300.","mu","2nd bJet p_{T}","GeV",false,true,false,true,folder1);   
//    makePlot("bjet_pt_singleLepCalc[2]","ALL",50,0,200,mu_cut,"19300.","mu","3rd bJet p_{T}","GeV",false,false,false,true,folder1);   
//    makePlot("bjet_pt_singleLepCalc[2]","ALL",50,0,500,mu_cut,"19300.","mu","3rd bJet p_{T}","GeV",false,true,false,true,folder1);   
//    makePlot("bjet_pt_singleLepCalc[3]","ALL",20,0,100,mu_cut,"19300.","mu","4th bJet p_{T}","GeV",false,false,false,true,folder1);   
//    makePlot("bjet_pt_singleLepCalc[3]","ALL",20,0,300,mu_cut,"19300.","mu","4th bJet p_{T}","GeV",false,true,false,true,folder1);   
// 
//    makePlot("bjet_phi_singleLepCalc[0]","ALL",50,-4,4,mu_cut,"19300.","mu","Leading bJet #phi","GeV",false,false,false,true,folder1);   
//    makePlot("bjet_phi_singleLepCalc[0]","ALL",50,-4,4,mu_cut,"19300.","mu","Leading bJet #phi","GeV",true,true,false,true,folder1);   
//    makePlot("bjet_phi_singleLepCalc[1]","ALL",50,-4,4,mu_cut,"19300.","mu","2nd bJet #phi","GeV",false,false,false,true,folder1);   
//    makePlot("bjet_phi_singleLepCalc[1]","ALL",50,-4,4,mu_cut,"19300.","mu","2nd bJet #phi","GeV",true,true,false,true,folder1);   
//    makePlot("bjet_phi_singleLepCalc[2]","ALL",50,-4,4,mu_cut,"19300.","mu","3rd bJet #phi","GeV",false,false,false,true,folder1);   
//    makePlot("bjet_phi_singleLepCalc[2]","ALL",50,-4,4,mu_cut,"19300.","mu","3rd bJet #phi","GeV",false,true,false,true,folder1);   
//    makePlot("bjet_phi_singleLepCalc[3]","ALL",20,-4,4,mu_cut,"19300.","mu","4th bJet #phi","GeV",false,false,false,true,folder1);   
//    makePlot("bjet_phi_singleLepCalc[3]","ALL",20,-4,4,mu_cut,"19300.","mu","4th bJet #phi","GeV",true,true,false,true,folder1);   
// 
//    makePlot("bjet_eta_singleLepCalc[0]","ALL",50,-5.0,5.0,mu_cut,"19300.","mu","Leading bJet #eta","",false,false,false,true,folder1);   
//    makePlot("bjet_eta_singleLepCalc[1]","ALL",50,-5.0,5.0,mu_cut,"19300.","mu","2nd bJet #eta","",false,false,false,true,folder1);   
//    makePlot("bjet_eta_singleLepCalc[2]","ALL",50,-5.0,5.0,mu_cut,"19300.","mu","3rd bJet #eta","",false,false,false,true,folder1);   
//    makePlot("bjet_eta_singleLepCalc[3]","ALL",20,-5.0,5.0,mu_cut,"19300.","mu","4th bJet #eta","",false,false,false,true,folder1);   
// 
//    makePlot("n_btags_singleLepCalc","ALL",6,0,6,mu_cut,"19300.","mu","BTagged Jets","",false,false,false,true,folder1);
//    makePlot("nSelJets_CommonCalc","ALL",9,0,9,mu_cut,"19300.","mu","Selected Jets","",false,false,false,true,folder1);
//    makePlot("nPV_singleLepCalc","ALL",50,0,50,mu_cut,"19300.","mu","nPV","",false,false,false,true,folder1);
//    makePlot("nTightMuons_CommonCalc","ALL",2,1,3,mu_cut,"19300.","mu","Tight #mu","",false,false,false,true,folder1);
// 
//    makePlot("CAHEPTopCSVLSubJets_JetSubCalc[0]","ALL",5,0,5,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[0]>200","19300.","mu","CAHEPTopCSVLSubJets[0]","",false,false,false,true,folder1);
//    makePlot("CAHEPTopCSVLSubJets_JetSubCalc[1]","ALL",5,0,5,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[1]>200","19300.","mu","CAHEPTopCSVLSubJets[1]","",false,false,false,true,folder1);
// 
//    makePlot("CAHEPTopCSVMSubJets_JetSubCalc[0]","ALL",5,0,5,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[0]>200","19300.","mu","CAHEPTopCSVMSubJets[0]","",false,false,false,true,folder1);
//    makePlot("CAHEPTopCSVMSubJets_JetSubCalc[1]","ALL",5,0,5,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[1]>200","19300.","mu","CAHEPTopCSVMSubJets[1]","",false,false,false,true,folder1);
// 
//    makePlot("CAHEPTopCSVTSubJets_JetSubCalc[0]","ALL",5,0,5,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[0]>200","19300.","mu","CAHEPTopCSVTSubJets[0]","",false,false,false,true,folder1);
//    makePlot("CAHEPTopCSVTSubJets_JetSubCalc[1]","ALL",5,0,5,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[1]>200","19300.","mu","CAHEPTopCSVTSubJets[1]","",false,false,false,true,folder1);
// 
//    makePlot("CAHEPTopJetCSV_JetSubCalc[0]","ALL",50,0,1,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[0]>200","19300.","mu","CAHEPTopJetCSV_JetSubCalc[0]","",true,false,false,true,folder1);
//    makePlot("CAHEPTopJetCSV_JetSubCalc[0]","ALL",50,0,1,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[0]>200","19300.","mu","CAHEPTopJetCSV_JetSubCalc[0]","",true,true,false,true,folder1);
//    makePlot("CAHEPTopJetCSV_JetSubCalc[1]","ALL",50,0,1,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[1]>200","19300.","mu","CAHEPTopJetCSV_JetSubCalc[1]","",true,false,false,true,folder1);
//    makePlot("CAHEPTopJetCSV_JetSubCalc[1]","ALL",50,0,1,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[1]>200","19300.","mu","CAHEPTopJetCSV_JetSubCalc[1]","",true,true,false,true,folder1);
// 
//    makePlot("CAHEPTopJetEta_JetSubCalc[0]","ALL",50,-3,3,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[0]>200","19300.","mu","CAHEPTopJetEta_JetSubCalc[0]","",true,false,false,true,folder1);
//    makePlot("CAHEPTopJetEta_JetSubCalc[0]","ALL",50,-3,3,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[0]>200","19300.","mu","CAHEPTopJetEta_JetSubCalc[0]","",true,true,false,true,folder1);
//    makePlot("CAHEPTopJetEta_JetSubCalc[1]","ALL",50,-3,3,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[1]>200","19300.","mu","CAHEPTopJetEta_JetSubCalc[1]","",true,false,false,true,folder1);
//    makePlot("CAHEPTopJetEta_JetSubCalc[1]","ALL",50,-3,3,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[1]>200","19300.","mu","CAHEPTopJetEta_JetSubCalc[1]","",true,true,false,true,folder1);
// 
// 
//    makePlot("CAHEPTopJetMass_JetSubCalc[0]","ALL",50,0,300,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[0]>200","19300.","mu","CAHEPTopJetMass_JetSubCalc[0]","",false,false,false,true,folder1);
//    makePlot("CAHEPTopJetMass_JetSubCalc[0]","ALL",50,0,500,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[0]>200","19300.","mu","CAHEPTopJetMass_JetSubCalc[0]","",false,true,false,true,folder1);
//    makePlot("CAHEPTopJetMass_JetSubCalc[1]","ALL",50,0,300,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[1]>200","19300.","mu","CAHEPTopJetMass_JetSubCalc[1]","",false,false,false,true,folder1);
//    makePlot("CAHEPTopJetMass_JetSubCalc[1]","ALL",50,0,500,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[1]>200","19300.","mu","CAHEPTopJetMass_JetSubCalc[1]","",false,true,false,true,folder1);
//    
//    makePlot("CAHEPTopJetPhi_JetSubCalc[0]","ALL",50,-4,4,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[0]>200","19300.","mu","CAHEPTopJetPhi_JetSubCalc[0]","",false,false,false,true,folder1);
//    makePlot("CAHEPTopJetPhi_JetSubCalc[0]","ALL",50,-4,4,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[0]>200","19300.","mu","CAHEPTopJetPhi_JetSubCalc[0]","",false,true,false,true,folder1);
//    makePlot("CAHEPTopJetPhi_JetSubCalc[1]","ALL",50,-4,4,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[1]>200","19300.","mu","CAHEPTopJetPhi_JetSubCalc[1]","",false,false,false,true,folder1);
//    makePlot("CAHEPTopJetPhi_JetSubCalc[1]","ALL",50,-4,4,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[1]>200","19300.","mu","CAHEPTopJetPhi_JetSubCalc[1]","",false,true,false,true,folder1);
// 
//    makePlot("CAHEPTopJetPt_JetSubCalc[0]","ALL",50,0,500,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[0]>200","19300.","mu","CAHEPTopJetPt_JetSubCalc[0]","",false,false,false,true,folder1);
//    makePlot("CAHEPTopJetPt_JetSubCalc[0]","ALL",50,0,1500,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[0]>200","19300.","mu","CAHEPTopJetPt_JetSubCalc[0]","",false,true,false,true,folder1);
//    makePlot("CAHEPTopJetPt_JetSubCalc[1]","ALL",50,0,500,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[1]>200","19300.","mu","CAHEPTopJetPt_JetSubCalc[1]","",false,false,false,true,folder1);
//    makePlot("CAHEPTopJetPt_JetSubCalc[1]","ALL",50,0,1500,mu_cut+"&&CAHEPTopJetPt_JetSubCalc[1]>200","19300.","mu","CAHEPTopJetPt_JetSubCalc[1]","",false,true,false,true,folder1);
// 
//    makePlot("CATopCSVLSubJets_JetSubCalc[0]","ALL",5,0,5,mu_cut+"&&CATopJetPt_JetSubCalc[0]>200","19300.","mu","CATopCSVLSubJets[0]","",false,false,false,true,folder1);
//    makePlot("CATopCSVLSubJets_JetSubCalc[1]","ALL",5,0,5,mu_cut+"&&CATopJetPt_JetSubCalc[1]>200","19300.","mu","CATopCSVLSubJets[1]","",false,false,false,true,folder1);
// 
//    makePlot("CATopCSVMSubJets_JetSubCalc[0]","ALL",5,0,5,mu_cut+"&&CATopJetPt_JetSubCalc[0]>200","19300.","mu","CATopCSVMSubJets[0]","",false,false,false,true,folder1);
//    makePlot("CATopCSVMSubJets_JetSubCalc[1]","ALL",5,0,5,mu_cut+"&&CATopJetPt_JetSubCalc[1]>200","19300.","mu","CATopCSVMSubJets[1]","",false,false,false,true,folder1);
// 
//    makePlot("CATopCSVTSubJets_JetSubCalc[0]","ALL",5,0,5,mu_cut+"&&CATopJetPt_JetSubCalc[0]>200","19300.","mu","CATopCSVTSubJets[0]","",false,false,false,true,folder1);
//    makePlot("CATopCSVTSubJets_JetSubCalc[1]","ALL",5,0,5,mu_cut+"&&CATopJetPt_JetSubCalc[1]>200","19300.","mu","CATopCSVTSubJets[1]","",false,false,false,true,folder1);
// 
//    makePlot("CATopJetnDaughters_JetSubCalc[0]","ALL",5,0,5,mu_cut+"&&CATopJetPt_JetSubCalc[0]>200","19300.","mu","CATopJetnDaughters[0]","",false,false,false,true,folder1);
//    makePlot("CATopJetnDaughters_JetSubCalc[1]","ALL",5,0,5,mu_cut+"&&CATopJetPt_JetSubCalc[1]>200","19300.","mu","CATopJetnDaughters[1]","",false,false,false,true,folder1);
// 
//    makePlot("CATopJetCSV_JetSubCalc[0]","ALL",50,0,1,mu_cut+"&&CATopJetPt_JetSubCalc[0]>200","19300.","mu","CATopJetCSV_JetSubCalc[0]","",false,false,false,true,folder1);
//    makePlot("CATopJetCSV_JetSubCalc[0]","ALL",50,0,1,mu_cut+"&&CATopJetPt_JetSubCalc[0]>200","19300.","mu","CATopJetCSV_JetSubCalc[0]","",false,true,false,true,folder1);
//    makePlot("CATopJetCSV_JetSubCalc[1]","ALL",50,0,1,mu_cut+"&&CATopJetPt_JetSubCalc[1]>200","19300.","mu","CATopJetCSV_JetSubCalc[1]","",false,false,false,true,folder1);
//    makePlot("CATopJetCSV_JetSubCalc[1]","ALL",50,0,1,mu_cut+"&&CATopJetPt_JetSubCalc[1]>200","19300.","mu","CATopJetCSV_JetSubCalc[1]","",false,true,false,true,folder1);
// 
//    makePlot("CATopJetEta_JetSubCalc[0]","ALL",50,-3,3,mu_cut+"&&CATopJetPt_JetSubCalc[0]>200","19300.","mu","CATopJetEta_JetSubCalc[0]","",false,false,false,true,folder1);
//    makePlot("CATopJetEta_JetSubCalc[0]","ALL",50,-3,3,mu_cut+"&&CATopJetPt_JetSubCalc[0]>200","19300.","mu","CATopJetEta_JetSubCalc[0]","",false,true,false,true,folder1);
//    makePlot("CATopJetEta_JetSubCalc[1]","ALL",50,-3,3,mu_cut+"&&CATopJetPt_JetSubCalc[1]>200","19300.","mu","CATopJetEta_JetSubCalc[1]","",false,false,false,true,folder1);
//    makePlot("CATopJetEta_JetSubCalc[1]","ALL",50,-3,3,mu_cut+"&&CATopJetPt_JetSubCalc[1]>200","19300.","mu","CATopJetEta_JetSubCalc[1]","",false,true,false,true,folder1);
// 
//    makePlot("CATopJetMinPairMass_JetSubCalc[0]","ALL",50,0,100,mu_cut+"&&CATopJetPt_JetSubCalc[0]>200","19300.","mu","CATopJetMinPairMass_JetSubCalc[0]","",false,false,false,true,folder1);
//    makePlot("CATopJetMinPairMass_JetSubCalc[0]","ALL",50,0,150,mu_cut+"&&CATopJetPt_JetSubCalc[0]>200","19300.","mu","CATopJetMinPairMass_JetSubCalc[0]","",false,true,false,true,folder1);
//    makePlot("CATopJetMinPairMass_JetSubCalc[1]","ALL",50,0,100,mu_cut+"&&CATopJetPt_JetSubCalc[1]>200","19300.","mu","CATopJetMinPairMass_JetSubCalc[1]","",false,false,false,true,folder1);
//    makePlot("CATopJetMinPairMass_JetSubCalc[1]","ALL",50,0,150,mu_cut+"&&CATopJetPt_JetSubCalc[1]>200","19300.","mu","CATopJetMinPairMass_JetSubCalc[1]","",false,true,false,true,folder1);
// 
//    makePlot("CATopJetPhi_JetSubCalc[0]","ALL",50,-4,4,mu_cut+"&&CATopJetPt_JetSubCalc[0]>200","19300.","mu","CATopJetPhi_JetSubCalc[0]","",false,false,false,true,folder1);
//    makePlot("CATopJetPhi_JetSubCalc[0]","ALL",50,-4,4,mu_cut+"&&CATopJetPt_JetSubCalc[0]>200","19300.","mu","CATopJetPhi_JetSubCalc[0]","",false,true,false,true,folder1);
//    makePlot("CATopJetPhi_JetSubCalc[1]","ALL",50,-4,4,mu_cut+"&&CATopJetPt_JetSubCalc[1]>200","19300.","mu","CATopJetPhi_JetSubCalc[1]","",false,false,false,true,folder1);
//    makePlot("CATopJetPhi_JetSubCalc[1]","ALL",50,-4,4,mu_cut+"&&CATopJetPt_JetSubCalc[1]>200","19300.","mu","CATopJetPhi_JetSubCalc[1]","",false,true,false,true,folder1);
//    
//    makePlot("CATopJetPt_JetSubCalc[0]","ALL",50,0,500,mu_cut+"&&CATopJetPt_JetSubCalc[0]>200","19300.","mu","CATopJetPt_JetSubCalc[0]","",false,false,false,true,folder1);
//    makePlot("CATopJetPt_JetSubCalc[0]","ALL",50,0,1500,mu_cut+"&&CATopJetPt_JetSubCalc[0]>200","19300.","mu","CATopJetPt_JetSubCalc[0]","",false,true,false,true,folder1);
//    makePlot("CATopJetPt_JetSubCalc[1]","ALL",50,0,500,mu_cut+"&&CATopJetPt_JetSubCalc[1]>200","19300.","mu","CATopJetPt_JetSubCalc[1]","",false,false,false,true,folder1);
//    makePlot("CATopJetPt_JetSubCalc[1]","ALL",50,0,1500,mu_cut+"&&CATopJetPt_JetSubCalc[1]>200","19300.","mu","CATopJetPt_JetSubCalc[1]","",false,true,false,true,folder1);
// 
//    makePlot("CATopJetTopMass_JetSubCalc[0]","ALL",50,0,200,mu_cut+"&&CATopJetPt_JetSubCalc[0]>200","19300.","mu","CATopJetTopMass_JetSubCalc[0]","",false,false,false,true,folder1);
//    makePlot("CATopJetTopMass_JetSubCalc[0]","ALL",50,0,500,mu_cut+"&&CATopJetPt_JetSubCalc[0]>200","19300.","mu","CATopJetTopMass_JetSubCalc[0]","",false,true,false,true,folder1);
//    makePlot("CATopJetTopMass_JetSubCalc[1]","ALL",50,0,200,mu_cut+"&&CATopJetPt_JetSubCalc[1]>200","19300.","mu","CATopJetTopMass_JetSubCalc[1]","",false,false,false,true,folder1);
//    makePlot("CATopJetTopMass_JetSubCalc[1]","ALL",50,0,500,mu_cut+"&&CATopJetPt_JetSubCalc[1]>200","19300.","mu","CATopJetTopMass_JetSubCalc[1]","",false,true,false,true,folder1);
// 
//    makePlot("CAWCSVLSubJets_JetSubCalc[0]","ALL",5,0,5,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","CAWCSVLSubJets[0]","",false,false,false,true,folder1);
//    makePlot("CAWCSVLSubJets_JetSubCalc[1]","ALL",5,0,5,mu_cut+"&&CAWJetPt_JetSubCalc[1]>200","19300.","mu","CAWCSVLSubJets[1]","",false,false,false,true,folder1);
// 
//    makePlot("CAWCSVMSubJets_JetSubCalc[0]","ALL",5,0,5,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","CAWCSVMSubJets[0]","",false,false,false,true,folder1);
//    makePlot("CAWCSVMSubJets_JetSubCalc[1]","ALL",5,0,5,mu_cut+"&&CAWJetPt_JetSubCalc[1]>200","19300.","mu","CAWCSVMSubJets[1]","",false,false,false,true,folder1);
// 
//    makePlot("CAWCSVTSubJets_JetSubCalc[0]","ALL",5,0,5,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","CAWCSVTSubJets[0]","",false,false,false,true,folder1);
//    makePlot("CAWCSVTSubJets_JetSubCalc[1]","ALL",5,0,5,mu_cut+"&&CAWJetPt_JetSubCalc[1]>200","19300.","mu","CAWCSVTSubJets[1]","",false,false,false,true,folder1);
// 
//    makePlot("CAWJetCSV_JetSubCalc[0]","ALL",50,0,1,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","CAWJetCSV_JetSubCalc[0]","",false,false,false,true,folder1);
//    makePlot("CAWJetCSV_JetSubCalc[0]","ALL",50,0,1,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","CAWJetCSV_JetSubCalc[0]","",false,true,false,true,folder1);
//    makePlot("CAWJetCSV_JetSubCalc[1]","ALL",50,0,1,mu_cut+"&&CAWJetPt_JetSubCalc[1]>200","19300.","mu","CAWJetCSV_JetSubCalc[1]","",false,false,false,true,folder1);
//    makePlot("CAWJetCSV_JetSubCalc[1]","ALL",50,0,1,mu_cut+"&&CAWJetPt_JetSubCalc[1]>200","19300.","mu","CAWJetCSV_JetSubCalc[1]","",false,true,false,true,folder1);
// 
//    makePlot("CAWJetEta_JetSubCalc[0]","ALL",50,-3,3,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","CAWJetEta_JetSubCalc[0]","",false,false,false,true,folder1);
//    makePlot("CAWJetEta_JetSubCalc[0]","ALL",50,-3,3,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","CAWJetEta_JetSubCalc[0]","",false,true,false,true,folder1);
//    makePlot("CAWJetEta_JetSubCalc[1]","ALL",50,-3,3,mu_cut+"&&CAWJetPt_JetSubCalc[1]>200","19300.","mu","CAWJetEta_JetSubCalc[1]","",false,false,false,true,folder1);
//    makePlot("CAWJetEta_JetSubCalc[1]","ALL",50,-3,3,mu_cut+"&&CAWJetPt_JetSubCalc[1]>200","19300.","mu","CAWJetEta_JetSubCalc[1]","",false,true,false,true,folder1);
// 
//    makePlot("CAWJetMass_JetSubCalc[0]","ALL",50,0,200,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","CAWJetMass_JetSubCalc[0]","GeV",false,false,false,true,folder1);
//    makePlot("CAWJetMass_JetSubCalc[0]","ALL",50,0,500,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","CAWJetMass_JetSubCalc[0]","GeV",false,true,false,true,folder1);
//    makePlot("CAWJetMass_JetSubCalc[1]","ALL",50,0,200,mu_cut+"&&CAWJetPt_JetSubCalc[1]>200","19300.","mu","CAWJetMass_JetSubCalc[1]","GeV",false,false,false,true,folder1);
//    makePlot("CAWJetMass_JetSubCalc[1]","ALL",50,0,500,mu_cut+"&&CAWJetPt_JetSubCalc[1]>200","19300.","mu","CAWJetMass_JetSubCalc[1]","GeV",false,true,false,true,folder1);
// 
//    makePlot("CAWJetPhi_JetSubCalc[0]","ALL",50,-4,4,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","CAWJetPhi_JetSubCalc[0]","",false,false,false,true,folder1);
//    makePlot("CAWJetPhi_JetSubCalc[0]","ALL",50,-4,4,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","CAWJetPhi_JetSubCalc[0]","",false,true,false,true,folder1);
//    makePlot("CAWJetPhi_JetSubCalc[1]","ALL",50,-4,4,mu_cut+"&&CAWJetPt_JetSubCalc[1]>200","19300.","mu","CAWJetPhi_JetSubCalc[1]","",false,false,false,true,folder1);
//    makePlot("CAWJetPhi_JetSubCalc[1]","ALL",50,-4,4,mu_cut+"&&CAWJetPt_JetSubCalc[1]>200","19300.","mu","CAWJetPhi_JetSubCalc[1]","",false,true,false,true,folder1);
// 
//    makePlot("CAWJetPt_JetSubCalc[0]","ALL",50,0,500,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","CAWJetPt_JetSubCalc[0]","",false,false,false,true,folder1);
//    makePlot("CAWJetPt_JetSubCalc[0]","ALL",50,0,1500,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","CAWJetPt_JetSubCalc[0]","",false,true,false,true,folder1);
//    makePlot("CAWJetPt_JetSubCalc[1]","ALL",50,0,500,mu_cut+"&&CAWJetPt_JetSubCalc[1]>200","19300.","mu","CAWJetPt_JetSubCalc[1]","",false,false,false,true,folder1);
//    makePlot("CAWJetPt_JetSubCalc[1]","ALL",50,0,1500,mu_cut+"&&CAWJetPt_JetSubCalc[1]>200","19300.","mu","CAWJetPt_JetSubCalc[1]","",false,true,false,true,folder1);
//    makePlot("minDRCAtoB_CATopoCalc","ALL",50,0,5,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","Min #DeltaR(CA8,b)","",false,true,false,true,folder1);
//    makePlot("tPrimeMass_CATopoCalc","ALL",50,0,1500,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","T` Mass","",false,true,false,true,folder1);
//    makePlot("tPrimeMassBestTop_CATopoCalc","ALL",50,0,1500,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","T` Mass (Best Top)","",false,true,false,true,folder1);
//    makePlot("CAMindrBMass_CATopoCalc","ALL",50,0,1500,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","Mass CA + B","",false,true,false,true,folder1);
//    makePlot("bestTopMasslnub_CATopoCalc","ALL",50,0,500,mu_cut+"&&CAWJetPt_JetSubCalc[0]>200","19300.","mu","Best Top Mass","",false,true,false,true,folder1);
// 
//    makePlot("CA8JetEnergy_JetSubCalc[0]","ALL",50,0,1000,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet Energy[0]","GeV",false,false,false,true,folder1);
//    makePlot("CA8JetEnergy_JetSubCalc[0]","ALL",50,0,2000,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet Energy[0]","GeV",false,true,false,true,folder1);   
//    makePlot("CA8JetEnergy_JetSubCalc[1]","ALL",50,0,1000,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet Energy[1]","GeV",false,false,false,true,folder1);
//    makePlot("CA8JetEnergy_JetSubCalc[1]","ALL",50,0,2000,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet Energy[1]","GeV",false,true,false,true,folder1);   
// 
//    makePlot("CA8JetEta_JetSubCalc[0]","ALL",50,-5,5,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet #eta[0]","",false,false,false,true,folder1);   
//    makePlot("CA8JetEta_JetSubCalc[0]","ALL",50,-5,5,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet #eta[0]","",false,true,false,true,folder1);   
//    makePlot("CA8JetEta_JetSubCalc[1]","ALL",50,-5,5,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet #eta[1]","",false,false,false,true,folder1);
//    makePlot("CA8JetEta_JetSubCalc[1]","ALL",50,-5,5,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet #eta[1]","",false,true,false,true,folder1);   
// 
//    makePlot("CA8JetMass_JetSubCalc[0]","ALL",50,0,250,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet Mass[0]","GeV",false,false,false,true,folder1);   
//    makePlot("CA8JetMass_JetSubCalc[0]","ALL",50,0,250,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet Mass[0]","GeV",false,true,false,true,folder1);   
//    makePlot("CA8JetMass_JetSubCalc[1]","ALL",50,0,250,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet Mass[1]","GeV",false,false,false,true,folder1);   
//    makePlot("CA8JetMass_JetSubCalc[1]","ALL",50,0,250,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet Mass[1]","GeV",false,true,false,true,folder1);   
// 
//    makePlot("CA8JetPhi_JetSubCalc[0]","ALL",50,-4,4,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet #phi[0]","",false,false,false,true,folder1);   
//    makePlot("CA8JetPhi_JetSubCalc[0]","ALL",50,-4,4,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet #phi[0]","",false,true,false,true,folder1);   
//    makePlot("CA8JetPhi_JetSubCalc[1]","ALL",50,-4,4,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet #phi[1]","",false,false,false,true,folder1);   
//    makePlot("CA8JetPhi_JetSubCalc[1]","ALL",50,-4,4,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet #phi[1]","",false,true,false,true,folder1);   
// 
//    makePlot("CA8JetPt_JetSubCalc[0]","ALL",50,0,800,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet p_{T}[0]","GeV",false,false,false,true,folder1);   
//    makePlot("CA8JetPt_JetSubCalc[0]","ALL",50,0,1500,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet p_{T}[0]","GeV",false,true,false,true,folder1);   
//    makePlot("CA8JetPt_JetSubCalc[1]","ALL",50,0,800,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet p_{T}[1]","GeV",false,false,false,true,folder1);   
//    makePlot("CA8JetPt_JetSubCalc[1]","ALL",50,0,1500,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet p_{T}[1]","GeV",false,true,false,true,folder1);   
// 
//    makePlot("CA8Tau1_JetSubCalc[0]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet #tau_{1}[0]","GeV",false,false,false,true,folder1);   
//    makePlot("CA8Tau1_JetSubCalc[0]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet #tau_{1}[0]","GeV",false,true,false,true,folder1);   
//    makePlot("CA8Tau1_JetSubCalc[1]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet #tau1_{1}[1]","GeV",false,false,false,true,folder1);   
//    makePlot("CA8Tau1_JetSubCalc[1]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet #tau1_{1}[1]","GeV",false,true,false,true,folder1);   
// 
//    makePlot("CA8Tau21_JetSubCalc[0]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet #tau_{21}[0]","GeV",true,false,false,true,folder1);   
//    makePlot("CA8Tau21_JetSubCalc[0]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet #tau_{21}[0]","GeV",true,true,false,true,folder1);   
//    makePlot("CA8Tau21_JetSubCalc[1]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet #tau_{21}[1]","GeV",true,false,false,true,folder1);   
//    makePlot("CA8Tau21_JetSubCalc[1]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet #tau_{21}[1]","GeV",true,true,false,true,folder1);   
// 
//    makePlot("CA8Tau2_JetSubCalc[0]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet #tau_{2}[0]","GeV",false,false,false,true,folder1);   
//    makePlot("CA8Tau2_JetSubCalc[0]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet #tau_{2}[0]","GeV",false,true,false,true,folder1);   
//    makePlot("CA8Tau2_JetSubCalc[1]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet #tau_{2}[1]","GeV",false,false,false,true,folder1);   
//    makePlot("CA8Tau2_JetSubCalc[1]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet #tau_{2}[1]","GeV",false,true,false,true,folder1);   
// 
//    makePlot("CA8Tau3_JetSubCalc[0]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet #tau_{3}[0]","GeV",false,false,false,true,folder1);   
//    makePlot("CA8Tau3_JetSubCalc[0]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet #tau_{3}[0]","GeV",false,true,false,true,folder1);   
//    makePlot("CA8Tau3_JetSubCalc[1]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet #tau_{3}[1]","GeV",false,false,false,true,folder1);   
//    makePlot("CA8Tau3_JetSubCalc[1]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet #tau_{3}[1]","GeV",false,true,false,true,folder1);   
// 
//    makePlot("CA8Tau4_JetSubCalc[0]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet #tau_{4} 1st element","GeV",false,false,false,true,folder1);   
//    makePlot("CA8Tau4_JetSubCalc[0]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[0]>200","19300.","mu","CA8 Jet #tau_{4} 1st element","GeV",false,true,false,true,folder1);   
//    makePlot("CA8Tau4_JetSubCalc[1]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet #tau_{4} 2nd element","GeV",false,false,false,true,folder1);   
//    makePlot("CA8Tau4_JetSubCalc[1]","ALL",50,0,1,mu_cut+"&&CA8JetPt_JetSubCalc[1]>200","19300.","mu","CA8 Jet #tau_{4} 2nd element","GeV",false,true,false,true,folder1);   
// 

   /*Mu Channel - TH_TZ plots with more cuts*/
   
//    makePlot("jet_pt_singleLepCalc[0]","TH_TZ",50,180,500,mu_cut+"&&"+more_cuts,"19300.","mu","Leading Jet p_{T}","GeV",false,false,false,true,folder2);   
//    makePlot("jet_pt_singleLepCalc[0]","TH_TZ",50,150,1500,mu_cut+"&&"+more_cuts,"19300.","mu","Leading Jet p_{T}","GeV",false,true,false,true,folder2);   
// 
//    makePlot("jet_pt_singleLepCalc[1]","TH_TZ",50,0,400,mu_cut+"&&"+more_cuts,"19300.","mu","2nd Jet p_{T}","GeV",false,false,false,true,folder2);   
//    makePlot("jet_pt_singleLepCalc[1]","TH_TZ",50,0,750,mu_cut+"&&"+more_cuts,"19300.","mu","2nd Jet p_{T}","GeV",false,true,false,true,folder2);   
// 
//    makePlot("jet_pt_singleLepCalc[2]","TH_TZ",50,0,200,mu_cut+"&&"+more_cuts,"19300.","mu","3rd Jet p_{T}","GeV",false,false,false,true,folder2);   
//    makePlot("jet_pt_singleLepCalc[2]","TH_TZ",50,0,500,mu_cut+"&&"+more_cuts,"19300.","mu","3rd Jet p_{T}","GeV",false,true,false,true,folder2);   
// 
//    makePlot("bjet_pt_singleLepCalc[0]","TH_TZ",50,0,500,mu_cut+"&&"+more_cuts,"19300.","mu","Leading bJet p_{T}","GeV",false,false,false,true,folder2);   
//    makePlot("bjet_pt_singleLepCalc[0]","TH_TZ",50,0,1500,mu_cut+"&&"+more_cuts,"19300.","mu","Leading bJet p_{T}","GeV",false,true,false,true,folder2);   
//    makePlot("bjet_pt_singleLepCalc[1]","TH_TZ",50,0,400,mu_cut+"&&"+more_cuts,"19300.","mu","2nd bJet p_{T}","GeV",false,false,false,true,folder2);   
//    makePlot("bjet_pt_singleLepCalc[1]","TH_TZ",50,0,750,mu_cut+"&&"+more_cuts,"19300.","mu","2nd bJet p_{T}","GeV",false,true,false,true,folder2);   
//
//   makePlot("corr_met_singleLepCalc","TH_TZ",50,0,150,mu_cut+"&&"+more_cuts,"19300.","mu","MET","GeV",false,false,false,true,folder2);   

//    makePlot("nSelJets_CommonCalc","TH_TZ",9,0,9,mu_cut+"&&"+more_cuts,"19300.","mu","Selected Jets","",false,false,false,true,folder2);
// 
//    makePlot("LeptonJet_DeltaR_LjetsTopoCalcNew","TH_TZ",50,0,5,mu_cut+"&&"+more_cuts,"19300.","mu","#DeltaR_{lj}","",false,false,false,true,folder2);   
// 
//    makePlot("Mevent_LjetsTopoCalcNew","TH_TZ",50,0,2500,mu_cut+"&&"+more_cuts,"19300.","mu","Mevent","",false,false,false,true,folder2);
//    makePlot("Mevent_LjetsTopoCalcNew","TH_TZ",50,0,2500,mu_cut+"&&"+more_cuts,"19300.","mu","Event Mass","",false,true,false,true,folder2);   
// 
//    makePlot("W_Pt_LjetsTopoCalcNew","TH_TZ",50,50,1000,mu_cut+"&&"+more_cuts,"19300.","mu","W P_t","GeV",false,true,false,true,folder2);
//    makePlot("W_Pt_LjetsTopoCalcNew","TH_TZ",50,50,500,mu_cut+"&&"+more_cuts,"19300.","mu","W P_t","GeV",false,false,false,true,folder2);
// 
//    makePlot("Jet1Jet2_Pt_LjetsTopoCalcNew","TH_TZ",50,0,1000,mu_cut+"&&"+more_cuts,"19300.","mu"," Jet1Jet2 Pt LjetsTopoCalcNew","GeV",false,true,false,true,folder2);
// 
//    makePlot("BestTop_LjetsTopoCalcNew","TH_TZ",50,0,1000,mu_cut+"&&"+more_cuts,"19300.","mu","BestTop LjetsTopoCalcNew ","GeV",false,false,false,true,folder2);
// 
//    makePlot("BTagTopMass_LjetsTopoCalcNew","TH_TZ",50,0,4000,mu_cut+"&&"+more_cuts,"19300.","mu","BTagTopMass LjetsTopoCalcNew","GeV",false,false,false,true,folder2);
// 
//    makePlot("CAHEPTopJetMass_JetSubCalc[0]","TH_TZ",50,0,300,mu_cut+"&&"+more_cuts,"19300.","mu","CAHEPTopJetMass_JetSubCalc[0]","",false,false,false,true,folder2);
//    makePlot("CAHEPTopJetMass_JetSubCalc[0]","TH_TZ",50,0,500,mu_cut+"&&"+more_cuts,"19300.","mu","CAHEPTopJetMass_JetSubCalc[0]","",false,true,false,true,folder2);

   makePlot("CAWCSVMSubJets_JetSubCalc[0]","TH_TZ",5,0,5,mu_cut+"&&"+more_cuts,"19300.","mu","CAWCSVMSubJets[0]","",false,false,false,true,folder2);
   makePlot("CAWCSVMSubJets_JetSubCalc[0]","TH_TZ",5,0,5,mu_cut+"&&"+more_cuts,"19300.","mu","CAWCSVMSubJets[0]","",false,true,false,true,folder2);

//   makePlot("CAWCSVLSubJets_JetSubCalc[0]","TH_TZ",5,0,5,mu_cut+"&&"+more_cuts,"19300.","mu","CAWCSVLSubJets[0]","",false,false,false,true,folder2);

   makePlot("CAWJetPt_JetSubCalc[0]","TH_TZ",50,0,500,mu_cut+"&&"+more_cuts,"19300.","mu","CAWJetPt_JetSubCalc[0]","",false,false,false,true,folder2);
   makePlot("CAWJetPt_JetSubCalc[0]","TH_TZ",50,0,1500,mu_cut+"&&"+more_cuts,"19300.","mu","CAWJetPt_JetSubCalc[0]","",false,true,false,true,folder2);

   makePlot("CAWJetMass_JetSubCalc[0]","TH_TZ",50,0,200,mu_cut+"&&"+more_cuts,"19300.","mu","CAWJetMass_JetSubCalc[0]","GeV",false,false,false,true,folder2);
   makePlot("CAWJetMass_JetSubCalc[0]","TH_TZ",50,0,500,mu_cut+"&&"+more_cuts,"19300.","mu","CAWJetMass_JetSubCalc[0]","GeV",false,true,false,true,folder2);

//    makePlot("CAHEPTopJetMass_JetSubCalc[0]","TH_TZ",50,0,300,mu_cut+"&&"+more_cuts,"19300.","mu","CAHEPTopJetMass_JetSubCalc[0]","",false,false,false,true,folder2);
//    makePlot("CAHEPTopJetMass_JetSubCalc[0]","TH_TZ",50,0,500,mu_cut+"&&"+more_cuts,"19300.","mu","CAHEPTopJetMass_JetSubCalc[0]","",false,true,false,true,folder2);

   makePlot("Hz_LjetsTopoCalcNew","TH_TZ",50,0,5000,mu_cut+"&&"+more_cuts,"19300.","mu","Hz LjetsTopoCalcNew","",false,true,false,true,folder2);

//   makePlot("Centrality_LjetsTopoCalcNew","TH_TZ",50,0,1,mu_cut+"&&"+more_cuts,"19300.","mu","Centrality LjetsTopoCalcNew","",false,false,false,true,folder2);

   makePlot("SqrtsT_LjetsTopoCalcNew","TH_TZ",50,0,1000,mu_cut+"&&"+more_cuts,"19300.","mu","#sqrt{sT}","GeV",false,false,false,true,folder2);   
   makePlot("SqrtsT_LjetsTopoCalcNew","TH_TZ",50,0,2000,mu_cut+"&&"+more_cuts,"19300.","mu","#sqrt{sT}","GeV",false,true,false,true,folder2);   

   makePlot("HT2prime_LjetsTopoCalcNew","TH_TZ",50,0,5,mu_cut+"&&"+more_cuts,"19300.","mu","HT2prime LjetsTopoCalcNew","",false,true,false,true,folder2);

   makePlot("HT2_LjetsTopoCalcNew","TH_TZ",50,0,1500,mu_cut+"&&"+more_cuts,"19300.","mu","HT2 LjetsTopoCalcNew","",false,true,false,true,folder2);

//   makePlot("dphiLepMet_LjetsTopoCalcNew","TH_TZ",50,0,4,mu_cut+"&&"+more_cuts,"19300.","mu","dphiLepMet","",false,false,false,true,folder2);
//   makePlot("dphiLepMet_LjetsTopoCalcNew","TH_TZ",50,0,4,mu_cut+"&&"+more_cuts,"19300.","mu","dphiLepMet","",false,true,false,true,folder2);

   makePlot("minDRCAtoB_CATopoCalc","TH_TZ",50,0,5,mu_cut+"&&"+more_cuts,"19300.","mu","Min #DeltaR(CA8,b)","",false,true,false,true,folder2);
   makePlot("tPrimeMass_CATopoCalc","TH_TZ",50,0,1500,mu_cut+"&&"+more_cuts,"19300.","mu","T` Mass","",false,true,false,true,folder2);
   makePlot("tPrimeMassBestTop_CATopoCalc","TH_TZ",50,0,1500,mu_cut+"&&"+more_cuts,"19300.","mu","T` Mass (Best Top)","",false,true,false,true,folder2);
   makePlot("CAMindrBMass_CATopoCalc","TH_TZ",50,0,1500,mu_cut+"&&"+more_cuts,"19300.","mu","Mass CA + B","",false,true,false,true,folder2);
   makePlot("bestTopMasslnub_CATopoCalc","TH_TZ",50,0,500,mu_cut+"&&"+more_cuts,"19300.","mu","Best Top Mass","",false,true,false,true,folder2);

   /*Mu Channel - BW Plots with more cuts*/

 //   makePlot("muon_1_pt_singleLepCalc","BW",50,0,150,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","#mu p_{T}","GeV",false,false,false,true,folder3);   
// 
//    makePlot("jet_pt_singleLepCalc[0]","BW",50,180,500,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","Leading Jet p_{T}","GeV",false,false,false,true,folder3);   
//    makePlot("jet_pt_singleLepCalc[0]","BW",50,150,1500,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","Leading Jet p_{T}","GeV",false,true,false,true,folder3);   
// 
//    makePlot("jet_pt_singleLepCalc[1]","BW",50,0,400,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","2nd Jet p_{T}","GeV",false,false,false,true,folder3);   
//    makePlot("jet_pt_singleLepCalc[1]","BW",50,0,750,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","2nd Jet p_{T}","GeV",false,true,false,true,folder3);   
// 
//    makePlot("jet_pt_singleLepCalc[2]","BW",50,0,200,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","3rd Jet p_{T}","GeV",false,false,false,true,folder3);   
//    makePlot("jet_pt_singleLepCalc[2]","BW",50,0,500,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","3rd Jet p_{T}","GeV",false,true,false,true,folder3);   
// 
//    makePlot("bjet_pt_singleLepCalc[0]","BW",50,0,500,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","Leading bJet p_{T}","GeV",false,false,false,true,folder3);   
//    makePlot("bjet_pt_singleLepCalc[0]","BW",50,0,1500,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","Leading bJet p_{T}","GeV",false,true,false,true,folder3);   
//    makePlot("bjet_pt_singleLepCalc[1]","BW",50,0,400,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","2nd bJet p_{T}","GeV",false,false,false,true,folder3);   
//    makePlot("bjet_pt_singleLepCalc[1]","BW",50,0,750,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","2nd bJet p_{T}","GeV",false,true,false,true,folder3);   
// 
//    makePlot("corr_met_singleLepCalc","BW",50,0,150,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","MET","GeV",false,false,false,true,folder3);   
// 
//    makePlot("nSelJets_CommonCalc","BW",9,0,9,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","Selected Jets","",false,false,false,true,folder3);
// 
//    makePlot("LeptonJet_DeltaR_LjetsTopoCalcNew","BW",50,0,5,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","#DeltaR_{lj}","",false,false,false,true,folder3);   
// 
//    makePlot("Mevent_LjetsTopoCalcNew","BW",50,0,2500,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","Mevent","",false,false,false,true,folder3);
//    makePlot("Mevent_LjetsTopoCalcNew","BW",50,0,2500,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","Event Mass","",false,true,false,true,folder3);   
// 
//    makePlot("W_Pt_LjetsTopoCalcNew","BW",50,50,1000,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","W P_t","GeV",false,true,false,true,folder3);
//    makePlot("W_Pt_LjetsTopoCalcNew","BW",50,50,500,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","W P_t","GeV",false,false,false,true,folder3);
// 
//    makePlot("Jet1Jet2_Pt_LjetsTopoCalcNew","BW",50,0,1000,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu"," Jet1Jet2 Pt LjetsTopoCalcNew","GeV",false,true,false,true,folder3);
// 
//    makePlot("BestTop_LjetsTopoCalcNew","BW",50,0,1000,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","BestTop LjetsTopoCalcNew ","GeV",false,false,false,true,folder3);
// 
//    makePlot("BTagTopMass_LjetsTopoCalcNew","BW",50,0,4000,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","BTagTopMass LjetsTopoCalcNew","GeV",false,false,false,true,folder3);
// 
//    makePlot("Hz_LjetsTopoCalcNew","BW",50,0,5000,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","Hz LjetsTopoCalcNew","",false,true,false,true,folder3);
// 
//    makePlot("Centrality_LjetsTopoCalcNew","BW",50,0,1,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","Centrality LjetsTopoCalcNew","",false,false,false,true,folder3);
// 
//    makePlot("SqrtsT_LjetsTopoCalcNew","BW",50,0,1000,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","#sqrt{sT}","GeV",false,false,false,true,folder3);   
//    makePlot("SqrtsT_LjetsTopoCalcNew","BW",50,0,2000,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","#sqrt{sT}","GeV",false,true,false,true,folder3);   
// 
//    makePlot("HT2prime_LjetsTopoCalcNew","BW",50,0,5,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","HT2prime LjetsTopoCalcNew","",false,true,false,true,folder3);
// 
//    makePlot("HT2_LjetsTopoCalcNew","BW",50,0,1500,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","HT2 LjetsTopoCalcNew","",false,true,false,true,folder3);
// 
//    makePlot("dphiLepMet_LjetsTopoCalcNew","BW",50,0,4,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","dphiLepMet","",false,false,false,true,folder3);
//    makePlot("dphiLepMet_LjetsTopoCalcNew","BW",50,0,4,mu_cut+"&&nSelJets_CommonCalc>0","19300.","mu","dphiLepMet","",false,true,false,true,folder3);


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
