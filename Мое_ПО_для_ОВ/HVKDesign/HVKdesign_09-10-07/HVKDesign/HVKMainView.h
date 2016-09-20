// HVKMainView.h : interface of the CMainView class
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _HVKMAINVIEW_H__
#define _HVKMAINVIEW_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../IfcApi/IfcTabCtrl.h"
#include "StdAfx.h"
class CMainView : public CIfcFormView
{
private:
public:
//	CIfcFormView m_IfcFrmView;	//унаследоваться не удалось попробую так...
protected: // create from serialization only
	CMainView();
	DECLARE_DYNCREATE(CMainView)
public:
	//{{AFX_DATA(CMainView)
	enum { IDD = IDD_HVKDESIGN_FORM };
	//}}AFX_DATA

// Attributes
public:
	CMainDoc* GetDocument();
	CMainFrame* m_pFrame;
// Operations
public:
	CMainFrame* GetFrame(){return m_pFrame;};
//	CMainDoc* GetDocument(){return (CMainDoc*)m_pDocument;}

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMainView)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HVKMainView.cpp
inline CMainDoc* CMainView::GetDocument()
   { return (CMainDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined _HVKMAINVIEW_H__
