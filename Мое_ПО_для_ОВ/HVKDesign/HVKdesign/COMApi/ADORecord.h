// ADORecord.h: interface for the CADORecord class.
//
//////////////////////////////////////////////////////////////////////
#ifndef __ADORECORD__
#define __ADORECORD__

//*********************************************************
#define INITGUID
#pragma warning(disable:4146)

/*#import "C:\Program Files\Common Files\System\ado\msado15.dll" \*/
#import "msado15.dll" rename_namespace("ADOCG") rename("EOF", "EndOfFile") //переименовать
using namespace ADOCG;

#include "ComApi.h"
#include "icrsint.h"

#include <string>
using namespace std;

class CIfcView;
//*********************************************************
class COMAPI CADORecord : public _RecordsetPtr
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
	int New();
	int Update();
/*	int NumberOfBaseFields;
	CString FieldsName[MaxNumBaseFld];
//	virtual int Open()=0;
//	virtual void DeleteCurrentRecord()=0;
	virtual void Find(CString str);
	void GetDataStrings(CString* str);
//	virtual	void ShowAllItemInListCtrl(CListCtrl* pListCtrl)=0;
//	virtual	void ShowAllItemInTreeCtrl(CTreeCtrl* pTreeCtrl)=0;
//	virtual void ShowSelectedItemInView(CStatic* m_stcText, CEdit* m_edtText)=0;
//	virtual void ShowDataDlg(int IsEdit)=0;
protected:
	void ShowAllItemInListCtrl(CListCtrl* pListCtrl, int level);
	void ShowAllItemInTreeCtrl(CTreeCtrl* pTreeCtrl, int level);
	void ShowSelectedItemInView(CStatic* m_stcText, CEdit* m_edtText, int level);
*/	void DeleteCurrentRecord(char* strSource);
};

#pragma warning(disable:4146)


#endif // ndef __ADORECORD__
