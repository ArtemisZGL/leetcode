class Solution {
public:
    class Letter
    {
        public:
            Letter(char letter)
            {
                this->letter = letter;        
            }
        
            int start;
            int end;
            char letter;
    };
    
    static bool cmp(Letter fir, Letter sec)
    {
        return fir.start <= sec.start;
    }
    
    
    
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        vector<Letter> interval;    //会被初始化为0
        map<char, bool> hasOccur;
        
        for(int i = 0; i < S.length(); i++)
        {
            if(!hasOccur[S[i]])
            {
                Letter letter(S[i]);
                letter.start = i;   //起始
                letter.end = i;
                hasOccur[S[i]] = true;
                interval.push_back(letter);
            }
            else
            {
                int index = -1;
                for(int j = 0; j < interval.size(); j++)
                {
                    if(interval[j].letter == S[i])
                    {
                        index = j;
                        break;
                    }
                }
                interval[index].end = i;
            }
            
        }
        
        sort(interval.begin(), interval.end(), cmp);
        
        int realStart = interval[0].start;
        int realEnd = interval[0].end;
        for(int i = 1; i < interval.size(); i++)
        {
            if(interval[i].start > realEnd)
            {
                cout << interval[i].letter << endl;
                ans.push_back(realEnd - realStart + 1);
                realEnd = interval[i].end;
                realStart = interval[i].start;
            }
            else
            {
                if(interval[i].end > realEnd)
                    realEnd = interval[i].end;
            }
        }
        ans.push_back(realEnd - realStart + 1);
        return ans;
    }
};
