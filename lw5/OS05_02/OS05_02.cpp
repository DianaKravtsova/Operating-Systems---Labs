#include <iostream>
#include "Windows.h"

void printParams(int p1, int p2, int p3);
HANDLE createProcces(int affinityMask, int priorityClass);
// NORMAL 32
// BELOW_NORMAL 16384
// HIGH 128
int main(int argc, char* argv[])
{
	if (argc == 4)
	{
		int affinityMask = atoi(argv[1]);
		int priorityClass1 = atoi(argv[2]);
		int priorityClass2 = atoi(argv[3]);
		SetProcessAffinityMask(GetCurrentProcess(), 0xF);

		printParams(affinityMask, priorityClass1, priorityClass2);

		HANDLE proc1 = createProcces(affinityMask, priorityClass1);
		HANDLE proc2 = createProcces(affinityMask, priorityClass2);

		HANDLE process[] = { proc1, proc2 };

		WaitForMultipleObjects(2, process, TRUE, INFINITY);
		CloseHandle(proc1);
		CloseHandle(proc2);
	}
	else
	{
		std::cout << "Not arguments" << std::endl;
	}

	system("pause");
	return 0;
}

void printParams(int p1, int p2, int p3) {
	std::cout << "processAffinityMask: " << p1 << std::endl;
	std::cout << "processPriorityClass1: " << p2 << std::endl;
	std::cout << "processPriorityClass2: " << p3 << std::endl;
}

HANDLE createProcces(int affinityMask, int priorityClass) {

	LPCWSTR an = L"D:\\3 курс\\ОС\\lw5\\Debug\\OS05_02x.exe";
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(STARTUPINFO)); si.cb = sizeof(STARTUPINFO);


	if (CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
	{
		std::cout << "--Process OS05_02x created\n";
	}
	else {
		std::cout << "--Process OS05_02x not created\n";
	}

	HANDLE h = pi.hProcess;

	SetPriorityClass(h, priorityClass);
	SetProcessAffinityMask(h, affinityMask);

	return h;
}