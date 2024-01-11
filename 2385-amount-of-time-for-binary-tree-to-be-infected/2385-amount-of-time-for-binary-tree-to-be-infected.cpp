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
    map<TreeNode*, TreeNode*> mp;
    TreeNode* st;
    void dfs(TreeNode* root, TreeNode* par, int start)
    {
        if(root==NULL) return;
        if(root->val==start) st=root;
        
        mp[root]=par;
        
        if(root==par)
        {
            dfs(root->left, par,start);
            dfs(root->right, par, start);
        }
        else
        {
            dfs(root->left, root, start);
            dfs(root->right, root, start);
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        dfs(root, root, start);
        
        queue<TreeNode*> q;
        q.push(st);
        int c=-1;
        
        map<TreeNode*, int> visit;
        
        while(!q.empty())
        {
            int z = q.size();
            while(z--)
            {
                TreeNode* node=q.front();
                q.pop();
                
                // cout<<node->val<<" ";
                
                visit[node]=1;
                
                if(node->left && visit[node->left]==0) q.push(node->left);
                if(node->right && visit[node->right]==0) q.push(node->right);
                if(visit[mp[node]]==0) q.push(mp[node]);
            }
            c++;
        }
        
        return c;
    }
};