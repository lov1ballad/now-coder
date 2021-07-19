#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Issubstr(string s1, string s2)
{
	if (s1[0] == s2[0])
	{
		s2 = s2.substr(0, s1.size());
		if (s2 == s1)
			return true;
	}
	return false;
}
void Mkdir(vector<string> v)
{
	string head = "mkdir -p ";
	for (int i = 0; i < v.size() - 1;)
	{
		if (Issubstr(v[i], v[i + 1]) &&
			v[i + 1][v[i].size()] == '/')
			v.erase(v.begin() + i);
		else
			i++;
	}
	for (const auto&e : v)
	{
		cout << head << e << endl;
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		string refresh = "\n";
		getline(cin, refresh);
		vector<string> v;
		for (int i = 0; i < n; ++i)
		{
			string s1;
			cin >> s1;
			v.push_back(s1);
		}
		sort(v.begin(), v.end());
		Mkdir(v);
		cout << endl;
	}
	return 0;
}