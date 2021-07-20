// write your code here cpp
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int row, col;
int x, y;//��ʼλ��"@"
char Rec[25][25] = { 0 };//����
bool passed[25][25] = { 0 };//��¼�Ѿ��߹���
int cur_x, cur_y;//��ǰ����λ��
int res = 0;//�ܹ��ܴﵽ��ɫ��ש����
int choice[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };//����ѡ��

void Init()
{
	res = 0;
	memset(Rec, 0, sizeof(Rec));
	memset(passed, 0, sizeof(passed));
	for (int i = 0; i<row; ++i)
	{
		for (int j = 0; j<col; ++j)
		{
			cin >> Rec[i][j];
			if (Rec[i][j] == '@')
			{
				x = i;
				y = j;
			}
		}
	}
}

bool Judge(int x, int y)
{
	if (x<0 || x >= row || y<0 || y >= col)
		return false;
	if (passed[x][y])
		return false;
	if (Rec[x][y] == '#')
		return false;
	return true;
}

void Dfs(int x, int y)
{
	if (x<0 || x >= row || y<0 || y >= col)
		return;
	res++;
	passed[x][y] = 1;
	for (int i = 0; i<4; ++i)
	{
		cur_x = x + choice[i][0];
		cur_y = y + choice[i][1];
		if (Judge(cur_x, cur_y))
			Dfs(cur_x, cur_y);
	}
	return;
}
int main()
{
	while (cin >> row >> col && row)
	{
		Init();
		Dfs(x, y);
		cout << res << endl;
	}
	return 0;
}