
/*
����һ��û���ظ����ֵ����У����������п��ܵ�ȫ���С�

ʾ��:

����: [1,2,3]
���:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/ 
/*
���������û��ݵķ�����ע�ⵥ��֧���ϲ��趨visited�����Ҵ��ݵ�preע��ÿһ�����ǲ���Ӱ�� 
*/ 
class Solution {
public:
    map<int, bool> visited;
    
    void btsearch(vector<vector<int>>& ans, vector<int>& nums, vector<int>pre)
    {
        //�Ѿ���������
        if(pre.size() == nums.size())
        {
            ans.push_back(pre);
            return;
        }
        
        //�ҵ�ûvisited
        int i = 0;
        for(; i < nums.size(); i++)
        {
            if(!visited[i])
            {
                //��ӵ�
                vector<int> temp = pre;
                temp.push_back(nums[i]);
                //��һ�ֻ�������
                visited[i] = true;
                btsearch(ans, nums, temp);
                //�������visted�Ļ���
                visited[i] = false;
            }
        }
        
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        vector<int> pre;
        btsearch(ans, nums, pre);
        return ans;
    }
};
