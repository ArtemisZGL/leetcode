/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/*
回溯的想法，每次都先加进去，然后到下一个位置，到底了再回来 
*/ 

class Solution {
public:
    void btsearch(vector<vector<int>>& ans, vector<int>& nums, vector<int> pre, int begin)
    {
        for(int i = begin; i < nums.size(); i++)
        {
            vector<int> temp = pre;
            temp.push_back(nums[i]);
            ans.push_back(temp);
            btsearch(ans, nums, temp, i+1);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> ans;
         vector<int> pre;
        ans.push_back(pre);
        btsearch(ans, nums, pre, 0);
        return ans;
    }
};
