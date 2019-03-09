# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
	def preorderTraversal(self, root):
		"""
		:type root: TreeNode
		:rtype: List[int]
		"""
		#recursion version
		'''
		res = []
		if root == None:
			return res
		res.append(root.val)
		res.extend(self.preorderTraversal(root.left))
		res.extend(self.preorderTraversal(root.right))
		return res
		'''

		#nonrecursion version
		res = []
		stack = []
		p = root
		while p != None or len(stack) != 0:
			while p != None:
				res.append(p.val)
				stack.append(p)
				p = p.left
			if len(stack) != 0:
				p = stack.pop().right

		return res