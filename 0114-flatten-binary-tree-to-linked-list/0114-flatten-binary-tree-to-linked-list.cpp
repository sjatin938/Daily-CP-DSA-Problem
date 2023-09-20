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
    void flatten(TreeNode *root) {
    if (root == NULL)
        return;

    auto x = root;
    while (x) {
        if (x->left == NULL)
            x = x->right;
        else {
            auto temp = x->left;
            while (temp->right != NULL && temp->right != x)
                temp = temp->right;

            if (temp->right == NULL) {
                temp->right = x;
                x = x->left;
            } else {
                temp->right = x->right;
                x->right = x->left;
                x->left = NULL;
            }
        }
    }
}
};