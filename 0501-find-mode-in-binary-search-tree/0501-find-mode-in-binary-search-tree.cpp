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
   int currFeq = 0, maxFreq = 0, prev_cursor = INT32_MIN;

void helper(TreeNode *root, vector<int> &ans) {
    if (root == NULL)
        return;

    helper(root->left, ans);

    if (root->val != prev_cursor) {
        currFeq = 1;
    } else {
        currFeq++;
    }
    if (currFeq == maxFreq) {
        ans.push_back(root->val);
    } else if (currFeq > maxFreq) {
        ans.clear();
        ans.push_back(root->val);
        maxFreq = currFeq;
    }
    prev_cursor = root->val;
    helper(root->right, ans);
}

vector<int> findMode(TreeNode *root) {
    if (root == NULL)
        return {};

    vector<int> ans;
    helper(root, ans);
    return ans;
}
};