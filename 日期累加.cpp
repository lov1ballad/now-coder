#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

bool IsLeap(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int GetDaysByYM(int year, int month)
{
	int days[] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && IsLeap(year))
		month = 0;
	return days[month];
}

void lastday(int year, int month, int day, int n)
{
	int monthdays = GetDaysByYM(year, month);
	while ((day + n)>monthdays)
	{
		month++;
		if (month>12)
		{
			year++;
			month = 1;
		}
		n -= monthdays;
		monthdays = GetDaysByYM(year, month);
	}
	printf("%04d-%02d-%02d\n", year, month, day + n);
}

int main()
{
	int m;
	cin >> m;
	while (m)
	{
		for (int i = 0; i<m; ++i)
		{
			int year, month, day, n;
			cin >> year >> month >> day >> n;
			lastday(year, month, day, n);
		}
		m--;
	}
	return 0;
}













