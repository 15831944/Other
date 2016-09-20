
#include "stdafx.h"

//#include "HVKApi.h"
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
//			L"Provider=sqloledb;Data Source=;Integrated Security='SSPI';Initial Catalog=Equipment;User Id=;Password=;",

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
		{	if(Type == Integer)
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
	{	GenerateError(e.Error(), e.Description());
		return FALSE;
	}
	return TRUE;
}

int CADORecord::GetData(const char* NameFld, int Type, void* Data)
{
	try{
		if(Data == NULL) return FALSE;
		if((*this)->Fields->Item[NameFld]->ActualSize > 0)
		{	if(Type == Integer)
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
	{	GenerateError(e.Error(), e.Description());
		return FALSE;
	}

	return TRUE;
}
int CADORecord::New()
{
	return TRUE;
}
int CADORecord::Update()
{
	return TRUE;
}

/*
void CADORecord::Find(CString str)
{
	try{
		(*this)->MoveFirst();
		(*this)->Find((_bstr_t)str,//критерий поиска
			0, //с какого смещения от текущей позиции начинать поиск
			adSearchForward);  //направление поиска вперед (adSearchBackward-назад)
	}	//были ошибки???	
	catch(_com_error &e)
	{
		//отобразить ошибку
		GenerateError(e.Error(), e.Description());
		return ;
	}
}

void CADORecord::ShowAllItemInListCtrl(CListCtrl* pListCtrl, int level)
{
CString s[MaxNumBaseFld];
	CRect Rect;
	pListCtrl->GetClientRect(&Rect);
	for(int j=0;j<level;j++)
		pListCtrl->InsertColumn(j, FieldsName[j], LVCFMT_LEFT, Rect.right/level);
	try{
		if(!(*this)->BOF) (*this)->MoveFirst();
		if((*this)->EndOfFile &&
			(*this)->BOF)
				return;
		int i=0;
		do
		{	
			GetDataStrings(s);
			pListCtrl->InsertItem(i,s[0]);
			for(j=1; j<level;j++)
				pListCtrl->SetItemText(i,j,s[j]);
			i++;
			(*this)->MoveNext();
		}while(!(*this)->EndOfFile);
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return ;
	}
}

void CADORecord::ShowAllItemInTreeCtrl(CTreeCtrl* pTreeCtrl, int level)
{

}

void CADORecord::ShowSelectedItemInView(CStatic* m_stcText, CEdit* m_edtText, int level)
{
CString s[MaxNumBaseFld];
	try{
		GetDataStrings(s);
		for(int i=0;i<level;i++)
		{	m_stcText[i].SetWindowText(FieldsName[i]);
			m_edtText[i].SetWindowText(s[i]);
		}
	}	//были ошибки???
	catch(_com_error &e)
	{
		//отобразить ошибку
		GenerateError(e.Error(), e.Description());
		return ;
	}
}
void CADORecord::GetDataStrings(CString* str)
{
	for (int i=0; i<NumberOfBaseFields;i++)
		if((*this)->Fields->Item[(long)i]->ActualSize > 0)
		{	str[i]=(char*)(_bstr_t)(*this)->Fields->Item[(long)i]->Value;
			str[i].TrimRight(' ');
		}
		else str[i]="";
}
*/
void CADORecord::DeleteCurrentRecord(char* strSource)
{
_variant_t  vtEmpty (DISP_E_PARAMNOTFOUND, VT_ERROR);
_CommandPtr ptrCmd;
	try{
		ptrCmd.CreateInstance(__uuidof(Command));
		ptrCmd->ActiveConnection = m_ptrConnection;
		ptrCmd->CommandText=(_bstr_t)strSource;
		ptrCmd->Execute(&vtEmpty, &vtEmpty, adCmdText);
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return;
	}
}

