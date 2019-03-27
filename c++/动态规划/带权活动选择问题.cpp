#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
***��������*** 
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
	int s = activities.size() - 1;	//ǰs�������� 
	
	//����Ѿ��������ֱ�ӷ���
	if(maxWforAct[s] != -1)
		return maxWforAct[s];
	//û�м�����ͷ�����������м���
	//��ѡ��ǰ��� 
	int fir = getMaxW(vector<Act>(activities.begin(), activities.begin() + s));
	 
	 //ѡ��ǰ��� 
	int lnc = leastNotConflict[s];
	//���ÿ���lnc = -1���������Ϊ�Ѿ����������ǰ��ͷ�����
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
	
	sort(activities.begin(), activities.end(), cmp);	//�Ȱ�����ʱ������
	
	leastNotConflict.resize(T, -1);
	//�ҳ�ÿ������ݵ�����±� 
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
		//����-1˵��ǰ���Ѿ�û���������ݵ� 
		leastNotConflict[i] = index;
	}
	
	//�ѵ�һ����weight���ļ������
	int i = 0;
	int maxWeight = -1;
	while(leastNotConflict[i] == -1)
	{
		if(activities[i].weight > maxWeight)
			maxWeight = activities[i].weight;
		i++;
	 } 
	 
	maxWforAct.resize(T, -1);
	 //�����õ����Ž��� 
	 i = 0;
	 while(leastNotConflict[i] == -1)
	 {
	 	maxWforAct[i] = maxWeight;
	 	i++;
	 }
	 
	 
	
	cout << getMaxW(activities);
}
