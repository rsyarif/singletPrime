#include <iostream>
#include <string>
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

void makeGraph()
{ 
  const Double_t start = 1.0;
  const Double_t end = 4.5;
  const Double_t step = 0.01;
  const Int_t nPoints = ceil( (end-start+step) /step ); //count number of points to calculate
  cout << "start, end, step, nPoints : " << start << ", " << end << ", " << step << ", " << nPoints << endl;

  TCanvas *canvas = new TCanvas();
  TGraph *gr = new TGraph(nPoints); 

  std::vector<std::string> maxJetEta;
  for(Int_t i = 0; i < nPoints; i++)
    {
      //convert eta (double) to string
      std::ostringstream strs;
      strs << start + step*i;
      std::string eta_str = strs.str();
      cout << "eta_str = " << eta_str << endl;
      //

      maxJetEta.push_back(eta_str);
       
      Double_t eff_sig = CalcEfficiency("root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,maxJetEta[i]);
      Double_t eff_bkg = CalcEfficiency("root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,maxJetEta[i]); 
      
      gr->SetPoint(i,eff_sig,eff_bkg);
      
      //clear osstringstream
      strs.str(std::string());
      eta_str.clear();
    }
 
  gr->SetLineColor(2);
  gr->SetLineWidth(2);
  gr->SetMarkerColor(4);
  gr->SetMarkerStyle(21);
  gr->SetTitle("ROC Curve");
  gr->GetXaxis()->SetTitle("Tprime Jet to TH (750 GeV) efficiency");
  gr->GetXaxis()->SetTitleOffset(1.2);
  gr->GetYaxis()->SetTitle("ttbar efficiency");
  gr->GetYaxis()->SetTitleOffset(1.4);

  //marking eta>1.5
  for(Int_t  i=0; i<nPoints ;i++)
    {
      if((start+step*i)==1.5){
	TLatex *marker = new TLatex(gr->GetX()[i], gr->GetY()[i],"(eta>1.5)");
	marker->SetTextSize(0.03);
	gr->GetListOfFunctions()->Add(marker);
      }
    }
  
  //marking starting value in graph
  std::ostringstream strs;  //convert start (double) to string
  strs << start; 
  std::string start_str = strs.str();
  TLatex *marker_2 = new TLatex(gr->GetX()[0], gr->GetY()[0],("eta>"+start_str).c_str());
  marker_2->SetTextSize(0.03);
  gr->GetListOfFunctions()->Add(marker_2);

  gr->Draw("AL");    
  canvas->Print("ROC_Curve.png");
  

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
