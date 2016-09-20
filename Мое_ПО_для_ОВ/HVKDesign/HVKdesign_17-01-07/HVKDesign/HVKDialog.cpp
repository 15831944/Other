// HVKDialog.cpp : implementation file
//

#include "stdafx.h"
#include "HVKDesign.h"
#include "HVKDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHVKDialog dialog


CHVKDialog::CHVKDialog(CWnd* pParent /*=NULL*/)
	: CIfcDialog(CHVKDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHVKDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHVKDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHVKDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHVKDialog, CDialog)
	//{{AFX_MSG_MAP(CHVKDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHVKDialog message handlers
