#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int Month[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
int day(int year, int month, int day)
{
	int year_day = year * 365 + year / 4 - year / 100 + year / 400;
	int month_day = Month[month - 1];
	if ((month % 4 == 0 && month % 100 != 0) || month % 400 == 0)
		month_day += 1;
	return year_day + month_day + day;
}

int main()
{
	int d1_year=0, d1_month=0, d1_day=0, d2_year=0, d2_month=0, d2_day=0;
	scanf("%4d%2d%2d\n", &d1_year, &d1_month, &d1_day);
	int d1days = day(d1_year, d1_month, d1_day);
	scanf("%4d%2d%2d", &d2_year, &d2_month, &d2_day);
	int d2days = day(d2_year, d2_month, d2_day);
	printf("%d", abs(d1days - d2days));
	return 0;
}