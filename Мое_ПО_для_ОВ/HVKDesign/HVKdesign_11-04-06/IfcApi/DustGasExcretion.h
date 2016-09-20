// DustGasExcretion.h: interface for the CDustGasExcretion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DUSTGASEXCRETION_H__DF19FB30_DCBF_45FF_ACB6_4E04535BB353__INCLUDED_)
#define AFX_DUSTGASEXCRETION_H__DF19FB30_DCBF_45FF_ACB6_4E04535BB353__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HVkApi.h"
#include "HVKDbObject.h"
#include "DustGasExcretionType.h"

class HVKAPI CDustGasExcretion:public CHVKDbObject
{
public:
	CDustGasExcretionType m_ExcretionType;
	double m_Size;		//количество
	double m_LAir;	//количество воздуха
public:
	CDustGasExcretion();
	virtual ~CDustGasExcretion();
	virtual int Init();
	void SetSize(double Size){m_Size = Size;};
	double GetSize(){return m_Size;};

	int const& operator==(CDustGasExcretion const& op2);
};

#endif // !defined(AFX_DUSTGASEXCRETION_H__DF19FB30_DCBF_45FF_ACB6_4E04535BB353__INCLUDED_)
