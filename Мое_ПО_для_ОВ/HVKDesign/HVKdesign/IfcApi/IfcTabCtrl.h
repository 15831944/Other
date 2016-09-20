#if !defined(AFX_IFCTABCTRL_H__F19AAD52_C332_4622_8610_B50141D58F3B__INCLUDED_)
#define AFX_IFCTABCTRL_H__F19AAD52_C332_4622_8610_B50141D58F3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IfcTabCtrl.h : header file
//
#include "string"
using namespace std;
/////////////////////////////////////////////////////////////////////////////
// CIfcTabCtrl window
typedef int (CIfcFormView::*TbItmFunctType)(void*);
class TbItmFunct
{
public:
	TbItmFunctType m_Fn;
	void* m_Data;
	TbItmFunct(TbItmFunctType Fn, void* Data):m_Data(Data)
	{m_Fn = Fn;};
};
class IFCAPI CIfcTabCtrlItem
{
public:
	char m_Name[256];
	TbItmFunct m_ShowFn;
	TbItmFunct m_HideFn;
	CIfcTabCtrlItem(char* Name, TbItmFunct ShowFn, TbItmFunct HideFn)
		:m_ShowFn(ShowFn), m_HideFn(HideFn)
	{
		strcpy(m_Name, Name);
	};
};

class IFCAPI CIfcTabCtrl : public CTabCtrl
{
	int m_NumPage;
	int m_CurSel;
	CIfcFormView* m_pFrmView;
// Construction
public:
	CIfcTabCtrlItem** m_ItmArr;
	CIfcTabCtrl(CIfcTabCtrlItem** ItmArr, int NumPage);
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIfcTabCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	int Show(CView* pView, HMENU nIDorHMENU);
	int Hide(CView* pView);
	int Update();
	virtual ~CIfcTabCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CIfcTabCtrl)
	afx_msg void OnSelchange(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IFCTABCTRL_H__F19AAD52_C332_4622_8610_B50141D58F3B__INCLUDED_)
