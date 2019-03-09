# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
	def zigzagLevelOrder(self, root):
		"""
		:type root: TreeNode
		:rtype: List[List[int]]
		"""
		if root == None:
			return []
		queue = []
		queue.append(root)
		ans = []
		level = []
		cur_count = 1
		next_count = 0
		left = True
		while len(queue) != 0:
			while cur_count != 0:
				top = queue[0]
				queue.pop(0)
				cur_count = cur_count - 1
				if top.left != None:
					queue.append(top.left)
					next_count = next_count + 1
				if top.right != None:
					queue.append(top.right)
					next_count = next_count + 1
				level.append(top.val)
			if not left:
				level.reverse()
			ans.append(level)
			level = []
			cur_count = next_count
			next_count = 0
			left = not left
		return ans