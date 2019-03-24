/*
假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。

示例 1:

输入: flowerbed = [1,0,0,0,1], n = 1
输出: True
示例 2:

输入: flowerbed = [1,0,0,0,1], n = 2
输出: False
注意:

数组内已种好的花不会违反种植规则。
输入的数组长度范围为 [1, 20000]。
n 是非负整数，且不会超过输入数组的大小。
*/ 

/*
贪心，找到位置就种 
*/ 

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size(); i++)
        {
            if(flowerbed[i] == 1)   //找到第一个没种花的对他前面和后面进行判断
                continue;
            
            int pre = 0, next = 0;
            if(i == 0)  //如果是第一个则认为前面没种
                pre = 0;
            else
                pre = flowerbed[i-1];
            
            if(i == flowerbed.size() - 1)   //如果是最后一个也认为没种
                next = 0;
            else
                next = flowerbed[i+1];
            
            if(next == 0 && pre == 0)
            {
                flowerbed[i] = 1; //记得更新数组
                n--;
            }
        }
        return n <= 0;  //<= 因为可能能种的比要求多
    }
};
