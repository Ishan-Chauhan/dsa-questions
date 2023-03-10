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
    int n;
    vector<int> v;
    
    Solution(ListNode* head) {
        ListNode *temp = head;
        n=0;
        while(temp)
        {
            v.push_back(temp->val);
            temp = temp->next;
            n++;
        }
    }
    
    int getRandom() {
        return v[rand()%n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */