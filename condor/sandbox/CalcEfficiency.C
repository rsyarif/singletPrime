#include <iostream>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TCanvas.h"

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


void CalcEfficiency(const string & dir = "root_files/new/", const string & name = "TpJTH", const string & mass = "500", const Double_t total = 1, const string & var = "event_CommonCalc")
{
  TFile *f = new TFile((dir + name + mass + ".root").c_str()); //note: include forward slash when writing directory
  TTree *t = (TTree *) f->Get("ljmet");

  /* Calculate efficiency and print */
  Double_t entries; 
  
  cout << " " << endl;
  cout << "Efficiency for " <<  name.c_str() << mass.c_str() << " sample :" << endl;
  cout << " " << endl;

  entries = t->Draw("event_CommonCalc","");
  cout << " No cut = " << entries << "/" << total << " = " << entries/total * 100 << " %" << endl;
  
  entries = t->Draw(var.c_str(), mu_cut1.c_str() );
  cout << " mu_cut1 = " << entries << "/" << total << " = " << entries/total * 100 << " %" << endl;
  
  entries = t->Draw("event_CommonCalc",mu_cut2.c_str());
  cout << " mu_cut2 = " << entries << "/" << total << " = " << entries/total * 100 << " %" << endl;

  entries = t->Draw("event_CommonCalc",mu_cut3.c_str());
  cout << " mu_cut3 = " << entries << "/" << total << " = " << entries/total * 100 << " %" << endl;

  entries = t->Draw("event_CommonCalc",mu_cut4.c_str());
  cout << " mu_cut4 = " << entries << "/" << total << " = " << entries/total * 100 << " %" << endl;

  entries =  t->Draw("event_CommonCalc",mu_cut5.c_str());
  cout << " mu_cut5 = " << entries << "/" << total << " = " << entries/total * 100 << " %" << endl;

  entries =  t->Draw("event_CommonCalc",mu_cut6.c_str());
  cout << " mu_cut6 = " << entries << "/" << total << " = " << entries/total * 100 << " %" << endl;

  entries = t->Draw("event_CommonCalc", ele_cut1.c_str() );
  cout << " ele_cut1 = " << entries << "/" << total << " = " << entries/total * 100 << " %" << endl;
  
  entries = t->Draw("event_CommonCalc",ele_cut2.c_str());
  cout << " ele_cut2 = " << entries << "/" << total << " = " << entries/total * 100 << " %" << endl;

  entries = t->Draw("event_CommonCalc",ele_cut3.c_str());
  cout << " ele_cut3 = " << entries << "/" << total << " = " << entries/total * 100 << " %" << endl;

  entries = t->Draw("event_CommonCalc",ele_cut4.c_str());
  cout << " ele_cut4 = " << entries << "/" << total << " = " << entries/total * 100 << " %" << endl;

  entries =  t->Draw("event_CommonCalc",ele_cut5.c_str());
  cout << " ele_cut5 = " << entries << "/" << total << " = " << entries/total * 100 << " %" << endl;

  entries =  t->Draw("event_CommonCalc",ele_cut6.c_str());
  cout << " ele_cut6 = " << entries << "/" << total << " = " << entries/total * 100 << " %" << endl;

  cout << " " << endl;
}

void CalcAll()
{
  //CalcEfficiency("root_files/","TpTH","750",199988.,"event_CommonCalc"); //old - from Josh
  //CalcEfficiency("../","TpTH","750",199988.,"event_CommonCalc"); //new - i ran
  //CalcEfficiency("root_files/","TpJTH","750",98858.,"event_CommonCalc"); // old 
  //CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc"); // new

  CalcEfficiency("root_files/new/","TpJTH","500",96117.,"event_CommonCalc");
  CalcEfficiency("root_files/new/","TpJTH","550",98590.,"event_CommonCalc");
  CalcEfficiency("root_files/new/","TpJTH","600",91455.,"event_CommonCalc");
  CalcEfficiency("root_files/new/","TpJTH","650",98427.,"event_CommonCalc");
  CalcEfficiency("root_files/new/","TpJTH","700",99038.,"event_CommonCalc");
  CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc");
  CalcEfficiency("root_files/new/","TpJTH","800",95270.,"event_CommonCalc");
  CalcEfficiency("root_files/new/","TpJTH","850",98630.,"event_CommonCalc");
  CalcEfficiency("root_files/new/","TpJTH","900",98471.,"event_CommonCalc");
  CalcEfficiency("root_files/new/","TpJTH","950",95131.,"event_CommonCalc");
  CalcEfficiency("root_files/new/","TpJTH","1000",98139.,"event_CommonCalc");
}

