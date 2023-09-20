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
    bool flag =1;
    int helper(TreeNode *root) {
    if (root == NULL)
        return 0;
    if (!root->left && !root->right)
        return 1;
    int l = helper(root->left);
    int r = helper(root->right);
    if (abs(l - r) > 1) {
        flag = 0;
        return -1;
    }
    return max(l, r) + 1;
}

bool isBalanced(TreeNode *root) {
    if (!root)
        return 1;
    helper(root);
    return flag;

}
};