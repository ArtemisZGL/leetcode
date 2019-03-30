/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/

/*
二分查找，先找到值，再左右两边找 
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        int med = 0;
        if(end < 0)
            return vector<int>{-1,-1};
        while(begin <= end)
        {
            med = begin + (end - begin) / 2;
            if(nums[med] < target)
                begin = med + 1;
            else if(nums[med] > target)
                end = med - 1;
            else
                break;
        }
        if(nums[med] != target)
            return vector<int>{-1,-1};
        begin = end = med;
        while(begin >= 0 && nums[begin] == target)
            begin--;
        
        while(end < nums.size() && nums[end] == target)
            end++;
        return vector<int>{begin+1,end-1};
    }
};
