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
		//Инициализация данными о ограждении
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
		//создать объект Command
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

//  	b - добавочные потери теплоты в долях от основных потерь, 
//  		определяемые в соответствии с:
//  Добавочные потери теплоты   через ограждающие конструкции 
//  следует принимать в долях от основных потерь:
//  а) в помещениях любого назначения через наружные вертикальные и наклонные
//     (вертикальная проекция) стены, двери и окна, обращенные на 
//  	    север, восток, северо-восток и северо-запад в размере 0,1, 
//  	    на юго-восток и запад - в размере 0,05; 
//  !!! добавить для помещения флажек угловое/неугловое (или сомбобокс)    
//  	в угловых помещениях дополнительно - по 0,05 на каждую стену, дверь и окно, 
//  		если одно из ограждений обращено на  север, восток, северо-восток и северо-запад 
//  	и 0,1 - в других случаях;
//  !!! - пока не учитывается!!!б) в помещениях, разрабатываемых для типового проектирования, через стены, двери и окна, обращенные на любую из сторон света, в размере 0,08 при одной наружной стене и 0,13 для угловых помещений (кроме жилых), а во всех жилых помещениях - 0,13;
//  !!! - пока не учитывается!!!а) через необогреваемые полы первого этажа над холодными подпольями зданий в местностях с расчетной температурой наружного воздуха минус 40  С и ниже (параметры Б) - в размере 0,05;
//  !!! - пока не учитывается!!!г) через наружные двери, не оборудованные воздушными или воздушно-тепловыми завесами, при высоте зданий H, м, от средней планировочной отметки земли до верха карниза, центра вытяжных отверстий фонаря или устья шахты в размере:
//  !!! - пока не учитывается!!!	0,2 H - для тройных дверей с двумя тамбурами между ними;
//  !!! - пока не учитывается!!!	0,27 H - для двойных дверей с тамбурами между ними;
//  !!! - пока не учитывается!!!	0,34 H - для двойных дверей без тамбура; 
//  !!! - пока не учитывается!!!	0,22 H - для одинарных дверей;
//  !!! - пока не учитывается!!!д) через наружные ворота, не оборудованные воздушными и воздушно-тепловыми завесами, - в размере 3 при отсутствии тамбура и в размере 1 - при наличии тамбура у ворот.
//  !!! - пока не учитывается!!!Примечание: Для летних и запасных наружных дверей и ворот добавочные потери теплоты по подпунктам "г" и "д" не следует учитывать.

	double b = 1;
	return b;
}
//---------------------------------------------------------------------------
int CFence::CalcHeatLoss()
{
// Пока расчет как будто у нас стена без окон и дверей, 
// надо предусмотреть окна и двери :)))
	
//  (СНиП 2.04.05-91)
//  	Основные и добавочные потери теплоты следует определять суммируя потери теплоты 
//  через отдельные ограждающие конструкции Q, Вт, с округлением до 10 Вт 
//  для помещений по формуле:
//  	Q = A(tp-text)(1 + Сумм(b))n/R,
//  где А - расчетная площадь ограждающей конструкции, м2;
//  	R -	сопротивление теплопередаче ограждающей конструкции, м2 С/Вт. 
//  		Сопротивление теплопередаче конструкции следует определять 
//  		по СНиП II-3-7** (кроме полов на грунте);
//  		для полов на грунте - в соответствии с п. 3 настоящего приложения, 
//  		принимая R = RC, для неутепленных полос и R = Rh для утепленных;
//  	tp -расчетная температура воздуха,  С, 
//  		в помещении с учетом повышения ее в зависимости от высоты 
//  		для помещений высотой более 4 м; 
//  	texp -расчетная температура наружного воздуха для холодного периода года
//  		при расчете потерь теплоты через наружные ограждения 
//  		или температура воздуха более холодного помещения-
//  		при расчете потерь теплоты через внутренние ограждения;
//  	b - добавочные потери теплоты в долях от основных потерь;
//  	п -	коэффициент, принимаемый в зависимости от положения 
//  		наружной поверхности ограждающих конструкций по отношению 
//  		к наружному воздуху по СНиП II-3-79**.

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
