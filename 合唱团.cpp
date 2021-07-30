#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*记第k个人的位置为one,则可以用f[one][k]表示从n个人中选择k个的方案。然后，它的子问题，需要从one前面的left个人里面，选择k-1个，这里left表示k-1个人中最后一个（即第k-1个）人的位置，因此，子问题可以表示成f[left][k-1].*/
int main()
{
	int n, k, d;
	long int res;

	res = 0;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}

	cin >> k;            //选取的k名学生
	cin >> d;            //相隔编号不超过d
	long int fmax[11][50] = { 0 };
	long int fmin[11][50] = { 0 };

	for (int j = 1; j <= k; j++)
	{
		for (int i = 0; i<n; i++)
		{
			if (j == 1)
			{
				fmax[j][i] = arr[i];
				fmin[j][i] = arr[i];
			}
			for (int p = 1; p <= d; p++)
			{
				if (i - p >= 0 && i - p<n)
				{
					fmax[j][i] = max(fmax[j][i], max(fmax[j - 1][i - p] * arr[i], fmin[j - 1][i - p] * arr[i]));                                //在i个数中选取j个数。
					fmin[j][i] = min(fmin[j][i], min(fmax[j - 1][i - p] * arr[i], fmin[j - 1][i - p] * arr[i]));
				}
			}
			res = max(res, fmax[k][i]);
		}
	}
	cout << res;

	if (arr != NULL)
	{
		delete[]arr;
		arr = NULL;
	}
	return 0;
}