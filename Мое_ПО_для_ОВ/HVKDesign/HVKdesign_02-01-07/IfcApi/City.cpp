// City.cpp: implementation of the CCity class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "HVKDbObject.h"
#include "City.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCity::CCity()
{
	strcpy(m_DbName, "city");
	m_MinTempHeatingSeason = 0;
	m_MiddleTempHeatingSeason = 0;
	m_MiddleTempCoolMounth = 0;
	m_TempHeatSeason = 0;
	m_HeatingSeasonLen = 0;
	m_WindSpeed = 0;
}

CCity::~CCity()
{

}

int CCity::Init()
{
	int stat;
	stat  = CHVKDbObject::Init();
	if(stat)
		stat = CHVKDbObject::m_ptrAdoRc->GetData("MinTempHeatingSeason", CADORecord::Double,
							 &m_MinTempHeatingSeason);
	if(stat)
		stat = CHVKDbObject::m_ptrAdoRc->GetData("MiddleTempHeatingSeason", CADORecord::Double,
							 &m_MiddleTempHeatingSeason);
	if(stat)
		stat = CHVKDbObject::m_ptrAdoRc->GetData("MiddleTempCoolMounth", CADORecord::Double, 
							 &m_MiddleTempCoolMounth);
	if(stat)
		stat = CHVKDbObject::m_ptrAdoRc->GetData("TempHeatSeason", CADORecord::Double, 
							 &m_TempHeatSeason);
	if(stat)
		stat = CHVKDbObject::m_ptrAdoRc->GetData("HeatingSeasonLen", CADORecord::Integer,
							 &m_HeatingSeasonLen);
	if(stat)
		stat = CHVKDbObject::m_ptrAdoRc->GetData("WindSpeed", CADORecord::Double,
							 &m_WindSpeed);
	return stat;
}
/*
int CCity::InitByID()
{
	int stat;
	char str[256];
	CreateOpenStrID(str);
	if(!CHVKDbObject::m_ptrAdoRc->Open(str)) return FALSE;
	stat  = Init();
	(*CHVKDbObject::m_ptrAdoRc)->Close();
	return stat;
}

int CCity::InitByName()
{
	int stat;
	char str[256];
	CreateOpenStrName(str);
	if(!CHVKDbObject::m_ptrAdoRc->Open(str)) return FALSE;
	stat  = Init();
	(*CHVKDbObject::m_ptrAdoRc)->Close();
	return stat;
}
*/
int const& CCity::operator==(CCity const& op2)
{
	return (*(CHVKDbObject*)this == *(CHVKDbObject*)&op2 &&
			m_MinTempHeatingSeason == op2.m_MinTempHeatingSeason &&
			m_MiddleTempHeatingSeason == op2.m_MiddleTempHeatingSeason &&
			m_MiddleTempCoolMounth == op2.m_MiddleTempCoolMounth &&
			m_TempHeatSeason == op2.m_TempHeatSeason &&
			m_HeatingSeasonLen == op2.m_HeatingSeasonLen &&
			m_WindSpeed == op2.m_WindSpeed);
}
