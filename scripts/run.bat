@echo off

if not exist "..\build\dist\ascension.exe" (
    echo missing executable, attempting to build first...
    call build.bat
)

pushd ..\build\dist
.\ascension
popd