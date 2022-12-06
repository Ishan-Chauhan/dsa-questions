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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *o=head, *e=head->next, *os=o, *es=e, *curr=e->next;
        int f=1;
        while(curr!=NULL)
        {
            if(f==1)
            {
                o->next = curr;
                o=curr;
                f=0;
            }
            else
            {
                e->next = curr;
                e=curr;
                f=1;
            }
            curr = curr->next;
        }
        o->next=es;
        e->next=NULL;
        return head;
    }
};