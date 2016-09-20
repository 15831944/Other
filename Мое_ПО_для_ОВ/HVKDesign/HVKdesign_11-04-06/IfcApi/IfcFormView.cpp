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

int CIfcFormView::ShowProject(CProject* pPrj)
{
	if(!pPrj)return FALSE;
	char str[256];

	ShowDataStr("Название проекта:", (void*)pPrj->m_Name, 
						CIfcValue::String);
	CADORecord* AdoRcPrt = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
	// Инициализация данными о заказчике
	//Текст запроса для выборки заказчика
	sprintf(str, "select * from party  order by name ASC");
	if(!AdoRcPrt->Open(str)) return FALSE;
	ShowDataStr("Заказчик:", (void*)pPrj->m_pClientParty, 
						CIfcValue::String, AdoRcPrt);
	ShowDataStr("Исполнитель:", (void*)pPrj->m_pAuthorParty, 
						CIfcValue::String, AdoRcPrt);

	CADORecord* AdoRcCt = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
	// Инициализация данными о городе
	//Текст запроса для выборки города
	sprintf(str, "select * from city  order by name ASC");
	if(!AdoRcCt->Open(str)) return FALSE;
	ShowDataStr("Город строительства:", (void*)pPrj->m_pCity, 
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
	ShowDataStr("Название здания:", (void*)pBld->m_Name, 
						CIfcValue::String);

	ShowDataStr("Максимальное количество этажей:", 
				(void*)&pBld->m_nFloor, CIfcValue::Integer);

	CADORecord* AdoRc = CHVKDbObject::m_ptrAdoRc;
	char str[256];
	// Инициализация данными о типах здания
	//Текст запроса для выборки типов здания
	sprintf(str, "select * from BuildingType");
	if(!AdoRc->Open(str)) return FALSE;
	ShowDataStr("Тип здания:", (void*)&pBld->m_BuildingType, 
						CIfcValue::String, AdoRc);


	ShowDataStr("Расчетная удельная нагрузка на отопление:", 
					(void*)&pBld->m_qor, CIfcValue::Double);
	ShowDataStr("Расчетная удельная нагрузка на вентиляцию:", 
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
	ShowDataStr("Название этажа:", (void*)pFlr->m_Name, 
					CIfcValue::String);
	ShowDataStr("Высота этажа:", (void*)&pFlr->m_Height, 
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
	ShowDataStr("Название помещения:", 
					(void*)pRm->m_Name, CIfcValue::String);
	ShowDataStr("Длина помещения:", 
					(void*)&pRm->m_Length, CIfcValue::Double);
	ShowDataStr("Ширина помешения:", 
					(void*)&pRm->m_Width, CIfcValue::Double);
	ShowDataStr("Высота помещения:", 
					(void*)&pRm->m_Height, CIfcValue::Double);
	ShowDataStr("Сумарные потери тепла через ограждения:", 
					(void*)&pRm->m_QOutFenceW, CIfcValue::Double);
	for(int i=0; i<m_NumObj; i++)
		m_pObjArr[i]->Show(m_TabArr);

	return TRUE;
}

int CIfcFormView::HideRmMain(void* Prm)
{
	return HideData();
}


static int ShowCalc(void* Data)
{
	return AfxMessageBox("Тепловой баланс расчет!!!");
};

static int ShowAirOut(void* Prm)
{
	
	CIfcDialog Dlg;

	Dlg.SetShowParam(-1, 50, -1, -1, -1, 20, 120, -1);
	Dlg.ShowBorderStc = TRUE;
	CRoom* pRm = static_cast<CRoom*>(Prm);

	Dlg.ShowHBHeader("Вытяжная вентиляция, м3/ч", " ");
	Dlg.ShowHBDataStr("                                 механическая местная", 
		(void*)&pRm->m_LOutMechLoc, (void*)&pRm->m_LOutMechLoc, 
		CIfcValue::Double, CIfcWnd::HandlEdt);
	Dlg.ShowHBDataStr("                   механическая общеобменная", 
		(void*)&pRm->m_LOutMechGlob, (void*)&pRm->m_LOutMechGlob, 
		CIfcValue::Double, CIfcWnd::HandlEdt);
	Dlg.ShowHBDataStr("                                             технологическая", 
		(void*)&pRm->m_LOutTech, (void*)&pRm->m_LOutTech, 
		CIfcValue::Double, CIfcWnd::HandlEdt);
	Dlg.ShowHBDataStr("                                                    естественная", 
		(void*)&pRm->m_LOutReal, (void*)&pRm->m_LOutReal, 
		CIfcValue::Double, CIfcWnd::HandlEdt);
	Dlg.ShowHBDataStr("                                                                   ИТОГО", 
		(void*)&pRm->m_LOutSum, (void*)&pRm->m_LOutSum, 
		CIfcValue::Double, CIfcWnd::HandlEdt);
	Dlg.DoModal();
	Dlg.HideData();

	return TRUE;
}
int CIfcFormView::ShowRmHB(void* Prm)
{
	CRoom* pRm = static_cast<CRoom*>(Prm);
	m_yCtrl = 40;
//заголовок
	ShowHBHeader("Наименование показателей", "зима", "лето" );
//объем
	ShowHBDataStr("Внутренний объем, м3", (void*)&pRm->m_V, (void*)&pRm->m_V, 
		CIfcValue::Double, BtnDontEdt,
		&BtnFunct(ShowAirOut, Prm));

//внутренняя температура
	ShowHBHeader("Температура воздуха, 0С", " ");
	ShowHBDataStr("                                                 в рабочей зоне", 
		(void*)&pRm->m_TwzW, (void*)&pRm->m_TwzS, 
		CIfcValue::Double, HandlEdt);
	ShowHBDataStr("                                                                притока", 
		(void*)&pRm->m_TprW, (void*)&pRm->m_TprS, 
		CIfcValue::Double, HandlEdt);
	ShowHBDataStr("                                                 в верхней зоне", 
		(void*)&pRm->m_ThzW, (void*)&pRm->m_ThzS, 
		CIfcValue::Double, HandlEdt);
	ShowHBDataStr("                                                     душирования", 
		(void*)&pRm->m_TdW, (void*)&pRm->m_TdS, 
		CIfcValue::Double, HandlEdt);
//влажность
	ShowHBHeader("Относительная влажность воздуха, %", " ");
	ShowHBDataStr("                                                 в рабочей зоне", 
		(void*)&pRm->m_VlwzW, (void*)&pRm->m_VlwzS, 
		CIfcValue::Double, HandlEdt);
	ShowHBDataStr("                                                                притока", 
		(void*)&pRm->m_VlprW, (void*)&pRm->m_VlprS, 
		CIfcValue::Double, HandlEdt);
	ShowHBDataStr("                                                 в верхней зоне", 
		(void*)&pRm->m_VlhzW, (void*)&pRm->m_VlhzS, 
		CIfcValue::Double, HandlEdt);
	ShowHBDataStr("                                                     душирования", 
		(void*)&pRm->m_VldW, (void*)&pRm->m_VldS, 
		CIfcValue::Double, HandlEdt);
//вытяжная вентиляция
	ShowHBDataStr("Вытяжная вентиляция, м3/ч", 
		(void*)&pRm->m_LOutSum, (void*)&pRm->m_LOutSum, 
		CIfcValue::Double, BtnDontEdt,
		&BtnFunct(ShowAirOut, Prm), 
		&BtnFunct(ShowAirOut, Prm));
//приточная вентиляция
	ShowHBDataStr("Приточная вентиляция, м3/ч", 
		(void*)&pRm->m_LInSum, (void*)&pRm->m_LInSum, 
		CIfcValue::Double, BtnDontEdt,
		&BtnFunct(ShowCalc, Prm), &BtnFunct(ShowCalc, Prm));
//кратность воздухообмена
	ShowHBDataStr("Кратность воздухообмена", 
		(void*)&pRm->m_k, (void*)&pRm->m_k, 
		CIfcValue::Double, DontEdt);
//теплопоступления
	ShowHBDataStr("Теплопоступления, ккал/ч", 
		(void*)&pRm->m_QInSumW, (void*)&pRm->m_QInSumS, 
		CIfcValue::Double, FHandlEdt_SBtnEdt,
		NULL, &BtnFunct(ShowCalc, Prm));
//теплопотери
	ShowHBDataStr("Теплопотери, ккал/ч", 
		(void*)&pRm->m_QOutSumW, NULL, 
		CIfcValue::Double, FBtnEdt_SDontEdt,
		&BtnFunct(ShowCalc, Prm));
//теплопотери при +5
	ShowHBDataStr("Теплопотери при +5 0С, ккал/ч", 
		(void*)&pRm->m_QOutFence5W, NULL, 
		CIfcValue::Double, FBtnEdt_SDontEdt,
		&BtnFunct(ShowCalc, Prm));
//теплопоизбытки/теплонедостатки
	ShowHBDataStr("Теплоизбытки/теплонедостатки(-), ккал/ч", 
		(void*)&pRm->m_dQW, (void*)&pRm->m_dQS, 
		CIfcValue::Double, DontEdt);
//теплонапряженность
	ShowHBDataStr("Теплонапряженность, ккал/ч на 1м3", 
		(void*)&pRm->m_dqW, (void*)&pRm->m_dqS, 
		CIfcValue::Double, DontEdt);
//Расчетное кол-во воздуха по тепловыделениям
	ShowHBDataStr("Кол-во в-ха по тепловыделениям, м3", 
		(void*)&pRm->m_LdQW, (void*)&pRm->m_LdQS, 
		CIfcValue::Double, DontEdt);
//Возмещение тепла приточной вентиляцией
	ShowHBDataStr("Тепло приточной вентиляцияции, ккал/ч", 
		(void*)&pRm->m_QLInW , NULL, 
		CIfcValue::Double, DontEdt);
//Возмещение тепла системой отопления
	ShowHBDataStr("Тепло системы отопелния, ккал/ч", 
		(void*)&pRm->m_QInHeatingW, NULL, 
		CIfcValue::Double, DontEdt);

////////////////
	for(int i=0; i<m_NumObj; i++)
	{	m_pObjArr[i]->Show(m_TabArr);
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

	CIfcTabCtrlItem** ItmArr = new CIfcTabCtrlItem*[2];
	ItmArr[0] = new CIfcTabCtrlItem("Основные данные", 
									TbItmFunct(CIfcFormView::ShowRmMain, pRm), 
									TbItmFunct(CIfcFormView::HideRmMain, pRm));

	ItmArr[1] = new CIfcTabCtrlItem("Тепловой баланс", 
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

int CIfcFormView::ShowFence(CFence* pFnc)
{
	if(!pFnc)return FALSE;
	ShowDataStr("Название ограждения:", 
					(void*)pFnc->m_Name, CIfcValue::String);
	ShowDataStr("Длина ограждения:", 
					(void*)&pFnc->m_Length, CIfcValue::Double);
	ShowDataStr("Высота ограждения:", 
					(void*)&pFnc->m_Height, CIfcValue::Double);

	CADORecord* AdoRcFt = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
	CADORecord* AdoRcWs = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
	char str[256];
	// Инициализация данными о типах ограждения
	//Текст запроса для выборки типов ограждения
	sprintf(str, "select * from FenceType");
	if(!AdoRcFt->Open(str)) return FALSE;
	ShowDataStr("Тип ограждения:", 
						(void*)&pFnc->m_FenceType, 
						CIfcValue::String, AdoRcFt);
	// Инициализация данными о сторонах света
	//Текст запроса для выборки сторон света
	sprintf(str, "select * from WorldSide");
	if(!AdoRcWs->Open(str)) return FALSE;
	ShowDataStr("Ориентация на сторону света:", 
						(void*)&pFnc->m_WorldSide, 
						CIfcValue::String, AdoRcWs);

	ShowDataStr("Потери тепла через ограждение:", 
					(void*)&pFnc->m_HeatLoss, 
					CIfcValue::Double, TRUE);
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
		pDC->SetTextColor(RGB(0, 0, 150)); //цвет текста
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
