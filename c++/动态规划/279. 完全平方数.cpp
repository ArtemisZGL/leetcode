/*
�������� n���ҵ����ɸ���ȫƽ���������� 1, 4, 9, 16, ...��ʹ�����ǵĺ͵��� n������Ҫ����ɺ͵���ȫƽ�����ĸ������١�

ʾ�� 1:

����: n = 12
���: 3 
����: 12 = 4 + 4 + 4.
ʾ�� 2:

����: n = 13
���: 2
����: 13 = 4 + 9.
*/ 

/*
��̬�滮������״̬D(i)Ϊ���ٵ�ƽ����
״̬ת�Ʒ��̣�D(i)=min(D(i-j) + 1)��jΪ����ƽ������С
��ʼ�����Խ�����D����ʼ��Ϊi�����ֽ�Ϊi��1
*/
class Solution {
public:
    vector<int> getSquares(int n)
    {
        vector<int> squares;
        int num = 1;
        int diff = 3;
        while(num <= n)
        {
            squares.push_back(num);
            num = diff + num;
            diff += 2;
        }
        return squares;
    }
    
    int numSquares(int n) {
        if(n == 0)
            return 0;
        vector<int> D(n+1, numeric_limits<int>::max());
        D[0] = 0;
        D[1] = 1;
        vector<int> squares = getSquares(n);
        
        for(int i = 1; i < n+1; i++)
        {
            for(int j = 0; j < squares.size(); j++)
            {
                if(i - squares[j] < 0)
                    break;
                D[i] = min(D[i], D[i - squares[j]] + 1);
            }
            //cout << D[i] << endl;
        }
        return D[n];
    }
};
