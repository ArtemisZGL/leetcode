/*
定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.
*/ 

/*
动态规划，定义状态D(i)为最少的平方数
状态转移方程，D(i)=min(D(i-j) + 1)，j为各个平方数大小
初始化可以将所有D都初始化为i，即分解为i个1
*/
class Solution {
public:
    vector<int> getSquares(int n)
    {
        vector<int> squares;
        int num = 1;
        int diff = 3;
        while(num <= n)
        {
            squares.push_back(num);
            num = diff + num;
            diff += 2;
        }
        return squares;
    }
    
    int numSquares(int n) {
        if(n == 0)
            return 0;
        vector<int> D(n+1, numeric_limits<int>::max());
        D[0] = 0;
        D[1] = 1;
        vector<int> squares = getSquares(n);
        
        for(int i = 1; i < n+1; i++)
        {
            for(int j = 0; j < squares.size(); j++)
            {
                if(i - squares[j] < 0)
                    break;
                D[i] = min(D[i], D[i - squares[j]] + 1);
            }
            //cout << D[i] << endl;
        }
        return D[n];
    }
};
