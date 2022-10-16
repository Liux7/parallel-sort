set i=100
:L1
echo %i% 
..\bin\omptest.exe %i% >> res.txt
set /a i=(%i%)*10
if %i% LEQ 10000000 goto L1