// BuildingType.cpp: implementation of the CBuildingType class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BuildingType.h"
#include "../ComApi/AdoRecord.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBuildingType::CBuildingType()
{
	strcpy(m_DbName, "BuildingType");
	m_qo = m_qv = 0;
}

CBuildingType::~CBuildingType()
{

}

int CBuildingType::Init()
{
	int stat = TRUE;
	try{
		//Инициализация данными о ограждении
		stat = CHVKDbObject::Init();
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("qo", CADORecord::Double, &m_qo);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("qv", CADORecord::Double, &m_qv);
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}

	return stat;
}

int const& CBuildingType::operator==(CBuildingType const& op2)
{
	return (*(CHVKDbObject*)this == *(CHVKDbObject*)&op2 &&
			m_qo == op2.m_qo && m_qv == op2.m_qv);
}
