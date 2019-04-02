/*
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1
*/ 
/*
矩阵的连通分量个数问题，和最大连通分量做法类似，深度优先搜素 
*/ 
class Solution {
public:
    bool findUnvisited(stack<pair<int, int>>& mstack, map<pair<int, int>, bool>& visited,
                      vector<vector<char>>& grid)
    {
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] == '1' && visited[pair<int, int>(i, j)] == false)
                {
                    mstack.push(pair<int,int>(i, j));
                    visited[pair<int, int>(i,j)] = true;
                    return true;
                }
        }
        return false;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        map<pair<int, int>, bool> visited;
        stack<pair<int, int>> mstack;
        int count = 0;
        
        int ymax = grid.size() - 1;
        if(ymax < 0)    //小心输入是空
            return count;
        int xmax = grid[ymax].size() - 1;
        
        while(!mstack.empty() || findUnvisited(mstack, visited, grid))
        {
            pair<int, int> cur = mstack.top();
            //上下左右四个点
            pair<int, int> left(cur.first, cur.second - 1);
            pair<int, int> right(cur.first, cur.second + 1);
            pair<int, int> top(cur.first - 1, cur.second);
            pair<int, int> down(cur.first+1, cur.second);
            //先看有没有越界，在看是否为1相当于看是不是连通
            //最后看有没有访问过
            if(left.second >= 0 && grid[left.first][left.second] == '1'
               && visited[left] == false)
            {
                mstack.push(left);
                visited[left] = true;
            }
            else if(right.second <= xmax && grid[right.first][right.second] == '1'
                   && visited[right] == false)
            {
                mstack.push(right);
                visited[right] = true;
            }
            else if(top.first >= 0 && grid[top.first][top.second] == '1'
                   && visited[top] == false)
            {
                mstack.push(top);
                visited[top] = true;
            }
            else if(down.first <= ymax && grid[down.first][down.second] == '1'
                   && visited[down] == false)
            {
                mstack.push(down);
                visited[down] = true;
            }
            else
            {
                
                mstack.pop();
                //栈空的时候才重新计算，说明把一个连通分量遍历完了
                if(mstack.empty())
                {
                    count++;
                }
            }
        }
        return count;
    }
};
