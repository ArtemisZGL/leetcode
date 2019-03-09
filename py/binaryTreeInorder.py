# Definition for a binary tree node.
import pdb

class TreeNode:
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

class Solution:
	def inorderTraversal(self, root):
		"""
		:type root: TreeNode
		:rtype: List[int]
		"""

		"""
		'''recursion version'''
		res = []
		if root == None:
			return res
		res.extend(self.inorderTraversal(root.left))
		res.append(root.val)
		res.extend(self.inorderTraversal(root.right))
		return res
		"""

		'''
		nonrecursion version
		use stack to store the left, when left is none, pop the stack and visit it and start again from its right
		'''
		res = []
		stack = []
		p = root
		while p != None or len(stack) != 0:
			while p != None:
				stack.append(p)
				p = p.left
			if len(stack) != 0:
				p = stack.pop()
				res.append(p.val)
				p = p.right
		return res	

test = Solution()
first = TreeNode(1)
second = TreeNode(2)
third = TreeNode(3)
first.left = None
first.right = second
second.left = third
print(test.inorderTraversal(first))
a = raw_input()

