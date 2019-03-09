/*
Ͱ����ķ������Ƚ�Ƶ��ͳ��һ�Σ�Ȼ�󴴽�n+1��Ͱ�����Ϊ0��Ͱû�ã���ÿ��Ͱ���±��ʾ��Ͱ����Ԫ�س��ֵ�Ƶ�ʣ�
���������ŵ�Ͱ��󣬾�ֱ�ӴӺ�ʼ����Ͱ��ȡ��k�����Ϳ����ˡ� 
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> frequency;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
            frequency[nums[i]]++;
        vector<vector<int>> buckets(nums.size() + 1);
        
        map<int, int>::iterator i;
        for(i = frequency.begin(); i != frequency.end(); i++)
        {
            buckets[i->second].push_back(i->first);
        }
        
        for(int j = buckets.size() - 1; j >= 0; j--)
        {
            int temp = 0;
            while(result.size() < k && temp < buckets[j].size())
            {
                result.push_back(buckets[j][temp]);
                temp++;
            }
        }
        return result;
    }
};
