// PC_BrowserDlg.h : header file
//

#if !defined(AFX_PC_BROWSERDLG_H__F5511FFD_305A_11D2_B989_00AA00AC7921__INCLUDED_)
#define AFX_PC_BROWSERDLG_H__F5511FFD_305A_11D2_B989_00AA00AC7921__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CPC_BrowserDlg dialog
#include "DirTreeCtrl.h"

class CPC_BrowserDlg : public CDialog
{
// Construction
public:
	CPC_BrowserDlg(CWnd* pParent = NULL);	// standard constructor
	CString sN, sP;

// Dialog Data
	//{{AFX_DATA(CPC_BrowserDlg)
	enum { IDD = IDD_PC_BROWSER_DIALOG };
	CEdit	m_EdtPath;
	CEdit	m_EdtName;
	CDirTreeCtrl	m_dir;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPC_BrowserDlg)
	public:
	virtual int DoModal(CString* i);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
	int Inspection();
// Implementation
protected:
//	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPC_BrowserDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnShowpath();
	afx_msg void OnSetpath();
	afx_msg void OnSelchangedBrowsetree(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnSetfocusBrowsetree(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PC_BROWSERDLG_H__F5511FFD_305A_11D2_B989_00AA00AC7921__INCLUDED_)
