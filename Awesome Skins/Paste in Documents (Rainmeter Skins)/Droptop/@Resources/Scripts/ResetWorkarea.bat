taskkill /T /F /IM "Droptop Rainmeter.exe"
taskkill /T /F /IM "reg.exe"
cd %~dp0
cd ..
cd ..
cd ..
cd "Droptop folders\Other files\Addons"
start "" %1Droptop Folders\Other files\Addons\Droptop Rainmeter.exe" -"0"
exit
