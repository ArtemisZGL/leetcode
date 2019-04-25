/*
https://blog.csdn.net/patrick_star_cowboy/article/details/73729756
相遇问题，移动距离最小的方式是所有元素都移动到中位数
为什么是中位数呢？
首先我们的目标是要将所有值通过加一或者减一来将数组元素变成一个目标值，每个元素到目标值的操作数就是他们的差
先假设这个目标值比所有元素都要小，此时总操作数就是sum（ai - target）
然后将这个目标值加一，此时分两种情况，加一后还比所有元素小，加一后比某些元素小比某些大
加一后还比所有元素小：总操作数就是sum（ai - target - 1） = sum(ai - target) - N, 总操作数减少N
加一后比某些元素小比某些大：
    此时比目标值大的元素到这个目标值的操作数仍然是减小了1，
    但是比目标值小的元素则相当于要进行一次加1操作才能追上目标值，也就是比原来的操作数增加1，
    假设左边的数为L个，右边的数为R个，目标值加1减少的总操作数就是R-L
    所以目标值加1的操作使左右两边的数一样多的时候就是总操作数最少的时候了，这就是中位数

总操作数就是sum - n * median，这样算好像不太对，因为有负数的话要取绝对值
*/

/*
要怎么找中位数呢，一种方法是排序然后找
另一种方法就是要用到找第k大的数的方法中的快排的想法了
*/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int medianPos = nums.size() / 2;
        int median = findKMaxNum(medianPos, nums);
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            count += abs(nums[i] - median);
        }
        return count;
    }
    
    int findKMaxNum(int K, vector<int>& nums)
    {
        int l = 0, h = nums.size() - 1;
        while(l < h)
        {
            int k = partition(nums, l, h);
            //cout << k << endl;
            //找到第k个就退出
            if(k == K)
                break;
            //如果比第k个小，只要找右边
            if(k < K) {
                l = k + 1;
            } else {
                h = k - 1;
            }
        }
        return nums[K];
    }
    
    int partition(vector<int>& nums, int l, int h)
    {
        //选l这个位置的为pivot值
        int pivot = nums[l];
        int i = l + 1, j = h;
        while(true)
        {
            //注意要先判断有没有越界
            while(i <= h && nums[i] < pivot)
                i++;
            while(j >= l+1 && nums[j] > pivot)
                j--;
            
            //i和j相遇说明已经分完了
            if(j <= i)
                break;
            
            //交换
            swap(nums, i, j);
            //交换后要移动，否则如果出现相等的情况就会死循环
            i++;
            j--;
        }
        //最后要将pivot和相遇点进行交换
        swap(nums, l, j);
        return j;
    }
    
    void swap(vector<int>& nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
