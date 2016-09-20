#if !defined(AFX_IFCDIALOG_H__7377C777_E0DA_4334_A074_DCC4999B8ACF__INCLUDED_)
#define AFX_IFCDIALOG_H__7377C777_E0DA_4334_A074_DCC4999B8ACF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IfcDialog.h : header file
//
#include "Resource.h"
#include "IfcWnd.h"
/////////////////////////////////////////////////////////////////////////////
// CIfcDialog dialog

class IFCAPI CIfcDialog : public CDialog, public CIfcWnd
{
// Construction
public:
	CIfcDialog(CWnd* pParent = NULL, int x = 0, int y = 0, int dx = 0, int dy = 0);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CIfcDialog)
	enum { IDD = IDD_IFCDIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	int m_x, m_y, m_dx, m_dy;
	int ShowBorderStc;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIfcDialog)
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CIfcDialog)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IFCDIALOG_H__7377C777_E0DA_4334_A074_DCC4999B8ACF__INCLUDED_)
