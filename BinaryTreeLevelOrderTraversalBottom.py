# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

#按照级别从底至顶遍历二叉树,比如这个树,
  #  3
  #  / \
  # 9  20
  #     /  \
  #  15   7
#   返回
# [
#   [15,7],
#   [9,20],
#   [3]
# ]
##这个只要先按照从前往后的顺序得到结果最后再逆序一下即可
class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result = []
        self.travel(root, 1, result)
        return result[::-1]

    def travel(self, root, level, result):
        if root == None:
            return
        if level > len(result):
            result.append([])
        result[level-1].append(root.val)
        self.travel(root.left, level+1, result)
        self.travel(root.right, level+1, result)

