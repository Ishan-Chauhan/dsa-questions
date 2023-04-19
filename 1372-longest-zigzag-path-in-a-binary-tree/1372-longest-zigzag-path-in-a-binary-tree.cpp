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
    void sol(TreeNode* root, int x, int d)
    {
        if(root==NULL) return;
        
        ans = max(ans, d);
        
        sol(root->left, 0, x==0?1:d+1);
        sol(root->right, 1, x==1?1:d+1);
        
    }
    int longestZigZag(TreeNode* root) {
        sol(root,0,0);
        sol(root,1,0);
        return ans;
    }
};