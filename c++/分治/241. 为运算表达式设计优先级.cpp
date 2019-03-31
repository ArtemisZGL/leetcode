/*
给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。

示例 1:

输入: "2-1-1"
输出: [0, 2]
解释: 
((2-1)-1) = 0 
(2-(1-1)) = 2
示例 2:

输入: "2*3-4*5"
输出: [-34, -14, -10, -10, 10]
解释: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/ 

/*
分治的思想，每次遇到一个符号，就分成两边进行递归求值，然后merge的时候就根据两边的结果和中间的符号进行计算 
*/
class Solution {
public:
    vector<int> merge(vector<int> leftAns, vector<int> rightAns, char op)
    {
        vector<int> ans;
        for(int i = 0; i < leftAns.size(); i++)
        {
            for(int j = 0; j < rightAns.size(); j++)
            {
                if(op == '+')
                    ans.push_back(leftAns[i] + rightAns[j]);
                else if(op == '-')
                    ans.push_back(leftAns[i] - rightAns[j]);
                else if(op == '*')
                    ans.push_back(leftAns[i] * rightAns[j]);
            }
        }
      
        return ans;
    }
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        
        for(int i = 0; i < input.length(); i++)
        {
            if(input[i] == '+' || input[i] == '-' || input[i] == '*')
            {
                string left = input.substr(0, i);
                string right = input.substr(i+1);
                vector<int> leftAns = diffWaysToCompute(left);
                vector<int> rightAns = diffWaysToCompute(right);
                vector<int> tempAns = merge(leftAns, rightAns, input[i]);
                ans.insert(ans.end(), tempAns.begin(), tempAns.end());
            }
        }
        if(ans.size() == 0)
        {
            ans.push_back(atoi(input.c_str()));
            return ans;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
}; 
