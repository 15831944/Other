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
	Name = NULL;

}

CRazdel::CRazdel(char* _Name,
				 double _VsegoStstOborudov, double _VsegoStstMontaga, 
				 double _VsegoStstSantehRabot, double _VsegoStstObshestrRabot):
				 VsegoStstOborudov(_VsegoStstOborudov),
				 VsegoStstMontaga(_VsegoStstMontaga),
				 VsegoStstSantehRabot(_VsegoStstSantehRabot),
				 VsegoStstObshestrRabot(_VsegoStstObshestrRabot)
{
	Name = new char[strlen(_Name)+1];
	strcpy(Name, _Name);
}

CRazdel::CRazdel(CRazdel& razdel)
{
	const char *str = razdel.GetName();
	Name = new char[strlen(str)+1];
	strcpy(Name, str);
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

CRazdel::~CRazdel()
{
	Delete();
}

void CRazdel::Delete()
{
	if(Name)
	{	
	/*static i=0;
	i++;
	CString s;
	s.Format("Delete:  %s: %d",Name,i);
	AfxMessageBox(s);*/
	delete[] Name;
	}
}

CRazdel&  CRazdel::operator=(CRazdel& razdel)
{
	if(this == &razdel) return *this;
	delete this;
	*this = *(new CRazdel(razdel));
	return *this;
}

void CRazdel::SetName(const char* str)
{	
	if(Name) delete[] Name;
	Name = new char[strlen(str)+1]; 
/*
	static i=0;
	i++;
	CString s;
	s.Format("SetName:  %s: %d", str, i);
	AfxMessageBox(s);
*/
	strcpy(Name, str);
}

char* CRazdel::GetName()const
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

istream & operator>>(istream & istrm, CRazdel& r)
{
	char s[256];
	istrm>>s;
	r.SetName(s);
	return istrm>>r.VsegoStstOborudov>>r.VsegoStstMontaga>>
				  r.VsegoStstSantehRabot>>r.VsegoStstObshestrRabot;
}

ostream & operator<<(ostream & ostrm, CRazdel const& r)
{
	return ostrm<<r.Name<<" "<<r.VsegoStstOborudov<<" "
		        <<r.VsegoStstMontaga<<" "<<r.VsegoStstSantehRabot<<" "
				<<r.VsegoStstObshestrRabot;
}
