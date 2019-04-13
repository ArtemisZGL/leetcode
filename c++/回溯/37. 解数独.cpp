
/*
��дһ������ͨ�������Ŀո�������������⡣

һ�������Ľⷨ����ѭ���¹���

���� 1-9 ��ÿһ��ֻ�ܳ���һ�Ρ�
���� 1-9 ��ÿһ��ֻ�ܳ���һ�Ρ�
���� 1-9 ��ÿһ���Դ�ʵ�߷ָ��� 3x3 ����ֻ�ܳ���һ�Ρ�
�հ׸��� '.' ��ʾ��
*/ 

class Solution {
public:
    //��־�ڼ������ĸ������Ѿ�����
    map<pair<int,char>, bool> rowUse;
    map<pair<int,char>, bool> colUse;
    map<pair<int,char>, bool> cubeUse;
    
    bool btsearch(int i, int j, vector<vector<char>>& board)
    {
        //ע������ҪС��9
        while(i < 9 && board[i][j] != '.')
        {
            //���еļ�
            i = (j == 8) ? i + 1: i;
            j = (j == 8) ? 0: j+ 1;
        }
        
        //�˳�����
        if(i == 9)
            return true;
        
        
        
        for(int kk = 1; kk < 10; kk++)
        {
            char k = kk + '0';
            //cout << "a";
            //���������������ż�����������

            if(rowUse[pair<int,int>(i, k)] == false && colUse[pair<int,int>(j, k)] == false
               && cubeUse[pair<int,int>(getCubeNum(i,j), k)] == false)
            {
                //cout << i << " " << j << " " << kk << endl;
                //cout << "b";
                board[i][j] = k;
                rowUse[pair<int,int>(i, k)] = true;
                colUse[pair<int,int>(j, k)] = true;
                cubeUse[pair<int,int>(getCubeNum(i,j), k)] = true;
                
                //��������
                if(btsearch(i, j, board))
                    return true;
                
                //���غ��������
                
                board[i][j] = '.';
                rowUse[pair<int,int>(i, k)] = false;
                colUse[pair<int,int>(j, k)] = false;
                cubeUse[pair<int,int>(getCubeNum(i,j), k)] = false;     
            }
            
        }
        //�޽�
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        //��ʼ��
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
