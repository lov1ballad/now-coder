#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=6&ru=%2Factivity%2Foj&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tab=answerKey
//class Solution {
//public:
//	int StrToInt(string str)
//	{
//		if (str.size() == 0)
//		{
//			return 0;
//		}
//		int i = 0;
//		int flag = 1;
//		unsigned long num = 0;
//		if (str[0] == '+')
//		{
//			flag = 1;
//			i++;
//		}
//		if (str[0] == '-')
//		{
//			flag = -1;
//			i++;
//		}
//		while (i<str.size())
//		{
//			if (str[i] < '0' || str[i] > '9')
//				return 0;
//			num = num * 10 + str[i] - '0';
//			i++;
//		}
//		return flag*num;
//	}
//};