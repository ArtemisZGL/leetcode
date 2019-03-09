class Solution:
	def largestRectangleArea(self, heights):
		"""
		:type hegihts: List[int]
		:rtype: int
		"""
		"""
		动态规划和最大栈
		把每个直方图的下标存到栈中，当遇到比栈顶大的入栈，比栈顶小的，就开始计算面积，每取一个栈顶元素计算一次，
		宽度为小的下标和该栈顶下标差，高度为栈顶元素的高度
		"""
		stack = []
		maxArea = 0
		n = len(heights)
		if n <= 0:
			return 0
		i = 0
		while i < n:
			if len(stack) == 0 or heights[i] >= heights[stack[-1]]:
				stack.append(i)
				i += 1
			else:
				top = heights[stack.pop()]
				wide = 0
				if len(stack) == 0:
					wide = i
				else:
					wide = i - stack[-1] - 1
				area = top * wide
				print(area)
				if area > maxArea:
					maxArea = area
		while len(stack) != 0:
				top = heights[stack.pop()]
				wide = 0
				if len(stack) == 0:
					wide = i
				else:
					wide = i - stack[-1] - 1
				area = top * wide
				print(area)
				if area > maxArea:
					maxArea = area
		return maxArea

test = Solution()
inputs = [2,1,5,6,2,3]
print(test.largestRectangleArea(inputs))
a = raw_input()