#if !defined(AFX_IFCFORMVIEW_H__45B78DAD_62F4_4D01_A803_BECDC9DA4B2F__INCLUDED_)
#define AFX_IFCFORMVIEW_H__45B78DAD_62F4_4D01_A803_BECDC9DA4B2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IfcFormView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIfcFormView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include "IfcApi.h"
#include "../ComApi/ADORecord.h"
#include "IfcButton.h"
#include "IfcWnd.h"

class CIfcWnd;
class CIfcObject;
class CIfcEdit;
class CIfcComboBox;
class CIfcButton;
class CIfcTabCtrl;
class CProject;
class CBuilding;
class CFloor;
class CRoom;
class CFence;

class IFCAPI CIfcFormView : public CFormView, public CIfcWnd
{
protected:
	DECLARE_DYNCREATE(CIfcFormView)

// Form Data
public:
	//{{AFX_DATA(CIfcFormView)
//	enum { IDD = _UNKNOWN_RESOURCE_ID_ };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

public:
	CIfcTabCtrl*	m_TabArr;
  // Operations
private:
//	int ShowAirOut(void* Prm);
public:
	int SelectPrj(CProject* pPrj);
	int ShowData();
	CIfcFormView(UINT nIDTemplate = 0);
	int ShowProject(CProject* Prj);
	int HideProject(CProject* Prj);
	int ShowBuilding(CBuilding* pBld);
	int HideBuilding(CBuilding* pBld);
	int ShowFloor(CFloor* pFlr);
	int HideFloor(CFloor* pFlr);
	int ShowRoom(CRoom* pRm);
	int HideRoom(CRoom* pRm);
	int ShowRmMain(void* Prm);
	int HideRmMain(void* Prm);
	int ShowRmHB(void* Prm);
	int HideRmHB(void* Prm);
	int ShowFence(CFence* pFnc);
	int HideFence(CFence* pFnc);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIfcFormView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CIfcFormView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CIfcFormView)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IFCFORMVIEW_H__45B78DAD_62F4_4D01_A803_BECDC9DA4B2F__INCLUDED_)
