/*
给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。
*/ 
/*
非完全连通图的计算最大连通分量问题，
可以用深度优先搜索，深度优先搜索主要解决的是可到达性问题，遍历到的点都是初始节点能到的 
两个关键，一个是栈，一个是visited
非完全连通还要考虑有多个子图的情况 
*/
class Solution {
public:
    bool findUnvisited(stack<pair<int, int>>& mstack, map<pair<int, int>, bool>& visited,
                      vector<vector<int>>& grid)
    {
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] == 1 && visited[pair<int, int>(i, j)] == false)
                {
                    mstack.push(pair<int,int>(i, j));
                    visited[pair<int, int>(i,j)] = true;
                    return true;
                }
        }
        return false;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        map<pair<int, int>, bool> visited;
        stack<pair<int, int>> mstack;
        int realMax = 0;
        int maxArea = 1;
        
        int ymax = grid.size() - 1;
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
            if(left.second >= 0 && grid[left.first][left.second] == 1
               && visited[left] == false)
            {
                maxArea++;
                mstack.push(left);
                visited[left] = true;
            }
            else if(right.second <= xmax && grid[right.first][right.second] == 1
                   && visited[right] == false)
            {
                maxArea++;
                mstack.push(right);
                visited[right] = true;
            }
            else if(top.first >= 0 && grid[top.first][top.second] == 1
                   && visited[top] == false)
            {
                maxArea++;
                mstack.push(top);
                visited[top] = true;
            }
            else if(down.first <= ymax && grid[down.first][down.second] == 1
                   && visited[down] == false)
            {
                maxArea++;
                mstack.push(down);
                visited[down] = true;
            }
            else
            {
                
                mstack.pop();
                //栈空的时候才重新计算，说明这时候已经没有点连通了
                if(mstack.empty())
                {
                    realMax = max(realMax, maxArea);
                    maxArea = 1;
                }
            }
        }
        return realMax;
    }
};
