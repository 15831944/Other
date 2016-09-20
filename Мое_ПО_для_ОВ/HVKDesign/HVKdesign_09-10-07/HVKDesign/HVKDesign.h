// HVKDesign.h : main header file for the HVKDESIGN application
//

#if !defined(AFX_HVKDESIGN_H__EF4AFBBF_4CEA_4288_B872_F78A4162D640__INCLUDED_)
#define AFX_HVKDESIGN_H__EF4AFBBF_4CEA_4288_B872_F78A4162D640__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHVKDesignApp:
// See HVKDesign.cpp for the implementation of this class
//

class CHVKDesignApp : public CWinApp
{
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CHVKDesignApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHVKDesignApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHVKDesignApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HVKDESIGN_H__EF4AFBBF_4CEA_4288_B872_F78A4162D640__INCLUDED_)
