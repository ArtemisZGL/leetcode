#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
***测试用例*** 
*
*  
	5
	1 4 5
	3 6 2
	2 5 7
	9 15 4
	12 16 1 
 
 	ans 11
* 
*/

class Act
{
	public:
		int start;
		int end;
		int weight;	
		Act(int s, int e, int w)
		{
			this->start = s;
			this->end = e;
			this->weight = w;
		}
};

vector<int> maxWforAct;
vector<int> leastNotConflict;

bool cmp(Act fir, Act sec)
{
	return fir.end <= sec.end;
}

int getMaxW(vector<Act> activities)
{
	int s = activities.size() - 1;	//前s个已排序活动 
	
	//如果已经计算过了直接返回
	if(maxWforAct[s] != -1)
		return maxWforAct[s];
	//没有计算过就分两种情况进行计算
	//不选当前这个 
	int fir = getMaxW(vector<Act>(activities.begin(), activities.begin() + s));
	 
	 //选当前这个 
	int lnc = leastNotConflict[s];
	//不用考虑lnc = -1的情况，因为已经计算过了在前面就返回了
	int sec = getMaxW(vector<Act>(activities.begin(), activities.begin() + lnc));
	maxWforAct[s] = max(fir, sec + activities[s].weight);
	return maxWforAct[s];
}

int main()
{
	int T;
	cin >> T;
	vector<Act > activities;
	for(int i = 0; i < T; i++)
	{
		int start, end, weight;
		cin >> start >> end >> weight;
		activities.push_back(Act(start, end, weight));
	}
	
	sort(activities.begin(), activities.end(), cmp);	//先按结束时间排序
	
	leastNotConflict.resize(T, -1);
	//找出每个活动相容的最大下标 
	for(int i = 0; i < T; i++)
	{
		int index = -1;
		for(int j = i - 1; j >= 0; j--)
		{
			if(activities[j].end <= activities[i].start)
			{
				index = j;
				break;
			}
		}
		//等于-1说明前面已经没有与他相容的 
		leastNotConflict[i] = index;
	}
	
	//把第一批中weight最大的计算出来
	int i = 0;
	int maxWeight = -1;
	while(leastNotConflict[i] == -1)
	{
		if(activities[i].weight > maxWeight)
			maxWeight = activities[i].weight;
		i++;
	 } 
	 
	maxWforAct.resize(T, -1);
	 //并设置到最优解中 
	 i = 0;
	 while(leastNotConflict[i] == -1)
	 {
	 	maxWforAct[i] = maxWeight;
	 	i++;
	 }
	 
	 
	
	cout << getMaxW(activities);
}
