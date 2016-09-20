// Fence.cpp: implementation of the CFence class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Fence.h"
#include "Room.h"
#include "Project.h"
#include "../IfcApi/IfcFormView.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CFence* CFence::Copy(CFence const& op2)
{
	CHVKDbObject::Copy(op2);
	m_pRm = op2.m_pRm;
	m_FenceType = op2.m_FenceType;
	m_WorldSide = op2.m_WorldSide;
	m_Length = op2.m_Length;
	m_Height = op2.m_Height;
	m_HeatLoss = op2.m_HeatLoss;
	return this;
}
//---------------------------------------------------------------------------
CHVKDbObject* CFence::Clone()
{
	CFence* pObj = new CFence(*this);
	return pObj;
}
//---------------------------------------------------------------------------
int CFence::Distruct()
{
	return TRUE;
}
//---------------------------------------------------------------------------
CFence::CFence(CRoom* pRm/* = NULL*/):m_pRm(pRm)
{
	strcpy(m_DbName, "fence");
	m_Length = 0;
	m_Height = m_pRm->m_Height;
	m_HeatLoss = 0;

}
//---------------------------------------------------------------------------
CFence::CFence(CFence const& op2):CHVKDbObject()
{
	strcpy(m_DbName, "fence");
    Copy(op2);
}
//---------------------------------------------------------------------------
CFence::~CFence()
{
	Distruct();
}
//---------------------------------------------------------------------------
CFence const& CFence::operator=(CFence const &op2)
{
	if(this == &op2 || *this == op2) return *this;
//	Delete();
	return *Copy(op2);
}
//---------------------------------------------------------------------------
int const& CFence::operator==(CFence const& op2)
{
	return (*(CHVKDbObject*)this == *(CHVKDbObject*)&op2 &&
			m_FenceType.IdCmp(op2.m_FenceType) &&
			m_WorldSide.IdCmp(op2.m_WorldSide) &&
			m_Length   == op2.m_Length && 
			m_Height   == op2.m_Height &&
			m_HeatLoss == op2.m_HeatLoss);
}
//---------------------------------------------------------------------------
int const& CFence::operator!=(CFence const& op2)
{
  return !operator==(op2);
}
//---------------------------------------------------------------------------
int const& CFence::CmpObj(CHVKDbObject* op2)
{
	return operator==(*(CFence*)op2);
}
//---------------------------------------------------------------------------
int CFence::Open(_ConnectionPtr ptrCon /*= NULL*/)
{
	return TRUE;
}
//---------------------------------------------------------------------------
int CFence::Init()
{
	int stat = TRUE;
	try{
		//������������� ������� � ����������
		CADORecord ptrAdoRc(*CHVKDbObject::m_ptrAdoRc);
		stat = CHVKDbObject::Init();
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("Length", CADORecord::Double, &m_Length);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("Height", CADORecord::Double, &m_Height);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("HeatLoss", CADORecord::Double, &m_HeatLoss);
		if(stat)
		{	int ID;
			stat = CHVKDbObject::m_ptrAdoRc->GetData("IdFenceType", CADORecord::Integer, &ID);
			m_FenceType.SetID(ID);
		}
		m_FenceType.InitByID();
		if(stat)
		{	int ID;
			stat = CHVKDbObject::m_ptrAdoRc->GetData("IdWorldSide", CADORecord::Integer, &ID);
			m_WorldSide.SetID(ID);
		}
		m_WorldSide.InitByID();
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}

	return stat;
}
//---------------------------------------------------------------------------
int CFence::ShowInFrmView(CIfcFormView* FrmView)
{
	FrmView->ShowFence(this);
	return TRUE;
}
//---------------------------------------------------------------------------
int CFence::HideInFrmView(CIfcFormView* FrmView)
{
	FrmView->HideFence(this);
	return TRUE;
}
//---------------------------------------------------------------------------
int CFence::ShowInTreeView(CIfcTreeView* pTreeView , HTREEITEM hParent/*= TVI_ROOT*/)
{
//	pTreeView->ShowVector(&m_pRoomVect, hParent);
	return TRUE;
}
//---------------------------------------------------------------------------
int CFence::Save(int IsNew/* = FALSE*/)
{
	try{
		_bstr_t bstrEmpty(L"");
		_variant_t  vtEmpty (DISP_E_PARAMNOTFOUND, VT_ERROR);
		//������� ������ Command
		char str[256];
		_CommandPtr ptrCmd;
		ptrCmd.CreateInstance(__uuidof(Command));
		ptrCmd->ActiveConnection=CHVKDbObject::m_ptrAdoRc->m_ptrConnection;

		if(!IsNew){
			ptrCmd->CommandText=L"update fence set Name='";
			ptrCmd->CommandText+=(const char*)m_Name;
			ptrCmd->CommandText+=L"', IdFenceType=";
			sprintf(str, "%d", m_FenceType.m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", idWorldSide=";
			sprintf(str, "%d", m_WorldSide.m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", Length=";
			sprintf(str, "%f", m_Length);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", Height=";
			sprintf(str, "%f", m_Height);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", HeatLoss=";
			sprintf(str, "%f", m_HeatLoss);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L" where id=";
			sprintf(str, "%d", m_ID);
			ptrCmd->CommandText+=(const char*)str;
		}
		else{
			ptrCmd->CommandText=L"insert into fence ";
			ptrCmd->CommandText+=L"(Name, id, IdRoom, IdFenceType, idWorldSide, Length, Height, HeatLoss) VALUES ('";
			ptrCmd->CommandText+=(const char*)m_Name;
			ptrCmd->CommandText+=L"', ";
			sprintf(str, "%d", SetID());
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%d", m_pRm->m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%d", m_FenceType.m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%d", m_WorldSide.m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_Length);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_Height);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_HeatLoss);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L")";
		}
		CString Str = (char*)ptrCmd->CommandText;
		ptrCmd->Execute(&vtEmpty, &vtEmpty, adCmdText);
		return TRUE;
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}
}
//---------------------------------------------------------------------------
int CFence::Delete()
{
	return CHVKDbObject::Delete();
}
//---------------------------------------------------------------------------
int CFence::DeleteEx()
{
	if(m_pRm)
		m_pRm->m_pFenceVect.Delete(this);
	return Delete();
}
//---------------------------------------------------------------------------
void* CFence::ChangeParent(void* pParent)
{
	CRoom* pRm = static_cast<CRoom*>(pParent);
	if(m_pRm)
		m_pRm = pRm;
	return m_pRm;
}
//---------------------------------------------------------------------------
CHVKDbObject* CFence::New()
{
	return NULL;
}
//---------------------------------------------------------------------------
int CFence::CalcAdtnlHeatLoss()
{

//  	b - ���������� ������ ������� � ����� �� �������� ������, 
//  		������������ � ������������ �:
//  ���������� ������ �������   ����� ����������� ����������� 
//  ������� ��������� � ����� �� �������� ������:
//  �) � ���������� ������ ���������� ����� �������� ������������ � ���������
//     (������������ ��������) �����, ����� � ����, ���������� �� 
//  	    �����, ������, ������-������ � ������-����� � ������� 0,1, 
//  	    �� ���-������ � ����� - � ������� 0,05; 
//  !!! �������� ��� ��������� ������ �������/��������� (��� ���������)    
//  	� ������� ���������� ������������� - �� 0,05 �� ������ �����, ����� � ����, 
//  		���� ���� �� ���������� �������� ��  �����, ������, ������-������ � ������-����� 
//  	� 0,1 - � ������ �������;
//  !!! - ���� �� �����������!!!�) � ����������, ��������������� ��� �������� ��������������, ����� �����, ����� � ����, ���������� �� ����� �� ������ �����, � ������� 0,08 ��� ����� �������� ����� � 0,13 ��� ������� ��������� (����� �����), � �� ���� ����� ���������� - 0,13;
//  !!! - ���� �� �����������!!!�) ����� �������������� ���� ������� ����� ��� ��������� ���������� ������ � ���������� � ��������� ������������ ��������� ������� ����� 40  � � ���� (��������� �) - � ������� 0,05;
//  !!! - ���� �� �����������!!!�) ����� �������� �����, �� ������������� ���������� ��� ��������-��������� ��������, ��� ������ ������ H, �, �� ������� ������������� ������� ����� �� ����� �������, ������ �������� ��������� ������ ��� ����� ����� � �������:
//  !!! - ���� �� �����������!!!	0,2 H - ��� ������� ������ � ����� ��������� ����� ����;
//  !!! - ���� �� �����������!!!	0,27 H - ��� ������� ������ � ��������� ����� ����;
//  !!! - ���� �� �����������!!!	0,34 H - ��� ������� ������ ��� �������; 
//  !!! - ���� �� �����������!!!	0,22 H - ��� ��������� ������;
//  !!! - ���� �� �����������!!!�) ����� �������� ������, �� ������������� ���������� � ��������-��������� ��������, - � ������� 3 ��� ���������� ������� � � ������� 1 - ��� ������� ������� � �����.
//  !!! - ���� �� �����������!!!����������: ��� ������ � �������� �������� ������ � ����� ���������� ������ ������� �� ���������� "�" � "�" �� ������� ���������.

	double b = 1;
	return b;
}
//---------------------------------------------------------------------------
int CFence::CalcHeatLoss()
{
// ���� ������ ��� ����� � ��� ����� ��� ���� � ������, 
// ���� ������������� ���� � ����� :)))
	
//  (���� 2.04.05-91)
//  	�������� � ���������� ������ ������� ������� ���������� �������� ������ ������� 
//  ����� ��������� ����������� ����������� Q, ��, � ����������� �� 10 �� 
//  ��� ��������� �� �������:
//  	Q = A(tp-text)(1 + ����(b))n/R,
//  ��� � - ��������� ������� ����������� �����������, �2;
//  	R -	������������� ������������� ����������� �����������, �2 �/��. 
//  		������������� ������������� ����������� ������� ���������� 
//  		�� ���� II-3-7** (����� ����� �� ������);
//  		��� ����� �� ������ - � ������������ � �. 3 ���������� ����������, 
//  		�������� R = RC, ��� ������������ ����� � R = Rh ��� ����������;
//  	tp -��������� ����������� �������,  �, 
//  		� ��������� � ������ ��������� �� � ����������� �� ������ 
//  		��� ��������� ������� ����� 4 �; 
//  	texp -��������� ����������� ��������� ������� ��� ��������� ������� ����
//  		��� ������� ������ ������� ����� �������� ���������� 
//  		��� ����������� ������� ����� ��������� ���������-
//  		��� ������� ������ ������� ����� ���������� ����������;
//  	b - ���������� ������ ������� � ����� �� �������� ������;
//  	� -	�����������, ����������� � ����������� �� ��������� 
//  		�������� ����������� ����������� ����������� �� ��������� 
//  		� ��������� ������� �� ���� II-3-79**.

	double A    = m_Length * m_Height;
	double R    = m_FenceType.m_TemperatureLag;
	double texp = m_pRm->m_pFlr->m_pBld->m_pPrj->m_pCity->m_MiddleTempHeatingSeason;
	double tp   = m_pRm->m_TwzW;
	double b    = CalcAdtnlHeatLoss();
	double n    = m_FenceType.m_n;

	m_HeatLoss = A*(tp - texp)*(1+b)*n/R;
	return TRUE;
}
//---------------------------------------------------------------------------
