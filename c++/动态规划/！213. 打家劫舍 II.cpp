/*
�ָ�����䣬��֮ǰ��������Ǳ���˻������Կ���0�������ڶ�������Ϊ͵�˵�0���Ͳ���͵���һ������Ȼ��
����1�����һ����͵�����һ���Ͳ���͵��0����

Ȼ��״̬�����״̬ת�Ʒ��̺�֮ǰ��һ����

�������ﲻ�����õݹ�ķ���ȥ�������Ϊ�����Ļ���Ҫ�ֿ���D�ˣ��ڲ�ͬ������D�ǲ�һ����
*/
class Solution {
public:
    vector<int> nums;
    int rob(vector<int>& nums) {
        if(nums.size() <= 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        this->nums = nums;
        
        return max(getMaxNum(0, nums.size() - 2), 
                   getMaxNum(1, nums.size() - 1));
    }
    
    int getMaxNum(int low, int height)
    {
        //�ɴ������±���˴�������
        int fir = 0, second = 0;
        for(int i = low; i <= height; i++)
        {
            int current = max(fir + nums[i], second);
            fir = second;
            second = current;
        }
        return second;
    }
};
