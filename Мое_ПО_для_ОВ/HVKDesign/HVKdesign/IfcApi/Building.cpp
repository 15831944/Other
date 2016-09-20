// Building.cpp: implementation of the CBuilding class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "../IfcApi/IfcFormView.h"
#include "../IfcApi/IfcTreeView.h"
#include "Building.h"
#include "Floor.h"
#include "Project.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CBuilding* CBuilding::Copy(CBuilding const& op2)
{
	CHVKDbObject::Copy(op2);
	m_pPrj = op2.m_pPrj;
	m_pFloorVect = op2.m_pFloorVect;
	m_pFloorVect.ChangeParent(this);
	m_BuildingType = op2.m_BuildingType;
	m_nFloor = op2.m_nFloor;
	m_qor = op2.m_qor;
	m_qvr = op2.m_qvr;
	
	return this;
}
//---------------------------------------------------------------------------
CHVKDbObject* CBuilding::Clone()
{
	CBuilding* pObj = new CBuilding(*this);
	return pObj;
}
//---------------------------------------------------------------------------
int CBuilding::Distruct()
{
	return TRUE;
}
//---------------------------------------------------------------------------
CBuilding::CBuilding(CProject* pPrj/* = NULL*/):m_pPrj(pPrj)
{
	strcpy(m_DbName, "building");
	m_nFloor = 0;
	m_qor = m_qvr = 0;
}
//---------------------------------------------------------------------------
CBuilding::CBuilding(CBuilding const& op2):CHVKDbObject()
{
	strcpy(m_DbName, "building");
    Copy(op2);
}
//---------------------------------------------------------------------------
CBuilding::~CBuilding()
{
	Distruct();
}
//---------------------------------------------------------------------------
CBuilding const& CBuilding::operator=(CBuilding const &op2)
{
	if(this == &op2 || *this == op2) return *this;
//	Delete();
	return *Copy(op2);
}
//---------------------------------------------------------------------------
int const& CBuilding::operator==(CBuilding const& op2)
{
	return (*(CHVKDbObject*)this == *(CHVKDbObject*)&op2 &&
			m_pFloorVect == op2.m_pFloorVect &&
			m_BuildingType.IdCmp(op2.m_BuildingType) &&
			m_nFloor == op2.m_nFloor &&
			m_qor == op2.m_qor && m_qvr == op2.m_qvr);
}
//---------------------------------------------------------------------------
int const& CBuilding::operator!=(CBuilding const& op2)
{
  return !operator==(op2);
}
//---------------------------------------------------------------------------
int const& CBuilding::CmpObj(CHVKDbObject* op2)
{
	return operator==(*(CBuilding*)op2);
}
//---------------------------------------------------------------------------
int CBuilding::Open(_ConnectionPtr ptrCon /*= NULL*/)
{
	return TRUE;
}
//---------------------------------------------------------------------------
int CBuilding::Init()
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
		CADORecord* ptrAdoRc_sv = CHVKDbObject::m_ptrAdoRc;
		CHVKDbObject::m_ptrAdoRc = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
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
int CBuilding::ShowInFrmView(CIfcFormView* FrmView)
{
	FrmView->ShowBuilding(this);
	return TRUE;
};
//---------------------------------------------------------------------------
int CBuilding::HideInFrmView(CIfcFormView* FrmView)
{
	FrmView->HideBuilding(this);
	return TRUE;
};
//---------------------------------------------------------------------------
int CBuilding::ShowInTreeView(CIfcTreeView* pTreeView , HTREEITEM hParent/*= TVI_ROOT*/)
{
	pTreeView->ShowVector(&m_pFloorVect, hParent);
	return TRUE;
}
//---------------------------------------------------------------------------
int CBuilding::Save(int IsNew/* = FALSE*/)
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
			ptrCmd->CommandText=L"update building set Name='";
			ptrCmd->CommandText+=(const char*)m_Name;
			ptrCmd->CommandText+=L"', IdBuildingType=";
			sprintf(str, "%d", m_BuildingType.m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", nFloor=";
			sprintf(str, "%d", m_nFloor);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", qor=";
			sprintf(str, "%f", m_qor);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", qvr=";
			sprintf(str, "%f", m_qvr);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L" where id=";
			sprintf(str, "%d", m_ID);
			ptrCmd->CommandText+=(const char*)str;
		}
		else{
			ptrCmd->CommandText=L"insert into building ";
			ptrCmd->CommandText+=L"(Name, Id, IdProject, IdBuildingType, nFloor, qor, qvr) VALUES ('";
			ptrCmd->CommandText+=(const char*)m_Name;
			ptrCmd->CommandText+=L"', ";
			sprintf(str, "%d", SetID());
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%d", m_pPrj->m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%d", m_BuildingType.m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%d", m_nFloor);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_qor);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_qvr);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L")";
			_bstr_t str = ptrCmd->CommandText;
		}
		ptrCmd->Execute(&vtEmpty, &vtEmpty, adCmdText);
		m_pFloorVect.Save(IsNew);
		return TRUE;
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}
}
//---------------------------------------------------------------------------
int CBuilding::Delete()
{
	m_pFloorVect.DeleteAll();
	return CHVKDbObject::Delete();
}
//---------------------------------------------------------------------------
int CBuilding::DeleteEx()
{
	if(m_pPrj)
		m_pPrj->m_pBuildingVect.Delete(this);
	return Delete();
}
//---------------------------------------------------------------------------
void* CBuilding::ChangeParent(void* pParent)
{
	CProject* pPrj = static_cast<CProject*>(pParent);
	if(m_pPrj)
		m_pPrj = pPrj;
	return m_pPrj;
}
//---------------------------------------------------------------------------
CHVKDbObject* CBuilding::New()
{
	CFloor* pFlr = new CFloor(this);
	pFlr->Save(TRUE);
	m_pFloorVect.push_back(pFlr);
	return pFlr;
}
//---------------------------------------------------------------------------