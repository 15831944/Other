// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Splash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//#include "IfcDialog.h"

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CLOSE()
	ON_COMMAND(ID_DISABLE, OnDisable)
	ON_UPDATE_COMMAND_UI(ID_DISABLE, OnUpdateDisable)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLBAR, OnUpdateViewToolbar)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateFileSaveAs)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_VIEW_CHANGE, OnViewChange)
	ON_COMMAND(ID_CALC_RM_HEATLOSS, OnCalcRmHeatloss)
	ON_COMMAND(ID_CALC_RM_HEATBALANCE, OnCalcRmHeatbalance)
// справочники
	ON_COMMAND(ID_CITYDIR, OnCityDir)
	ON_COMMAND(ID_BUILDINGTYPEDIR, OnBuildingTypeDir)
	ON_COMMAND(ID_FENCETYPEDIR, OnFenceTypeDir)
	ON_COMMAND(ID_FENCEVIEWDIR, OnFenceViewDir)
	ON_COMMAND(ID_PARTYDIR, OnPartyDir)
// справочники
	//}}AFX_MSG_MAP
	// Global help commands
	ON_COMMAND(ID_HELP_FINDER, CFrameWnd::OnHelpFinder)
	ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
	ON_COMMAND(ID_CONTEXT_HELP, CFrameWnd::OnContextHelp)
	ON_COMMAND(ID_DEFAULT_HELP, CFrameWnd::OnHelpFinder)
	ON_MESSAGE(WM_MYICONNOTIFY, OnIcon)		//иконка в трее
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{

}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Ошибка создания главной панели инструментов\n");
		return -1;      // fail to create
	}
/*
	if (!m_wndToolBarRoom.CreateEx(this) ||
		!m_wndToolBarRoom.LoadToolBar(IDR_TOOLBAR_ROOM))
	{
		TRACE0("Ошибка создания панели инструментов помещения\n");
		return -1;      // fail to create
	}
/*
	if (!m_wndDlgBar.Create(this, IDR_MAINFRAME, 
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("Failed to create dialogbar\n");
		return -1;		// fail to create
	}
*/
	if (!m_wndReBar.Create(this) /*||
		!m_wndReBar.AddBar(&m_wndToolBarRoom)*/ ||
		!m_wndReBar.AddBar(&m_wndToolBar)/* ||
		!m_wndReBar.AddBar(&m_wndDlgBar)*/)
	{
		TRACE0("Failed to create rebar\n");
		return -1;      // fail to create
	}
	//OnCalcRmHeatbalance();
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Remove this if you don't want tool tips
/*    m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
	CBRS_TOOLTIPS | CBRS_FLYBY);
    m_wndToolBarRoom.SetBarStyle(m_wndToolBarRoom.GetBarStyle() |
	CBRS_TOOLTIPS | CBRS_FLYBY);
*/
	m_pDoc = GetLeftPane()->GetDocument();
	m_pDoc->SetFrame(this);
	/*return*/ 
	if(!m_pDoc->OnFileOpen())
		return -1;
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	cs.style|= WS_MAXIMIZE;
	cs.x  = 75;
	cs.y  = 10;
	cs.cx = 840;
	cs.cy = 700;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

CMainViewTree* CMainFrame::GetLeftPane()
{
	CWnd* pWnd = m_wndSplitter.GetPane(0, 0);
	CMainViewTree* pView = DYNAMIC_DOWNCAST(CMainViewTree, pWnd);
	return pView;
}

CMainView* CMainFrame::GetRightPane()
{
	CWnd* pWnd = m_wndSplitter.GetPane(0, 1);
	CMainView* pView = DYNAMIC_DOWNCAST(CMainView, pWnd);
	return pView;
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// create a splitter with 1 row, 2 columns
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
	{
		TRACE0("Failed to CreateStaticSplitter\n");
		return FALSE;
	}
		// add the first splitter pane - the default view in column 0
	if (!m_wndSplitter.CreateView(0, 0,
		RUNTIME_CLASS(CMainViewTree), CSize(200, 0), pContext))
	{
		TRACE0("Failed to create first pane\n");
		return FALSE;
	}

	if (!m_wndSplitter.CreateView(0, 1,
		RUNTIME_CLASS(CMainView), CSize(0, 0), pContext))
	{
		TRACE0("Failed to create second pane\n");
		return FALSE;
	}
	return TRUE;
}

int CMainFrame::ChangeView(int col, int row, CRuntimeClass* pNewViewClass)
{
	//смена окна
	m_wndSplitter.DeleteView(col,row);
	if (!m_wndSplitter.CreateView(col, row,	pNewViewClass, CSize(0, 0), NULL))
	{
		TRACE0("Failed to create pane\n");
		return FALSE;
	}
	m_wndSplitter.RecalcLayout();
	return TRUE;
}

void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
/*	if(nType == SIZE_MINIMIZED)
	{	//Показать ярлык в системном трее
		NOTIFYICONDATA nf;
		nf.hWnd = m_hWnd;
		nf.uID = NULL;
		
		nf.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
		nf.uCallbackMessage = WM_MYICONNOTIFY;
		strcpy(nf.szTip,"Hello Systray");

		HICON hIcon;
		hIcon=AfxGetApp()->LoadIcon(IDR_MAINFRAME);
		nf.hIcon = hIcon;
		Shell_NotifyIcon(NIM_ADD,&nf);
		ShowWindow(SW_HIDE);
		return;
	}	*/
/*	if(GetActiveDocument())
		if(((CMainDoc*)GetActiveDocument())->m_pCurrObj)
		{	((CMainDoc*)GetActiveDocument())->m_pCurrObj->HideDataView(GetRightPane());
			((CMainDoc*)GetActiveDocument())->m_pCurrObj->ShowDataView(GetRightPane());
		}
*/
	CFrameWnd::OnSize(nType, cx, cy);
}

void CMainFrame::OnIcon(WPARAM wp, LPARAM lp)
{
	if (lp==WM_LBUTTONDOWN)	//двойной щелчок
	{	
		//Восстановить ярлык из системного трея
		RemoveIconInTray();
		::SetForegroundWindow(m_hWnd);
		//ShowWindow(SW_SHOW);
		ShowWindow(SW_RESTORE);
		//SetActiveWindow();
	}
}


void CMainFrame::OnClose() 
{
	//Восстановить ярлык из системного трея
	RemoveIconInTray();	
	CFrameWnd::OnClose();
}

BOOL CMainFrame::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message == WM_MYICONNOTIFY)
		AfxMessageBox("WM_MYICONNOTIFY");
	return CFrameWnd::PreTranslateMessage(pMsg);
}

LRESULT CMainFrame::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(message==WM_SIZE)
		if(wParam == SIZE_MINIMIZED)
		{	//Показать ярлык в системном трее
			AddIconInTray();
			ShowWindow(SW_HIDE);
			return TRUE;
		}	
	return CFrameWnd::WindowProc(message, wParam, lParam);
}


BOOL CMainFrame::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CFrameWnd::DestroyWindow();
}

void CMainFrame::OnDisable() 
{
	CMainDoc* pDoc = (CMainDoc*)GetActiveDocument();
	pDoc->m_pProject->m_pCurrObj->HideInFrmView(GetRightPane());
//	pDoc->m_IsEdt = !pDoc->m_IsEdt;
	pDoc->m_pProject->m_pCurrObj->ShowInFrmView(GetRightPane());
}

void CMainFrame::OnUpdateDisable(CCmdUI* pCmdUI) 
{
	CMainDoc* pDoc = (CMainDoc*)GetActiveDocument();
//	pCmdUI->SetCheck(pDoc->m_IsEdt);
}

void CMainFrame::OnCalcRmHeatloss() 
{
}

void CMainFrame::OnCalcRmHeatbalance() 
{
	CMainDoc* pDoc = (CMainDoc*)GetActiveDocument();
/*	if(pDoc->m_pCurrCalc)
	{	
		CCalcHeatBalance* pCalc = dynamic_cast<CCalcHeatBalance*>(pDoc->m_pCurrCalc);
		if(!(pCalc && pCalc->m_pObj == pDoc->m_pCurrObj))
		{	pDoc->m_pCurrCalc->HideInFrmView(GetRightPane());
			delete pDoc->m_pCurrCalc;
			pDoc->m_pCurrCalc =  new CCalcHeatBalance(dynamic_cast<CRoom*>(pDoc->m_pCurrObj));
//			pDoc->m_pCurrObj->HideDataView(&GetRightPane()->m_IfcFrmView);
			pDoc->m_pCurrCalc->ShowInFrmView(GetRightPane());
		}
		else
		{	pDoc->m_pCurrCalc->HideInFrmView(GetRightPane());
			delete pDoc->m_pCurrCalc;
			pDoc->m_pCurrCalc = NULL;
			pDoc->m_pCurrObj->ShowInFrmView(GetRightPane());
		}
	}
	else
	{	pDoc->m_pCurrCalc =  new CCalcHeatBalance(dynamic_cast<CRoom*>(pDoc->m_pCurrObj));
		pDoc->m_pCurrObj->HideInFrmView(GetRightPane());
		pDoc->m_pCurrCalc->ShowInFrmView(GetRightPane());
	}
*/
}
/*
void CMainFrame::OnUpdateCalcRmHeatbalance(CCmdUI* pCmdUI) 
{
//	CMainDoc* pDoc = (CMainDoc*)GetActiveDocument();
//	CRoom* pRm = dynamic_cast<CRoom*>(pDoc->m_pCurrObj);
	//if(pDoc->m_pCurrObj && !pRm) OnCalcRmHeatbalance();
///	pCmdUI->SetCheck(pDoc->m_pCurrCalc?TRUE:FALSE);
//	pCmdUI->Enable(pRm?TRUE:FALSE);
}

void CMainFrame::OnRepFull() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnRepHeatentry() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnRepHeatloss() 
{
	// TODO: Add your command handler code here
	
}
*/
int CMainFrame::ShowAirOut(CRoom *pRm)
{
	return TRUE;
}
/*
void CMainFrame::OnFileOpen() 
{
	CMainDoc* pDoc = (CMainDoc*)GetActiveDocument();
//	pDoc->OnCloseDocument();

//	pDoc = new CMainDoc;
	pDoc->OnOpenDocument(NULL);
}
*/



void CMainFrame::OnUpdateViewToolbar(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(FALSE);	
}

void CMainFrame::OnUpdateFileSaveAs(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(FALSE);	
}

void CMainFrame::OnEditPaste() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnEditCopy() 
{
	// TODO: Add your command handler code here
	
}


void CMainFrame::OnViewChange() 
{
	//переход м/у основной панелью и панелью дерева проекта
	if(GetActiveView() == GetRightPane())
	{	
/*		((CMainDoc*) GetActiveDocument())->m_pCurrObj->HideInFrmView(GetRightPane());
		((CMainDoc*) GetActiveDocument())->m_pCurrObj->ShowInFrmView(GetRightPane());
*/
//		это и не надо теперь, все обновиться в OnSelchanged дерева
//		GetRightPane()->UpdtData(FALSE);
		//GetLeftPane()->Update();
		//через Update не получилось изменить текст 
		//пойдем другим путем, хотя он не очень нравиться, но работает :)
		SetActiveView(GetLeftPane());
		HTREEITEM Item = GetLeftPane()->m_TreeCtrl.GetSelectedItem();
		GetLeftPane()->m_TreeCtrl.SelectItem(NULL);
		GetLeftPane()->m_TreeCtrl.SelectItem(Item);
		//получилось через одно место :)
	}
	else if(GetActiveView() == GetLeftPane())
		SetActiveView(GetRightPane());
}

/*
void CMainFrame::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	((CMainDoc*)GetActiveDocument())->OnFileOpen();
	CFrameWnd::OnShowWindow(bShow, nStatus);
}*/


BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	return CFrameWnd::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext);
}

void CMainFrame::AddIconInTray()		// поместить в трей
{
	//Показать ярлык в системном трее
	NOTIFYICONDATA nf;
	nf.hWnd = m_hWnd;
	nf.uID = NULL;

	nf.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nf.uCallbackMessage = WM_MYICONNOTIFY;
	strcpy(nf.szTip,"Hello Systray");

	HICON hIcon;
	hIcon=AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	nf.hIcon = hIcon;
	Shell_NotifyIcon(NIM_ADD,&nf);
}

void CMainFrame::RemoveIconInTray()		// убрать из трея
{
	//Восстановить ярлык из системного трея
	NOTIFYICONDATA nf;
	nf.hWnd = m_hWnd;
	nf.uID = NULL;
	nf.uFlags = NIF_ICON;
	nf.uCallbackMessage = NULL;
	nf.hIcon = NULL;
	Shell_NotifyIcon(NIM_DELETE,&nf);
}
/////////////////////////////////////////////
/*   СПРАВОЧНИКИ - реализация будет позже  */
/////////////////////////////////////////////
void CMainFrame::OnCityDir() 
{
	AfxMessageBox("Функциональность справочников будет добавлена позже");
}
void CMainFrame::OnBuildingTypeDir() 
{
	AfxMessageBox("Функциональность справочников будет добавлена позже");
}
void CMainFrame::OnFenceTypeDir() 
{
	AfxMessageBox("Функциональность справочников будет добавлена позже");
}
void CMainFrame::OnFenceViewDir() 
{
	AfxMessageBox("Функциональность справочников будет добавлена позже");
}
void CMainFrame::OnPartyDir() 
{
	AfxMessageBox("Функциональность справочников будет добавлена позже");
}
/////////////////////////////////////////////
/*   СПРАВОЧНИКИ - реализация будет позже  */
/////////////////////////////////////////////
