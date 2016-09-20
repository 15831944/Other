// HVKVector.h: interface for the CHVKVector class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _HVKVECTOR_H__
#define _HVKVECTOR_H__

#include <vector>
using namespace std;

#include "HVKApi.h"

class CHVKDbObject;
class HVKAPI CHVKVector
{
	vector<CHVKDbObject*> m_Vect;
public:
	CHVKVector* Copy(CHVKVector const& op2);
	int Distruct();

	CHVKVector();
	CHVKVector(CHVKVector const& op2);
	virtual ~CHVKVector();

	int const& IdCmp(CHVKVector const& op2);
	virtual int const& operator==(CHVKVector const& op2);
	virtual int const& operator!=(CHVKVector const& op2);
	CHVKVector const& operator=(CHVKVector const &op2);
	CHVKDbObject* operator[](int i)const{return m_Vect[i];};

	void push_back(CHVKDbObject* Obj){m_Vect.push_back(Obj);};
	int size()const{return m_Vect.size();};
	void clear(){m_Vect.clear();};

	void Delete(CHVKDbObject* pObj);
	void DeleteAll();
	int ChangeParent(void* pParent);
	int Save(int IsNew = FALSE);
};

#endif // ndef _HVKVECTOR_H__
