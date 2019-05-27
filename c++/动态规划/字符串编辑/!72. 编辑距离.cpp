/*
��������������е�˼���е�����

����״̬d[i][j] ��ʾ��������ǰi��j���ȵ�������ת����Ҫ�õĲ�����

״̬ת�Ʒ��̣�
    ����������������һλ��ȣ���ôת������Ĳ������͵������������ж�����һ�����ȵĲ�����
    d[i][j] = d[i-1][j-1]
    
    ����������һλ���ȣ��������������Ӧ�޸ģ�ɾ��������
    1. word1[0..i-1] �� word2[0..j-1] �ı任��Ҫ���� k ��
       word1[0..i] �� word2[0..j] �ı任���Ȱ�word1[0..i-1] �任�� word2[0..j-1]��Ȼ��
       �����һλ�޸ĳ� word1[i] �ĳ� word2[j]���ܹ����ĵĲ���Ϊk+1
    2. ��� word1[0..i-1] �� word2[0..j] �ı任��Ҫ���� k ��
        word1[0..i] �� word2[0..j] �ı任���Ȱ�word1[0..i-1] �任�� word2[0..j]��Ȼ��
       �����һλword1[i]ɾ�����ܹ����ĵĲ���Ϊk+1
    3. ��� word1[0..i] �� word2[0..j-1] �ı任��Ҫ���� k ��
        word1[0..i] �� word2[0..j] �ı任���Ȱ�word1[0..i] �任�� word2[0..j-1]��Ȼ��
       �����һλword2[i]���룬�ܹ����ĵĲ���Ϊk+1
    ȡ�������������Сֵ����
*/

/*
������������ word1 �� word2��������� word1 ת���� word2 ��ʹ�õ����ٲ����� ��

����Զ�һ�����ʽ����������ֲ�����

����һ���ַ�
ɾ��һ���ַ�
�滻һ���ַ�
ʾ�� 1:

����: word1 = "horse", word2 = "ros"
���: 3
����: 
horse -> rorse (�� 'h' �滻Ϊ 'r')
rorse -> rose (ɾ�� 'r')
rose -> ros (ɾ�� 'e')
ʾ�� 2:

����: word1 = "intention", word2 = "execution"
���: 5
����: 
intention -> inention (ɾ�� 't')
inention -> enention (�� 'i' �滻Ϊ 'e')
enention -> exention (�� 'n' �滻Ϊ 'x')
exention -> exection (�� 'n' �滻Ϊ 'c')
exection -> execution (���� 'u')
*/


class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        
        int maxLen = max(len1, len2);
        
        if(len1 == 0 || len2 == 0)
            return maxLen;
        
        //״̬��ʾ�����ִ�ǰi��j����ʱ
        int D[len1 + 1][len2 + 1];
        
        //��ʼ��״̬����ʼ��0���������ȵĲ�����
        //word2=0��word1ȫ��ɾ��
        //word1=0,word1ȫ������word2
        for(int i = 0; i <= len1; i++)
            D[i][0] = i;
        for(int i = 0; i <= len2; i++)
            D[0][i] = i;
        
        //��1��ʼ��0����Ϊһ����ʼ״̬.�����õݹ�Ҳ�����õ���
        for(int i = 1; i <= len1; i++)
            for(int j = 1; j <=len2; j++)
            {
                if(word1[i-1] == word2[j-1])
                    D[i][j] = D[i-1][j-1];
                else
                    D[i][j] = min(min(D[i-1][j-1],D[i-1][j]), D[i][j-1])+1;
            }
        
        return D[len1][len2];
    }
};
