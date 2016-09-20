//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
#include "Perevod.h"
#include "EDT_KPR.h"
#include "PRVD.h"
//---------------------------------------------------------------------------
TFrm_prvd *Frm_prvd;

//---------------------------------------------------------------------------
__fastcall TFrm_prvd::TFrm_prvd(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrm_prvd::Btn_ExitClick(TObject *Sender)
{
//  Frm_prvd->Close();
    exit(1);
}
//---------------------------------------------------------------------------
void __fastcall TFrm_prvd::Edt_QGWKeyPress(TObject *Sender, char &Key)
{
    EDT_KPR(Key);
}
//---------------------------------------------------------------------------

void __fastcall TFrm_prvd::Edt_QGWKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    prvd_q();
}
//---------------------------------------------------------------------------


void __fastcall TFrm_prvd::Edt_QGJKeyPress(TObject *Sender, char &Key)
{
    EDT_KPR(Key);
}
//---------------------------------------------------------------------------

void __fastcall TFrm_prvd::Edt_QGJKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    prvd_qq();
}
//---------------------------------------------------------------------------
void __fastcall TFrm_prvd::Edt_QGJ_kKeyPress(TObject *Sender, char &Key)
{
    EDT_KPR(Key);
}
//---------------------------------------------------------------------------

void __fastcall TFrm_prvd::Edt_QGJ_kKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    prvd_c();
}
//---------------------------------------------------------------------------

void __fastcall TFrm_prvd::Edt_PGPaKeyPress(TObject *Sender, char &Key)
{
    EDT_KPR(Key);
}
//---------------------------------------------------------------------------

void __fastcall TFrm_prvd::Edt_PGPaKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    prvd_P();
}
//---------------------------------------------------------------------------


void __fastcall TFrm_prvd::Edt_Gm_hKeyPress(TObject *Sender, char &Key)
{
    EDT_KPR(Key);
}
//---------------------------------------------------------------------------

void __fastcall TFrm_prvd::Edt_Gm_hKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    prvd_G();
}
//---------------------------------------------------------------------------

void __fastcall TFrm_prvd::Lbl_QtutMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    StsBr->SimpleText="тонна условного топлива";

}
//---------------------------------------------------------------------------

void __fastcall TFrm_prvd::TbSht_QQMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    StsBr->SimpleText="";
}
//---------------------------------------------------------------------------

void __fastcall TFrm_prvd::Edt_QtutMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    StsBr->SimpleText="тонна условного топлива";    
}
//---------------------------------------------------------------------------

void __fastcall TFrm_prvd::Edt_Gkg_hKeyPress(TObject *Sender, char &Key)
{
    EDT_KPR(Key);    
}
//---------------------------------------------------------------------------

void __fastcall TFrm_prvd::Edt_Gkg_hKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    prvd_Gm();
}
//---------------------------------------------------------------------------

