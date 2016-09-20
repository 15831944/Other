// Project.h: interface for the CProject class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _PROJECT_H__
#define _PROJECT_H__

#include "HVKDbObject.h"
#include "HVkApi.h"
#include "HVKVector.h"
#include "Building.h"
#include "Floor.h"
#include "Room.h"
#include "Fence.h"
#include "City.h"
#include "WorldSide.h"
#include "Party.h"
//#include "..\\IfcApi\\IfcFormView.h"

class CIfcTreeCtrl;
class CCity;
class CParty;
//class CHVKDbObject;
class CIfcFormView;
class HVKAPI CProject:public CHVKDbObject
{
private:
	enum
	{ MaxSizeAuthorStr = 256
	};
	CProject* m_svPrj;
public:
	CHVKVector	m_pBuildingVect;	//список зданий
	CCity*  m_pCity;
	CParty* m_pAuthorParty;
	CParty* m_pClientParty;
	char	m_Author[MaxSizeAuthorStr];
	CHVKDbObject*   m_pCurrObj;
public:
	CProject* Copy(CProject const& op2);
	virtual CHVKDbObject* Clone();
	int Distruct();

	int SetSvPrj(CProject* pPrj = NULL);
	int GetSvPrj();
	int IsNewPrj();
	int IsChangePrj();

	CProject();
	CProject(CProject const& op2);
	virtual ~CProject();

	CProject const& operator=(CProject const &op2);
	int const& operator==(CProject const& op2);
	int const& operator!=(CProject const& op2);
	virtual int const& CmpObj(CHVKDbObject* op2);

	virtual int Open();
	virtual int Init();
	virtual int Delete();

	virtual CHVKDbObject* New();
	virtual int Save(int IsNew = FALSE);
//	virtual int Update();
	int CreateNew();
	int SelectPrj(CIfcTreeView* pShowTrView);
	int SavePrj(CIfcWnd* pWnd);
	int ClosePrj(CIfcWnd* pWnd);
	char* GetAuthor(){return m_Author;};
	void SetAuthor(const char* Author){strcpy(m_Author, Author);};
	
	virtual int ShowInFrmView(CIfcFormView* FrmView);
	virtual int HideInFrmView(CIfcFormView* FrmView);

	virtual int ShowInTreeView(CIfcTreeView* pTreeView , HTREEITEM Parent = TVI_ROOT);
//	virtual int HideInTreeView(CIfcTreeView* pTreeView , HTREEITEM hParent/*= TVI_ROOT*/);

//	virtual void SetRecordset(){};
};
#endif // ndef _PROJECT_H__

