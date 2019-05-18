/*
动态规划：
状态定义：设定有两个状态up(i)和down(i), 位于i处，处于上升所能获得的最大摆动子序列长度 
状态转移：（有点像两个最长上升子序列）
1. 当nums[i] > nums[j] && i > j,up[i] = down[j] + 1 
2. 当nums[i] < nums[j] && i > j,down[i] = up[j] + 1
初始化：0处的up和down都是1
复杂度：空间和时间都是O(n^2)

线性动态规划：
状态定义：设定有两个状态up(i)和down(i), 位于i处，处于上升所能获得的最大摆动子序列长度
状态转移：只和前面的数字进行比较，不用两重循环,这时就要同时更新up和down了
(可以想象成是同时有两个序列down和up分开进行的
后一个数比前一个数大，那么此时up序列就增加， down序列还是不变
后一个数比前一个数小，那么此时down序列就增加，up序列还是不变)
1. 当nums[i] > nums[i-1],up[i] = down[i-1] + 1 , down[i] = down[i-1]
2. 当nums[i] < nums[i-1],down[i] = up[i-1] + 1,  up[i] = up[i-1]
初始化：0处的up和down都是1
复杂度：空间都是O(n^2)， 时间O(n)

对空间再次进行优化：
根据上面的线性动态规划，由于我们只要求这个序列的最长摆动序列，所以并不需要在每个点都保存状态（状态转移时只用到了前一个点的状态），所以只要存一个up和down就行了

贪心的方法：
先纪录第0个和第一个数之间的差，然后开始往后计算，只有找到差符号变化时才将摆动序列长度增加
*/

/*
如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。

例如， [1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3) 是正负交替出现的。相反, [1,4,7,2,5] 和 [1,7,4,5,5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。

给定一个整数序列，返回作为摆动序列的最长子序列的长度。 通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。

示例 1:

输入: [1,7,4,9,2,5]
输出: 6 
解释: 整个序列均为摆动序列。
示例 2:

输入: [1,17,5,10,13,15,10,5,16,8]
输出: 7
解释: 这个序列包含几个长度为 7 摆动序列，其中一个可为[1,17,10,13,10,16,8]。
*/ 

/*
//动态规划
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int up = 1;
        int down = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i-1])
                up = down + 1;
            else if(nums[i] < nums [i-1])
                down = up + 1;
        }
        return max(up, down);
    }
};
*/
//贪心
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        
        int preDiff = nums[1]  - nums[0];
        //如果差为0此时的摆动序列长度只有1 ，否则初始为2
        int count = preDiff == 0 ? 1 : 2;
        
        for(int i = 2; i < nums.size(); i++)
        {
            int diff = nums[i] - nums[i-1];
            //注意等于0的情况，diff=0是不用增加序列的
            if(preDiff <= 0 && diff > 0 || preDiff >= 0 && diff < 0)
            {
                count++;
                //prediff要在里面更新
                preDiff = diff;
            }
        }
        return count;
    }
};
