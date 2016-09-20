// RazdelZdanie.h: interface for the CRazdelZdanie class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RAZDELZDANIE_H__DE91489B_7246_4136_BB4C_A0982C2556CB__INCLUDED_)
#define AFX_RAZDELZDANIE_H__DE91489B_7246_4136_BB4C_A0982C2556CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Razdel.h"
#include "RazdelAnalog.h"
//#include "msword.h"

class CRazdelZdanie : public CRazdel  
{
//	char* Name;						    //название раздела
	CRazdelAnalog Analog;				//здание аналог
	double KoefNaRaznV;					//коефициент на разницу объемов
	double UdStoimost;					//стоимость еденицы измерения
	double SumStoimost;					//общая стоимость
//	static CRazdelZdanieDlg* m_Dlg;		//диалог для ввода инфы по разделу

public:
	static CRazdelZdanieDlg* m_Dlg;		//диалог для ввода инфы по разделу

	CRazdelZdanie();
	CRazdelZdanie(const CRazdelZdanie& razdel);
	CRazdelZdanie& operator=(CRazdelZdanie& razdel);
	CRazdelZdanie* Duplicate();

	void SetAnalog(CRazdelAnalog& analog);
	const CRazdelAnalog& GetAnalog()const;

	void SetKoefNaRaznV(double value);
	double GetKoefNaRaznV()const;

	void SetUdStoimost(double value);
	double GetUdStoimost()const;

	void SetSumStoimost(double value);
	double GetSumStoimost()const;

	void SetData();
	int GetData();

	void Write(::fstream& f);
	void Read(::fstream& f);

	friend istream & operator>>(istream& istrm, CRazdelZdanie& rz);
	friend ostream & operator<<(ostream& ostrm, CRazdelZdanie const& rz);

};

#endif // !defined(AFX_RAZDELZDANIE_H__DE91489B_7246_4136_BB4C_A0982C2556CB__INCLUDED_)
