// HVKVector.cpp: implementation of the CHVKVector class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HVKVector.h"
#include "HVKDbObject.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CHVKVector* CHVKVector::Copy(CHVKVector const& op2)
{
	m_Vect.clear();
	for(int i = 0; i < op2.size(); i++)
		if(op2[i])
			m_Vect.push_back(op2[i]->Clone());
	return this;
}
//---------------------------------------------------------------------------
int CHVKVector::Distruct()
{
	for(int i = 0; i < m_Vect.size(); i++)
		if(m_Vect[i])
			delete m_Vect[i];
	m_Vect.clear();
	return TRUE;
}
//---------------------------------------------------------------------------
CHVKVector::CHVKVector()
{
;
}
//---------------------------------------------------------------------------
CHVKVector::CHVKVector(CHVKVector const& op2)
{
	Copy(op2);
}
//---------------------------------------------------------------------------
CHVKVector::~CHVKVector()
{
	Distruct();
}
//---------------------------------------------------------------------------
int const& CHVKVector::IdCmp(CHVKVector const& op2)
{
	if(size() != op2.size()) return FALSE;
	for(int i=0; i<size(); i++)
		if(m_Vect[i]->m_ID != op2.m_Vect[i]->m_ID)
			return FALSE;
	return TRUE;
}
//---------------------------------------------------------------------------
int const& CHVKVector::operator==(CHVKVector const& op2)
{
	if(size() != (&op2)->size()) return FALSE;
	for(int i=0; i<size(); i++)
		if(!m_Vect[i]->CmpObj(op2.m_Vect[i]))
			return FALSE;
	return TRUE;
}
//---------------------------------------------------------------------------
int const& CHVKVector::operator!=(CHVKVector const& op2)
{
  return !operator==(op2);
}
//---------------------------------------------------------------------------
CHVKVector const& CHVKVector::operator=(CHVKVector const &op2)
{
	if(this==&op2 || *this == op2) return *this;
//	Delete();
	return *Copy(op2);
}
//---------------------------------------------------------------------------
int CHVKVector::Save(int IsNew/* = FALSE*/)
{
	for(int i = 0; i < m_Vect.size(); i++)
		if(m_Vect[i])
			m_Vect[i]->Save(IsNew);
	return TRUE;
}
//---------------------------------------------------------------------------
void CHVKVector::Delete(CHVKDbObject* pObj)
{
	vector<CHVKDbObject*>::iterator theIterator;
	//поиск   
	for(theIterator=m_Vect.begin();theIterator!=m_Vect.end(); theIterator++)
		if((*theIterator) == pObj)
		{	m_Vect.erase(theIterator);
			pObj->Delete();
			break;
		}
}
//---------------------------------------------------------------------------
void CHVKVector::DeleteAll()
{
	CHVKDbObject* pObj;
	for(int i = 0; i < m_Vect.size(); i++)
		if(m_Vect[i])
		{	pObj = m_Vect[i];
			Delete(pObj);
			delete pObj;
		}
}
//---------------------------------------------------------------------------
int CHVKVector::ChangeParent(void* pParent)
{
	for(int i = 0; i < m_Vect.size(); i++)
		if(m_Vect[i])
			m_Vect[i]->ChangeParent(pParent);
	return TRUE;
}
//---------------------------------------------------------------------------
