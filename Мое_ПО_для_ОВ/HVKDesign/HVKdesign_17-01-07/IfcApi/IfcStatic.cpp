// IfcStatic.cpp : implementation file
//

#include "stdafx.h"
#include "	\ add additional includes here"
#include "IfcStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIfcStatic

CIfcStatic::CIfcStatic(char* Capt, int x , int y, int dx = 0, int dy = 0, DWORD Style = NULL)
					:CIfcObject(&IfcValue(NULL, 0, Capt), xVal , int yVal, int dxVal/* = 0*/, int dyVal/* = 0*/,
		 int xCapt/* = -1*/, int yCapt/* = -1*/, int dxCapt/* = 0*/, int dy/* = 0*/)
{
}

CIfcStatic::~CIfcStatic()
{
}


BEGIN_MESSAGE_MAP(CIfcStatic, CStatic)
	//{{AFX_MSG_MAP(CIfcStatic)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIfcStatic message handlers
