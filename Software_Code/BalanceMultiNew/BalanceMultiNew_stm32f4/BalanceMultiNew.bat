echo off

path = %path%;E:\Learning\Matlab_Library_STM32F4\waijung13_10a\utils\gnumake382-w32
path = %path%;C:\KeilARM\ARM\ARMCC\BIN

echo on
gnumake382-w32 -f BalanceMultiNew.mk

