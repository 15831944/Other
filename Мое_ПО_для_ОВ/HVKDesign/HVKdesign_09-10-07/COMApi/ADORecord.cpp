
#include "stdafx.h"

#include "MemoryUtils.h"

//#include "HVKApi.h"
#include "ADORecord.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
//#define new DEBUG_NEW
#endif


CADORecord::CADORecord(_ConnectionPtr pConn/*=NULL*/)//:m_ptrConnection(pConn)//,m_pstrSource(NULL)
{
	OpenConnection();
	//создать объект Recordset
	CreateInstance(__uuidof(Recordset));
}

CADORecord::~CADORecord()
{
//	delete[] m_pstrSource;
//	m_pstrSource = NULL;
	;
	m_ptrConnection->Close();
	CMemoryUtils mu;
	mu.CheckMemory();

}

CADORecord* CADORecord::Copy(CADORecord const& op2)
{
//	m_pstrSource = op2.m_pstrSource;
	return this;
}

CADORecord const& CADORecord::operator=(CADORecord const &op2)
{
	if(this == &op2 || *this == op2) return *this;
	//создать объект Recordset
	CreateInstance(__uuidof(Recordset));
	return *Copy(op2);
}

int CADORecord::Open(const string& strSource)
{
_variant_t  vtEmpty (DISP_E_PARAMNOTFOUND, VT_ERROR);
_bstr_t bstrEmpty(L"");
/*
if(m_pstrSource)
	delete[] m_pstrSource;
m_pstrSource =  new char[256];//sizeof(strSource)];*/
//    strcpy(m_pstrSource, strSource.c_str());
//	m_pstrSource.reserve(strSource.size());
	m_pstrSource = strSource;
	try{
		(*this)->Open((_bstr_t)strSource.c_str(), 
			m_ptrConnection->ConnectionString,
//			L"Provider=sqloledb;Data Source=;Integrated Security='SSPI';Initial Catalog=Equipment;User Id=;Password=;",

		adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());//, m_pstrSource);
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
	{	GenerateError(e.Error(), e.Description());//, m_pstrSource);
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
	{	GenerateError(e.Error(), e.Description());//, m_pstrSource);
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
		GenerateError(e.Error(), e.Description());//, m_pstrSource);
		return;
	}
}
/*
//---------------------------------------------------------------------------
int CADORecord::Init()
{
	int stat = TRUE;
	CFloor* flr;	
	char str[256]; //переменная для комманд
	try{
		//Инициализация данными о здании
		stat = CHVKDbObject::Init();
		if(stat)
		{	int ID;
			stat = CHVKDbObject::m_ptrAdoRc->GetData("IdBuildingType", CADORecord::Integer, &ID);
			m_BuildingType.SetID(ID);
		}
		m_BuildingType.InitByID();
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("nFloor", CADORecord::Integer, &m_nFloor);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("qor", CADORecord::Double, &m_qor);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("qvr", CADORecord::Double, &m_qvr);
		//Создание списка этажей
		//Текст запроса для выборки таблицы этажей

		//CADORecord ptrAdoRc(*CHVKDbObject::m_ptrAdoRc);
		//CHVKDbObject::m_ptrAdoRc = (CADORecord*)&ptrAdoRc;
		//SaveCurADORecord();

		CADORecord* ptrAdoRc = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
		CHVKDbObject::m_ptrAdoRc = ptrAdoRc;
		sprintf(str, "select * from floor where IdBuilding=%d", m_ID);
		if(!CHVKDbObject::m_ptrAdoRc->Open(str)) stat = FALSE;
		if(!(*CHVKDbObject::m_ptrAdoRc)->BOF) 
			(*CHVKDbObject::m_ptrAdoRc)->MoveFirst();
		if((*CHVKDbObject::m_ptrAdoRc)->EndOfFile && (*CHVKDbObject::m_ptrAdoRc)->BOF)
			stat = FALSE;
		if(stat)
			do
			{
				flr = new CFloor(this);
				if(flr)
					stat = flr->Init();
				m_pFloorVect.push_back(flr);
				(*CHVKDbObject::m_ptrAdoRc)->MoveNext();
				
			}while(!(*CHVKDbObject::m_ptrAdoRc)->EndOfFile);// && stat);
		(*CHVKDbObject::m_ptrAdoRc)->Close();
		delete CHVKDbObject::m_ptrAdoRc;
//		RestorePrevADORecord();
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}

	return stat;
}*/
//---------------------------------------------------------------------------
int CADORecord::OpenConnection()
{
//  _ConnectionPtr m_ptrConn;
  _bstr_t     bstrEmpty(L"");
  try
  { //создать объект Connection
    m_ptrConnection.CreateInstance(__uuidof(Connection));
    //для SQL
    //m_ptrConn->CursorLocation=adUseServer;
    //соединение через udl файл
    m_ptrConnection->ConnectionString = _bstr_t("File Name=HVKDesign.udl");
    m_ptrConnection->Open(L"", bstrEmpty, bstrEmpty, -1);
  }catch(_com_error &e)
  { GenerateError(e.Error(), e.Description(), string(m_ptrConnection->ConnectionString));
    return FALSE;
  }
  return TRUE;
}


