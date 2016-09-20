// IfcWnd.cpp: implementation of the CIfcWnd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IfcWnd.h"

#include "IfcValue.h"
#include "IfcEdit.h"
#include "IfcButton.h"
#include "IfcComboBox.h"
#include "IfcTabCtrl.h"
#include "IfcFormView.h"
#include "Project.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIfcWnd::CIfcWnd()
{
	m_xStc = 20;
	m_yStc = 30;
	m_xVal = 20;
	m_yVal = m_yStc+15;
	m_Offset = 55;
	m_NumObj = 0;
	m_xBtn = 20;
	m_yBtn = 0;
	m_yCtrl = 40;
}

CIfcWnd::~CIfcWnd()
{

}
int CIfcWnd::ShowHBHeader(char* Capt1, char* Capt2/*= NULL*/, char* Capt3/*= NULL*/)
{
	int y = m_yCtrl;
	int h = HCONTROL;
	int xStc1 = 20, dxStc1= 290; 
	int	xStc2 = xStc1 + dxStc1, dxStc2 = 125 + h;

//заголовок
	m_pObjArr[m_NumObj] = new CIfcEdit(&CIfcValue(NULL, 0, Capt1), 
									0, y, 0, h, xStc1, y, dxStc1, h);
	m_NumObj++;

	if(Capt3 == NULL)
		dxStc2 *= 2;
	m_pObjArr[m_NumObj] = new CIfcEdit(&CIfcValue(NULL, 0, Capt2), 
									0, y, 0, h, xStc2, y, dxStc2, h);
	m_NumObj++;

	if(Capt3 != NULL)
	{	m_pObjArr[m_NumObj] = new CIfcEdit(&CIfcValue(NULL, 0, Capt3), 
										0, y, 0, h, xStc2+dxStc2, y, dxStc2, h);
		m_NumObj++;
	}
	m_yCtrl += h;
	return TRUE;
}

int CIfcWnd::ShowHBDataStr(char* Capt, void* DataW, void* DataS, int DataType, int ShowType /* = BousHandlEdt*/,
								BtnFunct* ClickFnW /* = NULL*/, BtnFunct* ClickFnS/* = NULL*/,
								CADORecord* ptrCurrentRecordset/*, EdtFunct* UpdateFn/* = NULL*/)
{
	int y = m_yCtrl;
	int h = HCONTROL;
	int xStc = 20, dxStc= 290, dxEdt1, dxEdt2;
	dxEdt1 = dxEdt2 = 125;
	int xEdt1 = xStc + dxStc;
	int xBtn = xEdt1 + dxEdt1;
	int dxBtn = h;
	int xEdt2 = xBtn + dxBtn;
	if(ShowType == CmbEdt && DataW != DataS)
		return FALSE;
	if(DataW == DataS)	//одно большое поле
	{
		if(ShowType == BtnEdt || ShowType == BtnDontEdt)
		{
			xBtn = xEdt1 + 2*dxEdt1 + dxBtn;
			dxEdt1 = 2*dxEdt1 + dxBtn;
		}else if(ShowType == HandlEdt || ShowType == DontEdt || CmbEdt)
		{
			dxEdt1 = 2*(dxEdt1 + dxBtn);
		}else return FALSE;
	}else if(ShowType == HandlEdt || ShowType == DontEdt || 
			 ShowType == FDontEdt_SHandlEdt || ShowType == FHandlEdt_SDontEdt)
	{
		dxEdt1 = dxEdt2 = dxEdt1 + dxBtn;
	}else if(ShowType == FDontEdt_SBtnEdt || ShowType == FHandlEdt_SBtnEdt)
	{
		dxEdt1 = dxEdt1 + dxBtn;
	}else if(ShowType == FBtnEdt_SHandlEdt || ShowType == FBtnEdt_SDontEdt ||
			 ShowType == FBtnDontEdt_SDontEdt)
	{
		dxEdt2 = dxEdt2 + dxBtn;
	}
	int IsReadOnly;
	if(	ShowType == DontEdt || ShowType == FDontEdt_SHandlEdt || 
		ShowType == FDontEdt_SBtnEdt || ShowType == BtnDontEdt ||
		ShowType == FBtnDontEdt_SDontEdt)
		IsReadOnly = 1;
	else IsReadOnly = 0;
	if(ShowType != CmbEdt)
		m_pObjArr[m_NumObj] = new CIfcEdit(&CIfcValue(DataW?DataW:"  -", DataW?DataType:CIfcValue::String, Capt), 
									xEdt1, y, dxEdt1, h, xStc, y, dxStc, h, IsReadOnly);
	else
	{	CHVKDbObject* pObj = static_cast<CHVKDbObject*>(DataW);
		m_pObjArr[m_NumObj] = new CIfcComboBox(&CIfcValue((void*)pObj->m_Name, DataType, Capt),
							ptrCurrentRecordset, xEdt1, y, pObj,
							dxEdt1, h, xStc, y, dxStc, h);
	}
	m_NumObj++;
	if(ShowType == BtnEdt || ShowType == FBtnEdt_SHandlEdt || 
	   ShowType == FBtnEdt_SDontEdt || ShowType == BtnDontEdt ||
	   ShowType == FBtnDontEdt_SDontEdt)
	{	m_pObjArr[m_NumObj] = new CIfcButton("...", xBtn, y, *ClickFnW, dxBtn, h);
		m_NumObj++;
	}
	if(	ShowType == DontEdt || ShowType == FHandlEdt_SDontEdt || 
		ShowType == FBtnEdt_SDontEdt || ShowType == BtnDontEdt)
		IsReadOnly = 1;
	else IsReadOnly = 0;
	if(DataW != DataS)
	{
		m_pObjArr[m_NumObj] = new CIfcEdit(&CIfcValue(DataS?DataS:"  -", DataS?DataType:CIfcValue::String, NULL), 
									xEdt2, y, dxEdt2, h, 0, 0, 0, 0, IsReadOnly);
		m_NumObj++;
		if(ShowType == BtnEdt || ShowType == FHandlEdt_SBtnEdt || 
			ShowType == FDontEdt_SBtnEdt || ShowType == BtnDontEdt)
		{	m_pObjArr[m_NumObj] = new CIfcButton("...", xBtn+dxBtn+dxEdt2, y, *ClickFnS, dxBtn, h);
			m_NumObj++;
		}
	}
	m_yCtrl += h;
	return TRUE;
}
// показать текст + поле ввода
int CIfcWnd::ShowDataStr(char* Capt, void* Data, int DataType, int IsReadOnly/* = 0*//*, EdtFunct* UpdateFn/* = NULL*/)
{
	m_pObjArr[m_NumObj] = new CIfcEdit(&CIfcValue(Data, DataType, Capt), 
								m_xVal, m_yVal+m_NumObj*m_Offset, 0, 0, m_xStc, m_yStc+m_NumObj*m_Offset, 0, 0, IsReadOnly);

	m_NumObj++;
	return TRUE;
}
// текст + поле воода + кнопку
int CIfcWnd::ShowDataStr(char* Capt, void* Data, int DataType, 
						 char* TxtBtn, BtnFunct ClickFn, 
						 int dxBtn, int dyBtn, int IsReadOnly/* = 0*//*, EdtFunct* UpdateFn*/)
{
	m_pObjArr[m_NumObj] = new CIfcEdit(&CIfcValue(Data, DataType, Capt), 
								m_xVal, m_yVal+m_NumObj*m_Offset, 0, 0, m_xStc, m_yStc+m_NumObj*m_Offset, 0, 0, IsReadOnly);
	m_pObjArr[m_NumObj]->m_dxVal = m_pObjArr[m_NumObj]->m_dxVal - dyBtn;
	int xBtn = m_pObjArr[m_NumObj]->m_xVal + m_pObjArr[m_NumObj]->m_dxVal;
	m_NumObj++;
	m_pObjArr[m_NumObj] = new CIfcButton(TxtBtn, xBtn, m_yVal+(m_NumObj-1)*m_Offset,
										ClickFn, dxBtn, dyBtn);
		
	m_NumObj++;
	return TRUE;
}
// текст + комбобокс
int CIfcWnd::ShowDataStr(char* Capt, void* Data, int DataType, CADORecord* ptrCurrentRecordset/*, EdtFunct* UpdateFn/* = NULL*/)
{
	CHVKDbObject* pObj = static_cast<CHVKDbObject*>(Data);
	m_pObjArr[m_NumObj] = new CIfcComboBox(&CIfcValue((void*)pObj->m_Name, DataType, Capt), 
							ptrCurrentRecordset, m_xVal, m_yVal+m_NumObj*m_Offset, pObj,
							0, 0, m_xStc, m_yStc+m_NumObj*m_Offset);
	m_NumObj++;
	return TRUE;
}

int CIfcWnd::HideData(int IsMsg/* = 1*/)
{
	int i;
	// нужно 2 цикла, а то если изменить не первое знаение, 
	// то сообщение выскакивает, на том едите, где меняли, 
	// а предыдущие в это время уже удалены и получается
	// некрасивая картина, позади месаджбокса
	for(i=0; i<m_NumObj; i++)
		m_pObjArr[i]->Update(&IsMsg);
	for(i=0; i<m_NumObj; i++)
		delete m_pObjArr[i];
	m_NumObj = 0;
	CIfcObject::m_IDCtrl = 1234;
	return TRUE;
}

void CIfcWnd::SetShowParam(int xStc, int yStc, int xVal, int yVal, int Offset,
						   int xBtn, int yBtn, int yCtrl)
{
	if(xStc>0)
		m_xStc = xStc;
	if(yStc>0)
		m_yStc = yStc;
	if(xVal>0)
		m_xVal = xVal;
	if(yVal>0)
		m_yVal = yVal;
	if(Offset>0)
		m_Offset = Offset;
	if(xBtn>0)
		m_xBtn = xBtn;
	if(yBtn>0)
		m_yBtn = yBtn;
	if(yCtrl>0)
		m_yCtrl = yCtrl;
}

int CIfcWnd::UpdtData(int IsMsg/* = 1*/)
{
	for(int i=0; i<m_NumObj; i++)
		m_pObjArr[i]->Update(&IsMsg);
	return TRUE;
}