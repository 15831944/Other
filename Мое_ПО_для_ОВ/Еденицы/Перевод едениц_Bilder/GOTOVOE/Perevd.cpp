//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Perevd.res");
USEFORM("Perevod.cpp", Frm_prvd);
USEUNIT("EDT_KPR.cpp");
USEUNIT("PRVD.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TFrm_prvd), &Frm_prvd);
         Application->Run();

        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
