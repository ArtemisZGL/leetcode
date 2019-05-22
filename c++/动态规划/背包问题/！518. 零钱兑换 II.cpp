/*
��ȫ��������
����״̬d[j]��ʾ��ǰi����Ʒ����Ϊj������£���ϵ���Ŀ

(��ʾ��j������i����Ʒ�����������i-1����Ʒ�����������j-coin���������Ҳ���Ǹպ÷Ŷ����Ӳ�ҵ����)
״̬ת�Ʒ��� d[j] = d[j] + d[j-coin]

��ʼ״̬D[0] = 1����ʾ���Ϊ0���������1������ʲô������
*/

/*
������ͬ����Ӳ�Һ�һ���ܽ�д��������������Դճ��ܽ���Ӳ�������������ÿһ������Ӳ�������޸��� 

 

ʾ�� 1:

����: amount = 5, coins = [1, 2, 5]
���: 4
����: �����ַ�ʽ���Դճ��ܽ��:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
ʾ�� 2:

����: amount = 3, coins = [2]
���: 0
����: ֻ�����2��Ӳ�Ҳ��ܴճ��ܽ��3��
*/ 

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        if(coins.size() == 0)
            return 0;
        
        int D[amount+1];
        for(int i = 0;i <= amount; i++)
            D[i] = 0;
        D[0] = 1;
        
        for(int i = 0; i < coins.size(); i++)
        {
            for(int j = coins[i]; j <= amount; j++)
            {
                D[j] = D[j] + D[j-coins[i]];
            }
        }
        return D[amount];
    }
};
