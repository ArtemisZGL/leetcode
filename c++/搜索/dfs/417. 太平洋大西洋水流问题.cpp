/*
给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。

规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。

请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。

 

提示：

输出坐标的顺序不重要
m 和 n 都小于150
 

示例：

 

给定下面的 5x5 矩阵:

  太平洋 ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * 大西洋

返回:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).
*/ 

/*
深度优先搜索，反向进行查找，可到达的记下来，最后两个都可以到达的就是结果 
*/ 

class Solution {
public:
    stack<pair<int, int> > mstack;
    map<pair<int, int>, bool> pacificVisited;
    map<pair<int, int>, bool> atlanticVisited;
    
    
    void findOneOcean(map<pair<int, int>, bool>& visited,vector<vector<int>>& matrix)
    {
        
        int rmax = matrix.size() - 1;
        if(rmax < 0)
            return;
        
        int cmax = matrix[rmax].size() - 1;
        
        while(!mstack.empty())  
        {
            pair<int,int> p = mstack.top();
            pair<int, int> left(p.first, p.second - 1);
            pair<int, int> right(p.first, p.second + 1);
            pair<int, int> top(p.first - 1, p.second);
            pair<int, int> down(p.first + 1, p.second);
            
            int curNum = matrix[p.first][p.second];
            
            if(left.second >= 0 && matrix[left.first][left.second] >= curNum && 
               visited[left] == false)
            {
                visited[left] = true;
                mstack.push(left);
            }
            else if(right.second <= cmax && matrix[right.first][right.second] >= curNum &&                          visited[right] == false)
            {
                visited[right] = true;
                mstack.push(right);
            }
            else if(top.first >= 0 && matrix[top.first][top.second] >= curNum && 
                    visited[top] == false)
            {
                visited[top] = true;
                mstack.push(top);
            }
            else if(down.first <= rmax && matrix[down.first][down.second] >= curNum &&                              visited[down] == false)
            {
                visited[down] = true;
                mstack.push(down);
            }
            else
            {
                mstack.pop();
            }
        }
    }
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> ans;
        int m = matrix.size() - 1;
        if(m < 0)
            return ans;
        
        int n = matrix[m].size() - 1;
        
        //每一行的第一列都能去到太平洋，每一行的最后一列都能去到大西洋
        //将每个点都进行一次深度遍历
        for(int i = 0; i <= m; i++)      
        {
            pacificVisited[pair<int,int>(i,0)] = true;
            mstack.push(pair<int,int>(i,0));
            findOneOcean(pacificVisited, matrix);
            
            mstack.push(pair<int, int>(i, n)); 
            atlanticVisited[pair<int,int>(i,n)] = true;
            findOneOcean(atlanticVisited, matrix);
        }
        
        
        //同理每一列的第一行和最后一行
        for(int i = 0; i <= n; i++)
        {
            pacificVisited[pair<int,int>(0,i)] = true;
            mstack.push(pair<int,int>(0,i));
            findOneOcean(pacificVisited, matrix);
            
            mstack.push(pair<int, int>(m,i)); 
            atlanticVisited[pair<int,int>(m,i)] = true;
            findOneOcean(atlanticVisited, matrix);
        }
        
        
        
        
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {   
                //cout << i << " " << j << " " << pacificVisited[pair<int,int>(i,j)] << " "
                 //   << atlanticVisited[pair<int,int>(i,j)] << endl;
                if(pacificVisited[pair<int,int>(i,j)] && atlanticVisited[pair<int,int>(i,j)])
                    ans.push_back(pair<int,int>(i,j));
            }
        }
        return ans;
    }
};
