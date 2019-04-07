/*
����һ����ά�����һ�����ʣ��ҳ��õ����Ƿ�����������С�

���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�

ʾ��:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

���� word = "ABCCED", ���� true.
���� word = "SEE", ���� true.
���� word = "ABCB", ���� false.
*/ 

/*
���ݵ�˼����������ϵ����⣬��ͨdfs������ջ��visited���������ǻ�����û����õݹ��visited
��Ϊ���ݵ�ʱ����һ�������ǲ���visit���Σ�����������һ�������ǿ���visit�����Ի�����ʱ��Ҫ��visited�ĳ�false
Ȼ���ÿ����������������������оͷ�����һ������ 
*/ 

class Solution {
public:
    
    map<pair<int,int>, bool> visited;
    pair<int, int> directions[4] = {pair<int, int>(-1,0), pair<int, int>(1,0), pair<int, int>(0, -1), pair<int, int>(0, 1)};
    
    bool btsearch(string word, vector<vector<char>>& board, string curStr, pair<int,int> curPos)
    {
        //�Ѿ��ҵ�
        if(curStr.length() == word.length())
            return true;
        
        //Խ������ǲ�����
        if(curPos.first < 0 || curPos.first > board.size() - 1
           || curPos.second < 0 || curPos.second > board[0].size() - 1
           || board[curPos.first][curPos.second] != word[curStr.length()])
            return false;
        
        curStr += board[curPos.first][curPos.second];
        
        for(int i = 0; i < 4; i++)
        {
            pair<int,int> nextPos(curPos.first + directions[i].first, curPos.second + directions[i].second);
            
            //����������֧û���ʹ�
            if(visited[nextPos]== false)
            {
                visited[nextPos]= true;
                //�������ͽ���
                if(btsearch(word, board, curStr, nextPos))
                    return true;
                //��֧����Ҫ�Ļ���
                visited[nextPos]= false;
            }
        }
        
        //ÿ����֧���Ѳ�������false
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                visited[pair<int,int>(i,j)] = true;
                if(btsearch(word, board, "", pair<int,int>(i,j)))
                    return true;
                //һ����֧��Ҫ�����
                visited[pair<int,int>(i,j)]= false;
            }
        }
        return false;
    }
};
