/*
https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/83acbb02-872a-4178-b22a-c89c3cb60263.jpg
定义四个状态： Buy(i)代表第i天买股票的最大利润，S1(i)代表第i天持有股票的利润
              sell(i)代表第i天卖股票的最大利润，S2(i)代表第i天没持有股票的利润
              (状态s2的存在就很好的达到了冷却期的效果，不能由sell直接转到buy状态)
状态转移方程：
             buy[i] = s2[i - 1] - prices[i];  ->前一天买入股票
            s1[i] = Math.max(buy[i - 1], s1[i - 1]); ->前一天买股票的利润，或者前一天持有股票的利润
            sell[i] = Math.max(buy[i - 1], s1[i - 1]) + prices[i]; ->前一天刚买今天就卖，或者前一天持有股票今天卖
            s2[i] = Math.max(s2[i - 1], sell[i - 1]); ->前一天刚卖股票，或者前一天已经是没有股票
*/

/*
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。?

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:

输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
*/ 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        
        int buy[prices.size()];
        int s1[prices.size()];
        int sell[prices.size()];
        int s2[prices.size()];
        
        buy[0] = -prices[0];
        s1[0] =  -prices[0];
        sell[0] = 0;
        s2[0] = 0;
        
        for(int i = 1; i < prices.size(); i++)
        {
            buy[i] = s2[i - 1] - prices[i];
            s1[i] = max(buy[i - 1], s1[i - 1]);
            sell[i] = max(buy[i - 1], s1[i - 1]) + prices[i];
            s2[i] = max(s2[i - 1], sell[i - 1]);
        }
        return max(s2[prices.size()-1], sell[prices.size()-1]);
    }
};
