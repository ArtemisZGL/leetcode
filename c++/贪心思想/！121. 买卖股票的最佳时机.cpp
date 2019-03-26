/*
����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�

��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������

ע���㲻���������Ʊǰ������Ʊ��

ʾ�� 1:

����: [7,1,5,3,6,4]
���: 5
����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
     ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�
*/ 

/*
̰��˼�룬����һ�Σ�ÿ�ν���ǰֵ����Сֵ���������������Ƚϡ���Сֵ�Ļ�Ҫʱʱ���£�
�����ǰ����СֵС����Ҫ������Сֵ
��������ܳɹ�����Ϊֻ�ܺ����ǰ�棬��ǰֵ��ǰ����СֵС����Ӱ��ǰ��ļ���������
�������Ľ��ʱҲ�ܸ��¡� 
*/ 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //��̬�滮
        /*
        if(prices.size() <= 1)
            return 0;
        if(prices.size() <= 2)
            return max(prices[1] - prices[0], 0);
        
        vector<int> temp(prices.begin(), prices.begin() + prices.size() - 1);
        int count = ( prices.size() - 1);
        int minNum = *min_element(prices.begin(), prices.begin() + count);
        return max(maxProfit(temp), prices[prices.size() - 1] - minNum);
        */
        
        if(prices.size() == 0)
            return 0;
        int currentMin = prices[0];
        int maxRes = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] - currentMin > maxRes)
                maxRes = prices[i] - currentMin;
            
            if(prices[i] < currentMin)
                currentMin = prices[i];
        }
        return maxRes;
    }
};
