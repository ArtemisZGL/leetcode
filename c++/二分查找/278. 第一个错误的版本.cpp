/*
���ǲ�Ʒ����Ŀǰ���ڴ���һ���Ŷӿ����µĲ�Ʒ�����ҵ��ǣ���Ĳ�Ʒ�����°汾û��ͨ��������⡣����ÿ���汾���ǻ���֮ǰ�İ汾�����ģ����Դ���İ汾֮������а汾���Ǵ�ġ�

�������� n ���汾 [1, 2, ..., n]�������ҳ�����֮�����а汾����ĵ�һ������İ汾��

�����ͨ������ bool isBadVersion(version) �ӿ����жϰ汾�� version �Ƿ��ڵ�Ԫ�����г���ʵ��һ�����������ҵ�һ������İ汾����Ӧ�þ������ٶԵ��� API �Ĵ�����

ʾ��:

���� n = 5������ version = 4 �ǵ�һ������İ汾��

���� isBadVersion(3) -> false
���� isBadVersion(5) -> true
���� isBadVersion(4) -> true

���ԣ�4 �ǵ�һ������İ汾�� 
*/ 

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

/*
���ֲ��ұ��֣��൱�������ظ����ҵ�һ��key����ʱ���Ҫ��start��ȷ��
*/
class Solution {
public:
    int firstBadVersion(int n) {
        int start = 0, end = n;
        while(start <= end)
        {
            int med = start + (end - start) / 2;
            
            if(isBadVersion(med))
                end = med - 1;
            else
                start = med + 1;
        }
        return start;
    }
};
