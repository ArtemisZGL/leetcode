#include <regex>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mstack;
        
        string token = "";
        regex reg("^\\-?[0-9]*$");
        int i = 0;
        while(i < tokens.size())
        {
            token = tokens[i++];
            if(token != "+" && token != "-" && token != "*" && token != "/")
            {
                
                mstack.push(atoi(token.c_str()));
            }
            else
            {
                
                int fir, sec;
                sec = mstack.top();
                mstack.pop();
                fir = mstack.top();
                mstack.pop();
                
                if(token == "+")
                    mstack.push(fir + sec);
                else if(token == "-")
                    mstack.push(fir - sec);
                else if(token == "*")
                    mstack.push(fir * sec);
                else if(token == "/")
                    mstack.push(fir / sec);
                    
            }
        }
        return mstack.top();
    }
};
