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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> v;
    if (root == NULL)
        return v;

    queue<TreeNode *> q;
    q.push(root);
    
    bool flag = 0;
    while (!q.empty()) {
        int n = q.size();
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            auto x = q.front();
            q.pop();
            temp.push_back(x->val);
            if (x->left)
                q.push(x->left);
            if (x->right)
                q.push(x->right);
        }
        if (flag == 1)
            reverse(temp.begin(), temp.end());

        v.push_back(temp);
        flag = !flag;
    }

    return v;

}
};