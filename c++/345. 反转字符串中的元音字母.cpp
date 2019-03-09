class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.length() - 1;
        set<char> hs{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while(left <= right)
        {
            if(hs.find(s[left]) != hs.end() && hs.find(s[right]) != hs.end())
            {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
            else if(hs.find(s[left]) == hs.end())
                left++;
            else if(hs.find(s[right]) == hs.end())
                right--;
        }
        return s;
    }
};
