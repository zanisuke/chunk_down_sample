set ROOT_PATH=%~dp0..
set ENGINE_PATH=%ROOT_PATH%\..\..\engine\ue4.26\Engine
set RUN_UAT_BAT=%ENGINE_PATH%\Build\BatchFiles\RunUAT.bat

set uebp_LogFolder=D:\work\unreal_plugin\projects\sample\BuildLog

%RUN_UAT_BAT% BuildCookRun ^
    -nocompile ^
    -nocompileeditor ^
    -project=%ROOT_PATH%\sample.uproject ^
    -targetplatform="Win64" ^
    -cook ^
    -build ^
    -stage ^
    -package ^
    -archive -archivedirectory ^
    -pak -compress ^