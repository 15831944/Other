// SmetaProject.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "SmetaProject.h"
#include "Zdanie.h"
#include "RazdelZdanie.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSmetaProjectApp

BEGIN_MESSAGE_MAP(CSmetaProjectApp, CWinApp)
	//{{AFX_MSG_MAP(CSmetaProjectApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSmetaProjectApp construction

CSmetaProjectApp::CSmetaProjectApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSmetaProjectApp object

CSmetaProjectApp theApp;
	//Статический член класса CRazdelZdanie
	CRazdelZdanieDlg* CRazdelZdanie::m_Dlg = new CRazdelZdanieDlg;
/////////////////////////////////////////////////////////////////////////////
// CSmetaProjectApp initialization

BOOL CSmetaProjectApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CZdanie z;
	m_pMainWnd = &z;
	int nResponse = z.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	delete CRazdelZdanie::m_Dlg;	//Статический член класса CRazdelZdanie
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;

}
