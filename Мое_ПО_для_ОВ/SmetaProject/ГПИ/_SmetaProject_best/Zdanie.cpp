// Zdanie.cpp : implementation file
//

#include "stdafx.h"
#include "SmetaProject.h"
#include "Zdanie.h"
#include "ZdanieResultsDlg.h"
#include "PC_BrowserDlg.h"
#include "DlgPb.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZdanie dialog


CZdanie::CZdanie(CWnd* pParent /*=NULL*/)
	: CZdanieResultsDlg(pParent)
{

	//{{AFX_DATA_INIT(CZdanie)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CZdanie::DoDataExchange(CDataExchange* pDX)
{
	CZdanieResultsDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZdanie)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_MSFLEXGRID, TableOfRazdel.Grid);
}


BEGIN_MESSAGE_MAP(CZdanie, CZdanieResultsDlg)
	//{{AFX_MSG_MAP(CZdanie)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_CALCULATE, MenuCalculate)
	ON_COMMAND(ID_WORD, MenuOutputToWord)
	ON_COMMAND(ID_ZDANIE, MenuZdanie)
	ON_COMMAND(ID_ADDRAZDEL, MenuAddRazdel)
	ON_COMMAND(ID_EDITRAZDEL, MenuEditRazdel)
	ON_COMMAND(ID_DELETERAZDEL, MenuDeleteRazdel)
	ON_COMMAND(ID_CUTRAZDEL, MenuCutRazdel)
	ON_COMMAND(ID_COPYRAZDEL, MenuCopyRazdel)
	ON_COMMAND(ID_PASTERAZDEL, MenuPasteRazdel)
	ON_COMMAND(ID_CUT, MenuCut)
	ON_COMMAND(ID_COPY, MenuCopy)
	ON_COMMAND(ID_PASTE, MenuPaste)
	ON_COMMAND(ID_NEW, MenuNew)
	ON_COMMAND(ID_OPEN, MenuOpen)
	ON_COMMAND(ID_CLOSE, MenuClose)
	ON_COMMAND(ID_SAVE, MenuSave)
	ON_COMMAND(ID_EXIT, MenuExit)
	ON_COMMAND(ID_ABOUT, MenuAbout)
	//ON_UPDATE_COMMAND_UI(ID_ZDANIE, OnUpdateZdanie)
END_MESSAGE_MAP()

BEGIN_EVENTSINK_MAP(CZdanie, CDialog)
    //{{AFX_EVENTSINK_MAP(CZdanieResultsDlg)
	ON_EVENT(CZdanie, IDC_MSFLEXGRID, -601 /* DblClick */, OnDblClickMsflexgrid, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZdanie message handlers
void CZdanie::OnOK() 
{
	// TODO: Add extra validation here
	if(!Close()) return;
	CZdanieResultsDlg::OnOK(); 
}

void CZdanie::OnCancel() 
{
	// TODO: Add extra validation here
	if(!Close()) return;
	CZdanieResultsDlg::OnCancel(); 
}

int CZdanie::GetData()
{
	if(m_Dlg.DoModal()==1)
	{
		m_Dlg.m_K1.Replace(',','.');
		KoefNaRaznNaklRash = atof(m_Dlg.m_K1);
		m_Dlg.m_K2.Replace(',','.');
		KoefPereschetOborud = atof(m_Dlg.m_K2);
		m_Dlg.m_K3.Replace(',','.');
		KoefPereschetCMR = atof(m_Dlg.m_K3);
		m_Dlg.m_V.Replace(',','.');
		SetV(atof(m_Dlg.m_V));
		SetName((LPCTSTR)m_Dlg.m_N);
		return 1;
	}
	m_Dlg.Clear();
	return 0;

}

void CZdanie::SetData()
{
	if(!Name) return;
	m_Dlg.Clear();
	if(KoefNaRaznNaklRash!=-1) m_Dlg.m_K1.Format("%1.3f", KoefNaRaznNaklRash);
	if(KoefPereschetOborud!=-1)m_Dlg.m_K2.Format("%1.3f", KoefPereschetOborud);
	if(KoefPereschetCMR!=-1) m_Dlg.m_K3.Format("%1.3f", KoefPereschetCMR);
	if(V!=-1)m_Dlg.m_V.Format("%1.3f", V);
	m_Dlg.m_N = Name;
}

void CZdanie::CalculateAll()
{
	if(TableOfRazdel.List.empty()) 
	{	MessageBox("No to calculate","Error");
		return;
	}
	const int pbbegin=0, pbend=100, 
		pbstep=100/(TableOfRazdel.List.size());
	CDlgPb* pDlg;
	pDlg = new CDlgPb();
	BOOL ret = pDlg->Create(IDD_DIALOGPB, this);
	pDlg->m_pb.SetStep(pbstep);
	pDlg->m_pb.SetPos(pbbegin);
	pDlg->ShowWindow(SW_SHOW);

	SumVsegoStstOborudov = 0;			//��������� ��������� �����������
	SumVsegoStstMontaga = 0;			//��������� ��������� �������
	SumVsegoStstSantehRabot = 0;		//��������� ��������� �������������� �����
	SumVsegoStstObshestrRabot = 0;		//��������� ��������� ���������������� �����
	SumStoimost = 0;					//��������� ����� ���������
	for(int i = 0; i<TableOfRazdel.List.size(); i++)
	{
		Calculate(TableOfRazdel.List[i]);
		SumVsegoStstOborudov += TableOfRazdel.List[i]->GetVsegoStstOborudov();
		SumVsegoStstMontaga += TableOfRazdel.List[i]->GetVsegoStstMontaga();
		SumVsegoStstSantehRabot += TableOfRazdel.List[i]->GetVsegoStstSantehRabot();
		SumVsegoStstObshestrRabot += TableOfRazdel.List[i]->GetVsegoStstObshestrRabot();
		SumStoimost += TableOfRazdel.List[i]->GetSumStoimost();			
		pDlg->m_pb.StepIt();
		Sleep(50);
	}
	delete pDlg;
}

void CZdanie::Calculate(CRazdelZdanie* Razdel)
{

	Razdel->SetVsegoStstOborudov(	  Razdel->GetAnalog().GetVsegoStstOborudov()*
									  KoefPereschetOborud*
									  V*
									  Razdel->GetKoefNaRaznV()/
									  Razdel->GetAnalog().GetV());
	Razdel->SetVsegoStstMontaga(      Razdel->GetAnalog().GetVsegoStstMontaga()*
								      KoefPereschetCMR*
								      V*
								      Razdel->GetKoefNaRaznV()/
								      Razdel->GetAnalog().GetV());
	Razdel->SetVsegoStstSantehRabot(  Razdel->GetAnalog().GetVsegoStstSantehRabot()*
									  KoefPereschetCMR*
									  V*
									  Razdel->GetKoefNaRaznV()/
									  Razdel->GetAnalog().GetV());
	Razdel->SetVsegoStstObshestrRabot(Razdel->GetAnalog().GetVsegoStstObshestrRabot()*
									  KoefPereschetCMR*
									  KoefNaRaznNaklRash*
								      V*
									  Razdel->GetKoefNaRaznV()/
									  Razdel->GetAnalog().GetV());
	Razdel->SetSumStoimost(Razdel->GetVsegoStstOborudov()	 + 
						   Razdel->GetVsegoStstMontaga()	 + 
					       Razdel->GetVsegoStstSantehRabot() + 
						   Razdel->GetVsegoStstObshestrRabot());

	Razdel->SetUdStoimost(Razdel->GetSumStoimost()/V);
}
/*
::istream & operator>>(::istream & istrm, CZdanie& z)
{
	return istrm;//>>r.Name>>r.VsegoStstOborudov>>r.VsegoStstMontaga>>
				  //r.VsegoStstSantehRabot>>r.VsegoStstObshestrRabot;
}

::ostream & operator<<(::ostream & ostrm, CZdanie const& z)
{

	ostrm<<(*(CZdanieData*)&z)<<endl;
	for(int i = 0; i<z.TableOfRazdel.List.size(); i++)
	{
		ostrm<<(*z.TableOfRazdel.List[i])<<endl;
	}
	return ostrm;
}
*/

BOOL CZdanie::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	return CZdanieResultsDlg::PreTranslateMessage(pMsg);
}

void CZdanie::BinaryRead(::fstream& f) 
{
	((CZdanieData*)this)->Read(f);
	CRazdelZdanie* r;
	while(!f.eof())
	{
		r=new CRazdelZdanie();
		r->Read(f);
		if(!f.eof()) TableOfRazdel.Add(r, true);
		else delete r;
	}
}

void CZdanie::BinaryWrite(::fstream& f)
{
	((CZdanieData*)this)->Write(f);
	for(int i = 0; i<TableOfRazdel.List.size(); i++)
	{
		TableOfRazdel.List[i]->Write(f);
	}
}

void CZdanie::TextRead(::fstream& f) 
{
	f>>(*((CZdanieData*)this));
	CRazdelZdanie* r;
	while(!f.eof())
	{
		r=new CRazdelZdanie();
		f>>(*r);
		if(!f.eof()) TableOfRazdel.Add(r, true);
		else delete r;
	}
}

void CZdanie::TextWrite(::fstream& f)
{
	f<<(*(CZdanieData*)this)<<endl;
	for(int i = 0; i<TableOfRazdel.List.size(); i++)
	{
		f<<(*TableOfRazdel.List[i])<<endl;
	}
}

//��������� ����
void CZdanie::MenuCalculate()
{
	if(Name) 
	{	CalculateAll();
		UpdateMenuAndToolBarItems(1, ID_WORD);
	}
	else MessageBox("������� ������ � ������!!!", "������");
}

void CZdanie::MenuOutputToWord()
{
	OutputResultsToWord();
}

void CZdanie::MenuZdanie()
{
	SetData();
	if(GetData()) 
	{	if(!IsChangeProject) IsChangeProject=1;
		UpdateMenuAndToolBarItems(0, ID_WORD);
	}
	if(Name && !TableOfRazdel.List.empty())
		UpdateMenuAndToolBarItems(1, ID_CALCULATE);
}

void CZdanie::MenuAddRazdel()
{
	CZdanieResultsDlg::OnAdd();
	UpdateMenuAndToolBarItems(1, ID_CLOSE, ID_PASTERAZDEL);
	if(Name && !TableOfRazdel.List.empty())
		UpdateMenuAndToolBarItems(1, ID_CALCULATE);
	if(!IsChangeProject) IsChangeProject=1;
	UpdateMenuAndToolBarItems(0, ID_WORD);
}

void CZdanie::MenuEditRazdel()
{
	CZdanieResultsDlg::OnReplace();
	UpdateMenuAndToolBarItems(0, ID_WORD);
}

void CZdanie::MenuDeleteRazdel()
{
	CZdanieResultsDlg::OnDelete();
	if(TableOfRazdel.List.empty())
	{	UpdateMenuAndToolBarItems(0, ID_CLOSE, ID_PASTE);
		UpdateMenuAndToolBarItems(0, ID_DELETERAZDEL, ID_CALCULATE);
	}
	if(!Name)
	{	UpdateMenuAndToolBarItems(0, ID_CALCULATE);
	}
	UpdateMenuAndToolBarItems(0, ID_WORD);
}

void CZdanie::MenuCutRazdel()
{
	TableOfRazdel.Cut();
	if(!IsChangeProject)IsChangeProject=1;
	if(!(Name && !TableOfRazdel.List.empty()))
		UpdateMenuAndToolBarItems(0, ID_CALCULATE);
	UpdateMenuAndToolBarItems(0, ID_WORD);
}

void CZdanie::MenuCopyRazdel()
{
	TableOfRazdel.Copy();
}

void CZdanie::MenuPasteRazdel()
{
	TableOfRazdel.Paste();
	if(!IsChangeProject)IsChangeProject=1;
	UpdateMenuAndToolBarItems(0, ID_WORD);
}

void CZdanie::MenuCut()
{
	MenuCutRazdel();
}

void CZdanie::MenuCopy()
{
	MenuCopyRazdel();
}

void CZdanie::MenuPaste()
{
	MenuPasteRazdel();
}

void CZdanie::MenuNew()
{
	if(!Close()) return;
	CPC_BrowserDlg d;
	if(d.DoModal(&ProjectPath)==IDOK)
	{	int  i = CreateDirectory(ProjectPath, NULL);
		int j=GetLastError();
		if(!i) 
		{	CString estr;
			estr.Format("�������� ��� �������\n������ ����� %d", j);
			MessageBox(estr);
			MenuNew();
			return;
		}	
		if(ProjectPath) SetCurrentDirectory(ProjectPath);
		int e=GetLastError();
		char b[255];
		GetCurrentDirectory(255,b);

		TableOfRazdel.Prepare();
		TableOfRazdel.Grid.SetFocus();
		TableOfRazdel.Grid.ShowWindow(SW_SHOW);
		UpdateMenuAndToolBarItems(1, ID_ZDANIE, ID_ADDRAZDEL);
		SetWindowTextProjectName();
	}
}

void CZdanie::MenuOpen()
{
	CFileDialog dlg(TRUE);
	CString str, name;
	str="�������� ������(data.smp)";
	str+=(TCHAR)NULL;
	str+="data.smp";
	str+=(TCHAR)NULL;
	dlg.m_ofn.lpstrFilter=str;
	dlg.m_ofn.nFilterIndex=0;
	if(dlg.DoModal()==IDOK)
	{	if(!Close()) return;
		ProjectPath = dlg.GetPathName();
		ProjectPath = ProjectPath.Mid(0,
			ProjectPath.GetLength() - dlg.GetFileName().GetLength());
		::fstream fin;
		fin.open(ProjectPath+"data.smp",ios::binary|ios::in);
		Read(fin);
		fin.close();
		TableOfRazdel.Grid.ShowWindow(SW_SHOW);
		UpdateMenuAndToolBarItems(1, ID_CLOSE, ID_DELETERAZDEL);
		UpdateMenuAndToolBarItems(1, ID_CUTRAZDEL, ID_PASTERAZDEL);
		if(!TableOfRazdel.List.empty())
			UpdateMenuAndToolBarItems(1, ID_EDITRAZDEL);
		if(Name && !TableOfRazdel.List.empty())
			UpdateMenuAndToolBarItems(1, ID_CALCULATE);
		SetWindowTextProjectName();
	}
}

void CZdanie::MenuClose()
{
	Close();

}

void CZdanie::MenuSave()
{
	if(TableOfRazdel.List.empty() && !Name) 
	{	MessageBox("������ ���������","������");
		return;
	}
	if(IsChangeProject)
	{
		::fstream fout(ProjectPath+"\\data.smp",ios::binary|ios::out);
		Write(fout);
		fout.close();
		IsChangeProject = 0;
	}
}

void CZdanie::MenuExit()
{
	CZdanie::OnOK();
}

void CZdanie::MenuAbout()
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CZdanie::OutputHeadOfTableToWord(Table* pTable)
{
//������������ ��������� �������
	COleVariant  covOpt((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	_Application app;
	Selection oSel;
	Cells oCells;
	app = pTable->GetApplication();
	oSel = app.GetSelection();
	const int ColumsWidthArr[10]={	225, 155, 43, 46, 63,
									45,  48, 50, 50, 38
								};

//�������������� ����� ��������
	Columns oColumns;
	Column oColumn;
	for(int i=0;i<10;i++)
	{
		// Set the width of each column
		oColumns = pTable->GetColumns();
		oColumn = oColumns.Item(i+1);
		oColumn.SetWidth((ColumsWidthArr[i]),0);  // 0 = wdAdjustNone
	}
//���������� � ������� �� ������ �������	
	pTable->AutoFitBehavior(0);
//������������� �����-���������, ������������ �� ������
	//�������� �������� 3�10 �����
	oSel.MoveRight(COleVariant(short(1)),
		COleVariant(short(10)), COleVariant(short(1)));
	oSel.MoveDown(COleVariant(short(5)),
		COleVariant(short(2)), COleVariant(short(1)));
	//���������� ����� ������������ ���������� �����-��������
	_ParagraphFormat oParFormat;
	oParFormat= oSel.GetParagraphFormat();
	oParFormat.SetAlignment(1);
	oCells = oSel.GetCells();
	oCells.SetVerticalAlignment (1);
	//���������� ����� ���� �����-���������
	Rows oRows;
	oRows = oSel.GetRows();
	oRows.SetHeadingFormat(9999998);
	//������� � ������ �������
	oSel.HomeKey(COleVariant(short(5)),covOpt);
//�������� ������� �� 3-� �����, ���������� �� � �������� �����
	oSel.MoveDown(COleVariant(short(5)),
		COleVariant(short(2)), COleVariant(short(1)));
	oCells = oSel.GetCells();
	oCells.Merge();
	oSel.TypeText("����������� ���������\n(����, ���, ������� � ��.)");
//������� � ��������� ������ � ������� ���� �����
	oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
	oSel.MoveDown(COleVariant(short(5)),
		COleVariant(short(2)), COleVariant(short(1)));
	oCells = oSel.GetCells();
	oCells.Merge();
	oSel.TypeText("������������ �����\n� ������");
//������� � ��������� ������ � ������� ���� �����
	oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
	oSel.MoveDown(COleVariant(short(5)),
		COleVariant(short(2)), COleVariant(short(1)));
	oCells = oSel.GetCells();
	oCells.Merge();
	oSel.TypeText("��.\n���.");
//������� � ��������� ������ � ������� ���� �����
	oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
	oSel.MoveDown(COleVariant(short(5)),
		COleVariant(short(2)), COleVariant(short(1)));
	oCells = oSel.GetCells();
	oCells.Merge();
	oSel.TypeText("���.");
//������� � ��������� ������ � ������� ���� �����
	oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
	oSel.MoveDown(COleVariant(short(5)),
		COleVariant(short(2)), COleVariant(short(1)));
	oCells = oSel.GetCells();
	oCells.Merge();
//	oSel.TypeText("��������� ��. ������-\n���, ���.���");
	oSel.TypeText("��������� ��. ������-\n���, ���");
//������� � ��������� ������
	oSel.MoveRight(COleVariant(short(12)),
		COleVariant(short(1)), COleVariant(short(0)));
//�������� 5 ����� � ������ � ���������� ��
	oSel.MoveRight(COleVariant(short(1)),
		COleVariant(short(5)), COleVariant(short(1)));
	oCells = oSel.GetCells();
	oCells.Merge();
//������ � ��� �����
	oSel.TypeText("����� ��������� ���.���");
//������� � ������ ������������ ������ ��� �������
//	oSel.HomeKey(COleVariant(short(5)),covOpt);
	oSel.MoveDown(COleVariant(short(5)),
		COleVariant(short(1)), COleVariant(short(0)));
	oSel.MoveLeft(COleVariant(short(1)),
		COleVariant(short(5)), COleVariant(short(0)));//������ 5 ���� 3
//�������� 2 ������ � �������, ���������� �� � ������ �����
	oSel.MoveDown(COleVariant(short(5)),
		COleVariant(short(1)), COleVariant(short(1)));
	oCells = oSel.GetCells();
	oCells.Merge();
	oSel.TypeText("�����");
//������� � ��������� ������
	oSel.MoveRight(COleVariant(short(12)),
		COleVariant(short(1)), COleVariant(short(0)));
//�������� 4 ������ � ������, ���������� �� � ������ �����
	oSel.MoveRight(COleVariant(short(1)),
		COleVariant(short(4)), COleVariant(short(1)));
	oCells = oSel.GetCells();
	oCells.Merge();
	oSel.TypeText("� ��� �����");
//������� � ������ ������������ ������ ��� ������� � ������ ����� � ���
//	oSel.HomeKey(COleVariant(short(5)),covOpt);
	oSel.MoveDown(COleVariant(short(5)),
		COleVariant(short(1)), COleVariant(short(0)));
	oSel.MoveLeft(COleVariant(short(1)),
		COleVariant(short(4)), COleVariant(short(0)));//������ 4 ���� 2
	oSel.TypeText("�����-������� �����");
//������� � ��������� ������ � ������ �����
	oSel.MoveRight(COleVariant(short(12)),
		COleVariant(short(1)), COleVariant(short(0)));
	oSel.TypeText("������-��� �����");
//������� � ��������� ������ � ������ �����
	oSel.MoveRight(COleVariant(short(12)),
		COleVariant(short(1)), COleVariant(short(0)));
	oSel.TypeText("�������-�����");
//������� � ��������� ������ � ������ �����
	oSel.MoveRight(COleVariant(short(12)),
		COleVariant(short(1)), COleVariant(short(0)));
	oSel.TypeText("���-��� ������");
//������� � ������ ������ ����� ����� ���������
	oSel.MoveRight(COleVariant(short(12)), COleVariant(short(1)), COleVariant(short(0)));
}

void CZdanie::OutputRazdelToWord(Table *pTable, CRazdelZdanie* pRazdel)
{
//����� �� �������� (���������� ����� �������)
	COleVariant  covOpt((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	_Application app;
	Selection oSel;
	Cell oCell;
	Range oRange;
	CString str;
	_Font oFont;
	app = pTable->GetApplication();
	oSel = app.GetSelection();
	_ParagraphFormat oParFormat;
//������ ����� � ������ ������
	str.Format("������:%s\vK=%1.2f-����������� �� ������� �������;", pRazdel->GetAnalog().GetName(),pRazdel->GetKoefNaRaznV());
	oSel.TypeText(str);
	str.Format("\vK=%1.2f-����������� �� ������� ��������� ��������;", GetKoefNaRaznNaklRash());
	oSel.TypeText(str);
	str.Format("\vK=%1.2f-����������� ��� ��������� ��������� ������������ � ����1991� � ���� 2001�;", GetKoefPereschetOborud());
	oSel.TypeText(str);
	str.Format("\vK=%1.2f-����������� ��� ��������� ��������� ��� � ����1984� � ���� 2001�.", GetKoefPereschetCMR());
	oSel.TypeText(str);
//������� � ��������� ������ � ������ �����
	oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
	CString s1, s2, s3, s4, s5;
	if(	pRazdel->GetAnalog().GetVsegoStstObshestrRabot()>0)
		s1.Format("%1.0fx%1.3f",
		pRazdel->GetAnalog().GetVsegoStstObshestrRabot(),
		KoefNaRaznNaklRash);
	else s1 = "";
	if(	pRazdel->GetAnalog().GetVsegoStstSantehRabot()>0)
		if(s1 != "") s2.Format("+%1.0f",
			pRazdel->GetAnalog().GetVsegoStstSantehRabot());
		else s2.Format("%1.0f",
			pRazdel->GetAnalog().GetVsegoStstSantehRabot());
	else s2 = "";
	if(pRazdel->GetAnalog().GetVsegoStstMontaga()>0)
		if((s1+s2) != "")
			s3.Format("+%1.0f", pRazdel->GetAnalog().GetVsegoStstMontaga());
		else 
			s3.Format("%1.0f", pRazdel->GetAnalog().GetVsegoStstMontaga());
	else s3 = "";
	if(s1+s2+s3!="")
		s4.Format("(%s%s%s)x%1.3f", s1, s2, s3, KoefPereschetCMR);
	else s4 = "";
	if(pRazdel->GetAnalog().GetVsegoStstOborudov()>0)
		if(s4 != "")
			s5.Format("+%1.0fx%1.3f",
					  pRazdel->GetAnalog().GetVsegoStstOborudov(),
					  KoefPereschetOborud);
		else s5.Format("%1.0fx%1.3f",
					   pRazdel->GetAnalog().GetVsegoStstOborudov(),
					   KoefPereschetOborud);
	else s5="";
	if((s4+s5)!="")	
		str.Format("%s\v[%s%s]x%1.3f/%1.1f=%1.2f",
					pRazdel->GetName(),
					s4,
					s5,
					pRazdel->GetKoefNaRaznV(),
					pRazdel->GetAnalog().GetV(),
					pRazdel->GetUdStoimost());
	else str = pRazdel->GetName();
	if(str.Find('(') == -1)
	{	str.Replace("[", "(");
		str.Replace("]", ")");
	}
	oSel.TypeText(str);
//������� � ��������� ������ � ������ �����
	oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
	oSel.TypeText("�");
	oFont = oSel.GetFont();
	oFont.SetSuperscript(9999998);
	oSel.TypeText("2");
	oFont.SetSuperscript(9999998);
	//���������� ������������ �� ������
	oParFormat= oSel.GetParagraphFormat();
	oParFormat.SetAlignment(1);
//������� � ��������� ������ � ������ �����
	oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
	str.Format("%5.2f", V);//�����
	oSel.TypeText(str);
	//���������� ������������ �� ������
	oParFormat= oSel.GetParagraphFormat();
	oParFormat.SetAlignment(1);
//������� � ��������� ������ � ������ �����
	oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
	str.Format("%5.2f",pRazdel->GetUdStoimost());//�������� ���������
	oSel.TypeText(str);
	//���������� ������������ �� ������
	oParFormat= oSel.GetParagraphFormat();
	oParFormat.SetAlignment(1);
//������� � ��������� ������ � ������ �����
	oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
	str.Format("%5.2f",pRazdel->GetSumStoimost()/1000);//��������� ���������
	oSel.TypeText(str);
	//���������� ������������ �� ������
	oParFormat= oSel.GetParagraphFormat();
	oParFormat.SetAlignment(1);
//������� � ��������� ������ � ������ �����
	oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
	//��������� ������.�����
	if((pRazdel->GetVsegoStstObshestrRabot()+pRazdel->GetVsegoStstSantehRabot())>0)
		str.Format("%5.2f",
			(pRazdel->GetVsegoStstObshestrRabot()+pRazdel->GetVsegoStstSantehRabot())/1000);
	else str = "-";
	oSel.TypeText(str);
	//���������� ������������ �� ������
	oParFormat= oSel.GetParagraphFormat();
	oParFormat.SetAlignment(1);
//������� � ��������� ������ � ������ �����
	oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
	//��������� ��������� �����
	if(pRazdel->GetVsegoStstMontaga()>0)
		str.Format("%5.2f",pRazdel->GetVsegoStstMontaga()/1000);
	else str = "-";
	oSel.TypeText(str);
	//���������� ������������ �� ������
	oParFormat= oSel.GetParagraphFormat();
	oParFormat.SetAlignment(1);
//������� � ��������� ������ � ������ �����
	oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
	//��������� ������������
	if(pRazdel->GetVsegoStstOborudov()>0)
		str.Format("%5.2f",pRazdel->GetVsegoStstOborudov()/1000);
	else str = "-";
	oSel.TypeText(str);
	//���������� ������������ �� ������
	oParFormat= oSel.GetParagraphFormat();
	oParFormat.SetAlignment(1);
//������� � ��������� ������ � ������ �����
	oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
	oSel.TypeText("-");
	//���������� ������������ �� ������
	oParFormat= oSel.GetParagraphFormat();
	oParFormat.SetAlignment(1);
	//������� � ������ ��������� ������
	oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);

}

void CZdanie::OutputResultsToWord()
{
//����� ������� �� ������ � Word
//���������� word �� ���������

	COleVariant  covOpt((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	COleVariant covTrue((short)TRUE), covFalse((short)FALSE);
	_Application app;  // app - ��� ������ _Application, �.�. Word 10
	const int pbbegin=0, pbstep=10,
		pbend=(TableOfRazdel.List.size()+7)*pbstep;
	CDlgPb* pDlg;
	pDlg = new CDlgPb();
	BOOL ret = pDlg->Create(IDD_DIALOGPB, this);
	pDlg->m_pb.SetStep(pbstep);
	pDlg->m_pb.SetPos(pbbegin+pbstep);
	pDlg->ShowWindow(SW_SHOW);
	if(!app.CreateDispatch("Word.Application")) //��������� ������
	{
		AfxMessageBox("������ ��� ������ Word�!");
		return;
	}
	else {
//		app.SetVisible(TRUE); //� ������� ��� �������
		Documents oDocs;
		_Document oDoc;
		Paragraphs oPars;
		Paragraph oPar;
		Selection oSel;
		//���� ��������� ����������
		oDocs = app.GetDocuments();
		//���������, ���� ��������� Word ��� ������� ������� ����������???
		WIN32_FIND_DATA FindFileData;
		HANDLE hFind;
		hFind = FindFirstFile (ProjectPath+"\\SmpResults.doc", &FindFileData);
		if (hFind == INVALID_HANDLE_VALUE) 
		{//���� ��������� Word ��� ������� ������� �� ����������, ������� �����
			//�������� � ��������� ���������� ����� ��������
			oDocs.Add(covOpt,covOpt,covOpt,covOpt);//2000
		} else 
		{//���� ��������� Word ��� ������� ������� ����������, ������� ���
			//������� ������������ ��������
			FindClose(hFind);
			oDoc = oDocs.Open(COleVariant(ProjectPath+"\\SmpResults.doc"),
				covOpt, covOpt, covOpt, covOpt, covOpt, covOpt, covOpt, covOpt,
				covOpt, covOpt, covOpt);//, covOpt, covOpt,covOpt);
			//������� � ������ ���������
			//oDoc.Repaginate();
			//�������� ���������. ��������� ��� ���, ��� ����� ������� �������
			oSel = app.GetSelection();
			oSel.WholeStory();
			oSel.Delete (COleVariant((short)1), COleVariant((short)1));
		}
		pDlg->m_pb.StepIt();
		//� �������� �������� ��� �������� ��������� � ������� 1
		oDoc = oDocs.Item(COleVariant(long(1)));
		//�������������� ��������
		oDoc.Activate();
		//�������� ���������. ��������� ��� ���, ��� ����� ������� �������
		oSel = app.GetSelection();
		//�������� ���������� ��������		
		PageSetup ps;
		ps = oDoc.GetPageSetup();
		ps.SetOrientation(1);
		//���������� � ��������� �����, ��������� ���������.
		//�������� ������� ���������
		oPars = oSel.GetParagraphs();
		//�������� ����� �������� � ����������� �� ���������
		oPar = oPars.Add(covOpt);
		//���������� �����
		_Font oFont;
		oFont = oSel.GetFont();
		oFont.SetName("Times New Roman"); //����� ������ Times New Roman
	//	oFont.SetName("Arial");	//����� ������ Arial
		oFont.SetSize(14); //������ ������
		oSel.SetFont(oFont);
		// ���������� �����
		oPar.SetAlignment(AL_CENTER);	//��������� �� ������
		CString str;
		str="��������� ������� ������\n";
		str+="��������� ���������� �������������� �����";
		str+=" �� ��������� � ����������\n";
		str=str+Name+"\n";
		oSel.TypeText(str);
		oPar.SetAlignment(AL_LEFT);	//��������� �� ������ ����
		//�������� �����
		oFont.SetSize(8);
		oSel.TypeText("��������� ��� � ������������ � ����� 2001�.\n");
		//�������� �����
		oFont.SetSize(10);
		pDlg->m_pb.StepIt();
		//�������� �������
		Range oRange;
		Table oTable;
		Tables oTables;
		Row oRow;
		Rows oRows;
		Cell oCell;
		oRange = oSel.GetRange();
		oTables = oDoc.GetTables();
		oTable = oTables.Add(oRange, TableOfRazdel.List.size()+4, 10,
			COleVariant((short)1),
			COleVariant((short)0));
		//������� ���������� ������� �/� ���������
		oRows = oTable.GetRows();
		if(!TableOfRazdel.List.empty())//���� ���� ������ 1 ������
			for(int i=0; i<(TableOfRazdel.List.size()-1);i++)
			{	
				oRow = oRows.Item(i+4);
				Borders oBorders;
				Border oBorder;
				oBorders = oRow.GetBorders();
				oBorder = oBorders.Item(-3);
				oBorder.SetLineStyle(0);
			}
		//������� ��������� �������
		OutputHeadOfTableToWord(&oTable);
		pDlg->m_pb.StepIt();
		//������� ��� �������
		for(int i = 0; i<TableOfRazdel.List.size(); i++)
		{
			OutputRazdelToWord(&oTable, TableOfRazdel.List[i]);
			pDlg->m_pb.StepIt();
		}
		oSel.TypeText("�����:");
		//���������� ������������ �� ������� ����
		_ParagraphFormat oParFormat;
		oParFormat= oSel.GetParagraphFormat();
		oParFormat.SetAlignment(AL_RIGHT);
		//������� � ��������� ������ � ������ �����
		oSel.MoveRight(COleVariant(short(12)), COleVariant(short(5)), covOpt);
		str.Format("%5.2f",SumStoimost/1000);	//��������� ���������
		oSel.TypeText(str);
		//���������� ������������ �� ������
		oParFormat= oSel.GetParagraphFormat();
		oParFormat.SetAlignment(AL_CENTER);
		//������� � ��������� ������ � ������ �����
		oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
		//��������� ������.�����
		if((SumVsegoStstObshestrRabot+SumVsegoStstSantehRabot)>0)
			str.Format("%5.2f", (SumVsegoStstObshestrRabot+SumVsegoStstSantehRabot)/1000);
		else str = "-";
		oSel.TypeText(str);
		//���������� ������������ �� ������
		oParFormat = oSel.GetParagraphFormat();
		oParFormat.SetAlignment(AL_CENTER);
		//������� � ��������� ������ � ������ �����
		oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
		//��������� ��������� �����
		if(SumVsegoStstMontaga>0)
			str.Format("%5.2f", SumVsegoStstMontaga/1000);
		else str="-";
		oSel.TypeText(str);
		//���������� ������������ �� ������
		oParFormat= oSel.GetParagraphFormat();
		oParFormat.SetAlignment(AL_CENTER);
		//������� � ��������� ������ � ������ �����
		oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
		//��������� ������������
		if(SumVsegoStstOborudov>0)
			str.Format("%5.2f", SumVsegoStstOborudov/1000);
		else str = "-";
		oSel.TypeText(str);
		//���������� ������������ �� ������
		oParFormat= oSel.GetParagraphFormat();
		oParFormat.SetAlignment(AL_CENTER);
		//������� � ��������� ������ � ������ �����
		oSel.MoveRight(COleVariant(short(12)), covOpt, covOpt);
		oSel.TypeText("-");
		oParFormat= oSel.GetParagraphFormat();
		oParFormat.SetAlignment(AL_CENTER);
		//������� � ��������� �� �������� ������
		oSel.MoveDown(COleVariant(short(5)),
		COleVariant(short(1)), covOpt);
		pDlg->m_pb.StepIt();
		//����������
		oDoc.SaveAs( COleVariant(ProjectPath+"\\SmpResults.doc"), 
				   COleVariant((short)0),
				   covFalse, 
				   COleVariant(""), 
				   covTrue, 
				   COleVariant(""),
				   covFalse, 
				   covFalse, 
				   covFalse, 
				   covFalse, 
				   covFalse);/*,
				   covFalse,
				   covFalse,
				   covFalse,
				   covFalse,
				   covFalse);*/
	pDlg->ShowWindow(SW_HIDE);
	int IsShow = MessageBox("�������� ������, ������ ���������� ���������?",
					"����� ����������� � Word",
					MB_YESNO|MB_ICONQUESTION);
	pDlg->ShowWindow(SW_SHOW);
	pDlg->m_pb.SetPos(pbend);
	if(IsShow == IDYES)
		app.SetVisible(TRUE); //� ������� ��� �������
	else
		// ������� Word
		app.Quit(covFalse, covOpt, covOpt);
	}
	delete pDlg;

}
void CZdanie::OnDblClickMsflexgrid() 
{
	int i;
	i = TableOfRazdel.Grid.GetRow()-1;
	if((TableOfRazdel.List.empty() && !i) ||
		i==TableOfRazdel.List.size())
		MenuAddRazdel();
	else
		if(i < TableOfRazdel.List.size())
			MenuEditRazdel();
}

int  CZdanie::Close()
{
	if(TableOfRazdel.List.empty() && !Name) 
	{	UpdateMenuAndToolBarItems(0, ID_CLOSE, ID_WORD);
		return 1;
	}
	if(IsChangeProject)
	{	int res = AfxMessageBox("��������� ���������", MB_YESNOCANCEL|MB_ICONQUESTION);
		if(res == IDCANCEL) return 0;
		if(res == IDYES) 
		{	MenuSave();
		}
	}
	Clear();
	TableOfRazdel.Clear();
	TableOfRazdel.Update();
	TableOfRazdel.Grid.ShowWindow(SW_HIDE);
	IsChangeProject = 0;
	UpdateMenuAndToolBarItems(0, ID_CLOSE, ID_WORD);
	CString s;
	GetWindowText(s);
	int index = s.Find("-");
	if(index != -1) SetWindowText(s.Mid(0, index-1));
	return 1;
}

void CZdanie::SetWindowTextProjectName()
{
	CString s, s1;
	GetWindowText(s);
	CString ProjectPathTmp = ProjectPath;
	ProjectPathTmp.TrimRight("\\");
	int index = ProjectPathTmp.ReverseFind('\\');
	s1 = ProjectPathTmp.Mid(index+1);
	SetWindowText(s+" - ������ "+s1);
}