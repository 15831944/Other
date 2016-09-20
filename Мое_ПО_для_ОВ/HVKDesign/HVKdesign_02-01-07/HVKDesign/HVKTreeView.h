#if !defined(AFX_HVKTREEVIEW_H__15B160D9_3F6D_479D_97DF_4AF0B701371D__INCLUDED_)
#define AFX_HVKTREEVIEW_H__15B160D9_3F6D_479D_97DF_4AF0B701371D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HVKTreeView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMainViewTree view
#include "StdAfx.h"

class CMainViewTree : public CIfcTreeView
{
protected:
	CMainViewTree();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMainViewTree)

// Attributes
private:
public:
	CMainFrame* m_pFrame;
// Operations
public:
	CMainFrame* GetFrame(){return m_pFrame;};
	CMainDoc* GetDocument(){return (CMainDoc*)m_pDocument;}
//	CHVKDbObject* m_pObj;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainViewTree)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMainViewTree();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CMainViewTree)
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeydown(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HVKTREEVIEW_H__15B160D9_3F6D_479D_97DF_4AF0B701371D__INCLUDED_)
