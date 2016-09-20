// IfcTreeView.cpp : implementation file
//

#include "stdafx.h"
#include "IfcTreeView.h"
#include "HVKVector.h"
#include "HVKDbObject.h"
#include "Project.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIfcTreeView

IMPLEMENT_DYNCREATE(CIfcTreeView, CTreeView)

CIfcTreeView::CIfcTreeView():m_TreeCtrl(GetTreeCtrl())
{
}

CIfcTreeView::~CIfcTreeView()
{

}

void CIfcTreeView::ShowVector(CHVKVector *vect, HTREEITEM hParent /*= TVI_ROOT*/)
{
	for(int i=0; i<vect->size();i++)
	{ HTREEITEM Parent = InsertObject((*vect)[i], hParent);
	CHVKDbObject* pObj;
	pObj = (*vect)[i];
	if((*vect)[i])
		(*vect)[i]->ShowInTreeView(this, Parent);
	}
}

void CIfcTreeView::Init()
{
	m_TreeCtrl.SetIndent(25);
	m_TreeCtrl.ModifyStyle(NULL,TVS_LINESATROOT|TVS_HASBUTTONS|TVS_HASLINES|TVS_SHOWSELALWAYS);
}

int CIfcTreeView::ShowProject(CProject *pPrj)
{
	return pPrj->ShowInTreeView(this);
}

CHVKDbObject* CIfcTreeView::FindObject(HTREEITEM Item)
{
	map<HTREEITEM, CHVKDbObject*>::iterator theIterator;
	//поиск элемента   
	theIterator = m_ListItem.find(Item);
	//если элемент найден
	if (theIterator != m_ListItem.end())
		return (*theIterator).second;
	return NULL;
}

HTREEITEM CIfcTreeView::FindItem(CHVKDbObject* pObj)
{
	map<HTREEITEM, CHVKDbObject*>::iterator theIterator;
	//поиск объекта
	for(theIterator=m_ListItem.begin();theIterator!=m_ListItem.end(); theIterator++)
		if((*theIterator).second == pObj)
			return (HTREEITEM)&(*theIterator).first;
	return NULL;
}

HTREEITEM CIfcTreeView::InsertObject(CHVKDbObject* obj, HTREEITEM hParent/*= TVI_ROOT*/)
{
	if(!obj) return m_TreeCtrl.GetSelectedItem();
	HTREEITEM Item = m_TreeCtrl.InsertItem(obj->GetName(), hParent);
	//Заносим в список 
	m_ListItem.insert(map<HTREEITEM, CHVKDbObject*>::value_type(Item, obj));
	return Item;
}

void CIfcTreeView::Clear()
{
	m_TreeCtrl.DeleteAllItems();
	m_ListItem.clear();
}

void CIfcTreeView::DeleteSelItem()
{
	HTREEITEM selItem  = m_TreeCtrl.GetSelectedItem();
	HTREEITEM nextItem = m_TreeCtrl.GetPrevSiblingItem(selItem);
	if(!nextItem)
		nextItem = m_TreeCtrl.GetNextSiblingItem(selItem);
	if(!nextItem)
		nextItem = m_TreeCtrl.GetParentItem(selItem);
	m_TreeCtrl.SelectItem(nextItem);
	CHVKDbObject* selObj = FindObject(selItem);
	selObj->DeleteEx();
	delete selObj;
	m_TreeCtrl.DeleteItem(selItem);
}

void CIfcTreeView::AddObject() 
{
	HTREEITEM selItem = m_TreeCtrl.GetSelectedItem();
	if(selItem)
	{	CHVKDbObject* pCurObj  = FindObject(selItem);
		m_TreeCtrl.SelectItem(InsertObject(pCurObj->New(), selItem));
	}
}
/*
void CIfcTreeView::Update() 
{
	CHVKDbObject* pCurObj  = FindObject(m_TreeCtrl.GetSelectedItem());
	CHVKDbObject* pRootObj = FindObject(m_TreeCtrl.GetRootItem());
	Clear();
	pRootObj->ShowInTreeView(this);
	HTREEITEM selItem = FindItem(pCurObj);
	m_TreeCtrl.SelectItem(selItem);
	m_TreeCtrl.Expand(selItem, TVE_COLLAPSE);
}
*/
void CIfcTreeView::Update(CHVKDbObject* pObj)
{
	if(!pObj)
		pObj = FindObject(m_TreeCtrl.GetSelectedItem());
	if(!pObj) return;
	HTREEITEM Item = FindItem(pObj);	
	m_TreeCtrl.SetItemText(Item, pObj->m_Name);
}

void CIfcTreeView::Update(HTREEITEM Item/* = NULL*/)
{
	if(!Item)
		Item = m_TreeCtrl.GetSelectedItem();
	if(!Item)
		return;
	if(Item)
		m_TreeCtrl.SetItemText(Item, FindObject(Item)->m_Name);
}

BEGIN_MESSAGE_MAP(CIfcTreeView, CTreeView)
	//{{AFX_MSG_MAP(CIfcTreeView)
	ON_NOTIFY_REFLECT(TVN_KEYDOWN, OnKeydown)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIfcTreeView drawing

void CIfcTreeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CIfcTreeView diagnostics

#ifdef _DEBUG
void CIfcTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CIfcTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIfcTreeView message handlers

void CIfcTreeView::OnKeydown(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_KEYDOWN* pTVKeyDown = (TV_KEYDOWN*)pNMHDR;
	if(pTVKeyDown->wVKey == VK_DELETE)		//клавиша del
	{
		if(::MessageBox(m_hWnd, "Вы действительно хотите удалить текущий элемент?", 
				"Запрос подтверждения удаления", MB_YESNO|MB_ICONQUESTION) == IDYES)
			DeleteSelItem();
	}
	if(pTVKeyDown->wVKey == VK_INSERT)		//клавиша ins
		AddObject();
	*pResult = 0;
}

void CIfcTreeView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	Update(pNMTreeView->itemOld.hItem);
	*pResult = 0;
}
