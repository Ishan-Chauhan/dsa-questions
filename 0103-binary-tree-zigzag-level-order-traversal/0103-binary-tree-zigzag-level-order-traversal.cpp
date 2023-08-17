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
    void sol(TreeNode* root, vector<vector<int>>& res)
    {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size(), i=0;
            vector<int> temp(sz);
            while(sz--)
            {
                TreeNode* x = q.front();
                q.pop();
                temp[i++] = x->val;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            res.push_back(temp);
        }
        
        for(int i=1; i<res.size(); i+=2) reverse(res[i].begin(), res[i].end());
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        
        sol(root, res);
        return res;
    }
};
