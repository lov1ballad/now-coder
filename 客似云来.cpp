#define _CRT_SECURE_NO_WARNINGS 1
// write your code here cpp
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int from, to;
	while (cin >> from >> to)
	{
		long sum = 0, a = 1, b = 1;
		for (int i = 0; i<to; ++i){
			if (i >= from - 1){
				sum += a;
			}
			swap(a, b);
			b += a;
		}

		cout << sum << endl;
	}
	return 0;
}
