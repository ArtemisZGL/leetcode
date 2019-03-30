/*

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1
示例 2:

输入: [4,5,6,7,0,1,2]
输出: 0
*/ 

/*
二分查找的方法，如果中间的比右边要大，说明旋转到了右边，所以l = m + 1
如果中间的比右边要小，说明小的在左边，h = m
由于h= m，所以循环条件要改为 < 

*/ 

class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1;
        while(begin < end)
        {
            int med = begin + (end - begin) / 2;
            if(nums[med] > nums[end])
                begin = med + 1;
            else
                end = med;
        }
        return nums[begin];
    }
};
