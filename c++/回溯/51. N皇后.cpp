/*
n �ʺ������о�������ν� n ���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������



��ͼΪ 8 �ʺ������һ�ֽⷨ��

����һ������ n���������в�ͬ�� n �ʺ�����Ľ��������

ÿһ�ֽⷨ����һ����ȷ�� n �ʺ���������ӷ��÷������÷����� 'Q' �� '.' �ֱ�����˻ʺ�Ϳ�λ��

����: 4
���: [
 [".Q..",  // �ⷨ 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // �ⷨ 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/ 

/*
���͵Ļ������⣬һ��һ�еķŻʺ󣬶�ÿһ�У�����ÿһ�У�Ȼ��ͨ��map������һ�е�ǰ�Ƿ��ͻ������ͻ�ͼ����ţ�
���ÿһ�ж����ܷž�Ҫ����

Ҫע�����ʱ��pop_back�Լ�visitd�����޸Ļ����������visited�������ĸ������������Խ��Ƿ��Ѿ����ˣ�ע��Խǵ��±���� 
*/ 


class Solution {
public:
    map<int, bool> rowUsed;
    map<int, bool> colUsed;
    //r+c
    map<int, bool> d45Used;
    //n-1-(r - c)
    map<int, bool> d135Used;
    
    void btsearch(vector<vector<string>>& ans, int n, int curRow, vector<string> curPlan)
    {
        if(curRow == n)
        {
            ans.push_back(curPlan);
            return;
        }
        
        for(int col = 0; col < n; col++)
        {
            //����ͻ����
            if(!rowUsed[curRow] && !colUsed[col] && !d45Used[curRow + col] && !d135Used[n-1-curRow+col])
            {
                rowUsed[curRow] = true;
                colUsed[col] = true;
                d45Used[curRow + col] = true;
                d135Used[n-1-curRow+col] = true;
                
                //�Żʺ�
                string rows = "";
                for(int j = 0; j < n; j++)
                    rows += ".";
                rows[col] = 'Q';
                
                curPlan.push_back(rows);
                
                //������һ��
                btsearch(ans, n, curRow + 1, curPlan);
                
                //����
                curPlan.pop_back();
                rowUsed[curRow] = false;
                colUsed[col] = false;
                d45Used[curRow + col] = false;
                d135Used[n-1-curRow+col] = false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
        
        vector<string> temp;
        btsearch(ans, n, 0, temp);
        
        return ans;
    }
};
