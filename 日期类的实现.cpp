//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Date
//{
//	friend ostream& operator<<(ostream &out, const Date& d);
//public:
//	bool leap(int year)
//	{return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));}
//	// 获取某年某月的天数
//	int GetMonthDay(int year, int month)
//	{
//		static int days[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		if (month == 2 && leap(year))
//			month = 0;
//		return days[month];
//	}
//
//	// 全缺省的构造函数
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		m_year = year;
//		m_month = month;
//		m_day = day;
//	}
//
//	// 拷贝构造函数
//	// d2(d1)
//	Date(const Date& d)
//	{
//		m_year = d.m_year;
//		m_month = d.m_month;
//		m_day = d.m_day;
//	}
//
//	// 赋值运算符重载
//	// d2 = d3 -> d2.operator=(&d2, d3)
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			m_year = d.m_year;
//			m_month = d.m_month;
//			m_day = d.m_day;
//		}
//		return *this;
//	}
//
//	// 析构函数
//	~Date()
//	{
//
//	}
//
//	// 日期+=天数
//	Date& operator+=(int day)
//	{
//		if (day<0)
//			return *this -= -day;
//		m_day += day;
//		while (m_day > GetMonthDay(m_year, m_month))
//		{
//			m_day -= GetMonthDay(m_year, m_month);
//			m_month++;
//			if (m_month == 13)
//			{
//				m_year++;
//				m_month = 1;
//			}
//		}
//		return*this;
//	}
//
//	// 日期+天数
//	Date operator+(int day)
//	{
//		Date tmp = *this;
//		tmp += day;
//		return tmp;
//	}
//
//	// 日期-天数
//	Date operator-(int day)
//	{
//		Date tmp = *this;
//		tmp -= day;
//		return tmp;
//	}
//
//	// 日期-=天数
//	Date& operator-=(int day)
//	{
//		if (day < 0)
//			return *this += -day;
//		m_day -= day;
//		while (m_day <= 0)
//		{
//			--m_month;
//			if (m_month == 0)
//			{
//				--m_year;
//				m_month = 12;
//			}
//			m_day += GetMonthDay(m_year, m_month);
//		}
//		return *this;
//	}
//
//	// 前置++
//	Date& operator++()
//	{
//		m_day++;
//		int mdays = GetMonthDay(m_year, m_month);
//		if (m_day > mdays)
//		{
//			m_day = 1;
//			m_month++;
//			if (m_month > 12)
//			{
//				m_month = 1;
//				m_year++;
//			}
//		}
//		return *this;
//	}
//
//	// 后置++
//	Date operator++(int)
//	{
//		Date tmp = *this;
//		++(*this);
//		return tmp;
//	}
//
//	// 后置--
//	Date operator--(int)
//	{
//		Date tmp = *this;
//		--(*this);
//		return tmp;
//	}
//
//	// 前置--
//	Date& operator--()
//	{
//		if (m_day == 1)
//		{
//			--m_month;
//			if (m_month == 0)
//			{
//				m_month = 12;
//				--m_year;
//				m_day = GetMonthDay(m_year, m_month);
//			}
//		}
//		return *this;
//	}
//
//	// >运算符重载
//	bool operator>(const Date& d)
//	{
//		if ((m_year > d.m_year)
//			|| (m_year == d.m_year && m_month > d.m_month)
//			|| (m_year == d.m_year && m_month == d.m_month && m_day > d.m_day))
//			return true;
//		return false;
//	}
//
//	// ==运算符重载
//	bool operator==(const Date& d)
//	{
//		return (m_year == d.m_year &&
//			m_month == d.m_month &&
//			m_day == d.m_day);
//	}
//
//	// >=运算符重载
//	inline bool operator >= (const Date& d)
//	{
//		return !(*this < d);
//	}
//
//	// <运算符重载
//	bool operator < (const Date& d)
//	{
//		if ((m_year < d.m_year)
//			|| (m_year == d.m_year && m_month < d.m_month)
//			|| (m_year == d.m_year && m_month == d.m_month && m_day < d.m_day))
//			return true;
//		return false;
//	}
//
//	// <=运算符重载
//	bool operator <= (const Date& d)
//	{
//		return !(*this > d);
//	}
//
//	// !=运算符重载
//	bool operator != (const Date& d)
//	{
//		return !(*this == d);
//	}
//
//	// 日期-日期 返回天数
//	int operator-(const Date& d)
//	{
//		int flag = 1;
//		Date max = *this;
//		Date min = d;
//		if (*this < d)
//		{
//			max = d;
//			min = *this;
//			flag = -1;
//		}
//		int day = 0;
//		while (min < max)
//		{
//			++min;
//			++day;
//		}
//		return day*flag;
//	}
//
//	int GetdayByymd(int year, int month, int day)
//	{
//		int days = 0;
//		for (int i = 1; i < month; ++i)
//		{
//			days += GetMonthDay(year, i);
//		}
//		return days += day;
//	}
//private:
//	int m_year;
//	int m_month;
//	int m_day;
//};
//
//ostream& operator<<(ostream &out, const Date& d)
//{
//	out<<d.m_year<<"-"<<d.m_month<<"-"<<d.m_day;
//	return out;
//}
//void main()
//{
//	Date d1(2000,1,1);
//	Date d2(d1);
//	if (d1 == d2)
//		cout << "Equal" << endl;
//	else if (d1 > d2)
//		cout << "d1 > d2" << endl;
//	else
//		cout << "d1 < d2" << endl;
//	--d1;
//	cout<<d1<<endl;
//}