// DlgPb.cpp : implementation file
//

#include "stdafx.h"
#include "SmetaProject.h"
#include "DlgPb.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPb dialog


CDlgPb::CDlgPb(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPb::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPb)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgPb::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPb)
	DDX_Control(pDX, IDC_PROGRESS, m_pb);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPb, CDialog)
	//{{AFX_MSG_MAP(CDlgPb)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPb message handlers
