#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

struct node {
	int w;
	int h;
};

bool cmp(node first, node next)
{
	if (first.w != next.w)
		return first.w < next.w;//�����ش�С��������
	else
		return first.h > next.h;//������ͬʱ����߸ߵķ���ǰ��
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (n <= 0)
			break;

		vector<node> vec;
		for (int i = 0; i < n; ++i) {
			int num, weight, height;
			cin >> num >> weight >> height;
			node tmp;
			tmp.w = weight;
			tmp.h = height;
			vec.push_back(tmp);
		}

		stable_sort(vec.begin(), vec.end(), cmp);//stable_sort()���Զ�vector��ĳ����Ա�������򣬶��ҿɱ�֤���Ԫ�ص�ԭ����Դ���������󱣳ֲ��䡣

		//�������ȡ�������������
		vector<int> liss(n + 1, 1);
		int max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++)
			{
				if (vec[j].h <= vec[i].h && liss[j] + 1 > liss[i])
				{
					liss[i] = liss[j] + 1;
					if (max < liss[i])
						max = liss[i];
				}
			}
		}

		cout << max << endl;
	}

	return 0;
}
