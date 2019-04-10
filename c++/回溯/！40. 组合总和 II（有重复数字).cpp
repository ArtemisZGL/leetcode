/*
����һ������ candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�

candidates �е�ÿ��������ÿ�������ֻ��ʹ��һ�Ρ�

˵����

�������֣�����Ŀ������������������
�⼯���ܰ����ظ�����ϡ� 
ʾ�� 1:

����: candidates = [10,1,2,7,6,1,5], target = 8,
����⼯Ϊ:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
ʾ�� 2:

����: candidates = [2,5,2,1,2], target = 5,
����⼯Ϊ:
[
  [1,2,2],
  [5]
]
*/ 
/*
��������������������ظ����ֵģ�ÿ�����ֿ���ѡ��Σ����Ǹø���ֻ��ѡһ��
Ϊ�˱����ظ����������Ҫ����visit����������֤ 
*/ 
class Solution {
public:
    map<int, bool> visited;
    
    void btsearch(int target, vector<int>& candidates, vector<int> pre, vector<vector<int>>& ans, int start)
    {
        
        //����ѡ�������������Բ�������k
        for(int i = start; i < candidates.size(); i++)
        {
            //��visit����Ҫ����
            //���ǰһ�����͵�ǰ����һ���������������visit�Ϳ��Լ���ѡ����Ϊ����ѡ�ظ�������
            //�����ǰһ����ûvisit�Ļ����õ���������Ǻ�ǰһ����һ���ģ����Ծ�ֱ������
            if(i != 0 && candidates[i] == candidates[i-1] && visited[i - 1] == false)
                continue;
            vector<int> temp = pre;
            temp.push_back(candidates[i]);
            int sum = accumulate(temp.begin(), temp.end(), 0);
            if(sum == target)
                ans.push_back(temp);
            else if(sum < target)   //��Ϊ�����ǲ������ظ�ѡ�ģ���i+1��ʼ
            {
                visited[i] = true;
                btsearch(target, candidates, temp, ans, i + 1);
                visited[i] = false;
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> pre;
        btsearch(target, candidates, pre, ans, 0);
        return ans;
    }
};
