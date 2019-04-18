/*
辗转相除法求最大公约数 

使用位操作和减法来求解最大公约数

如果 a 和 b 均为偶数，f(a, b) = 2*f(a/2, b/2);
如果 a 是偶数 b 是奇数，f(a, b) = f(a/2, b);
如果 b 是偶数 a 是奇数，f(a, b) = f(a, b/2);
如果 a 和 b 均为奇数，f(a, b) = f(b, a-b);
 乘 2 和除 2 都可以转换为移位操作。
*/ 

#include <iostream>
using namespace std;
int gcd(int a, int b);
int gcd2(int a, int b);
int main()
{
	while(cin)
	{
		int a, b;
		cin >> a >> b;
		cout << gcd(a, b) << endl;
		cout << gcd2(a, b) << endl;
	}
}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int gcd2(int a, int b)
{
	if(a < b)
		return gcd2(b, a);
	
	if(b == 0)
		return a;
	
	bool evenA = (a % 2 == 0);
	bool evenB = (b % 2 == 0);
	
	if(evenA && evenB)
	{
		return 2 * gcd2(a >> 1, b >> 1);
	}
	else if(evenA && !evenB)
	{
		return gcd2(a >> 1, b);
	}
	else if(!evenA && evenB)
	{
		return gcd2(a, b >> 1);
	}
	else
		return gcd2(b, a - b);
} 
