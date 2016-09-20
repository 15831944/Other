// ZdanieData.cpp: implementation of the CZdanieData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SmetaProject.h"
#include "ZdanieData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CZdanieData::CZdanieData()
{
	Name = "";
	V = -1;
	KoefNaRaznNaklRash  = -1;
	KoefPereschetOborud = -1;
	KoefPereschetCMR = -1;
}

CZdanieData::~CZdanieData()
{
	Delete();
}

void CZdanieData::Delete()
{
}

void CZdanieData::Clear()
{
	Name = "";
	V = -1;
	KoefNaRaznNaklRash  = -1;
	KoefPereschetOborud = -1;
	KoefPereschetCMR = -1;

}
void CZdanieData::SetV(double value)
{
	V = value;
}

double CZdanieData::GetV()
{
	return V;
}

void CZdanieData::SetName(const char* str)
{
	Name = str;
}

CString CZdanieData::GetName()
{
	return Name;
}

void CZdanieData::SetKoefNaRaznNaklRash(double value)
{
	KoefNaRaznNaklRash = value;
}

double CZdanieData::GetKoefNaRaznNaklRash()
{
	return KoefNaRaznNaklRash;
}

void CZdanieData::SetKoefPereschetOborud(double value)
{
	KoefPereschetOborud = value;
}

double CZdanieData::GetKoefPereschetOborud()
{
	return KoefPereschetOborud;
}

void CZdanieData::SetKoefPereschetCMR(double value)
{
	KoefPereschetCMR = value;
}

double CZdanieData::GetKoefPereschetCMR()
{
	return KoefPereschetCMR;
}

::istream & operator>>(::istream & istrm, CZdanieData& z)
{
	char s[256];
	istrm>>s;
	if(strcmp(s,"-1")) z.SetName(s); else z.Name = "";
	return istrm>>z.V>>z.KoefNaRaznNaklRash>>
				  z.KoefPereschetOborud>>z.KoefPereschetCMR;
}

::ostream & operator<<(::ostream & ostrm, CZdanieData const& z)
{
	if(z.Name=="") ostrm<<"-1"; else ostrm<<z.Name;
	return ostrm<<" "<<z.V<<" "<<z.KoefNaRaznNaklRash<<" "<<
				  z.KoefPereschetOborud<<" "<<z.KoefPereschetCMR;
}