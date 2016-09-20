// Razdel.h: interface for the CRazdel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RAZDEL_H__419BB299_653D_4491_B7F5_9A4B73B192FC__INCLUDED_)
#define AFX_RAZDEL_H__419BB299_653D_4491_B7F5_9A4B73B192FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RazdelZdanieDlg.h"


class CRazdel  
{
	char* Name;							//�������� ������
	double VsegoStstOborudov;			//����� ��������� �����������
	double VsegoStstMontaga;			//����� ��������� �������
	double VsegoStstSantehRabot;		//����� ��������� �������������� �����
	double VsegoStstObshestrRabot;		//����� ��������� ���������������� �����

public:
	CRazdelZdanieDlg m_InptDlg;			//������ ��� ����� ���� �� ������
	CRazdel();
	CRazdel(char*, double, double, double, double);
	CRazdel(CRazdel& razdel);
	CRazdel* Duplicate();
	void Delete();
	~CRazdel();

	CRazdel&  operator=(CRazdel& razdel);

	void SetName(const char* str);
	char* GetName()const;

	void SetVsegoStstOborudov(double Value);
	double GetVsegoStstOborudov()const;
	
	void SetVsegoStstMontaga(double Value);
	double GetVsegoStstMontaga()const;
	
	void SetVsegoStstSantehRabot(double Value);
	double GetVsegoStstSantehRabot()const;
	
	void SetVsegoStstObshestrRabot(double Value);
	double GetVsegoStstObshestrRabot()const;

	friend istream & operator>>(istream& istrm, CRazdel& r);
	friend ostream & operator<<(ostream& ostrm, CRazdel const& r);

};

#endif // !defined(AFX_RAZDEL_H__419BB299_653D_4491_B7F5_9A4B73B192FC__INCLUDED_)
