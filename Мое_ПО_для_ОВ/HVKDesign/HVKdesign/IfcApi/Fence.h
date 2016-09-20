// Fence.h: interface for the CFence class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _FENCE_H__
#define _FENCE_H__

#include "FenceType.h"
#include "WorldSide.h"
#include "HVkApi.h"
#include "HVKDbObject.h"

class CWorldSide;
class CRoom;
class HVKAPI CFence:public CHVKDbObject
{
public:
	CRoom* m_pRm;
	CFenceType m_FenceType;
	CWorldSide m_WorldSide;
	double m_Length, m_Height;
	double m_HeatLoss;			//потери ч/з ограждение
public:
	CFence* Copy(CFence const& op2);
	virtual CHVKDbObject* Clone();
	int Distruct();

	CFence(CRoom* pRm = NULL);
	CFence(CFence const& op2);
	virtual ~CFence();

	CFence const& operator=(CFence const &op2);
	int const& operator==(CFence const& op2);
	int const& operator!=(CFence const& op2);
	virtual int const& CmpObj(CHVKDbObject* op2);

	virtual int Open(_ConnectionPtr  ptrCon = NULL);
	virtual int Init();
	virtual CHVKDbObject* New();
	virtual int Delete();
	virtual int DeleteEx();
	virtual void* ChangeParent(void* pParent);

	int ShowInFrmView(CIfcFormView* FrmView);
	int HideInFrmView(CIfcFormView* FrmView);
	virtual int ShowInTreeView(CIfcTreeView* pTreeView , HTREEITEM Parent = TVI_ROOT);
	virtual int Save(int IsNew = FALSE);

	int CalcHeatLoss();
private:
	int CalcAdtnlHeatLoss();

};

#endif // ndef _FENCE_H__
