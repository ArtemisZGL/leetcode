/*
对只能交易两次的推广，推广到只能交易k次

注意这里的交易k次其实是买卖算一次，新的一次买才算是到达新的一次操作流程中

之前两次交易的时候，要保存firstsell，firstBuy， secSell, secBuy
这次k次交易的话，其实就是扩展，用数组来存
D[i][j] 第一维表示k次操作，第二维表示买或者卖，状态的含义就是在前i天买(卖)k次的最大利润
由于状态转移只和前一天的状态有关，所以可以省略天数这一维

状态转移方程就是和之前一样
买： D[j][1] = max(D[j][1], D[j-1][0] - prices[i]); 等于前一天操作k次买， 前一天操作k次卖，然后今天买的最大值
卖：  D[j][0] = max(D[j][0], D[j][1] + prices[i]); 等于前一天操作k次卖，今天操作k次买然后卖的最大值，相当于今天买了可以马上卖，也算是操作k次
*/


/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [2,4,1], k = 2
输出: 2
解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2:

输入: [3,2,6,5,0,3], k = 2
输出: 7
解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
*/ 

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        
        //k的数目比天数的一半还多，相当于可以随便买卖操作
        //用贪心
        if(k > prices.size() / 2)
        {
            int res = 0;
            for(int i = 1; i < prices.size(); i++)
            {
                if(prices[i] > prices[i-1])
                    res += prices[i] - prices[i-1];
            }
            return res;
        }
        
        
        int D[k+1][2];
        
        //初始化，记得把交易第0次的买初始化成-prices
        for(int i = 0; i <= k; i++)
        {
            D[i][0] = 0;    //卖
            D[i][1] = -prices[0];  //买
        }
        
        int maxx = 0;
        
        //从第2天开始，第一天已经初始化
        for(int i = 1; i < prices.size(); i++)
        {
            for(int j = 1; j <= k; j++)
            {
                //注意这里的D[j][1]而不是D[j-1][1]
                D[j][1] = max(D[j][1], D[j-1][0] - prices[i]);
                D[j][0] = max(D[j][0], D[j][1] + prices[i]);
                maxx = max(D[j][0], maxx);
                cout << D[j][0] << " " << D[j][1] << endl;
            }
        }
        
        return maxx;
    }
};
