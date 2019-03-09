/*
������漰һ����������⣺����������Ӿ����ǵ��͵Ķ�̬�滮���⡣

? ? ? ? ����Ӧ�ÿ���μ����Ĺ��̣���������Ҫ˼·���ǣ����ھ����е�ÿһ���㣬�����������������߶ȳ��Ըø߶������������ȣ���ʵ��������ÿ������ĵ������������һ���ǶԵģ�����Ҫ�������룬��ʹ��һ�����ϵ������������������߶�������Ŀ�ȵ������������ͬһ���У�������������������ض��и߶�û����ô�ߵĵ㣬������Щ�����棬�ض���һ�������øղŵ�������ڣ����Կ�������ղ���һ����������������Ľ���������ȷ�ģ�

? ? ? ? �����˻���ԭ��֮�����ǿ����µݹ�ԭ��

? ? ? ? �������߶Ⱥܺ���⣬����õ�Ϊ0����ô�õ�����߶�Ϊ0�������0����Ϊ��һ�����߶ȼ�1����

max_height[j] = max_height[j] + 1
?????????�������/�Ҷ˵㣬����ֻ��Ҫ��һ��������¼���иõ����/�ұ߽缴�ɣ����ǻ�Ҫ���������߶��µ�������죬���Ի�Ҫȡ��һ�иõ�߽�Ľϴ�/Сֵ�������õ�Ϊ0�����ñ߽�ֵ������õ����/�ұ߽磬����ȡ����ֵ��? ??????????? ?

while j >= 0:
                if matrix[i][j] == "1":
                    max_right[j] = min(max_right[j], right_border)
                else:
                    right_border = j - 1
                    max_right[j] = n - 1
                j = j - 1
? ? ? ? ?�������ͱȽϼ��ˣ�������������ɡ�


--------------------- 
���ߣ�����ͮ 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/weixin_37743125/article/details/80055323 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�

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
                    leftBorder[j] = 0;  //����Ϊ0����Ϊ����һ���жϵ�ʱ����Ҫѡ���
                    left = j + 1;   //��ǰ�е���߽��������ڵ���һ��
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
