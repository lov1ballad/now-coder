//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//bool isleap(int year)
//{
//	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
//}
//int GetmonthDay(int year, int month)
//{
//	int arr[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (month == 2 && isleap(year))
//		month = 0;
//	return arr[month];
//}
//int dayByymd(int year, int month, int day)
//{
//	int sum = 0;
//	for (int i = 1; i<month; ++i)
//		sum += GetmonthDay(year, i);
//	sum += day;
//	return sum;
//}
//int main()
//{
//	int year, month, day, ret;
//	while (cin >> year >> month >> day)
//	{
//		ret = dayByymd(year, month, day);
//		cout << ret << endl;
//	}
//	return 0;
//}