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
	TC_ITEM tci;   // в нее записываются параметры создаваемой закладки

	memset(&tci,0,sizeof(tci));
	tci.mask = TCIF_TEXT;		// у закладки будет только текст

// Массив названий закладок
char* Name[6]={"Объемный расход","Массовый расход","Удельная теплоемкость",
			   "Удельная теплота","Количество теплоты","Давление"
				};
	for(int i=0;i<6;i++)
	{	tci.pszText =Name[i]; // название закладки
		m_Tab.InsertItem(i, &tci); 
	}
	//-----------------
	// добавить, чтобы при запуске создавалась первая закладка:	

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
	 int id; // ID диалога

	// надо сначала удалить предыдущий диалог в Tab Control'е:
	if (m_pTabDialog)
	{
		m_pTabDialog->DestroyWindow();
		delete m_pTabDialog;
	}

	//-----------------
enum{	GIGA=1000000000, MEGA=1000000, KILO=1000, MILI=1000,
		SANTI=100, LITR_FROM_M=1000,	KG_FROM_T=1000
	};

//	Массив надписей на формах
	char* StaticText0[]={"м3/ч","м3/мин","м3/с",
						 "л/ч","л/мин","л/с"
						};
	char* StaticText1[]={"кг/ч","кг/мин","кг/с",
						 "т/ч","т/мин","т/с"
						};
	char* StaticText2[]={"ГДж/кг0С","МДж/кг0С","кДж/кг0С","Дж/кг0С",
						 "Гкал/кг0С","Мкал/кг0С","ккал/кг0С","кал/кг0С"
						};
	char* StaticText3[]={"ГВт","МВт","кВт","Вт",
						 "Гкал/ч","Мкал/ч","ккал/ч","кал/ч"
						};
	char* StaticText4[]={"ГДж","МДж","кДж","Дж",
						 "Гкал","Мкал","ккал","кал",
						  "т.у.т"
						};
	char* StaticText5[]={"ГПа","МПа","кПа","Па",
						 "м.вод.ст.","мм.вод.ст.",
						 "м.рт.ст.","мм.рт.ст.",
						  "кгс/мм2","кгс/см2","кгс/м2",
						 "бар","атм","ат"
						};

	char** StaticText[]={StaticText0,StaticText1,StaticText2,
						 StaticText3,StaticText4,StaticText5
						};
// Массив кол-в Edit'ов на форме
	int nAllEdt[6]={6,6,8,8,9,14};
// Массив кол-в столбцов на форме
	int nColumn[6]={2,2,2,2,3,4};
// Массив кол-в Edit'ов в каждом столбце на форме
/*	
	int nEdtInColumn0[]={0,3,6};
	int nEdtInColumn1[]={0,3,6};
	int nEdtInColumn2[]={0,4,8};
	int nEdtInColumn3[]={0,4,8};
	int nEdtInColumn4[]={0,4,8,9};
	int nEdtInColumn5[]={0,4,8,11,14};
	int* nEdtInColumn[]={ nEdtInColumn0, nEdtInColumn1, nEdtInColumn2,
						  nEdtInColumn3, nEdtInColumn4, nEdtInColumn5
						};
*/
	int** nEdtInColumn=new int*[6];
	nEdtInColumn[0]=new int[2];
	nEdtInColumn[0][0]=3;	nEdtInColumn[0][1]=3;
	nEdtInColumn[1]=new int[2];
	nEdtInColumn[1][0]=3;	nEdtInColumn[1][1]=3;
	nEdtInColumn[2]=new int[2];
	nEdtInColumn[2][0]=4;	nEdtInColumn[2][1]=4;
	nEdtInColumn[3]=new int[2];
	nEdtInColumn[3][0]=4;	nEdtInColumn[3][1]=4;
	nEdtInColumn[4]=new int[3];
	nEdtInColumn[4][0]=4;	nEdtInColumn[4][1]=4;	nEdtInColumn[4][2]=1;
	nEdtInColumn[5]=new int[4];
	nEdtInColumn[5][0]=4;	nEdtInColumn[5][1]=4;	nEdtInColumn[5][2]=3;
	nEdtInColumn[5][3]=3;


// Массив кол-в эл-тов в каждой еденице на форме
/*	int nInEd0[]={0,3,6};
	int nInEd1[]={0,3,6};
	int nInEd2[]={0,4,8};
	int nInEd3[]={0,4,8};
	int nInEd4[]={0,4,8,9};
	int nInEd5[]={0,4,6,8,11,12,13,14};
	int* nInEd[]={nInEd0, nInEd1, nInEd2, nInEd3, nInEd4, nInEd5};
*/
	int** nInEd=new int*[6];
	
	nInEd[0]=new int[3];
	nInEd[0][0]=0;	nInEd[0][1]=3;	nInEd[0][2]=6;
	
	nInEd[1]=new int[3];
	nInEd[1][0]=0;	nInEd[1][1]=3;	nInEd[1][2]=6;
	
	nInEd[2]=new int[3];
	nInEd[2][0]=0;	nInEd[2][1]=4;	nInEd[2][2]=8;
	
	nInEd[3]=new int[3];
	nInEd[3][0]=0;	nInEd[3][1]=4;	nInEd[3][2]=8;
	
	nInEd[4]=new int[4];
	nInEd[4][0]=0;	nInEd[4][1]=4;	nInEd[4][2]=8;	nInEd[4][3]=9;

	nInEd[5]=new int[8];
	nInEd[5][0]=0;	nInEd[5][1]=4;	nInEd[5][2]=6;	nInEd[5][3]=8;	
	nInEd[5][4]=11;	nInEd[5][5]=12;	nInEd[5][6]=13;	nInEd[5][7]=14;


// Массив кол-в едениц измерения на форме
	int nEd[6]={2,2,2,2,3,7}; 

	// Массив коэф-тов перевода из текущей величины во все другие
	double ***Koeficient = new double**[6];

	Koeficient[0] = new double*[nEd[0]];
	for(int i=0;i<nEd[0];i++)
		Koeficient[0][i] = new double[nEd[0]];
    Koeficient[0][0][0]=1;			Koeficient[0][0][1]=1000;
    Koeficient[0][1][0]=0.001;		Koeficient[0][1][1]=1;

	Koeficient[1] = new double*[nEd[1]] ;
    for(i=0;i<nEd[1];i++)
		Koeficient[1][i] = new double[nEd[1]];
    Koeficient[1][0][0]=1;			Koeficient[1][0][1]=0.001;
    Koeficient[1][1][0]=1000;		Koeficient[1][1][1]=1;

	Koeficient[2] = new double*[nEd[2]] ;
   	for(i=0;i<nEd[2];i++)
		Koeficient[2][i] = new double[nEd[2]];
    Koeficient[2][0][0]=1;			Koeficient[2][0][1]=0.239;
    Koeficient[2][1][0]=4.187;		Koeficient[2][1][1]=1;

	Koeficient[3] = new double*[nEd[3]] ;
   	for(i=0;i<nEd[3];i++)
		Koeficient[3][i] = new double[nEd[3]];
    Koeficient[3][0][0]=1;           Koeficient[3][0][1]=860;
    Koeficient[3][1][0]=1.163e-3;    Koeficient[3][1][1]=1;
    
	Koeficient[4] = new double*[nEd[4]] ;
	for(i=0;i<nEd[4];i++)
	    Koeficient[4][i] = new double[nEd[4]];
       
	Koeficient[4][0][0]=1;		  Koeficient[4][0][1]=0,239; Koeficient[4][0][2]=0.341e-10;
    Koeficient[4][1][0]=4.187;	  Koeficient[4][1][1]=1;	 Koeficient[4][1][2]=0.143e-9;
    Koeficient[4][2][0]=2.931e10; Koeficient[4][2][1]=7e9;	 Koeficient[4][2][2]=1;
    
	Koeficient[5] = new double*[nEd[5]] ;
	for(i=0;i<nEd[5];i++)
	    Koeficient[5][i] = new double[nEd[5]];
    
	Koeficient[5][0][0]=1;	  
    Koeficient[5][0][1]=0.102; 
    Koeficient[5][0][2]=0.008;
    Koeficient[5][0][3]=0.102;
    Koeficient[5][0][4]=1e-6;
    Koeficient[5][0][5]=9.869e-6;
    Koeficient[5][0][6]=1.020e-5;;
	    Koeficient[5][1][0]=9.807;
    	Koeficient[5][1][1]=1;
      	Koeficient[5][1][2]=0.074;
       	Koeficient[5][1][3]=1;
       	Koeficient[5][1][4]=9.807e-6;
       	Koeficient[5][1][5]=9.678e-5;
       	Koeficient[5][1][6]=0.0001;
    Koeficient[5][2][0]=133.322;
    Koeficient[5][2][1]=13.595;
    Koeficient[5][2][2]=1;
    Koeficient[5][2][3]=13.595;
    Koeficient[5][2][4]=1.333e-4;
    Koeficient[5][2][5]=0.001;
    Koeficient[5][2][6]=0.001;
        Koeficient[5][3][0]=9.807;
        Koeficient[5][3][1]=1;
        Koeficient[5][3][2]=0.074;
        Koeficient[5][3][3]=1;
        Koeficient[5][3][4]=9.807e-6;
        Koeficient[5][3][5]=9.678e-5;
        Koeficient[5][3][6]=0.0001;
    Koeficient[5][4][0]=1e6;
    Koeficient[5][4][1]=1.02e5;
    Koeficient[5][4][2]=7.501e3;
    Koeficient[5][4][3]=1.02e5;
    Koeficient[5][4][4]=1;
    Koeficient[5][4][5]=9.869;
    Koeficient[5][4][6]=10.197;
        Koeficient[5][5][0]=1.013e5;
        Koeficient[5][5][1]=1.033e4;
        Koeficient[5][5][2]=7.6e2;
        Koeficient[5][5][3]=1.033e4;
        Koeficient[5][5][4]=1.013e-1;
        Koeficient[5][5][5]=1;
        Koeficient[5][5][6]=1.033;
    Koeficient[5][6][0]=9.81e4;
    Koeficient[5][6][1]=10000;
    Koeficient[5][6][2]=735.561;
    Koeficient[5][6][3]=10000;
    Koeficient[5][6][4]=9.807e-2;
    Koeficient[5][6][5]=9.678e-1;
    Koeficient[5][6][6]=1;
// Mассив приставок
	double *** Pristavka = new double**[6];
	
	Pristavka[2] = new double*[2];
	for(i=0;i<3;i++)
	    Pristavka[2][i] = new double[4];
	Pristavka[2][0][0]=GIGA;
    Pristavka[2][0][1]=MEGA;
    Pristavka[2][0][2]=KILO;
    Pristavka[2][0][3]=1;
        Pristavka[2][1][0]=GIGA;
        Pristavka[2][1][1]=MEGA;
        Pristavka[2][1][2]=KILO;
        Pristavka[2][1][3]=1;

	Pristavka[0] = new double*[2];
	for(i=0;i<2;i++)
	    Pristavka[0][i] = new double[3];
	Pristavka[0][0][0]=1.0/3600;
    Pristavka[0][0][1]=1.0/60;
    Pristavka[0][0][2]=1;
        Pristavka[0][1][0]=1.0/3600;
		Pristavka[0][1][1]=1.0/60;
		Pristavka[0][1][2]=1;
        
	Pristavka[1] = new double*[2];
	for(i=0;i<2;i++)
	    Pristavka[1][i] = new double[3];
	Pristavka[1][0][0]=1.0/3600;
    Pristavka[1][0][1]=1.0/60;
    Pristavka[1][0][2]=1;
        Pristavka[1][1][0]=1.0/3600;
		Pristavka[1][1][1]=1.0/60;
		Pristavka[1][1][2]=1;

	Pristavka[3] = new double*[2];
	for(i=0;i<2;i++)
	    Pristavka[3][i] = new double[4];
    Pristavka[3][0][0]=GIGA;	Pristavka[3][1][0]=GIGA;
    Pristavka[3][0][1]=MEGA;	Pristavka[3][1][1]=MEGA;
    Pristavka[3][0][2]=KILO;	Pristavka[3][1][2]=KILO;
    Pristavka[3][0][3]=1;		Pristavka[3][1][3]=1;

	Pristavka[4] = new double*[3];
	for(i=0;i<2;i++)
	    Pristavka[4][i] = new double[4];
    Pristavka[4][2] = new double;
    Pristavka[4][0][0]=GIGA;
    Pristavka[4][0][1]=MEGA;
    Pristavka[4][0][2]=KILO;
    Pristavka[4][0][3]=1;
        Pristavka[4][1][0]=GIGA;
        Pristavka[4][1][1]=MEGA;
        Pristavka[4][1][2]=KILO;
        Pristavka[4][1][3]=1;
    Pristavka[4][2][0]=1;

	Pristavka[5] = new double*[6];
	Pristavka[5][0] = new double[4];
	for(i=1;i<3;i++)
	    Pristavka[5][i] = new double[2];
    Pristavka[5][3] = new double[3];
	for(i=4;i<=6;i++)
	    Pristavka[5][i] = new double;
 	Pristavka[5][0][0]=GIGA;
    Pristavka[5][0][1]=MEGA;
    Pristavka[5][0][2]=KILO;
    Pristavka[5][0][3]=1;
        Pristavka[5][1][0]=MILI;
        Pristavka[5][1][1]=1;
    Pristavka[5][2][0]=MILI;
    Pristavka[5][2][1]=1;
        Pristavka[5][3][0]=MILI*MILI;
        Pristavka[5][3][1]=SANTI*SANTI;
        Pristavka[5][3][2]=1;
    Pristavka[5][4][0]=1;
    Pristavka[5][5][0]=1;
    Pristavka[5][6][0]=1;

	//-----------------

	id = IDD_TABPAGE;
	// теперь в зависимости от того, какая закладка выбрана, 
	// выбираем соотв. диалог

	i=m_Tab.GetCurSel();
	m_pTabDialog = new CTabPage(NULL,nAllEdt[i],nEdtInColumn[i],
								nInEd[i],nEd[i]/*,StaticText[i]*/,
								Koeficient[i], Pristavka[i]);
	// создаем диалог
	m_pTabDialog->Create (id, (CWnd*)&m_Tab);	//параметры: ресурс диалога и родитель
	m_pTabDialog->CreateEdits(StaticText[i]);	//создает и размещает Edit'ы на форме

	CRect rc; 

	m_Tab.GetWindowRect (&rc); // получаем "рабочую область"
	m_Tab.ScreenToClient (&rc); // преобразуем в относительные координаты
	
	// исключаем область, где отображаются названия закладок:
	m_Tab.AdjustRect (FALSE, &rc); 

	// помещаем диалог на место..
	m_pTabDialog->MoveWindow (&rc);

	// и показываем:
	m_pTabDialog->ShowWindow ( SW_SHOWNORMAL );
	m_pTabDialog->UpdateWindow();
	// чтобы можно было перемещатся по закладкам спомощью клавиш
	m_Tab.SetFocus();

/*	for(i=0;i<6;i++)
		for(int j=0;j<nAllEdt[i];j++)
		{	delete[] nEdtInColumn[j];
			delete[] InEd[j];
		}
	delete[] nEdtInColumn;
	delete[] InEd;
*/
//-----------------------------------------------------------------------------------
	
	*pResult = 0;
}

BOOL CTabCtrDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	m_pTabDialog->DestroyWindow();
	
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
