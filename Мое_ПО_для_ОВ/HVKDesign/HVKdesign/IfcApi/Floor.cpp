// Floor.cpp: implementation of the CFloor class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Floor.h"
#include "Room.h"
/*
#include "../IfcApi/IfcTreeView.h"
#include "../IfcApi/IfcFormView.h"
*/
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CFloor* CFloor::Copy(CFloor const& op2)
{
	CHVKDbObject::Copy(op2);
	m_pBld = op2.m_pBld;
	m_pRoomVect = op2.m_pRoomVect;
	m_pRoomVect.ChangeParent(this);
	m_Height = op2.m_Height;
	return this;
}
//---------------------------------------------------------------------------
CHVKDbObject* CFloor::Clone()
{
	CFloor* pObj = new CFloor(*this);
	return pObj;
}
//---------------------------------------------------------------------------
int CFloor::Distruct()
{
	return TRUE;
}
//---------------------------------------------------------------------------
CFloor::CFloor(CBuilding* pBld/* = NULL*/):m_pBld(pBld)
{
	strcpy(m_DbName, "floor");
	m_Height = 0;

}
//---------------------------------------------------------------------------
CFloor::CFloor(CFloor const& op2):CHVKDbObject()
{
	strcpy(m_DbName, "floor");
    Copy(op2);
}
//---------------------------------------------------------------------------
CFloor::~CFloor()
{
	Distruct();
}
//---------------------------------------------------------------------------
CFloor const& CFloor::operator=(CFloor const &op2)
{
	if(this == &op2 || *this == op2) return *this;
//	Delete();
	return *Copy(op2);
}
//---------------------------------------------------------------------------
int const& CFloor::operator==(CFloor const& op2)
{
	return (*(CHVKDbObject*)this == *(CHVKDbObject*)&op2 &&
			m_pRoomVect == op2.m_pRoomVect &&
			m_Height == op2.m_Height);
}
//---------------------------------------------------------------------------
int const& CFloor::operator!=(CFloor const& op2)
{
  return !operator==(op2);
}
//---------------------------------------------------------------------------
int const& CFloor::CmpObj(CHVKDbObject* op2)
{
	return operator==(*(CFloor*)op2);
}
//---------------------------------------------------------------------------
int CFloor::Open(_ConnectionPtr ptrCon /*= NULL*/)
{
	return TRUE;
}
//---------------------------------------------------------------------------
int CFloor::Init()
{
	int stat = TRUE;
	CRoom* rm;	
	char str[256]; //переменная для комманд
	try{
		//Инициализация данными об этаже
		stat = CHVKDbObject::Init();
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("Height", CADORecord::Double, &m_Height);
		//Создание списка комнат
		//Текст запроса для выборки таблицы комнат
		CADORecord* ptrAdoRc_sv = CHVKDbObject::m_ptrAdoRc;
		CHVKDbObject::m_ptrAdoRc = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
		sprintf(str, "select * from room where Idfloor=%d", m_ID);
		if(!CHVKDbObject::m_ptrAdoRc->Open(str)) stat = FALSE;
		if(!(*CHVKDbObject::m_ptrAdoRc)->BOF) 
			(*CHVKDbObject::m_ptrAdoRc)->MoveFirst();
		if((*CHVKDbObject::m_ptrAdoRc)->EndOfFile && (*CHVKDbObject::m_ptrAdoRc)->BOF)
			stat = FALSE;
		if(stat)
			do
			{
				rm = new CRoom(this);
				if(rm)
					stat = rm->Init();
				m_pRoomVect.push_back(rm);
				(*CHVKDbObject::m_ptrAdoRc)->MoveNext();
			}while(!(*CHVKDbObject::m_ptrAdoRc)->EndOfFile/* && stat*/);
		(*CHVKDbObject::m_ptrAdoRc)->Close();
		delete CHVKDbObject::m_ptrAdoRc;
		CHVKDbObject::m_ptrAdoRc = ptrAdoRc_sv;
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}

	return stat;
}
//---------------------------------------------------------------------------
int CFloor::ShowInFrmView(CIfcFormView* FrmView)
{
	FrmView->ShowFloor(this);
	return TRUE;
};
//---------------------------------------------------------------------------
int CFloor::HideInFrmView(CIfcFormView* FrmView)
{
	FrmView->HideFloor(this);
	return TRUE;
};
//---------------------------------------------------------------------------
int CFloor::ShowInTreeView(CIfcTreeView* pTreeView , HTREEITEM hParent/*= TVI_ROOT*/)
{
	pTreeView->ShowVector(&m_pRoomVect, hParent);
	return TRUE;
}
//---------------------------------------------------------------------------
int CFloor::Save(int IsNew/* = FALSE*/)
{
	try{
		_bstr_t bstrEmpty(L"");
		_variant_t  vtEmpty (DISP_E_PARAMNOTFOUND, VT_ERROR);
		//создать объект Command
		char str[256];
		_CommandPtr ptrCmd;
		ptrCmd.CreateInstance(__uuidof(Command));
		ptrCmd->ActiveConnection=CHVKDbObject::m_ptrAdoRc->m_ptrConnection;
		if(!IsNew){
			ptrCmd->CommandText=L"update floor set Name='";
			ptrCmd->CommandText+=(const char*)m_Name;
			ptrCmd->CommandText+=L"', Height=";
			sprintf(str, "%f", m_Height);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L" where id=";
			sprintf(str, "%d", m_ID);
			ptrCmd->CommandText+=(const char*)str;
		}
		else{
			ptrCmd->CommandText=L"insert into floor ";
			ptrCmd->CommandText+=L"(Name, id, IdBuilding, Height) VALUES ('";
			ptrCmd->CommandText+=(const char*)m_Name;
			ptrCmd->CommandText+=L"', ";
			sprintf(str, "%d", SetID());
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%d", m_pBld->m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_Height);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L")";
		}
		ptrCmd->Execute(&vtEmpty, &vtEmpty, adCmdText);
		m_pRoomVect.Save(IsNew);
		return TRUE;
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}
}
//---------------------------------------------------------------------------
int CFloor::Delete()
{
	m_pRoomVect.DeleteAll();
	return CHVKDbObject::Delete();
}
//---------------------------------------------------------------------------
int CFloor::DeleteEx()
{	if(m_pBld)
		m_pBld->m_pFloorVect.Delete(this);
	return Delete();
}
//---------------------------------------------------------------------------
void* CFloor::ChangeParent(void* pParent)
{
	CBuilding* pBld = static_cast<CBuilding*>(pParent);
	if(m_pBld)
		m_pBld = pBld;
	return m_pBld;
}
//---------------------------------------------------------------------------
CHVKDbObject* CFloor::New()
{
	CRoom* pRm = new CRoom(this);
	pRm->Save(TRUE);
	m_pRoomVect.push_back(pRm);
	return pRm;
}
//---------------------------------------------------------------------------

