/*
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
*/ 

class Solution {
public:
    
    void  btsearch(vector<vector<int>>& ans, int begin, int n, int k, vector<int> pre)
    {
        if(k == 0)
        {
            if(accumulate(pre.begin(), pre.end(), 0) == n)
                ans.push_back(pre);
            return;
        }
        
        for(int i = begin; i <= 9; i++)
        {
            int sum = accumulate(pre.begin(), pre.end(), 0);
            if(sum + i <= n)
            {
                vector<int> temp = pre;
                temp.push_back(i);
                btsearch(ans, i + 1, n, k - 1, temp);
            }
        }
    }
        
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> pre;
        btsearch(ans, 1, n, k, pre);
        return ans;
    }
};
