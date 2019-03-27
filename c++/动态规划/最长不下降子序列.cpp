#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
/*
����״̬L[i]��״̬ת�Ʒֳ����֣��û��ǲ������һ��������������һ����Si����ô��Ҫ��ǰ����һ��������Si����Sj��ȡ����L��j��+1, ������þ���L��i-1����ȡ�����ߵ����ֵ
P��i������Ϊȡ��L��i��������ֵ���±�

*/
int main()
{
	vector<int> nums;
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	int L[T], P[T];
	L[0] = 1;
	P[0] = -1;
	int ans = 0;
	int maxEnd = 0; 
	for(int j = 1; j < T; j++)
	{
		L[j] = 1;
		P[j] = -1;
		for(int i = 0; i < j; i++)
		{
			if(nums[i] <= nums[j] && L[i] + 1 > L[j])
			{
				P[j] = i;
				L[j] = L[i] + 1;
				
			}
		}
		if(ans < L[j])
			maxEnd = j;
		ans = max(ans, L[j]);
	}
	cout << ans << endl;
	int temp = maxEnd;
	/*
	for(int i = 0; i < T; i++)
		cout << P[i] << " " << L[i] << endl;
		*/
	//��������������� 
	vector<int> result;
	while(temp != -1)
	{
		result.push_back(nums[temp]);
		temp = P[temp];
	}
	reverse(result.begin(), result.end());
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	
 } 
