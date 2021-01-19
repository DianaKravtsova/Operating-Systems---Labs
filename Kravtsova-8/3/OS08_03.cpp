#include <iostream>
#include <ctime>
#include <Windows.h>
#define SECOND 10000000

int i = 0;
HANDLE htimer = NULL;
using namespace std;
int main()
{
	htimer = CreateWaitableTimer(NULL, FALSE, NULL);
	long long it = -3 * SECOND;

	clock_t firsttime = clock();
	while (true) {
		i++;
		if (!SetWaitableTimer(htimer, (LARGE_INTEGER*)&it, 3000, NULL, NULL, FALSE)) { throw "Error SrtWaitableTimer"; }
		if (i == 6) {
			cout << clock() - firsttime << " " << i << endl;
			break;
		}
		cout << clock() - firsttime << " " << i << endl;
		WaitForSingleObject(htimer, INFINITE);
	}

	system("pause");
}