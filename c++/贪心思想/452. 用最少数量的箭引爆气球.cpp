/*
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。开始坐标总是小于结束坐标。平面内最多存在104个气球。

一支弓箭可以沿着x轴从不同点完全垂直地射出。在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

Example:

输入:
[[10,16], [2,8], [1,6], [7,12]]

输出:
2

*/

/*
同样是找无重叠区间的贪心问题，先按结束时间进行排序，然后每次选开始时间大于已选结束时间
这题和之前的那个相比要注意区间的开闭问题，因为end那里是闭区间，所以必须是大于，所以一开始就不能用最小值初始currentEnd,先把第一个放进去 

*/ 

class Solution {
public:
    static bool cmp(pair<int,int> fir, pair<int, int> sec)
    {
        return fir.second <= sec.second;
    }
    
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size() == 0)
            return 0;
        
        sort(points.begin(), points.end(), cmp);
        int currentEnd = points[0].second;
        int count = 1;
        for(int i = 1; i < points.size(); i++)
        {
            if(points[i].first > currentEnd)
            {
                count++;
                currentEnd = points[i].second;
            }
        }
        return count;
    }
};
