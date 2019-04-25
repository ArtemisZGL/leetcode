/*
https://blog.csdn.net/patrick_star_cowboy/article/details/73729756
�������⣬�ƶ�������С�ķ�ʽ������Ԫ�ض��ƶ�����λ��
Ϊʲô����λ���أ�
�������ǵ�Ŀ����Ҫ������ֵͨ����һ���߼�һ��������Ԫ�ر��һ��Ŀ��ֵ��ÿ��Ԫ�ص�Ŀ��ֵ�Ĳ������������ǵĲ�
�ȼ������Ŀ��ֵ������Ԫ�ض�ҪС����ʱ�ܲ���������sum��ai - target��
Ȼ�����Ŀ��ֵ��һ����ʱ�������������һ�󻹱�����Ԫ��С����һ���ĳЩԪ��С��ĳЩ��
��һ�󻹱�����Ԫ��С���ܲ���������sum��ai - target - 1�� = sum(ai - target) - N, �ܲ���������N
��һ���ĳЩԪ��С��ĳЩ��
    ��ʱ��Ŀ��ֵ���Ԫ�ص����Ŀ��ֵ�Ĳ�������Ȼ�Ǽ�С��1��
    ���Ǳ�Ŀ��ֵС��Ԫ�����൱��Ҫ����һ�μ�1��������׷��Ŀ��ֵ��Ҳ���Ǳ�ԭ���Ĳ���������1��
    ������ߵ���ΪL�����ұߵ���ΪR����Ŀ��ֵ��1���ٵ��ܲ���������R-L
    ����Ŀ��ֵ��1�Ĳ���ʹ�������ߵ���һ�����ʱ������ܲ��������ٵ�ʱ���ˣ��������λ��

�ܲ���������sum - n * median�����������̫�ԣ���Ϊ�и����Ļ�Ҫȡ����ֵ
*/

/*
Ҫ��ô����λ���أ�һ�ַ���������Ȼ����
��һ�ַ�������Ҫ�õ��ҵ�k������ķ����еĿ��ŵ��뷨��
*/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int medianPos = nums.size() / 2;
        int median = findKMaxNum(medianPos, nums);
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            count += abs(nums[i] - median);
        }
        return count;
    }
    
    int findKMaxNum(int K, vector<int>& nums)
    {
        int l = 0, h = nums.size() - 1;
        while(l < h)
        {
            int k = partition(nums, l, h);
            //cout << k << endl;
            //�ҵ���k�����˳�
            if(k == K)
                break;
            //����ȵ�k��С��ֻҪ���ұ�
            if(k < K) {
                l = k + 1;
            } else {
                h = k - 1;
            }
        }
        return nums[K];
    }
    
    int partition(vector<int>& nums, int l, int h)
    {
        //ѡl���λ�õ�Ϊpivotֵ
        int pivot = nums[l];
        int i = l + 1, j = h;
        while(true)
        {
            //ע��Ҫ���ж���û��Խ��
            while(i <= h && nums[i] < pivot)
                i++;
            while(j >= l+1 && nums[j] > pivot)
                j--;
            
            //i��j����˵���Ѿ�������
            if(j <= i)
                break;
            
            //����
            swap(nums, i, j);
            //������Ҫ�ƶ����������������ȵ�����ͻ���ѭ��
            i++;
            j--;
        }
        //���Ҫ��pivot����������н���
        swap(nums, l, j);
        return j;
    }
    
    void swap(vector<int>& nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
