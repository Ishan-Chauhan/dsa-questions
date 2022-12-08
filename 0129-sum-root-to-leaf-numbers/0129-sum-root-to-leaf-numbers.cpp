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
    int sum=0;
    void sol(TreeNode* root, int c)
    {
        if(root==NULL) return ;
        c = 10*c + root->val;
        if(root->left==NULL && root->right==NULL)
        {
            sum += c;
            return;
        }
        sol(root->left,c);
        sol(root->right,c);
    }
    int sumNumbers(TreeNode* root) {
        int c=0;
        sol(root,c);
        return sum;
    }
};