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
 TreeNode *helper(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return root;
    TreeNode *t;
    if (root->val > p->val && root->val > q->val)
        t = lowestCommonAncestor(root->left, p, q);
    else if (root->val > p->val && root->val < q->val)
        return root;
    else if (root->val == p->val || root->val == q->val)
        return root;
    else
        t = lowestCommonAncestor(root->right, p, q);
    return t;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (p->val > q->val)
    {
        TreeNode *temp = p;
        p = q;
        q = temp;
    }
    return helper(root, p, q);
}
};