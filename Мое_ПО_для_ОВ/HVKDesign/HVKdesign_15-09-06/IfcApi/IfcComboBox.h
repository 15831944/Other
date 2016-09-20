#if !defined(AFX_IFCCOMBOBOX_H__3D63451D_6877_4E43_B6A3_78B39D6914FB__INCLUDED_)
#define AFX_IFCCOMBOBOX_H__3D63451D_6877_4E43_B6A3_78B39D6914FB__INCLUDED_
/*
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000*/
// IfcComboBox.h : header file
//
#include "IfcApi.h"
#include "HVKDbObject.h"

/////////////////////////////////////////////////////////////////////////////
// CIfcComboBox window
#include "IfcObject.h"

//class CHVKObject;
class CADORecord;
class IFCAPI CIfcComboBox : public CComboBox, public CIfcObject
{
	CADORecord* m_ptrCurrentRecordset;
	CHVKDbObject* m_pObj;
	int m_IsCanCreateNew;
// Construction
public:
	CIfcComboBox(CIfcValue* Value, CADORecord* ptrCurrentRecordset, int xVal , int yVal, CHVKDbObject* pObj = NULL,
		 int dxVal = 0, int dyVal = 0, int xCapt = -1, int yCapt = -1, int dxCapt = 0, int dyCapt = 0);
// Attributes
public:

// Operations
public:
	virtual int Show(CWnd* pView);
	virtual int Update(int* IsMsg = 0);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIfcComboBox)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIfcComboBox();
	void SetCanCreateNew(int Val){m_IsCanCreateNew = Val;};
	// Generated message map functions
protected:
	//{{AFX_MSG(CIfcComboBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IFCCOMBOBOX_H__3D63451D_6877_4E43_B6A3_78B39D6914FB__INCLUDED_)
