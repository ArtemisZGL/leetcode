/*
��С������Ϊ�����ĳ˻��������Լ��
*/ 

#include <iostream>
using namespace std;
int gcd(int a, int b);
int lcm(int a, int b); 
int main()
{
	while(cin)
	{
		int a, b;
		cin >> a >> b;
		cout << lcm(a, b) << endl;
	}
}

int lcm(int a, int b)
{
	return a * b / (gcd(a,b));
}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
