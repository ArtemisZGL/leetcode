/*
��Ŀ����������ũ���г����ĸţÿ�궼���� 1 ͷСĸţ��������Զ��������
		 ��һ���� 1 ֻСĸţ���ӵڶ��꿪ʼ��ĸţ��ʼ��Сĸţ��ÿֻС
		 ĸţ 3 ��֮������ֿ�����Сĸţ���������� N���� N ���ţ��������

��̬�滮�� 
״̬������D(i)��ʾ��i��ĸţ������
ת�Ʒ��� ��D(i) = D(i-1) + D(i-3) ��һ���������ǰ�������������Ϊǰ3��ĵ������������м�ǰ2���ǰ1�����ӵĶ�������
��ʼֵ��D(1) = 1��D(2) = 2, D(3) = 3 
*/ 

#include <iostream>
#include <vector>
using namespace std;

vector<int> D;

int getCowNum(int n)
{
	if(n <= 3)
		return D[n];
	
	int fir = D[n-1] == -1 ? getCowNum(n-1) : D[n-1];
	int sec = D[n-3] == -1 ? getCowNum(n-3) : D[n-3];
	
	D[n] = fir + sec;
	return D[n];
}

int main()
{
	int n;
	cin >> n;
	if(n < 0)
		cout << 0 << endl;
	else if(n <= 3)
		cout << 3 << endl;
	else
	{
		D = vector<int>(n + 1, -1);
		D[1] = 1;
		D[2] = 2;
		D[3] = 3;
		cout << getCowNum(n) << endl;
	}
}
