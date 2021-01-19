echo off
echo параметры %*
echo параметр 1 %1
echo параметр 2 %2
echo параметр 3 %3

set /a plus = %1 + %2
set /a mult = %1 * %2 
set /a del = %3 / %2 
set /a minus= %2 - %1 
set /a res = minus * (%1-%2)
echo %1 + %2 = %plus%
echo %1 * %2 = %mult% 
echo %3 / %2 = %del% 
echo %2 - %1 = %minus% 
echo (%2 - %1)*(%1-%2) = %res% 