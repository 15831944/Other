// Orient.h: interface for the COrient class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _WORLDSIDE_H__
#define _WORLDSIDE_H__

#include "HVKDbObject.h"

class CWorldSide:public CHVKDbObject
{
public:
	double m_koef;
public:
	CWorldSide();
	virtual ~CWorldSide();
	virtual int Init();
	int const& operator==(CWorldSide const& op2);

};

#endif // !defined _WORLDSIDE_H__
