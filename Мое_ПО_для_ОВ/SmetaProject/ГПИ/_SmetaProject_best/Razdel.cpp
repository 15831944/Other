// Razdel.cpp: implementation of the CRazdel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SmetaProject.h"
#include "Razdel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CRazdel::CRazdel()
{

}

CRazdel::CRazdel(CString _Name,
				 double _VsegoStstOborudov, double _VsegoStstMontaga, 
				 double _VsegoStstSantehRabot, double _VsegoStstObshestrRabot):
				 Name(_Name),
				 VsegoStstOborudov(_VsegoStstOborudov),
				 VsegoStstMontaga(_VsegoStstMontaga),
				 VsegoStstSantehRabot(_VsegoStstSantehRabot),
				 VsegoStstObshestrRabot(_VsegoStstObshestrRabot)
{
}

CRazdel::CRazdel(CRazdel& razdel)
{
	Name = razdel.GetName();
	VsegoStstObshestrRabot = razdel.GetVsegoStstObshestrRabot();
	VsegoStstOborudov = razdel.GetVsegoStstOborudov();
	VsegoStstMontaga = razdel.GetVsegoStstMontaga();
	VsegoStstSantehRabot = razdel.GetVsegoStstSantehRabot();
	VsegoStstObshestrRabot = razdel.GetVsegoStstObshestrRabot();
}

CRazdel* CRazdel::Duplicate()
{
	return new CRazdel(*this);
}


CRazdel&  CRazdel::operator=(CRazdel& razdel)
{
	if(this == &razdel) return *this;
	delete this;
	*this = *(new CRazdel(razdel));
	return *this;
}

void CRazdel::SetName(CString str)
{	
	Name = str;
}

CString CRazdel::GetName()const
{
	return Name;
}

void CRazdel::SetVsegoStstOborudov(double Value)
{
	VsegoStstOborudov = Value;
}

double CRazdel::GetVsegoStstOborudov()const
{
	return VsegoStstOborudov;
}

void CRazdel::SetVsegoStstMontaga(double Value)
{
	VsegoStstMontaga  = Value;
}

double CRazdel::GetVsegoStstMontaga()const
{
	return VsegoStstMontaga;
}

void CRazdel::SetVsegoStstSantehRabot(double Value)
{
	VsegoStstSantehRabot = Value;
}

double CRazdel::GetVsegoStstSantehRabot()const
{
	return VsegoStstSantehRabot;
}

void CRazdel::SetVsegoStstObshestrRabot(double Value)
{
	VsegoStstObshestrRabot = Value;
}

double CRazdel::GetVsegoStstObshestrRabot()const
{
	return VsegoStstObshestrRabot;
}

void CRazdel::Read(::fstream& f)
{
	char s[500];
	f.read(s, sizeof(s));
	Name = s;
	f.read((char*) &VsegoStstOborudov, sizeof(VsegoStstOborudov));
	f.read((char*) &VsegoStstMontaga, sizeof(VsegoStstMontaga));
	f.read((char*) &VsegoStstSantehRabot, sizeof(VsegoStstSantehRabot));
	f.read((char*) &VsegoStstObshestrRabot, sizeof(VsegoStstObshestrRabot));
}

void CRazdel::Write(::fstream& f)
{
	char s[500];
	strcpy(s, Name);
	f.write((char*) &s, sizeof(s));
	f.write((char*) &VsegoStstOborudov, sizeof(VsegoStstOborudov));
	f.write((char*) &VsegoStstMontaga, sizeof(VsegoStstMontaga));
	f.write((char*) &VsegoStstSantehRabot, sizeof(VsegoStstSantehRabot));
	f.write((char*) &VsegoStstObshestrRabot, sizeof(VsegoStstObshestrRabot));
}

istream & operator>>(istream & istrm, CRazdel& r)
{
	char str[500];
	istrm>>str;
	CString s = str;
	s.Replace("@@@", " ");
	r.SetName(s);
	return istrm>>r.VsegoStstOborudov>>r.VsegoStstMontaga>>
				  r.VsegoStstSantehRabot>>r.VsegoStstObshestrRabot;
}

ostream & operator<<(ostream & ostrm, CRazdel const& r)
{
	CString s;
	s = r.Name;
	s.Replace(" ", "@@@");
	return ostrm<<s<<" "<<r.VsegoStstOborudov<<" "
		        <<r.VsegoStstMontaga<<" "<<r.VsegoStstSantehRabot<<" "
				<<r.VsegoStstObshestrRabot;
}
