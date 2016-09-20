@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by OV.HPJ. >"hlp\OV.hm"
echo. >>"hlp\OV.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\OV.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\OV.hm"
echo. >>"hlp\OV.hm"
echo // Prompts (IDP_*) >>"hlp\OV.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\OV.hm"
echo. >>"hlp\OV.hm"
echo // Resources (IDR_*) >>"hlp\OV.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\OV.hm"
echo. >>"hlp\OV.hm"
echo // Dialogs (IDD_*) >>"hlp\OV.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\OV.hm"
echo. >>"hlp\OV.hm"
echo // Frame Controls (IDW_*) >>"hlp\OV.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\OV.hm"
REM -- Make help for Project OV


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\OV.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\OV.hlp" goto :Error
if not exist "hlp\OV.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\OV.hlp" Debug
if exist Debug\nul copy "hlp\OV.cnt" Debug
if exist Release\nul copy "hlp\OV.hlp" Release
if exist Release\nul copy "hlp\OV.cnt" Release
echo.
goto :done

:Error
echo hlp\OV.hpj(1) : error: Problem encountered creating help file

:done
echo.
