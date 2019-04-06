/*
����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�

�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��



ʾ��:

���룺"23"
�����["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
˵��:
��������Ĵ��ǰ��ֵ������еģ��������������ѡ��������˳��
*/ 
/*
�Ҹо���û�õ����ݵģ����е�dfs�ĸо�
����ÿ�����֣�����ÿ����Ӧ����ĸ��appendһ�Σ�Ȼ��ݹ�append�¸����ֶ�Ӧ����ĸ

������ĵݹ��У����ǲ�һ��Ҫ���ݹ�Ľ��ͨ������ֵ����ʾ������ֱ�Ӵ���һ��ans�����飬���������ͼ���ans���������ݹ� 
*/ 

class Solution {
public:
    string key[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void dfsString(string pre, vector<string>& ans, string str)
    {
    	//�����Ѿ����� 
        if(pre.length() == str.length())
        {
            ans.push_back(pre);
            return;
        }
        
        //�����ֵ��ĸ����� 
        int curIndex = str[pre.length()] - '0';
        for(int i = 0; i < key[curIndex].length(); i++)
        {
            string temp = pre + key[curIndex][i];
            dfsString(temp, ans, str);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0)
            return ans;
        dfsString("", ans, digits);
        return ans;
    }
};
