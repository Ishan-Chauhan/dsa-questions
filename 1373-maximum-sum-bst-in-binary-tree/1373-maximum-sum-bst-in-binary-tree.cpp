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
class node{
public:
    int sum, isBST, leftmax, rightmin;
    
    node(int a,int b,int c,int d)
    {
        sum=a;
        isBST=b;
        leftmax=c;
        rightmin=d;
    }
};

class Solution {
public:
    
    node* sol(TreeNode* root, int& ans)
    {
        if(root==NULL) return new node(0, 1, INT_MIN, INT_MAX);
        
        node* left = sol(root->left, ans);
        node* right = sol(root->right, ans);
        
        if(left->isBST==1 && right->isBST==1 && root->val>(left->leftmax) &&      root->val<(right->rightmin))
        {
            ans = max(ans, left->sum+right->sum+root->val);
            return new node(left->sum+right->sum+root->val, 1, max(left->leftmax, max(right->leftmax, root->val)), min(right->rightmin,min(left->rightmin, root->val)));
        }
        
        return new node(0,0,0,0);
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        node* temp=sol(root, ans);
        return ans;
    }
};