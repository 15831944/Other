// ZdanieResultsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SmetaProject.h"
#include "ZdanieResultsDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZdanieResultsDlg dialog

CZdanieResultsDlg::CZdanieResultsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZdanieResultsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZdanieResultsDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	hAccel = LoadAccelerators( AfxGetResourceHandle(),
		MAKEINTRESOURCE(IDR_ACCELERATOR));
	IsChangeProject = 0;
}

void CZdanieResultsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZdanieResultsDlg)
	DDX_Control(pDX, ID_EXIT, m_btnExit);
	DDX_Control(pDX, ID_CALCULATE, m_btnCalculate);
	DDX_Control(pDX, ID_ZDANIE, m_btnZdanie);
	DDX_Control(pDX, ID_WORD, m_btnWord);
	DDX_Control(pDX, ID_EDITRAZDEL, m_btnEditRazdel);
	DDX_Control(pDX, ID_DELETERAZDEL, m_btnDeleteRazdel);
	DDX_Control(pDX, ID_ADDRAZDEL, m_btnAddRazdel);
	DDX_Control(pDX, ID_HELP, m_btnHelp);
	DDX_Control(pDX, ID_PASTE, m_btnPaste);
	DDX_Control(pDX, ID_COPY, m_btnCopy);
	DDX_Control(pDX, ID_OPEN, m_btnOpen);
	DDX_Control(pDX, ID_NEW, m_btnNew);
	DDX_Control(pDX, ID_CUT, m_btnCut);
	DDX_Control(pDX, ID_SAVE, m_btnSave);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CZdanieResultsDlg, CDialog)
	//{{AFX_MSG_MAP(CZdanieResultsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OK, OnOkClicked)
	ON_BN_CLICKED(IDC_CANCEL, OnCancelClicked)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	ON_WM_CREATE() // событие создания окна
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZdanieResultsDlg message handlers

BOOL CZdanieResultsDlg::OnInitDialog()
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
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	m_btnNew.SetIcon(::LoadIcon(AfxGetResourceHandle(), 
		MAKEINTRESOURCE (IDI_NEW)));
	m_btnOpen.SetIcon(::LoadIcon(AfxGetResourceHandle(), 
		MAKEINTRESOURCE (IDI_OPEN)));
	m_btnSave.SetIcon(::LoadIcon(AfxGetResourceHandle(), 
		MAKEINTRESOURCE (IDI_SAVE)));
	m_btnCut.SetIcon(::LoadIcon(AfxGetResourceHandle(), 
		MAKEINTRESOURCE (IDI_CUT)));
	m_btnCopy.SetIcon(::LoadIcon(AfxGetResourceHandle(), 
		MAKEINTRESOURCE (IDI_COPY)));
	m_btnPaste.SetIcon(::LoadIcon(AfxGetResourceHandle(), 
		MAKEINTRESOURCE (IDI_PASTE)));
	m_btnHelp.SetIcon(::LoadIcon(AfxGetResourceHandle(), 
		MAKEINTRESOURCE (IDI_HELP)));
	m_btnAddRazdel.SetIcon(::LoadIcon(AfxGetResourceHandle(), 
		MAKEINTRESOURCE (IDI_ADDRAZDEL)));
	m_btnDeleteRazdel.SetIcon(::LoadIcon(AfxGetResourceHandle(), 
		MAKEINTRESOURCE (IDI_DELETERAZDEL)));
	m_btnEditRazdel.SetIcon(::LoadIcon(AfxGetResourceHandle(), 
		MAKEINTRESOURCE (IDI_EDITRAZDEL)));
	m_btnZdanie.SetIcon(::LoadIcon(AfxGetResourceHandle(), 
		MAKEINTRESOURCE (IDI_ZDANIE)));
	m_btnCalculate.SetIcon(::LoadIcon(AfxGetResourceHandle(), 
		MAKEINTRESOURCE (IDI_CALCULATE)));
	m_btnWord.SetIcon(::LoadIcon(AfxGetResourceHandle(), 
		MAKEINTRESOURCE (IDI_WORD)));
	m_btnExit.SetIcon(::LoadIcon(AfxGetResourceHandle(), 
		MAKEINTRESOURCE (IDI_EXIT)));
	m_Menu.LoadMenu(IDC_MENU);
	SetMenu(&m_Menu);
	UpdateMenuAndToolBarItems(0, ID_CLOSE, ID_WORD);
	return TRUE;  // возвращает TRUE  до тех пор, пока Вы не установите
				// фокус на элемент управления

}

void CZdanieResultsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CZdanieResultsDlg::OnDestroy()
{
	WinHelp(0L, HELP_QUIT);
	CDialog::OnDestroy();

}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CZdanieResultsDlg::OnPaint() 
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
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{	
		CDialog::OnPaint();
	}

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CZdanieResultsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CZdanieResultsDlg::OnOK() 
{
	// TODO: Add extra validation here
	CDialog::OnOK(); 
}

void CZdanieResultsDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	CDialog::OnCancel();
}

void CZdanieResultsDlg::OnOkClicked() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK(); //чтобы окно закрывалось при нажатии на Ok
}

void CZdanieResultsDlg::OnCancelClicked() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel(); //чтобы окно закрывалось при нажатии на Cancel

}

void CZdanieResultsDlg::OnAdd() 
{
	if(TableOfRazdel.Grid.GetRow()>=TableOfRazdel.List.size())
		TableOfRazdel.Grid.SetRow(TableOfRazdel.List.size()+1);
	CRazdelZdanie* r = new CRazdelZdanie;
	if(r->GetData()) TableOfRazdel.Add(r);
	if(!IsChangeProject) IsChangeProject=1;
}
void CZdanieResultsDlg::OnReplace() 
{
	CRazdelZdanie* r;// = new CRazdelZdanie();
	int i = TableOfRazdel.Grid.GetRow()-1;
	if(TableOfRazdel.List.empty() || i>TableOfRazdel.List.size())
		return;
	r = TableOfRazdel.List[i];
	r->SetData();
	if(r->GetData()) 
		TableOfRazdel.Replace(r);
	if(!IsChangeProject)IsChangeProject=1;
}
void CZdanieResultsDlg::OnDelete()
{
	TableOfRazdel.Remove();
	if(!IsChangeProject)IsChangeProject=1;
}

BEGIN_EVENTSINK_MAP(CZdanieResultsDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CZdanieResultsDlg)
//	ON_EVENT(CZdanieResultsDlg, IDC_MSFLEXGRID, -601 /* DblClick */, OnDblClickMsflexgrid, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()


int CZdanieResultsDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}


BOOL CZdanieResultsDlg::PreTranslateMessage(MSG* pMsg) 
{
	if (TranslateAccelerator(m_hWnd, hAccel, pMsg)) return TRUE;
	if(pMsg->message==WM_KEYDOWN )
	{	int i;
		switch (pMsg->wParam)
		{	case VK_ESCAPE:
				return FALSE;
			case VK_RETURN:
				return FALSE;
			case VK_DOWN:
				i = TableOfRazdel.Grid.GetRow()+1;
				if(i <= TableOfRazdel.List.size()+1)
				{	
					TableOfRazdel.Grid.SetRow(i);
				}
				return TRUE;
			case VK_UP:
				i = TableOfRazdel.Grid.GetRow()-1;
				if(i)
				{
					TableOfRazdel.Grid.SetRow (i);
				}
				return TRUE;
			default:
				return CDialog::PreTranslateMessage(pMsg);
		}

	}else
		return CDialog::PreTranslateMessage(pMsg);
}

int CZdanieResultsDlg::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	return CDialog::DoModal();
}

void CZdanieResultsDlg::UpdateMenuAndToolBarItems(int Enabled, int begin, int end)
{
CButton* btn;
	if(!end) end = begin;
	for(int i=begin; i<=end; i++)
	{	m_Menu.EnableMenuItem(i,!Enabled);
		if(!Enabled)
		{	m_Menu.EnableMenuItem(i, MF_DISABLED | MF_GRAYED);
		}else m_Menu.EnableMenuItem(i, MF_ENABLED);
		btn=(CButton*)GetDlgItem(i);
		if(btn) btn->EnableWindow(Enabled);
	}
}

