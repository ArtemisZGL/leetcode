class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        int count = 0;
        
        while(left < right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            else
                return isvalidPalindrome(s.substr(left + 1, right - left)) ||                                          isvalidPalindrome(s.substr(left, right - left));
        }
        return true;
    }
    bool isvalidPalindrome(string s)
    {
        int left = 0, right = s.length() - 1;
 
        while(left < right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            else
                return false;
        }
        return true;
    }
};
