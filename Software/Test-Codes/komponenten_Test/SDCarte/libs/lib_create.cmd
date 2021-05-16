echo on

set includePath=%cd%\lib_include.htemp

REM echo %includePath%

if exist lib_include.h (
	del lib_include.h
)

echo /*Lib Include*/ >> %includePath%

forfiles /S /M *.h /C "cmd /c echo #include @RELPATH >> %includePath%"

ren %includePath% lib_include.h

pause