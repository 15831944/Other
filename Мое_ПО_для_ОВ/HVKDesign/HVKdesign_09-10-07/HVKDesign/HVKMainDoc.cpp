// HVKMainDoc.cpp : implementation of the CMainDoc class
//

#include "stdafx.h"
#include "HVKInitDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainDoc

IMPLEMENT_DYNCREATE(CMainDoc, CDocument)

BEGIN_MESSAGE_MAP(CMainDoc, CDocument)
	//{{AFX_MSG_MAP(CMainDoc)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainDoc construction/destruction

CMainDoc::CMainDoc():m_ptrConn(NULL), m_ptrCurrentRecordset(NULL)
{
//	m_ptrConn = OpenConnection();
	m_ptrCurrentRecordset = new CADORecord(/*m_ptrConn*/);
//	m_pProject = new CProject();
	m_pProject = NULL;
}

CMainDoc::~CMainDoc()
{
	if(m_ptrCurrentRecordset)
	{	if((*m_ptrCurrentRecordset)->State==adStateOpen)
			(*m_ptrCurrentRecordset)->Close();
		delete m_ptrCurrentRecordset;
	}
	if(m_ptrConn!= NULL && (m_ptrConn->State == adStateOpen))
		m_ptrConn->Close();
	if(m_pProject)
		delete m_pProject;
	m_pProject = NULL;
	delete m_ptrCurrentRecordset;
//	delete CIfcObject::m_pFont;
}

BOOL CMainDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMainDoc serialization



/////////////////////////////////////////////////////////////////////////////
// CMainDoc diagnostics

#ifdef _DEBUG
void CMainDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMainDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainDoc commands

void CMainDoc::CloseDocument()
{
	if(m_pProject && m_pFrame)
	{	m_pProject->ClosePrj(m_pFrame->GetRightPane());
		delete m_pProject;
		m_pProject = NULL;
//		m_pProject = new CProject;
	}
}

BOOL CMainDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	int stat = TRUE;
	if(m_pFrame)
	{	Init();
		m_pProject = new CProject;
		stat = m_pProject->SelectPrj(m_pFrame->GetLeftPane());
	}
	return stat;
}

BOOL CMainDoc::SaveModified() 
{
	CloseDocument();
	return TRUE;
}

BOOL CMainDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	if(m_pProject && m_pFrame)
		m_pProject->SavePrj(m_pFrame->GetRightPane());
	return TRUE;
}

void CMainDoc::OnFileSave() 
{
	OnSaveDocument(NULL);
}

void CMainDoc::Init()
{
	static int IsEdt = TRUE;
	CIfcObject::m_IDCtrl = 1234;
	CIfcObject::m_pIsEdt = &IsEdt;
	CIfcObject::m_pFont = NULL;
}

/*void*/int CMainDoc::OnFileOpen() 
{
	int stat = TRUE;
	if(m_pFrame)
	{	CloseDocument();
		m_pFrame->GetLeftPane()->Clear();
//		if(!OnOpenDocument(NULL))
//			CloseDocument();
		stat = OnOpenDocument(NULL);
	}
	return stat;
}
