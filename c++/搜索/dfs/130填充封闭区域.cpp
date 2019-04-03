/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
*/

/*
深度优先搜索O，如果在边界就是不被包围的，当一个子图被搜索完且边界index为false则说明有一个元素在边界，不用转换
然后注意当栈为空的时候才是说明一个连通子图搜索完毕，这时候就要将条件重置 
*/

class Solution {
public:
    stack<pair<int,int>> mstack;
    map<pair<int, int> ,bool> visited;
    
    bool getO(vector<vector<char>>& board, vector<pair<int,int>>& temp)
    {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] == 'O' && visited[pair<int, int>(i,j)] == false)
                {
                    visited[pair<int, int>(i,j)] = true;
                    mstack.push(pair<int,int>(i,j));
                    temp.push_back(pair<int,int>(i,j));
                    return true;
                }
            }
        }
        return false;
    }
    
    void solve(vector<vector<char>>& board) {
        bool index = true;
        int rmax = board.size() - 1;
        if(rmax < 0)
            return;
        
        int cmax = board[rmax].size() - 1;
        vector<pair<int,int>> temp;
        while(!mstack.empty() || getO(board,temp))
        {
            pair<int,int> p = mstack.top();
            if(p.first == 0 || p.first == rmax || p.second == 0 || p.second == cmax)
                index = false;
            //cout << p.first << " " << p.second<< endl;
            pair<int, int> left(p.first, p.second - 1);
            pair<int, int> right(p.first, p.second + 1);
            pair<int, int> top(p.first - 1, p.second);
            pair<int, int> down(p.first + 1, p.second);
            
            if(left.second >= 0 && board[left.first][left.second] == 'O' && visited[left] == false)
            {
                if(left.second == 0)    //到了边界
                    index = false;
                visited[left] = true;
                mstack.push(left);
                temp.push_back(left);
            }
            else if(right.second <= cmax && board[right.first][right.second] == 'O' && visited[right] == false)
            {
                if(right.second == cmax)    //到了边界
                    index = false;
                visited[right] = true;
                mstack.push(right);
                temp.push_back(right);
            }
            else if(top.first >= 0 && board[top.first][top.second] == 'O' && visited[top] == false)
            {
                if(top.first == 0)    //到了边界
                    index = false;
                visited[top] = true;
                mstack.push(top);
                temp.push_back(top);
            }
            else if(down.first <= rmax && board[down.first][down.second] == 'O' && visited[down] == false)
            {
                if(down.second == rmax)    //到了边界
                    index = false;
                visited[down] = true;
                mstack.push(down);
                temp.push_back(down);
            }
            else
            {
                mstack.pop();
                
                //cout << index << endl;
                if(index && mstack.empty()) //连通子图复合被包围的条件
                {
                    for(int i = 0; i < temp.size(); i++)
                    {
                        board[temp[i].first][temp[i].second] = 'X';
                    }
                    //cout << "a";
                    
                }
                
                if(mstack.empty())  //搜索完一个连通子图就重置
                {
                    index = true;
                    temp.clear();
                }
            }
        }
    }
};
