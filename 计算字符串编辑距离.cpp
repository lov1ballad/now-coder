#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minDistance(string word1, string word2)
{
	if (word1.empty() || word2.empty())
	{
		return max(word1.size(), word2.size());
	}
	int len1 = word1.size();
	int len2 = word2.size();
	vector<vector<int>> iv(1 + len1, vector<int>(1 + len2, 0));
	for (int i = 0; i <= len1; ++i)
	{
		iv[i][0] = i;
	}
	for (int i = 0; i <= len2; ++i)
	{
		iv[0][i] = i;
	}
	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j)
		{
			if (word1[i - 1] == word2[j - 1])
			{
				iv[i][j] = 1 + min(iv[i][j - 1], iv[i - 1][j]);
				iv[i][j] = min(iv[i][j], iv[i - 1][j - 1]);
			}
			else
			{
				iv[i][j] = 1 + min(iv[i][j - 1], iv[i - 1][j]);
				iv[i][j] = min(iv[i][j], 1 + iv[i - 1][j - 1]);
			}
		}
	}
	return iv[len1][len2];
}
int main()
{
	string a, b;
	while (cin >> a >> b)
		cout << minDistance(a, b) << endl;
	return 0;
}