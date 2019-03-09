class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)
            return;
        if(m == 0)
        {
            nums1 = nums2;
        }
        
        int first = m - 1, second = n - 1, mergeIndex = m - 1 + n;
        while(first >= 0 || second >= 0)
        {
            if(first < 0)
            {
                while(second >= 0)
                {
                    nums1[mergeIndex--] = nums2[second];
                    second--;
                }
            }
            else if(second < 0)
            {
                while(first >= 0)
                {
                    nums1[mergeIndex--] = nums1[first];
                    first--;
                }
            }
            else if(nums1[first] < nums2[second])
            {
                nums1[mergeIndex--] = nums2[second];
                second--;
            }
            else if(nums1[first] >= nums2[second])
            {
                nums1[mergeIndex--] = nums1[first];
                first--;
            }
        }
    }
};
