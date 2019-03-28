/*
����һ��ֻ����Сд��ĸ����������letters ��һ��Ŀ����ĸ target��Ѱ���������������Ŀ����ĸ�����С��ĸ��

��������ĸ��˳����ѭ���ġ��ٸ����ӣ����Ŀ����ĸtarget = 'z' ������������Ϊ letters = ['a', 'b']����𰸷��� 'a'��

ʾ��:

����:
letters = ["c", "f", "j"]
target = "a"
���: "c"

����:
letters = ["c", "f", "j"]
target = "c"
���: "f"

����:
letters = ["c", "f", "j"]
target = "d"
���: "f"

����:
letters = ["c", "f", "j"]
target = "g"
���: "j"

����:
letters = ["c", "f", "j"]
target = "j"
���: "c"

����:
letters = ["c", "f", "j"]
target = "k"
���: "c"
*/


class Solution {
public:
    /*
    *   �ҵ�һ����keyֵ���
    *   �ȿ������ǲ��Ǳ�key�󣬷���ֱ�ӷ���,����������Ŀ��ѭ���ģ�����û�б�key��ģ��ͽ�key��Ϊ��
    *   ��������С�Ļ�ҪС�Ľ�������
    *   < key begin = med + 1
    *   > key end = med - 1
    *   ����Ҫ�ҵ�һ����key��� > key�� end = end - 1,����Ҫ�ҵ�һ����������������ǰ��Ȼ��beginָ�ľ��Ƿ��������ĵ�һ��
    *   ����end����Զָ��������Ҫ��ǰһ����begin��ָ��������Ҫ��
    */
    char nextGreatestLetter(vector<char>& letters, char target) {
        int begin = 0, end = letters.size() - 1;
        if(letters[end] <= target)
            target = letters[begin] - 1;
        
        while(begin <= end)
        {
            int med = begin + (end - begin) / 2;
            
            if(letters[med] > target)
                end = med - 1;
            else
                begin = med + 1;
            
        }
        
        return letters[begin];
    }
};
