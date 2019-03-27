#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
/*
定义状态L[i]，状态转移分成两种，用还是不用最后一个，如果用了最后一个数Si，那么就要在前面找一个不大于Si的数Sj，取他的L【j】+1, 如果不用就是L【i-1】，取这两者的最大值
P【i】定义为取得L【i】这个最大值的下标

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
	//回溯求得最优序列 
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
