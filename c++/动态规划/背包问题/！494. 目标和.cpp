/*
sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
2 * sum(P) = target + sum(nums)

���������ʽ�ӣ����ǿ���ת��Ϊ0-1�������⣬�����ǣ�target + sum ��/ 2
���ж����зŷ����Խ���������
*/

/*
����һ���Ǹ��������飬a1, a2, ..., an, ��һ��Ŀ������S������������������ + �� -�����������е�����һ���������㶼���Դ� + �� -��ѡ��һ�����������ǰ�档

���ؿ���ʹ���������ΪĿ���� S ��������ӷ��ŵķ�������

ʾ�� 1:

����: nums: [1, 1, 1, 1, 1], S: 3
���: 5
����: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

һ����5�ַ���������Ŀ���Ϊ3��
*/ 

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0)
            return 0;
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        
        if(sum < S || (sum + S) % 2 != 0)
            return 0;
        
        int W = (sum + S) / 2;
        vector<int> D(W + 1, 0); //����������պ÷����Ĵ���
        //��ʼ��
        D[0] = 1;
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = W; j >= nums[i]; j--)
            {
                //���ϸպ�ȱ�ٵ�ǰnum��
                D[j] = D[j] + D[j-nums[i]];
            }
        }
        return D[W];
    }
};
