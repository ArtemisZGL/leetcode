/*
�ѡ�����⣺n���������ѡ�����Ǿ�����ͬ����Դ�������ڲ�ͬ��ʱ�䴰[x,y)������Ҫ�����ķ�������
��̰���㷨����̬�滮��������
	�ѻ��ĳ�ַ�ʽ����Ȼ��˳��Ի����ѡȡ���Ƿ��ܱ�֤���ţ����ҷ������Ҳ�������֤������֤����
		����ʽ����ʼʱ�䣬����ʱ�䣬�ʱ�䳤�ȣ����������ͻ����������ʱ������Ȼ��ѡȡ�����ŵģ�
			֤������֤���������һ�����Ž⣨��Ψһ����̰�Ľ⣬��ǰr���ѡ����һ���ģ���r+1��ѡ��һ����Ȼ������̰���㷨��ѡ������ģ����Ҽ��ݣ����԰����Ž�ĵ�r+1�������̰�Ľ�ĵ�r+1��
			������֮�󲻻�Ӱ�����Ž�ķ�����������������������ȥ����֤��̰�Ľ������Ž��һ��

��Ȩ�ѡ�����⣺ÿ����Ǵ�Ȩ�ģ�����ѡ�񷽰�ҪȨ�����ġ���������̰�ģ��ö�̬�滮��
*/


/*
limitsͷ�ļ��÷� 
#include <limits> 
numeric_limits<T>::min() numeric_limits<T>::max()
*/ 


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval fir, Interval sec)
    {
        if(fir.end <= sec.end)
            return true;    //����true����ǰ��
        else
            return false;
    }
    
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0;
        int currentEnd = numeric_limits<int>::min() ; 
        for(int i = 0; i < intervals.size(); i++)
        {
            if(intervals[i].start >= currentEnd)
            {
                currentEnd = intervals[i].end;
                count++;
            }
        }
        return intervals.size() - count;
    }
    
    
}; 
