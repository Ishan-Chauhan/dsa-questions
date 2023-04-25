class SmallestInfiniteSet {
public:
    unordered_map<int,int> m;
    int c=1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int y=c;
        m[c]=-1;
        while(m[c]<0)    c++;
        return y;
    }
    
    void addBack(int num) {
        if(m[num]==-1)
        {
            m[num]=0;
        }
        if(num<c) c = num;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */