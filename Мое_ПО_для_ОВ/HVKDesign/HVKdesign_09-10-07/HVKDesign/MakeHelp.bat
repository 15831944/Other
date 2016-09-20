@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by HVKDESIGN.HPJ. >"hlp\HVKDesign.hm"
echo. >>"hlp\HVKDesign.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\HVKDesign.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\HVKDesign.hm"
echo. >>"hlp\HVKDesign.hm"
echo // Prompts (IDP_*) >>"hlp\HVKDesign.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\HVKDesign.hm"
echo. >>"hlp\HVKDesign.hm"
echo // Resources (IDR_*) >>"hlp\HVKDesign.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\HVKDesign.hm"
echo. >>"hlp\HVKDesign.hm"
echo // Dialogs (IDD_*) >>"hlp\HVKDesign.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\HVKDesign.hm"
echo. >>"hlp\HVKDesign.hm"
echo // Frame Controls (IDW_*) >>"hlp\HVKDesign.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\HVKDesign.hm"
REM -- Make help for Project HVKDESIGN


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\HVKDesign.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\HVKDesign.hlp" goto :Error
if not exist "hlp\HVKDesign.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\HVKDesign.hlp" Debug
if exist Debug\nul copy "hlp\HVKDesign.cnt" Debug
if exist Release\nul copy "hlp\HVKDesign.hlp" Release
if exist Release\nul copy "hlp\HVKDesign.cnt" Release
echo.
goto :done

:Error
echo hlp\HVKDesign.hpj(1) : error: Problem encountered creating help file

:done
echo.
