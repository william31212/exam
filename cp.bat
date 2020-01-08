@echo off

cls

echo COMPILING...

g++ --std=c++14 %1.cpp -o %1.exe

if %ERRORLEVEL% EQU 0 (
	echo FINISHED
	%1.exe < %1.in > %1.out
)