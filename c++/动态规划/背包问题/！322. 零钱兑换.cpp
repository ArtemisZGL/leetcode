/*
0-1背包问题，就是把总金额看成背包容量，然后把硬币对应的金额看成硬币的体积，求最少能放满
不过在这里由于硬币是可以重复使用的，相当于完全背包问题

这时候在进行第二重循环，也就是遍历容量的时候就不用逆序了，而是用正序
因为用了空间优化，所以在遍历容量的时候我们用逆序，是因为我们在状态转移方程 Di(j) = max(Di-1(j), Di-1(j-w)+v)
中要用到上一轮的Di-1（j-w),如果正序的话就会覆盖掉变成了Di(j-w)
但是在完全背包问题中，我们在使用了一个物品以后还可以使用，所以状态转移方程Di(j) = max(Di-1(j), Di(j-w)+v)
这里的Di-1(j-w)改为Di(j-w)是因为在前i个物品的j-w容量下，第i个物品是能够重复使用的
所以此时我们反而要用正序来将前面的更新后才更新后面的

针对这一题，由于要取的是最小的物品数，所以应该用min，并且初始化所有为最大值，然后d[0] = 0，如果最后结果比aoumt还大
说明不存在这种情况 
D[j] = min(D[j], D[j-coins[i]] + 1);
*/

/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1
*/ 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(coins.size() <= 0)
            return -1;

        long long D[amount+1];
        for(int i = 0; i <= amount; i++)
            D[i] = numeric_limits<int>::max();
        
        D[0] = 0;
        
        for(int i = 0; i < coins.size(); i++)
        {
            //改为正序遍历
            for(int j = coins[i]; j <= amount; j++)
            {
                D[j] = min(D[j], D[j-coins[i]] + 1);
            }
        }
        
        return D[amount] > amount ? -1 : D[amount];
    }
};
