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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* p=head;
        while(p!=NULL && p->next!=NULL)
        {
            int a=p->val;
            p->val=(p->next)->val;
            (p->next)->val=a;
            p=(p->next)->next;
        }
        return head;
    }
};