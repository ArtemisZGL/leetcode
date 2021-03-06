/*
给定一个长度为 n 的整数数组，你的任务是判断在最多改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中所有的 i (1 <= i < n)，满足 array[i] <= array[i + 1]。

示例 1:

输入: [4,2,3]
输出: True
解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
示例 2:

输入: [4,2,1]
输出: False
解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
说明:  n 的范围为 [1, 10,000]。
*/ 


/*
贪心的思想，每次遇到不符合条件的就进行改变，总是优先让前面的变小（因为非递减，这样做可以使后面的影响尽可能小） 
遇到比后面大，就两种选择，如果后面比前面的前面还小，说明不能把前面的变小，这样前面的规则就被破坏了
就只能把后面的变大
一直检验下去，超过1次就false
注意边界条件 
*/ 

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() <=2) //两个肯定可以
            return true;
        
        int count = 0;
        
        //不用判断最后一个所以size()-1
        for(int i = 0;i < nums.size() - 1 && count < 2; i++)
        {
            if(nums[i] > nums[i+1]) //和后面一个比较,前一个变小或者后一个变大
            {
                count++;
                if(i == 0)
                    nums[i] = nums[i+1];
                else if(nums[i - 1] < nums[i+1])
                    nums[i] = nums[i+1];
                else
                    nums[i+1] = nums[i];
            }
        }
        
        return count < 2;
    }
};
