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
int maxPathSum(TreeNode *root, int &maxSum) {
    if (root == NULL)
        return 0;
    int l = max(0 ,maxPathSum(root->left, maxSum));
    int r = max (maxPathSum(root->right, maxSum),0);
    maxSum = max(maxSum, root->val + l + r);
    return root->val + max(l, r);
}

int maxPathSum(TreeNode *root) {
    if (root == NULL)
        return 0;
    int maxSum = INT32_MIN;
     maxPathSum(root, maxSum);
     return maxSum;
}
};