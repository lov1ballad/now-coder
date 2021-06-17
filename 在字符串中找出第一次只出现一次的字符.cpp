#define _CRT_SECURE_NO_WARNINGS 1
char FirstOnceChar(char* s)
{
	assert(s != NULL);
	const int tablesize = 256;
	int hashtable[256];
	for (int i = 0; i < tablesize; i++)
	{
		hashtable[i] = 0; //将哈希表初始化
	}

	char* hashKey = s;
	while (*hashKey != '\0')
	{
		hashtable[*(hashKey++)]++;
	}
	hashKey = s;
	while (*hashKey != '\0')
	{
		if (hashtable[*hashKey] == 1)
		{
			return *hashKey;
		}
		hashKey++;
	}
	return '\0';
}
int main()
{
	char* s = "abcdacfgb"; //
	cout << FirstOnceChar(s) << endl;
	system("pause");
}