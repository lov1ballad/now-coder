#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "stdio.h"
#include <vector>
using namespace std;
int gcd(int m, int n)
{
	if (n == 0)
		return m;

	int temp = m%n;
	m = n;
	n = temp;
	return gcd(m, n);
}
int main()
{
	int n, ans;
	while (cin >> n >> ans)
	{
		while (n>0)
		{
			int cur;
			cin >> cur;
			ans = ans + ((ans<cur) ? gcd(cur, ans) : cur);
			n--;
		}
		cout << ans << endl;
	}
	return 0;
}