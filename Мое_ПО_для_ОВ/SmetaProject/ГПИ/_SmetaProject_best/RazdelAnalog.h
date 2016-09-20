// RazdelAnalog.h: interface for the CRazdelAnalog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RAZDELANALOG_H__5619698B_0AB4_4D82_B6A7_DF8E3B22A8FA__INCLUDED_)
#define AFX_RAZDELANALOG_H__5619698B_0AB4_4D82_B6A7_DF8E3B22A8FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Razdel.h"

class CRazdelAnalog : public CRazdel  
{
	double V;					//объем аналога

public:
	CRazdelAnalog();
	CRazdelAnalog(const CRazdelAnalog& r);
	CRazdelAnalog* Duplicate();
	CRazdelAnalog& operator=(const CRazdelAnalog& razdel);

	void SetV(double Value);
	double GetV()const;

	void Write(::fstream& f);
	void Read(::fstream& f);

	
	friend istream & operator>>(istream& istrm, CRazdelAnalog& ra);
	friend ostream & operator<<(ostream& ostrm, CRazdelAnalog const& ra);

};

#endif // !defined(AFX_RAZDELANALOG_H__5619698B_0AB4_4D82_B6A7_DF8E3B22A8FA__INCLUDED_)
