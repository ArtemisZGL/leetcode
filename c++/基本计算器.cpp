#include <iostream>
#include <stack>
using namespace std;
/*
http://www.cnblogs.com/grandyang/p/4570699.html
�����������ʵ��һ�������ļ�����������򵥵��������ʽ��������Ŀ�����˱��ʽ��ֻ�мӼ��ţ����֣����źͿո�
û�г˳�����ô��ûɶ��������ȼ�֮���ˡ����������ͱ��û����ô�����ˡ�������Ҫһ��ջ���������㣬�ø�����sign����ʾ��ǰ�ķ��ţ�
���Ǳ����������ַ���s��������������֣����ڿ����Ǹ���λ������������Ҫ��whileѭ����֮������ֶ���������Ȼ����sign*num�����½��res��
��������˼Ӻţ���sign��Ϊ1����������˷��ţ���Ϊ-1����������������ţ���ѵ�ǰ���res�ͷ���signѹ��ջ��res����Ϊ0��sign����Ϊ1��
��������������ţ����res����ջ���ķ��ţ�ջ��Ԫ�س�ջ�����res����ջ�������֣�ջ��Ԫ�س�ջ���������£�
*/
class Solution {
public:
    int calculate(string s) {
    	/* 
        int sign = 1;
        int result = 0;
        stack<int> mstack;
        
        for(int i = 0; i < s.length(); i++)
        {
        	char c = s[i];
        	if(s[i] >= '0')
        	{
        		int tempNum = 0;
        		while(s[i] >= '0' && i < s.length())
        		{
        			tempNum = tempNum * 10 - '0' + s[i] ;	//�ȼ�0��Ȼ����� 
        			i++;
				}
				result += tempNum * sign;
				i--;
			}
			else if(s[i] == '+')
				sign = 1;
			else if(s[i] == '-')
				sign = -1;
			else if(s[i] == '(')
			{
				mstack.push(result);
				mstack.push(sign);
				sign = 1;
        		result = 0;
			}
			else if(s[i] == ')')
			{
				int preSign = mstack.top();
				mstack.pop();
				int preResult = mstack.top();
				mstack.pop();
				
				result = preResult + result * preSign;
			}
			
		}
		return result;
		*/ 
    }
};

int main()
{
	Solution s;
	cout << s.calculate("2147483647");
 } 
 
 
