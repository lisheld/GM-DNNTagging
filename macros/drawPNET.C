void drawPNET()
{


  //TFile *fin = new TFile("hist_ppref.root");
  TFile *fin = new TFile("hist.root");

  TH2D *hc = (TH2D*)fin->Get("hc");
  TH2D *hb = (TH2D*)fin->Get("hb");
  TH2D *hl = (TH2D*)fin->Get("hl");

  TH1D *hcy = (TH1D*)hc->ProjectionY("hcy");
  TH1D *hby = (TH1D*)hb->ProjectionY("hby");
  TH1D *hly = (TH1D*)hl->ProjectionY("hly");

  TCanvas *c0=new TCanvas("c0","c0",600,600);

  hcy->Scale(1./hcy->Integral());
  hby->Scale(1./hby->Integral());
  hly->Scale(1./hly->Integral());

  hcy->SetLineColor(kGreen);
  hcy->SetMarkerColor(kGreen);
  hby->SetLineColor(kRed);
  hby->SetMarkerColor(kRed);
  
  hcy->Draw("");
  hby->Draw("same");
  hly->Draw("same");

  const int nbins = 100;
  
  TGraph *gCvsB = new TGraph(nbins);
  TGraph *gCvsL = new TGraph(nbins);

  //double integralC = hcy->Integral(0,nbins+1);
  //double integralB = hby->Integral(0,nbins+1);
  //double integralL = hly->Integral(0,nbins+1);
  double integralC = hcy->Integral(1,nbins);
  double integralB = hby->Integral(1,nbins);
  double integralL = hly->Integral(1,nbins);
  
  for(int i = 0;i<nbins;i++){
    //double effC = hcy->Integral(i+1,nbins+1)/integralC;
    //double effB = hby->Integral(i+1,nbins+1)/integralB;
    //double effL = hly->Integral(i+1,nbins+1)/integralL;
    double effC = hcy->Integral(i+1,nbins)/integralC;
    double effB = hby->Integral(i+1,nbins)/integralB;
    double effL = hly->Integral(i+1,nbins)/integralL;
    
    gCvsB->SetPoint(i,effC,effB);
    gCvsL->SetPoint(i,effC,effL);

  }

  gCvsB->SetLineColor(kRed);

  gCvsB->SetLineWidth(3);
  gCvsL->SetLineWidth(3);
  
  gCvsB->GetXaxis()->SetTitle("tagging efficiency");
  gCvsB->GetYaxis()->SetTitle("mistag rate");
 
  TCanvas *c1=new TCanvas("c1","c1",600,600);
  c1->SetLogy();

  
  gCvsB->Draw("al");
  gCvsL->Draw("l");

  
  
  TLegend *leg=new TLegend(0.6,0.3,0.8,0.5);
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->AddEntry(gCvsL,"charm:light","l");
  leg->AddEntry(gCvsB,"charm:bottom","l");
  leg->Draw();
}
