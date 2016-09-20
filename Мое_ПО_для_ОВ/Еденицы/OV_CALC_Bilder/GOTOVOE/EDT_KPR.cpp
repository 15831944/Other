//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "EDT_KPR.h"
#include "Perevod.h"
//---------------------------------------------------------------------------
void EDT_KPR(char &Key)
{
    switch (Key)
    {   case '0':;case '1':;case '2':;case '3':;case '4':;case '5':;
        case '6':;case '7':;case '8':;case '9':;case 8:
            break;
        case'e':;case'E':
            if(!AnsiPos("e",((TEdit *)Frm_prvd->ActiveControl)->Text)&&
               !AnsiPos("E",((TEdit *)Frm_prvd->ActiveControl)->Text))Key='E';
            else Key='\0';
            break;
        case '.':;case ',':
            if(!AnsiPos(",",((TEdit *)Frm_prvd->ActiveControl)->Text))Key=',';
            else Key='\0';
            break;
        case '-':
            if(AnsiPos("e",((TEdit *)Frm_prvd->ActiveControl)->Text)||
                AnsiPos("E",((TEdit *)Frm_prvd->ActiveControl)->Text) &&
                !AnsiPos("-",((TEdit *)Frm_prvd->ActiveControl)->Text))Key='-';
            else Key='\0';
            break;
        default: Key='\0';
    }    
}
//---------------------------------------------------------------------------

