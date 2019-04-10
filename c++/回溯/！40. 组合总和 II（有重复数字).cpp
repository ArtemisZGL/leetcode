/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
*/ 
/*
这里的输入数组中是有重复数字的，每个数字可以选多次，但是该个数只能选一次
为了避免重复的情况，还要加入visit，来进行验证 
*/ 
class Solution {
public:
    map<int, bool> visited;
    
    void btsearch(int target, vector<int>& candidates, vector<int> pre, vector<vector<int>>& ans, int start)
    {
        
        //可以选任意多个数，所以不用设置k
        for(int i = start; i < candidates.size(); i++)
        {
            //加visit的主要作用
            //如果前一个数和当前的数一样，并且这个数有visit就可以继续选，因为可以选重复的数字
            //但如果前一个数没visit的话，得到的情况都是和前一个数一样的，所以就直接跳过
            if(i != 0 && candidates[i] == candidates[i-1] && visited[i - 1] == false)
                continue;
            vector<int> temp = pre;
            temp.push_back(candidates[i]);
            int sum = accumulate(temp.begin(), temp.end(), 0);
            if(sum == target)
                ans.push_back(temp);
            else if(sum < target)   //因为这里是不可以重复选的，从i+1开始
            {
                visited[i] = true;
                btsearch(target, candidates, temp, ans, i + 1);
                visited[i] = false;
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> pre;
        btsearch(target, candidates, pre, ans, 0);
        return ans;
    }
};
