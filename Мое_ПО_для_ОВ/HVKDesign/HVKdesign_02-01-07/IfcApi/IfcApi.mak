# Microsoft Developer Studio Generated NMAKE File, Based on IfcApi.dsp
!IF "$(CFG)" == ""
CFG=IfcApi - Win32 Debug
!MESSAGE No configuration specified. Defaulting to IfcApi - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "IfcApi - Win32 Release" && "$(CFG)" != "IfcApi - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "IfcApi - Win32 Release"

OUTDIR=.\..\Release
INTDIR=.\..\Release.tmp\IfcApi
# Begin Custom Macros
OutDir=.\..\Release
# End Custom Macros

ALL : "$(OUTDIR)\IfcApi.dll"


CLEAN :
	-@erase "$(INTDIR)\Building.obj"
	-@erase "$(INTDIR)\BuildingType.obj"
	-@erase "$(INTDIR)\CalcHeatBalance.obj"
	-@erase "$(INTDIR)\CalcHeatLoss.obj"
	-@erase "$(INTDIR)\City.obj"
	-@erase "$(INTDIR)\DustGasExcretion.obj"
	-@erase "$(INTDIR)\DustGasExcretionType.obj"
	-@erase "$(INTDIR)\Fence.obj"
	-@erase "$(INTDIR)\FenceType.obj"
	-@erase "$(INTDIR)\FenceView.obj"
	-@erase "$(INTDIR)\Floor.obj"
	-@erase "$(INTDIR)\HVKApi.obj"
	-@erase "$(INTDIR)\HVKCalcObject.obj"
	-@erase "$(INTDIR)\HVKDbDirect.obj"
	-@erase "$(INTDIR)\HVKDbObject.obj"
	-@erase "$(INTDIR)\HVKVector.obj"
	-@erase "$(INTDIR)\IfcApi.obj"
	-@erase "$(INTDIR)\IfcApi.pch"
	-@erase "$(INTDIR)\IfcApi.res"
	-@erase "$(INTDIR)\IfcButton.obj"
	-@erase "$(INTDIR)\IfcComboBox.obj"
	-@erase "$(INTDIR)\IfcDialog.obj"
	-@erase "$(INTDIR)\IfcEdit.obj"
	-@erase "$(INTDIR)\IfcFormView.obj"
	-@erase "$(INTDIR)\IfcObject.obj"
	-@erase "$(INTDIR)\IfcTabCtrl.obj"
	-@erase "$(INTDIR)\IfcTreeView.obj"
	-@erase "$(INTDIR)\IfcValue.obj"
	-@erase "$(INTDIR)\IfcWnd.obj"
	-@erase "$(INTDIR)\Party.obj"
	-@erase "$(INTDIR)\Project.obj"
	-@erase "$(INTDIR)\Room.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\WorldSide.obj"
	-@erase "$(OUTDIR)\IfcApi.dll"
	-@erase "$(OUTDIR)\IfcApi.exp"
	-@erase "$(OUTDIR)\IfcApi.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "IFCAPI_EXPORTS" /Fp"$(INTDIR)\IfcApi.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x419 /fo"$(INTDIR)\IfcApi.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\IfcApi.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\IfcApi.pdb" /machine:I386 /def:".\IfcApi.def" /out:"$(OUTDIR)\IfcApi.dll" /implib:"$(OUTDIR)\IfcApi.lib" 
DEF_FILE= \
	".\IfcApi.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Building.obj" \
	"$(INTDIR)\BuildingType.obj" \
	"$(INTDIR)\CalcHeatBalance.obj" \
	"$(INTDIR)\CalcHeatLoss.obj" \
	"$(INTDIR)\City.obj" \
	"$(INTDIR)\DustGasExcretion.obj" \
	"$(INTDIR)\DustGasExcretionType.obj" \
	"$(INTDIR)\Fence.obj" \
	"$(INTDIR)\FenceType.obj" \
	"$(INTDIR)\FenceView.obj" \
	"$(INTDIR)\Floor.obj" \
	"$(INTDIR)\HVKApi.obj" \
	"$(INTDIR)\HVKCalcObject.obj" \
	"$(INTDIR)\HVKDbDirect.obj" \
	"$(INTDIR)\HVKDbObject.obj" \
	"$(INTDIR)\HVKVector.obj" \
	"$(INTDIR)\Party.obj" \
	"$(INTDIR)\Project.obj" \
	"$(INTDIR)\Room.obj" \
	"$(INTDIR)\WorldSide.obj" \
	"$(INTDIR)\IfcApi.obj" \
	"$(INTDIR)\IfcButton.obj" \
	"$(INTDIR)\IfcComboBox.obj" \
	"$(INTDIR)\IfcDialog.obj" \
	"$(INTDIR)\IfcEdit.obj" \
	"$(INTDIR)\IfcFormView.obj" \
	"$(INTDIR)\IfcObject.obj" \
	"$(INTDIR)\IfcTabCtrl.obj" \
	"$(INTDIR)\IfcTreeView.obj" \
	"$(INTDIR)\IfcValue.obj" \
	"$(INTDIR)\IfcWnd.obj" \
	"$(INTDIR)\IfcApi.res"

"$(OUTDIR)\IfcApi.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"

OUTDIR=.\..\Debug
INTDIR=.\..\Debug.tmp\IfcApi
# Begin Custom Macros
OutDir=.\..\Debug
# End Custom Macros

ALL : "$(OUTDIR)\IfcApi.dll" "$(OUTDIR)\IfcApi.bsc"


CLEAN :
	-@erase "$(INTDIR)\Building.obj"
	-@erase "$(INTDIR)\Building.sbr"
	-@erase "$(INTDIR)\BuildingType.obj"
	-@erase "$(INTDIR)\BuildingType.sbr"
	-@erase "$(INTDIR)\CalcHeatBalance.obj"
	-@erase "$(INTDIR)\CalcHeatBalance.sbr"
	-@erase "$(INTDIR)\CalcHeatLoss.obj"
	-@erase "$(INTDIR)\CalcHeatLoss.sbr"
	-@erase "$(INTDIR)\City.obj"
	-@erase "$(INTDIR)\City.sbr"
	-@erase "$(INTDIR)\DustGasExcretion.obj"
	-@erase "$(INTDIR)\DustGasExcretion.sbr"
	-@erase "$(INTDIR)\DustGasExcretionType.obj"
	-@erase "$(INTDIR)\DustGasExcretionType.sbr"
	-@erase "$(INTDIR)\Fence.obj"
	-@erase "$(INTDIR)\Fence.sbr"
	-@erase "$(INTDIR)\FenceType.obj"
	-@erase "$(INTDIR)\FenceType.sbr"
	-@erase "$(INTDIR)\FenceView.obj"
	-@erase "$(INTDIR)\FenceView.sbr"
	-@erase "$(INTDIR)\Floor.obj"
	-@erase "$(INTDIR)\Floor.sbr"
	-@erase "$(INTDIR)\HVKApi.obj"
	-@erase "$(INTDIR)\HVKApi.sbr"
	-@erase "$(INTDIR)\HVKCalcObject.obj"
	-@erase "$(INTDIR)\HVKCalcObject.sbr"
	-@erase "$(INTDIR)\HVKDbDirect.obj"
	-@erase "$(INTDIR)\HVKDbDirect.sbr"
	-@erase "$(INTDIR)\HVKDbObject.obj"
	-@erase "$(INTDIR)\HVKDbObject.sbr"
	-@erase "$(INTDIR)\HVKVector.obj"
	-@erase "$(INTDIR)\HVKVector.sbr"
	-@erase "$(INTDIR)\IfcApi.obj"
	-@erase "$(INTDIR)\IfcApi.pch"
	-@erase "$(INTDIR)\IfcApi.res"
	-@erase "$(INTDIR)\IfcApi.sbr"
	-@erase "$(INTDIR)\IfcButton.obj"
	-@erase "$(INTDIR)\IfcButton.sbr"
	-@erase "$(INTDIR)\IfcComboBox.obj"
	-@erase "$(INTDIR)\IfcComboBox.sbr"
	-@erase "$(INTDIR)\IfcDialog.obj"
	-@erase "$(INTDIR)\IfcDialog.sbr"
	-@erase "$(INTDIR)\IfcEdit.obj"
	-@erase "$(INTDIR)\IfcEdit.sbr"
	-@erase "$(INTDIR)\IfcFormView.obj"
	-@erase "$(INTDIR)\IfcFormView.sbr"
	-@erase "$(INTDIR)\IfcObject.obj"
	-@erase "$(INTDIR)\IfcObject.sbr"
	-@erase "$(INTDIR)\IfcTabCtrl.obj"
	-@erase "$(INTDIR)\IfcTabCtrl.sbr"
	-@erase "$(INTDIR)\IfcTreeView.obj"
	-@erase "$(INTDIR)\IfcTreeView.sbr"
	-@erase "$(INTDIR)\IfcValue.obj"
	-@erase "$(INTDIR)\IfcValue.sbr"
	-@erase "$(INTDIR)\IfcWnd.obj"
	-@erase "$(INTDIR)\IfcWnd.sbr"
	-@erase "$(INTDIR)\Party.obj"
	-@erase "$(INTDIR)\Party.sbr"
	-@erase "$(INTDIR)\Project.obj"
	-@erase "$(INTDIR)\Project.sbr"
	-@erase "$(INTDIR)\Room.obj"
	-@erase "$(INTDIR)\Room.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WorldSide.obj"
	-@erase "$(INTDIR)\WorldSide.sbr"
	-@erase "$(OUTDIR)\IfcApi.bsc"
	-@erase "$(OUTDIR)\IfcApi.dll"
	-@erase "$(OUTDIR)\IfcApi.exp"
	-@erase "$(OUTDIR)\IfcApi.ilk"
	-@erase "$(OUTDIR)\IfcApi.lib"
	-@erase "$(OUTDIR)\IfcApi.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "IFCAPI_EXPORTS" /D "HVKAPI_EXPORTS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\IfcApi.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
RSC_PROJ=/l 0x419 /fo"$(INTDIR)\IfcApi.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\IfcApi.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\Building.sbr" \
	"$(INTDIR)\BuildingType.sbr" \
	"$(INTDIR)\CalcHeatBalance.sbr" \
	"$(INTDIR)\CalcHeatLoss.sbr" \
	"$(INTDIR)\City.sbr" \
	"$(INTDIR)\DustGasExcretion.sbr" \
	"$(INTDIR)\DustGasExcretionType.sbr" \
	"$(INTDIR)\Fence.sbr" \
	"$(INTDIR)\FenceType.sbr" \
	"$(INTDIR)\FenceView.sbr" \
	"$(INTDIR)\Floor.sbr" \
	"$(INTDIR)\HVKApi.sbr" \
	"$(INTDIR)\HVKCalcObject.sbr" \
	"$(INTDIR)\HVKDbDirect.sbr" \
	"$(INTDIR)\HVKDbObject.sbr" \
	"$(INTDIR)\HVKVector.sbr" \
	"$(INTDIR)\Party.sbr" \
	"$(INTDIR)\Project.sbr" \
	"$(INTDIR)\Room.sbr" \
	"$(INTDIR)\WorldSide.sbr" \
	"$(INTDIR)\IfcApi.sbr" \
	"$(INTDIR)\IfcButton.sbr" \
	"$(INTDIR)\IfcComboBox.sbr" \
	"$(INTDIR)\IfcDialog.sbr" \
	"$(INTDIR)\IfcEdit.sbr" \
	"$(INTDIR)\IfcFormView.sbr" \
	"$(INTDIR)\IfcObject.sbr" \
	"$(INTDIR)\IfcTabCtrl.sbr" \
	"$(INTDIR)\IfcTreeView.sbr" \
	"$(INTDIR)\IfcValue.sbr" \
	"$(INTDIR)\IfcWnd.sbr"

"$(OUTDIR)\IfcApi.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\IfcApi.pdb" /debug /machine:I386 /def:".\IfcApi.def" /out:"$(OUTDIR)\IfcApi.dll" /implib:"$(OUTDIR)\IfcApi.lib" /pdbtype:sept 
DEF_FILE= \
	".\IfcApi.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Building.obj" \
	"$(INTDIR)\BuildingType.obj" \
	"$(INTDIR)\CalcHeatBalance.obj" \
	"$(INTDIR)\CalcHeatLoss.obj" \
	"$(INTDIR)\City.obj" \
	"$(INTDIR)\DustGasExcretion.obj" \
	"$(INTDIR)\DustGasExcretionType.obj" \
	"$(INTDIR)\Fence.obj" \
	"$(INTDIR)\FenceType.obj" \
	"$(INTDIR)\FenceView.obj" \
	"$(INTDIR)\Floor.obj" \
	"$(INTDIR)\HVKApi.obj" \
	"$(INTDIR)\HVKCalcObject.obj" \
	"$(INTDIR)\HVKDbDirect.obj" \
	"$(INTDIR)\HVKDbObject.obj" \
	"$(INTDIR)\HVKVector.obj" \
	"$(INTDIR)\Party.obj" \
	"$(INTDIR)\Project.obj" \
	"$(INTDIR)\Room.obj" \
	"$(INTDIR)\WorldSide.obj" \
	"$(INTDIR)\IfcApi.obj" \
	"$(INTDIR)\IfcButton.obj" \
	"$(INTDIR)\IfcComboBox.obj" \
	"$(INTDIR)\IfcDialog.obj" \
	"$(INTDIR)\IfcEdit.obj" \
	"$(INTDIR)\IfcFormView.obj" \
	"$(INTDIR)\IfcObject.obj" \
	"$(INTDIR)\IfcTabCtrl.obj" \
	"$(INTDIR)\IfcTreeView.obj" \
	"$(INTDIR)\IfcValue.obj" \
	"$(INTDIR)\IfcWnd.obj" \
	"$(INTDIR)\IfcApi.res"

"$(OUTDIR)\IfcApi.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("IfcApi.dep")
!INCLUDE "IfcApi.dep"
!ELSE 
!MESSAGE Warning: cannot find "IfcApi.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "IfcApi - Win32 Release" || "$(CFG)" == "IfcApi - Win32 Debug"
SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "IFCAPI_EXPORTS" /Fp"$(INTDIR)\IfcApi.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\IfcApi.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "IFCAPI_EXPORTS" /D "HVKAPI_EXPORTS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\IfcApi.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\IfcApi.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Building.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\Building.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\Building.obj"	"$(INTDIR)\Building.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\BuildingType.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\BuildingType.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\BuildingType.obj"	"$(INTDIR)\BuildingType.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\CalcHeatBalance.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\CalcHeatBalance.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\CalcHeatBalance.obj"	"$(INTDIR)\CalcHeatBalance.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\CalcHeatLoss.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\CalcHeatLoss.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\CalcHeatLoss.obj"	"$(INTDIR)\CalcHeatLoss.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\City.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\City.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\City.obj"	"$(INTDIR)\City.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\DustGasExcretion.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\DustGasExcretion.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\DustGasExcretion.obj"	"$(INTDIR)\DustGasExcretion.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\DustGasExcretionType.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\DustGasExcretionType.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\DustGasExcretionType.obj"	"$(INTDIR)\DustGasExcretionType.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\Fence.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\Fence.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\Fence.obj"	"$(INTDIR)\Fence.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\FenceType.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\FenceType.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\FenceType.obj"	"$(INTDIR)\FenceType.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\FenceView.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\FenceView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\FenceView.obj"	"$(INTDIR)\FenceView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\Floor.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\Floor.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\Floor.obj"	"$(INTDIR)\Floor.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\HVKApi.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\HVKApi.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\HVKApi.obj"	"$(INTDIR)\HVKApi.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\HVKCalcObject.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\HVKCalcObject.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\HVKCalcObject.obj"	"$(INTDIR)\HVKCalcObject.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\HVKDbDirect.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\HVKDbDirect.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\HVKDbDirect.obj"	"$(INTDIR)\HVKDbDirect.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\HVKDbObject.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\HVKDbObject.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\HVKDbObject.obj"	"$(INTDIR)\HVKDbObject.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\HVKVector.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\HVKVector.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\HVKVector.obj"	"$(INTDIR)\HVKVector.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\Party.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\Party.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\Party.obj"	"$(INTDIR)\Party.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\Project.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\Project.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\Project.obj"	"$(INTDIR)\Project.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\Room.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\Room.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\Room.obj"	"$(INTDIR)\Room.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\WorldSide.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\WorldSide.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\WorldSide.obj"	"$(INTDIR)\WorldSide.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\IfcApi.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\IfcApi.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\IfcApi.obj"	"$(INTDIR)\IfcApi.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\IfcApi.rc

"$(INTDIR)\IfcApi.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\IfcButton.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\IfcButton.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\IfcButton.obj"	"$(INTDIR)\IfcButton.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\IfcComboBox.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\IfcComboBox.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\IfcComboBox.obj"	"$(INTDIR)\IfcComboBox.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\IfcDialog.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\IfcDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\IfcDialog.obj"	"$(INTDIR)\IfcDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\IfcEdit.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\IfcEdit.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\IfcEdit.obj"	"$(INTDIR)\IfcEdit.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\IfcFormView.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\IfcFormView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\IfcFormView.obj"	"$(INTDIR)\IfcFormView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\IfcObject.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\IfcObject.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\IfcObject.obj"	"$(INTDIR)\IfcObject.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\IfcTabCtrl.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\IfcTabCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\IfcTabCtrl.obj"	"$(INTDIR)\IfcTabCtrl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\IfcTreeView.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\IfcTreeView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\IfcTreeView.obj"	"$(INTDIR)\IfcTreeView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\IfcValue.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\IfcValue.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\IfcValue.obj"	"$(INTDIR)\IfcValue.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 

SOURCE=.\IfcWnd.cpp

!IF  "$(CFG)" == "IfcApi - Win32 Release"


"$(INTDIR)\IfcWnd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ELSEIF  "$(CFG)" == "IfcApi - Win32 Debug"


"$(INTDIR)\IfcWnd.obj"	"$(INTDIR)\IfcWnd.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\IfcApi.pch"


!ENDIF 


!ENDIF 

