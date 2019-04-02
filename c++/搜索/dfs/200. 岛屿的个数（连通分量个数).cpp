/*
����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά���񣬼��㵺���������һ������ˮ��Χ����������ͨ��ˮƽ�����ֱ���������ڵ�½�����Ӷ��ɵġ�����Լ���������ĸ��߾���ˮ��Χ��

ʾ�� 1:

����:
11110
11010
11000
00000

���: 1
*/ 
/*
�������ͨ�����������⣬�������ͨ�����������ƣ������������ 
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
        if(ymax < 0)    //С�������ǿ�
            return count;
        int xmax = grid[ymax].size() - 1;
        
        while(!mstack.empty() || findUnvisited(mstack, visited, grid))
        {
            pair<int, int> cur = mstack.top();
            //���������ĸ���
            pair<int, int> left(cur.first, cur.second - 1);
            pair<int, int> right(cur.first, cur.second + 1);
            pair<int, int> top(cur.first - 1, cur.second);
            pair<int, int> down(cur.first+1, cur.second);
            //�ȿ���û��Խ�磬�ڿ��Ƿ�Ϊ1�൱�ڿ��ǲ�����ͨ
            //�����û�з��ʹ�
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
                //ջ�յ�ʱ������¼��㣬˵����һ����ͨ������������
                if(mstack.empty())
                {
                    count++;
                }
            }
        }
        return count;
    }
};
