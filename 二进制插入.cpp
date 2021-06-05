#define _CRT_SECURE_NO_WARNINGS 1
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i)
	{
		return n | (m << j);
	}
};