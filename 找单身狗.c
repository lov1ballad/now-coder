#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void findTwoNum(int arr[], int n, int * pnum1, int * pnum2)
{
	int i;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		sum ^= arr[i];
	} //先找到两个数互相异或的结果
	int pos;
	for (int j = 0; j < 32;j++)
	{
		if (sum & 1 << j)
		{
			pos = j;
			break;
		}
	} //再找到有分歧的一位。在这一位上，两个数一定是一个1一个0
	for (int k = 0; k < n; k++)
	{
		if (arr[k] & 1 << pos)
		{
			*pnum1 ^= arr[k]; //这一位是1的，放在数1里
		}
		else
		{
			*pnum2 ^= arr[k]; //这一位是0的，放在数2里
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