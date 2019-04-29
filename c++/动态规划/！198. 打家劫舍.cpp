/*
��̬�滮
D(i) ��ʾ��i����֮ǰ�����͵���Ľ��ͷֳ�͵���߲�͵��i�ң����͵��i�ҾͲ���͵��i-1�ң���D��i-1��һ�����ÿ��ǣ�
ע��D��i��������һ��Ҫ͵��i�ң�ֻ�ǻὫ�俼�ǽ�ȥ
D��i�� = max(money��i�� + D(i-2), D(i-1))
��ʼ����Ϣ��D(0) = money(0),D(1) = max(money(1), money(0)��
*/
class Solution {
public:
    vector<int> D;
    int rob(vector<int>& nums) {
        if(nums.size() <= 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        D = vector<int>(nums.size(), -1);
        D[0] = nums[0];
        //ע���ʼ״̬�Ķ���
        D[1] = max(nums[0], nums[1]);
        
        return getMaxNum(nums, nums.size() - 1);;
    }
    
    int getMaxNum(vector<int>& nums, int n)
    {
        if(n < 0)
            return 0;
        if(n == 0)
            return D[0];
        if(n == 1)
            return D[1];
        
        int fir = D[n-2] == -1 ? getMaxNum(nums, n-2) : D[n-2];
        fir += nums[n];
        int sec = D[n-1] == -1 ? getMaxNum(nums, n-1) : D[n-1];
        
        D[n] = max(fir, sec);
        return D[n];
    }
};
