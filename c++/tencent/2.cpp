#include <iostream>
#include <vector>

using namespace std;
vector<int> attack, money;
int n;

int OPT(int cur, int totalW, int totalM)
{
	cout << cur <<" "<< totalW << " " << totalM << endl;
	if(attack[cur] > totalW)	//必须买
	{
		if(cur == n-1)
			return totalM + money[cur];
		else
			return OPT(cur + 1, totalW + attack[cur], totalM + money[cur]);
	 } 
	 else	//可买可不买 
	 {
		if(cur == n-1)
			return totalM;
	 	int no = OPT(cur + 1, totalW, totalM);
	 	int yes = OPT(cur + 1, totalW + attack[cur], totalM + money[cur]);
	 	
	 	return min(yes, no);
	 }
}

int main()
{
	
	cin >> n;
	if(n == 0)
		return 0;
	attack.resize(n);
	money.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> attack[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> money[i];
	}

	cout << OPT(0, 0, 0);
	
}
