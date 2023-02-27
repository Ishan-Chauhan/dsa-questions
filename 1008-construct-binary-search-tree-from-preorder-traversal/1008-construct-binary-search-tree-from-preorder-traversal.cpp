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
    TreeNode* sol(vector<int>& v)
    {
        TreeNode* root = new TreeNode(v[0]);
        vector<int> l,r;
        for(int i=1;i<v.size();i++)
        {
            if(v[i]<root->val) l.push_back(v[i]);
            else r.push_back(v[i]);
        }
        if(l.size()) root->left = sol(l);
        if(r.size()) root->right = sol(r);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return sol(preorder);
    }
};