/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == NULL)
        return NULL;

    if (root->val == p->val || root->val == q->val) {
        return root;
    }
    auto x = lowestCommonAncestor(root->left, p, q);
    auto y = lowestCommonAncestor(root->right, p, q);
   
    if (x == NULL && y != NULL)
        return y;
    else if (x != NULL && y == NULL)
        return x;
    if(x!= NULL && y!= NULL)
            return root;
    return NULL;
}
};