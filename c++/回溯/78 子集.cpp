/*
����һ�鲻���ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����

˵�����⼯���ܰ����ظ����Ӽ���

ʾ��:

����: nums = [1,2,3]
���:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/*
���ݵ��뷨��ÿ�ζ��ȼӽ�ȥ��Ȼ����һ��λ�ã��������ٻ��� 
*/ 

class Solution {
public:
    void btsearch(vector<vector<int>>& ans, vector<int>& nums, vector<int> pre, int begin)
    {
        for(int i = begin; i < nums.size(); i++)
        {
            vector<int> temp = pre;
            temp.push_back(nums[i]);
            ans.push_back(temp);
            btsearch(ans, nums, temp, i+1);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> ans;
         vector<int> pre;
        ans.push_back(pre);
        btsearch(ans, nums, pre, 0);
        return ans;
    }
};
