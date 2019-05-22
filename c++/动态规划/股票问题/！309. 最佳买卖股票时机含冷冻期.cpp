/*
https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/83acbb02-872a-4178-b22a-c89c3cb60263.jpg
�����ĸ�״̬�� Buy(i)�����i�����Ʊ���������S1(i)�����i����й�Ʊ������
              sell(i)�����i������Ʊ���������S2(i)�����i��û���й�Ʊ������
              (״̬s2�Ĵ��ھͺܺõĴﵽ����ȴ�ڵ�Ч����������sellֱ��ת��buy״̬)
״̬ת�Ʒ��̣�
             buy[i] = s2[i - 1] - prices[i];  ->ǰһ�������Ʊ
            s1[i] = Math.max(buy[i - 1], s1[i - 1]); ->ǰһ�����Ʊ�����󣬻���ǰһ����й�Ʊ������
            sell[i] = Math.max(buy[i - 1], s1[i - 1]) + prices[i]; ->ǰһ�����������������ǰһ����й�Ʊ������
            s2[i] = Math.max(s2[i - 1], sell[i - 1]); ->ǰһ�������Ʊ������ǰһ���Ѿ���û�й�Ʊ
*/

/*
����һ���������飬���е� i ��Ԫ�ش����˵� i ��Ĺ�Ʊ�۸� ��?

���һ���㷨����������������������Լ�������£�����Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ��:

�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����
������Ʊ�����޷��ڵڶ��������Ʊ (���䶳��Ϊ 1 ��)��
ʾ��:

����: [1,2,3,0,2]
���: 3 
����: ��Ӧ�Ľ���״̬Ϊ: [����, ����, �䶳��, ����, ����]
*/ 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        
        int buy[prices.size()];
        int s1[prices.size()];
        int sell[prices.size()];
        int s2[prices.size()];
        
        buy[0] = -prices[0];
        s1[0] =  -prices[0];
        sell[0] = 0;
        s2[0] = 0;
        
        for(int i = 1; i < prices.size(); i++)
        {
            buy[i] = s2[i - 1] - prices[i];
            s1[i] = max(buy[i - 1], s1[i - 1]);
            sell[i] = max(buy[i - 1], s1[i - 1]) + prices[i];
            s2[i] = max(s2[i - 1], sell[i - 1]);
        }
        return max(s2[prices.size()-1], sell[prices.size()-1]);
    }
};
