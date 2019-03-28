/*
给定一个只包含小写字母的有序数组letters 和一个目标字母 target，寻找有序数组里面比目标字母大的最小字母。

数组里字母的顺序是循环的。举个例子，如果目标字母target = 'z' 并且有序数组为 letters = ['a', 'b']，则答案返回 'a'。

示例:

输入:
letters = ["c", "f", "j"]
target = "a"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "c"
输出: "f"

输入:
letters = ["c", "f", "j"]
target = "d"
输出: "f"

输入:
letters = ["c", "f", "j"]
target = "g"
输出: "j"

输入:
letters = ["c", "f", "j"]
target = "j"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "k"
输出: "c"
*/


class Solution {
public:
    /*
    *   找第一个比key值大的
    *   先看最大的是不是比key大，否则直接返回,但是这里题目是循环的，所以没有比key大的，就将key设为比
    *   数组中最小的还要小的进行搜索
    *   < key begin = med + 1
    *   > key end = med - 1
    *   由于要找第一个比key大的 > key， end = end - 1,就是要找第一个，符合条件就往前，然后begin指的就是符合条件的第一个
    *   这样end就永远指向我们想要的前一个，begin就指向我们想要的
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
