/*
信件排错问题
有 N 个 信 和 信封，它们被打乱，求错误装信方式的数量。（全部都装错的数量） 

第一种方法最简单：有个全错位排列公式：S=n!(1-1/1!+1/2!-1/3!+...(-1)^n/n!)

另一种方法就是总的n!减去所有信封装对的情况（哪怕只有一封装对也算）
S=n!-C(n,1)f(n-1)-C(n,2)f(n-2)-...C(n,n-2)f(2)-1 

动态规划，先定义状态D(i),表示i个信封和信的错误排放方式数量
转移方程：错误装信：假设第i封信放到第j个信封，第j封信放到第k个信封，那么问题就在于判断i是否等于k
如果i == k
	那么就是剩下i-2个信和信封，所以排错方式就是d（i-2)，然后这个j的选取有i-1种方式，所以总共有（i-1）*d（i-2)种
如果i != k
	此时如果把i和j信件交换，j就是在正确位置，其余还是在错误位置，因此有d(i-1)中方式，然后j的选取又有i-1种，因此有 (i-1) * d(i-1)
	
D(i) = (i-1) * d(i-2) + (i-1) * d(i-1)
 
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> D;

int DPmethor(int n)
{
	if(n <= 2)
		return D[n];
	
	int fir = D[n-2] == -1 ? DPmethor(n-2) : D[n-2];
	int sec = D[n-1] == -1 ? DPmethor(n-1) : D[n-1];
	D[n] = (n-1) * (fir + sec);
	return D[n];
}

int formularMethor(int n)
{
	//分子和分母,循环的时候每次乘以i就行了 
	int up = 1;
	int down = 1;
	double sum = 1;
	
	//从1开始，否则分母为0不好弄 
	for(int i = 1; i <= n; i++)
	{
		up *= -1;
		down *= i;
		//注意这里的类型，temp和up和sum都要是浮点数，两个整数相除，在赋值前就已经截断了，浮点加到整数也会截断 
		double temp = (double)up / down;
		//cout << up << " " << down << " " << temp << endl;
		sum += temp;
	}
	return down * sum;
}

  
int main()
{
	
	int n;
	cin >> n;
	//初始化动态规划的状态 
	D = vector<int>(n + 1 , -1); 
	if(n <= 1)
		cout << 0 << endl;
	else if(n == 2)
		cout << 1 << endl;
	else
	{
		D[1] = 0;
		D[2] = 1;
		
		cout << DPmethor(n) << endl;
		cout << formularMethor(n) << endl;	
	}
	
} 

