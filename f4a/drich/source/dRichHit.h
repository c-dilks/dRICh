#ifndef DRICHHIT_H
#define DRICHHIT_H

#include <g4main/PHG4Hit.h>
#include <g4main/PHG4Hitv1.h>
#include <g4main/PHG4HitDefs.h>

#include <climits>  // for INT_MIN, ULONG_LONG_MAX
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <utility>

#include <G4ThreeVector.hh>
#include <G4String.hh>

class dRichHit : public PHG4Hit
{
  public:
    dRichHit() = default;
    explicit dRichHit(const PHG4Hit* g4hit);
    virtual ~dRichHit() = default;
    void Reset();

    // accessors
    int get_trkid() const { return trackid; }
    G4ThreeVector get_position(const int i) const { return hitPos[i]; } // 0=entry, 1=exit
    float get_x(const int i) const { return hitPos[i].x(); }
    float get_y(const int i) const { return hitPos[i].y(); }
    float get_z(const int i) const { return hitPos[i].z(); }
    float get_t(const int i) const { return t[i]; }
    G4ThreeVector get_momentum() const { return momVec; }
    G4ThreeVector get_momentum_dir() const { return momDir; }
    G4ThreeVector get_vertex_position() const { return vtxPos; }
    G4ThreeVector get_vertex_momentum_dir() const { return vtxMomDir; }
    float get_delta_t() const { return t[1]-t[0]; }
    int get_petal() const { return petal; }
    int get_psst() const { return psst; }
    int get_pdg() const { return pdg; }
    G4String get_particle_name() const { return pname; }
    G4String get_process() const { return process; }

    float get_edep() const { return edep; }
    PHG4HitDefs::keytype get_hit_id() const { return hitid; }
    int get_detid() const;
    int get_shower_id() const { return showerid; }

    // modifiers
    void set_position(const int i, const G4ThreeVector v) { hitPos[i] = v; }
    void set_momentum(const G4ThreeVector v) { momVec = v; }
    void set_momentum_dir(const G4ThreeVector v) { momDir = v; }
    void set_vertex_position(const G4ThreeVector v) { vtxPos = v; }
    void set_vertex_momentum_dir(const G4ThreeVector v) { vtxMomDir = v; }
    void set_t(const int i, const float f) { t[i] = f; }
    void set_petal(const int i) { petal = i; }
    void set_psst(const int i) { psst = i; }
    void set_pdg(const int i) { pdg = i; }
    void set_particle_name(const G4String s) { pname = s; }
    void set_process(const G4String s) { process = s; };

    void set_edep(const float f) { edep = f; }
    void set_hit_id(const PHG4HitDefs::keytype i) { hitid = i; }
    void set_shower_id(const int i) { showerid = i; }
    void set_trkid(const int i) { trackid = i; }


    // diagnostics
    virtual void print() const;



  protected:
    float x[2] = {NAN, NAN};
    float y[2] = {NAN, NAN};
    float z[2] = {NAN, NAN};
    float t[2] = {NAN, NAN};
    G4ThreeVector hitPos[2];
    G4ThreeVector momVec,momDir,vtxPos,vtxMomDir;
    int petal = INT_MIN;
    int psst = INT_MIN;
    int pdg = INT_MIN;
    G4String pname,process;
    PHG4HitDefs::keytype hitid = ULONG_LONG_MAX;
    int trackid = INT_MIN;
    int showerid = INT_MIN;
    float edep = NAN;

};

#endif
