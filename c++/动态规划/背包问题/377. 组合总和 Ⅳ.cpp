/*
��������ϸ�����������˳���йأ����Կ��Կ�����˳����صı�������
Ŀ��������Ϊ������Ȼ���������Ϊ��Ʒ

����״̬d(i)��ʾ����Ϊiʱ����ϸ���
״̬ת�Ʒ��̣�d(i) = d(i) + d(i-w)
��j+1����Ʒ������Ϊiʱ��ǰj����Ʒ����ϸ�������ǰj����Ʒ��i-w�����ĸ���
��ʼ״̬d(0) = 1 ���� 0��
*/

/*
����һ��������������Ҳ������ظ����ֵ����飬�ҳ���Ϊ����Ŀ������������ϵĸ�����

ʾ��:

nums = [1, 2, 3]
target = 4

���п��ܵ����Ϊ��
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

��ע�⣬˳��ͬ�����б�������ͬ����ϡ�

������Ϊ 7��
*/ 

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0)
            return 1;
        
        if(nums.size() == 0)
            return 0;
        
        long long D[target+1];
        for(int i = 0; i < target + 1; i++)
            D[i] = 0;
        D[0] = 1;
        
        for(int i = 1; i <= target; i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(i >= nums[j])
                    D[i] += D[i - nums[j]] %INT_MAX;
            }
        }
        return D[target];
    }
};
