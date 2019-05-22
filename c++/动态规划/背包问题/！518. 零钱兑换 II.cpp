/*
完全背包问题
定义状态d[j]表示在前i个物品容量为j的情况下，组合的数目

(表示在j容量，i个物品的组合数等于i-1个物品的组合数加上j-coin的组合数，也就是刚好放多这个硬币的情况)
状态转移方程 d[j] = d[j] + d[j-coin]

初始状态D[0] = 1，表示金额为0的组合数是1，就是什么都不妨
*/

/*
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 

 

示例 1:

输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
示例 2:

输入: amount = 3, coins = [2]
输出: 0
解释: 只用面额2的硬币不能凑成总金额3。
*/ 

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        if(coins.size() == 0)
            return 0;
        
        int D[amount+1];
        for(int i = 0;i <= amount; i++)
            D[i] = 0;
        D[0] = 1;
        
        for(int i = 0; i < coins.size(); i++)
        {
            for(int j = coins[i]; j <= amount; j++)
            {
                D[j] = D[j] + D[j-coins[i]];
            }
        }
        return D[amount];
    }
};
