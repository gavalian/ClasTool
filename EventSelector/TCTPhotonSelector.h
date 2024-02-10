// Autogenerated Class (Header File)
// Author : G.Gavalian
// Date   : Mon Apr  2 18:27:33 EDT 2007
//

#ifndef __TCTPhotonSelector__
#define __TCTPhotonSelector__
#include <iostream>
#include <TROOT.h>
#include <TVector3.h>
#include <TObject.h>
#include "TDSTReader.h"
#include "TMiniDSTReader.h"

class TCTPhotonSelector : public TObject {

private:

  TVirtualReader *fReader;

  Double_t    fPhotonTime;
  Double_t    fStartTime;
  Double_t    fPhotonDt;
  Double_t    fPhotonEnergy;
  Int_t       fPhotonEID;
  Int_t       fPhotonTID;
 
public:

TCTPhotonSelector ();
~TCTPhotonSelector ();

 void   SetDSTReader(TVirtualReader *fr){fReader = fr;};

 void   FindBestPhoton();

 Double_t   GetSTT();
 Int_t      GetEID(){return fPhotonEID;};
 Int_t      GetTID(){return fPhotonTID;};
 Double_t   GetDT(){return fPhotonDt;};
 Double_t   GetE(){return fPhotonEnergy;};
 Int_t      GetNGTime(double interval);
 void       SetAllFalse();

ClassDef(TCTPhotonSelector,1)


};
#endif