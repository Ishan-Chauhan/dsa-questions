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
    int succ(TreeNode* root)
    {
        while(root->left!=NULL)
            root=root->left;
        return root->val;
    }
    int pre(TreeNode* root)
    {
        while(root->right!=NULL)
            root=root->right;
        return root->val;
    }
    int getMinimumDifference(TreeNode* root) {
        if(root->left)
        {
            diff=min(diff,abs(root->val-pre(root->left)));
            getMinimumDifference(root->left);
        }
        if(root->right)
        {
            diff=min(diff,abs(root->val-succ(root->right)));
            getMinimumDifference(root->right);
        }
        return diff;
    }
};