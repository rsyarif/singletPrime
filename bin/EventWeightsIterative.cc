#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "PhysicsTools/Utilities/interface/Lumi3DReWeighting.h"
#include "PhysicsTools/Utilities/interface/LumiReWeighting.h"
#include "TFile.h"
#include "TROOT.h"
#include "TKey.h"
#include "TTree.h"
#include "TH1F.h"


std::vector<float> data;
std::vector<float> mc;
edm::LumiReWeighting *LumiWeightsOld;

void readdir(TDirectory *dir,optutl::CommandLineParser parser,float ev,int doPU,TH1F* puWeight); 



int main (int argc, char* argv[]) 
{
   optutl::CommandLineParser parser ("Sets Event Weights in the ntuple");
   parser.addOption("histoName",optutl::CommandLineParser::kString,"Counter Histogram Name","EventSummary");
   parser.addOption("weight",optutl::CommandLineParser::kDouble,"Weight to apply",1.0);
   parser.addOption("events",optutl::CommandLineParser::kInteger,"Number of AOD Events",0);
   parser.addOption("branch",optutl::CommandLineParser::kString,"Branch","__WEIGHT__");
   parser.addOption("doOneD",optutl::CommandLineParser::kInteger,"Do OneD",0);

   
   parser.parseArguments (argc, argv);
   

   //read PU info
   TH1F *puWeight=0;
   int doPU=0;
   TFile *fPU = new TFile("../puInfo.root");

   if(fPU!=0 && fPU->IsOpen()) {
     puWeight = (TH1F*)fPU->Get("weight");
     doPU=1;
     printf("ENABLING PU WEIGHTING USING VERTICES\n");

   }

   else if(parser.integerValue("doOneD")) {
   
     doPU=2;     
     LumiWeightsOld = new edm::LumiReWeighting("../../PileUp/MC_Summer12_PU_S10-600bins.root ","../../PileUp/Data_Pileup_2012_ReRecoPixel-600bins.root","pileup","pileup");     
     
   }

 
   TFile *g = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");

   TH1F* evC  = (TH1F*)g->Get(parser.stringValue("histoName").c_str());
   float ev = evC->GetBinContent(1);
   
   g->Close();
   
   int events = parser.integerValue("events");
   if (events > 0){
   	ev = events;
   	printf("%f events entered manually\n",ev);
   }
   else{
   	printf("Found  %f Events Counted\n",ev);
   }
   
   TFile *f = new TFile(parser.stringValue("outputFile").c_str(),"UPDATE");   

   readdir(f,parser,ev,doPU,puWeight);
   f->Close();
   if(fPU!=0 && fPU->IsOpen())
     fPU->Close();

} 


void readdir(TDirectory *dir,optutl::CommandLineParser parser,float ev,int doPU,TH1F *puWeight) 
{
  TDirectory *dirsav = gDirectory;
  TIter next(dir->GetListOfKeys());
  TKey *key;
  while ((key = (TKey*)next())) {
    printf("Found key=%s \n",key->GetName());
    TObject *obj = key->ReadObj();

    if (obj->IsA()->InheritsFrom(TDirectory::Class())) {
      dir->cd(key->GetName());
      TDirectory *subdir = gDirectory;
      readdir(subdir,parser,ev,doPU,puWeight);
      dirsav->cd();
    }
    else if(obj->IsA()->InheritsFrom(TTree::Class())) {
      TTree *t = (TTree*)obj;
      float weight = parser.doubleValue("weight")/(ev);


      TBranch *newBranch = t->Branch(parser.stringValue("branch").c_str(),&weight,(parser.stringValue("branch")+"/F").c_str());
      int vertices;
      double bxd=0;

      if(doPU==1)
		t->SetBranchAddress("nPV_WprimeCalc",&vertices);
      else if( doPU==2 ){
      	t->SetBranchAddress("nTrueInteractions_PileUpCalc",&bxd);
      }

      printf("Found tree -> weighting\n");
      for(Int_t i=0;i<t->GetEntries();++i){
	  	t->GetEntry(i);
	  	weight = parser.doubleValue("weight")/(ev);
	  	if(doPU==1) {
	    	int bin=puWeight->FindBin(vertices);
	    	if(bin>puWeight->GetNbinsX()){
				printf("Overflow using max bin\n");
				bin = puWeight->GetNbinsX();
	    	}
	    	weight*=puWeight->GetBinContent(bin);
	    	if(i==1)
	      		printf("PU WEIGHT = %f\n",puWeight->GetBinContent(puWeight->FindBin(vertices)));

	  	}
	  	else if(doPU==2) {
	  		float bxf = float(bxd);
	    	weight*=LumiWeightsOld->weight(bxf);
	  	}

	  	newBranch->Fill();
	  }
      t->Write("",TObject::kOverwrite);
    }

  }

}
