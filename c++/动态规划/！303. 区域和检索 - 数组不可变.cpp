/*
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

示例：

给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
说明:

你可以假设数组不可变。
会多次调用 sumRange 方法。
*/ 
/*
注意这里是两个闭区间，状态定义有点技巧，多次调用的情况下比较快 
动态规划？用状态D(i)记录从第0个到第i-1个的和，然后求区间的时候只要D(i+!) - D（j)
状态转移方程就为D(i) = d(i-1) + nums[i-1]，避免重复计算
第一个的初始值d(0) = 0
*/
class NumArray {
public:
    vector<int> D;
    NumArray(vector<int>& nums) {
        D = vector<int>(nums.size() + 1);
        D[0] = 0;
        for(int i = 1; i <= nums.size(); i++)
            D[i] = D[i-1] + nums[i-1];
        
    }
    
    int sumRange(int i, int j) {
        if(i > D.size() || j > D.size() || i < 0 || j < 0)
            return 0;
        return D[j+1] - D[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
