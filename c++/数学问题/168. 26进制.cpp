/*
给定一个正整数，返回它在 Excel 表中相对应的列名称。

例如，

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
示例 1:

输入: 1
输出: "A"
示例 2:

输入: 28
输出: "AB"
示例 3:

输入: 701
输出: "ZY"
*/ 

/*
相当于26进制的转换
*/
class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        
        
        while(n > 0)
        {
            //注意这里由于n是从1开始的，所以要先减1，不然求余那里不好弄
            n = n - 1;
            
            //位运算大概只有2的幂次能用
            ans += (n % 26) + 'A';
            
            n = n / 26;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
