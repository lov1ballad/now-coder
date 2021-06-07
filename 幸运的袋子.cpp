#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int luckbag(vector<int> iv, int pos, long sum, long mul, int num)
{
	int count = 0;
	for (int i = pos; i<num; ++i)
	{
		sum += iv[i];
		mul *= iv[i];
		if (sum>mul)
			count += (1 + luckbag(iv, i + 1, sum, mul, num));
		else if (iv[i] == 1)
			count += luckbag(iv, i + 1, sum, mul, num);
		else
			break;
		sum -= iv[i];
		mul /= iv[i];
		while (i<num - 1 && iv[i] == iv[i + 1])
			++i;
	}
	return count;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> iv(n);
		for (int i = 0; i<n; ++i)
		{
			cin >> iv[i];
		}
		sort(iv.begin(), iv.end());
		cout << luckbag(iv, 0, 0, 1, n) << endl;
	}
	return 0;
}