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
    int ans=0;
    void sol(TreeNode* root, int maxi, int mini)
    {
        if(root==NULL) return;
        ans = max(ans, max(abs(root->val-maxi),abs(root->val-mini)));
        if(root->left)
        {  
            sol(root->left, max(root->val,maxi), min(root->val,mini));
        }
        if(root->right)
        {
            sol(root->right, max(root->val,maxi), min(root->val,mini));
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        sol(root, root->val, root->val);
        return ans;
    }
};