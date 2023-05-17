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
    ListNode* rev(ListNode* head)
    {
        ListNode* a=NULL, *b=head, *c=b->next;
        while(b!=NULL)
        {
            b->next=a;
            a=b;
            b=c;
            if(c)
                c=c->next;
        }
        return a;
    }
    ListNode* mid(ListNode* head)
    {
        ListNode* s=head, *f=head;
        while(f!=NULL && f->next!=NULL)
        {
            s=s->next;
            f=(f->next)->next;
        }
        if(f==NULL) return s;
        return s->next;
    }
    int pairSum(ListNode* head) {
        ListNode* x=mid(head);
        // cout<<x->val;
        ListNode* mid=rev(x);
        // cout<<(head->next)->val;
        int ans=-1;
        while(mid!=NULL)
        {
            ans=max(ans, head->val+mid->val);
            mid=mid->next;
            head=head->next;
        }
        return ans;
    }
};