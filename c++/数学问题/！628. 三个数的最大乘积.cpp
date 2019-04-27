/*
�������ĳ˻���󣬻�Ҫ���ǵ�������˵���������Բ��ܼ򵥵���������������ˣ���Ҫ�ҳ���С��2������
��Ϊ������������������Ƚ�����������˴������������������С������˴�
*/

/*
����һ���������飬���������ҳ�����������ɵ����˻������������˻���

ʾ�� 1:

����: [1,2,3]
���: 6
ʾ�� 2:

����: [1,2,3,4]
���: 24
ע��:

�������������鳤�ȷ�Χ��[3,104]�����������е�Ԫ�ط�Χ��[-1000, 1000]��
����������������������ĳ˻����ᳬ��32λ�з��������ķ�Χ��
*/ 
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = numeric_limits<int>::min();
        int max2 = numeric_limits<int>::min();
        int max3 = numeric_limits<int>::min();
        
        int min1 = numeric_limits<int>::max();
        int min2 = numeric_limits<int>::max();
        int min3 = numeric_limits<int>::max();
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2)
            {
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i] > max3)
                max3 = nums[i];
            
            if(nums[i] < min1)
            {
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] < min2)
                min2 = nums[i];
            
        }
        
        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};
