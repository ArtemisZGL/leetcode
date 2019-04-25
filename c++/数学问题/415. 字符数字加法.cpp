class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0, i = num1.length()- 1, j = num2.length()-1;
        string ans;
        
        while(i >= 0 && j >= 0)
        {
            int fir = num1[i--] - '0';
            int sec = num2[j--] - '0';
            int result = fir + sec + carry;
            carry = result / 10;
            ans += (result % 10 + '0');
        }
        
        
        while(i >= 0)
        {
            int result = num1[i--] - '0' + carry;
            carry = result / 10;
            ans += (result % 10 + '0');
        }
        
        while(j >= 0)
        {
            int result = num2[j--] - '0' + carry;
            carry = result / 10;
            ans += (result % 10 + '0');
        }
        
        if(carry != 0)
            ans += (carry + '0');
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
