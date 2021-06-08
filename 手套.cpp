#define _CRT_SECURE_NO_WARNINGS 1
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int ans = 0;
		int ls = 0, rs = 0;
		int lmin = 27, rmin = 27;  //边界值是26
		for (int i = 0; i<n; i++)
		{
			if (left[i] * right[i] == 0)
			{
				ans += left[i] + right[i];    //这里因为有一边为0，所以直接加起来就好了
			}
			else
			{
				ls += left[i];              //计算左边除了为零的那几组的总和
				rs += right[i]; 			  //右边总和
				lmin = min(lmin, left[i]);    //左边的最小值
				rmin = min(rmin, right[i]);	 //右边的最小值
			}
		}
		return ans + min(ls - lmin + 1, rs - rmin + 1) + 1;  //0的数量+最小拿出的数量+任意拿出的1
	}

};
