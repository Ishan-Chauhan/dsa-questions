class LRUCache {
public:
    class node{
        public:
            int key;
            int val;
            node* next;
            node* prev;
            node(int k, int v)
            {
                key = k;
                val = v;
            }
    };
    int cap;
    map<int,node*> m;
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(node* p)
    {
        node* temp = head->next;
        p->next = temp;
        p->prev = head;
        temp->prev = p;
        head->next = p;
    }
    
    void delnode(node* p)
    {
        node* pre = p->prev;
        node* nxt = p->next;
        pre->next =  nxt;
        nxt->prev = pre;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            node *p = m[key];
            m.erase(key);
            delnode(p);
            addnode(p);
            m[key] = head->next;
            return p->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        node* p = new node(key, value);
        if(m.find(key)!=m.end())
        {
            node* exist = m[key];
            m.erase(key);
            delnode(exist);
        }
        else if(m.size()==cap)
        {
            node* p = tail->prev;
            m.erase(p->key);
            delnode(p);
        }
        
        m[key] = p;
        addnode(p);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */