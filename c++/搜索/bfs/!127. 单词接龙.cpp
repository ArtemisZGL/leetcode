/*
�����������ʣ�beginWord �� endWord����һ���ֵ䣬�ҵ��� beginWord �� endWord �����ת�����еĳ��ȡ�ת������ѭ���¹���

ÿ��ת��ֻ�ܸı�һ����ĸ��
ת�������е��м䵥�ʱ������ֵ��еĵ��ʡ�
˵��:

���������������ת�����У����� 0��
���е��ʾ�����ͬ�ĳ��ȡ�
���е���ֻ��Сд��ĸ��ɡ�
�ֵ��в������ظ��ĵ��ʡ�
����Լ��� beginWord �� endWord �Ƿǿյģ��Ҷ��߲���ͬ��
ʾ�� 1:

����:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

���: 5

����: һ�����ת�������� "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     �������ĳ��� 5��
ʾ�� 2:

����:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

���: 0

����: endWord "cog" �����ֵ��У������޷�����ת����
*/ 


/*
�����������������bfs������̫���ˣ��ڼ��ı�һ����ĸ�Ƿ����ֵ���ʱ������ֱ�ӽ�����������ʱ
ͨ������һ�� unordered_set��hash����в��Ҿͻ��ܶ� 
*/ 
class Solution {
public:
    //����ÿ���ʶ�Ӧ�ı�һ�����ʺ����ֵ��е����д�
     map<string, vector<string>> isConnected(vector<string>& wordList)
    {
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        map<string, vector<string>> connected;
         
         //�����б��е�ÿ����
        for(int i = 0; i < wordList.size(); i++)
        {
            //���ڴʵ�ÿ����ĸ
            for(int j = 0; j < wordList[i].length(); j++)
            {
                //����a-zÿ����ĸ
                for(int k = 0; k < 26; k++)
                {
                    string temp = wordList[i];
                    //��ԭ����ͬ�ľ�����
                    if(temp[j] == k + 'a')
                        continue;
                    temp[j] = k + 'a';
                   
                    //�滻���Ƿ���list��
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
            //ÿ�����ж��������дʶ�Ҫ�����ж�
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
