#if !defined(AFX_DLGPB_H__D033897D_3F4A_4E49_8A6C_13B534BD3C74__INCLUDED_)
#define AFX_DLGPB_H__D033897D_3F4A_4E49_8A6C_13B534BD3C74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPb.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPb dialog

class CDlgPb : public CDialog
{
// Construction
public:
	CDlgPb(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgPb)
	enum { IDD = IDD_DIALOGPB };
	CProgressCtrl	m_pb;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPb)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPb)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPB_H__D033897D_3F4A_4E49_8A6C_13B534BD3C74__INCLUDED_)
