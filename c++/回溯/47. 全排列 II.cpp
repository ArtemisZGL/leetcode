/*
����һ���ɰ����ظ����ֵ����У��������в��ظ���ȫ���С�

ʾ��:

����: [1,1,2]
���:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/ 
class Solution {
public:
    map<int, bool> visited;
    
    void btsearch(set<vector<int>>& ans, vector<int>& nums, vector<int>pre)
    {
        //�Ѿ���������
        if(pre.size() == nums.size())
        {
            ans.insert(pre);
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
    

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        
        vector<int> pre;
        btsearch(ans, nums, pre);
        vector<vector<int>> real(ans.begin(), ans.end());
        return real;
    }
};
