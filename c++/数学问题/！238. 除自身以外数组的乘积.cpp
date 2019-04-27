/*
给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
*/ 

/*
如果可以用除法，就直接全部乘起来，然后对应每个数进行除就行了

时间复杂度要求O（n），空间复杂度要求常数
先初始化结果全为1，
从左往右遍历，每次乘以左边全部数的乘积left，left再乘以当前的数进行更新
从右往左遍历，每次乘以右边全部数的乘积right，right再乘以当前的数进行更新 
*/ 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> result(nums.size(), 1);
        if(nums.size() == 0)
            return result;
        
        int left = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            result[i] *= left;
            left = left * nums[i];
        }
        
        int right = nums[nums.size()-1];
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            result[i] *= right;
            right *= nums[i];
        }
        
        return result;
    }
};
