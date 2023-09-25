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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return root;
        if(root->val == p->val || root->val == q->val)
            return root;
        auto y = lowestCommonAncestor(root->left , p , q);
        auto x = lowestCommonAncestor(root->right, p , q);

        if(y && !x)
        return y;
        else if(!y && x)
        return x;
        else if(!x && !y)
        return nullptr;
        else
        return root;
    }
};