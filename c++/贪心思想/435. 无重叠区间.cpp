/*
活动选择问题：n个问题进行选择，他们竞争不同的资源，而且在不同的时间窗[x,y)，我们要找最多的方案数？
（贪心算法，动态规划。。。）
	把活动按某种方式排序，然后按顺序对活动进行选取（是否能保证最优？先找反例，找不到反例证明，反证法）
		排序方式：开始时间，结束时间，活动时间长度，与其它活动冲突个数（结束时间排序然后选取是最优的）
			证明：反证，假设存在一个最优解（不唯一）和贪心解，设前r个活动选择是一样的，到r+1的选择不一样，然后由于贪心算法是选早结束的，而且兼容，可以把最优解的第r+1个活动换成贪心解的第r+1个
			，换了之后不会影响最优解的方案活动个数，后面可以依次下去。可证明贪心解是最优解的一个

带权活动选择问题：每个活动是带权的，最后的选择方案要权重最大的。（不能用贪心，用动态规划）
*/


/*
limits头文件用法 
#include <limits> 
numeric_limits<T>::min() numeric_limits<T>::max()
*/ 


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval fir, Interval sec)
    {
        if(fir.end <= sec.end)
            return true;    //返回true排在前面
        else
            return false;
    }
    
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0;
        int currentEnd = numeric_limits<int>::min() ; 
        for(int i = 0; i < intervals.size(); i++)
        {
            if(intervals[i].start >= currentEnd)
            {
                currentEnd = intervals[i].end;
                count++;
            }
        }
        return intervals.size() - count;
    }
    
    
}; 
