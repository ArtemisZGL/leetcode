/*
Í°ÅÅÐòµÄ·½·¨¡£ 
*/ 

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> frequency;
        for(int i = 0; i < s.length(); i++)
            frequency[s[i]] += 1;
        
        vector<vector<char>> buckets(s.length() + 1);
        
        map<char, int>::iterator it;
        for(it = frequency.begin(); it != frequency.end(); it++)
        {
            buckets[it->second].push_back(it->first);
        }
        
        string ans = "";
        for(int i = buckets.size() - 1; i >= 0 ; i--)
        {
            for(int j = 0; j < buckets[i].size(); j++)
            {
                for(int k = 0; k < i; k++)
                    ans += buckets[i][j];
            }
        }
        return ans;
    }
};
