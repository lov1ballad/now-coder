#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
double dp[25][25];
int block[25][25];

double pro(int row, int col)
{
	for (int i = 1; i <= row; ++i)
	{
		for (int j = 1; j <= col; ++j)
		{
			if (i == 1 && j == 1)
			{
				dp[i][j] = block[i][j] == 1 ? 0 : 1;
				continue;
			}
			if (block[i][j] == 1)
			{
				dp[i][j] = 0;
			}
			else{
				if (i == row && j == col)
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
				else if (i == row)
				{
					dp[i][j] = dp[i - 1][j] * 0.5 + dp[i][j - 1];
				}
				else if (j == col)
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1] * 0.5;
				}
				else{
					dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])*0.5;
				}
			}
		}
	}
	return dp[row][col];
}

int main()
{
	int row, col, k;
	int x, y;
	while (cin >> row >> col >> k)
	{
		memset(dp, 0, sizeof(dp));
		memset(block, 0, sizeof(block));
		while (k--)
		{
			cin >> x >> y;
			block[x][y] = 1;
		}
		double res = pro(row, col);
		printf("%.2lf\n", res);
	}
	return 0;
}