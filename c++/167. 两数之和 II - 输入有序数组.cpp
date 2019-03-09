/*
题目描述：在有序数组中找出两个数，使它们的和为 target。

使用双指针，一个指针指向值较小的元素，一个指针指向值较大的元素。指向较小元素的指针从头向尾遍历，指向较大元素的指针从尾向头遍历。

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
