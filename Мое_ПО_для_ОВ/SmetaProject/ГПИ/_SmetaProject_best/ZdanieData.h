// ZdanieData.h: interface for the CZdanieData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZDANIEDATA_H__3978A746_FF39_47C8_8CFF_CBB2F289577C__INCLUDED_)
#define AFX_ZDANIEDATA_H__3978A746_FF39_47C8_8CFF_CBB2F289577C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string.h>
#include "RazdelZdanie.h"
#include "ZdanieResultsDlg.h"

#include <list>
using namespace std;

class CZdanieData  
{

protected:
	CString Name;							//название  здания
	double V;							//объем здания
	double	KoefNaRaznNaklRash;			//коефициент на разницу накладных расходов
	double	KoefPereschetOborud;		//коефициент для пересчета стоимости оборудования
										//в базе1991г к базе 2001г
	double	KoefPereschetCMR;			//коефициент для пересчета стоимости СМР
										//в базе1984г к базе 2001г
public:
	double SumVsegoStstOborudov;		//суммарная стоимость оборудвания
	double SumVsegoStstMontaga;			//суммарная стоимость монтажа
	double SumVsegoStstSantehRabot;		//суммарная стоимость сантехнических работ
	double SumVsegoStstObshestrRabot;	//суммарная стоимость общестроительных работ
	double SumStoimost;					//суммарная общая стоимость

protected:
	CString ProjectPath;	//путь проекта

public:
	CZdanieData();
	virtual ~CZdanieData();
	void Clear();

	void SetV(double value);
	double GetV();

	void SetName(const char* str);
	CString GetName();

	void SetKoefNaRaznNaklRash(double value);
	double GetKoefNaRaznNaklRash();

	void SetKoefPereschetOborud(double value);
	double GetKoefPereschetOborud();

	void SetKoefPereschetCMR(double value);
	double GetKoefPereschetCMR();

	void Write(::fstream& f);
	void Read(::fstream& f);

	friend ::istream & operator>>(::istream & istrm, CZdanieData& z);
	friend ::ostream & operator<<(::ostream & ostrm, CZdanieData const& z);
private:
	void Delete();

};

#endif // !defined(AFX_ZDANIEDATA_H__3978A746_FF39_47C8_8CFF_CBB2F289577C__INCLUDED_)
