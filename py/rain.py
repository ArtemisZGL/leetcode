class Solution:
	def trap(self, height):
		"""
		:type height: list
		:rtype: str
		"""
		if len(height) <= 2:
			return 0

		maxl = height[0]
		maxr = height[-1]
		i = 1
		j = len(height) - 2
		water = 0
		while(i <= j):
			if maxl < maxr:
				if height[i] >= maxl:
					maxl = height[i]
				else:
					water += maxl - height[i]
				i = i + 1
			else:
				if height[j] >= maxr:
					maxr = height[j]
				else:
					water += maxr - height[j]
				j = j - 1
		return water

test = Solution()
while True:
	num = input()
	inputs = []
	while num >= 0:
		inputs.append(num)
		num = input()
	print(test.trap(inputs))
