/*
题目描述：假设农场中成熟的母牛每年都会生 1 头小母牛，并且永远不会死。
		 第一年有 1 只小母牛，从第二年开始，母牛开始生小母牛。每只小
		 母牛 3 年之后成熟又可以生小母牛。给定整数 N，求 N 年后牛的数量。

动态规划： 
状态变量：D(i)表示第i年母牛的数量
转移方程 ：D(i) = D(i-1) + D(i-3) 上一年的数量加前三年的数量，因为前3年的到今年能升，中间前2年和前1年增加的都不能生
初始值：D(1) = 1，D(2) = 2, D(3) = 3 
*/ 

#include <iostream>
#include <vector>
using namespace std;

vector<int> D;

int getCowNum(int n)
{
	if(n <= 3)
		return D[n];
	
	int fir = D[n-1] == -1 ? getCowNum(n-1) : D[n-1];
	int sec = D[n-3] == -1 ? getCowNum(n-3) : D[n-3];
	
	D[n] = fir + sec;
	return D[n];
}

int main()
{
	int n;
	cin >> n;
	if(n < 0)
		cout << 0 << endl;
	else if(n <= 3)
		cout << 3 << endl;
	else
	{
		D = vector<int>(n + 1, -1);
		D[1] = 1;
		D[2] = 2;
		D[3] = 3;
		cout << getCowNum(n) << endl;
	}
}
