/*
��˵�������ô�⣬������˵������Ӧ��ͨ��һ��ջά��һ���������У������ǰ�������ַ�c��ջ����Ԫ��ascll��С��
�Ͳ��ϵ���ջ��Ԫ�أ��������ջ�У���������Եõ�һ�����������У����Ƕ����������ô���ǲ��еġ���Ϊ����һ���������ܳ����ظ�����ĸ��
����Ҫ��һЩ��������������һ��������count�������ַ�������Ȼ��ʼ����ÿ���ַ������ȰѶ�Ӧ�ַ��ļ���-1��
Ȼ��Ƚϵ�ǰ�������ַ�c��ջ��Ԫ��ascll��С�������ջ��Ԫ��С����ջ��Ԫ�صļ�������Ϊ0��
����ζ���Ȱ�ջ��Ԫ�ص���֮������ٰ�ջ��Ԫ��ѹ������γɸ�С���ַ�������bcabc�������ַ�aʱ����a��ascll��cС��
����c���ַ��ں��滹�У�c��������Ϊ0��������ζ���Ȱ�c������aѹ�룬֮����ѹ��c���Եõ���С���ַ�������
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
