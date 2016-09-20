// FenceView.h: interface for the CFenceView class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _FENCEVIEW_H__
#define _FENCEVIEW_H__

#include "HVKDbObject.h"

class CFenceView:public CHVKDbObject
{
	double m_koef;
public:
	CFenceView();
	virtual ~CFenceView();
	virtual int Init();
	int const& operator==(CFenceView const& op2);
};

#endif // !defined _FENCEVIEW_H__
