/*
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/ 

/*
和之前重复数组求组合差不多，就是要先排序，然后加visit数组，如果前一个和当前相同，并且前一个没vistit就跳过，否则就和前一个的情况重复 
*/ 

class Solution {
public:
    map<int, bool> visited;
    
    void btsearch(vector<vector<int>>& ans, int begin, vector<int> pre, vector<int>& nums)
    {
        for(int i = begin; i < nums.size(); i++)
        {
            //去掉重复的情况
            if(i != 0 && nums[i - 1] == nums[i] && visited[i - 1] == false)
                continue;
            
            vector<int> temp = pre;
            temp.push_back(nums[i]);
            
            visited[i] = true;
            ans.push_back(temp);
            btsearch(ans, i + 1, temp, nums);
            //回溯回来以后把visited改成false
            visited[i] = false;
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> pre;
        //把空集加进去
        ans.push_back(pre);
        btsearch(ans, 0, pre, nums);
        return ans;
    }
};
