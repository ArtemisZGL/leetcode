/*
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
*/ 
/*
回溯的思想，和dfs有点像，不同在于回溯的时候是一个分支中的visit，但是dfs是整个全局的visit，
即
在访问一个新元素进入新的递归调用时，需要将新元素标记为已经访问，这样才能在继续递归调用时不用重复访问该元素；
但是在递归返回时，需要将元素标记为未访问，因为只需要保证在一个递归链中不同时访问一个元素，可以访问已经访问过但是不在当前递归链中的元素。
（就像我们这题访问每个数字一样）

普通 DFS 主要用在 可达性问题 ，这种问题只需要执行到特点的位置然后返回即可。
而 Backtracking 主要用于求解 排列组合 问题，例如有 { 'a','b','c' } 三个字符，
求解所有由这三个字符排列得到的字符串，这种问题在执行到特定的位置返回之后还会继续执行求解过程。 
（这题也是排列组合问题） 
*/
class Solution {
public:
    int findDot(string str)
    {
        size_t index = str.find(".", index);
        int count = 0;
        while( index != str.npos)
        {
            count++;
            index = str.find(".", index + 1);
            
        }
        
        return count;
    }
    
    void bt(vector<string>& ans, string pre, string s)
    {
        int dotNum = findDot(pre);
        
        //后面又加点了所以不能在后面
        int curIndex = pre.length() - dotNum;
        
        //已经有3个点
        if(dotNum == 3)
        {
            //长度够了
            if(pre.length() == s.length() + 3)
                ans.push_back(pre);
            else
                return;
        }
        else     //否则加点,一开始为空的时候不加
        {
            if(pre != "")
                pre += ".";
        }
        
        //要算上dotNum
        
        
        //最多3位 0-255.检查是否越界
        for(int i = 1; i <= min(3, (int)(s.length() - curIndex)); i++)
        {
            //先去出来看是不是大于255
            string temp = s.substr(curIndex, i);
            if(atoi(temp.c_str()) > 255)
                break;
            
            //不能有前置零
            if(temp.length() != 1 && temp[0] == '0')
                break;
            
            //这里不能直接用pre，否则会影响下一个
            string tempPre = pre + temp;
            //pre += temp;
            bt(ans, tempPre, s);
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        bt(ans, "", s);
        return ans;
    }
};
