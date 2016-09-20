// DustGasExcretion.cpp: implementation of the CDustGasExcretion class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DustGasExcretion.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDustGasExcretion::CDustGasExcretion()
{
	strcpy(m_DbName, "DustGasExcretion");
	m_Size = 0;
}

CDustGasExcretion::~CDustGasExcretion()
{

}

int CDustGasExcretion::Init()
{
	int stat = TRUE;
	try{
		//Инициализация данными о вредностях
		stat = CHVKDbObject::Init();
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("Size", CADORecord::Double, &m_Size);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("AirSize", CADORecord::Double, &m_LAir);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("IdDustGasExcretionType", CADORecord::Integer, &m_ExcretionType.m_ID);
		// Инициализация данными о вредностях
		m_ExcretionType.InitByID();

	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}

	return stat;
}

int const& CDustGasExcretion::operator==(CDustGasExcretion const& op2)
{
	return (*(CHVKDbObject*)this == *(CHVKDbObject*)&op2 &&
			m_ExcretionType.IdCmp(op2.m_ExcretionType) &&
			m_Size == op2.m_Size && m_LAir == op2.m_LAir);
}
