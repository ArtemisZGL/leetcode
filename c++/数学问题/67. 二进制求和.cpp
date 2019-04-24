/*
���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����

����Ϊ�ǿ��ַ�����ֻ�������� 1 �� 0��

ʾ�� 1:

����: a = "11", b = "1"
���: "100"
ʾ�� 2:

����: a = "1010", b = "1011"
���: "10101"
*/ 

class Solution {
public:
    vector<char> add(char fir, char sec, char carry)
    {
        //��һ���ǽ�����ڶ����ǽ�λ
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
        
        //�ȶԹ�ͬ���ֽ��мӷ�
        int t = 0;
        for(; t < min(alen, blen); t++)
        {
            vector<char> result = add(a[i-t], b[j-t], carry);
            carry = result[1];
            ans += result[0];
        }
        //��һ����ǰ�滹��
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
        //���Ҫ���Ͻ�λ
        if(carry == '1')
            ans += carry;
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
