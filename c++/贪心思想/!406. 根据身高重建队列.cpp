/*
�����д���˳���һȺ��վ��һ�����С� ÿ������һ��������(h, k)��ʾ������h������˵���ߣ�k�����������ǰ������ߴ��ڻ����h�������� ��дһ���㷨���ؽ�������С�

ע�⣺
����������1100�ˡ�

ʾ��

����:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

���:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

*/ 


/*
��Ҳ��֪�����㲻��̰�����⣬��������һ������
̰�ĵĶ����ǽ�����ֳ�С���⣬Ȼ��ÿ��С��������Ž������Թ��ɴ���������Ž⣨��һ���У�
һ����������Ȱ�ĳ��������������Ȼ��������Ľ������������ 
*/ 

/*
���������Ҳ���Ȱ�������һ��ʼ�ҵ��뷨�ǰ��߶ȴӵ͵����ţ�Ȼ��Ӱ����߲����¶��У����������Ļ������Ļ�Ӱ��ǰ�����Ľ��

����Ӧ���ǰ��Ӹߵ������������������Ļ��������Ķ��Ǳȶ����а��ģ�����Ӱ�쵽�ڶ���ֵk��λ��
��ô����Ǹ߶���ͬ���أ�Ӧ����kֵС����ǰ�棬��Ϊk�Ķ����Ǵ��ڵ��ڣ����ڵ�Ҳ�㣬������kС�����ţ�
���漴ʹ����ͬh����k����һ��������ǰһ����ͬh�ĺ��棬����Ӱ�쵽����λ�� 
*/ 

/*
ע������insert���÷������õ������÷����ײ������飬���Բ�����β�����븴�ӶȽϸߣ�������������ʧЧ 
single element (1)	
iterator insert (iterator position, const value_type& val);
fill (2)	void insert (iterator position, size_type n, const value_type& val);
range (3)	template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last); 
*/

class Solution {
public:
    static bool cmp(pair<int, int> fir, pair<int, int> sec)
    {
        if(fir.first > sec.first)
            return true;
        else if(fir.first < sec.first)
            return false;
        else
            return fir.second <= sec.second;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), cmp);
        
        vector<pair<int, int> > ans;
        for(int i = 0; i < people.size(); i++)
        {
            vector<pair<int, int> >::iterator it = ans.begin();
            ans.insert(it + people[i].second, people[i]);
        }
        return ans;
    }
};
