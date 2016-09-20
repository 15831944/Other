// TabCtrDlg.h : header file
//

#if !defined(AFX_TABCTRDLG_H__881505F4_C517_47FA_BD5F_A6F850020030__INCLUDED_)
#define AFX_TABCTRDLG_H__881505F4_C517_47FA_BD5F_A6F850020030__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "TabPage.h"
/////////////////////////////////////////////////////////////////////////////
// CTabCtrDlg dialog

class CTabCtrDlg : public CDialog
{
// Construction
public:
	CTabCtrDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTabCtrDlg)
	enum { IDD = IDD_TABCTR_DIALOG };
	CTabCtrl	m_Tab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabCtrDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CTabPage* m_pTabDialog; // <--- добавить (переменная-указатель на текущий диалог)

	// Generated message map functions
	//{{AFX_MSG(CTabCtrDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnClickedOk();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABCTRDLG_H__881505F4_C517_47FA_BD5F_A6F850020030__INCLUDED_)
