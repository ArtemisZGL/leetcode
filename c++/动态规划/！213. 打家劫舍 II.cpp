/*
分割成区间，和之前的区别就是变成了环，可以看成0到倒数第二个（因为偷了第0个就不能偷最后一个），然后
还有1到最后一个（偷了最后一个就不能偷第0个）

然后状态定义和状态转移方程和之前是一样的

但是这里不方便用递归的方法去解决，因为这样的话就要分开存D了，在不同的区间D是不一样的
*/
class Solution {
public:
    vector<int> nums;
    int rob(vector<int>& nums) {
        if(nums.size() <= 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        this->nums = nums;
        
        return max(getMaxNum(0, nums.size() - 2), 
                   getMaxNum(1, nums.size() - 1));
    }
    
    int getMaxNum(int low, int height)
    {
        //由从上往下变成了从下往上
        int fir = 0, second = 0;
        for(int i = low; i <= height; i++)
        {
            int current = max(fir + nums[i], second);
            fir = second;
            second = current;
        }
        return second;
    }
};
