/*
假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

*/ 


/*
我也不知道这算不算贪心问题，不过还是一样的想
贪心的定义是将问题分成小问题，然后每个小问题的最优解最后可以构成大问题的最优解（不一定有）
一般的做法是先按某个方法进行排序，然后对排序后的进行子问题操作 
*/ 

/*
这题的做法也是先按照排序，一开始我的想法是按高度从低到高排，然后从矮到高插入新队列，但是这样的话后插入的会影响前面插入的结果

所以应该是按从高到低来进行排序，这样的话后面插入的都是比队列中矮的，不会影响到第二个值k的位置
那么如果是高度相同的呢，应该让k值小的排前面，因为k的定义是大于等于，等于的也算，所以让k小的先排，
后面即使是相同h，但k大则一定会排在前一个相同h的后面，不会影响到他的位置 
*/ 

/*
注意这里insert的用法，常用的三个用法，底层是数组，所以不是在尾部插入复杂度较高，插入后迭代器会失效 
single element (1)	
iterator insert (iterator position, const value_type& val);
fill (2)	void insert (iterator position, size_type n, const value_type& val);
range (3)	template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last); 
*/

class Solution {
public:
    static bool cmp(pair<int, int> fir, pair<int, int> sec)
    {
        if(fir.first > sec.first)
            return true;
        else if(fir.first < sec.first)
            return false;
        else
            return fir.second <= sec.second;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), cmp);
        
        vector<pair<int, int> > ans;
        for(int i = 0; i < people.size(); i++)
        {
            vector<pair<int, int> >::iterator it = ans.begin();
            ans.insert(it + people[i].second, people[i]);
        }
        return ans;
    }
};
