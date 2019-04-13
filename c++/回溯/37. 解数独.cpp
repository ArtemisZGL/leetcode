
/*
编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。
*/ 

class Solution {
public:
    //标志第几行中哪个数字已经用了
    map<pair<int,char>, bool> rowUse;
    map<pair<int,char>, bool> colUse;
    map<pair<int,char>, bool> cubeUse;
    
    bool btsearch(int i, int j, vector<vector<char>>& board)
    {
        //注意行数要小于9
        while(i < 9 && board[i][j] != '.')
        {
            //逐行的加
            i = (j == 8) ? i + 1: i;
            j = (j == 8) ? 0: j+ 1;
        }
        
        //退出条件
        if(i == 9)
            return true;
        
        
        
        for(int kk = 1; kk < 10; kk++)
        {
            char k = kk + '0';
            //cout << "a";
            //三个都满足条件才继续往下搜索

            if(rowUse[pair<int,int>(i, k)] == false && colUse[pair<int,int>(j, k)] == false
               && cubeUse[pair<int,int>(getCubeNum(i,j), k)] == false)
            {
                //cout << i << " " << j << " " << kk << endl;
                //cout << "b";
                board[i][j] = k;
                rowUse[pair<int,int>(i, k)] = true;
                colUse[pair<int,int>(j, k)] = true;
                cubeUse[pair<int,int>(getCubeNum(i,j), k)] = true;
                
                //结束条件
                if(btsearch(i, j, board))
                    return true;
                
                //返回后继续搜索
                
                board[i][j] = '.';
                rowUse[pair<int,int>(i, k)] = false;
                colUse[pair<int,int>(j, k)] = false;
                cubeUse[pair<int,int>(getCubeNum(i,j), k)] = false;     
            }
            
        }
        //无解
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        //初始化
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] != '.')
                {
                    rowUse[pair<int,int>(i, board[i][j])] = true;
                    colUse[pair<int,int>(j, board[i][j])] = true;
                    cubeUse[pair<int,int>(getCubeNum(i,j), board[i][j])] = true;
                    
                }
                
            }
        }
        cout << btsearch(0,0, board);
    }
    
    int getCubeNum(int i,int j)
    {
        int r = i / 3;
        int c = j / 3;
        return r * 3 + c;
    }
};
