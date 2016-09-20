// HVKCalcObject.h: interface for the CHVKCalcObject class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _HVKCALCOBJECT_H__
#define _HVKCALCOBJECT_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HVKApi.h"

//class CHVKDbObject;
class CIfcFormView;

class HVKAPI CHVKCalcObject 
{
public:
	CHVKDbObject* m_pObj;
public:
	CHVKCalcObject();
	CHVKCalcObject(CHVKDbObject* pObj);
	virtual ~CHVKCalcObject();
	virtual int ShowInFrmView(CIfcFormView* FrmView);
	virtual int HideInFrmView(CIfcFormView* FrmView);
//	virtual int Run(CIfcFormView* FrmView);
//	virtual int UpdateDbObjData(CHVKDbObject* pDbObj){return TRUE;};
};

#endif // !defined _HVKCALCOBJECT_H__
