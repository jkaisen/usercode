/* -------------------------------------------------------------------------------------------------------------------------
  Script for dividing the tag and probe pT
  -------------------------------------------------------------------------------------------------------------------------
*/
//  -------------------------------------------------------------------------------------
//  load options & set plot style
//  -------------------------------------------------------------------------------------
#include "TROOT.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TBranch.h"
#include "TLeaf.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TH1.h"
#include "THStack.h"
#include "TH2.h"
#include "TF1.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TMath.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void mistagRate() {
	TFile* f_tagProbePt;

	TH1F* h_topTagPt;
	TH1F* h_topProbePt;
	TH1F* h_mistagrate;

	TCanvas* c1;
	TH1F* Check;

	// getting the tag and probe root file
	cout<<"opening the file"<<endl;
	f_tagProbePt = new TFile("probe_and_tag_hist.root");
	Check = (TH1F*) f_tagProbePt->Get("topTagPt")->Clone();
	cout<<"DEBUG: after reading the file ="<< Check->GetSum()<<endl;

	// getting the topTagPt and topProbePt hists
	cout<<"getting the histograms"<<endl;
	h_topTagPt   = (TH1F*) f_tagProbePt->Get("topTagPt")->Clone();
	h_topProbePt = (TH1F*) f_tagProbePt->Get("topProbePt")->Clone();

	// dividing topProbePt by topTagPt
	h_mistagrate = (TH1F*) h_topTagPt->Clone();
	h_mistagrate->SetName("mistagrate");
	h_mistagrate->SetTitle("Mistag Rate;p_{T}(GeV)");
	h_mistagrate->Divide((TH1F*) h_topProbePt);


	// plotting the mistagrate plot
	cout<<"plotting the mistagRate plot"<<endl;
	c1 = new TCanvas("c" , "" , 800, 600);

	c1->cd();
	h_mistagrate->Draw("");
	c1->Draw();
	c1->SaveAs("mistagRatePlot.png", "png");




}
