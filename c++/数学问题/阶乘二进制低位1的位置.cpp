/*
�ҵ�n!�Ķ����Ʊ�ʾ�����λ1��λ�á�
��2�������λΪ0������2��������1λ�������λ��1���������2. �����1��λ�þ��� n!���Գ���2�Ĵ���+1
��2������2������ӵĸ�������֮ǰ��5�����Ӹ�����һ���ķ��� 
���Ҫ��1����Ϊ��λ�� 
*/ 

#include <iostream>
using namespace std;

void findLowestOne(int n)
{
	if(n == 0)
		return 0;
	
	return n / 2 + findLowestOne(n / 2);
	
	/*
	int ans = 0;
    while(n)
    {
        n = n >> 1;
        ans += n;
    }
    return ans + 1;
	*/
}
int main()
{
	int n;
	cin >> n;
	cout << findLowestOne(n) + 1;
} 
