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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int preStart, int inStart, int inEnd) {
    if (preStart >= preorder.size())
        return NULL;
    if (inStart > inEnd)
        return NULL;

    TreeNode *node = new TreeNode(preorder[preStart]);
    int inIdx = mp[node->val];

    int left = inIdx - inStart;

    node->left = buildTree(preorder, inorder, preStart+1, inStart, inIdx-1);
    node->right = buildTree(preorder, inorder, preStart + left + 1, inIdx+1, inEnd);
    return node;

}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    for (int i = 0; i < n; i++) {
        mp[inorder[i]] = i;
    }

    return buildTree(preorder, inorder, 0, 0, inorder.size() - 1);

}
};