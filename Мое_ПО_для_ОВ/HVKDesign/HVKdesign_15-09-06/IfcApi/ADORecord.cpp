
#include "stdafx.h"

#include "IfcApi.h"
#include "ADORecord.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


CADORecord::CADORecord(_ConnectionPtr pConn/*=NULL*/):m_ptrConnection(pConn)
{
  //создать объект Recordset
  CreateInstance(__uuidof(Recordset));

}

CADORecord::~CADORecord()
{
}

int CADORecord::Open(const char* strSource)
{
_variant_t  vtEmpty (DISP_E_PARAMNOTFOUND, VT_ERROR);
_bstr_t bstrEmpty(L"");
  try{
    (*this)->Open((_bstr_t)strSource, 
      m_ptrConnection->ConnectionString,
//      L"Provider=sqloledb;Data Source=;Integrated Security='SSPI';Initial Catalog=Equipment;User Id=;Password=;",

    adOpenDynamic, adLockOptimistic, adCmdText);
  }
  catch(_com_error &e)
  {
    GenerateError(e.Error(), e.Description());
    return FALSE;
  }
return TRUE;
}

int CADORecord::GetData(int NumFld, int Type, void* Data)
{
  try{
    if(Data == NULL) return FALSE;
    if((*this)->Fields->Item[(long)NumFld]->ActualSize > 0)
    { if(Type == Integer)
        *(int*)Data = short((*this)->Fields->Item[(long)NumFld]->Value);
      else if(Type == Double)
        *(double*)Data = double((*this)->Fields->Item[(long)NumFld]->Value);
      else if(Type == String)
        strcpy((char*)Data,
          (char*)(_bstr_t)(*this)->Fields->Item[(long)NumFld]->Value);
    }else
    {
      if(Type == Integer || Type == Double)
        *(int*)Data = 0;
      else if(Type == String)
        strcpy((char*)Data, "");
    }
  }catch(_com_error &e)
  { GenerateError(e.Error(), e.Description());
    return FALSE;
  }
  return TRUE;
}

int CADORecord::GetData(const char* NameFld, int Type, void* Data)
{
  try{
    if(Data == NULL) return FALSE;
    if((*this)->Fields->Item[NameFld]->ActualSize > 0)
    { if(Type == Integer)
        *(int*)Data = short((*this)->Fields->Item[NameFld]->Value);
      else if(Type == Double)
        *(double*)Data = double((*this)->Fields->Item[NameFld]->Value);
      else if(Type == String)
        strcpy((char*)Data, 
             (char*)(_bstr_t)(*this)->Fields->Item[NameFld]->Value);
    }else
    {
      if(Type == Integer || Type == Double)
        *(int*)Data = 0;
      else if(Type == String)
        strcpy((char*)Data, "");
    }
  }catch(_com_error &e)
  { GenerateError(e.Error(), e.Description());
    return FALSE;
  }

  return TRUE;
}
