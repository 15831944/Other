// DustGasExcretionType.cpp: implementation of the CDustGasExcretionType class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DustGasExcretionType.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDustGasExcretionType::CDustGasExcretionType()
{
	strcpy(m_DbName, "DustGasExcretionType");
}

CDustGasExcretionType::~CDustGasExcretionType()
{

}

int CDustGasExcretionType::Init()
{
	int stat = TRUE;
	try{
		//Инициализация данными о ограждении
		stat = CHVKDbObject::Init();
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("PDK", CADORecord::Double, &m_PDK);
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}

	return stat;
}

int const& CDustGasExcretionType::operator==(CDustGasExcretionType const& op2)
{
	return (*(CHVKDbObject*)this == *(CHVKDbObject*)&op2 &&
			m_PDK == op2.m_PDK);
}
