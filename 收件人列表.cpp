#define _CRT_SECURE_NO_WARNINGS 1
// write your code here cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	string name;
	string namelist;
	while (cin >> n)
	{
		getchar();
		namelist.clear();//一次namelist输出完后注意要清空namelist
		while (n> 0)
		{
			getline(cin, name);
			if (name.find(',') != -1 || name.find(' ') != -1)//判断是否有逗号或者空格
			{
				name.resize(name.size() + 1);//要在name头部插入字符" 将其容量+1然后所有字符往后移动一位 将name[0]赋值为"
				for (int i = name.size() - 1; i > 0; i--)
				{
					name[i] = name[i - 1];

				}
				name[0] = '"';
				name.push_back('"');
				if (n != 1)//判断是否为最后一个name 最后一个name不加逗号和空格
				{
					name.push_back(',');
					name.push_back(' ');
				}
				namelist += name;
				n--;
			}
			else
			{
				if (n != 1)//判断是否为最后一个name 最后一个name不加逗号和空格
				{
					name.push_back(',');
					name.push_back(' ');
				}
				namelist += name;
				n--;

			}
		}
		cout << namelist << endl;
	}
	return 0;
}