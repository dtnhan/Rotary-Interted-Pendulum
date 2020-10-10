echo off

REM Always run this script file from the folder where the makefile resides.
REM Do not forget to update "WaijungRoot" to Waijung's root directory.
set WaijungRoot=E:\Learning\Matlab_Library_STM32F4\waijung13_10a
set WaijungGnuArmPath=E:\Learning\Matlab_Library_STM32F4\waijung13_10a\utils\gnu_tools_arm_embedded\bin

echo on
REM Check which toolchain is used
%WaijungGnuArmPath%\arm-none-eabi-gcc --version

%WaijungRoot%\utils\gnumake382-w32\gnumake382-w32 -f BalanceFuzzy.mk 
REM %WaijungRoot%\utils\gnumake382-w32\gnumake382-w32 -f BalanceFuzzy.mk clean-obj

