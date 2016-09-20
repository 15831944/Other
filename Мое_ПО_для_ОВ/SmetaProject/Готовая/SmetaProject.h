// SmetaProject.h : main header file for the SMETAPROJECT application
//

#if !defined(AFX_SMETAPROJECT_H__02FE6966_BAFD_41CC_8BF0_52670BA9B11D__INCLUDED_)
#define AFX_SMETAPROJECT_H__02FE6966_BAFD_41CC_8BF0_52670BA9B11D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSmetaProjectApp:
// See SmetaProject.cpp for the implementation of this class
//
//#include <stdio.h>
class CSmetaProjectApp : public CWinApp
{
public:
	CSmetaProjectApp();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSmetaProjectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSmetaProjectApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMETAPROJECT_H__02FE6966_BAFD_41CC_8BF0_52670BA9B11D__INCLUDED_)
