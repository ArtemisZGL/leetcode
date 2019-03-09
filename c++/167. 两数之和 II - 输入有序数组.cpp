/*
��Ŀ�������������������ҳ���������ʹ���ǵĺ�Ϊ target��

ʹ��˫ָ�룬һ��ָ��ָ��ֵ��С��Ԫ�أ�һ��ָ��ָ��ֵ�ϴ��Ԫ�ء�ָ���СԪ�ص�ָ���ͷ��β������ָ��ϴ�Ԫ�ص�ָ���β��ͷ������

*/ 

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lessP = 0, greatP = numbers.size() - 1;
        
        while(lessP < greatP)
        {
            if(numbers[lessP] + numbers[greatP] < target)
                lessP++;
            else if(numbers[lessP] + numbers[greatP] > target)
                greatP--;
            else
            {
                vector<int> result;
                result.push_back(lessP+1);
                result.push_back(greatP+1);
                return result;
            }
        }
        return vector<int>();
    }
};
