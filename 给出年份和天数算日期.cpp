#include<iostream>
using namespace std;

int main()
{
	int monthdays[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, n;
	while (cin >> year >> n)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			monthdays[2] = monthdays[0];
		int month = 1;
		while (n > monthdays[month])
		{
			n -= monthdays[month];
			month++;
		}
		printf("%04d-%02d-%02d", year, month, n);
	}
	return 0;
}