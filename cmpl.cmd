@PATH=c:\MinGW\bin;%PATH%
c:\MinGW\bin\g++.exe -std=c++0x -static-libgcc -static-libstdc++ -o test.exe test.cpp -I"C:\MinGW\include" -L"C:\MinGW\lib" -l"comdlg32"
@pause
