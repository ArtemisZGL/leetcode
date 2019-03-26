/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/ 

/*
贪心的思想，每次只要前面的和大于0，就加当前这个，然后将结果和最优的结果比较，每次都要将最优的记下来 
如果还想把区间给记下来，还要弄两个数组，加的时候就push，不加就clear，最后比最优好，就记下来 
*/ 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxRes = nums[0], preSum = 0;
       vector<int> resultInterval;
        vector<int> currentInterval;
        for(int i = 0; i < nums.size(); i++)
        {
            if(preSum > 0)  //如果前面的和大于0，就贪心的想要继续加下一个
            {
                preSum += nums[i];
                currentInterval.push_back(nums[i]);
            }
            else        //否则就重新从现在开始
            {
                preSum = nums[i];
                currentInterval.clear();
                currentInterval.push_back(nums[i]);
            }
            
            //每个步骤之后，都要看现在的结果和以往的结果相比是不是最好的，纪录下最好的结果
            if(maxRes < preSum)
                resultInterval = currentInterval;
            maxRes = max(maxRes, preSum);
        }
        for(int num : resultInterval)
            cout << num  << " ";
        return maxRes;
    }
};
