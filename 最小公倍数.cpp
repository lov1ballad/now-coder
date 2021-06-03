#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/questionTerminal/d077de5c3623407b953bfdf49843dd43
#include <iostream>
using namespace std;
long gcd(long a, long b)
{
	if (a%b == 0) return b;
	else return gcd(b, a%b);
}
int main()
{
	long a, b, s;
	cin >> a >> b;
	s = gcd(a, b);
	cout << s*(a / s)*(b / s);
	return 0;
}