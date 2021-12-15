@echo off

set cwd=%~dp0
powershell.exe -executionpolicy remotesigned -File %cwd%get_ipv4.ps1 > %cwd%ipv4.log

set /p ipv4=<%cwd%ipv4.log
echo =====================================================
echo Ip-Adresse: %ipv4%
echo =====================================================

taskkill /f /im "WinNFSd.exe"

call %cwd%\WinNFSd.exe -addr %ipv4% -log on -pathFile %cwd%exports.txt
pause