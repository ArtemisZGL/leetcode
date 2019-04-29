/*
动态规划
D(i) 表示第i个及之前最多能偷到的金额，就分成偷或者不偷第i家，如果偷第i家就不能偷第i-1家（即D（i-1）一定不用考虑）
注意D（i）不代表一定要偷第i家，只是会将其考虑进去
D（i） = max(money（i） + D(i-2), D(i-1))
初始化信息：D(0) = money(0),D(1) = max(money(1), money(0)）
*/
class Solution {
public:
    vector<int> D;
    int rob(vector<int>& nums) {
        if(nums.size() <= 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        D = vector<int>(nums.size(), -1);
        D[0] = nums[0];
        //注意初始状态的定义
        D[1] = max(nums[0], nums[1]);
        
        return getMaxNum(nums, nums.size() - 1);;
    }
    
    int getMaxNum(vector<int>& nums, int n)
    {
        if(n < 0)
            return 0;
        if(n == 0)
            return D[0];
        if(n == 1)
            return D[1];
        
        int fir = D[n-2] == -1 ? getMaxNum(nums, n-2) : D[n-2];
        fir += nums[n];
        int sec = D[n-1] == -1 ? getMaxNum(nums, n-1) : D[n-1];
        
        D[n] = max(fir, sec);
        return D[n];
    }
};
