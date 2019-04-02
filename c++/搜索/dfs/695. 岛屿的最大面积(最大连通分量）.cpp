/*
����һ��������һЩ 0 �� 1�ķǿն�ά���� grid , һ�� ���� �����ĸ����� (ˮƽ��ֱ) �� 1 (��������) ���ɵ���ϡ�����Լ����ά������ĸ���Ե����ˮ��Χ�š�

�ҵ������Ķ�ά���������ĵ��������(���û�е��죬�򷵻����Ϊ0��)

ʾ�� 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
�������������������Ӧ���� 6��ע��𰸲�Ӧ����11����Ϊ����ֻ�ܰ���ˮƽ��ֱ���ĸ�����ġ�1����

ʾ�� 2:

[[0,0,0,0,0,0,0,0]]
����������������ľ���, ���� 0��
*/ 
/*
����ȫ��ͨͼ�ļ��������ͨ�������⣬
��������������������������������Ҫ������ǿɵ��������⣬�������ĵ㶼�ǳ�ʼ�ڵ��ܵ��� 
�����ؼ���һ����ջ��һ����visited
����ȫ��ͨ��Ҫ�����ж����ͼ����� 
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
            //���������ĸ���
            pair<int, int> left(cur.first, cur.second - 1);
            pair<int, int> right(cur.first, cur.second + 1);
            pair<int, int> top(cur.first - 1, cur.second);
            pair<int, int> down(cur.first+1, cur.second);
            //�ȿ���û��Խ�磬�ڿ��Ƿ�Ϊ1�൱�ڿ��ǲ�����ͨ
            //�����û�з��ʹ�
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
                //ջ�յ�ʱ������¼��㣬˵����ʱ���Ѿ�û�е���ͨ��
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
