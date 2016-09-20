// HVKMainDoc.h : interface of the CMainDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HVKMAINDOC_H__0A8FEFA8_B541_4444_892C_D11C7792984F__INCLUDED_)
#define AFX_HVKMAINDOC_H__0A8FEFA8_B541_4444_892C_D11C7792984F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StdAfx.h"
#include "..\\IfcApi\\Project.h"

class CProject;
class CMainDoc : public CDocument
{
protected: // create from serialization only
	CMainDoc();
	DECLARE_DYNCREATE(CMainDoc)
	
// Attributes
private:
	CADORecord* m_ptrCurrentRecordset;
	_ConnectionPtr m_ptrConn;
	CMainFrame* m_pFrame;
// Operations
public:
	CProject* m_pProject;
//	CProject m_SaveProject;
	void CloseDocument();
	void SetFrame(CMainFrame* pFrame){m_pFrame = pFrame;};
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	protected:
	virtual BOOL SaveModified();
	//}}AFX_VIRTUAL
// Implementation
	void Init();
public:
	virtual ~CMainDoc();
	/*afx_msg void*/ int OnFileOpen();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMainDoc)
	afx_msg void OnUpdateDisable(CCmdUI* pCmdUI);
	afx_msg void OnFileSave();
//	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HVKMAINDOC_H__0A8FEFA8_B541_4444_892C_D11C7792984F__INCLUDED_)
