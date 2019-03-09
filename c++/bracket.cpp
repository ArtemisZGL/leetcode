#include <stack>
class Solution {
public:
    bool isValid(string s) {
        if(s == "")
            return true;
        
        stack<char> myStack;
        
        for(int i = 0; i < s.length(); i++)
        {
            char tempChar = s[i];
            if(tempChar == '(' || tempChar == '[' || tempChar == '{')
            {
                myStack.push(tempChar);
            }
            else
            {
                if(myStack.empty())
                    return false;
                
                char top = myStack.top();
                if( (top == '(' && tempChar == ')') || (top == '[' && tempChar == ']') || 
                    (top == '{' && tempChar == '}') ) 
                    myStack.pop();
                else
                    return false;
            }
        }
        
        return myStack.empty();
    }
};
