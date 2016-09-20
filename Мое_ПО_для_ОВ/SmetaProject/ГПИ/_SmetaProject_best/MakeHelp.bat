@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by SMETAPROJECT.HPJ. >"hlp\SmetaProject.hm"
echo. >>"hlp\SmetaProject.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\SmetaProject.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\SmetaProject.hm"
echo. >>"hlp\SmetaProject.hm"
echo // Prompts (IDP_*) >>"hlp\SmetaProject.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\SmetaProject.hm"
echo. >>"hlp\SmetaProject.hm"
echo // Resources (IDR_*) >>"hlp\SmetaProject.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\SmetaProject.hm"
echo. >>"hlp\SmetaProject.hm"
echo // Dialogs (IDD_*) >>"hlp\SmetaProject.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\SmetaProject.hm"
echo. >>"hlp\SmetaProject.hm"
echo // Frame Controls (IDW_*) >>"hlp\SmetaProject.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\SmetaProject.hm"
REM -- Make help for Project SMETAPROJECT


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\SmetaProject.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\SmetaProject.hlp" goto :Error
if not exist "hlp\SmetaProject.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\SmetaProject.hlp" Debug
if exist Debug\nul copy "hlp\SmetaProject.cnt" Debug
if exist Release\nul copy "hlp\SmetaProject.hlp" Release
if exist Release\nul copy "hlp\SmetaProject.cnt" Release
echo.
goto :done

:Error
echo hlp\SmetaProject.hpj(1) : error: Problem encountered creating help file

:done
echo.
