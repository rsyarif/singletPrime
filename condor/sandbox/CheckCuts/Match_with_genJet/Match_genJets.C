#include <iostream>
#include <math.h>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TCanvas.h"
#include <string>

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

void Histo2D(std::string & dir, std::string & name, std::string & mass, std::string & var1, std::string & var2, std::string & cut, int bins1, float min1, float max1,  int bins2, float min2, float max2){

  TFile *f1 = new TFile((dir + name + mass + ".root").c_str()); //note: include forward slash when writing directory

  TTree *t1 = (TTree *) f1->Get("ljmet");

  TCanvas *c1 = new TCanvas("c1",(var1+"_vs_"+var2).c_str(),600,400);
  TCanvas *c2 = new TCanvas("c2",(var1+"_vs_"+var2).c_str(),600,600);
  TCanvas *c3 = new TCanvas("c3",(var1+"_vs_"+var2).c_str(),600,400);

  TH2F *h1 = new TH2F("h1","",bins2,min2,max2,bins1,min1,max1);
  TH2F *h2 = new TH2F("h2","",bins2,min2,max2,bins1,min1,max1);
  TH2F *h3 = new TH2F("h3","",bins2,min2,max2,bins1,min1,max1);
  
  h1->GetXaxis()->SetTitle(var2.c_str());
  h1->GetXaxis()->SetTitleOffset(1.75);
  h1->GetYaxis()->SetTitle(var1.c_str());
  h1->GetYaxis()->SetTitleOffset(1.85);

  h2->GetXaxis()->SetTitle(var2.c_str());
  h2->GetXaxis()->SetTitleOffset(1.3);
  h2->GetYaxis()->SetTitle(var1.c_str());
  h2->GetYaxis()->SetTitleOffset(1.1);
  h2->SetStats(0);
 
  h3->GetXaxis()->SetTitle(var2.c_str());
  h3->GetXaxis()->SetTitleOffset(1.75);
  h3->GetYaxis()->SetTitle(var1.c_str());
  h3->GetYaxis()->SetTitleOffset(1.85);
  h1->SetStats(0);


  if(cut==mu_cut2){
    h1->SetTitle("#mu");
    h2->SetTitle("#mu");
    h3->SetTitle("#mu");
  }
  else if(cut==ele_cut2){
    h1->SetTitle("ele");
    h2->SetTitle("ele");
    h3->SetTitle("ele");
  } 

  gStyle->SetPalette(1);

  c1->cd();
  t1->Draw((var1+":"+var2+">>h1").c_str(),cut.c_str(),"LEGO2");
  
  c2->cd();
  t1->Draw((var1+":"+var2+">>h2").c_str(),cut.c_str(),"CONTZ");
  
  c3->cd();
  t1->Draw((var1+":"+var2+">>h3").c_str(),cut.c_str(),"SURF3");

  //temp below is very inefficient
  if(min2==0){
    std::string min = "0";
  }
  else if(min2==200){
    std::string min = "200";
  }
  if (max2==200){
    std::string max = "200";
  }
  else if(max2==800){
    std::string max = "800";
  }

  if(cut==mu_cut2){
    c1->SaveAs(("plots/"+name+mass+"_"+var1+"_vs_"+var2+"_"+min+"_"+max+"_mu_LEGO2Z.png").c_str());
    c2->SaveAs(("plots/"+name+mass+"_"+var1+"_vs_"+var2+"_"+min+"_"+max+"_mu_CONTZ.png").c_str());
    c3->SaveAs(("plots/"+name+mass+"_"+var1+"_vs_"+var2+"_"+min+"_"+max+"_mu_SURF3.png").c_str());
  }
  else if(cut==ele_cut2){
    c1->SaveAs(("plots/"+name+mass+"_"+var1+"_vs_"+var2+"_"+min+"_"+max+"_ele_LEGO2Z.png").c_str());
    c2->SaveAs(("plots/"+name+mass+"_"+var1+"_vs_"+var2+"_"+min+"_"+max+"_ele_CONTZ.png").c_str());
    c3->SaveAs(("plots/"+name+mass+"_"+var1+"_vs_"+var2+"_"+min+"_"+max+"_ele_SURF3.png").c_str());
  }
}

void makeHisto(){
  
  //genCA8
  Histo2D("../root_files/new/","TpJTH","600","CA8Tau21_JetSubCalc[0]","genCA8JetPt_JetSubCalc",mu_cut2,50,0,1,40,0,800);
  Histo2D("../root_files/new/","TpJTH","600","CA8Tau21_JetSubCalc[0]","genCA8JetPt_JetSubCalc",mu_cut2,50,0,1,40,0,200);
  Histo2D("../root_files/new/","TpJTH","600","CA8Tau21_JetSubCalc[0]","genCA8JetPt_JetSubCalc",mu_cut2,50,0,1,40,200,800);

  Histo2D("../root_files/new/","TpJTH","600","CAWJetMass_JetSubCalc[0]","genCA8JetPt_JetSubCalc",mu_cut2,50,0,250,40,0,800);  
  Histo2D("../root_files/new/","TpJTH","600","CAWJetMass_JetSubCalc[0]","genCA8JetPt_JetSubCalc",mu_cut2,50,0,250,40,0,200);  
  Histo2D("../root_files/new/","TpJTH","600","CAWJetMass_JetSubCalc[0]","genCA8JetPt_JetSubCalc",mu_cut2,50,0,250,40,200,800);  

  Histo2D("../root_files/new/","TpJTH","900","CA8Tau21_JetSubCalc[0]","genCA8JetPt_JetSubCalc",mu_cut2,50,0,1,40,0,800);
  Histo2D("../root_files/new/","TpJTH","900","CA8Tau21_JetSubCalc[0]","genCA8JetPt_JetSubCalc",mu_cut2,50,0,1,40,0,200);
  Histo2D("../root_files/new/","TpJTH","900","CA8Tau21_JetSubCalc[0]","genCA8JetPt_JetSubCalc",mu_cut2,50,0,1,40,200,800);

  Histo2D("../root_files/new/","TpJTH","900","CAWJetMass_JetSubCalc[0]","genCA8JetPt_JetSubCalc",mu_cut2,50,0,250,40,0,800);  
  Histo2D("../root_files/new/","TpJTH","900","CAWJetMass_JetSubCalc[0]","genCA8JetPt_JetSubCalc",mu_cut2,50,0,250,40,0,200);  
  Histo2D("../root_files/new/","TpJTH","900","CAWJetMass_JetSubCalc[0]","genCA8JetPt_JetSubCalc",mu_cut2,50,0,250,40,200,800);
  /*
  //Higgs 
  Histo2D("../root_files/new/","TpJTH","600","CA8Tau21_JetSubCalc[0]","genHiggsPt_singleLepCalc",mu_cut2,50,0,1,40,0,800);
  Histo2D("../root_files/new/","TpJTH","600","CA8Tau21_JetSubCalc[0]","genHiggsPt_singleLepCalc",mu_cut2,50,0,1,40,0,200);
  Histo2D("../root_files/new/","TpJTH","600","CA8Tau21_JetSubCalc[0]","genHiggsPt_singleLepCalc",mu_cut2,50,0,1,40,200,800);

  Histo2D("../root_files/new/","TpJTH","600","CAWJetMass_JetSubCalc[0]","genHiggsPt_singleLepCalc",mu_cut2,50,0,250,40,0,800);  
  Histo2D("../root_files/new/","TpJTH","600","CAWJetMass_JetSubCalc[0]","genHiggsPt_singleLepCalc",mu_cut2,50,0,250,40,0,200);  
  Histo2D("../root_files/new/","TpJTH","600","CAWJetMass_JetSubCalc[0]","genHiggsPt_singleLepCalc",mu_cut2,50,0,250,40,200,800);  

  Histo2D("../root_files/new/","TpJTH","900","CA8Tau21_JetSubCalc[0]","genHiggsPt_singleLepCalc",mu_cut2,50,0,1,40,0,800);
  Histo2D("../root_files/new/","TpJTH","900","CA8Tau21_JetSubCalc[0]","genHiggsPt_singleLepCalc",mu_cut2,50,0,1,40,0,200);
  Histo2D("../root_files/new/","TpJTH","900","CA8Tau21_JetSubCalc[0]","genHiggsPt_singleLepCalc",mu_cut2,50,0,1,40,200,800);

  Histo2D("../root_files/new/","TpJTH","900","CAWJetMass_JetSubCalc[0]","genHiggsPt_singleLepCalc",mu_cut2,50,0,250,40,0,800);  
  Histo2D("../root_files/new/","TpJTH","900","CAWJetMass_JetSubCalc[0]","genHiggsPt_singleLepCalc",mu_cut2,50,0,250,40,0,200);  
  Histo2D("../root_files/new/","TpJTH","900","CAWJetMass_JetSubCalc[0]","genHiggsPt_singleLepCalc",mu_cut2,50,0,250,40,200,800);

  //W
  Histo2D("../root_files/new/","TpJTH","600","CA8Tau21_JetSubCalc[0]","genWPt_singleLepCalc",mu_cut2,50,0,1,40,0,800);
  Histo2D("../root_files/new/","TpJTH","600","CA8Tau21_JetSubCalc[0]","genWPt_singleLepCalc",mu_cut2,50,0,1,40,0,200);
  Histo2D("../root_files/new/","TpJTH","600","CA8Tau21_JetSubCalc[0]","genWPt_singleLepCalc",mu_cut2,50,0,1,40,200,800);

  Histo2D("../root_files/new/","TpJTH","600","CAWJetMass_JetSubCalc[0]","genWPt_singleLepCalc",mu_cut2,50,0,250,40,0,800);  
  Histo2D("../root_files/new/","TpJTH","600","CAWJetMass_JetSubCalc[0]","genWPt_singleLepCalc",mu_cut2,50,0,250,40,0,200);  
  Histo2D("../root_files/new/","TpJTH","600","CAWJetMass_JetSubCalc[0]","genWPt_singleLepCalc",mu_cut2,50,0,250,40,200,800);  

  Histo2D("../root_files/new/","TpJTH","900","CA8Tau21_JetSubCalc[0]","genWPt_singleLepCalc",mu_cut2,50,0,1,40,0,800);
  Histo2D("../root_files/new/","TpJTH","900","CA8Tau21_JetSubCalc[0]","genWPt_singleLepCalc",mu_cut2,50,0,1,40,0,200);
  Histo2D("../root_files/new/","TpJTH","900","CA8Tau21_JetSubCalc[0]","genWPt_singleLepCalc",mu_cut2,50,0,1,40,200,800);

  Histo2D("../root_files/new/","TpJTH","900","CAWJetMass_JetSubCalc[0]","genWPt_singleLepCalc",mu_cut2,50,0,250,40,0,800);  
  Histo2D("../root_files/new/","TpJTH","900","CAWJetMass_JetSubCalc[0]","genWPt_singleLepCalc",mu_cut2,50,0,250,40,0,200);  
  Histo2D("../root_files/new/","TpJTH","900","CAWJetMass_JetSubCalc[0]","genWPt_singleLepCalc",mu_cut2,50,0,250,40,200,800);
  */
  //Histo2D("../root_files/new/","TpJTH","600","CA8Tau21_JetSubCalc[0]","CA8JetPt_JetSubCalc",mu_cut2,50,0,1,40,0,800); 
  //Histo2D("../root_files/new/","TpJTH","600","CA8Tau21_JetSubCalc[0]","CA8JetPt_JetSubCalc",ele_cut2,50,0,1,40,0,800); 

  //Histo2D("../root_files/new/","TpJTH","600","CA8Tau21_JetSubCalc[0]","CA8JetPt_JetSubCalc",mu_cut2,50,0,1,40,0,200);
  //Histo2D("../root_files/new/","TpJTH","600","CA8Tau21_JetSubCalc[0]","CA8JetPt_JetSubCalc",ele_cut2,50,0,1,40,0,200);

  //Histo2D("../root_files/new/","TpJTH","600","CA8Tau21_JetSubCalc[0]","CA8JetPt_JetSubCalc",mu_cut2,50,0,1,40,200,800);
  //Histo2D("../root_files/new/","TpJTH","600","CA8Tau21_JetSubCalc[0]","CA8JetPt_JetSubCalc",ele_cut2,50,0,1,40,200,800);

  //Histo2D("../root_files/new/","TpJTH","600","CAWJetMass_JetSubCalc[0]","CA8JetPt_JetSubCalc",mu_cut2,50,0,250,40,0,800);  
  //Histo2D("../root_files/new/","TpJTH","600","CAWJetMass_JetSubCalc[0]","CA8JetPt_JetSubCalc",ele_cut2,50,0,250,40,0,800);

  //Histo2D("../root_files/new/","TpJTH","600","CAWJetMass_JetSubCalc[0]","CA8JetPt_JetSubCalc",mu_cut2,50,0,250,40,0,200);  
  //Histo2D("../root_files/new/","TpJTH","600","CAWJetMass_JetSubCalc[0]","CA8JetPt_JetSubCalc",ele_cut2,50,0,250,40,0,200);

  //Histo2D("../root_files/new/","TpJTH","600","CAWJetMass_JetSubCalc[0]","CA8JetPt_JetSubCalc",mu_cut2,50,0,250,40,200,800);  
  //Histo2D("../root_files/new/","TpJTH","600","CAWJetMass_JetSubCalc[0]","CA8JetPt_JetSubCalc",ele_cut2,50,0,250,40,200,800);
  
  //Histo2D("../root_files/new/","TpJTH","900","CA8Tau21_JetSubCalc[0]","CA8JetPt_JetSubCalc",mu_cut2,50,0,1,40,0,800);  
  //Histo2D("../root_files/new/","TpJTH","900","CA8Tau21_JetSubCalc[0]","CA8JetPt_JetSubCalc",ele_cut2,50,0,1,40,0,800);

  //Histo2D("../root_files/new/","TpJTH","900","CA8Tau21_JetSubCalc[0]","CA8JetPt_JetSubCalc",mu_cut2,50,0,1,40,0,200);  
  //Histo2D("../root_files/new/","TpJTH","900","CA8Tau21_JetSubCalc[0]","CA8JetPt_JetSubCalc",ele_cut2,50,0,1,40,0,200);

  //Histo2D("../root_files/new/","TpJTH","900","CA8Tau21_JetSubCalc[0]","CA8JetPt_JetSubCalc",mu_cut2,50,0,1,40,200,800);  
  //Histo2D("../root_files/new/","TpJTH","900","CA8Tau21_JetSubCalc[0]","CA8JetPt_JetSubCalc",ele_cut2,50,0,1,40,200,800);

  //Histo2D("../root_files/new/","TpJTH","900","CAWJetMass_JetSubCalc[0]","CA8JetPt_JetSubCalc",mu_cut2,50,0,250,40,0,800);  
  //Histo2D("../root_files/new/","TpJTH","900","CAWJetMass_JetSubCalc[0]","CA8JetPt_JetSubCalc",ele_cut2,50,0,250,40,0,800);

  //Histo2D("../root_files/new/","TpJTH","900","CAWJetMass_JetSubCalc[0]","CA8JetPt_JetSubCalc",mu_cut2,50,0,250,40,0,200);  
  //Histo2D("../root_files/new/","TpJTH","900","CAWJetMass_JetSubCalc[0]","CA8JetPt_JetSubCalc",ele_cut2,50,0,250,40,0,200);

  //Histo2D("../root_files/new/","TpJTH","900","CAWJetMass_JetSubCalc[0]","CA8JetPt_JetSubCalc",mu_cut2,50,0,250,40,200,800);  
  //Histo2D("../root_files/new/","TpJTH","900","CAWJetMass_JetSubCalc[0]","CA8JetPt_JetSubCalc",ele_cut2,50,0,250,40,200,800);

  
}

