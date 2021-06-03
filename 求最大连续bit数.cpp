#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int max(int a, int b)
{
	return a>b ? a : b;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int tmp = 1;
		int count = 0;
		int cur = 0;
		int len = 1;
		int m = n;
		while (m)
		{
			m /= 2;
			len++;
		}
		for (int i = 0; i<len; ++i)
		{
			if (n & tmp)
			{
				count++;
				cur = max(count, cur);
			}
			else
			{
				count = 0;
			}
			tmp <<= 1;
		}
		cout << cur << endl;
	}
	return 0;
}