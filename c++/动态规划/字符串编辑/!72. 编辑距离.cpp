/*
和找最长公共子序列的思想有点类似

定义状态d[i][j] 表示两个序列前i，j长度的子序列转化所要用的操作数

状态转移方程：
    如果两个子序列最后一位相等，那么转换所需的操作数就等于两个子序列都减少一个长度的操作数
    d[i][j] = d[i-1][j-1]
    
    否则如果最后一位不等，有三种情况，对应修改，删除，插入
    1. word1[0..i-1] 到 word2[0..j-1] 的变换需要消耗 k 步
       word1[0..i] 到 word2[0..j] 的变换就先把word1[0..i-1] 变换到 word2[0..j-1]，然后
       把最后一位修改成 word1[i] 改成 word2[j]，总共消耗的步数为k+1
    2. 如果 word1[0..i-1] 到 word2[0..j] 的变换需要消耗 k 步
        word1[0..i] 到 word2[0..j] 的变换就先把word1[0..i-1] 变换到 word2[0..j]，然后
       把最后一位word1[i]删掉，总共消耗的步数为k+1
    3. 如果 word1[0..i] 到 word2[0..j-1] 的变换需要消耗 k 步
        word1[0..i] 到 word2[0..j] 的变换就先把word1[0..i] 变换到 word2[0..j-1]，然后
       把最后一位word2[i]插入，总共消耗的步数为k+1
    取这三种情况的最小值就行
*/

/*
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
示例 1:

输入: word1 = "horse", word2 = "ros"
输出: 3
解释: 
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2:

输入: word1 = "intention", word2 = "execution"
输出: 5
解释: 
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
*/


class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        
        int maxLen = max(len1, len2);
        
        if(len1 == 0 || len2 == 0)
            return maxLen;
        
        //状态表示两个字串前i，j长度时
        int D[len1 + 1][len2 + 1];
        
        //初始化状态，初始化0和其它长度的操作数
        //word2=0，word1全部删掉
        //word1=0,word1全部插入word2
        for(int i = 0; i <= len1; i++)
            D[i][0] = i;
        for(int i = 0; i <= len2; i++)
            D[0][i] = i;
        
        //从1开始，0定义为一个初始状态.可以用递归也可以用递推
        for(int i = 1; i <= len1; i++)
            for(int j = 1; j <=len2; j++)
            {
                if(word1[i-1] == word2[j-1])
                    D[i][j] = D[i-1][j-1];
                else
                    D[i][j] = min(min(D[i-1][j-1],D[i-1][j]), D[i][j-1])+1;
            }
        
        return D[len1][len2];
    }
};
