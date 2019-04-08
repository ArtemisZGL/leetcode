/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/ 
class Solution {
public:
    map<int, bool> visited;
    
    void btsearch(set<vector<int>>& ans, vector<int>& nums, vector<int>pre)
    {
        //已经满足条件
        if(pre.size() == nums.size())
        {
            ans.insert(pre);
            return;
        }
        
        //找到没visited
        int i = 0;
        for(; i < nums.size(); i++)
        {
            if(!visited[i])
            {
                //添加到
                vector<int> temp = pre;
                temp.push_back(nums[i]);
                //下一轮回溯搜索
                visited[i] = true;
                btsearch(ans, nums, temp);
                //回来后把visted改回来
                visited[i] = false;
            }
        }
        
        
        
    }
    

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        
        vector<int> pre;
        btsearch(ans, nums, pre);
        vector<vector<int>> real(ans.begin(), ans.end());
        return real;
    }
};
