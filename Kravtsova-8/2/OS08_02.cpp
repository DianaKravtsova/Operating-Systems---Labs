#include <iostream>
#include <ctime>

using namespace std;
int main()
{
	clock_t t1 = clock();
	int i = 0;
	bool flag1 = true;

	while (true) {
		i++;
		clock_t t2 = clock();
		if (t2 - t1 == 5000 && flag1) {
			cout << i << endl;
			flag1 = false;
		}
		if (t2 - t1 == 10000 && !flag1) {
			cout << i << endl;
			flag1 = true;
		}
		if (t2 - t1 == 15000) {
			cout << i << endl;
			break;
		}
	}
	system("pause");
}