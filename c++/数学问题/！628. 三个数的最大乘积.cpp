/*
三个数的乘积最大，还要考虑到负数相乘的情况，所以不能简单的找最大的三个数相乘，还要找出最小的2个数，
因为他们相乘是正数，最后比较三个正数相乘大还是最大正数和两个最小负数相乘大
*/

/*
给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

示例 1:

输入: [1,2,3]
输出: 6
示例 2:

输入: [1,2,3,4]
输出: 24
注意:

给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。
输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。
*/ 
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = numeric_limits<int>::min();
        int max2 = numeric_limits<int>::min();
        int max3 = numeric_limits<int>::min();
        
        int min1 = numeric_limits<int>::max();
        int min2 = numeric_limits<int>::max();
        int min3 = numeric_limits<int>::max();
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2)
            {
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i] > max3)
                max3 = nums[i];
            
            if(nums[i] < min1)
            {
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] < min2)
                min2 = nums[i];
            
        }
        
        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};
