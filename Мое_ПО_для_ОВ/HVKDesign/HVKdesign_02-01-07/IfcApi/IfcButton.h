#if !defined(AFX_IFCBUTTON_H__360EDE0B_E6F5_46BB_98F5_E8293AE6A975__INCLUDED_)
#define AFX_IFCBUTTON_H__360EDE0B_E6F5_46BB_98F5_E8293AE6A975__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IfcButton.h : header file
//
#include "IfcApi.h"
#include "IfcFormView.h"
#include "IfcObject.h"
/////////////////////////////////////////////////////////////////////////////
// CIfcButton window
typedef int (*BtnFunctType)(void*);
class BtnFunct
{
public:
	BtnFunctType m_Fn;
	void* m_Data;
	BtnFunct(BtnFunctType Fn, void* Data):m_Data(Data)
		{m_Fn = Fn;};
};

class IFCAPI CIfcButton : public CButton, public CIfcObject
{

	enum
	{
		BtnLen    = 23, 
		BtnHeight = 23
	};
	char m_Name[256];
	int m_x, m_y;
	int m_dx, m_dy;
	BtnFunct m_ClickFn;
// Construction
public:
	CIfcButton(char* Name, int x, int y, BtnFunct ClickFn, int dx = 0, int dy = 0);
	virtual int Show(CWnd* pView);
	virtual int Update(int* IsMsg = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIfcButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIfcButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CIfcButton)
	afx_msg void OnClicked();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IFCBUTTON_H__360EDE0B_E6F5_46BB_98F5_E8293AE6A975__INCLUDED_)
