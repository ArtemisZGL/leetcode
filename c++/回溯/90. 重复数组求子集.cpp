/*
����һ�����ܰ����ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����

˵�����⼯���ܰ����ظ����Ӽ���

ʾ��:

����: [1,2,2]
���:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/ 

/*
��֮ǰ�ظ���������ϲ�࣬����Ҫ������Ȼ���visit���飬���ǰһ���͵�ǰ��ͬ������ǰһ��ûvistit������������ͺ�ǰһ��������ظ� 
*/ 

class Solution {
public:
    map<int, bool> visited;
    
    void btsearch(vector<vector<int>>& ans, int begin, vector<int> pre, vector<int>& nums)
    {
        for(int i = begin; i < nums.size(); i++)
        {
            //ȥ���ظ������
            if(i != 0 && nums[i - 1] == nums[i] && visited[i - 1] == false)
                continue;
            
            vector<int> temp = pre;
            temp.push_back(nums[i]);
            
            visited[i] = true;
            ans.push_back(temp);
            btsearch(ans, i + 1, temp, nums);
            //���ݻ����Ժ��visited�ĳ�false
            visited[i] = false;
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> pre;
        //�ѿռ��ӽ�ȥ
        ans.push_back(pre);
        btsearch(ans, 0, pre, nums);
        return ans;
    }
};
