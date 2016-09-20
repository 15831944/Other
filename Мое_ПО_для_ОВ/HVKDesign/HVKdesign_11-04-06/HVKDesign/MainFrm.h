// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__4020F235_4039_475C_8263_C1533C818644__INCLUDED_)
#define AFX_MAINFRM_H__4020F235_4039_475C_8263_C1533C818644__INCLUDED_


class CMainView;
class CMainViewTree;
class CMainDoc;

class CMainFrame : public CFrameWnd
{
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
private:
	CSplitterWnd m_wndSplitter;
	CMainDoc* m_pDoc;
// Operations
public:
	CMainViewTree*  GetLeftPane();
	CMainView    * GetRightPane();
	CSplitterWnd* GetSplitter(){return &m_wndSplitter;};
	int ChangeView(int col, int row, CRuntimeClass* pNewViewClass);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL DestroyWindow();
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	int ShowAirOut(CRoom* pRm);
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	CToolBar    m_wndToolBarRoom;
	CReBar      m_wndReBar;
	CDialogBar  m_wndDlgBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnClose();
	afx_msg void OnDisable();
	afx_msg void OnUpdateDisable(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewToolbar(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileSaveAs(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnEditCopy();
	afx_msg void OnViewChange();
	afx_msg void OnBuildingTypeDir();
	afx_msg void OnCalcRmHeatloss();
	afx_msg void OnCalcRmHeatbalance();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	void OnIcon(WPARAM wp, LPARAM lp);//иконка в трее
private:
	void AddIconInTray();		// поместить в трей
	void RemoveIconInTray();	// убрать из трея
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__4020F235_4039_475C_8263_C1533C818644__INCLUDED_)
