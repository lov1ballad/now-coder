//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include<assert.h>
////VALID ��ʾ����Ϸ�
////INVALID ��ʾ����Ƿ�
//enum State
//{
//	VALID,//0
//	INVALID//1
//};
////Ĭ�Ͻ�����ܷǷ�������ȷת�����ٸ�Ϊ�Ϸ�
//enum State state = INVALID;
//int my_atoi(char *str)
//{
//	int flag = 1;//����Ϊ��
//	long long ret = 0;
//	assert(str);
//	state = INVALID;
//	//�����հ��ַ�
//	while(isspace(*str))
//		//��������: ���str�Ƿ��ǿո���������(�����ַ�)���з�
//
//	//��������: �Ƿ��ط�0, ���򷵻�0
//	{
//		str++;
//	}
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	//����������
//	if(*str == '+')
//	{
//		str++;
//	}
//	else if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//	//��ʼת�������ַ�ֱ���������ַ�
//	while(isdigit(*str))
//		//��������: ���ch�Ƿ�������(0-9)
//
//		//��������: �Ƿ��ط�0, ���򷵻�0
//	{
//		ret = ret * 10 + flag * (*str - '0');
//		if ((ret > INT_MAX) || (ret < INT_MIN))
//		{
//			return 0;
//		}
//		str++;
//	}
//	//����ֹͣ
//	if(*str == '\0')
//	{
//		state = VALID;
//		return (int)ret;
//	}
//	else
//	{//�����������ַ�
//		return (int)ret;
//	}
//}
//int main()
//{
//	char *p = "-1028542";
//	printf("%d\n", my_atoi(p));
//	return 0;
//}