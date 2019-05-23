/*
https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/1e2c588c-72b7-445e-aacb-d55dc8a88c29.png
ͬ���Ƕ�̬�滮��״̬�����֮ǰ��һ����������ͬ״̬֮���ת��������ͬ
*/

/*
����һ���������� prices�����е� i ��Ԫ�ش����˵� i ��Ĺ�Ʊ�۸� ���Ǹ����� fee �����˽��׹�Ʊ���������á�

��������޴ε���ɽ��ף�������ÿ�ν��׶���Ҫ�������ѡ�������Ѿ�������һ����Ʊ����������֮ǰ��Ͳ����ټ��������Ʊ�ˡ�

���ػ����������ֵ��

ʾ�� 1:

����: prices = [1, 3, 2, 8, 4, 9], fee = 2
���: 8
����: �ܹ��ﵽ���������:  
�ڴ˴����� prices[0] = 1
�ڴ˴����� prices[3] = 8
�ڴ˴����� prices[4] = 4
�ڴ˴����� prices[5] = 9
������: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
*/ 
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int days = prices.size();
        
        if(days == 0)
            return 0;
        
        //����״̬
        int buy[days];
        int s1[days];
        int sell[days];
        int s2[days];
        
        //��ʼ״̬
        buy[0] = -prices[0];
        s1[0] = -prices[0];
        sell[0] = 0;
        s2[0] = 0;
        
        for(int i = 1; i < days; i++)
        {
            buy[i] = max(s2[i-1], sell[i-1]) - prices[i];
            s1[i] = max(buy[i-1], s1[i-1]);
            sell[i] = max(buy[i-1], s1[i-1])  + prices[i] - fee;
            s2[i] = max(s2[i-1], sell[i-1]);
        }
        return max(s2[days-1], sell[days-1]);
    }
};
