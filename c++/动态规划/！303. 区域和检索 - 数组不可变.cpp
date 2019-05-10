/*
����һ����������  nums�������������� i �� j  (i �� j) ��Χ��Ԫ�ص��ܺͣ����� i,  j ���㡣

ʾ����

���� nums = [-2, 0, 3, -5, 2, -1]����ͺ���Ϊ sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
˵��:

����Լ������鲻�ɱ䡣
���ε��� sumRange ������
*/ 
/*
ע�����������������䣬״̬�����е㼼�ɣ���ε��õ�����±ȽϿ� 
��̬�滮����״̬D(i)��¼�ӵ�0������i-1���ĺͣ�Ȼ���������ʱ��ֻҪD(i+!) - D��j)
״̬ת�Ʒ��̾�ΪD(i) = d(i-1) + nums[i-1]�������ظ�����
��һ���ĳ�ʼֵd(0) = 0
*/
class NumArray {
public:
    vector<int> D;
    NumArray(vector<int>& nums) {
        D = vector<int>(nums.size() + 1);
        D[0] = 0;
        for(int i = 1; i <= nums.size(); i++)
            D[i] = D[i-1] + nums[i-1];
        
    }
    
    int sumRange(int i, int j) {
        if(i > D.size() || j > D.size() || i < 0 || j < 0)
            return 0;
        return D[j+1] - D[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
