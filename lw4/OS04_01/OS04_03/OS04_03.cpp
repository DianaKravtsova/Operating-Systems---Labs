﻿// OS04_03.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Windows.h>
#include <iostream>

using namespace std;

DWORD pid = NULL;

DWORD WINAPI OS04_02_T1()
{
	DWORD tid = GetCurrentThreadId();
	int d = 50;

	for (int i = 0; i < d; i++)
	{
		Sleep(1000);
		cout << "PID = " << pid << ", Дочерний поток 1: " << " tid- " << tid << " : " << i << endl;

	}
	return 0;
}

DWORD WINAPI OS04_02_T2()
{
	DWORD tid = GetCurrentThreadId();
	int d2 = 125;
	for (int i = 0; i < d2; i++)
	{
		Sleep(1000);
		cout << "PID = " << pid << ", Дочерний поток 2: " << " tid- " << tid << " : " << i << endl;

	}
	return 0;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	pid = GetCurrentProcessId();
	DWORD tid = GetCurrentThreadId();
	int d = 100;
	DWORD ChildId = NULL;
	DWORD ChildId2 = NULL;

	HANDLE hChild = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_02_T1, NULL, 0, &ChildId);
	HANDLE hChild2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_02_T2, NULL, 0, &ChildId2);

	for (int i = 0; i < d; i++) {
		Sleep(1000);
		cout << "PID = " << pid << ", Родительский: " << " tid- " << tid << " : " << i << endl;
		if (i == 20)
		{
			SuspendThread(hChild);
			cout << "Приостановка д.п. 1" << endl;
		}
		if (i == 60)
		{
			ResumeThread(hChild);
			cout << "Возобновление д.п. 1" << endl;
		}
		if (i == 40)
		{
			SuspendThread(hChild2);
			cout << "Приостановка д.п. 2" << endl;
		}
	}
	ResumeThread(hChild2);
	cout << "Возобновление д.п. 2" << endl;
	WaitForSingleObject(hChild, INFINITE);
	WaitForSingleObject(hChild2, INFINITE);
	CloseHandle(hChild);
	CloseHandle(hChild2);

	system("pause");
	return 0;

}