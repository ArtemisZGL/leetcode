/*
完全背包， 把目标字符串看成是一个背包，然后字典看成是物品
该问题涉及到字典中单词的使用顺序，因此可理解为涉及顺序的完全背包问题。

涉及顺序的完全背包要怎么处理呢？，把物品的循环放到内层中去
定义状态d[i]， 表示在i容量下能否放满
（状态转移，当前容量是否可以放满，就逐个逐个物品来，第j个物品
如果当前容量已经确定可以放满，或者是恰好放下第j个物品能够放满
状态转移方程：d[i] = d[i] || d[i-]

初始状态：d[0] = true, 容量为0有解
*/

/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
*/ 

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.length() == 0)
            return true;
        
        int D[s.length() + 1];
        for(int i = 0; i <= s.length(); i++)
            D[i] = false;
        D[0] = true;
        
        //表示在字符串的前i个字串的情况
        for(int i = 1; i <= s.length(); i++)
        {
            //对物品进行遍历
            for(int j = 0; j < wordDict.size(); j++)
            {
                int len = wordDict[j].length();
                //还要验证是否和字符串匹配
                if(len <= i && wordDict[j] == s.substr(i-len, len))
                    D[i] = D[i] || D[i-wordDict[j].length()];
            }
        }
        
        return D[s.length()];
    }
};
