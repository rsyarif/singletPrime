#include <iostream>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TGraph.h"
#include "TCanvas.h"

/* Define Cuts */
  
std::string cut(const bool isMu, const string &  maxJetEta_cut){
  
  std::string cuts = "&&nSelJets_CommonCalc>1&&CA8Tau21_JetSubCalc[0]<0.5&&CA8JetPt_JetSubCalc>200&&CAWCSVMSubJets_JetSubCalc[0]==2&&CAWJetMass_JetSubCalc[0]>85&&CAWJetMass_JetSubCalc[0]<145&&maxJetEta_LjetsTopoCalcNew>";
  
  if(isMu)
    { 
      std::string allcut ="nTightMuons_CommonCalc==1" +  cuts + maxJetEta_cut.c_str();
    }
  else
    {
      std::string allcut = "nTightMuons_CommonCalc==0" +  cuts + maxJetEta_cut.c_str();
    }
  return allcut;
}

double CalcEfficiency(const string & dir, const string & name, const string & mass, const Double_t total, const string & var, const bool isMu, const string & eta_cut)
{
  TFile *f = new TFile((dir + name + mass + ".root").c_str()); //note: include forward slash when writing directory
  TTree *t = (TTree *) f->Get("ljmet");

  std::string cut = cut(isMu, eta_cut.c_str()); 
  
  Double_t entries =  t->Draw("event_CommonCalc",cut.c_str());
  
  Double_t efficiency = entries/total;

  cout << "efficiency = " << entries << "/" << total << " = " << efficiency * 100. << " %" << endl;
  
  return efficiency;
  
}

void CalcAll()
{ 
  const Int_t n=36;
  Double_t x[n],y[n];
  
  x[0] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"1.0");
  x[1] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"1.1");
  x[2] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"1.2");
  x[3] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"1.3");
  x[4] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"1.4");
  x[5] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"1.5");
  x[6] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"1.6");
  x[7] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"1.7");
  x[8] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"1.8");
  x[9] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"1.9");
  x[10] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"2.0");
  x[11] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"2.1");
  x[12] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"2.2");
  x[13] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"2.3");
  x[14] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"2.4");
  x[15] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"2.5");
  x[16] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"2.6");
  x[17] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"2.7");
  x[18] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"2.8");
  x[19] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"2.9");
  x[20] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"3.0");
  x[21] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"3.1");
  x[22] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"3.2");
  x[23] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"3.3");
  x[24] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"3.4");
  x[25] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"3.5");
  x[26] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"3.6");
  x[27] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"3.7");
  x[28] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"3.8");
  x[29] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"3.9");
  x[30] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"4.0");
  x[31] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"4.1");
  x[32] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"4.2");
  x[33] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"4.3");
  x[34] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"4.4");
  x[35] = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"4.5");
  

  y[0] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"1.0");
  y[1] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"1.1");
  y[2] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"1.2");
  y[3] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"1.3");
  y[4] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"1.4");
  y[5] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"1.5");
  y[6] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"1.6");
  y[7] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"1.7");
  y[8] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"1.8");
  y[9] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"1.9");
  y[10] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"2.0");
  y[11] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"2.1");
  y[12] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"2.2");
  y[13] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"2.3");
  y[14] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"2.4");
  y[15] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"2.5");
  y[16] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"2.6");
  y[17] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"2.7");
  y[18] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"2.8");
  y[19] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"2.9");
  y[20] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"3.0");
  y[21] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"3.1");
  y[22] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"3.2");
  y[23] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"3.3");
  y[24] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"3.4");
  y[25] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"3.5");
  y[26] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"3.6");
  y[27] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"3.7");
  y[28] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"3.8");
  y[29] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"3.9");
  y[30] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"4.0");
  y[31] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"4.1");
  y[32] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"4.2");
  y[33] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"4.3");
  y[34] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"4.4");
  y[35] = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,"4.5");
  

  TCanvas *c2 = new TCanvas();
  gr = new TGraph(n,x,y);
  gr->SetLineColor(2);
  gr->SetLineWidth(2);
  gr->SetMarkerColor(4);
  gr->SetMarkerStyle(21);
  gr->SetTitle("ROC Curve");
  gr->GetXaxis()->SetTitle("Tprime Jet to TH (750 GeV) efficiency");
  gr->GetXaxis()->SetTitleOffset(1.2);
  gr->GetYaxis()->SetTitle("ttbar efficiency");
  gr->GetYaxis()->SetTitleOffset(1.4);

  //write info next to points
  TLatex *marker = new TLatex(gr->GetX()[5], gr->GetY()[5],"(eta>1.5)");
  marker->SetTextSize(0.03);
  gr->GetListOfFunctions()->Add(marker);
  TLatex *marker_2 = new TLatex(gr->GetX()[0], gr->GetY()[0],"(eta>1.0)");
  marker_2->SetTextSize(0.03);
  gr->GetListOfFunctions()->Add(marker_2);

  gr->Draw("A*PL");    
  c2->Print("ROC_Curve.png");

  /*
  CalcEfficiency("root_files/new/","TpJTH","550",98590.,"event_CommonCalc",true,"2.5");
  CalcEfficiency("root_files/new/","TpJTH","600",91455.,"event_CommonCalc",true,"1.5");
  CalcEfficiency("root_files/new/","TpJTH","650",98427.,"event_CommonCalc",true,"1.5");
  CalcEfficiency("root_files/new/","TpJTH","700",99038.,"event_CommonCalc",true,"1.5");
  CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,"1.5");
  CalcEfficiency("root_files/new/","TpJTH","800",95270.,"event_CommonCalc",true,"1.5");
  CalcEfficiency("root_files/new/","TpJTH","850",98630.,"event_CommonCalc",true,"1.5");
  CalcEfficiency("root_files/new/","TpJTH","900",98471.,"event_CommonCalc",true,"1.5");
  CalcEfficiency("root_files/new/","TpJTH","950",95131.,"event_CommonCalc",true,"1.5");
  CalcEfficiency("root_files/new/","TpJTH","1000",98139.,"event_CommonCalc",true,"1.5");
  */
  
}
