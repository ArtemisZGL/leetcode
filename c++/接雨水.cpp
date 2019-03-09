class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> maxLeft(size), maxRight(size);  //��i����ߵ������ұߵ����
        int totalWater = 0;
        
        for(int i = 1; i < size; i++)   //���жϵ�һ����Ĭ�ϳ�ʼ��Ϊ0
        {
            maxLeft[i] = max(maxLeft[i-1], height[i-1]);    //����ߺ���ߵ�������Ƚ�
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
