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

std::vector<Double_t> eff_precut;
std::vector<Double_t> eff_mu_cut1;
std::vector<Double_t> eff_mu_cut2;
std::vector<Double_t> eff_mu_cut3;
std::vector<Double_t> eff_mu_cut4;
std::vector<Double_t> eff_mu_cut5;
std::vector<Double_t> eff_mu_cut6;
std::vector<Double_t> eff_ele_cut1;
std::vector<Double_t> eff_ele_cut2;
std::vector<Double_t> eff_ele_cut3;
std::vector<Double_t> eff_ele_cut4;
std::vector<Double_t> eff_ele_cut5;
std::vector<Double_t> eff_ele_cut6;

Double_t eff_bkg_precut;
std::vector<Double_t> eff_bkg_mu;
std::vector<Double_t> eff_bkg_ele;

void CalcEfficiency(const string & dir = "root_files/new/", const string & name = "TpJTH", const string & mass = "500", const Double_t total = 1, const string & var = "event_CommonCalc", const bool isSig = true)
{
  TFile *f = new TFile((dir + name + mass + ".root").c_str()); //note: include forward slash when writing directory
  TTree *t = (TTree *) f->Get("ljmet");

  /* Calculate efficiency and print */
  std::vector<Double_t> entries = 0; 

  cout << " " << endl;
  cout << "Efficiency for " <<  name.c_str() << mass.c_str() << " sample :" << endl;
  cout << " " << endl;

  if(isSig){
  
    entries.push_back( t->Draw(var.c_str(),"") );
    cout << " No cut = " << entries[0] << "/" << total << " = " << entries[0]/total * 100 << " %" << endl;
    eff_precut.push_back(entries[0]/total);
    
    entries.push_back(t->Draw(var.c_str(), mu_cut1.c_str() ) );
    cout << " mu_cut1 = " << entries[1] << "/" << total << " = " << entries[1]/total * 100 << " %" << endl;
    eff_mu_cut1.push_back(entries[1]/total); 
    
    entries.push_back(t->Draw(var.c_str(),mu_cut2.c_str()));
    cout << " mu_cut2 = " << entries[2] << "/" << total << " = " << entries[2]/total * 100 << " %" << endl;
    eff_mu_cut2.push_back(entries[2]/total);
    
    entries.push_back(t->Draw(var.c_str(),mu_cut3.c_str()));
    cout << " mu_cut3 = " << entries[3] << "/" << total << " = " << entries[3]/total * 100 << " %" << endl;
    eff_mu_cut3.push_back(entries[3]/total);
    
    entries.push_back(t->Draw(var.c_str(),mu_cut4.c_str()));
    cout << " mu_cut4 = " << entries[4] << "/" << total << " = " << entries[4]/total * 100 << " %" << endl;
    eff_mu_cut4.push_back(entries[4]/total);
    
    entries.push_back( t->Draw(var.c_str(),mu_cut5.c_str()));
    cout << " mu_cut5 = " << entries[5] << "/" << total << " = " << entries[5]/total * 100 << " %" << endl;
    eff_mu_cut5.push_back(entries[5]/total);
    
    entries.push_back( t->Draw(var.c_str(),mu_cut6.c_str()));
    cout << " mu_cut6 = " << entries[6] << "/" << total << " = " << entries[6]/total * 100 << " %" << endl;
    eff_mu_cut6.push_back(entries[6]/total);
    
    entries.push_back(t->Draw(var.c_str(), ele_cut1.c_str() )); //entries[7]
    cout << " ele_cut1 = " << entries[7] << "/" << total << " = " << entries[7]/total * 100 << " %" << endl;  
    eff_ele_cut1.push_back(entries[7]/total);
    
    entries.push_back(t->Draw(var.c_str(),ele_cut2.c_str()));
    cout << " ele_cut2 = " << entries[8] << "/" << total << " = " << entries[8]/total * 100 << " %" << endl;
    eff_ele_cut2.push_back(entries[8]/total);
    
    entries.push_back(t->Draw(var.c_str(),ele_cut3.c_str()));
    cout << " ele_cut3 = " << entries[9] << "/" << total << " = " << entries[9]/total * 100 << " %" << endl;
    eff_ele_cut3.push_back(entries[9]/total);
    
    entries.push_back(t->Draw(var.c_str(),ele_cut4.c_str()));
    cout << " ele_cut4 = " << entries[10] << "/" << total << " = " << entries[10]/total * 100 << " %" << endl;
    eff_ele_cut4.push_back(entries[10]/total);
    
    entries.push_back( t->Draw(var.c_str(),ele_cut5.c_str()));
    cout << " ele_cut5 = " << entries[11] << "/" << total << " = " << entries[11]/total * 100 << " %" << endl;
    eff_ele_cut5.push_back(entries[11]/total);
    
    entries.push_back( t->Draw(var.c_str(),ele_cut6.c_str())); //entries[12]
    cout << " ele_cut6 = " << entries[12] << "/" << total << " = " << entries[12]/total * 100 << " %" << endl;
    eff_ele_cut6.push_back(entries[12]/total);
    
    cout << " " << endl;
    
  }

  if(isSig!=true){
    entries.push_back(t->Draw(var.c_str(),"") );
    cout << " No cut = " << entries[0] << "/" << total << " = " << entries[0]/total * 100 << " %" << " = " << entries[0]/total << endl;
    eff_bkg_precut = entries[0]/total;
    
    entries.push_back(t->Draw(var.c_str(), mu_cut1.c_str() ) );
    cout << " mu_cut1 = " << entries[1] << "/" << total << " = " << entries[1]/total * 100 << " %" << endl;
    eff_bkg_mu.push_back(entries[1]/total); 
    
    entries.push_back(t->Draw(var.c_str(),mu_cut2.c_str()));
    cout << " mu_cut2 = " << entries[2] << "/" << total << " = " << entries[2]/total * 100 << " %" << endl;
    eff_bkg_mu.push_back(entries[2]/total);
    
    entries.push_back(t->Draw(var.c_str(),mu_cut3.c_str()));
    cout << " mu_cut3 = " << entries[3] << "/" << total << " = " << entries[3]/total * 100 << " %" << endl;
    eff_bkg_mu.push_back(entries[3]/total);
    
    entries.push_back(t->Draw(var.c_str(),mu_cut4.c_str()));
    cout << " mu_cut4 = " << entries[4] << "/" << total << " = " << entries[4]/total * 100 << " %" << endl;
    eff_bkg_mu.push_back(entries[4]/total);
    
    entries.push_back( t->Draw(var.c_str(),mu_cut5.c_str()));
    cout << " mu_cut5 = " << entries[5] << "/" << total << " = " << entries[5]/total * 100 << " %" << endl;
    eff_bkg_mu.push_back(entries[5]/total);
    
    entries.push_back( t->Draw(var.c_str(),mu_cut6.c_str()));
    cout << " mu_cut6 = " << entries[6] << "/" << total << " = " << entries[6]/total * 100 << " %" << endl;
    eff_bkg_mu.push_back(entries[6]/total);
       
    entries.push_back(t->Draw(var.c_str(), ele_cut1.c_str() ) );
    cout << " ele_cut1 = " << entries[7] << "/" << total << " = " << entries[1]/total * 100 << " %" << endl;
    eff_bkg_ele.push_back(entries[7]/total); 
    
    entries.push_back(t->Draw(var.c_str(),ele_cut2.c_str()));
    cout << " ele_cut2 = " << entries[8] << "/" << total << " = " << entries[2]/total * 100 << " %" << endl;
    eff_bkg_ele.push_back(entries[8]/total);
    
    entries.push_back(t->Draw(var.c_str(),ele_cut3.c_str()));
    cout << " ele_cut3 = " << entries[9] << "/" << total << " = " << entries[3]/total * 100 << " %" << endl;
    eff_bkg_ele.push_back(entries[9]/total);
    
    entries.push_back(t->Draw(var.c_str(),ele_cut4.c_str()));
    cout << " ele_cut4 = " << entries[10] << "/" << total << " = " << entries[4]/total * 100 << " %" << endl;
    eff_bkg_ele.push_back(entries[10]/total);
    
    entries.push_back( t->Draw(var.c_str(),ele_cut5.c_str()));
    cout << " ele_cut5 = " << entries[11] << "/" << total << " = " << entries[5]/total * 100 << " %" << endl;
    eff_bkg_ele.push_back(entries[11]/total);
    
    entries.push_back( t->Draw(var.c_str(),ele_cut6.c_str()));
    cout << " ele_cut6 = " << entries[12] << "/" << total << " = " << entries[6]/total * 100 << " %" << endl;
    eff_bkg_ele.push_back(entries[12]/total);
  }
    
}
  
void CalcAll()
{
  //CalcEfficiency("root_files/","TpTH","750",199988.,"event_CommonCalc"); //old - from Josh
  //CalcEfficiency("../root_files/","TpTH","750",199988.,"event_CommonCalc"); //new - i ran
  //CalcEfficiency("root_files/","TpJTH","750",98858.,"event_CommonCalc"); // old 
  //CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc"); // new

  CalcEfficiency("../root_files/new/","TpJTH","500",96117.,"event_CommonCalc");
  CalcEfficiency("../root_files/new/","TpJTH","550",98590.,"event_CommonCalc");
  CalcEfficiency("../root_files/new/","TpJTH","600",91455.,"event_CommonCalc");
  CalcEfficiency("../root_files/new/","TpJTH","650",98427.,"event_CommonCalc");
  CalcEfficiency("../root_files/new/","TpJTH","700",99038.,"event_CommonCalc");
  CalcEfficiency("../root_files/new/","TpJTH","750",98858.,"event_CommonCalc");
  CalcEfficiency("../root_files/new/","TpJTH","800",95270.,"event_CommonCalc");
  CalcEfficiency("../root_files/new/","TpJTH","850",98630.,"event_CommonCalc");
  CalcEfficiency("../root_files/new/","TpJTH","900",98471.,"event_CommonCalc");
  CalcEfficiency("../root_files/new/","TpJTH","950",95131.,"event_CommonCalc");
  CalcEfficiency("../root_files/new/","TpJTH","1000",98139.,"event_CommonCalc");

  CalcEfficiency("../root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",false); 
}

void makeGraph(){
  CalcAll();
  
  TGraph *g = new TGraph(eff_precut.size());
  TGraph *mu_g1 = new TGraph(eff_mu_cut1.size());
  TGraph *mu_g2  = new TGraph(eff_mu_cut2.size());
  TGraph *mu_g3 = new TGraph(eff_mu_cut3.size());
  TGraph *mu_g4  = new TGraph(eff_mu_cut4.size());
  TGraph *mu_g5 = new TGraph(eff_mu_cut5.size());
  TGraph *mu_g6  = new TGraph(eff_mu_cut6.size());

  TGraph *ele_g1 = new TGraph(eff_ele_cut1.size());
  TGraph *ele_g2  = new TGraph(eff_ele_cut2.size());
  TGraph *ele_g3 = new TGraph(eff_ele_cut3.size());
  TGraph *ele_g4  = new TGraph(eff_ele_cut4.size());
  TGraph *ele_g5 = new TGraph(eff_ele_cut5.size());
  TGraph *ele_g6  = new TGraph(eff_ele_cut6.size());
 
  TGraph *bkg_g = new TGraph(eff_mu_cut1.size());
  TGraph *bkg_mu_g1 = new TGraph(eff_mu_cut1.size());
  TGraph *bkg_mu_g2 = new TGraph(eff_mu_cut1.size());
  TGraph *bkg_mu_g3 = new TGraph(eff_mu_cut1.size());
  TGraph *bkg_mu_g4 = new TGraph(eff_mu_cut1.size());
  TGraph *bkg_mu_g5 = new TGraph(eff_mu_cut1.size());
  TGraph *bkg_mu_g6 = new TGraph(eff_mu_cut1.size());
 
  TGraph *bkg_ele_g1 = new TGraph(eff_ele_cut1.size());
  TGraph *bkg_ele_g2 = new TGraph(eff_ele_cut1.size());
  TGraph *bkg_ele_g3 = new TGraph(eff_ele_cut1.size());
  TGraph *bkg_ele_g4 = new TGraph(eff_ele_cut1.size());
  TGraph *bkg_ele_g5 = new TGraph(eff_ele_cut1.size());
  TGraph *bkg_ele_g6 = new TGraph(eff_ele_cut1.size());

  TCanvas *c2 = new TCanvas("c2","Efficiency Graphs");
  c2->SetLogy();
  //c2->SetGrid();
  //c2->SetTicks();
  TCanvas *c3 = new TCanvas("c3","Efficiency Graphs");                                              
  c3->SetLogy();
  //c3->SetGrid();
  //c3->SetTicks();
  
  for(Int_t i = 0; i < eff_precut.size(); ++i){
    Double_t mass = 500.+ i*50.;
    g->SetPoint(i,mass,eff_precut[i]);

    mu_g1->SetPoint(i,mass,eff_mu_cut1[i]);
    mu_g2->SetPoint(i,mass,eff_mu_cut2[i]);
    mu_g3->SetPoint(i,mass,eff_mu_cut3[i]);
    mu_g4->SetPoint(i,mass,eff_mu_cut4[i]);
    mu_g5->SetPoint(i,mass,eff_mu_cut5[i]);
    mu_g6->SetPoint(i,mass,eff_mu_cut6[i]);
    
    ele_g1->SetPoint(i,mass,eff_ele_cut1[i]);
    ele_g2->SetPoint(i,mass,eff_ele_cut2[i]);
    ele_g3->SetPoint(i,mass,eff_ele_cut3[i]);
    ele_g4->SetPoint(i,mass,eff_ele_cut4[i]);
    ele_g5->SetPoint(i,mass,eff_ele_cut5[i]);
    ele_g6->SetPoint(i,mass,eff_ele_cut6[i]);

    bkg_g->SetPoint(i,mass,eff_bkg_precut);

    bkg_mu_g1->SetPoint(i,mass,eff_bkg_mu[0]);
    bkg_mu_g2->SetPoint(i,mass,eff_bkg_mu[1]);
    bkg_mu_g3->SetPoint(i,mass,eff_bkg_mu[2]);
    bkg_mu_g4->SetPoint(i,mass,eff_bkg_mu[3]);
    bkg_mu_g5->SetPoint(i,mass,eff_bkg_mu[4]);
    bkg_mu_g6->SetPoint(i,mass,eff_bkg_mu[5]);
    
    bkg_ele_g1->SetPoint(i,mass,eff_bkg_ele[0]);
    bkg_ele_g2->SetPoint(i,mass,eff_bkg_ele[1]);
    bkg_ele_g3->SetPoint(i,mass,eff_bkg_ele[2]);
    bkg_ele_g4->SetPoint(i,mass,eff_bkg_ele[3]);
    bkg_ele_g5->SetPoint(i,mass,eff_bkg_ele[4]);
    bkg_ele_g6->SetPoint(i,mass,eff_bkg_ele[5]);
    
  }   
       
  c2->cd();
  
  g->SetLineWidth(2);
  g->SetLineColor(2);
  g->SetMaximum(0.15);
  g->SetMinimum(1e-6);
  g->SetTitle("");
  g->GetXaxis()->SetTitle("TpJTH mass point (GeV)");
  g->GetYaxis()->SetTitle("Efficiency");
  g->Draw("AL*");
  
  mu_g1->SetLineColor(3);
  mu_g1->Draw("L*");
  // superimpose the second graph by leaving out the axis option "A"
  mu_g2->SetLineWidth(2);
  mu_g2->SetMarkerStyle(21);
  mu_g2->SetLineStyle(6);
  mu_g2->SetLineColor(4);
  mu_g2->Draw("L*");

  mu_g3->SetLineWidth(2);
  mu_g3->SetMarkerStyle(22);
  mu_g3->SetLineStyle(7);
  mu_g3->SetLineColor(5);
  mu_g3->Draw("L*");

  mu_g4->SetLineWidth(2);
  mu_g4->SetMarkerStyle(23);
  mu_g4->SetLineStyle(8);
  mu_g4->SetLineColor(6);
  mu_g4->Draw("L*");

  mu_g5->SetLineWidth(2);
  mu_g5->SetMarkerStyle(24);
  mu_g5->SetLineStyle(9);
  mu_g5->SetLineColor(7);
  mu_g5->Draw("L*");

  mu_g6->SetLineWidth(2);
  mu_g6->SetMarkerStyle(25);
  mu_g6->SetLineStyle(10);
  mu_g6->SetLineColor(8);
  mu_g6->Draw("L*");

  bkg_g->SetLineWidth(2);
  bkg_g->SetLineColor(2);
  bkg_g->Draw("L");
  
  bkg_mu_g1->SetLineColor(3);
  bkg_mu_g1->Draw("L");
  // superimpose the second graph by leaving out the axis option "A"
  bkg_mu_g2->SetLineWidth(2);
  bkg_mu_g2->SetMarkerStyle(21);
  bkg_mu_g2->SetLineStyle(6);
  bkg_mu_g2->SetLineColor(4);
  bkg_mu_g2->Draw("L");

  bkg_mu_g3->SetLineWidth(2);
  bkg_mu_g3->SetMarkerStyle(22);
  bkg_mu_g3->SetLineStyle(7);
  bkg_mu_g3->SetLineColor(5);
  bkg_mu_g3->Draw("L");

  bkg_mu_g4->SetLineWidth(2);
  bkg_mu_g4->SetMarkerStyle(23);
  bkg_mu_g4->SetLineStyle(8);
  bkg_mu_g4->SetLineColor(6);
  bkg_mu_g4->Draw("L");

  bkg_mu_g5->SetLineWidth(2);
  bkg_mu_g5->SetMarkerStyle(24);
  bkg_mu_g5->SetLineStyle(9);
  bkg_mu_g5->SetLineColor(7);
  bkg_mu_g5->Draw("L");

  bkg_mu_g6->SetLineWidth(2);
  bkg_mu_g6->SetMarkerStyle(25);
  bkg_mu_g6->SetLineStyle(10);
  bkg_mu_g6->SetLineColor(8);
  bkg_mu_g6->Draw("L");

  leg = new TLegend(0.65,0.125,0.9,0.25);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->AddEntry(g,"precut","LP");
  leg->AddEntry(mu_g1,"mu_cut1","LP");
  leg->AddEntry(mu_g2,"mu_cut2","LP");
  leg->AddEntry(mu_g3,"mu_cut3","LP");
  leg->AddEntry(mu_g4,"mu_cut4","LP");
  leg->AddEntry(mu_g5,"mu_cut5","LP");
  leg->AddEntry(mu_g6,"mu_cut6","LP");
  leg->Draw();

  
  c3->cd();

  g->Draw("AL*");
  
  ele_g1->SetLineColor(3);
  ele_g1->Draw("L*");
  // superimpose the second graph by leaving out the axis option "A"
  ele_g2->SetLineWidth(2);
  ele_g2->SetMarkerStyle(21);
  ele_g2->SetLineStyle(6);
  ele_g2->SetLineColor(4);
  ele_g2->Draw("L*");

  ele_g3->SetLineWidth(2);
  ele_g3->SetMarkerStyle(22);
  ele_g3->SetLineStyle(7);
  ele_g3->SetLineColor(5);
  ele_g3->Draw("L*");

  ele_g4->SetLineWidth(2);
  ele_g4->SetMarkerStyle(23);
  ele_g4->SetLineStyle(8);
  ele_g4->SetLineColor(6);
  ele_g4->Draw("L*");

  ele_g5->SetLineWidth(2);
  ele_g5->SetMarkerStyle(24);
  ele_g5->SetLineStyle(9);
  ele_g5->SetLineColor(7);
  ele_g5->Draw("L*");

  ele_g6->SetLineWidth(2);
  ele_g6->SetMarkerStyle(25);
  ele_g6->SetLineStyle(10);
  ele_g6->SetLineColor(8);
  ele_g6->Draw("L*");

  bkg_g->SetLineWidth(2);
  bkg_g->SetLineColor(2);
  bkg_g->Draw("L");
  
  bkg_ele_g1->SetLineColor(3);
  bkg_ele_g1->Draw("L");
  // superimpose the second graph by leaving out the axis option "A"
  bkg_ele_g2->SetLineWidth(2);
  bkg_ele_g2->SetMarkerStyle(21);
  bkg_ele_g2->SetLineStyle(6);
  bkg_ele_g2->SetLineColor(4);
  bkg_ele_g2->Draw("L");

  bkg_ele_g3->SetLineWidth(2);
  bkg_ele_g3->SetMarkerStyle(22);
  bkg_ele_g3->SetLineStyle(7);
  bkg_ele_g3->SetLineColor(5);
  bkg_ele_g3->Draw("L");

  bkg_ele_g4->SetLineWidth(2);
  bkg_ele_g4->SetMarkerStyle(23);
  bkg_ele_g4->SetLineStyle(8);
  bkg_ele_g4->SetLineColor(6);
  bkg_ele_g4->Draw("L");

  bkg_ele_g5->SetLineWidth(2);
  bkg_ele_g5->SetMarkerStyle(24);
  bkg_ele_g5->SetLineStyle(9);
  bkg_ele_g5->SetLineColor(7);
  bkg_ele_g5->Draw("L");

  bkg_ele_g6->SetLineWidth(2);
  bkg_ele_g6->SetMarkerStyle(25);
  bkg_ele_g6->SetLineStyle(10);
  bkg_ele_g6->SetLineColor(8);
  bkg_ele_g6->Draw("L");

  leg = new TLegend(0.65,0.125,0.9,0.25);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->AddEntry(g,"precut","LP");
  leg->AddEntry(ele_g1,"ele_cut1","LP");
  leg->AddEntry(ele_g2,"ele_cut2","LP");
  leg->AddEntry(ele_g3,"ele_cut3","LP");
  leg->AddEntry(ele_g4,"ele_cut4","LP");
  leg->AddEntry(ele_g5,"ele_cut5","LP");
  leg->AddEntry(ele_g6,"ele_cut6","LP");
  leg->Draw();
 
  c2->Print("Plots/eff_vs_mass_mu_withBkg.png");
  c2->Print("Plots/eff_vs_mass_mu_withBkg.eps");
  c3->Print("Plots/eff_vs_mass_ele_withBkg.png");
  c3->Print("Plots/eff_vs_mass_ele_withBkg.eps");
  
}


void compTHandJTH(){

    CalcEfficiency("../root_files/","TpTH","750",199988.,"event_CommonCalc"); //new - i ran
    CalcEfficiency("../root_files/new/","TpJTH","750",98858.,"event_CommonCalc");

    TGraph *TH_mu = new TGraph(eff_mu_cut1.size());
    TGraph *JTH_mu = new TGraph(eff_mu_cut1.size());
    TGraph *TH_ele = new TGraph(eff_ele_cut1.size());
    TGraph *JTH_ele = new TGraph(eff_ele_cut1.size());

    TCanvas *c2 = new TCanvas("c2","Efficiency Graph (mu)");
    //c2->SetLogy();
    c2->SetGrid();
    TCanvas *c3 = new TCanvas("c3","Efficiency Graphs (e)"); 
    //c3->SetLogy();
    c3->SetGrid();

    TH_mu->SetPoint(0,1,eff_mu_cut1[0]);
    TH_mu->SetPoint(1,2,eff_mu_cut2[0]);
    TH_mu->SetPoint(2,3,eff_mu_cut3[0]);
    TH_mu->SetPoint(3,4,eff_mu_cut4[0]);
    TH_mu->SetPoint(4,5,eff_mu_cut5[0]);
    
    JTH_mu->SetPoint(0,1,eff_mu_cut1[1]);
    JTH_mu->SetPoint(1,2,eff_mu_cut2[1]);
    JTH_mu->SetPoint(2,3,eff_mu_cut3[1]);
    JTH_mu->SetPoint(3,4,eff_mu_cut4[1]);
    JTH_mu->SetPoint(4,5,eff_mu_cut5[1]);
    
    c2->cd();
    
    TH_mu->SetLineWidth(2);
    TH_mu->SetLineColor(2);
    TH_mu->SetMaximum(0.05);
    //TH_mu->SetMinimum(1e-4);
    TH_mu->SetTitle("");
    TH_mu->GetXaxis()->SetTitle("mu_cut type");
    TH_mu->GetXaxis()->SetNdivisions(5);
    TH_mu->GetYaxis()->SetTitle("Efficiency");
    TH_mu->GetYaxis()->SetTitleOffset(1.3);
    TH_mu->Draw("AL*");

    JTH_mu->SetLineColor(3);
    JTH_mu->Draw("L*");

    leg = new TLegend(0.65,0.2+.3,0.9,0.5+.3);
    leg->SetFillStyle(0);
    leg->SetBorderSize(0);
    leg->AddEntry(TH_mu,"TpTH750","LP");
    leg->AddEntry(JTH_mu,"TpJTH750","LP");
    leg->Draw();


    TH_ele->SetPoint(0,1,eff_ele_cut1[0]);
    TH_ele->SetPoint(1,2,eff_ele_cut2[0]);
    TH_ele->SetPoint(2,3,eff_ele_cut3[0]);
    TH_ele->SetPoint(3,4,eff_ele_cut4[0]);
    TH_ele->SetPoint(4,5,eff_ele_cut5[0]);

    JTH_ele->SetPoint(0,1,eff_ele_cut1[1]);
    JTH_ele->SetPoint(1,2,eff_ele_cut2[1]);
    JTH_ele->SetPoint(2,3,eff_ele_cut3[1]);
    JTH_ele->SetPoint(3,4,eff_ele_cut4[1]);
    JTH_ele->SetPoint(4,5,eff_ele_cut5[1]);

    c3->cd();
    
    TH_ele->SetLineWidth(2);
    TH_ele->SetLineColor(2);
    TH_ele->SetMaximum(0.05);
    //TH_ele->SetMinimum(1e-4);
    TH_ele->SetTitle("");
    TH_ele->GetXaxis()->SetTitle("ele_cut type");
    TH_ele->GetXaxis()->SetNdivisions(5);
    TH_ele->GetYaxis()->SetTitle("Efficiency");
    TH_ele->GetYaxis()->SetTitleOffset(1.3);
    TH_ele->Draw("AL*");

    JTH_ele->SetLineColor(3);
    JTH_ele->Draw("L*");

    leg2 = new TLegend(0.65,0.5,0.9,0.8);
    leg2->SetFillStyle(0);
    leg2->SetBorderSize(0);
    leg2->AddEntry(TH_ele,"TpTH750","LP");
    leg2->AddEntry(JTH_ele,"TpJTH750","LP");
    leg2->Draw();

    c2->Print("Plots/effcomp_THvsJTH750_mu.png");
    c2->Print("Plots/effcomp_THvsJTH750_mu.eps");
    c3->Print("Plots/effcomp_THvsJTH750_ele.png");
    c3->Print("Plots/effcomp_THvsJTH750_ele.eps");

}

void graphRatio(){
  CalcAll();

  TGraph *g = new TGraph(eff_precut.size());
  TGraph *mu_g1 = new TGraph(eff_mu_cut1.size());
  TGraph *mu_g2  = new TGraph(eff_mu_cut2.size());
  TGraph *mu_g3 = new TGraph(eff_mu_cut3.size());
  TGraph *mu_g4  = new TGraph(eff_mu_cut4.size());
  TGraph *mu_g5 = new TGraph(eff_mu_cut5.size());
  TGraph *mu_g6  = new TGraph(eff_mu_cut6.size());

  TGraph *ele_g1 = new TGraph(eff_ele_cut1.size());
  TGraph *ele_g2  = new TGraph(eff_ele_cut2.size());
  TGraph *ele_g3 = new TGraph(eff_ele_cut3.size());
  TGraph *ele_g4  = new TGraph(eff_ele_cut4.size());
  TGraph *ele_g5 = new TGraph(eff_ele_cut5.size());
  TGraph *ele_g6  = new TGraph(eff_ele_cut6.size());

  TCanvas *c2 = new TCanvas("c2","Efficiency Graphs");
  c2->SetLogy();
  //c2->SetGrid();
  //c2->SetTicks();
  TCanvas *c3 = new TCanvas("c3","Efficiency Graphs");                                              
  c3->SetLogy();
  //c3->SetGrid();
  //c3->SetTicks();

  for(Int_t i = 0; i < eff_precut.size(); ++i){
    Double_t mass = 500.+ i*50.;
    
    g->SetPoint(i,mass,eff_precut[i]/eff_bkg_precut);

    mu_g1->SetPoint(i,mass,eff_mu_cut1[i]/eff_bkg_mu[0]);
    mu_g2->SetPoint(i,mass,eff_mu_cut2[i]/eff_bkg_mu[1]);
    mu_g3->SetPoint(i,mass,eff_mu_cut3[i]/eff_bkg_mu[2]);
    mu_g4->SetPoint(i,mass,eff_mu_cut4[i]/eff_bkg_mu[3]);
    mu_g5->SetPoint(i,mass,eff_mu_cut5[i]/eff_bkg_mu[4]);
    mu_g6->SetPoint(i,mass,eff_mu_cut6[i]/eff_bkg_mu[5]);
    
    ele_g1->SetPoint(i,mass,eff_ele_cut1[i]/eff_bkg_ele[0]);
    ele_g2->SetPoint(i,mass,eff_ele_cut2[i]/eff_bkg_ele[1]);
    ele_g3->SetPoint(i,mass,eff_ele_cut3[i]/eff_bkg_ele[2]);
    ele_g4->SetPoint(i,mass,eff_ele_cut4[i]/eff_bkg_ele[3]);
    ele_g5->SetPoint(i,mass,eff_ele_cut5[i]/eff_bkg_ele[4]);
    ele_g6->SetPoint(i,mass,eff_ele_cut6[i]/eff_bkg_ele[5]);
  }

  c2->cd();

  g->SetLineWidth(2);
  g->SetLineColor(2);
  g->SetMaximum(10e3);
  g->SetMinimum(1e-1);
  g->SetTitle("");
  g->GetXaxis()->SetTitle("TpJTH mass point (GeV)");
  g->GetYaxis()->SetTitle("Eff_{sig}/Eff_{bkg}");
  g->Draw("AL*");
  
  mu_g1->SetLineColor(3);
  mu_g1->Draw("L*");
  // superimpose the second graph by leaving out the axis option "A"
  mu_g2->SetLineWidth(2);
  mu_g2->SetMarkerStyle(21);
  mu_g2->SetLineStyle(6);
  mu_g2->SetLineColor(4);
  mu_g2->Draw("L*");

  mu_g3->SetLineWidth(2);
  mu_g3->SetMarkerStyle(22);
  mu_g3->SetLineStyle(7);
  mu_g3->SetLineColor(5);
  mu_g3->Draw("L*");

  mu_g4->SetLineWidth(2);
  mu_g4->SetMarkerStyle(23);
  mu_g4->SetLineStyle(8);
  mu_g4->SetLineColor(6);
  mu_g4->Draw("L*");

  mu_g5->SetLineWidth(2);
  mu_g5->SetMarkerStyle(24);
  mu_g5->SetLineStyle(9);
  mu_g5->SetLineColor(7);
  mu_g5->Draw("L*");

  mu_g6->SetLineWidth(2);
  mu_g6->SetMarkerStyle(25);
  mu_g6->SetLineStyle(10);
  mu_g6->SetLineColor(8);
  mu_g6->Draw("L*");

  leg = new TLegend(0.2,0.6,0.5,0.85);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->AddEntry(g,"precut","LP");
  leg->AddEntry(mu_g1,"mu_cut1","LP");
  leg->AddEntry(mu_g2,"mu_cut2","LP");
  leg->AddEntry(mu_g3,"mu_cut3","LP");
  leg->AddEntry(mu_g4,"mu_cut4","LP");
  leg->AddEntry(mu_g5,"mu_cut5","LP");
  leg->AddEntry(mu_g6,"mu_cut6","LP");
  leg->Draw();

  
  c3->cd();

  g->Draw("AL*");
  
  ele_g1->SetLineColor(3);
  ele_g1->Draw("L*");
  // superimpose the second graph by leaving out the axis option "A"
  ele_g2->SetLineWidth(2);
  ele_g2->SetMarkerStyle(21);
  ele_g2->SetLineStyle(6);
  ele_g2->SetLineColor(4);
  ele_g2->Draw("L*");

  ele_g3->SetLineWidth(2);
  ele_g3->SetMarkerStyle(22);
  ele_g3->SetLineStyle(7);
  ele_g3->SetLineColor(5);
  ele_g3->Draw("L*");

  ele_g4->SetLineWidth(2);
  ele_g4->SetMarkerStyle(23);
  ele_g4->SetLineStyle(8);
  ele_g4->SetLineColor(6);
  ele_g4->Draw("L*");

  ele_g5->SetLineWidth(2);
  ele_g5->SetMarkerStyle(24);
  ele_g5->SetLineStyle(9);
  ele_g5->SetLineColor(7);
  ele_g5->Draw("L*");

  ele_g6->SetLineWidth(2);
  ele_g6->SetMarkerStyle(25);
  ele_g6->SetLineStyle(10);
  ele_g6->SetLineColor(8);
  ele_g6->Draw("L*");

  leg = new TLegend(0.2,0.6,0.5,0.85);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->AddEntry(g,"precut","LP");
  leg->AddEntry(ele_g1,"ele_cut1","LP");
  leg->AddEntry(ele_g2,"ele_cut2","LP");
  leg->AddEntry(ele_g3,"ele_cut3","LP");
  leg->AddEntry(ele_g4,"ele_cut4","LP");
  leg->AddEntry(ele_g5,"ele_cut5","LP");
  leg->AddEntry(ele_g6,"ele_cut6","LP");
  leg->Draw();
 
  c2->Print("Plots/effRatio_vs_mass_mu.png");
  c2->Print("Plots/effRatio_vs_mass_mu.eps");
  c3->Print("Plots/effRatio_vs_mass_ele.png");
  c3->Print("Plots/effRatio_vs_mass_ele.eps");

}
