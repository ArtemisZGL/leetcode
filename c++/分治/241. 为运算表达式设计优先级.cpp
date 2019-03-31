/*
����һ���������ֺ���������ַ�����Ϊ���ʽ������ţ��ı����������ȼ��������ͬ�Ľ��������Ҫ�������п��ܵ���ϵĽ������Ч��������Ű��� +, - �Լ� * ��

ʾ�� 1:

����: "2-1-1"
���: [0, 2]
����: 
((2-1)-1) = 0 
(2-(1-1)) = 2
ʾ�� 2:

����: "2*3-4*5"
���: [-34, -14, -10, -10, 10]
����: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/ 

/*
���ε�˼�룬ÿ������һ�����ţ��ͷֳ����߽��еݹ���ֵ��Ȼ��merge��ʱ��͸������ߵĽ�����м�ķ��Ž��м��� 
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
