// write your code here cpp
#include <iostream>
using namespace std;

int day_of_week(int year, int month, int day)
{
	//月（m大于等于3，小于等于14，即在蔡勒公式中，某年的1、2月要看作上一年			的13、14月来计算
	if (month == 1 || month == 2) {
		month += 12;
		year -= 1;
	}
	int c = year / 100;
	year = year % 100;
	int week = year + (year / 4) + (c / 4) - 2 * c + 26 * (month + 1) / 10 + day - 1;  //公式：w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
	week = (week % 7 + 7) % 7;

	if (week == 0) {
		week = 7;
	}

	return week;
}

int day_of_demand(int year, int month, int count, int d_of_week)
{
	//count 第几个星期     d_of_week周几
	int week = day_of_week(year, month, 1);
	// 第几个星期 * 7天 + 这个星期到星期 d_of_week 还剩几天
	int day = 1 + (count - 1) * 7 + ((7 - week) + d_of_week) % 7;
	return day;
}
//输出格式为yyyy-mm-dd
// 元旦
void new_year_day(int year) {
	printf("%d-01-01\n", year);
}

// 马丁·路德·金纪念日
void martin_luther_king_day(int year) {
	printf("%d-01-%02d\n", year, day_of_demand(year, 1, 3, 1));
}

// 总统日
void president_day(int year) {
	printf("%d-02-%02d\n", year, day_of_demand(year, 2, 3, 1));
}

// 阵亡将士纪念日
void memorial_day(int year) {
	// 从 6 月往前数
	int week = day_of_week(year, 6, 1);
	int d = (week == 1) ? 6 : (week - 2);
	int day = 31 - d;
	printf("%d-05-%02d\n", year, day);
}

// 国庆
void independence_day(int year) {
	printf("%d-07-04\n", year);
}

// 劳动节
void labor_day(int year) {
	printf("%d-09-%02d\n", year, day_of_demand(year, 9, 1, 1));
}

// 感恩节
void thanks_giving_day(int year) {
	printf("%d-11-%02d\n", year, day_of_demand(year, 11, 4, 4));
}

// 圣诞节
void christmas(int year) {
	printf("%d-12-25\n", year);
}

// 美国节日
void festival(int year) {
	new_year_day(year);
	martin_luther_king_day(year);
	president_day(year);
	memorial_day(year);
	independence_day(year);
	labor_day(year);
	thanks_giving_day(year);
	christmas(year);
}

int main() {
	int year;
	while (cin >> year) {
		festival(year);
		cout << endl;
	}
}
