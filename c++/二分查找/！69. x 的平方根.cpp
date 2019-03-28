/*
ʵ�� int sqrt(int x) ������

���㲢���� x ��ƽ���������� x �ǷǸ�������

���ڷ������������������ֻ���������Ĳ��֣�С�����ֽ�����ȥ��

ʾ�� 1:

����: 4
���: 2
ʾ�� 2:

����: 8
���: 2
˵��: 8 ��ƽ������ 2.82842..., 
     ���ڷ���������������С�����ֽ�����ȥ
*/

class Solution {
public:
    //����ȡ��������ȡС�ڵ���key�ĵ�һ������key��ƽ����
    //С��key begin = med + 1
    //����key end = med - 1
    //�ǵ����أ����������кܶ�key����ʱ�����Ǿ�Ҫȡ���ұߵģ����key�����ڣ�Ҳ��ȡС��key�����ұߵ�
    //���Ե�<=key��begin��Ҫ����med+1������Begin��ָ��պñ�key��ģ�end��ָ������Ҫ�Ĵ�
    int mySqrt(int x) {
        int begin = 1, end = x;
        while(begin <= end)
        {
            int med = begin + (end - begin) / 2;
            
            if(med > x / med)       //���ﲻ��ֱ����med*med����������
                end = med - 1;
            else 
                begin = med + 1;   
        }
        return end;
    }
};
