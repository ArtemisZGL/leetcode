/*
1*2*3*4
1*2 2*3 3*4
*/
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<vector<int>> m; //m[i][j]表示Ai连乘到Aj的cost 
vector<int> weidu;

int getMinCost(int start, int end)
{
	//cout << start << " " << end;
	if(m[start][end] != numeric_limits<int>::max())
	{
		return m[start][end];
	}
	
	for(int i = start; i < end; i++)
	{
		int pro1 = getMinCost(start, i);
		int pro2 = getMinCost(i + 1, end);
		//cout << pro1 << " " << pro2 << " " << weidu[start]*weidu[i+1]*weidu[end+1] << endl;
		m[start][end] = min(m[start][end], pro1 + pro2 + weidu[start]*weidu[i+1]*weidu[end+1]);
	}
	//cout << "yes" << start << " " << end << " " << m[start][end] << endl;
	return m[start][end];
}

int main()
{
	int T;
	cin >> T;
	weidu.resize(T);	//共有T-1个矩阵相乘 1*2 2*3 就记成1 2 3 
	for(int i = 0; i < T; i++)
	{
		cin >> weidu[i];
	}
	
	
	//初始化 
	m.resize(T-1);
	for(int i = 0; i < T - 1; i++)
	{
		m[i].resize(T-1, numeric_limits<int>::max());
		m[i][i] = 0;
	}
	/*
	for(int i = 0; i < T - 1; i++)
	{
		for(int j = 0; j  < T - 1; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
	cout << "A";
	*/
	cout << getMinCost(0, T-2);
}                        
