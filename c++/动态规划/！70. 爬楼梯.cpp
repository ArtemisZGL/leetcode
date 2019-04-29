/*
动态规划中比较经典的跳台阶问题：
首先定义一个状态：D（i）表示到达第i个台阶的方法数
则根据题意，找到一个状态转移方程：D（i） = D（i-1） + D(i-2)
另外还要规定初值D（1） = D（2） = 1，小于1的都设为0
动态规划就是将问题划分为子问题，对每个子问题求最优解，并且子问题是有可能重复的，所以要把子问题的结果存起来
*/

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
*/ 
class Solution {
public:
    vector<int> D;
    int climbStairs(int n) {
        if(n <= 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        
        //初始化,因为从1开始，所以要n+1
        D = vector<int>(n + 1, -1);
        D[1] = 1;
        D[2] = 2;
        return getResolveNum(n);
    }
    
    int getResolveNum(int n)
    {
        if(n <= 0)
            return 0;
        if(n <= 2)
            return D[n];
        
        //判断是否已经计算过该子问题
        
        int fir = D[n-1] == -1 ? getResolveNum(n-1) : D[n-1];
        int sec = D[n-2] == -1 ? getResolveNum(n-2) : D[n-2];
        
        //纪录子问题结果
        D[n] = fir + sec;
        return fir + sec;
    }
};
