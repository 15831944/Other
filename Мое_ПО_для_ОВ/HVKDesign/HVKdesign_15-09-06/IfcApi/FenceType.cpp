// FenceType.cpp: implementation of the CFenceType class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FenceType.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFenceType::CFenceType()
{
	strcpy(m_DbName, "FenceType");
	m_TemperatureLag = 0;
	m_Length = 0;
	m_Height = 0;

}

CFenceType::~CFenceType()
{

}

int CFenceType::Init()
{
	int stat = TRUE;
	try{
		//Инициализация данными о ограждении
		stat = CHVKDbObject::Init();
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("TemperatureLag", CADORecord::Double, &m_TemperatureLag);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("Length", CADORecord::Double, &m_Length);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("Height", CADORecord::Double, &m_Height);
		if(stat)
		{	int ID;
			stat = CHVKDbObject::m_ptrAdoRc->GetData("IdFenceView", CADORecord::Integer, &ID);
			m_FenceView.SetID(ID);
		}
		m_FenceView.InitByID();
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}

	return stat;
}

int const& CFenceType::operator==(CFenceType const& op2)
{
	return (*(CHVKDbObject*)this == *(CHVKDbObject*)&op2 &&
			m_FenceView.IdCmp(op2.m_FenceView) &&
			m_TemperatureLag == op2.m_TemperatureLag &&
			m_Length == op2.m_Length && m_Height == op2.m_Height);
}
