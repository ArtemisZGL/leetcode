/*
����һ��������������飬�ҵ���������������еĳ��ȡ�

ʾ��:

����: [10,9,2,5,3,7,101,18]
���: 4 
����: ��������������� [2,3,7,101]�����ĳ����� 4��
*/ 

/*
��һ�ַ�����ת����������������⣬���Ӷ�ΪO(nlogn) + O(n^2)
�Ƚ�ԭ����X��������õ�Y����ôX��Y������������о��������������
����������еĶ�̬�滮�ⷨ��
��D(i,j)ΪXi��Yj�������������
״̬ת�Ʒ��̣������������Xi��Yj���һ��Ԫ�����, D(i,j) = D(i-1, j-1) + 1
�������Ⱦ��Ǵ��������D(i,j) = max(D(i-1,j), D(i, j-1))
��ʼ״̬��D(1, 0)��D(0,1)Ϊ9=0

�������ַ����������Ԫ�ص�ʱ������в�ͨ

�ڶ��ַ�����ֱ�Ӷ�̬�滮,O(n^2)
��D(i)Ϊ�Ե�i��Ԫ��Ϊ��β������������У����ﲻ�ÿ������ǲ���������β���ܻ�Ҫ��һ��Ԫ�ؽ�β�����ȡD���ֵ��
״̬ת�Ʒ��̣��ӵ�i��Ԫ��ǰ���ұ���С��Ԫ��Aj��Ȼ���ҳ���Aj��β�������������D(j)��D(i) = max(D��j��)+1��
�Ҳ�������С�ģ���ֱ����1
��ʼ״̬D(0) = 1

�����ַ�������̬�滮�� O(nlogn)
��tails[i] �洢���ǳ���Ϊ i + 1 ʱ������������е����һ��Ԫ�أ�
�����ڳ������ʱ�������С��Ԫ�أ��������ܱ�֤����ĸ����ǶԵģ�
����һ��Ԫ�� x��
��������� tails �������е�ֵ����ô������ӵ� tails ���棬��ʾ����������г��ȼ� 1��
��� tails[i-1] < x <= tails[i]����ô���� tails[i] = x����������С��(����λ��ʱ�ö��ֲ���)
*/

/*
class Solution {
public:
    vector<vector<int>> D;
    int lengthOfLIS(vector<int>& nums) {
        //�������������
        vector<int> sortNums = nums;
        sort(sortNums.begin(), sortNums.end());
        
        //�ж��������
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        
        //��ʼ��D
        D = vector<vector<int>>(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        D[1][0] = 0;
        D[0][1] = 0;
        
        return LCS(nums, sortNums, nums.size(), sortNums.size());
    }
    
    int LCS(vector<int>& nums, vector<int>& sortNums, int i, int j)
    {
        if(i == 0 || j == 0)
            return 0;
        if(nums[i-1] == sortNums[j-1])
        {
            cout << "a" << endl;
            int pre = D[i-1][j-1] == -1 ? LCS(nums, sortNums, i-1,j-1) : D[i-1][j-1];
            D[i][j] = pre + 1;
        }
        else
        {
            int fir = D[i-1][j] == -1 ? LCS(nums, sortNums, i-1,j) : D[i-1][j];
            int sec = D[i][j-1] == -1 ? LCS(nums, sortNums, i,j-1) : D[i][j-1];
            D[i][j] = max(fir, sec);
        }
        return D[i][j];
    }
};

*/

/*
class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        //�ж��������
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        
        vector<int> D(nums.size(), 0);
        
        for(int i = 0; i < nums.size(); i++)
        {
            int maxx = 1;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                    maxx = max(maxx, D[j] + 1);
            }
            D[i] = maxx;
        }
        sort(D.begin(), D.end());
        return D[nums.size()-1];
    }
};
*/

class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        //�ж��������
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        
        vector<int> tails;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int index = binarySearch(tails, num);
            if(index < tails.size())
                tails[index] = num;
            else
                tails.push_back(num);
        }
        return tails.size();
    }
    
    int binarySearch(vector<int> tails, int x)
    {
        int l = 0, h = tails.size();
        while (l < h) {
            //��ֹ���
            int mid = l + (h - l) / 2;
            if (tails[mid] == x) {
                return mid;
            } else if (tails[mid] > x) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};


