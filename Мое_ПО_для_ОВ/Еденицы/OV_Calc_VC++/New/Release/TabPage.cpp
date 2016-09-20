// TabPage1.cpp : implementation file
//

#include "stdafx.h"
#include "TabCtr.h"
#include "TabPage.h"
#include < strstrea.h >

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabPage dialog


//CTabPage::CTabPage(CWnd* pParent /*=NULL*/)

CTabPage::CTabPage(CWnd* pParent /*= NULL*/,//CEdit** _pEdtArr /*= NULL*/,
				   int _nAllEdt /*= 0*/, int* _nEdtInColumn /*= 0*/,
				   int* _nInEd /*= 0*/, int _nEd/*= 0*/,
				   double ** _Koeficient /*= NULL*/, double** _Pristavka /*= NULL*/): 
				   CDialog(CTabPage::IDD, pParent), nAllEdt(_nAllEdt), nEd(_nEd)
{
	//{{AFX_DATA_INIT(CTabPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	pEdtArr = NULL;
	pStatic=NULL;

	nInEd=_nInEd;
	nEdtInColumn=_nEdtInColumn;
	Koeficient = _Koeficient;
	Pristavka = _Pristavka;

}


void CTabPage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTabPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	
	//CreateEdits();
}

void CTabPage::CreateEdits(char** StaticText /*= NULL*/)
{
	pEdtArr=new CMyEdit**[nAllEdt];
	pStatic=new CStatic*[nAllEdt];
	
	for(int i=0,column=0,row=0;i<nEd;i++)
	{		
		pEdtArr[i]=new CMyEdit*[nInEd[i+1]-nInEd[i]];
		for(int j=0;j<(nInEd[i+1]-nInEd[i]);j++,row++)
		{
			if(row>=nEdtInColumn[column])
			{
				column++;
				row=0;
			}
			pEdtArr[i][j]=new CMyEdit;
			pEdtArr[i][j]->CreateEx(WS_EX_CLIENTEDGE, // Make a client edge label.
				_T("EDIT"), "", WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL, 
				20+190*column, (row*3+1)*20, 90, 27,m_hWnd, (HMENU)1234);
/*			pEdtArr[i][j]->Create
			(WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_VISIBLE|WS_EX_CLIENTEDGE,
			CRect(20+190*column, (row*3+1)*20, 20+190*column+90, (row*3+1)*20+27), this, 1234);
*/
			pEdtArr[i][j]->SetFont(GetFont());



			int k=nInEd[i]+j;
			pStatic[k]=new CStatic;
			pStatic[k]->CreateEx(NULL, 
				_T("STATIC"), StaticText[k], WS_CHILD | WS_VISIBLE,
				120+190*column, (row*3+1)*20+5, 100, 27, m_hWnd, (HMENU)1235);
			pStatic[k]->SetFont(GetFont());
			
		}
	}
}

BEGIN_MESSAGE_MAP(CTabPage, CDialog)
	//{{AFX_MSG_MAP(CTabPage)
	ON_BN_CLICKED(IDOK, OnOk)
	ON_EN_UPDATE(1234, OnUpdateEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabPage message handlers

BOOL CTabPage::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	return CDialog::DestroyWindow();
}

CTabPage::~CTabPage()
{
	for(int i=0,k=0;i<nEd;i++)
	{	for(int j=0;j<(nInEd[i+1]-nInEd[i]);j++,k++)
		{
			pEdtArr[i][j]->DestroyWindow();
			delete pEdtArr[i][j];
			pStatic[k]->DestroyWindow();
			delete pStatic[k];
		}
		delete[] pEdtArr[i];
	}
	delete[] pEdtArr;
	delete[] pStatic;
	delete[] nEdtInColumn;
	delete[] nInEd;
	
	for(i=0;i<nEd;i++)
	{	delete[] Koeficient[i];
		delete[] Pristavka[i];
	}

	delete[] Koeficient;
	delete[] Pristavka;

	DestroyWindow();
}
//////////////////////////
void CTabPage::Perevod()
//int N_ED,int *N_EDT,TEdit ***EDT_ARR,double **KOEF,int **PRISTAVKA
{
CMyEdit* pCurrEdt=(CMyEdit*)GetFocus();
int curr_i=0,curr_j=0;
double base_curr_znach;
CString CurrEdtText;
	pCurrEdt->GetWindowText(CurrEdtText);
    if (CurrEdtText!="")
    {
        for(int i=0;i<nEd;i++)
            for(int j=0;j<(nInEd[i+1]-nInEd[i]);j++)
				if(pCurrEdt==pEdtArr[i][j])
                {
					curr_i=i;
                    curr_j=j;
					break;
                }
		base_curr_znach=atof(CurrEdtText)*Pristavka[curr_i][curr_j];

        for(i=0;i<nEd;i++)
            for(int j=0;j<(nInEd[i+1]-nInEd[i]);j++)
                if (!(i==curr_i&&j==curr_j))
				{	double znach=base_curr_znach*Koeficient[curr_i][i]/Pristavka[i][j];
					char buf[100];
					ostrstream os (buf,100);
					os << znach<< ends;  
						//строка должна обязательно оканчиваться ends
	               	pEdtArr[i][j]->SetWindowText(buf);
				}
    }else
    {   for(int i=0;i<nEd;i++)
            for(int j=0;j<(nInEd[i+1]-nInEd[i]);j++)
                if (!(i==curr_i&&j==curr_j))
                    pEdtArr[i][j]->SetWindowText("");
    }
}

void CTabPage::OnOk() 
{
	// TODO: Add your control notification handler code here
//	CDialog::OnOK();
}

void CTabPage::OnCancel() 
{
	// TODO: Add extra cleanup here
	
//	CDialog::OnCancel();
}
void CTabPage::OnUpdateEdit() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
static int count=0;
	if(!count)
	{	count=1;
		Perevod();
		count=0;
	}
}
