@echo off
if not exist include\stdio.h goto notbc
if not exist cslib\tools\prefix.mak goto notcslib

type cslib\tools\prefix.mak > cslib\windows\makefile
cd >> cslib\windows\makefile
type cslib\tools\windows.mak >> cslib\windows\makefile

echo Installing #include files
cd include
if not exist dosgraph.h rename graphics.h dosgraph.h
copy ..\cslib\include\*.h
cd ..

if not exist cslib\dos\genlib.c goto enddos
echo Making DOS version of the libraries
type cslib\tools\prefix.mak > cslib\dos\makefile
cd >> cslib\dos\makefile
type cslib\tools\dos.mak >> cslib\dos\makefile
cd cslib\dos
make
cd ..\..
:enddos

if not exist cslib\windows\genlib.c goto endwind
echo Making Windows version of the libraries
type cslib\tools\prefix.mak > cslib\windows\makefile
cd >> cslib\windows\makefile
type cslib\tools\windows.mak >> cslib\windows\makefile
cd cslib\windows
make
cd ..\..
:endwind

echo Installation complete
goto end

:notbc
echo Error: This file must be executed in the Borland compiler directory.
goto end

:notcslib
echo Error: The CSLIB subdirectory must have been installed in the
echo Borland compiler directory.

:end

