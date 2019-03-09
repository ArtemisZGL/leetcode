/*
先说这道题怎么解，如上所说，我们应该通过一个栈维护一个递增序列，如果当前待插入字符c比栈顶的元素ascll码小，
就不断弹出栈顶元素，否则放入栈中，这样便可以得到一个递增的序列，但是对于这道题这么做是不行的。因为加了一个条件不能出现重复的字母，
所以要加一些限制条件，先用一个计数器count给所有字符计数，然后开始遍历每个字符，首先把对应字符的计数-1，
然后比较当前带插入字符c和栈顶元素ascll大小，如果比栈顶元素小并且栈顶元素的计数器不为0，
就意味着先把栈顶元素弹出之后可以再把栈顶元素压入可以形成更小的字符串（如bcabc，当到字符a时发现a的ascll比c小，
并且c的字符在后面还有（c计数器不为0），就意味着先把c弹出，a压入，之后再压入c可以得到更小的字符串）。
*/ 
#include<iostream>
#include<vector> 
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> letterCount(26, 0);
        vector<bool> letterVisited(26, false);
        string mstack;
        
        for(auto c : s)
        {
            letterCount[c - 'a']++;
        }
        
        for(auto c: s)
        {
            letterCount[c - 'a']--;
            if(letterVisited[c - 'a'])
                continue;
            if(mstack.empty())
                mstack.push_back(c);
            else
            {
                char top = mstack.back();
                while(c < top && letterCount[top - 'a'] > 0)
                {
                    mstack.pop_back();
                    letterVisited[top - 'a'] = false;
                    if(mstack.empty())
                    {
                        break;
                    }
                    top = mstack.back();
                }
                mstack.push_back(c);
                cout << mstack << endl;
                letterVisited[c - 'a'] = true;
            }
            
        }
        return mstack;
    }
};

int main()
{
	Solution s;
	cout << s.removeDuplicateLetters("bcabc");
 } 
