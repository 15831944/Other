// RoomFrmView.cpp : implementation file
//

#include "stdafx.h"
//#include "	\ add additional includes here"
#include "RoomFrmView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRoomFrmView dialog


CRoomFrmView::CRoomFrmView(CWnd* pParent /*=NULL*/)
	: CDialog(CRoomFrmView::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRoomFrmView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRoomFrmView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRoomFrmView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRoomFrmView, CDialog)
	//{{AFX_MSG_MAP(CRoomFrmView)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoomFrmView message handlers
