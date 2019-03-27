/*
*测试用例
	ABCBDAB
	BDCABC

	ans：BCAB

*
*/

/*
	这个用的是动态规划，区分和匹配子序列，这个是没有分哪个是主哪个是副不能双指针，否则不知道移动哪个 
*/ 


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> LCS;

int getMaxLCS(string fir, string sec)
{
	int i = fir.length() - 1;
	int j = sec.length() - 1;
	//已经算过了 
	if(LCS[i][j] != -1)
		return LCS[i][j];
	
	//没算过就分两种，最后一个相等或者不相等
	if(fir[i] == sec[j])
	{
		int lcs;
		//等于0就不用在查下一个了 
		if(i == 0 || j == 0)
			LCS[i][j] = 1;
		else
		{
			lcs = getMaxLCS(fir.substr(0, i), sec.substr(0, j));
			LCS[i][j] = lcs + 1;	
		}
	 } 
	 else
	 {
	 	//等于0就不用在切分了 
	 	int pro1 = (j == 0) ? -1: getMaxLCS(fir, sec.substr(0, j));
	 	int pro2 = (i == 0) ? -1: getMaxLCS(fir.substr(0, i), sec);
	 	LCS[i][j] = max(pro1, pro2);
	 }
	 
	 return LCS[i][j];
}

int main()
{
	string fir, sec;
	cin >> fir >> sec;
	//状态LCS[i]p[j] xi,和yj的最长序列长度
	LCS.resize(fir.length());
	for(int i = 0; i < fir.length(); i++)
	{
		LCS[i].resize((sec.length()), -1);
	}
	
	//设置边界 
	if(fir[0] == sec[0])
		LCS[0][0] = 1;
	else
		LCS[0][0] = 0;
	
	LCS[0][1] = fir[0] == sec[1];
	LCS[1][0] = fir[1] == sec[0];
	
	cout << getMaxLCS(fir, sec);
}
