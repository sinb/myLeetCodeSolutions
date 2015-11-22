/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 二叉排序树中，寻找两个节点的最低公共祖先
如果两个节点一个比root大，一个比root小，那么root就是LCA
如果两个都比root大，那么LCA可能在root的右面，所以往右查找
如果两个都比root小，那么LCA可能在root的左面，所以往左查找
找到头还没找到跳出循环了，说明没有
 
 */
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root)
        {
            if (p->val > root->val && q->val > root->val)
            {
                root = root->right;
                continue;
            }
            else if (p->val < root->val && q->val < root->val)
            {
                root = root->left;
                continue;
            }
            else 
                return root;
        }
        return NULL;
    }
};
