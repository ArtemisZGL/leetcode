/*
给定一个整数，写一个函数来判断它是否是 3 的幂次方。

示例 1:

输入: 27
输出: true
示例 2:

输入: 0
输出: false
示例 3:

输入: 9
输出: true
示例 4:

输入: 45
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？
*/ 

class Solution {
public:
    bool isPowerOfThree(int n) {
        //先找到该类型的最大整数
        int maxInt = numeric_limits<int>::max();
        //log3（maxInt），并且取证，就得到了最大的3的幂数
        int maxThree = log(maxInt) / log(3);
        //然后再^3就是最大的3的幂
        maxThree = pow(3, maxThree);
        //如果是3的幂次方必定可以被这个最大的幂次整除，因为因子都只有3和1
        return n > 0 && maxThree % n == 0;
    }
};
