// Party.h: interface for the CParty class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _PARTY_H__
#define _PARTY_H__

#include "HVKDbObject.h"
#include "HVkApi.h"

class CParty:public CHVKDbObject
{
	char m_BossName[256];
	bool m_IsAuthor;
public:
	CParty* Copy(CParty const& op2);
	virtual CHVKDbObject* Clone();
	int Distruct();

	CParty();
	CParty(CParty const& op2);
	virtual ~CParty();

	int const& operator==(CParty const& op2);
	int const& operator!=(CParty const& op2);
	CParty const& operator=(CParty const &op2);

	char* GetBossName(){return m_BossName;};
	bool  IsAuthor(){return m_IsAuthor;};
	void SetBossName(char* Name){strcpy(m_BossName, Name);};
	void SetAuthor(bool IsAuthor){m_IsAuthor = IsAuthor;};
	virtual int Save(int IsNew = FALSE);
};

#endif // ndef _PARTY_H__
