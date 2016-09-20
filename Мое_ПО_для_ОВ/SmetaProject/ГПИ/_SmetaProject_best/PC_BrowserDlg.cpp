// PC_BrowserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DirTreeCtrl.h"
#include "SmetaProject.h"
#include "PC_BrowserDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPC_BrowserDlg dialog

CPC_BrowserDlg::CPC_BrowserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPC_BrowserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPC_BrowserDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
//	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPC_BrowserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPC_BrowserDlg)
	DDX_Control(pDX, IDC_EDITNAME, m_EdtName);
	DDX_Control(pDX, IDC_EDITPATH, m_EdtPath);
	DDX_Control(pDX, ID_BROWSETREE, m_dir);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPC_BrowserDlg, CDialog)
	//{{AFX_MSG_MAP(CPC_BrowserDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_NOTIFY(TVN_SELCHANGED, ID_BROWSETREE, OnSelchangedBrowsetree)
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_SETFOCUS, ID_BROWSETREE, OnSetfocusBrowsetree)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPC_BrowserDlg message handlers

BOOL CPC_BrowserDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
//	SetIcon(m_hIcon, TRUE);			// Set big icon
//	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_dir.Initialize();
//разворачивание текущей директории
	char str[500] = {0};
	GetCurrentDirectory(256,str);
	m_dir.SetPath(str);
	m_EdtName.SetWindowText("");
	int len = strlen(str);
	str[len]='\\';
	str[len+1]='\0';
	m_EdtPath.SetWindowText(str);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPC_BrowserDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialog::OnSysCommand(nID, lParam);
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPC_BrowserDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
//		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
/*HCURSOR CPC_BrowserDlg::OnQueryDragIcon()
{
//	return (HCURSOR) m_hIcon;
}
*/
void CPC_BrowserDlg::OnShowpath() 
{
    HTREEITEM hItem=m_dir.GetSelectedItem();

    if (hItem)
        MessageBox (m_dir.GetFullPath(hItem));
    else
        MessageBox ("No Item Selected...");
}

void CPC_BrowserDlg::OnSelchangedBrowsetree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	    HTREEITEM hItem = m_dir.GetSelectedItem();
    if (hItem)
    {	m_EdtPath.SetWindowText(m_dir.GetFullPath(hItem));
		m_EdtName.SetSel(0, -1);
		m_EdtName.SetFocus();
	}else
        MessageBox ("Выберите папку для размещения проекта...");
	*pResult = 0;
}

int CPC_BrowserDlg::Inspection()
{
	CString sN, sP;
	m_EdtName.GetWindowText(sN);
	m_EdtPath.GetWindowText(sP);
	if(sN.IsEmpty() || sP.IsEmpty())
		return 0;
	return 1;

}

void CPC_BrowserDlg::OnOK() 
{
	// TODO: Add extra validation here
	if(!Inspection()) MessageBox("Укажите размещение проекта");
	else 
	{	//CString sN, sP;
		m_EdtName.GetWindowText(sN);
		m_EdtPath.GetWindowText(sP);
		sP+=sN;
		CDialog::OnOK();
	}
}

int CPC_BrowserDlg::DoModal(CString* str)
{
	// TODO: Add your specialized code here and/or call the base class
	int rez = CDialog::DoModal();
	*str=sP;
	return rez;
}

void CPC_BrowserDlg::OnSetfocusBrowsetree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_EdtName.SetFocus();
	*pResult = 0;
}
