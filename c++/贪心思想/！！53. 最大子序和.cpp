/*
����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

ʾ��:

����: [-2,1,-3,4,-1,2,1,-5,4],
���: 6
����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��
����:

������Ѿ�ʵ�ָ��Ӷ�Ϊ O(n) �Ľⷨ������ʹ�ø�Ϊ����ķ��η���⡣
*/ 

/*
̰�ĵ�˼�룬ÿ��ֻҪǰ��ĺʹ���0���ͼӵ�ǰ�����Ȼ�󽫽�������ŵĽ���Ƚϣ�ÿ�ζ�Ҫ�����ŵļ����� 
�����������������������ҪŪ�������飬�ӵ�ʱ���push�����Ӿ�clear���������źã��ͼ����� 
*/ 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxRes = nums[0], preSum = 0;
       vector<int> resultInterval;
        vector<int> currentInterval;
        for(int i = 0; i < nums.size(); i++)
        {
            if(preSum > 0)  //���ǰ��ĺʹ���0����̰�ĵ���Ҫ��������һ��
            {
                preSum += nums[i];
                currentInterval.push_back(nums[i]);
            }
            else        //��������´����ڿ�ʼ
            {
                preSum = nums[i];
                currentInterval.clear();
                currentInterval.push_back(nums[i]);
            }
            
            //ÿ������֮�󣬶�Ҫ�����ڵĽ���������Ľ������ǲ�����õģ���¼����õĽ��
            if(maxRes < preSum)
                resultInterval = currentInterval;
            maxRes = max(maxRes, preSum);
        }
        for(int num : resultInterval)
            cout << num  << " ";
        return maxRes;
    }
};
