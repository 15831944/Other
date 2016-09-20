// Orient.cpp: implementation of the COrient class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WorldSide.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWorldSide::CWorldSide()
{
	strcpy(m_DbName, "WorldSide");
}

CWorldSide::~CWorldSide()
{

}
int CWorldSide::Init()
{
	int stat = TRUE;
	try{
		//Инициализация данными о стороне света
		stat = CHVKDbObject::Init();
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("koef", CADORecord::Double, &m_koef);
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}
	return stat;
}

int const& CWorldSide::operator==(CWorldSide const& op2)
{
	return (*(CHVKDbObject*)this == *(CHVKDbObject*)&op2 &&
			m_koef == op2.m_koef);
}
