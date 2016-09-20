// RazdelZdanieDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SmetaProject.h"
#include "RazdelZdanieDlg.h"
#include "MyFunctions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRazdelZdanieDlg dialog

CRazdelZdanieDlg::CRazdelZdanieDlg(CWnd* pParent /*=NULL*/)
		: CDialog(CRazdelZdanieDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRazdelZdanieDlg)
	m_K1 = _T("");
	m_S1 = _T("");
	m_S3 = _T("");
	m_S2 = _T("");
	m_S4 = _T("");
	m_NA = _T("");
	m_VA = _T("");
	m_N = _T("");
	//}}AFX_DATA_INIT
}


void CRazdelZdanieDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRazdelDlg)
	DDX_Text(pDX, IDC_EDITK1, m_K1);
	DDX_Text(pDX, IDC_EDITS1, m_S1);
	DDX_Text(pDX, IDC_EDITS3, m_S3);
	DDX_Text(pDX, IDC_EDITS2, m_S2);
	DDX_Text(pDX, IDC_EDITS4, m_S4);
	DDX_Text(pDX, IDC_EDITN, m_N);
	DDX_Text(pDX, IDC_EDITNA, m_NA);
	DDX_Text(pDX, IDC_EDITVA, m_VA);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRazdelZdanieDlg, CDialog)
	//{{AFX_MSG_MAP(CRazdelZdanieDlg)
	ON_BN_CLICKED(IDC_OK, OnOkBtnClicked)
	ON_BN_CLICKED(IDC_CANCEL, OnCancelBtnClicked)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRazdelZdanieDlg message handlers

void CRazdelZdanieDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
//	CDialog::OnCancel();
}

void CRazdelZdanieDlg::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CRazdelZdanieDlg::OnOkBtnClicked() 
{
	// TODO: Add your control notification handler code here
	if(InspectData()) CDialog::OnOK();
}

void CRazdelZdanieDlg::OnCancelBtnClicked() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
int CRazdelZdanieDlg::InspectData()
{
	UpdateData(TRUE);
	if(	IsNumber((LPCTSTR)m_K1) && IsNumber((LPCTSTR)m_S1) &&
		IsNumber((LPCTSTR)m_S2) && IsNumber((LPCTSTR)m_S3) && 
		IsNumber((LPCTSTR)m_S4) && IsNumber((LPCTSTR)m_VA) &&
		m_NA!="" && m_N!=""
	  )
	  return 1;
	MessageBox("Данные введены неверно");
	return 0;

}
void CRazdelZdanieDlg::Clear()
{
	m_K1 = _T("");
	m_S1 = _T("");
	m_S3 = _T("");
	m_S2 = _T("");
	m_S4 = _T("");
	m_NA = _T("");
	m_VA = _T("");
	m_N = _T("");

}
