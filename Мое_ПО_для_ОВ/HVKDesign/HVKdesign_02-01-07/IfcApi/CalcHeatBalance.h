// CalcHeatBalance.h: interface for the CCalcHeatBalance class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCHEATBALANCE_H__71DDED7D_43D5_496E_AE4A_A9842DDF4D3F__INCLUDED_)
#define AFX_CALCHEATBALANCE_H__71DDED7D_43D5_496E_AE4A_A9842DDF4D3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HVKDbObject.h"
#include "HVKCalcObject.h"
#include "HVkApi.h"
#include "Room.h"


//class CRoom;
class HVKAPI CCalcHeatBalance : public CHVKCalcObject 
{
public:
	CHVKDbObject* m_pObj;
public:
	CCalcHeatBalance();
	CCalcHeatBalance(CRoom* pRoom);
	void SetObj(CHVKDbObject* pObj){m_pObj = pObj;};
	CHVKDbObject* GetObj(){return m_pObj;};
	virtual ~CCalcHeatBalance();
	virtual int ShowInFrmView(CIfcFormView* FrmView);
	virtual int HideInFrmView(CIfcFormView* FrmView);
//	virtual int UpdateDbObjData(CHVKDbObject* pDbObj){return TRUE;};
//	virtual int Run(CIfcFormView* FrmView);
};

#endif // !defined(AFX_CALCHEATBALANCE_H__71DDED7D_43D5_496E_AE4A_A9842DDF4D3F__INCLUDED_)
