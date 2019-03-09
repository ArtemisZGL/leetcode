class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> maxLeft(size), maxRight(size);  //第i个左边的最大和右边的最大
        int totalWater = 0;
        
        for(int i = 1; i < size; i++)   //不判断第一个，默认初始化为0
        {
            maxLeft[i] = max(maxLeft[i-1], height[i-1]);    //用左边和左边的左边最大比较
        }
        
        for(int i = size - 2; i >= 0; i--)
        {
            maxRight[i] = max(maxRight[i + 1], height[i+1]);
        }
        
        for(int i = 0; i < size; i++)
        {
            int bottomleck = min(maxLeft[i], maxRight[i]);
            int diff = bottomleck - height[i];
            totalWater += (diff > 0 ? diff : 0);
        }
        return totalWater;
    }
};
