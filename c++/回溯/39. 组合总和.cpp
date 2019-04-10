/*
����һ�����ظ�Ԫ�ص����� candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�

candidates �е����ֿ����������ظ���ѡȡ��

˵����

�������֣����� target��������������
�⼯���ܰ����ظ�����ϡ� 
ʾ�� 1:

����: candidates = [2,3,6,7], target = 7,
����⼯Ϊ:
[
  [7],
  [2,2,3]
]
ʾ�� 2:

����: candidates = [2,3,5], target = 8,
����⼯Ϊ:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/ 

/*
���ݵ�˼�룬ѡ���ܼ���ѡ�ͼ���ѡ�����ܾ��˻�ȥ��һ���ݹ�
 ���ﻹҪע�����ͨ����ϵĲ�ͬ����Ϊ�ǿ������ѡ�������������ҿ����ظ�ѡһ����
 ����ͬ������ϻ��ǲ�������ֵ� 
*/ 
class Solution {
public:
    void btsearch(int target, vector<int>& candidates, vector<int> pre, vector<vector<int>>& ans, int start)
    {
        
        //����ѡ�������������Բ�������k
        for(int i = start; i < candidates.size(); i++)
        {
            vector<int> temp = pre;
            temp.push_back(candidates[i]);
            int sum = accumulate(temp.begin(), temp.end(), 0);
            if(sum == target)
                ans.push_back(temp);
            else if(sum < target)   //��Ϊ�����ǿ����ظ�ѡ�ģ�����ֱ����һ�ο��Դ�i��ʼ����ͨ���ֻ�ܴ�i+1��ʼ
                btsearch(target, candidates, temp, ans, i);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> pre;
        btsearch(target, candidates, pre, ans, 0);
        return ans;
    }
};
