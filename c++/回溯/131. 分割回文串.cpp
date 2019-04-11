/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

/*
我的想法就是每次只切成两部分，begin代表切的起始位置，i是切的长度，然后每次切了之后，看前面的那部分是回文，就递归切后面的，
下一次切的起始位置是要加上切的长度 begin = begin + i，
如果前面不是回文，就直接不用继续切后面了
当切的起始位置为最后的时候就说明结束，加入到结果中 
*/ 
class Solution {
public:
    void btsearch(vector<vector<string>>& ans, int begin, vector<string> pre, string s)
    {
        if(begin == s.size())
        {
            ans.push_back(pre);
            return;
        }
        
        //每次只切成2部分,i表示切割的长度，最多切size-begin
        for(int i = 1; i < s.size() - begin + 1; i++)
        {
            string fir = s.substr(begin, i);
            if(isHW(fir))
            {
                vector<string> temp = pre;
                temp.push_back(fir);
                btsearch(ans, begin + i, temp, s);
            }
        }
    }
    
    bool isHW(string s)
    {
        int begin = 0, end = s.size() - 1;
        if(end < begin)
            return false;
        while(begin < end)
        {
            if(s[begin] != s[end])
                return false;
            else
            {
                begin++;
                end--;
            }
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> pre;
        btsearch(ans, 0, pre, s);
        return ans;
    }
};
