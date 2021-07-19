#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		stack<char> st;
		string s1;
		string refresh;
		size_t maxsize = 0;
		refresh = "\n";
		getline(cin, refresh);
		for (int i = 0; i<n; ++i)
		{
			getline(cin,s1);
			char tmp = s1[0];
			s1.erase(s1.begin(), s1.begin() + 2);
			if (s1 == "connect")
			{
				st.push(tmp);
				maxsize = max(maxsize, st.size());
			}
			else if (s1 == "disconnect")
				st.pop();
		}
		cout << maxsize << endl;
	}
	return 0;
}