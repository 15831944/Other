// Floor.h: interface for the CFloor class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _FLOOR_H__
#define _FLOOR_H__

#include "HVkApi.h"
#include "HVKDbObject.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HVKDbObject.h"
#include "Building.h"

class CHVKDbObject;

class CFloor:public CHVKDbObject
{
public:
	CBuilding* m_pBld;
	CHVKVector	m_pRoomVect;	//список комнат
	double m_Height;			//высота этажа
public:
	CFloor* Copy(CFloor const& op2);
	virtual CHVKDbObject* Clone();
	int Distruct();

	CFloor(CBuilding* pBld = NULL);
	CFloor(CFloor const& op2);
	virtual ~CFloor();
	
	CFloor const& operator=(CFloor const &op2);
	int const& operator==(CFloor const& op2);
	int const& operator!=(CFloor const& op2);
	virtual int const& CmpObj(CHVKDbObject* op2);

	virtual int Open(_ConnectionPtr  ptrCon = NULL);
	virtual int Init();
	virtual CHVKDbObject* New();
	virtual int Save(int IsNew = FALSE);
//	virtual int Update();
	virtual int Delete();
	virtual int DeleteEx();
	virtual void* ChangeParent(void* pParent);

	virtual int ShowInTreeView(CIfcTreeView* pTreeView , HTREEITEM Parent = TVI_ROOT);
	int ShowInFrmView(CIfcFormView* FrmView);
	int HideInFrmView(CIfcFormView* FrmView);
};

#endif // ndef _FLOOR_H__
