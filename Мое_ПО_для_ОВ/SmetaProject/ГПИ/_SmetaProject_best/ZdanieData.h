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
	CString Name;							//��������  ������
	double V;							//����� ������
	double	KoefNaRaznNaklRash;			//���������� �� ������� ��������� ��������
	double	KoefPereschetOborud;		//���������� ��� ��������� ��������� ������������
										//� ����1991� � ���� 2001�
	double	KoefPereschetCMR;			//���������� ��� ��������� ��������� ���
										//� ����1984� � ���� 2001�
public:
	double SumVsegoStstOborudov;		//��������� ��������� �����������
	double SumVsegoStstMontaga;			//��������� ��������� �������
	double SumVsegoStstSantehRabot;		//��������� ��������� �������������� �����
	double SumVsegoStstObshestrRabot;	//��������� ��������� ���������������� �����
	double SumStoimost;					//��������� ����� ���������

protected:
	CString ProjectPath;	//���� �������

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
