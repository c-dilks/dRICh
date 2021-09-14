// specific study compare <counts>/thrownParticle vs. momentum plots
void drawRatioCounts(TString particle="kaon") {
  gStyle->SetOptStat(0);
  TFile *newFile = new TFile("out/count.new."+particle+".plots.root","read");
  TFile *oldFile = new TFile("out/count.old."+particle+".plots.root","read");
  TProfile *newProf = (TProfile*) newFile->Get("aveHitsVsP");
  TProfile *oldProf = (TProfile*) oldFile->Get("aveHitsVsP");
  TProfile *ratio = (TProfile*) newProf->Clone("ratio");
  ratio->Divide(oldProf);
  ratio->SetMarkerStyle(kFullCircle);
  ratio->SetMarkerColor(kBlack);
  ratio->Draw("HIST P");
};
