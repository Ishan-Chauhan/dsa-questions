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
    string res;
    void sol(TreeNode* root, string temp)
    {
        if(root==NULL) return;
        temp.push_back(root->val+'a');
        if(root->left==NULL && root->right==NULL)
        {
            reverse(temp.begin(), temp.end());
            if(res.size()==0 || temp<res) res=temp;
            // temp.pop_back();
            // else if
            return;
        }
        if(root->left) sol(root->left, temp);
        if(root->right) sol(root->right, temp);
        
    }
    string smallestFromLeaf(TreeNode* root) {
        string temp;
        sol(root, temp);
        return res;
    }
};