/*
����һ������Ϊ n ���������飬����������ж������ı� 1 ��Ԫ�ص�����£��������ܷ���һ���ǵݼ����С�

��������������һ���ǵݼ����еģ� �������������е� i (1 <= i < n)������ array[i] <= array[i + 1]��

ʾ�� 1:

����: [4,2,3]
���: True
����: �����ͨ���ѵ�һ��4���1��ʹ������Ϊһ���ǵݼ����С�
ʾ�� 2:

����: [4,2,1]
���: False
����: �㲻����ֻ�ı�һ��Ԫ�ص�����½����Ϊ�ǵݼ����С�
˵��:  n �ķ�ΧΪ [1, 10,000]��
*/ 

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() <=2) //�����϶�����
            return true;
        
        int count = 0;
        
        //�����ж����һ������size()-1
        for(int i = 0;i < nums.size() - 1 && count < 2; i++)
        {
            if(nums[i] > nums[i+1]) //�ͺ���һ���Ƚ�,ǰһ����С���ߺ�һ�����
            {
                count++;
                if(i == 0)
                    nums[i] = nums[i+1];
                else if(nums[i - 1] < nums[i+1])
                    nums[i] = nums[i+1];
                else
                    nums[i+1] = nums[i];
            }
        }
        
        return count < 2;
    }
};
