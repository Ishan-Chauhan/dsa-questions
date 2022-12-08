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
    void sol(TreeNode* root, vector<int>& a)
    {
        if(root==NULL) return;
        if(root->left) sol(root->left,a);
        if(root->left==NULL && root->right==NULL)
        {
            a.push_back(root->val);
            return;
        }
        if(root->right) sol(root->right,a);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b;
        sol(root1,a);
        sol(root2,b);
        return a==b;
    }
};