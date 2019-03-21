/*
一开始想到的方法是两遍扫描，先扫描一次记录0，1，2的个数，然后第二次扫描根据第一次的个数来按位置排

一遍扫描的方法是用三个量记录放0，1，2的位置，通过扫描，如果是0就和0的位置进行交换，0位置前进，1位置前进，如果是2就和2位置交换
2位置减，此时不能将1位置前进，因为你不知道换过来的是什么（如果是和0换那么换过来的肯定是1），要注意循环判断条件中的 = 

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
