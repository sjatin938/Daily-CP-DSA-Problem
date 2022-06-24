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
   int minNo = INT32_MAX;
int p = INT32_MAX;

int minDiffInBST(TreeNode *root) {

    if (root == NULL)
        return 0;

    minDiffInBST(root->left);

    int diff = abs(root->val - p);
    minNo = min(minNo, diff);
    p = root->val;

    minDiffInBST(root->right);

    return minNo;
}
};