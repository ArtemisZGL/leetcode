/*
��1��2n�����ֳ����鳤Ϊn�ģ�Ȼ��ֱ�����
1.����n���� abs��A��i�� - B��i��) < k 
�ж����зַ�

�Ƚϱ������е���� 
�ֳ�Apre��Bpre
Ȼ�����ұ�Apre���������б�����Ȼ��ÿ���ұ�Bpre��Acur +k ��ģ�Ȼ���������
�����ұ�Acur -kС�ģ���Ϊ�Ǿ���ֵ���� Ȼ����ǰ������;�������BpreС��break 
����remain����Ϊ0�����1���������������ľ�return 
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
