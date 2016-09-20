// IfcDialog1.cpp : implementation file
//

#include "stdafx.h"
//#include "	\ add additional includes here"
#include "IfcDialog1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIfcDialog1 dialog


CIfcDialog1::CIfcDialog1(CWnd* pParent /*=NULL*/)
	: CDialog(CIfcDialog1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIfcDialog1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CIfcDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIfcDialog1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIfcDialog1, CDialog)
	//{{AFX_MSG_MAP(CIfcDialog1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIfcDialog1 message handlers
