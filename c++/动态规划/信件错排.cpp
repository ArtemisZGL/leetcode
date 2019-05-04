/*
�ż��Ŵ�����
�� N �� �� �� �ŷ⣬���Ǳ����ң������װ�ŷ�ʽ����������ȫ����װ��������� 

��һ�ַ�����򵥣��и�ȫ��λ���й�ʽ��S=n!(1-1/1!+1/2!-1/3!+...(-1)^n/n!)

��һ�ַ��������ܵ�n!��ȥ�����ŷ�װ�Ե����������ֻ��һ��װ��Ҳ�㣩
S=n!-C(n,1)f(n-1)-C(n,2)f(n-2)-...C(n,n-2)f(2)-1 

��̬�滮���ȶ���״̬D(i),��ʾi���ŷ���ŵĴ����ŷŷ�ʽ����
ת�Ʒ��̣�����װ�ţ������i���ŷŵ���j���ŷ⣬��j���ŷŵ���k���ŷ⣬��ô����������ж�i�Ƿ����k
���i == k
	��ô����ʣ��i-2���ź��ŷ⣬�����Ŵ�ʽ����d��i-2)��Ȼ�����j��ѡȡ��i-1�ַ�ʽ�������ܹ��У�i-1��*d��i-2)��
���i != k
	��ʱ�����i��j�ż�������j��������ȷλ�ã����໹���ڴ���λ�ã������d(i-1)�з�ʽ��Ȼ��j��ѡȡ����i-1�֣������ (i-1) * d(i-1)
	
D(i) = (i-1) * d(i-2) + (i-1) * d(i-1)
 
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> D;

int DPmethor(int n)
{
	if(n <= 2)
		return D[n];
	
	int fir = D[n-2] == -1 ? DPmethor(n-2) : D[n-2];
	int sec = D[n-1] == -1 ? DPmethor(n-1) : D[n-1];
	D[n] = (n-1) * (fir + sec);
	return D[n];
}

int formularMethor(int n)
{
	//���Ӻͷ�ĸ,ѭ����ʱ��ÿ�γ���i������ 
	int up = 1;
	int down = 1;
	double sum = 1;
	
	//��1��ʼ�������ĸΪ0����Ū 
	for(int i = 1; i <= n; i++)
	{
		up *= -1;
		down *= i;
		//ע����������ͣ�temp��up��sum��Ҫ�Ǹ���������������������ڸ�ֵǰ���Ѿ��ض��ˣ�����ӵ�����Ҳ��ض� 
		double temp = (double)up / down;
		//cout << up << " " << down << " " << temp << endl;
		sum += temp;
	}
	return down * sum;
}

  
int main()
{
	
	int n;
	cin >> n;
	//��ʼ����̬�滮��״̬ 
	D = vector<int>(n + 1 , -1); 
	if(n <= 1)
		cout << 0 << endl;
	else if(n == 2)
		cout << 1 << endl;
	else
	{
		D[1] = 0;
		D[2] = 1;
		
		cout << DPmethor(n) << endl;
		cout << formularMethor(n) << endl;	
	}
	
} 

