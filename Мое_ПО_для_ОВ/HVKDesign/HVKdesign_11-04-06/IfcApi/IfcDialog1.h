#if !defined(AFX_IFCDIALOG1_H__FB0A3678_57E1_4130_B23D_8EAD934B88C6__INCLUDED_)
#define AFX_IFCDIALOG1_H__FB0A3678_57E1_4130_B23D_8EAD934B88C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IfcDialog1.h : header file
//
#include "Resource.h"

/////////////////////////////////////////////////////////////////////////////
// CIfcDialog1 dialog

class CIfcDialog1 : public CDialog
{
// Construction
public:
	CIfcDialog1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CIfcDialog1)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIfcDialog1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CIfcDialog1)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IFCDIALOG1_H__FB0A3678_57E1_4130_B23D_8EAD934B88C6__INCLUDED_)
