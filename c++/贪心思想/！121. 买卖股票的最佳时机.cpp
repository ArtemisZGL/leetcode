/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
*/ 

/*
贪心思想，遍历一次，每次将当前值和最小值相减，并和最大结果比较。最小值的话要时时更新，
如果当前比最小值小，就要更新最小值
这个做法能成功是因为只能后面减前面，当前值比前面最小值小不会影响前面的计算结果，到
计算后面的结果时也能更新。 
*/ 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //动态规划
        /*
        if(prices.size() <= 1)
            return 0;
        if(prices.size() <= 2)
            return max(prices[1] - prices[0], 0);
        
        vector<int> temp(prices.begin(), prices.begin() + prices.size() - 1);
        int count = ( prices.size() - 1);
        int minNum = *min_element(prices.begin(), prices.begin() + count);
        return max(maxProfit(temp), prices[prices.size() - 1] - minNum);
        */
        
        if(prices.size() == 0)
            return 0;
        int currentMin = prices[0];
        int maxRes = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] - currentMin > maxRes)
                maxRes = prices[i] - currentMin;
            
            if(prices[i] < currentMin)
                currentMin = prices[i];
        }
        return maxRes;
    }
};
