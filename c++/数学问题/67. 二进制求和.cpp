/*
给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
*/ 

class Solution {
public:
    vector<char> add(char fir, char sec, char carry)
    {
        //第一个是结果，第二个是进位
        vector<char> result;
        if(fir == '1' && sec == '1' && carry == '1')
        {
            result.push_back('1');
            result.push_back('1');
        }
        else if(fir == '0' && sec == '0' && carry == '0')
        {
            result.push_back('0');
            result.push_back('0');
        }
        else if((fir == '1' && sec == '1') || (fir == '1' && carry == '1') || (sec == '1' && carry == '1'))
        {
            result.push_back('0');
            result.push_back('1');
        }
        else
        {
            result.push_back('1');
            result.push_back('0');
        }
        return result;
    }
    string addBinary(string a, string b) {
        int alen = a.length();
        int blen = b.length();
        int i = alen -1, j = blen -1;
        
        char carry = '0';
        string ans = "";
        
        //先对共同部分进行加法
        int t = 0;
        for(; t < min(alen, blen); t++)
        {
            vector<char> result = add(a[i-t], b[j-t], carry);
            carry = result[1];
            ans += result[0];
        }
        //第一个数前面还有
        if(alen > t)
        {
            while(alen > t)
            {
                vector<char> result = add(a[i-t], '0', carry);
                t++;
                carry = result[1];
                ans += result[0];
            }
        }
        if(blen > t)
        {
            while(blen > t)
            {
                vector<char> result = add('0', b[j-t], carry);
                t++;
                carry = result[1];
                ans += result[0];
            }
        }
        
        //cout << carry;
        //最后还要加上进位
        if(carry == '1')
            ans += carry;
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
