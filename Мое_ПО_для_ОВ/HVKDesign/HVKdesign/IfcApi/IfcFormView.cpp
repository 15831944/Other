// IfcFormView.cpp : implementation file
//

#include "stdafx.h"
//#include "	\ add additional includes here"
#include "IfcValue.h"
#include "IfcEdit.h"
#include "IfcButton.h"
#include "IfcComboBox.h"
#include "IfcTabCtrl.h"
#include "IfcFormView.h"
#include "Project.h"
#include "IfcDialog.h"

#include "..\HVKDesign\MainFrm.h"

#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CIfcFormView* pFv;
CRoom* pRmStc;
/////////////////////////////////////////////////////////////////////////////
// CIfcFormView

IMPLEMENT_DYNCREATE(CIfcFormView, CFormView)

CIfcFormView::CIfcFormView(UINT nIDTemplate)
	: CFormView(nIDTemplate)
{
	//{{AFX_DATA_INIT(CIfcFormView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CIfcFormView::~CIfcFormView()
{
}

int CIfcFormView::ShowData()
{
	for(int i=0; i<m_NumObj; i++)
		m_pObjArr[i]->Show(this);
	return TRUE;
}

int CIfcFormView::Update()
{
	if(this)
	{	if(!strcmp(m_pObj->m_DbName, "room"))
			return m_TabArr->Update();
		else
		{
			m_pObj->HideInFrmView(this);
			m_pObj->ShowInFrmView(this);
		}
	}
	return TRUE;
}

int CIfcFormView::ShowProject(CProject* pPrj)
{
	if(!pPrj)return FALSE;
	m_pObj = pPrj;
	char str[256];

	ShowDataStr("�������� �������:", (void*)pPrj->m_Name, 
						CIfcValue::String);
	CADORecord* AdoRcPrt = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
	// ������������� ������� � ���������
	//����� ������� ��� ������� ���������
	sprintf(str, "select * from party  order by name ASC");
	if(!AdoRcPrt->Open(str)) return FALSE;
	ShowDataStr("��������:", (void*)pPrj->m_pClientParty, 
						CIfcValue::String, AdoRcPrt);
	ShowDataStr("�����������:", (void*)pPrj->m_pAuthorParty, 
						CIfcValue::String, AdoRcPrt);

	CADORecord* AdoRcCt = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
	// ������������� ������� � ������
	//����� ������� ��� ������� ������
	sprintf(str, "select * from city  order by name ASC");
	if(!AdoRcCt->Open(str)) return FALSE;
	ShowDataStr("����� �������������:", (void*)pPrj->m_pCity, 
						CIfcValue::String, AdoRcCt);
	ShowData();
	(*AdoRcPrt)->Close();
	(*AdoRcCt)->Close();
	delete AdoRcCt;
	delete AdoRcPrt;
	return TRUE;
}

int CIfcFormView::HideProject(CProject* pPrj)
{
	return HideData();
}

int CIfcFormView::ShowBuilding(CBuilding *pBld)
{
	if(!pBld)return FALSE;
	m_pObj = pBld;
	ShowDataStr("�������� ������:", (void*)pBld->m_Name, 
						CIfcValue::String);

	ShowDataStr("������������ ���������� ������:", 
				(void*)&pBld->m_nFloor, CIfcValue::Integer);

	CADORecord* AdoRc = CHVKDbObject::m_ptrAdoRc;
	char str[256];
	// ������������� ������� � ����� ������
	//����� ������� ��� ������� ����� ������
	sprintf(str, "select * from BuildingType");
	if(!AdoRc->Open(str)) return FALSE;
	ShowDataStr("��� ������:", (void*)&pBld->m_BuildingType, 
						CIfcValue::String, AdoRc);


	ShowDataStr("��������� �������� �������� �� ���������:", 
					(void*)&pBld->m_qor, CIfcValue::Double);
	ShowDataStr("��������� �������� �������� �� ����������:", 
					(void*)&pBld->m_qvr, CIfcValue::Double);
	ShowData();
	(*AdoRc)->Close();
	return TRUE;
}

int CIfcFormView::HideBuilding(CBuilding *pBld)
{
	return HideData();
}

int CIfcFormView::ShowFloor(CFloor* pFlr)
{
	if(!pFlr)return FALSE;
	m_pObj = pFlr;
	ShowDataStr("�������� �����:", (void*)pFlr->m_Name, 
					CIfcValue::String);
	ShowDataStr("������ �����:", (void*)&pFlr->m_Height, 
					CIfcValue::Double);
	ShowData();
	return TRUE;
}

int CIfcFormView::HideFloor(CFloor* pFlr)
{
	return HideData();
}

int CIfcFormView::ShowRmMain(void* Prm)
{
	CRoom* pRm = static_cast<CRoom*>(Prm);
	ShowDataStr("�������� ���������:", 
					(void*)pRm->m_Name, CIfcValue::String);
	ShowDataStr("����� ���������:", 
					(void*)&pRm->m_Length, CIfcValue::Double);
	ShowDataStr("������ ���������:", 
					(void*)&pRm->m_Width, CIfcValue::Double);
	ShowDataStr("������ ���������:", 
					(void*)&pRm->m_Height, CIfcValue::Double);
	ShowDataStr("�������� ������ ����� ����� ����������:", 
					(void*)&pRm->m_QOutFenceW, CIfcValue::Double);
	for(int i=0; i<m_NumObj; i++)
		m_pObjArr[i]->Show(m_TabArr->GetParent());

	return TRUE;
}

int CIfcFormView::HideRmMain(void* Prm)
{
	return HideData();
}


static int ShowCalc(void* Data)
{
	return AfxMessageBox("�������� ������ ������!!!");
};
static int CalcHL(void* Data)
{
	CRoom* pRm = static_cast<CRoom*>(Data);
	pRm->CalcSumFenceHeatLoss();
	pRm->Update();
	pFv->Update();
	return AfxMessageBox("������ ����������� ���������");
};

//---------------------------------------------------------------------------
static int OnOK(void* Prm)
{
	CIfcDialog* pDlg = static_cast<CIfcDialog*>(Prm);
	CIfcComboBox* Cbb = dynamic_cast<CIfcComboBox*>(pDlg->m_pObjArr[0]);
	pDlg->HideData(0);
	pDlg->PostMessage(WM_CLOSE, NULL, NULL);
	pRmStc->Update();
	pFv->Update();
//	AfxMessageBox("OnOK");
	return TRUE;
}
//---------------------------------------------------------------------------
static int ShowV(void* Prm)
{
	CIfcDialog Dlg(NULL, 20, 20, 626, 208);
	CRoom* pRm = static_cast<CRoom*>(Prm);

	Dlg.ShowBorderStc = TRUE;
	Dlg.ShowHBDataStr("���������� �����, �3/�", 
		(void*)&pRm->m_V, (void*)&pRm->m_V, 
		CIfcValue::Double, CIfcWnd::DontEdt);
	Dlg.ShowHBDataStr("                                                                     �����", 
		(void*)&pRm->m_Length, (void*)&pRm->m_Length, 
		CIfcValue::Double, CIfcWnd::HandlEdt);
	Dlg.ShowHBDataStr("                                                                  ������", 
		(void*)&pRm->m_Width, (void*)&pRm->m_Width, 
		CIfcValue::Double, CIfcWnd::HandlEdt);
	Dlg.ShowHBDataStr("                                                                  ������", 
		(void*)&pRm->m_Height, (void*)&pRm->m_Height, 
		CIfcValue::Double, CIfcWnd::HandlEdt);
	Dlg.m_pObjArr[Dlg.m_NumObj] = new CIfcButton(
		"OK", 20, Dlg.m_dy-40-1.5*_H,
		BtnFunct(OnOK, &Dlg), Dlg.m_dx-40 , 1.5*_H);
	Dlg.m_NumObj++;

	Dlg.DoModal();

	return TRUE;
}
//---------------------------------------------------------------------------
static int ShowAirIn(void* Prm)
{
	CIfcDialog Dlg(NULL, 20, 20, 626, 230);
	CRoom* pRm = static_cast<CRoom*>(Prm);

	Dlg.ShowBorderStc = TRUE;
	Dlg.ShowHBDataStr("��������� ����������, �3/�", 
		(void*)&pRm->m_LInSum, (void*)&pRm->m_LInSum, 
		CIfcValue::Double, CIfcWnd::DontEdt);
	Dlg.ShowHBDataStr("                ������������ �� �����������", 
		(void*)&pRm->m_LInMechLoc, (void*)&pRm->m_LInMechLoc, 
		CIfcValue::Double, CIfcWnd::HandlEdt);
	Dlg.ShowHBDataStr("                   ������������ ������������", 
		(void*)&pRm->m_LInMechGlob, (void*)&pRm->m_LInMechGlob, 
		CIfcValue::Double, CIfcWnd::HandlEdt);
	Dlg.ShowHBDataStr("                                             ���������������", 
		(void*)&pRm->m_LInTech, (void*)&pRm->m_LInTech, 
		CIfcValue::Double, CIfcWnd::HandlEdt);
	Dlg.ShowHBDataStr("                                                    ������������", 
		(void*)&pRm->m_LInReal, (void*)&pRm->m_LInReal, 
		CIfcValue::Double, CIfcWnd::HandlEdt);
	Dlg.m_pObjArr[Dlg.m_NumObj] = new CIfcButton(
		"OK", 20, Dlg.m_dy-40-1.5*_H,
		BtnFunct(OnOK, &Dlg), Dlg.m_dx-40 , 1.5*_H);
	Dlg.m_NumObj++;

	Dlg.DoModal();

	return TRUE;
}
//---------------------------------------------------------------------------
static int ShowAirOut(void* Prm)
{
	CIfcDialog Dlg(NULL, 20, 20, 626, 230);
	CRoom* pRm = static_cast<CRoom*>(Prm);

	Dlg.ShowBorderStc = TRUE;
	Dlg.ShowHBDataStr("�������� ����������, �3/�", 
		(void*)&pRm->m_LOutSum, (void*)&pRm->m_LOutSum, 
		CIfcValue::Double, CIfcWnd::DontEdt);
	Dlg.ShowHBDataStr("                                 ������������ �������", 
		(void*)&pRm->m_LOutMechLoc, (void*)&pRm->m_LOutMechLoc, 
		CIfcValue::Double, CIfcWnd::HandlEdt);
	Dlg.ShowHBDataStr("                   ������������ ������������", 
		(void*)&pRm->m_LOutMechGlob, (void*)&pRm->m_LOutMechGlob, 
		CIfcValue::Double, CIfcWnd::HandlEdt);
	Dlg.ShowHBDataStr("                                             ���������������", 
		(void*)&pRm->m_LOutTech, (void*)&pRm->m_LOutTech, 
		CIfcValue::Double, CIfcWnd::HandlEdt);
	Dlg.ShowHBDataStr("                                                    ������������", 
		(void*)&pRm->m_LOutReal, (void*)&pRm->m_LOutReal, 
		CIfcValue::Double, CIfcWnd::HandlEdt);
	Dlg.m_pObjArr[Dlg.m_NumObj] = new CIfcButton(
		"OK", 20, Dlg.m_dy-40-1.5*_H,
		BtnFunct(OnOK, &Dlg), Dlg.m_dx-40 , 1.5*_H);
	Dlg.m_NumObj++;

	Dlg.DoModal();

	return TRUE;
}
//---------------------------------------------------------------------------
int CIfcFormView::ShowRmHB(void* Prm)
{
	CRoom* pRm = static_cast<CRoom*>(Prm);
	m_yCtrl = 40;
//���������
	ShowHBHeader("������������ �����������", "����", "����" );
//�����
	ShowHBDataStr("���������� �����, �3", (void*)&pRm->m_V, (void*)&pRm->m_V, 
		CIfcValue::Double, BtnDontEdt,
		&BtnFunct(ShowV, Prm));

//���������� �����������
	ShowHBHeader("����������� �������, 0�", " ");
	ShowHBDataStr("                                                 � ������� ����", 
		(void*)&pRm->m_TwzW, (void*)&pRm->m_TwzS, 
		CIfcValue::Double, HandlEdt);
	ShowHBDataStr("                                                                �������", 
		(void*)&pRm->m_TprW, (void*)&pRm->m_TprS, 
		CIfcValue::Double, HandlEdt);
	ShowHBDataStr("                                                 � ������� ����", 
		(void*)&pRm->m_ThzW, (void*)&pRm->m_ThzS, 
		CIfcValue::Double, HandlEdt);
	ShowHBDataStr("                                                     �����������", 
		(void*)&pRm->m_TdW, (void*)&pRm->m_TdS, 
		CIfcValue::Double, HandlEdt);
//���������
	ShowHBHeader("������������� ��������� �������, %", " ");
	ShowHBDataStr("                                                 � ������� ����", 
		(void*)&pRm->m_VlwzW, (void*)&pRm->m_VlwzS, 
		CIfcValue::Double, HandlEdt);
	ShowHBDataStr("                                                                �������", 
		(void*)&pRm->m_VlprW, (void*)&pRm->m_VlprS, 
		CIfcValue::Double, HandlEdt);
	ShowHBDataStr("                                                 � ������� ����", 
		(void*)&pRm->m_VlhzW, (void*)&pRm->m_VlhzS, 
		CIfcValue::Double, HandlEdt);
	ShowHBDataStr("                                                     �����������", 
		(void*)&pRm->m_VldW, (void*)&pRm->m_VldS, 
		CIfcValue::Double, HandlEdt);
//�������� ����������
	ShowHBDataStr("�������� ����������, �3/�", 
		(void*)&pRm->m_LOutSum, (void*)&pRm->m_LOutSum, 
		CIfcValue::Double, BtnDontEdt,
		&BtnFunct(ShowAirOut, Prm), 
		&BtnFunct(ShowAirOut, Prm));
//��������� ����������
	ShowHBDataStr("��������� ����������, �3/�", 
		(void*)&pRm->m_LInSum, (void*)&pRm->m_LInSum, 
		CIfcValue::Double, BtnDontEdt,
		&BtnFunct(ShowAirIn, Prm), &BtnFunct(ShowAirIn, Prm));
//��������� �������������
	ShowHBDataStr("��������� �������������", 
		(void*)&pRm->m_k, (void*)&pRm->m_k, 
		CIfcValue::Double, DontEdt);
//����������������
	ShowHBDataStr("����������������, ����/�", 
		(void*)&pRm->m_QInSumW, (void*)&pRm->m_QInSumS, 
		CIfcValue::Double, FHandlEdt_SBtnEdt,
		NULL, &BtnFunct(ShowCalc, Prm));
//�����������
	ShowHBDataStr("�����������, ����/�", 
		(void*)&pRm->m_QOutSumW, NULL, 
		CIfcValue::Double, FBtnDontEdt_SDontEdt,
		&BtnFunct(CalcHL, Prm));
//����������� ��� +5
	ShowHBDataStr("����������� ��� +5 0�, ����/�", 
		(void*)&pRm->m_QOutFence5W, NULL, 
		CIfcValue::Double, FBtnEdt_SDontEdt,
		&BtnFunct(ShowCalc, Prm));
//��������������/���������������
	ShowHBDataStr("������������/���������������(-), ����/�", 
		(void*)&pRm->m_dQW, (void*)&pRm->m_dQS, 
		CIfcValue::Double, DontEdt);
//������������������
	ShowHBDataStr("������������������, ����/� �� 1�3", 
		(void*)&pRm->m_dqW, (void*)&pRm->m_dqS, 
		CIfcValue::Double, DontEdt);
//��������� ���-�� ������� �� ���������������
	ShowHBDataStr("���-�� �-�� �� ���������������, �3", 
		(void*)&pRm->m_LdQW, (void*)&pRm->m_LdQS, 
		CIfcValue::Double, DontEdt);
//���������� ����� ��������� �����������
	ShowHBDataStr("����� ��������� �������������, ����/�", 
		(void*)&pRm->m_QLInW , NULL, 
		CIfcValue::Double, DontEdt);
//���������� ����� �������� ���������
	ShowHBDataStr("����� ������� ���������, ����/�", 
		(void*)&pRm->m_QInHeatingW, NULL, 
		CIfcValue::Double, DontEdt);

////////////////
	for(int i=0; i<m_NumObj; i++)
	{	m_pObjArr[i]->Show(m_TabArr->GetParent());
		if(m_pObjArr[i]->m_pCaptStc)
			m_pObjArr[i]->m_pCaptStc->ModifyStyleEx(0, WS_EX_STATICEDGE, SWP_FRAMECHANGED);
	}
	return TRUE;
}

int CIfcFormView::HideRmHB(void* Prm)
{
	return HideData();
}

int CIfcFormView::ShowRoom(CRoom* pRm)
{
	if(!pRm)return FALSE;
	m_pObj = pRm;
	pFv = this;
	pRmStc = pRm;
	CIfcTabCtrlItem** ItmArr = new CIfcTabCtrlItem*[2];
	ItmArr[0] = new CIfcTabCtrlItem("�������� ������", 
									TbItmFunct(CIfcFormView::ShowRmMain, pRm), 
									TbItmFunct(CIfcFormView::HideRmMain, pRm));

	ItmArr[1] = new CIfcTabCtrlItem("�������� ������", 
									TbItmFunct(CIfcFormView::ShowRmHB, pRm), 
									TbItmFunct(CIfcFormView::HideRmHB, pRm));

	m_TabArr = new CIfcTabCtrl(ItmArr, 2);
	m_TabArr->Show(this, (HMENU)123);

	return TRUE;
}

int CIfcFormView::HideRoom(CRoom* pRm)
{
	m_TabArr->Hide(this);
	delete m_TabArr;

	return TRUE;
}
static int CalcFenceHL(void* Prm)
{
	if(!Prm) return FALSE;
	CFence* pFnc = static_cast<CFence*>(Prm);
	if(pFnc->CalcHeatLoss())
	{
		pFv->Update();
		pFnc->m_pRm->GetSumFenceHeatLoss();
		AfxMessageBox("������ ����������� ���������� ��������");
	}
	return TRUE;
}

int CIfcFormView::ShowFence(CFence* pFnc)
{
	int h = HCONTROL;
	int dxBtn = h;
	pFv = this;
	if(!pFnc)return FALSE;
	m_pObj = pFnc;
	ShowDataStr("�������� ����������:", 
					(void*)pFnc->m_Name, CIfcValue::String);
	ShowDataStr("����� ����������:", 
					(void*)&pFnc->m_Length, CIfcValue::Double);
	ShowDataStr("������ ����������:", 
					(void*)&pFnc->m_Height, CIfcValue::Double);

	CADORecord* AdoRcFt = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
	CADORecord* AdoRcWs = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
	char str[256];
	// ������������� ������� � ����� ����������
	//����� ������� ��� ������� ����� ����������
	sprintf(str, "select * from FenceType");
	if(!AdoRcFt->Open(str)) return FALSE;
	ShowDataStr("��� ����������:", 
						(void*)&pFnc->m_FenceType, 
						CIfcValue::String, AdoRcFt);
	// ������������� ������� � �������� �����
	//����� ������� ��� ������� ������ �����
	sprintf(str, "select * from WorldSide");
	if(!AdoRcWs->Open(str)) return FALSE;
	ShowDataStr("���������� �� ������� �����:", 
						(void*)&pFnc->m_WorldSide, 
						CIfcValue::String, AdoRcWs);

	ShowDataStr("������ ����� ����� ����������:", 
					(void*)&pFnc->m_HeatLoss, 
					CIfcValue::Double, "...", 
					BtnFunct(CalcFenceHL, pFnc), dxBtn, h, TRUE);

	ShowData();
	(*AdoRcFt)->Close();
	(*AdoRcWs)->Close();
	delete AdoRcFt;
	delete AdoRcWs;
	return TRUE;
}

int CIfcFormView::HideFence(CFence* pFnc)
{
  return HideData();
}

void CIfcFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIfcFormView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIfcFormView, CFormView)
	//{{AFX_MSG_MAP(CIfcFormView)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIfcFormView diagnostics

#ifdef _DEBUG
void CIfcFormView::AssertValid() const
{
	CFormView::AssertValid();
}

void CIfcFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIfcFormView message handlers

HBRUSH CIfcFormView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{

	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
	if(dynamic_cast<CStatic*>(pWnd))
		pDC->SetTextColor(RGB(0, 0, 150)); //���� ������
	// TODO: Return a different brush if the default is not desired
	return hbr;
/*
	CIfcObject* pIfcObj; 
	if(pIfcObj = dynamic_cast<CIfcObject*>(pWnd))
		return pIfcObj->SetAttrib(hbr); 
*/
}

int CIfcFormView::SelectPrj(CProject* pPrj)
{
	return TRUE;

}
