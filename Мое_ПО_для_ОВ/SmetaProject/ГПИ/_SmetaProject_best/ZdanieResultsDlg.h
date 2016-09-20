// ZdanieResultsDlg.h : header file
//
//{{AFX_INCLUDES()
#include "msflexgrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_ZDANIERESULTSDLG_H__046499A8_9178_4E78_B66F_6649841A81A0__INCLUDED_)
#define AFX_ZDANIERESULTSDLG_H__046499A8_9178_4E78_B66F_6649841A81A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ZdanieInfoDlg.h"
#include "MyDataTable.h"
#include <afxext.h> // MFC Расширения
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
// CZdanieResultsDlg dialog

class CZdanieResultsDlg : public CDialog
{
// Construction
public:
	CZdanieResultsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CZdanieResultsDlg)
	enum { IDD = IDD_ZDANIERESULTS_DIALOG };
	CButton	m_btnExit;
	CButton	m_btnCalculate;
	CButton	m_btnZdanie;
	CButton	m_btnWord;
	CButton	m_btnEditRazdel;
	CButton	m_btnDeleteRazdel;
	CButton	m_btnAddRazdel;
	CButton	m_btnHelp;
	CButton	m_btnPaste;
	CButton	m_btnCopy;
	CButton	m_btnOpen;
	CButton	m_btnNew;
	CButton	m_btnCut;
	CButton	m_btnSave;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZdanieResultsDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
// Implementation
protected:
	HACCEL hAccel;
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CZdanieResultsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnOkClicked();
	afx_msg void OnCancelClicked();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnCalculate();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
//	afx_msg void OnUpdateCommandUi(CCmdUI*);
	DECLARE_MESSAGE_MAP()
	int IsChangeProject;	//флаг изменения проекта

public:
	void UpdateMenuAndToolBarItems(int Enabled, int begin, int end = 0);
	CZdanieInfoDlg m_Dlg;			//диалог для ввода инфы по зданию
	CMyDataTable TableOfRazdel;		//таблица с разделами
//	CStatusBar m_wndStatusBar;		// Панель состояния
//	CToolBar m_ToolBar;			// панель инструментов
	CMenu m_Menu;

	void OnAdd();
	void OnReplace();
	void OnDelete();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZDANIERESULTSDLG_H__046499A8_9178_4E78_B66F_6649841A81A0__INCLUDED_)
