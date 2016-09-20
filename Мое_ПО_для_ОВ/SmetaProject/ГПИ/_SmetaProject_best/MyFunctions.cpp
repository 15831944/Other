// MyFunctions.cpp
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SmetaProject.h"
#include "MyFunctions.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

int IsNumber(const char* str)
{
	if(!strlen(str)) return 0;
	for(UINT i=0; i<strlen(str); i++)
		if(!((str[i]<='9' && str[i]>='0') || str[i]==',' || str[i]=='.' || 
		  (str[i]=='-' && i == 0)))
		  return 0;
	return 1;
}

