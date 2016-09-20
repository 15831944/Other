// IfcValue.h: interface for the CIfcValue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IFCVALUE_H__CE3B187B_994C_488A_A01B_34093591EB31__INCLUDED_)
#define AFX_IFCVALUE_H__CE3B187B_994C_488A_A01B_34093591EB31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IfcApi.h"

class IFCAPI CIfcValue  
{
public:
	enum 
	{
		MaxSizeStr = 256,
	};
	enum
	{
		Integer,
		String,
		Double
	};
public:
	char  m_Capt[MaxSizeStr];
	void* m_pVal;
	int   m_ValType;
public:
	CIfcValue(){;};
	CIfcValue(void* pVal, int ValType, char* Capt = NULL);
	virtual ~CIfcValue();
	int GetValue(char* text, int* IsMsg = NULL);
	int SetValue(char* text);
};

#endif // !defined(AFX_IFCVALUE_H__CE3B187B_994C_488A_A01B_34093591EB31__INCLUDED_)
