// Room.cpp: implementation of the CRoom class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Project.h"
#include "Room.h"
#include "Fence.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CRoom* CRoom::Copy(CRoom const& op2)
{
	CHVKDbObject::Copy(op2);
	m_pFlr       = op2.m_pFlr;
	m_pFenceVect = op2.m_pFenceVect;
	m_pFenceVect.ChangeParent(this);

	m_Length     = op2.m_Length;
	m_Width      = op2.m_Width;
	m_Height     = op2.m_Height;
	m_V          = op2.m_V;

	m_TwzW = op2.m_TwzW;
	m_TwzS = op2.m_TwzS;
	m_TprW = op2.m_TprW;
	m_TprS = op2.m_TprS;
	m_ThzW = op2.m_ThzW;
	m_ThzS = op2.m_ThzS;
	m_TdW  = op2.m_TdW;
	m_TdS  = op2.m_TdS;

	m_VlwzW = op2.m_VlwzW;
	m_VlwzS = op2.m_VlwzS;
	m_VlprW = op2.m_VlprW;
	m_VlprS = op2.m_VlprS;
	m_VlhzW = op2.m_VlhzW;
	m_VlhzS = op2.m_VlhzS;
	m_VldW  = op2.m_VldW;
	m_VldS  = op2.m_VldS;

	m_LOutMechLoc  = op2.m_LOutMechLoc;			
	m_LOutMechGlob = op2.m_LOutMechGlob;			
	m_LOutTech     = op2.m_LOutTech;				
	m_LOutReal     = op2.m_LOutReal;				
	m_LOutSum      = op2.m_LOutSum;				
	m_Excretion    = op2.m_Excretion;			
	m_LOutExcr     = op2.m_LOutExcr;				
	m_LInMechLoc   = op2.m_LInMechLoc;			
	m_LInMechGlob  = op2.m_LInMechGlob;			
	m_LInTech      = op2.m_LInTech;				
	m_LInReal      = op2.m_LInReal;				
	m_LInSum       = op2.m_LInSum;				

	m_k = op2.m_k;					
	          
	m_QInTech    = op2.m_QInTech;				
	m_QInMath    = op2.m_QInMath;				
	m_QInSunRadS = op2.m_QInSunRadS;			
	m_QInSumW    = op2.m_QInSumW;				
	m_QInSumS    = op2.m_QInSumS;				
	             
	m_QOutFenceW   = op2.m_QOutFenceW;			
	m_QOutMathW    = op2.m_QOutMathW;				
	m_QOutAirHzW   = op2.m_QOutAirHzW;			
	m_QOutAirHzS   = op2.m_QOutAirHzS;			
	m_QOutAirTechW = op2.m_QOutAirTechW;			
	m_QOutAirTechS = op2.m_QOutAirTechS;			
	m_QOutAirLocW  = op2.m_QOutAirLocW;			
	m_QOutAirLocS  = op2.m_QOutAirLocS;			
	m_QOutSumW     = op2.m_QOutSumW;				
	m_QOutSumS     = op2.m_QOutSumS;				

	m_QOutFence5W = op2.m_QOutFence5W;			

	m_dQW = op2.m_dQW;					
	m_dQS = op2.m_dQS;					
	m_dqW = op2.m_dqW;					
	m_dqS = op2.m_dqS;					
	m_LdQW = op2.m_LdQW;					
	m_LdQS = op2.m_LdQS;					
	m_QLInW = op2.m_QLInW;					
	m_QInHeatingW = op2.m_QInHeatingW;			
	
	return this;
}
//---------------------------------------------------------------------------
CHVKDbObject* CRoom::Clone()
{
	CRoom* pObj = new CRoom(*this);
	return pObj;
}
//---------------------------------------------------------------------------
int CRoom::Distruct()
{
	return TRUE;
}
//---------------------------------------------------------------------------
CRoom::CRoom(CFloor* pFlr/* = NULL*/):m_pFlr(pFlr)
{
	strcpy(m_DbName, "room");

	m_Length = m_Width = 0;
	m_Height = m_pFlr->m_Height;
	m_V = 0;				
	m_TwzW = m_TwzS = 0;	
	m_TprW = m_TprS = 0;	
	m_ThzW = m_ThzS = 0;
	m_TdW = m_TdS = 0;

	m_VlwzW = m_VlwzS = 0;		
	m_VlprW = m_VlprS = 0;
	m_VlhzW = m_VlhzS = 0;		
	m_VldW = m_VldS = 0;

	m_LOutMechLoc = 0;
	m_LOutMechGlob = 0;			
	m_LOutTech = 0;				
	m_LOutReal =0;				
	m_LOutSum = 0;				
	m_LOutExcr = 0;				
	m_LInMechLoc = 0;			
	m_LInMechGlob = 0;			
	m_LInTech = 0;				
	m_LInReal = 0;				
	m_LInSum = 0;				
	m_k = 1;					
	
	m_QInTech = 0;				
	m_QInMath = 0;				
	m_QInSunRadS = 0;			
	m_QInSumW = 0;				
	m_QInSumS = 0;				

	m_QOutFenceW = 0;			
	m_QOutMathW = 0;			
	m_QOutAirHzW = m_QOutAirHzS = 0;			
	m_QOutAirTechW = m_QOutAirTechS = 0;
	m_QOutAirLocW = m_QOutAirLocS = 0;
	m_QOutSumW = m_QOutSumS = 0;

	m_QOutFence5W = 0;
	m_dQW = m_dQS = 0;
	m_dqW = m_dqS = 0;
	m_LdQW = m_LdQS = 0;
	m_QLInW = m_QInHeatingW = 0;
}
//---------------------------------------------------------------------------
CRoom::CRoom(CRoom const& op2):CHVKDbObject()
{
	strcpy(m_DbName, "room");
    Copy(op2);
}
//---------------------------------------------------------------------------
CRoom::~CRoom()
{
	Distruct();
}
//---------------------------------------------------------------------------
CRoom const& CRoom::operator=(CRoom const &op2)
{
	if(this == &op2 || *this == op2) return *this;
//	Delete();
	return *Copy(op2);
}
//---------------------------------------------------------------------------
int const& CRoom::operator==(CRoom const& op2)
{
	return (*(CHVKDbObject*)this == *(CHVKDbObject*)&op2 &&
			m_pFenceVect == op2.m_pFenceVect &&
			m_Length == op2.m_Length && m_Width == op2.m_Width &&
			m_Height == op2.m_Height && m_V     == op2.m_V     &&
			m_TwzW   == op2.m_TwzW   && m_TwzS  == op2.m_TwzS  &&
			m_TprW   == op2.m_TprW   && m_TprS  == op2.m_TprS  &&
			m_ThzW   == op2.m_ThzW   && m_ThzS  == op2.m_ThzS  &&
			m_TdW    == op2.m_TdW    && m_TdS   == op2.m_TdS   &&
			m_VlwzW  == op2.m_VlwzW  && m_VlwzS == op2.m_VlwzS &&
			m_VlprW  == op2.m_VlprW  && m_VlprS == op2.m_VlprS &&
			m_VlhzW  == op2.m_VlhzW  && m_VlhzS == op2.m_VlhzS &&
			m_VldW   == op2.m_VldW   && m_VldS  == op2.m_VldS  &&
			m_LOutMechLoc  == op2.m_LOutMechLoc  &&
			m_LOutMechGlob == op2.m_LOutMechGlob &&
			m_LOutTech     == op2.m_LOutTech     &&
			m_LOutReal     == op2.m_LOutReal     &&
			m_LOutSum      == op2.m_LOutSum      &&
			m_Excretion.IdCmp(op2.m_Excretion)   &&
			m_LOutExcr     == op2.m_LOutExcr     &&
			m_LInMechLoc   == op2.m_LInMechLoc   &&
			m_LInMechGlob  == op2.m_LInMechGlob  &&
			m_LInTech      == op2.m_LInTech      &&
			m_LInReal      == op2.m_LInReal      &&
			m_LInSum       == op2.m_LInSum       &&
			m_k == op2.m_k && 
			m_QInTech      == op2.m_QInTech      &&
			m_QInMath      == op2.m_QInMath      &&
			m_QInSunRadS   == op2.m_QInSunRadS   &&
			m_QInSumW      == op2.m_QInSumW      &&
			m_QInSumS      == op2.m_QInSumS      &&
			m_QOutFenceW   == op2.m_QOutFenceW   &&
			m_QOutMathW    == op2.m_QOutMathW    &&
			m_QOutAirHzW   == op2.m_QOutAirHzW   &&
			m_QOutAirHzS   == op2.m_QOutAirHzS   &&
			m_QOutAirTechW == op2.m_QOutAirTechW &&
			m_QOutAirTechS == op2.m_QOutAirTechS &&
			m_QOutAirLocW  == op2.m_QOutAirLocW  &&
			m_QOutAirLocS  == op2.m_QOutAirLocS  &&
			m_QOutSumW     == op2.m_QOutSumW     &&
			m_QOutSumS     == op2.m_QOutSumS     &&
			m_QOutFence5W  == op2.m_QOutFence5W  &&
			m_dQW   == op2.m_dQW   && m_dQS         == op2.m_dQS  &&
			m_dqW   == op2.m_dqW   && m_dqS         == op2.m_dqS  &&
			m_LdQW  == op2.m_LdQW  && m_LdQS        == op2.m_LdQS &&
			m_QLInW == op2.m_QLInW && m_QInHeatingW == op2.m_QInHeatingW);
}
//---------------------------------------------------------------------------
int const& CRoom::operator!=(CRoom const& op2)
{
  return !operator==(op2);
}
//---------------------------------------------------------------------------
int const& CRoom::CmpObj(CHVKDbObject* op2)
{
	return operator==(*(CRoom*)op2);
}
//---------------------------------------------------------------------------
int CRoom::Open(_ConnectionPtr ptrCon /*= NULL*/)
{
	return TRUE;
}
//---------------------------------------------------------------------------
int CRoom::Init()
{
	int stat = TRUE;
	CFence* pFnc;	
	char str[256]; //переменная для комманд
	try{
		//Инициализация данными о комнате
		CADORecord ptrAdoRc(*CHVKDbObject::m_ptrAdoRc);
		stat = CHVKDbObject::Init();
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("Length", CADORecord::Double, &m_Length);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("Width", CADORecord::Double, &m_Width);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("Height", CADORecord::Double, &m_Height);
		CalcV();
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("TwzW", CADORecord::Double, &m_TwzW);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("TwzS", CADORecord::Double, &m_TwzS);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("TprW", CADORecord::Double, &m_TprW);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("TprS", CADORecord::Double, &m_TprS);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("ThzW", CADORecord::Double, &m_ThzW);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("ThzS", CADORecord::Double, &m_ThzS);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("TdW", CADORecord::Double, &m_TdW);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("TdS", CADORecord::Double, &m_TdS);

		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("VlwzW", CADORecord::Double, &m_VlwzW);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("VlwzS", CADORecord::Double, &m_VlwzS);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("VlprW", CADORecord::Double, &m_VlprW);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("VlprS", CADORecord::Double, &m_VlprS);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("VlhzW", CADORecord::Double, &m_VlhzW);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("VlhzS", CADORecord::Double, &m_VlhzS);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("VldW", CADORecord::Double, &m_VldW);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("VldS", CADORecord::Double, &m_VldS);

		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("LOutMechLoc", CADORecord::Double, &m_LOutMechLoc);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("LOutMechGlob", CADORecord::Double, &m_LOutMechGlob);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("LOutTech", CADORecord::Double, &m_LOutTech);
/*		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("LOutReal", CADORecord::Double, &m_LOutReal);
*/		CalcLOutReal();
		CalcLOutSum();
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("LInMechLoc", CADORecord::Double, &m_LInMechLoc);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("LInMechGlob", CADORecord::Double, &m_LInMechGlob);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("LInTech", CADORecord::Double, &m_LInTech);
/*		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("LInReal", CADORecord::Double, &m_LInReal);
*/		CalcLInReal();
		CalcLInSum();
		CalcK();
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("QInTech", CADORecord::Double, &m_QInTech);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("QInMath", CADORecord::Double, &m_QInMath);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("QInSunRadS", CADORecord::Double, &m_QInSunRadS);
		CalcQInSumW();
		CalcQInSumS();
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("QOutFenceW", CADORecord::Double, &m_QOutFenceW);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("QOutMathW", CADORecord::Double, &m_QOutMathW);
		CalcQOutAirHzW();
		CalcQOutAirTechW();
		CalcQOutAirLocW();

/*		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("QOutAirHzW", CADORecord::Double, &m_QOutAirHzW);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("QOutAirTechW", CADORecord::Double, &m_QOutAirTechW);
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("QOutAirLocW", CADORecord::Double, &m_QOutAirLocW);
*/		CalcQOutSum();
		CalcdQW();
		CalcdQS();
		CalcdqW();
		CalcdqS();
		CalcLdQW();
		CalcLdQS();
		CalcQLInW();
		CalcQInHeatingW();
		if(stat)
			stat = CHVKDbObject::m_ptrAdoRc->GetData("QOutFence5W", CADORecord::Double, &m_QOutFence5W);

		if(stat)
		{	int ID;
			stat = CHVKDbObject::m_ptrAdoRc->GetData("IdDustGasExcretion", 
										CADORecord::Integer, &ID);
			m_Excretion.SetID(ID);
		}
		//Создание списка ограждений
		//Текст запроса для выборки таблицы ограждений
		CADORecord* ptrAdoRc_sv = CHVKDbObject::m_ptrAdoRc;
		CHVKDbObject::m_ptrAdoRc = new CADORecord(CHVKDbObject::m_ptrAdoRc->m_ptrConnection);
		sprintf(str, "select * from fence where Idroom=%d", m_ID);
		if(!CHVKDbObject::m_ptrAdoRc->Open(str)) stat = FALSE;
		if(!(*CHVKDbObject::m_ptrAdoRc)->BOF) 
			(*CHVKDbObject::m_ptrAdoRc)->MoveFirst();
		if((*CHVKDbObject::m_ptrAdoRc)->EndOfFile && (*CHVKDbObject::m_ptrAdoRc)->BOF)
			stat = FALSE;
		if(stat)
			do
			{
				pFnc = new CFence(this);
				if(pFnc)
					stat = pFnc->Init();
				m_pFenceVect.push_back(pFnc);
				(*CHVKDbObject::m_ptrAdoRc)->MoveNext();
			}while(!(*CHVKDbObject::m_ptrAdoRc)->EndOfFile/* && stat*/);
		(*CHVKDbObject::m_ptrAdoRc)->Close();
		delete CHVKDbObject::m_ptrAdoRc;
		CHVKDbObject::m_ptrAdoRc = ptrAdoRc_sv;
		GetSumFenceHeatLoss();
		// Инициализация данными о вредностях
		m_Excretion.InitByID();
		m_TprS = m_pFlr->m_pBld->m_pPrj->m_pCity->m_TempHeatSeason;

	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}
	return stat;
}
//---------------------------------------------------------------------------
int CRoom::ShowInFrmView(CIfcFormView* FrmView)
{
//	CMainFrame* pFrame = static_cast<CMainFrame*>(AfxGetMainWnd());
//	pFrame->ChangeView(1, 0, RUNTIME_CLASS(CRoomFrmView));
	FrmView->ShowRoom(this);
	return TRUE;
}
//---------------------------------------------------------------------------
int CRoom::HideInFrmView(CIfcFormView* FrmView)
{
//	CMainFrame* pFrame = static_cast<CMainFrame*>(AfxGetMainWnd());
//	pFrame->ChangeView(1, 0, RUNTIME_CLASS(CMainView));
	FrmView->HideRoom(this);
	return TRUE;
}
//---------------------------------------------------------------------------
int CRoom::ShowInTreeView(CIfcTreeView* pTreeView , HTREEITEM hParent/*= TVI_ROOT*/)
{
  pTreeView->ShowVector(&m_pFenceVect, hParent);
  return TRUE;
}
//---------------------------------------------------------------------------
double CRoom::GetSumFenceHeatLoss()
{
	m_QOutFenceW = 0;
	for(int i=0; i<m_pFenceVect.size(); i++)
		m_QOutFenceW  += (dynamic_cast<CFence*>(m_pFenceVect[i]))->m_HeatLoss;
	return m_QOutFenceW;
}
//---------------------------------------------------------------------------
double CRoom::CalcSumFenceHeatLoss()
{
	CFence* pFnc;
	m_QOutFenceW = 0;
	for(int i=0; i<m_pFenceVect.size(); i++)
	{	pFnc = dynamic_cast<CFence*>(m_pFenceVect[i]);
		pFnc->CalcHeatLoss();
		m_QOutFenceW  += pFnc->m_HeatLoss;
	}
	return m_QOutFenceW;
}
//---------------------------------------------------------------------------
double CRoom::CalcV()
{
	return m_V = m_Length*m_Width*m_Height;
}
//---------------------------------------------------------------------------
double CRoom::CalcLOutReal()
{
	return m_LOutReal = m_V;
}
//---------------------------------------------------------------------------
double CRoom::CalcLInReal()
{
	return m_LInReal = m_V;
}
//---------------------------------------------------------------------------
double CRoom::CalcLOutSum()
{
	return m_LOutSum = m_LOutMechLoc + m_LOutMechGlob + m_LOutTech + m_LOutReal;
}
//---------------------------------------------------------------------------
double CRoom::CalcLInSum()
{
	return m_LInSum = m_LInMechLoc + m_LInMechGlob+ m_LInTech + m_LInReal;
}
//---------------------------------------------------------------------------
double CRoom::CalcK()
{
	if(!m_V) m_k = 1;
	else m_k = m_LOutSum/m_V;
	return m_k;
}
//---------------------------------------------------------------------------
double CRoom::CalcQInSumW()
{
	return m_QInSumW = m_QInTech+ m_QInMath;
}
//---------------------------------------------------------------------------
double CRoom::CalcQInSumS()
{
	return m_QInSumS = m_QInTech+ m_QInMath + m_QInSunRadS;
}
//---------------------------------------------------------------------------
double CRoom::CalcQOutSum()
{
	return m_QOutSumW = m_QOutFenceW + m_QOutMathW + m_QOutAirHzW + m_QOutAirTechW + m_QOutAirLocW;
}
//---------------------------------------------------------------------------
double CRoom::CalcdQW()
{
	return m_dQW = m_QOutSumW - m_QInSumW;
}
//---------------------------------------------------------------------------
double CRoom::CalcdQS()
{
	return m_dQS = m_QInSumS;
}
//---------------------------------------------------------------------------
double CRoom::CalcdqW()
{
	if(!m_V) m_dqW = 0;
	else m_dqW = m_dQW / m_V;
	if(m_dqW<0) m_dqW = -m_dqW;
	return m_dqW;
}
//---------------------------------------------------------------------------
double CRoom::CalcdqS()
{
	if(!m_V) m_dqS = 0;
	else m_dqS = m_dQS / m_V; 
	return m_dqS;
}
//---------------------------------------------------------------------------
double CRoom::CalcLdQW()
{	m_LdQW = 0;
	if(m_dQW>0 && m_ThzW > m_TprW)
		m_LdQW = m_dQW / (0.24*1.2*(m_ThzW - m_TprW));
	return m_LdQW;
}
//---------------------------------------------------------------------------
double CRoom::CalcLdQS()
{	m_LdQS = 0;
	if(m_dQS>0 && m_ThzS > m_TprS)
		m_LdQS = m_dQS / (0.24*1.2*(m_ThzS - m_TprS));
	return m_LdQS;
}
//---------------------------------------------------------------------------
double CRoom::CalcQLInW()
{
	return m_QLInW = 0.21*1.2*(m_TprW - m_TwzW)*m_LInSum;
}
//---------------------------------------------------------------------------
double CRoom::CalcQInHeatingW()
{
	m_QInHeatingW = 0;
	if(m_dQW>0)
		m_QInHeatingW = m_dQW - m_QLInW;
	return m_QInHeatingW; 
}
//---------------------------------------------------------------------------
double CRoom::CalcQOutAirHzW()
{
	return m_QOutAirHzW = m_LOutMechGlob*
		0.24*1.2*(m_ThzW - m_pFlr->m_pBld->m_pPrj->m_pCity->m_MinTempHeatingSeason);
}
//---------------------------------------------------------------------------
double CRoom::CalcQOutAirTechW()
{
	return m_QOutAirTechW = m_LOutTech*
		0.24*1.2*(m_TwzW - m_pFlr->m_pBld->m_pPrj->m_pCity->m_MinTempHeatingSeason);
}
//---------------------------------------------------------------------------
double CRoom::CalcQOutAirLocW()
{
	return m_QOutAirLocW= m_LOutMechLoc*
		0.24*1.2*(m_TwzW - m_pFlr->m_pBld->m_pPrj->m_pCity->m_MinTempHeatingSeason);
}
/*
//---------------------------------------------------------------------------
double CRoom::CalcQOutAirHzS()
{
	return m_QOutAirHzS = m_LOutMechGlob*
		0.24*1.2*(m_ThzS - m_pFlr->m_pBld->m_pPrj->m_pCity->m_TempHeatSeason);
}
//---------------------------------------------------------------------------
double CRoom::CalcQOutAirTechS()
{
	return m_QOutAirTechS = m_LOutTech*
		0.24*1.2*(m_TwzS - m_pFlr->m_pBld->m_pPrj->m_pCity->m_TempHeatSeason);
}
//---------------------------------------------------------------------------
double CRoom::CalcQOutAirLocS()
{
	return m_QOutAirLocS= m_LOutMechGlob*
		0.24*1.2*(m_TwzS - m_pFlr->m_pBld->m_pPrj->m_pCity->m_TempHeatSeason);
}
*/
//---------------------------------------------------------------------------
int CRoom::Save(int IsNew/* = FALSE*/)
{
	try{
		_bstr_t bstrEmpty(L"");
		_variant_t  vtEmpty (DISP_E_PARAMNOTFOUND, VT_ERROR);
		//создать объект Command
		char str[256];
		_CommandPtr ptrCmd;
		ptrCmd.CreateInstance(__uuidof(Command));
		ptrCmd->ActiveConnection = CHVKDbObject::m_ptrAdoRc->m_ptrConnection;
		if(!IsNew){
			ptrCmd->CommandText  = L"update room set Name='";
			ptrCmd->CommandText += (const char*)m_Name;
			ptrCmd->CommandText += L"', Length=";
			sprintf(str, "%f", m_Length);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", Width=";
			sprintf(str, "%f", m_Width);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", Height=";
			sprintf(str, "%f", m_Height);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", TwzW=";
			sprintf(str, "%f", m_TwzW);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", TwzS="; 
			sprintf(str, "%f", m_TwzS);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", TprW=";
			sprintf(str, "%f", m_TprW);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", TprS=";
			sprintf(str, "%f", m_TprS);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", ThzW=";
			sprintf(str, "%f", m_ThzW);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", ThzS=";
			sprintf(str, "%f", m_ThzS);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", TdW=";
			sprintf(str, "%f", m_TdW);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", TdS=";
			sprintf(str, "%f", m_TdS);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", VlwzW=";
			sprintf(str, "%f", m_VlwzW);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", VlwzS=";
			sprintf(str, "%f", m_VlwzS);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", VlprW=";
			sprintf(str, "%f", m_VlprW);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", VlprS=";
			sprintf(str, "%f", m_VlprS);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", VlhzW=";
			sprintf(str, "%f", m_VlhzW);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", VlhzS=";
			sprintf(str, "%f", m_VlhzS);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", VldW=";
			sprintf(str, "%f", m_VldW);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", VldS=";
			sprintf(str, "%f", m_VldS);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", LOutMechLoc=";
			sprintf(str, "%f", m_LOutMechLoc);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", LOutMechGlob="; 
			sprintf(str, "%f", m_LOutMechGlob);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", LOutTech="; 
			sprintf(str, "%f", m_LOutTech);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", LInMechLoc="; 
			sprintf(str, "%f", m_LInMechLoc);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", LInMechGlob="; 
			sprintf(str, "%f", m_LInMechGlob);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", LInTech="; 
			sprintf(str, "%f", m_LInTech);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", QInTech="; 
			sprintf(str, "%f", m_QInTech);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", QInMath="; 
			sprintf(str, "%f", m_QInMath);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", QInSunRadS=";
			sprintf(str, "%f", m_QInSunRadS);
			ptrCmd->CommandText+= (const char*)str;
			ptrCmd->CommandText += L", QOutFenceW="; 
			sprintf(str, "%f", m_QOutFenceW);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", QOutMathW="; 
			sprintf(str, "%f", m_QOutMathW);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", QOutFence5W="; 
			sprintf(str, "%f", m_QOutFence5W);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L", IdDustGasExcretion=";
			sprintf(str, "%d", m_Excretion.m_ID);
			ptrCmd->CommandText += (const char*)str;
			ptrCmd->CommandText += L" where id=";
			sprintf(str, "%d", m_ID);
			ptrCmd->CommandText += (const char*)str;
		}
		else{
			ptrCmd->CommandText=L"insert into room ";
			ptrCmd->CommandText+=L"(Name, id, IdFloor, Length, Width, Height, TwzW, TwzS, TprW, TprS, ThzW, ";
			ptrCmd->CommandText+=L"ThzS, TdW, TdS, VlwzW, VlwzS, VlprW, VlprS, VlhzW, ";
			ptrCmd->CommandText+=L"VlhzS, VldW, VldS, LOutMechLoc, LOutMechGlob, LOutTech, ";
			ptrCmd->CommandText+=L"LInMechLoc, LInMechGlob, LInTech, QInTech, QInMath, ";
			ptrCmd->CommandText+=L"QInSunRadS, QOutFenceW, QOutMathW, QOutFence5W, IdDustGasExcretion) VALUES ('";
			ptrCmd->CommandText+=(const char*)m_Name;
			ptrCmd->CommandText+=L"', ";
			sprintf(str, "%d", SetID());
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%d", m_pFlr->m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_Length);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_Width);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_Height);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_TwzW);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_TwzS);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_TprW);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_TprS);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_ThzW);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_ThzS);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_TdW);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_TdS);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_VlwzW);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_VlwzS);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_VlprW);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_VlprS);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_VlhzW);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_VlhzS);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_VldW);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_VldS);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_LOutMechLoc);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_LOutMechGlob);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_LOutTech);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_LInMechLoc);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_LInMechGlob);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_LInTech);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_QInTech);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_QInMath);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_QInSunRadS);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_QOutFenceW);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_QOutMathW);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%f", m_QOutFence5W);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L", ";
			sprintf(str, "%d", m_Excretion.m_ID);
			ptrCmd->CommandText+=(const char*)str;
			ptrCmd->CommandText+=L")";
		}
		ptrCmd->Execute(&vtEmpty, &vtEmpty, adCmdText);
		m_pFenceVect.Save(IsNew);
		m_Excretion.Save(IsNew);
		return TRUE;
	}
	catch(_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
		return FALSE;
	}
}
//---------------------------------------------------------------------------
int CRoom::Delete()
{
	m_pFenceVect.DeleteAll();
	return CHVKDbObject::Delete();
}
//---------------------------------------------------------------------------
int CRoom::DeleteEx()
{
	if(m_pFlr)
		m_pFlr->m_pRoomVect.Delete(this);
	return Delete();
}
//---------------------------------------------------------------------------
void* CRoom::ChangeParent(void* pParent)
{
	CFloor* pFlr = static_cast<CFloor*>(pParent);
	if(m_pFlr)
		m_pFlr = pFlr;
	return m_pFlr;
}
//---------------------------------------------------------------------------
CHVKDbObject* CRoom::New()
{
	CFence* pFnc = new CFence(this);
	pFnc->Save(TRUE);
	m_pFenceVect.push_back(pFnc);
	return pFnc;
}
//---------------------------------------------------------------------------
int CRoom::Update()
{
	CalcV();
	CalcLOutReal();
	CalcLOutSum();
	CalcLInReal();
	CalcLInSum();
	CalcK();
	CalcQInSumW();
	CalcQInSumS();
	CalcQOutAirHzW();
	CalcQOutAirTechW();
	CalcQOutAirLocW();
	CalcQOutSum();
	CalcdQW();
	CalcdQS();
	CalcdqW();
	CalcdqS();
	CalcLdQW();
	CalcLdQS();
	CalcQLInW();
	CalcQInHeatingW();
	GetSumFenceHeatLoss();
	return TRUE;
	}
//---------------------------------------------------------------------------
