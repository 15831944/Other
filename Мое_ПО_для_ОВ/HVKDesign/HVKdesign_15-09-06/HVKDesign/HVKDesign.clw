; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "HVKDesign.h"
LastPage=0

ClassCount=12
Class1=CHVKDesignApp
Class2=CMainDoc
Class3=CMainView
Class4=CMainFrame

ResourceCount=10
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME (English (U.S.))
Class5=CAboutDlg
Resource3=IDR_MAINFRAME_
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_HVKDESIGN_FORM (English (U.S.))
Class6=CMainViewTree
Resource6=IDR_MENU1
Class7=CDLGCls
Class8=CMyDialog
Class9=CIfcDialog
Class10=CHVKDialog
Resource7=IDR_TOOLBAR_ROOM
Class11=CHVKInitDlg
Resource8=IDD_DIALOG (QWE)
Class12=CSplashWnd
Resource9=IDD_HVKDESIGN_FORM
Resource10=IDR_MAINFRAME

[CLS:CHVKDesignApp]
Type=0
HeaderFile=HVKDesign.h
ImplementationFile=HVKDesign.cpp
Filter=N

[CLS:CMainDoc]
Type=0
HeaderFile=HVKMainDoc.h
ImplementationFile=HVKMainDoc.cpp
Filter=N
LastObject=ID_FILE_SAVE
BaseClass=CDocument
VirtualFilter=DC

[CLS:CMainView]
Type=0
HeaderFile=HVKMainView.h
ImplementationFile=HVKMainView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=CMainView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_BUILDINGTYPEDIR




[CLS:CAboutDlg]
Type=0
HeaderFile=HVKDesign.cpp
ImplementationFile=HVKDesign.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_CITYDIR
Command12=ID_BUILDINGTYPEDIR
Command13=ID_FENCEVIEWIR
Command14=ID_FENCETYPEDIR
Command15=ID_PARTYDIR
Command16=ID_CALC_RM_HEATLOSS
Command17=ID_CALC_RM_HEATENTRY
Command18=ID_REP_FULL
Command19=ID_REP_HEATLOSS
Command20=ID_REP_HEATENTRY
Command21=ID_VIEW_TOOLBAR
Command22=ID_VIEW_STATUS_BAR
Command23=ID_VIEW_CHANGE
Command24=ID_HELP_FINDER
Command25=ID_APP_ABOUT
CommandCount=25

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_OPEN
Command4=ID_FILE_PRINT
Command5=ID_FILE_SAVE
Command6=ID_EDIT_PASTE
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_HELP
Command10=ID_CONTEXT_HELP
Command11=ID_NEXT_PANE
Command12=ID_PREV_PANE
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_CHANGE
Command16=ID_EDIT_CUT
Command17=ID_EDIT_UNDO
CommandCount=17

[DLG:IDD_HVKDESIGN_FORM]
Type=1
Class=CMainView
ControlCount=0

[DLG:IDD_HVKDESIGN_FORM (English (U.S.))]
Type=1
Class=CMainView
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_CONTEXT_HELP
CommandCount=9

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_HELP_FINDER
Command17=ID_APP_ABOUT
CommandCount=17

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
Command15=ID_CONTEXT_HELP
Command16=ID_HELP
CommandCount=16

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CIfcDialog
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[CLS:CMainViewTree]
Type=0
HeaderFile=HVKTreeView.h
ImplementationFile=HVKTreeView.cpp
BaseClass=CTreeView
Filter=C
LastObject=CMainViewTree
VirtualFilter=VWC

[DLG:IDR_MAINFRAME]
Type=1
Class=CIfcDialog
ControlCount=0

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_BUTTON32790
Command8=ID_BUTTON32791
Command9=ID_DISABLE
Command10=ID_BUTTON32792
Command11=ID_BUTTON32793
Command12=ID_APP_ABOUT
Command13=ID_CONTEXT_HELP
CommandCount=13

[CLS:CDLGCls]
Type=0
HeaderFile=DLGCls.h
ImplementationFile=DLGCls.cpp
BaseClass=CDialog
Filter=D
LastObject=CDLGCls

[TB:IDR_TOOLBAR_ROOM]
Type=1
Class=?
Command1=ID_CALC_RM_HEATLOSS
Command2=ID_CALC_RM_HEATBALANCE
CommandCount=2

[CLS:CMyDialog]
Type=0
HeaderFile=MyDialog.h
ImplementationFile=MyDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CMyDialog

[CLS:CIfcDialog]
Type=0
HeaderFile=IfcDialog.h
ImplementationFile=IfcDialog.cpp
BaseClass=CDialog
Filter=D

[CLS:CHVKDialog]
Type=0
HeaderFile=HVKDialog.h
ImplementationFile=HVKDialog.cpp
BaseClass=CDialog
Filter=D

[CLS:CHVKInitDlg]
Type=0
HeaderFile=HVKInitDlg.h
ImplementationFile=HVKInitDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_RADIOOPEN
VirtualFilter=dWC

[TB:IDR_MAINFRAME_]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_CONTEXT_HELP
Command10=ID_DISABLE
CommandCount=10

[DLG:IDD_DIALOG (QWE)]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_RADIONEW,button,1342373897
Control3=IDC_RADIOOPEN,button,1342373897

[CLS:CSplashWnd]
Type=0
HeaderFile=Splash.h
ImplementationFile=Splash.cpp
BaseClass=CWnd
LastObject=CSplashWnd

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_TRAY_EXIT
CommandCount=1

