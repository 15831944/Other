// BuildingType.h: interface for the CBuildingType class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _BUILDINGTYPE_H__
#define _BUILDINGTYPE_H__

#include "HVkApi.h"
#include "HVKDbObject.h"

class CHVKDbObject;
class HVKAPI CBuildingType:public CHVKDbObject
{
double m_qo, m_qv;
public:
	CBuildingType();
	virtual ~CBuildingType();
	virtual int Init();
	int const& operator==(CBuildingType const& op2);
};

#endif // !defined _BUILDINGTYPE_H__
