#include <iostream>
using namespace std;
bool notChar(char c); 
int main()
{
    int T = 0;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int charWidth = 0, maxWidth = 0;
        cin >> charWidth >> maxWidth;
        
        string text = "";
        cin >> text;
        
        int lineCount = 0, currentCount = 0;
        bool impossible = false;
        
        for(int j = 0; j < text.length(); j++)
        {
            char currentChar = text[j];
            
            if( (currentChar >= 'a' && currentChar < 'z') || 
                (currentChar >= 'A' && currentChar < 'Z') )
            {
                if(currentCount + charWidth <= maxWidth)
                {
                    if(notChar(text[j + 1]) && currentCount + 2* charWidth > maxWidth)
                    {
                       lineCount++;
                       j--;
                        if(currentCount == 0)
                        {
                            impossible = true;
                            break;
                        }
                        currentCount = 0;
                    }
                    else
                        currentCount += charWidth;    
                }
                else
                {
                    lineCount++;
                    j--;
                    currentCount = 0;
                }
            }
            else if(notChar(currentCount))
            {
                currentCount += charWidth;
            }
            else
            {
            	
                j++;
                lineCount++;
                currentCount = 0;
            }
           
        }
        if(currentCount != 0)
        	lineCount++;
        if(impossible)
            cout << "impossible";
        else
            cout << lineCount;
        
        if(i != T - 1)
            cout << endl;
    }
}

bool notChar(char c)
{
    return (c == ',' || c == '.' || c == '!' || c == '?');
}
