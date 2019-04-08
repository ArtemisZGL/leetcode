/*
������������ n �� k������ 1 ... n �����п��ܵ� k ��������ϡ�

ʾ��:

����: n = 4, k = 2
���:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/ 
/*
	һ��ʼ��Ϊ�ͺ����в�࣬���Ƿ�������ǲ�ͬ�ظ��ģ����Ի���һ�ַ���
	https://blog.csdn.net/lindaxym/article/details/80951872
	Ҳ��ʹ�û��ݵķ�������n������ѡ1����Ȼ��Ӻ��������ѡk-1����ѡ���˾ͻص���һ������һ������ѡ 
*/ 
class Solution {
public:
    /*
    map<int, bool> visited;
    
    void btsearch(vector<vector<int>>& ans, int n, int k, vector<int> pre)
    {
        if(pre.size() == k)
        {
            ans.push_back(pre);
            return;
        }
        
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                vector<int> temp = pre;
                temp.push_back(i);
                visited[i] = true;
                btsearch(ans, n, k, temp);
                visited[i] = false;
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        
        vector<int> pre;
        btsearch(ans, n , k, pre);
        return ans;
    }
    */
    
    void btsearch(vector<vector<int>>& ans, int begin, int n, int k, vector<int> pre)
    {
        //����ѡ��
        if(k==0)
        {
            ans.push_back(pre);
            return;
        }
        
        //��˳��ѡ������n-k������ѡ�Ѿ�ѡ����k����
        for(int i = begin; i <= n - k + 1; i++)
        {
            vector<int> temp = pre;
            temp.push_back(i);
            //�Ӻ������ѡk������һ������ѡk-1������i+1λ��ʼ
            btsearch(ans, i + 1, n, k - 1, temp);
        }
    }
    
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> ans;
        
        vector<int> pre;
        btsearch(ans, 1, n , k, pre);
        return ans;
    }
    
};
