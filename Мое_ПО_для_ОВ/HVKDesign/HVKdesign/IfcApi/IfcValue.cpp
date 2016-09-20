// IfcValue.cpp: implementation of the CIfcValue class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IfcValue.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIfcValue::CIfcValue(void* pVal, int ValType, char* Capt/* = NULL*/)
				   :m_pVal(pVal), m_ValType(ValType) 
{
	if(Capt)
		strcpy(m_Capt, Capt);
	else strcpy(m_Capt, "");
}

CIfcValue::~CIfcValue()
{

}

int CheckMsg()
{
/*	return (MessageBox(NULL, "Сохранить изменения?",
				  "Данные были изменены", MB_YESNO|MB_ICONQUESTION)==IDYES);
*/
	return TRUE;
}

int CIfcValue::GetValue(char* text, int* IsMsg/* = 0*/)
{
	int isYES = -1;
	if(m_ValType == Integer)
	{	int tmp = atoi(text);
		if(tmp != *(int*)m_pVal && (*IsMsg == 1 && (isYES = CheckMsg()) || !*IsMsg))
			*(int*)m_pVal = tmp;
	}
	else if(m_ValType == Double)
	{	double tmp = atof(text);
		if((((tmp - *(double*)m_pVal)>=0.01)||((*(double*)m_pVal- tmp)>=0.01))&& (*IsMsg == 1 && (isYES = CheckMsg()) || !*IsMsg))
			*(double*)m_pVal = tmp;
	}
	else if(m_ValType == String)
	{	if(strcmp((char*)m_pVal, text) && (!IsMsg || (*IsMsg == 1 && (isYES = CheckMsg()) || !*IsMsg)))
			strcpy((char*)m_pVal, text);
	}
	if(IsMsg && *IsMsg == 1 && !isYES)
		*IsMsg = 2;
	else if(IsMsg && *IsMsg == 1 && isYES >0)
	{	*IsMsg = !*IsMsg;
		return TRUE;
	}
	else if(!IsMsg || *IsMsg == 0)
		return TRUE;
	return FALSE;
}
int CIfcValue::SetValue(char* text)
{
	if(m_ValType == Integer)
		sprintf(text, "%d", *(int*)m_pVal);
	else if(m_ValType == Double)
		sprintf(text, "%.2f", *(double*)m_pVal);
	else if(m_ValType == String)
		strcpy(text, (char*)m_pVal);
	return TRUE;
}
