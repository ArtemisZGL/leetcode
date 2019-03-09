#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
map<char, char> mymap;
 vector<char> mv;
int findNum(char c);
int main()
{
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int ruleCount = 0;
        cin >> ruleCount;
        
        mymap.clear();

        for(int j = 0; j < ruleCount; j++)
		{
			char x, y;
			cin >> x >> y;
			mymap[x] = y;
		}
		
		int loseCount = 0;
		cin >> loseCount;
		
		mv.clear();
		for(int j = 0; j < loseCount; j++)
		{
			char lose;
			cin >> lose;
			mv.push_back(lose);
		}
		
		string text = "";
		cin >> text;
		int count = 0;
		for(int j = 0; j < text.length(); j++)
		{
			int temp = findNum(text[j]);
			if(temp == 999999)
			{
				count = -1;
				break;
			}
			else
				count += temp;
			
			//cout << temp << " ";
		}
		if(count != -1)
			count += text.length();
		cout << count << endl;
    }
}

int findNum(char c)
{
	if(find(mv.begin(), mv.end(), c) != mv.end())
	{
		//cout << "zgl " << c << endl;
		map<char, char>::iterator it = mymap.begin();
		map<char, int> pre;
		while(it != mymap.end())
		{
			//cout << "lgz" << endl;
			if(it->second == c)
			{
				//cout << "lgz" << it->first;
				pre[it->first] = 1;
				map<char, int>::iterator it2 = pre.begin();
				bool index = false;
				while(it2 != pre.end())
				{
					if(it2->first != it->first && it2->second == 1)
						index = true;
					it2++;
				}
				if(!index && find(mv.begin(), mv.end(), it->first) != mv.end())
				{
					int temp = findNum(it->first);
					if(temp == 999999)
						return 999999;
					pre[it->first] = pre[it->first] + temp;
				}
			}
			it++;
		}
		map<char, int>::iterator it2 = pre.begin();
		int min = 999999;
		while(it2 != pre.end())
		{
			//cout << it2->second;
			if(it2->second < min)
				min = it2->second;
			
			it2++;
		}
		//cout << endl;
		return min;
	}
	else
		return 0;
}
