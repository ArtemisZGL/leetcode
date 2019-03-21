#include <iostream>
#include <stack>
#include <cmath>
using namespace std; 
int main()
{
	string str = "";
	stack<int> ms , op;
	cin >> str;
	bool preNum = false;
	int count = 1;
	int num = 0;
	for(int i = 0; i < str.size(); i++)
	{
		//cout << str[i] << endl;
		char temp = str[i];
		if(temp >= '0' && temp <= '9')
		{
			if(preNum)
			{
				num = pow(10,count) * num + (temp - '0');
				count++; 
			}
			else
			{
				preNum = true;
				num += temp - '0';
			}
		}
		else
		{
			ms.push((num));
			if(ms.size() == 2)
			{
				int fir = ms.top();
				ms.pop();
				int sec = ms.top();
				ms.pop();
				char oper = op.top();
				op.pop();
				int result = 0;
				if(oper == '+')
					result = fir + sec;
				else
					result = sec - fir;
				
				ms.push(result);
			}
			op.push(temp);
			num = 0;
			count = 1;
			preNum = false;
			
		}
	}
	int fir = ms.top();
	ms.pop();
	char oper = op.top();
	op.pop();
	int result = 0;
	if(oper == '+')
		result = fir + num;
	else
		result = fir - num;
	
	ms.push(result);
	cout <<  ms.top();
}
