// HVKInitDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HVKDesign.h"
#include "HVKInitDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHVKInitDlg dialog


CHVKInitDlg::CHVKInitDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHVKInitDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHVKInitDlg)
//	m_New = TRUE;
//	m_Open = FALSE;
	//}}AFX_DATA_INIT
	
}


void CHVKInitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHVKInitDlg)
//	DDX_Radio(pDX, IDC_RADIONEW, m_New);
//	DDX_Radio(pDX, IDC_RADIOOPEN, m_Open);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHVKInitDlg, CDialog)
	//{{AFX_MSG_MAP(CHVKInitDlg)
//	ON_BN_CLICKED(IDC_RADIONEW, OnRadionew)
//	ON_BN_CLICKED(IDC_RADIOOPEN, OnRadioopen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHVKInitDlg message handlers

void CHVKInitDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}
/*
void CHVKInitDlg::OnRadionew() 
{
	m_New = FALSE;
	m_Open = TRUE;
	UpdateData(FALSE);
}

void CHVKInitDlg::OnRadioopen() 
{
	m_New = TRUE;
	m_Open = FALSE;
	UpdateData(FALSE);
}
*/