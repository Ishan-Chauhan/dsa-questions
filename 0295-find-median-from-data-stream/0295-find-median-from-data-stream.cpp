class MedianFinder {
public:
    priority_queue<int> ma;
    priority_queue<int,vector<int>,greater<int>> mi;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(ma.empty())
        {
            ma.push(num);
        }
        else if(mi.empty())
        {
            if(num>=ma.top())
                mi.push(num);
            else
            {
                int temp = ma.top();
                mi.push(temp);
                ma.pop();
                ma.push(num);
            }
        }
        else
        {
            if(num>=mi.top())
            {
                mi.push(num);
            }
            else
            {
                ma.push(num);
            }
        }
        int sz = ma.size();
        sz-=mi.size();
        // cout<<sz<<" ";
        if(sz>1)
        {
            int temp = ma.top();
            mi.push(temp);
            ma.pop();
        }
        else if(sz<-1)
        {
            int temp = mi.top();
            ma.push(temp);
            mi.pop();
        }
    }
    
    double findMedian() {
        // cout<<ma.top()<<" ";
        if(ma.size()>mi.size()) return double(ma.top());
        else if(ma.size()<mi.size()) return double(mi.top());
        else return (ma.top()+mi.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */