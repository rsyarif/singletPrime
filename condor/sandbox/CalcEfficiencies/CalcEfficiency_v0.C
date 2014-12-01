{
  /* Define Cuts */
  
  std::string mu_cut1 = "nTightMuons_CommonCalc==1";
  std::string mu_cut2 = "nTightMuons_CommonCalc==1&&nSelJets_CommonCalc>1";
  std::string mu_cut3 = "nTightMuons_CommonCalc==1&&nSelJets_CommonCalc>1&&CA8Tau21_JetSubCalc[0]<0.5&&CA8JetPt_JetSubCalc>200";
  std::string mu_cut4 = "nTightMuons_CommonCalc==1&&nSelJets_CommonCalc>1&&CA8Tau21_JetSubCalc[0]<0.5&&CA8JetPt_JetSubCalc>200&&CAWCSVMSubJets_JetSubCalc[0]==2";
  std::string mu_cut5 = "nTightMuons_CommonCalc==1&&nSelJets_CommonCalc>1&&CA8Tau21_JetSubCalc[0]<0.5&&CA8JetPt_JetSubCalc>200&&CAWCSVMSubJets_JetSubCalc[0]==2&&CAWJetMass_JetSubCalc[0]>85&&CAWJetMass_JetSubCalc[0]<145";
  std::string mu_cut6 = "nTightMuons_CommonCalc==1&&nSelJets_CommonCalc>1&&CA8Tau21_JetSubCalc[0]<0.5&&CA8JetPt_JetSubCalc>200&&CAWCSVMSubJets_JetSubCalc[0]==2&&CAWJetMass_JetSubCalc[0]>85&&CAWJetMass_JetSubCalc[0]<145&&maxJetEta_LjetsTopoCalcNew>1.5";
  

  std::string ele_cut1 = "nTightMuons_CommonCalc==0";
  std::string ele_cut2 = "nTightMuons_CommonCalc==0&&nSelJets_CommonCalc>1";
  std::string ele_cut3 = "nTightMuons_CommonCalc==0&&nSelJets_CommonCalc>1&&CA8Tau21_JetSubCalc[0]<0.5&&CA8JetPt_JetSubCalc>200";
  std::string ele_cut4 = "nTightMuons_CommonCalc==0&&nSelJets_CommonCalc>1&&CA8Tau21_JetSubCalc[0]<0.5&&CA8JetPt_JetSubCalc>200&&CAWCSVMSubJets_JetSubCalc[0]==2";
  std::string ele_cut5 = "nTightMuons_CommonCalc==0&&nSelJets_CommonCalc>1&&CA8Tau21_JetSubCalc[0]<0.5&&CA8JetPt_JetSubCalc>200&&CAWCSVMSubJets_JetSubCalc[0]==2&&CAWJetMass_JetSubCalc[0]>85&&CAWJetMass_JetSubCalc[0]<145";
  std::string ele_cut6 = "nTightMuons_CommonCalc==0&&nSelJets_CommonCalc>1&&CA8Tau21_JetSubCalc[0]<0.5&&CA8JetPt_JetSubCalc>200&&CAWCSVMSubJets_JetSubCalc[0]==2&&CAWJetMass_JetSubCalc[0]>85&&CAWJetMass_JetSubCalc[0]<145&&maxJetEta_LjetsTopoCalcNew>1.5";
  
  
  /* Open file and tree */

  TFile *fTH750 = new TFile("root_files/TpTH750.root");
  TTree *tTH750 = (TTree *) fTH750->Get("ljmet");
  
  TFile *fJTH750 = new TFile("root_files/TpJTH750.root");
  TTree *tJTH750 = (TTree *) fJTH750->Get("ljmet");

  /* Calculate efficiency and print */

  Double_t entries; 

  cout << " " << endl;
  cout << "Efficiency for TH750 sample :" << endl;
  cout << " " << endl;
  
  Double_t total_TH750 = 199988; //source: DAS

  tTH750->Draw("event_CommonCalc>>h");
  entries = h->GetEntries();
  cout << " No cut = " << entries << "/" << total_TH750 << " = " << entries/total_TH750 * 100 << " %" << endl;

  tTH750->Draw("event_CommonCalc>>h",mu_cut1.c_str());
  entries = h->GetEntries();
  cout << " mu_cut1 = " << entries << "/" << total_TH750 << " = " << entries/total_TH750 * 100 << " %" << endl;
  
  tTH750->Draw("event_CommonCalc>>h",mu_cut2.c_str());
  entries = h->GetEntries();
  cout << " mu_cut2 = " << entries << "/" << total_TH750 << " = " << entries/total_TH750 * 100 << " %" << endl;

  tTH750->Draw("event_CommonCalc>>h",mu_cut3.c_str());
  entries = h->GetEntries();
  cout << " mu_cut3 = " << entries << "/" << total_TH750 << " = " << entries/total_TH750 * 100 << " %" << endl;

  tTH750->Draw("event_CommonCalc>>h",mu_cut4.c_str());
  entries = h->GetEntries();
  cout << " mu_cut4 = " << entries << "/" << total_TH750 << " = " << entries/total_TH750 * 100 << " %" << endl;

  tTH750->Draw("event_CommonCalc>>h",mu_cut5.c_str());
  entries = h->GetEntries();
  cout << " mu_cut5 = " << entries << "/" << total_TH750 << " = " << entries/total_TH750 * 100 << " %" << endl;

  tTH750->Draw("event_CommonCalc>>h",ele_cut1.c_str());
  entries = h->GetEntries();
  cout << " ele_cut1 = " << entries << "/" << total_TH750 << " = " << entries/total_TH750 * 100 << " %" << endl;
  
  tTH750->Draw("event_CommonCalc>>h",ele_cut2.c_str());
  entries = h->GetEntries();
  cout << " ele_cut2 = " << entries << "/" << total_TH750 << " = " << entries/total_TH750 * 100 << " %" << endl;

  tTH750->Draw("event_CommonCalc>>h",ele_cut3.c_str());
  entries = h->GetEntries();
  cout << " ele_cut3 = " << entries << "/" << total_TH750 << " = " << entries/total_TH750 * 100 << " %" << endl;

  tTH750->Draw("event_CommonCalc>>h",ele_cut4.c_str());
  entries = h->GetEntries();
  cout << " ele_cut4 = " << entries << "/" << total_TH750 << " = " << entries/total_TH750 * 100 << " %" << endl;

  tTH750->Draw("event_CommonCalc>>h",ele_cut5.c_str());
  entries = h->GetEntries();
  cout << " ele_cut5 = " << entries << "/" << total_TH750 << " = " << entries/total_TH750 * 100 << " %" << endl;

  cout << " " << endl;
  cout << "Efficiency for JTH750 sample :" << endl;
  cout << " " << endl;

  Double_t total_JTH750 = 98858; //source: DAS

  tJTH750->Draw("event_CommonCalc>>h");
  entries = h->GetEntries();
  cout << " No cut = " << entries << "/" << total_JTH750 << " = " << entries/total_JTH750 * 100 << " %" << endl;

  tJTH750->Draw("event_CommonCalc>>h",mu_cut1.c_str());
  entries = h->GetEntries();
  cout << " mu_cut1 = " << entries << "/" << total_JTH750 << " = " << entries/total_JTH750 * 100 << " %" << endl;
  
  tJTH750->Draw("event_CommonCalc>>h",mu_cut2.c_str());
  entries = h->GetEntries();
  cout << " mu_cut2 = " << entries << "/" << total_JTH750 << " = " << entries/total_JTH750 * 100 << " %" << endl;

  tJTH750->Draw("event_CommonCalc>>h",mu_cut3.c_str());
  entries = h->GetEntries();
  cout << " mu_cut3 = " << entries << "/" << total_JTH750 << " = " << entries/total_JTH750 * 100 << " %" << endl;

  tJTH750->Draw("event_CommonCalc>>h",mu_cut4.c_str());
  entries = h->GetEntries();
  cout << " mu_cut4 = " << entries << "/" << total_JTH750 << " = " << entries/total_JTH750 * 100 << " %" << endl;

  tJTH750->Draw("event_CommonCalc>>h",mu_cut5.c_str());
  entries = h->GetEntries();
  cout << " mu_cut5 = " << entries << "/" << total_JTH750 << " = " << entries/total_JTH750 * 100 << " %" << endl;

  tJTH750->Draw("event_CommonCalc>>h",ele_cut1.c_str());
  entries = h->GetEntries();
  cout << " ele_cut1 = " << entries << "/" << total_JTH750 << " = " << entries/total_JTH750 * 100 << " %" << endl;
  
  tJTH750->Draw("event_CommonCalc>>h",ele_cut2.c_str());
  entries = h->GetEntries();
  cout << " ele_cut2 = " << entries << "/" << total_JTH750 << " = " << entries/total_JTH750 * 100 << " %" << endl;

  tJTH750->Draw("event_CommonCalc>>h",ele_cut3.c_str());
  entries = h->GetEntries();
  cout << " ele_cut3 = " << entries << "/" << total_JTH750 << " = " << entries/total_JTH750 * 100 << " %" << endl;

  tJTH750->Draw("event_CommonCalc>>h",ele_cut4.c_str());
  entries = h->GetEntries();
  cout << " ele_cut4 = " << entries << "/" << total_JTH750 << " = " << entries/total_JTH750 * 100 << " %" << endl;

  tJTH750->Draw("event_CommonCalc>>h",ele_cut5.c_str());
  entries = h->GetEntries();
  cout << " ele_cut5 = " << entries << "/" << total_JTH750 << " = " << entries/total_JTH750 * 100 << " %" << endl;

  cout << " " << endl;

}
