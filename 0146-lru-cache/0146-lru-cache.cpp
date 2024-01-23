class node{
public:
    int key;
    int val;
    node *next, *prev;

    node(int k, int v)
    {
        key=k;
        val=v;
    }
};
class LRUCache {   
public:
    int cap;
    node *head, *tail;
    unordered_map<int, node*> mp;
    
    LRUCache(int capacity) {
        cap=capacity;
        head = new node(-1,-1);
        tail = new node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    // void pri(node* x)
    // {
    //     while(x!=tail)
    //     {
    //         cout<<x->val<<" ";
    //         x = x->next;
    //     }
    //     cout<<endl;
    // }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        
        node* temp = mp[key];
        
        (temp->prev)->next=temp->next;
        (temp->next)->prev=temp->prev;
        
        temp->next = head->next;
        (head->next)->prev = temp;
        
        head->next = temp;
        temp->prev=head;
        // cout<<(head->next)->val<<endl;
        // pri(head->next);
        return temp->val;
    }
    
    void put(int key, int value) {
        node* temp;
        if(mp.find(key)!=mp.end())
        {
            temp = mp[key];
            (temp->prev)->next=temp->next;
            (temp->next)->prev=temp->prev;
            temp->val = value;
        }
        else
        {
            temp = new node(key, value);
            mp[key] = temp;
            if(cap==0)
            {
                node* del = tail->prev;
                (del->prev)->next = del->next;
                (del->next)->prev=del->prev;
                mp.erase(mp.find(del->key));
                // delete del;
            }
            else cap--;
        }
        // cout<<key;
        
        temp->next = head->next;
        (head->next)->prev = temp;

        head->next = temp;
        temp->prev=head;
        // pri(head->next);
        // cout<<(head->next)->val<<endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */