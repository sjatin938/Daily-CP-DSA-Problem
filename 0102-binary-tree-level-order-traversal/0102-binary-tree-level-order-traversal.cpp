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
    int height(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
   return  max(height(root->left), height(root->right)) + 1;
}
   void levelOrder(TreeNode *root, vector<vector<int>> &ans, int &level, int start) {

    if (root == NULL || level < start) {
        return;
    }
    if (level == start && root != NULL) {
        ans[level].push_back(root->val);
    }
    levelOrder(root->left, ans, level, start + 1);
    levelOrder(root->right, ans, level, start + 1);
}

vector<vector<int>> levelOrder(TreeNode *root) {
    if(root == NULL)
        return {};
    int depth = height(root);
    vector<vector<int>> ans(depth, vector<int>());
    for (int i = 0; i < depth; i++) {
        levelOrder(root, ans, i, 0);
    }
    return ans;
}
};