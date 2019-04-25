/*
给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数。每次移动可以使 n - 1 个元素增加 1。

示例:

输入:
[1,2,3]

输出:
3

解释:
只需要3次移动（注意每次移动会增加两个元素的值）：

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/

/*
n-1个元素增加1，可以看成是n个元素加1然后其中一个元素-1，也就是每次操作是1个元素减1
然后要达到的目标是所有元素相等，即要将所有元素都减到最小值，
操作次数 = （a1 - min) + (a2 - min) +...+ (an - min) = sum - n*min
时间复杂度为O(N)
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = numeric_limits<int>::max();
        //注意溢出 
        long sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < min)
                min = nums[i];
            sum += nums[i];
        }
        return sum - nums.size() * min;
    }
};
