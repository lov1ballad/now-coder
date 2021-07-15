#define _CRT_SECURE_NO_WARNINGS 1
// write your code here cpp
#include <iostream>
using namespace std;
int main(){
	int n;
	long long a[100];
	a[1] = 1;
	a[2] = 2;
	while (cin >> n){
		for (int i = 3; i <= n; i++){
			a[i] = a[i - 1] + a[i - 2];
		}
		cout << a[n] << endl;
	}
}