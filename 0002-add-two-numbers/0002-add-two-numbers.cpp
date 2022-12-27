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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a=l1;
        ListNode* b=l2;
        int c=0,s;
        while(a && b)
        {
            s=(a->val+b->val+c);
            if(s<10)
            {
                a->val=s;
                b->val=s;
                c=0;
            }
            else
            {
                a->val=s%10;
                b->val=s%10;
                c=1;
            }
            a=a->next;
            b=b->next;
        }
        int f=0;
        while(a)
        {
            f=1;
            a->val+=c;
            if(a->val>9)
            {
                a->val=(a->val)%10;
                c=1;
            }
            else
            {
                c=0;
            }
            a=a->next;
        }
        if(c==1)
        {
            ListNode *temp = new ListNode(1);
            a=l1;
            while(a->next!=NULL) a=a->next;
            a->next=temp;
        }
        if(f==1)
        {
            return l1;
        }
        while(b)
        {
            b->val+=c;
            if(b->val>9)
            {
                b->val=(b->val)%10;
                c=1;
            }
            else
            {
                c=0;
            }
            b=b->next;
        }
        if(c==1)
        {
            ListNode *temp = new ListNode(1);
            b=l2;
            while(b->next!=NULL) b=b->next;
            b->next=temp;
        }
        return l2;
    }
};