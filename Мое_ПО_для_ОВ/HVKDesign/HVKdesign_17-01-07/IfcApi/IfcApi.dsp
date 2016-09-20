# Microsoft Developer Studio Project File - Name="IfcApi" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=IfcApi - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "IfcApi.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "IfcApi.mak" CFG="IfcApi - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "IfcApi - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "IfcApi - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "IfcApi - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\Release"
# PROP Intermediate_Dir "..\Release.tmp\IfcApi"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "IFCAPI_EXPORTS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x419 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386

!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\Debug"
# PROP Intermediate_Dir "..\Debug.tmp\IfcApi"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "IFCAPI_EXPORTS" /D "HVKAPI_EXPORTS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x419 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /nodefaultlib

!ENDIF 

# Begin Target

# Name "IfcApi - Win32 Release"
# Name "IfcApi - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\IfcApi.rc2
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "HVKAPI"

# PROP Default_Filter ""
# Begin Group "Source Files No. 1"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Building.cpp
# End Source File
# Begin Source File

SOURCE=.\BuildingType.cpp
# End Source File
# Begin Source File

SOURCE=.\CalcHeatBalance.cpp
# End Source File
# Begin Source File

SOURCE=.\CalcHeatLoss.cpp
# End Source File
# Begin Source File

SOURCE=.\City.cpp
# End Source File
# Begin Source File

SOURCE=.\DustGasExcretion.cpp
# End Source File
# Begin Source File

SOURCE=.\DustGasExcretionType.cpp
# End Source File
# Begin Source File

SOURCE=.\Fence.cpp
# End Source File
# Begin Source File

SOURCE=.\FenceType.cpp
# End Source File
# Begin Source File

SOURCE=.\FenceView.cpp
# End Source File
# Begin Source File

SOURCE=.\Floor.cpp
# End Source File
# Begin Source File

SOURCE=.\HVKApi.cpp
# End Source File
# Begin Source File

SOURCE=.\HVKCalcObject.cpp
# End Source File
# Begin Source File

SOURCE=.\HVKDbDirect.cpp
# End Source File
# Begin Source File

SOURCE=.\HVKDbObject.cpp
# End Source File
# Begin Source File

SOURCE=.\HVKVector.cpp
# End Source File
# Begin Source File

SOURCE=.\Party.cpp
# End Source File
# Begin Source File

SOURCE=.\Project.cpp
# End Source File
# Begin Source File

SOURCE=.\Room.cpp
# End Source File
# Begin Source File

SOURCE=.\WorldSide.cpp
# End Source File
# End Group
# Begin Group "Header Files No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Building.h
# End Source File
# Begin Source File

SOURCE=.\BuildingType.h
# End Source File
# Begin Source File

SOURCE=.\CalcHeatBalance.h
# End Source File
# Begin Source File

SOURCE=.\CalcHeatLoss.h
# End Source File
# Begin Source File

SOURCE=.\City.h
# End Source File
# Begin Source File

SOURCE=.\DustGasExcretion.h
# End Source File
# Begin Source File

SOURCE=.\DustGasExcretionType.h
# End Source File
# Begin Source File

SOURCE=.\Fence.h
# End Source File
# Begin Source File

SOURCE=.\FenceType.h
# End Source File
# Begin Source File

SOURCE=.\FenceView.h
# End Source File
# Begin Source File

SOURCE=.\Floor.h
# End Source File
# Begin Source File

SOURCE=.\HVKApi.h
# End Source File
# Begin Source File

SOURCE=.\HVKCalcObject.h
# End Source File
# Begin Source File

SOURCE=.\HVKDbDirect.h
# End Source File
# Begin Source File

SOURCE=.\HVKDbObject.h
# End Source File
# Begin Source File

SOURCE=.\HVKVector.h
# End Source File
# Begin Source File

SOURCE=.\Party.h
# End Source File
# Begin Source File

SOURCE=.\Project.h
# End Source File
# Begin Source File

SOURCE=.\Room.h
# End Source File
# Begin Source File

SOURCE=.\WorldSide.h
# End Source File
# End Group
# End Group
# Begin Group "IFCAPI"

# PROP Default_Filter ""
# Begin Group "Source Files No. 2"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\IfcApi.cpp
# End Source File
# Begin Source File

SOURCE=.\IfcApi.def
# End Source File
# Begin Source File

SOURCE=.\IfcApi.rc
# End Source File
# Begin Source File

SOURCE=.\IfcButton.cpp
# End Source File
# Begin Source File

SOURCE=.\IfcComboBox.cpp
# End Source File
# Begin Source File

SOURCE=.\IfcDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\IfcEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\IfcFormView.cpp
# End Source File
# Begin Source File

SOURCE=.\IfcObject.cpp
# End Source File
# Begin Source File

SOURCE=.\IfcTabCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\IfcTreeView.cpp
# End Source File
# Begin Source File

SOURCE=.\IfcValue.cpp
# End Source File
# Begin Source File

SOURCE=.\IfcWnd.cpp
# End Source File
# End Group
# Begin Group "Header Files No. 2"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\IfcApi.h
# End Source File
# Begin Source File

SOURCE=.\IfcButton.h
# End Source File
# Begin Source File

SOURCE=.\IfcComboBox.h
# End Source File
# Begin Source File

SOURCE=.\IfcDialog.h
# End Source File
# Begin Source File

SOURCE=.\IfcEdit.h
# End Source File
# Begin Source File

SOURCE=.\IfcFormView.h
# End Source File
# Begin Source File

SOURCE=.\IfcObject.h
# End Source File
# Begin Source File

SOURCE=.\IfcTabCtrl.h
# End Source File
# Begin Source File

SOURCE=.\IfcTreeView.h
# End Source File
# Begin Source File

SOURCE=.\IfcValue.h
# End Source File
# Begin Source File

SOURCE=.\IfcWnd.h
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=.\msado15.tlh
# End Source File
# Begin Source File

SOURCE=.\msado15.tli
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
