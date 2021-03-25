//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<assert.h>
//
//void my_strncpy(char* dst, const char* src, int n)
//{
//	char* ret = dst;
//	while (n && (*(dst++) = *(src++)))
//		n--;
//	if (n) 
//		while (--n)
//			*(dst++) = '\0';
//	return ret;
//}
//
//int main()
//{
//	char* arr[10] = { 0 };
//	my_strncpy(arr, "abcdefg", 4);
//	printf("%s", arr);
//	return 0;
//}