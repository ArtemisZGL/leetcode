/*
这道题涉及一个经典的问题：求矩阵的最大子矩阵，是典型的动态规划问题。

? ? ? ? 首先应该看如何简化求解的过程，这道题的主要思路就是：对于矩阵中的每一个点，他的最大面积即是最大高度乘以该高度下延伸的最大宽度（其实这样对于每个矩阵的点的最大面积并不一定是对的，但是要这样子想，即使这一个点上的最大面积并不是在最大高度下延伸的宽度的面积。但是在同一行中，如果满足上述条件，必定有高度没有这么高的点，那在这些点里面，必定有一点可以求得刚才的面积存在，所以可以求出刚才那一个点的最大面积，最后的结果因而是正确的）

? ? ? ? 掌握了基本原理之后我们可以下递归原理：

? ? ? ? 首先最大高度很好理解，如果该点为0，那么该点的最大高度为0，如果非0，即为上一行最大高度加1，即

max_height[j] = max_height[j] + 1
?????????其次是左/右端点，我们只需要找一个变量记录本行该点的左/右边界即可，但是还要满足在最大高度下的最大延伸，所以还要取上一行该点边界的较大/小值。故若该点为0，重置边界值，重设该点的左/右边界，否则，取上述值。? ??????????? ?

while j >= 0:
                if matrix[i][j] == "1":
                    max_right[j] = min(max_right[j], right_border)
                else:
                    right_border = j - 1
                    max_right[j] = n - 1
                j = j - 1
? ? ? ? ?接下来就比较简单了，求出最大面积即可。


--------------------- 
作者：马彦彤 
来源：CSDN 
原文：https://blog.csdn.net/weixin_37743125/article/details/80055323 
版权声明：本文为博主原创文章，转载请附上博文链接！

*/ 

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)
            return 0;
        
        int columns = matrix[0].size();
        int leftBorder[columns];
        int rightBorder[columns];
        int maxHeight[columns];
        for(int i = 0; i < columns; i++)
        {
            leftBorder[i] = 0;
            rightBorder[i] = columns - 1;
            maxHeight[i] = 0;
        }
        int maxArea = 0;
        
        
        for(int i = 0; i < rows; i++)
        {
            int left = 0;
            int right = columns - 1;
            
            for(int j = 0; j < columns; j++)
            {
                if(matrix[i][j] == '1')
                {
                    maxHeight[j] += 1;
                    leftBorder[j] = max(leftBorder[j], left);
                }
                else
                {
                    maxHeight[j] = 0;
                    leftBorder[j] = 0;  //重置为0，因为在下一行判断的时候是要选大的
                    left = j + 1;   //当前行的左边界变成了现在的下一个
                }
            }
            for(int j = columns-1; j >=0; j--)
            {
                if(matrix[i][j] == '1')
                {
                    rightBorder[j] = min(rightBorder[j], right);
                }
                else
                {
                    rightBorder[j] = columns - 1;
                    right = j - 1;
                }
            }
            
            for(int j = 0; j < columns; j++)
            {
                int area = (rightBorder[j] - leftBorder[j] + 1) * maxHeight[j];
                if(area > maxArea)
                    maxArea = area;
            }
        }
        return maxArea;
    }
};
