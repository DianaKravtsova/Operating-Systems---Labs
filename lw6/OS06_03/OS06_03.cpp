#include <iostream>
#include <Windows.h>

using namespace std;
#define PG (4096)
int pg = 256;

int main()
{
	setlocale(LC_ALL, "rus");

	int* m1 = (int*)VirtualAlloc(NULL, pg * PG, MEM_COMMIT, PAGE_READWRITE);
	for (int i = 0; i < pg * PG / 4; i++)
	{
		m1[i] = i;
	}

	// K = 34
	// R = 3B
	// A = 2A
	// Страница 34 = 52, смещение 3BA = 946
	int* m2 = m1 + 52 * 1024 + 946;
	cout << *m2 << endl;
	system("pause");
}
