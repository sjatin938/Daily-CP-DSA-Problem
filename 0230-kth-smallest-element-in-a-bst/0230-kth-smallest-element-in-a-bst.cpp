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
   int kthSmallest(TreeNode *root, int k) {
    if (!root)
        return -1;
    priority_queue<int> q;
    queue<TreeNode *> r;
    r.push(root);
    while (!r.empty()) {
        TreeNode *temp = r.front();
        r.pop();
        q.push(-(temp->val));
        if (temp->left != NULL)
            r.push(temp->left);
        if (temp->right != NULL)
            r.push(temp->right);
    }
  
    for (int i = 1; i < k; i++) {
        q.pop();
    }
    return -q.top();
}
};