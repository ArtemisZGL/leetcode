/*
https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/1e2c588c-72b7-445e-aacb-d55dc8a88c29.png
同样是动态规划，状态定义和之前的一样，不过不同状态之间的转换有所不同
*/

/*
给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每次交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

示例 1:

输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
输出: 8
解释: 能够达到的最大利润:  
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
*/ 
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int days = prices.size();
        
        if(days == 0)
            return 0;
        
        //定义状态
        int buy[days];
        int s1[days];
        int sell[days];
        int s2[days];
        
        //初始状态
        buy[0] = -prices[0];
        s1[0] = -prices[0];
        sell[0] = 0;
        s2[0] = 0;
        
        for(int i = 1; i < days; i++)
        {
            buy[i] = max(s2[i-1], sell[i-1]) - prices[i];
            s1[i] = max(buy[i-1], s1[i-1]);
            sell[i] = max(buy[i-1], s1[i-1])  + prices[i] - fee;
            s2[i] = max(s2[i-1], sell[i-1]);
        }
        return max(s2[days-1], sell[days-1]);
    }
};
