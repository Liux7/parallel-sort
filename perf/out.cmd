set i=1
:L1
echo %i% 
..\test.exe %i% >> res.txt
set /a i=(%i%)*2
if %i% LEQ 2048 goto L1