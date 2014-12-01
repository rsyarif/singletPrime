#include <iostream>
#include <math.h>
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

void Histo(std::string & dir, std::string & name, std::string & mass1, std::string & mass2, std::string & var, std::string & cut, int bins, float min, float max){

  TFile *f1 = new TFile((dir + name + mass1 + ".root").c_str()); //note: include forward slash when writing directory
  TFile *f2 = new TFile((dir + name + mass2 + ".root").c_str()); //note: include forward slash when writing directory

  TTree *t1 = (TTree *) f1->Get("ljmet");
  TTree *t2 = (TTree *) f2->Get("ljmet");

  //TCanvas *c1 = new TCanvas("c1",var.c_str(),600,600);
  TH1F *h1 = new TH1F((name+mass1).c_str(),(name+mass1).c_str(),bins,min,max);
  TH1F *h2 = new TH1F((name+mass2).c_str(),(name+mass2).c_str(),bins,min,max);

  h1->GetXaxis()->SetTitle(var.c_str());
  h1->GetYaxis()->SetTitle("Events");
  h1->SetLineWidth(2);

  h2->GetXaxis()->SetTitle(var.c_str());
  h2->GetYaxis()->SetTitle("Events");
  if(cut==mu_cut2){
    h2->SetTitle("#mu");
  }
  else if(cut==ele_cut2){
    h2->SetTitle("ele");
  } 
  h2->SetLineWidth(2);
  h2->SetLineColor(2);

  t2->Draw((var+">>"+name+mass2).c_str(),cut.c_str());
  t1->Draw((var+">>"+name+mass1).c_str(),cut.c_str(),"SAMES");
  
  gPad->Update();
  TPaveStats *st = (TPaveStats*)h1->FindObject("stats");
  st->SetY1NDC(0.8);  
  st->SetY2NDC(0.65); 

  leg = new TLegend(0.125,0.75,0.275,0.85);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->AddEntry(h1,(name+mass1).c_str(),"LP");
  leg->AddEntry(h2,(name+mass2).c_str(),"LP");
  leg->Draw("SAME");

  if(cut==mu_cut2){
    c1->SaveAs(("plots/"+name+mass1+"AND"+mass2+"_"+var+"_mu.png").c_str());
    //c1->SaveAs(("plots/"+name+mass1+"AND"+mass2+"_"+var+"_mu"+".eps").c_str());
      }
  else if(cut==ele_cut2){
    c1->SaveAs(("plots/"+name+mass1+"AND"+mass2+"_"+var+"_ele.png").c_str());
    //c1->SaveAs(("plots/"+name+mass1+"AND"+mass2+"_"+var+"_ele"+".eps").c_str());
      }
}

void makeHisto(){
  Histo("../root_files/new/","TpJTH","600","900","CA8Tau21_JetSubCalc[0]",mu_cut2,50,0,1);  
  Histo("../root_files/new/","TpJTH","600","900","CA8Tau21_JetSubCalc[0]",ele_cut2,50,0,1); 

  Histo("../root_files/new/","TpJTH","600","900","CA8JetPt_JetSubCalc",mu_cut2,40,0,800);  
  Histo("../root_files/new/","TpJTH","600","900","CA8JetPt_JetSubCalc",ele_cut2,40,0,800); 

  Histo("../root_files/new/","TpJTH","600","900","CAWCSVMSubJets_JetSubCalc[0]",mu_cut2,5,-0.5,4.5);  
  Histo("../root_files/new/","TpJTH","600","900","CAWCSVMSubJets_JetSubCalc[0]",ele_cut2,5,-0.5,4.5); 
  
  Histo("../root_files/new/","TpJTH","600","900","CAWJetMass_JetSubCalc[0]",mu_cut2,50,0,250);  
  Histo("../root_files/new/","TpJTH","600","900","CAWJetMass_JetSubCalc[0]",ele_cut2,50,0,250); 

  Histo("../root_files/new/","TpJTH","600","900","maxJetEta_LjetsTopoCalcNew",mu_cut2,50,0,5);  
  Histo("../root_files/new/","TpJTH","600","900","maxJetEta_LjetsTopoCalcNew",ele_cut2,50,0,5);

  Histo("../root_files/new/","TpJTH","700","800","CA8Tau21_JetSubCalc[0]",mu_cut2,50,0,1);  
  Histo("../root_files/new/","TpJTH","700","800","CA8Tau21_JetSubCalc[0]",ele_cut2,50,0,1); 

  Histo("../root_files/new/","TpJTH","700","800","CA8JetPt_JetSubCalc",mu_cut2,40,0,800);  
  Histo("../root_files/new/","TpJTH","700","800","CA8JetPt_JetSubCalc",ele_cut2,40,0,800); 

  Histo("../root_files/new/","TpJTH","700","800","CAWCSVMSubJets_JetSubCalc[0]",mu_cut2,5,-0.5,4.5);  
  Histo("../root_files/new/","TpJTH","700","800","CAWCSVMSubJets_JetSubCalc[0]",ele_cut2,5,-0.5,4.5); 
  
  Histo("../root_files/new/","TpJTH","700","800","CAWJetMass_JetSubCalc[0]",mu_cut2,50,0,250);  
  Histo("../root_files/new/","TpJTH","700","800","CAWJetMass_JetSubCalc[0]",ele_cut2,50,0,250); 

  Histo("../root_files/new/","TpJTH","700","800","maxJetEta_LjetsTopoCalcNew",mu_cut2,50,0,5);  
  Histo("../root_files/new/","TpJTH","700","800","maxJetEta_LjetsTopoCalcNew",ele_cut2,50,0,5);
  
}

