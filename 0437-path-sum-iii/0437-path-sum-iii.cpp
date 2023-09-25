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
    unordered_map<long long, int> mp;
int cunt = 0;

void helper(TreeNode *root, int targetSum, long sum) {
    if (root == NULL)
        return;
    sum =   sum + root->val;
    if (sum == targetSum)
        cunt++;
    if (mp.find(sum - targetSum) != mp.end()) {
        cunt = cunt + mp[sum - targetSum];
    }
    mp[sum]++;
    helper(root->left, targetSum, sum);
    helper(root->right, targetSum, sum);
    mp[sum]--;

}

int pathSum(TreeNode *root, int targetSum) {
    if (root == NULL)
        return 0;
    helper(root, targetSum, 0);
    return cunt;
}
};