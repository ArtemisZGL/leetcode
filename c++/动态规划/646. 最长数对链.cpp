/*
��̬�滮������������е����⣬����Ҫ�������Ƚ���������Ϊ�����ð�˳��������������
**/

/*
���� n �����ԡ� ��ÿһ�������У���һ���������Ǳȵڶ�������С��

���ڣ����Ƕ���һ�ָ����ϵ�����ҽ��� b < c ʱ������(c, d) �ſ��Ը��� (a, b) ���档������������ʽ������һ����������

����һ���������ϣ��ҳ��ܹ��γɵ���������ĳ��ȡ��㲻��Ҫ�õ����е����ԣ���������κ�˳��ѡ�����е�һЩ���������졣

ʾ�� :

����: [[1,2], [2,3], [3,4]]
���: 2
����: ����������� [1,2] -> [3,4]
*/ 
class Solution {
public:
    static bool cmp(vector<int> fir, vector<int> sec)
    {
        return fir[0] < sec[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size() == 0)
            return 0;
        
        sort(pairs.begin(), pairs.end(), cmp);
        
        vector<int> D(pairs.size(), 0);
        
        for(int i = 0; i < pairs.size(); i++)
        {
            int maxx = 1;
            for(int j = 0; j < i; j++)
            {
                if(pairs[j][1] < pairs[i][0])
                {
                    maxx = max(maxx, D[j] + 1);
                }
            }
            D[i] = maxx;
        }
        
        sort(D.begin(), D.end());
        return(D[D.size() - 1]) ;
    }
};
