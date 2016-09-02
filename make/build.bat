@echo off

set DEBUGVARS=/Od /Zi /FC /nologo /Tp
set RELEASEVARS=/O2 /Oi /FC /W4 /wd4100 /nologo /Tc

set code=..\code\sdl_main.cpp

set includes=/I "..\deps\includes"

set libs=/link ^
		/LIBPATH:..\deps\libs\ SDL2.lib SDL2main.lib

set options=%DEBUGVARS% %code% %includes% %libs%

mkdir ..\bin
xcopy /D "..\deps\libs\*.dll" "..\bin\"

pushd ..\bin
cl -EHsc %options% /SUBSYSTEM:CONSOLE
popd