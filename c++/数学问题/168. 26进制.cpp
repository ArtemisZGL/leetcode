/*
����һ������������������ Excel �������Ӧ�������ơ�

���磬

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
ʾ�� 1:

����: 1
���: "A"
ʾ�� 2:

����: 28
���: "AB"
ʾ�� 3:

����: 701
���: "ZY"
*/ 

/*
�൱��26���Ƶ�ת��
*/
class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        
        
        while(n > 0)
        {
            //ע����������n�Ǵ�1��ʼ�ģ�����Ҫ�ȼ�1����Ȼ�������ﲻ��Ū
            n = n - 1;
            
            //λ������ֻ��2���ݴ�����
            ans += (n % 26) + 'A';
            
            n = n / 26;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
