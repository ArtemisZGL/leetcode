#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
bool cmp(string a, string b)
{
	if(b.find(a) != b.npos)
		return false;
	if(a.find(b) != a.npos)
		return true;
	int t = strcmp(a.c_str(),b.c_str());
	return (t <= 0);
}
int main()
{
	string str = "";
	cin >> str;
	
	map<char, int> lower, upper;
	
	for(unsigned int i = 0; i < str.size(); i++)
	{
		char temp = str[i];
		if(temp >= 'a' && temp <= 'z')
			lower[temp]++;
		else if(temp >= 'A' && temp <= 'Z')
			upper[temp]++;
	}
	char count = 'A';
	int diff = 'A' - 'a';
	string str2 = "";
	vector<string> ans;
	while(true)
	{
		//cout << "a"; 
		char low = count-diff;
		if(upper[count] > 0 && lower[low] > 0)
		{
			str2 = str2 + count + low;

			upper[count]--;
			lower[count-diff]--;
			
			count++;
		}
		else
		{
			//cout << str2;
			if(str2 != "")
			{
				ans.push_back(str2);
				count = 'A';
				str2 = "";
			}
			else
			{
				if(count != 'Z')
					count++;
				else
					break;
			}				
		}
	}
	if(ans.empty())
		cout << "Not Found";
	sort(ans.begin(), ans.end(), cmp);
	vector<string>::iterator it = ans.begin();
	int count2 = 0;
	for(it = ans.begin(); it != ans.end(); it++,count2++)
	{
		cout << *it;
		if(count2 != ans.size() - 1)
			cout << endl;
	}	
	
} 
