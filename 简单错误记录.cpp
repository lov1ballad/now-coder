#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
	string str;
	vector<pair<string, int>> ves;
	while (getline(cin, str)) {
		istringstream istr(str);
		string s1, s2;
		istr >> s1 >> s2;
		auto b = s1.find_last_of('\\');
		if (b != string::npos) {
			s1 = s1.substr(b + 1);
		}
		string s = s1 + " " + s2;
		vector<pair<string, int>>::iterator re = find_if(ves.begin(), ves.end(), [s](pair<string, int> pai) {return pai.first == s; });
		if (re != ves.end()) {
			re->second += 1;
		}
		else {
			ves.push_back(make_pair(s, 1));
		}
	}
	int i = ves.size()>8 ? ves.size() - 8 : 0;
	string temp;
	for (; i<ves.size(); ++i) {
		temp = ves[i].first;
		int t = temp.find_first_of(' ');
		int len = temp.substr(0, t).size();
		if (len> 16) {
			temp = temp.substr(len - 16, 16) + temp.substr(t);
		}
		cout << temp << " " << ves[i].second << endl;
	}
	return 0;
}