/*
�ڶ�ά�ռ�����������ε����򡣶���ÿ�������ṩ��������ˮƽ�����ϣ�����ֱ���Ŀ�ʼ�ͽ������ꡣ��������ˮƽ�ģ�����y���겢����Ҫ�����ֻҪ֪����ʼ�ͽ�����x������㹻�ˡ���ʼ��������С�ڽ������ꡣƽ����������104������

һ֧������������x��Ӳ�ͬ����ȫ��ֱ�������������x�����һ֧��������һ�������ֱ���Ŀ�ʼ�ͽ�������Ϊ xstart��xend�� ������  xstart �� x �� xend���������ᱻ��������������Ĺ���������û�����ơ� ����һ�������֮�󣬿������޵�ǰ�����������ҵ�ʹ����������ȫ��������������Ĺ�������С������

Example:

����:
[[10,16], [2,8], [1,6], [7,12]]

���:
2

*/

/*
ͬ���������ص������̰�����⣬�Ȱ�����ʱ���������Ȼ��ÿ��ѡ��ʼʱ�������ѡ����ʱ��
�����֮ǰ���Ǹ����Ҫע������Ŀ������⣬��Ϊend�����Ǳ����䣬���Ա����Ǵ��ڣ�����һ��ʼ�Ͳ�������Сֵ��ʼcurrentEnd,�Ȱѵ�һ���Ž�ȥ 

*/ 

class Solution {
public:
    static bool cmp(pair<int,int> fir, pair<int, int> sec)
    {
        return fir.second <= sec.second;
    }
    
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size() == 0)
            return 0;
        
        sort(points.begin(), points.end(), cmp);
        int currentEnd = points[0].second;
        int count = 1;
        for(int i = 1; i < points.size(); i++)
        {
            if(points[i].first > currentEnd)
            {
                count++;
                currentEnd = points[i].second;
            }
        }
        return count;
    }
};
