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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int,vector<ListNode*>> m;
        
        int n = lists.size();
        for(int i=0;i<n;i++)
        {
            ListNode* temp = lists[i];
            while(temp!=NULL)
            {
                m[temp->val].push_back(temp);
                temp = temp->next;
            }
        }
        
        ListNode* head=NULL,*temp=NULL;
        for(auto& it: m)
        {
            for(auto& i:it.second)
            {
                if(head==NULL)
                {
                    head=i;
                    temp=head;
                }
                else
                {
                    temp->next = i;
                    temp = i;
                }
            }
        }
        return head;
    }
};