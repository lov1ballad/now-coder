#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int Add(int num1, int num2)
	{
		while (num1)
		{
			int num3 = num1;
			num1 = (num1&num2) << 1;
			num2 = num2^num3;
		}
		return num2;
	}
};