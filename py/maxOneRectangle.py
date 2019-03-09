class Solution:
	def maximalRectangle(self, matrix):
		"""
		:type matrix: List[List[str]]
		:rtype: int
		"""
		"""
		动态规划，计算出每点的最大面积，如果为1则是前一个高度加一，如果是0就是0
		然后左右两个边界，如果是1，则左边界为当前行边界和上一行该点边界中大的那个，如果为0则当前行左边界为下一个点，该点左边界为0
		右边界则是取小的那个
		"""
		if len(matrix) == 0:
			return 0

		m = len(matrix)
		n = len(matrix[0])
		maxHeight = [0 for i in range(0, n)]
		maxLeft = [0 for i in range(0, n)]
		maxRight = [n - 1 for i in range(0, n)]
		maxArea = 0

		for i in range(0, m):
			left = 0
			right = n - 1

			k = n - 1
			while k >= 0:
				if matrix[i][k] == "1":
					maxRight[k] = min(right, maxRight[k])
				else:
					maxRight[k] = n - 1
					right = k - 1
				k -= 1

			for j in range(0, n):
				if matrix[i][j] == "1":
					maxHeight[j] += 1
					maxLeft[j] = max(left, maxLeft[j])
				else:
					maxHeight[j] = 0
					left = j + 1
					maxLeft[j] = 0

				area = maxHeight[j] * (maxRight[j] - maxLeft[j] + 1)
				if area > maxArea:
					maxArea = area

		return maxArea

test = Solution()
ma = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]