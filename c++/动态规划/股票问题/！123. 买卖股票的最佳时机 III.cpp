/*
重要的是要搞清楚各个状态之间的转移，并注意各个状态的更新顺序

多状态动态规划：设立四个状态，我们的想法是在同一天是有四个状态的，这些状态直接是互不影响，相当于平行世界
firstBuy, firstSell, secBuy, secSell四个状态代表在前i天第一次买，第一次卖等的最大利润
本来应该是一个数组来存储不同天的状态的，但是考虑到只和前一天的状态有关，可以进行空间上的优化

状态转移 firstBuy[i] = max(firstBuy[i-1], -prices[i]) 前i-1天第一次买最大利润或者今天第一次买
        firstSell[i] = max(firstSell[i-1], firstBuy[i] + prices[i]) 前i-1天第一次卖最大利润或者前i天第一次买然后今天卖（由于必须是要先卖了才能再买，所以只能是第一次买之后第一次卖）(可以今天买了马上卖)
        secBuy[i] = max(secBuy[i-1], firstSell[i] - prices[i]) 前i-1天第二次卖最大利润或者前i天第一次卖最大利润-今天的价格
        secSell[i] = max(secSell[i-1], secBuy[i] + prices[i]) 前i-1天第二次卖最大利润或者是前i天第二次买利润马上卖掉

*/

/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [3,3,5,0,0,3,1,4]
输出: 6
解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
*/ 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        //定义并初始化状态
        int firstBuy = -prices[0];
        int firstSell = 0;
        int secBuy = INT_MIN; //这个不能初始化为0，买东西的利润是负的
        int secSell = 0;
        
        for(int i = 1; i < prices.size(); i++)
        {
            firstBuy = max(firstBuy, -prices[i]);
            firstSell = max(firstSell, firstBuy + prices[i]);
            secBuy = max(secBuy, firstSell - prices[i]);
            secSell = max(secSell, secBuy + prices[i]);
        }
        return max(firstSell, secSell);
    }
};
