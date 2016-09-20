// CalcHeatLoss.h: interface for the CCalcHeatLoss class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCHEATLOSS_H__F9C6A3D8_28BA_4DB8_B31B_E03AB4F0A5BA__INCLUDED_)
#define AFX_CALCHEATLOSS_H__F9C6A3D8_28BA_4DB8_B31B_E03AB4F0A5BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HVKDbObject.h"
#include "HVKCalcObject.h"

class CRoom;
class HVKAPI CCalcHeatLoss : public CHVKCalcObject  
{
private:
//	virtual int UpdateRoomData(CHVKDbObject* pDbObj){return TRUE;};
//	virtual int RunRoom(CIfcFormView* FrmView);
public:
	CCalcHeatLoss();
	CCalcHeatLoss(CRoom* pRoom);
	virtual ~CCalcHeatLoss();
	virtual int ShowInFrmView(CIfcFormView* FrmView);
	virtual int HideInFrmView(CIfcFormView* FrmView);
//	virtual int UpdateDbObjData(CHVKDbObject* pDbObj){return TRUE;};
//	virtual int Run(CIfcFormView* FrmView);
};

#endif // !defined(AFX_CALCHEATLOSS_H__F9C6A3D8_28BA_4DB8_B31B_E03AB4F0A5BA__INCLUDED_)
