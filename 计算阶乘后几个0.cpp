#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int f(int n) {
	int result = 1;
	int num = 0;
	for (int i = n; i >= 1; i--)
		result *= i;

	while (1) {
		if (result % 10 == 0) {
			result /= 10;
			num++;
		}
		else
			break;
	}
	return num;
}

int main() {
	int n;
	cin >> n;
	cout << f(n) << endl;
	return 0;
}
