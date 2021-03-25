#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void findTwoNum(int arr[], int n, int * pnum1, int * pnum2)
{
	int i;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		sum ^= arr[i];
	} //���ҵ��������������Ľ��
	int pos;
	for (int j = 0; j < 32;j++)
	{
		if (sum & 1 << j)
		{
			pos = j;
			break;
		}
	} //���ҵ��з����һλ������һλ�ϣ�������һ����һ��1һ��0
	for (int k = 0; k < n; k++)
	{
		if (arr[k] & 1 << pos)
		{
			*pnum1 ^= arr[k]; //��һλ��1�ģ�������1��
		}
		else
		{
			*pnum2 ^= arr[k]; //��һλ��0�ģ�������2��
		}
	}
}
int main()
{
	int arr[6] = { 1, 2, 1, 2, 5, 6 };
	int single1=0, single2=0;
	findTwoNum(arr, sizeof(arr) / sizeof(arr[0]),&single1,&single2);
	printf("%d %d\n", single1, single2);
	return 0;
}