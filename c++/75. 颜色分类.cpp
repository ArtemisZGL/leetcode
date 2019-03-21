/*
һ��ʼ�뵽�ķ���������ɨ�裬��ɨ��һ�μ�¼0��1��2�ĸ�����Ȼ��ڶ���ɨ����ݵ�һ�εĸ�������λ����

һ��ɨ��ķ���������������¼��0��1��2��λ�ã�ͨ��ɨ�裬�����0�ͺ�0��λ�ý��н�����0λ��ǰ����1λ��ǰ���������2�ͺ�2λ�ý���
2λ�ü�����ʱ���ܽ�1λ��ǰ������Ϊ�㲻֪������������ʲô������Ǻ�0����ô�������Ŀ϶���1����Ҫע��ѭ���ж������е� = 

*/ 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = nums.size() - 1;
        while(one <= two)
        {
            if(nums[one] == 0)
            {
                swap(nums, zero, one);
                one++;
                zero++;
            }
            else if(nums[one] == 2)
            {
                swap(nums, two, one);
                two--;
            }
            else
                one++;
        }
    }
    
    void swap(vector<int>& nums, int fir, int sec)
    {
        int temp = nums[fir];
        nums[fir] = nums[sec];
        nums[sec] = temp;
    }
};
