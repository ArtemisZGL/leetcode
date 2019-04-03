/*
����һ����ά�ľ��󣬰��� 'X' �� 'O'����ĸ O����

�ҵ����б� 'X' Χ�Ƶ����򣬲�����Щ���������е� 'O' �� 'X' ��䡣

ʾ��:

X X X X
X O O X
X X O X
X O X X
������ĺ����󣬾����Ϊ��

X X X X
X X X X
X X X X
X O X X
*/

/*
�����������O������ڱ߽���ǲ�����Χ�ģ���һ����ͼ���������ұ߽�indexΪfalse��˵����һ��Ԫ���ڱ߽磬����ת��
Ȼ��ע�⵱ջΪ�յ�ʱ�����˵��һ����ͨ��ͼ������ϣ���ʱ���Ҫ���������� 
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
                if(left.second == 0)    //���˱߽�
                    index = false;
                visited[left] = true;
                mstack.push(left);
                temp.push_back(left);
            }
            else if(right.second <= cmax && board[right.first][right.second] == 'O' && visited[right] == false)
            {
                if(right.second == cmax)    //���˱߽�
                    index = false;
                visited[right] = true;
                mstack.push(right);
                temp.push_back(right);
            }
            else if(top.first >= 0 && board[top.first][top.second] == 'O' && visited[top] == false)
            {
                if(top.first == 0)    //���˱߽�
                    index = false;
                visited[top] = true;
                mstack.push(top);
                temp.push_back(top);
            }
            else if(down.first <= rmax && board[down.first][down.second] == 'O' && visited[down] == false)
            {
                if(down.second == rmax)    //���˱߽�
                    index = false;
                visited[down] = true;
                mstack.push(down);
                temp.push_back(down);
            }
            else
            {
                mstack.pop();
                
                //cout << index << endl;
                if(index && mstack.empty()) //��ͨ��ͼ���ϱ���Χ������
                {
                    for(int i = 0; i < temp.size(); i++)
                    {
                        board[temp[i].first][temp[i].second] = 'X';
                    }
                    //cout << "a";
                    
                }
                
                if(mstack.empty())  //������һ����ͨ��ͼ������
                {
                    index = true;
                    temp.clear();
                }
            }
        }
    }
};
