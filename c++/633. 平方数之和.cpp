/*
和从有序数组找和一样，双指针，一个从0开始，一个从根号开始 
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
