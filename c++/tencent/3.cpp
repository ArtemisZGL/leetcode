/*
把1到2n的数分成两组长为n的，然后分别排序
1.。。n满足 abs（A【i】 - B【i】) < k 
有多少中分法

比较暴力，有点分治 
分成Apre，Bpre
然后先找比Apre大的往后进行遍历，然后每个找比Bpre和Acur +k 大的，然后往后遍历
或者找比Acur -k小的（因为是绝对值）， 然后往前遍历，途中如果比Bpre小就break 
遇到remain数组为0结果加1，上面搜索不到的就return 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int c = 0;
int n;
int k;

int findNum(vector<int> remainNum, int tar)
{
	for(int j = 0; j < remainNum.size(); j++)
	{
		if(remainNum[j] >= tar)
			return j;
	}
	return -1;
}

int findNum3(vector<int> remainNum, int tar)
{
	for(int j = 0; j < remainNum.size(); j++)
	{
		if(remainNum[j] <= tar)
			return j;
	}
	return -1;
}

int findNum2(vector<int> remainNum, int tar1, int tar2)
{
	for(int j = 0; j < remainNum.size(); j++)
	{
		if(remainNum[j] >= tar1 && remainNum[j] >= tar2)
			return j;
	}
	return -1;
}
void OPT(int Apre, int Bpre, vector<int> remainNum)
{
	if(remainNum.size() == 0)
	{
		c++;
		cout << endl;
		return;
	}
	int i = findNum(remainNum, Apre+1);
	if(i == -1)
		return;
	
	for(; i < remainNum.size(); i++)
	{
		vector<int> temp = remainNum;
		temp.erase(temp.begin() + i);
		int j = findNum2(temp, remainNum[i] + k, Bpre + 1);
		int j2 = findNum3(temp, remainNum[i] - k);
		if(j != -1)
		{
			for(; j < temp.size(); j++)
			{
				vector<int> temp2 = temp; 
				temp2.erase(temp2.begin() + j);
				cout << remainNum[i] << " " << temp[j] << endl;
				OPT(remainNum[i], temp[j], temp2);
			}
		 } 
		 if(j2 != -1)
		 {
		 	for(; j2 >= 0; j2--)
			{
				vector<int> temp2 = temp; 
				if(temp2[j2] < Bpre)
					break; 
				temp2.erase(temp2.begin() + j2);
				cout << remainNum[i] << " " << temp[j2] << endl;
				OPT(remainNum[i], temp[j2], temp2);
			}
		 }
		
		
	}
}


int main()
{
	
	cin >> n >> k;
	vector<int> remainNum(2*n);
	
	for(int i = 0; i < 2*n; i++)
	{
		remainNum[i] = i + 1;
	}
	//sort(remainNum.begin(), remainNum.end());
	OPT(0, 0, remainNum);
	cout << c;
}
