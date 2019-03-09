/*
用快排的方法（左右两边，左边找到一个比pivot大的，右边找到一个比pivot小的，然后交换） 
找第k大的数，不用全部排序，每轮排序之后看pivot的位置，pivot的位置就是排序后的位置，如果是k说明他就是第k大的数，小于k（k要反转，因为
数组从小到大排序）就排后面的部分，如果大于k就排前面的部分，注意如果只有两个数，可能已经全部排序，但是不是k，此时直接返回nums[k] 

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
