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
class BSTIterator {
public:
    queue<int>ans;
    void recur( TreeNode* root){
        if(!root)
        return ;
        recur( root->left);
        ans.push(root->val);
        recur( root->right);
    }
    BSTIterator(TreeNode* root) {
        recur(root);
    }

    
    int next() {

        int x=  ans.front();
        ans.pop();
        return x;
    }
    
    bool hasNext() {
        if(!ans.size())
        return false;
        return 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */