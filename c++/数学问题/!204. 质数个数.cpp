/*
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/ 

/*
埃拉托斯特尼筛法在每次找到一个素数时，将能被素数整除的数排除掉。 素数是从2开始的，注意溢出的问题 
*/ 

class Solution {
public:
    int countPrimes(int n) {
        
        if(n <=0 )
            return 0;
        
        //用于保存是不是质数，然后一开始初始化都是false，然后用埃拉托斯特尼筛法在每次找到一个素数时，将能被素数整除的数排除掉。
        bool notPrimes[n] = {false};
        int count = 0;
        //从2开始，1不算质数
        for(int i = 2; i < n; i++)
        {   
            //如果不是质数
            if(notPrimes[i])
                continue;
            
            count++;
            
            //将质数的倍数去除掉,从i*i开始，因为前面的已经计算过了.每次加i，就是i的倍数
            for(long long j = ((long long)i )* i; j < n; j += i)
            {
                notPrimes[(int)j] = true;
            }
            
        }
        return count;
    }
};
