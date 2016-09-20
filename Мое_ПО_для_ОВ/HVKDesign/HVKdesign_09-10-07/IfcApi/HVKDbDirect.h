// HVKDbDirect.h: interface for the CHVKDbDirect class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _HVKDBDIRECT_H__
#define _HVKDBDIRECT_H__

class CHVKDbDirect  
{
	int m_NumFields;
	char* m_FieldsName;
public:
	CHVKDbDirect(int NumFields);
	virtual ~CHVKDbDirect();

};

#endif // !defined _HVKDBDIRECT_H__
