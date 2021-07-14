#define _CRT_SECURE_NO_WARNINGS 1
// write your code here cpp
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int primeArray[78667] = { 0 };

int isprime(int n)
{
	int i;
	for (i = 2; i*i <= n; i++)
	if (n%i == 0)
		return 0;
	return 1;
}
void primetable()
{
	int i, j = 0;
	for (i = 2; i <= 1000000; i++)
	if (isprime(i))
	{
		primeArray[j++] = i;
	}
}

int main()
{
	primetable();//����������
	int N;
	while (scanf("%d", &N) != EOF)//ѭ������
	{
		printf("%d = ", N);
		vector<int> yinzi;
		for (int i = 0; i < 78667;)
		{
			if (N%primeArray[i] == 0)
			{
				yinzi.push_back(primeArray[i]);//���ֽ������������������
				N /= primeArray[i];
				if (N == 1)
				{
					break;
				}
			}
			else
			{
				i++;
			}
		}
		for (int i = 0; i < yinzi.size() - 1; i++)//��ӡ���
		{
			printf("%d * ", yinzi[i]);
		}
		printf("%d\n", yinzi[yinzi.size() - 1]);
	}
}