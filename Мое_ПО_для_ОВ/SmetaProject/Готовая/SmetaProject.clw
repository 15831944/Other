; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CZdanieInfoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SmetaProject.h"

ClassCount=8
Class1=CSmetaProjectApp
Class2=CZdanieResultsDlg
Class3=CAboutDlg

ResourceCount=8
Resource1=IDD_DIALOGPB
Resource2=IDD_PC_BROWSER_DIALOG
Resource3=IDD_ABOUTBOX
Class5=CZdanieInfoDlg
Resource4=IDD_RAZDELZDANIE_DIALOG
Resource5=IDC_MENU
Class4=CZdanie
Resource6=IDD_ZDANIERESULTS_DIALOG
Resource7=IDD_ZDANIEINFO_DIALOG
Class6=CPC_BrowserDlg
Class7=CDirTreeCtrl
Class8=CDlgPb
Resource8=IDR_ACCELERATOR

[CLS:CSmetaProjectApp]
Type=0
HeaderFile=SmetaProject.h
ImplementationFile=SmetaProject.cpp
Filter=N
LastObject=CSmetaProjectApp

[CLS:CZdanieResultsDlg]
Type=0
HeaderFile=ZdanieResultsDlg.h
ImplementationFile=ZdanieResultsDlg.cpp
Filter=T
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CZdanieResultsDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ZdanieResultsDlg.h
ImplementationFile=ZdanieResultsDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CZdanie]
Type=0
HeaderFile=Zdanie.h
ImplementationFile=Zdanie.cpp
BaseClass=CZdanieResultsDlg
Filter=D
LastObject=ID_ZDANIE
VirtualFilter=dWC

[DLG:IDD_RAZDELZDANIE_DIALOG]
Type=1
Class=?
ControlCount=19
Control1=IDC_EDITN,edit,1350631552
Control2=IDC_EDITK1,edit,1350631552
Control3=IDC_EDITNA,edit,1350631552
Control4=IDC_EDITVA,edit,1350631552
Control5=IDC_EDITS1,edit,1350631552
Control6=IDC_EDITS2,edit,1350631552
Control7=IDC_EDITS3,edit,1350631552
Control8=IDC_EDITS4,edit,1350631552
Control9=IDC_OK,button,1342242817
Control10=IDC_CANCEL,button,1342242816
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352

[DLG:IDD_ZDANIEINFO_DIALOG]
Type=1
Class=?
ControlCount=12
Control1=IDC_EDITN,edit,1350631552
Control2=IDC_EDITV,edit,1350631552
Control3=IDC_EDITK1,edit,1350631552
Control4=IDC_EDITK2,edit,1350631552
Control5=IDC_EDITK3,edit,1350631552
Control6=IDC_OK,button,1342242817
Control7=IDC_CANCEL,button,1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352

[CLS:CZdanieInfoDlg]
Type=0
HeaderFile=ZdanieInfoDlg.h
ImplementationFile=ZdanieInfoDlg.cpp
BaseClass=CDialog
LastObject=CZdanieInfoDlg
Filter=D
VirtualFilter=dWC

[DLG:IDD_ZDANIERESULTS_DIALOG]
Type=1
Class=CZdanie
ControlCount=16
Control1=IDC_MSFLEXGRID,{6262D3A0-531B-11CF-91F6-C2863C385E30},1073807360
Control2=ID_NEW,button,1342246720
Control3=ID_OPEN,button,1342246720
Control4=ID_SAVE,button,1342246720
Control5=ID_CUT,button,1342246720
Control6=ID_COPY,button,1342246720
Control7=ID_PASTE,button,1342246720
Control8=ID_ADDRAZDEL,button,1342246720
Control9=ID_DELETERAZDEL,button,1342246720
Control10=ID_EDITRAZDEL,button,1342246720
Control11=ID_ZDANIE,button,1342246720
Control12=ID_CALCULATE,button,1342246720
Control13=ID_WORD,button,1342246720
Control14=ID_EXIT,button,1342246720
Control15=ID_HELP,button,1342246720
Control16=IDC_STATIC,button,1342259207

[MNU:IDC_MENU]
Type=1
Class=?
Command1=ID_NEW
Command2=ID_OPEN
Command3=ID_CLOSE
Command4=ID_SAVE
Command5=ID_EXIT
Command6=ID_CUT
Command7=ID_COPY
Command8=ID_PASTE
Command9=ID_ZDANIE
Command10=ID_ADDRAZDEL
Command11=ID_EDITRAZDEL
Command12=ID_DELETERAZDEL
Command13=ID_CUTRAZDEL
Command14=ID_COPYRAZDEL
Command15=ID_PASTERAZDEL
Command16=ID_CALCULATE
Command17=ID_WORD
Command18=ID_HELP
Command19=ID_ABOUT
CommandCount=19

[CLS:CPC_BrowserDlg]
Type=0
HeaderFile=PC_BrowserDlg.h
ImplementationFile=PC_BrowserDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPC_BrowserDlg

[DLG:IDD_PC_BROWSER_DIALOG]
Type=1
Class=?
ControlCount=7
Control1=IDC_EDITNAME,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=ID_BROWSETREE,SysTreeView32,1350567983
Control5=IDC_EDITPATH,edit,1350568064
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352

[ACL:IDR_ACCELERATOR]
Type=1
Class=?
Command1=ID_COPY
Command2=ID_NEW
Command3=ID_OPEN
Command4=ID_SAVE
Command5=ID_PASTE
Command6=ID_DELETERAZDEL
Command7=ID_CLOSE
Command8=ID_EXIT
Command9=ID_ADDRAZDEL
Command10=ID_CUT
Command11=ID_ZDANIE
CommandCount=11

[CLS:CDirTreeCtrl]
Type=0
HeaderFile=DirTreeCtrl.h
ImplementationFile=DirTreeCtrl.cpp
BaseClass=CTreeCtrl
LastObject=CDirTreeCtrl

[DLG:IDD_DIALOGPB]
Type=1
Class=CDlgPb
ControlCount=1
Control1=IDC_PROGRESS,msctls_progress32,1350565889

[CLS:CDlgPb]
Type=0
HeaderFile=DlgPb.h
ImplementationFile=DlgPb.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgPb
VirtualFilter=dWC

