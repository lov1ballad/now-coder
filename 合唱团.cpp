#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*�ǵ�k���˵�λ��Ϊone,�������f[one][k]��ʾ��n������ѡ��k���ķ�����Ȼ�����������⣬��Ҫ��oneǰ���left�������棬ѡ��k-1��������left��ʾk-1���������һ��������k-1�����˵�λ�ã���ˣ���������Ա�ʾ��f[left][k-1].*/
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

	cin >> k;            //ѡȡ��k��ѧ��
	cin >> d;            //�����Ų�����d
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
					fmax[j][i] = max(fmax[j][i], max(fmax[j - 1][i - p] * arr[i], fmin[j - 1][i - p] * arr[i]));                                //��i������ѡȡj������
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