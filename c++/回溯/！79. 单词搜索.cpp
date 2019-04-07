/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.
*/ 

/*
回溯的思想解决排列组合的问题，普通dfs可以用栈和visited来做，但是回溯最好还是用递归和visited
因为回溯的时候在一条链上是不能visit两次，但是在另外一条链上是可以visit，所以回来的时候要把visited改成false
然后对每个方向进行搜索，遇到不行就返回上一个方向 
*/ 

class Solution {
public:
    
    map<pair<int,int>, bool> visited;
    pair<int, int> directions[4] = {pair<int, int>(-1,0), pair<int, int>(1,0), pair<int, int>(0, -1), pair<int, int>(0, 1)};
    
    bool btsearch(string word, vector<vector<char>>& board, string curStr, pair<int,int> curPos)
    {
        //已经找到
        if(curStr.length() == word.length())
            return true;
        
        //越界或者是不符合
        if(curPos.first < 0 || curPos.first > board.size() - 1
           || curPos.second < 0 || curPos.second > board[0].size() - 1
           || board[curPos.first][curPos.second] != word[curStr.length()])
            return false;
        
        curStr += board[curPos.first][curPos.second];
        
        for(int i = 0; i < 4; i++)
        {
            pair<int,int> nextPos(curPos.first + directions[i].first, curPos.second + directions[i].second);
            
            //如果在这个分支没访问过
            if(visited[nextPos]== false)
            {
                visited[nextPos]= true;
                //搜索到就结束
                if(btsearch(word, board, curStr, nextPos))
                    return true;
                //分支返回要改回来
                visited[nextPos]= false;
            }
        }
        
        //每个分支都搜不到才是false
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                visited[pair<int,int>(i,j)] = true;
                if(btsearch(word, board, "", pair<int,int>(i,j)))
                    return true;
                //一个分支后要变回来
                visited[pair<int,int>(i,j)]= false;
            }
        }
        return false;
    }
};
