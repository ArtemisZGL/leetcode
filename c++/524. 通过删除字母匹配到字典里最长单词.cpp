/*
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output:
"apple"

题目描述：删除 s 中的一些字符，使得它构成字符串列表 d 中的一个字符串，
找出能构成的最长字符串。如果有多个相同长度的结果，返回字典序的最小字符串。

比较暴力的方法， 从d中遍历，首先判断其长度是否比已经找到的长
如果是，就进行验证，验证的方法就是双指针，相同就两个一起往前，不同就s的往前，最后如果看d的指针是否
走到最尾 
如果不是，就直接跳过 

*/ 

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        for(int i = 0; i < d.size(); i++)
        {
            string temp = d[i];
            if(temp.length() < ans.length() || (temp.length() == ans.length() && temp.compare(ans) >= 0))
                continue;
            if(isValid(s, temp))
                ans = temp;
        }
        return ans;
    }
    
    bool isValid(string str, string target)
    {
        int pre = 0, post = 0;
        while(pre < str.length() && post < target.length())
        {
            if(str[pre] == target[post])
            {
                pre++;
                post++;
            }
            else
            {
                pre++;
            }
        }
        return post >= target.length();
    }
};
