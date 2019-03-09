class Solution:
	def simplifyPath(self, path):
		"""
		:type path: str
		:rtype: str
		"""
		files = path.split('/')
		stack = []
		for file in files:
			if file == '' or file == '.':
				continue
			elif file == '..':
				if len(stack) != 0:
					stack.pop()
			else:
				stack.append(file)
		if len(stack) == 0:
			return '/'
		ans = ''
		while len(stack) != 0:
			ans = '/' + stack.pop() + ans
		return ans