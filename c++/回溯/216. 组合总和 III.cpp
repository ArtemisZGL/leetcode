/*
�ҳ��������֮��Ϊ n �� k ��������ϡ������ֻ������ 1 - 9 ��������������ÿ������в������ظ������֡�

˵����

�������ֶ�����������
�⼯���ܰ����ظ�����ϡ� 
ʾ�� 1:

����: k = 3, n = 7
���: [[1,2,4]]
ʾ�� 2:

����: k = 3, n = 9
���: [[1,2,6], [1,3,5], [2,3,4]]
*/ 

class Solution {
public:
    
    void  btsearch(vector<vector<int>>& ans, int begin, int n, int k, vector<int> pre)
    {
        if(k == 0)
        {
            if(accumulate(pre.begin(), pre.end(), 0) == n)
                ans.push_back(pre);
            return;
        }
        
        for(int i = begin; i <= 9; i++)
        {
            int sum = accumulate(pre.begin(), pre.end(), 0);
            if(sum + i <= n)
            {
                vector<int> temp = pre;
                temp.push_back(i);
                btsearch(ans, i + 1, n, k - 1, temp);
            }
        }
    }
        
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> pre;
        btsearch(ans, 1, n, k, pre);
        return ans;
    }
};
