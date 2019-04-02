#include <iostream>
using namespace std;

/*
用bfs广度优先搜索来解决不带权的最短路径问题，也可以是一些可以看成图的最优解问题 

这题可以看成是从n点到0点的最短路径问题，每个自然数n都是一个点，两个点之间有边意味着差一个平方数
 
*/ 

class Solution {
public:
	//获取从1到n的平方数 ，（n+1）^2 - n^2=  2n +1,所以每次diff+2 
    vector<int> getSquares(int n)
    {
        vector<int> squares;
        int num = 1;
        int diff = 3;
        while(num <= n)	//注意要等于，否则输入为平方数的时候就错了 
        {
            squares.push_back(num);
            num = diff + num;
            diff += 2;
        }
        return squares;
    }
    
    //看成从n这个点到0这个点，每差一个平方数可以看成有边
    int numSquares(int n) {
        vector<int> squares = getSquares(n);
        
        //两个重要的数据结构，访问的queue，标记是否访问过的map 
        queue<int> levelSearch;
        levelSearch.push(n);
        map<int, bool> visited;
        visited[n] = true;
        int level = 0;
        
        while(!levelSearch.empty())
        {
            int size = levelSearch.size();
            level++;
            //每个level把队列清空一次，属于同一个层次 
            for(int i = 0; i < size; i++)
            {
                //当前点
                int cur = levelSearch.front();
                levelSearch.pop();
                for(int j = 0; j < squares.size(); j++)
                {
                    int next = cur - squares[j];
                    //cout << next << " ";
                    if(next == 0)	//去到0点 
                        return level;
                    //后面肯定都是小于0
                    else if(next < 0)
                        break;
                    else
                    {
                        if(!visited[next])
                        {
                            visited[next] = true;
                            levelSearch.push(next);
                        }
                    }
                }
                //cout << cur << endl;
            }
        }
        
        return -1;
    }
};
