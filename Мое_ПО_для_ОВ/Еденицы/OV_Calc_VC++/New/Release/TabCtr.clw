; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyEdit
LastTemplate=CEdit
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TabCtr.h"

ClassCount=5
Class1=CTabCtrApp
Class2=CTabCtrDlg

ResourceCount=3
Resource2=IDD_TABPAGE
Resource1=IDR_MAINFRAME
Class3=CTabPage
Class4=lasss1
Class5=CMyEdit
Resource3=IDD_TABCTR_DIALOG

[CLS:CTabCtrApp]
Type=0
HeaderFile=TabCtr.h
ImplementationFile=TabCtr.cpp
Filter=N
LastObject=CTabCtrApp

[CLS:CTabCtrDlg]
Type=0
HeaderFile=TabCtrDlg.h
ImplementationFile=TabCtrDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CTabCtrDlg



[DLG:IDD_TABCTR_DIALOG]
Type=1
Class=CTabCtrDlg
ControlCount=3
Control1=IDC_TAB,SysTabControl32,1342243392
Control2=IDC_OK,button,1342242816
Control3=ID_HELP,button,1342242816

[DLG:IDD_TABPAGE]
Type=1
Class=CTabPage
ControlCount=0

[CLS:lasss1]
Type=0
HeaderFile=lasss11.h
ImplementationFile=lasss11.cpp
BaseClass=CDialog
Filter=D

[CLS:CTabPage]
Type=0
HeaderFile=tabpage.h
ImplementationFile=tabpage.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CTabPage

[CLS:CMyEdit]
Type=0
HeaderFile=MyEdit.h
ImplementationFile=MyEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC
LastObject=CMyEdit

