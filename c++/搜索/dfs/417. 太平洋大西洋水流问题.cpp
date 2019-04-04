/*
����һ�� m x n �ķǸ�������������ʾһƬ��½�ϸ�����Ԫ��ĸ߶ȡ���̫ƽ�󡱴��ڴ�½����߽���ϱ߽磬���������󡱴��ڴ�½���ұ߽���±߽硣

�涨ˮ��ֻ�ܰ����ϡ��¡������ĸ�������������ֻ�ܴӸߵ��ͻ�����ͬ�ȸ߶���������

���ҳ���Щˮ���ȿ�����������̫ƽ�󡱣������������������󡱵�½�ص�Ԫ�����ꡣ

 

��ʾ��

��������˳����Ҫ
m �� n ��С��150
 

ʾ����

 

��������� 5x5 ����:

  ̫ƽ�� ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * ������

����:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (��ͼ�д����ŵĵ�Ԫ).
*/ 

/*
�������������������в��ң��ɵ���ļ�������������������Ե���ľ��ǽ�� 
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
        
        //ÿһ�еĵ�һ�ж���ȥ��̫ƽ��ÿһ�е����һ�ж���ȥ��������
        //��ÿ���㶼����һ����ȱ���
        for(int i = 0; i <= m; i++)      
        {
            pacificVisited[pair<int,int>(i,0)] = true;
            mstack.push(pair<int,int>(i,0));
            findOneOcean(pacificVisited, matrix);
            
            mstack.push(pair<int, int>(i, n)); 
            atlanticVisited[pair<int,int>(i,n)] = true;
            findOneOcean(atlanticVisited, matrix);
        }
        
        
        //ͬ��ÿһ�еĵ�һ�к����һ��
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
