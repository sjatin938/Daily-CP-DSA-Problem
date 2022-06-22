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
  TreeNode *first = NULL, *second = NULL;
TreeNode *p = new TreeNode(INT32_MIN);

void inorder(TreeNode *root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);
    if (first == NULL && p->val > root->val) {
        first = p;
    }
    if (first && p->val > root->val) {
        second = root;
    }
    p = root;
    inorder(root->right);
}

void recoverTree(TreeNode *root) {


    if (root == nullptr) {
        return;
    }
    inorder(root);
    swap(first->val, second->val);

}
};