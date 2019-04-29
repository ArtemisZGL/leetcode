/*
�ȶ���״̬D[i]����ʾ�����i��̨�׻��ѵ�
״̬ת�Ʒ��� D[i] = min(D[i-1], D[i-2]) + cost[i-1]
��ֵ D[1] = cost[0], D[2] = cost[1]
*/

/*
�����ÿ��������Ϊһ�����ݣ��� i�����ݶ�Ӧ��һ���Ǹ�������������ֵ cost[i](������0��ʼ)��

ÿ��������һ�������㶼Ҫ���Ѷ�Ӧ����������ֵ��Ȼ�������ѡ�������һ�����ݻ������������ݡ�

����Ҫ�ҵ��ﵽ¥�㶥������ͻ��ѡ��ڿ�ʼʱ�������ѡ�������Ϊ 0 �� 1 ��Ԫ����Ϊ��ʼ���ݡ�

ʾ�� 1:

����: cost = [10, 15, 20]
���: 15
����: ��ͻ����Ǵ�cost[1]��ʼ��Ȼ�����������ɵ����ݶ���һ������15��
 ʾ�� 2:

����: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
���: 6
����: ��ͻ��ѷ�ʽ�Ǵ�cost[0]��ʼ�����������Щ1������cost[3]��һ������6��
*/ 
class Solution {
public:
    vector<int> D;
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() <= 0)
            return 0;
        if(cost.size() == 1)
            return 0;

        D = vector<int>(cost.size() + 2, -1);
        D[1] = cost[0];
        D[2] = cost[1];
        //��������Ǹ�����Ϊ0
        cost.push_back(0);
        return getMincost(cost, cost.size());
    }
    
    int getMincost(vector<int>& cost,int n)
    {
        if(n <= 0)
            return 0;
        //��һ����̨��
        if(n <= 2)
            return D[n];
        
        int fir = D[n-1] == -1 ? getMincost(cost, n-1) : D[n-1];
        int sec = D[n-2] == -1 ? getMincost(cost, n-2) : D[n-2];
        
        int m = min(fir, sec);
        D[n] = m + cost[n - 1];
        
        return D[n];
    }
};
