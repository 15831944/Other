// RazdelAnalog.cpp: implementation of the CRazdelAnalog class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SmetaProject.h"
#include "RazdelAnalog.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRazdelAnalog::CRazdelAnalog()
{

}

CRazdelAnalog::CRazdelAnalog(const CRazdelAnalog& AnalogRazdel):
			   CRazdel(AnalogRazdel.GetName(),
					   AnalogRazdel.GetVsegoStstOborudov(),
					   AnalogRazdel.GetVsegoStstMontaga(),
				       AnalogRazdel.GetVsegoStstSantehRabot(),
					   AnalogRazdel.GetVsegoStstObshestrRabot())
{
	V = AnalogRazdel.GetV();
}

CRazdelAnalog* CRazdelAnalog::Duplicate()
{
	return new CRazdelAnalog(*this);
}

CRazdelAnalog&  CRazdelAnalog::operator=(const CRazdelAnalog& AnalogRazdel)
{
	if(this == &AnalogRazdel) return *this;
	delete this;
	*this = *(new CRazdelAnalog(AnalogRazdel));
	return *this;
}

void CRazdelAnalog::SetV(double Value)
{
	V = Value;
}

double CRazdelAnalog::GetV()const
{
	return V;
}

void CRazdelAnalog::Read(::fstream& f)
{
	((CRazdel*)this)->Read(f);
	f.read((char*) &V, sizeof(V));

}

void CRazdelAnalog::Write(::fstream& f)
{
	((CRazdel*)this)->Write(f);
	f.write((char*)&V, sizeof(V));

}

istream & operator>>(istream & istrm, CRazdelAnalog& ra)
{
	istrm>>*(CRazdel*)&ra>>ra.V;
    return istrm;
}

ostream & operator<<(ostream & ostrm, CRazdelAnalog const& ra)
{
	return ostrm<<*(CRazdel*)&ra<<" "<<ra.GetV();

}
