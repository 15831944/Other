// HVKCalcObject.cpp: implementation of the CHVKCalcObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HVKCalcObject.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHVKCalcObject::CHVKCalcObject()
{

}

CHVKCalcObject::CHVKCalcObject(CHVKDbObject* pObj):m_pObj(pObj)
{

}

CHVKCalcObject::~CHVKCalcObject()
{

}

int CHVKCalcObject::ShowInFrmView(CIfcFormView* FrmView)
{
	return TRUE;	
}

int CHVKCalcObject::HideInFrmView(CIfcFormView* FrmView)
{
	return TRUE;	
}
