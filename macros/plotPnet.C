void plotPnet()
{
  cout<<" hello ? "<<endl;

  TFile *f = new TFile("merged_HiForestMiniAOD_1.root");
  TTree *t = (TTree*)f->Get("ak4PFJetAnalyzer/t");

//Declaration of leaves types
   Int_t           run;
   Int_t           evt;
   Int_t           lumi;
   Int_t           nref;
   Float_t         rawpt[20];
   Float_t         jtpt[20];
   Float_t         jteta[20];
   Float_t         jty[20];
   Float_t         jtphi[20];
   Float_t         jtpu[20];
   Float_t         jtm[20];
   Float_t         jtarea[20];
   Int_t           ncalo;
   Float_t         calopt[8];
   Float_t         caloeta[8];
   Float_t         calophi[8];
   Float_t         jtPfCHF[20];
   Float_t         jtPfNHF[20];
   Float_t         jtPfCEF[20];
   Float_t         jtPfNEF[20];
   Float_t         jtPfMUF[20];
   Int_t           jtPfCHM[20];
   Int_t           jtPfNHM[20];
   Int_t           jtPfCEM[20];
   Int_t           jtPfNEM[20];
   Int_t           jtPfMUM[20];
   Float_t         jttau1[20];
   Float_t         jttau2[20];
   Float_t         jttau3[20];
   Float_t         discr_deepCSV[20];
   Float_t         discr_pfJP[20];
   Float_t         discr_deepFlavour[20];
   Float_t         discr_deepFlavour_probc[20];
   Float_t         discr_pnetXform[20];
   Float_t         discr_pnetXform_probc[20];
   Float_t         discr_pX[20];
   Float_t         pthat;
   Float_t         refpt[20];
   Float_t         refeta[20];
   Float_t         refy[20];
   Float_t         refphi[20];
   Float_t         refm[20];
   Float_t         refarea[20];
   Float_t         refdphijt[20];
   Float_t         refdrjt[20];
   Float_t         refparton_pt[20];
   Int_t           refparton_flavor[20];
   Int_t           refparton_flavorForB[20];
   Float_t         genChargedSum[20];
   Float_t         genHardSum[20];
   Float_t         signalChargedSum[20];
   Float_t         signalHardSum[20];
   Int_t           ngen;
   Int_t           genmatchindex[9];
   Float_t         genpt[9];
   Float_t         geneta[9];
   Float_t         geny[9];
   Float_t         genphi[9];
   Float_t         genm[9];
   Float_t         gendphijt[9];
   Float_t         gendrjt[9];

   // Set branch addresses.
   //t->SetBranchAddress("run",&run);
   //t->SetBranchAddress("evt",&evt);
   //t->SetBranchAddress("lumi",&lumi);
   t->SetBranchAddress("nref",&nref);
   //t->SetBranchAddress("ncalo",&ncalo);
   //t->SetBranchAddress("rawpt",rawpt);
   t->SetBranchAddress("jtpt",jtpt);
   t->SetBranchAddress("jteta",jteta);
   //t->SetBranchAddress("jty",jty);
   //t->SetBranchAddress("jtphi",jtphi);
   //t->SetBranchAddress("jtpu",jtpu);
   //t->SetBranchAddress("jtm",jtm);
   //t->SetBranchAddress("jtarea",jtarea);
   //t->SetBranchAddress("ncalo",&ncalo);
   //t->SetBranchAddress("calopt",calopt);
   //t->SetBranchAddress("caloeta",caloeta);
   //t->SetBranchAddress("calophi",calophi);
   //t->SetBranchAddress("jtPfCHF",jtPfCHF);
   //t->SetBranchAddress("jtPfNHF",jtPfNHF);
   //t->SetBranchAddress("jtPfCEF",jtPfCEF);
   //t->SetBranchAddress("jtPfNEF",jtPfNEF);
   //t->SetBranchAddress("jtPfMUF",jtPfMUF);
   //t->SetBranchAddress("jtPfCHM",jtPfCHM);
   //t->SetBranchAddress("jtPfNHM",jtPfNHM);
   //t->SetBranchAddress("jtPfCEM",jtPfCEM);
   //t->SetBranchAddress("jtPfNEM",jtPfNEM);
   //t->SetBranchAddress("jtPfMUM",jtPfMUM);
   //t->SetBranchAddress("jttau1",jttau1);
   //t->SetBranchAddress("jttau2",jttau2);
   //t->SetBranchAddress("jttau3",jttau3);
   //t->SetBranchAddress("discr_deepCSV",discr_deepCSV);
   //t->SetBranchAddress("discr_pfJP",discr_pfJP);
   //t->SetBranchAddress("discr_deepFlavour",discr_deepFlavour);
   //t->SetBranchAddress("discr_deepFlavour_probc",discr_deepFlavour_probc);
   //t->SetBranchAddress("discr_pnetXform",discr_pnetXform);
   t->SetBranchAddress("discr_pnetXform_probc",discr_pnetXform_probc);
   //t->SetBranchAddress("discr_pX",discr_pX);
   //t->SetBranchAddress("pthat",&pthat);
   t->SetBranchAddress("refpt",refpt);
   //t->SetBranchAddress("refeta",refeta);
   //t->SetBranchAddress("refy",refy);
   //t->SetBranchAddress("refphi",refphi);
   //t->SetBranchAddress("refm",refm);
   //t->SetBranchAddress("refarea",refarea);
   //t->SetBranchAddress("refdphijt",refdphijt);
   //t->SetBranchAddress("refdrjt",refdrjt);
   //t->SetBranchAddress("refparton_pt",refparton_pt);
   //t->SetBranchAddress("refparton_flavor",refparton_flavor);
   t->SetBranchAddress("refparton_flavorForB",refparton_flavorForB);
   //t->SetBranchAddress("genChargedSum",genChargedSum);
   //t->SetBranchAddress("genHardSum",genHardSum);
   //t->SetBranchAddress("signalChargedSum",signalChargedSum);
   //t->SetBranchAddress("signalHardSum",signalHardSum);
   //t->SetBranchAddress("ngen",&ngen);
   //t->SetBranchAddress("genmatchindex",genmatchindex);
   //t->SetBranchAddress("genpt",genpt);
   //t->SetBranchAddress("geneta",geneta);
   //t->SetBranchAddress("geny",geny);
   //t->SetBranchAddress("genphi",genphi);
   //t->SetBranchAddress("genm",genm);
   //t->SetBranchAddress("gendphijt",gendphijt);
   //t->SetBranchAddress("gendrjt",gendrjt);

//     This is the loop skeleton
//       To read only selected branches, Insert statements like:
// t->SetBranchStatus("*",0);  // disable all branches
// TTreePlayer->SetBranchStatus("branchname",1);  // activate branchname

   Long64_t nentries = t->GetEntries();

   TH2F *hc = new TH2F("hc","hc",50,0,250,100,0,1);
   TH2F *hb = new TH2F("hb","hb",50,0,250,100,0,1);
   TH2F *hl = new TH2F("hl","hl",50,0,250,100,0,1);


   Long64_t nbytes = 0;
   std::cout<<" hello "<<std::endl;

   for (Long64_t i=0; i<nentries;i++) {

     if(i%10000==0) cout<<" i "<<i<<endl;

      nbytes += t->GetEntry(i);

     for(int j=0;j<nref;j++){

       
       
       if(jtpt[j]<30||jtpt[j]>40) continue;
       if(abs(jteta[j])>2.) continue;
       if(!(refpt[j]>0)) continue;
       if(abs(refparton_flavorForB[j])==4 ) hc->Fill(jtpt[j],discr_pnetXform_probc[j]);
       else if(abs(refparton_flavorForB[j])==5 ) hb->Fill(jtpt[j],discr_pnetXform_probc[j]);
       else hl->Fill(jtpt[j],discr_pnetXform_probc[j]);
       
     }
   }
   TFile *fout = new TFile("hist.root","RECREATE");
   hc->Write();
   hb->Write();
   hl->Write();
   fout->Close();
}




