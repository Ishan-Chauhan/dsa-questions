class MyHashSet {
public:
    map<int,int> m;
    MyHashSet() {
        
    }
    
    void add(int key) {
        m[key]=1;
    }
    
    void remove(int key) {
        m[key]=0;
    }
    
    bool contains(int key) {
        for(auto i: m)
        {
            if(i.first==key && i.second>0)return true;
            //cout<<i.first<<" "<<i.second<<endl;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */