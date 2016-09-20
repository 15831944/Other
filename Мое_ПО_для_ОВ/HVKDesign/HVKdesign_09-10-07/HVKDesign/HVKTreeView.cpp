// HVKTreeView.cpp : implementation file
//

#include "stdafx.h"
#include "HVKDesign.h"

#include "HVKMainDoc.h"
#include "HVKTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainViewTree

IMPLEMENT_DYNCREATE(CMainViewTree, CTreeView)

//map<HTREEITEM, CHVKDbObject*> ListItem;


CMainViewTree::CMainViewTree()
{
}

CMainViewTree::~CMainViewTree()
{
}


BEGIN_MESSAGE_MAP(CMainViewTree, CTreeView)
	//{{AFX_MSG_MAP(CMainViewTree)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_NOTIFY_REFLECT(TVN_KEYDOWN, OnKeydown)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainViewTree drawing

void CMainViewTree::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
}

/////////////////////////////////////////////////////////////////////////////
// CMainViewTree diagnostics

#ifdef _DEBUG
void CMainViewTree::AssertValid() const
{
	CTreeView::AssertValid();
}

void CMainViewTree::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainViewTree message handlers

void CMainViewTree::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();
	Init();
	m_pFrame = (CMainFrame*)GetParentFrame();
//	((CMainDoc*)m_pFrame->GetActiveDocument())->OnFileOpen();
}

void CMainViewTree::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	GetDocument()->m_pProject->m_pCurrObj = FindObject(pNMTreeView->itemNew.hItem);
	CHVKDbObject* ObjOld = FindObject(pNMTreeView->itemOld.hItem);
	if(ObjOld)
		ObjOld->HideInFrmView(m_pFrame->GetRightPane());
	if(GetDocument()->m_pProject->m_pCurrObj)
		GetDocument()->m_pProject->m_pCurrObj->ShowInFrmView(m_pFrame->GetRightPane());
	CIfcTreeView::OnSelchanged(pNMHDR, pResult);
}

void CMainViewTree::OnKeydown(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_KEYDOWN* pTVKeyDown = (TV_KEYDOWN*)pNMHDR;
	CIfcTreeView::OnKeydown(pNMHDR, pResult);
	if(pTVKeyDown->wVKey == VK_INSERT)
		m_pFrame->SetActiveView(m_pFrame->GetRightPane());
}
