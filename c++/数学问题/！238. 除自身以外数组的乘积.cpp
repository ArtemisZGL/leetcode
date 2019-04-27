/*
��������Ϊ n ���������� nums������ n > 1������������� output ������ output[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻���

ʾ��:

����: [1,2,3,4]
���: [24,12,8,6]
˵��: �벻Ҫʹ�ó��������� O(n) ʱ�临�Ӷ�����ɴ��⡣

���ף�
������ڳ����ռ临�Ӷ�����������Ŀ�𣿣� ���ڶԿռ临�Ӷȷ�����Ŀ�ģ�������鲻����Ϊ����ռ䡣��
*/ 

/*
��������ó�������ֱ��ȫ����������Ȼ���Ӧÿ�������г�������

ʱ�临�Ӷ�Ҫ��O��n�����ռ临�Ӷ�Ҫ����
�ȳ�ʼ�����ȫΪ1��
�������ұ�����ÿ�γ������ȫ�����ĳ˻�left��left�ٳ��Ե�ǰ�������и���
�������������ÿ�γ����ұ�ȫ�����ĳ˻�right��right�ٳ��Ե�ǰ�������и��� 
*/ 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> result(nums.size(), 1);
        if(nums.size() == 0)
            return result;
        
        int left = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            result[i] *= left;
            left = left * nums[i];
        }
        
        int right = nums[nums.size()-1];
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            result[i] *= right;
            right *= nums[i];
        }
        
        return result;
    }
};
