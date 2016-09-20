#if !defined(AFX_RAZDELZDANIEDLG_H__402C70D3_BAF2_468D_8E8A_877E402C8624__INCLUDED_)
#define AFX_RAZDELZDANIEDLG_H__402C70D3_BAF2_468D_8E8A_877E402C8624__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// RazdelZdanieDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRazdelZdanieDlg dialog

class CRazdelZdanieDlg : public CDialog
{
// Construction
public:
	CRazdelZdanieDlg(CWnd* pParent = NULL);   // standard constructor
	int InspectData();
	void Clear();

// Dialog Data
	//{{AFX_DATA(CRazdelZdanieDlg)
	enum { IDD = IDD_RAZDELZDANIE_DIALOG };
	CString	m_K1;
	CString	m_S1;
	CString	m_S2;
	CString	m_S3;
	CString	m_S4;
	CString	m_N;
	CString	m_VA;
	CString	m_NA;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRazdelZdanieDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRazdelZdanieDlg)
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnOkBtnClicked();
	afx_msg void OnCancelBtnClicked();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RAZDELZDANIEDLG_H__402C70D3_BAF2_468D_8E8A_877E402C8624__INCLUDED_)
