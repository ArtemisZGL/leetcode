/*
�����ַ��� s �� t ���ж� s �Ƿ�Ϊ t �������С�

�������Ϊ s �� t �н�����Ӣ��Сд��ĸ���ַ��� t ���ܻ�ܳ������� ~= 500,000������ s �Ǹ����ַ��������� <=100����

�ַ�����һ����������ԭʼ�ַ���ɾ��һЩ��Ҳ���Բ�ɾ�����ַ������ı�ʣ���ַ����λ���γɵ����ַ����������磬"ace"��"abcde"��һ�������У���"aec"���ǣ���

ʾ�� 1:
s = "abc", t = "ahbgdc"

���� true.

ʾ�� 2:
s = "axc", t = "ahbgdc"

���� false.

������ս :

����д�������� S������S1, S2, ... , Sk ���� k >= 10�ڣ�����Ҫ���μ�������Ƿ�Ϊ T �������С�����������£���������ı���룿

*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*
         *   ��򵥾���ֱ����˫ָ��ķ�������
         */
        
        /*
         *   ̰���а�����������ѡȡ����ÿ����ĸ�Ŀ�ʼ�������������
         *   Ȼ���ڱ���ƥ����Ӵ����У�Ҫ����һ����������丱����
         *   Ȼ����һ����ĸ�Ľ�������Ҫ����һ������Ľ�������֮�󣬲��޸ĵ�ǰ��ĸ�Ľ���
         *
         *   �������������У���Ϊ����λ�õ�����ɢ�ģ����������ģ�
         *
         *   ����ֻ�ܼ�¼ÿ����ĸ��Ӧ���ֵ�λ�ã�Ȼ�����s���ҵ���Ӧ���������Сλ��
         *   ����Ҫ����һ����ĸ��λ��Ҫ��
         */
        
        
        map<char, bool> occur;
        map<char, vector<int> > letters;
        for(int i = 0; i < t.length(); i++)
        {
            if(occur[t[i]])
               letters[t[i]].push_back(i);
            else
            {
                occur[t[i]] = true;
                letters[t[i]].push_back(i);
            }
                
        }
        
        int preIndex = -1; 
        for(int i = 0; i < s.length(); i++)
        {
            //cout<<s[i] << endl;
            if(!occur[s[i]])
                return false;
            else
            {
                bool satisfy = false;
                for(int j = 0; j < letters[s[i]].size(); j++)
                {
                    if(letters[s[i]][j] > preIndex)
                    {
                        preIndex = letters[s[i]][j];
                        //cout << s[i] << preIndex << " ";
                        satisfy = true;
                        break;
                    }
                    
                }
                if(!satisfy)
                    return false;
            }
        }
        return true;
    }
};
