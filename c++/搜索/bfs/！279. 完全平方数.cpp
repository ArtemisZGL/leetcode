#include <iostream>
using namespace std;

/*
��bfs��������������������Ȩ�����·�����⣬Ҳ������һЩ���Կ���ͼ�����Ž����� 

������Կ����Ǵ�n�㵽0������·�����⣬ÿ����Ȼ��n����һ���㣬������֮���б���ζ�Ų�һ��ƽ����
 
*/ 

class Solution {
public:
	//��ȡ��1��n��ƽ���� ����n+1��^2 - n^2=  2n +1,����ÿ��diff+2 
    vector<int> getSquares(int n)
    {
        vector<int> squares;
        int num = 1;
        int diff = 3;
        while(num <= n)	//ע��Ҫ���ڣ���������Ϊƽ������ʱ��ʹ��� 
        {
            squares.push_back(num);
            num = diff + num;
            diff += 2;
        }
        return squares;
    }
    
    //���ɴ�n����㵽0����㣬ÿ��һ��ƽ�������Կ����б�
    int numSquares(int n) {
        vector<int> squares = getSquares(n);
        
        //������Ҫ�����ݽṹ�����ʵ�queue������Ƿ���ʹ���map 
        queue<int> levelSearch;
        levelSearch.push(n);
        map<int, bool> visited;
        visited[n] = true;
        int level = 0;
        
        while(!levelSearch.empty())
        {
            int size = levelSearch.size();
            level++;
            //ÿ��level�Ѷ������һ�Σ�����ͬһ����� 
            for(int i = 0; i < size; i++)
            {
                //��ǰ��
                int cur = levelSearch.front();
                levelSearch.pop();
                for(int j = 0; j < squares.size(); j++)
                {
                    int next = cur - squares[j];
                    //cout << next << " ";
                    if(next == 0)	//ȥ��0�� 
                        return level;
                    //����϶�����С��0
                    else if(next < 0)
                        break;
                    else
                    {
                        if(!visited[next])
                        {
                            visited[next] = true;
                            levelSearch.push(next);
                        }
                    }
                }
                //cout << cur << endl;
            }
        }
        
        return -1;
    }
};
