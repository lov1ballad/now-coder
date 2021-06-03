#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int count = 0;
		int size = s.size();
		//³¤¶È
		if (size <= 4)
			count += 5;
		else if (size > 5 && size < 7)
			count += 10;
		else
			count += 25;
		int tmp = 0;
		int cur = 0;
		int ps = 0;
		int m = 0;
		for (auto e : s)
		{
			//×ÖÄ¸
			if (e >= 'a' && e <= 'z')
				tmp++;
			if (e >= 'A' && e <= 'Z')
				cur++;
			//Êý×Ö
			if (e >= 0 && e <= 9)
				ps++;
			//·ûºÅ
			if (!(e >= 'a' && e <= 'z' || e >= 'A' && e <= 'Z' || e >= 0 && e <= 9))
				m++;
		}
		if ((tmp + cur) == 0)
			count += 0;
		else if ((tmp != 0 && cur == 0) || (tmp == 0 && cur != 0))
			count += 10;
		else
			count += 20;

		if (ps == 0)
			count += 0;
		else if (ps == 1)
			count += 10;
		else
			count += 20;

		if (m == 0)
			count += 0;
		else if (m == 1)
			count += 10;
		else
			count += 25;

		if (ps != 0 && (tmp + cur) != 0 && m == 0)
			count += 2;
		if (ps != 0 && m != 0 && (tmp + cur) != 0)
		{
			if (tmp && cur)
				count += 5;
			else
				count += 3;
		}

		if (count >= 90)
			cout << "VERY_SECURE" << endl;
		else if (count >= 80)
			cout << "SECURE" << endl;
		else if (count >= 70)
			cout << "VERY_STRONG" << endl;
		else if (count >= 60)
			cout << "STRONG" << endl;
		else if (count >= 50)
			cout << "AVERAGE" << endl;
		else if (count >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
}