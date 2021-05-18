//-----------------------------------------------
// dRich event tree module
//-----------------------------------------------

#ifndef DRICHTREE_H
#define DRICHTREE_H

#include <fun4all/SubsysReco.h>
#include <Rtypes.h>
#include <TString.h>
#include <Geant4/G4ThreeVector.hh>
#include <Geant4/G4String.hh>

//class Fun4AllHistoManager; //---
class PHCompositeNode;
class TFile;
class TTree;
//class TH1; //---
//class TH2; //---

class dRichTree : public SubsysReco
{
  public:
    // constructor
    dRichTree(const std::string &name = "dRichTree",
              const std::string &fname = "dRichTree.root");

    // destructor
    virtual ~dRichTree();

    // SubsysReco processing methods:
    int Init(PHCompositeNode *);
    int process_event(PHCompositeNode *);
    int End(PHCompositeNode *);


  private:

    std::string m_outfileN; // output file name
    TFile *m_outfile; // output file
    TTree *m_tree; // the dRich tree

    //TH1 *m_histo; //---
    // Fun4AllHistoManager *m_hm; // histogram manager //---

    // data accessors
    void getHits(PHCompositeNode *topNode);
    //void getHEPMCTruth(PHCompositeNode *topNode); //---

    void vectorToArray(G4ThreeVector vec, Double_t *arr);
    void initTrees();
    //void resetVars(); //---

    
    //------------------------------
    // tree variables
    //------------------------------

    Int_t evnum;
    Int_t trackID;
    char hitType[128];
    Int_t petal,psst,pdg;
    char particleName[128];
    char process[256];
    Int_t parentID;
    Double_t photHitPos[3]; // [xyz]
    Double_t photP[3];
    Double_t photPdir[3];
    Double_t photVtxPos[3];
    Double_t photVtxPdir[3];
    Double_t photDeltaT;

};

#endif // DRICHTREE_H
