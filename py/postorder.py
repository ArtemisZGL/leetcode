# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
	def postorderTraversal(self, root):
		"""
		:type root: TreeNode
		:rtype: List[int]
		"""

		#recursion version
		'''
		res = []
		if root == None:
			return res
		res.extend(self.postorderTraversal(root.left))
		res.extend(self.postorderTraversal(root.right))
		res.append(root.val)
		return res
        '''

		#nonrecursion version
		res = []
		stack = []
		pre = root
		stack.append(root)
		while len(stack) != 0:
			cur = stack[-1]
			if (cur.right == None and cur.left == None) or (cur.left == pre or cur.right == pre):
				res.append(cur.val)
				stack.pop()
				pre = cur
			else:
				if cur.right != None:
					stack.append(cur.right)
				if cur.left != None:
					stack.append(cur.left)
		return res

test = Solution()
first = TreeNode(1)
second = TreeNode(2)
third = TreeNode(3)
first.left = None
first.right = second
second.left = third
print(test.postorderTraversal(first))
a = raw_input()