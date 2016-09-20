#if !defined(AFX_TABPAGE1_H__10E6BB71_7821_4781_A02B_1DC800FC16DD__INCLUDED_)
#define AFX_TABPAGE1_H__10E6BB71_7821_4781_A02B_1DC800FC16DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyEdit.h"
// TabPage1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTabPage dialog

class CTabPage : public CDialog
{
private:
	CMyEdit*** pEdtArr;	//2D массив Edit'ов
	CStatic** pStatic;	//массив надписей к Edit'ам  
	int nAllEdt;		//кол-во Edit'ов на форме
	int* nEdtInColumn;	//кол-во Edit'ов в столбцах
	int* nInEd;			//кол-во эл-тов в каждой еденице
	int nEd;			//кол-во едениц измерения на форме	

	double **Koeficient;//массив коэф-тов перевода из текущей величины во все другие
	double **Pristavka;	//массив приставок
	
	void Perevod();		//ф-я перевода из введенного числа во все еденицы

// Construction
public:
	CTabPage(CWnd* pParent = NULL,		// standard constructor
			 int _nAllEdt = 0, int* _nEdtInColumn = NULL,
			 int* _nInEd = NULL,int _nEd = 0,
			 double ** _Koeficient = NULL, double** _Pristavka = NULL);
	~CTabPage();
	void CreateEdits(char** StaticText = NULL);
	afx_msg void OnUpdateEdit();
// Dialog Data
	//{{AFX_DATA(CTabPage)
	enum { IDD = IDD_TABPAGE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabPage)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTabPage)
	afx_msg void OnOk();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABPAGE1_H__10E6BB71_7821_4781_A02B_1DC800FC16DD__INCLUDED_)
