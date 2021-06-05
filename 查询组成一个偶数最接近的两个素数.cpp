#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
bool IsP(int n)
{
	for (int i = 2; i<n / 2; ++i)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int n1, n2;
		int tmp = n / 2;
		while (tmp>0)
		{
			n2 = n - tmp;
			if (IsP(tmp) && IsP((n2)))
			{
				n1 = tmp;
				break;
			}
			tmp--;
		}
		cout << n1 << endl << n2 << endl;
	}
	return 0;
}
/*
while(cin>>n)
{
	int left = n/2;
	int right = n-left;
	while(!IsP(left) || !IsP(right))
	{
		left--;
		right++;
	}
	cout<<left<<endl<<right<<endl;
}
*/