#include <Windows.h>
#include <iostream>

using namespace std;




int main()
{
	DWORD pid = GetCurrentProcessId(); // извлекает значение идентификатора вызывающего процесса
	DWORD tid = GetCurrentThreadId(); // извлекает значение идентификатора вызывающего потока

	unsigned long long d = MAXULONGLONG / 100000000000;

	for (unsigned long long i = 0; i < MAXULONGLONG; i++) {
		if (i % d == 0)
			cout << "PID = " << pid << ", TID = " << tid << " : " << i << endl;
	}
	system("pause");
	return 0;
}