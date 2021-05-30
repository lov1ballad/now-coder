#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int fib(int n)
{
	/*int *arr = new int [n];
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2;i<=n;++i)
	{
	arr[i] = arr[i-1] + arr[i-2];
	}
	delete[] arr;
	return arr[n];*/
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int min(int n)
{
	int a = 0;
	int left = 0;
	int right = 0;
	while (1)
	{
		if (fib(a)< n)
		{
			left = n - fib(a);
		}
		else{
			right = fib(a) - n;
			break;
		}
		a++;
	}
	if (left<right)
		return left;
	return right;
}
int main()
{
	int n;
	cin >> n;
	cout << min(n) << endl;
	return 0;
}