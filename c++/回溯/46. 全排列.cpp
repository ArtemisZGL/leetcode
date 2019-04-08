
/*
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/ 
/*
排列问题用回溯的方法，注意单个支链上才设定visited，并且传递的pre注意每一步都是不能影响 
*/ 
class Solution {
public:
    map<int, bool> visited;
    
    void btsearch(vector<vector<int>>& ans, vector<int>& nums, vector<int>pre)
    {
        //已经满足条件
        if(pre.size() == nums.size())
        {
            ans.push_back(pre);
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
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        vector<int> pre;
        btsearch(ans, nums, pre);
        return ans;
    }
};
