#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

int main()
{
    DWORD pid = GetCurrentProcessId();
    for (int i = 0; i < 90; i++) {
        
        Sleep(100);
        std::cout << "PID = " << pid << " : " << i << std::endl;
    }

    system("pause");
    return 0;
}
