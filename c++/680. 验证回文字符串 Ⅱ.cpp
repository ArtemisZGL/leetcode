/*
简单的验证回文字符串很简单，就直接双指针前后，
但是如果要验证可以删掉一个的回文字符串，可以使用递归，就是遇到第一次不行的时候
就分两种情况，一个是删右边，一个是删左边，用原始判断方法，只要有一个可以就行 
*/ 
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
