/*
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去
*/

class Solution {
public:
    //开方取整，就是取小于等于key的第一个数，key是平方根
    //小于key begin = med + 1
    //大于key end = med - 1
    //那等于呢，不妨想象有很多key，这时候我们就要取最右边的，如果key不存在，也是取小于key中最右边的
    //所以当<=key，begin都要等于med+1，这样Begin就指向刚好比key大的，end就指向我们要的答案
    int mySqrt(int x) {
        int begin = 1, end = x;
        while(begin <= end)
        {
            int med = begin + (end - begin) / 2;
            
            if(med > x / med)       //这里不能直接算med*med，否则会溢出
                end = med - 1;
            else 
                begin = med + 1;   
        }
        return end;
    }
};
