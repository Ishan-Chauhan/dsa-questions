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
    private:
    ListNode* rev(ListNode* node)
    {
        ListNode* prev=NULL, *curr=node, *nxt;
        if(curr!=NULL) nxt=curr->next;
        
        while(nxt!=NULL)
        {
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if(nxt)
                nxt=nxt->next;
        }
        curr->next=prev;
        // cout<<curr->val<<endl;
        return curr;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = rev(l1);
        l2 = rev(l2);
        ListNode* head=NULL;
        
        int c=0, sum;
        while(l1!=NULL || l2!=NULL)
        {
            sum=0;
            if(l1 && l2)
            {
                sum = l1->val + l2->val+c;
                
                ListNode* x = new ListNode(sum%10, head);
                head = x;
                    
                if(sum>9) c=1;
                else c=0;
                
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1)
            {
                sum = l1->val+c;
                
                ListNode* x = new ListNode(sum%10, head);
                head = x;
                    
                if(sum>9) c=1;
                else c=0;
                l1=l1->next;
            }
            else
            {
                sum = l2->val+c;
                
                ListNode* x = new ListNode(sum%10, head);
                head = x;
                    
                if(sum>9) c=1;
                else c=0;
                l2=l2->next;
            }
            // cout<<sum<<" ";
        }
        if(c)
        {
            ListNode* x = new ListNode(1, head);
            head = x;
        }
        return head;
    }
};