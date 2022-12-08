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
    vector<int> v;
    void func(TreeNode *p)
    {
        if (p)
        {
            func(p->left);
            v.push_back(p->val);
            func(p->right);
        }
    }
    bool isValidBST(TreeNode *root)
    {
        TreeNode *p = root;
        func(p);
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] >= v[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};