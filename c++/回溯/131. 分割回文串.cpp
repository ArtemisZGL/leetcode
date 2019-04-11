/*
����һ���ַ��� s���� s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����ǻ��Ĵ���

���� s ���п��ܵķָ����

ʾ��:

����: "aab"
���:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

/*
�ҵ��뷨����ÿ��ֻ�г������֣�begin�����е���ʼλ�ã�i���еĳ��ȣ�Ȼ��ÿ������֮�󣬿�ǰ����ǲ����ǻ��ģ��͵ݹ��к���ģ�
��һ���е���ʼλ����Ҫ�����еĳ��� begin = begin + i��
���ǰ�治�ǻ��ģ���ֱ�Ӳ��ü����к�����
���е���ʼλ��Ϊ����ʱ���˵�����������뵽����� 
*/ 
class Solution {
public:
    void btsearch(vector<vector<string>>& ans, int begin, vector<string> pre, string s)
    {
        if(begin == s.size())
        {
            ans.push_back(pre);
            return;
        }
        
        //ÿ��ֻ�г�2����,i��ʾ�и�ĳ��ȣ������size-begin
        for(int i = 1; i < s.size() - begin + 1; i++)
        {
            string fir = s.substr(begin, i);
            if(isHW(fir))
            {
                vector<string> temp = pre;
                temp.push_back(fir);
                btsearch(ans, begin + i, temp, s);
            }
        }
    }
    
    bool isHW(string s)
    {
        int begin = 0, end = s.size() - 1;
        if(end < begin)
            return false;
        while(begin < end)
        {
            if(s[begin] != s[end])
                return false;
            else
            {
                begin++;
                end--;
            }
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> pre;
        btsearch(ans, 0, pre, s);
        return ans;
    }
};
