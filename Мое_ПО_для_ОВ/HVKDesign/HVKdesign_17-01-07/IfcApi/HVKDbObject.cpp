// HVKDbObject.cpp: implementation of the CHVKDbObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HVKDbObject.h"
#include "../ComApi/ADORecord.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHVKDbObject* CHVKDbObject::Copy(CHVKDbObject const& op2)
{
	strcpy(m_Name, op2.m_Name);
	strcpy(m_NameWindow, op2.m_NameWindow);
	m_ID = op2.m_ID;
	
	return this;
}
//---------------------------------------------------------------------------
int CHVKDbObject::Distruct()
{
	delete[] m_Name;
	delete[] m_NameWindow;
	return TRUE;
}
//---------------------------------------------------------------------------
CHVKDbObject* CHVKDbObject::Clone()
{
	CHVKDbObject* pObj = new CHVKDbObject(*this);
	return pObj;
}
//---------------------------------------------------------------------------
CHVKDbObject::CHVKDbObject()
{
	m_Name = new char[256];
	m_NameWindow = new char [256];

	strcpy(m_Name, "");
	strcpy(m_NameWindow, "");
	m_ID = 1;
}
//---------------------------------------------------------------------------
CHVKDbObject::CHVKDbObject(CHVKDbObject const& op2)
{
	m_Name = new char[256];
	m_NameWindow = new char [256];
	Copy(op2);
}
//---------------------------------------------------------------------------
CHVKDbObject::~CHVKDbObject()
{
	Distruct();
}
//---------------------------------------------------------------------------
int const& CHVKDbObject::operator==(CHVKDbObject const& op2)
{
  if(!strcmp(m_Name, op2.m_Name))
		return TRUE;
  else return FALSE;
}
//---------------------------------------------------------------------------
int const& CHVKDbObject::operator!=(CHVKDbObject const& op2)
{
  return !operator==(op2);
}
//---------------------------------------------------------------------------
CHVKDbObject const& CHVKDbObject::operator=(CHVKDbObject const &op2)
{
	if(this==&op2 || *this == op2) return *this;
//	Delete();
	return *Copy(op2);
}
//---------------------------------------------------------------------------
int const& CHVKDbObject::CmpObj(CHVKDbObject* op2)
{
	return operator==(*op2);
}
//---------------------------------------------------------------------------
int CHVKDbObject::InitByID()
{
	char str[256]; //переменная для комманд
	int stat;
	try{
		CreateOpenStrID(str);
		CADORecord* ptrAdoRc_sv = CHVKDbObject::m_ptrAdoRc;
		CHVKDbObject::m_ptrAdoRc = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
		if(!CHVKDbObject::m_ptrAdoRc->Open(str)) return FALSE;
		stat = Init();
		(*CHVKDbObject::m_ptrAdoRc)->Close();
		delete CHVKDbObject::m_ptrAdoRc;
		CHVKDbObject::m_ptrAdoRc = ptrAdoRc_sv;
		return stat;
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}
}
//---------------------------------------------------------------------------
int CHVKDbObject::InitByName()
{
	char str[256]; //переменная для комманд
	int stat;
	CreateOpenStrName(str);
	CADORecord* ptrAdoRc_sv = CHVKDbObject::m_ptrAdoRc;
	CHVKDbObject::m_ptrAdoRc = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
	if(CHVKDbObject::m_ptrAdoRc->Open(str))
	{	stat = Init();
		(*CHVKDbObject::m_ptrAdoRc)->Close();
	}else stat = FALSE;
	delete CHVKDbObject::m_ptrAdoRc;
	CHVKDbObject::m_ptrAdoRc = ptrAdoRc_sv;
	return stat;
}
//---------------------------------------------------------------------------
int CHVKDbObject::Init()
{	int stat = 0;
	stat = CHVKDbObject::m_ptrAdoRc->GetData("ID", CADORecord::Integer, &m_ID);
	if(stat)
		stat = CHVKDbObject::m_ptrAdoRc->GetData("Name", CADORecord::String, m_Name);
	return stat;
}
//---------------------------------------------------------------------------
int CHVKDbObject::CreateOpenStrID(char* str)
{
	return sprintf(str, "select * from %s where id=%d", m_DbName, m_ID);
}
//---------------------------------------------------------------------------
int CHVKDbObject::CreateOpenStrName(char* str)
{
	return sprintf(str, "select * from %s where Name=\"%s\"", m_DbName, m_Name);
}
//---------------------------------------------------------------------------
int CHVKDbObject::CreateDeleteStrID(char* str)
{
	return sprintf(str, "delete * from %s where id=%d", m_DbName, m_ID);
}
//---------------------------------------------------------------------------
int CHVKDbObject::CreateDeleteStrName(char* str)
{
	return sprintf(str, "delete* from %s where Name=\"%s\"", m_DbName, m_Name);
}
//---------------------------------------------------------------------------
int CHVKDbObject::ShowInTreeView(CIfcTreeView* pTreeView , HTREEITEM Parent/*= TVI_ROOT*/)
{
	return TRUE;
}
//---------------------------------------------------------------------------
int CHVKDbObject::Save(int IsNew/* = FALSE*/)
{
	return TRUE;
}
//---------------------------------------------------------------------------
CHVKDbObject* CHVKDbObject::New()
{
	return NULL;
}
//---------------------------------------------------------------------------
int CHVKDbObject::Delete()
{
	try{
		CADORecord* pAdoRc = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
		char s[256];
		CreateDeleteStrID(s);
		pAdoRc->DeleteCurrentRecord(s);
	//	(*pAdoRc)->Close();
		delete pAdoRc;
		return TRUE;
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}
}
//---------------------------------------------------------------------------
int CHVKDbObject::DeleteEx()
{
	return Delete();
}
//---------------------------------------------------------------------------
int CHVKDbObject::SetID()
{
	try{
		CADORecord* pAdoRc = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
		char str[256];
		sprintf(str, "Select max(id) from %s ", m_DbName);
		if(!pAdoRc->Open(str)) return FALSE;
		if(!(*pAdoRc)->BOF)(*pAdoRc)->MoveFirst();
		pAdoRc->GetData(0, CADORecord::Integer, &m_ID);
		(*pAdoRc)->Close();
		delete pAdoRc;
		return ++m_ID;
		}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}
}
//---------------------------------------------------------------------------
int const& CHVKDbObject::IdCmp(CHVKDbObject const& op2)
{
	return (m_ID == op2.m_ID);
}
//---------------------------------------------------------------------------

void CHVKDbObject::Clear()
{
	strcpy(m_Name, "");
};

