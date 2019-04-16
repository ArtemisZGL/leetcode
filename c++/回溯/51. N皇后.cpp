/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。



上图为 8 皇后问题的一种解法。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/ 

/*
典型的回溯问题，一行一行的放皇后，对每一行，遍历每一列，然后通过map检查放这一列当前是否冲突，不冲突就继续放，
如果每一列都不能放就要回溯

要注意回溯时的pop_back以及visitd变量修改回来，这里的visited变量有四个，行列两个对角是否已经用了，注意对角的下标计算 
*/ 


class Solution {
public:
    map<int, bool> rowUsed;
    map<int, bool> colUsed;
    //r+c
    map<int, bool> d45Used;
    //n-1-(r - c)
    map<int, bool> d135Used;
    
    void btsearch(vector<vector<string>>& ans, int n, int curRow, vector<string> curPlan)
    {
        if(curRow == n)
        {
            ans.push_back(curPlan);
            return;
        }
        
        for(int col = 0; col < n; col++)
        {
            //不冲突条件
            if(!rowUsed[curRow] && !colUsed[col] && !d45Used[curRow + col] && !d135Used[n-1-curRow+col])
            {
                rowUsed[curRow] = true;
                colUsed[col] = true;
                d45Used[curRow + col] = true;
                d135Used[n-1-curRow+col] = true;
                
                //放皇后
                string rows = "";
                for(int j = 0; j < n; j++)
                    rows += ".";
                rows[col] = 'Q';
                
                curPlan.push_back(rows);
                
                //继续下一行
                btsearch(ans, n, curRow + 1, curPlan);
                
                //回溯
                curPlan.pop_back();
                rowUsed[curRow] = false;
                colUsed[col] = false;
                d45Used[curRow + col] = false;
                d135Used[n-1-curRow+col] = false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
        
        vector<string> temp;
        btsearch(ans, n, 0, temp);
        
        return ans;
    }
};
