bin_boot.exe -f ..\Debug\Exe\CV060.bin -o sys_cpu.bin -i "CV060 sys" -j -u 1 -h 0x01000600 -s 0x01000600

bin_boot.exe -f test_2.bin -o sys_user.bin -i "USER Test" -j -u 1 -h 0x01000600 -s 0x01000600

rem bin_boot.exe -f ..\..\..\..\..\User\20111108_Zolochi\20111108_C1_test.bin   -o sys_user.bin -i  "USER Zolochi 1" -j -u 1 -h 0x01000600 -s 0x01000600

rem bin_boot.exe -f ..\..\..\..\..\User\20111108_Zolochi\20111108_C14.bin -o sys_user_14.bin -i "USER Zolochi 14" -j -u 1 -h 0x01000600 -s 0x01000600

bin_boot.exe -f ..\..\..\..\..\User\20111128_Shevchenko16_2.bin -o sys_user_sh1.bin -i "USER Shevchenko 16" -j -u 1 -h 0x01000600 -s 0x01000600
bin_boot.exe -f ..\..\..\..\..\User\20111128_Shevchenko16_2.bin -o sys_user_sh2.bin -i "USER Shevchenko 16" -j -u 1 -h 0x01000600 -s 0x01000600

bin_boot.exe -f ..\..\..\..\..\User\20111128_Shevchenko16_2_inverted.bin -o sys_user_sh2_inv.bin -i "USER Shevchenko 16 inv" -j -u 1 -h 0x01000600 -s 0x01000600
bin_boot.exe -f ..\..\..\..\..\User\20111128_Shevchenko16_2_under.bin -o sys_user_under.bin -i "USER Shevchenko 16 under" -j -u 1 -h 0x01000600 -s 0x01000600

rem bin_boot.exe -f ..\..\..\..\..\User\test_pulses.bin -o sys_user.bin -i "USER Pulses" -j -u 1 -h 0x01000600 -s 0x01000600

rem bin_boot.exe -f ..\Test\1.bin -o sys_user_1.bin -i "Test" -j -u 1 -h 0x01000600 -s 0x01000600

bin_boot.exe -f ..\..\..\..\..\User\test_2.bin -o sys_user.bin -i "USER Test" -j -u 1 -h 0x01000600 -s 0x01000600