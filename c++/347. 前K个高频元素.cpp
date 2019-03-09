/*
桶排序的方法，先将频率统计一次，然后创建n+1个桶（标号为0的桶没用），每个桶的下标表示该桶里面元素出现的频率，
把所有数放到桶里后，就直接从后开始遍历桶，取够k个数就可以了。 
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
