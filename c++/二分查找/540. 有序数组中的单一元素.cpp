/*
给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。

示例 1:

输入: [1,1,2,3,3,4,4,8,8]
输出: 2
示例 2:

输入: [3,3,7,7,10,11,11]
输出: 10
*/ 

class Solution {
public:
    /*
    第一种方法位运算，进行异或，适用于无序的
    */
    /*
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            result ^=  nums[i];
        }
        return result;
    }
    */
    
    /*
    如果是有序的，可以用二分查找
    令 index 为 Single Element 在数组中的位置。如果 m 为偶数，并且 m + 1 < index，那么 nums[m] == nums[m + 1]；m + 1 >= index，那么 nums[m] != nums[m + 1]。

从上面的规律可以知道，如果 nums[m] == nums[m + 1]，那么 index 所在的数组位置为 [m + 2, h]，此时令 l = m + 2；如果 nums[m] != nums[m + 1]，那么 index 所在的数组位置为 [l, m]，此时令 h = m。

因为 h 的赋值表达式为 h = m，那么循环条件也就只能使用 l < h 这种形式。
    */
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while(start < end)
        {
            int med = start + (end - start) / 2;
            if(med % 2 == 1)
            {
                med--;
            }
            if(nums[med] == nums[med+1])
                start += 2;
            else
                end = med;
            
        }
        return nums[start];
    }
};
