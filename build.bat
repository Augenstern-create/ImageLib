@echo off

set ROOT_DIR=%~dp0
set BUILD_DIR=%ROOT_DIR%build
set BUILD_TYPE=Release

rem 删除之前编译文件,重新编译
if exist "%BUILD_DIR%" (
    echo %BUILD_DIR%
    rmdir /s /q "%BUILD_DIR%"
)

mkdir "%BUILD_DIR%"
cd "%BUILD_DIR%"

cmake -A x64 ^
-DCMAKE_BUILD_TYPE=%BUILD_TYPE% ^
-DCMAKE_SYSTEM_NAME=Windows ^
-DINTTYPES_FORMAT=C99 ^
-DAUTO_EXPOSURE=ON ^
-DBUILD_DIR=%BUILD_DIR%  ^
..

cmake --build . --config %BUILD_TYPE% -j8

cd %BUILD_DIR%\%BUILD_TYPE%
"demo.exe"
cd ..\..