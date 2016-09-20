#if !defined(AFX_IFCTREEVIEW_H__0E061BD8_A978_41CF_BB18_D2E433C084C7__INCLUDED_)
#define AFX_IFCTREEVIEW_H__0E061BD8_A978_41CF_BB18_D2E433C084C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IfcTreeView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIfcTreeView view
#include "stdafx.h"
#include "IfcApi.h"

#include <map>
using namespace std;


class CProject;
class CHVKDbObject;
class CHVKVector;
class IFCAPI CIfcTreeView : public CTreeView
{
public:
	CTreeCtrl&  m_TreeCtrl;
	map<HTREEITEM, CHVKDbObject*> m_ListItem;
protected:
	CIfcTreeView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CIfcTreeView)

// Attributes
public:

// Operations
public:
public:
	void Init();
	int ShowProject(CProject* pPrj);
	void ShowVector(CHVKVector* vect, HTREEITEM hParent = TVI_ROOT);
	CHVKDbObject* FindObject(HTREEITEM Item);
	HTREEITEM FindItem(CHVKDbObject* Obj);
	HTREEITEM InsertObject(CHVKDbObject* obj, HTREEITEM hParent = TVI_ROOT);
	void CIfcTreeView::AddObject();
	void Clear();
	void DeleteSelItem();
	void Update(CHVKDbObject* pObj);
	void Update(HTREEITEM Item = NULL);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIfcTreeView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CIfcTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CIfcTreeView)
	afx_msg void OnKeydown(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IFCTREEVIEW_H__0E061BD8_A978_41CF_BB18_D2E433C084C7__INCLUDED_)
