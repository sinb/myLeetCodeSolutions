# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

#按照级别遍历二叉树,比如这个树,
  #  3
  #  / \
  # 9  20
  #     /  \
  #  15   7
#   返回
#   [
#   [3],
#   [9,20],
#   [15,7]
#   ]
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result = []
        self.travel(root, 1, result)
        return result
        
    def travel(self, root, level, result):
        if root == None:
            return
        if level > len(result):
            result.append([])
        result[level-1].append(root.val)
        self.travel(root.left, level+1, result)
        self.travel(root.right, level+1, result)

