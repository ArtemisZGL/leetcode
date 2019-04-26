/*
平方序列：1,4,9,16,..

间隔：3,5,7,...

间隔为等差数列，使用这个特性可以得到从 1 开始的平方序列。
*/

/*
给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

说明：不要使用任何内置的库函数，如  sqrt。

示例 1：

输入：16
输出：True
示例 2：

输入：14
输出：False
*/ 

class Solution {
public:
    bool isPerfectSquare(int num) {
        long sqrt = 1, diff = 3;
        while(true)
        {
            if(sqrt > num)
                return false;
            if(sqrt == num)
                return true;
            
            sqrt += diff;
            diff += 2;
        }
    }
};
