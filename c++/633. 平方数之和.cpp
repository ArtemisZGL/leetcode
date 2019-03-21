/*
�ʹ����������Һ�һ����˫ָ�룬һ����0��ʼ��һ���Ӹ��ſ�ʼ 
*/ 
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0, right = floor(sqrt(c));
        while(left <= right)
        {
            long long temp = left * left + right * right;
            if(temp < c)
            {
               left++; 
            }
            else if(temp > c)
            {
                right--;
            }
            else
                return true;
        }
        return false;
    }
};
