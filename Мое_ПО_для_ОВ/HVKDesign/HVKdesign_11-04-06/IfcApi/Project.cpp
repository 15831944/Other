// Project.cpp: implementation of the CProject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Project.h"
#include "..\\IfcApi\\IfcFormView.h"
#include "..\\IfcApi\\IfcDialog.h"
#include "..\\IfcApi\\IfcComboBox.h"
#include "..\\IfcApi\\IfcEdit.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
CProject* CProject::Copy(CProject const& op2)
{
	CHVKDbObject::Copy(op2);
	m_pBuildingVect =  op2.m_pBuildingVect;
	if(op2.m_pCity)
		*m_pCity        = *op2.m_pCity;
	if(op2.m_pAuthorParty)
		*m_pAuthorParty = *op2.m_pAuthorParty;
	if(op2.m_pClientParty)
		*m_pClientParty = *op2.m_pClientParty;
/*	if(op2.m_svPrj)
		*m_svPrj = *op2.m_svPrj;
*/	return this;
}
//---------------------------------------------------------------------------
CHVKDbObject* CProject::Clone()
{
	CProject* pObj = new CProject();
	return pObj->Copy(*this);
}
//---------------------------------------------------------------------------
int CProject::Distruct()
{
	if(m_pCity)
		delete m_pCity;
	if(m_pAuthorParty)
		delete m_pAuthorParty;
	if(m_pClientParty)
		delete m_pClientParty;
	if(m_svPrj)
		delete m_svPrj;
	return TRUE;
}
//---------------------------------------------------------------------------
CProject::CProject()
{
	strcpy(m_NameWindow, "Данные о проекте");
	strcpy(m_DbName, "project");

	m_pCity        = new CCity;
	m_pAuthorParty = new CParty;
	m_pClientParty = new CParty;
	m_svPrj        = NULL;
	m_pCurrObj     = this;
}
//---------------------------------------------------------------------------
CProject::CProject(CProject const& op2):CHVKDbObject()
{
	strcpy(m_NameWindow, "Данные о проекте");
	strcpy(m_DbName, "project");
	m_pCurrObj     = this;

    Copy(op2);
}
//---------------------------------------------------------------------------
CProject::~CProject()
{
	Distruct();
}
//---------------------------------------------------------------------------
int CProject::SetSvPrj(CProject* pPrj/* = NULL*/)
{
	if(!m_svPrj)
		m_svPrj = new CProject;
	if(!pPrj)
		pPrj = this;
	*m_svPrj = *pPrj;
	return TRUE;
}
//---------------------------------------------------------------------------
int CProject::IsChangePrj()
{
	return !(m_svPrj && *m_svPrj == *this);
}
//---------------------------------------------------------------------------
CProject const& CProject::operator=(CProject const &op2)
{
	if(this==&op2 || *this == op2) return *this;
//	Delete();
	return *Copy(op2);
}
//---------------------------------------------------------------------------
int const& CProject::operator==(CProject const& op2)
{
	return(*(CHVKDbObject*)this == *(CHVKDbObject*)&op2 &&
		 m_pBuildingVect ==  op2.m_pBuildingVect && 
		*m_pAuthorParty  == *op2.m_pAuthorParty  && 
		*m_pClientParty  == *op2.m_pClientParty  &&
		*m_pCity         == *op2.m_pCity);
/*	int stat1, stat2, stat3, stat4, stat5;
	stat1 = (*(CHVKDbObject*)this == *(CHVKDbObject*)&op2);
	stat2 = (m_pBuildingVect  ==  op2.m_pBuildingVect);
	stat3 = (*m_pAuthorParty  == *op2.m_pAuthorParty);
	stat4 = (*m_pClientParty  == *op2.m_pClientParty);
	stat5 = (*m_pCity         == *op2.m_pCity);
	return stat1 && stat2 && stat3 && stat4 && stat5;*/
}
//---------------------------------------------------------------------------
int const& CProject::operator!=(CProject const& op2)
{
  return !operator==(op2);
}
//---------------------------------------------------------------------------
int const& CProject::CmpObj(CHVKDbObject* op2)
{
	return operator==(*(CProject*)op2);
}
//---------------------------------------------------------------------------
int CProject::Open()
{
	int stat=0;
//	SetID(5);
//	InitByID();
	return stat;
}
//---------------------------------------------------------------------------
int CProject::Init()
{
	int stat;
	CBuilding* bld;	
	char str[256]; //переменная для комманд
	try{
		//Инициализация данными о проекте
		stat = CHVKDbObject::Init();
		if(stat)
		{	int ID;
			stat = CHVKDbObject::m_ptrAdoRc->GetData("IdCity", CADORecord::Integer, &ID);
			m_pCity->SetID(ID);
		}
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("Author", CADORecord::String, m_Author);
		if(stat)
		{	int ID;
			stat = CHVKDbObject::m_ptrAdoRc->GetData("IdClientParty", CADORecord::Integer, &ID);
			m_pClientParty->SetID(ID);
		}
		if(stat)
		{	int ID;
			stat = CHVKDbObject::m_ptrAdoRc->GetData("IdAuthorParty", CADORecord::Integer, 
								  &ID);
			m_pAuthorParty->SetID(ID);
		}
		// Инициализация данными о городе
		m_pCity->InitByID();
		// Инициализация данными о клиентской организации
		m_pClientParty->InitByID();
		// Инициализация данными о нашей организации (исполнитель)
		m_pAuthorParty->InitByID();
		CADORecord* ptrAdoRc_sv = CHVKDbObject::m_ptrAdoRc;
		CHVKDbObject::m_ptrAdoRc = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
		//Создание списка зданий
		//Текст запроса для выборки таблицы зданий
		sprintf(str, "select * from building where idProject=%d", m_ID);
		if(!CHVKDbObject::m_ptrAdoRc->Open(str)) return FALSE;
		if(!(*CHVKDbObject::m_ptrAdoRc)->BOF) 
			(*CHVKDbObject::m_ptrAdoRc)->MoveFirst();
		if((*CHVKDbObject::m_ptrAdoRc)->EndOfFile && (*CHVKDbObject::m_ptrAdoRc)->BOF)
			stat = FALSE;
		if(stat)
			do
			{
				bld = new CBuilding(this);
				if(bld)
					stat = bld->Init();
					m_pBuildingVect.push_back(bld);
					(*CHVKDbObject::m_ptrAdoRc)->MoveNext();
			}while(!(*CHVKDbObject::m_ptrAdoRc)->EndOfFile/* && stat*/);
		(*CHVKDbObject::m_ptrAdoRc)->Close();
		delete CHVKDbObject::m_ptrAdoRc;
		CHVKDbObject::m_ptrAdoRc = ptrAdoRc_sv;
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}
	return stat;
}
//---------------------------------------------------------------------------
int CProject::Delete()
{
	m_pBuildingVect.DeleteAll();
	return CHVKDbObject::Delete();
}
//---------------------------------------------------------------------------
int CProject::ShowInFrmView(CIfcFormView* FrmView)
{
	FrmView->ShowProject(this);
	return TRUE;
};
//---------------------------------------------------------------------------
int CProject::HideInFrmView(CIfcFormView* FrmView)
{
	FrmView->HideProject(this);
	return TRUE;
};
//---------------------------------------------------------------------------
int CProject::ShowInTreeView(CIfcTreeView* pTreeView , HTREEITEM hParent/*= TVI_ROOT*/)
{
	HTREEITEM Parent = pTreeView->InsertObject(this);
	pTreeView->ShowVector(&m_pBuildingVect, Parent);
//	pTreeView->m_TreeCtrl.SelectItem(pTreeView->m_TreeCtrl.GetRootItem());
	return TRUE;
}
//---------------------------------------------------------------------------
static int SelPrj(void* Prm)
{
	CIfcDialog* pDlg = static_cast<CIfcDialog*>(Prm);
	CIfcComboBox* Cbb = dynamic_cast<CIfcComboBox*>(pDlg->m_pObjArr[0]);
	if(Cbb->GetCurSel()!=CB_ERR )
	{	pDlg->HideData(0);
		pDlg->PostMessage(WM_CLOSE, NULL, NULL);
	}
	return TRUE;
}
//---------------------------------------------------------------------------
int CProject::SelectPrj(CIfcTreeView* pShowTrView)
{
	CIfcDialog Dlg(NULL, 20, 20, 500, 200);
	CADORecord* AdoRcPrj = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
	char str[256];
	// Инициализация данными о типах ограждения
	//Текст запроса для выборки типов ограждения
	sprintf(str, "select * from Project Order By Name");
	if(!AdoRcPrj->Open(str)) return FALSE;

	Dlg.m_pObjArr[Dlg.m_NumObj] = new CIfcComboBox(
		&CIfcValue((void*)m_Name, CIfcValue::String, "Выберите проект"), 
		AdoRcPrj, 20, 40, this,
		Dlg.m_dx-40, _H,20, 20, Dlg.m_dx-40, _H);
	(static_cast<CIfcComboBox*>(Dlg.m_pObjArr[Dlg.m_NumObj]))->SetCanCreateNew(TRUE);
	Dlg.m_NumObj++;
	Dlg.m_pObjArr[Dlg.m_NumObj] = new CIfcButton(
		"OK", 20, Dlg.m_dy-40-1.5*_H,
		BtnFunct(SelPrj, &Dlg), Dlg.m_dx-40 , 1.5*_H);
	Dlg.m_NumObj++;

	Dlg.DoModal();
	(*AdoRcPrj)->Close();
	delete AdoRcPrj;
	SetSvPrj();
	pShowTrView->ShowProject(this);
	return TRUE;
}
//---------------------------------------------------------------------------
static int NewPrj(void* Prm)
{
	CIfcDialog* pDlg = static_cast<CIfcDialog*>(Prm);
	pDlg->HideData(0);
	pDlg->PostMessage(WM_CLOSE, NULL, NULL);
	return TRUE;
}
//---------------------------------------------------------------------------
int CProject::CreateNew()
{
/*	CIfcDialog Dlg(NULL, 20, 20, 500, 200);
	Dlg.m_pObjArr[Dlg.m_NumObj] = new CIfcEdit(
		&CIfcValue((void*)this->m_Name, CIfcValue::String, "Название проекта"), 
		20, 40, Dlg.m_dx-40, _H, 
		20, 20, Dlg.m_dx-40, _H, FALSE);
	Dlg.m_NumObj++;

	Dlg.m_pObjArr[Dlg.m_NumObj] = new CIfcButton(
		"OK", 20, Dlg.m_dy-40-2*_H,
		BtnFunct(NewPrj, &Dlg), Dlg.m_dx-40 , 2*_H);
	Dlg.m_NumObj++;

	Dlg.DoModal();*/
	Save(TRUE);
	return TRUE;
}
//---------------------------------------------------------------------------
int CProject::SavePrj(CIfcWnd* pWnd)
{
	pWnd->UpdtData(FALSE);
	Save();
	SetSvPrj();
	return TRUE;
}
//---------------------------------------------------------------------------
int CProject::ClosePrj(CIfcWnd* pWnd)
{
	if(m_pCurrObj)
		pWnd->UpdtData();
	if(IsChangePrj())
		if(MessageBox(NULL, "Сохранить изменения проекта?",
			  "Данные были изменены", MB_YESNO|MB_ICONQUESTION)==IDYES)
			Save();
		else
		{	SetSvPrj();
		 	Delete();	//пока так, а потом все изменения внести в транзакцию
			Save(TRUE);
		}
	if(m_pCurrObj)
		m_pCurrObj->HideInFrmView((CIfcFormView*)pWnd);	
	return TRUE;
}
//---------------------------------------------------------------------------
int CProject::Save(int IsNew/* = FALSE*/)
{
	try{
		_bstr_t bstrEmpty(L"");
		_variant_t  vtEmpty (DISP_E_PARAMNOTFOUND, VT_ERROR);
		//создать объект Command
		char str[256];
		_CommandPtr ptrCmd;
		ptrCmd.CreateInstance(__uuidof(Command));
		ptrCmd->ActiveConnection=CHVKDbObject::m_ptrAdoRc->m_ptrConnection;
		if(!IsNew){
			ptrCmd->CommandText=L"update project set Name='";
			ptrCmd->CommandText+=(const char*)m_Name;
			ptrCmd->CommandText+=L"', IdClientParty=";
			sprintf(str, "%d", m_pClientParty->m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", IdAuthorParty=";
			sprintf(str, "%d", m_pAuthorParty->m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", IdCity=";
			sprintf(str, "%d", m_pCity->m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L" where id=";
			sprintf(str, "%d", m_ID);
			ptrCmd->CommandText+=(const char*)str;
		}
		else{
			ptrCmd->CommandText=L"insert into project ";
			ptrCmd->CommandText+=L"(Name, Id, IdClientParty, IdAuthorParty, IdCity) VALUES ('";
			ptrCmd->CommandText+=(const char*)m_Name;
			ptrCmd->CommandText+=L"', ";
			sprintf(str, "%d", SetID());
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%d", m_pClientParty->m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%d", m_pAuthorParty->m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%d", m_pCity->m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L")";
		}
		ptrCmd->Execute(&vtEmpty, &vtEmpty, adCmdText);
		m_pBuildingVect.Save(IsNew);
		return TRUE;
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}
}
//---------------------------------------------------------------------------
CHVKDbObject* CProject::New()
{
	CBuilding* pBld = new CBuilding(this);
	pBld->Save(TRUE);
	m_pBuildingVect.push_back(pBld);
	return pBld;
}
//---------------------------------------------------------------------------
