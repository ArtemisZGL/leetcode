/*
����һ��������дһ���������ж����Ƿ��� 3 ���ݴη���

ʾ�� 1:

����: 27
���: true
ʾ�� 2:

����: 0
���: false
ʾ�� 3:

����: 9
���: true
ʾ�� 4:

����: 45
���: false
���ף�
���ܲ�ʹ��ѭ�����ߵݹ�����ɱ�����
*/ 

class Solution {
public:
    bool isPowerOfThree(int n) {
        //���ҵ������͵��������
        int maxInt = numeric_limits<int>::max();
        //log3��maxInt��������ȡ֤���͵õ�������3������
        int maxThree = log(maxInt) / log(3);
        //Ȼ����^3��������3����
        maxThree = pow(3, maxThree);
        //�����3���ݴη��ض����Ա���������ݴ���������Ϊ���Ӷ�ֻ��3��1
        return n > 0 && maxThree % n == 0;
    }
};
