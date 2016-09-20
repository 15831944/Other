#if !defined(AFX_IFCEDIT_H__C0F8CED3_8644_4A1D_A1AC_0973C4083AD5__INCLUDED_)
#define AFX_IFCEDIT_H__C0F8CED3_8644_4A1D_A1AC_0973C4083AD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IfcEdit.h : header file
//
#include "IfcApi.h"
#include "IfcObject.h"
/////////////////////////////////////////////////////////////////////////////
// CIfcEdit window
typedef int (*EdtFunctType)(void*);
class EdtFunct
{
public:
	EdtFunctType m_Fn;
	void* m_Data;
	EdtFunct(EdtFunctType Fn, void* Data):m_Data(Data)
		{m_Fn = Fn;};
};


class IFCAPI CIfcEdit : public CEdit, public CIfcObject
{
// Construction
public:
CIfcEdit(CIfcValue* Value, int xVal, int yVal, int dxVal = 0, int dyVal = 0,
		 int xCapt = -1, int yCapt = -1, int dxCapt = 0, int dyCapt = 0, 
		 int IsReadOnly = 0/*, EdtFunct* UpdateFn = 0*/);

// Attributes
public:
	int m_IsReadOnly;
//	EdtFunct* m_UpdateFn;
// Operations
public:
	virtual int Show(CWnd* pView);
	virtual int Update(int* IsMsg = 0);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIfcEdit)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIfcEdit();

// Generated message map functions
protected:
	//{{AFX_MSG(CIfcEdit)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChange();
	afx_msg void OnKillfocus();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IFCEDIT_H__C0F8CED3_8644_4A1D_A1AC_0973C4083AD5__INCLUDED_)
