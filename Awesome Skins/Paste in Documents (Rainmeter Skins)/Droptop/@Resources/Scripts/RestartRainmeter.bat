@echo off
taskkill /f /im "Rainmeter.exe"
timeout 1
start "" %1Rainmeter.exe"
exit