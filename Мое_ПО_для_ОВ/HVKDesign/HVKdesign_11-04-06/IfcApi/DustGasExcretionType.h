// DustGasExcretionType.h: interface for the CDustGasExcretionType class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DUSTGASEXCRETIONTYPE_H__C1058048_C124_43BC_9316_DA9BC178066B__INCLUDED_)
#define AFX_DUSTGASEXCRETIONTYPE_H__C1058048_C124_43BC_9316_DA9BC178066B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HVKDbObject.h"

class CDustGasExcretionType : public CHVKDbObject  
{
	double m_PDK;
public:
	CDustGasExcretionType();
	virtual ~CDustGasExcretionType();
	virtual int Init();
	int const& operator==(CDustGasExcretionType const& op2);

};

#endif // !defined(AFX_DUSTGASEXCRETIONTYPE_H__C1058048_C124_43BC_9316_DA9BC178066B__INCLUDED_)
