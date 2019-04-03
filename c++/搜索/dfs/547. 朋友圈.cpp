/*
������ N ��ѧ����������Щ�������ѣ���Щ���ǡ����ǵ���������Ǵ����ԡ������֪ A �� B �����ѣ�B �� C �����ѣ���ô���ǿ�����Ϊ A Ҳ�� C �����ѡ���ν������Ȧ����ָ�������ѵļ��ϡ�

����һ�� N * N �ľ��� M����ʾ�༶��ѧ��֮������ѹ�ϵ�����M[i][j] = 1����ʾ��֪�� i ���� j ��ѧ����Ϊ���ѹ�ϵ������Ϊ��֪����������������ѧ���е���֪������Ȧ������

ʾ�� 1:

����: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
���: 2 
˵������֪ѧ��0��ѧ��1��Ϊ���ѣ�������һ������Ȧ��
��2��ѧ���Լ���һ������Ȧ�����Է���2��
ʾ�� 2:

����: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
���: 1
˵������֪ѧ��0��ѧ��1��Ϊ���ѣ�ѧ��1��ѧ��2��Ϊ���ѣ�����ѧ��0��ѧ��2Ҳ�����ѣ���������������һ������Ȧ������1��
*/ 

/*
����������� 
*/ 

class Solution {
public:
    stack<int> mstack;
    map<int, bool> visited;
    
    bool getFirstNotVisited(vector<vector<int>>& M)
    {
        for(int i = 0; i < M.size(); i++)
        {
            for(int j = 0; j < M[i].size(); j++)
            {
                if(M[i][j] == 1 && visited[j] == false)
                {
                    mstack.push(j);
                    visited[j] = true;
                    return true;
                }
            }
        }
        return false;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;
        while(!mstack.empty() || getFirstNotVisited(M))
        {
            int top = mstack.top();
            bool index = false;
            for(int i = 0; i < M[top].size(); i++)
            {
                if(M[top][i] == 1 && visited[i] == false)
                {
                    mstack.push(i);
                    index = true;
                    visited[i] = true;
                }
            }
            
            if(!index)
                mstack.pop();
            
            if(mstack.empty())
                count++;
        }
        return count;
    }
};
