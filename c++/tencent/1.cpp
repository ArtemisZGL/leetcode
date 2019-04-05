#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main()
{
	int n, s;
	cin >> n >> s;
	vector<int> vs(n);
	for(int i = 0; i < n; i++)
	{
		cin >> vs[i];
	}
	
	sort(vs.begin(), vs.end());
	
	for(int i = n-1; i>=0; i--)
	{
		s = s - (vs[i] - vs[0]);
		if(s <= 0)
			break;
	}
	if(s <= 0)
		cout << vs[0];
	else
	{
		while(s > 0 && vs[0] > 0)
		{
			s -= n;
			vs[0]--;
		}
		if(s > 0)
			cout << -1;
		else
			cout << vs[0];
	}	
	
	
}
