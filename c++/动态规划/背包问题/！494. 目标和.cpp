/*
sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
2 * sum(P) = target + sum(nums)

根据上面的式子，我们可以转换为0-1背包问题，容量是（target + sum ）/ 2
找有多少中放法可以将背包放满
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0)
            return 0;
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        
        if(sum < S || (sum + S) % 2 != 0)
            return 0;
        
        int W = (sum + S) / 2;
        vector<int> D(W + 1, 0); //代表该容量刚好放满的次数
        //初始化
        D[0] = 1;
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = W; j >= nums[i]; j--)
            {
                //加上刚好缺少当前num的
                D[j] = D[j] + D[j-nums[i]];
            }
        }
        return D[W];
    }
};
