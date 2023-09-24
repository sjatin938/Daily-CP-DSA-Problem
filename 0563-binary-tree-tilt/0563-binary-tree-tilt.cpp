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
int sum  = 0 ;
int helper(TreeNode *root) {
    if (root == NULL)
        return 0;
    int x = root->val;
    if (root->left == NULL && root->right == NULL) {
        root->val = 0;
        return x;
    }
    int l = helper(root->left);
    int r = helper(root->right);
    root->val = abs(l - r);
    sum =sum+root->val;
    return l + r + x;
}

int findTilt(TreeNode *root) {
    if (root == NULL)
        return 0;
    helper(root);
   return sum;
}
};