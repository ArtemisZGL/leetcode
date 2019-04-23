/*
找到n!的二进制表示中最低位1的位置。
若2进制最低位为0，除以2就是右移1位，若最低位是1，则除不开2. 故最低1的位置就是 n!可以除开2的次数+1
除2就是找2这个因子的个数，和之前找5的因子个数是一样的方法 
最后还要加1，因为是位置 
*/ 

#include <iostream>
using namespace std;

void findLowestOne(int n)
{
	if(n == 0)
		return 0;
	
	return n / 2 + findLowestOne(n / 2);
	
	/*
	int ans = 0;
    while(n)
    {
        n = n >> 1;
        ans += n;
    }
    return ans + 1;
	*/
}
int main()
{
	int n;
	cin >> n;
	cout << findLowestOne(n) + 1;
} 
