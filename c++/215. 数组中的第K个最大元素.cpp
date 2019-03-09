/*
�ÿ��ŵķ������������ߣ�����ҵ�һ����pivot��ģ��ұ��ҵ�һ����pivotС�ģ�Ȼ�󽻻��� 
�ҵ�k�����������ȫ������ÿ������֮��pivot��λ�ã�pivot��λ�þ���������λ�ã������k˵�������ǵ�k�������С��k��kҪ��ת����Ϊ
�����С�������򣩾��ź���Ĳ��֣��������k����ǰ��Ĳ��֣�ע�����ֻ���������������Ѿ�ȫ�����򣬵��ǲ���k����ʱֱ�ӷ���nums[k] 

*/ 

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() <= 1)
            return nums[0];
        k = nums.size() - k;
        int l = 0, h = nums.size() - 1;
        while(l < h)
        {
            int pos = partition(nums, l, h);
            cout << pos;
            if(pos == k)
                break;
            else if(pos < k)
                l = pos + 1;
            else
                h = pos - 1;
        }
        return nums[k];
    }
    
    int partition(vector<int>& nums, int l, int h)
    {
        int pivot = nums[l];
        int i = l, j = h + 1;
        while(true)
        {
            while(nums[--j] > pivot && j > l);
            while(nums[++i] < pivot && i < h);
            if(i >= j)
                break;
            swap(nums, i, j);
        }
        swap(nums, j, l);
        return j;
    }
    
    void swap(vector<int>& nums, int pos1, int pos2)
    {
        if(pos1 >=0 && pos1 < nums.size() && pos2 >= 0 && pos2 < nums.size())
        {
            int temp = nums[pos1];
            nums[pos1] = nums[pos2];
            nums[pos2] = temp;
        }
    }
};
