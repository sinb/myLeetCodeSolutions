#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
// 中序遍历
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> vec;
        putIntoVecInOrder(vec, root);
        return vec;
    }
    void putIntoVecInOrder(vector<int> &vec,TreeNode* root)
    {
        if (root == NULL)
            return;
        putIntoVecInOrder(vec,root->left);
        vec.push_back(root->val);
        putIntoVecInOrder(vec,root->right);
    }
//先序
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> vec;
        putIntoVecPreOrder(vec, root);
        return vec;
    }
    void putIntoVecPreOrder(vector<int> &vec,TreeNode* root)
    {
        if (root == NULL)
            return;
        vec.push_back(root->val);
        putIntoVecPreOrder(vec,root->left);
        putIntoVecPreOrder(vec,root->right);
    }
//后序
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> vec;
        putIntoVecPostOrder(vec, root);
        return vec;
    }
    void putIntoVecPostOrder(vector<int> &vec,TreeNode* root)
    {
        if (root == NULL)
            return;
        putIntoVecPostOrder(vec,root->left);
        putIntoVecPostOrder(vec,root->right);
        vec.push_back(root->val);
    }
};
// test solution
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main()
{
    TreeNode t1(1);
    TreeNode t2(2);    TreeNode t3(3);    TreeNode t4(4);    TreeNode t5(5);
    t1.left = &t2;  t1.right = &t3;
    t3.left = &t4;
    t4.right = &t5;
//    inorder(&t1);
    Solution s;
    vector<int> vec;
    vec = s.preorderTraversal(&t1);
    for (auto i = vec.begin(); i != vec.end(); i++)
        cout << *i <<" ";

}
/*
# Python program to for tree traversals
 
# A class that represents an individual node in a
# Binary Tree
class Node:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.val = key
 
 
# A function to do inorder tree traversal
def printInorder(root):
 
    if root:
 
        # First recur on left child
        printInorder(root.left)
 
        # then print the data of node
        print(root.val),
 
        # now recur on right child
        printInorder(root.right)
 
 
 
# A function to do postorder tree traversal
def printPostorder(root):
 
    if root:
 
        # First recur on left child
        printPostorder(root.left)
 
        # the recur on right child
        printPostorder(root.right)
 
        # now print the data of node
        print(root.val),
 
 
# A function to do postorder tree traversal
def printPreorder(root):
 
    if root:
 
        # First print the data of node
        print(root.val),
 
        # Then recur on left child
        printPreorder(root.left)
 
        # Finally recur on right child
        printPreorder(root.right)
 
 
# Driver code
root = Node(1)
root.left      = Node(2)
root.right     = Node(3)
root.left.left  = Node(4)
root.left.right  = Node(5)
print "Preorder traversal of binary tree is"
printPreorder(root)
 
print "\nInorder traversal of binary tree is"
printInorder(root)
 
print "\nPostorder traversal of binary tree is"
printPostorder(root)
*/
