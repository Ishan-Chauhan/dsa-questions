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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=INT_MIN, sz, temp=0, lvl=0, curr=0;
        while(!q.empty())
        {
            sz = q.size();
            temp=0;
            while(sz--)
            {
                temp += q.front()->val;
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            curr++;
            if(temp>ans)
            {
                // cout<<temp<<" ";
                ans=temp;
                lvl=curr;
            }
        }
        return lvl;
    }
};