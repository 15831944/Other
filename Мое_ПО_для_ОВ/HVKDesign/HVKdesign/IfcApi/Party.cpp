// Party.cpp: implementation of the CParty class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Party.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CParty* CParty::Copy(CParty const& op2)
{
	CHVKDbObject::Copy(op2);
	strcpy(m_BossName, op2.m_BossName);
	m_IsAuthor = op2.m_IsAuthor;
	return this;
}
//---------------------------------------------------------------------------
CHVKDbObject* CParty::Clone()
{
	CParty* pObj = new CParty(*this);
	return pObj;
}
//---------------------------------------------------------------------------
int CParty::Distruct()
{
	return TRUE;
}
//---------------------------------------------------------------------------
CParty::CParty()
{
	strcpy(m_DbName, "party");
	strcpy(m_BossName, "");
	m_IsAuthor = false;
}
//---------------------------------------------------------------------------
CParty::CParty(CParty const& op2):CHVKDbObject()
{
	strcpy(m_DbName, "party");
    Copy(op2);
}
//---------------------------------------------------------------------------
CParty::~CParty()
{
	Distruct();
}
//---------------------------------------------------------------------------
int const& CParty::operator==(CParty const& op2)
{
/*	return (*(CHVKDbObject*)this == *(CHVKDbObject*)&op2 &&
			!strcmp(m_BossName, op2.m_BossName) &&
			m_IsAuthor == op2.m_IsAuthor);
*/
	int stat1, stat2, stat3;
	stat1 = *(CHVKDbObject*)this == *(CHVKDbObject*)&op2;
	stat2 = !strcmp(m_BossName, op2.m_BossName);
	stat3 = m_IsAuthor == op2.m_IsAuthor;
	return stat1&& stat2&&stat3;
}
//---------------------------------------------------------------------------
int const& CParty::operator!=(CParty const& op2)
{
  return !operator==(op2);
}
//---------------------------------------------------------------------------
CParty const& CParty::operator=(CParty const &op2)
{
	if(this == &op2 || *this == op2) return *this;
//	Delete();
	return *Copy(op2);
}
//---------------------------------------------------------------------------
int CParty::Save(int IsNew/* = FALSE*/)
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
			ptrCmd->CommandText=L"update party set Name='";
			ptrCmd->CommandText+=(const char*)m_Name;
			ptrCmd->CommandText+=L"',  where id=";
			sprintf(str, "%d", m_ID);
			ptrCmd->CommandText+=(const char*)str;
		}
		else{
			ptrCmd->CommandText=L"insert into party ";
			ptrCmd->CommandText+=L"(Name, ) VALUES ('";
			ptrCmd->CommandText+=(const char*)m_Name;
			ptrCmd->CommandText+=L"')";
		}
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
