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
    int diff=INT_MAX;
    TreeNode* prev=NULL;
    void sol(TreeNode* root)
    {
        if(root==NULL) return;
        sol(root->left);
        if(prev!=NULL) diff = min(diff, abs(root->val-prev->val));
        prev=root;
        sol(root->right);
        
    }
    int getMinimumDifference(TreeNode* root) {
        sol(root);
        return diff;
    }
};