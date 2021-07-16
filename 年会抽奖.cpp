#define _CRT_SECURE_NO_WARNINGS 1
// write your code here cpp
#include<iostream>
using namespace std;

int main()
{
	int n;
	long long a[21] = { 0, 0, 1 }, b[21] = { 1, 1, 2 };
	while (cin >> n) {
		for (int i = 3; i <= n; i++)
		{
			b[i] = i * b[i - 1];
			a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
			//		cout << "a[i]=" << a[i] << endl;
			//		cout << "b[i]=" << b[i] << endl;

		}
		//	cout << 1.0 * a[n] / b[n]*100 << endl;
		printf("%.2f%c\n", 1.0 * a[n] / b[n] * 100, '%');

	}
	return 0;
}