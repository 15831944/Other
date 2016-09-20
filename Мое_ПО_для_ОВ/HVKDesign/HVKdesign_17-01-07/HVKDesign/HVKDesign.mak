# Microsoft Developer Studio Generated NMAKE File, Based on HVKDesign.dsp
!IF "$(CFG)" == ""
CFG=HVKDesign - Win32 Debug
!MESSAGE No configuration specified. Defaulting to HVKDesign - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "HVKDesign - Win32 Release" && "$(CFG)" != "HVKDesign - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "HVKDesign.mak" CFG="HVKDesign - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "HVKDesign - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "HVKDesign - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "HVKDesign - Win32 Release"

OUTDIR=.\..\Release
INTDIR=.\..\Release.tmp\HVKDesign
# Begin Custom Macros
OutDir=.\..\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : ".\..\Release\HVKDesign.hlp" ".\..\Release\HVKDesign.cnt" "$(OUTDIR)\HVKDesign.exe" "$(OUTDIR)\HVKDesign.bsc"

!ELSE 

ALL : "IfcApi - Win32 Release" "COMApi - Win32 Release" ".\..\Release\HVKDesign.hlp" ".\..\Release\HVKDesign.cnt" "$(OUTDIR)\HVKDesign.exe" "$(OUTDIR)\HVKDesign.bsc"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"COMApi - Win32 ReleaseCLEAN" "IfcApi - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\HVKDesign.obj"
	-@erase "$(INTDIR)\HVKDesign.res"
	-@erase "$(INTDIR)\HVKDesign.sbr"
	-@erase "$(INTDIR)\HVKInitDlg.obj"
	-@erase "$(INTDIR)\HVKInitDlg.sbr"
	-@erase "$(INTDIR)\HVKMainDoc.obj"
	-@erase "$(INTDIR)\HVKMainDoc.sbr"
	-@erase "$(INTDIR)\HVKMainView.obj"
	-@erase "$(INTDIR)\HVKMainView.sbr"
	-@erase "$(INTDIR)\HVKTreeView.obj"
	-@erase "$(INTDIR)\HVKTreeView.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\HVKDesign.bsc"
	-@erase "$(OUTDIR)\HVKDesign.exe"
	-@erase ".\..\Release\HVKDesign.cnt"
	-@erase ".\..\Release\HVKDesign.hlp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\HVKDesign.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\HVKDesign.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\HVKDesign.sbr" \
	"$(INTDIR)\HVKInitDlg.sbr" \
	"$(INTDIR)\HVKMainDoc.sbr" \
	"$(INTDIR)\HVKMainView.sbr" \
	"$(INTDIR)\HVKTreeView.sbr" \
	"$(INTDIR)\MainFrm.sbr"

"$(OUTDIR)\HVKDesign.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\HVKDesign.pdb" /machine:I386 /out:"$(OUTDIR)\HVKDesign.exe" 
LINK32_OBJS= \
	"$(INTDIR)\HVKDesign.obj" \
	"$(INTDIR)\HVKInitDlg.obj" \
	"$(INTDIR)\HVKMainDoc.obj" \
	"$(INTDIR)\HVKMainView.obj" \
	"$(INTDIR)\HVKTreeView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\HVKDesign.res" \
	"$(OUTDIR)\COMApi.lib" \
	"$(OUTDIR)\IfcApi.lib"

"$(OUTDIR)\HVKDesign.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "HVKDesign - Win32 Debug"

OUTDIR=.\..\Debug
INTDIR=.\..\Debug.tmp\HVKDesign
# Begin Custom Macros
OutDir=.\..\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : ".\..\Debug\HVKDesign.hlp" ".\..\Debug\HVKDesign.cnt" "$(OUTDIR)\HVKDesign.exe" "$(OUTDIR)\HVKDesign.bsc"

!ELSE 

ALL : "IfcApi - Win32 Debug" "COMApi - Win32 Debug" ".\..\Debug\HVKDesign.hlp" ".\..\Debug\HVKDesign.cnt" "$(OUTDIR)\HVKDesign.exe" "$(OUTDIR)\HVKDesign.bsc"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"COMApi - Win32 DebugCLEAN" "IfcApi - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\HVKDesign.obj"
	-@erase "$(INTDIR)\HVKDesign.res"
	-@erase "$(INTDIR)\HVKDesign.sbr"
	-@erase "$(INTDIR)\HVKInitDlg.obj"
	-@erase "$(INTDIR)\HVKInitDlg.sbr"
	-@erase "$(INTDIR)\HVKMainDoc.obj"
	-@erase "$(INTDIR)\HVKMainDoc.sbr"
	-@erase "$(INTDIR)\HVKMainView.obj"
	-@erase "$(INTDIR)\HVKMainView.sbr"
	-@erase "$(INTDIR)\HVKTreeView.obj"
	-@erase "$(INTDIR)\HVKTreeView.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\HVKDesign.bsc"
	-@erase "$(OUTDIR)\HVKDesign.exe"
	-@erase "$(OUTDIR)\HVKDesign.ilk"
	-@erase "$(OUTDIR)\HVKDesign.pdb"
	-@erase ".\..\Debug\HVKDesign.cnt"
	-@erase ".\..\Debug\HVKDesign.hlp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /vd0 /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x419 /fo"$(INTDIR)\HVKDesign.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\HVKDesign.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\HVKDesign.sbr" \
	"$(INTDIR)\HVKInitDlg.sbr" \
	"$(INTDIR)\HVKMainDoc.sbr" \
	"$(INTDIR)\HVKMainView.sbr" \
	"$(INTDIR)\HVKTreeView.sbr" \
	"$(INTDIR)\MainFrm.sbr"

"$(OUTDIR)\HVKDesign.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\HVKDesign.pdb" /debug /machine:I386 /out:"$(OUTDIR)\HVKDesign.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\HVKDesign.obj" \
	"$(INTDIR)\HVKInitDlg.obj" \
	"$(INTDIR)\HVKMainDoc.obj" \
	"$(INTDIR)\HVKMainView.obj" \
	"$(INTDIR)\HVKTreeView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\HVKDesign.res" \
	"$(OUTDIR)\COMApi.lib" \
	"$(OUTDIR)\IfcApi.lib"

"$(OUTDIR)\HVKDesign.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("HVKDesign.dep")
!INCLUDE "HVKDesign.dep"
!ELSE 
!MESSAGE Warning: cannot find "HVKDesign.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "HVKDesign - Win32 Release" || "$(CFG)" == "HVKDesign - Win32 Debug"
SOURCE=.\HVKDesign.cpp

"$(INTDIR)\HVKDesign.obj"	"$(INTDIR)\HVKDesign.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\hlp\HVKDesign.hpj

!IF  "$(CFG)" == "HVKDesign - Win32 Release"

OutDir=.\..\Release
TargetName=HVKDesign
InputPath=.\hlp\HVKDesign.hpj
InputName=HVKDesign
USERDEP__HVKDE="hlp\AfxCore.rtf"	"hlp\AfxPrint.rtf"	"hlp\$(TargetName).hm"	

"..\Release\HVKDesign.hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)" $(USERDEP__HVKDE)
	<<tempfile.bat 
	@echo off 
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
<< 
	

!ELSEIF  "$(CFG)" == "HVKDesign - Win32 Debug"

OutDir=.\..\Debug
TargetName=HVKDesign
InputPath=.\hlp\HVKDesign.hpj
InputName=HVKDesign
USERDEP__HVKDE="hlp\AfxCore.rtf"	"hlp\AfxPrint.rtf"	"hlp\$(TargetName).hm"	

"..\Debug\HVKDesign.hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)" $(USERDEP__HVKDE)
	<<tempfile.bat 
	@echo off 
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
<< 
	

!ENDIF 

SOURCE=.\HVKDesign.rc

"$(INTDIR)\HVKDesign.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\HVKInitDlg.cpp

"$(INTDIR)\HVKInitDlg.obj"	"$(INTDIR)\HVKInitDlg.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\HVKMainDoc.cpp

"$(INTDIR)\HVKMainDoc.obj"	"$(INTDIR)\HVKMainDoc.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\HVKMainView.cpp

"$(INTDIR)\HVKMainView.obj"	"$(INTDIR)\HVKMainView.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\HVKTreeView.cpp

"$(INTDIR)\HVKTreeView.obj"	"$(INTDIR)\HVKTreeView.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Resource.h

!IF  "$(CFG)" == "HVKDesign - Win32 Release"

TargetName=HVKDesign
InputPath=.\Resource.h

".\hlp\HVKDesign.hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
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
<< 
	

!ELSEIF  "$(CFG)" == "HVKDesign - Win32 Debug"

TargetName=HVKDesign
InputPath=.\Resource.h

".\hlp\HVKDesign.hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
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
<< 
	

!ENDIF 

SOURCE=.\hlp\HVKDesign.cnt

!IF  "$(CFG)" == "HVKDesign - Win32 Release"

OutDir=.\..\Release
InputPath=.\hlp\HVKDesign.cnt
InputName=HVKDesign

"..\Release\HVKDesign.cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	copy "hlp\$(InputName).cnt" $(OutDir)
<< 
	

!ELSEIF  "$(CFG)" == "HVKDesign - Win32 Debug"

OutDir=.\..\Debug
InputPath=.\hlp\HVKDesign.cnt
InputName=HVKDesign

"..\Debug\HVKDesign.cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	copy "hlp\$(InputName).cnt" $(OutDir)
<< 
	

!ENDIF 

!IF  "$(CFG)" == "HVKDesign - Win32 Release"

"COMApi - Win32 Release" : 
   cd "\Татьяна\Мои документы\УЧЕБА_В03ПО\Диплом\Мой диплом\Sources\HVKdesign\COMApi"
   $(MAKE) /$(MAKEFLAGS) /F ".\COMApi.mak" CFG="COMApi - Win32 Release" 
   cd "..\HVKDesign"

"COMApi - Win32 ReleaseCLEAN" : 
   cd "\Татьяна\Мои документы\УЧЕБА_В03ПО\Диплом\Мой диплом\Sources\HVKdesign\COMApi"
   $(MAKE) /$(MAKEFLAGS) /F ".\COMApi.mak" CFG="COMApi - Win32 Release" RECURSE=1 CLEAN 
   cd "..\HVKDesign"

!ELSEIF  "$(CFG)" == "HVKDesign - Win32 Debug"

"COMApi - Win32 Debug" : 
   cd "\Татьяна\Мои документы\УЧЕБА_В03ПО\Диплом\Мой диплом\Sources\HVKdesign\COMApi"
   $(MAKE) /$(MAKEFLAGS) /F ".\COMApi.mak" CFG="COMApi - Win32 Debug" 
   cd "..\HVKDesign"

"COMApi - Win32 DebugCLEAN" : 
   cd "\Татьяна\Мои документы\УЧЕБА_В03ПО\Диплом\Мой диплом\Sources\HVKdesign\COMApi"
   $(MAKE) /$(MAKEFLAGS) /F ".\COMApi.mak" CFG="COMApi - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\HVKDesign"

!ENDIF 

!IF  "$(CFG)" == "HVKDesign - Win32 Release"

"IfcApi - Win32 Release" : 
   cd "\Татьяна\Мои документы\УЧЕБА_В03ПО\Диплом\Мой диплом\Sources\HVKdesign\IfcApi"
   $(MAKE) /$(MAKEFLAGS) /F ".\IfcApi.mak" CFG="IfcApi - Win32 Release" 
   cd "..\HVKDesign"

"IfcApi - Win32 ReleaseCLEAN" : 
   cd "\Татьяна\Мои документы\УЧЕБА_В03ПО\Диплом\Мой диплом\Sources\HVKdesign\IfcApi"
   $(MAKE) /$(MAKEFLAGS) /F ".\IfcApi.mak" CFG="IfcApi - Win32 Release" RECURSE=1 CLEAN 
   cd "..\HVKDesign"

!ELSEIF  "$(CFG)" == "HVKDesign - Win32 Debug"

"IfcApi - Win32 Debug" : 
   cd "\Татьяна\Мои документы\УЧЕБА_В03ПО\Диплом\Мой диплом\Sources\HVKdesign\IfcApi"
   $(MAKE) /$(MAKEFLAGS) /F ".\IfcApi.mak" CFG="IfcApi - Win32 Debug" 
   cd "..\HVKDesign"

"IfcApi - Win32 DebugCLEAN" : 
   cd "\Татьяна\Мои документы\УЧЕБА_В03ПО\Диплом\Мой диплом\Sources\HVKdesign\IfcApi"
   $(MAKE) /$(MAKEFLAGS) /F ".\IfcApi.mak" CFG="IfcApi - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\HVKDesign"

!ENDIF 


!ENDIF 

