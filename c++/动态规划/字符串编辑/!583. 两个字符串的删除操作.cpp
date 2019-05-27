/*
找最长公共子序列，然后用两者总长度减去两倍的公共子序列长度就是要删除的步数
*/

/*
给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

示例 1:

输入: "sea", "eat"
输出: 2
解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        
        int maxLen = max(len1, len2);
        
        if(len1 == 0 || len2 == 0)
            return maxLen;
        
        //状态表示两个字串前i，j长度时的公共子序列长度
        int D[len1 + 1][len2 + 1];
        
        //初始化状态，初始化0和其它长度的公共子序列长度都为0
        for(int i = 0; i <= len1; i++)
            D[i][0] = 0;
        for(int i = 0; i <= len2; i++)
            D[0][i] = 0;
        
        //从1开始，0定义为一个初始状态.可以用递归也可以用递推
        for(int i = 1; i <= len1; i++)
            for(int j = 1; j <=len2; j++)
            {
                if(word1[i-1] == word2[j-1])
                    D[i][j] = D[i-1][j-1] + 1;
                else
                    D[i][j] = max(D[i-1][j], D[i][j-1]);
            }
        
        return len1 + len2 - 2* D[len1][len2];
    }
};
