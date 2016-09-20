// ADORecord.h: interface for the CADORecord class.
//
//////////////////////////////////////////////////////////////////////
#ifndef __ADORECORD__
#define __ADORECORD__

//*********************************************************
#define INITGUID
#pragma warning(disable:4146)

/*#import "C:\Program Files\Common Files\System\ado\msado15.dll" \*/
#import "msado15.dll" rename_namespace("ADOCG") rename("EOF", "EndOfFile") //ÿõ¨õøüõýþòðª¹
using namespace ADOCG;

#include "icrsint.h"
#include "IfcApi.h"

#include <string>
using namespace std;

class CIfcView;
//*********************************************************
class IFCAPI CADORecord : public _RecordsetPtr
{
  enum {MaxNumBaseFld = 8};
public:
  enum {Integer, Double, String};
  _ConnectionPtr m_ptrConnection;

  CADORecord(_ConnectionPtr pConn = NULL);
  virtual ~CADORecord();
  int Open(const char* strSource);
  int GetData(int NumFld, int Type, void* Data);
  int GetData(const char* NameFld, int Type, void* Data);

};

#pragma warning(disable:4146)

#endif // ndef __ADORECORD__
