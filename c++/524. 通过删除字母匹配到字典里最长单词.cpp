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
