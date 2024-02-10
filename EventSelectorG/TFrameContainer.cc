// Autogenerated Class (Source File)
// Author : G.Gavalian
// Date   : Fri Mar 30 10:29:03 EST 2007
//

#include "TFrameContainer.h"
#include "TGuiStudio.h"

ClassImp(TFrameContainer)


const Char_t *filetypes[] = {
    "Config Files",    "*.cfg",
    "Config Files",   "*.Conf",
    "All files",     "*",
    0,               0
};



TFrameContainer::TFrameContainer (const TGWindow* p,
			      TGWindow* buttonHandler, Int_t  drawEventId, Int_t  addcutEventId, Int_t  addhistEventId):
TGCompositeFrame(p, 250, 100, kVerticalFrame| kRaisedFrame)
{
  fButtonLayout = new TGLayoutHints(kLHintsTop | kLHintsLeft | kLHintsExpandX, 5, 2, 2, 2);


  fSelectionFrame = new TGCompositeFrame(this, 100, 100, kHorizontalFrame);
  fTreeView = new TGCanvas(fSelectionFrame, 150, 10, kSunkenFrame | kDoubleBorder);
  
  fParticleList = new TCTParticleList(fTreeView,1);
  fParticleList->SetCanvas(fTreeView);
  fParticleList->Associate(this);
  fTreeView->SetContainer(fParticleList);

  fSelectionFrame->AddFrame(fTreeView,new TGLayoutHints(kLHintsExpandX |kLHintsExpandY, 0, 0, 0, 0));

  fRunButton = new TGTextButton(this, "Run", 1);
  fRunButton->Associate(this);

  fNEventsRun = new TGNumberEntry(this,40000,12,15,TGNumberFormat::kNESInteger);
  fNEventsRun->Associate(this);

  fEditButton = new TGTextButton(this, "Edit", 2);
  fEditButton->Associate(this);

  fDrawButton = new TGTextButton(this, "Draw", 3);
  fDrawButton->Associate(this);

  fNEvtSlider = new TGHSlider(this,100,kScaleBoth,5);

  AddFrame(fSelectionFrame, new TGLayoutHints( kLHintsExpandY|kLHintsExpandX, 0, 0, 0, 0));

  AddFrame(fDrawButton, fButtonLayout); 
  AddFrame(fEditButton, fButtonLayout); 
  AddFrame(fNEvtSlider, fButtonLayout);
  AddFrame(fNEventsRun, fButtonLayout);  
  AddFrame(fRunButton, fButtonLayout);  

  fParticleList->AddParticle("pi+","pi+");
  fParticleList->AddParticle("pi-","pi-");
  fParticleList->AddParticle("proton","proton");
  printf("Number of particles = %d\n",fParticleList->GetNPart());
  //  AddItem("aa");
  //  ShowItems();
  MapSubwindows();
  Resize(GetDefaultSize());
  MapWindow();
  //  Show(); 
}

TFrameContainer::~TFrameContainer (){

}

//-----------------

void   TFrameContainer::_cmd_Run()
{
  Int_t  _n_evt = (Int_t) fNEventsRun->GetIntNumber();
  printf("Gonna Try to Run for %d events\n",_n_evt);
  gGuiStudio->Run(_n_evt);
}
void   TFrameContainer::_cmd_Draw()
{
  TString  _var_name = fParticleList->GetSelectedName();
  gGuiStudio->Draw(_var_name.Data());
}

//-----------------

void    TFrameContainer::UpdateFrame(TCTContainer *_fct)
{
  fParticleList->FillFromContainer(_fct);
}
//-----------------
void    TFrameContainer::Init(const char *ntname,const char *file)
{
  //  fNtUtil = new TNtUtils(ntname);
  //  fNtUtil->AddFile(file);
}
void    TFrameContainer::SetSliderRange(int _min, int _max, int _pos)
{
  fNEvtSlider->SetRange(_min,_max);
  Int_t  _sl_pos_corrected = ((int) (_pos/20000))*20000;
  fNEvtSlider->SetPosition(_pos);
  //  fNEvtSlider->SetScale(50000);
}
void   TFrameContainer::_cmd_ChangeNEvents()
{
  Int_t  _sl_pos = fNEvtSlider->GetPosition();
  Int_t  _sl_pos_corrected = ((int) (_sl_pos/20000))*20000;
  fNEvtSlider->SetPosition(_sl_pos_corrected);
  fNEventsRun->SetIntNumber(_sl_pos_corrected);
  //  printf("Slider position is %d\n",_sl_pos);
}

Bool_t   TFrameContainer::ProcessMessage(Long_t msg, Long_t parm1, Long_t parm2)
{
  Int_t Selection;
  Int_t retval;
  printf("processing message %d %d\n",GET_MSG(msg),GET_SUBMSG(msg));

  if(GET_MSG(msg)==kC_LISTTREE){
    //    printf("This is a list tree item \n");
    if(GET_SUBMSG(msg)==2) _cmd_Draw();
  }
  

  if(GET_MSG(msg)==kC_HSLIDER){
    if(GET_SUBMSG(msg)==kSL_RELEASE) _cmd_ChangeNEvents();
  }

  switch (GET_MSG(msg)) {
     case kC_COMMAND:
       switch (GET_SUBMSG(msg)) {
            case kCM_BUTTON:
	      switch (parm1) {
	      case 1:
		//		printf("button 1 was pressed\n");
		_cmd_Run();
		break;
	      case 2:
		//		printf("button 2 was pressed\n");
		
		break;
	      case 3:
		printf("button 3 was pressed\n");
		{
		  TString aa = fParticleList->GetSelectedName();
		  printf("Selected Item = %s\n",aa.Data());
		  _cmd_Draw();
		}
		//		DrawHisto();
		break;
	      case 11:
		//		printf("button 3 was pressed\n");
		//		DrawHisto("same");
		break;
	      case 6:
		//		printf("button 3 was pressed\n");
		//		LoadConfigFile();
		break;
	      case 7:
		//		printf("button 3 was pressed\n");
		//		SaveConfigFile();
		break;
	      case 8:
		//		printf("button 3 was pressed\n");
		//		DrawHistoAll();
		break;
	      case 9:
		//		printf("button 3 was pressed\n");
		//		SaveFile("default.root");
		break;
		
	      }
       }
  }
}

void    TFrameContainer::SaveFile(const char *filename)
{
  //  fNtUtil->Save("projectoutput.root");
}

void    TFrameContainer::LoadConfigFile(int status)
{


  
}

void    TFrameContainer::OpenProject(const char *filename)
{
 
}

void    TFrameContainer::SaveConfigFile()
{
 
}

void    TFrameContainer::DrawHisto(const char *opt)
{
 
}

void    TFrameContainer::DrawHistoAll()
{

 
}
