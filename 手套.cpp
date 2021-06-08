#define _CRT_SECURE_NO_WARNINGS 1
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int ans = 0;
		int ls = 0, rs = 0;
		int lmin = 27, rmin = 27;  //�߽�ֵ��26
		for (int i = 0; i<n; i++)
		{
			if (left[i] * right[i] == 0)
			{
				ans += left[i] + right[i];    //������Ϊ��һ��Ϊ0������ֱ�Ӽ������ͺ���
			}
			else
			{
				ls += left[i];              //������߳���Ϊ����Ǽ�����ܺ�
				rs += right[i]; 			  //�ұ��ܺ�
				lmin = min(lmin, left[i]);    //��ߵ���Сֵ
				rmin = min(rmin, right[i]);	 //�ұߵ���Сֵ
			}
		}
		return ans + min(ls - lmin + 1, rs - rmin + 1) + 1;  //0������+��С�ó�������+�����ó���1
	}

};
