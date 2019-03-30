/*
����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�

����㷨ʱ�临�Ӷȱ����� O(log n) ����

��������в�����Ŀ��ֵ������ [-1, -1]��

ʾ�� 1:

����: nums = [5,7,7,8,8,10], target = 8
���: [3,4]
ʾ�� 2:

����: nums = [5,7,7,8,8,10], target = 6
���: [-1,-1]
*/

/*
���ֲ��ң����ҵ�ֵ�������������� 
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        int med = 0;
        if(end < 0)
            return vector<int>{-1,-1};
        while(begin <= end)
        {
            med = begin + (end - begin) / 2;
            if(nums[med] < target)
                begin = med + 1;
            else if(nums[med] > target)
                end = med - 1;
            else
                break;
        }
        if(nums[med] != target)
            return vector<int>{-1,-1};
        begin = end = med;
        while(begin >= 0 && nums[begin] == target)
            begin--;
        
        while(end < nums.size() && nums[end] == target)
            end++;
        return vector<int>{begin+1,end-1};
    }
};
