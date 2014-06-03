void PlotComp(TString Var, TString nBins, TString lBin, TString hBin, TString XLabel = "", TString Cuts = "", TString Name = "", bool LegRight = true) {


 	TString P1 = Var+">>p1("+nBins+","+lBin+","+hBin+")";
 	TString P2 = Var+">>p2("+nBins+","+lBin+","+hBin+")";
 	TString P3 = Var+">>p3("+nBins+","+lBin+","+hBin+")";
 	TString P4 = Var+">>p4("+nBins+","+lBin+","+hBin+")";
 	TString P5 = Var+">>p5("+nBins+","+lBin+","+hBin+")";
 	
	TFile f1("TpBW750.root");
	TFile f2("TpTH750.root");
	TFile f3("TpTZ750.root");
	TFile f4("TT.root");
	TFile f5("WJets.root");
 	//gStyle->SetOptStat(2211);
 	
 	//TString weight = "__WEIGHT__*__CORR__*19790";	
	TTree* t1 = f1.Get("ljmet");
	TTree* t2 = f2.Get("ljmet");
	TTree* t3 = f3.Get("ljmet");
	TTree* t4 = f4.Get("ljmet");
	TTree* t5 = f5.Get("ljmet");

	TCanvas *C = new TCanvas();
	C->cd();

	t1->Draw(P1,Cuts);
	p1->SetLineColor(kRed);
	p1->Sumw2();
	p1->SetTitle(0);
	double S = 1.0/p1->Integral();
	p1->Scale(S);
	p1->Draw();

	t2->Draw(P2,Cuts,"same");
	p2->Sumw2();
  	double S2 = 1.0/p2->Integral();
  	p2->Scale(S2);
  	p2->SetLineColor(4);
	p2->SetTitle(0);

	t3->Draw(P3,Cuts,"same");
	p3->Sumw2();
  	double S3 = 1.0/p3->Integral();
  	p3->Scale(S3);
  	p3->SetLineColor(3);
	p3->SetTitle(0);

	t4->Draw(P4,Cuts,"same");
	p4->Sumw2();
  	double S4 = 1.0/p4->Integral();
  	p4->Scale(S4);
  	p4->SetLineColor(1);
  	p4->SetMarkerColor(1);
  	p4->SetMarkerStyle(20);
  	p4->SetMarkerSize(0.75);
	p4->SetTitle(0);

	t5->Draw(P5,Cuts,"same");
	p5->Sumw2();
  	double S5 = 1.0/p5->Integral();
  	p5->Scale(S5);
  	p5->SetLineColor(2);
  	p5->SetMarkerColor(2);
  	p5->SetMarkerStyle(34);
  	p5->SetMarkerSize(0.75);
	p5->SetTitle(0);

  	p1->GetXaxis()->SetTitle(XLabel);
  	p1->GetYaxis()->SetTitle("A.U.");
  	
  	vector<double> MaxVec;
  	MaxVec.push_back(p1->GetMaximum());
  	MaxVec.push_back(p2->GetMaximum());
  	MaxVec.push_back(p3->GetMaximum());
  	MaxVec.push_back(p4->GetMaximum());
  	MaxVec.push_back(p5->GetMaximum());
  	  	
  	double max = 0;
  	for( int i=0; i<MaxVec.size(); i++){
  		if(MaxVec[i]>max){
  			max=MaxVec[i];
  		}
  	}
  	p1->SetMaximum(max*1.2);
  	p1->SetMinimum(0.0);
 	p1->Draw("h");
 	p2->Draw("hsame");
 	p3->Draw("hsame");
 	p4->Draw("psame");	
 	p5->Draw("psame");	
 	
	if(LegRight){
		TLegend *le = new TLegend(0.65,0.9,0.9,0.7,"");
	}
	else{
		TLegend *le = new TLegend(0.2,0.9,0.5,0.7,"");
	}
	le->AddEntry(p1,"T[750]#rightarrowBW");
	le->AddEntry(p2,"T[750]#rightarrowtH");
	le->AddEntry(p3,"T[750]#rightarrowtZ");
	le->AddEntry(p4,"t#bar{t}");
	le->AddEntry(p5,"W+Jets");
	le->SetBorderSize(0);
	le->SetFillColor(0);
	le->Draw("same");
	if(Name == ""){
		C->SaveAs("PlotsPNG/"+Var+".png");
		C->SaveAs("PlotsPDF/"+Var+".pdf");
	}
	else{
		C->SaveAs("PlotsPNG/"+Name+".png");
		C->SaveAs("PlotsPDF/"+Name+".pdf");
	}		
	
}