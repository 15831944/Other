// IfcComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "IfcComboBox.h"
#include "../ComApi/AdoRecord.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIfcComboBox

CIfcComboBox::CIfcComboBox(CIfcValue* Value, CADORecord* ptrCurrentRecordset, int xVal , int yVal, CHVKDbObject* pObj /*= NULL*/,
		 int dxVal/* = 0*/, int dyVal/* = 0*/, int xCapt/* = -1*/, int yCapt/* = -1*/, int dxCapt/* = 0*/, int dyCapt/* = 0*/)
		 :CIfcObject(Value, xVal , yVal, dxVal, dyVal, xCapt, yCapt, 
		  dxCapt, dyCapt), m_ptrCurrentRecordset(ptrCurrentRecordset), m_pObj(pObj)
{
	m_IsCanCreateNew = FALSE;
}

CIfcComboBox::~CIfcComboBox()
{
}

int CIfcComboBox::Show(CWnd* pView)
{
	int listH = 200;
	char FldData[CIfcValue::MaxSizeStr];
	char strVal[CIfcValue::MaxSizeStr];
	if(m_pCaptStc)
	{	ShowStatic(pView);
//		m_pCaptStc->SetFont(CIfcObject::m_pFont);
		SetWndFont(m_pCaptStc);
	}
	m_Value.SetValue(strVal);
	DWORD dwStyle = WS_CHILD|WS_TABSTOP|WS_VSCROLL |WS_VISIBLE|ES_AUTOVSCROLL;
	if(!*CIfcObject::m_pIsEdt)
		dwStyle|=ES_READONLY;
	else
		dwStyle|=CBS_DROPDOWNLIST;
	if(*CIfcObject::m_pIsEdt)
	{	CreateEx(WS_EX_CLIENTEDGE, _T("COMBOBOX"), strVal, dwStyle, 
		m_xVal, m_yVal,  m_dxVal, m_dyVal+listH, 
		pView->m_hWnd, (HMENU)CIfcObject::m_IDCtrl++);
		try{
		  if(!(*m_ptrCurrentRecordset)->BOF) (*m_ptrCurrentRecordset)->MoveFirst();
		  if((*m_ptrCurrentRecordset)->EndOfFile &&
			(*m_ptrCurrentRecordset)->BOF)
			  return FALSE;
		  if(m_IsCanCreateNew)
			AddString("Новый...");
		  do
		  { 
			m_ptrCurrentRecordset->GetData("Name", CADORecord::String, FldData);
			AddString(FldData);
			(*m_ptrCurrentRecordset)->MoveNext();
		  }while(!(*m_ptrCurrentRecordset)->EndOfFile);
		}
		catch(_com_error &e)
		{
		  GenerateError(e.Error(), e.Description());
		  return FALSE;
		}
		if(strcmp(strVal, ""))
			SelectString(-1, strVal);
		else
			SetCurSel(0);
	}
	else
		CreateEx(WS_EX_CLIENTEDGE/*NULL*/, 
		  _T("EDIT"), strVal, dwStyle, m_xVal, m_yVal,
		  m_dxVal, m_dyVal, pView->m_hWnd, (HMENU)CIfcObject::m_IDCtrl++);
//	SetFont(pView->GetFont());
//	SetFont(CIfcObject::m_pFont);
		SetWndFont(this);
	return TRUE;
}

int CIfcComboBox::Update(int* IsMsg/* = 0*/)
{
	int stat = TRUE;
	if(!GetCurSel()) 
		stat = m_pObj->CreateNew();
	else
	{	char str[CIfcValue::MaxSizeStr];
		GetWindowText(str, CIfcValue::MaxSizeStr);
		if(m_Value.GetValue(str, IsMsg) && m_pObj)
		{
			strcpy(m_pObj->m_Name, str);
			m_pObj->InitByName();
		}
		stat = TRUE;
	}
	return stat;
}

BEGIN_MESSAGE_MAP(CIfcComboBox, CComboBox)
	//{{AFX_MSG_MAP(CIfcComboBox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIfcComboBox message handlers

BOOL CIfcComboBox::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message == WM_KEYDOWN)	
		if(pMsg->wParam == VK_RETURN)
			pMsg->wParam = VK_TAB;
	return CComboBox::PreTranslateMessage(pMsg);
}
