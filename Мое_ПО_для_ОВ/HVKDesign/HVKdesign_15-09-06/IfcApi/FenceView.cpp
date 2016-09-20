// FenceView.cpp: implementation of the CFenceView class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FenceView.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFenceView::CFenceView()
{
	strcpy(m_DbName, "FenceView");
	m_koef = 0;
}

CFenceView::~CFenceView()
{

}

int CFenceView::Init()
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

int const& CFenceView::operator==(CFenceView const& op2)
{
	return (*(CHVKDbObject*)this == *(CHVKDbObject*)&op2 &&
			m_koef == op2.m_koef);
}