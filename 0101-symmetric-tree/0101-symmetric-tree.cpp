/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
bool isSymmetric(TreeNode *q, TreeNode *p) {
    if (p == NULL && q == NULL)
        return 1;
    if (p != NULL && q == NULL)
        return 0;
    if (p == NULL && q != NULL)
        return 0;
    if (p->val != q->val)
        return 0;

    bool f1 = isSymmetric(p->left, q->right);
    bool f2 = isSymmetric(p->right, q->left);
    return f1 & f2;

}

bool isSymmetric(TreeNode *root) {
    if (root == NULL)
        return 1;

    return isSymmetric(root->left, root->right);
}
};