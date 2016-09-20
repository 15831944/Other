// Building.h: interface for the CBuilding class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _BUILDING_H__
#define _BUILDING_H__

#include "HVKDbObject.h"
#include "BuildingType.h"
#include "HVKVector.h"
#include "HVkApi.h"

class CBuildingType;
//class CHVKVector;
//class CHVKDbObject;
class CProject;
class HVKAPI CBuilding:public CHVKDbObject
{
private:
public:
	CProject* m_pPrj;
	CHVKVector	m_pFloorVect;	//������ ������
	CBuildingType m_BuildingType;
	int m_nFloor;				// ���-�� ������ 
	double m_qor, m_qvr;		//��������� �������� �������� ������
	//��� ����� ��� ������, �� ��� �/� ������ �����. ������
public:
	CBuilding* Copy(CBuilding const& op2);
	virtual CHVKDbObject* Clone();
	int Distruct();


	CBuilding(CProject* pPrj = NULL);
	CBuilding(CBuilding const& op2);
	virtual ~CBuilding();

	int const& operator==(CBuilding const& op2);
	int const& operator!=(CBuilding const& op2);
	CBuilding const& operator=(CBuilding const &op2);
	virtual int const& CmpObj(CHVKDbObject* op2);

	virtual int Init();
	virtual int Open(_ConnectionPtr  ptrCon = NULL);
	virtual CHVKDbObject* New();
	virtual int Delete();
	virtual int DeleteEx();
	virtual void* ChangeParent(void* pParent);

	int ShowInFrmView(CIfcFormView* FrmView);
	int HideInFrmView(CIfcFormView* FrmView);
	virtual int ShowInTreeView(CIfcTreeView* pTreeView , HTREEITEM Parent = TVI_ROOT);
	virtual int Save(int IsNew = FALSE);
//	virtual int Update();
};

#endif // ndef _BUILDING_H__
