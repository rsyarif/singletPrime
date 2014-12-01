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
  const Double_t step = 0.1;
  const Int_t nPoints = ceil( (end-start+step) /step ); //count number of points to calculate
  cout << "start, end, step, nPoints : " << start << ", " << end << ", " << step << ", " << nPoints << endl;

  TCanvas *canvas = new TCanvas();
  TCanvas *canvas2 = new TCanvas();
  TCanvas *canvas3 = new TCanvas();
  TCanvas *canvas4 = new TCanvas();
  TCanvas *canvas5 = new TCanvas();

  TCanvas *canvas6 = new TCanvas();
  TMultiGraph *mg = new TMultiGraph();

  TGraph *gr = new TGraph(nPoints); //eff_bkg vs eff_sig 
  TGraph *gr2 = new TGraph(nPoints); // S/B vs eff_sig
  TGraph *gr3 = new TGraph(nPoints); // S/sqrtB vs eff_sig
  TGraph *gr4 = new TGraph(nPoints); // S/sqrt(S + B) vs eff_sig
  TGraph *gr5 = new TGraph(nPoints); // S/sqrt(S + B + deltaB) vs eff_sig

  std::vector<std::string> maxJetEta;
  Double_t eff_sig ;
  Double_t eff_bkg ;
  Double_t S;
  Double_t B;
  const Double_t xsec_sig = 1.0;
  const Double_t xsec_bkg = 239.0; //ttbar xsec
  const Double_t lumi = 197300;
  const Double_t delta = 0.2;
  for(Int_t i = 0; i < nPoints; i++)
    {
      //convert eta (double) to string
      std::ostringstream strs;
      strs << start + step*i;
      std::string eta_str = strs.str();
      cout << "eta_str = " << eta_str << endl;
      //

      maxJetEta.push_back(eta_str);
       
      eff_sig = CalcEfficiency("../root_files/new/","TpJTH","750",98858.,"event_CommonCalc",true,maxJetEta[i]);
      eff_bkg = CalcEfficiency("../root_files/","TT","",25424818. + 4246444. + 10537444.,"event_CommonCalc",true,maxJetEta[i]); 

      S = eff_sig * xsec_sig * lumi;
      B = eff_bkg * xsec_bkg * lumi;
     
      gr->SetPoint(i,eff_sig,eff_bkg);
      gr2->SetPoint(i,eff_sig,S/B);
      gr3->SetPoint(i,eff_sig,S/sqrt(B));
      gr4->SetPoint(i,eff_sig,S/sqrt(S+B));
      gr5->SetPoint(i,eff_sig,S/sqrt(S+B+delta*B));
      
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

  gr2->SetLineColor(2);
  gr2->SetLineWidth(2);
  gr2->SetMarkerColor(4);
  gr2->SetMarkerStyle(21);
  gr2->SetTitle("S/B");
  gr2->GetXaxis()->SetTitle("Tprime Jet to TH (750 GeV) efficiency");
  gr2->GetXaxis()->SetTitleOffset(1.2);
  gr2->GetYaxis()->SetTitle("S/B");
  gr2->GetYaxis()->SetTitleOffset(1.4);
  
  gr3->SetLineColor(2);
  gr3->SetLineWidth(2);
  gr3->SetMarkerColor(4);
  gr3->SetMarkerStyle(21);
  gr3->SetTitle("S/#sqrt{B}");
  gr3->GetXaxis()->SetTitle("Tprime Jet to TH (750 GeV) efficiency");
  gr3->GetXaxis()->SetTitleOffset(1.2);
  gr3->GetYaxis()->SetTitle("S/#sqrt{B}");
  gr3->GetYaxis()->SetTitleOffset(1.4);
  
  gr4->SetLineColor(3);
  gr4->SetLineWidth(2);
  gr4->SetMarkerColor(7);
  gr4->SetMarkerStyle(21);
  gr4->SetTitle("S/#sqrt{S+B}");
  gr4->GetXaxis()->SetTitle("Tprime Jet to TH (750 GeV) efficiency");
  gr4->GetXaxis()->SetTitleOffset(1.2);
  gr4->GetYaxis()->SetTitle("S/#sqrt{S+B}");
  gr4->GetYaxis()->SetTitleOffset(1.4);
  
  gr5->SetLineColor(4);
  gr5->SetLineWidth(2);
  gr5->SetMarkerColor(8);
  gr5->SetMarkerStyle(21);
  gr5->SetTitle("S/#sqrt{S+B+#deltaB}");
  gr5->GetXaxis()->SetTitle("Tprime Jet to TH (750 GeV) efficiency");
  gr5->GetXaxis()->SetTitleOffset(1.2);
  gr5->GetYaxis()->SetTitle("S/#sqrt{S+B+#deltaB}");
  gr5->GetYaxis()->SetTitleOffset(1.4);

  //marking eta>1.5
  for(Int_t  i=0; i<nPoints ;i++)
    {
      if((start+step*i)==1.5){
	TLatex *marker = new TLatex(gr->GetX()[i], gr->GetY()[i],"#eta>1.5");
	marker->SetTextSize(0.03);
	gr->GetListOfFunctions()->Add(marker);	
	TLatex *marker = new TLatex(gr2->GetX()[i], gr2->GetY()[i],"#eta>1.5");
	marker->SetTextSize(0.03);
	gr2->GetListOfFunctions()->Add(marker);
	TLatex *marker = new TLatex(gr3->GetX()[i], gr3->GetY()[i],"#eta>1.5");
	marker->SetTextSize(0.03);
	gr3->GetListOfFunctions()->Add(marker);
	TLatex *marker = new TLatex(gr4->GetX()[i], gr4->GetY()[i],"#eta>1.5");
	marker->SetTextSize(0.03);
	gr4->GetListOfFunctions()->Add(marker);
	TLatex *marker = new TLatex(gr5->GetX()[i], gr5->GetY()[i],"#eta>1.5");
	marker->SetTextSize(0.03);
	gr5->GetListOfFunctions()->Add(marker);
      }
    }
  
  //marking starting value in graph
  std::ostringstream strs;  //convert start (double) to string
  strs << start; 
  std::string start_str = strs.str();
  TLatex *marker_2 = new TLatex(gr->GetX()[0], gr->GetY()[0],("#eta>"+start_str).c_str());
  marker_2->SetTextSize(0.03);
  gr->GetListOfFunctions()->Add(marker_2);
  TLatex *marker_2 = new TLatex(gr2->GetX()[0], gr2->GetY()[0],("#eta>"+start_str).c_str());
  marker_2->SetTextSize(0.03);
  gr2->GetListOfFunctions()->Add(marker_2);
  TLatex *marker_2 = new TLatex(gr3->GetX()[0], gr3->GetY()[0],("#eta>"+start_str).c_str());
  marker_2->SetTextSize(0.03);
  gr3->GetListOfFunctions()->Add(marker_2);
  TLatex *marker_2 = new TLatex(gr4->GetX()[0], gr4->GetY()[0],("#eta>"+start_str).c_str());
  marker_2->SetTextSize(0.03);
  gr4->GetListOfFunctions()->Add(marker_2);
  TLatex *marker_2 = new TLatex(gr5->GetX()[0], gr5->GetY()[0],("#eta>"+start_str).c_str());
  marker_2->SetTextSize(0.03);
  gr5->GetListOfFunctions()->Add(marker_2);
  
  canvas->cd();
  gr->Draw("APL");    
  canvas->SaveAs("ROC_Curve.png");

  canvas2->cd();
  gr2->Draw("APL");    
  canvas2->SaveAs("ROC_SB_Curve.png");

  canvas3->cd();
  gr3->Draw("APL");    
  canvas3->SaveAs("ROC_SsqrtB_Curve.png");

  canvas4->cd();
  gr4->Draw("APL");    
  canvas4->SaveAs("ROC_SsqrtSB_Curve.png");

  canvas5->cd();
  gr5->Draw("APL");    
  canvas5->SaveAs("ROC_SsqrtSBdeltaB_Curve.png");

  canvas6->cd();
  mg->SetTitle(";TpJTH750 efficiency;");
  mg->Add(gr4);
  mg->Add(gr5);
  gr3->Draw("APL");    
  gr3->GetYaxis()->SetTitle("");
  mg->Draw("PL");
  canvas6->BuildLegend(0.1,0.75,0.3,0.9);
  canvas6->SaveAs("ROC_superimpose_Curve.png");

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
