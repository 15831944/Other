// ZdanieInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SmetaProject.h"
#include "ZdanieInfoDlg.h"
#include "MyFunctions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZdanieInfoDlg dialog

CZdanieInfoDlg::CZdanieInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZdanieInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZdanieInfoDlg)
	m_K1 = _T("1");
	m_K2 = _T("1");
	m_K3 = _T("1");
	m_V = _T("");
	m_N = _T("");
	//}}AFX_DATA_INIT
}


void CZdanieInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZdanieInfoDlg)
	DDX_Text(pDX, IDC_EDITK1, m_K1);
	DDX_Text(pDX, IDC_EDITK2, m_K2);
	DDX_Text(pDX, IDC_EDITK3, m_K3);
	DDX_Text(pDX, IDC_EDITV, m_V);
	DDX_Text(pDX, IDC_EDITN, m_N);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CZdanieInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CZdanieInfoDlg)
	ON_BN_CLICKED(IDC_OK, OnOkBtnClicked)
	ON_BN_CLICKED(IDC_CANCEL, OnCancelBtnClicked)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZdanieInfoDlg message handlers
void CZdanieInfoDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
//	CDialog::OnCancel();
}

void CZdanieInfoDlg::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CZdanieInfoDlg::OnOkBtnClicked() 
{
	// TODO: Add your control notification handler code here
	if(InspectData()) CDialog::OnOK();
}

void CZdanieInfoDlg::OnCancelBtnClicked() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
int CZdanieInfoDlg::InspectData()
{
	UpdateData(TRUE);
	if(	IsNumber((LPCTSTR)m_K1) && IsNumber((LPCTSTR)m_K2) && 
		IsNumber((LPCTSTR)m_K3) && IsNumber((LPCTSTR)m_V) &&
		m_N!=""
	   )
		return 1;
	MessageBox("Данные введены неверно");
	return 0;

}
void CZdanieInfoDlg::Clear()
{
	m_K1 = "1";
	m_K2 = "1";
	m_K3 = "1";
	m_V = "";
	m_N = "";
}