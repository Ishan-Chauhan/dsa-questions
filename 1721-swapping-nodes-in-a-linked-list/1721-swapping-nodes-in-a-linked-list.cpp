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
class Solution {
public:
    int len(ListNode* head)
    {
        int c=0;
        while(head!=NULL)
        {
            c++;
            head=head->next;
        }
        return c;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(head->next==NULL)
            return head;
        ListNode* p=head;
        int n=len(p);
        int a,b,c=1;
        while(p!=NULL)
        {
            if(c==k)
                a=p->val;
            if(c==n-k+1)
                b=p->val;
            p=p->next;
            c++;
        }
        p=head;
        c=1;
        while(p!=NULL)
        {
            if(c==k)
            {
                p->val=b;
            }
            if(c==n-k+1)
            {
                p->val=a;
            }
            p=p->next;
            c++;
        }
        return head;
    }
};