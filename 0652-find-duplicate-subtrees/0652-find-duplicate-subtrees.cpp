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
    vector<TreeNode *> ans;
unordered_map<string, int> map;
unordered_map<string, TreeNode *> mp2;

string solve(TreeNode *root) {

    if (root == NULL) {
        return "!";
    }
    string temp = "(";
    temp += to_string(root->val);
    temp += solve(root->left);
    temp += solve(root->right) + ")";
    map[temp]++;
    mp2[temp] = root;
    return temp;
}

vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {

    if (root == NULL) {
        return {};
    }
    solve(root);
    for (auto x: map) {
        if (x.second > 1) {
            TreeNode *t = mp2[x.first];
            ans.push_back(t);
        }
    }
    return ans;

 
    }
};