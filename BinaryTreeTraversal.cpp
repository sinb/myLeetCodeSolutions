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
