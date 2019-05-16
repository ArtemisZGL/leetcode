/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
*/ 

/*
第一种方法，转成最长公共子序列问题，复杂度为O(nlogn) + O(n^2)
先将原数组X进行排序得到Y，那么X和Y的最长公共子序列就是最长上升子序列
最长公共子序列的动态规划解法：
设D(i,j)为Xi和Yj的最长公共子序列
状态转移方程：有两种情况，Xi和Yj最后一个元素相等, D(i,j) = D(i-1, j-1) + 1
如果不相等就是错开的情况：D(i,j) = max(D(i-1,j), D(i, j-1))
初始状态：D(1, 0)和D(0,1)为9=0

但是这种方法在有相等元素的时候好像行不通

第二种方法，直接动态规划,O(n^2)
设D(i)为以第i个元素为结尾的最长上升子序列（这里不用考虑他是不是以他结尾，总会要以一个元素结尾，最后取D最大值）
状态转移方程：从第i个元素前面找比他小的元素Aj，然后找出以Aj结尾的最长上升子序列D(j)，D(i) = max(D（j）)+1，
找不到比他小的，就直接是1
初始状态D(0) = 1

第三种方法：动态规划， O(nlogn)
设tails[i] 存储的是长度为 i + 1 时的最长递增子序列的最后一个元素，
并且在长度相等时存的是最小的元素（这样才能保证下面的更新是对的）
对于一个元素 x，
如果它大于 tails 数组所有的值，那么把它添加到 tails 后面，表示最长递增子序列长度加 1；
如果 tails[i-1] < x <= tails[i]，那么更新 tails[i] = x。（保持最小）(查找位置时用二分查找)
*/

/*
class Solution {
public:
    vector<vector<int>> D;
    int lengthOfLIS(vector<int>& nums) {
        //对数组进行排序
        vector<int> sortNums = nums;
        sort(sortNums.begin(), sortNums.end());
        
        //判断特殊情况
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        
        //初始化D
        D = vector<vector<int>>(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        D[1][0] = 0;
        D[0][1] = 0;
        
        return LCS(nums, sortNums, nums.size(), sortNums.size());
    }
    
    int LCS(vector<int>& nums, vector<int>& sortNums, int i, int j)
    {
        if(i == 0 || j == 0)
            return 0;
        if(nums[i-1] == sortNums[j-1])
        {
            cout << "a" << endl;
            int pre = D[i-1][j-1] == -1 ? LCS(nums, sortNums, i-1,j-1) : D[i-1][j-1];
            D[i][j] = pre + 1;
        }
        else
        {
            int fir = D[i-1][j] == -1 ? LCS(nums, sortNums, i-1,j) : D[i-1][j];
            int sec = D[i][j-1] == -1 ? LCS(nums, sortNums, i,j-1) : D[i][j-1];
            D[i][j] = max(fir, sec);
        }
        return D[i][j];
    }
};

*/

/*
class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        //判断特殊情况
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        
        vector<int> D(nums.size(), 0);
        
        for(int i = 0; i < nums.size(); i++)
        {
            int maxx = 1;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                    maxx = max(maxx, D[j] + 1);
            }
            D[i] = maxx;
        }
        sort(D.begin(), D.end());
        return D[nums.size()-1];
    }
};
*/

class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        //判断特殊情况
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        
        vector<int> tails;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int index = binarySearch(tails, num);
            if(index < tails.size())
                tails[index] = num;
            else
                tails.push_back(num);
        }
        return tails.size();
    }
    
    int binarySearch(vector<int> tails, int x)
    {
        int l = 0, h = tails.size();
        while (l < h) {
            //防止溢出
            int mid = l + (h - l) / 2;
            if (tails[mid] == x) {
                return mid;
            } else if (tails[mid] > x) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};


