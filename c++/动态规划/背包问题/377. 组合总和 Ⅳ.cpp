/*
由于是组合个数，所以与顺序有关，所以可以看成是顺序相关的背包问题
目标正整数为容量，然后各个数字为物品

定义状态d(i)表示容量为i时的组合个数
状态转移方程：d(i) = d(i) + d(i-w)
第j+1个物品在容量为i时由前j个物品的组合个数加上前j个物品在i-w容量的个数
初始状态d(0) = 1 还是 0？
*/

/*
给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

示例:

nums = [1, 2, 3]
target = 4

所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

请注意，顺序不同的序列被视作不同的组合。

因此输出为 7。
*/ 

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0)
            return 1;
        
        if(nums.size() == 0)
            return 0;
        
        long long D[target+1];
        for(int i = 0; i < target + 1; i++)
            D[i] = 0;
        D[0] = 1;
        
        for(int i = 1; i <= target; i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(i >= nums[j])
                    D[i] += D[i - nums[j]] %INT_MAX;
            }
        }
        return D[target];
    }
};
