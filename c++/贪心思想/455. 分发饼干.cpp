/*
题目描述：每个孩子都有一个满足度，每个饼干都有一个大小，只有饼干的大小大于等于一个孩子的满足度，
该孩子才会获得满足。求解最多可以获得满足的孩子数量。

贪心算法：用尽量小的饼干刚好满足小孩子的胃口
反证法：证明：假设在某次选择中，贪心策略选择给当前满足度最小的孩子分配第 m 个饼干，
第 m 个饼干为可以满足该孩子的最小饼干。假设存在一种最优策略，给该孩子分配第 n 个饼干，
并且 m < n。我们可以发现，经过这一轮分配，贪心策略分配后剩下的饼干一定有一个比最优策略来得大。
因此在后续的分配中，贪心策略一定能满足更多的孩子。也就是说不存在比贪心策略更优的策略，即贪心策略就是最优策略。
*/ 

/*
注意在判断条件的时候先判断下标有没有越界，再用下标来取数进行判断 
要学会自己写测试用例，判断一些边界条件 
*/ 
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());	//g是孩子，s是饼干 
        sort(s.begin(), s.end());
        
        int gindex = 0, sindex = 0;
        int count = 0;
        
        while(gindex < g.size() && sindex < s.size())
        {
            while(sindex < s.size() && g[gindex] > s[sindex])	//找到一个可以满足孩子胃口的最小饼干 
                sindex++;
            
            if(sindex < s.size())	//在范围内 
                count++;
            gindex++;				//满足后，孩子和饼干都要后移 
            sindex++;
        }
        
        return count;
    }
};
