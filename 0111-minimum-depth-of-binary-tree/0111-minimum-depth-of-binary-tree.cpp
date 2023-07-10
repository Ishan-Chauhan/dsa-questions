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
    int fun(TreeNode* root)
    {
        if(!root) return 1e9;
        if(!root->left && !root->right) return 1;
        
        return 1+min(fun(root->left),fun(root->right));
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return fun(root);
    }
};