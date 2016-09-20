// TabCtrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TabCtr.h"
#include "TabCtrDlg.h"
#include "TabPage.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabCtrDlg dialog

CTabCtrDlg::CTabCtrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTabCtrDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTabCtrDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON);
	m_pTabDialog=0;
}

void CTabCtrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTabCtrDlg)
	DDX_Control(pDX, IDC_TAB, m_Tab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTabCtrDlg, CDialog)
	//{{AFX_MSG_MAP(CTabCtrDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, OnSelchangeTab)
	ON_BN_CLICKED(IDC_OK, OnClickedOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabCtrDlg message handlers

BOOL CTabCtrDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
//-----------------------------------------------------------------------------------
	TC_ITEM tci;   // � ��� ������������ ��������� ����������� ��������

	memset(&tci,0,sizeof(tci));
	tci.mask = TCIF_TEXT;		// � �������� ����� ������ �����

	for(int i=0;i<6;i++)
	{	tci.pszText =Name[i]; // �������� ��������
		m_Tab.InsertItem(i, &tci); 
	}
	//-----------------
	// ��������, ����� ��� ������� ����������� ������ ��������:	

	NMHDR hdr;

	hdr.code = TCN_SELCHANGE;
	hdr.hwndFrom = m_Tab.m_hWnd;

	SendMessage ( WM_NOTIFY, m_Tab.GetDlgCtrlID(), (LPARAM)&hdr );

	//-----------------
//-----------------------------------------------------------------------------------

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTabCtrDlg::OnPaint() 
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
HCURSOR CTabCtrDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTabCtrDlg::OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
//-----------------------------------------------------------------------------------
	 int id; // ID �������

	// ���� ������� ������� ���������� ������ � Tab Control'�:
	if (m_pTabDialog)
	{
		m_pTabDialog->DestroyWindow();
		delete m_pTabDialog;
	}

	//-----------------
enum{	GIGA=1000000000, MEGA=1000000, KILO=1000, MILI=1000,
		SANTI=100, LITR_FROM_M=1000,	KG_FROM_T=1000
	};

	//-----------------

	id = IDD_TABPAGE;
	// ������ � ����������� �� ����, ����� �������� �������, 
	// �������� �����. ������

// ������ ���-� Edit'�� �� �����
	int nAllEdt[6]={6,6,8,8,9,14};
// ������ ���-� �������� �� �����
	int nColumn[6]={2,2,2,2,3,4};
// ������ ���-� ������ ��������� �� �����
	int nEd[6]={2,2,2,2,3,7}; 
//	������ �������� �� ������
	char** StaticText;
// ������ ���-� Edit'�� � ������ ������� �� �����
	int* nEdtInColumn;
// ������ ���-� ��-��� � ������ ������� �� �����
	int* nInEd;
// ������ ����-��� �������� �� ������� �������� �� ��� ������
	double** Koeficient;
// M����� ���������
	double** Pristavka;
//-------------------------------//

	int SelectionTab=m_Tab.GetCurSel();
	switch (SelectionTab)
	{	case 0:
		{	//	������ �������� �� ������
			char* ST[]={"�3/�","�3/���","�3/�",
						"�/�","�/���","�/�"
						};
			StaticText = ST;
			// ������ ���-� Edit'�� � ������ ������� �� �����
			nEdtInColumn=new int[2];
			nEdtInColumn[0]=3;	nEdtInColumn[1]=3;
			// ������ ���-� ��-��� � ������ ������� �� �����
			nInEd=new int[3];
			nInEd[0]=0;	nInEd[1]=3;	nInEd[2]=6;

			// ������ ����-��� �������� �� ������� �������� �� ��� ������
			Koeficient = new double*[nEd[SelectionTab]];
			for(int i=0;i<nEd[SelectionTab];i++)
				Koeficient[i] = new double[nEd[SelectionTab]];
			Koeficient[0][0]=1;			Koeficient[0][1]=1000;
			Koeficient[1][0]=0.001;		Koeficient[1][1]=1;

			// M����� ���������
			Pristavka = new double*[2];
			for(i=0;i<2;i++)
				Pristavka[i] = new double[3];
			Pristavka[0][0]=1.0/3600;
			Pristavka[0][1]=1.0/60;
			Pristavka[0][2]=1;
				Pristavka[1][0]=1.0/3600;
				Pristavka[1][1]=1.0/60;
				Pristavka[1][2]=1;
			
			break;
		}
		case 1:
		{	char* ST[]={"��/�","��/���","��/�",
						 "�/�","�/���","�/�"
						};
			StaticText = ST;
	
			nEdtInColumn=new int[2];
			nEdtInColumn[0]=3;	nEdtInColumn[1]=3;

			nInEd=new int[3];
			nInEd[0]=0;	nInEd[1]=3;	nInEd[2]=6;
	
			Koeficient = new double*[nEd[SelectionTab]] ;
			for(int i=0;i<nEd[SelectionTab];i++)
				Koeficient[i] = new double[nEd[SelectionTab]];
			Koeficient[0][0]=1;			Koeficient[0][1]=0.001;
			Koeficient[1][0]=1000;		Koeficient[1][1]=1;

			Pristavka = new double*[2];
			for(i=0;i<2;i++)
				Pristavka[i] = new double[3];
			Pristavka[0][0]=1.0/3600;
			Pristavka[0][1]=1.0/60;
			Pristavka[0][2]=1;
				Pristavka[1][0]=1.0/3600;
				Pristavka[1][1]=1.0/60;
				Pristavka[1][2]=1;
			
			break;
		}
		case 2:
		{	char* ST[]={"���/��0�","���/��0�","���/��0�","��/��0�",
						 "����/��0�","����/��0�","����/��0�","���/��0�"
						};
			StaticText = ST;

			nEdtInColumn=new int[2];
			nEdtInColumn[0]=4;	nEdtInColumn[1]=4;

			nInEd=new int[3];
			nInEd[0]=0;	nInEd[1]=4;	nInEd[2]=8;
	
			Koeficient = new double*[nEd[SelectionTab]] ;
   			for(int i=0;i<nEd[SelectionTab];i++)
				Koeficient[i] = new double[nEd[SelectionTab]];
			Koeficient[0][0]=1;			Koeficient[0][1]=0.239;
			Koeficient[1][0]=4.187;		Koeficient[1][1]=1;

			Pristavka = new double*[2];
			for(i=0;i<2;i++)
				Pristavka[i] = new double[4];
			Pristavka[0][0]=GIGA;
			Pristavka[0][1]=MEGA;
			Pristavka[0][2]=KILO;
			Pristavka[0][3]=1;
				Pristavka[1][0]=GIGA;
				Pristavka[1][1]=MEGA;
				Pristavka[1][2]=KILO;
				Pristavka[1][3]=1;

			break;
		}
		case 3:
		{	char* ST[]={"���","���","���","��",
						"����/�","����/�","����/�","���/�"
						};
			StaticText = ST;

			nEdtInColumn=new int[2];
			nEdtInColumn[0]=4;	nEdtInColumn[1]=4;

			nInEd=new int[3];
			nInEd[0]=0;	nInEd[1]=4;	nInEd[2]=8;

			Koeficient = new double*[nEd[SelectionTab]] ;
   			for(int i=0;i<nEd[SelectionTab];i++)
				Koeficient[i] = new double[nEd[SelectionTab]];
			Koeficient[0][0]=1;           Koeficient[0][1]=860;
			Koeficient[1][0]=1.163e-3;    Koeficient[1][1]=1;
    
			Pristavka = new double*[2];
			for(i=0;i<2;i++)
				Pristavka[i] = new double[4];
			Pristavka[0][0]=GIGA;	Pristavka[1][0]=GIGA;
			Pristavka[0][1]=MEGA;	Pristavka[1][1]=MEGA;
			Pristavka[0][2]=KILO;	Pristavka[1][2]=KILO;
			Pristavka[0][3]=1;		Pristavka[1][3]=1;

			break;
		}
		case 4:
		{	char* ST[]={"���","���","���","��",
						"����","����","����","���",
						 "�.�.�"
						};
			StaticText = ST;

			nEdtInColumn=new int[3];
			nEdtInColumn[0]=4;	nEdtInColumn[1]=4;	nEdtInColumn[2]=1;

			nInEd=new int[4];
			nInEd[0]=0;	nInEd[1]=4;	nInEd[2]=8;	nInEd[3]=9;

			Koeficient = new double*[nEd[SelectionTab]] ;
			for(int i=0;i<nEd[SelectionTab];i++)
				Koeficient[i] = new double[nEd[SelectionTab]];
       		Koeficient[0][0]=1;			Koeficient[0][1]=0,239;	Koeficient[0][2]=0.341e-10;
			Koeficient[1][0]=4.187;		Koeficient[1][1]=1;		Koeficient[1][2]=0.143e-9;
			Koeficient[2][0]=2.931e10;	Koeficient[2][1]=7e9;	Koeficient[2][2]=1;
    
			Pristavka = new double*[3];
			for(i=0;i<2;i++)
				Pristavka[i] = new double[4];
			Pristavka[2] = new double;
			Pristavka[0][0]=GIGA;
			Pristavka[0][1]=MEGA;
			Pristavka[0][2]=KILO;
			Pristavka[0][3]=1;
				Pristavka[1][0]=GIGA;
				Pristavka[1][1]=MEGA;
				Pristavka[1][2]=KILO;
				Pristavka[1][3]=1;
			Pristavka[2][0]=1;
			
			break;
		}
		case 5:
		{	char* ST[]={"���","���","���","��",
						"�.���.��.","��.���.��.",
						"�.��.��.","��.��.��.",
						"���/��2","���/��2","���/�2",
						"���","���","��"
						};
			StaticText = ST;

			nEdtInColumn=new int[4];
			nEdtInColumn[0]=4;	nEdtInColumn[1]=4;
			nEdtInColumn[2]=3;	nEdtInColumn[3]=3;

			nInEd=new int[8];
			nInEd[0]=0;		nInEd[1]=4;		nInEd[2]=6;		nInEd[3]=8;	
			nInEd[4]=11;	nInEd[5]=12;	nInEd[6]=13;	nInEd[7]=14;
					
			Koeficient = new double*[nEd[SelectionTab]] ;
			for(int i=0;i<nEd[SelectionTab];i++)
				Koeficient[i] = new double[nEd[SelectionTab]];
    		Koeficient[0][0]=1;	  
			Koeficient[0][1]=0.102; 
			Koeficient[0][2]=0.008;
			Koeficient[0][3]=0.102;
			Koeficient[0][4]=1e-6;
			Koeficient[0][5]=9.869e-6;
			Koeficient[0][6]=1.020e-5;;
				Koeficient[1][0]=9.807;
    			Koeficient[1][1]=1;
      			Koeficient[1][2]=0.074;
       			Koeficient[1][3]=1;
       			Koeficient[1][4]=9.807e-6;
       			Koeficient[1][5]=9.678e-5;
       			Koeficient[1][6]=0.0001;
			Koeficient[2][0]=133.322;
			Koeficient[2][1]=13.595;
			Koeficient[2][2]=1;
			Koeficient[2][3]=13.595;
			Koeficient[2][4]=1.333e-4;
			Koeficient[2][5]=0.001;
			Koeficient[2][6]=0.001;
				Koeficient[3][0]=9.807;
				Koeficient[3][1]=1;
				Koeficient[3][2]=0.074;
				Koeficient[3][3]=1;
				Koeficient[3][4]=9.807e-6;
				Koeficient[3][5]=9.678e-5;
				Koeficient[3][6]=0.0001;
			Koeficient[4][0]=1e6;
			Koeficient[4][1]=1.02e5;
			Koeficient[4][2]=7.501e3;
			Koeficient[4][3]=1.02e5;
			Koeficient[4][4]=1;
			Koeficient[4][5]=9.869;
			Koeficient[4][6]=10.197;
				Koeficient[5][0]=1.013e5;
				Koeficient[5][1]=1.033e4;
				Koeficient[5][2]=7.6e2;
				Koeficient[5][3]=1.033e4;
				Koeficient[5][4]=1.013e-1;
				Koeficient[5][5]=1;
				Koeficient[5][6]=1.033;
			Koeficient[6][0]=9.81e4;
			Koeficient[6][1]=10000;
			Koeficient[6][2]=735.561;
			Koeficient[6][3]=10000;
			Koeficient[6][4]=9.807e-2;
			Koeficient[6][5]=9.678e-1;
			Koeficient[6][6]=1;
						
			Pristavka = new double*[7];
			Pristavka[0] = new double[4];
			for(i=1;i<3;i++)
				Pristavka[i] = new double[2];
			Pristavka[3] = new double[3];
			for(i=4;i<=6;i++)
				Pristavka[i] = new double;
 			Pristavka[0][0]=GIGA;
			Pristavka[0][1]=MEGA;
			Pristavka[0][2]=KILO;
			Pristavka[0][3]=1;
				Pristavka[1][0]=MILI;
				Pristavka[1][1]=1;
			Pristavka[2][0]=MILI;
			Pristavka[2][1]=1;
				Pristavka[3][0]=MILI*MILI;
				Pristavka[3][1]=SANTI*SANTI;
				Pristavka[3][2]=1;
			Pristavka[4][0]=1;
			Pristavka[5][0]=1;
			Pristavka[6][0]=1;
		
			break;
		}
	}//end switch

	m_pTabDialog = new CTabPage(NULL,nAllEdt[SelectionTab], nEdtInColumn,
								nInEd, nEd[SelectionTab], Koeficient, Pristavka);

	// ������� ������
	m_pTabDialog->Create (id, (CWnd*)&m_Tab);	//���������: ������ ������� � ��������
	m_pTabDialog->CreateEdits(StaticText);		//������� � ��������� Edit'� �� �����

	CRect rc; 

	m_Tab.GetWindowRect (&rc); // �������� "������� �������"
	m_Tab.ScreenToClient (&rc); // ����������� � ������������� ����������
	
	// ��������� �������, ��� ������������ �������� ��������:
	m_Tab.AdjustRect (FALSE, &rc); 

	// �������� ������ �� �����..
	m_pTabDialog->MoveWindow (&rc);

	// � ����������:
	m_pTabDialog->ShowWindow ( SW_SHOWNORMAL );
	m_pTabDialog->UpdateWindow();
	// ����� ����� ���� ����������� �� ��������� �������� ������
	m_Tab.SetFocus();

//-----------------------------------------------------------------------------------

	*pResult = 0;
}

BOOL CTabCtrDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	delete m_pTabDialog;
	return CDialog::DestroyWindow();
}

void CTabCtrDlg::OnOK() 
{
	// TODO: Add extra validation here
//	CDialog::OnOK();
}

void CTabCtrDlg::OnClickedOk() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}

void CTabCtrDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	CDialog::OnCancel();
}
