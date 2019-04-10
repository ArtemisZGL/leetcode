/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/ 

/*
回溯的思想，选了能继续选就继续选，不能就退回去上一个递归
 这里还要注意和普通求组合的不同，因为是可以随便选任意多个数，并且可以重复选一个数
 但是同样的组合还是不允许出现的 
*/ 
class Solution {
public:
    void btsearch(int target, vector<int>& candidates, vector<int> pre, vector<vector<int>>& ans, int start)
    {
        
        //可以选任意多个数，所以不用设置k
        for(int i = start; i < candidates.size(); i++)
        {
            vector<int> temp = pre;
            temp.push_back(candidates[i]);
            int sum = accumulate(temp.begin(), temp.end(), 0);
            if(sum == target)
                ans.push_back(temp);
            else if(sum < target)   //因为这里是可以重复选的，所以直接下一次可以从i开始，普通组合只能从i+1开始
                btsearch(target, candidates, temp, ans, i);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> pre;
        btsearch(target, candidates, pre, ans, 0);
        return ans;
    }
};
