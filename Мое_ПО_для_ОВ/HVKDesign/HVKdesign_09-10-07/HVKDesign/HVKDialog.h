#if !defined(AFX_HVKDIALOG_H__FE1D356A_9B30_475A_B306_EF699AF62613__INCLUDED_)
#define AFX_HVKDIALOG_H__FE1D356A_9B30_475A_B306_EF699AF62613__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HVKDialog.h : header file
//
#include "..\iFCaPI\iFCdIALOG.H"
/////////////////////////////////////////////////////////////////////////////
// CHVKDialog dialog

class CHVKDialog : public CIfcDialog
{
// Construction
public:
	CHVKDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHVKDialog)
	enum { IDD = IDD_DIALOG };

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHVKDialog)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHVKDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HVKDIALOG_H__FE1D356A_9B30_475A_B306_EF699AF62613__INCLUDED_)
