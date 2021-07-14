// write your code here cpp
#include <iostream>
using namespace std;

int day_of_week(int year, int month, int day)
{
	//�£�m���ڵ���3��С�ڵ���14�����ڲ��չ�ʽ�У�ĳ���1��2��Ҫ������һ��			��13��14��������
	if (month == 1 || month == 2) {
		month += 12;
		year -= 1;
	}
	int c = year / 100;
	year = year % 100;
	int week = year + (year / 4) + (c / 4) - 2 * c + 26 * (month + 1) / 10 + day - 1;  //��ʽ��w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
	week = (week % 7 + 7) % 7;

	if (week == 0) {
		week = 7;
	}

	return week;
}

int day_of_demand(int year, int month, int count, int d_of_week)
{
	//count �ڼ�������     d_of_week�ܼ�
	int week = day_of_week(year, month, 1);
	// �ڼ������� * 7�� + ������ڵ����� d_of_week ��ʣ����
	int day = 1 + (count - 1) * 7 + ((7 - week) + d_of_week) % 7;
	return day;
}
//�����ʽΪyyyy-mm-dd
// Ԫ��
void new_year_day(int year) {
	printf("%d-01-01\n", year);
}

// ����·�¡��������
void martin_luther_king_day(int year) {
	printf("%d-01-%02d\n", year, day_of_demand(year, 1, 3, 1));
}

// ��ͳ��
void president_day(int year) {
	printf("%d-02-%02d\n", year, day_of_demand(year, 2, 3, 1));
}

// ������ʿ������
void memorial_day(int year) {
	// �� 6 ����ǰ��
	int week = day_of_week(year, 6, 1);
	int d = (week == 1) ? 6 : (week - 2);
	int day = 31 - d;
	printf("%d-05-%02d\n", year, day);
}

// ����
void independence_day(int year) {
	printf("%d-07-04\n", year);
}

// �Ͷ���
void labor_day(int year) {
	printf("%d-09-%02d\n", year, day_of_demand(year, 9, 1, 1));
}

// �ж���
void thanks_giving_day(int year) {
	printf("%d-11-%02d\n", year, day_of_demand(year, 11, 4, 4));
}

// ʥ����
void christmas(int year) {
	printf("%d-12-25\n", year);
}

// ��������
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
