/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
*/ 
/*
我感觉是没用到回溯的，就有点dfs的感觉
对于每个数字，对他每个对应的字母都append一次，然后递归append下个数字对应的字母

在这里的递归中，我们不一定要将递归的结果通过返回值来显示，可以直接传递一个ans的数组，满足条件就加入ans，并结束递归 
*/ 

class Solution {
public:
    string key[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void dfsString(string pre, vector<string>& ans, string str)
    {
    	//长度已经够了 
        if(pre.length() == str.length())
        {
            ans.push_back(pre);
            return;
        }
        
        //现在轮到哪个数字 
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
