/*
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output:
"apple"

��Ŀ������ɾ�� s �е�һЩ�ַ���ʹ���������ַ����б� d �е�һ���ַ�����
�ҳ��ܹ��ɵ���ַ���������ж����ͬ���ȵĽ���������ֵ������С�ַ�����

�Ƚϱ����ķ����� ��d�б����������ж��䳤���Ƿ���Ѿ��ҵ��ĳ�
����ǣ��ͽ�����֤����֤�ķ�������˫ָ�룬��ͬ������һ����ǰ����ͬ��s����ǰ����������d��ָ���Ƿ�
�ߵ���β 
������ǣ���ֱ������ 

*/ 

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        for(int i = 0; i < d.size(); i++)
        {
            string temp = d[i];
            if(temp.length() < ans.length() || (temp.length() == ans.length() && temp.compare(ans) >= 0))
                continue;
            if(isValid(s, temp))
                ans = temp;
        }
        return ans;
    }
    
    bool isValid(string str, string target)
    {
        int pre = 0, post = 0;
        while(pre < str.length() && post < target.length())
        {
            if(str[pre] == target[post])
            {
                pre++;
                post++;
            }
            else
            {
                pre++;
            }
        }
        return post >= target.length();
    }
};
