#include <iostream>
#include "Windows.h"

#define LINE std::cout<<"------------------------------"<<std::endl;

void printPID();
void printTID();
void printProcessPrty(HANDLE h);
void printThreadPrty(HANDLE h);
void printAffinityMask(HANDLE hp, HANDLE ht);

int main()
{
	HANDLE hp = GetCurrentProcess();
	HANDLE ht = GetCurrentThread();

	for (int i = 0; i < 1000000; i++)
	{
		Sleep(200);
		if (i % 1000 == 0) {
			std::cout << "----- " << i << " -----" << std::endl;
			printPID();
			printProcessPrty(hp);
			printTID();
			printThreadPrty(ht);
			printAffinityMask(hp, ht);
		}
	}
	system("pause");
	return 0;
}

void printPID() {
	std::cout << "--------->Current PID: " << GetCurrentProcessId() << std::endl;
}
void printTID() {
	std::cout << "--------->Current TID: " << GetCurrentThreadId() << std::endl;
}
void printProcessPrty(HANDLE h) {
	DWORD prty = GetPriorityClass(h);

	switch (prty) {
	case IDLE_PRIORITY_CLASS: std::cout << "--------->PRIORITY-->IDLE_PRIORITY_CLASS" << std::endl; break;
	case BELOW_NORMAL_PRIORITY_CLASS: std::cout << "--------->PRIORITY-->BELOW_NORMAL_PRIORITY_CLASS" << std::endl; break;
	case NORMAL_PRIORITY_CLASS: std::cout << "--------->PRIORITY-->NORMAL_PRIORITY_CLASS" << std::endl; break;
	case ABOVE_NORMAL_PRIORITY_CLASS: std::cout << "--------->PRIORITY-->ABOVE_NORMAL_PRIORITY_CLASS" << std::endl; break;
	case HIGH_PRIORITY_CLASS: std::cout << "--------->PRIORITY-->HIGH_PRIORITY_CLASS" << std::endl; break;
	case REALTIME_PRIORITY_CLASS: std::cout << "--------->PRIORITY-->REALTIME_PRIORITY_CLASS" << std::endl; break;
	default: std::cout << "--------->PRIORITY -->? " << std::endl << std::endl; break;
	}
}
void printThreadPrty(HANDLE h) {
	DWORD prty = GetPriorityClass(h);

	switch (prty) {
	case THREAD_PRIORITY_LOWEST: std::cout << "--------->PRIORITY-->THREAD_PRIORITY_LOWEST" << std::endl; break;
	case THREAD_PRIORITY_BELOW_NORMAL: std::cout << "--------->PRIORITY-->THREAD_PRIORITY_BELOW_NORMAL" << std::endl; break;
	case THREAD_PRIORITY_NORMAL: std::cout << "--------->PRIORITY-->THREAD_PRIORITY_NORMAL" << std::endl; break;
	case THREAD_PRIORITY_ABOVE_NORMAL: std::cout << "--------->PRIORITY-->THREAD_PRIORITY_ABOVE_NORMAL" << std::endl; break;
	case THREAD_PRIORITY_HIGHEST: std::cout << "--------->PRIORITY-->THREAD_PRIORITY_HIGHEST" << std::endl; break;
	case THREAD_PRIORITY_IDLE: std::cout << "--------->PRIORITY-->THREAD_PRIORITY_IDLE" << std::endl; break;
	default: std::cout << "--------->PRIORITY -->? " << std::endl << std::endl; break;
	}
}
void printAffinityMask(HANDLE hp, HANDLE ht) {
	DWORD pa = NULL, sa = NULL, icpu = -1;
	if (!GetProcessAffinityMask(hp, &pa, &sa)) throw "GetProcessAffinityMask";
	std::cout << "Process affinity Mask: " << std::showbase << std::hex << pa << std::endl;
	std::cout << "System affinity Mask: " << std::showbase << std::hex << sa << std::endl;
	icpu = SetThreadIdealProcessor(ht, MAXIMUM_PROCESSORS);//return установленый процессор для потока
	std::cout << "Thread IdealProcessor: " << std::dec << icpu << std::endl << std::endl;
}

