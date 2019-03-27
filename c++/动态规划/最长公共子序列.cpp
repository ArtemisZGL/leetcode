/*
*��������
	ABCBDAB
	BDCABC

	ans��BCAB

*
*/

/*
	����õ��Ƕ�̬�滮�����ֺ�ƥ�������У������û�з��ĸ������ĸ��Ǹ�����˫ָ�룬����֪���ƶ��ĸ� 
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
	//�Ѿ������ 
	if(LCS[i][j] != -1)
		return LCS[i][j];
	
	//û����ͷ����֣����һ����Ȼ��߲����
	if(fir[i] == sec[j])
	{
		int lcs;
		//����0�Ͳ����ڲ���һ���� 
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
	 	//����0�Ͳ������з��� 
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
	//״̬LCS[i]p[j] xi,��yj������г���
	LCS.resize(fir.length());
	for(int i = 0; i < fir.length(); i++)
	{
		LCS[i].resize((sec.length()), -1);
	}
	
	//���ñ߽� 
	if(fir[0] == sec[0])
		LCS[0][0] = 1;
	else
		LCS[0][0] = 0;
	
	LCS[0][1] = fir[0] == sec[1];
	LCS[1][0] = fir[1] == sec[0];
	
	cout << getMaxLCS(fir, sec);
}
