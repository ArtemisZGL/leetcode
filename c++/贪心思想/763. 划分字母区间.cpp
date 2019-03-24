/*
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

示例 1:

输入: S = "ababcbacadefegdehijhklij"
输出: [9,7,8]
解释:
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
注意:

S的长度在[1, 500]之间。
S只包含小写字母'a'到'z'。
*/ 

/*
一开始的想法是像找不重叠区间那样，先对结束时间进行排序，然后每次选与前一个结束时间不重叠的，并改变开始时间
但是这样做不太行

新的做法是按开始时间进行排序，然后顺序进行判断，如果开始时间比当前区间结束时间早，说明重叠了，就要延长结束时间
如果不是，就可以另开一个新的区间，这样就能把字母区间尽可能多进行划分了 

*/ 

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
