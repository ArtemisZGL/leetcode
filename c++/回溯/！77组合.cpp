/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/ 
/*
	一开始因为就和排列差不多，但是发现组合是不同重复的，所以换了一种方法
	https://blog.csdn.net/lindaxym/article/details/80951872
	也是使用回溯的方法，从n个数里选1个，然后从后面的数里选k-1个，选够了就回到上一步，换一个继续选 
*/ 
class Solution {
public:
    /*
    map<int, bool> visited;
    
    void btsearch(vector<vector<int>>& ans, int n, int k, vector<int> pre)
    {
        if(pre.size() == k)
        {
            ans.push_back(pre);
            return;
        }
        
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                vector<int> temp = pre;
                temp.push_back(i);
                visited[i] = true;
                btsearch(ans, n, k, temp);
                visited[i] = false;
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        
        vector<int> pre;
        btsearch(ans, n , k, pre);
        return ans;
    }
    */
    
    void btsearch(vector<vector<int>>& ans, int begin, int n, int k, vector<int> pre)
    {
        //不用选了
        if(k==0)
        {
            ans.push_back(pre);
            return;
        }
        
        //按顺序选，到第n-k个往后选已经选不够k个了
        for(int i = begin; i <= n - k + 1; i++)
        {
            vector<int> temp = pre;
            temp.push_back(i);
            //从后面的数选k个，下一步就是选k-1个，从i+1位开始
            btsearch(ans, i + 1, n, k - 1, temp);
        }
    }
    
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> ans;
        
        vector<int> pre;
        btsearch(ans, 1, n , k, pre);
        return ans;
    }
    
};
