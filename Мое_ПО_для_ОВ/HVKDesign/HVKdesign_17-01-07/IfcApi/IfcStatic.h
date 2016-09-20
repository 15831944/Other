#if !defined(AFX_IFCSTATIC_H__2FA6F14B_10BA_4F6E_99A4_1F21F82996CA__INCLUDED_)
#define AFX_IFCSTATIC_H__2FA6F14B_10BA_4F6E_99A4_1F21F82996CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IfcStatic.h : header file
//
#include "IfcApi.h"
#include "IfcObject.h"

/////////////////////////////////////////////////////////////////////////////
// CIfcStatic window

class IFCAPI CIfcStatic : public CStatic, public CIfcObject
{
// Construction
public:
	CIfcStatic(char* Capt, int x , int y, int dx = 0, int dy = 0, DWORD Style = NULL);
	// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIfcStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIfcStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CIfcStatic)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IFCSTATIC_H__2FA6F14B_10BA_4F6E_99A4_1F21F82996CA__INCLUDED_)
