#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

CRITICAL_SECTION cs;
DWORD pid = NULL;
DWORD tid = NULL;

DWORD WINAPI ChildThread() {
    pid = GetCurrentProcessId();
    tid = GetCurrentThreadId();
    for (int i = 0; i < 90; i++) {
        if (i == 30) {
            EnterCriticalSection(&cs);
        }
        else if (i == 60) {
            LeaveCriticalSection(&cs);
        }
        Sleep(100);
        cout << "PID = " << pid << " CHILD TID = " << tid << " : " << i << endl;
    }
    return 0;
}

int main() {
    InitializeCriticalSection(&cs);

    HANDLE ChildA = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ChildThread, NULL, 0, NULL);
    HANDLE ChildB = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ChildThread, NULL, 0, NULL);

    tid = GetCurrentThreadId();
    pid = GetCurrentProcessId();
    for (int i = 0; i < 90; i++) {
        if (i == 30) {
            EnterCriticalSection(&cs);
        }
        else if (i == 60) {
            LeaveCriticalSection(&cs);
        }
        Sleep(100);
        cout << "PID = " << pid << " PARENT TID = " << tid << " : " << i << endl;
    }

    WaitForSingleObject(ChildA, INFINITE);
    WaitForSingleObject(ChildB, INFINITE);

    DeleteCriticalSection(&cs);

    CloseHandle(ChildA);
    CloseHandle(ChildB);
}

