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
		namelist.clear();//һ��namelist������ע��Ҫ���namelist
		while (n> 0)
		{
			getline(cin, name);
			if (name.find(',') != -1 || name.find(' ') != -1)//�ж��Ƿ��ж��Ż��߿ո�
			{
				name.resize(name.size() + 1);//Ҫ��nameͷ�������ַ�" ��������+1Ȼ�������ַ������ƶ�һλ ��name[0]��ֵΪ"
				for (int i = name.size() - 1; i > 0; i--)
				{
					name[i] = name[i - 1];

				}
				name[0] = '"';
				name.push_back('"');
				if (n != 1)//�ж��Ƿ�Ϊ���һ��name ���һ��name���Ӷ��źͿո�
				{
					name.push_back(',');
					name.push_back(' ');
				}
				namelist += name;
				n--;
			}
			else
			{
				if (n != 1)//�ж��Ƿ�Ϊ���һ��name ���һ��name���Ӷ��źͿո�
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