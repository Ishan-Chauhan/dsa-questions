/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* insert(TreeNode* root,int val)
    {
        TreeNode* p= new TreeNode;
        if(root==NULL)
        {
            TreeNode* p= new TreeNode;
            p->val=val;
            root=p;
            return root;
        }
        else if(root->val>val)
            root->left=insert(root->left,val);
        else
            root->right=insert(root->right,val);
        return root;
    }
    TreeNode* func(vector<int>& v,int a,int b,TreeNode* root)
    {
        if(b<a)
            return root;
        int mid=(a+b)/2;
        root=insert(root,v[mid]);
        func(v,a,mid-1,root);
        func(v,mid+1,b,root);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root=NULL;
        vector<int> v;
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        root=func(v,0,v.size()-1,root);
        return root;
    }
};