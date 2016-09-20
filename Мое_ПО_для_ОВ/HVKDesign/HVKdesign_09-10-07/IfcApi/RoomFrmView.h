#if !defined(AFX_ROOMFRMVIEW_H__B286FE2A_FA2C_4B9F_BB58_31246C5C9018__INCLUDED_)
#define AFX_ROOMFRMVIEW_H__B286FE2A_FA2C_4B9F_BB58_31246C5C9018__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RoomFrmView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRoomFrmView dialog

class CRoomFrmView : public CDialog
{
// Construction
public:
	CRoomFrmView(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRoomFrmView)
	enum { IDD = IDD_FORMVIEW_ROOM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoomFrmView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRoomFrmView)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROOMFRMVIEW_H__B286FE2A_FA2C_4B9F_BB58_31246C5C9018__INCLUDED_)
