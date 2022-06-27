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
TreeNode *solve(int preStart, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder)
{
    if (preStart >= preorder.size())
        return NULL;
    if (inStart >= inorder.size() || inEnd < inStart)
        return NULL;

    int inIndex = 0;

    TreeNode *root = new TreeNode(preorder[preStart]);

    inIndex = mp[root->val];

    // This is important! Skip all of the leftNodes in the pre order traversal. (Look at inorder)
    int leftNodes = inIndex - inStart;

    root->left = solve(preStart + 1, inStart, inIndex - 1, preorder, inorder);
    root->right = solve(preStart + leftNodes + 1, inIndex + 1, inEnd, preorder, inorder);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    return solve(0, 0, inorder.size() - 1, preorder, inorder);
}
};