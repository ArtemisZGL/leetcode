/*
ƽ�����У�1,4,9,16,..

�����3,5,7,...

���Ϊ�Ȳ����У�ʹ��������Կ��Եõ��� 1 ��ʼ��ƽ�����С�
*/

/*
����һ�������� num����дһ����������� num ��һ����ȫƽ�������򷵻� True�����򷵻� False��

˵������Ҫʹ���κ����õĿ⺯������  sqrt��

ʾ�� 1��

���룺16
�����True
ʾ�� 2��

���룺14
�����False
*/ 

class Solution {
public:
    bool isPerfectSquare(int num) {
        long sqrt = 1, diff = 3;
        while(true)
        {
            if(sqrt > num)
                return false;
            if(sqrt == num)
                return true;
            
            sqrt += diff;
            diff += 2;
        }
    }
};
