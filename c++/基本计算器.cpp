#include <iostream>
#include <stack>
using namespace std;
/*
http://www.cnblogs.com/grandyang/p/4570699.html
这道题让我们实现一个基本的计算器来计算简单的算数表达式，而且题目限制了表达式中只有加减号，数字，括号和空格，
没有乘除，那么就没啥计算的优先级之分了。于是这道题就变的没有那么复杂了。我们需要一个栈来辅助计算，用个变量sign来表示当前的符号，
我们遍历给定的字符串s，如果遇到了数字，由于可能是个多位数，所以我们要用while循环把之后的数字都读进来，然后用sign*num来更新结果res；
如果遇到了加号，则sign赋为1，如果遇到了符号，则赋为-1；如果遇到了左括号，则把当前结果res和符号sign压入栈，res重置为0，sign重置为1；
如果遇到了右括号，结果res乘以栈顶的符号，栈顶元素出栈，结果res加上栈顶的数字，栈顶元素出栈。代码如下：
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
        			tempNum = tempNum * 10 - '0' + s[i] ;	//先减0不然会溢出 
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
 
 
