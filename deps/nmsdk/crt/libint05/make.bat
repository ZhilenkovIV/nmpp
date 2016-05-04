@echo off
BREAK ON
if "%NEURO%" == "" goto Usage1

echo ----------- Build libint library -----------
echo ----------- Build libint library ----------- >libint.log
for %%i in (*.asm) do nmcc %%i -Snolink >>libint.log -6405
for %%i in (*.cpp) do nmcc %%i -Snolink >>libint.log -6405 -O2
libr -c libint05.lib *.elf >>libint.log

echo -------------------------- Build done ----------------------------
echo -------------------------- Build done ---------------------------->>libint.log
goto exit

:Usage1
echo The environment variable NEURO must be set to point
echo to the root of your NM SDK installation.
goto exit

:exit
