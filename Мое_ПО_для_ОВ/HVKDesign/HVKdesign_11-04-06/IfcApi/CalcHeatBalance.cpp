// CalcHeatBalance.cpp: implementation of the CCalcHeatBalance class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcHeatBalance.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCalcHeatBalance::CCalcHeatBalance()
{

}

CCalcHeatBalance::CCalcHeatBalance(CRoom* pRoom)
					:CHVKCalcObject(pRoom)
{

}

CCalcHeatBalance::~CCalcHeatBalance()
{

}

int CCalcHeatBalance::ShowInFrmView(CIfcFormView* FrmView)
{
	return TRUE;	
}

int CCalcHeatBalance::HideInFrmView(CIfcFormView* FrmView)
{
	return TRUE;	
}
