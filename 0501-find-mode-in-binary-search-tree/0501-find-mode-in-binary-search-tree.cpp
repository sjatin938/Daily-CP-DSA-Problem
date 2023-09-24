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
    
void helper(TreeNode *root, unordered_map<int, int> &mp, vector<int> &ans) {

    if (root == NULL)
        return;
    if (mp.find(root->val) != mp.end())
        mp[root->val]++;
    else {
        mp[root->val] = 1;
    }
    helper(root->left, mp, ans);
    helper(root->right, mp, ans);


}

vector<int> findMode(TreeNode *root) {
    if (root == NULL)
        return {};

    vector<int> ans;

    unordered_map<int, int> mp;
    helper(root, mp, ans);
    int count = 0;

  for (auto &x: mp) {
        if (count == x.second) {
            ans.push_back(x.first);
        } else if (count < x.second) {
            ans.clear();
            ans.push_back(x.first);
            count = x.second;
        }
    }
    return ans;

}
};