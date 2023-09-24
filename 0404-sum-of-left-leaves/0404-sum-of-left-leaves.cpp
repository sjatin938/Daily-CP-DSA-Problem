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
   int ans= 0;
void sumOfLeftLeaves(TreeNode *root, TreeNode *prev) {

    if (root == NULL)
        return;
    if (!root->left && !root->right) {
        if (prev->left == root)
            ans = ans + root->val;
        return;
    }
    sumOfLeftLeaves(root->left, root);
    sumOfLeftLeaves(root->right, root);
}

int sumOfLeftLeaves(TreeNode *root) {
    if (root == NULL)
        return 0;

    TreeNode *prev = NULL;
    sumOfLeftLeaves(root, root);
    return ans;
}
};