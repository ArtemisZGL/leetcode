/*
动态规划的最长递增子序列的问题，不过要对序列先进行排序，因为他不用按顺序来构成子序列
**/

/*
给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。

现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。

给定一个对数集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。

示例 :

输入: [[1,2], [2,3], [3,4]]
输出: 2
解释: 最长的数对链是 [1,2] -> [3,4]
*/ 
class Solution {
public:
    static bool cmp(vector<int> fir, vector<int> sec)
    {
        return fir[0] < sec[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size() == 0)
            return 0;
        
        sort(pairs.begin(), pairs.end(), cmp);
        
        vector<int> D(pairs.size(), 0);
        
        for(int i = 0; i < pairs.size(); i++)
        {
            int maxx = 1;
            for(int j = 0; j < i; j++)
            {
                if(pairs[j][1] < pairs[i][0])
                {
                    maxx = max(maxx, D[j] + 1);
                }
            }
            D[i] = maxx;
        }
        
        sort(D.begin(), D.end());
        return(D[D.size() - 1]) ;
    }
};
