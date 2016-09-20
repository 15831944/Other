#if !defined(AFX_HVKINITDLG_H__27AC4AC2_503D_48A4_8DED_B06C46E24615__INCLUDED_)
#define AFX_HVKINITDLG_H__27AC4AC2_503D_48A4_8DED_B06C46E24615__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HVKInitDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHVKInitDlg dialog

class CHVKInitDlg : public CDialog
{
// Construction
public:
	CHVKInitDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHVKInitDlg)
	enum { IDD = IDD_DIALOG };
	int		m_New;
	int		m_Open;
	//}}AFX_DATA
//	int m_New;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHVKInitDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHVKInitDlg)
	virtual void OnOK();
	afx_msg void OnRadionew();
	afx_msg void OnRadioopen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HVKINITDLG_H__27AC4AC2_503D_48A4_8DED_B06C46E24615__INCLUDED_)
