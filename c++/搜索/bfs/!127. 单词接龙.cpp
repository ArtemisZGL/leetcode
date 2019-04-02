/*
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。
*/ 


/*
下面这个方法是用了bfs，但是太慢了，在检测改变一个字母是否在字典中时，不能直接进行搜索，超时
通过建立一个 unordered_set的hash表进行查找就会快很多 
*/ 
class Solution {
public:
    //返回每个词对应改变一个单词后还在字典中的所有词
     map<string, vector<string>> isConnected(vector<string>& wordList)
    {
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        map<string, vector<string>> connected;
         
         //对于列表中的每个词
        for(int i = 0; i < wordList.size(); i++)
        {
            //对于词的每个字母
            for(int j = 0; j < wordList[i].length(); j++)
            {
                //对于a-z每个字母
                for(int k = 0; k < 26; k++)
                {
                    string temp = wordList[i];
                    //和原来相同的就跳过
                    if(temp[j] == k + 'a')
                        continue;
                    temp[j] = k + 'a';
                   
                    //替换后看是否还在list中
                    if(word_set.count(temp) != 0)
                    {
                        connected[wordList[i]].push_back(temp);
                         //cout << temp << endl;
                    }
                }
            }
        }
         return connected;
    }
    
    bool inList(vector<string>& wordList, string temp)
    {
        for(int i = 0; i < wordList.size(); i++)
            if(wordList[i] == temp)
                return true;
        
        return false;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(!inList(wordList, beginWord))
            wordList.push_back(beginWord);
        
        map<string, vector<string>> connected = isConnected(wordList);
        
        queue<string> search;
        search.push(beginWord);
        
        map<string, bool> visited;
        visited[beginWord] = true;
        
        int level = 1;
        
        while(!search.empty())
        {
            level++;
            //每层所有队列中所有词都要出队判断
            int size = search.size();
            while(size-- > 0)
            {
                string str = search.front();
                search.pop();
                //cout << connected[str].size() << endl;
                for(int j = 0; j < connected[str].size(); j++)
                {
                  
                    string cur = connected[str][j];
                    //cout << cur << " ";
                    if(cur == endWord)
                        return level;
                    else
                        if(!visited[cur])
                        {
                            search.push(cur);
                            visited[cur] = true;
                        }
                }
                //cout << str << endl;
            }
        }
        return 0;
    }
};
