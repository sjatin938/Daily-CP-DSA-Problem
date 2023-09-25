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
    int maxStep=0;
    void helper(TreeNode *root, int step, bool isRight) {
    if (root == nullptr) return;

    maxStep = max(maxStep, step);

    if (isRight) {// if coming from right go left
        helper(root->left, step + 1, false);
        helper(root->right, 1, true);//try again from start
    } else {// else coming from left then go right
        helper(root->right, step + 1, true);
        helper(root->left, 1, false);
    }
}

int longestZigZag(TreeNode *root) {
    if (!root)
        return 0;
    helper(root->right, 1, true);
    helper(root->left, 1, false);
    return maxStep;
}
};