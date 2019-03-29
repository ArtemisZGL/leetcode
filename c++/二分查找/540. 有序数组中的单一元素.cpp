/*
����һ��ֻ�����������������飬ÿ��Ԫ�ض���������Σ�Ψ��һ����ֻ�����һ�Σ��ҳ��������

ʾ�� 1:

����: [1,1,2,3,3,4,4,8,8]
���: 2
ʾ�� 2:

����: [3,3,7,7,10,11,11]
���: 10
*/ 

class Solution {
public:
    /*
    ��һ�ַ���λ���㣬������������������
    */
    /*
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            result ^=  nums[i];
        }
        return result;
    }
    */
    
    /*
    ���������ģ������ö��ֲ���
    �� index Ϊ Single Element �������е�λ�á���� m Ϊż�������� m + 1 < index����ô nums[m] == nums[m + 1]��m + 1 >= index����ô nums[m] != nums[m + 1]��

������Ĺ��ɿ���֪������� nums[m] == nums[m + 1]����ô index ���ڵ�����λ��Ϊ [m + 2, h]����ʱ�� l = m + 2����� nums[m] != nums[m + 1]����ô index ���ڵ�����λ��Ϊ [l, m]����ʱ�� h = m��

��Ϊ h �ĸ�ֵ���ʽΪ h = m����ôѭ������Ҳ��ֻ��ʹ�� l < h ������ʽ��
    */
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while(start < end)
        {
            int med = start + (end - start) / 2;
            if(med % 2 == 1)
            {
                med--;
            }
            if(nums[med] == nums[med+1])
                start += 2;
            else
                end = med;
            
        }
        return nums[start];
    }
};
