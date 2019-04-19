
class Solution {
public:
    string convertToBase7(int num) {
        
        //要特殊处理0的情况,因为不会进入循环
        if(num == 0)
            return "0";
        
        string ans = "";
        bool neg = num < 0;
        
        if(neg)
            num = -1 * num;
        
        //注意循环条件，因为/7是整除，所以最后肯定会为0的
        while(num > 0)
        {
            //求余的方法
            ans += (num % 7 + 48);
            
            num = num / 7;
        }
        
        if(neg)
            ans += '-';
        
        //还要把ans反转过来,reverse函数可用在容器中，string也算是容器的一种
        reverse(ans.begin(), ans.end());
        
        
        return ans;
        
    }
};
