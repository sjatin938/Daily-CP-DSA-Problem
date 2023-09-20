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
      unordered_map<int, int> mp;

TreeNode *solve(vector<int> inorder, vector<int> postorder, int inStart, int inEnd, int &idx) {

    if (inStart > inEnd) {
        return NULL;
    }
    // 9, 15, 7, 20, 3
    // 9, 3, 15, 20, 7
    TreeNode *root = new TreeNode(postorder[idx--]);
    int l = mp[root->val];
    root->right = solve(inorder, postorder, l + 1, inEnd, idx );
    root->left = solve(inorder, postorder, inStart, l - 1, idx);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

    if (inorder.size() == 0) {
        return NULL;
    }
    for (int i = 0; i < postorder.size(); i++) {
        mp[inorder[i]] = i;
    
    }
    int n = postorder.size() - 1;
    TreeNode *root = solve(inorder, postorder, 0, inorder.size() - 1, n);
    return root;
}
};