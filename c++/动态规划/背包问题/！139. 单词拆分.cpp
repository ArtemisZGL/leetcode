/*
��ȫ������ ��Ŀ���ַ���������һ��������Ȼ���ֵ俴������Ʒ
�������漰���ֵ��е��ʵ�ʹ��˳����˿����Ϊ�漰˳�����ȫ�������⡣

�漰˳�����ȫ����Ҫ��ô�����أ�������Ʒ��ѭ���ŵ��ڲ���ȥ
����״̬d[i]�� ��ʾ��i�������ܷ����
��״̬ת�ƣ���ǰ�����Ƿ���Է���������������Ʒ������j����Ʒ
�����ǰ�����Ѿ�ȷ�����Է�����������ǡ�÷��µ�j����Ʒ�ܹ�����
״̬ת�Ʒ��̣�d[i] = d[i] || d[i-]

��ʼ״̬��d[0] = true, ����Ϊ0�н�
*/

/*
����һ���ǿ��ַ��� s ��һ�������ǿյ����б���ֵ� wordDict���ж� s �Ƿ���Ա��ո���Ϊһ���������ֵ��г��ֵĵ��ʡ�

˵����

���ʱ�����ظ�ʹ���ֵ��еĵ��ʡ�
����Լ����ֵ���û���ظ��ĵ��ʡ�
ʾ�� 1��

����: s = "leetcode", wordDict = ["leet", "code"]
���: true
����: ���� true ��Ϊ "leetcode" ���Ա���ֳ� "leet code"��
*/ 

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.length() == 0)
            return true;
        
        int D[s.length() + 1];
        for(int i = 0; i <= s.length(); i++)
            D[i] = false;
        D[0] = true;
        
        //��ʾ���ַ�����ǰi���ִ������
        for(int i = 1; i <= s.length(); i++)
        {
            //����Ʒ���б���
            for(int j = 0; j < wordDict.size(); j++)
            {
                int len = wordDict[j].length();
                //��Ҫ��֤�Ƿ���ַ���ƥ��
                if(len <= i && wordDict[j] == s.substr(i-len, len))
                    D[i] = D[i] || D[i-wordDict[j].length()];
            }
        }
        
        return D[s.length()];
    }
};
