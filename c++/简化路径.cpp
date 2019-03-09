#include <stdio.h>
class Solution {
public:
    string simplifyPath(string path) {
        const char* split = "/";
        stack<char*> mstack;
        char* p = (char*)path.c_str();
        char* temp = strtok(p, split);
        while(temp != NULL)
        {
            if(strcmp(temp, "..") == 0)
            {    
                if(!mstack.empty())
                     mstack.pop();
            }
            else if(strcmp(temp, ".")  != 0 && strcmp(temp, "") != 0)
                mstack.push(temp);
            
            temp = strtok(NULL, split);
        }
        
        string ans = "";
        int size =  mstack.size();
        for(int i = 0; i < size; i++)
        {
            ans = mstack.top() + ans;
            ans = "/" + ans;
            mstack.pop();
        }
        if(ans == "")
            ans += "/";
        return ans;
    }
};
