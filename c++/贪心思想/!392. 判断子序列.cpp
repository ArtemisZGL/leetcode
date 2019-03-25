/*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

示例 1:
s = "abc", t = "ahbgdc"

返回 true.

示例 2:
s = "axc", t = "ahbgdc"

返回 false.

后续挑战 :

如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*
         *   最简单就是直接用双指针的方法来做
         */
        
        /*
         *   贪心中按区间来进行选取，将每个子母的开始结束区间记下来
         *   然后在遍历匹配的子串序列，要拷贝一份上面的区间副本。
         *   然后下一个字母的结束区间要在上一个区间的结束区间之后，并修改当前字母的结束
         *
         *   但是这样好像不行，因为他的位置点是离散的，不是连续的，
         *
         *   所以只能纪录每个字母对应出现的位置，然后遍历s，找到对应能满足的最小位置
         *   必须要比上一个字母的位置要大
         */
        
        
        map<char, bool> occur;
        map<char, vector<int> > letters;
        for(int i = 0; i < t.length(); i++)
        {
            if(occur[t[i]])
               letters[t[i]].push_back(i);
            else
            {
                occur[t[i]] = true;
                letters[t[i]].push_back(i);
            }
                
        }
        
        int preIndex = -1; 
        for(int i = 0; i < s.length(); i++)
        {
            //cout<<s[i] << endl;
            if(!occur[s[i]])
                return false;
            else
            {
                bool satisfy = false;
                for(int j = 0; j < letters[s[i]].size(); j++)
                {
                    if(letters[s[i]][j] > preIndex)
                    {
                        preIndex = letters[s[i]][j];
                        //cout << s[i] << preIndex << " ";
                        satisfy = true;
                        break;
                    }
                    
                }
                if(!satisfy)
                    return false;
            }
        }
        return true;
    }
};
