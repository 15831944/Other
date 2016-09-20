# Microsoft Developer Studio Project File - Name="SmetaProject" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=SmetaProject - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SmetaProject.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SmetaProject.mak" CFG="SmetaProject - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SmetaProject - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "SmetaProject - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SmetaProject - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "SmetaProject - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "SmetaProject - Win32 Release"
# Name "SmetaProject - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\DirTreeCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgPb.cpp
# End Source File
# Begin Source File

SOURCE=.\font.cpp
# End Source File
# Begin Source File

SOURCE=.\msflexgrid.cpp
# End Source File
# Begin Source File

SOURCE=.\msword9.cpp
# End Source File
# Begin Source File

SOURCE=.\MyDataTable.cpp
# End Source File
# Begin Source File

SOURCE=.\MyFunctions.cpp
# End Source File
# Begin Source File

SOURCE=.\PC_BrowserDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Razdel.cpp
# End Source File
# Begin Source File

SOURCE=.\RazdelAnalog.cpp
# End Source File
# Begin Source File

SOURCE=.\RazdelZdanie.cpp
# End Source File
# Begin Source File

SOURCE=.\RazdelZdanieDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\rowcursor.cpp
# End Source File
# Begin Source File

SOURCE=.\SmetaProject.cpp
# End Source File
# Begin Source File

SOURCE=.\hlp\SmetaProject.hpj

!IF  "$(CFG)" == "SmetaProject - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help file...
OutDir=.\Release
InputPath=.\hlp\SmetaProject.hpj
InputName=SmetaProject

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "SmetaProject - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help file...
OutDir=.\Debug
InputPath=.\hlp\SmetaProject.hpj
InputName=SmetaProject

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\SmetaProject.rc
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Zdanie.cpp
# End Source File
# Begin Source File

SOURCE=.\ZdanieData.cpp
# End Source File
# Begin Source File

SOURCE=.\ZdanieInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ZdanieResultsDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\DirTreeCtrl.h
# End Source File
# Begin Source File

SOURCE=.\DlgPb.h
# End Source File
# Begin Source File

SOURCE=.\font.h
# End Source File
# Begin Source File

SOURCE=.\msflexgrid.h
# End Source File
# Begin Source File

SOURCE=.\msword9.h
# End Source File
# Begin Source File

SOURCE=.\MyDataTable.h
# End Source File
# Begin Source File

SOURCE=.\MyFunctions.h
# End Source File
# Begin Source File

SOURCE=.\panel.h
# End Source File
# Begin Source File

SOURCE=.\panels.h
# End Source File
# Begin Source File

SOURCE=.\PC_BrowserDlg.h
# End Source File
# Begin Source File

SOURCE=.\picture.h
# End Source File
# Begin Source File

SOURCE=.\Razdel.h
# End Source File
# Begin Source File

SOURCE=.\RazdelAnalog.h
# End Source File
# Begin Source File

SOURCE=.\RazdelZdanie.h
# End Source File
# Begin Source File

SOURCE=.\RazdelZdanieDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h

!IF  "$(CFG)" == "SmetaProject - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=SmetaProject
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "SmetaProject - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=SmetaProject
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm" 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\rowcursor.h
# End Source File
# Begin Source File

SOURCE=.\SmetaProject.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Zdanie.h
# End Source File
# Begin Source File

SOURCE=.\ZdanieData.h
# End Source File
# Begin Source File

SOURCE=.\ZdanieInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\ZdanieResultsDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\addrazde.ico
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\calculat.ico
# End Source File
# Begin Source File

SOURCE=.\res\cup.ico
# End Source File
# Begin Source File

SOURCE=.\res\deletera.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00001.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00002.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00003.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00004.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00005.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon2.ico
# End Source File
# Begin Source File

SOURCE=.\res\idc_copy.ico
# End Source File
# Begin Source File

SOURCE=.\res\open.ico
# End Source File
# Begin Source File

SOURCE=.\res\SmetaProject.ico
# End Source File
# Begin Source File

SOURCE=.\res\SmetaProject.rc2
# End Source File
# Begin Source File

SOURCE=.\res\zdanie1.ico
# End Source File
# End Group
# Begin Group "Help Files"

# PROP Default_Filter "cnt;rtf"
# Begin Source File

SOURCE=.\hlp\AfxDlg.rtf
# End Source File
# Begin Source File

SOURCE=.\hlp\SmetaProject.cnt

!IF  "$(CFG)" == "SmetaProject - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\Release
InputPath=.\hlp\SmetaProject.cnt
InputName=SmetaProject

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ELSEIF  "$(CFG)" == "SmetaProject - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\Debug
InputPath=.\hlp\SmetaProject.cnt
InputName=SmetaProject

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section SmetaProject : {CE6F49B3-3623-4CDB-857B-10BFFE651BB1}
# 	2:13:DirTreeCtrl.h:DirTreeCtrl.h
# 	2:15:DirTreeCtrl.cpp:DirTreeCtrl.cpp
# 	2:19:Application Include:SmetaProject.h
# 	2:19:CLASS: CDirTreeCtrl:CDirTreeCtrl
# End Section
# Section SmetaProject : {8E3867A1-8586-11D1-B16A-00C0F0283628}
# 	2:5:Class:CStatusBar1
# 	2:10:HeaderFile:statusbar.h
# 	2:8:ImplFile:statusbar.cpp
# End Section
# Section SmetaProject : {9F6AA700-D188-11CD-AD48-00AA003C9CB6}
# 	2:5:Class:CRowCursor
# 	2:10:HeaderFile:rowcursor.h
# 	2:8:ImplFile:rowcursor.cpp
# End Section
# Section SmetaProject : {ECBFE847-E4F8-43FE-A8FA-C22EF097A20E}
# 	1:21:IDD_ZDANIEINFO_DIALOG:104
# 	2:16:Resource Include:resource.h
# 	2:21:CLASS: CZdanieInfoDlg:CZdanieInfoDlg
# 	2:15:ZdanieInfoDlg.h:ZdanieInfoDlg.h
# 	2:17:ZdanieInfoDlg.cpp:ZdanieInfoDlg.cpp
# 	2:10:ENUM: enum:enum
# 	2:19:Application Include:SmetaProject.h
# 	2:21:IDD_ZDANIEINFO_DIALOG:IDD_ZDANIEINFO_DIALOG
# End Section
# Section SmetaProject : {79730931-3F87-4ADD-97C5-FF47D9EF7719}
# 	2:19:CLASS: CMyDataTable:CMyDataTable
# 	2:15:MyDataTable.cpp:MyDataTable.cpp
# 	2:19:Application Include:SmetaProject.h
# 	2:13:MyDataTable.h:MyDataTable.h
# End Section
# Section SmetaProject : {E0AB895F-5BB6-4513-807D-9E78253DF61B}
# 	1:21:IDD_PC_BROWSER_DIALOG:105
# 	2:16:Resource Include:resource.h
# 	2:21:IDD_PC_BROWSER_DIALOG:IDD_PC_BROWSER_DIALOG
# 	2:21:CLASS: CPC_BrowserDlg:CPC_BrowserDlg
# 	2:10:ENUM: enum:enum
# 	2:17:PC_BrowserDlg.cpp:PC_BrowserDlg.cpp
# 	2:15:PC_BrowserDlg.h:PC_BrowserDlg.h
# 	2:19:Application Include:SmetaProject.h
# End Section
# Section SmetaProject : {8E3867A4-8586-11D1-B16A-00C0F0283628}
# 	2:5:Class:CPanels
# 	2:10:HeaderFile:panels.h
# 	2:8:ImplFile:panels.cpp
# End Section
# Section SmetaProject : {5F4DF280-531B-11CF-91F6-C2863C385E30}
# 	2:5:Class:CMSFlexGrid
# 	2:10:HeaderFile:msflexgrid.h
# 	2:8:ImplFile:msflexgrid.cpp
# End Section
# Section SmetaProject : {03A5ACC2-2C08-45A3-B208-F4CB80884772}
# 	2:14:RazdelAnalog.h:RazdelAnalog.h
# 	2:16:RazdelAnalog.cpp:RazdelAnalog.cpp
# 	2:20:CLASS: CRazdelAnalog:CRazdelAnalog
# 	2:19:Application Include:SmetaProject.h
# End Section
# Section SmetaProject : {BEF6E003-A874-101A-8BBA-00AA00300CAB}
# 	2:5:Class:COleFont
# 	2:10:HeaderFile:font.h
# 	2:8:ImplFile:font.cpp
# End Section
# Section SmetaProject : {6262D3A0-531B-11CF-91F6-C2863C385E30}
# 	2:21:DefaultSinkHeaderFile:msflexgrid.h
# 	2:16:DefaultSinkClass:CMSFlexGrid
# End Section
# Section SmetaProject : {8E3867AA-8586-11D1-B16A-00C0F0283628}
# 	2:5:Class:CPanel
# 	2:10:HeaderFile:panel.h
# 	2:8:ImplFile:panel.cpp
# End Section
# Section SmetaProject : {0E9A267D-9780-4CFD-9DE6-B1B3557F6E6B}
# 	2:10:Razdel.cpp:Razdel.cpp
# 	2:14:CLASS: CRazdel:CRazdel
# 	2:19:Application Include:SmetaProject.h
# 	2:8:Razdel.h:Razdel.h
# End Section
# Section SmetaProject : {2877CC8F-FF92-48E5-8E9E-6AE0E82D437A}
# 	2:20:CLASS: CRazdelZdanie:CRazdelZdanie
# 	2:14:RazdelZdanie.h:RazdelZdanie.h
# 	2:16:RazdelZdanie.cpp:RazdelZdanie.cpp
# 	2:19:Application Include:SmetaProject.h
# End Section
# Section SmetaProject : {8E3867A3-8586-11D1-B16A-00C0F0283628}
# 	2:21:DefaultSinkHeaderFile:statusbar.h
# 	2:16:DefaultSinkClass:CStatusBar1
# End Section
# Section SmetaProject : {7BF80981-BF32-101A-8BBB-00AA00300CAB}
# 	2:5:Class:CPicture
# 	2:10:HeaderFile:picture.h
# 	2:8:ImplFile:picture.cpp
# End Section
# Section SmetaProject : {D13C9C43-60A6-4AB7-801E-38AEC25910DF}
# 	1:23:IDD_RAZDELZDANIE_DIALOG:103
# 	2:16:Resource Include:resource.h
# 	2:23:IDD_RAZDELZDANIE_DIALOG:IDD_RAZDELZDANIE_DIALOG
# 	2:10:ENUM: enum:enum
# 	2:23:CLASS: CRazdelZdanieDlg:CRazdelZdanieDlg
# 	2:19:RazdelZdanieDlg.cpp:RazdelZdanieDlg.cpp
# 	2:17:RazdelZdanieDlg.h:RazdelZdanieDlg.h
# 	2:19:Application Include:SmetaProject.h
# End Section
