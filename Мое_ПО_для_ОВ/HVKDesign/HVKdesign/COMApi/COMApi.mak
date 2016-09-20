# Microsoft Developer Studio Generated NMAKE File, Based on COMApi.dsp
!IF "$(CFG)" == ""
CFG=COMApi - Win32 Debug
!MESSAGE No configuration specified. Defaulting to COMApi - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "COMApi - Win32 Release" && "$(CFG)" != "COMApi - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "COMApi.mak" CFG="COMApi - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "COMApi - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "COMApi - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "COMApi - Win32 Release"

OUTDIR=.\..\Release
INTDIR=.\..\Release\ComApi
# Begin Custom Macros
OutDir=.\..\Release
# End Custom Macros

ALL : "$(OUTDIR)\COMApi.dll"


CLEAN :
	-@erase "$(INTDIR)\ADORecord.obj"
	-@erase "$(INTDIR)\COMApi.obj"
	-@erase "$(INTDIR)\COMApi.pch"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\COMApi.dll"
	-@erase "$(OUTDIR)\COMApi.exp"
	-@erase "$(OUTDIR)\COMApi.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "COMAPI_EXPORTS" /Fp"$(INTDIR)\COMApi.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\COMApi.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\COMApi.pdb" /machine:I386 /out:"$(OUTDIR)\COMApi.dll" /implib:"$(OUTDIR)\COMApi.lib" 
LINK32_OBJS= \
	"$(INTDIR)\ADORecord.obj" \
	"$(INTDIR)\COMApi.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\COMApi.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "COMApi - Win32 Debug"

OUTDIR=.\..\Debug
INTDIR=.\..\Debug.tmp\ComApi
# Begin Custom Macros
OutDir=.\..\Debug
# End Custom Macros

ALL : "$(OUTDIR)\COMApi.dll"


CLEAN :
	-@erase "$(INTDIR)\ADORecord.obj"
	-@erase "$(INTDIR)\COMApi.obj"
	-@erase "$(INTDIR)\COMApi.pch"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\COMApi.dll"
	-@erase "$(OUTDIR)\COMApi.exp"
	-@erase "$(OUTDIR)\COMApi.ilk"
	-@erase "$(OUTDIR)\COMApi.lib"
	-@erase "$(OUTDIR)\COMApi.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "COMAPI_EXPORTS" /Fp"$(INTDIR)\COMApi.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\COMApi.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:yes /pdb:"$(OUTDIR)\COMApi.pdb" /debug /machine:I386 /out:"$(OUTDIR)\COMApi.dll" /implib:"$(OUTDIR)\COMApi.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ADORecord.obj" \
	"$(INTDIR)\COMApi.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\COMApi.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("COMApi.dep")
!INCLUDE "COMApi.dep"
!ELSE 
!MESSAGE Warning: cannot find "COMApi.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "COMApi - Win32 Release" || "$(CFG)" == "COMApi - Win32 Debug"
SOURCE=.\ADORecord.cpp

"$(INTDIR)\ADORecord.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COMApi.pch"


SOURCE=.\COMApi.cpp

"$(INTDIR)\COMApi.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COMApi.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "COMApi - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "COMAPI_EXPORTS" /Fp"$(INTDIR)\COMApi.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\COMApi.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "COMApi - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "COMAPI_EXPORTS" /Fp"$(INTDIR)\COMApi.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\COMApi.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

