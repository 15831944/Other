#if !defined(AFX_ZDANIEINFODLG_H__01C07F1F_ADAA_4FAC_ACA5_C9DF3E4AE54A__INCLUDED_)
#define AFX_ZDANIEINFODLG_H__01C07F1F_ADAA_4FAC_ACA5_C9DF3E4AE54A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ZdanieInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CZdanieInfoDlg dialog

class CZdanieInfoDlg : public CDialog
{
// Construction
public:
	CZdanieInfoDlg(CWnd* pParent = NULL);   // standard constructor
	int InspectData();
	void Clear();

// Dialog Data
	//{{AFX_DATA(CZdanieDlg)
	enum { IDD = IDD_ZDANIEINFO_DIALOG };
	CString	m_K1;
	CString	m_K2;
	CString	m_K3;
	CString	m_V;
	CString	m_N;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZdanieInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CZdanieInfoDlg)
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnOkBtnClicked();
	afx_msg void OnCancelBtnClicked();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZDANIEINFODLG_H__01C07F1F_ADAA_4FAC_ACA5_C9DF3E4AE54A__INCLUDED_)
