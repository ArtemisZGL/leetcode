
class Solution {
public:
    string convertToBase7(int num) {
        
        //Ҫ���⴦��0�����,��Ϊ�������ѭ��
        if(num == 0)
            return "0";
        
        string ans = "";
        bool neg = num < 0;
        
        if(neg)
            num = -1 * num;
        
        //ע��ѭ����������Ϊ/7���������������϶���Ϊ0��
        while(num > 0)
        {
            //����ķ���
            ans += (num % 7 + 48);
            
            num = num / 7;
        }
        
        if(neg)
            ans += '-';
        
        //��Ҫ��ans��ת����,reverse���������������У�stringҲ����������һ��
        reverse(ans.begin(), ans.end());
        
        
        return ans;
        
    }
};
