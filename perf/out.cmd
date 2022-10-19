set i=1024
:L1
echo %i% 
..\bin\omptest.exe %i% >> res.txt
set /a i=(%i%)*4
if %i% LEQ 1048576 goto L1