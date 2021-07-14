#define _CRT_SECURE_NO_WARNINGS 1
// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int res = 0;
		size_t pos = 0;
		while ((pos = s1.find(s2, pos)) != std::string::npos)
		{
			pos += s2.size();
			++res;
		}
		cout << res << endl;
	}
	return 0;
}