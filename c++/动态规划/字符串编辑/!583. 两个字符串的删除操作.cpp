/*
������������У�Ȼ���������ܳ��ȼ�ȥ�����Ĺ��������г��Ⱦ���Ҫɾ���Ĳ���
*/

/*
������������ word1 �� word2���ҵ�ʹ�� word1 �� word2 ��ͬ�������С������ÿ������ɾ������һ���ַ����е�һ���ַ���

ʾ�� 1:

����: "sea", "eat"
���: 2
����: ��һ����"sea"��Ϊ"ea"���ڶ�����"eat"��Ϊ"ea"

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        
        int maxLen = max(len1, len2);
        
        if(len1 == 0 || len2 == 0)
            return maxLen;
        
        //״̬��ʾ�����ִ�ǰi��j����ʱ�Ĺ��������г���
        int D[len1 + 1][len2 + 1];
        
        //��ʼ��״̬����ʼ��0���������ȵĹ��������г��ȶ�Ϊ0
        for(int i = 0; i <= len1; i++)
            D[i][0] = 0;
        for(int i = 0; i <= len2; i++)
            D[0][i] = 0;
        
        //��1��ʼ��0����Ϊһ����ʼ״̬.�����õݹ�Ҳ�����õ���
        for(int i = 1; i <= len1; i++)
            for(int j = 1; j <=len2; j++)
            {
                if(word1[i-1] == word2[j-1])
                    D[i][j] = D[i-1][j-1] + 1;
                else
                    D[i][j] = max(D[i-1][j], D[i][j-1]);
            }
        
        return len1 + len2 - 2* D[len1][len2];
    }
};
