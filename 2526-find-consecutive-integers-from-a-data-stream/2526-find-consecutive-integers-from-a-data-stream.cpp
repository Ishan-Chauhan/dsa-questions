class DataStream {
private:
    int k,val;
    long c, last;
public:
    DataStream(int value, int k) {
        val=value;
        this->k=k;
        c=0;
        last=0;
    }
    
    bool consec(int num) {
        c++;
        if(num!=val) last=c;
        
        return (c-last)>=k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */