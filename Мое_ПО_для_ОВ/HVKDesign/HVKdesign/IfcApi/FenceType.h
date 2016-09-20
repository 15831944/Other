// FenceType.h: interface for the CFenceType class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _FENCETYPE_H__
#define _FENCETYPE_H__

#include "HVKDbObject.h"
#include "FenceView.h"

class CFenceType:public CHVKDbObject
{
public:
	CFenceView m_FenceView;
	double m_TemperatureLag;
	double m_Length;
	double m_Height;
	double m_n;
public:
	CFenceType();
	virtual ~CFenceType();
	virtual int Init();
	int const& operator==(CFenceType const& op2);
};

#endif // !defined _FENCETYPE_H__
