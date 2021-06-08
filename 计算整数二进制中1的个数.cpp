#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
	int n;
	int count;
	while (cin >> n)
	{
		count = 0;
		for (int i = 0; i<32; ++i)
		{
			if (n & (1 << i))
				count++;
		}
		cout << count << endl;
	}
	return 0;
}