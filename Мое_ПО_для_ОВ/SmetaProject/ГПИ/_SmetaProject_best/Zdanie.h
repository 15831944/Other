#if !defined(AFX_ZDANIE_H__9F6E6962_6F89_43CB_B23E_A8971C2C87CF__INCLUDED_)
#define AFX_ZDANIE_H__9F6E6962_6F89_43CB_B23E_A8971C2C87CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Zdanie.h : header file
//
#include "ZdanieResultsDlg.h"
#include "ZdanieData.h"
#include "msword9.h"

/////////////////////////////////////////////////////////////////////////////
// CZdanie dialog

class CZdanie : public CZdanieResultsDlg,
				public CZdanieData
{
// Construction
public:
	CZdanie(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CZdanie)
//	enum { IDD = IDD_SMETAPROJECT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZdanie)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CZdanie)
	afx_msg void OnDblClickMsflexgrid();
	DECLARE_EVENTSINK_MAP()
	DECLARE_MESSAGE_MAP()

	//}}AFX_MSG
	void MenuCalculate();
	void MenuOutputToWord();
	void MenuZdanie();
	void MenuAddRazdel();
	void MenuEditRazdel();
	void MenuDeleteRazdel();
	void MenuCutRazdel();
	void MenuCopyRazdel();
	void MenuPasteRazdel();
	void MenuCut();
	void MenuCopy();
	void MenuPaste();
	void MenuNew();
	void MenuOpen();
	void MenuClose();
	void MenuSave();
	void MenuExit();
	void MenuAbout();


	void OutputHeadOfTableToWord(Table* pTable);
	void OutputRazdelToWord(Table *pTable, CRazdelZdanie* pRazdel);
	int  Close();

	void TextRead(::fstream& f);
	void TextWrite(::fstream& f);

	void BinaryRead(::fstream& f);
	void BinaryWrite(::fstream& f);

public:

	void OnOK();
	void OnCancel();

	void SetData();
	int GetData();

	void Calculate(CRazdelZdanie*);
	void CalculateAll();

	void OutputResultsToWord();

//	friend ::istream & operator>>(::istream & istrm, CZdanie& z);
//	friend ::ostream & operator<<(::ostream & ostrm, CZdanie const& z);
	void Read(::fstream& f, int binary = true){binary?BinaryRead(f):TextRead(f);};
	void Write(::fstream& f , int binary = true){binary?BinaryWrite(f):TextWrite(f);};

	void SetWindowTextProjectName();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZDANIE_H__9F6E6962_6F89_43CB_B23E_A8971C2C87CF__INCLUDED_)
