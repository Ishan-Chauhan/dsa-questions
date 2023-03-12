/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *p;
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;
    if(list1->val<list2->val)
    {
        p=list1;
        p->next=mergeTwoLists(list1->next,list2);
        return list1;
    }
    else
    {
        p=list2;
        p->next=mergeTwoLists(list1,list2->next);
        return list2;
    }
}